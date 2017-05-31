/*
 * (C) Copyright 2015 Hans de Goede <hdegoede@redhat.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _SUNXI_CPU_H
#define _SUNXI_CPU_H

#if defined(CONFIG_MACH_SUN9I)
#include <mach/cpu_sun9i.h>
#else
#include <mach/cpu_sun4i.h>
#endif

#endif /* _SUNXI_CPU_H */
