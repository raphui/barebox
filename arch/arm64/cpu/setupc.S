#include <linux/linkage.h>
#include <asm/sections.h>

.section .text.setupc

/*
 * setup_c: copy binary to link address, clear bss and
 * continue executing at new address.
 *
 * This function does not return to the address it is
 * called from, but to the same location in the copied
 * binary.
 */
ENTRY(setup_c)
#if 0
	push	{x4, x5}
	mov	x5, lr
	bl	get_runtime_offset
	subs	x4, x0, #0
	beq	1f			/* skip memcpy if already at correct address */
	ldr	x0,=_text
	ldr	x2,=__bss_start
	sub	x2, x2, x0
	sub	x1, x0, x4
	bl	memcpy			/* memcpy(_text, _text - offset, __bss_start - _text) */
1:	ldr	x0, =__bss_start
	mov	x1, #0
	ldr	x2, =__bss_stop
	sub	x2, x2, x0
	bl	memset			/* clear bss */
#ifdef CONFIG_MMU
	bl	arm_early_mmu_cache_flush
#endif
	mov	x0, #0
	bl	v8_invalidate_icache_all
	add	x6, x5, x4		/* adjust return address to new location */
	pop	{x4, x5}
	mov	pc, x6
#endif
	ret
ENDPROC(setup_c)

/*
 * void relocate_to_adr(unsigned long targetadr)
 *
 * Copy binary to targetadr, relocate code and continue
 * executing at new address.
 */
.section .text.relocate_to_adr
ENTRY(relocate_to_adr)

#if 0
					/* r0: target address */
	push	{r3, r4, r5, r6, r7, r8}
	mov	r7, lr

	mov	r6, r0

	bl	get_runtime_offset

	mov	r5, r0

	ld_var	_text, r0, r4
	mov	r8, r0

	sub	r1, r0, r5		/* r1: from address */

	cmp	r1, r6			/* already at correct address? */
	beq	1f			/* yes, skip copy to new address */

	ld_var	__bss_start, r2, r4

	sub	r2, r2, r0		/* r2: size */
	mov	r0, r6			/* r0: target */

	add	r7, r7, r0		/* adjust return address */
	sub	r7, r7, r1		/* lr += offset */

	bl	memcpy			/* copy binary */

#ifdef CONFIG_MMU
	bl	arm_early_mmu_cache_flush
#endif
	mov	r0,#0
	mcr	p15, 0, r0, c7, c5, 0	/* flush icache */

	ldr	r0,=1f
	sub	r0, r0, r8
	add	r0, r0, r6
	mov	pc, r0			/* jump to relocated address */
1:
	bl	relocate_to_current_adr	/* relocate binary */

	mov	lr, r7

	pop	{r3, r4, r5, r6, r7, r8}
	mov	pc, lr

#endif

ENDPROC(relocate_to_adr)
