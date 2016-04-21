#ifndef __ASM_ARM_SYSTEM_INFO_H
#define __ASM_ARM_SYSTEM_INFO_H

#include <asm/cputype.h>

#define CPU_ARCH_UNKNOWN	0
#define CPU_ARCH_ARMv8		10

#define CPU_IS_CORTEX_A53	0x410fd034
#define CPU_IS_CORTEX_A53_MASK	0xff0ffff0

#define CPU_IS_CORTEX_A57	0x411fd070
#define CPU_IS_CORTEX_A57_MASK	0xff0ffff0

#define cpu_is_arm(core) ((read_cpuid_id() & CPU_IS_##core##_MASK) == CPU_IS_##core)

#ifdef CONFIG_CPU_64v8
#ifdef ARM_ARCH
#define ARM_MULTIARCH
#else
#define ARM_ARCH CPU_ARCH_ARMv8
#endif
#define cpu_is_cortex_a53() cpu_is_arm(CORTEX_A53)
#define cpu_is_cortex_a57() cpu_is_arm(CORTEX_A57)
#else
#define cpu_is_cortex_a53() (0)
#define cpu_is_cortex_a57() (0)
#endif

#ifndef __ASSEMBLY__

#ifdef ARM_MULTIARCH
/*
 * Early version to get the ARM cpu architecture. Only needed during
 * early startup when the C environment is not yet fully initialized.
 * Normally you should use cpu_architecture() instead.
 */
static inline int arm_early_get_cpu_architecture(void)
{
	int cpu_arch;

	if ((read_cpuid_id() & 0x000f0000) == 0x000f0000) {
		unsigned int mmfr0;

		asm("mrs	%0, id_mmfr0_el1"
		    : "=r" (mmfr0));
		if ((mmfr0 & 0x0000000f) >= 0x00000003 ||
		    (mmfr0 & 0x000000f0) >= 0x00000030)
			cpu_arch = CPU_ARCH_ARMv8;
		else
			cpu_arch = CPU_ARCH_UNKNOWN;
	} else
		cpu_arch = CPU_ARCH_UNKNOWN;

	return cpu_arch;
}

extern int __pure cpu_architecture(void);
#else
static inline int __pure arm_early_get_cpu_architecture(void)
{
	return ARM_ARCH;
}

static inline int __pure cpu_architecture(void)
{
	return ARM_ARCH;
}
#endif

#endif /* !__ASSEMBLY__ */

#endif /* __ASM_ARM_SYSTEM_INFO_H */
