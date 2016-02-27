/*
 * (c) 2016 Raphaël Poggi <poggi.raph@gmail.com>
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

#include <asm/system.h>
#include <asm-generic/io.h>
#include <common.h>
#include <init.h>
#include <mach/stm32f746.h>
#include <mach/stm32_rcc.h>
#include <mach/stm32_pwr.h>

#define HSE_STARTUP_TIMEOUT	0x5000

#define PLL_M		10
#define PLL_Q		2
#define PLL_N		210
#define PLL_P		2

static int stm32_set_sys_clock(void)
{
	unsigned int timeout = HSE_STARTUP_TIMEOUT;
	unsigned int hse_status = 0;
	unsigned int val;

	/* Enable HSE */
	val = readl(RCC_BASE + RCC_CR);
	val |= RCC_CR_HSEON;
	writel(val, RCC_BASE + RCC_CR);

	/* Wait till HSE is ready and if Time out is reached exit */
	do
	{
		val = readl(RCC_BASE + RCC_CR);
	} while (!(val & RCC_CR_HSERDY) && timeout--);

	val = readl(RCC_BASE + RCC_CR);

	if (val & RCC_CR_HSERDY) {
		/* Select regulator voltage output Scale 1 mode */
		val = readl(RCC_BASE + RCC_APB1ENR);
		val |= RCC_APB1ENR_PWREN;
		writel(val, RCC_BASE + RCC_APB1ENR);

		val = readl(PWR_BASE + PWR_CR);
		val |= PWR_CR_VOS;
		writel(val, PWR_BASE + PWR_CR);

		/* HCLK = SYSCLK / 1*/
		val = readl(RCC_BASE + RCC_CFGR);
		val |= RCC_CFGR_HPRE_DIV1;
		writel(val, RCC_BASE + RCC_CFGR);

		/* PCLK2 = HCLK / 2*/
		val = readl(RCC_BASE + RCC_CFGR);
		val |= RCC_CFGR_PPRE2_DIV2;
		writel(val, RCC_BASE + RCC_CFGR);

		/* PCLK1 = HCLK / 4*/
		val = readl(RCC_BASE + RCC_CFGR);
		val |= RCC_CFGR_PPRE1_DIV4;
		writel(val, RCC_BASE + RCC_CFGR);

		/* Configure the main PLL */
		writel(PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
			(RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24), RCC_BASE + RCC_PLLCFGR);

		/* Enable the main PLL */
		val = readl(RCC_BASE + RCC_CR);
		val |= RCC_CR_PLLON;
		writel(val, RCC_BASE + RCC_CR);

		/* Wait till the main PLL is ready */
		val = readl(RCC_BASE + RCC_CR);
		while (!(val & RCC_CR_PLLRDY))
			val = readl(RCC_BASE + RCC_CR);

		/* Enable the Over-drive to extend the clock frequency to 180 Mhz */
		val = readl(PWR_BASE + PWR_CR);
		val |= PWR_CR_ODEN;
		writel(val, PWR_BASE + PWR_CR);

		val = readl(PWR_BASE + PWR_CSR);
		while (!(val & PWR_CSR_ODRDY))
			val = readl(PWR_BASE + PWR_CSR);
	
		val = readl(PWR_BASE + PWR_CR);
		val |= PWR_CR_ODSWEN;
		writel(val, PWR_BASE + PWR_CR);

		val = readl(PWR_BASE + PWR_CSR);
		while (!(val & PWR_CSR_ODSWRDY))
			val = readl(PWR_BASE + PWR_CSR);

		/* Configure Flash prefetch, Instruction cache, Data cache and wait state */
//		FLASH->ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;


		/* Select the main PLL as system clock source */
		val = readl(RCC_BASE + RCC_CFGR);
		val &= ~RCC_CFGR_SW;
		writel(val, RCC_BASE + RCC_CFGR);

		val = readl(RCC_BASE + RCC_CFGR);
		val |= RCC_CFGR_SW_PLL;
		writel(val, RCC_BASE + RCC_CFGR);

		/* Wait till the main PLL is used as system clock source */
		val = readl(RCC_BASE + RCC_CFGR);
		while ((val & RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
			val = readl(RCC_BASE + RCC_CFGR);

	}
	else
		hang();	
}

static int stm32_init(void)
{
	unsigned int val;

	/* Reset RCC clock */
	val = readl(RCC_BASE + RCC_CR);
	val |= RCC_CR_HSION;
	writel(val, RCC_BASE + RCC_CFGR);

	/* Reset HSEON, CSSON and PLLON bits */
	val = readl(RCC_BASE + RCC_CR);
	val &= 0xFEF6FFFF;
	writel(val, RCC_BASE + RCC_CR);

	/* Reset PLLCFGR register */
	writel(0x24003010, RCC_BASE + RCC_PLLCFGR);

	/* Reset HSEBYP bit */
	val = readl(RCC_BASE + RCC_CR);
	val &= 0xFFFBFFFF;
	writel(val, RCC_BASE + RCC_CR);

	/* Disable all interrupts */
	writel(0x0, RCC_BASE + RCC_CIR);

	stm32_set_sys_clock();
	
#define SCS_BASE                        (unsigned int) (0xE000E000)                                 /* System Control Space Base Address */
#define SCB_BASE                        (SCS_BASE + 0x0D00)                                     /* System Control Block Base Address */
#define SCB_VTOR                        (unsigned int) (SCB_BASE + 0x008)                /* Vector Table Offset Register */
	writel(FLASH_BASE, SCB_VTOR);

	return 0;
}
postcore_initcall(stm32_init);
