/*
 * cpuinfo.c - Show information about cp15 registers
 *
 * Copyright (c) 2009 Sascha Hauer <s.hauer@pengutronix.de>, Pengutronix
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <common.h>
#include <command.h>
#include <complete.h>

#define CPU_ARCH_UNKNOWN	0
#define CPU_ARCH_ARMv8		10

#define ARM_CPU_PART_CORTEX_A53	    0xD03
#define ARM_CPU_PART_CORTEX_A57	    0xD07

static void decode_cache(unsigned long size)
{
	int linelen = 1 << ((size & 0x3) + 3);
	int mult = 2 + ((size >> 2) & 1);
	int cache_size = mult << (((size >> 6) & 0x7) + 8);

	if (((size >> 2) & 0xf) == 1)
		printf("no cache\n");
	else
		printf("%d bytes (linelen = %d)\n", cache_size, linelen);
}

static int do_cpuinfo(int argc, char *argv[])
{
	unsigned long mainid, cache, cr;
	char *architecture, *implementer;
	int i;
	int cpu_arch;

	__asm__ __volatile__(
		"mrs	%0, midr_el1\n"
		: "=r" (mainid)
		:
		: "memory");

	switch (mainid >> 24) {
	case 0x41:
		implementer = "ARM";
		break;
	case 0x44:
		implementer = "Digital Equipment Corp.";
		break;
	case 0x40:
		implementer = "Motorola - Freescale Semiconductor Inc.";
		break;
	case 0x56:
		implementer = "Marvell Semiconductor Inc.";
		break;
	case 0x69:
		implementer = "Intel Corp.";
		break;
	default:
		implementer = "Unknown";
	}

	if ((mainid & 0x000f0000) == 0x000f0000) {
		unsigned int mmfr0;

		asm("mrs	%0, id_mmfr0_el1"
		    : "=r" (mmfr0));
		if ((mmfr0 & 0x0000000f) >= 0x00000005 ||
		    (mmfr0 & 0x000000f0) >= 0x00000000)
			cpu_arch = CPU_ARCH_ARMv8;
		else
			cpu_arch = CPU_ARCH_UNKNOWN;
	} else
		cpu_arch = CPU_ARCH_UNKNOWN;

	switch (cpu_arch) {
	case CPU_ARCH_ARMv8:
		architecture = "v8";
		break;
	case CPU_ARCH_UNKNOWN:
	default:
		architecture = "Unknown";
	}

	printf("implementer: %s\narchitecture: %s\n",
			implementer, architecture);

	if (cpu_arch == CPU_ARCH_ARMv8) {
		unsigned int major, minor;
		char *part;
		major = (mainid >> 20) & 0xf;
		minor = mainid & 0xf;
		switch ((mainid >> 4) & 0xfff) {
		case ARM_CPU_PART_CORTEX_A53:
			part = "Cortex-A53";
			break;
		case ARM_CPU_PART_CORTEX_A57:
			part = "Cortex-A57";
			break;
		default:
			part = "unknown";
		}
		printf("core: %s r%up%u\n", part, major, minor);
	}

	if (cache & (1 << 24)) {
		/* separate I/D cache */
		printf("I-cache: ");
		decode_cache(cache & 0xfff);
		printf("D-cache: ");
		decode_cache((cache >> 12) & 0xfff);
	} else {
		/* unified I/D cache */
		printf("cache: ");
		decode_cache(cache & 0xfff);
	}

	return 0;
}

BAREBOX_CMD_START(cpuinfo)
	.cmd            = do_cpuinfo,
	BAREBOX_CMD_DESC("show info about CPU")
	BAREBOX_CMD_GROUP(CMD_GRP_INFO)
	BAREBOX_CMD_COMPLETE(empty_complete)
BAREBOX_CMD_END

