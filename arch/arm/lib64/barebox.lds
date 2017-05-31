/*
 *
 * Automatically generated file; DO NOT EDIT.
 * Barebox/arm 2016.11.0 Configuration
 *
 */
/*
 * Helper macros to use CONFIG_ options in C expressions. Note that
 * these only work with boolean and tristate options.
 */
/*
 * Getting something that works in C and CPP for an arg that may or may
 * not be defined is tricky.  Here, if we have "#define CONFIG_BOOGER 1"
 * we match on the placeholder define, insert the "0," for arg1 and generate
 * the triplet (0, 1, 0).  Then the last step cherry picks the 2nd arg (a one).
 * When CONFIG_BOOGER is not defined, we generate a (... 1, 0) pair, and when
 * the last step cherry picks the 2nd arg, we get a zero.
 */
/*
 * IS_ENABLED(CONFIG_FOO) evaluates to 1 if CONFIG_FOO is set to 'y' or 'm',
 * 0 otherwise.
 *
 */
/*
 * IS_BUILTIN(CONFIG_FOO) evaluates to 1 if CONFIG_FOO is set to 'y', 0
 * otherwise. For boolean options, this is equivalent to
 * IS_ENABLED(CONFIG_FOO).
 */
/*
 * IS_MODULE(CONFIG_FOO) evaluates to 1 if CONFIG_FOO is set to 'm', 0
 * otherwise.
 */
/*
 * (C) Copyright 2000-2004
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *
 */
/*
 * Align to a 32 byte boundary equal to the
 * alignment gcc 4.5 uses for a struct
 */
/* Indirect stringification.  Doing two levels allows the parameter to be a
 * macro itself.  For example, compile with -DFOO=bar, __stringify(FOO)
 * converts to "bar".
 */
/* use 2 ASSERT because ld can not accept '"size" "10"' format */
OUTPUT_FORMAT("elf64-littleaarch64", "elf64-littleaarch64", "elf64-littleaarch64")
OUTPUT_ARCH(aarch64)
ENTRY(start)
SECTIONS
{
 . = 0x41000000;

 . = ALIGN(4);
 .text :
 {
  _stext = .;
  _text = .;
  *(.text_entry*)
  __bare_init_start = .;
  *(.text_bare_init*)
  __bare_init_end = .;
  __exceptions_start = .;
  KEEP(*(.text_exceptions*))
  __exceptions_stop = .;
  *(.text*)
 }
 _barebox_bare_init_size = __bare_init_end - _text; ASSERT(_barebox_bare_init_size < 0x01000000, "Barebox bare_init size > ") ASSERT(_barebox_bare_init_size < 0x01000000, "0x01000000")
 . = ALIGN(4);
 .rodata : { *(.rodata*) }
 _etext = .; /* End of text and rodata section */
 _sdata = .;
 . = ALIGN(4);
 .data : { *(.data*) }
 .barebox_imd : { KEEP(*(.barebox_imd_start)) KEEP(*(.barebox_imd_1*)) *(.barebox_imd_0*) KEEP(*(.barebox_imd_end)) }
 . = .;
 __barebox_cmd_start = .;
 .barebox_cmd : { KEEP(*(SORT_BY_NAME(.barebox_cmd*))) }
 __barebox_cmd_end = .;
 __barebox_magicvar_start = .;
 .barebox_magicvar : { KEEP(*(SORT_BY_NAME(.barebox_magicvar*))) }
 __barebox_magicvar_end = .;
 __barebox_initcalls_start = .;
 .barebox_initcalls : { KEEP(*(.initcall.0)) KEEP(*(.initcall.1)) KEEP(*(.initcall.2)) KEEP(*(.initcall.3)) KEEP(*(.initcall.4)) KEEP(*(.initcall.5)) KEEP(*(.initcall.6)) KEEP(*(.initcall.7)) KEEP(*(.initcall.8)) KEEP(*(.initcall.9)) KEEP(*(.initcall.10)) KEEP(*(.initcall.11)) KEEP(*(.initcall.12)) KEEP(*(.initcall.13)) KEEP(*(.initcall.14)) }
 __barebox_initcalls_end = .;
 __barebox_exitcalls_start = .;
 .barebox_exitcalls : { KEEP(*(.exitcall.0)) KEEP(*(.exitcall.1)) KEEP(*(.exitcall.2)) KEEP(*(.exitcall.3)) KEEP(*(.exitcall.4)) KEEP(*(.exitcall.5)) KEEP(*(.exitcall.6)) }
 __barebox_exitcalls_end = .;
 __usymtab_start = .;
 __usymtab : { KEEP(*(__usymtab)) }
 __usymtab_end = .;
 .oftables : { . = ALIGN(8); __clk_of_table_start = .; KEEP(*(.__clk_of_table)); KEEP(*(.__clk_of_table_end)); __clk_of_table_end = .; }
 .dtb : { . = ALIGN(8); __dtb_start = .; KEEP(*(.dtb.rodata.*)); __dtb_end = .; }
 .rel.dyn : {
  __rel_dyn_start = .;
  *(.rel*)
  __rel_dyn_end = .;
 }
 .dynsym : {
  __dynsym_start = .;
  *(.dynsym)
  __dynsym_end = .;
 }
 _edata = .;
 . = ALIGN(4);
 __bss_start = .;
 .bss : { *(.bss*) }
 __bss_stop = .;
 _end = .;
 _barebox_image_size = __bss_start - 0x41000000;
}
