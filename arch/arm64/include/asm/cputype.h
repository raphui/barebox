#ifndef __ASM_ARM_CPUTYPE_H
#define __ASM_ARM_CPUTYPE_H

#include <linux/stringify.h>
#include <linux/kernel.h>

#define CPUID_ID	"midr_el1"
#define CPUID_CACHETYPE	"ctr_el0"
#define CPUID_MPIDR	"mpidr_el1"

#define CPUID_EXT_PFR0	"id_pfr0_el1"
#define CPUID_EXT_PFR1	"id_pfr1_el1"
#define CPUID_EXT_DFR0	"id_dfr0_el1"
#define CPUID_EXT_AFR0	"id_afr0_el1"
#define CPUID_EXT_MMFR0	"id_mmfr0_el1"
#define CPUID_EXT_MMFR1	"id_mmfr1_el1"
#define CPUID_EXT_MMFR2 "id_mmfr2_el1"
#define CPUID_EXT_MMFR3	"id_mmfr3_el1"
#define CPUID_EXT_ISAR0	"id_isar0_el1"
#define CPUID_EXT_ISAR1	"id_isar1_el1"
#define CPUID_EXT_ISAR2	"id_isar2_el1"
#define CPUID_EXT_ISAR3	"id_isar3_el1"
#define CPUID_EXT_ISAR4	"id_isar4_el1"
#define CPUID_EXT_ISAR5	"id_isar5_el1"

extern unsigned int processor_id;

#define read_cpuid(reg)							\
	({								\
		unsigned int __val;					\
		asm("mrs	%0, " __stringify(reg)			\
		    : "=r" (__val)					\
		    :							\
		    : "cc");						\
		__val;							\
	})

/*
 * The CPU ID never changes at run time, so we might as well tell the
 * compiler that it's constant.  Use this function to read the CPU ID
 * rather than directly reading processor_id or read_cpuid() directly.
 */
static inline unsigned int __attribute_const__ read_cpuid_id(void)
{
	return read_cpuid(CPUID_ID);
}

static inline unsigned int __attribute_const__ read_cpuid_mpidr(void)
{
	return read_cpuid(CPUID_MPIDR);
}


#endif
