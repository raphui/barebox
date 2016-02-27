#ifndef STM32_RCC_H
#define STM32_RCC_H

#define RCC_CR		0x0
#define RCC_PLLCFGR	0x4
#define RCC_CFGR	0x8
#define RCC_CIR		0xC
#define RCC_AHB1RST	0x10
#define RCC_AHB2RST	0x14
#define RCC_AHB3RST	0x18
#define RCC_APB1RST	0x20
#define RCC_APB2RST	0x24
#define RCC_AHB1ENR	0x30
#define RCC_AHB2ENR	0x34
#define RCC_AHB3ENR	0x38
#define RCC_APB1ENR	0x40
#define RCC_APB2ENR	0x44
#define RCC_AHB1LPENR	0x50
#define RCC_AHB2LPENR	0x54
#define RCC_AHB3LPENR	0x58
#define RCC_APB1LPENR	0x60
#define RCC_APB2LPENR	0x64
#define RCC_BDCR	0x70
#define RCC_CSR		0x74


/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CR register  ********************/
#define  RCC_CR_HSION                        ((unsigned int)0x00000001)
#define  RCC_CR_HSIRDY                       ((unsigned int)0x00000002)

#define  RCC_CR_HSITRIM                      ((unsigned int)0x000000F8)
#define  RCC_CR_HSITRIM_0                    ((unsigned int)0x00000008)/*!<Bit 0 */
#define  RCC_CR_HSITRIM_1                    ((unsigned int)0x00000010)/*!<Bit 1 */
#define  RCC_CR_HSITRIM_2                    ((unsigned int)0x00000020)/*!<Bit 2 */
#define  RCC_CR_HSITRIM_3                    ((unsigned int)0x00000040)/*!<Bit 3 */
#define  RCC_CR_HSITRIM_4                    ((unsigned int)0x00000080)/*!<Bit 4 */

#define  RCC_CR_HSICAL                       ((unsigned int)0x0000FF00)
#define  RCC_CR_HSICAL_0                     ((unsigned int)0x00000100)/*!<Bit 0 */
#define  RCC_CR_HSICAL_1                     ((unsigned int)0x00000200)/*!<Bit 1 */
#define  RCC_CR_HSICAL_2                     ((unsigned int)0x00000400)/*!<Bit 2 */
#define  RCC_CR_HSICAL_3                     ((unsigned int)0x00000800)/*!<Bit 3 */
#define  RCC_CR_HSICAL_4                     ((unsigned int)0x00001000)/*!<Bit 4 */
#define  RCC_CR_HSICAL_5                     ((unsigned int)0x00002000)/*!<Bit 5 */
#define  RCC_CR_HSICAL_6                     ((unsigned int)0x00004000)/*!<Bit 6 */
#define  RCC_CR_HSICAL_7                     ((unsigned int)0x00008000)/*!<Bit 7 */

#define  RCC_CR_HSEON                        ((unsigned int)0x00010000)
#define  RCC_CR_HSERDY                       ((unsigned int)0x00020000)
#define  RCC_CR_HSEBYP                       ((unsigned int)0x00040000)
#define  RCC_CR_CSSON                        ((unsigned int)0x00080000)
#define  RCC_CR_PLLON                        ((unsigned int)0x01000000)
#define  RCC_CR_PLLRDY                       ((unsigned int)0x02000000)
#define  RCC_CR_PLLI2SON                     ((unsigned int)0x04000000)
#define  RCC_CR_PLLI2SRDY                    ((unsigned int)0x08000000)
#define  RCC_CR_PLLSAION                     ((unsigned int)0x10000000)
#define  RCC_CR_PLLSAIRDY                    ((unsigned int)0x20000000)

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define  RCC_PLLCFGR_PLLM                    ((unsigned int)0x0000003F)
#define  RCC_PLLCFGR_PLLM_0                  ((unsigned int)0x00000001)
#define  RCC_PLLCFGR_PLLM_1                  ((unsigned int)0x00000002)
#define  RCC_PLLCFGR_PLLM_2                  ((unsigned int)0x00000004)
#define  RCC_PLLCFGR_PLLM_3                  ((unsigned int)0x00000008)
#define  RCC_PLLCFGR_PLLM_4                  ((unsigned int)0x00000010)
#define  RCC_PLLCFGR_PLLM_5                  ((unsigned int)0x00000020)

#define  RCC_PLLCFGR_PLLN                     ((unsigned int)0x00007FC0)
#define  RCC_PLLCFGR_PLLN_0                   ((unsigned int)0x00000040)
#define  RCC_PLLCFGR_PLLN_1                   ((unsigned int)0x00000080)
#define  RCC_PLLCFGR_PLLN_2                   ((unsigned int)0x00000100)
#define  RCC_PLLCFGR_PLLN_3                   ((unsigned int)0x00000200)
#define  RCC_PLLCFGR_PLLN_4                   ((unsigned int)0x00000400)
#define  RCC_PLLCFGR_PLLN_5                   ((unsigned int)0x00000800)
#define  RCC_PLLCFGR_PLLN_6                   ((unsigned int)0x00001000)
#define  RCC_PLLCFGR_PLLN_7                   ((unsigned int)0x00002000)
#define  RCC_PLLCFGR_PLLN_8                   ((unsigned int)0x00004000)

#define  RCC_PLLCFGR_PLLP                    ((unsigned int)0x00030000)
#define  RCC_PLLCFGR_PLLP_0                  ((unsigned int)0x00010000)
#define  RCC_PLLCFGR_PLLP_1                  ((unsigned int)0x00020000)

#define  RCC_PLLCFGR_PLLSRC                  ((unsigned int)0x00400000)
#define  RCC_PLLCFGR_PLLSRC_HSE              ((unsigned int)0x00400000)
#define  RCC_PLLCFGR_PLLSRC_HSI              ((unsigned int)0x00000000)

#define  RCC_PLLCFGR_PLLQ                    ((unsigned int)0x0F000000)
#define  RCC_PLLCFGR_PLLQ_0                  ((unsigned int)0x01000000)
#define  RCC_PLLCFGR_PLLQ_1                  ((unsigned int)0x02000000)
#define  RCC_PLLCFGR_PLLQ_2                  ((unsigned int)0x04000000)
#define  RCC_PLLCFGR_PLLQ_3                  ((unsigned int)0x08000000)


/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define  RCC_CFGR_SW                         ((unsigned int)0x00000003)        /*!< SW[1:0] bits (System clock Switch) */
#define  RCC_CFGR_SW_0                       ((unsigned int)0x00000001)        /*!< Bit 0 */
#define  RCC_CFGR_SW_1                       ((unsigned int)0x00000002)        /*!< Bit 1 */

#define  RCC_CFGR_SW_HSI                     ((unsigned int)0x00000000)        /*!< HSI selected as system clock */
#define  RCC_CFGR_SW_HSE                     ((unsigned int)0x00000001)        /*!< HSE selected as system clock */
#define  RCC_CFGR_SW_PLL                     ((unsigned int)0x00000002)        /*!< PLL/PLLP selected as system clock */

/*!< SWS configuration */
#define  RCC_CFGR_SWS                        ((unsigned int)0x0000000C)        /*!< SWS[1:0] bits (System Clock Switch Status) */
#define  RCC_CFGR_SWS_0                      ((unsigned int)0x00000004)        /*!< Bit 0 */
#define  RCC_CFGR_SWS_1                      ((unsigned int)0x00000008)        /*!< Bit 1 */

#define  RCC_CFGR_SWS_HSI                    ((unsigned int)0x00000000)        /*!< HSI oscillator used as system clock */
#define  RCC_CFGR_SWS_HSE                    ((unsigned int)0x00000004)        /*!< HSE oscillator used as system clock */
#define  RCC_CFGR_SWS_PLL                    ((unsigned int)0x00000008)        /*!< PLL/PLLP used as system clock       */

/*!< HPRE configuration */
#define  RCC_CFGR_HPRE                       ((unsigned int)0x000000F0)        /*!< HPRE[3:0] bits (AHB prescaler) */
#define  RCC_CFGR_HPRE_0                     ((unsigned int)0x00000010)        /*!< Bit 0 */
#define  RCC_CFGR_HPRE_1                     ((unsigned int)0x00000020)        /*!< Bit 1 */
#define  RCC_CFGR_HPRE_2                     ((unsigned int)0x00000040)        /*!< Bit 2 */
#define  RCC_CFGR_HPRE_3                     ((unsigned int)0x00000080)        /*!< Bit 3 */

#define  RCC_CFGR_HPRE_DIV1                  ((unsigned int)0x00000000)        /*!< SYSCLK not divided */
#define  RCC_CFGR_HPRE_DIV2                  ((unsigned int)0x00000080)        /*!< SYSCLK divided by 2 */
#define  RCC_CFGR_HPRE_DIV4                  ((unsigned int)0x00000090)        /*!< SYSCLK divided by 4 */
#define  RCC_CFGR_HPRE_DIV8                  ((unsigned int)0x000000A0)        /*!< SYSCLK divided by 8 */
#define  RCC_CFGR_HPRE_DIV16                 ((unsigned int)0x000000B0)        /*!< SYSCLK divided by 16 */
#define  RCC_CFGR_HPRE_DIV64                 ((unsigned int)0x000000C0)        /*!< SYSCLK divided by 64 */
#define  RCC_CFGR_HPRE_DIV128                ((unsigned int)0x000000D0)        /*!< SYSCLK divided by 128 */
#define  RCC_CFGR_HPRE_DIV256                ((unsigned int)0x000000E0)        /*!< SYSCLK divided by 256 */
#define  RCC_CFGR_HPRE_DIV512                ((unsigned int)0x000000F0)        /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define  RCC_CFGR_PPRE1                      ((unsigned int)0x00001C00)        /*!< PRE1[2:0] bits (APB1 prescaler) */
#define  RCC_CFGR_PPRE1_0                    ((unsigned int)0x00000400)        /*!< Bit 0 */
#define  RCC_CFGR_PPRE1_1                    ((unsigned int)0x00000800)        /*!< Bit 1 */
#define  RCC_CFGR_PPRE1_2                    ((unsigned int)0x00001000)        /*!< Bit 2 */

#define  RCC_CFGR_PPRE1_DIV1                 ((unsigned int)0x00000000)        /*!< HCLK not divided */
#define  RCC_CFGR_PPRE1_DIV2                 ((unsigned int)0x00001000)        /*!< HCLK divided by 2 */
#define  RCC_CFGR_PPRE1_DIV4                 ((unsigned int)0x00001400)        /*!< HCLK divided by 4 */
#define  RCC_CFGR_PPRE1_DIV8                 ((unsigned int)0x00001800)        /*!< HCLK divided by 8 */
#define  RCC_CFGR_PPRE1_DIV16                ((unsigned int)0x00001C00)        /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define  RCC_CFGR_PPRE2                      ((unsigned int)0x0000E000)        /*!< PRE2[2:0] bits (APB2 prescaler) */
#define  RCC_CFGR_PPRE2_0                    ((unsigned int)0x00002000)        /*!< Bit 0 */
#define  RCC_CFGR_PPRE2_1                    ((unsigned int)0x00004000)        /*!< Bit 1 */
#define  RCC_CFGR_PPRE2_2                    ((unsigned int)0x00008000)        /*!< Bit 2 */

#define  RCC_CFGR_PPRE2_DIV1                 ((unsigned int)0x00000000)        /*!< HCLK not divided */
#define  RCC_CFGR_PPRE2_DIV2                 ((unsigned int)0x00008000)        /*!< HCLK divided by 2 */
#define  RCC_CFGR_PPRE2_DIV4                 ((unsigned int)0x0000A000)        /*!< HCLK divided by 4 */
#define  RCC_CFGR_PPRE2_DIV8                 ((unsigned int)0x0000C000)        /*!< HCLK divided by 8 */
#define  RCC_CFGR_PPRE2_DIV16                ((unsigned int)0x0000E000)        /*!< HCLK divided by 16 */

/*!< RTCPRE configuration */
#define  RCC_CFGR_RTCPRE                     ((unsigned int)0x001F0000)
#define  RCC_CFGR_RTCPRE_0                   ((unsigned int)0x00010000)
#define  RCC_CFGR_RTCPRE_1                   ((unsigned int)0x00020000)
#define  RCC_CFGR_RTCPRE_2                   ((unsigned int)0x00040000)
#define  RCC_CFGR_RTCPRE_3                   ((unsigned int)0x00080000)
#define  RCC_CFGR_RTCPRE_4                   ((unsigned int)0x00100000)

/*!< MCO1 configuration */
#define  RCC_CFGR_MCO1                       ((unsigned int)0x00600000)
#define  RCC_CFGR_MCO1_0                     ((unsigned int)0x00200000)
#define  RCC_CFGR_MCO1_1                     ((unsigned int)0x00400000)

#define  RCC_CFGR_I2SSRC                     ((unsigned int)0x00800000)

#define  RCC_CFGR_MCO1PRE                    ((unsigned int)0x07000000)
#define  RCC_CFGR_MCO1PRE_0                  ((unsigned int)0x01000000)
#define  RCC_CFGR_MCO1PRE_1                  ((unsigned int)0x02000000)
#define  RCC_CFGR_MCO1PRE_2                  ((unsigned int)0x04000000)

#define  RCC_CFGR_MCO2PRE                    ((unsigned int)0x38000000)
#define  RCC_CFGR_MCO2PRE_0                  ((unsigned int)0x08000000)
#define  RCC_CFGR_MCO2PRE_1                  ((unsigned int)0x10000000)
#define  RCC_CFGR_MCO2PRE_2                  ((unsigned int)0x20000000)

#define  RCC_CFGR_MCO2                       ((unsigned int)0xC0000000)
#define  RCC_CFGR_MCO2_0                     ((unsigned int)0x40000000)
#define  RCC_CFGR_MCO2_1                     ((unsigned int)0x80000000)

/********************  Bit definition for RCC_CIR register  *******************/
#define  RCC_CIR_LSIRDYF                     ((unsigned int)0x00000001)
#define  RCC_CIR_LSERDYF                     ((unsigned int)0x00000002)
#define  RCC_CIR_HSIRDYF                     ((unsigned int)0x00000004)
#define  RCC_CIR_HSERDYF                     ((unsigned int)0x00000008)
#define  RCC_CIR_PLLRDYF                     ((unsigned int)0x00000010)
#define  RCC_CIR_PLLI2SRDYF                  ((unsigned int)0x00000020)
#define  RCC_CIR_PLLSAIRDYF                  ((unsigned int)0x00000040)
#define  RCC_CIR_CSSF                        ((unsigned int)0x00000080)
#define  RCC_CIR_LSIRDYIE                    ((unsigned int)0x00000100)
#define  RCC_CIR_LSERDYIE                    ((unsigned int)0x00000200)
#define  RCC_CIR_HSIRDYIE                    ((unsigned int)0x00000400)
#define  RCC_CIR_HSERDYIE                    ((unsigned int)0x00000800)
#define  RCC_CIR_PLLRDYIE                    ((unsigned int)0x00001000)
#define  RCC_CIR_PLLI2SRDYIE                 ((unsigned int)0x00002000)
#define  RCC_CIR_PLLSAIRDYIE                 ((unsigned int)0x00004000)
#define  RCC_CIR_LSIRDYC                     ((unsigned int)0x00010000)
#define  RCC_CIR_LSERDYC                     ((unsigned int)0x00020000)
#define  RCC_CIR_HSIRDYC                     ((unsigned int)0x00040000)
#define  RCC_CIR_HSERDYC                     ((unsigned int)0x00080000)
#define  RCC_CIR_PLLRDYC                     ((unsigned int)0x00100000)
#define  RCC_CIR_PLLI2SRDYC                  ((unsigned int)0x00200000)
#define  RCC_CIR_PLLSAIRDYC                  ((unsigned int)0x00400000)
#define  RCC_CIR_CSSC                        ((unsigned int)0x00800000)

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define  RCC_AHB1RSTR_GPIOARST               ((unsigned int)0x00000001)
#define  RCC_AHB1RSTR_GPIOBRST               ((unsigned int)0x00000002)
#define  RCC_AHB1RSTR_GPIOCRST               ((unsigned int)0x00000004)
#define  RCC_AHB1RSTR_GPIODRST               ((unsigned int)0x00000008)
#define  RCC_AHB1RSTR_GPIOERST               ((unsigned int)0x00000010)
#define  RCC_AHB1RSTR_GPIOFRST               ((unsigned int)0x00000020)
#define  RCC_AHB1RSTR_GPIOGRST               ((unsigned int)0x00000040)
#define  RCC_AHB1RSTR_GPIOHRST               ((unsigned int)0x00000080)
#define  RCC_AHB1RSTR_GPIOIRST               ((unsigned int)0x00000100)
#define  RCC_AHB1RSTR_GPIOJRST               ((unsigned int)0x00000200)
#define  RCC_AHB1RSTR_GPIOKRST               ((unsigned int)0x00000400)
#define  RCC_AHB1RSTR_CRCRST                 ((unsigned int)0x00001000)
#define  RCC_AHB1RSTR_DMA1RST                ((unsigned int)0x00200000)
#define  RCC_AHB1RSTR_DMA2RST                ((unsigned int)0x00400000)
#define  RCC_AHB1RSTR_DMA2DRST               ((unsigned int)0x00800000)
#define  RCC_AHB1RSTR_ETHMACRST              ((unsigned int)0x02000000)
#define  RCC_AHB1RSTR_OTGHRST                ((unsigned int)0x10000000)

/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define  RCC_AHB2RSTR_DCMIRST                ((unsigned int)0x00000001)
#define  RCC_AHB2RSTR_CRYPRST                ((unsigned int)0x00000010)
#define  RCC_AHB2RSTR_HASHRST                ((unsigned int)0x00000020)
/* maintained for legacy purpose */
#define  RCC_AHB2RSTR_HSAHRST                RCC_AHB2RSTR_HASHRST
#define  RCC_AHB2RSTR_RNGRST                 ((unsigned int)0x00000040)
#define  RCC_AHB2RSTR_OTGFSRST               ((unsigned int)0x00000080)

/********************  Bit definition for RCC_AHB3RSTR register  **************/
#define  RCC_AHB3RSTR_FMCRST                ((unsigned int)0x00000001)

/********************  Bit definition for RCC_APB1RSTR register  **************/
#define  RCC_APB1RSTR_TIM2RST                ((unsigned int)0x00000001)
#define  RCC_APB1RSTR_TIM3RST                ((unsigned int)0x00000002)
#define  RCC_APB1RSTR_TIM4RST                ((unsigned int)0x00000004)
#define  RCC_APB1RSTR_TIM5RST                ((unsigned int)0x00000008)
#define  RCC_APB1RSTR_TIM6RST                ((unsigned int)0x00000010)
#define  RCC_APB1RSTR_TIM7RST                ((unsigned int)0x00000020)
#define  RCC_APB1RSTR_TIM12RST               ((unsigned int)0x00000040)
#define  RCC_APB1RSTR_TIM13RST               ((unsigned int)0x00000080)
#define  RCC_APB1RSTR_TIM14RST               ((unsigned int)0x00000100)
#define  RCC_APB1RSTR_WWDGRST                ((unsigned int)0x00000800)
#define  RCC_APB1RSTR_SPI2RST                ((unsigned int)0x00004000)
#define  RCC_APB1RSTR_SPI3RST                ((unsigned int)0x00008000)
#define  RCC_APB1RSTR_USART2RST              ((unsigned int)0x00020000)
#define  RCC_APB1RSTR_USART3RST              ((unsigned int)0x00040000)
#define  RCC_APB1RSTR_UART4RST               ((unsigned int)0x00080000)
#define  RCC_APB1RSTR_UART5RST               ((unsigned int)0x00100000)
#define  RCC_APB1RSTR_I2C1RST                ((unsigned int)0x00200000)
#define  RCC_APB1RSTR_I2C2RST                ((unsigned int)0x00400000)
#define  RCC_APB1RSTR_I2C3RST                ((unsigned int)0x00800000)
#define  RCC_APB1RSTR_CAN1RST                ((unsigned int)0x02000000)
#define  RCC_APB1RSTR_CAN2RST                ((unsigned int)0x04000000)
#define  RCC_APB1RSTR_PWRRST                 ((unsigned int)0x10000000)
#define  RCC_APB1RSTR_DACRST                 ((unsigned int)0x20000000)
#define  RCC_APB1RSTR_UART7RST               ((unsigned int)0x40000000)
#define  RCC_APB1RSTR_UART8RST               ((unsigned int)0x80000000)

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define  RCC_APB2RSTR_TIM1RST                ((unsigned int)0x00000001)
#define  RCC_APB2RSTR_TIM8RST                ((unsigned int)0x00000002)
#define  RCC_APB2RSTR_USART1RST              ((unsigned int)0x00000010)
#define  RCC_APB2RSTR_USART6RST              ((unsigned int)0x00000020)
#define  RCC_APB2RSTR_ADCRST                 ((unsigned int)0x00000100)
#define  RCC_APB2RSTR_SDIORST                ((unsigned int)0x00000800)
#define  RCC_APB2RSTR_SPI1RST                ((unsigned int)0x00001000)
#define  RCC_APB2RSTR_SPI4RST                ((unsigned int)0x00002000)
#define  RCC_APB2RSTR_SYSCFGRST              ((unsigned int)0x00004000)
#define  RCC_APB2RSTR_TIM9RST                ((unsigned int)0x00010000)
#define  RCC_APB2RSTR_TIM10RST               ((unsigned int)0x00020000)
#define  RCC_APB2RSTR_TIM11RST               ((unsigned int)0x00040000)
#define  RCC_APB2RSTR_SPI5RST                ((unsigned int)0x00100000)
#define  RCC_APB2RSTR_SPI6RST                ((unsigned int)0x00200000)
#define  RCC_APB2RSTR_SAI1RST                ((unsigned int)0x00400000)
#define  RCC_APB2RSTR_LTDCRST                ((unsigned int)0x04000000)

/* Old SPI1RST bit definition, maintained for legacy purpose */
#define  RCC_APB2RSTR_SPI1                   RCC_APB2RSTR_SPI1RST

/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define  RCC_AHB1ENR_GPIOAEN                 ((unsigned int)0x00000001)
#define  RCC_AHB1ENR_GPIOBEN                 ((unsigned int)0x00000002)
#define  RCC_AHB1ENR_GPIOCEN                 ((unsigned int)0x00000004)
#define  RCC_AHB1ENR_GPIODEN                 ((unsigned int)0x00000008)
#define  RCC_AHB1ENR_GPIOEEN                 ((unsigned int)0x00000010)
#define  RCC_AHB1ENR_GPIOFEN                 ((unsigned int)0x00000020)
#define  RCC_AHB1ENR_GPIOGEN                 ((unsigned int)0x00000040)
#define  RCC_AHB1ENR_GPIOHEN                 ((unsigned int)0x00000080)
#define  RCC_AHB1ENR_GPIOIEN                 ((unsigned int)0x00000100)
#define  RCC_AHB1ENR_GPIOJEN                 ((unsigned int)0x00000200)
#define  RCC_AHB1ENR_GPIOKEN                 ((unsigned int)0x00000400)
#define  RCC_AHB1ENR_CRCEN                   ((unsigned int)0x00001000)
#define  RCC_AHB1ENR_BKPSRAMEN               ((unsigned int)0x00040000)
#define  RCC_AHB1ENR_CCMDATARAMEN            ((unsigned int)0x00100000)
#define  RCC_AHB1ENR_DMA1EN                  ((unsigned int)0x00200000)
#define  RCC_AHB1ENR_DMA2EN                  ((unsigned int)0x00400000)
#define  RCC_AHB1ENR_DMA2DEN                 ((unsigned int)0x00800000)
#define  RCC_AHB1ENR_ETHMACEN                ((unsigned int)0x02000000)
#define  RCC_AHB1ENR_ETHMACTXEN              ((unsigned int)0x04000000)
#define  RCC_AHB1ENR_ETHMACRXEN              ((unsigned int)0x08000000)
#define  RCC_AHB1ENR_ETHMACPTPEN             ((unsigned int)0x10000000)
#define  RCC_AHB1ENR_OTGHSEN                 ((unsigned int)0x20000000)
#define  RCC_AHB1ENR_OTGHSULPIEN             ((unsigned int)0x40000000)

/********************  Bit definition for RCC_AHB2ENR register  ***************/
#define  RCC_AHB2ENR_DCMIEN                  ((unsigned int)0x00000001)
#define  RCC_AHB2ENR_CRYPEN                  ((unsigned int)0x00000010)
#define  RCC_AHB2ENR_HASHEN                  ((unsigned int)0x00000020)
#define  RCC_AHB2ENR_RNGEN                   ((unsigned int)0x00000040)
#define  RCC_AHB2ENR_OTGFSEN                 ((unsigned int)0x00000080)

/********************  Bit definition for RCC_AHB3ENR register  ***************/
#define  RCC_AHB3ENR_FMCEN                  ((unsigned int)0x00000001)

/********************  Bit definition for RCC_APB1ENR register  ***************/
#define  RCC_APB1ENR_TIM2EN                  ((unsigned int)0x00000001)
#define  RCC_APB1ENR_TIM3EN                  ((unsigned int)0x00000002)
#define  RCC_APB1ENR_TIM4EN                  ((unsigned int)0x00000004)
#define  RCC_APB1ENR_TIM5EN                  ((unsigned int)0x00000008)
#define  RCC_APB1ENR_TIM6EN                  ((unsigned int)0x00000010)
#define  RCC_APB1ENR_TIM7EN                  ((unsigned int)0x00000020)
#define  RCC_APB1ENR_TIM12EN                 ((unsigned int)0x00000040)
#define  RCC_APB1ENR_TIM13EN                 ((unsigned int)0x00000080)
#define  RCC_APB1ENR_TIM14EN                 ((unsigned int)0x00000100)
#define  RCC_APB1ENR_WWDGEN                  ((unsigned int)0x00000800)
#define  RCC_APB1ENR_SPI2EN                  ((unsigned int)0x00004000)
#define  RCC_APB1ENR_SPI3EN                  ((unsigned int)0x00008000)
#define  RCC_APB1ENR_USART2EN                ((unsigned int)0x00020000)
#define  RCC_APB1ENR_USART3EN                ((unsigned int)0x00040000)
#define  RCC_APB1ENR_UART4EN                 ((unsigned int)0x00080000)
#define  RCC_APB1ENR_UART5EN                 ((unsigned int)0x00100000)
#define  RCC_APB1ENR_I2C1EN                  ((unsigned int)0x00200000)
#define  RCC_APB1ENR_I2C2EN                  ((unsigned int)0x00400000)
#define  RCC_APB1ENR_I2C3EN                  ((unsigned int)0x00800000)
#define  RCC_APB1ENR_CAN1EN                  ((unsigned int)0x02000000)
#define  RCC_APB1ENR_CAN2EN                  ((unsigned int)0x04000000)
#define  RCC_APB1ENR_PWREN                   ((unsigned int)0x10000000)
#define  RCC_APB1ENR_DACEN                   ((unsigned int)0x20000000)
#define  RCC_APB1ENR_UART7EN                 ((unsigned int)0x40000000)
#define  RCC_APB1ENR_UART8EN                 ((unsigned int)0x80000000)

/********************  Bit definition for RCC_APB2ENR register  ***************/
#define  RCC_APB2ENR_TIM1EN                  ((unsigned int)0x00000001)
#define  RCC_APB2ENR_TIM8EN                  ((unsigned int)0x00000002)
#define  RCC_APB2ENR_USART1EN                ((unsigned int)0x00000010)
#define  RCC_APB2ENR_USART6EN                ((unsigned int)0x00000020)
#define  RCC_APB2ENR_ADC1EN                  ((unsigned int)0x00000100)
#define  RCC_APB2ENR_ADC2EN                  ((unsigned int)0x00000200)
#define  RCC_APB2ENR_ADC3EN                  ((unsigned int)0x00000400)
#define  RCC_APB2ENR_SDIOEN                  ((unsigned int)0x00000800)
#define  RCC_APB2ENR_SPI1EN                  ((unsigned int)0x00001000)
#define  RCC_APB2ENR_SPI4EN                  ((unsigned int)0x00002000)
#define  RCC_APB2ENR_SYSCFGEN                ((unsigned int)0x00004000)
#define  RCC_APB2ENR_TIM9EN                  ((unsigned int)0x00010000)
#define  RCC_APB2ENR_TIM10EN                 ((unsigned int)0x00020000)
#define  RCC_APB2ENR_TIM11EN                 ((unsigned int)0x00040000)
#define  RCC_APB2ENR_SPI5EN                  ((unsigned int)0x00100000)
#define  RCC_APB2ENR_SPI6EN                  ((unsigned int)0x00200000)
#define  RCC_APB2ENR_SAI1EN                  ((unsigned int)0x00400000)
#define  RCC_APB2ENR_LTDCEN                  ((unsigned int)0x04000000)

/********************  Bit definition for RCC_AHB1LPENR register  *************/
#define  RCC_AHB1LPENR_GPIOALPEN             ((unsigned int)0x00000001)
#define  RCC_AHB1LPENR_GPIOBLPEN             ((unsigned int)0x00000002)
#define  RCC_AHB1LPENR_GPIOCLPEN             ((unsigned int)0x00000004)
#define  RCC_AHB1LPENR_GPIODLPEN             ((unsigned int)0x00000008)
#define  RCC_AHB1LPENR_GPIOELPEN             ((unsigned int)0x00000010)
#define  RCC_AHB1LPENR_GPIOFLPEN             ((unsigned int)0x00000020)
#define  RCC_AHB1LPENR_GPIOGLPEN             ((unsigned int)0x00000040)
#define  RCC_AHB1LPENR_GPIOHLPEN             ((unsigned int)0x00000080)
#define  RCC_AHB1LPENR_GPIOILPEN             ((unsigned int)0x00000100)
#define  RCC_AHB1LPENR_GPIOJLPEN             ((unsigned int)0x00000200)
#define  RCC_AHB1LPENR_GPIOKLPEN             ((unsigned int)0x00000400)
#define  RCC_AHB1LPENR_CRCLPEN               ((unsigned int)0x00001000)
#define  RCC_AHB1LPENR_FLITFLPEN             ((unsigned int)0x00008000)
#define  RCC_AHB1LPENR_SRAM1LPEN             ((unsigned int)0x00010000)
#define  RCC_AHB1LPENR_SRAM2LPEN             ((unsigned int)0x00020000)
#define  RCC_AHB1LPENR_BKPSRAMLPEN           ((unsigned int)0x00040000)
#define  RCC_AHB1LPENR_SRAM3LPEN             ((unsigned int)0x00080000)
#define  RCC_AHB1LPENR_DMA1LPEN              ((unsigned int)0x00200000)
#define  RCC_AHB1LPENR_DMA2LPEN              ((unsigned int)0x00400000)
#define  RCC_AHB1LPENR_DMA2DLPEN             ((unsigned int)0x00800000)
#define  RCC_AHB1LPENR_ETHMACLPEN            ((unsigned int)0x02000000)
#define  RCC_AHB1LPENR_ETHMACTXLPEN          ((unsigned int)0x04000000)
#define  RCC_AHB1LPENR_ETHMACRXLPEN          ((unsigned int)0x08000000)
#define  RCC_AHB1LPENR_ETHMACPTPLPEN         ((unsigned int)0x10000000)
#define  RCC_AHB1LPENR_OTGHSLPEN             ((unsigned int)0x20000000)
#define  RCC_AHB1LPENR_OTGHSULPILPEN         ((unsigned int)0x40000000)

/********************  Bit definition for RCC_AHB2LPENR register  *************/
#define  RCC_AHB2LPENR_DCMILPEN              ((unsigned int)0x00000001)
#define  RCC_AHB2LPENR_CRYPLPEN              ((unsigned int)0x00000010)
#define  RCC_AHB2LPENR_HASHLPEN              ((unsigned int)0x00000020)
#define  RCC_AHB2LPENR_RNGLPEN               ((unsigned int)0x00000040)
#define  RCC_AHB2LPENR_OTGFSLPEN             ((unsigned int)0x00000080)

/********************  Bit definition for RCC_AHB3LPENR register  *************/
#define  RCC_AHB3LPENR_FMCLPEN              ((unsigned int)0x00000001)

/********************  Bit definition for RCC_APB1LPENR register  *************/
#define  RCC_APB1LPENR_TIM2LPEN              ((unsigned int)0x00000001)
#define  RCC_APB1LPENR_TIM3LPEN              ((unsigned int)0x00000002)
#define  RCC_APB1LPENR_TIM4LPEN              ((unsigned int)0x00000004)
#define  RCC_APB1LPENR_TIM5LPEN              ((unsigned int)0x00000008)
#define  RCC_APB1LPENR_TIM6LPEN              ((unsigned int)0x00000010)
#define  RCC_APB1LPENR_TIM7LPEN              ((unsigned int)0x00000020)
#define  RCC_APB1LPENR_TIM12LPEN             ((unsigned int)0x00000040)
#define  RCC_APB1LPENR_TIM13LPEN             ((unsigned int)0x00000080)
#define  RCC_APB1LPENR_TIM14LPEN             ((unsigned int)0x00000100)
#define  RCC_APB1LPENR_WWDGLPEN              ((unsigned int)0x00000800)
#define  RCC_APB1LPENR_SPI2LPEN              ((unsigned int)0x00004000)
#define  RCC_APB1LPENR_SPI3LPEN              ((unsigned int)0x00008000)
#define  RCC_APB1LPENR_USART2LPEN            ((unsigned int)0x00020000)
#define  RCC_APB1LPENR_USART3LPEN            ((unsigned int)0x00040000)
#define  RCC_APB1LPENR_UART4LPEN             ((unsigned int)0x00080000)
#define  RCC_APB1LPENR_UART5LPEN             ((unsigned int)0x00100000)
#define  RCC_APB1LPENR_I2C1LPEN              ((unsigned int)0x00200000)
#define  RCC_APB1LPENR_I2C2LPEN              ((unsigned int)0x00400000)
#define  RCC_APB1LPENR_I2C3LPEN              ((unsigned int)0x00800000)
#define  RCC_APB1LPENR_CAN1LPEN              ((unsigned int)0x02000000)
#define  RCC_APB1LPENR_CAN2LPEN              ((unsigned int)0x04000000)
#define  RCC_APB1LPENR_PWRLPEN               ((unsigned int)0x10000000)
#define  RCC_APB1LPENR_DACLPEN               ((unsigned int)0x20000000)
#define  RCC_APB1LPENR_UART7LPEN             ((unsigned int)0x40000000)
#define  RCC_APB1LPENR_UART8LPEN             ((unsigned int)0x80000000)

/********************  Bit definition for RCC_APB2LPENR register  *************/
#define  RCC_APB2LPENR_TIM1LPEN              ((unsigned int)0x00000001)
#define  RCC_APB2LPENR_TIM8LPEN              ((unsigned int)0x00000002)
#define  RCC_APB2LPENR_USART1LPEN            ((unsigned int)0x00000010)
#define  RCC_APB2LPENR_USART6LPEN            ((unsigned int)0x00000020)
#define  RCC_APB2LPENR_ADC1LPEN              ((unsigned int)0x00000100)
#define  RCC_APB2LPENR_ADC2PEN               ((unsigned int)0x00000200)
#define  RCC_APB2LPENR_ADC3LPEN              ((unsigned int)0x00000400)
#define  RCC_APB2LPENR_SDIOLPEN              ((unsigned int)0x00000800)
#define  RCC_APB2LPENR_SPI1LPEN              ((unsigned int)0x00001000)
#define  RCC_APB2LPENR_SPI4LPEN              ((unsigned int)0x00002000)
#define  RCC_APB2LPENR_SYSCFGLPEN            ((unsigned int)0x00004000)
#define  RCC_APB2LPENR_TIM9LPEN              ((unsigned int)0x00010000)
#define  RCC_APB2LPENR_TIM10LPEN             ((unsigned int)0x00020000)
#define  RCC_APB2LPENR_TIM11LPEN             ((unsigned int)0x00040000)
#define  RCC_APB2LPENR_SPI5LPEN              ((unsigned int)0x00100000)
#define  RCC_APB2LPENR_SPI6LPEN              ((unsigned int)0x00200000)
#define  RCC_APB2LPENR_SAI1LPEN              ((unsigned int)0x00400000)
#define  RCC_APB2LPENR_LTDCLPEN              ((unsigned int)0x04000000)

/********************  Bit definition for RCC_BDCR register  ******************/
#define  RCC_BDCR_LSEON                      ((unsigned int)0x00000001)
#define  RCC_BDCR_LSERDY                     ((unsigned int)0x00000002)
#define  RCC_BDCR_LSEBYP                     ((unsigned int)0x00000004)
#define  RCC_BDCR_LSEMOD                     ((unsigned int)0x00000008)

#define  RCC_BDCR_RTCSEL                    ((unsigned int)0x00000300)
#define  RCC_BDCR_RTCSEL_0                  ((unsigned int)0x00000100)
#define  RCC_BDCR_RTCSEL_1                  ((unsigned int)0x00000200)

#define  RCC_BDCR_RTCEN                      ((unsigned int)0x00008000)
#define  RCC_BDCR_BDRST                      ((unsigned int)0x00010000)

/********************  Bit definition for RCC_CSR register  *******************/
#define  RCC_CSR_LSION                       ((unsigned int)0x00000001)
#define  RCC_CSR_LSIRDY                      ((unsigned int)0x00000002)
#define  RCC_CSR_RMVF                        ((unsigned int)0x01000000)
#define  RCC_CSR_BORRSTF                     ((unsigned int)0x02000000)
#define  RCC_CSR_PADRSTF                     ((unsigned int)0x04000000)
#define  RCC_CSR_PORRSTF                     ((unsigned int)0x08000000)
#define  RCC_CSR_SFTRSTF                     ((unsigned int)0x10000000)
#define  RCC_CSR_WDGRSTF                     ((unsigned int)0x20000000)
#define  RCC_CSR_WWDGRSTF                    ((unsigned int)0x40000000)
#define  RCC_CSR_LPWRRSTF                    ((unsigned int)0x80000000)

/********************  Bit definition for RCC_SSCGR register  *****************/
#define  RCC_SSCGR_MODPER                    ((unsigned int)0x00001FFF)
#define  RCC_SSCGR_INCSTEP                   ((unsigned int)0x0FFFE000)
#define  RCC_SSCGR_SPREADSEL                 ((unsigned int)0x40000000)
#define  RCC_SSCGR_SSCGEN                    ((unsigned int)0x80000000)

/********************  Bit definition for RCC_PLLI2SCFGR register  ************/
#define  RCC_PLLI2SCFGR_PLLI2SM              ((unsigned int)0x0000003F)
#define  RCC_PLLI2SCFGR_PLLI2SM_0            ((unsigned int)0x00000001)
#define  RCC_PLLI2SCFGR_PLLI2SM_1            ((unsigned int)0x00000002)
#define  RCC_PLLI2SCFGR_PLLI2SM_2            ((unsigned int)0x00000004)
#define  RCC_PLLI2SCFGR_PLLI2SM_3            ((unsigned int)0x00000008)
#define  RCC_PLLI2SCFGR_PLLI2SM_4            ((unsigned int)0x00000010)
#define  RCC_PLLI2SCFGR_PLLI2SM_5            ((unsigned int)0x00000020)

#define  RCC_PLLI2SCFGR_PLLI2SN              ((unsigned int)0x00007FC0)
#define  RCC_PLLI2SCFGR_PLLI2SN_0            ((unsigned int)0x00000040)
#define  RCC_PLLI2SCFGR_PLLI2SN_1            ((unsigned int)0x00000080)
#define  RCC_PLLI2SCFGR_PLLI2SN_2            ((unsigned int)0x00000100)
#define  RCC_PLLI2SCFGR_PLLI2SN_3            ((unsigned int)0x00000200)
#define  RCC_PLLI2SCFGR_PLLI2SN_4            ((unsigned int)0x00000400)
#define  RCC_PLLI2SCFGR_PLLI2SN_5            ((unsigned int)0x00000800)
#define  RCC_PLLI2SCFGR_PLLI2SN_6            ((unsigned int)0x00001000)
#define  RCC_PLLI2SCFGR_PLLI2SN_7            ((unsigned int)0x00002000)
#define  RCC_PLLI2SCFGR_PLLI2SN_8            ((unsigned int)0x00004000)

#define  RCC_PLLI2SCFGR_PLLI2SQ              ((unsigned int)0x0F000000)
#define  RCC_PLLI2SCFGR_PLLI2SQ_0            ((unsigned int)0x01000000)
#define  RCC_PLLI2SCFGR_PLLI2SQ_1            ((unsigned int)0x02000000)
#define  RCC_PLLI2SCFGR_PLLI2SQ_2            ((unsigned int)0x04000000)
#define  RCC_PLLI2SCFGR_PLLI2SQ_3            ((unsigned int)0x08000000)

#define  RCC_PLLI2SCFGR_PLLI2SR              ((unsigned int)0x70000000)
#define  RCC_PLLI2SCFGR_PLLI2SR_0            ((unsigned int)0x10000000)
#define  RCC_PLLI2SCFGR_PLLI2SR_1            ((unsigned int)0x20000000)
#define  RCC_PLLI2SCFGR_PLLI2SR_2            ((unsigned int)0x40000000)

/********************  Bit definition for RCC_PLLSAICFGR register  ************/
#define  RCC_PLLSAICFGR_PLLSAIN              ((unsigned int)0x00007FC0)
#define  RCC_PLLSAICFGR_PLLSAIN_0            ((unsigned int)0x00000040)
#define  RCC_PLLSAICFGR_PLLSAIN_1            ((unsigned int)0x00000080)
#define  RCC_PLLSAICFGR_PLLSAIN_2            ((unsigned int)0x00000100)
#define  RCC_PLLSAICFGR_PLLSAIN_3            ((unsigned int)0x00000200)
#define  RCC_PLLSAICFGR_PLLSAIN_4            ((unsigned int)0x00000400)
#define  RCC_PLLSAICFGR_PLLSAIN_5            ((unsigned int)0x00000800)
#define  RCC_PLLSAICFGR_PLLSAIN_6            ((unsigned int)0x00001000)
#define  RCC_PLLSAICFGR_PLLSAIN_7            ((unsigned int)0x00002000)
#define  RCC_PLLSAICFGR_PLLSAIN_8            ((unsigned int)0x00004000)

#define  RCC_PLLSAICFGR_PLLSAIQ              ((unsigned int)0x0F000000)
#define  RCC_PLLSAICFGR_PLLSAIQ_0            ((unsigned int)0x01000000)
#define  RCC_PLLSAICFGR_PLLSAIQ_1            ((unsigned int)0x02000000)
#define  RCC_PLLSAICFGR_PLLSAIQ_2            ((unsigned int)0x04000000)
#define  RCC_PLLSAICFGR_PLLSAIQ_3            ((unsigned int)0x08000000)

#define  RCC_PLLSAICFGR_PLLSAIR              ((unsigned int)0x70000000)
#define  RCC_PLLSAICFGR_PLLSAIR_0            ((unsigned int)0x10000000)
#define  RCC_PLLSAICFGR_PLLSAIR_1            ((unsigned int)0x20000000)
#define  RCC_PLLSAICFGR_PLLSAIR_2            ((unsigned int)0x40000000)

/********************  Bit definition for RCC_DCKCFGR register  ***************/
#define  RCC_DCKCFGR_PLLI2SDIVQ              ((unsigned int)0x0000001F)
#define  RCC_DCKCFGR_PLLSAIDIVQ              ((unsigned int)0x00001F00)
#define  RCC_DCKCFGR_PLLSAIDIVR              ((unsigned int)0x00030000)

#define  RCC_DCKCFGR_SAI1ASRC                ((unsigned int)0x00300000)
#define  RCC_DCKCFGR_SAI1ASRC_0              ((unsigned int)0x00100000)
#define  RCC_DCKCFGR_SAI1ASRC_1              ((unsigned int)0x00200000)

#define  RCC_DCKCFGR_SAI1BSRC                ((unsigned int)0x00C00000)
#define  RCC_DCKCFGR_SAI1BSRC_0              ((unsigned int)0x00400000)
#define  RCC_DCKCFGR_SAI1BSRC_1              ((unsigned int)0x00800000)

#define  RCC_DCKCFGR_TIMPRE                  ((unsigned int)0x01000000)
#define  RCC_DCKCFGR_CK48MSEL                ((unsigned int)0x08000000)

#endif /* STM32_RCC_H */
