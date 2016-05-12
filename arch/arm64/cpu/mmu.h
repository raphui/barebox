#ifndef __ARM_MMU_H
#define __ARM_MMU_H

#ifdef __ASSEMBLY__
#define _AC(X, Y)	X
#else
#define _AC(X, Y)	(X##Y)
#endif

#define UL(x)		_AC(x, UL)

/***************************************************************/
/*
 * The following definitions are related each other, shoud be
 * calculated specifically.
 */
#define VA_BITS			(33)	/* 42 bits virtual address */

/* PAGE_SHIFT determines the page size */
#undef  PAGE_SIZE
#define PAGE_SHIFT		16
#define PAGE_SIZE		(1 << PAGE_SHIFT)
#define PAGE_MASK		(~(PAGE_SIZE-1))

/*
 * section address mask and size definitions.
 */
#define SECTION_SHIFT		29
#define SECTION_SIZE		(UL(1) << SECTION_SHIFT)
#define SECTION_MASK		(~(SECTION_SIZE-1))
/***************************************************************/

/*
 * Memory types
 */
#define MT_DEVICE_NGNRNE	0
#define MT_DEVICE_NGNRE		1
#define MT_DEVICE_GRE		2
#define MT_NORMAL_NC		3
#define MT_NORMAL		4

#define MEMORY_ATTRIBUTES	((0x00 << (MT_DEVICE_NGNRNE*8)) |	\
				(0x04 << (MT_DEVICE_NGNRE*8)) |		\
				(0x0c << (MT_DEVICE_GRE*8)) |		\
				(0x44 << (MT_NORMAL_NC*8)) |		\
				(UL(0xff) << (MT_NORMAL*8)))

/*
 * Hardware page table definitions.
 *
 * Level 2 descriptor (PMD).
 */
#define PMD_TYPE_MASK		(3 << 0)
#define PMD_TYPE_FAULT		(0 << 0)
#define PMD_TYPE_TABLE		(3 << 0)
#define PMD_TYPE_PAGE		(3 << 0)
#define PMD_TYPE_SECT		(1 << 0)

#define PTE_TYPE_MASK		(3 << 0)
#define PTE_TYPE_FAULT		(0 << 0)
#define PTE_TYPE_TABLE		(3 << 0)
#define PTE_TYPE_PAGE		(3 << 0)
#define PTE_TYPE_SECT		(1 << 0)

/*
 * Section
 */
#define PMD_SECT_NON_SHARE	(0 << 8)
#define PMD_SECT_OUTER_SHARE	(2 << 8)
#define PMD_SECT_INNER_SHARE	(3 << 8)
#define PMD_SECT_AF		(1 << 10)
#define PMD_SECT_NG		(1 << 11)
#define PMD_SECT_PXN		(UL(1) << 53)
#define PMD_SECT_UXN		(UL(1) << 54)

/*
 * AttrIndx[2:0]
 */
#define PMD_ATTRINDX(t)		((t) << 2)
#define PMD_ATTRINDX_MASK	(7 << 2)

/*
 * TCR flags.
 */
#define TCR_T0SZ(x)		((64 - (x)) << 0)
#define TCR_IRGN_NC		(0 << 8)
#define TCR_IRGN_WBWA		(1 << 8)
#define TCR_IRGN_WT		(2 << 8)
#define TCR_IRGN_WBNWA		(3 << 8)
#define TCR_IRGN_MASK		(3 << 8)
#define TCR_ORGN_NC		(0 << 10)
#define TCR_ORGN_WBWA		(1 << 10)
#define TCR_ORGN_WT		(2 << 10)
#define TCR_ORGN_WBNWA		(3 << 10)
#define TCR_ORGN_MASK		(3 << 10)
#define TCR_SHARED_NON		(0 << 12)
#define TCR_SHARED_OUTER	(2 << 12)
#define TCR_SHARED_INNER	(3 << 12)
#define TCR_TG0_4K		(0 << 14)
#define TCR_TG0_64K		(1 << 14)
#define TCR_TG0_16K		(2 << 14)
#define TCR_EL1_IPS_BITS	(UL(3) << 32)	/* 42 bits physical address */
#define TCR_EL2_IPS_BITS	(3 << 16)	/* 42 bits physical address */
#define TCR_EL3_IPS_BITS	(3 << 16)	/* 42 bits physical address */

#define TCR_EL1_RSVD		(1 << 31)
#define TCR_EL2_RSVD		(1 << 31 | 1 << 23)
#define TCR_EL3_RSVD		(1 << 31 | 1 << 23)

#define TCR_FLAGS             TCR_TG0_4K | \
                                TCR_SHARED_OUTER | \
                                TCR_SHARED_INNER | \
                                TCR_IRGN_WBWA | \
                                TCR_ORGN_WBWA | \
                                TCR_T0SZ(VA_BITS)

#define MEMORY_ATTR     PMD_SECT_AF | PMD_SECT_INNER_SHARE |    \
                        PMD_ATTRINDX(MT_NORMAL) |       \
                        PMD_TYPE_SECT

#ifndef __ASSEMBLY__

static inline void set_ttbr_tcr_mair(int el, uint64_t table, uint64_t tcr, uint64_t attr)
{
	asm volatile("dsb sy");
	if (el == 1) {
		asm volatile("msr ttbr0_el1, %0" : : "r" (table) : "memory");
		asm volatile("msr tcr_el1, %0" : : "r" (tcr) : "memory");
		asm volatile("msr mair_el1, %0" : : "r" (attr) : "memory");
	} else if (el == 2) {
		asm volatile("msr ttbr0_el2, %0" : : "r" (table) : "memory");
		asm volatile("msr tcr_el2, %0" : : "r" (tcr) : "memory");
		asm volatile("msr mair_el2, %0" : : "r" (attr) : "memory");
	} else if (el == 3) {
		asm volatile("msr ttbr0_el3, %0" : : "r" (table) : "memory");
		asm volatile("msr tcr_el3, %0" : : "r" (tcr) : "memory");
		asm volatile("msr mair_el3, %0" : : "r" (attr) : "memory");
	} else {
		hang();
	}
	asm volatile("isb");
}

static inline uint64_t get_ttbr(int el)
{
	uint64_t val;
	if (el == 1) {
		asm volatile("mrs %0, ttbr0_el1" : "=r" (val));
	} else if (el == 2) {
		asm volatile("mrs %0, ttbr0_el2" : "=r" (val));
	} else if (el == 3) {
		asm volatile("mrs %0, ttbr0_el3" : "=r" (val));
	} else {
		hang();
	}

	return val;
}
#endif

#define UNUSED_DESC                0x6EbAAD0BBADbA6E0

#define VA_START                   0x0
#define BITS_PER_VA                33
/* Granule size of 4KB is being used */
#define GRANULE_SIZE_SHIFT         12
#define GRANULE_SIZE               (1 << GRANULE_SIZE_SHIFT)
#define XLAT_ADDR_MASK             ((1UL << BITS_PER_VA) - GRANULE_SIZE)
#define GRANULE_SIZE_MASK          ((1 << GRANULE_SIZE_SHIFT) - 1)

#define BITS_RESOLVED_PER_LVL   (GRANULE_SIZE_SHIFT - 3)
#define L1_ADDR_SHIFT           (GRANULE_SIZE_SHIFT + BITS_RESOLVED_PER_LVL * 2)
#define L2_ADDR_SHIFT           (GRANULE_SIZE_SHIFT + BITS_RESOLVED_PER_LVL * 1)
#define L3_ADDR_SHIFT           (GRANULE_SIZE_SHIFT + BITS_RESOLVED_PER_LVL * 0)


#define L1_ADDR_MASK     (((1UL << BITS_RESOLVED_PER_LVL) - 1) << L1_ADDR_SHIFT)
#define L2_ADDR_MASK     (((1UL << BITS_RESOLVED_PER_LVL) - 1) << L2_ADDR_SHIFT)
#define L3_ADDR_MASK     (((1UL << BITS_RESOLVED_PER_LVL) - 1) << L3_ADDR_SHIFT)

/* These macros give the size of the region addressed by each entry of a xlat
   table at any given level */
#define L3_XLAT_SIZE               (1UL << L3_ADDR_SHIFT)
#define L2_XLAT_SIZE               (1UL << L2_ADDR_SHIFT)
#define L1_XLAT_SIZE               (1UL << L1_ADDR_SHIFT)

#define IS_ALIGNED(x,a)         (((x) & ((__typeof__(x))(a)-1UL)) == 0)

#define PAGE_MASK	GRANULE_SIZE

#ifdef CONFIG_MMU
void __mmu_cache_on(void);
void __mmu_cache_off(void);
void __mmu_cache_flush(void);
#else
static inline void __mmu_cache_on(void) {}
static inline void __mmu_cache_off(void) {}
static inline void __mmu_cache_flush(void) {}
#endif

#endif /* __ARM_MMU_H */
