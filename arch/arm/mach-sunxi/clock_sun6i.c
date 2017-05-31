/*
 * sun6i specific clock code
 *
 * (C) Copyright 2007-2012
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Tom Cubie <tangliang@allwinnertech.com>
 *
 * (C) Copyright 2013 Luke Kenneth Casson Leighton <lkcl@lkcl.net>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <mach/clock.h>

void clock_init_uart(void)
{
	struct sunxi_ccm_reg *const ccm =
		(struct sunxi_ccm_reg *)SUNXI_CCM_BASE;

	/* uart clock source is apb2 */
	writel(APB2_CLK_SRC_OSC24M|
	       APB2_CLK_RATE_N_1|
	       APB2_CLK_RATE_M(1),
	       &ccm->apb2_div);

	/* open the clock for uart */
	setbits_le32(&ccm->apb2_gate,
		     CLK_GATE_OPEN << (APB2_GATE_UART_SHIFT +
				       CONFIG_CONS_INDEX - 1));

	/* deassert uart reset */
	setbits_le32(&ccm->apb2_reset_cfg,
		     1 << (APB2_RESET_UART_SHIFT +
			   CONFIG_CONS_INDEX - 1));
}

void clock_set_pll3(unsigned int clk)
{
	struct sunxi_ccm_reg * const ccm =
		(struct sunxi_ccm_reg *)SUNXI_CCM_BASE;
	const int m = 8; /* 3 MHz steps just like sun4i, sun5i and sun7i */

	if (clk == 0) {
		clrbits_le32(&ccm->pll3_cfg, CCM_PLL3_CTRL_EN);
		return;
	}

	/* PLL3 rate = 24000000 * n / m */
	writel(CCM_PLL3_CTRL_EN | CCM_PLL3_CTRL_INTEGER_MODE |
	       CCM_PLL3_CTRL_N(clk / (24000000 / m)) | CCM_PLL3_CTRL_M(m),
	       &ccm->pll3_cfg);
}

void clock_set_pll5(unsigned int clk, bool sigma_delta_enable)
{
	struct sunxi_ccm_reg * const ccm =
		(struct sunxi_ccm_reg *)SUNXI_CCM_BASE;
	const int max_n = 32;
	int k = 1, m = 2;

	if (sigma_delta_enable)
		writel(CCM_PLL5_PATTERN, &ccm->pll5_pattern_cfg);

	/* PLL5 rate = 24000000 * n * k / m */
	if (clk > 24000000 * k * max_n / m) {
		m = 1;
		if (clk > 24000000 * k * max_n / m)
			k = 2;
	}
	writel(CCM_PLL5_CTRL_EN |
	       (sigma_delta_enable ? CCM_PLL5_CTRL_SIGMA_DELTA_EN : 0) |
	       CCM_PLL5_CTRL_UPD |
	       CCM_PLL5_CTRL_N(clk / (24000000 * k / m)) |
	       CCM_PLL5_CTRL_K(k) | CCM_PLL5_CTRL_M(m), &ccm->pll5_cfg);

	udelay(5500);
}

unsigned int clock_get_pll3(void)
{
	struct sunxi_ccm_reg *const ccm =
		(struct sunxi_ccm_reg *)SUNXI_CCM_BASE;
	uint32_t rval = readl(&ccm->pll3_cfg);
	int n = ((rval & CCM_PLL3_CTRL_N_MASK) >> CCM_PLL3_CTRL_N_SHIFT) + 1;
	int m = ((rval & CCM_PLL3_CTRL_M_MASK) >> CCM_PLL3_CTRL_M_SHIFT) + 1;

	/* Multiply by 1000 after dividing by m to avoid integer overflows */
	return (24000 * n / m) * 1000;
}

unsigned int clock_get_pll6(void)
{
	struct sunxi_ccm_reg *const ccm =
		(struct sunxi_ccm_reg *)SUNXI_CCM_BASE;
	uint32_t rval = readl(&ccm->pll6_cfg);
	int n = ((rval & CCM_PLL6_CTRL_N_MASK) >> CCM_PLL6_CTRL_N_SHIFT) + 1;
	int k = ((rval & CCM_PLL6_CTRL_K_MASK) >> CCM_PLL6_CTRL_K_SHIFT) + 1;
	return 24000000 * n * k / 2;
}

unsigned int clock_get_mipi_pll(void)
{
	struct sunxi_ccm_reg *const ccm =
		(struct sunxi_ccm_reg *)SUNXI_CCM_BASE;
	uint32_t rval = readl(&ccm->mipi_pll_cfg);
	unsigned int n = ((rval & CCM_MIPI_PLL_CTRL_N_MASK) >> CCM_MIPI_PLL_CTRL_N_SHIFT) + 1;
	unsigned int k = ((rval & CCM_MIPI_PLL_CTRL_K_MASK) >> CCM_MIPI_PLL_CTRL_K_SHIFT) + 1;
	unsigned int m = ((rval & CCM_MIPI_PLL_CTRL_M_MASK) >> CCM_MIPI_PLL_CTRL_M_SHIFT) + 1;
	unsigned int src = clock_get_pll3();

	/* Multiply by 1000 after dividing by m to avoid integer overflows */
	return ((src / 1000) * n * k / m) * 1000;
}

void clock_set_de_mod_clock(u32 *clk_cfg, unsigned int hz)
{
	int pll = clock_get_pll6() * 2;
	int div = 1;

	while ((pll / div) > hz)
		div++;

	writel(CCM_DE_CTRL_GATE | CCM_DE_CTRL_PLL6_2X | CCM_DE_CTRL_M(div),
	       clk_cfg);
}
