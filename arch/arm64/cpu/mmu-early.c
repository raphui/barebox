#include <common.h>
#include <asm/mmu.h>
#include <errno.h>
#include <linux/sizes.h>
#include <asm/memory.h>
#include <asm/system.h>
#include <asm/cache.h>

#include "mmu.h"

static uint32_t *ttb;

static int pte_type(uint64_t *pte)
{
	return *pte & PMD_TYPE_MASK;
}

static uint64_t *find_pte(uint64_t addr)
{
	uint64_t *pte = ttb;
	uint64_t block_shift;
	int i;
	int idx;

	if (!ttb)
		arm_mmu_not_initialized_error();

	for (i = 1; i < 4; i++) {
		block_shift = level2shift(i);
		idx = (addr >> block_shift) & 0x1FF;
		pte += idx;

		printf("idx=%llx PTE %p at level %d: %llx\n", idx, pte, i, *pte);

		if ((pte_type(pte) != PMD_TYPE_TABLE) || (block_shift <= GRANULE_SIZE_SHIFT))
			break;
		else
			pte = (uint64_t *)(*pte & XLAT_ADDR_MASK);	
	}


	return entry;
}

static void map_region(uint64_t virt, uint64_t phys, uint64_t size, uint64_t attr)
{
	uint64_t block_size;
	uint64_t block_shift;
	uint64_t *pte;
	uint64_t idx;
	uint64_t *table;
	uint64_t addr;
	int level;

	table = table;

	phys &= PAGE_MASK;
	addr = virt & PAGE_MASK;

	while (size) {
		for (level = 1; level < 4; level++) {
			idx = (addr & level2mask(level)) >> level2shift(level);
			block_size = (1 << level2shift(level));

			if (size >= block_size && IS_ALIGNED(addr, block_size)) {
				pte = table + idx;
				printf("virt at %llx pte at %llx at level %d remaining size %llx\n", virt, pte, level, size);
				*pte = phys | attr;
				phys += block_size;
				addr += block_size;
				size -= block_size;
				break;

			} else if (pte_type(pte) == PMD_TYPE_FAULT) {
				table = xtables_create_table(pgd);
				xtables_set_table(pte, table);
			}
		}

	}
}

static void create_sections(unsigned long addr, int size_m, unsigned int flags)
{
	int i;

	map_region(addr, addr, size_m, flags);
//
//	addr >>= 20;
//
//	for (i = size_m; i > 0; i--, addr++)
//		ttb[addr] = (addr << 20) | flags;
}

static void map_cachable(unsigned long start, unsigned long size)
{
	start &= ~(SZ_1M - 1);
	size = (size + (SZ_1M - 1)) & ~(SZ_1M - 1);

	create_sections(start, size >> 20, PMD_SECT_AP_WRITE |
			PMD_SECT_AP_READ | PMD_TYPE_SECT | PMD_SECT_WB);
}

 mmu_early_enable(uint32_t membase, uint32_t memsize, uint32_t _ttb)
{
	int i;

	ttb = (uint32_t *)_ttb;

//	arm_set_cache_functions();

//	/* Set the ttb register */
//	asm volatile ("mcr  p15,0,%0,c2,c0,0" : : "r"(ttb) /*:*/);
//
//	/* Set the Domain Access Control Register */
//	i = 0x3;
//	asm volatile ("mcr  p15,0,%0,c3,c0,0" : : "r"(i) /*:*/);

	create_sections(0, 4096, PMD_SECT_AP_WRITE |
			PMD_SECT_AP_READ | PMD_TYPE_SECT);

	set_ttbr_tcr_mair(1, ttb, TCR_FLAGS, MEMORY_ATTR);

	map_cachable(membase, memsize);

//	__mmu_cache_on();
}
