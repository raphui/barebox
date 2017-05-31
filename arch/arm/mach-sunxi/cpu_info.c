/*
 * (C) Copyright 2007-2011
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Tom Cubie <tangliang@allwinnertech.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <mach/cpu.h>
#include <mach/clock.h>
#include <errno.h>

#ifdef CONFIG_DISPLAY_CPUINFO
int print_cpuinfo(void)
{
	puts("CPU:   Allwinner A64 (SUN50I)\n");

	return 0;
}
#endif
