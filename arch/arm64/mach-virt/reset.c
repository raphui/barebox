/*
 * Copyright (C) 2016 Raphaël Poggi <poggi.raph@gmail.com>
 *
 * GPLv2 only
 */

#include <common.h>
#include <io.h>
#include <init.h>
#include <restart.h>
#include <mach/devices.h>

static void virt_reset_soc(struct restart_handler *rst)
{
	hang();
}

static int restart_register_feature(void)
{
	restart_handler_register_fn(virt_reset_soc);

	return 0;
}
coredevice_initcall(restart_register_feature);
