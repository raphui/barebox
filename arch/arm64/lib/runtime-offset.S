#include <linux/linkage.h>
#include <asm/assembler.h>

.section ".text_bare_init","ax"

/*
 * Get the offset between the link address and the address
 * we are currently running at.
 */
ENTRY(get_runtime_offset)
1:	adr x0, 1b
	adr x1, get_runtime_offset
	subs x0, x1, x0
	subs x0, x0, #1
	ret

linkadr:
.word get_runtime_offset
ENDPROC(get_runtime_offset)

.globl __ld_var_base
__ld_var_base:

/*
 * Functions to calculate selected linker supplied variables during runtime.
 * This is needed for relocatable binaries when the linker variables are
 * needed before finxing up the relocations.
 */
.macro ld_var_entry name
	ENTRY(__ld_var_\name)
		ldr x0, __\name
		b 1f
	__\name: .word \name - __ld_var_base
	ENDPROC(__ld_var_\name)
.endm

ld_var_entry _text
ld_var_entry __rel_dyn_start
ld_var_entry __rel_dyn_end
ld_var_entry __dynsym_start
ld_var_entry __dynsym_end
ld_var_entry _barebox_image_size
ld_var_entry __bss_start
ld_var_entry __bss_stop
#ifdef __PBL__
ld_var_entry __image_end
#endif

1:
	ldr x1, =__ld_var_base
	adds x0, x0, x1
	ret
