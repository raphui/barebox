/*
 * Copyright (C) 2016 Raphaël Poggi <poggi.raph@gmail.com>
 *
 * GPLv2 only
 */

#include <common.h>
#include <init.h>
#include <asm/armlinux.h>
#include <asm/system_info.h>
//#include <mach/devices.h>
#include <environment.h>
#include <linux/sizes.h>
#include <io.h>
#include <envfs.h>
#include <globalvar.h>
#include <asm/mmu.h>

//static int pine64_plus_mem_init(void)
//{
//	pine64_plus_add_ddram(SZ_1G);
//
//	return 0;
//}
//mem_initcall(pine64_plus_mem_init);

//static int pine64_plus_env_init(void)
//{
//	add_cfi_flash_device(0, 0x00000000, SZ_128M, 0);
//
//	devfs_add_partition("nor0", 0x00000, 0x40000, DEVFS_PARTITION_FIXED, "self0");
//	devfs_add_partition("nor0", 0x40000, 0x20000, DEVFS_PARTITION_FIXED, "env0");
//
//	if (IS_ENABLED(CONFIG_DEFAULT_ENVIRONMENT_GENERIC))
//		defaultenv_append_directory(defaultenv_pine64_plus);
//
//	return 0;
//}
//device_initcall(pine64_plus_env_init);

//static int pine64_plus_console_init(void)
//{
//	pine64_plus_register_uart(0);
//
//	return 0;
//}
//console_initcall(pine64_plus_console_init);

static int pine64_plus_core_init(void)
{
	char *hostname = "pine64";

	barebox_set_model("ARM Pine64");
	barebox_set_hostname(hostname);

	return 0;
}
postcore_initcall(pine64_plus_core_init);

#ifdef CONFIG_MMU
static int pine64_plus_mmu_enable(void)
{
	/* Mapping all periph and flash range */
	arch_remap_range((void *)0x00000000, 0x40000000, DEV_MEM);

	mmu_enable();

	return 0;
}
postmmu_initcall(pine64_plus_mmu_enable);
#endif
