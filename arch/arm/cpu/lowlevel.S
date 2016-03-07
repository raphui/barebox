#include <linux/linkage.h>
#include <init.h>
#include <asm/system.h>

.section ".text_bare_init_","ax"
ENTRY(arm_cpu_lowlevel_init)
	/* set the cpu to SVC32 mode, mask irq and fiq */
	mrs	r12, cpsr
	bic	r12, r12, #0x1f
	orr	r12, r12, #0xd3
	msr	cpsr, r12

#if __LINUX_ARM_ARCH__ >= 6
	/*
	 * ICIALLU: Invalidate all instruction caches to PoU,
	 * includes flushing of branch predictors.
	 * Even if the i-cache is off it might contain stale entries
	 * that are better discarded before enabling the cache.
	 * Architectually this is even possible after a cold reset.
	 */
	mcr	p15, 0, r12, c7, c5, 0
	/* DSB, ensure completion of the invalidation */
	mcr	p15, 0, r12, c7, c10, 4
	/*
	 * ISB, ensure instruction fetch path is in sync.
	 * Note that the ARM Architecture Reference Manual, ARMv7-A and ARMv7-R
	 * edition (ARM DDI 0406C.c) doesn't define this instruction in the
	 * ARMv6 part (D12.7.10). It only has: "Support of additional
	 * operations is IMPLEMENTATION DEFINED".
	 * But an earlier version of the ARMARM (ARM DDI 0100I) does define it
	 * as "Flush prefetch buffer (PrefetchFlush)".
	 */
	mcr	p15, 0, r12, c7, c5, 4
#endif

	/* disable MMU stuff and data/unified caches */
	mrc	p15, 0, r12, c1, c0, 0		/* SCTLR */
	bic	r12, r12, #(CR_M | CR_C | CR_B)
	bic	r12, r12, #(CR_S | CR_R | CR_V)

	/* enable instruction cache */
	orr	r12, r12, #CR_I

#if __LINUX_ARM_ARCH__ >= 6
	orr	r12, r12, #CR_U
	bic	r12, r12, #CR_A
#else
	orr	r12, r12, #CR_A
#endif

#ifdef __ARMEB__
	orr	r12, r12, #CR_B
#endif

	mcr	p15, 0, r12, c1, c0, 0		/* SCTLR */

	mov	pc, lr
ENDPROC(arm_cpu_lowlevel_init)

ENTRY(armv8_cpu_lowlevel_init)
	adr	x0, vectors
	mrs	x1, CurrentEL
	cmp	x1, #0xC		/* Check EL3 state */
	b.eq	1f
	cmp	x1, #0x8		/* Check EL2 state */
	b.eq	2f
	cmp	x1, #0x4		/* Check EL1 state */
	b.eq	3f

1:
	msr	vbar_el3, x0
	mov	x0, #1			/* Non-Secure EL0/1 */
	orr	x0, x0, #(1 << 10)	/* 64-bit EL2 */
	msr	scr_el3, x0
	msr	cptr_el3, xzr
	b	done

2:
	msr	vbar_el2, x0
	mov	x0, #0x33ff		/* Enable FP/SIMD */
	msr	cptr_el2, x0
	b	done
	

3:
	msr	vbar_el1, x0
	mov	x0, #(3 << 20)		/* Enable FP/SIMD */
	msr	cpacr_el1, x0
	b	done


done:		
	b	done

ENDPROC(armv8_cpu_lowlevel_init)
