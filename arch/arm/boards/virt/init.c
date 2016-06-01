/*
 * Copyright (C) 2016 Raphaël Poggi <poggi.raph@gmail.com>
 *
 * GPLv2 only
 */

#include <common.h>
#include <init.h>
#include <asm/armlinux.h>
#include <asm/system_info.h>
#include <mach/devices.h>
#include <environment.h>
#include <linux/sizes.h>
#include <io.h>
#include <globalvar.h>
#include <asm/mmu.h>

static int virt_mem_init(void)
{
	virt_add_ddram(SZ_512M);

	add_cfi_flash_device(0, 0x00000000, SZ_4M, 0);

	devfs_add_partition("nor0", 0x00000, 0x40000, DEVFS_PARTITION_FIXED, "self0");
	devfs_add_partition("nor0", 0x40000, 0x20000, DEVFS_PARTITION_FIXED, "env0");

	return 0;
}
mem_initcall(virt_mem_init);

static int virt_console_init(void)
{
	virt_register_uart(0);

	return 0;
}
console_initcall(virt_console_init);

static int virt_core_init(void)
{
	char *hostname = "virt";

	if (cpu_is_cortex_a53())
		hostname = "virt-a53";
	else if (cpu_is_cortex_a57())
		hostname = "virt-a57";

	barebox_set_model("ARM QEMU virt");
	barebox_set_hostname(hostname);

	return 0;
}
postcore_initcall(virt_core_init);

static int virt_mmu_enable(void)
{
	/* Mapping all periph range */
	arch_remap_range(0x09000000, 0x01000000, PMD_SECT_DEF_CACHED);

	/* Mapping all flash range */
	arch_remap_range(0x00000000, 0x08000000, PMD_SECT_DEF_CACHED);

	mmu_enable();

	return 0;
}
postmmu_initcall(virt_mmu_enable);
