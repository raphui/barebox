/*
 * linux/arch/arm/kernel/entry-v7m.S
 *
 * Copyright (C) 2008 ARM Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Low-level vector interface routines for the ARMv7-M architecture
 */
#include <asm/memory.h>
#include <asm/v7m.h>

__invalid_entry:
	v7m_exception_entry
#ifdef CONFIG_PRINTK
	adr	r0, strerr
	mrs	r1, ipsr
	mov	r2, lr
	bl	printk
#endif
	mov	r0, sp
	bl	show_regs
1:	b	1b
ENDPROC(__invalid_entry)

strerr:	.asciz	"\nUnhandled exception: IPSR = %08lx LR = %08lx\n"

	.align	2
__irq_entry:
	v7m_exception_entry

	@
	@ Invoke the IRQ handler
	@
	mrs	r0, ipsr
	ldr	r1, =V7M_xPSR_EXCEPTIONNO
	and	r0, r1
	sub	r0, #16
	mov	r1, sp
	stmdb	sp!, {lr}
	@ routine called with r0 = irq number, r1 = struct pt_regs *
	bl	nvic_handle_irq

	pop	{lr}
	@
	@ Check for any pending work if returning to user
	@
	ldr	r1, =BASEADDR_V7M_SCB
	ldr	r0, [r1, V7M_SCB_ICSR]
	tst	r0, V7M_SCB_ICSR_RETTOBASE
	beq	2f

	get_thread_info tsk
	ldr	r2, [tsk, #TI_FLAGS]
	tst	r2, #_TIF_WORK_MASK
	beq	2f			@ no work pending
	mov	r0, #V7M_SCB_ICSR_PENDSVSET
	str	r0, [r1, V7M_SCB_ICSR]	@ raise PendSV

2:
	@ registers r0-r3 and r12 are automatically restored on exception
	@ return. r4-r7 were not clobbered in v7m_exception_entry so for
	@ correctness they don't need to be restored. So only r8-r11 must be
	@ restored here. The easiest way to do so is to restore r0-r7, too.
	ldmia	sp!, {r0-r11}
	add	sp, #S_FRAME_SIZE-S_IP
	cpsie	i
	bx	lr
ENDPROC(__irq_entry)

__pendsv_entry:
	v7m_exception_entry

	ldr	r1, =BASEADDR_V7M_SCB
	mov	r0, #V7M_SCB_ICSR_PENDSVCLR
	str	r0, [r1, V7M_SCB_ICSR]	@ clear PendSV

	@ execute the pending work, including reschedule
	get_thread_info tsk
	mov	why, #0
	b	ret_to_user_from_irq
ENDPROC(__pendsv_entry)

	.data
#if CONFIG_CPU_V7M_NUM_IRQ <= 112
	.align	9
#else
	.align	10
#endif

/*
 * Vector table (Natural alignment need to be ensured)
 */
ENTRY(vector_table)
	.long	0			@ 0 - Reset stack pointer
	.long	__invalid_entry		@ 1 - Reset
	.long	__invalid_entry		@ 2 - NMI
	.long	__invalid_entry		@ 3 - HardFault
	.long	__invalid_entry		@ 4 - MemManage
	.long	__invalid_entry		@ 5 - BusFault
	.long	__invalid_entry		@ 6 - UsageFault
	.long	__invalid_entry		@ 7 - Reserved
	.long	__invalid_entry		@ 8 - Reserved
	.long	__invalid_entry		@ 9 - Reserved
	.long	__invalid_entry		@ 10 - Reserved
	.long	vector_swi		@ 11 - SVCall
	.long	__invalid_entry		@ 12 - Debug Monitor
	.long	__invalid_entry		@ 13 - Reserved
	.long	__pendsv_entry		@ 14 - PendSV
	.long	__invalid_entry		@ 15 - SysTick
	.rept	CONFIG_CPU_V7M_NUM_IRQ
	.long	__irq_entry		@ External Interrupts
	.endr
