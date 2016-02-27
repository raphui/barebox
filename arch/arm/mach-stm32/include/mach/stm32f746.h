
#ifndef STM32F746_H
#define STM32F746_H

#define __CM4_REV                 0x0001  /*!< Core revision r0p1                            */
#define __MPU_PRESENT             1       /*!< STM32F4XX provides an MPU                     */
#define __NVIC_PRIO_BITS          4       /*!< STM32F4XX uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0       /*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1       /*!< FPU present                                   */

/**
 * @brief STM32F4XX Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */
typedef enum IRQn
{
	/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
	NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
	MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
	BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
	UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
	SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
	DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
	PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
	SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
	/******  STM32 specific Interrupt Numbers **********************************************************************/
	WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
	PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
	TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
	RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
	FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
	RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
	EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
	EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
	EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
	EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
	EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
	DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
	DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
	DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
	DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
	DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
	DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
	DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
	ADC_IRQn                    = 18,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
	CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupt                                                 */
	CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupt                                                */
	CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                                */
	CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                                */
	EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
	TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
	TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
	TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
	TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
	TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
	TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
	TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
	I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
	I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
	I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */
	I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */  
	SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
	SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
	USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
	USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
	USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                           */
	EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
	RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
	OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */    
	TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
	TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
	TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
	TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                                    */
	DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                            */
	FMC_IRQn                    = 48,     /*!< FMC global Interrupt                                              */
	SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                             */
	TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
	SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
	UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                            */
	UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                            */
	TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
	TIM7_IRQn                   = 55,     /*!< TIM7 global interrupt                                             */
	DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global Interrupt                                    */
	DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global Interrupt                                    */
	DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global Interrupt                                    */
	DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global Interrupt                                    */
	DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global Interrupt                                    */
	ETH_IRQn                    = 61,     /*!< Ethernet global Interrupt                                         */
	ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line Interrupt                       */
	CAN2_TX_IRQn                = 63,     /*!< CAN2 TX Interrupt                                                 */
	CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0 Interrupt                                                */
	CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1 Interrupt                                                */
	CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE Interrupt                                                */
	OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                       */
	DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
	DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
	DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
	USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                           */
	I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
	I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
	OTG_HS_EP1_OUT_IRQn         = 74,     /*!< USB OTG HS End Point 1 Out global interrupt                       */
	OTG_HS_EP1_IN_IRQn          = 75,     /*!< USB OTG HS End Point 1 In global interrupt                        */
	OTG_HS_WKUP_IRQn            = 76,     /*!< USB OTG HS Wakeup through EXTI interrupt                          */
	OTG_HS_IRQn                 = 77,     /*!< USB OTG HS global interrupt                                       */
	DCMI_IRQn                   = 78,     /*!< DCMI global interrupt                                             */
	CRYP_IRQn                   = 79,     /*!< CRYP crypto global interrupt                                      */
	HASH_RNG_IRQn               = 80,     /*!< Hash and Rng global interrupt                                     */
	FPU_IRQn                    = 81,     /*!< FPU global interrupt                                              */
	UART7_IRQn                  = 82,     /*!< UART7 global interrupt                                            */
	UART8_IRQn                  = 83,     /*!< UART8 global interrupt                                            */
	SPI4_IRQn                   = 84,     /*!< SPI4 global Interrupt                                             */
	SPI5_IRQn                   = 85,     /*!< SPI5 global Interrupt                                             */
	SPI6_IRQn                   = 86,     /*!< SPI6 global Interrupt                                             */
	SAI1_IRQn                   = 87,     /*!< SAI1 global Interrupt                                             */
	LTDC_IRQn                   = 88,     /*!< LTDC global Interrupt                                             */
	LTDC_ER_IRQn                = 89,     /*!< LTDC Error global Interrupt                                       */
	DMA2D_IRQn                  = 90      /*!< DMA2D global Interrupt                                            */
} IRQn_Type;

#define FLASH_BASE            ((unsigned int)0x08000000) /*!< FLASH(up to 1 MB) base address in the alias region                         */
#define CCMDATARAM_BASE       ((unsigned int)0x10000000) /*!< CCM(core coupled memory) data RAM(64 KB) base address in the alias region  */
#define SRAM1_BASE            ((unsigned int)0x20000000) /*!< SRAM1(112 KB) base address in the alias region                             */
#define SRAM2_BASE            ((unsigned int)0x2001C000) /*!< SRAM2(16 KB) base address in the alias region                              */
#define SRAM3_BASE            ((unsigned int)0x20020000) /*!< SRAM3(64 KB) base address in the alias region                              */
#define PERIPH_BASE           ((unsigned int)0x40000000) /*!< Peripheral base address in the alias region                                */
#define BKPSRAM_BASE          ((unsigned int)0x40024000) /*!< Backup SRAM(4 KB) base address in the alias region                         */

#define FMC_R_BASE            ((unsigned int)0xA0000000) /*!< FMC registers base address */        

#define CCMDATARAM_BB_BASE    ((unsigned int)0x12000000) /*!< CCM(core coupled memory) data RAM(64 KB) base address in the bit-band region  */
#define SRAM1_BB_BASE         ((unsigned int)0x22000000) /*!< SRAM1(112 KB) base address in the bit-band region                             */
#define SRAM2_BB_BASE         ((unsigned int)0x2201C000) /*!< SRAM2(16 KB) base address in the bit-band region                              */
#define SRAM3_BB_BASE         ((unsigned int)0x22400000) /*!< SRAM3(64 KB) base address in the bit-band region                              */
#define PERIPH_BB_BASE        ((unsigned int)0x42000000) /*!< Peripheral base address in the bit-band region                                */
#define BKPSRAM_BB_BASE       ((unsigned int)0x42024000) /*!< Backup SRAM(4 KB) base address in the bit-band region                         */

/* Legacy defines */
#define SRAM_BASE             SRAM1_BASE
#define SRAM_BB_BASE          SRAM1_BB_BASE


/*!< Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000)

/*!< APB1 peripherals */
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x1800)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x1C00)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x2000)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000)
#define I2S2ext_BASE          (APB1PERIPH_BASE + 0x3400)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00)
#define I2S3ext_BASE          (APB1PERIPH_BASE + 0x4000)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x5C00)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400)
#define CAN2_BASE             (APB1PERIPH_BASE + 0x6800)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400)
#define UART7_BASE            (APB1PERIPH_BASE + 0x7800)
#define UART8_BASE            (APB1PERIPH_BASE + 0x7C00)

/*!< APB2 peripherals */
#define TIM1_BASE             (APB2PERIPH_BASE + 0x0000)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x0400)
#define USART1_BASE           (APB2PERIPH_BASE + 0x1000)
#define USART6_BASE           (APB2PERIPH_BASE + 0x1400)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2000)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2100)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x2200)
#define ADC_BASE              (APB2PERIPH_BASE + 0x2300)
#define SDIO_BASE             (APB2PERIPH_BASE + 0x2C00)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
#define SPI4_BASE             (APB2PERIPH_BASE + 0x3400)
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x3800)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x3C00)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4000)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x4400)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x4800)
#define SPI5_BASE             (APB2PERIPH_BASE + 0x5000)
#define SPI6_BASE             (APB2PERIPH_BASE + 0x5400)
#define SAI1_BASE             (APB2PERIPH_BASE + 0x5800)
#define SAI1_Block_A_BASE     (SAI1_BASE + 0x004)
#define SAI1_Block_B_BASE     (SAI1_BASE + 0x024)
#define LTDC_BASE             (APB2PERIPH_BASE + 0x6800)
#define LTDC_Layer1_BASE      (LTDC_BASE + 0x84)
#define LTDC_Layer2_BASE      (LTDC_BASE + 0x104)

/*!< AHB1 peripherals */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000)
#define GPIOJ_BASE            (AHB1PERIPH_BASE + 0x2400)
#define GPIOK_BASE            (AHB1PERIPH_BASE + 0x2800)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00)
#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000)
#define DMA1_Stream0_BASE     (DMA1_BASE + 0x010)
#define DMA1_Stream1_BASE     (DMA1_BASE + 0x028)
#define DMA1_Stream2_BASE     (DMA1_BASE + 0x040)
#define DMA1_Stream3_BASE     (DMA1_BASE + 0x058)
#define DMA1_Stream4_BASE     (DMA1_BASE + 0x070)
#define DMA1_Stream5_BASE     (DMA1_BASE + 0x088)
#define DMA1_Stream6_BASE     (DMA1_BASE + 0x0A0)
#define DMA1_Stream7_BASE     (DMA1_BASE + 0x0B8)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x6400)
#define DMA2_Stream0_BASE     (DMA2_BASE + 0x010)
#define DMA2_Stream1_BASE     (DMA2_BASE + 0x028)
#define DMA2_Stream2_BASE     (DMA2_BASE + 0x040)
#define DMA2_Stream3_BASE     (DMA2_BASE + 0x058)
#define DMA2_Stream4_BASE     (DMA2_BASE + 0x070)
#define DMA2_Stream5_BASE     (DMA2_BASE + 0x088)
#define DMA2_Stream6_BASE     (DMA2_BASE + 0x0A0)
#define DMA2_Stream7_BASE     (DMA2_BASE + 0x0B8)
#define ETH_BASE              (AHB1PERIPH_BASE + 0x8000)
#define ETH_MAC_BASE          (ETH_BASE)
#define ETH_MMC_BASE          (ETH_BASE + 0x0100)
#define ETH_PTP_BASE          (ETH_BASE + 0x0700)
#define ETH_DMA_BASE          (ETH_BASE + 0x1000)
#define DMA2D_BASE            (AHB1PERIPH_BASE + 0xB000)

/*!< AHB2 peripherals */
#define DCMI_BASE             (AHB2PERIPH_BASE + 0x50000)
#define CRYP_BASE             (AHB2PERIPH_BASE + 0x60000)
#define HASH_BASE             (AHB2PERIPH_BASE + 0x60400)
#define HASH_DIGEST_BASE      (AHB2PERIPH_BASE + 0x60710)
#define RNG_BASE              (AHB2PERIPH_BASE + 0x60800)
/*!< FMC Bankx registers base address */
#define FMC_Bank1_R_BASE      (FMC_R_BASE + 0x0000)
#define FMC_Bank1E_R_BASE     (FMC_R_BASE + 0x0104)
#define FMC_Bank2_R_BASE      (FMC_R_BASE + 0x0060)
#define FMC_Bank3_R_BASE      (FMC_R_BASE + 0x0080)
#define FMC_Bank4_R_BASE      (FMC_R_BASE + 0x00A0)
#define FMC_Bank5_6_R_BASE    (FMC_R_BASE + 0x0140)

/* Debug MCU registers base address */
#define DBGMCU_BASE           ((unsigned int )0xE0042000)

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY                    ((unsigned int)0x0000000F)
#define FLASH_ACR_LATENCY_0WS                ((unsigned int)0x00000000)
#define FLASH_ACR_LATENCY_1WS                ((unsigned int)0x00000001)
#define FLASH_ACR_LATENCY_2WS                ((unsigned int)0x00000002)
#define FLASH_ACR_LATENCY_3WS                ((unsigned int)0x00000003)
#define FLASH_ACR_LATENCY_4WS                ((unsigned int)0x00000004)
#define FLASH_ACR_LATENCY_5WS                ((unsigned int)0x00000005)
#define FLASH_ACR_LATENCY_6WS                ((unsigned int)0x00000006)
#define FLASH_ACR_LATENCY_7WS                ((unsigned int)0x00000007)
#define FLASH_ACR_LATENCY_8WS                ((unsigned int)0x00000008)
#define FLASH_ACR_LATENCY_9WS                ((unsigned int)0x00000009)
#define FLASH_ACR_LATENCY_10WS               ((unsigned int)0x0000000A)
#define FLASH_ACR_LATENCY_11WS               ((unsigned int)0x0000000B)
#define FLASH_ACR_LATENCY_12WS               ((unsigned int)0x0000000C)
#define FLASH_ACR_LATENCY_13WS               ((unsigned int)0x0000000D)
#define FLASH_ACR_LATENCY_14WS               ((unsigned int)0x0000000E)
#define FLASH_ACR_LATENCY_15WS               ((unsigned int)0x0000000F)

#define FLASH_ACR_PRFTEN                     ((unsigned int)0x00000100)
#define FLASH_ACR_ICEN                       ((unsigned int)0x00000200)
#define FLASH_ACR_DCEN                       ((unsigned int)0x00000400)
#define FLASH_ACR_ICRST                      ((unsigned int)0x00000800)
#define FLASH_ACR_DCRST                      ((unsigned int)0x00001000)
#define FLASH_ACR_BYTE0_ADDRESS              ((unsigned int)0x40023C00)
#define FLASH_ACR_BYTE2_ADDRESS              ((unsigned int)0x40023C03)

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP                         ((unsigned int)0x00000001)
#define FLASH_SR_SOP                         ((unsigned int)0x00000002)
#define FLASH_SR_WRPERR                      ((unsigned int)0x00000010)
#define FLASH_SR_PGAERR                      ((unsigned int)0x00000020)
#define FLASH_SR_PGPERR                      ((unsigned int)0x00000040)
#define FLASH_SR_PGSERR                      ((unsigned int)0x00000080)
#define FLASH_SR_BSY                         ((unsigned int)0x00010000)

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG                          ((unsigned int)0x00000001)
#define FLASH_CR_SER                         ((unsigned int)0x00000002)
#define FLASH_CR_MER                         ((unsigned int)0x00000004)
#define FLASH_CR_MER1                        FLASH_CR_MER
#define FLASH_CR_SNB                         ((unsigned int)0x000000F8)
#define FLASH_CR_SNB_0                       ((unsigned int)0x00000008)
#define FLASH_CR_SNB_1                       ((unsigned int)0x00000010)
#define FLASH_CR_SNB_2                       ((unsigned int)0x00000020)
#define FLASH_CR_SNB_3                       ((unsigned int)0x00000040)
#define FLASH_CR_SNB_4                       ((unsigned int)0x00000040)
#define FLASH_CR_PSIZE                       ((unsigned int)0x00000300)
#define FLASH_CR_PSIZE_0                     ((unsigned int)0x00000100)
#define FLASH_CR_PSIZE_1                     ((unsigned int)0x00000200)
#define FLASH_CR_MER2                        ((unsigned int)0x00008000)
#define FLASH_CR_STRT                        ((unsigned int)0x00010000)
#define FLASH_CR_EOPIE                       ((unsigned int)0x01000000)
#define FLASH_CR_LOCK                        ((unsigned int)0x80000000)

/*******************  Bits definition for FLASH_OPTCR register  ***************/
#define FLASH_OPTCR_OPTLOCK                 ((unsigned int)0x00000001)
#define FLASH_OPTCR_OPTSTRT                 ((unsigned int)0x00000002)
#define FLASH_OPTCR_BOR_LEV_0               ((unsigned int)0x00000004)
#define FLASH_OPTCR_BOR_LEV_1               ((unsigned int)0x00000008)
#define FLASH_OPTCR_BOR_LEV                 ((unsigned int)0x0000000C)
#define FLASH_OPTCR_BFB2                    ((unsigned int)0x00000010)

#define FLASH_OPTCR_WDG_SW                  ((unsigned int)0x00000020)
#define FLASH_OPTCR_nRST_STOP               ((unsigned int)0x00000040)
#define FLASH_OPTCR_nRST_STDBY              ((unsigned int)0x00000080)
#define FLASH_OPTCR_RDP                     ((unsigned int)0x0000FF00)
#define FLASH_OPTCR_RDP_0                   ((unsigned int)0x00000100)
#define FLASH_OPTCR_RDP_1                   ((unsigned int)0x00000200)
#define FLASH_OPTCR_RDP_2                   ((unsigned int)0x00000400)
#define FLASH_OPTCR_RDP_3                   ((unsigned int)0x00000800)
#define FLASH_OPTCR_RDP_4                   ((unsigned int)0x00001000)
#define FLASH_OPTCR_RDP_5                   ((unsigned int)0x00002000)
#define FLASH_OPTCR_RDP_6                   ((unsigned int)0x00004000)
#define FLASH_OPTCR_RDP_7                   ((unsigned int)0x00008000)
#define FLASH_OPTCR_nWRP                    ((unsigned int)0x0FFF0000)
#define FLASH_OPTCR_nWRP_0                  ((unsigned int)0x00010000)
#define FLASH_OPTCR_nWRP_1                  ((unsigned int)0x00020000)
#define FLASH_OPTCR_nWRP_2                  ((unsigned int)0x00040000)
#define FLASH_OPTCR_nWRP_3                  ((unsigned int)0x00080000)
#define FLASH_OPTCR_nWRP_4                  ((unsigned int)0x00100000)
#define FLASH_OPTCR_nWRP_5                  ((unsigned int)0x00200000)
#define FLASH_OPTCR_nWRP_6                  ((unsigned int)0x00400000)
#define FLASH_OPTCR_nWRP_7                  ((unsigned int)0x00800000)
#define FLASH_OPTCR_nWRP_8                  ((unsigned int)0x01000000)
#define FLASH_OPTCR_nWRP_9                  ((unsigned int)0x02000000)
#define FLASH_OPTCR_nWRP_10                 ((unsigned int)0x04000000)
#define FLASH_OPTCR_nWRP_11                 ((unsigned int)0x08000000)

#define FLASH_OPTCR_DB1M                    ((unsigned int)0x40000000) 
#define FLASH_OPTCR_SPRMOD                  ((unsigned int)0x80000000) 

/******************  Bits definition for FLASH_OPTCR1 register  ***************/
#define FLASH_OPTCR1_nWRP                    ((unsigned int)0x0FFF0000)
#define FLASH_OPTCR1_nWRP_0                  ((unsigned int)0x00010000)
#define FLASH_OPTCR1_nWRP_1                  ((unsigned int)0x00020000)
#define FLASH_OPTCR1_nWRP_2                  ((unsigned int)0x00040000)
#define FLASH_OPTCR1_nWRP_3                  ((unsigned int)0x00080000)
#define FLASH_OPTCR1_nWRP_4                  ((unsigned int)0x00100000)
#define FLASH_OPTCR1_nWRP_5                  ((unsigned int)0x00200000)
#define FLASH_OPTCR1_nWRP_6                  ((unsigned int)0x00400000)
#define FLASH_OPTCR1_nWRP_7                  ((unsigned int)0x00800000)
#define FLASH_OPTCR1_nWRP_8                  ((unsigned int)0x01000000)
#define FLASH_OPTCR1_nWRP_9                  ((unsigned int)0x02000000)
#define FLASH_OPTCR1_nWRP_10                 ((unsigned int)0x04000000)
#define FLASH_OPTCR1_nWRP_11                 ((unsigned int)0x08000000)

/******************************************************************************/
/*                                                                            */
/*                          Flexible Memory Controller                        */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for FMC_BCR1 register  *******************/
#define  FMC_BCR1_MBKEN                     ((unsigned int)0x00000001)        /*!<Memory bank enable bit                 */
#define  FMC_BCR1_MUXEN                     ((unsigned int)0x00000002)        /*!<Address/data multiplexing enable bit   */

#define  FMC_BCR1_MTYP                      ((unsigned int)0x0000000C)        /*!<MTYP[1:0] bits (Memory type)           */
#define  FMC_BCR1_MTYP_0                    ((unsigned int)0x00000004)        /*!<Bit 0 */
#define  FMC_BCR1_MTYP_1                    ((unsigned int)0x00000008)        /*!<Bit 1 */

#define  FMC_BCR1_MWID                      ((unsigned int)0x00000030)        /*!<MWID[1:0] bits (Memory data bus width) */
#define  FMC_BCR1_MWID_0                    ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BCR1_MWID_1                    ((unsigned int)0x00000020)        /*!<Bit 1 */

#define  FMC_BCR1_FACCEN                    ((unsigned int)0x00000040)        /*!<Flash access enable        */
#define  FMC_BCR1_BURSTEN                   ((unsigned int)0x00000100)        /*!<Burst enable bit           */
#define  FMC_BCR1_WAITPOL                   ((unsigned int)0x00000200)        /*!<Wait signal polarity bit   */
#define  FMC_BCR1_WRAPMOD                   ((unsigned int)0x00000400)        /*!<Wrapped burst mode support */
#define  FMC_BCR1_WAITCFG                   ((unsigned int)0x00000800)        /*!<Wait timing configuration  */
#define  FMC_BCR1_WREN                      ((unsigned int)0x00001000)        /*!<Write enable bit           */
#define  FMC_BCR1_WAITEN                    ((unsigned int)0x00002000)        /*!<Wait enable bit            */
#define  FMC_BCR1_EXTMOD                    ((unsigned int)0x00004000)        /*!<Extended mode enable       */
#define  FMC_BCR1_ASYNCWAIT                 ((unsigned int)0x00008000)        /*!<Asynchronous wait          */
#define  FMC_BCR1_CBURSTRW                  ((unsigned int)0x00080000)        /*!<Write burst enable         */
#define  FMC_BCR1_CCLKEN                    ((unsigned int)0x00100000)        /*!<Continous clock enable     */

/******************  Bit definition for FMC_BCR2 register  *******************/
#define  FMC_BCR2_MBKEN                     ((unsigned int)0x00000001)        /*!<Memory bank enable bit                 */
#define  FMC_BCR2_MUXEN                     ((unsigned int)0x00000002)        /*!<Address/data multiplexing enable bit   */

#define  FMC_BCR2_MTYP                      ((unsigned int)0x0000000C)        /*!<MTYP[1:0] bits (Memory type)           */
#define  FMC_BCR2_MTYP_0                    ((unsigned int)0x00000004)        /*!<Bit 0 */
#define  FMC_BCR2_MTYP_1                    ((unsigned int)0x00000008)        /*!<Bit 1 */

#define  FMC_BCR2_MWID                      ((unsigned int)0x00000030)        /*!<MWID[1:0] bits (Memory data bus width) */
#define  FMC_BCR2_MWID_0                    ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BCR2_MWID_1                    ((unsigned int)0x00000020)        /*!<Bit 1 */

#define  FMC_BCR2_FACCEN                    ((unsigned int)0x00000040)        /*!<Flash access enable        */
#define  FMC_BCR2_BURSTEN                   ((unsigned int)0x00000100)        /*!<Burst enable bit           */
#define  FMC_BCR2_WAITPOL                   ((unsigned int)0x00000200)        /*!<Wait signal polarity bit   */
#define  FMC_BCR2_WRAPMOD                   ((unsigned int)0x00000400)        /*!<Wrapped burst mode support */
#define  FMC_BCR2_WAITCFG                   ((unsigned int)0x00000800)        /*!<Wait timing configuration  */
#define  FMC_BCR2_WREN                      ((unsigned int)0x00001000)        /*!<Write enable bit           */
#define  FMC_BCR2_WAITEN                    ((unsigned int)0x00002000)        /*!<Wait enable bit            */
#define  FMC_BCR2_EXTMOD                    ((unsigned int)0x00004000)        /*!<Extended mode enable       */
#define  FMC_BCR2_ASYNCWAIT                 ((unsigned int)0x00008000)        /*!<Asynchronous wait          */
#define  FMC_BCR2_CBURSTRW                  ((unsigned int)0x00080000)        /*!<Write burst enable         */

/******************  Bit definition for FMC_BCR3 register  *******************/
#define  FMC_BCR3_MBKEN                     ((unsigned int)0x00000001)        /*!<Memory bank enable bit                 */
#define  FMC_BCR3_MUXEN                     ((unsigned int)0x00000002)        /*!<Address/data multiplexing enable bit   */

#define  FMC_BCR3_MTYP                      ((unsigned int)0x0000000C)        /*!<MTYP[1:0] bits (Memory type)           */
#define  FMC_BCR3_MTYP_0                    ((unsigned int)0x00000004)        /*!<Bit 0 */
#define  FMC_BCR3_MTYP_1                    ((unsigned int)0x00000008)        /*!<Bit 1 */

#define  FMC_BCR3_MWID                      ((unsigned int)0x00000030)        /*!<MWID[1:0] bits (Memory data bus width) */
#define  FMC_BCR3_MWID_0                    ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BCR3_MWID_1                    ((unsigned int)0x00000020)        /*!<Bit 1 */

#define  FMC_BCR3_FACCEN                    ((unsigned int)0x00000040)        /*!<Flash access enable        */
#define  FMC_BCR3_BURSTEN                   ((unsigned int)0x00000100)        /*!<Burst enable bit           */
#define  FMC_BCR3_WAITPOL                   ((unsigned int)0x00000200)        /*!<Wait signal polarity bit   */
#define  FMC_BCR3_WRAPMOD                   ((unsigned int)0x00000400)        /*!<Wrapped burst mode support */
#define  FMC_BCR3_WAITCFG                   ((unsigned int)0x00000800)        /*!<Wait timing configuration  */
#define  FMC_BCR3_WREN                      ((unsigned int)0x00001000)        /*!<Write enable bit           */
#define  FMC_BCR3_WAITEN                    ((unsigned int)0x00002000)        /*!<Wait enable bit            */
#define  FMC_BCR3_EXTMOD                    ((unsigned int)0x00004000)        /*!<Extended mode enable       */
#define  FMC_BCR3_ASYNCWAIT                 ((unsigned int)0x00008000)        /*!<Asynchronous wait          */
#define  FMC_BCR3_CBURSTRW                  ((unsigned int)0x00080000)        /*!<Write burst enable         */

/******************  Bit definition for FMC_BCR4 register  *******************/
#define  FMC_BCR4_MBKEN                     ((unsigned int)0x00000001)        /*!<Memory bank enable bit                 */
#define  FMC_BCR4_MUXEN                     ((unsigned int)0x00000002)        /*!<Address/data multiplexing enable bit   */

#define  FMC_BCR4_MTYP                      ((unsigned int)0x0000000C)        /*!<MTYP[1:0] bits (Memory type)           */
#define  FMC_BCR4_MTYP_0                    ((unsigned int)0x00000004)        /*!<Bit 0 */
#define  FMC_BCR4_MTYP_1                    ((unsigned int)0x00000008)        /*!<Bit 1 */

#define  FMC_BCR4_MWID                      ((unsigned int)0x00000030)        /*!<MWID[1:0] bits (Memory data bus width) */
#define  FMC_BCR4_MWID_0                    ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BCR4_MWID_1                    ((unsigned int)0x00000020)        /*!<Bit 1 */

#define  FMC_BCR4_FACCEN                    ((unsigned int)0x00000040)        /*!<Flash access enable        */
#define  FMC_BCR4_BURSTEN                   ((unsigned int)0x00000100)        /*!<Burst enable bit           */
#define  FMC_BCR4_WAITPOL                   ((unsigned int)0x00000200)        /*!<Wait signal polarity bit   */
#define  FMC_BCR4_WRAPMOD                   ((unsigned int)0x00000400)        /*!<Wrapped burst mode support */
#define  FMC_BCR4_WAITCFG                   ((unsigned int)0x00000800)        /*!<Wait timing configuration  */
#define  FMC_BCR4_WREN                      ((unsigned int)0x00001000)        /*!<Write enable bit           */
#define  FMC_BCR4_WAITEN                    ((unsigned int)0x00002000)        /*!<Wait enable bit            */
#define  FMC_BCR4_EXTMOD                    ((unsigned int)0x00004000)        /*!<Extended mode enable       */
#define  FMC_BCR4_ASYNCWAIT                 ((unsigned int)0x00008000)        /*!<Asynchronous wait          */
#define  FMC_BCR4_CBURSTRW                  ((unsigned int)0x00080000)        /*!<Write burst enable         */

/******************  Bit definition for FMC_BTR1 register  ******************/
#define  FMC_BTR1_ADDSET                    ((unsigned int)0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BTR1_ADDSET_0                  ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_BTR1_ADDSET_1                  ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_BTR1_ADDSET_2                  ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_BTR1_ADDSET_3                  ((unsigned int)0x00000008)        /*!<Bit 3 */

#define  FMC_BTR1_ADDHLD                    ((unsigned int)0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration)  */
#define  FMC_BTR1_ADDHLD_0                  ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BTR1_ADDHLD_1                  ((unsigned int)0x00000020)        /*!<Bit 1 */
#define  FMC_BTR1_ADDHLD_2                  ((unsigned int)0x00000040)        /*!<Bit 2 */
#define  FMC_BTR1_ADDHLD_3                  ((unsigned int)0x00000080)        /*!<Bit 3 */

#define  FMC_BTR1_DATAST                    ((unsigned int)0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BTR1_DATAST_0                  ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_BTR1_DATAST_1                  ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_BTR1_DATAST_2                  ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_BTR1_DATAST_3                  ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_BTR1_DATAST_4                  ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_BTR1_DATAST_5                  ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_BTR1_DATAST_6                  ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_BTR1_DATAST_7                  ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_BTR1_BUSTURN                   ((unsigned int)0x000F0000)        /*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FMC_BTR1_BUSTURN_0                 ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_BTR1_BUSTURN_1                 ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_BTR1_BUSTURN_2                 ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_BTR1_BUSTURN_3                 ((unsigned int)0x00080000)        /*!<Bit 3 */

#define  FMC_BTR1_CLKDIV                    ((unsigned int)0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BTR1_CLKDIV_0                  ((unsigned int)0x00100000)        /*!<Bit 0 */
#define  FMC_BTR1_CLKDIV_1                  ((unsigned int)0x00200000)        /*!<Bit 1 */
#define  FMC_BTR1_CLKDIV_2                  ((unsigned int)0x00400000)        /*!<Bit 2 */
#define  FMC_BTR1_CLKDIV_3                  ((unsigned int)0x00800000)        /*!<Bit 3 */

#define  FMC_BTR1_DATLAT                    ((unsigned int)0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BTR1_DATLAT_0                  ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_BTR1_DATLAT_1                  ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_BTR1_DATLAT_2                  ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_BTR1_DATLAT_3                  ((unsigned int)0x08000000)        /*!<Bit 3 */

#define  FMC_BTR1_ACCMOD                    ((unsigned int)0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BTR1_ACCMOD_0                  ((unsigned int)0x10000000)        /*!<Bit 0 */
#define  FMC_BTR1_ACCMOD_1                  ((unsigned int)0x20000000)        /*!<Bit 1 */

/******************  Bit definition for FMC_BTR2 register  *******************/
#define  FMC_BTR2_ADDSET                    ((unsigned int)0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BTR2_ADDSET_0                  ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_BTR2_ADDSET_1                  ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_BTR2_ADDSET_2                  ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_BTR2_ADDSET_3                  ((unsigned int)0x00000008)        /*!<Bit 3 */

#define  FMC_BTR2_ADDHLD                    ((unsigned int)0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BTR2_ADDHLD_0                  ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BTR2_ADDHLD_1                  ((unsigned int)0x00000020)        /*!<Bit 1 */
#define  FMC_BTR2_ADDHLD_2                  ((unsigned int)0x00000040)        /*!<Bit 2 */
#define  FMC_BTR2_ADDHLD_3                  ((unsigned int)0x00000080)        /*!<Bit 3 */

#define  FMC_BTR2_DATAST                    ((unsigned int)0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BTR2_DATAST_0                  ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_BTR2_DATAST_1                  ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_BTR2_DATAST_2                  ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_BTR2_DATAST_3                  ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_BTR2_DATAST_4                  ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_BTR2_DATAST_5                  ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_BTR2_DATAST_6                  ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_BTR2_DATAST_7                  ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_BTR2_BUSTURN                   ((unsigned int)0x000F0000)        /*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FMC_BTR2_BUSTURN_0                 ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_BTR2_BUSTURN_1                 ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_BTR2_BUSTURN_2                 ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_BTR2_BUSTURN_3                 ((unsigned int)0x00080000)        /*!<Bit 3 */

#define  FMC_BTR2_CLKDIV                    ((unsigned int)0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BTR2_CLKDIV_0                  ((unsigned int)0x00100000)        /*!<Bit 0 */
#define  FMC_BTR2_CLKDIV_1                  ((unsigned int)0x00200000)        /*!<Bit 1 */
#define  FMC_BTR2_CLKDIV_2                  ((unsigned int)0x00400000)        /*!<Bit 2 */
#define  FMC_BTR2_CLKDIV_3                  ((unsigned int)0x00800000)        /*!<Bit 3 */

#define  FMC_BTR2_DATLAT                    ((unsigned int)0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BTR2_DATLAT_0                  ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_BTR2_DATLAT_1                  ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_BTR2_DATLAT_2                  ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_BTR2_DATLAT_3                  ((unsigned int)0x08000000)        /*!<Bit 3 */

#define  FMC_BTR2_ACCMOD                    ((unsigned int)0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BTR2_ACCMOD_0                  ((unsigned int)0x10000000)        /*!<Bit 0 */
#define  FMC_BTR2_ACCMOD_1                  ((unsigned int)0x20000000)        /*!<Bit 1 */

/*******************  Bit definition for FMC_BTR3 register  *******************/
#define  FMC_BTR3_ADDSET                    ((unsigned int)0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BTR3_ADDSET_0                  ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_BTR3_ADDSET_1                  ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_BTR3_ADDSET_2                  ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_BTR3_ADDSET_3                  ((unsigned int)0x00000008)        /*!<Bit 3 */

#define  FMC_BTR3_ADDHLD                    ((unsigned int)0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BTR3_ADDHLD_0                  ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BTR3_ADDHLD_1                  ((unsigned int)0x00000020)        /*!<Bit 1 */
#define  FMC_BTR3_ADDHLD_2                  ((unsigned int)0x00000040)        /*!<Bit 2 */
#define  FMC_BTR3_ADDHLD_3                  ((unsigned int)0x00000080)        /*!<Bit 3 */

#define  FMC_BTR3_DATAST                    ((unsigned int)0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BTR3_DATAST_0                  ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_BTR3_DATAST_1                  ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_BTR3_DATAST_2                  ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_BTR3_DATAST_3                  ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_BTR3_DATAST_4                  ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_BTR3_DATAST_5                  ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_BTR3_DATAST_6                  ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_BTR3_DATAST_7                  ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_BTR3_BUSTURN                   ((unsigned int)0x000F0000)        /*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FMC_BTR3_BUSTURN_0                 ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_BTR3_BUSTURN_1                 ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_BTR3_BUSTURN_2                 ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_BTR3_BUSTURN_3                 ((unsigned int)0x00080000)        /*!<Bit 3 */

#define  FMC_BTR3_CLKDIV                    ((unsigned int)0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BTR3_CLKDIV_0                  ((unsigned int)0x00100000)        /*!<Bit 0 */
#define  FMC_BTR3_CLKDIV_1                  ((unsigned int)0x00200000)        /*!<Bit 1 */
#define  FMC_BTR3_CLKDIV_2                  ((unsigned int)0x00400000)        /*!<Bit 2 */
#define  FMC_BTR3_CLKDIV_3                  ((unsigned int)0x00800000)        /*!<Bit 3 */

#define  FMC_BTR3_DATLAT                    ((unsigned int)0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BTR3_DATLAT_0                  ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_BTR3_DATLAT_1                  ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_BTR3_DATLAT_2                  ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_BTR3_DATLAT_3                  ((unsigned int)0x08000000)        /*!<Bit 3 */

#define  FMC_BTR3_ACCMOD                    ((unsigned int)0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BTR3_ACCMOD_0                  ((unsigned int)0x10000000)        /*!<Bit 0 */
#define  FMC_BTR3_ACCMOD_1                  ((unsigned int)0x20000000)        /*!<Bit 1 */

/******************  Bit definition for FMC_BTR4 register  *******************/
#define  FMC_BTR4_ADDSET                    ((unsigned int)0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BTR4_ADDSET_0                  ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_BTR4_ADDSET_1                  ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_BTR4_ADDSET_2                  ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_BTR4_ADDSET_3                  ((unsigned int)0x00000008)        /*!<Bit 3 */

#define  FMC_BTR4_ADDHLD                    ((unsigned int)0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BTR4_ADDHLD_0                  ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BTR4_ADDHLD_1                  ((unsigned int)0x00000020)        /*!<Bit 1 */
#define  FMC_BTR4_ADDHLD_2                  ((unsigned int)0x00000040)        /*!<Bit 2 */
#define  FMC_BTR4_ADDHLD_3                  ((unsigned int)0x00000080)        /*!<Bit 3 */

#define  FMC_BTR4_DATAST                    ((unsigned int)0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BTR4_DATAST_0                  ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_BTR4_DATAST_1                  ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_BTR4_DATAST_2                  ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_BTR4_DATAST_3                  ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_BTR4_DATAST_4                  ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_BTR4_DATAST_5                  ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_BTR4_DATAST_6                  ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_BTR4_DATAST_7                  ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_BTR4_BUSTURN                   ((unsigned int)0x000F0000)        /*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FMC_BTR4_BUSTURN_0                 ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_BTR4_BUSTURN_1                 ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_BTR4_BUSTURN_2                 ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_BTR4_BUSTURN_3                 ((unsigned int)0x00080000)        /*!<Bit 3 */

#define  FMC_BTR4_CLKDIV                    ((unsigned int)0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BTR4_CLKDIV_0                  ((unsigned int)0x00100000)        /*!<Bit 0 */
#define  FMC_BTR4_CLKDIV_1                  ((unsigned int)0x00200000)        /*!<Bit 1 */
#define  FMC_BTR4_CLKDIV_2                  ((unsigned int)0x00400000)        /*!<Bit 2 */
#define  FMC_BTR4_CLKDIV_3                  ((unsigned int)0x00800000)        /*!<Bit 3 */

#define  FMC_BTR4_DATLAT                    ((unsigned int)0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BTR4_DATLAT_0                  ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_BTR4_DATLAT_1                  ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_BTR4_DATLAT_2                  ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_BTR4_DATLAT_3                  ((unsigned int)0x08000000)        /*!<Bit 3 */

#define  FMC_BTR4_ACCMOD                    ((unsigned int)0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BTR4_ACCMOD_0                  ((unsigned int)0x10000000)        /*!<Bit 0 */
#define  FMC_BTR4_ACCMOD_1                  ((unsigned int)0x20000000)        /*!<Bit 1 */

/******************  Bit definition for FMC_BWTR1 register  ******************/
#define  FMC_BWTR1_ADDSET                   ((unsigned int)0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BWTR1_ADDSET_0                 ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_BWTR1_ADDSET_1                 ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_BWTR1_ADDSET_2                 ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_BWTR1_ADDSET_3                 ((unsigned int)0x00000008)        /*!<Bit 3 */

#define  FMC_BWTR1_ADDHLD                   ((unsigned int)0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BWTR1_ADDHLD_0                 ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BWTR1_ADDHLD_1                 ((unsigned int)0x00000020)        /*!<Bit 1 */
#define  FMC_BWTR1_ADDHLD_2                 ((unsigned int)0x00000040)        /*!<Bit 2 */
#define  FMC_BWTR1_ADDHLD_3                 ((unsigned int)0x00000080)        /*!<Bit 3 */

#define  FMC_BWTR1_DATAST                   ((unsigned int)0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BWTR1_DATAST_0                 ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_BWTR1_DATAST_1                 ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_BWTR1_DATAST_2                 ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_BWTR1_DATAST_3                 ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_BWTR1_DATAST_4                 ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_BWTR1_DATAST_5                 ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_BWTR1_DATAST_6                 ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_BWTR1_DATAST_7                 ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_BWTR1_CLKDIV                   ((unsigned int)0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BWTR1_CLKDIV_0                 ((unsigned int)0x00100000)        /*!<Bit 0 */
#define  FMC_BWTR1_CLKDIV_1                 ((unsigned int)0x00200000)        /*!<Bit 1 */
#define  FMC_BWTR1_CLKDIV_2                 ((unsigned int)0x00400000)        /*!<Bit 2 */
#define  FMC_BWTR1_CLKDIV_3                 ((unsigned int)0x00800000)        /*!<Bit 3 */

#define  FMC_BWTR1_DATLAT                   ((unsigned int)0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BWTR1_DATLAT_0                 ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_BWTR1_DATLAT_1                 ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_BWTR1_DATLAT_2                 ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_BWTR1_DATLAT_3                 ((unsigned int)0x08000000)        /*!<Bit 3 */

#define  FMC_BWTR1_ACCMOD                   ((unsigned int)0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BWTR1_ACCMOD_0                 ((unsigned int)0x10000000)        /*!<Bit 0 */
#define  FMC_BWTR1_ACCMOD_1                 ((unsigned int)0x20000000)        /*!<Bit 1 */

/******************  Bit definition for FMC_BWTR2 register  ******************/
#define  FMC_BWTR2_ADDSET                   ((unsigned int)0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BWTR2_ADDSET_0                 ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_BWTR2_ADDSET_1                 ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_BWTR2_ADDSET_2                 ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_BWTR2_ADDSET_3                 ((unsigned int)0x00000008)        /*!<Bit 3 */

#define  FMC_BWTR2_ADDHLD                   ((unsigned int)0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BWTR2_ADDHLD_0                 ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BWTR2_ADDHLD_1                 ((unsigned int)0x00000020)        /*!<Bit 1 */
#define  FMC_BWTR2_ADDHLD_2                 ((unsigned int)0x00000040)        /*!<Bit 2 */
#define  FMC_BWTR2_ADDHLD_3                 ((unsigned int)0x00000080)        /*!<Bit 3 */

#define  FMC_BWTR2_DATAST                   ((unsigned int)0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BWTR2_DATAST_0                 ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_BWTR2_DATAST_1                 ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_BWTR2_DATAST_2                 ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_BWTR2_DATAST_3                 ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_BWTR2_DATAST_4                 ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_BWTR2_DATAST_5                 ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_BWTR2_DATAST_6                 ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_BWTR2_DATAST_7                 ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_BWTR2_CLKDIV                   ((unsigned int)0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BWTR2_CLKDIV_0                 ((unsigned int)0x00100000)        /*!<Bit 0 */
#define  FMC_BWTR2_CLKDIV_1                 ((unsigned int)0x00200000)        /*!<Bit 1*/
#define  FMC_BWTR2_CLKDIV_2                 ((unsigned int)0x00400000)        /*!<Bit 2 */
#define  FMC_BWTR2_CLKDIV_3                 ((unsigned int)0x00800000)        /*!<Bit 3 */

#define  FMC_BWTR2_DATLAT                   ((unsigned int)0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BWTR2_DATLAT_0                 ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_BWTR2_DATLAT_1                 ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_BWTR2_DATLAT_2                 ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_BWTR2_DATLAT_3                 ((unsigned int)0x08000000)        /*!<Bit 3 */

#define  FMC_BWTR2_ACCMOD                   ((unsigned int)0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BWTR2_ACCMOD_0                 ((unsigned int)0x10000000)        /*!<Bit 0 */
#define  FMC_BWTR2_ACCMOD_1                 ((unsigned int)0x20000000)        /*!<Bit 1 */

/******************  Bit definition for FMC_BWTR3 register  ******************/
#define  FMC_BWTR3_ADDSET                   ((unsigned int)0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BWTR3_ADDSET_0                 ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_BWTR3_ADDSET_1                 ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_BWTR3_ADDSET_2                 ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_BWTR3_ADDSET_3                 ((unsigned int)0x00000008)        /*!<Bit 3 */

#define  FMC_BWTR3_ADDHLD                   ((unsigned int)0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BWTR3_ADDHLD_0                 ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BWTR3_ADDHLD_1                 ((unsigned int)0x00000020)        /*!<Bit 1 */
#define  FMC_BWTR3_ADDHLD_2                 ((unsigned int)0x00000040)        /*!<Bit 2 */
#define  FMC_BWTR3_ADDHLD_3                 ((unsigned int)0x00000080)        /*!<Bit 3 */

#define  FMC_BWTR3_DATAST                   ((unsigned int)0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BWTR3_DATAST_0                 ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_BWTR3_DATAST_1                 ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_BWTR3_DATAST_2                 ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_BWTR3_DATAST_3                 ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_BWTR3_DATAST_4                 ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_BWTR3_DATAST_5                 ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_BWTR3_DATAST_6                 ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_BWTR3_DATAST_7                 ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_BWTR3_CLKDIV                   ((unsigned int)0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BWTR3_CLKDIV_0                 ((unsigned int)0x00100000)        /*!<Bit 0 */
#define  FMC_BWTR3_CLKDIV_1                 ((unsigned int)0x00200000)        /*!<Bit 1 */
#define  FMC_BWTR3_CLKDIV_2                 ((unsigned int)0x00400000)        /*!<Bit 2 */
#define  FMC_BWTR3_CLKDIV_3                 ((unsigned int)0x00800000)        /*!<Bit 3 */

#define  FMC_BWTR3_DATLAT                   ((unsigned int)0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BWTR3_DATLAT_0                 ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_BWTR3_DATLAT_1                 ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_BWTR3_DATLAT_2                 ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_BWTR3_DATLAT_3                 ((unsigned int)0x08000000)        /*!<Bit 3 */

#define  FMC_BWTR3_ACCMOD                   ((unsigned int)0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BWTR3_ACCMOD_0                 ((unsigned int)0x10000000)        /*!<Bit 0 */
#define  FMC_BWTR3_ACCMOD_1                 ((unsigned int)0x20000000)        /*!<Bit 1 */

/******************  Bit definition for FMC_BWTR4 register  ******************/
#define  FMC_BWTR4_ADDSET                   ((unsigned int)0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BWTR4_ADDSET_0                 ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_BWTR4_ADDSET_1                 ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_BWTR4_ADDSET_2                 ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_BWTR4_ADDSET_3                 ((unsigned int)0x00000008)        /*!<Bit 3 */

#define  FMC_BWTR4_ADDHLD                   ((unsigned int)0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BWTR4_ADDHLD_0                 ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_BWTR4_ADDHLD_1                 ((unsigned int)0x00000020)        /*!<Bit 1 */
#define  FMC_BWTR4_ADDHLD_2                 ((unsigned int)0x00000040)        /*!<Bit 2 */
#define  FMC_BWTR4_ADDHLD_3                 ((unsigned int)0x00000080)        /*!<Bit 3 */

#define  FMC_BWTR4_DATAST                   ((unsigned int)0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BWTR4_DATAST_0                 ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_BWTR4_DATAST_1                 ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_BWTR4_DATAST_2                 ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_BWTR4_DATAST_3                 ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_BWTR4_DATAST_4                 ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_BWTR4_DATAST_5                 ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_BWTR4_DATAST_6                 ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_BWTR4_DATAST_7                 ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_BWTR4_CLKDIV                   ((unsigned int)0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BWTR4_CLKDIV_0                 ((unsigned int)0x00100000)        /*!<Bit 0 */
#define  FMC_BWTR4_CLKDIV_1                 ((unsigned int)0x00200000)        /*!<Bit 1 */
#define  FMC_BWTR4_CLKDIV_2                 ((unsigned int)0x00400000)        /*!<Bit 2 */
#define  FMC_BWTR4_CLKDIV_3                 ((unsigned int)0x00800000)        /*!<Bit 3 */

#define  FMC_BWTR4_DATLAT                   ((unsigned int)0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BWTR4_DATLAT_0                 ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_BWTR4_DATLAT_1                 ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_BWTR4_DATLAT_2                 ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_BWTR4_DATLAT_3                 ((unsigned int)0x08000000)        /*!<Bit 3 */

#define  FMC_BWTR4_ACCMOD                   ((unsigned int)0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BWTR4_ACCMOD_0                 ((unsigned int)0x10000000)        /*!<Bit 0 */
#define  FMC_BWTR4_ACCMOD_1                 ((unsigned int)0x20000000)        /*!<Bit 1 */

/******************  Bit definition for FMC_PCR2 register  *******************/
#define  FMC_PCR2_PWAITEN                   ((unsigned int)0x00000002)        /*!<Wait feature enable bit                   */
#define  FMC_PCR2_PBKEN                     ((unsigned int)0x00000004)        /*!<PC Card/NAND Flash memory bank enable bit */
#define  FMC_PCR2_PTYP                      ((unsigned int)0x00000008)        /*!<Memory type                               */

#define  FMC_PCR2_PWID                      ((unsigned int)0x00000030)        /*!<PWID[1:0] bits (NAND Flash databus width) */
#define  FMC_PCR2_PWID_0                    ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_PCR2_PWID_1                    ((unsigned int)0x00000020)        /*!<Bit 1 */

#define  FMC_PCR2_ECCEN                     ((unsigned int)0x00000040)        /*!<ECC computation logic enable bit          */

#define  FMC_PCR2_TCLR                      ((unsigned int)0x00001E00)        /*!<TCLR[3:0] bits (CLE to RE delay)          */
#define  FMC_PCR2_TCLR_0                    ((unsigned int)0x00000200)        /*!<Bit 0 */
#define  FMC_PCR2_TCLR_1                    ((unsigned int)0x00000400)        /*!<Bit 1 */
#define  FMC_PCR2_TCLR_2                    ((unsigned int)0x00000800)        /*!<Bit 2 */
#define  FMC_PCR2_TCLR_3                    ((unsigned int)0x00001000)        /*!<Bit 3 */

#define  FMC_PCR2_TAR                       ((unsigned int)0x0001E000)        /*!<TAR[3:0] bits (ALE to RE delay)           */
#define  FMC_PCR2_TAR_0                     ((unsigned int)0x00002000)        /*!<Bit 0 */
#define  FMC_PCR2_TAR_1                     ((unsigned int)0x00004000)        /*!<Bit 1 */
#define  FMC_PCR2_TAR_2                     ((unsigned int)0x00008000)        /*!<Bit 2 */
#define  FMC_PCR2_TAR_3                     ((unsigned int)0x00010000)        /*!<Bit 3 */

#define  FMC_PCR2_ECCPS                     ((unsigned int)0x000E0000)        /*!<ECCPS[1:0] bits (ECC page size)           */
#define  FMC_PCR2_ECCPS_0                   ((unsigned int)0x00020000)        /*!<Bit 0 */
#define  FMC_PCR2_ECCPS_1                   ((unsigned int)0x00040000)        /*!<Bit 1 */
#define  FMC_PCR2_ECCPS_2                   ((unsigned int)0x00080000)        /*!<Bit 2 */

/******************  Bit definition for FMC_PCR3 register  *******************/
#define  FMC_PCR3_PWAITEN                   ((unsigned int)0x00000002)        /*!<Wait feature enable bit                   */
#define  FMC_PCR3_PBKEN                     ((unsigned int)0x00000004)        /*!<PC Card/NAND Flash memory bank enable bit */
#define  FMC_PCR3_PTYP                      ((unsigned int)0x00000008)        /*!<Memory type                               */

#define  FMC_PCR3_PWID                      ((unsigned int)0x00000030)        /*!<PWID[1:0] bits (NAND Flash databus width) */
#define  FMC_PCR3_PWID_0                    ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_PCR3_PWID_1                    ((unsigned int)0x00000020)        /*!<Bit 1 */

#define  FMC_PCR3_ECCEN                     ((unsigned int)0x00000040)        /*!<ECC computation logic enable bit          */

#define  FMC_PCR3_TCLR                      ((unsigned int)0x00001E00)        /*!<TCLR[3:0] bits (CLE to RE delay)          */
#define  FMC_PCR3_TCLR_0                    ((unsigned int)0x00000200)        /*!<Bit 0 */
#define  FMC_PCR3_TCLR_1                    ((unsigned int)0x00000400)        /*!<Bit 1 */
#define  FMC_PCR3_TCLR_2                    ((unsigned int)0x00000800)        /*!<Bit 2 */
#define  FMC_PCR3_TCLR_3                    ((unsigned int)0x00001000)        /*!<Bit 3 */

#define  FMC_PCR3_TAR                       ((unsigned int)0x0001E000)        /*!<TAR[3:0] bits (ALE to RE delay)           */
#define  FMC_PCR3_TAR_0                     ((unsigned int)0x00002000)        /*!<Bit 0 */
#define  FMC_PCR3_TAR_1                     ((unsigned int)0x00004000)        /*!<Bit 1 */
#define  FMC_PCR3_TAR_2                     ((unsigned int)0x00008000)        /*!<Bit 2 */
#define  FMC_PCR3_TAR_3                     ((unsigned int)0x00010000)        /*!<Bit 3 */

#define  FMC_PCR3_ECCPS                     ((unsigned int)0x000E0000)        /*!<ECCPS[2:0] bits (ECC page size)           */
#define  FMC_PCR3_ECCPS_0                   ((unsigned int)0x00020000)        /*!<Bit 0 */
#define  FMC_PCR3_ECCPS_1                   ((unsigned int)0x00040000)        /*!<Bit 1 */
#define  FMC_PCR3_ECCPS_2                   ((unsigned int)0x00080000)        /*!<Bit 2 */

/******************  Bit definition for FMC_PCR4 register  *******************/
#define  FMC_PCR4_PWAITEN                   ((unsigned int)0x00000002)        /*!<Wait feature enable bit                   */
#define  FMC_PCR4_PBKEN                     ((unsigned int)0x00000004)        /*!<PC Card/NAND Flash memory bank enable bit */
#define  FMC_PCR4_PTYP                      ((unsigned int)0x00000008)        /*!<Memory type                               */

#define  FMC_PCR4_PWID                      ((unsigned int)0x00000030)        /*!<PWID[1:0] bits (NAND Flash databus width) */
#define  FMC_PCR4_PWID_0                    ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_PCR4_PWID_1                    ((unsigned int)0x00000020)        /*!<Bit 1 */

#define  FMC_PCR4_ECCEN                     ((unsigned int)0x00000040)        /*!<ECC computation logic enable bit          */

#define  FMC_PCR4_TCLR                      ((unsigned int)0x00001E00)        /*!<TCLR[3:0] bits (CLE to RE delay)          */
#define  FMC_PCR4_TCLR_0                    ((unsigned int)0x00000200)        /*!<Bit 0 */
#define  FMC_PCR4_TCLR_1                    ((unsigned int)0x00000400)        /*!<Bit 1 */
#define  FMC_PCR4_TCLR_2                    ((unsigned int)0x00000800)        /*!<Bit 2 */
#define  FMC_PCR4_TCLR_3                    ((unsigned int)0x00001000)        /*!<Bit 3 */

#define  FMC_PCR4_TAR                       ((unsigned int)0x0001E000)        /*!<TAR[3:0] bits (ALE to RE delay)           */
#define  FMC_PCR4_TAR_0                     ((unsigned int)0x00002000)        /*!<Bit 0 */
#define  FMC_PCR4_TAR_1                     ((unsigned int)0x00004000)        /*!<Bit 1 */
#define  FMC_PCR4_TAR_2                     ((unsigned int)0x00008000)        /*!<Bit 2 */
#define  FMC_PCR4_TAR_3                     ((unsigned int)0x00010000)        /*!<Bit 3 */

#define  FMC_PCR4_ECCPS                     ((unsigned int)0x000E0000)        /*!<ECCPS[2:0] bits (ECC page size)           */
#define  FMC_PCR4_ECCPS_0                   ((unsigned int)0x00020000)        /*!<Bit 0 */
#define  FMC_PCR4_ECCPS_1                   ((unsigned int)0x00040000)        /*!<Bit 1 */
#define  FMC_PCR4_ECCPS_2                   ((unsigned int)0x00080000)        /*!<Bit 2 */

/*******************  Bit definition for FMC_SR2 register  *******************/
#define  FMC_SR2_IRS                        ((unsigned char)0x01)               /*!<Interrupt Rising Edge status                */
#define  FMC_SR2_ILS                        ((unsigned char)0x02)               /*!<Interrupt Level status                      */
#define  FMC_SR2_IFS                        ((unsigned char)0x04)               /*!<Interrupt Falling Edge status               */
#define  FMC_SR2_IREN                       ((unsigned char)0x08)               /*!<Interrupt Rising Edge detection Enable bit  */
#define  FMC_SR2_ILEN                       ((unsigned char)0x10)               /*!<Interrupt Level detection Enable bit        */
#define  FMC_SR2_IFEN                       ((unsigned char)0x20)               /*!<Interrupt Falling Edge detection Enable bit */
#define  FMC_SR2_FEMPT                      ((unsigned char)0x40)               /*!<FIFO empty                                  */

/*******************  Bit definition for FMC_SR3 register  *******************/
#define  FMC_SR3_IRS                        ((unsigned char)0x01)               /*!<Interrupt Rising Edge status                */
#define  FMC_SR3_ILS                        ((unsigned char)0x02)               /*!<Interrupt Level status                      */
#define  FMC_SR3_IFS                        ((unsigned char)0x04)               /*!<Interrupt Falling Edge status               */
#define  FMC_SR3_IREN                       ((unsigned char)0x08)               /*!<Interrupt Rising Edge detection Enable bit  */
#define  FMC_SR3_ILEN                       ((unsigned char)0x10)               /*!<Interrupt Level detection Enable bit        */
#define  FMC_SR3_IFEN                       ((unsigned char)0x20)               /*!<Interrupt Falling Edge detection Enable bit */
#define  FMC_SR3_FEMPT                      ((unsigned char)0x40)               /*!<FIFO empty                                  */

/*******************  Bit definition for FMC_SR4 register  *******************/
#define  FMC_SR4_IRS                        ((unsigned char)0x01)               /*!<Interrupt Rising Edge status                */
#define  FMC_SR4_ILS                        ((unsigned char)0x02)               /*!<Interrupt Level status                      */
#define  FMC_SR4_IFS                        ((unsigned char)0x04)               /*!<Interrupt Falling Edge status               */
#define  FMC_SR4_IREN                       ((unsigned char)0x08)               /*!<Interrupt Rising Edge detection Enable bit  */
#define  FMC_SR4_ILEN                       ((unsigned char)0x10)               /*!<Interrupt Level detection Enable bit        */
#define  FMC_SR4_IFEN                       ((unsigned char)0x20)               /*!<Interrupt Falling Edge detection Enable bit */
#define  FMC_SR4_FEMPT                      ((unsigned char)0x40)               /*!<FIFO empty                                  */

/******************  Bit definition for FMC_PMEM2 register  ******************/
#define  FMC_PMEM2_MEMSET2                  ((unsigned int)0x000000FF)        /*!<MEMSET2[7:0] bits (Common memory 2 setup time) */
#define  FMC_PMEM2_MEMSET2_0                ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_PMEM2_MEMSET2_1                ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_PMEM2_MEMSET2_2                ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_PMEM2_MEMSET2_3                ((unsigned int)0x00000008)        /*!<Bit 3 */
#define  FMC_PMEM2_MEMSET2_4                ((unsigned int)0x00000010)        /*!<Bit 4 */
#define  FMC_PMEM2_MEMSET2_5                ((unsigned int)0x00000020)        /*!<Bit 5 */
#define  FMC_PMEM2_MEMSET2_6                ((unsigned int)0x00000040)        /*!<Bit 6 */
#define  FMC_PMEM2_MEMSET2_7                ((unsigned int)0x00000080)        /*!<Bit 7 */

#define  FMC_PMEM2_MEMWAIT2                 ((unsigned int)0x0000FF00)        /*!<MEMWAIT2[7:0] bits (Common memory 2 wait time) */
#define  FMC_PMEM2_MEMWAIT2_0               ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_PMEM2_MEMWAIT2_1               ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_PMEM2_MEMWAIT2_2               ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_PMEM2_MEMWAIT2_3               ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_PMEM2_MEMWAIT2_4               ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_PMEM2_MEMWAIT2_5               ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_PMEM2_MEMWAIT2_6               ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_PMEM2_MEMWAIT2_7               ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_PMEM2_MEMHOLD2                 ((unsigned int)0x00FF0000)        /*!<MEMHOLD2[7:0] bits (Common memory 2 hold time) */
#define  FMC_PMEM2_MEMHOLD2_0               ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_PMEM2_MEMHOLD2_1               ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_PMEM2_MEMHOLD2_2               ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_PMEM2_MEMHOLD2_3               ((unsigned int)0x00080000)        /*!<Bit 3 */
#define  FMC_PMEM2_MEMHOLD2_4               ((unsigned int)0x00100000)        /*!<Bit 4 */
#define  FMC_PMEM2_MEMHOLD2_5               ((unsigned int)0x00200000)        /*!<Bit 5 */
#define  FMC_PMEM2_MEMHOLD2_6               ((unsigned int)0x00400000)        /*!<Bit 6 */
#define  FMC_PMEM2_MEMHOLD2_7               ((unsigned int)0x00800000)        /*!<Bit 7 */

#define  FMC_PMEM2_MEMHIZ2                  ((unsigned int)0xFF000000)        /*!<MEMHIZ2[7:0] bits (Common memory 2 databus HiZ time) */
#define  FMC_PMEM2_MEMHIZ2_0                ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_PMEM2_MEMHIZ2_1                ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_PMEM2_MEMHIZ2_2                ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_PMEM2_MEMHIZ2_3                ((unsigned int)0x08000000)        /*!<Bit 3 */
#define  FMC_PMEM2_MEMHIZ2_4                ((unsigned int)0x10000000)        /*!<Bit 4 */
#define  FMC_PMEM2_MEMHIZ2_5                ((unsigned int)0x20000000)        /*!<Bit 5 */
#define  FMC_PMEM2_MEMHIZ2_6                ((unsigned int)0x40000000)        /*!<Bit 6 */
#define  FMC_PMEM2_MEMHIZ2_7                ((unsigned int)0x80000000)        /*!<Bit 7 */

/******************  Bit definition for FMC_PMEM3 register  ******************/
#define  FMC_PMEM3_MEMSET3                  ((unsigned int)0x000000FF)        /*!<MEMSET3[7:0] bits (Common memory 3 setup time) */
#define  FMC_PMEM3_MEMSET3_0                ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_PMEM3_MEMSET3_1                ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_PMEM3_MEMSET3_2                ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_PMEM3_MEMSET3_3                ((unsigned int)0x00000008)        /*!<Bit 3 */
#define  FMC_PMEM3_MEMSET3_4                ((unsigned int)0x00000010)        /*!<Bit 4 */
#define  FMC_PMEM3_MEMSET3_5                ((unsigned int)0x00000020)        /*!<Bit 5 */
#define  FMC_PMEM3_MEMSET3_6                ((unsigned int)0x00000040)        /*!<Bit 6 */
#define  FMC_PMEM3_MEMSET3_7                ((unsigned int)0x00000080)        /*!<Bit 7 */

#define  FMC_PMEM3_MEMWAIT3                 ((unsigned int)0x0000FF00)        /*!<MEMWAIT3[7:0] bits (Common memory 3 wait time) */
#define  FMC_PMEM3_MEMWAIT3_0               ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_PMEM3_MEMWAIT3_1               ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_PMEM3_MEMWAIT3_2               ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_PMEM3_MEMWAIT3_3               ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_PMEM3_MEMWAIT3_4               ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_PMEM3_MEMWAIT3_5               ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_PMEM3_MEMWAIT3_6               ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_PMEM3_MEMWAIT3_7               ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_PMEM3_MEMHOLD3                 ((unsigned int)0x00FF0000)        /*!<MEMHOLD3[7:0] bits (Common memory 3 hold time) */
#define  FMC_PMEM3_MEMHOLD3_0               ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_PMEM3_MEMHOLD3_1               ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_PMEM3_MEMHOLD3_2               ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_PMEM3_MEMHOLD3_3               ((unsigned int)0x00080000)        /*!<Bit 3 */
#define  FMC_PMEM3_MEMHOLD3_4               ((unsigned int)0x00100000)        /*!<Bit 4 */
#define  FMC_PMEM3_MEMHOLD3_5               ((unsigned int)0x00200000)        /*!<Bit 5 */
#define  FMC_PMEM3_MEMHOLD3_6               ((unsigned int)0x00400000)        /*!<Bit 6 */
#define  FMC_PMEM3_MEMHOLD3_7               ((unsigned int)0x00800000)        /*!<Bit 7 */

#define  FMC_PMEM3_MEMHIZ3                  ((unsigned int)0xFF000000)        /*!<MEMHIZ3[7:0] bits (Common memory 3 databus HiZ time) */
#define  FMC_PMEM3_MEMHIZ3_0                ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_PMEM3_MEMHIZ3_1                ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_PMEM3_MEMHIZ3_2                ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_PMEM3_MEMHIZ3_3                ((unsigned int)0x08000000)        /*!<Bit 3 */
#define  FMC_PMEM3_MEMHIZ3_4                ((unsigned int)0x10000000)        /*!<Bit 4 */
#define  FMC_PMEM3_MEMHIZ3_5                ((unsigned int)0x20000000)        /*!<Bit 5 */
#define  FMC_PMEM3_MEMHIZ3_6                ((unsigned int)0x40000000)        /*!<Bit 6 */
#define  FMC_PMEM3_MEMHIZ3_7                ((unsigned int)0x80000000)        /*!<Bit 7 */

/******************  Bit definition for FMC_PMEM4 register  ******************/
#define  FMC_PMEM4_MEMSET4                  ((unsigned int)0x000000FF)        /*!<MEMSET4[7:0] bits (Common memory 4 setup time) */
#define  FMC_PMEM4_MEMSET4_0                ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_PMEM4_MEMSET4_1                ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_PMEM4_MEMSET4_2                ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_PMEM4_MEMSET4_3                ((unsigned int)0x00000008)        /*!<Bit 3 */
#define  FMC_PMEM4_MEMSET4_4                ((unsigned int)0x00000010)        /*!<Bit 4 */
#define  FMC_PMEM4_MEMSET4_5                ((unsigned int)0x00000020)        /*!<Bit 5 */
#define  FMC_PMEM4_MEMSET4_6                ((unsigned int)0x00000040)        /*!<Bit 6 */
#define  FMC_PMEM4_MEMSET4_7                ((unsigned int)0x00000080)        /*!<Bit 7 */

#define  FMC_PMEM4_MEMWAIT4                 ((unsigned int)0x0000FF00)        /*!<MEMWAIT4[7:0] bits (Common memory 4 wait time) */
#define  FMC_PMEM4_MEMWAIT4_0               ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_PMEM4_MEMWAIT4_1               ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_PMEM4_MEMWAIT4_2               ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_PMEM4_MEMWAIT4_3               ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_PMEM4_MEMWAIT4_4               ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_PMEM4_MEMWAIT4_5               ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_PMEM4_MEMWAIT4_6               ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_PMEM4_MEMWAIT4_7               ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_PMEM4_MEMHOLD4                 ((unsigned int)0x00FF0000)        /*!<MEMHOLD4[7:0] bits (Common memory 4 hold time) */
#define  FMC_PMEM4_MEMHOLD4_0               ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_PMEM4_MEMHOLD4_1               ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_PMEM4_MEMHOLD4_2               ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_PMEM4_MEMHOLD4_3               ((unsigned int)0x00080000)        /*!<Bit 3 */
#define  FMC_PMEM4_MEMHOLD4_4               ((unsigned int)0x00100000)        /*!<Bit 4 */
#define  FMC_PMEM4_MEMHOLD4_5               ((unsigned int)0x00200000)        /*!<Bit 5 */
#define  FMC_PMEM4_MEMHOLD4_6               ((unsigned int)0x00400000)        /*!<Bit 6 */
#define  FMC_PMEM4_MEMHOLD4_7               ((unsigned int)0x00800000)        /*!<Bit 7 */

#define  FMC_PMEM4_MEMHIZ4                  ((unsigned int)0xFF000000)        /*!<MEMHIZ4[7:0] bits (Common memory 4 databus HiZ time) */
#define  FMC_PMEM4_MEMHIZ4_0                ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_PMEM4_MEMHIZ4_1                ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_PMEM4_MEMHIZ4_2                ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_PMEM4_MEMHIZ4_3                ((unsigned int)0x08000000)        /*!<Bit 3 */
#define  FMC_PMEM4_MEMHIZ4_4                ((unsigned int)0x10000000)        /*!<Bit 4 */
#define  FMC_PMEM4_MEMHIZ4_5                ((unsigned int)0x20000000)        /*!<Bit 5 */
#define  FMC_PMEM4_MEMHIZ4_6                ((unsigned int)0x40000000)        /*!<Bit 6 */
#define  FMC_PMEM4_MEMHIZ4_7                ((unsigned int)0x80000000)        /*!<Bit 7 */

/******************  Bit definition for FMC_PATT2 register  ******************/
#define  FMC_PATT2_ATTSET2                  ((unsigned int)0x000000FF)        /*!<ATTSET2[7:0] bits (Attribute memory 2 setup time) */
#define  FMC_PATT2_ATTSET2_0                ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_PATT2_ATTSET2_1                ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_PATT2_ATTSET2_2                ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_PATT2_ATTSET2_3                ((unsigned int)0x00000008)        /*!<Bit 3 */
#define  FMC_PATT2_ATTSET2_4                ((unsigned int)0x00000010)        /*!<Bit 4 */
#define  FMC_PATT2_ATTSET2_5                ((unsigned int)0x00000020)        /*!<Bit 5 */
#define  FMC_PATT2_ATTSET2_6                ((unsigned int)0x00000040)        /*!<Bit 6 */
#define  FMC_PATT2_ATTSET2_7                ((unsigned int)0x00000080)        /*!<Bit 7 */

#define  FMC_PATT2_ATTWAIT2                 ((unsigned int)0x0000FF00)        /*!<ATTWAIT2[7:0] bits (Attribute memory 2 wait time) */
#define  FMC_PATT2_ATTWAIT2_0               ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_PATT2_ATTWAIT2_1               ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_PATT2_ATTWAIT2_2               ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_PATT2_ATTWAIT2_3               ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_PATT2_ATTWAIT2_4               ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_PATT2_ATTWAIT2_5               ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_PATT2_ATTWAIT2_6               ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_PATT2_ATTWAIT2_7               ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_PATT2_ATTHOLD2                 ((unsigned int)0x00FF0000)        /*!<ATTHOLD2[7:0] bits (Attribute memory 2 hold time) */
#define  FMC_PATT2_ATTHOLD2_0               ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_PATT2_ATTHOLD2_1               ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_PATT2_ATTHOLD2_2               ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_PATT2_ATTHOLD2_3               ((unsigned int)0x00080000)        /*!<Bit 3 */
#define  FMC_PATT2_ATTHOLD2_4               ((unsigned int)0x00100000)        /*!<Bit 4 */
#define  FMC_PATT2_ATTHOLD2_5               ((unsigned int)0x00200000)        /*!<Bit 5 */
#define  FMC_PATT2_ATTHOLD2_6               ((unsigned int)0x00400000)        /*!<Bit 6 */
#define  FMC_PATT2_ATTHOLD2_7               ((unsigned int)0x00800000)        /*!<Bit 7 */

#define  FMC_PATT2_ATTHIZ2                  ((unsigned int)0xFF000000)        /*!<ATTHIZ2[7:0] bits (Attribute memory 2 databus HiZ time) */
#define  FMC_PATT2_ATTHIZ2_0                ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_PATT2_ATTHIZ2_1                ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_PATT2_ATTHIZ2_2                ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_PATT2_ATTHIZ2_3                ((unsigned int)0x08000000)        /*!<Bit 3 */
#define  FMC_PATT2_ATTHIZ2_4                ((unsigned int)0x10000000)        /*!<Bit 4 */
#define  FMC_PATT2_ATTHIZ2_5                ((unsigned int)0x20000000)        /*!<Bit 5 */
#define  FMC_PATT2_ATTHIZ2_6                ((unsigned int)0x40000000)        /*!<Bit 6 */
#define  FMC_PATT2_ATTHIZ2_7                ((unsigned int)0x80000000)        /*!<Bit 7 */

/******************  Bit definition for FMC_PATT3 register  ******************/
#define  FMC_PATT3_ATTSET3                  ((unsigned int)0x000000FF)        /*!<ATTSET3[7:0] bits (Attribute memory 3 setup time) */
#define  FMC_PATT3_ATTSET3_0                ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_PATT3_ATTSET3_1                ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_PATT3_ATTSET3_2                ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_PATT3_ATTSET3_3                ((unsigned int)0x00000008)        /*!<Bit 3 */
#define  FMC_PATT3_ATTSET3_4                ((unsigned int)0x00000010)        /*!<Bit 4 */
#define  FMC_PATT3_ATTSET3_5                ((unsigned int)0x00000020)        /*!<Bit 5 */
#define  FMC_PATT3_ATTSET3_6                ((unsigned int)0x00000040)        /*!<Bit 6 */
#define  FMC_PATT3_ATTSET3_7                ((unsigned int)0x00000080)        /*!<Bit 7 */

#define  FMC_PATT3_ATTWAIT3                 ((unsigned int)0x0000FF00)        /*!<ATTWAIT3[7:0] bits (Attribute memory 3 wait time) */
#define  FMC_PATT3_ATTWAIT3_0               ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_PATT3_ATTWAIT3_1               ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_PATT3_ATTWAIT3_2               ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_PATT3_ATTWAIT3_3               ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_PATT3_ATTWAIT3_4               ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_PATT3_ATTWAIT3_5               ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_PATT3_ATTWAIT3_6               ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_PATT3_ATTWAIT3_7               ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_PATT3_ATTHOLD3                 ((unsigned int)0x00FF0000)        /*!<ATTHOLD3[7:0] bits (Attribute memory 3 hold time) */
#define  FMC_PATT3_ATTHOLD3_0               ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_PATT3_ATTHOLD3_1               ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_PATT3_ATTHOLD3_2               ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_PATT3_ATTHOLD3_3               ((unsigned int)0x00080000)        /*!<Bit 3 */
#define  FMC_PATT3_ATTHOLD3_4               ((unsigned int)0x00100000)        /*!<Bit 4 */
#define  FMC_PATT3_ATTHOLD3_5               ((unsigned int)0x00200000)        /*!<Bit 5 */
#define  FMC_PATT3_ATTHOLD3_6               ((unsigned int)0x00400000)        /*!<Bit 6 */
#define  FMC_PATT3_ATTHOLD3_7               ((unsigned int)0x00800000)        /*!<Bit 7 */

#define  FMC_PATT3_ATTHIZ3                  ((unsigned int)0xFF000000)        /*!<ATTHIZ3[7:0] bits (Attribute memory 3 databus HiZ time) */
#define  FMC_PATT3_ATTHIZ3_0                ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_PATT3_ATTHIZ3_1                ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_PATT3_ATTHIZ3_2                ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_PATT3_ATTHIZ3_3                ((unsigned int)0x08000000)        /*!<Bit 3 */
#define  FMC_PATT3_ATTHIZ3_4                ((unsigned int)0x10000000)        /*!<Bit 4 */
#define  FMC_PATT3_ATTHIZ3_5                ((unsigned int)0x20000000)        /*!<Bit 5 */
#define  FMC_PATT3_ATTHIZ3_6                ((unsigned int)0x40000000)        /*!<Bit 6 */
#define  FMC_PATT3_ATTHIZ3_7                ((unsigned int)0x80000000)        /*!<Bit 7 */

/******************  Bit definition for FMC_PATT4 register  ******************/
#define  FMC_PATT4_ATTSET4                  ((unsigned int)0x000000FF)        /*!<ATTSET4[7:0] bits (Attribute memory 4 setup time) */
#define  FMC_PATT4_ATTSET4_0                ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_PATT4_ATTSET4_1                ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_PATT4_ATTSET4_2                ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_PATT4_ATTSET4_3                ((unsigned int)0x00000008)        /*!<Bit 3 */
#define  FMC_PATT4_ATTSET4_4                ((unsigned int)0x00000010)        /*!<Bit 4 */
#define  FMC_PATT4_ATTSET4_5                ((unsigned int)0x00000020)        /*!<Bit 5 */
#define  FMC_PATT4_ATTSET4_6                ((unsigned int)0x00000040)        /*!<Bit 6 */
#define  FMC_PATT4_ATTSET4_7                ((unsigned int)0x00000080)        /*!<Bit 7 */

#define  FMC_PATT4_ATTWAIT4                 ((unsigned int)0x0000FF00)        /*!<ATTWAIT4[7:0] bits (Attribute memory 4 wait time) */
#define  FMC_PATT4_ATTWAIT4_0               ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_PATT4_ATTWAIT4_1               ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_PATT4_ATTWAIT4_2               ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_PATT4_ATTWAIT4_3               ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_PATT4_ATTWAIT4_4               ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_PATT4_ATTWAIT4_5               ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_PATT4_ATTWAIT4_6               ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_PATT4_ATTWAIT4_7               ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_PATT4_ATTHOLD4                 ((unsigned int)0x00FF0000)        /*!<ATTHOLD4[7:0] bits (Attribute memory 4 hold time) */
#define  FMC_PATT4_ATTHOLD4_0               ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_PATT4_ATTHOLD4_1               ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_PATT4_ATTHOLD4_2               ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_PATT4_ATTHOLD4_3               ((unsigned int)0x00080000)        /*!<Bit 3 */
#define  FMC_PATT4_ATTHOLD4_4               ((unsigned int)0x00100000)        /*!<Bit 4 */
#define  FMC_PATT4_ATTHOLD4_5               ((unsigned int)0x00200000)        /*!<Bit 5 */
#define  FMC_PATT4_ATTHOLD4_6               ((unsigned int)0x00400000)        /*!<Bit 6 */
#define  FMC_PATT4_ATTHOLD4_7               ((unsigned int)0x00800000)        /*!<Bit 7 */

#define  FMC_PATT4_ATTHIZ4                  ((unsigned int)0xFF000000)        /*!<ATTHIZ4[7:0] bits (Attribute memory 4 databus HiZ time) */
#define  FMC_PATT4_ATTHIZ4_0                ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_PATT4_ATTHIZ4_1                ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_PATT4_ATTHIZ4_2                ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_PATT4_ATTHIZ4_3                ((unsigned int)0x08000000)        /*!<Bit 3 */
#define  FMC_PATT4_ATTHIZ4_4                ((unsigned int)0x10000000)        /*!<Bit 4 */
#define  FMC_PATT4_ATTHIZ4_5                ((unsigned int)0x20000000)        /*!<Bit 5 */
#define  FMC_PATT4_ATTHIZ4_6                ((unsigned int)0x40000000)        /*!<Bit 6 */
#define  FMC_PATT4_ATTHIZ4_7                ((unsigned int)0x80000000)        /*!<Bit 7 */

/******************  Bit definition for FMC_PIO4 register  *******************/
#define  FMC_PIO4_IOSET4                    ((unsigned int)0x000000FF)        /*!<IOSET4[7:0] bits (I/O 4 setup time) */
#define  FMC_PIO4_IOSET4_0                  ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_PIO4_IOSET4_1                  ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_PIO4_IOSET4_2                  ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_PIO4_IOSET4_3                  ((unsigned int)0x00000008)        /*!<Bit 3 */
#define  FMC_PIO4_IOSET4_4                  ((unsigned int)0x00000010)        /*!<Bit 4 */
#define  FMC_PIO4_IOSET4_5                  ((unsigned int)0x00000020)        /*!<Bit 5 */
#define  FMC_PIO4_IOSET4_6                  ((unsigned int)0x00000040)        /*!<Bit 6 */
#define  FMC_PIO4_IOSET4_7                  ((unsigned int)0x00000080)        /*!<Bit 7 */

#define  FMC_PIO4_IOWAIT4                   ((unsigned int)0x0000FF00)        /*!<IOWAIT4[7:0] bits (I/O 4 wait time) */
#define  FMC_PIO4_IOWAIT4_0                 ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_PIO4_IOWAIT4_1                 ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_PIO4_IOWAIT4_2                 ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_PIO4_IOWAIT4_3                 ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  FMC_PIO4_IOWAIT4_4                 ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  FMC_PIO4_IOWAIT4_5                 ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  FMC_PIO4_IOWAIT4_6                 ((unsigned int)0x00004000)        /*!<Bit 6 */
#define  FMC_PIO4_IOWAIT4_7                 ((unsigned int)0x00008000)        /*!<Bit 7 */

#define  FMC_PIO4_IOHOLD4                   ((unsigned int)0x00FF0000)        /*!<IOHOLD4[7:0] bits (I/O 4 hold time) */
#define  FMC_PIO4_IOHOLD4_0                 ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_PIO4_IOHOLD4_1                 ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_PIO4_IOHOLD4_2                 ((unsigned int)0x00040000)        /*!<Bit 2 */
#define  FMC_PIO4_IOHOLD4_3                 ((unsigned int)0x00080000)        /*!<Bit 3 */
#define  FMC_PIO4_IOHOLD4_4                 ((unsigned int)0x00100000)        /*!<Bit 4 */
#define  FMC_PIO4_IOHOLD4_5                 ((unsigned int)0x00200000)        /*!<Bit 5 */
#define  FMC_PIO4_IOHOLD4_6                 ((unsigned int)0x00400000)        /*!<Bit 6 */
#define  FMC_PIO4_IOHOLD4_7                 ((unsigned int)0x00800000)        /*!<Bit 7 */

#define  FMC_PIO4_IOHIZ4                    ((unsigned int)0xFF000000)        /*!<IOHIZ4[7:0] bits (I/O 4 databus HiZ time) */
#define  FMC_PIO4_IOHIZ4_0                  ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_PIO4_IOHIZ4_1                  ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_PIO4_IOHIZ4_2                  ((unsigned int)0x04000000)        /*!<Bit 2 */
#define  FMC_PIO4_IOHIZ4_3                  ((unsigned int)0x08000000)        /*!<Bit 3 */
#define  FMC_PIO4_IOHIZ4_4                  ((unsigned int)0x10000000)        /*!<Bit 4 */
#define  FMC_PIO4_IOHIZ4_5                  ((unsigned int)0x20000000)        /*!<Bit 5 */
#define  FMC_PIO4_IOHIZ4_6                  ((unsigned int)0x40000000)        /*!<Bit 6 */
#define  FMC_PIO4_IOHIZ4_7                  ((unsigned int)0x80000000)        /*!<Bit 7 */

/******************  Bit definition for FMC_ECCR2 register  ******************/
#define  FMC_ECCR2_ECC2                     ((unsigned int)0xFFFFFFFF)        /*!<ECC result */

/******************  Bit definition for FMC_ECCR3 register  ******************/
#define  FMC_ECCR3_ECC3                     ((unsigned int)0xFFFFFFFF)        /*!<ECC result */

/******************  Bit definition for FMC_SDCR1 register  ******************/
#define  FMC_SDCR1_NC                       ((unsigned int)0x00000003)        /*!<NC[1:0] bits (Number of column bits) */
#define  FMC_SDCR1_NC_0                     ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_SDCR1_NC_1                     ((unsigned int)0x00000002)        /*!<Bit 1 */

#define  FMC_SDCR1_NR                       ((unsigned int)0x0000000C)        /*!<NR[1:0] bits (Number of row bits) */
#define  FMC_SDCR1_NR_0                     ((unsigned int)0x00000004)        /*!<Bit 0 */
#define  FMC_SDCR1_NR_1                     ((unsigned int)0x00000008)        /*!<Bit 1 */

#define  FMC_SDCR1_MWID                     ((unsigned int)0x00000030)        /*!<NR[1:0] bits (Number of row bits) */
#define  FMC_SDCR1_MWID_0                   ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_SDCR1_MWID_1                   ((unsigned int)0x00000020)        /*!<Bit 1 */

#define  FMC_SDCR1_NB                       ((unsigned int)0x00000040)        /*!<Number of internal bank */

#define  FMC_SDCR1_CAS                      ((unsigned int)0x00000180)        /*!<CAS[1:0] bits (CAS latency) */
#define  FMC_SDCR1_CAS_0                    ((unsigned int)0x00000080)        /*!<Bit 0 */
#define  FMC_SDCR1_CAS_1                    ((unsigned int)0x00000100)        /*!<Bit 1 */

#define  FMC_SDCR1_WP                       ((unsigned int)0x00000200)        /*!<Write protection */

#define  FMC_SDCR1_SDCLK                    ((unsigned int)0x00000C00)        /*!<SDRAM clock configuration */
#define  FMC_SDCR1_SDCLK_0                  ((unsigned int)0x00000400)        /*!<Bit 0 */
#define  FMC_SDCR1_SDCLK_1                  ((unsigned int)0x00000800)        /*!<Bit 1 */

#define  FMC_SDCR1_RBURST                   ((unsigned int)0x00001000)        /*!<Read burst */

#define  FMC_SDCR1_RPIPE                    ((unsigned int)0x00006000)        /*!<Write protection */
#define  FMC_SDCR1_RPIPE_0                  ((unsigned int)0x00002000)        /*!<Bit 0 */
#define  FMC_SDCR1_RPIPE_1                  ((unsigned int)0x00004000)        /*!<Bit 1 */

/******************  Bit definition for FMC_SDCR2 register  ******************/
#define  FMC_SDCR2_NC                       ((unsigned int)0x00000003)        /*!<NC[1:0] bits (Number of column bits) */
#define  FMC_SDCR2_NC_0                     ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_SDCR2_NC_1                     ((unsigned int)0x00000002)        /*!<Bit 1 */

#define  FMC_SDCR2_NR                       ((unsigned int)0x0000000C)        /*!<NR[1:0] bits (Number of row bits) */
#define  FMC_SDCR2_NR_0                     ((unsigned int)0x00000004)        /*!<Bit 0 */
#define  FMC_SDCR2_NR_1                     ((unsigned int)0x00000008)        /*!<Bit 1 */

#define  FMC_SDCR2_MWID                     ((unsigned int)0x00000030)        /*!<NR[1:0] bits (Number of row bits) */
#define  FMC_SDCR2_MWID_0                   ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_SDCR2_MWID_1                   ((unsigned int)0x00000020)        /*!<Bit 1 */

#define  FMC_SDCR2_NB                       ((unsigned int)0x00000040)        /*!<Number of internal bank */

#define  FMC_SDCR2_CAS                      ((unsigned int)0x00000180)        /*!<CAS[1:0] bits (CAS latency) */
#define  FMC_SDCR2_CAS_0                    ((unsigned int)0x00000080)        /*!<Bit 0 */
#define  FMC_SDCR2_CAS_1                    ((unsigned int)0x00000100)        /*!<Bit 1 */

#define  FMC_SDCR2_WP                       ((unsigned int)0x00000200)        /*!<Write protection */

#define  FMC_SDCR2_SDCLK                    ((unsigned int)0x00000C00)        /*!<SDCLK[1:0] (SDRAM clock configuration) */
#define  FMC_SDCR2_SDCLK_0                  ((unsigned int)0x00000400)        /*!<Bit 0 */
#define  FMC_SDCR2_SDCLK_1                  ((unsigned int)0x00000800)        /*!<Bit 1 */

#define  FMC_SDCR2_RBURST                   ((unsigned int)0x00001000)        /*!<Read burst */

#define  FMC_SDCR2_RPIPE                    ((unsigned int)0x00006000)        /*!<RPIPE[1:0](Read pipe) */
#define  FMC_SDCR2_RPIPE_0                  ((unsigned int)0x00002000)        /*!<Bit 0 */
#define  FMC_SDCR2_RPIPE_1                  ((unsigned int)0x00004000)        /*!<Bit 1 */

/******************  Bit definition for FMC_SDTR1 register  ******************/
#define  FMC_SDTR1_TMRD                     ((unsigned int)0x0000000F)        /*!<TMRD[3:0] bits (Load mode register to active) */
#define  FMC_SDTR1_TMRD_0                   ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_SDTR1_TMRD_1                   ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_SDTR1_TMRD_2                   ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_SDTR1_TMRD_3                   ((unsigned int)0x00000008)        /*!<Bit 3 */

#define  FMC_SDTR1_TXSR                     ((unsigned int)0x000000F0)        /*!<TXSR[3:0] bits (Exit self refresh) */
#define  FMC_SDTR1_TXSR_0                   ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_SDTR1_TXSR_1                   ((unsigned int)0x00000020)        /*!<Bit 1 */
#define  FMC_SDTR1_TXSR_2                   ((unsigned int)0x00000040)        /*!<Bit 2 */
#define  FMC_SDTR1_TXSR_3                   ((unsigned int)0x00000080)        /*!<Bit 3 */

#define  FMC_SDTR1_TRAS                     ((unsigned int)0x00000F00)        /*!<TRAS[3:0] bits (Self refresh time) */
#define  FMC_SDTR1_TRAS_0                   ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_SDTR1_TRAS_1                   ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_SDTR1_TRAS_2                   ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_SDTR1_TRAS_3                   ((unsigned int)0x00000800)        /*!<Bit 3 */

#define  FMC_SDTR1_TRC                      ((unsigned int)0x0000F000)        /*!<TRC[2:0] bits (Row cycle delay) */
#define  FMC_SDTR1_TRC_0                    ((unsigned int)0x00001000)        /*!<Bit 0 */
#define  FMC_SDTR1_TRC_1                    ((unsigned int)0x00002000)        /*!<Bit 1 */
#define  FMC_SDTR1_TRC_2                    ((unsigned int)0x00004000)        /*!<Bit 2 */

#define  FMC_SDTR1_TWR                      ((unsigned int)0x000F0000)        /*!<TRC[2:0] bits (Write recovery delay) */
#define  FMC_SDTR1_TWR_0                    ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_SDTR1_TWR_1                    ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_SDTR1_TWR_2                    ((unsigned int)0x00040000)        /*!<Bit 2 */

#define  FMC_SDTR1_TRP                      ((unsigned int)0x00F00000)        /*!<TRP[2:0] bits (Row precharge delay) */
#define  FMC_SDTR1_TRP_0                    ((unsigned int)0x00100000)        /*!<Bit 0 */
#define  FMC_SDTR1_TRP_1                    ((unsigned int)0x00200000)        /*!<Bit 1 */
#define  FMC_SDTR1_TRP_2                    ((unsigned int)0x00400000)        /*!<Bit 2 */

#define  FMC_SDTR1_TRCD                     ((unsigned int)0x0F000000)        /*!<TRP[2:0] bits (Row to column delay) */
#define  FMC_SDTR1_TRCD_0                   ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_SDTR1_TRCD_1                   ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_SDTR1_TRCD_2                   ((unsigned int)0x04000000)        /*!<Bit 2 */

/******************  Bit definition for FMC_SDTR2 register  ******************/
#define  FMC_SDTR2_TMRD                     ((unsigned int)0x0000000F)        /*!<TMRD[3:0] bits (Load mode register to active) */
#define  FMC_SDTR2_TMRD_0                   ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_SDTR2_TMRD_1                   ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_SDTR2_TMRD_2                   ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  FMC_SDTR2_TMRD_3                   ((unsigned int)0x00000008)        /*!<Bit 3 */

#define  FMC_SDTR2_TXSR                     ((unsigned int)0x000000F0)        /*!<TXSR[3:0] bits (Exit self refresh) */
#define  FMC_SDTR2_TXSR_0                   ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  FMC_SDTR2_TXSR_1                   ((unsigned int)0x00000020)        /*!<Bit 1 */
#define  FMC_SDTR2_TXSR_2                   ((unsigned int)0x00000040)        /*!<Bit 2 */
#define  FMC_SDTR2_TXSR_3                   ((unsigned int)0x00000080)        /*!<Bit 3 */

#define  FMC_SDTR2_TRAS                     ((unsigned int)0x00000F00)        /*!<TRAS[3:0] bits (Self refresh time) */
#define  FMC_SDTR2_TRAS_0                   ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  FMC_SDTR2_TRAS_1                   ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  FMC_SDTR2_TRAS_2                   ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  FMC_SDTR2_TRAS_3                   ((unsigned int)0x00000800)        /*!<Bit 3 */

#define  FMC_SDTR2_TRC                      ((unsigned int)0x0000F000)        /*!<TRC[2:0] bits (Row cycle delay) */
#define  FMC_SDTR2_TRC_0                    ((unsigned int)0x00001000)        /*!<Bit 0 */
#define  FMC_SDTR2_TRC_1                    ((unsigned int)0x00002000)        /*!<Bit 1 */
#define  FMC_SDTR2_TRC_2                    ((unsigned int)0x00004000)        /*!<Bit 2 */

#define  FMC_SDTR2_TWR                      ((unsigned int)0x000F0000)        /*!<TRC[2:0] bits (Write recovery delay) */
#define  FMC_SDTR2_TWR_0                    ((unsigned int)0x00010000)        /*!<Bit 0 */
#define  FMC_SDTR2_TWR_1                    ((unsigned int)0x00020000)        /*!<Bit 1 */
#define  FMC_SDTR2_TWR_2                    ((unsigned int)0x00040000)        /*!<Bit 2 */

#define  FMC_SDTR2_TRP                      ((unsigned int)0x00F00000)        /*!<TRP[2:0] bits (Row precharge delay) */
#define  FMC_SDTR2_TRP_0                    ((unsigned int)0x00100000)        /*!<Bit 0 */
#define  FMC_SDTR2_TRP_1                    ((unsigned int)0x00200000)        /*!<Bit 1 */
#define  FMC_SDTR2_TRP_2                    ((unsigned int)0x00400000)        /*!<Bit 2 */

#define  FMC_SDTR2_TRCD                     ((unsigned int)0x0F000000)        /*!<TRP[2:0] bits (Row to column delay) */
#define  FMC_SDTR2_TRCD_0                   ((unsigned int)0x01000000)        /*!<Bit 0 */
#define  FMC_SDTR2_TRCD_1                   ((unsigned int)0x02000000)        /*!<Bit 1 */
#define  FMC_SDTR2_TRCD_2                   ((unsigned int)0x04000000)        /*!<Bit 2 */

/******************  Bit definition for FMC_SDCMR register  ******************/
#define  FMC_SDCMR_MODE                     ((unsigned int)0x00000007)        /*!<MODE[2:0] bits (Command mode) */
#define  FMC_SDCMR_MODE_0                   ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  FMC_SDCMR_MODE_1                   ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  FMC_SDCMR_MODE_2                   ((unsigned int)0x00000003)        /*!<Bit 2 */

#define  FMC_SDCMR_CTB2                     ((unsigned int)0x00000008)        /*!<Command target 2 */

#define  FMC_SDCMR_CTB1                     ((unsigned int)0x00000010)        /*!<Command target 1 */

#define  FMC_SDCMR_NRFS                     ((unsigned int)0x000001E0)        /*!<NRFS[3:0] bits (Number of auto-refresh) */
#define  FMC_SDCMR_NRFS_0                   ((unsigned int)0x00000020)        /*!<Bit 0 */
#define  FMC_SDCMR_NRFS_1                   ((unsigned int)0x00000040)        /*!<Bit 1 */
#define  FMC_SDCMR_NRFS_2                   ((unsigned int)0x00000080)        /*!<Bit 2 */
#define  FMC_SDCMR_NRFS_3                   ((unsigned int)0x00000100)        /*!<Bit 3 */

#define  FMC_SDCMR_MRD                      ((unsigned int)0x003FFE00)        /*!<MRD[12:0] bits (Mode register definition) */

/******************  Bit definition for FMC_SDRTR register  ******************/
#define  FMC_SDRTR_CRE                      ((unsigned int)0x00000001)        /*!<Clear refresh error flag */

#define  FMC_SDRTR_COUNT                    ((unsigned int)0x00003FFE)        /*!<COUNT[12:0] bits (Refresh timer count) */

#define  FMC_SDRTR_REIE                     ((unsigned int)0x00004000)        /*!<RES interupt enable */

/******************  Bit definition for FMC_SDSR register  ******************/
#define  FMC_SDSR_RE                        ((unsigned int)0x00000001)        /*!<Refresh error flag */

#define  FMC_SDSR_MODES1                    ((unsigned int)0x00000006)        /*!<MODES1[1:0]bits (Status mode for bank 1) */
#define  FMC_SDSR_MODES1_0                  ((unsigned int)0x00000002)        /*!<Bit 0 */
#define  FMC_SDSR_MODES1_1                  ((unsigned int)0x00000004)        /*!<Bit 1 */

#define  FMC_SDSR_MODES2                    ((unsigned int)0x00000018)        /*!<MODES2[1:0]bits (Status mode for bank 2) */
#define  FMC_SDSR_MODES2_0                  ((unsigned int)0x00000008)        /*!<Bit 0 */
#define  FMC_SDSR_MODES2_1                  ((unsigned int)0x00000010)        /*!<Bit 1 */

#define  FMC_SDSR_BUSY                      ((unsigned int)0x00000020)        /*!<Busy status */

/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O                             */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODER0                    ((unsigned int)0x00000003)
#define GPIO_MODER_MODER0_0                  ((unsigned int)0x00000001)
#define GPIO_MODER_MODER0_1                  ((unsigned int)0x00000002)

#define GPIO_MODER_MODER1                    ((unsigned int)0x0000000C)
#define GPIO_MODER_MODER1_0                  ((unsigned int)0x00000004)
#define GPIO_MODER_MODER1_1                  ((unsigned int)0x00000008)

#define GPIO_MODER_MODER2                    ((unsigned int)0x00000030)
#define GPIO_MODER_MODER2_0                  ((unsigned int)0x00000010)
#define GPIO_MODER_MODER2_1                  ((unsigned int)0x00000020)

#define GPIO_MODER_MODER3                    ((unsigned int)0x000000C0)
#define GPIO_MODER_MODER3_0                  ((unsigned int)0x00000040)
#define GPIO_MODER_MODER3_1                  ((unsigned int)0x00000080)

#define GPIO_MODER_MODER4                    ((unsigned int)0x00000300)
#define GPIO_MODER_MODER4_0                  ((unsigned int)0x00000100)
#define GPIO_MODER_MODER4_1                  ((unsigned int)0x00000200)

#define GPIO_MODER_MODER5                    ((unsigned int)0x00000C00)
#define GPIO_MODER_MODER5_0                  ((unsigned int)0x00000400)
#define GPIO_MODER_MODER5_1                  ((unsigned int)0x00000800)

#define GPIO_MODER_MODER6                    ((unsigned int)0x00003000)
#define GPIO_MODER_MODER6_0                  ((unsigned int)0x00001000)
#define GPIO_MODER_MODER6_1                  ((unsigned int)0x00002000)

#define GPIO_MODER_MODER7                    ((unsigned int)0x0000C000)
#define GPIO_MODER_MODER7_0                  ((unsigned int)0x00004000)
#define GPIO_MODER_MODER7_1                  ((unsigned int)0x00008000)

#define GPIO_MODER_MODER8                    ((unsigned int)0x00030000)
#define GPIO_MODER_MODER8_0                  ((unsigned int)0x00010000)
#define GPIO_MODER_MODER8_1                  ((unsigned int)0x00020000)

#define GPIO_MODER_MODER9                    ((unsigned int)0x000C0000)
#define GPIO_MODER_MODER9_0                  ((unsigned int)0x00040000)
#define GPIO_MODER_MODER9_1                  ((unsigned int)0x00080000)

#define GPIO_MODER_MODER10                   ((unsigned int)0x00300000)
#define GPIO_MODER_MODER10_0                 ((unsigned int)0x00100000)
#define GPIO_MODER_MODER10_1                 ((unsigned int)0x00200000)

#define GPIO_MODER_MODER11                   ((unsigned int)0x00C00000)
#define GPIO_MODER_MODER11_0                 ((unsigned int)0x00400000)
#define GPIO_MODER_MODER11_1                 ((unsigned int)0x00800000)

#define GPIO_MODER_MODER12                   ((unsigned int)0x03000000)
#define GPIO_MODER_MODER12_0                 ((unsigned int)0x01000000)
#define GPIO_MODER_MODER12_1                 ((unsigned int)0x02000000)

#define GPIO_MODER_MODER13                   ((unsigned int)0x0C000000)
#define GPIO_MODER_MODER13_0                 ((unsigned int)0x04000000)
#define GPIO_MODER_MODER13_1                 ((unsigned int)0x08000000)

#define GPIO_MODER_MODER14                   ((unsigned int)0x30000000)
#define GPIO_MODER_MODER14_0                 ((unsigned int)0x10000000)
#define GPIO_MODER_MODER14_1                 ((unsigned int)0x20000000)

#define GPIO_MODER_MODER15                   ((unsigned int)0xC0000000)
#define GPIO_MODER_MODER15_0                 ((unsigned int)0x40000000)
#define GPIO_MODER_MODER15_1                 ((unsigned int)0x80000000)

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT_0                     ((unsigned int)0x00000001)
#define GPIO_OTYPER_OT_1                     ((unsigned int)0x00000002)
#define GPIO_OTYPER_OT_2                     ((unsigned int)0x00000004)
#define GPIO_OTYPER_OT_3                     ((unsigned int)0x00000008)
#define GPIO_OTYPER_OT_4                     ((unsigned int)0x00000010)
#define GPIO_OTYPER_OT_5                     ((unsigned int)0x00000020)
#define GPIO_OTYPER_OT_6                     ((unsigned int)0x00000040)
#define GPIO_OTYPER_OT_7                     ((unsigned int)0x00000080)
#define GPIO_OTYPER_OT_8                     ((unsigned int)0x00000100)
#define GPIO_OTYPER_OT_9                     ((unsigned int)0x00000200)
#define GPIO_OTYPER_OT_10                    ((unsigned int)0x00000400)
#define GPIO_OTYPER_OT_11                    ((unsigned int)0x00000800)
#define GPIO_OTYPER_OT_12                    ((unsigned int)0x00001000)
#define GPIO_OTYPER_OT_13                    ((unsigned int)0x00002000)
#define GPIO_OTYPER_OT_14                    ((unsigned int)0x00004000)
#define GPIO_OTYPER_OT_15                    ((unsigned int)0x00008000)

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define GPIO_OSPEEDER_OSPEEDR0               ((unsigned int)0x00000003)
#define GPIO_OSPEEDER_OSPEEDR0_0             ((unsigned int)0x00000001)
#define GPIO_OSPEEDER_OSPEEDR0_1             ((unsigned int)0x00000002)

#define GPIO_OSPEEDER_OSPEEDR1               ((unsigned int)0x0000000C)
#define GPIO_OSPEEDER_OSPEEDR1_0             ((unsigned int)0x00000004)
#define GPIO_OSPEEDER_OSPEEDR1_1             ((unsigned int)0x00000008)

#define GPIO_OSPEEDER_OSPEEDR2               ((unsigned int)0x00000030)
#define GPIO_OSPEEDER_OSPEEDR2_0             ((unsigned int)0x00000010)
#define GPIO_OSPEEDER_OSPEEDR2_1             ((unsigned int)0x00000020)

#define GPIO_OSPEEDER_OSPEEDR3               ((unsigned int)0x000000C0)
#define GPIO_OSPEEDER_OSPEEDR3_0             ((unsigned int)0x00000040)
#define GPIO_OSPEEDER_OSPEEDR3_1             ((unsigned int)0x00000080)

#define GPIO_OSPEEDER_OSPEEDR4               ((unsigned int)0x00000300)
#define GPIO_OSPEEDER_OSPEEDR4_0             ((unsigned int)0x00000100)
#define GPIO_OSPEEDER_OSPEEDR4_1             ((unsigned int)0x00000200)

#define GPIO_OSPEEDER_OSPEEDR5               ((unsigned int)0x00000C00)
#define GPIO_OSPEEDER_OSPEEDR5_0             ((unsigned int)0x00000400)
#define GPIO_OSPEEDER_OSPEEDR5_1             ((unsigned int)0x00000800)

#define GPIO_OSPEEDER_OSPEEDR6               ((unsigned int)0x00003000)
#define GPIO_OSPEEDER_OSPEEDR6_0             ((unsigned int)0x00001000)
#define GPIO_OSPEEDER_OSPEEDR6_1             ((unsigned int)0x00002000)

#define GPIO_OSPEEDER_OSPEEDR7               ((unsigned int)0x0000C000)
#define GPIO_OSPEEDER_OSPEEDR7_0             ((unsigned int)0x00004000)
#define GPIO_OSPEEDER_OSPEEDR7_1             ((unsigned int)0x00008000)

#define GPIO_OSPEEDER_OSPEEDR8               ((unsigned int)0x00030000)
#define GPIO_OSPEEDER_OSPEEDR8_0             ((unsigned int)0x00010000)
#define GPIO_OSPEEDER_OSPEEDR8_1             ((unsigned int)0x00020000)

#define GPIO_OSPEEDER_OSPEEDR9               ((unsigned int)0x000C0000)
#define GPIO_OSPEEDER_OSPEEDR9_0             ((unsigned int)0x00040000)
#define GPIO_OSPEEDER_OSPEEDR9_1             ((unsigned int)0x00080000)

#define GPIO_OSPEEDER_OSPEEDR10              ((unsigned int)0x00300000)
#define GPIO_OSPEEDER_OSPEEDR10_0            ((unsigned int)0x00100000)
#define GPIO_OSPEEDER_OSPEEDR10_1            ((unsigned int)0x00200000)

#define GPIO_OSPEEDER_OSPEEDR11              ((unsigned int)0x00C00000)
#define GPIO_OSPEEDER_OSPEEDR11_0            ((unsigned int)0x00400000)
#define GPIO_OSPEEDER_OSPEEDR11_1            ((unsigned int)0x00800000)

#define GPIO_OSPEEDER_OSPEEDR12              ((unsigned int)0x03000000)
#define GPIO_OSPEEDER_OSPEEDR12_0            ((unsigned int)0x01000000)
#define GPIO_OSPEEDER_OSPEEDR12_1            ((unsigned int)0x02000000)

#define GPIO_OSPEEDER_OSPEEDR13              ((unsigned int)0x0C000000)
#define GPIO_OSPEEDER_OSPEEDR13_0            ((unsigned int)0x04000000)
#define GPIO_OSPEEDER_OSPEEDR13_1            ((unsigned int)0x08000000)

#define GPIO_OSPEEDER_OSPEEDR14              ((unsigned int)0x30000000)
#define GPIO_OSPEEDER_OSPEEDR14_0            ((unsigned int)0x10000000)
#define GPIO_OSPEEDER_OSPEEDR14_1            ((unsigned int)0x20000000)

#define GPIO_OSPEEDER_OSPEEDR15              ((unsigned int)0xC0000000)
#define GPIO_OSPEEDER_OSPEEDR15_0            ((unsigned int)0x40000000)
#define GPIO_OSPEEDER_OSPEEDR15_1            ((unsigned int)0x80000000)

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPDR0                    ((unsigned int)0x00000003)
#define GPIO_PUPDR_PUPDR0_0                  ((unsigned int)0x00000001)
#define GPIO_PUPDR_PUPDR0_1                  ((unsigned int)0x00000002)

#define GPIO_PUPDR_PUPDR1                    ((unsigned int)0x0000000C)
#define GPIO_PUPDR_PUPDR1_0                  ((unsigned int)0x00000004)
#define GPIO_PUPDR_PUPDR1_1                  ((unsigned int)0x00000008)

#define GPIO_PUPDR_PUPDR2                    ((unsigned int)0x00000030)
#define GPIO_PUPDR_PUPDR2_0                  ((unsigned int)0x00000010)
#define GPIO_PUPDR_PUPDR2_1                  ((unsigned int)0x00000020)

#define GPIO_PUPDR_PUPDR3                    ((unsigned int)0x000000C0)
#define GPIO_PUPDR_PUPDR3_0                  ((unsigned int)0x00000040)
#define GPIO_PUPDR_PUPDR3_1                  ((unsigned int)0x00000080)

#define GPIO_PUPDR_PUPDR4                    ((unsigned int)0x00000300)
#define GPIO_PUPDR_PUPDR4_0                  ((unsigned int)0x00000100)
#define GPIO_PUPDR_PUPDR4_1                  ((unsigned int)0x00000200)

#define GPIO_PUPDR_PUPDR5                    ((unsigned int)0x00000C00)
#define GPIO_PUPDR_PUPDR5_0                  ((unsigned int)0x00000400)
#define GPIO_PUPDR_PUPDR5_1                  ((unsigned int)0x00000800)

#define GPIO_PUPDR_PUPDR6                    ((unsigned int)0x00003000)
#define GPIO_PUPDR_PUPDR6_0                  ((unsigned int)0x00001000)
#define GPIO_PUPDR_PUPDR6_1                  ((unsigned int)0x00002000)

#define GPIO_PUPDR_PUPDR7                    ((unsigned int)0x0000C000)
#define GPIO_PUPDR_PUPDR7_0                  ((unsigned int)0x00004000)
#define GPIO_PUPDR_PUPDR7_1                  ((unsigned int)0x00008000)

#define GPIO_PUPDR_PUPDR8                    ((unsigned int)0x00030000)
#define GPIO_PUPDR_PUPDR8_0                  ((unsigned int)0x00010000)
#define GPIO_PUPDR_PUPDR8_1                  ((unsigned int)0x00020000)

#define GPIO_PUPDR_PUPDR9                    ((unsigned int)0x000C0000)
#define GPIO_PUPDR_PUPDR9_0                  ((unsigned int)0x00040000)
#define GPIO_PUPDR_PUPDR9_1                  ((unsigned int)0x00080000)

#define GPIO_PUPDR_PUPDR10                   ((unsigned int)0x00300000)
#define GPIO_PUPDR_PUPDR10_0                 ((unsigned int)0x00100000)
#define GPIO_PUPDR_PUPDR10_1                 ((unsigned int)0x00200000)

#define GPIO_PUPDR_PUPDR11                   ((unsigned int)0x00C00000)
#define GPIO_PUPDR_PUPDR11_0                 ((unsigned int)0x00400000)
#define GPIO_PUPDR_PUPDR11_1                 ((unsigned int)0x00800000)

#define GPIO_PUPDR_PUPDR12                   ((unsigned int)0x03000000)
#define GPIO_PUPDR_PUPDR12_0                 ((unsigned int)0x01000000)
#define GPIO_PUPDR_PUPDR12_1                 ((unsigned int)0x02000000)

#define GPIO_PUPDR_PUPDR13                   ((unsigned int)0x0C000000)
#define GPIO_PUPDR_PUPDR13_0                 ((unsigned int)0x04000000)
#define GPIO_PUPDR_PUPDR13_1                 ((unsigned int)0x08000000)

#define GPIO_PUPDR_PUPDR14                   ((unsigned int)0x30000000)
#define GPIO_PUPDR_PUPDR14_0                 ((unsigned int)0x10000000)
#define GPIO_PUPDR_PUPDR14_1                 ((unsigned int)0x20000000)

#define GPIO_PUPDR_PUPDR15                   ((unsigned int)0xC0000000)
#define GPIO_PUPDR_PUPDR15_0                 ((unsigned int)0x40000000)
#define GPIO_PUPDR_PUPDR15_1                 ((unsigned int)0x80000000)

/******************  Bits definition for GPIO_IDR register  *******************/
#define GPIO_IDR_IDR_0                       ((unsigned int)0x00000001)
#define GPIO_IDR_IDR_1                       ((unsigned int)0x00000002)
#define GPIO_IDR_IDR_2                       ((unsigned int)0x00000004)
#define GPIO_IDR_IDR_3                       ((unsigned int)0x00000008)
#define GPIO_IDR_IDR_4                       ((unsigned int)0x00000010)
#define GPIO_IDR_IDR_5                       ((unsigned int)0x00000020)
#define GPIO_IDR_IDR_6                       ((unsigned int)0x00000040)
#define GPIO_IDR_IDR_7                       ((unsigned int)0x00000080)
#define GPIO_IDR_IDR_8                       ((unsigned int)0x00000100)
#define GPIO_IDR_IDR_9                       ((unsigned int)0x00000200)
#define GPIO_IDR_IDR_10                      ((unsigned int)0x00000400)
#define GPIO_IDR_IDR_11                      ((unsigned int)0x00000800)
#define GPIO_IDR_IDR_12                      ((unsigned int)0x00001000)
#define GPIO_IDR_IDR_13                      ((unsigned int)0x00002000)
#define GPIO_IDR_IDR_14                      ((unsigned int)0x00004000)
#define GPIO_IDR_IDR_15                      ((unsigned int)0x00008000)
/* Old GPIO_IDR register bits definition, maintained for legacy purpose */
#define GPIO_OTYPER_IDR_0                    GPIO_IDR_IDR_0
#define GPIO_OTYPER_IDR_1                    GPIO_IDR_IDR_1
#define GPIO_OTYPER_IDR_2                    GPIO_IDR_IDR_2
#define GPIO_OTYPER_IDR_3                    GPIO_IDR_IDR_3
#define GPIO_OTYPER_IDR_4                    GPIO_IDR_IDR_4
#define GPIO_OTYPER_IDR_5                    GPIO_IDR_IDR_5
#define GPIO_OTYPER_IDR_6                    GPIO_IDR_IDR_6
#define GPIO_OTYPER_IDR_7                    GPIO_IDR_IDR_7
#define GPIO_OTYPER_IDR_8                    GPIO_IDR_IDR_8
#define GPIO_OTYPER_IDR_9                    GPIO_IDR_IDR_9
#define GPIO_OTYPER_IDR_10                   GPIO_IDR_IDR_10
#define GPIO_OTYPER_IDR_11                   GPIO_IDR_IDR_11
#define GPIO_OTYPER_IDR_12                   GPIO_IDR_IDR_12
#define GPIO_OTYPER_IDR_13                   GPIO_IDR_IDR_13
#define GPIO_OTYPER_IDR_14                   GPIO_IDR_IDR_14
#define GPIO_OTYPER_IDR_15                   GPIO_IDR_IDR_15

/******************  Bits definition for GPIO_ODR register  *******************/
#define GPIO_ODR_ODR_0                       ((unsigned int)0x00000001)
#define GPIO_ODR_ODR_1                       ((unsigned int)0x00000002)
#define GPIO_ODR_ODR_2                       ((unsigned int)0x00000004)
#define GPIO_ODR_ODR_3                       ((unsigned int)0x00000008)
#define GPIO_ODR_ODR_4                       ((unsigned int)0x00000010)
#define GPIO_ODR_ODR_5                       ((unsigned int)0x00000020)
#define GPIO_ODR_ODR_6                       ((unsigned int)0x00000040)
#define GPIO_ODR_ODR_7                       ((unsigned int)0x00000080)
#define GPIO_ODR_ODR_8                       ((unsigned int)0x00000100)
#define GPIO_ODR_ODR_9                       ((unsigned int)0x00000200)
#define GPIO_ODR_ODR_10                      ((unsigned int)0x00000400)
#define GPIO_ODR_ODR_11                      ((unsigned int)0x00000800)
#define GPIO_ODR_ODR_12                      ((unsigned int)0x00001000)
#define GPIO_ODR_ODR_13                      ((unsigned int)0x00002000)
#define GPIO_ODR_ODR_14                      ((unsigned int)0x00004000)
#define GPIO_ODR_ODR_15                      ((unsigned int)0x00008000)
/* Old GPIO_ODR register bits definition, maintained for legacy purpose */
#define GPIO_OTYPER_ODR_0                    GPIO_ODR_ODR_0
#define GPIO_OTYPER_ODR_1                    GPIO_ODR_ODR_1
#define GPIO_OTYPER_ODR_2                    GPIO_ODR_ODR_2
#define GPIO_OTYPER_ODR_3                    GPIO_ODR_ODR_3
#define GPIO_OTYPER_ODR_4                    GPIO_ODR_ODR_4
#define GPIO_OTYPER_ODR_5                    GPIO_ODR_ODR_5
#define GPIO_OTYPER_ODR_6                    GPIO_ODR_ODR_6
#define GPIO_OTYPER_ODR_7                    GPIO_ODR_ODR_7
#define GPIO_OTYPER_ODR_8                    GPIO_ODR_ODR_8
#define GPIO_OTYPER_ODR_9                    GPIO_ODR_ODR_9
#define GPIO_OTYPER_ODR_10                   GPIO_ODR_ODR_10
#define GPIO_OTYPER_ODR_11                   GPIO_ODR_ODR_11
#define GPIO_OTYPER_ODR_12                   GPIO_ODR_ODR_12
#define GPIO_OTYPER_ODR_13                   GPIO_ODR_ODR_13
#define GPIO_OTYPER_ODR_14                   GPIO_ODR_ODR_14
#define GPIO_OTYPER_ODR_15                   GPIO_ODR_ODR_15

/******************  Bits definition for GPIO_BSRR register  ******************/
#define GPIO_BSRR_BS_0                       ((unsigned int)0x00000001)
#define GPIO_BSRR_BS_1                       ((unsigned int)0x00000002)
#define GPIO_BSRR_BS_2                       ((unsigned int)0x00000004)
#define GPIO_BSRR_BS_3                       ((unsigned int)0x00000008)
#define GPIO_BSRR_BS_4                       ((unsigned int)0x00000010)
#define GPIO_BSRR_BS_5                       ((unsigned int)0x00000020)
#define GPIO_BSRR_BS_6                       ((unsigned int)0x00000040)
#define GPIO_BSRR_BS_7                       ((unsigned int)0x00000080)
#define GPIO_BSRR_BS_8                       ((unsigned int)0x00000100)
#define GPIO_BSRR_BS_9                       ((unsigned int)0x00000200)
#define GPIO_BSRR_BS_10                      ((unsigned int)0x00000400)
#define GPIO_BSRR_BS_11                      ((unsigned int)0x00000800)
#define GPIO_BSRR_BS_12                      ((unsigned int)0x00001000)
#define GPIO_BSRR_BS_13                      ((unsigned int)0x00002000)
#define GPIO_BSRR_BS_14                      ((unsigned int)0x00004000)
#define GPIO_BSRR_BS_15                      ((unsigned int)0x00008000)
#define GPIO_BSRR_BR_0                       ((unsigned int)0x00010000)
#define GPIO_BSRR_BR_1                       ((unsigned int)0x00020000)
#define GPIO_BSRR_BR_2                       ((unsigned int)0x00040000)
#define GPIO_BSRR_BR_3                       ((unsigned int)0x00080000)
#define GPIO_BSRR_BR_4                       ((unsigned int)0x00100000)
#define GPIO_BSRR_BR_5                       ((unsigned int)0x00200000)
#define GPIO_BSRR_BR_6                       ((unsigned int)0x00400000)
#define GPIO_BSRR_BR_7                       ((unsigned int)0x00800000)
#define GPIO_BSRR_BR_8                       ((unsigned int)0x01000000)
#define GPIO_BSRR_BR_9                       ((unsigned int)0x02000000)
#define GPIO_BSRR_BR_10                      ((unsigned int)0x04000000)
#define GPIO_BSRR_BR_11                      ((unsigned int)0x08000000)
#define GPIO_BSRR_BR_12                      ((unsigned int)0x10000000)
#define GPIO_BSRR_BR_13                      ((unsigned int)0x20000000)
#define GPIO_BSRR_BR_14                      ((unsigned int)0x40000000)
#define GPIO_BSRR_BR_15                      ((unsigned int)0x80000000)

/******************************************************************************/
/*                                                                            */
/*                                    HASH                                    */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for HASH_CR register  ********************/
#define HASH_CR_INIT                         ((unsigned int)0x00000004)
#define HASH_CR_DMAE                         ((unsigned int)0x00000008)
#define HASH_CR_DATATYPE                     ((unsigned int)0x00000030)
#define HASH_CR_DATATYPE_0                   ((unsigned int)0x00000010)
#define HASH_CR_DATATYPE_1                   ((unsigned int)0x00000020)
#define HASH_CR_MODE                         ((unsigned int)0x00000040)
#define HASH_CR_ALGO                         ((unsigned int)0x00040080)
#define HASH_CR_ALGO_0                       ((unsigned int)0x00000080)
#define HASH_CR_ALGO_1                       ((unsigned int)0x00040000)
#define HASH_CR_NBW                          ((unsigned int)0x00000F00)
#define HASH_CR_NBW_0                        ((unsigned int)0x00000100)
#define HASH_CR_NBW_1                        ((unsigned int)0x00000200)
#define HASH_CR_NBW_2                        ((unsigned int)0x00000400)
#define HASH_CR_NBW_3                        ((unsigned int)0x00000800)
#define HASH_CR_DINNE                        ((unsigned int)0x00001000)
#define HASH_CR_MDMAT                        ((unsigned int)0x00002000)
#define HASH_CR_LKEY                         ((unsigned int)0x00010000)

/******************  Bits definition for HASH_STR register  *******************/
#define HASH_STR_NBW                         ((unsigned int)0x0000001F)
#define HASH_STR_NBW_0                       ((unsigned int)0x00000001)
#define HASH_STR_NBW_1                       ((unsigned int)0x00000002)
#define HASH_STR_NBW_2                       ((unsigned int)0x00000004)
#define HASH_STR_NBW_3                       ((unsigned int)0x00000008)
#define HASH_STR_NBW_4                       ((unsigned int)0x00000010)
#define HASH_STR_DCAL                        ((unsigned int)0x00000100)

/******************  Bits definition for HASH_IMR register  *******************/
#define HASH_IMR_DINIM                       ((unsigned int)0x00000001)
#define HASH_IMR_DCIM                        ((unsigned int)0x00000002)

/******************  Bits definition for HASH_SR register  ********************/
#define HASH_SR_DINIS                        ((unsigned int)0x00000001)
#define HASH_SR_DCIS                         ((unsigned int)0x00000002)
#define HASH_SR_DMAS                         ((unsigned int)0x00000004)
#define HASH_SR_BUSY                         ((unsigned int)0x00000008)

/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface                    */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CR1 register  ********************/
#define  I2C_CR1_PE                          ((unsigned short)0x0001)            /*!<Peripheral Enable                             */
#define  I2C_CR1_SMBUS                       ((unsigned short)0x0002)            /*!<SMBus Mode                                    */
#define  I2C_CR1_SMBTYPE                     ((unsigned short)0x0008)            /*!<SMBus Type                                    */
#define  I2C_CR1_ENARP                       ((unsigned short)0x0010)            /*!<ARP Enable                                    */
#define  I2C_CR1_ENPEC                       ((unsigned short)0x0020)            /*!<PEC Enable                                    */
#define  I2C_CR1_ENGC                        ((unsigned short)0x0040)            /*!<General Call Enable                           */
#define  I2C_CR1_NOSTRETCH                   ((unsigned short)0x0080)            /*!<Clock Stretching Disable (Slave mode)         */
#define  I2C_CR1_START                       ((unsigned short)0x0100)            /*!<Start Generation                              */
#define  I2C_CR1_STOP                        ((unsigned short)0x0200)            /*!<Stop Generation                               */
#define  I2C_CR1_ACK                         ((unsigned short)0x0400)            /*!<Acknowledge Enable                            */
#define  I2C_CR1_POS                         ((unsigned short)0x0800)            /*!<Acknowledge/PEC Position (for data reception) */
#define  I2C_CR1_PEC                         ((unsigned short)0x1000)            /*!<Packet Error Checking                         */
#define  I2C_CR1_ALERT                       ((unsigned short)0x2000)            /*!<SMBus Alert                                   */
#define  I2C_CR1_SWRST                       ((unsigned short)0x8000)            /*!<Software Reset                                */

/*******************  Bit definition for I2C_CR2 register  ********************/
#define  I2C_CR2_FREQ                        ((unsigned short)0x003F)            /*!<FREQ[5:0] bits (Peripheral Clock Frequency)   */
#define  I2C_CR2_FREQ_0                      ((unsigned short)0x0001)            /*!<Bit 0 */
#define  I2C_CR2_FREQ_1                      ((unsigned short)0x0002)            /*!<Bit 1 */
#define  I2C_CR2_FREQ_2                      ((unsigned short)0x0004)            /*!<Bit 2 */
#define  I2C_CR2_FREQ_3                      ((unsigned short)0x0008)            /*!<Bit 3 */
#define  I2C_CR2_FREQ_4                      ((unsigned short)0x0010)            /*!<Bit 4 */
#define  I2C_CR2_FREQ_5                      ((unsigned short)0x0020)            /*!<Bit 5 */

#define  I2C_CR2_ITERREN                     ((unsigned short)0x0100)            /*!<Error Interrupt Enable  */
#define  I2C_CR2_ITEVTEN                     ((unsigned short)0x0200)            /*!<Event Interrupt Enable  */
#define  I2C_CR2_ITBUFEN                     ((unsigned short)0x0400)            /*!<Buffer Interrupt Enable */
#define  I2C_CR2_DMAEN                       ((unsigned short)0x0800)            /*!<DMA Requests Enable     */
#define  I2C_CR2_LAST                        ((unsigned short)0x1000)            /*!<DMA Last Transfer       */

/*******************  Bit definition for I2C_OAR1 register  *******************/
#define  I2C_OAR1_ADD1_7                     ((unsigned short)0x00FE)            /*!<Interface Address */
#define  I2C_OAR1_ADD8_9                     ((unsigned short)0x0300)            /*!<Interface Address */

#define  I2C_OAR1_ADD0                       ((unsigned short)0x0001)            /*!<Bit 0 */
#define  I2C_OAR1_ADD1                       ((unsigned short)0x0002)            /*!<Bit 1 */
#define  I2C_OAR1_ADD2                       ((unsigned short)0x0004)            /*!<Bit 2 */
#define  I2C_OAR1_ADD3                       ((unsigned short)0x0008)            /*!<Bit 3 */
#define  I2C_OAR1_ADD4                       ((unsigned short)0x0010)            /*!<Bit 4 */
#define  I2C_OAR1_ADD5                       ((unsigned short)0x0020)            /*!<Bit 5 */
#define  I2C_OAR1_ADD6                       ((unsigned short)0x0040)            /*!<Bit 6 */
#define  I2C_OAR1_ADD7                       ((unsigned short)0x0080)            /*!<Bit 7 */
#define  I2C_OAR1_ADD8                       ((unsigned short)0x0100)            /*!<Bit 8 */
#define  I2C_OAR1_ADD9                       ((unsigned short)0x0200)            /*!<Bit 9 */

#define  I2C_OAR1_ADDMODE                    ((unsigned short)0x8000)            /*!<Addressing Mode (Slave mode) */

/*******************  Bit definition for I2C_OAR2 register  *******************/
#define  I2C_OAR2_ENDUAL                     ((unsigned char)0x01)               /*!<Dual addressing mode enable */
#define  I2C_OAR2_ADD2                       ((unsigned char)0xFE)               /*!<Interface address           */

/********************  Bit definition for I2C_DR register  ********************/
#define  I2C_DR_DR                           ((unsigned char)0xFF)               /*!<8-bit Data Register         */

/*******************  Bit definition for I2C_SR1 register  ********************/
#define  I2C_SR1_SB                          ((unsigned short)0x0001)            /*!<Start Bit (Master mode)                         */
#define  I2C_SR1_ADDR                        ((unsigned short)0x0002)            /*!<Address sent (master mode)/matched (slave mode) */
#define  I2C_SR1_BTF                         ((unsigned short)0x0004)            /*!<Byte Transfer Finished                          */
#define  I2C_SR1_ADD10                       ((unsigned short)0x0008)            /*!<10-bit header sent (Master mode)                */
#define  I2C_SR1_STOPF                       ((unsigned short)0x0010)            /*!<Stop detection (Slave mode)                     */
#define  I2C_SR1_RXNE                        ((unsigned short)0x0040)            /*!<Data Register not Empty (receivers)             */
#define  I2C_SR1_TXE                         ((unsigned short)0x0080)            /*!<Data Register Empty (transmitters)              */
#define  I2C_SR1_BERR                        ((unsigned short)0x0100)            /*!<Bus Error                                       */
#define  I2C_SR1_ARLO                        ((unsigned short)0x0200)            /*!<Arbitration Lost (master mode)                  */
#define  I2C_SR1_AF                          ((unsigned short)0x0400)            /*!<Acknowledge Failure                             */
#define  I2C_SR1_OVR                         ((unsigned short)0x0800)            /*!<Overrun/Underrun                                */
#define  I2C_SR1_PECERR                      ((unsigned short)0x1000)            /*!<PEC Error in reception                          */
#define  I2C_SR1_TIMEOUT                     ((unsigned short)0x4000)            /*!<Timeout or Tlow Error                           */
#define  I2C_SR1_SMBALERT                    ((unsigned short)0x8000)            /*!<SMBus Alert                                     */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define  I2C_SR2_MSL                         ((unsigned short)0x0001)            /*!<Master/Slave                              */
#define  I2C_SR2_BUSY                        ((unsigned short)0x0002)            /*!<Bus Busy                                  */
#define  I2C_SR2_TRA                         ((unsigned short)0x0004)            /*!<Transmitter/Receiver                      */
#define  I2C_SR2_GENCALL                     ((unsigned short)0x0010)            /*!<General Call Address (Slave mode)         */
#define  I2C_SR2_SMBDEFAULT                  ((unsigned short)0x0020)            /*!<SMBus Device Default Address (Slave mode) */
#define  I2C_SR2_SMBHOST                     ((unsigned short)0x0040)            /*!<SMBus Host Header (Slave mode)            */
#define  I2C_SR2_DUALF                       ((unsigned short)0x0080)            /*!<Dual Flag (Slave mode)                    */
#define  I2C_SR2_PEC                         ((unsigned short)0xFF00)            /*!<Packet Error Checking Register            */

/*******************  Bit definition for I2C_CCR register  ********************/
#define  I2C_CCR_CCR                         ((unsigned short)0x0FFF)            /*!<Clock Control Register in Fast/Standard mode (Master mode) */
#define  I2C_CCR_DUTY                        ((unsigned short)0x4000)            /*!<Fast Mode Duty Cycle                                       */
#define  I2C_CCR_FS                          ((unsigned short)0x8000)            /*!<I2C Master Mode Selection                                  */

/******************  Bit definition for I2C_TRISE register  *******************/
#define  I2C_TRISE_TRISE                     ((unsigned char)0x3F)               /*!<Maximum Rise Time in Fast/Standard mode (Master mode) */

/******************  Bit definition for I2C_FLTR register  *******************/
#define  I2C_FLTR_DNF                     ((unsigned char)0x0F)                  /*!<Digital Noise Filter    */
#define  I2C_FLTR_ANOFF                   ((unsigned char)0x10)                  /*!<Analog Noise Filter OFF */

/******************************************************************************/
/*                                                                            */
/*              Fast-mode Plus Inter-integrated circuit (FMPI2C)              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CR1 register  *******************/
#define  FMPI2C_CR1_PE                          ((unsigned int)0x00000001)        /*!< Peripheral enable                   */
#define  FMPI2C_CR1_TXIE                        ((unsigned int)0x00000002)        /*!< TX interrupt enable                 */
#define  FMPI2C_CR1_RXIE                        ((unsigned int)0x00000004)        /*!< RX interrupt enable                 */
#define  FMPI2C_CR1_ADDRIE                      ((unsigned int)0x00000008)        /*!< Address match interrupt enable      */
#define  FMPI2C_CR1_NACKIE                      ((unsigned int)0x00000010)        /*!< NACK received interrupt enable      */
#define  FMPI2C_CR1_STOPIE                      ((unsigned int)0x00000020)        /*!< STOP detection interrupt enable     */
#define  FMPI2C_CR1_TCIE                        ((unsigned int)0x00000040)        /*!< Transfer complete interrupt enable  */
#define  FMPI2C_CR1_ERRIE                       ((unsigned int)0x00000080)        /*!< Errors interrupt enable             */
#define  FMPI2C_CR1_DFN                         ((unsigned int)0x00000F00)        /*!< Digital noise filter                */
#define  FMPI2C_CR1_ANFOFF                      ((unsigned int)0x00001000)        /*!< Analog noise filter OFF             */
#define  FMPI2C_CR1_SWRST                       ((unsigned int)0x00002000)        /*!< Software reset                      */
#define  FMPI2C_CR1_TXDMAEN                     ((unsigned int)0x00004000)        /*!< DMA transmission requests enable    */
#define  FMPI2C_CR1_RXDMAEN                     ((unsigned int)0x00008000)        /*!< DMA reception requests enable       */
#define  FMPI2C_CR1_SBC                         ((unsigned int)0x00010000)        /*!< Slave byte control                  */
#define  FMPI2C_CR1_NOSTRETCH                   ((unsigned int)0x00020000)        /*!< Clock stretching disable            */
#define  FMPI2C_CR1_WUPEN                       ((unsigned int)0x00040000)        /*!< Wakeup from STOP enable             */
#define  FMPI2C_CR1_GCEN                        ((unsigned int)0x00080000)        /*!< General call enable                 */
#define  FMPI2C_CR1_SMBHEN                      ((unsigned int)0x00100000)        /*!< SMBus host address enable           */
#define  FMPI2C_CR1_SMBDEN                      ((unsigned int)0x00200000)        /*!< SMBus device default address enable */
#define  FMPI2C_CR1_ALERTEN                     ((unsigned int)0x00400000)        /*!< SMBus alert enable                  */
#define  FMPI2C_CR1_PECEN                       ((unsigned int)0x00800000)        /*!< PEC enable                          */

/******************  Bit definition for I2C_CR2 register  ********************/
#define  FMPI2C_CR2_SADD                        ((unsigned int)0x000003FF)        /*!< Slave address (master mode)                             */
#define  FMPI2C_CR2_RD_WRN                      ((unsigned int)0x00000400)        /*!< Transfer direction (master mode)                        */
#define  FMPI2C_CR2_ADD10                       ((unsigned int)0x00000800)        /*!< 10-bit addressing mode (master mode)                    */
#define  FMPI2C_CR2_HEAD10R                     ((unsigned int)0x00001000)        /*!< 10-bit address header only read direction (master mode) */
#define  FMPI2C_CR2_START                       ((unsigned int)0x00002000)        /*!< START generation                                        */
#define  FMPI2C_CR2_STOP                        ((unsigned int)0x00004000)        /*!< STOP generation (master mode)                           */
#define  FMPI2C_CR2_NACK                        ((unsigned int)0x00008000)        /*!< NACK generation (slave mode)                            */
#define  FMPI2C_CR2_NBYTES                      ((unsigned int)0x00FF0000)        /*!< Number of bytes                                         */
#define  FMPI2C_CR2_RELOAD                      ((unsigned int)0x01000000)        /*!< NBYTES reload mode                                      */
#define  FMPI2C_CR2_AUTOEND                     ((unsigned int)0x02000000)        /*!< Automatic end mode (master mode)                        */
#define  FMPI2C_CR2_PECBYTE                     ((unsigned int)0x04000000)        /*!< Packet error checking byte                              */

/*******************  Bit definition for I2C_OAR1 register  ******************/
#define  FMPI2C_OAR1_OA1                        ((unsigned int)0x000003FF)        /*!< Interface own address 1   */
#define  FMPI2C_OAR1_OA1MODE                    ((unsigned int)0x00000400)        /*!< Own address 1 10-bit mode */
#define  FMPI2C_OAR1_OA1EN                      ((unsigned int)0x00008000)        /*!< Own address 1 enable     */

/*******************  Bit definition for I2C_OAR2 register  *******************/
#define  FMPI2C_OAR2_OA2                        ((unsigned int)0x000000FE)        /*!< Interface own address 2 */
#define  FMPI2C_OAR2_OA2MSK                     ((unsigned int)0x00000700)        /*!< Own address 2 masks     */
#define  FMPI2C_OAR2_OA2EN                      ((unsigned int)0x00008000)        /*!< Own address 2 enable    */

/*******************  Bit definition for I2C_TIMINGR register *****************/
#define  FMPI2C_TIMINGR_SCLL                    ((unsigned int)0x000000FF)        /*!< SCL low period (master mode)  */
#define  FMPI2C_TIMINGR_SCLH                    ((unsigned int)0x0000FF00)        /*!< SCL high period (master mode) */
#define  FMPI2C_TIMINGR_SDADEL                  ((unsigned int)0x000F0000)        /*!< Data hold time                */
#define  FMPI2C_TIMINGR_SCLDEL                  ((unsigned int)0x00F00000)        /*!< Data setup time               */
#define  FMPI2C_TIMINGR_PRESC                   ((unsigned int)0xF0000000)        /*!< Timings prescaler             */

/******************* Bit definition for I2C_TIMEOUTR register *****************/
#define  FMPI2C_TIMEOUTR_TIMEOUTA               ((unsigned int)0x00000FFF)        /*!< Bus timeout A                 */
#define  FMPI2C_TIMEOUTR_TIDLE                  ((unsigned int)0x00001000)        /*!< Idle clock timeout detection  */
#define  FMPI2C_TIMEOUTR_TIMOUTEN               ((unsigned int)0x00008000)        /*!< Clock timeout enable          */
#define  FMPI2C_TIMEOUTR_TIMEOUTB               ((unsigned int)0x0FFF0000)        /*!< Bus timeout B                 */
#define  FMPI2C_TIMEOUTR_TEXTEN                 ((unsigned int)0x80000000)        /*!< Extended clock timeout enable */

/******************  Bit definition for I2C_ISR register  *********************/
#define  FMPI2C_ISR_TXE                         ((unsigned int)0x00000001)        /*!< Transmit data register empty    */
#define  FMPI2C_ISR_TXIS                        ((unsigned int)0x00000002)        /*!< Transmit interrupt status       */
#define  FMPI2C_ISR_RXNE                        ((unsigned int)0x00000004)        /*!< Receive data register not empty */
#define  FMPI2C_ISR_ADDR                        ((unsigned int)0x00000008)        /*!< Address matched (slave mode)    */
#define  FMPI2C_ISR_NACKF                       ((unsigned int)0x00000010)        /*!< NACK received flag              */
#define  FMPI2C_ISR_STOPF                       ((unsigned int)0x00000020)        /*!< STOP detection flag             */
#define  FMPI2C_ISR_TC                          ((unsigned int)0x00000040)        /*!< Transfer complete (master mode) */
#define  FMPI2C_ISR_TCR                         ((unsigned int)0x00000080)        /*!< Transfer complete reload        */
#define  FMPI2C_ISR_BERR                        ((unsigned int)0x00000100)        /*!< Bus error                       */
#define  FMPI2C_ISR_ARLO                        ((unsigned int)0x00000200)        /*!< Arbitration lost                */
#define  FMPI2C_ISR_OVR                         ((unsigned int)0x00000400)        /*!< Overrun/Underrun                */
#define  FMPI2C_ISR_PECERR                      ((unsigned int)0x00000800)        /*!< PEC error in reception          */
#define  FMPI2C_ISR_TIMEOUT                     ((unsigned int)0x00001000)        /*!< Timeout or Tlow detection flag  */
#define  FMPI2C_ISR_ALERT                       ((unsigned int)0x00002000)        /*!< SMBus alert                     */
#define  FMPI2C_ISR_BUSY                        ((unsigned int)0x00008000)        /*!< Bus busy                        */
#define  FMPI2C_ISR_DIR                         ((unsigned int)0x00010000)        /*!< Transfer direction (slave mode) */
#define  FMPI2C_ISR_ADDCODE                     ((unsigned int)0x00FE0000)        /*!< Address match code (slave mode) */

/******************  Bit definition for I2C_ICR register  *********************/
#define  FMPI2C_ICR_ADDRCF                      ((unsigned int)0x00000008)        /*!< Address matched clear flag  */
#define  FMPI2C_ICR_NACKCF                      ((unsigned int)0x00000010)        /*!< NACK clear flag             */
#define  FMPI2C_ICR_STOPCF                      ((unsigned int)0x00000020)        /*!< STOP detection clear flag   */
#define  FMPI2C_ICR_BERRCF                      ((unsigned int)0x00000100)        /*!< Bus error clear flag */
#define  FMPI2C_ICR_ARLOCF                      ((unsigned int)0x00000200)        /*!< Arbitration lost clear flag */
#define  FMPI2C_ICR_OVRCF                       ((unsigned int)0x00000400)        /*!< Overrun/Underrun clear flag */
#define  FMPI2C_ICR_PECCF                       ((unsigned int)0x00000800)        /*!< PAC error clear flag        */
#define  FMPI2C_ICR_TIMOUTCF                    ((unsigned int)0x00001000)        /*!< Timeout clear flag          */
#define  FMPI2C_ICR_ALERTCF                     ((unsigned int)0x00002000)        /*!< Alert clear flag            */

/******************  Bit definition for I2C_PECR register  ********************/
#define  FMPI2C_PECR_PEC                        ((unsigned int)0x000000FF)        /*!< PEC register */

/******************  Bit definition for I2C_RXDR register  *********************/
#define  FMPI2C_RXDR_RXDATA                     ((unsigned int)0x000000FF)        /*!< 8-bit receive data */

/******************  Bit definition for I2C_TXDR register  *********************/
#define  FMPI2C_TXDR_TXDATA                     ((unsigned int)0x000000FF)        /*!< 8-bit transmit data */

/******************************************************************************/
/*                                                                            */
/*                           Independent WATCHDOG                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDG_KR register  ********************/
#define  IWDG_KR_KEY                         ((unsigned short)0xFFFF)            /*!<Key value (write only, read 0000h)  */

/*******************  Bit definition for IWDG_PR register  ********************/
#define  IWDG_PR_PR                          ((unsigned char)0x07)               /*!<PR[2:0] (Prescaler divider)         */
#define  IWDG_PR_PR_0                        ((unsigned char)0x01)               /*!<Bit 0 */
#define  IWDG_PR_PR_1                        ((unsigned char)0x02)               /*!<Bit 1 */
#define  IWDG_PR_PR_2                        ((unsigned char)0x04)               /*!<Bit 2 */

/*******************  Bit definition for IWDG_RLR register  *******************/
#define  IWDG_RLR_RL                         ((unsigned short)0x0FFF)            /*!<Watchdog counter reload value        */

/*******************  Bit definition for IWDG_SR register  ********************/
#define  IWDG_SR_PVU                         ((unsigned char)0x01)               /*!<Watchdog prescaler value update      */
#define  IWDG_SR_RVU                         ((unsigned char)0x02)               /*!<Watchdog counter reload value update */

/******************************************************************************/
/*                                                                            */
/*                      LCD-TFT Display Controller (LTDC)                     */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for LTDC_SSCR register  *****************/

#define LTDC_SSCR_VSH                       ((unsigned int)0x000007FF)              /*!< Vertical Synchronization Height */
#define LTDC_SSCR_HSW                       ((unsigned int)0x0FFF0000)              /*!< Horizontal Synchronization Width */

/********************  Bit definition for LTDC_BPCR register  *****************/

#define LTDC_BPCR_AVBP                      ((unsigned int)0x000007FF)              /*!< Accumulated Vertical Back Porch */
#define LTDC_BPCR_AHBP                      ((unsigned int)0x0FFF0000)              /*!< Accumulated Horizontal Back Porch */

/********************  Bit definition for LTDC_AWCR register  *****************/

#define LTDC_AWCR_AAH                       ((unsigned int)0x000007FF)              /*!< Accumulated Active heigh */
#define LTDC_AWCR_AAW                       ((unsigned int)0x0FFF0000)              /*!< Accumulated Active Width */

/********************  Bit definition for LTDC_TWCR register  *****************/

#define LTDC_TWCR_TOTALH                    ((unsigned int)0x000007FF)              /*!< Total Heigh */
#define LTDC_TWCR_TOTALW                    ((unsigned int)0x0FFF0000)              /*!< Total Width */

/********************  Bit definition for LTDC_GCR register  ******************/

#define LTDC_GCR_LTDCEN                     ((unsigned int)0x00000001)              /*!< LCD-TFT controller enable bit */
#define LTDC_GCR_DBW                        ((unsigned int)0x00000070)              /*!< Dither Blue Width */
#define LTDC_GCR_DGW                        ((unsigned int)0x00000700)              /*!< Dither Green Width */
#define LTDC_GCR_DRW                        ((unsigned int)0x00007000)              /*!< Dither Red Width */
#define LTDC_GCR_DTEN                       ((unsigned int)0x00010000)              /*!< Dither Enable */
#define LTDC_GCR_PCPOL                      ((unsigned int)0x10000000)              /*!< Pixel Clock Polarity */
#define LTDC_GCR_DEPOL                      ((unsigned int)0x20000000)              /*!< Data Enable Polarity */
#define LTDC_GCR_VSPOL                      ((unsigned int)0x40000000)              /*!< Vertical Synchronization Polarity */
#define LTDC_GCR_HSPOL                      ((unsigned int)0x80000000)              /*!< Horizontal Synchronization Polarity */

/********************  Bit definition for LTDC_SRCR register  *****************/

#define LTDC_SRCR_IMR                      ((unsigned int)0x00000001)               /*!< Immediate Reload */
#define LTDC_SRCR_VBR                      ((unsigned int)0x00000002)               /*!< Vertical Blanking Reload */

/********************  Bit definition for LTDC_BCCR register  *****************/

#define LTDC_BCCR_BCBLUE                    ((unsigned int)0x000000FF)              /*!< Background Blue value */
#define LTDC_BCCR_BCGREEN                   ((unsigned int)0x0000FF00)              /*!< Background Green value */
#define LTDC_BCCR_BCRED                     ((unsigned int)0x00FF0000)              /*!< Background Red value */

/********************  Bit definition for LTDC_IER register  ******************/

#define LTDC_IER_LIE                        ((unsigned int)0x00000001)              /*!< Line Interrupt Enable */
#define LTDC_IER_FUIE                       ((unsigned int)0x00000002)              /*!< FIFO Underrun Interrupt Enable */
#define LTDC_IER_TERRIE                     ((unsigned int)0x00000004)              /*!< Transfer Error Interrupt Enable */
#define LTDC_IER_RRIE                       ((unsigned int)0x00000008)              /*!< Register Reload interrupt enable */

/********************  Bit definition for LTDC_ISR register  ******************/

#define LTDC_ISR_LIF                        ((unsigned int)0x00000001)              /*!< Line Interrupt Flag */
#define LTDC_ISR_FUIF                       ((unsigned int)0x00000002)              /*!< FIFO Underrun Interrupt Flag */
#define LTDC_ISR_TERRIF                     ((unsigned int)0x00000004)              /*!< Transfer Error Interrupt Flag */
#define LTDC_ISR_RRIF                       ((unsigned int)0x00000008)              /*!< Register Reload interrupt Flag */

/********************  Bit definition for LTDC_ICR register  ******************/

#define LTDC_ICR_CLIF                       ((unsigned int)0x00000001)              /*!< Clears the Line Interrupt Flag */
#define LTDC_ICR_CFUIF                      ((unsigned int)0x00000002)              /*!< Clears the FIFO Underrun Interrupt Flag */
#define LTDC_ICR_CTERRIF                    ((unsigned int)0x00000004)              /*!< Clears the Transfer Error Interrupt Flag */
#define LTDC_ICR_CRRIF                      ((unsigned int)0x00000008)              /*!< Clears Register Reload interrupt Flag */

/********************  Bit definition for LTDC_LIPCR register  ****************/

#define LTDC_LIPCR_LIPOS                    ((unsigned int)0x000007FF)              /*!< Line Interrupt Position */

/********************  Bit definition for LTDC_CPSR register  *****************/

#define LTDC_CPSR_CYPOS                     ((unsigned int)0x0000FFFF)              /*!< Current Y Position */
#define LTDC_CPSR_CXPOS                     ((unsigned int)0xFFFF0000)              /*!< Current X Position */

/********************  Bit definition for LTDC_CDSR register  *****************/

#define LTDC_CDSR_VDES                      ((unsigned int)0x00000001)              /*!< Vertical Data Enable Status */
#define LTDC_CDSR_HDES                      ((unsigned int)0x00000002)              /*!< Horizontal Data Enable Status */
#define LTDC_CDSR_VSYNCS                    ((unsigned int)0x00000004)              /*!< Vertical Synchronization Status */
#define LTDC_CDSR_HSYNCS                    ((unsigned int)0x00000008)              /*!< Horizontal Synchronization Status */

/********************  Bit definition for LTDC_LxCR register  *****************/

#define LTDC_LxCR_LEN                       ((unsigned int)0x00000001)              /*!< Layer Enable */
#define LTDC_LxCR_COLKEN                    ((unsigned int)0x00000002)              /*!< Color Keying Enable */
#define LTDC_LxCR_CLUTEN                    ((unsigned int)0x00000010)              /*!< Color Lockup Table Enable */

/********************  Bit definition for LTDC_LxWHPCR register  **************/

#define LTDC_LxWHPCR_WHSTPOS                ((unsigned int)0x00000FFF)              /*!< Window Horizontal Start Position */
#define LTDC_LxWHPCR_WHSPPOS                ((unsigned int)0xFFFF0000)              /*!< Window Horizontal Stop Position */

/********************  Bit definition for LTDC_LxWVPCR register  **************/

#define LTDC_LxWVPCR_WVSTPOS                ((unsigned int)0x00000FFF)              /*!< Window Vertical Start Position */
#define LTDC_LxWVPCR_WVSPPOS                ((unsigned int)0xFFFF0000)              /*!< Window Vertical Stop Position */

/********************  Bit definition for LTDC_LxCKCR register  ***************/

#define LTDC_LxCKCR_CKBLUE                  ((unsigned int)0x000000FF)              /*!< Color Key Blue value */
#define LTDC_LxCKCR_CKGREEN                 ((unsigned int)0x0000FF00)              /*!< Color Key Green value */
#define LTDC_LxCKCR_CKRED                   ((unsigned int)0x00FF0000)              /*!< Color Key Red value */

/********************  Bit definition for LTDC_LxPFCR register  ***************/

#define LTDC_LxPFCR_PF                      ((unsigned int)0x00000007)              /*!< Pixel Format */

/********************  Bit definition for LTDC_LxCACR register  ***************/

#define LTDC_LxCACR_CONSTA                  ((unsigned int)0x000000FF)              /*!< Constant Alpha */

/********************  Bit definition for LTDC_LxDCCR register  ***************/

#define LTDC_LxDCCR_DCBLUE                  ((unsigned int)0x000000FF)              /*!< Default Color Blue */
#define LTDC_LxDCCR_DCGREEN                 ((unsigned int)0x0000FF00)              /*!< Default Color Green */
#define LTDC_LxDCCR_DCRED                   ((unsigned int)0x00FF0000)              /*!< Default Color Red */
#define LTDC_LxDCCR_DCALPHA                 ((unsigned int)0xFF000000)              /*!< Default Color Alpha */

/********************  Bit definition for LTDC_LxBFCR register  ***************/

#define LTDC_LxBFCR_BF2                     ((unsigned int)0x00000007)              /*!< Blending Factor 2 */
#define LTDC_LxBFCR_BF1                     ((unsigned int)0x00000700)              /*!< Blending Factor 1 */

/********************  Bit definition for LTDC_LxCFBAR register  **************/

#define LTDC_LxCFBAR_CFBADD                 ((unsigned int)0xFFFFFFFF)              /*!< Color Frame Buffer Start Address */

/********************  Bit definition for LTDC_LxCFBLR register  **************/

#define LTDC_LxCFBLR_CFBLL                  ((unsigned int)0x00001FFF)              /*!< Color Frame Buffer Line Length */
#define LTDC_LxCFBLR_CFBP                   ((unsigned int)0x1FFF0000)              /*!< Color Frame Buffer Pitch in bytes */

/********************  Bit definition for LTDC_LxCFBLNR register  *************/

#define LTDC_LxCFBLNR_CFBLNBR               ((unsigned int)0x000007FF)              /*!< Frame Buffer Line Number */

/********************  Bit definition for LTDC_LxCLUTWR register  *************/

#define LTDC_LxCLUTWR_BLUE                  ((unsigned int)0x000000FF)              /*!< Blue value */
#define LTDC_LxCLUTWR_GREEN                 ((unsigned int)0x0000FF00)              /*!< Green value */
#define LTDC_LxCLUTWR_RED                   ((unsigned int)0x00FF0000)              /*!< Red value */
#define LTDC_LxCLUTWR_CLUTADD               ((unsigned int)0xFF000000)              /*!< CLUT address */

/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWR_CR register  ********************/
#define  PWR_CR_LPDS                         ((unsigned int)0x00000001)     /*!< Low-Power Deepsleep                 */
#define  PWR_CR_PDDS                         ((unsigned int)0x00000002)     /*!< Power Down Deepsleep                */
#define  PWR_CR_CWUF                         ((unsigned int)0x00000004)     /*!< Clear Wakeup Flag                   */
#define  PWR_CR_CSBF                         ((unsigned int)0x00000008)     /*!< Clear Standby Flag                  */
#define  PWR_CR_PVDE                         ((unsigned int)0x00000010)     /*!< Power Voltage Detector Enable       */

#define  PWR_CR_PLS                          ((unsigned int)0x000000E0)     /*!< PLS[2:0] bits (PVD Level Selection) */
#define  PWR_CR_PLS_0                        ((unsigned int)0x00000020)     /*!< Bit 0 */
#define  PWR_CR_PLS_1                        ((unsigned int)0x00000040)     /*!< Bit 1 */
#define  PWR_CR_PLS_2                        ((unsigned int)0x00000080)     /*!< Bit 2 */

/*!< PVD level configuration */
#define  PWR_CR_PLS_LEV0                     ((unsigned int)0x00000000)     /*!< PVD level 0 */
#define  PWR_CR_PLS_LEV1                     ((unsigned int)0x00000020)     /*!< PVD level 1 */
#define  PWR_CR_PLS_LEV2                     ((unsigned int)0x00000040)     /*!< PVD level 2 */
#define  PWR_CR_PLS_LEV3                     ((unsigned int)0x00000060)     /*!< PVD level 3 */
#define  PWR_CR_PLS_LEV4                     ((unsigned int)0x00000080)     /*!< PVD level 4 */
#define  PWR_CR_PLS_LEV5                     ((unsigned int)0x000000A0)     /*!< PVD level 5 */
#define  PWR_CR_PLS_LEV6                     ((unsigned int)0x000000C0)     /*!< PVD level 6 */
#define  PWR_CR_PLS_LEV7                     ((unsigned int)0x000000E0)     /*!< PVD level 7 */

#define  PWR_CR_DBP                          ((unsigned int)0x00000100)     /*!< Disable Backup Domain write protection                     */
#define  PWR_CR_FPDS                         ((unsigned int)0x00000200)     /*!< Flash power down in Stop mode                              */
#define  PWR_CR_LPUDS                        ((unsigned int)0x00000400)     /*!< Low-Power Regulator in Stop under-drive mode               */
#define  PWR_CR_MRUDS                        ((unsigned int)0x00000800)     /*!< Main regulator in Stop under-drive mode                    */

#define  PWR_CR_LPLVDS                       ((unsigned int)0x00000400)     /*!< Low-power regulator Low Voltage in Deep Sleep mode         */
#define  PWR_CR_MRLVDS                       ((unsigned int)0x00000800)     /*!< Main regulator Low Voltage in Deep Sleep mode              */

#define  PWR_CR_ADCDC1                       ((unsigned int)0x00002000)     /*!< Refer to AN4073 on how to use this bit */ 

#define  PWR_CR_VOS                          ((unsigned int)0x0000C000)     /*!< VOS[1:0] bits (Regulator voltage scaling output selection) */
#define  PWR_CR_VOS_0                        ((unsigned int)0x00004000)     /*!< Bit 0 */
#define  PWR_CR_VOS_1                        ((unsigned int)0x00008000)     /*!< Bit 1 */

#define  PWR_CR_ODEN                         ((unsigned int)0x00010000)     /*!< Over Drive enable                   */
#define  PWR_CR_ODSWEN                       ((unsigned int)0x00020000)     /*!< Over Drive switch enabled           */
#define  PWR_CR_UDEN                         ((unsigned int)0x000C0000)     /*!< Under Drive enable in stop mode     */
#define  PWR_CR_UDEN_0                       ((unsigned int)0x00040000)     /*!< Bit 0                               */
#define  PWR_CR_UDEN_1                       ((unsigned int)0x00080000)     /*!< Bit 1                               */

#define  PWR_CR_FMSSR                        ((unsigned int)0x00100000)     /*!< Flash Memory Sleep System Run        */
#define  PWR_CR_FISSR                        ((unsigned int)0x00200000)     /*!< Flash Interface Stop while System Run */

/* Legacy define */
#define  PWR_CR_PMODE                        PWR_CR_VOS

/*******************  Bit definition for PWR_CSR register  ********************/
#define  PWR_CSR_WUF                         ((unsigned int)0x00000001)     /*!< Wakeup Flag                                      */
#define  PWR_CSR_SBF                         ((unsigned int)0x00000002)     /*!< Standby Flag                                     */
#define  PWR_CSR_PVDO                        ((unsigned int)0x00000004)     /*!< PVD Output                                       */
#define  PWR_CSR_BRR                         ((unsigned int)0x00000008)     /*!< Backup regulator ready                           */
#define  PWR_CSR_WUPP                        ((unsigned int)0x00000080)     /*!< WKUP pin Polarity                                */
#define  PWR_CSR_EWUP                        ((unsigned int)0x00000100)     /*!< Enable WKUP pin                                  */
#define  PWR_CSR_BRE                         ((unsigned int)0x00000200)     /*!< Backup regulator enable                          */
#define  PWR_CSR_VOSRDY                      ((unsigned int)0x00004000)     /*!< Regulator voltage scaling output selection ready */
#define  PWR_CSR_ODRDY                       ((unsigned int)0x00010000)     /*!< Over Drive generator ready                       */
#define  PWR_CSR_ODSWRDY                     ((unsigned int)0x00020000)     /*!< Over Drive Switch ready                          */
#define  PWR_CSR_UDSWRDY                     ((unsigned int)0x000C0000)     /*!< Under Drive ready                                */

/* Legacy define */
#define  PWR_CSR_REGRDY                      PWR_CSR_VOSRDY

/******************************************************************************/
/*                                                                            */
/*                                    RNG                                     */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RNG_CR register  *******************/
#define RNG_CR_RNGEN                         ((unsigned int)0x00000004)
#define RNG_CR_IE                            ((unsigned int)0x00000008)

/********************  Bits definition for RNG_SR register  *******************/
#define RNG_SR_DRDY                          ((unsigned int)0x00000001)
#define RNG_SR_CECS                          ((unsigned int)0x00000002)
#define RNG_SR_SECS                          ((unsigned int)0x00000004)
#define RNG_SR_CEIS                          ((unsigned int)0x00000020)
#define RNG_SR_SEIS                          ((unsigned int)0x00000040)

/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RTC_TR register  *******************/
#define RTC_TR_PM                            ((unsigned int)0x00400000)
#define RTC_TR_HT                            ((unsigned int)0x00300000)
#define RTC_TR_HT_0                          ((unsigned int)0x00100000)
#define RTC_TR_HT_1                          ((unsigned int)0x00200000)
#define RTC_TR_HU                            ((unsigned int)0x000F0000)
#define RTC_TR_HU_0                          ((unsigned int)0x00010000)
#define RTC_TR_HU_1                          ((unsigned int)0x00020000)
#define RTC_TR_HU_2                          ((unsigned int)0x00040000)
#define RTC_TR_HU_3                          ((unsigned int)0x00080000)
#define RTC_TR_MNT                           ((unsigned int)0x00007000)
#define RTC_TR_MNT_0                         ((unsigned int)0x00001000)
#define RTC_TR_MNT_1                         ((unsigned int)0x00002000)
#define RTC_TR_MNT_2                         ((unsigned int)0x00004000)
#define RTC_TR_MNU                           ((unsigned int)0x00000F00)
#define RTC_TR_MNU_0                         ((unsigned int)0x00000100)
#define RTC_TR_MNU_1                         ((unsigned int)0x00000200)
#define RTC_TR_MNU_2                         ((unsigned int)0x00000400)
#define RTC_TR_MNU_3                         ((unsigned int)0x00000800)
#define RTC_TR_ST                            ((unsigned int)0x00000070)
#define RTC_TR_ST_0                          ((unsigned int)0x00000010)
#define RTC_TR_ST_1                          ((unsigned int)0x00000020)
#define RTC_TR_ST_2                          ((unsigned int)0x00000040)
#define RTC_TR_SU                            ((unsigned int)0x0000000F)
#define RTC_TR_SU_0                          ((unsigned int)0x00000001)
#define RTC_TR_SU_1                          ((unsigned int)0x00000002)
#define RTC_TR_SU_2                          ((unsigned int)0x00000004)
#define RTC_TR_SU_3                          ((unsigned int)0x00000008)

/********************  Bits definition for RTC_DR register  *******************/
#define RTC_DR_YT                            ((unsigned int)0x00F00000)
#define RTC_DR_YT_0                          ((unsigned int)0x00100000)
#define RTC_DR_YT_1                          ((unsigned int)0x00200000)
#define RTC_DR_YT_2                          ((unsigned int)0x00400000)
#define RTC_DR_YT_3                          ((unsigned int)0x00800000)
#define RTC_DR_YU                            ((unsigned int)0x000F0000)
#define RTC_DR_YU_0                          ((unsigned int)0x00010000)
#define RTC_DR_YU_1                          ((unsigned int)0x00020000)
#define RTC_DR_YU_2                          ((unsigned int)0x00040000)
#define RTC_DR_YU_3                          ((unsigned int)0x00080000)
#define RTC_DR_WDU                           ((unsigned int)0x0000E000)
#define RTC_DR_WDU_0                         ((unsigned int)0x00002000)
#define RTC_DR_WDU_1                         ((unsigned int)0x00004000)
#define RTC_DR_WDU_2                         ((unsigned int)0x00008000)
#define RTC_DR_MT                            ((unsigned int)0x00001000)
#define RTC_DR_MU                            ((unsigned int)0x00000F00)
#define RTC_DR_MU_0                          ((unsigned int)0x00000100)
#define RTC_DR_MU_1                          ((unsigned int)0x00000200)
#define RTC_DR_MU_2                          ((unsigned int)0x00000400)
#define RTC_DR_MU_3                          ((unsigned int)0x00000800)
#define RTC_DR_DT                            ((unsigned int)0x00000030)
#define RTC_DR_DT_0                          ((unsigned int)0x00000010)
#define RTC_DR_DT_1                          ((unsigned int)0x00000020)
#define RTC_DR_DU                            ((unsigned int)0x0000000F)
#define RTC_DR_DU_0                          ((unsigned int)0x00000001)
#define RTC_DR_DU_1                          ((unsigned int)0x00000002)
#define RTC_DR_DU_2                          ((unsigned int)0x00000004)
#define RTC_DR_DU_3                          ((unsigned int)0x00000008)

/********************  Bits definition for RTC_CR register  *******************/
#define RTC_CR_COE                           ((unsigned int)0x00800000)
#define RTC_CR_OSEL                          ((unsigned int)0x00600000)
#define RTC_CR_OSEL_0                        ((unsigned int)0x00200000)
#define RTC_CR_OSEL_1                        ((unsigned int)0x00400000)
#define RTC_CR_POL                           ((unsigned int)0x00100000)
#define RTC_CR_COSEL                         ((unsigned int)0x00080000)
#define RTC_CR_BCK                           ((unsigned int)0x00040000)
#define RTC_CR_SUB1H                         ((unsigned int)0x00020000)
#define RTC_CR_ADD1H                         ((unsigned int)0x00010000)
#define RTC_CR_TSIE                          ((unsigned int)0x00008000)
#define RTC_CR_WUTIE                         ((unsigned int)0x00004000)
#define RTC_CR_ALRBIE                        ((unsigned int)0x00002000)
#define RTC_CR_ALRAIE                        ((unsigned int)0x00001000)
#define RTC_CR_TSE                           ((unsigned int)0x00000800)
#define RTC_CR_WUTE                          ((unsigned int)0x00000400)
#define RTC_CR_ALRBE                         ((unsigned int)0x00000200)
#define RTC_CR_ALRAE                         ((unsigned int)0x00000100)
#define RTC_CR_DCE                           ((unsigned int)0x00000080)
#define RTC_CR_FMT                           ((unsigned int)0x00000040)
#define RTC_CR_BYPSHAD                       ((unsigned int)0x00000020)
#define RTC_CR_REFCKON                       ((unsigned int)0x00000010)
#define RTC_CR_TSEDGE                        ((unsigned int)0x00000008)
#define RTC_CR_WUCKSEL                       ((unsigned int)0x00000007)
#define RTC_CR_WUCKSEL_0                     ((unsigned int)0x00000001)
#define RTC_CR_WUCKSEL_1                     ((unsigned int)0x00000002)
#define RTC_CR_WUCKSEL_2                     ((unsigned int)0x00000004)

/********************  Bits definition for RTC_ISR register  ******************/
#define RTC_ISR_RECALPF                      ((unsigned int)0x00010000)
#define RTC_ISR_TAMP1F                       ((unsigned int)0x00002000)
#define RTC_ISR_TSOVF                        ((unsigned int)0x00001000)
#define RTC_ISR_TSF                          ((unsigned int)0x00000800)
#define RTC_ISR_WUTF                         ((unsigned int)0x00000400)
#define RTC_ISR_ALRBF                        ((unsigned int)0x00000200)
#define RTC_ISR_ALRAF                        ((unsigned int)0x00000100)
#define RTC_ISR_INIT                         ((unsigned int)0x00000080)
#define RTC_ISR_INITF                        ((unsigned int)0x00000040)
#define RTC_ISR_RSF                          ((unsigned int)0x00000020)
#define RTC_ISR_INITS                        ((unsigned int)0x00000010)
#define RTC_ISR_SHPF                         ((unsigned int)0x00000008)
#define RTC_ISR_WUTWF                        ((unsigned int)0x00000004)
#define RTC_ISR_ALRBWF                       ((unsigned int)0x00000002)
#define RTC_ISR_ALRAWF                       ((unsigned int)0x00000001)

/********************  Bits definition for RTC_PRER register  *****************/
#define RTC_PRER_PREDIV_A                    ((unsigned int)0x007F0000)
#define RTC_PRER_PREDIV_S                    ((unsigned int)0x00001FFF)

/********************  Bits definition for RTC_WUTR register  *****************/
#define RTC_WUTR_WUT                         ((unsigned int)0x0000FFFF)

/********************  Bits definition for RTC_CALIBR register  ***************/
#define RTC_CALIBR_DCS                       ((unsigned int)0x00000080)
#define RTC_CALIBR_DC                        ((unsigned int)0x0000001F)

/********************  Bits definition for RTC_ALRMAR register  ***************/
#define RTC_ALRMAR_MSK4                      ((unsigned int)0x80000000)
#define RTC_ALRMAR_WDSEL                     ((unsigned int)0x40000000)
#define RTC_ALRMAR_DT                        ((unsigned int)0x30000000)
#define RTC_ALRMAR_DT_0                      ((unsigned int)0x10000000)
#define RTC_ALRMAR_DT_1                      ((unsigned int)0x20000000)
#define RTC_ALRMAR_DU                        ((unsigned int)0x0F000000)
#define RTC_ALRMAR_DU_0                      ((unsigned int)0x01000000)
#define RTC_ALRMAR_DU_1                      ((unsigned int)0x02000000)
#define RTC_ALRMAR_DU_2                      ((unsigned int)0x04000000)
#define RTC_ALRMAR_DU_3                      ((unsigned int)0x08000000)
#define RTC_ALRMAR_MSK3                      ((unsigned int)0x00800000)
#define RTC_ALRMAR_PM                        ((unsigned int)0x00400000)
#define RTC_ALRMAR_HT                        ((unsigned int)0x00300000)
#define RTC_ALRMAR_HT_0                      ((unsigned int)0x00100000)
#define RTC_ALRMAR_HT_1                      ((unsigned int)0x00200000)
#define RTC_ALRMAR_HU                        ((unsigned int)0x000F0000)
#define RTC_ALRMAR_HU_0                      ((unsigned int)0x00010000)
#define RTC_ALRMAR_HU_1                      ((unsigned int)0x00020000)
#define RTC_ALRMAR_HU_2                      ((unsigned int)0x00040000)
#define RTC_ALRMAR_HU_3                      ((unsigned int)0x00080000)
#define RTC_ALRMAR_MSK2                      ((unsigned int)0x00008000)
#define RTC_ALRMAR_MNT                       ((unsigned int)0x00007000)
#define RTC_ALRMAR_MNT_0                     ((unsigned int)0x00001000)
#define RTC_ALRMAR_MNT_1                     ((unsigned int)0x00002000)
#define RTC_ALRMAR_MNT_2                     ((unsigned int)0x00004000)
#define RTC_ALRMAR_MNU                       ((unsigned int)0x00000F00)
#define RTC_ALRMAR_MNU_0                     ((unsigned int)0x00000100)
#define RTC_ALRMAR_MNU_1                     ((unsigned int)0x00000200)
#define RTC_ALRMAR_MNU_2                     ((unsigned int)0x00000400)
#define RTC_ALRMAR_MNU_3                     ((unsigned int)0x00000800)
#define RTC_ALRMAR_MSK1                      ((unsigned int)0x00000080)
#define RTC_ALRMAR_ST                        ((unsigned int)0x00000070)
#define RTC_ALRMAR_ST_0                      ((unsigned int)0x00000010)
#define RTC_ALRMAR_ST_1                      ((unsigned int)0x00000020)
#define RTC_ALRMAR_ST_2                      ((unsigned int)0x00000040)
#define RTC_ALRMAR_SU                        ((unsigned int)0x0000000F)
#define RTC_ALRMAR_SU_0                      ((unsigned int)0x00000001)
#define RTC_ALRMAR_SU_1                      ((unsigned int)0x00000002)
#define RTC_ALRMAR_SU_2                      ((unsigned int)0x00000004)
#define RTC_ALRMAR_SU_3                      ((unsigned int)0x00000008)

/********************  Bits definition for RTC_ALRMBR register  ***************/
#define RTC_ALRMBR_MSK4                      ((unsigned int)0x80000000)
#define RTC_ALRMBR_WDSEL                     ((unsigned int)0x40000000)
#define RTC_ALRMBR_DT                        ((unsigned int)0x30000000)
#define RTC_ALRMBR_DT_0                      ((unsigned int)0x10000000)
#define RTC_ALRMBR_DT_1                      ((unsigned int)0x20000000)
#define RTC_ALRMBR_DU                        ((unsigned int)0x0F000000)
#define RTC_ALRMBR_DU_0                      ((unsigned int)0x01000000)
#define RTC_ALRMBR_DU_1                      ((unsigned int)0x02000000)
#define RTC_ALRMBR_DU_2                      ((unsigned int)0x04000000)
#define RTC_ALRMBR_DU_3                      ((unsigned int)0x08000000)
#define RTC_ALRMBR_MSK3                      ((unsigned int)0x00800000)
#define RTC_ALRMBR_PM                        ((unsigned int)0x00400000)
#define RTC_ALRMBR_HT                        ((unsigned int)0x00300000)
#define RTC_ALRMBR_HT_0                      ((unsigned int)0x00100000)
#define RTC_ALRMBR_HT_1                      ((unsigned int)0x00200000)
#define RTC_ALRMBR_HU                        ((unsigned int)0x000F0000)
#define RTC_ALRMBR_HU_0                      ((unsigned int)0x00010000)
#define RTC_ALRMBR_HU_1                      ((unsigned int)0x00020000)
#define RTC_ALRMBR_HU_2                      ((unsigned int)0x00040000)
#define RTC_ALRMBR_HU_3                      ((unsigned int)0x00080000)
#define RTC_ALRMBR_MSK2                      ((unsigned int)0x00008000)
#define RTC_ALRMBR_MNT                       ((unsigned int)0x00007000)
#define RTC_ALRMBR_MNT_0                     ((unsigned int)0x00001000)
#define RTC_ALRMBR_MNT_1                     ((unsigned int)0x00002000)
#define RTC_ALRMBR_MNT_2                     ((unsigned int)0x00004000)
#define RTC_ALRMBR_MNU                       ((unsigned int)0x00000F00)
#define RTC_ALRMBR_MNU_0                     ((unsigned int)0x00000100)
#define RTC_ALRMBR_MNU_1                     ((unsigned int)0x00000200)
#define RTC_ALRMBR_MNU_2                     ((unsigned int)0x00000400)
#define RTC_ALRMBR_MNU_3                     ((unsigned int)0x00000800)
#define RTC_ALRMBR_MSK1                      ((unsigned int)0x00000080)
#define RTC_ALRMBR_ST                        ((unsigned int)0x00000070)
#define RTC_ALRMBR_ST_0                      ((unsigned int)0x00000010)
#define RTC_ALRMBR_ST_1                      ((unsigned int)0x00000020)
#define RTC_ALRMBR_ST_2                      ((unsigned int)0x00000040)
#define RTC_ALRMBR_SU                        ((unsigned int)0x0000000F)
#define RTC_ALRMBR_SU_0                      ((unsigned int)0x00000001)
#define RTC_ALRMBR_SU_1                      ((unsigned int)0x00000002)
#define RTC_ALRMBR_SU_2                      ((unsigned int)0x00000004)
#define RTC_ALRMBR_SU_3                      ((unsigned int)0x00000008)

/********************  Bits definition for RTC_WPR register  ******************/
#define RTC_WPR_KEY                          ((unsigned int)0x000000FF)

/********************  Bits definition for RTC_SSR register  ******************/
#define RTC_SSR_SS                           ((unsigned int)0x0000FFFF)

/********************  Bits definition for RTC_SHIFTR register  ***************/
#define RTC_SHIFTR_SUBFS                     ((unsigned int)0x00007FFF)
#define RTC_SHIFTR_ADD1S                     ((unsigned int)0x80000000)

/********************  Bits definition for RTC_TSTR register  *****************/
#define RTC_TSTR_PM                          ((unsigned int)0x00400000)
#define RTC_TSTR_HT                          ((unsigned int)0x00300000)
#define RTC_TSTR_HT_0                        ((unsigned int)0x00100000)
#define RTC_TSTR_HT_1                        ((unsigned int)0x00200000)
#define RTC_TSTR_HU                          ((unsigned int)0x000F0000)
#define RTC_TSTR_HU_0                        ((unsigned int)0x00010000)
#define RTC_TSTR_HU_1                        ((unsigned int)0x00020000)
#define RTC_TSTR_HU_2                        ((unsigned int)0x00040000)
#define RTC_TSTR_HU_3                        ((unsigned int)0x00080000)
#define RTC_TSTR_MNT                         ((unsigned int)0x00007000)
#define RTC_TSTR_MNT_0                       ((unsigned int)0x00001000)
#define RTC_TSTR_MNT_1                       ((unsigned int)0x00002000)
#define RTC_TSTR_MNT_2                       ((unsigned int)0x00004000)
#define RTC_TSTR_MNU                         ((unsigned int)0x00000F00)
#define RTC_TSTR_MNU_0                       ((unsigned int)0x00000100)
#define RTC_TSTR_MNU_1                       ((unsigned int)0x00000200)
#define RTC_TSTR_MNU_2                       ((unsigned int)0x00000400)
#define RTC_TSTR_MNU_3                       ((unsigned int)0x00000800)
#define RTC_TSTR_ST                          ((unsigned int)0x00000070)
#define RTC_TSTR_ST_0                        ((unsigned int)0x00000010)
#define RTC_TSTR_ST_1                        ((unsigned int)0x00000020)
#define RTC_TSTR_ST_2                        ((unsigned int)0x00000040)
#define RTC_TSTR_SU                          ((unsigned int)0x0000000F)
#define RTC_TSTR_SU_0                        ((unsigned int)0x00000001)
#define RTC_TSTR_SU_1                        ((unsigned int)0x00000002)
#define RTC_TSTR_SU_2                        ((unsigned int)0x00000004)
#define RTC_TSTR_SU_3                        ((unsigned int)0x00000008)

/********************  Bits definition for RTC_TSDR register  *****************/
#define RTC_TSDR_WDU                         ((unsigned int)0x0000E000)
#define RTC_TSDR_WDU_0                       ((unsigned int)0x00002000)
#define RTC_TSDR_WDU_1                       ((unsigned int)0x00004000)
#define RTC_TSDR_WDU_2                       ((unsigned int)0x00008000)
#define RTC_TSDR_MT                          ((unsigned int)0x00001000)
#define RTC_TSDR_MU                          ((unsigned int)0x00000F00)
#define RTC_TSDR_MU_0                        ((unsigned int)0x00000100)
#define RTC_TSDR_MU_1                        ((unsigned int)0x00000200)
#define RTC_TSDR_MU_2                        ((unsigned int)0x00000400)
#define RTC_TSDR_MU_3                        ((unsigned int)0x00000800)
#define RTC_TSDR_DT                          ((unsigned int)0x00000030)
#define RTC_TSDR_DT_0                        ((unsigned int)0x00000010)
#define RTC_TSDR_DT_1                        ((unsigned int)0x00000020)
#define RTC_TSDR_DU                          ((unsigned int)0x0000000F)
#define RTC_TSDR_DU_0                        ((unsigned int)0x00000001)
#define RTC_TSDR_DU_1                        ((unsigned int)0x00000002)
#define RTC_TSDR_DU_2                        ((unsigned int)0x00000004)
#define RTC_TSDR_DU_3                        ((unsigned int)0x00000008)

/********************  Bits definition for RTC_TSSSR register  ****************/
#define RTC_TSSSR_SS                         ((unsigned int)0x0000FFFF)

/********************  Bits definition for RTC_CAL register  *****************/
#define RTC_CALR_CALP                        ((unsigned int)0x00008000)
#define RTC_CALR_CALW8                       ((unsigned int)0x00004000)
#define RTC_CALR_CALW16                      ((unsigned int)0x00002000)
#define RTC_CALR_CALM                        ((unsigned int)0x000001FF)
#define RTC_CALR_CALM_0                      ((unsigned int)0x00000001)
#define RTC_CALR_CALM_1                      ((unsigned int)0x00000002)
#define RTC_CALR_CALM_2                      ((unsigned int)0x00000004)
#define RTC_CALR_CALM_3                      ((unsigned int)0x00000008)
#define RTC_CALR_CALM_4                      ((unsigned int)0x00000010)
#define RTC_CALR_CALM_5                      ((unsigned int)0x00000020)
#define RTC_CALR_CALM_6                      ((unsigned int)0x00000040)
#define RTC_CALR_CALM_7                      ((unsigned int)0x00000080)
#define RTC_CALR_CALM_8                      ((unsigned int)0x00000100)

/********************  Bits definition for RTC_TAFCR register  ****************/
#define RTC_TAFCR_ALARMOUTTYPE               ((unsigned int)0x00040000)
#define RTC_TAFCR_TSINSEL                    ((unsigned int)0x00020000)
#define RTC_TAFCR_TAMPINSEL                  ((unsigned int)0x00010000)
#define RTC_TAFCR_TAMPPUDIS                  ((unsigned int)0x00008000)
#define RTC_TAFCR_TAMPPRCH                   ((unsigned int)0x00006000)
#define RTC_TAFCR_TAMPPRCH_0                 ((unsigned int)0x00002000)
#define RTC_TAFCR_TAMPPRCH_1                 ((unsigned int)0x00004000)
#define RTC_TAFCR_TAMPFLT                    ((unsigned int)0x00001800)
#define RTC_TAFCR_TAMPFLT_0                  ((unsigned int)0x00000800)
#define RTC_TAFCR_TAMPFLT_1                  ((unsigned int)0x00001000)
#define RTC_TAFCR_TAMPFREQ                   ((unsigned int)0x00000700)
#define RTC_TAFCR_TAMPFREQ_0                 ((unsigned int)0x00000100)
#define RTC_TAFCR_TAMPFREQ_1                 ((unsigned int)0x00000200)
#define RTC_TAFCR_TAMPFREQ_2                 ((unsigned int)0x00000400)
#define RTC_TAFCR_TAMPTS                     ((unsigned int)0x00000080)
#define RTC_TAFCR_TAMPIE                     ((unsigned int)0x00000004)
#define RTC_TAFCR_TAMP1TRG                   ((unsigned int)0x00000002)
#define RTC_TAFCR_TAMP1E                     ((unsigned int)0x00000001)

/********************  Bits definition for RTC_ALRMASSR register  *************/
#define RTC_ALRMASSR_MASKSS                  ((unsigned int)0x0F000000)
#define RTC_ALRMASSR_MASKSS_0                ((unsigned int)0x01000000)
#define RTC_ALRMASSR_MASKSS_1                ((unsigned int)0x02000000)
#define RTC_ALRMASSR_MASKSS_2                ((unsigned int)0x04000000)
#define RTC_ALRMASSR_MASKSS_3                ((unsigned int)0x08000000)
#define RTC_ALRMASSR_SS                      ((unsigned int)0x00007FFF)

/********************  Bits definition for RTC_ALRMBSSR register  *************/
#define RTC_ALRMBSSR_MASKSS                  ((unsigned int)0x0F000000)
#define RTC_ALRMBSSR_MASKSS_0                ((unsigned int)0x01000000)
#define RTC_ALRMBSSR_MASKSS_1                ((unsigned int)0x02000000)
#define RTC_ALRMBSSR_MASKSS_2                ((unsigned int)0x04000000)
#define RTC_ALRMBSSR_MASKSS_3                ((unsigned int)0x08000000)
#define RTC_ALRMBSSR_SS                      ((unsigned int)0x00007FFF)

/********************  Bits definition for RTC_BKP0R register  ****************/
#define RTC_BKP0R                            ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP1R register  ****************/
#define RTC_BKP1R                            ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP2R register  ****************/
#define RTC_BKP2R                            ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP3R register  ****************/
#define RTC_BKP3R                            ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP4R register  ****************/
#define RTC_BKP4R                            ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP5R register  ****************/
#define RTC_BKP5R                            ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP6R register  ****************/
#define RTC_BKP6R                            ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP7R register  ****************/
#define RTC_BKP7R                            ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP8R register  ****************/
#define RTC_BKP8R                            ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP9R register  ****************/
#define RTC_BKP9R                            ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP10R register  ***************/
#define RTC_BKP10R                           ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP11R register  ***************/
#define RTC_BKP11R                           ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP12R register  ***************/
#define RTC_BKP12R                           ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP13R register  ***************/
#define RTC_BKP13R                           ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP14R register  ***************/
#define RTC_BKP14R                           ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP15R register  ***************/
#define RTC_BKP15R                           ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP16R register  ***************/
#define RTC_BKP16R                           ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP17R register  ***************/
#define RTC_BKP17R                           ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP18R register  ***************/
#define RTC_BKP18R                           ((unsigned int)0xFFFFFFFF)

/********************  Bits definition for RTC_BKP19R register  ***************/
#define RTC_BKP19R                           ((unsigned int)0xFFFFFFFF)

/******************************************************************************/
/*                                                                            */
/*                          Serial Audio Interface                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SAI_GCR register  *******************/
#define  SAI_GCR_SYNCIN                  ((unsigned int)0x00000003)        /*!<SYNCIN[1:0] bits (Synchronization Inputs)   */
#define  SAI_GCR_SYNCIN_0                ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  SAI_GCR_SYNCIN_1                ((unsigned int)0x00000002)        /*!<Bit 1 */

#define  SAI_GCR_SYNCOUT                 ((unsigned int)0x00000030)        /*!<SYNCOUT[1:0] bits (Synchronization Outputs) */
#define  SAI_GCR_SYNCOUT_0               ((unsigned int)0x00000010)        /*!<Bit 0 */
#define  SAI_GCR_SYNCOUT_1               ((unsigned int)0x00000020)        /*!<Bit 1 */

/*******************  Bit definition for SAI_xCR1 register  *******************/
#define  SAI_xCR1_MODE                    ((unsigned int)0x00000003)        /*!<MODE[1:0] bits (Audio Block Mode)           */
#define  SAI_xCR1_MODE_0                  ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  SAI_xCR1_MODE_1                  ((unsigned int)0x00000002)        /*!<Bit 1 */

#define  SAI_xCR1_PRTCFG                  ((unsigned int)0x0000000C)        /*!<PRTCFG[1:0] bits (Protocol Configuration)   */
#define  SAI_xCR1_PRTCFG_0                ((unsigned int)0x00000004)        /*!<Bit 0 */
#define  SAI_xCR1_PRTCFG_1                ((unsigned int)0x00000008)        /*!<Bit 1 */

#define  SAI_xCR1_DS                      ((unsigned int)0x000000E0)        /*!<DS[1:0] bits (Data Size) */
#define  SAI_xCR1_DS_0                    ((unsigned int)0x00000020)        /*!<Bit 0 */
#define  SAI_xCR1_DS_1                    ((unsigned int)0x00000040)        /*!<Bit 1 */
#define  SAI_xCR1_DS_2                    ((unsigned int)0x00000080)        /*!<Bit 2 */

#define  SAI_xCR1_LSBFIRST                ((unsigned int)0x00000100)        /*!<LSB First Configuration  */
#define  SAI_xCR1_CKSTR                   ((unsigned int)0x00000200)        /*!<ClocK STRobing edge      */

#define  SAI_xCR1_SYNCEN                  ((unsigned int)0x00000C00)        /*!<SYNCEN[1:0](SYNChronization ENable) */
#define  SAI_xCR1_SYNCEN_0                ((unsigned int)0x00000400)        /*!<Bit 0 */
#define  SAI_xCR1_SYNCEN_1                ((unsigned int)0x00000800)        /*!<Bit 1 */

#define  SAI_xCR1_MONO                    ((unsigned int)0x00001000)        /*!<Mono mode                  */
#define  SAI_xCR1_OUTDRIV                 ((unsigned int)0x00002000)        /*!<Output Drive               */
#define  SAI_xCR1_SAIEN                   ((unsigned int)0x00010000)        /*!<Audio Block enable         */
#define  SAI_xCR1_DMAEN                   ((unsigned int)0x00020000)        /*!<DMA enable                 */
#define  SAI_xCR1_NODIV                   ((unsigned int)0x00080000)        /*!<No Divider Configuration   */

#define  SAI_xCR1_MCKDIV                  ((unsigned int)0x00780000)        /*!<MCKDIV[3:0] (Master ClocK Divider)  */
#define  SAI_xCR1_MCKDIV_0                ((unsigned int)0x00080000)        /*!<Bit 0  */
#define  SAI_xCR1_MCKDIV_1                ((unsigned int)0x00100000)        /*!<Bit 1  */
#define  SAI_xCR1_MCKDIV_2                ((unsigned int)0x00200000)        /*!<Bit 2  */
#define  SAI_xCR1_MCKDIV_3                ((unsigned int)0x00400000)        /*!<Bit 3  */

/*******************  Bit definition for SAI_xCR2 register  *******************/
#define  SAI_xCR2_FTH                     ((unsigned int)0x00000003)        /*!<FTH[1:0](Fifo THreshold)  */
#define  SAI_xCR2_FTH_0                   ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  SAI_xCR2_FTH_1                   ((unsigned int)0x00000002)        /*!<Bit 1 */

#define  SAI_xCR2_FFLUSH                  ((unsigned int)0x00000008)        /*!<Fifo FLUSH                       */
#define  SAI_xCR2_TRIS                    ((unsigned int)0x00000010)        /*!<TRIState Management on data line */
#define  SAI_xCR2_MUTE                    ((unsigned int)0x00000020)        /*!<Mute mode                        */
#define  SAI_xCR2_MUTEVAL                 ((unsigned int)0x00000040)        /*!<Muate value                      */

#define  SAI_xCR2_MUTECNT                  ((unsigned int)0x00001F80)       /*!<MUTECNT[5:0] (MUTE counter) */
#define  SAI_xCR2_MUTECNT_0               ((unsigned int)0x00000080)        /*!<Bit 0 */
#define  SAI_xCR2_MUTECNT_1               ((unsigned int)0x00000100)        /*!<Bit 1 */
#define  SAI_xCR2_MUTECNT_2               ((unsigned int)0x00000200)        /*!<Bit 2 */
#define  SAI_xCR2_MUTECNT_3               ((unsigned int)0x00000400)        /*!<Bit 3 */
#define  SAI_xCR2_MUTECNT_4               ((unsigned int)0x00000800)        /*!<Bit 4 */
#define  SAI_xCR2_MUTECNT_5               ((unsigned int)0x00001000)        /*!<Bit 5 */

#define  SAI_xCR2_CPL                     ((unsigned int)0x00080000)        /*!< Complement Bit             */

#define  SAI_xCR2_COMP                    ((unsigned int)0x0000C000)        /*!<COMP[1:0] (Companding mode) */
#define  SAI_xCR2_COMP_0                  ((unsigned int)0x00004000)        /*!<Bit 0 */
#define  SAI_xCR2_COMP_1                  ((unsigned int)0x00008000)        /*!<Bit 1 */

/******************  Bit definition for SAI_xFRCR register  *******************/
#define  SAI_xFRCR_FRL                    ((unsigned int)0x000000FF)        /*!<FRL[1:0](Frame length)  */
#define  SAI_xFRCR_FRL_0                  ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  SAI_xFRCR_FRL_1                  ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  SAI_xFRCR_FRL_2                  ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  SAI_xFRCR_FRL_3                  ((unsigned int)0x00000008)        /*!<Bit 3 */
#define  SAI_xFRCR_FRL_4                  ((unsigned int)0x00000010)        /*!<Bit 4 */
#define  SAI_xFRCR_FRL_5                  ((unsigned int)0x00000020)        /*!<Bit 5 */
#define  SAI_xFRCR_FRL_6                  ((unsigned int)0x00000040)        /*!<Bit 6 */
#define  SAI_xFRCR_FRL_7                  ((unsigned int)0x00000080)        /*!<Bit 7 */

#define  SAI_xFRCR_FSALL                  ((unsigned int)0x00007F00)        /*!<FRL[1:0] (Frame synchronization active level length)  */
#define  SAI_xFRCR_FSALL_0                ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  SAI_xFRCR_FSALL_1                ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  SAI_xFRCR_FSALL_2                ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  SAI_xFRCR_FSALL_3                ((unsigned int)0x00000800)        /*!<Bit 3 */
#define  SAI_xFRCR_FSALL_4                ((unsigned int)0x00001000)        /*!<Bit 4 */
#define  SAI_xFRCR_FSALL_5                ((unsigned int)0x00002000)        /*!<Bit 5 */
#define  SAI_xFRCR_FSALL_6                ((unsigned int)0x00004000)        /*!<Bit 6 */

#define  SAI_xFRCR_FSDEF                  ((unsigned int)0x00010000)        /*!< Frame Synchronization Definition */
#define  SAI_xFRCR_FSPO                   ((unsigned int)0x00020000)        /*!<Frame Synchronization POLarity    */
#define  SAI_xFRCR_FSOFF                  ((unsigned int)0x00040000)        /*!<Frame Synchronization OFFset      */

/******************  Bit definition for SAI_xSLOTR register  *******************/
#define  SAI_xSLOTR_FBOFF                 ((unsigned int)0x0000001F)        /*!<FRL[4:0](First Bit Offset)  */
#define  SAI_xSLOTR_FBOFF_0               ((unsigned int)0x00000001)        /*!<Bit 0 */
#define  SAI_xSLOTR_FBOFF_1               ((unsigned int)0x00000002)        /*!<Bit 1 */
#define  SAI_xSLOTR_FBOFF_2               ((unsigned int)0x00000004)        /*!<Bit 2 */
#define  SAI_xSLOTR_FBOFF_3               ((unsigned int)0x00000008)        /*!<Bit 3 */
#define  SAI_xSLOTR_FBOFF_4               ((unsigned int)0x00000010)        /*!<Bit 4 */

#define  SAI_xSLOTR_SLOTSZ                ((unsigned int)0x000000C0)        /*!<SLOTSZ[1:0] (Slot size)  */
#define  SAI_xSLOTR_SLOTSZ_0              ((unsigned int)0x00000040)        /*!<Bit 0 */
#define  SAI_xSLOTR_SLOTSZ_1              ((unsigned int)0x00000080)        /*!<Bit 1 */

#define  SAI_xSLOTR_NBSLOT                ((unsigned int)0x00000F00)        /*!<NBSLOT[3:0] (Number of Slot in audio Frame)  */
#define  SAI_xSLOTR_NBSLOT_0              ((unsigned int)0x00000100)        /*!<Bit 0 */
#define  SAI_xSLOTR_NBSLOT_1              ((unsigned int)0x00000200)        /*!<Bit 1 */
#define  SAI_xSLOTR_NBSLOT_2              ((unsigned int)0x00000400)        /*!<Bit 2 */
#define  SAI_xSLOTR_NBSLOT_3              ((unsigned int)0x00000800)        /*!<Bit 3 */

#define  SAI_xSLOTR_SLOTEN                ((unsigned int)0xFFFF0000)        /*!<SLOTEN[15:0] (Slot Enable)  */

/*******************  Bit definition for SAI_xIMR register  *******************/
#define  SAI_xIMR_OVRUDRIE                ((unsigned int)0x00000001)        /*!<Overrun underrun interrupt enable                              */
#define  SAI_xIMR_MUTEDETIE               ((unsigned int)0x00000002)        /*!<Mute detection interrupt enable                                */
#define  SAI_xIMR_WCKCFGIE                ((unsigned int)0x00000004)        /*!<Wrong Clock Configuration interrupt enable                     */
#define  SAI_xIMR_FREQIE                  ((unsigned int)0x00000008)        /*!<FIFO request interrupt enable                                  */
#define  SAI_xIMR_CNRDYIE                 ((unsigned int)0x00000010)        /*!<Codec not ready interrupt enable                               */
#define  SAI_xIMR_AFSDETIE                ((unsigned int)0x00000020)        /*!<Anticipated frame synchronization detection interrupt enable   */
#define  SAI_xIMR_LFSDETIE                ((unsigned int)0x00000040)        /*!<Late frame synchronization detection interrupt enable          */

/********************  Bit definition for SAI_xSR register  *******************/
#define  SAI_xSR_OVRUDR                   ((unsigned int)0x00000001)         /*!<Overrun underrun                               */
#define  SAI_xSR_MUTEDET                  ((unsigned int)0x00000002)         /*!<Mute detection                                 */
#define  SAI_xSR_WCKCFG                   ((unsigned int)0x00000004)         /*!<Wrong Clock Configuration                      */
#define  SAI_xSR_FREQ                     ((unsigned int)0x00000008)         /*!<FIFO request                                   */
#define  SAI_xSR_CNRDY                    ((unsigned int)0x00000010)         /*!<Codec not ready                                */
#define  SAI_xSR_AFSDET                   ((unsigned int)0x00000020)         /*!<Anticipated frame synchronization detection    */
#define  SAI_xSR_LFSDET                   ((unsigned int)0x00000040)         /*!<Late frame synchronization detection           */

#define  SAI_xSR_FLVL                     ((unsigned int)0x00070000)         /*!<FLVL[2:0] (FIFO Level Threshold)               */
#define  SAI_xSR_FLVL_0                   ((unsigned int)0x00010000)         /*!<Bit 0 */
#define  SAI_xSR_FLVL_1                   ((unsigned int)0x00020000)         /*!<Bit 1 */
#define  SAI_xSR_FLVL_2                   ((unsigned int)0x00030000)         /*!<Bit 2 */

/******************  Bit definition for SAI_xCLRFR register  ******************/
#define  SAI_xCLRFR_COVRUDR               ((unsigned int)0x00000001)        /*!<Clear Overrun underrun                               */
#define  SAI_xCLRFR_CMUTEDET              ((unsigned int)0x00000002)        /*!<Clear Mute detection                                 */
#define  SAI_xCLRFR_CWCKCFG               ((unsigned int)0x00000004)        /*!<Clear Wrong Clock Configuration                      */
#define  SAI_xCLRFR_CFREQ                 ((unsigned int)0x00000008)        /*!<Clear FIFO request                                   */
#define  SAI_xCLRFR_CCNRDY                ((unsigned int)0x00000010)        /*!<Clear Codec not ready                                */
#define  SAI_xCLRFR_CAFSDET               ((unsigned int)0x00000020)        /*!<Clear Anticipated frame synchronization detection    */
#define  SAI_xCLRFR_CLFSDET               ((unsigned int)0x00000040)        /*!<Clear Late frame synchronization detection           */

/******************  Bit definition for SAI_xDR register  ******************/
#define  SAI_xDR_DATA                     ((unsigned int)0xFFFFFFFF)        

/******************************************************************************/
/*                                                                            */
/*                          SD host Interface                                 */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for SDIO_POWER register  ******************/
#define  SDIO_POWER_PWRCTRL                  ((unsigned char)0x03)               /*!<PWRCTRL[1:0] bits (Power supply control bits) */
#define  SDIO_POWER_PWRCTRL_0                ((unsigned char)0x01)               /*!<Bit 0 */
#define  SDIO_POWER_PWRCTRL_1                ((unsigned char)0x02)               /*!<Bit 1 */

/******************  Bit definition for SDIO_CLKCR register  ******************/
#define  SDIO_CLKCR_CLKDIV                   ((unsigned short)0x00FF)            /*!<Clock divide factor             */
#define  SDIO_CLKCR_CLKEN                    ((unsigned short)0x0100)            /*!<Clock enable bit                */
#define  SDIO_CLKCR_PWRSAV                   ((unsigned short)0x0200)            /*!<Power saving configuration bit  */
#define  SDIO_CLKCR_BYPASS                   ((unsigned short)0x0400)            /*!<Clock divider bypass enable bit */

#define  SDIO_CLKCR_WIDBUS                   ((unsigned short)0x1800)            /*!<WIDBUS[1:0] bits (Wide bus mode enable bit) */
#define  SDIO_CLKCR_WIDBUS_0                 ((unsigned short)0x0800)            /*!<Bit 0 */
#define  SDIO_CLKCR_WIDBUS_1                 ((unsigned short)0x1000)            /*!<Bit 1 */

#define  SDIO_CLKCR_NEGEDGE                  ((unsigned short)0x2000)            /*!<SDIO_CK dephasing selection bit */
#define  SDIO_CLKCR_HWFC_EN                  ((unsigned short)0x4000)            /*!<HW Flow Control enable          */

/*******************  Bit definition for SDIO_ARG register  *******************/
#define  SDIO_ARG_CMDARG                     ((unsigned int)0xFFFFFFFF)            /*!<Command argument */

/*******************  Bit definition for SDIO_CMD register  *******************/
#define  SDIO_CMD_CMDINDEX                   ((unsigned short)0x003F)            /*!<Command Index                               */

#define  SDIO_CMD_WAITRESP                   ((unsigned short)0x00C0)            /*!<WAITRESP[1:0] bits (Wait for response bits) */
#define  SDIO_CMD_WAITRESP_0                 ((unsigned short)0x0040)            /*!< Bit 0 */
#define  SDIO_CMD_WAITRESP_1                 ((unsigned short)0x0080)            /*!< Bit 1 */

#define  SDIO_CMD_WAITINT                    ((unsigned short)0x0100)            /*!<CPSM Waits for Interrupt Request                               */
#define  SDIO_CMD_WAITPEND                   ((unsigned short)0x0200)            /*!<CPSM Waits for ends of data transfer (CmdPend internal signal) */
#define  SDIO_CMD_CPSMEN                     ((unsigned short)0x0400)            /*!<Command path state machine (CPSM) Enable bit                   */
#define  SDIO_CMD_SDIOSUSPEND                ((unsigned short)0x0800)            /*!<SD I/O suspend command                                         */
#define  SDIO_CMD_ENCMDCOMPL                 ((unsigned short)0x1000)            /*!<Enable CMD completion                                          */
#define  SDIO_CMD_NIEN                       ((unsigned short)0x2000)            /*!<Not Interrupt Enable */
#define  SDIO_CMD_CEATACMD                   ((unsigned short)0x4000)            /*!<CE-ATA command       */

/*****************  Bit definition for SDIO_RESPCMD register  *****************/
#define  SDIO_RESPCMD_RESPCMD                ((unsigned char)0x3F)               /*!<Response command index */

/******************  Bit definition for SDIO_RESP0 register  ******************/
#define  SDIO_RESP0_CARDSTATUS0              ((unsigned int)0xFFFFFFFF)        /*!<Card Status */

/******************  Bit definition for SDIO_RESP1 register  ******************/
#define  SDIO_RESP1_CARDSTATUS1              ((unsigned int)0xFFFFFFFF)        /*!<Card Status */

/******************  Bit definition for SDIO_RESP2 register  ******************/
#define  SDIO_RESP2_CARDSTATUS2              ((unsigned int)0xFFFFFFFF)        /*!<Card Status */

/******************  Bit definition for SDIO_RESP3 register  ******************/
#define  SDIO_RESP3_CARDSTATUS3              ((unsigned int)0xFFFFFFFF)        /*!<Card Status */

/******************  Bit definition for SDIO_RESP4 register  ******************/
#define  SDIO_RESP4_CARDSTATUS4              ((unsigned int)0xFFFFFFFF)        /*!<Card Status */

/******************  Bit definition for SDIO_DTIMER register  *****************/
#define  SDIO_DTIMER_DATATIME                ((unsigned int)0xFFFFFFFF)        /*!<Data timeout period. */

/******************  Bit definition for SDIO_DLEN register  *******************/
#define  SDIO_DLEN_DATALENGTH                ((unsigned int)0x01FFFFFF)        /*!<Data length value    */

/******************  Bit definition for SDIO_DCTRL register  ******************/
#define  SDIO_DCTRL_DTEN                     ((unsigned short)0x0001)            /*!<Data transfer enabled bit         */
#define  SDIO_DCTRL_DTDIR                    ((unsigned short)0x0002)            /*!<Data transfer direction selection */
#define  SDIO_DCTRL_DTMODE                   ((unsigned short)0x0004)            /*!<Data transfer mode selection      */
#define  SDIO_DCTRL_DMAEN                    ((unsigned short)0x0008)            /*!<DMA enabled bit                   */

#define  SDIO_DCTRL_DBLOCKSIZE               ((unsigned short)0x00F0)            /*!<DBLOCKSIZE[3:0] bits (Data block size) */
#define  SDIO_DCTRL_DBLOCKSIZE_0             ((unsigned short)0x0010)            /*!<Bit 0 */
#define  SDIO_DCTRL_DBLOCKSIZE_1             ((unsigned short)0x0020)            /*!<Bit 1 */
#define  SDIO_DCTRL_DBLOCKSIZE_2             ((unsigned short)0x0040)            /*!<Bit 2 */
#define  SDIO_DCTRL_DBLOCKSIZE_3             ((unsigned short)0x0080)            /*!<Bit 3 */

#define  SDIO_DCTRL_RWSTART                  ((unsigned short)0x0100)            /*!<Read wait start         */
#define  SDIO_DCTRL_RWSTOP                   ((unsigned short)0x0200)            /*!<Read wait stop          */
#define  SDIO_DCTRL_RWMOD                    ((unsigned short)0x0400)            /*!<Read wait mode          */
#define  SDIO_DCTRL_SDIOEN                   ((unsigned short)0x0800)            /*!<SD I/O enable functions */

/******************  Bit definition for SDIO_DCOUNT register  *****************/
#define  SDIO_DCOUNT_DATACOUNT               ((unsigned int)0x01FFFFFF)        /*!<Data count value */

/******************  Bit definition for SDIO_STA register  ********************/
#define  SDIO_STA_CCRCFAIL                   ((unsigned int)0x00000001)        /*!<Command response received (CRC check failed)  */
#define  SDIO_STA_DCRCFAIL                   ((unsigned int)0x00000002)        /*!<Data block sent/received (CRC check failed)   */
#define  SDIO_STA_CTIMEOUT                   ((unsigned int)0x00000004)        /*!<Command response timeout                      */
#define  SDIO_STA_DTIMEOUT                   ((unsigned int)0x00000008)        /*!<Data timeout                                  */
#define  SDIO_STA_TXUNDERR                   ((unsigned int)0x00000010)        /*!<Transmit FIFO underrun error                  */
#define  SDIO_STA_RXOVERR                    ((unsigned int)0x00000020)        /*!<Received FIFO overrun error                   */
#define  SDIO_STA_CMDREND                    ((unsigned int)0x00000040)        /*!<Command response received (CRC check passed)  */
#define  SDIO_STA_CMDSENT                    ((unsigned int)0x00000080)        /*!<Command sent (no response required)           */
#define  SDIO_STA_DATAEND                    ((unsigned int)0x00000100)        /*!<Data end (data counter, SDIDCOUNT, is zero)   */
#define  SDIO_STA_STBITERR                   ((unsigned int)0x00000200)        /*!<Start bit not detected on all data signals in wide bus mode */
#define  SDIO_STA_DBCKEND                    ((unsigned int)0x00000400)        /*!<Data block sent/received (CRC check passed)   */
#define  SDIO_STA_CMDACT                     ((unsigned int)0x00000800)        /*!<Command transfer in progress                  */
#define  SDIO_STA_TXACT                      ((unsigned int)0x00001000)        /*!<Data transmit in progress                     */
#define  SDIO_STA_RXACT                      ((unsigned int)0x00002000)        /*!<Data receive in progress                      */
#define  SDIO_STA_TXFIFOHE                   ((unsigned int)0x00004000)        /*!<Transmit FIFO Half Empty: at least 8 words can be written into the FIFO */
#define  SDIO_STA_RXFIFOHF                   ((unsigned int)0x00008000)        /*!<Receive FIFO Half Full: there are at least 8 words in the FIFO */
#define  SDIO_STA_TXFIFOF                    ((unsigned int)0x00010000)        /*!<Transmit FIFO full                            */
#define  SDIO_STA_RXFIFOF                    ((unsigned int)0x00020000)        /*!<Receive FIFO full                             */
#define  SDIO_STA_TXFIFOE                    ((unsigned int)0x00040000)        /*!<Transmit FIFO empty                           */
#define  SDIO_STA_RXFIFOE                    ((unsigned int)0x00080000)        /*!<Receive FIFO empty                            */
#define  SDIO_STA_TXDAVL                     ((unsigned int)0x00100000)        /*!<Data available in transmit FIFO               */
#define  SDIO_STA_RXDAVL                     ((unsigned int)0x00200000)        /*!<Data available in receive FIFO                */
#define  SDIO_STA_SDIOIT                     ((unsigned int)0x00400000)        /*!<SDIO interrupt received                       */
#define  SDIO_STA_CEATAEND                   ((unsigned int)0x00800000)        /*!<CE-ATA command completion signal received for CMD61 */

/*******************  Bit definition for SDIO_ICR register  *******************/
#define  SDIO_ICR_CCRCFAILC                  ((unsigned int)0x00000001)        /*!<CCRCFAIL flag clear bit */
#define  SDIO_ICR_DCRCFAILC                  ((unsigned int)0x00000002)        /*!<DCRCFAIL flag clear bit */
#define  SDIO_ICR_CTIMEOUTC                  ((unsigned int)0x00000004)        /*!<CTIMEOUT flag clear bit */
#define  SDIO_ICR_DTIMEOUTC                  ((unsigned int)0x00000008)        /*!<DTIMEOUT flag clear bit */
#define  SDIO_ICR_TXUNDERRC                  ((unsigned int)0x00000010)        /*!<TXUNDERR flag clear bit */
#define  SDIO_ICR_RXOVERRC                   ((unsigned int)0x00000020)        /*!<RXOVERR flag clear bit  */
#define  SDIO_ICR_CMDRENDC                   ((unsigned int)0x00000040)        /*!<CMDREND flag clear bit  */
#define  SDIO_ICR_CMDSENTC                   ((unsigned int)0x00000080)        /*!<CMDSENT flag clear bit  */
#define  SDIO_ICR_DATAENDC                   ((unsigned int)0x00000100)        /*!<DATAEND flag clear bit  */
#define  SDIO_ICR_STBITERRC                  ((unsigned int)0x00000200)        /*!<STBITERR flag clear bit */
#define  SDIO_ICR_DBCKENDC                   ((unsigned int)0x00000400)        /*!<DBCKEND flag clear bit  */
#define  SDIO_ICR_SDIOITC                    ((unsigned int)0x00400000)        /*!<SDIOIT flag clear bit   */
#define  SDIO_ICR_CEATAENDC                  ((unsigned int)0x00800000)        /*!<CEATAEND flag clear bit */

/******************  Bit definition for SDIO_MASK register  *******************/
#define  SDIO_MASK_CCRCFAILIE                ((unsigned int)0x00000001)        /*!<Command CRC Fail Interrupt Enable          */
#define  SDIO_MASK_DCRCFAILIE                ((unsigned int)0x00000002)        /*!<Data CRC Fail Interrupt Enable             */
#define  SDIO_MASK_CTIMEOUTIE                ((unsigned int)0x00000004)        /*!<Command TimeOut Interrupt Enable           */
#define  SDIO_MASK_DTIMEOUTIE                ((unsigned int)0x00000008)        /*!<Data TimeOut Interrupt Enable              */
#define  SDIO_MASK_TXUNDERRIE                ((unsigned int)0x00000010)        /*!<Tx FIFO UnderRun Error Interrupt Enable    */
#define  SDIO_MASK_RXOVERRIE                 ((unsigned int)0x00000020)        /*!<Rx FIFO OverRun Error Interrupt Enable     */
#define  SDIO_MASK_CMDRENDIE                 ((unsigned int)0x00000040)        /*!<Command Response Received Interrupt Enable */
#define  SDIO_MASK_CMDSENTIE                 ((unsigned int)0x00000080)        /*!<Command Sent Interrupt Enable              */
#define  SDIO_MASK_DATAENDIE                 ((unsigned int)0x00000100)        /*!<Data End Interrupt Enable                  */
#define  SDIO_MASK_STBITERRIE                ((unsigned int)0x00000200)        /*!<Start Bit Error Interrupt Enable           */
#define  SDIO_MASK_DBCKENDIE                 ((unsigned int)0x00000400)        /*!<Data Block End Interrupt Enable            */
#define  SDIO_MASK_CMDACTIE                  ((unsigned int)0x00000800)        /*!<CCommand Acting Interrupt Enable           */
#define  SDIO_MASK_TXACTIE                   ((unsigned int)0x00001000)        /*!<Data Transmit Acting Interrupt Enable      */
#define  SDIO_MASK_RXACTIE                   ((unsigned int)0x00002000)        /*!<Data receive acting interrupt enabled      */
#define  SDIO_MASK_TXFIFOHEIE                ((unsigned int)0x00004000)        /*!<Tx FIFO Half Empty interrupt Enable        */
#define  SDIO_MASK_RXFIFOHFIE                ((unsigned int)0x00008000)        /*!<Rx FIFO Half Full interrupt Enable         */
#define  SDIO_MASK_TXFIFOFIE                 ((unsigned int)0x00010000)        /*!<Tx FIFO Full interrupt Enable              */
#define  SDIO_MASK_RXFIFOFIE                 ((unsigned int)0x00020000)        /*!<Rx FIFO Full interrupt Enable              */
#define  SDIO_MASK_TXFIFOEIE                 ((unsigned int)0x00040000)        /*!<Tx FIFO Empty interrupt Enable             */
#define  SDIO_MASK_RXFIFOEIE                 ((unsigned int)0x00080000)        /*!<Rx FIFO Empty interrupt Enable             */
#define  SDIO_MASK_TXDAVLIE                  ((unsigned int)0x00100000)        /*!<Data available in Tx FIFO interrupt Enable */
#define  SDIO_MASK_RXDAVLIE                  ((unsigned int)0x00200000)        /*!<Data available in Rx FIFO interrupt Enable */
#define  SDIO_MASK_SDIOITIE                  ((unsigned int)0x00400000)        /*!<SDIO Mode Interrupt Received interrupt Enable */
#define  SDIO_MASK_CEATAENDIE                ((unsigned int)0x00800000)        /*!<CE-ATA command completion signal received Interrupt Enable */

/*****************  Bit definition for SDIO_FIFOCNT register  *****************/
#define  SDIO_FIFOCNT_FIFOCOUNT              ((unsigned int)0x00FFFFFF)        /*!<Remaining number of words to be written to or read from the FIFO */

/******************  Bit definition for SDIO_FIFO register  *******************/
#define  SDIO_FIFO_FIFODATA                  ((unsigned int)0xFFFFFFFF)        /*!<Receive and transmit FIFO data */

/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface                         */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for SPI_CR1 register  ********************/
#define  SPI_CR1_CPHA                        ((unsigned short)0x0001)            /*!<Clock Phase      */
#define  SPI_CR1_CPOL                        ((unsigned short)0x0002)            /*!<Clock Polarity   */
#define  SPI_CR1_MSTR                        ((unsigned short)0x0004)            /*!<Master Selection */

#define  SPI_CR1_BR                          ((unsigned short)0x0038)            /*!<BR[2:0] bits (Baud Rate Control) */
#define  SPI_CR1_BR_0                        ((unsigned short)0x0008)            /*!<Bit 0 */
#define  SPI_CR1_BR_1                        ((unsigned short)0x0010)            /*!<Bit 1 */
#define  SPI_CR1_BR_2                        ((unsigned short)0x0020)            /*!<Bit 2 */

#define  SPI_CR1_SPE                         ((unsigned short)0x0040)            /*!<SPI Enable                          */
#define  SPI_CR1_LSBFIRST                    ((unsigned short)0x0080)            /*!<Frame Format                        */
#define  SPI_CR1_SSI                         ((unsigned short)0x0100)            /*!<Internal slave select               */
#define  SPI_CR1_SSM                         ((unsigned short)0x0200)            /*!<Software slave management           */
#define  SPI_CR1_RXONLY                      ((unsigned short)0x0400)            /*!<Receive only                        */
#define  SPI_CR1_DFF                         ((unsigned short)0x0800)            /*!<Data Frame Format                   */
#define  SPI_CR1_CRCNEXT                     ((unsigned short)0x1000)            /*!<Transmit CRC next                   */
#define  SPI_CR1_CRCEN                       ((unsigned short)0x2000)            /*!<Hardware CRC calculation enable     */
#define  SPI_CR1_BIDIOE                      ((unsigned short)0x4000)            /*!<Output enable in bidirectional mode */
#define  SPI_CR1_BIDIMODE                    ((unsigned short)0x8000)            /*!<Bidirectional data mode enable      */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define  SPI_CR2_RXDMAEN                     ((unsigned char)0x01)               /*!<Rx Buffer DMA Enable                 */
#define  SPI_CR2_TXDMAEN                     ((unsigned char)0x02)               /*!<Tx Buffer DMA Enable                 */
#define  SPI_CR2_SSOE                        ((unsigned char)0x04)               /*!<SS Output Enable                     */
#define  SPI_CR2_ERRIE                       ((unsigned char)0x20)               /*!<Error Interrupt Enable               */
#define  SPI_CR2_RXNEIE                      ((unsigned char)0x40)               /*!<RX buffer Not Empty Interrupt Enable */
#define  SPI_CR2_TXEIE                       ((unsigned char)0x80)               /*!<Tx buffer Empty Interrupt Enable     */

/********************  Bit definition for SPI_SR register  ********************/
#define  SPI_SR_RXNE                         ((unsigned char)0x01)               /*!<Receive buffer Not Empty */
#define  SPI_SR_TXE                          ((unsigned char)0x02)               /*!<Transmit buffer Empty    */
#define  SPI_SR_CHSIDE                       ((unsigned char)0x04)               /*!<Channel side             */
#define  SPI_SR_UDR                          ((unsigned char)0x08)               /*!<Underrun flag            */
#define  SPI_SR_CRCERR                       ((unsigned char)0x10)               /*!<CRC Error flag           */
#define  SPI_SR_MODF                         ((unsigned char)0x20)               /*!<Mode fault               */
#define  SPI_SR_OVR                          ((unsigned char)0x40)               /*!<Overrun flag             */
#define  SPI_SR_BSY                          ((unsigned char)0x80)               /*!<Busy flag                */

/********************  Bit definition for SPI_DR register  ********************/
#define  SPI_DR_DR                           ((unsigned short)0xFFFF)            /*!<Data Register           */

/*******************  Bit definition for SPI_CRCPR register  ******************/
#define  SPI_CRCPR_CRCPOLY                   ((unsigned short)0xFFFF)            /*!<CRC polynomial register */

/******************  Bit definition for SPI_RXCRCR register  ******************/
#define  SPI_RXCRCR_RXCRC                    ((unsigned short)0xFFFF)            /*!<Rx CRC Register         */

/******************  Bit definition for SPI_TXCRCR register  ******************/
#define  SPI_TXCRCR_TXCRC                    ((unsigned short)0xFFFF)            /*!<Tx CRC Register         */

/******************  Bit definition for SPI_I2SCFGR register  *****************/
#define  SPI_I2SCFGR_CHLEN                   ((unsigned short)0x0001)            /*!<Channel length (number of bits per audio channel) */

#define  SPI_I2SCFGR_DATLEN                  ((unsigned short)0x0006)            /*!<DATLEN[1:0] bits (Data length to be transferred)  */
#define  SPI_I2SCFGR_DATLEN_0                ((unsigned short)0x0002)            /*!<Bit 0 */
#define  SPI_I2SCFGR_DATLEN_1                ((unsigned short)0x0004)            /*!<Bit 1 */

#define  SPI_I2SCFGR_CKPOL                   ((unsigned short)0x0008)            /*!<steady state clock polarity               */

#define  SPI_I2SCFGR_I2SSTD                  ((unsigned short)0x0030)            /*!<I2SSTD[1:0] bits (I2S standard selection) */
#define  SPI_I2SCFGR_I2SSTD_0                ((unsigned short)0x0010)            /*!<Bit 0 */
#define  SPI_I2SCFGR_I2SSTD_1                ((unsigned short)0x0020)            /*!<Bit 1 */

#define  SPI_I2SCFGR_PCMSYNC                 ((unsigned short)0x0080)            /*!<PCM frame synchronization                 */

#define  SPI_I2SCFGR_I2SCFG                  ((unsigned short)0x0300)            /*!<I2SCFG[1:0] bits (I2S configuration mode) */
#define  SPI_I2SCFGR_I2SCFG_0                ((unsigned short)0x0100)            /*!<Bit 0 */
#define  SPI_I2SCFGR_I2SCFG_1                ((unsigned short)0x0200)            /*!<Bit 1 */

#define  SPI_I2SCFGR_I2SE                    ((unsigned short)0x0400)            /*!<I2S Enable         */
#define  SPI_I2SCFGR_I2SMOD                  ((unsigned short)0x0800)            /*!<I2S mode selection */

/******************  Bit definition for SPI_I2SPR register  *******************/
#define  SPI_I2SPR_I2SDIV                    ((unsigned short)0x00FF)            /*!<I2S Linear prescaler         */
#define  SPI_I2SPR_ODD                       ((unsigned short)0x0100)            /*!<Odd factor for the prescaler */
#define  SPI_I2SPR_MCKOE                     ((unsigned short)0x0200)            /*!<Master Clock Output Enable   */

/******************************************************************************/
/*                                                                            */
/*                                 SYSCFG                                     */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for SYSCFG_MEMRMP register  ***************/  
#define SYSCFG_MEMRMP_MEM_MODE          ((unsigned int)0x00000007) /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_MEMRMP_MEM_MODE_0        ((unsigned int)0x00000001) /*!<Bit 0 */
#define SYSCFG_MEMRMP_MEM_MODE_1        ((unsigned int)0x00000002) /*!<Bit 1 */
#define SYSCFG_MEMRMP_MEM_MODE_2        ((unsigned int)0x00000004) /*!<Bit 2 */

#define SYSCFG_MEMRMP_FB_MODE           ((unsigned int)0x00000100) /*!< User Flash Bank mode */

#define SYSCFG_MEMRMP_SWP_FMC           ((unsigned int)0x00000C00) /*!< FMC memory mapping swap */
#define SYSCFG_MEMRMP_SWP_FMC_0         ((unsigned int)0x00000400) /*!<Bit 0 */
#define SYSCFG_MEMRMP_SWP_FMC_1         ((unsigned int)0x00000800) /*!<Bit 1 */


/******************  Bit definition for SYSCFG_PMC register  ******************/
#define SYSCFG_PMC_ADCxDC2              ((unsigned int)0x00070000) /*!< Refer to AN4073 on how to use this bit  */
#define SYSCFG_PMC_ADC1DC2              ((unsigned int)0x00010000) /*!< Refer to AN4073 on how to use this bit  */
#define SYSCFG_PMC_ADC2DC2              ((unsigned int)0x00020000) /*!< Refer to AN4073 on how to use this bit  */
#define SYSCFG_PMC_ADC3DC2              ((unsigned int)0x00040000) /*!< Refer to AN4073 on how to use this bit  */

#define SYSCFG_PMC_MII_RMII_SEL         ((unsigned int)0x00800000) /*!<Ethernet PHY interface selection */
/* Old MII_RMII_SEL bit definition, maintained for legacy purpose */
#define SYSCFG_PMC_MII_RMII             SYSCFG_PMC_MII_RMII_SEL

/*****************  Bit definition for SYSCFG_EXTICR1 register  ***************/
#define SYSCFG_EXTICR1_EXTI0            ((unsigned short)0x000F) /*!<EXTI 0 configuration */
#define SYSCFG_EXTICR1_EXTI1            ((unsigned short)0x00F0) /*!<EXTI 1 configuration */
#define SYSCFG_EXTICR1_EXTI2            ((unsigned short)0x0F00) /*!<EXTI 2 configuration */
#define SYSCFG_EXTICR1_EXTI3            ((unsigned short)0xF000) /*!<EXTI 3 configuration */
/** 
 * @brief   EXTI0 configuration  
 */ 
#define SYSCFG_EXTICR1_EXTI0_PA         ((unsigned short)0x0000) /*!<PA[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PB         ((unsigned short)0x0001) /*!<PB[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PC         ((unsigned short)0x0002) /*!<PC[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PD         ((unsigned short)0x0003) /*!<PD[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PE         ((unsigned short)0x0004) /*!<PE[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PF         ((unsigned short)0x0005) /*!<PF[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PG         ((unsigned short)0x0006) /*!<PG[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PH         ((unsigned short)0x0007) /*!<PH[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PI         ((unsigned short)0x0008) /*!<PI[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PJ         ((unsigned short)0x0009) /*!<PJ[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PK         ((unsigned short)0x000A) /*!<PK[0] pin */

/** 
 * @brief   EXTI1 configuration  
 */ 
#define SYSCFG_EXTICR1_EXTI1_PA         ((unsigned short)0x0000) /*!<PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB         ((unsigned short)0x0010) /*!<PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC         ((unsigned short)0x0020) /*!<PC[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PD         ((unsigned short)0x0030) /*!<PD[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PE         ((unsigned short)0x0040) /*!<PE[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PF         ((unsigned short)0x0050) /*!<PF[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PG         ((unsigned short)0x0060) /*!<PG[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PH         ((unsigned short)0x0070) /*!<PH[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PI         ((unsigned short)0x0080) /*!<PI[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PJ         ((unsigned short)0x0090) /*!<PJ[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PK         ((unsigned short)0x00A0) /*!<PK[1] pin */

/** 
 * @brief   EXTI2 configuration  
 */ 
#define SYSCFG_EXTICR1_EXTI2_PA         ((unsigned short)0x0000) /*!<PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB         ((unsigned short)0x0100) /*!<PB[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PC         ((unsigned short)0x0200) /*!<PC[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PD         ((unsigned short)0x0300) /*!<PD[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PE         ((unsigned short)0x0400) /*!<PE[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PF         ((unsigned short)0x0500) /*!<PF[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PG         ((unsigned short)0x0600) /*!<PG[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PH         ((unsigned short)0x0700) /*!<PH[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PI         ((unsigned short)0x0800) /*!<PI[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PJ         ((unsigned short)0x0900) /*!<PJ[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PK         ((unsigned short)0x0A00) /*!<PK[2] pin */

/** 
 * @brief   EXTI3 configuration  
 */ 
#define SYSCFG_EXTICR1_EXTI3_PA         ((unsigned short)0x0000) /*!<PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB         ((unsigned short)0x1000) /*!<PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PC         ((unsigned short)0x2000) /*!<PC[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PD         ((unsigned short)0x3000) /*!<PD[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PE         ((unsigned short)0x4000) /*!<PE[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PF         ((unsigned short)0x5000) /*!<PF[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PG         ((unsigned short)0x6000) /*!<PG[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PH         ((unsigned short)0x7000) /*!<PH[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PI         ((unsigned short)0x8000) /*!<PI[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PJ         ((unsigned short)0x9000) /*!<PJ[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PK         ((unsigned short)0xA000) /*!<PK[3] pin */

/*****************  Bit definition for SYSCFG_EXTICR2 register  ***************/
#define SYSCFG_EXTICR2_EXTI4            ((unsigned short)0x000F) /*!<EXTI 4 configuration */
#define SYSCFG_EXTICR2_EXTI5            ((unsigned short)0x00F0) /*!<EXTI 5 configuration */
#define SYSCFG_EXTICR2_EXTI6            ((unsigned short)0x0F00) /*!<EXTI 6 configuration */
#define SYSCFG_EXTICR2_EXTI7            ((unsigned short)0xF000) /*!<EXTI 7 configuration */
/** 
 * @brief   EXTI4 configuration  
 */ 
#define SYSCFG_EXTICR2_EXTI4_PA         ((unsigned short)0x0000) /*!<PA[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PB         ((unsigned short)0x0001) /*!<PB[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PC         ((unsigned short)0x0002) /*!<PC[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PD         ((unsigned short)0x0003) /*!<PD[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PE         ((unsigned short)0x0004) /*!<PE[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PF         ((unsigned short)0x0005) /*!<PF[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PG         ((unsigned short)0x0006) /*!<PG[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PH         ((unsigned short)0x0007) /*!<PH[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PI         ((unsigned short)0x0008) /*!<PI[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PJ         ((unsigned short)0x0009) /*!<PJ[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PK         ((unsigned short)0x000A) /*!<PK[4] pin */

/** 
 * @brief   EXTI5 configuration  
 */ 
#define SYSCFG_EXTICR2_EXTI5_PA         ((unsigned short)0x0000) /*!<PA[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PB         ((unsigned short)0x0010) /*!<PB[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PC         ((unsigned short)0x0020) /*!<PC[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PD         ((unsigned short)0x0030) /*!<PD[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PE         ((unsigned short)0x0040) /*!<PE[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PF         ((unsigned short)0x0050) /*!<PF[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PG         ((unsigned short)0x0060) /*!<PG[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PH         ((unsigned short)0x0070) /*!<PH[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PI         ((unsigned short)0x0080) /*!<PI[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PJ         ((unsigned short)0x0090) /*!<PJ[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PK         ((unsigned short)0x00A0) /*!<PK[5] pin */

/** 
 * @brief   EXTI6 configuration  
 */ 
#define SYSCFG_EXTICR2_EXTI6_PA         ((unsigned short)0x0000) /*!<PA[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PB         ((unsigned short)0x0100) /*!<PB[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PC         ((unsigned short)0x0200) /*!<PC[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PD         ((unsigned short)0x0300) /*!<PD[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PE         ((unsigned short)0x0400) /*!<PE[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PF         ((unsigned short)0x0500) /*!<PF[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PG         ((unsigned short)0x0600) /*!<PG[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PH         ((unsigned short)0x0700) /*!<PH[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PI         ((unsigned short)0x0800) /*!<PI[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PJ         ((unsigned short)0x0900) /*!<PJ[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PK         ((unsigned short)0x0A00) /*!<PK[6] pin */

/** 
 * @brief   EXTI7 configuration  
 */ 
#define SYSCFG_EXTICR2_EXTI7_PA         ((unsigned short)0x0000) /*!<PA[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PB         ((unsigned short)0x1000) /*!<PB[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PC         ((unsigned short)0x2000) /*!<PC[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PD         ((unsigned short)0x3000) /*!<PD[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PE         ((unsigned short)0x4000) /*!<PE[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PF         ((unsigned short)0x5000) /*!<PF[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PG         ((unsigned short)0x6000) /*!<PG[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PH         ((unsigned short)0x7000) /*!<PH[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PI         ((unsigned short)0x8000) /*!<PI[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PJ         ((unsigned short)0x9000) /*!<PJ[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PK         ((unsigned short)0xA000) /*!<PK[7] pin */

/*****************  Bit definition for SYSCFG_EXTICR3 register  ***************/
#define SYSCFG_EXTICR3_EXTI8            ((unsigned short)0x000F) /*!<EXTI 8 configuration */
#define SYSCFG_EXTICR3_EXTI9            ((unsigned short)0x00F0) /*!<EXTI 9 configuration */
#define SYSCFG_EXTICR3_EXTI10           ((unsigned short)0x0F00) /*!<EXTI 10 configuration */
#define SYSCFG_EXTICR3_EXTI11           ((unsigned short)0xF000) /*!<EXTI 11 configuration */

/** 
 * @brief   EXTI8 configuration  
 */ 
#define SYSCFG_EXTICR3_EXTI8_PA         ((unsigned short)0x0000) /*!<PA[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PB         ((unsigned short)0x0001) /*!<PB[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PC         ((unsigned short)0x0002) /*!<PC[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PD         ((unsigned short)0x0003) /*!<PD[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PE         ((unsigned short)0x0004) /*!<PE[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PF         ((unsigned short)0x0005) /*!<PF[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PG         ((unsigned short)0x0006) /*!<PG[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PH         ((unsigned short)0x0007) /*!<PH[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PI         ((unsigned short)0x0008) /*!<PI[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PJ         ((unsigned short)0x0009) /*!<PJ[8] pin */

/** 
 * @brief   EXTI9 configuration  
 */ 
#define SYSCFG_EXTICR3_EXTI9_PA         ((unsigned short)0x0000) /*!<PA[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PB         ((unsigned short)0x0010) /*!<PB[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PC         ((unsigned short)0x0020) /*!<PC[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PD         ((unsigned short)0x0030) /*!<PD[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PE         ((unsigned short)0x0040) /*!<PE[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PF         ((unsigned short)0x0050) /*!<PF[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PG         ((unsigned short)0x0060) /*!<PG[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PH         ((unsigned short)0x0070) /*!<PH[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PI         ((unsigned short)0x0080) /*!<PI[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PJ         ((unsigned short)0x0090) /*!<PJ[9] pin */

/** 
 * @brief   EXTI10 configuration  
 */ 
#define SYSCFG_EXTICR3_EXTI10_PA        ((unsigned short)0x0000) /*!<PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB        ((unsigned short)0x0100) /*!<PB[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PC        ((unsigned short)0x0200) /*!<PC[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PD        ((unsigned short)0x0300) /*!<PD[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PE        ((unsigned short)0x0400) /*!<PE[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PF        ((unsigned short)0x0500) /*!<PF[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PG        ((unsigned short)0x0600) /*!<PG[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PH        ((unsigned short)0x0700) /*!<PH[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PI        ((unsigned short)0x0800) /*!<PI[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PJ        ((unsigned short)0x0900) /*!<PJ[10] pin */

/** 
 * @brief   EXTI11 configuration  
 */ 
#define SYSCFG_EXTICR3_EXTI11_PA        ((unsigned short)0x0000) /*!<PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB        ((unsigned short)0x1000) /*!<PB[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PC        ((unsigned short)0x2000) /*!<PC[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PD        ((unsigned short)0x3000) /*!<PD[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PE        ((unsigned short)0x4000) /*!<PE[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PF        ((unsigned short)0x5000) /*!<PF[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PG        ((unsigned short)0x6000) /*!<PG[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PH        ((unsigned short)0x7000) /*!<PH[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PI        ((unsigned short)0x8000) /*!<PI[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PJ        ((unsigned short)0x9000) /*!<PJ[11] pin */

/*****************  Bit definition for SYSCFG_EXTICR4 register  ***************/
#define SYSCFG_EXTICR4_EXTI12           ((unsigned short)0x000F) /*!<EXTI 12 configuration */
#define SYSCFG_EXTICR4_EXTI13           ((unsigned short)0x00F0) /*!<EXTI 13 configuration */
#define SYSCFG_EXTICR4_EXTI14           ((unsigned short)0x0F00) /*!<EXTI 14 configuration */
#define SYSCFG_EXTICR4_EXTI15           ((unsigned short)0xF000) /*!<EXTI 15 configuration */
/** 
 * @brief   EXTI12 configuration  
 */ 
#define SYSCFG_EXTICR4_EXTI12_PA        ((unsigned short)0x0000) /*!<PA[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PB        ((unsigned short)0x0001) /*!<PB[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PC        ((unsigned short)0x0002) /*!<PC[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PD        ((unsigned short)0x0003) /*!<PD[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PE        ((unsigned short)0x0004) /*!<PE[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PF        ((unsigned short)0x0005) /*!<PF[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PG        ((unsigned short)0x0006) /*!<PG[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PH        ((unsigned short)0x0007) /*!<PH[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PI        ((unsigned short)0x0008) /*!<PI[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PJ        ((unsigned short)0x0009) /*!<PJ[12] pin */

/** 
 * @brief   EXTI13 configuration  
 */ 
#define SYSCFG_EXTICR4_EXTI13_PA        ((unsigned short)0x0000) /*!<PA[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PB        ((unsigned short)0x0010) /*!<PB[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PC        ((unsigned short)0x0020) /*!<PC[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PD        ((unsigned short)0x0030) /*!<PD[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PE        ((unsigned short)0x0040) /*!<PE[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PF        ((unsigned short)0x0050) /*!<PF[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PG        ((unsigned short)0x0060) /*!<PG[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PH        ((unsigned short)0x0070) /*!<PH[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PI        ((unsigned short)0x0008) /*!<PI[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PJ        ((unsigned short)0x0009) /*!<PJ[13] pin */

/** 
 * @brief   EXTI14 configuration  
 */ 
#define SYSCFG_EXTICR4_EXTI14_PA        ((unsigned short)0x0000) /*!<PA[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PB        ((unsigned short)0x0100) /*!<PB[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PC        ((unsigned short)0x0200) /*!<PC[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PD        ((unsigned short)0x0300) /*!<PD[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PE        ((unsigned short)0x0400) /*!<PE[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PF        ((unsigned short)0x0500) /*!<PF[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PG        ((unsigned short)0x0600) /*!<PG[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PH        ((unsigned short)0x0700) /*!<PH[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PI        ((unsigned short)0x0800) /*!<PI[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PJ        ((unsigned short)0x0900) /*!<PJ[14] pin */

/** 
 * @brief   EXTI15 configuration  
 */ 
#define SYSCFG_EXTICR4_EXTI15_PA        ((unsigned short)0x0000) /*!<PA[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PB        ((unsigned short)0x1000) /*!<PB[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PC        ((unsigned short)0x2000) /*!<PC[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PD        ((unsigned short)0x3000) /*!<PD[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PE        ((unsigned short)0x4000) /*!<PE[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PF        ((unsigned short)0x5000) /*!<PF[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PG        ((unsigned short)0x6000) /*!<PG[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PH        ((unsigned short)0x7000) /*!<PH[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PI        ((unsigned short)0x8000) /*!<PI[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PJ        ((unsigned short)0x9000) /*!<PJ[15] pin */

/******************  Bit definition for SYSCFG_CMPCR register  ****************/  
#define SYSCFG_CMPCR_CMP_PD             ((unsigned int)0x00000001) /*!<Compensation cell ready flag */
#define SYSCFG_CMPCR_READY              ((unsigned int)0x00000100) /*!<Compensation cell power-down */

/******************************************************************************/
/*                                                                            */
/*                                    TIM                                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TIM_CR1 register  ********************/
#define  TIM_CR1_CEN                         ((unsigned short)0x0001)            /*!<Counter enable        */
#define  TIM_CR1_UDIS                        ((unsigned short)0x0002)            /*!<Update disable        */
#define  TIM_CR1_URS                         ((unsigned short)0x0004)            /*!<Update request source */
#define  TIM_CR1_OPM                         ((unsigned short)0x0008)            /*!<One pulse mode        */
#define  TIM_CR1_DIR                         ((unsigned short)0x0010)            /*!<Direction             */

#define  TIM_CR1_CMS                         ((unsigned short)0x0060)            /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define  TIM_CR1_CMS_0                       ((unsigned short)0x0020)            /*!<Bit 0 */
#define  TIM_CR1_CMS_1                       ((unsigned short)0x0040)            /*!<Bit 1 */

#define  TIM_CR1_ARPE                        ((unsigned short)0x0080)            /*!<Auto-reload preload enable     */

#define  TIM_CR1_CKD                         ((unsigned short)0x0300)            /*!<CKD[1:0] bits (clock division) */
#define  TIM_CR1_CKD_0                       ((unsigned short)0x0100)            /*!<Bit 0 */
#define  TIM_CR1_CKD_1                       ((unsigned short)0x0200)            /*!<Bit 1 */

/*******************  Bit definition for TIM_CR2 register  ********************/
#define  TIM_CR2_CCPC                        ((unsigned short)0x0001)            /*!<Capture/Compare Preloaded Control        */
#define  TIM_CR2_CCUS                        ((unsigned short)0x0004)            /*!<Capture/Compare Control Update Selection */
#define  TIM_CR2_CCDS                        ((unsigned short)0x0008)            /*!<Capture/Compare DMA Selection            */

#define  TIM_CR2_MMS                         ((unsigned short)0x0070)            /*!<MMS[2:0] bits (Master Mode Selection) */
#define  TIM_CR2_MMS_0                       ((unsigned short)0x0010)            /*!<Bit 0 */
#define  TIM_CR2_MMS_1                       ((unsigned short)0x0020)            /*!<Bit 1 */
#define  TIM_CR2_MMS_2                       ((unsigned short)0x0040)            /*!<Bit 2 */

#define  TIM_CR2_TI1S                        ((unsigned short)0x0080)            /*!<TI1 Selection */
#define  TIM_CR2_OIS1                        ((unsigned short)0x0100)            /*!<Output Idle state 1 (OC1 output)  */
#define  TIM_CR2_OIS1N                       ((unsigned short)0x0200)            /*!<Output Idle state 1 (OC1N output) */
#define  TIM_CR2_OIS2                        ((unsigned short)0x0400)            /*!<Output Idle state 2 (OC2 output)  */
#define  TIM_CR2_OIS2N                       ((unsigned short)0x0800)            /*!<Output Idle state 2 (OC2N output) */
#define  TIM_CR2_OIS3                        ((unsigned short)0x1000)            /*!<Output Idle state 3 (OC3 output)  */
#define  TIM_CR2_OIS3N                       ((unsigned short)0x2000)            /*!<Output Idle state 3 (OC3N output) */
#define  TIM_CR2_OIS4                        ((unsigned short)0x4000)            /*!<Output Idle state 4 (OC4 output)  */

/*******************  Bit definition for TIM_SMCR register  *******************/
#define  TIM_SMCR_SMS                        ((unsigned short)0x0007)            /*!<SMS[2:0] bits (Slave mode selection)    */
#define  TIM_SMCR_SMS_0                      ((unsigned short)0x0001)            /*!<Bit 0 */
#define  TIM_SMCR_SMS_1                      ((unsigned short)0x0002)            /*!<Bit 1 */
#define  TIM_SMCR_SMS_2                      ((unsigned short)0x0004)            /*!<Bit 2 */

#define  TIM_SMCR_TS                         ((unsigned short)0x0070)            /*!<TS[2:0] bits (Trigger selection)        */
#define  TIM_SMCR_TS_0                       ((unsigned short)0x0010)            /*!<Bit 0 */
#define  TIM_SMCR_TS_1                       ((unsigned short)0x0020)            /*!<Bit 1 */
#define  TIM_SMCR_TS_2                       ((unsigned short)0x0040)            /*!<Bit 2 */

#define  TIM_SMCR_MSM                        ((unsigned short)0x0080)            /*!<Master/slave mode                       */

#define  TIM_SMCR_ETF                        ((unsigned short)0x0F00)            /*!<ETF[3:0] bits (External trigger filter) */
#define  TIM_SMCR_ETF_0                      ((unsigned short)0x0100)            /*!<Bit 0 */
#define  TIM_SMCR_ETF_1                      ((unsigned short)0x0200)            /*!<Bit 1 */
#define  TIM_SMCR_ETF_2                      ((unsigned short)0x0400)            /*!<Bit 2 */
#define  TIM_SMCR_ETF_3                      ((unsigned short)0x0800)            /*!<Bit 3 */

#define  TIM_SMCR_ETPS                       ((unsigned short)0x3000)            /*!<ETPS[1:0] bits (External trigger prescaler) */
#define  TIM_SMCR_ETPS_0                     ((unsigned short)0x1000)            /*!<Bit 0 */
#define  TIM_SMCR_ETPS_1                     ((unsigned short)0x2000)            /*!<Bit 1 */

#define  TIM_SMCR_ECE                        ((unsigned short)0x4000)            /*!<External clock enable     */
#define  TIM_SMCR_ETP                        ((unsigned short)0x8000)            /*!<External trigger polarity */

/*******************  Bit definition for TIM_DIER register  *******************/
#define  TIM_DIER_UIE                        ((unsigned short)0x0001)            /*!<Update interrupt enable */
#define  TIM_DIER_CC1IE                      ((unsigned short)0x0002)            /*!<Capture/Compare 1 interrupt enable   */
#define  TIM_DIER_CC2IE                      ((unsigned short)0x0004)            /*!<Capture/Compare 2 interrupt enable   */
#define  TIM_DIER_CC3IE                      ((unsigned short)0x0008)            /*!<Capture/Compare 3 interrupt enable   */
#define  TIM_DIER_CC4IE                      ((unsigned short)0x0010)            /*!<Capture/Compare 4 interrupt enable   */
#define  TIM_DIER_COMIE                      ((unsigned short)0x0020)            /*!<COM interrupt enable                 */
#define  TIM_DIER_TIE                        ((unsigned short)0x0040)            /*!<Trigger interrupt enable             */
#define  TIM_DIER_BIE                        ((unsigned short)0x0080)            /*!<Break interrupt enable               */
#define  TIM_DIER_UDE                        ((unsigned short)0x0100)            /*!<Update DMA request enable            */
#define  TIM_DIER_CC1DE                      ((unsigned short)0x0200)            /*!<Capture/Compare 1 DMA request enable */
#define  TIM_DIER_CC2DE                      ((unsigned short)0x0400)            /*!<Capture/Compare 2 DMA request enable */
#define  TIM_DIER_CC3DE                      ((unsigned short)0x0800)            /*!<Capture/Compare 3 DMA request enable */
#define  TIM_DIER_CC4DE                      ((unsigned short)0x1000)            /*!<Capture/Compare 4 DMA request enable */
#define  TIM_DIER_COMDE                      ((unsigned short)0x2000)            /*!<COM DMA request enable               */
#define  TIM_DIER_TDE                        ((unsigned short)0x4000)            /*!<Trigger DMA request enable           */

/********************  Bit definition for TIM_SR register  ********************/
#define  TIM_SR_UIF                          ((unsigned short)0x0001)            /*!<Update interrupt Flag              */
#define  TIM_SR_CC1IF                        ((unsigned short)0x0002)            /*!<Capture/Compare 1 interrupt Flag   */
#define  TIM_SR_CC2IF                        ((unsigned short)0x0004)            /*!<Capture/Compare 2 interrupt Flag   */
#define  TIM_SR_CC3IF                        ((unsigned short)0x0008)            /*!<Capture/Compare 3 interrupt Flag   */
#define  TIM_SR_CC4IF                        ((unsigned short)0x0010)            /*!<Capture/Compare 4 interrupt Flag   */
#define  TIM_SR_COMIF                        ((unsigned short)0x0020)            /*!<COM interrupt Flag                 */
#define  TIM_SR_TIF                          ((unsigned short)0x0040)            /*!<Trigger interrupt Flag             */
#define  TIM_SR_BIF                          ((unsigned short)0x0080)            /*!<Break interrupt Flag               */
#define  TIM_SR_CC1OF                        ((unsigned short)0x0200)            /*!<Capture/Compare 1 Overcapture Flag */
#define  TIM_SR_CC2OF                        ((unsigned short)0x0400)            /*!<Capture/Compare 2 Overcapture Flag */
#define  TIM_SR_CC3OF                        ((unsigned short)0x0800)            /*!<Capture/Compare 3 Overcapture Flag */
#define  TIM_SR_CC4OF                        ((unsigned short)0x1000)            /*!<Capture/Compare 4 Overcapture Flag */

/*******************  Bit definition for TIM_EGR register  ********************/
#define  TIM_EGR_UG                          ((unsigned char)0x01)               /*!<Update Generation                         */
#define  TIM_EGR_CC1G                        ((unsigned char)0x02)               /*!<Capture/Compare 1 Generation              */
#define  TIM_EGR_CC2G                        ((unsigned char)0x04)               /*!<Capture/Compare 2 Generation              */
#define  TIM_EGR_CC3G                        ((unsigned char)0x08)               /*!<Capture/Compare 3 Generation              */
#define  TIM_EGR_CC4G                        ((unsigned char)0x10)               /*!<Capture/Compare 4 Generation              */
#define  TIM_EGR_COMG                        ((unsigned char)0x20)               /*!<Capture/Compare Control Update Generation */
#define  TIM_EGR_TG                          ((unsigned char)0x40)               /*!<Trigger Generation                        */
#define  TIM_EGR_BG                          ((unsigned char)0x80)               /*!<Break Generation                          */

/******************  Bit definition for TIM_CCMR1 register  *******************/
#define  TIM_CCMR1_CC1S                      ((unsigned short)0x0003)            /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define  TIM_CCMR1_CC1S_0                    ((unsigned short)0x0001)            /*!<Bit 0 */
#define  TIM_CCMR1_CC1S_1                    ((unsigned short)0x0002)            /*!<Bit 1 */

#define  TIM_CCMR1_OC1FE                     ((unsigned short)0x0004)            /*!<Output Compare 1 Fast enable                 */
#define  TIM_CCMR1_OC1PE                     ((unsigned short)0x0008)            /*!<Output Compare 1 Preload enable              */

#define  TIM_CCMR1_OC1M                      ((unsigned short)0x0070)            /*!<OC1M[2:0] bits (Output Compare 1 Mode)       */
#define  TIM_CCMR1_OC1M_0                    ((unsigned short)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR1_OC1M_1                    ((unsigned short)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR1_OC1M_2                    ((unsigned short)0x0040)            /*!<Bit 2 */

#define  TIM_CCMR1_OC1CE                     ((unsigned short)0x0080)            /*!<Output Compare 1Clear Enable                 */

#define  TIM_CCMR1_CC2S                      ((unsigned short)0x0300)            /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define  TIM_CCMR1_CC2S_0                    ((unsigned short)0x0100)            /*!<Bit 0 */
#define  TIM_CCMR1_CC2S_1                    ((unsigned short)0x0200)            /*!<Bit 1 */

#define  TIM_CCMR1_OC2FE                     ((unsigned short)0x0400)            /*!<Output Compare 2 Fast enable                 */
#define  TIM_CCMR1_OC2PE                     ((unsigned short)0x0800)            /*!<Output Compare 2 Preload enable              */

#define  TIM_CCMR1_OC2M                      ((unsigned short)0x7000)            /*!<OC2M[2:0] bits (Output Compare 2 Mode)       */
#define  TIM_CCMR1_OC2M_0                    ((unsigned short)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR1_OC2M_1                    ((unsigned short)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR1_OC2M_2                    ((unsigned short)0x4000)            /*!<Bit 2 */

#define  TIM_CCMR1_OC2CE                     ((unsigned short)0x8000)            /*!<Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIM_CCMR1_IC1PSC                    ((unsigned short)0x000C)            /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define  TIM_CCMR1_IC1PSC_0                  ((unsigned short)0x0004)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1PSC_1                  ((unsigned short)0x0008)            /*!<Bit 1 */

#define  TIM_CCMR1_IC1F                      ((unsigned short)0x00F0)            /*!<IC1F[3:0] bits (Input Capture 1 Filter)      */
#define  TIM_CCMR1_IC1F_0                    ((unsigned short)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1F_1                    ((unsigned short)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR1_IC1F_2                    ((unsigned short)0x0040)            /*!<Bit 2 */
#define  TIM_CCMR1_IC1F_3                    ((unsigned short)0x0080)            /*!<Bit 3 */

#define  TIM_CCMR1_IC2PSC                    ((unsigned short)0x0C00)            /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler)  */
#define  TIM_CCMR1_IC2PSC_0                  ((unsigned short)0x0400)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2PSC_1                  ((unsigned short)0x0800)            /*!<Bit 1 */

#define  TIM_CCMR1_IC2F                      ((unsigned short)0xF000)            /*!<IC2F[3:0] bits (Input Capture 2 Filter)       */
#define  TIM_CCMR1_IC2F_0                    ((unsigned short)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2F_1                    ((unsigned short)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR1_IC2F_2                    ((unsigned short)0x4000)            /*!<Bit 2 */
#define  TIM_CCMR1_IC2F_3                    ((unsigned short)0x8000)            /*!<Bit 3 */

/******************  Bit definition for TIM_CCMR2 register  *******************/
#define  TIM_CCMR2_CC3S                      ((unsigned short)0x0003)            /*!<CC3S[1:0] bits (Capture/Compare 3 Selection)  */
#define  TIM_CCMR2_CC3S_0                    ((unsigned short)0x0001)            /*!<Bit 0 */
#define  TIM_CCMR2_CC3S_1                    ((unsigned short)0x0002)            /*!<Bit 1 */

#define  TIM_CCMR2_OC3FE                     ((unsigned short)0x0004)            /*!<Output Compare 3 Fast enable           */
#define  TIM_CCMR2_OC3PE                     ((unsigned short)0x0008)            /*!<Output Compare 3 Preload enable        */

#define  TIM_CCMR2_OC3M                      ((unsigned short)0x0070)            /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define  TIM_CCMR2_OC3M_0                    ((unsigned short)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR2_OC3M_1                    ((unsigned short)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR2_OC3M_2                    ((unsigned short)0x0040)            /*!<Bit 2 */

#define  TIM_CCMR2_OC3CE                     ((unsigned short)0x0080)            /*!<Output Compare 3 Clear Enable */

#define  TIM_CCMR2_CC4S                      ((unsigned short)0x0300)            /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define  TIM_CCMR2_CC4S_0                    ((unsigned short)0x0100)            /*!<Bit 0 */
#define  TIM_CCMR2_CC4S_1                    ((unsigned short)0x0200)            /*!<Bit 1 */

#define  TIM_CCMR2_OC4FE                     ((unsigned short)0x0400)            /*!<Output Compare 4 Fast enable    */
#define  TIM_CCMR2_OC4PE                     ((unsigned short)0x0800)            /*!<Output Compare 4 Preload enable */

#define  TIM_CCMR2_OC4M                      ((unsigned short)0x7000)            /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define  TIM_CCMR2_OC4M_0                    ((unsigned short)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR2_OC4M_1                    ((unsigned short)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR2_OC4M_2                    ((unsigned short)0x4000)            /*!<Bit 2 */

#define  TIM_CCMR2_OC4CE                     ((unsigned short)0x8000)            /*!<Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIM_CCMR2_IC3PSC                    ((unsigned short)0x000C)            /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define  TIM_CCMR2_IC3PSC_0                  ((unsigned short)0x0004)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3PSC_1                  ((unsigned short)0x0008)            /*!<Bit 1 */

#define  TIM_CCMR2_IC3F                      ((unsigned short)0x00F0)            /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define  TIM_CCMR2_IC3F_0                    ((unsigned short)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3F_1                    ((unsigned short)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR2_IC3F_2                    ((unsigned short)0x0040)            /*!<Bit 2 */
#define  TIM_CCMR2_IC3F_3                    ((unsigned short)0x0080)            /*!<Bit 3 */

#define  TIM_CCMR2_IC4PSC                    ((unsigned short)0x0C00)            /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define  TIM_CCMR2_IC4PSC_0                  ((unsigned short)0x0400)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4PSC_1                  ((unsigned short)0x0800)            /*!<Bit 1 */

#define  TIM_CCMR2_IC4F                      ((unsigned short)0xF000)            /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define  TIM_CCMR2_IC4F_0                    ((unsigned short)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4F_1                    ((unsigned short)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR2_IC4F_2                    ((unsigned short)0x4000)            /*!<Bit 2 */
#define  TIM_CCMR2_IC4F_3                    ((unsigned short)0x8000)            /*!<Bit 3 */

/*******************  Bit definition for TIM_CCER register  *******************/
#define  TIM_CCER_CC1E                       ((unsigned short)0x0001)            /*!<Capture/Compare 1 output enable                 */
#define  TIM_CCER_CC1P                       ((unsigned short)0x0002)            /*!<Capture/Compare 1 output Polarity               */
#define  TIM_CCER_CC1NE                      ((unsigned short)0x0004)            /*!<Capture/Compare 1 Complementary output enable   */
#define  TIM_CCER_CC1NP                      ((unsigned short)0x0008)            /*!<Capture/Compare 1 Complementary output Polarity */
#define  TIM_CCER_CC2E                       ((unsigned short)0x0010)            /*!<Capture/Compare 2 output enable                 */
#define  TIM_CCER_CC2P                       ((unsigned short)0x0020)            /*!<Capture/Compare 2 output Polarity               */
#define  TIM_CCER_CC2NE                      ((unsigned short)0x0040)            /*!<Capture/Compare 2 Complementary output enable   */
#define  TIM_CCER_CC2NP                      ((unsigned short)0x0080)            /*!<Capture/Compare 2 Complementary output Polarity */
#define  TIM_CCER_CC3E                       ((unsigned short)0x0100)            /*!<Capture/Compare 3 output enable                 */
#define  TIM_CCER_CC3P                       ((unsigned short)0x0200)            /*!<Capture/Compare 3 output Polarity               */
#define  TIM_CCER_CC3NE                      ((unsigned short)0x0400)            /*!<Capture/Compare 3 Complementary output enable   */
#define  TIM_CCER_CC3NP                      ((unsigned short)0x0800)            /*!<Capture/Compare 3 Complementary output Polarity */
#define  TIM_CCER_CC4E                       ((unsigned short)0x1000)            /*!<Capture/Compare 4 output enable                 */
#define  TIM_CCER_CC4P                       ((unsigned short)0x2000)            /*!<Capture/Compare 4 output Polarity               */
#define  TIM_CCER_CC4NP                      ((unsigned short)0x8000)            /*!<Capture/Compare 4 Complementary output Polarity */

/*******************  Bit definition for TIM_CNT register  ********************/
#define  TIM_CNT_CNT                         ((unsigned short)0xFFFF)            /*!<Counter Value            */

/*******************  Bit definition for TIM_PSC register  ********************/
#define  TIM_PSC_PSC                         ((unsigned short)0xFFFF)            /*!<Prescaler Value          */

/*******************  Bit definition for TIM_ARR register  ********************/
#define  TIM_ARR_ARR                         ((unsigned short)0xFFFF)            /*!<actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  ********************/
#define  TIM_RCR_REP                         ((unsigned char)0xFF)               /*!<Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  *******************/
#define  TIM_CCR1_CCR1                       ((unsigned short)0xFFFF)            /*!<Capture/Compare 1 Value  */

/*******************  Bit definition for TIM_CCR2 register  *******************/
#define  TIM_CCR2_CCR2                       ((unsigned short)0xFFFF)            /*!<Capture/Compare 2 Value  */

/*******************  Bit definition for TIM_CCR3 register  *******************/
#define  TIM_CCR3_CCR3                       ((unsigned short)0xFFFF)            /*!<Capture/Compare 3 Value  */

/*******************  Bit definition for TIM_CCR4 register  *******************/
#define  TIM_CCR4_CCR4                       ((unsigned short)0xFFFF)            /*!<Capture/Compare 4 Value  */

/*******************  Bit definition for TIM_BDTR register  *******************/
#define  TIM_BDTR_DTG                        ((unsigned short)0x00FF)            /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define  TIM_BDTR_DTG_0                      ((unsigned short)0x0001)            /*!<Bit 0 */
#define  TIM_BDTR_DTG_1                      ((unsigned short)0x0002)            /*!<Bit 1 */
#define  TIM_BDTR_DTG_2                      ((unsigned short)0x0004)            /*!<Bit 2 */
#define  TIM_BDTR_DTG_3                      ((unsigned short)0x0008)            /*!<Bit 3 */
#define  TIM_BDTR_DTG_4                      ((unsigned short)0x0010)            /*!<Bit 4 */
#define  TIM_BDTR_DTG_5                      ((unsigned short)0x0020)            /*!<Bit 5 */
#define  TIM_BDTR_DTG_6                      ((unsigned short)0x0040)            /*!<Bit 6 */
#define  TIM_BDTR_DTG_7                      ((unsigned short)0x0080)            /*!<Bit 7 */

#define  TIM_BDTR_LOCK                       ((unsigned short)0x0300)            /*!<LOCK[1:0] bits (Lock Configuration) */
#define  TIM_BDTR_LOCK_0                     ((unsigned short)0x0100)            /*!<Bit 0 */
#define  TIM_BDTR_LOCK_1                     ((unsigned short)0x0200)            /*!<Bit 1 */

#define  TIM_BDTR_OSSI                       ((unsigned short)0x0400)            /*!<Off-State Selection for Idle mode */
#define  TIM_BDTR_OSSR                       ((unsigned short)0x0800)            /*!<Off-State Selection for Run mode  */
#define  TIM_BDTR_BKE                        ((unsigned short)0x1000)            /*!<Break enable                      */
#define  TIM_BDTR_BKP                        ((unsigned short)0x2000)            /*!<Break Polarity                    */
#define  TIM_BDTR_AOE                        ((unsigned short)0x4000)            /*!<Automatic Output enable           */
#define  TIM_BDTR_MOE                        ((unsigned short)0x8000)            /*!<Main Output enable                */

/*******************  Bit definition for TIM_DCR register  ********************/
#define  TIM_DCR_DBA                         ((unsigned short)0x001F)            /*!<DBA[4:0] bits (DMA Base Address) */
#define  TIM_DCR_DBA_0                       ((unsigned short)0x0001)            /*!<Bit 0 */
#define  TIM_DCR_DBA_1                       ((unsigned short)0x0002)            /*!<Bit 1 */
#define  TIM_DCR_DBA_2                       ((unsigned short)0x0004)            /*!<Bit 2 */
#define  TIM_DCR_DBA_3                       ((unsigned short)0x0008)            /*!<Bit 3 */
#define  TIM_DCR_DBA_4                       ((unsigned short)0x0010)            /*!<Bit 4 */

#define  TIM_DCR_DBL                         ((unsigned short)0x1F00)            /*!<DBL[4:0] bits (DMA Burst Length) */
#define  TIM_DCR_DBL_0                       ((unsigned short)0x0100)            /*!<Bit 0 */
#define  TIM_DCR_DBL_1                       ((unsigned short)0x0200)            /*!<Bit 1 */
#define  TIM_DCR_DBL_2                       ((unsigned short)0x0400)            /*!<Bit 2 */
#define  TIM_DCR_DBL_3                       ((unsigned short)0x0800)            /*!<Bit 3 */
#define  TIM_DCR_DBL_4                       ((unsigned short)0x1000)            /*!<Bit 4 */

/*******************  Bit definition for TIM_DMAR register  *******************/
#define  TIM_DMAR_DMAB                       ((unsigned short)0xFFFF)            /*!<DMA register for burst accesses                    */

/*******************  Bit definition for TIM_OR register  *********************/
#define TIM_OR_TI4_RMP                       ((unsigned short)0x00C0)            /*!<TI4_RMP[1:0] bits (TIM5 Input 4 remap)             */
#define TIM_OR_TI4_RMP_0                     ((unsigned short)0x0040)            /*!<Bit 0 */
#define TIM_OR_TI4_RMP_1                     ((unsigned short)0x0080)            /*!<Bit 1 */
#define TIM_OR_ITR1_RMP                      ((unsigned short)0x0C00)            /*!<ITR1_RMP[1:0] bits (TIM2 Internal trigger 1 remap) */
#define TIM_OR_ITR1_RMP_0                    ((unsigned short)0x0400)            /*!<Bit 0 */
#define TIM_OR_ITR1_RMP_1                    ((unsigned short)0x0800)            /*!<Bit 1 */


/******************************************************************************/
/*                                                                            */
/*         Universal Synchronous Asynchronous Receiver Transmitter            */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for USART_SR register  *******************/
#define  USART_SR_PE                         ((unsigned short)0x0001)            /*!<Parity Error                 */
#define  USART_SR_FE                         ((unsigned short)0x0002)            /*!<Framing Error                */
#define  USART_SR_NE                         ((unsigned short)0x0004)            /*!<Noise Error Flag             */
#define  USART_SR_ORE                        ((unsigned short)0x0008)            /*!<OverRun Error                */
#define  USART_SR_IDLE                       ((unsigned short)0x0010)            /*!<IDLE line detected           */
#define  USART_SR_RXNE                       ((unsigned short)0x0020)            /*!<Read Data Register Not Empty */
#define  USART_SR_TC                         ((unsigned short)0x0040)            /*!<Transmission Complete        */
#define  USART_SR_TXE                        ((unsigned short)0x0080)            /*!<Transmit Data Register Empty */
#define  USART_SR_LBD                        ((unsigned short)0x0100)            /*!<LIN Break Detection Flag     */
#define  USART_SR_CTS                        ((unsigned short)0x0200)            /*!<CTS Flag                     */

/*******************  Bit definition for USART_DR register  *******************/
#define  USART_DR_DR                         ((unsigned short)0x01FF)            /*!<Data value */

/******************  Bit definition for USART_BRR register  *******************/
#define  USART_BRR_DIV_Fraction              ((unsigned short)0x000F)            /*!<Fraction of USARTDIV */
#define  USART_BRR_DIV_Mantissa              ((unsigned short)0xFFF0)            /*!<Mantissa of USARTDIV */

/******************  Bit definition for USART_CR1 register  *******************/
#define  USART_CR1_SBK                       ((unsigned short)0x0001)            /*!<Send Break                             */
#define  USART_CR1_RWU                       ((unsigned short)0x0002)            /*!<Receiver wakeup                        */
#define  USART_CR1_RE                        ((unsigned short)0x0004)            /*!<Receiver Enable                        */
#define  USART_CR1_TE                        ((unsigned short)0x0008)            /*!<Transmitter Enable                     */
#define  USART_CR1_IDLEIE                    ((unsigned short)0x0010)            /*!<IDLE Interrupt Enable                  */
#define  USART_CR1_RXNEIE                    ((unsigned short)0x0020)            /*!<RXNE Interrupt Enable                  */
#define  USART_CR1_TCIE                      ((unsigned short)0x0040)            /*!<Transmission Complete Interrupt Enable */
#define  USART_CR1_TXEIE                     ((unsigned short)0x0080)            /*!<PE Interrupt Enable                    */
#define  USART_CR1_PEIE                      ((unsigned short)0x0100)            /*!<PE Interrupt Enable                    */
#define  USART_CR1_PS                        ((unsigned short)0x0200)            /*!<Parity Selection                       */
#define  USART_CR1_PCE                       ((unsigned short)0x0400)            /*!<Parity Control Enable                  */
#define  USART_CR1_WAKE                      ((unsigned short)0x0800)            /*!<Wakeup method                          */
#define  USART_CR1_M                         ((unsigned short)0x1000)            /*!<Word length                            */
#define  USART_CR1_UE                        ((unsigned short)0x2000)            /*!<USART Enable                           */
#define  USART_CR1_OVER8                     ((unsigned short)0x8000)            /*!<USART Oversampling by 8 enable         */

/******************  Bit definition for USART_CR2 register  *******************/
#define  USART_CR2_ADD                       ((unsigned short)0x000F)            /*!<Address of the USART node            */
#define  USART_CR2_LBDL                      ((unsigned short)0x0020)            /*!<LIN Break Detection Length           */
#define  USART_CR2_LBDIE                     ((unsigned short)0x0040)            /*!<LIN Break Detection Interrupt Enable */
#define  USART_CR2_LBCL                      ((unsigned short)0x0100)            /*!<Last Bit Clock pulse                 */
#define  USART_CR2_CPHA                      ((unsigned short)0x0200)            /*!<Clock Phase                          */
#define  USART_CR2_CPOL                      ((unsigned short)0x0400)            /*!<Clock Polarity                       */
#define  USART_CR2_CLKEN                     ((unsigned short)0x0800)            /*!<Clock Enable                         */

#define  USART_CR2_STOP                      ((unsigned short)0x3000)            /*!<STOP[1:0] bits (STOP bits) */
#define  USART_CR2_STOP_0                    ((unsigned short)0x1000)            /*!<Bit 0 */
#define  USART_CR2_STOP_1                    ((unsigned short)0x2000)            /*!<Bit 1 */

#define  USART_CR2_LINEN                     ((unsigned short)0x4000)            /*!<LIN mode enable */

/******************  Bit definition for USART_CR3 register  *******************/
#define  USART_CR3_EIE                       ((unsigned short)0x0001)            /*!<Error Interrupt Enable      */
#define  USART_CR3_IREN                      ((unsigned short)0x0002)            /*!<IrDA mode Enable            */
#define  USART_CR3_IRLP                      ((unsigned short)0x0004)            /*!<IrDA Low-Power              */
#define  USART_CR3_HDSEL                     ((unsigned short)0x0008)            /*!<Half-Duplex Selection       */
#define  USART_CR3_NACK                      ((unsigned short)0x0010)            /*!<Smartcard NACK enable       */
#define  USART_CR3_SCEN                      ((unsigned short)0x0020)            /*!<Smartcard mode enable       */
#define  USART_CR3_DMAR                      ((unsigned short)0x0040)            /*!<DMA Enable Receiver         */
#define  USART_CR3_DMAT                      ((unsigned short)0x0080)            /*!<DMA Enable Transmitter      */
#define  USART_CR3_RTSE                      ((unsigned short)0x0100)            /*!<RTS Enable                  */
#define  USART_CR3_CTSE                      ((unsigned short)0x0200)            /*!<CTS Enable                  */
#define  USART_CR3_CTSIE                     ((unsigned short)0x0400)            /*!<CTS Interrupt Enable        */
#define  USART_CR3_ONEBIT                    ((unsigned short)0x0800)            /*!<USART One bit method enable */

/******************  Bit definition for USART_GTPR register  ******************/
#define  USART_GTPR_PSC                      ((unsigned short)0x00FF)            /*!<PSC[7:0] bits (Prescaler value) */
#define  USART_GTPR_PSC_0                    ((unsigned short)0x0001)            /*!<Bit 0 */
#define  USART_GTPR_PSC_1                    ((unsigned short)0x0002)            /*!<Bit 1 */
#define  USART_GTPR_PSC_2                    ((unsigned short)0x0004)            /*!<Bit 2 */
#define  USART_GTPR_PSC_3                    ((unsigned short)0x0008)            /*!<Bit 3 */
#define  USART_GTPR_PSC_4                    ((unsigned short)0x0010)            /*!<Bit 4 */
#define  USART_GTPR_PSC_5                    ((unsigned short)0x0020)            /*!<Bit 5 */
#define  USART_GTPR_PSC_6                    ((unsigned short)0x0040)            /*!<Bit 6 */
#define  USART_GTPR_PSC_7                    ((unsigned short)0x0080)            /*!<Bit 7 */

#define  USART_GTPR_GT                       ((unsigned short)0xFF00)            /*!<Guard time value */

/******************************************************************************/
/*                                                                            */
/*                            Window WATCHDOG                                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for WWDG_CR register  ********************/
#define  WWDG_CR_T                           ((unsigned char)0x7F)               /*!<T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define  WWDG_CR_T0                          ((unsigned char)0x01)               /*!<Bit 0 */
#define  WWDG_CR_T1                          ((unsigned char)0x02)               /*!<Bit 1 */
#define  WWDG_CR_T2                          ((unsigned char)0x04)               /*!<Bit 2 */
#define  WWDG_CR_T3                          ((unsigned char)0x08)               /*!<Bit 3 */
#define  WWDG_CR_T4                          ((unsigned char)0x10)               /*!<Bit 4 */
#define  WWDG_CR_T5                          ((unsigned char)0x20)               /*!<Bit 5 */
#define  WWDG_CR_T6                          ((unsigned char)0x40)               /*!<Bit 6 */

#define  WWDG_CR_WDGA                        ((unsigned char)0x80)               /*!<Activation bit */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define  WWDG_CFR_W                          ((unsigned short)0x007F)            /*!<W[6:0] bits (7-bit window value) */
#define  WWDG_CFR_W0                         ((unsigned short)0x0001)            /*!<Bit 0 */
#define  WWDG_CFR_W1                         ((unsigned short)0x0002)            /*!<Bit 1 */
#define  WWDG_CFR_W2                         ((unsigned short)0x0004)            /*!<Bit 2 */
#define  WWDG_CFR_W3                         ((unsigned short)0x0008)            /*!<Bit 3 */
#define  WWDG_CFR_W4                         ((unsigned short)0x0010)            /*!<Bit 4 */
#define  WWDG_CFR_W5                         ((unsigned short)0x0020)            /*!<Bit 5 */
#define  WWDG_CFR_W6                         ((unsigned short)0x0040)            /*!<Bit 6 */

#define  WWDG_CFR_WDGTB                      ((unsigned short)0x0180)            /*!<WDGTB[1:0] bits (Timer Base) */
#define  WWDG_CFR_WDGTB0                     ((unsigned short)0x0080)            /*!<Bit 0 */
#define  WWDG_CFR_WDGTB1                     ((unsigned short)0x0100)            /*!<Bit 1 */

#define  WWDG_CFR_EWI                        ((unsigned short)0x0200)            /*!<Early Wakeup Interrupt */

/*******************  Bit definition for WWDG_SR register  ********************/
#define  WWDG_SR_EWIF                        ((unsigned char)0x01)               /*!<Early Wakeup Interrupt Flag */


/******************************************************************************/
/*                                                                            */
/*                                DBG                                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DBGMCU_IDCODE register  *************/
#define  DBGMCU_IDCODE_DEV_ID                ((unsigned int)0x00000FFF)
#define  DBGMCU_IDCODE_REV_ID                ((unsigned int)0xFFFF0000)

/********************  Bit definition for DBGMCU_CR register  *****************/
#define  DBGMCU_CR_DBG_SLEEP                 ((unsigned int)0x00000001)
#define  DBGMCU_CR_DBG_STOP                  ((unsigned int)0x00000002)
#define  DBGMCU_CR_DBG_STANDBY               ((unsigned int)0x00000004)
#define  DBGMCU_CR_TRACE_IOEN                ((unsigned int)0x00000020)

#define  DBGMCU_CR_TRACE_MODE                ((unsigned int)0x000000C0)
#define  DBGMCU_CR_TRACE_MODE_0              ((unsigned int)0x00000040)/*!<Bit 0 */
#define  DBGMCU_CR_TRACE_MODE_1              ((unsigned int)0x00000080)/*!<Bit 1 */

/********************  Bit definition for DBGMCU_APB1_FZ register  ************/
#define  DBGMCU_APB1_FZ_DBG_TIM2_STOP            ((unsigned int)0x00000001)
#define  DBGMCU_APB1_FZ_DBG_TIM3_STOP            ((unsigned int)0x00000002)
#define  DBGMCU_APB1_FZ_DBG_TIM4_STOP            ((unsigned int)0x00000004)
#define  DBGMCU_APB1_FZ_DBG_TIM5_STOP            ((unsigned int)0x00000008)
#define  DBGMCU_APB1_FZ_DBG_TIM6_STOP            ((unsigned int)0x00000010)
#define  DBGMCU_APB1_FZ_DBG_TIM7_STOP            ((unsigned int)0x00000020)
#define  DBGMCU_APB1_FZ_DBG_TIM12_STOP           ((unsigned int)0x00000040)
#define  DBGMCU_APB1_FZ_DBG_TIM13_STOP           ((unsigned int)0x00000080)
#define  DBGMCU_APB1_FZ_DBG_TIM14_STOP           ((unsigned int)0x00000100)
#define  DBGMCU_APB1_FZ_DBG_RTC_STOP             ((unsigned int)0x00000400)
#define  DBGMCU_APB1_FZ_DBG_WWDG_STOP            ((unsigned int)0x00000800)
#define  DBGMCU_APB1_FZ_DBG_IWDG_STOP            ((unsigned int)0x00001000)
#define  DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT   ((unsigned int)0x00200000)
#define  DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT   ((unsigned int)0x00400000)
#define  DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT   ((unsigned int)0x00800000)
#define  DBGMCU_APB1_FZ_DBG_CAN1_STOP            ((unsigned int)0x02000000)
#define  DBGMCU_APB1_FZ_DBG_CAN2_STOP            ((unsigned int)0x04000000)
/* Old IWDGSTOP bit definition, maintained for legacy purpose */
#define  DBGMCU_APB1_FZ_DBG_IWDEG_STOP           DBGMCU_APB1_FZ_DBG_IWDG_STOP

/********************  Bit definition for DBGMCU_APB1_FZ register  ************/
#define  DBGMCU_APB1_FZ_DBG_TIM1_STOP        ((unsigned int)0x00000001)
#define  DBGMCU_APB1_FZ_DBG_TIM8_STOP        ((unsigned int)0x00000002)
#define  DBGMCU_APB1_FZ_DBG_TIM9_STOP        ((unsigned int)0x00010000)
#define  DBGMCU_APB1_FZ_DBG_TIM10_STOP       ((unsigned int)0x00020000)
#define  DBGMCU_APB1_FZ_DBG_TIM11_STOP       ((unsigned int)0x00040000)

/******************************************************************************/
/*                                                                            */
/*                Ethernet MAC Registers bits definitions                     */
/*                                                                            */
/******************************************************************************/
/* Bit definition for Ethernet MAC Control Register register */
#define ETH_MACCR_WD      ((unsigned int)0x00800000)  /* Watchdog disable */
#define ETH_MACCR_JD      ((unsigned int)0x00400000)  /* Jabber disable */
#define ETH_MACCR_IFG     ((unsigned int)0x000E0000)  /* Inter-frame gap */
#define ETH_MACCR_IFG_96Bit     ((unsigned int)0x00000000)  /* Minimum IFG between frames during transmission is 96Bit */
#define ETH_MACCR_IFG_88Bit     ((unsigned int)0x00020000)  /* Minimum IFG between frames during transmission is 88Bit */
#define ETH_MACCR_IFG_80Bit     ((unsigned int)0x00040000)  /* Minimum IFG between frames during transmission is 80Bit */
#define ETH_MACCR_IFG_72Bit     ((unsigned int)0x00060000)  /* Minimum IFG between frames during transmission is 72Bit */
#define ETH_MACCR_IFG_64Bit     ((unsigned int)0x00080000)  /* Minimum IFG between frames during transmission is 64Bit */        
#define ETH_MACCR_IFG_56Bit     ((unsigned int)0x000A0000)  /* Minimum IFG between frames during transmission is 56Bit */
#define ETH_MACCR_IFG_48Bit     ((unsigned int)0x000C0000)  /* Minimum IFG between frames during transmission is 48Bit */
#define ETH_MACCR_IFG_40Bit     ((unsigned int)0x000E0000)  /* Minimum IFG between frames during transmission is 40Bit */              
#define ETH_MACCR_CSD     ((unsigned int)0x00010000)  /* Carrier sense disable (during transmission) */
#define ETH_MACCR_FES     ((unsigned int)0x00004000)  /* Fast ethernet speed */
#define ETH_MACCR_ROD     ((unsigned int)0x00002000)  /* Receive own disable */
#define ETH_MACCR_LM      ((unsigned int)0x00001000)  /* loopback mode */
#define ETH_MACCR_DM      ((unsigned int)0x00000800)  /* Duplex mode */
#define ETH_MACCR_IPCO    ((unsigned int)0x00000400)  /* IP Checksum offload */
#define ETH_MACCR_RD      ((unsigned int)0x00000200)  /* Retry disable */
#define ETH_MACCR_APCS    ((unsigned int)0x00000080)  /* Automatic Pad/CRC stripping */
#define ETH_MACCR_BL      ((unsigned int)0x00000060)  /* Back-off limit: random integer number (r) of slot time delays before rescheduling
							 a transmission attempt during retries after a collision: 0 =< r <2^k */
#define ETH_MACCR_BL_10    ((unsigned int)0x00000000)  /* k = min (n, 10) */
#define ETH_MACCR_BL_8     ((unsigned int)0x00000020)  /* k = min (n, 8) */
#define ETH_MACCR_BL_4     ((unsigned int)0x00000040)  /* k = min (n, 4) */
#define ETH_MACCR_BL_1     ((unsigned int)0x00000060)  /* k = min (n, 1) */ 
#define ETH_MACCR_DC      ((unsigned int)0x00000010)  /* Defferal check */
#define ETH_MACCR_TE      ((unsigned int)0x00000008)  /* Transmitter enable */
#define ETH_MACCR_RE      ((unsigned int)0x00000004)  /* Receiver enable */

/* Bit definition for Ethernet MAC Frame Filter Register */
#define ETH_MACFFR_RA     ((unsigned int)0x80000000)  /* Receive all */ 
#define ETH_MACFFR_HPF    ((unsigned int)0x00000400)  /* Hash or perfect filter */ 
#define ETH_MACFFR_SAF    ((unsigned int)0x00000200)  /* Source address filter enable */ 
#define ETH_MACFFR_SAIF   ((unsigned int)0x00000100)  /* SA inverse filtering */ 
#define ETH_MACFFR_PCF    ((unsigned int)0x000000C0)  /* Pass control frames: 3 cases */
#define ETH_MACFFR_PCF_BlockAll                ((unsigned int)0x00000040)  /* MAC filters all control frames from reaching the application */
#define ETH_MACFFR_PCF_ForwardAll              ((unsigned int)0x00000080)  /* MAC forwards all control frames to application even if they fail the Address Filter */
#define ETH_MACFFR_PCF_ForwardPassedAddrFilter ((unsigned int)0x000000C0)  /* MAC forwards control frames that pass the Address Filter. */ 
#define ETH_MACFFR_BFD    ((unsigned int)0x00000020)  /* Broadcast frame disable */ 
#define ETH_MACFFR_PAM    ((unsigned int)0x00000010)  /* Pass all mutlicast */ 
#define ETH_MACFFR_DAIF   ((unsigned int)0x00000008)  /* DA Inverse filtering */ 
#define ETH_MACFFR_HM     ((unsigned int)0x00000004)  /* Hash multicast */ 
#define ETH_MACFFR_HU     ((unsigned int)0x00000002)  /* Hash unicast */
#define ETH_MACFFR_PM     ((unsigned int)0x00000001)  /* Promiscuous mode */

/* Bit definition for Ethernet MAC Hash Table High Register */
#define ETH_MACHTHR_HTH   ((unsigned int)0xFFFFFFFF)  /* Hash table high */

/* Bit definition for Ethernet MAC Hash Table Low Register */
#define ETH_MACHTLR_HTL   ((unsigned int)0xFFFFFFFF)  /* Hash table low */

/* Bit definition for Ethernet MAC MII Address Register */
#define ETH_MACMIIAR_PA   ((unsigned int)0x0000F800)  /* Physical layer address */ 
#define ETH_MACMIIAR_MR   ((unsigned int)0x000007C0)  /* MII register in the selected PHY */ 
#define ETH_MACMIIAR_CR   ((unsigned int)0x0000001C)  /* CR clock range: 6 cases */ 
#define ETH_MACMIIAR_CR_Div42   ((unsigned int)0x00000000)  /* HCLK:60-100 MHz; MDC clock= HCLK/42 */
#define ETH_MACMIIAR_CR_Div62   ((unsigned int)0x00000004)  /* HCLK:100-150 MHz; MDC clock= HCLK/62 */
#define ETH_MACMIIAR_CR_Div16   ((unsigned int)0x00000008)  /* HCLK:20-35 MHz; MDC clock= HCLK/16 */
#define ETH_MACMIIAR_CR_Div26   ((unsigned int)0x0000000C)  /* HCLK:35-60 MHz; MDC clock= HCLK/26 */
#define ETH_MACMIIAR_CR_Div102  ((unsigned int)0x00000010)  /* HCLK:150-168 MHz; MDC clock= HCLK/102 */  
#define ETH_MACMIIAR_MW   ((unsigned int)0x00000002)  /* MII write */ 
#define ETH_MACMIIAR_MB   ((unsigned int)0x00000001)  /* MII busy */ 

/* Bit definition for Ethernet MAC MII Data Register */
#define ETH_MACMIIDR_MD   ((unsigned int)0x0000FFFF)  /* MII data: read/write data from/to PHY */

/* Bit definition for Ethernet MAC Flow Control Register */
#define ETH_MACFCR_PT     ((unsigned int)0xFFFF0000)  /* Pause time */
#define ETH_MACFCR_ZQPD   ((unsigned int)0x00000080)  /* Zero-quanta pause disable */
#define ETH_MACFCR_PLT    ((unsigned int)0x00000030)  /* Pause low threshold: 4 cases */
#define ETH_MACFCR_PLT_Minus4   ((unsigned int)0x00000000)  /* Pause time minus 4 slot times */
#define ETH_MACFCR_PLT_Minus28  ((unsigned int)0x00000010)  /* Pause time minus 28 slot times */
#define ETH_MACFCR_PLT_Minus144 ((unsigned int)0x00000020)  /* Pause time minus 144 slot times */
#define ETH_MACFCR_PLT_Minus256 ((unsigned int)0x00000030)  /* Pause time minus 256 slot times */      
#define ETH_MACFCR_UPFD   ((unsigned int)0x00000008)  /* Unicast pause frame detect */
#define ETH_MACFCR_RFCE   ((unsigned int)0x00000004)  /* Receive flow control enable */
#define ETH_MACFCR_TFCE   ((unsigned int)0x00000002)  /* Transmit flow control enable */
#define ETH_MACFCR_FCBBPA ((unsigned int)0x00000001)  /* Flow control busy/backpressure activate */

/* Bit definition for Ethernet MAC VLAN Tag Register */
#define ETH_MACVLANTR_VLANTC ((unsigned int)0x00010000)  /* 12-bit VLAN tag comparison */
#define ETH_MACVLANTR_VLANTI ((unsigned int)0x0000FFFF)  /* VLAN tag identifier (for receive frames) */

/* Bit definition for Ethernet MAC Remote Wake-UpFrame Filter Register */ 
#define ETH_MACRWUFFR_D   ((unsigned int)0xFFFFFFFF)  /* Wake-up frame filter register data */
/* Eight sequential Writes to this address (offset 0x28) will write all Wake-UpFrame Filter Registers.
   Eight sequential Reads from this address (offset 0x28) will read all Wake-UpFrame Filter Registers. */
/* Wake-UpFrame Filter Reg0 : Filter 0 Byte Mask
   Wake-UpFrame Filter Reg1 : Filter 1 Byte Mask
   Wake-UpFrame Filter Reg2 : Filter 2 Byte Mask
   Wake-UpFrame Filter Reg3 : Filter 3 Byte Mask
   Wake-UpFrame Filter Reg4 : RSVD - Filter3 Command - RSVD - Filter2 Command - 
   RSVD - Filter1 Command - RSVD - Filter0 Command
   Wake-UpFrame Filter Re5 : Filter3 Offset - Filter2 Offset - Filter1 Offset - Filter0 Offset
   Wake-UpFrame Filter Re6 : Filter1 CRC16 - Filter0 CRC16
   Wake-UpFrame Filter Re7 : Filter3 CRC16 - Filter2 CRC16 */

/* Bit definition for Ethernet MAC PMT Control and Status Register */ 
#define ETH_MACPMTCSR_WFFRPR ((unsigned int)0x80000000)  /* Wake-Up Frame Filter Register Pointer Reset */
#define ETH_MACPMTCSR_GU     ((unsigned int)0x00000200)  /* Global Unicast */
#define ETH_MACPMTCSR_WFR    ((unsigned int)0x00000040)  /* Wake-Up Frame Received */
#define ETH_MACPMTCSR_MPR    ((unsigned int)0x00000020)  /* Magic Packet Received */
#define ETH_MACPMTCSR_WFE    ((unsigned int)0x00000004)  /* Wake-Up Frame Enable */
#define ETH_MACPMTCSR_MPE    ((unsigned int)0x00000002)  /* Magic Packet Enable */
#define ETH_MACPMTCSR_PD     ((unsigned int)0x00000001)  /* Power Down */

/* Bit definition for Ethernet MAC Status Register */
#define ETH_MACSR_TSTS      ((unsigned int)0x00000200)  /* Time stamp trigger status */
#define ETH_MACSR_MMCTS     ((unsigned int)0x00000040)  /* MMC transmit status */
#define ETH_MACSR_MMMCRS    ((unsigned int)0x00000020)  /* MMC receive status */
#define ETH_MACSR_MMCS      ((unsigned int)0x00000010)  /* MMC status */
#define ETH_MACSR_PMTS      ((unsigned int)0x00000008)  /* PMT status */

/* Bit definition for Ethernet MAC Interrupt Mask Register */
#define ETH_MACIMR_TSTIM     ((unsigned int)0x00000200)  /* Time stamp trigger interrupt mask */
#define ETH_MACIMR_PMTIM     ((unsigned int)0x00000008)  /* PMT interrupt mask */

/* Bit definition for Ethernet MAC Address0 High Register */
#define ETH_MACA0HR_MACA0H   ((unsigned int)0x0000FFFF)  /* MAC address0 high */

/* Bit definition for Ethernet MAC Address0 Low Register */
#define ETH_MACA0LR_MACA0L   ((unsigned int)0xFFFFFFFF)  /* MAC address0 low */

/* Bit definition for Ethernet MAC Address1 High Register */
#define ETH_MACA1HR_AE       ((unsigned int)0x80000000)  /* Address enable */
#define ETH_MACA1HR_SA       ((unsigned int)0x40000000)  /* Source address */
#define ETH_MACA1HR_MBC      ((unsigned int)0x3F000000)  /* Mask byte control: bits to mask for comparison of the MAC Address bytes */
#define ETH_MACA1HR_MBC_HBits15_8    ((unsigned int)0x20000000)  /* Mask MAC Address high reg bits [15:8] */
#define ETH_MACA1HR_MBC_HBits7_0     ((unsigned int)0x10000000)  /* Mask MAC Address high reg bits [7:0] */
#define ETH_MACA1HR_MBC_LBits31_24   ((unsigned int)0x08000000)  /* Mask MAC Address low reg bits [31:24] */
#define ETH_MACA1HR_MBC_LBits23_16   ((unsigned int)0x04000000)  /* Mask MAC Address low reg bits [23:16] */
#define ETH_MACA1HR_MBC_LBits15_8    ((unsigned int)0x02000000)  /* Mask MAC Address low reg bits [15:8] */
#define ETH_MACA1HR_MBC_LBits7_0     ((unsigned int)0x01000000)  /* Mask MAC Address low reg bits [7:0] */ 
#define ETH_MACA1HR_MACA1H   ((unsigned int)0x0000FFFF)  /* MAC address1 high */

/* Bit definition for Ethernet MAC Address1 Low Register */
#define ETH_MACA1LR_MACA1L   ((unsigned int)0xFFFFFFFF)  /* MAC address1 low */

/* Bit definition for Ethernet MAC Address2 High Register */
#define ETH_MACA2HR_AE       ((unsigned int)0x80000000)  /* Address enable */
#define ETH_MACA2HR_SA       ((unsigned int)0x40000000)  /* Source address */
#define ETH_MACA2HR_MBC      ((unsigned int)0x3F000000)  /* Mask byte control */
#define ETH_MACA2HR_MBC_HBits15_8    ((unsigned int)0x20000000)  /* Mask MAC Address high reg bits [15:8] */
#define ETH_MACA2HR_MBC_HBits7_0     ((unsigned int)0x10000000)  /* Mask MAC Address high reg bits [7:0] */
#define ETH_MACA2HR_MBC_LBits31_24   ((unsigned int)0x08000000)  /* Mask MAC Address low reg bits [31:24] */
#define ETH_MACA2HR_MBC_LBits23_16   ((unsigned int)0x04000000)  /* Mask MAC Address low reg bits [23:16] */
#define ETH_MACA2HR_MBC_LBits15_8    ((unsigned int)0x02000000)  /* Mask MAC Address low reg bits [15:8] */
#define ETH_MACA2HR_MBC_LBits7_0     ((unsigned int)0x01000000)  /* Mask MAC Address low reg bits [70] */
#define ETH_MACA2HR_MACA2H   ((unsigned int)0x0000FFFF)  /* MAC address1 high */

/* Bit definition for Ethernet MAC Address2 Low Register */
#define ETH_MACA2LR_MACA2L   ((unsigned int)0xFFFFFFFF)  /* MAC address2 low */

/* Bit definition for Ethernet MAC Address3 High Register */
#define ETH_MACA3HR_AE       ((unsigned int)0x80000000)  /* Address enable */
#define ETH_MACA3HR_SA       ((unsigned int)0x40000000)  /* Source address */
#define ETH_MACA3HR_MBC      ((unsigned int)0x3F000000)  /* Mask byte control */
#define ETH_MACA3HR_MBC_HBits15_8    ((unsigned int)0x20000000)  /* Mask MAC Address high reg bits [15:8] */
#define ETH_MACA3HR_MBC_HBits7_0     ((unsigned int)0x10000000)  /* Mask MAC Address high reg bits [7:0] */
#define ETH_MACA3HR_MBC_LBits31_24   ((unsigned int)0x08000000)  /* Mask MAC Address low reg bits [31:24] */
#define ETH_MACA3HR_MBC_LBits23_16   ((unsigned int)0x04000000)  /* Mask MAC Address low reg bits [23:16] */
#define ETH_MACA3HR_MBC_LBits15_8    ((unsigned int)0x02000000)  /* Mask MAC Address low reg bits [15:8] */
#define ETH_MACA3HR_MBC_LBits7_0     ((unsigned int)0x01000000)  /* Mask MAC Address low reg bits [70] */
#define ETH_MACA3HR_MACA3H   ((unsigned int)0x0000FFFF)  /* MAC address3 high */

/* Bit definition for Ethernet MAC Address3 Low Register */
#define ETH_MACA3LR_MACA3L   ((unsigned int)0xFFFFFFFF)  /* MAC address3 low */

/******************************************************************************/
/*                Ethernet MMC Registers bits definition                      */
/******************************************************************************/

/* Bit definition for Ethernet MMC Contol Register */
#define ETH_MMCCR_MCFHP      ((unsigned int)0x00000020)  /* MMC counter Full-Half preset */
#define ETH_MMCCR_MCP        ((unsigned int)0x00000010)  /* MMC counter preset */
#define ETH_MMCCR_MCF        ((unsigned int)0x00000008)  /* MMC Counter Freeze */
#define ETH_MMCCR_ROR        ((unsigned int)0x00000004)  /* Reset on Read */
#define ETH_MMCCR_CSR        ((unsigned int)0x00000002)  /* Counter Stop Rollover */
#define ETH_MMCCR_CR         ((unsigned int)0x00000001)  /* Counters Reset */

/* Bit definition for Ethernet MMC Receive Interrupt Register */
#define ETH_MMCRIR_RGUFS     ((unsigned int)0x00020000)  /* Set when Rx good unicast frames counter reaches half the maximum value */
#define ETH_MMCRIR_RFAES     ((unsigned int)0x00000040)  /* Set when Rx alignment error counter reaches half the maximum value */
#define ETH_MMCRIR_RFCES     ((unsigned int)0x00000020)  /* Set when Rx crc error counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Transmit Interrupt Register */
#define ETH_MMCTIR_TGFS      ((unsigned int)0x00200000)  /* Set when Tx good frame count counter reaches half the maximum value */
#define ETH_MMCTIR_TGFMSCS   ((unsigned int)0x00008000)  /* Set when Tx good multi col counter reaches half the maximum value */
#define ETH_MMCTIR_TGFSCS    ((unsigned int)0x00004000)  /* Set when Tx good single col counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Receive Interrupt Mask Register */
#define ETH_MMCRIMR_RGUFM    ((unsigned int)0x00020000)  /* Mask the interrupt when Rx good unicast frames counter reaches half the maximum value */
#define ETH_MMCRIMR_RFAEM    ((unsigned int)0x00000040)  /* Mask the interrupt when when Rx alignment error counter reaches half the maximum value */
#define ETH_MMCRIMR_RFCEM    ((unsigned int)0x00000020)  /* Mask the interrupt when Rx crc error counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Transmit Interrupt Mask Register */
#define ETH_MMCTIMR_TGFM     ((unsigned int)0x00200000)  /* Mask the interrupt when Tx good frame count counter reaches half the maximum value */
#define ETH_MMCTIMR_TGFMSCM  ((unsigned int)0x00008000)  /* Mask the interrupt when Tx good multi col counter reaches half the maximum value */
#define ETH_MMCTIMR_TGFSCM   ((unsigned int)0x00004000)  /* Mask the interrupt when Tx good single col counter reaches half the maximum value */

/* Bit definition for Ethernet MMC Transmitted Good Frames after Single Collision Counter Register */
#define ETH_MMCTGFSCCR_TGFSCC     ((unsigned int)0xFFFFFFFF)  /* Number of successfully transmitted frames after a single collision in Half-duplex mode. */

/* Bit definition for Ethernet MMC Transmitted Good Frames after More than a Single Collision Counter Register */
#define ETH_MMCTGFMSCCR_TGFMSCC   ((unsigned int)0xFFFFFFFF)  /* Number of successfully transmitted frames after more than a single collision in Half-duplex mode. */

/* Bit definition for Ethernet MMC Transmitted Good Frames Counter Register */
#define ETH_MMCTGFCR_TGFC    ((unsigned int)0xFFFFFFFF)  /* Number of good frames transmitted. */

/* Bit definition for Ethernet MMC Received Frames with CRC Error Counter Register */
#define ETH_MMCRFCECR_RFCEC  ((unsigned int)0xFFFFFFFF)  /* Number of frames received with CRC error. */

/* Bit definition for Ethernet MMC Received Frames with Alignement Error Counter Register */
#define ETH_MMCRFAECR_RFAEC  ((unsigned int)0xFFFFFFFF)  /* Number of frames received with alignment (dribble) error */

/* Bit definition for Ethernet MMC Received Good Unicast Frames Counter Register */
#define ETH_MMCRGUFCR_RGUFC  ((unsigned int)0xFFFFFFFF)  /* Number of good unicast frames received. */

/******************************************************************************/
/*               Ethernet PTP Registers bits definition                       */
/******************************************************************************/

/* Bit definition for Ethernet PTP Time Stamp Contol Register */
#define ETH_PTPTSCR_TSCNT       ((unsigned int)0x00030000)  /* Time stamp clock node type */
#define ETH_PTPTSSR_TSSMRME     ((unsigned int)0x00008000)  /* Time stamp snapshot for message relevant to master enable */
#define ETH_PTPTSSR_TSSEME      ((unsigned int)0x00004000)  /* Time stamp snapshot for event message enable */
#define ETH_PTPTSSR_TSSIPV4FE   ((unsigned int)0x00002000)  /* Time stamp snapshot for IPv4 frames enable */
#define ETH_PTPTSSR_TSSIPV6FE   ((unsigned int)0x00001000)  /* Time stamp snapshot for IPv6 frames enable */
#define ETH_PTPTSSR_TSSPTPOEFE  ((unsigned int)0x00000800)  /* Time stamp snapshot for PTP over ethernet frames enable */
#define ETH_PTPTSSR_TSPTPPSV2E  ((unsigned int)0x00000400)  /* Time stamp PTP packet snooping for version2 format enable */
#define ETH_PTPTSSR_TSSSR       ((unsigned int)0x00000200)  /* Time stamp Sub-seconds rollover */
#define ETH_PTPTSSR_TSSARFE     ((unsigned int)0x00000100)  /* Time stamp snapshot for all received frames enable */

#define ETH_PTPTSCR_TSARU    ((unsigned int)0x00000020)  /* Addend register update */
#define ETH_PTPTSCR_TSITE    ((unsigned int)0x00000010)  /* Time stamp interrupt trigger enable */
#define ETH_PTPTSCR_TSSTU    ((unsigned int)0x00000008)  /* Time stamp update */
#define ETH_PTPTSCR_TSSTI    ((unsigned int)0x00000004)  /* Time stamp initialize */
#define ETH_PTPTSCR_TSFCU    ((unsigned int)0x00000002)  /* Time stamp fine or coarse update */
#define ETH_PTPTSCR_TSE      ((unsigned int)0x00000001)  /* Time stamp enable */

/* Bit definition for Ethernet PTP Sub-Second Increment Register */
#define ETH_PTPSSIR_STSSI    ((unsigned int)0x000000FF)  /* System time Sub-second increment value */

/* Bit definition for Ethernet PTP Time Stamp High Register */
#define ETH_PTPTSHR_STS      ((unsigned int)0xFFFFFFFF)  /* System Time second */

/* Bit definition for Ethernet PTP Time Stamp Low Register */
#define ETH_PTPTSLR_STPNS    ((unsigned int)0x80000000)  /* System Time Positive or negative time */
#define ETH_PTPTSLR_STSS     ((unsigned int)0x7FFFFFFF)  /* System Time sub-seconds */

/* Bit definition for Ethernet PTP Time Stamp High Update Register */
#define ETH_PTPTSHUR_TSUS    ((unsigned int)0xFFFFFFFF)  /* Time stamp update seconds */

/* Bit definition for Ethernet PTP Time Stamp Low Update Register */
#define ETH_PTPTSLUR_TSUPNS  ((unsigned int)0x80000000)  /* Time stamp update Positive or negative time */
#define ETH_PTPTSLUR_TSUSS   ((unsigned int)0x7FFFFFFF)  /* Time stamp update sub-seconds */

/* Bit definition for Ethernet PTP Time Stamp Addend Register */
#define ETH_PTPTSAR_TSA      ((unsigned int)0xFFFFFFFF)  /* Time stamp addend */

/* Bit definition for Ethernet PTP Target Time High Register */
#define ETH_PTPTTHR_TTSH     ((unsigned int)0xFFFFFFFF)  /* Target time stamp high */

/* Bit definition for Ethernet PTP Target Time Low Register */
#define ETH_PTPTTLR_TTSL     ((unsigned int)0xFFFFFFFF)  /* Target time stamp low */

/* Bit definition for Ethernet PTP Time Stamp Status Register */
#define ETH_PTPTSSR_TSTTR    ((unsigned int)0x00000020)  /* Time stamp target time reached */
#define ETH_PTPTSSR_TSSO     ((unsigned int)0x00000010)  /* Time stamp seconds overflow */

/******************************************************************************/
/*                 Ethernet DMA Registers bits definition                     */
/******************************************************************************/

/* Bit definition for Ethernet DMA Bus Mode Register */
#define ETH_DMABMR_AAB       ((unsigned int)0x02000000)  /* Address-Aligned beats */
#define ETH_DMABMR_FPM        ((unsigned int)0x01000000)  /* 4xPBL mode */
#define ETH_DMABMR_USP       ((unsigned int)0x00800000)  /* Use separate PBL */
#define ETH_DMABMR_RDP       ((unsigned int)0x007E0000)  /* RxDMA PBL */
#define ETH_DMABMR_RDP_1Beat    ((unsigned int)0x00020000)  /* maximum number of beats to be transferred in one RxDMA transaction is 1 */
#define ETH_DMABMR_RDP_2Beat    ((unsigned int)0x00040000)  /* maximum number of beats to be transferred in one RxDMA transaction is 2 */
#define ETH_DMABMR_RDP_4Beat    ((unsigned int)0x00080000)  /* maximum number of beats to be transferred in one RxDMA transaction is 4 */
#define ETH_DMABMR_RDP_8Beat    ((unsigned int)0x00100000)  /* maximum number of beats to be transferred in one RxDMA transaction is 8 */
#define ETH_DMABMR_RDP_16Beat   ((unsigned int)0x00200000)  /* maximum number of beats to be transferred in one RxDMA transaction is 16 */
#define ETH_DMABMR_RDP_32Beat   ((unsigned int)0x00400000)  /* maximum number of beats to be transferred in one RxDMA transaction is 32 */                
#define ETH_DMABMR_RDP_4xPBL_4Beat   ((unsigned int)0x01020000)  /* maximum number of beats to be transferred in one RxDMA transaction is 4 */
#define ETH_DMABMR_RDP_4xPBL_8Beat   ((unsigned int)0x01040000)  /* maximum number of beats to be transferred in one RxDMA transaction is 8 */
#define ETH_DMABMR_RDP_4xPBL_16Beat  ((unsigned int)0x01080000)  /* maximum number of beats to be transferred in one RxDMA transaction is 16 */
#define ETH_DMABMR_RDP_4xPBL_32Beat  ((unsigned int)0x01100000)  /* maximum number of beats to be transferred in one RxDMA transaction is 32 */
#define ETH_DMABMR_RDP_4xPBL_64Beat  ((unsigned int)0x01200000)  /* maximum number of beats to be transferred in one RxDMA transaction is 64 */
#define ETH_DMABMR_RDP_4xPBL_128Beat ((unsigned int)0x01400000)  /* maximum number of beats to be transferred in one RxDMA transaction is 128 */  
#define ETH_DMABMR_FB        ((unsigned int)0x00010000)  /* Fixed Burst */
#define ETH_DMABMR_RTPR      ((unsigned int)0x0000C000)  /* Rx Tx priority ratio */
#define ETH_DMABMR_RTPR_1_1     ((unsigned int)0x00000000)  /* Rx Tx priority ratio */
#define ETH_DMABMR_RTPR_2_1     ((unsigned int)0x00004000)  /* Rx Tx priority ratio */
#define ETH_DMABMR_RTPR_3_1     ((unsigned int)0x00008000)  /* Rx Tx priority ratio */
#define ETH_DMABMR_RTPR_4_1     ((unsigned int)0x0000C000)  /* Rx Tx priority ratio */  
#define ETH_DMABMR_PBL    ((unsigned int)0x00003F00)  /* Programmable burst length */
#define ETH_DMABMR_PBL_1Beat    ((unsigned int)0x00000100)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 1 */
#define ETH_DMABMR_PBL_2Beat    ((unsigned int)0x00000200)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 2 */
#define ETH_DMABMR_PBL_4Beat    ((unsigned int)0x00000400)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 4 */
#define ETH_DMABMR_PBL_8Beat    ((unsigned int)0x00000800)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 8 */
#define ETH_DMABMR_PBL_16Beat   ((unsigned int)0x00001000)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 16 */
#define ETH_DMABMR_PBL_32Beat   ((unsigned int)0x00002000)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 32 */                
#define ETH_DMABMR_PBL_4xPBL_4Beat   ((unsigned int)0x01000100)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 4 */
#define ETH_DMABMR_PBL_4xPBL_8Beat   ((unsigned int)0x01000200)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 8 */
#define ETH_DMABMR_PBL_4xPBL_16Beat  ((unsigned int)0x01000400)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 16 */
#define ETH_DMABMR_PBL_4xPBL_32Beat  ((unsigned int)0x01000800)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 32 */
#define ETH_DMABMR_PBL_4xPBL_64Beat  ((unsigned int)0x01001000)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 64 */
#define ETH_DMABMR_PBL_4xPBL_128Beat ((unsigned int)0x01002000)  /* maximum number of beats to be transferred in one TxDMA (or both) transaction is 128 */
#define ETH_DMABMR_EDE       ((unsigned int)0x00000080)  /* Enhanced Descriptor Enable */
#define ETH_DMABMR_DSL       ((unsigned int)0x0000007C)  /* Descriptor Skip Length */
#define ETH_DMABMR_DA        ((unsigned int)0x00000002)  /* DMA arbitration scheme */
#define ETH_DMABMR_SR        ((unsigned int)0x00000001)  /* Software reset */

/* Bit definition for Ethernet DMA Transmit Poll Demand Register */
#define ETH_DMATPDR_TPD      ((unsigned int)0xFFFFFFFF)  /* Transmit poll demand */

/* Bit definition for Ethernet DMA Receive Poll Demand Register */
#define ETH_DMARPDR_RPD      ((unsigned int)0xFFFFFFFF)  /* Receive poll demand  */

/* Bit definition for Ethernet DMA Receive Descriptor List Address Register */
#define ETH_DMARDLAR_SRL     ((unsigned int)0xFFFFFFFF)  /* Start of receive list */

/* Bit definition for Ethernet DMA Transmit Descriptor List Address Register */
#define ETH_DMATDLAR_STL     ((unsigned int)0xFFFFFFFF)  /* Start of transmit list */

/* Bit definition for Ethernet DMA Status Register */
#define ETH_DMASR_TSTS       ((unsigned int)0x20000000)  /* Time-stamp trigger status */
#define ETH_DMASR_PMTS       ((unsigned int)0x10000000)  /* PMT status */
#define ETH_DMASR_MMCS       ((unsigned int)0x08000000)  /* MMC status */
#define ETH_DMASR_EBS        ((unsigned int)0x03800000)  /* Error bits status */
/* combination with EBS[2:0] for GetFlagStatus function */
#define ETH_DMASR_EBS_DescAccess      ((unsigned int)0x02000000)  /* Error bits 0-data buffer, 1-desc. access */
#define ETH_DMASR_EBS_ReadTransf      ((unsigned int)0x01000000)  /* Error bits 0-write trnsf, 1-read transfr */
#define ETH_DMASR_EBS_DataTransfTx    ((unsigned int)0x00800000)  /* Error bits 0-Rx DMA, 1-Tx DMA */
#define ETH_DMASR_TPS         ((unsigned int)0x00700000)  /* Transmit process state */
#define ETH_DMASR_TPS_Stopped         ((unsigned int)0x00000000)  /* Stopped - Reset or Stop Tx Command issued  */
#define ETH_DMASR_TPS_Fetching        ((unsigned int)0x00100000)  /* Running - fetching the Tx descriptor */
#define ETH_DMASR_TPS_Waiting         ((unsigned int)0x00200000)  /* Running - waiting for status */
#define ETH_DMASR_TPS_Reading         ((unsigned int)0x00300000)  /* Running - reading the data from host memory */
#define ETH_DMASR_TPS_Suspended       ((unsigned int)0x00600000)  /* Suspended - Tx Descriptor unavailabe */
#define ETH_DMASR_TPS_Closing         ((unsigned int)0x00700000)  /* Running - closing Rx descriptor */
#define ETH_DMASR_RPS         ((unsigned int)0x000E0000)  /* Receive process state */
#define ETH_DMASR_RPS_Stopped         ((unsigned int)0x00000000)  /* Stopped - Reset or Stop Rx Command issued */
#define ETH_DMASR_RPS_Fetching        ((unsigned int)0x00020000)  /* Running - fetching the Rx descriptor */
#define ETH_DMASR_RPS_Waiting         ((unsigned int)0x00060000)  /* Running - waiting for packet */
#define ETH_DMASR_RPS_Suspended       ((unsigned int)0x00080000)  /* Suspended - Rx Descriptor unavailable */
#define ETH_DMASR_RPS_Closing         ((unsigned int)0x000A0000)  /* Running - closing descriptor */
#define ETH_DMASR_RPS_Queuing         ((unsigned int)0x000E0000)  /* Running - queuing the recieve frame into host memory */
#define ETH_DMASR_NIS        ((unsigned int)0x00010000)  /* Normal interrupt summary */
#define ETH_DMASR_AIS        ((unsigned int)0x00008000)  /* Abnormal interrupt summary */
#define ETH_DMASR_ERS        ((unsigned int)0x00004000)  /* Early receive status */
#define ETH_DMASR_FBES       ((unsigned int)0x00002000)  /* Fatal bus error status */
#define ETH_DMASR_ETS        ((unsigned int)0x00000400)  /* Early transmit status */
#define ETH_DMASR_RWTS       ((unsigned int)0x00000200)  /* Receive watchdog timeout status */
#define ETH_DMASR_RPSS       ((unsigned int)0x00000100)  /* Receive process stopped status */
#define ETH_DMASR_RBUS       ((unsigned int)0x00000080)  /* Receive buffer unavailable status */
#define ETH_DMASR_RS         ((unsigned int)0x00000040)  /* Receive status */
#define ETH_DMASR_TUS        ((unsigned int)0x00000020)  /* Transmit underflow status */
#define ETH_DMASR_ROS        ((unsigned int)0x00000010)  /* Receive overflow status */
#define ETH_DMASR_TJTS       ((unsigned int)0x00000008)  /* Transmit jabber timeout status */
#define ETH_DMASR_TBUS       ((unsigned int)0x00000004)  /* Transmit buffer unavailable status */
#define ETH_DMASR_TPSS       ((unsigned int)0x00000002)  /* Transmit process stopped status */
#define ETH_DMASR_TS         ((unsigned int)0x00000001)  /* Transmit status */

/* Bit definition for Ethernet DMA Operation Mode Register */
#define ETH_DMAOMR_DTCEFD    ((unsigned int)0x04000000)  /* Disable Dropping of TCP/IP checksum error frames */
#define ETH_DMAOMR_RSF       ((unsigned int)0x02000000)  /* Receive store and forward */
#define ETH_DMAOMR_DFRF      ((unsigned int)0x01000000)  /* Disable flushing of received frames */
#define ETH_DMAOMR_TSF       ((unsigned int)0x00200000)  /* Transmit store and forward */
#define ETH_DMAOMR_FTF       ((unsigned int)0x00100000)  /* Flush transmit FIFO */
#define ETH_DMAOMR_TTC       ((unsigned int)0x0001C000)  /* Transmit threshold control */
#define ETH_DMAOMR_TTC_64Bytes       ((unsigned int)0x00000000)  /* threshold level of the MTL Transmit FIFO is 64 Bytes */
#define ETH_DMAOMR_TTC_128Bytes      ((unsigned int)0x00004000)  /* threshold level of the MTL Transmit FIFO is 128 Bytes */
#define ETH_DMAOMR_TTC_192Bytes      ((unsigned int)0x00008000)  /* threshold level of the MTL Transmit FIFO is 192 Bytes */
#define ETH_DMAOMR_TTC_256Bytes      ((unsigned int)0x0000C000)  /* threshold level of the MTL Transmit FIFO is 256 Bytes */
#define ETH_DMAOMR_TTC_40Bytes       ((unsigned int)0x00010000)  /* threshold level of the MTL Transmit FIFO is 40 Bytes */
#define ETH_DMAOMR_TTC_32Bytes       ((unsigned int)0x00014000)  /* threshold level of the MTL Transmit FIFO is 32 Bytes */
#define ETH_DMAOMR_TTC_24Bytes       ((unsigned int)0x00018000)  /* threshold level of the MTL Transmit FIFO is 24 Bytes */
#define ETH_DMAOMR_TTC_16Bytes       ((unsigned int)0x0001C000)  /* threshold level of the MTL Transmit FIFO is 16 Bytes */
#define ETH_DMAOMR_ST        ((unsigned int)0x00002000)  /* Start/stop transmission command */
#define ETH_DMAOMR_FEF       ((unsigned int)0x00000080)  /* Forward error frames */
#define ETH_DMAOMR_FUGF      ((unsigned int)0x00000040)  /* Forward undersized good frames */
#define ETH_DMAOMR_RTC       ((unsigned int)0x00000018)  /* receive threshold control */
#define ETH_DMAOMR_RTC_64Bytes       ((unsigned int)0x00000000)  /* threshold level of the MTL Receive FIFO is 64 Bytes */
#define ETH_DMAOMR_RTC_32Bytes       ((unsigned int)0x00000008)  /* threshold level of the MTL Receive FIFO is 32 Bytes */
#define ETH_DMAOMR_RTC_96Bytes       ((unsigned int)0x00000010)  /* threshold level of the MTL Receive FIFO is 96 Bytes */
#define ETH_DMAOMR_RTC_128Bytes      ((unsigned int)0x00000018)  /* threshold level of the MTL Receive FIFO is 128 Bytes */
#define ETH_DMAOMR_OSF       ((unsigned int)0x00000004)  /* operate on second frame */
#define ETH_DMAOMR_SR        ((unsigned int)0x00000002)  /* Start/stop receive */

/* Bit definition for Ethernet DMA Interrupt Enable Register */
#define ETH_DMAIER_NISE      ((unsigned int)0x00010000)  /* Normal interrupt summary enable */
#define ETH_DMAIER_AISE      ((unsigned int)0x00008000)  /* Abnormal interrupt summary enable */
#define ETH_DMAIER_ERIE      ((unsigned int)0x00004000)  /* Early receive interrupt enable */
#define ETH_DMAIER_FBEIE     ((unsigned int)0x00002000)  /* Fatal bus error interrupt enable */
#define ETH_DMAIER_ETIE      ((unsigned int)0x00000400)  /* Early transmit interrupt enable */
#define ETH_DMAIER_RWTIE     ((unsigned int)0x00000200)  /* Receive watchdog timeout interrupt enable */
#define ETH_DMAIER_RPSIE     ((unsigned int)0x00000100)  /* Receive process stopped interrupt enable */
#define ETH_DMAIER_RBUIE     ((unsigned int)0x00000080)  /* Receive buffer unavailable interrupt enable */
#define ETH_DMAIER_RIE       ((unsigned int)0x00000040)  /* Receive interrupt enable */
#define ETH_DMAIER_TUIE      ((unsigned int)0x00000020)  /* Transmit Underflow interrupt enable */
#define ETH_DMAIER_ROIE      ((unsigned int)0x00000010)  /* Receive Overflow interrupt enable */
#define ETH_DMAIER_TJTIE     ((unsigned int)0x00000008)  /* Transmit jabber timeout interrupt enable */
#define ETH_DMAIER_TBUIE     ((unsigned int)0x00000004)  /* Transmit buffer unavailable interrupt enable */
#define ETH_DMAIER_TPSIE     ((unsigned int)0x00000002)  /* Transmit process stopped interrupt enable */
#define ETH_DMAIER_TIE       ((unsigned int)0x00000001)  /* Transmit interrupt enable */

/* Bit definition for Ethernet DMA Missed Frame and Buffer Overflow Counter Register */
#define ETH_DMAMFBOCR_OFOC   ((unsigned int)0x10000000)  /* Overflow bit for FIFO overflow counter */
#define ETH_DMAMFBOCR_MFA    ((unsigned int)0x0FFE0000)  /* Number of frames missed by the application */
#define ETH_DMAMFBOCR_OMFC   ((unsigned int)0x00010000)  /* Overflow bit for missed frame counter */
#define ETH_DMAMFBOCR_MFC    ((unsigned int)0x0000FFFF)  /* Number of frames missed by the controller */

/* Bit definition for Ethernet DMA Current Host Transmit Descriptor Register */
#define ETH_DMACHTDR_HTDAP   ((unsigned int)0xFFFFFFFF)  /* Host transmit descriptor address pointer */

/* Bit definition for Ethernet DMA Current Host Receive Descriptor Register */
#define ETH_DMACHRDR_HRDAP   ((unsigned int)0xFFFFFFFF)  /* Host receive descriptor address pointer */

/* Bit definition for Ethernet DMA Current Host Transmit Buffer Address Register */
#define ETH_DMACHTBAR_HTBAP  ((unsigned int)0xFFFFFFFF)  /* Host transmit buffer address pointer */

/* Bit definition for Ethernet DMA Current Host Receive Buffer Address Register */
#define ETH_DMACHRBAR_HRBAP  ((unsigned int)0xFFFFFFFF)  /* Host receive buffer address pointer */

/**
 *
 */

/** @addtogroup Exported_macro
 * @{
 */

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
 * @}
 */

#endif /* STM32F746_H */
