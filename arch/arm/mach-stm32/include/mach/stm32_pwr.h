#ifndef STM32_PWR_H
#define STM32_PWR_H

#define PWR_CR		0x0
#define PWR_CSR		0x4

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

#endif /* STM32_PWR_H */
