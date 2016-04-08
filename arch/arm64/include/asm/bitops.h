/*
 * Copyright (C) 2012 ARM Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __ASM_BITOPS_H
#define __ASM_BITOPS_H

#include <linux/compiler.h>

#ifndef _LINUX_BITOPS_H
#error only <linux/bitops.h> can be included directly
#endif

/*
 * Little endian assembly atomic bitops.
 */
extern void set_bit(int nr, volatile unsigned long *p);
extern void clear_bit(int nr, volatile unsigned long *p);
extern void change_bit(int nr, volatile unsigned long *p);
extern int test_and_set_bit(int nr, volatile unsigned long *p);
extern int test_and_clear_bit(int nr, volatile unsigned long *p);
extern int test_and_change_bit(int nr, volatile unsigned long *p);

#include <asm-generic/bitops/__ffs.h>
#include <asm-generic/bitops/ffs.h>
#include <asm-generic/bitops/__fls.h>
#include <asm-generic/bitops/fls.h>

#include <asm-generic/bitops/ffz.h>
#include <asm-generic/bitops/fls64.h>
#include <asm-generic/bitops/find.h>

#include <asm-generic/bitops/hweight.h>

#include <asm-generic/bitops/ops.h>

#endif /* __ASM_BITOPS_H */
