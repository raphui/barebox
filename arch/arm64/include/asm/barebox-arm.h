/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Alex Zuepke <azu@sysgo.de>
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
 */

#ifndef _BAREBOX_ARM_H_
#define _BAREBOX_ARM_H_

#include <linux/sizes.h>
#include <asm-generic/memory_layout.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/compiler.h>
#include <asm/barebox-arm-head.h>

/* cpu/.../cpu.c */
int	cleanup_before_linux(void);

/* arch/<arch>board(s)/.../... */
int	board_init(void);
int	dram_init(void);

extern char __exceptions_start[], __exceptions_stop[];

void board_init_lowlevel(void);
uint32_t get_runtime_offset(void);

void setup_c(void);
void relocate_to_current_adr(void);
void relocate_to_adr(unsigned long target);
void __noreturn barebox_arm_entry(unsigned long membase, unsigned long memsize, void *boarddata);

struct barebox_arm_boarddata {
#define BAREBOX_ARM_BOARDDATA_MAGIC	0xabe742c3
	u32 magic;
	u32 machine; /* machine number to pass to barebox. This may or may
		      * not be a ARM machine number registered on arm.linux.org.uk.
		      * It must only be unique across barebox. Please use a number
		      * that do not potientially clashes with registered machines,
		      * i.e. use a number > 0x10000.
		      */
};

/*
 * Create a boarddata struct at given address. Suitable to be passed
 * as boarddata to barebox_arm_entry(). The machine can be retrieved
 * later with barebox_arm_machine().
 */
static inline void boarddata_create(void *adr, u32 machine)
{
	struct barebox_arm_boarddata *bd = adr;

	bd->magic = BAREBOX_ARM_BOARDDATA_MAGIC;
	bd->machine = machine;
}

u32 barebox_arm_machine(void);

struct barebox_arm_boarddata_compressed_dtb {
#define BAREBOX_ARM_BOARDDATA_COMPRESSED_DTB_MAGIC 0x7b66bcbd
	u32 magic;
	u32 datalen;
	u32 datalen_uncompressed;
};

struct barebox_arm_boarddata *barebox_arm_get_boarddata(void);

#if defined(CONFIG_RELOCATABLE) && defined(CONFIG_ARM_EXCEPTIONS)
void arm_fixup_vectors(void);
#else
static inline void arm_fixup_vectors(void)
{
}
#endif

void *barebox_arm_boot_dtb(void);

static inline unsigned long arm_mem_stack(unsigned long membase,
					  unsigned long endmem)
{
	return endmem - STACK_SIZE;
}

static inline unsigned long arm_mem_ttb(unsigned long membase,
					unsigned long endmem)
{
	endmem = arm_mem_stack(membase, endmem);
	endmem &= ~(SZ_16K - 1);
	endmem -= SZ_16K;

	return endmem;
}

static inline unsigned long arm_mem_early_malloc(unsigned long membase,
						 unsigned long endmem)
{
	return arm_mem_ttb(membase, endmem) - SZ_128K;
}

static inline unsigned long arm_mem_early_malloc_end(unsigned long membase,
						     unsigned long endmem)
{
	return arm_mem_ttb(membase, endmem);
}

static inline unsigned long arm_mem_ramoops(unsigned long membase,
					    unsigned long endmem)
{
	endmem = arm_mem_ttb(membase, endmem);
#ifdef CONFIG_FS_PSTORE_RAMOOPS
	endmem -= CONFIG_FS_PSTORE_RAMOOPS_SIZE;
	endmem &= ~(SZ_4K - 1); /* Align to 4K */
#endif

	return endmem;
}

static inline unsigned long arm_mem_barebox_image(unsigned long membase,
						  unsigned long endmem,
						  unsigned long size)
{
	endmem = arm_mem_ramoops(membase, endmem);

	if (IS_ENABLED(CONFIG_RELOCATABLE)) {
		endmem -= size;
		endmem &= ~(SZ_1M - 1);
	}

	return endmem;
}

#define ENTRY_FUNCTION(name, arg0, arg1, arg2)				\
	static void __##name(uint32_t, uint32_t, uint32_t);		\
									\
	void __naked __section(.text_head_entry_##name)	name		\
				(uint32_t r0, uint32_t r1, uint32_t r2)	\
		{							\
			__barebox_arm_head();				\
			__##name(r0, r1, r2);				\
		}							\
		static void __naked noinline __##name			\
			(uint32_t arg0, uint32_t arg1, uint32_t arg2)



#endif	/* _BAREBOX_ARM_H_ */
