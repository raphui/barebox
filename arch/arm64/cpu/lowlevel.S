#include <linux/linkage.h>
#include <init.h>
#include <asm/system.h>
#include <asm/gic.h>

.section ".text_bare_init_","ax"

ENTRY(arm_cpu_lowlevel_init)
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
#if 1
	ldr	x1, =GIC_DIST_BASE		// GICD_CTLR
	mov	w0, #3				// EnableGrp0 | EnableGrp1
	str	w0, [x1]

	ldr	x1, =GIC_DIST_BASE + 0x80	// GICD_IGROUPR
	mov	w0, #~0				// Grp1 interrupts
	str	w0, [x1], #4
	b.ne	2f				// Only local interrupts for secondary CPUs
	str	w0, [x1], #4
	str	w0, [x1], #4

2:	ldr	x1, =GIC_CPU_BASE		// GICC_CTLR
	ldr	w0, [x1]
	mov	w0, #3				// EnableGrp0 | EnableGrp1
	str	w0, [x1]

	mov	w0, #1 << 7			// allow NS access to GICC_PMR
	str	w0, [x1, #4]			// GICC_PMR

	msr	sctlr_el2, xzr
#endif

	ret

ENDPROC(arm_cpu_lowlevel_init)
