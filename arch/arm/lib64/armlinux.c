/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * Copyright (C) 2001  Erik Mouw (J.A.K.Mouw@its.tudelft.nl)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 */

#include <boot.h>
#include <common.h>
#include <command.h>
#include <driver.h>
#include <environment.h>
#include <image.h>
#include <init.h>
#include <fs.h>
#include <linux/list.h>
#include <xfuncs.h>
#include <malloc.h>
#include <fcntl.h>
#include <errno.h>
#include <memory.h>
#include <of.h>
#include <magicvar.h>

#include <asm/byteorder.h>
#include <asm/setup.h>
#include <asm/barebox-arm.h>
#include <asm/armlinux.h>
#include <asm/system.h>

static void *armlinux_bootparams = NULL;

static int armlinux_architecture;
static u32 armlinux_system_rev;
static u64 armlinux_system_serial;

BAREBOX_MAGICVAR(armlinux_architecture, "ARM machine ID");
BAREBOX_MAGICVAR(armlinux_system_rev, "ARM system revision");
BAREBOX_MAGICVAR(armlinux_system_serial, "ARM system serial");

void armlinux_set_architecture(int architecture)
{
	export_env_ull("armlinux_architecture", architecture);
	armlinux_architecture = architecture;
}

int armlinux_get_architecture(void)
{
	getenv_uint("armlinux_architecture", &armlinux_architecture);

	return armlinux_architecture;
}

void armlinux_set_revision(unsigned int rev)
{
	export_env_ull("armlinux_system_rev", rev);
	armlinux_system_rev = rev;
}

unsigned int armlinux_get_revision(void)
{
	getenv_uint("armlinux_system_rev", &armlinux_system_rev);

	return armlinux_system_rev;
}

void armlinux_set_serial(u64 serial)
{
	export_env_ull("armlinux_system_serial", serial);
	armlinux_system_serial = serial;
}

u64 armlinux_get_serial(void)
{
	getenv_ull("armlinux_system_serial", &armlinux_system_serial);

	return armlinux_system_serial;
}

void armlinux_set_bootparams(void *params)
{
	armlinux_bootparams = params;
}

void start_linux(void *adr, int swap, unsigned long initrd_address,
		unsigned long initrd_size, void *oftree)
{
	void (*kernel)(void *dtb) = adr;

	shutdown_barebox();

	kernel(oftree);
}
