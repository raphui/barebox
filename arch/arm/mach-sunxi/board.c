/*
 * (C) Copyright 2012 Henrik Nordstrom <henrik@henriknordstrom.net>
 *
 * (C) Copyright 2007-2011
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Tom Cubie <tangliang@allwinnertech.com>
 *
 * Some init for sunxi platform.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
//#include <mmc.h>
//#include <serial.h>
//#include <asm/gpio.h>
#include <asm/io.h>
#include <mach/clock.h>
#include <mach/gpio.h>
//#include <mach/spl.h>
//#include <mach/sys_proto.h>
//#include <mach/timer.h>
//#include <mach/tzpc.h>
//#include <mach/mmc.h>

#include <linux/compiler.h>

#ifdef CONFIG_MACH_SUN50I
#include <asm/armv8/mmu.h>

static struct mm_region sunxi_mem_map[] = {
	{
		/* SRAM, MMIO regions */
		.virt = 0x0UL,
		.phys = 0x0UL,
		.size = 0x40000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE
	}, {
		/* RAM */
		.virt = 0x40000000UL,
		.phys = 0x40000000UL,
		.size = 0x80000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) |
			 PTE_BLOCK_INNER_SHARE
	}, {
		/* List terminator */
		0,
	}
};
struct mm_region *mem_map = sunxi_mem_map;
#endif

static int gpio_init(void)
{
	sunxi_gpio_set_cfgpin(SUNXI_GPB(8), SUN50I_GPB_UART0);
	sunxi_gpio_set_cfgpin(SUNXI_GPB(9), SUN50I_GPB_UART0);
	sunxi_gpio_set_pull(SUNXI_GPB(9), SUNXI_GPIO_PULL_UP);

	return 0;
}

void s_init(void)
{
	clock_init();
//	timer_init();
	gpio_init();
}
