#include <common.h>
#include <asm/mmu.h>
#include <errno.h>
#include <linux/sizes.h>
#include <asm/memory.h>
#include <asm/system.h>
#include <asm/cache.h>

#include "mmu.h"

static uint64_t *ttb;
int free_idx = 1;


#define MAX_ENTRIES	512

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

	val = (uint64_t)table_addr | PMD_TYPE_TABLE;
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
				*pte = addr | attr;
				printk("virt at %llx pte at %llx [%llx] at level %d with idx %d remaining size %llx\n", addr, pte, *pte, level, idx, size);
				addr += block_size;
				size -= block_size;
				break;

			}

			table = xtables_get_level_table(pte);
		}

	}
}

static void create_sections(unsigned long addr, int size_m, unsigned int flags)
{
	map_region(addr, addr, size_m, flags);
}

static void map_cachable(unsigned long start, unsigned long size)
{
	create_sections(start, size, PMD_SECT_AP_WRITE |
			PMD_SECT_AP_READ | PMD_TYPE_SECT | PMD_SECT_WB);
}

void mmu_early_enable(uint32_t membase, uint32_t memsize, uint32_t _ttb)
{
	int i;
	uint64_t *pt;

	ttb = (uint64_t *)_ttb;

	memset(ttb, 0, GRANULE_SIZE);

	set_ttbr_tcr_mair(1, ttb, TCR_FLAGS, MEMORY_ATTR);

	create_sections(0, 4096, PMD_SECT_AP_WRITE |
			PMD_SECT_AP_READ | PMD_TYPE_SECT);

	map_cachable(membase, memsize);

	isb();
	find_pte(0x40000000);
	find_pte(0x5fa00000);
	set_sctlr(get_sctlr() | CR_M);
	isb();

//	__mmu_cache_on();
}
