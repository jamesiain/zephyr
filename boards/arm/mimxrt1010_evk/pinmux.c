/*
 * Copyright (c) 2019, NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <fsl_iomuxc.h>
#include <fsl_gpio.h>

static int mimxrt1010_evk_init(struct device *dev)
{
	ARG_UNUSED(dev);

	CLOCK_EnableClock(kCLOCK_Iomuxc);
	CLOCK_EnableClock(kCLOCK_IomuxcSnvs);

#if DT_NODE_HAS_STATUS(DT_NODELABEL(gpio1), okay)
	IOMUXC_SetPinMux(IOMUXC_GPIO_11_GPIOMUX_IO11, 0);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_11_GPIOMUX_IO11,
				IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_PUE(1) |
				IOMUXC_SW_PAD_CTL_PAD_PUS(2) |
				IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
				IOMUXC_SW_PAD_CTL_PAD_DSE(4));
	IOMUXC_GPR->GPR26 &= ~(IOMUXC_GPR_GPR26_GPIO_SEL(1 << 11));
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(gpio2), okay)
	IOMUXC_SetPinMux(IOMUXC_GPIO_SD_05_GPIO2_IO05, 0);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_05_GPIO2_IO05,
				IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_PUE(1) |
				IOMUXC_SW_PAD_CTL_PAD_PUS(2) |
				IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
				IOMUXC_SW_PAD_CTL_PAD_DSE(4));
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(lpuart1), okay)
	/* LPUART1 TX/RX */
	IOMUXC_SetPinMux(IOMUXC_GPIO_09_LPUART1_RXD, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_10_LPUART1_TXD, 0);

	IOMUXC_SetPinConfig(IOMUXC_GPIO_09_LPUART1_RXD,
				IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
				IOMUXC_SW_PAD_CTL_PAD_DSE(6));

	IOMUXC_SetPinConfig(IOMUXC_GPIO_10_LPUART1_TXD,
				IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
				IOMUXC_SW_PAD_CTL_PAD_DSE(6));
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(lpi2c1), okay)
	/* LPI2C1 SCL, SDA */
	IOMUXC_SetPinMux(IOMUXC_GPIO_01_LPI2C1_SDA, 1);
	IOMUXC_SetPinMux(IOMUXC_GPIO_02_LPI2C1_SCL, 1);

	IOMUXC_SetPinConfig(IOMUXC_GPIO_02_LPI2C1_SCL,
				IOMUXC_SW_PAD_CTL_PAD_PUS(3) |
				IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_ODE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
				IOMUXC_SW_PAD_CTL_PAD_DSE(6));

	IOMUXC_SetPinConfig(IOMUXC_GPIO_01_LPI2C1_SDA,
				IOMUXC_SW_PAD_CTL_PAD_PUS(3) |
				IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_ODE_MASK |
				IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
				IOMUXC_SW_PAD_CTL_PAD_DSE(6));
#endif

	return 0;
}

SYS_INIT(mimxrt1010_evk_init, PRE_KERNEL_1, 0);
