/*
 * Copyright (c) 2009-2013 Sascha Hauer <s.hauer@pengutronix.de>, Pengutronix
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#define pr_fmt(fmt)	"mmu: " fmt

#include <common.h>
#include <dma-dir.h>
#include <init.h>
#include <mmu.h>
#include <errno.h>
#include <linux/sizes.h>
#include <asm/memory.h>
#include <asm/barebox-arm.h>
#include <asm/system.h>
#include <asm/cache.h>
#include <memory.h>
#include <asm/system_info.h>

#include "mmu.h"

static unsigned long *ttb;
static int free_idx;

static void arm_mmu_not_initialized_error(void)
{
	/*
	 * This means:
	 * - one of the MMU functions like dma_alloc_coherent
	 *   or remap_range is called too early, before the MMU is initialized
	 * - Or the MMU initialization has failed earlier
	 */
	panic("MMU not initialized\n");
}

static int level2shift(int level)
{
	/* Page is 12 bits wide, every level translates 9 bits */
	return (12 + 9 * (3 - level));
}

static uint64_t level2mask(int level)
{
	if (level == 1)
		return L1_ADDR_MASK;
	else if (level == 2)
		return L2_ADDR_MASK;
	else if (level == 3)
		return L3_ADDR_MASK;
}

static int pte_type(uint64_t *pte)
{
	return *pte & PMD_TYPE_MASK;
}

static void xtables_set_table(uint64_t *pt, uint64_t *table_addr)
{
	uint64_t val;

	val = PMD_TYPE_TABLE | (uint64_t)table_addr;
	*pt = val;
}

static uint64_t *xtables_create_table(void)
{
	uint64_t *new_table = ttb + free_idx * GRANULE_SIZE;

	/* Mark all entries as invalid */
	memset(new_table, 0, GRANULE_SIZE);

	free_idx++;

	return new_table;
}

static uint64_t xtables_get_level_table(uint64_t *pte)
{
	uint64_t *table = (uint64_t *)(*pte & XLAT_ADDR_MASK);

	if (pte_type(pte) != PMD_TYPE_TABLE) {
		table = xtables_create_table();
		xtables_set_table(pte, table);
	}

	return table;
}

static uint64_t *find_pte(uint64_t addr)
{
	uint64_t *pte;
	uint64_t block_shift;
	uint64_t idx;
	int i;

	pte = ttb;

	for (i = 1; i < 4; i++) {
		block_shift = level2shift(i);
		idx = (addr & level2mask(i)) >> block_shift;
		pte += idx;

		if ((pte_type(pte) != PMD_TYPE_TABLE) || (block_shift <= GRANULE_SIZE_SHIFT))
			break;
		else
			pte = (uint64_t *)(*pte & XLAT_ADDR_MASK);
	}

	printk("virt: %llx at idx=%d PTE %p at level %d: %llx\n", addr, idx, pte, i, *pte);

	return pte;
}

static void map_region(uint64_t virt, uint64_t phys, uint64_t size, uint64_t attr)
{
	uint64_t block_size;
	uint64_t block_shift;
	uint64_t *pte;
	uint64_t idx;
	uint64_t addr;
	uint64_t *table;
	int level;

	addr = virt;

	attr &= ~(PMD_TYPE_SECT);

	while (size) {
		table = ttb;
		for (level = 1; level < 4; level++) {
			block_shift = level2shift(level);
			idx = (addr & level2mask(level)) >> block_shift;
			block_size = (1 << block_shift);

			pte = table + idx;

			if (level == 3)
				attr |= PMD_TYPE_PAGE;
			else
				attr |= PMD_TYPE_SECT;

			if (size >= block_size && IS_ALIGNED(addr, block_size)) {
				*pte = phys | attr;
				addr += block_size;
				phys += block_size;
				size -= block_size;
				break;

			}

			table = xtables_get_level_table(pte);
		}

	}
}

static void create_sections(unsigned long virt, unsigned long phys, int size_m,
		unsigned int flags)
{
	if (!ttb)
		arm_mmu_not_initialized_error();

	map_region(virt, phys, size_m, flags);

//	__mmu_cache_flush();
}

static void map_cachable(unsigned long start, unsigned long size)
{
	create_sections(start, start, size, PMD_SECT_AP_WRITE |
			PMD_SECT_AP_READ | PMD_TYPE_SECT | PMD_SECT_WB);
}

/*
 * Do it the simple way for now and invalidate the entire
 * tlb
 */
static inline void tlb_invalidate(void)
{
	unsigned int el = current_el();

	dsb();

	if (el == 1)
		__asm__ __volatile__("tlbi alle1\n\t" : : : "memory");
	else if (el == 2)
		__asm__ __volatile__("tlbi alle2\n\t" : : : "memory");
	else if (el == 3)
		__asm__ __volatile__("tlbi alle3\n\t" : : : "memory");

	dsb();
	isb();
}

#define PTE_FLAGS_CACHED_V7 (PTE_EXT_TEX(1) | PTE_BUFFERABLE | PTE_CACHEABLE)
#define PTE_FLAGS_WC_V7 PTE_EXT_TEX(1)
#define PTE_FLAGS_UNCACHED_V7 (0)
#define PTE_FLAGS_CACHED_V4 (PTE_SMALL_AP_UNO_SRW | PTE_BUFFERABLE | PTE_CACHEABLE)
#define PTE_FLAGS_UNCACHED_V4 PTE_SMALL_AP_UNO_SRW

/*
 * PTE flags to set cached and uncached areas.
 * This will be determined at runtime.
 */
static uint32_t pte_flags_cached;
static uint32_t pte_flags_wc;
static uint32_t pte_flags_uncached;

#define PTE_MASK ((1 << 12) - 1)

//static void dma_flush_range(unsigned long start, unsigned long end)
//{
//	__dma_flush_range(start, end);
//	if (outer_cache.flush_range)
//		outer_cache.flush_range(start, end);
//}
//
//static void dma_inv_range(unsigned long start, unsigned long end)
//{
//	if (outer_cache.inv_range)
//		outer_cache.inv_range(start, end);
//	__dma_inv_range(start, end);
//}
//
//static int __remap_range(void *_start, size_t size, u32 pte_flags)
//{
//	unsigned long start = (unsigned long)_start;
//	u32 *p;
//	int numentries, i;
//
//	numentries = size >> PAGE_SHIFT;
//	p = find_pte(start);
//
//	for (i = 0; i < numentries; i++) {
//		p[i] &= ~PTE_MASK;
//		p[i] |= pte_flags | PTE_TYPE_SMALL;
//	}
//
//	dma_flush_range((unsigned long)p,
//			(unsigned long)p + numentries * sizeof(u32));
//
//	tlb_invalidate();
//
//	return 0;
//}

//int arch_remap_range(void *start, size_t size, unsigned flags)
//{
//	u32 pte_flags;
//
//	switch (flags) {
//	case MAP_CACHED:
//		pte_flags = pte_flags_cached;
//		break;
//	case MAP_UNCACHED:
//		pte_flags = pte_flags_uncached;
//		break;
//	default:
//		return -EINVAL;
//	}
//
//	return __remap_range(start, size, pte_flags);
//}

void *map_io_sections(unsigned long phys, void *_start, size_t size)
{

	map_region(_start, phys, size, PMD_SECT_DEF_UNCACHED);

//	dma_flush_range((unsigned long)ttb, (unsigned long)ttb + 0x4000);
//	tlb_invalidate();
//	return _start;
}

/*
 * remap the memory bank described by mem cachable and
 * bufferable
 */
static int arm_mmu_remap_sdram(struct memory_bank *bank)
{
	unsigned long phys = (unsigned long)bank->start;
	unsigned long ttb_start = phys >> 20;
	unsigned long ttb_end = (phys >> 20) + (bank->size >> 20);
	unsigned long num_ptes = bank->size >> 12;
	int i, pte;
	u32 *ptes;

	pr_debug("remapping SDRAM from 0x%08lx (size 0x%08lx)\n",
			phys, bank->size);

//	/*
//	 * We replace each 1MiB section in this range with second level page
//	 * tables, therefore we must have 1Mib aligment here.
//	 */
//	if ((phys & (SZ_1M - 1)) || (bank->size & (SZ_1M - 1)))
//		return -EINVAL;
//
//	ptes = xmemalign(PAGE_SIZE, num_ptes * sizeof(u32));
//
//	pr_debug("ptes: 0x%p ttb_start: 0x%08lx ttb_end: 0x%08lx\n",
//			ptes, ttb_start, ttb_end);
//
//	for (i = 0; i < num_ptes; i++) {
//		ptes[i] = (phys + i * PAGE_SIZE) | PTE_TYPE_SMALL |
//			pte_flags_cached;
//	}
//
//	pte = 0;
//
//	for (i = ttb_start; i < ttb_end; i++) {
//		ttb[i] = (unsigned long)(&ptes[pte]) | PMD_TYPE_TABLE |
//			(0 << 4);
//		pte += 256;
//	}
//
//	dma_flush_range((unsigned long)ttb, (unsigned long)ttb + 0x4000);
//	dma_flush_range((unsigned long)ptes,
//			(unsigned long)ptes + num_ptes * sizeof(u32));
//
//	tlb_invalidate();

	return 0;
}
/*
 * We have 8 exception vectors and the table consists of absolute
 * jumps, so we need 8 * 4 bytes for the instructions and another
 * 8 * 4 bytes for the addresses.
 */
#define ARM_VECTORS_SIZE	(sizeof(u32) * 8 * 2)

/*
 * Prepare MMU for usage enable it.
 */
static int mmu_init(void)
{
	struct memory_bank *bank;
	int i;

	printk("%s\n", __func__);
	if (list_empty(&memory_banks))
		/*
		 * If you see this it means you have no memory registered.
		 * This can be done either with arm_add_mem_device() in an
		 * initcall prior to mmu_initcall or via devicetree in the
		 * memory node.
		 */
		panic("MMU: No memory bank found! Cannot continue\n");

	if (get_sctlr() & CR_M) {
		ttb = get_ttbr(1);
		if (!request_sdram_region("ttb", (unsigned long)ttb, SZ_16K))
			/*
			* This can mean that:
			* - the early MMU code has put the ttb into a place
			*   which we don't have inside our available memory
			* - Somebody else has occupied the ttb region which means
			*   the ttb will get corrupted.
			*/
			pr_crit("Critical Error: Can't request SDRAM region for ttb at %p\n",
				ttb);
	} else {
		ttb = memalign(0x1000, SZ_16K);
		free_idx = 1;

		memset(ttb, 0, GRANULE_SIZE);

		set_ttbr_tcr_mair(1, ttb, TCR_FLAGS, MEMORY_ATTR);
	}

	pr_debug("ttb: 0x%p\n", ttb);

	/* create a flat mapping using 1MiB sections */
	create_sections(0, 0, PAGE_SIZE, PMD_SECT_AP_WRITE | PMD_SECT_AP_READ |
			PMD_TYPE_SECT);

	/*
	 * First remap sdram cached using sections.
	 * This is to speed up the generation of 2nd level page tables
	 * below
	 */
	for_each_memory_bank(bank) {
		printk("bankbase %x, banksize: %x, bankend: %x\n", bank->start, bank->size, bank->start + bank->size);
		create_sections(bank->start, bank->start, bank->size,
				PMD_SECT_DEF_CACHED);
	}

	map_cachable(0x09000000, 0x01000000);
	map_cachable(0x00000000, 0x08000000);

//	__mmu_cache_on();

	/*
	 * Now that we have the MMU and caches on remap sdram again using
	 * page tables
	 */
//	for_each_memory_bank(bank)
//		arm_mmu_remap_sdram(bank);

	if (!(get_sctlr() & CR_M))
		set_sctlr(get_sctlr() | CR_M | CR_C | CR_I);

	return 0;
}
mmu_initcall(mmu_init);

void mmu_early_enable(uint32_t membase, uint32_t memsize, uint32_t _ttb)
{
	int i;
	uint64_t *pt;

	ttb = (uint64_t *)_ttb;

	memset(ttb, 0, GRANULE_SIZE);
	free_idx = 1;

	set_ttbr_tcr_mair(1, ttb, TCR_FLAGS, MEMORY_ATTR);

	create_sections(0, 0, 4096, PMD_SECT_AP_WRITE |
			PMD_SECT_AP_READ | PMD_TYPE_SECT);

	map_cachable(membase, memsize);
	map_cachable(0x09000000, 0x01000000);
	map_cachable(0x00000000, 0x08000000);

	printk("membase %x, memsize: %x, memend: %x\n", membase, memsize, membase + memsize);

	isb();
	set_sctlr(get_sctlr() | CR_M);
	isb();

//	__mmu_cache_on();
}

void *dma_alloc_coherent(size_t size, dma_addr_t *dma_handle)
{
//	void *ret;
//
//	size = PAGE_ALIGN(size);
//	ret = xmemalign(PAGE_SIZE, size);
//	if (dma_handle)
//		*dma_handle = (dma_addr_t)ret;
//
//	dma_inv_range((unsigned long)ret, (unsigned long)ret + size);
//
//	__remap_range(ret, size, pte_flags_uncached);
//
//	return ret;
}

void *dma_alloc_writecombine(size_t size, dma_addr_t *dma_handle)
{
//	void *ret;
//
//	size = PAGE_ALIGN(size);
//	ret = xmemalign(PAGE_SIZE, size);
//	if (dma_handle)
//		*dma_handle = (dma_addr_t)ret;
//
//	dma_inv_range((unsigned long)ret, (unsigned long)ret + size);
//
//	__remap_range(ret, size, pte_flags_wc);
//
//	return ret;
}

unsigned long virt_to_phys(volatile void *virt)
{
	return (unsigned long)virt;
}

void *phys_to_virt(unsigned long phys)
{
	return (void *)phys;
}

void dma_free_coherent(void *mem, dma_addr_t dma_handle, size_t size)
{
//	size = PAGE_ALIGN(size);
//	__remap_range(mem, size, pte_flags_cached);
//
//	free(mem);
}

void dma_sync_single_for_cpu(unsigned long address, size_t size,
			     enum dma_data_direction dir)
{
//	if (dir != DMA_TO_DEVICE) {
//		if (outer_cache.inv_range)
//			outer_cache.inv_range(address, address + size);
//		__dma_inv_range(address, address + size);
//	}
}

void dma_sync_single_for_device(unsigned long address, size_t size,
				enum dma_data_direction dir)
{
//	if (dir == DMA_FROM_DEVICE) {
//		__dma_inv_range(address, address + size);
//		if (outer_cache.inv_range)
//			outer_cache.inv_range(address, address + size);
//	} else {
//		__dma_clean_range(address, address + size);
//		if (outer_cache.clean_range)
//			outer_cache.clean_range(address, address + size);
//	}
}
