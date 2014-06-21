/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Mcu_Cfg.h                                                   */
/* Version      = 3.1.7                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        Xx4                                           */
/*============================================================================*/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  3.1.13
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    FK4_4010_MCU_V308_140113_HEADLAMP.arxml
 * GENERATED ON:  16 Jan 2014 - 08:46:12
 */


#ifndef MCU_CFG_H
#define MCU_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define MCU_CFG_AR_MAJOR_VERSION  2
#define MCU_CFG_AR_MINOR_VERSION  2
#define MCU_CFG_AR_PATCH_VERSION  1

/* File version information */
#define MCU_CFG_SW_MAJOR_VERSION  3
#define MCU_CFG_SW_MINOR_VERSION  0

/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define MCU_AR_MAJOR_VERSION_VALUE          2
#define MCU_AR_MINOR_VERSION_VALUE          2
#define MCU_AR_PATCH_VERSION_VALUE          1

#define MCU_SW_MAJOR_VERSION_VALUE          3
#define MCU_SW_MINOR_VERSION_VALUE          0
#define MCU_SW_PATCH_VERSION_VALUE          0

#define MCU_VENDOR_ID_VALUE                 23
#define MCU_MODULE_ID_VALUE                 101

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the MCU Driver */
#define MCU_INSTANCE_ID_VALUE               0

/* Pre-compile option for the development error detection and reporting */
#define MCU_DEV_ERROR_DETECT                STD_OFF

/* Pre-compile option for Mcu_GetVersion API */
#define MCU_VERSION_INFO_API                STD_OFF

/* Pre-compile option for Mcu_PerformReset API */
#define MCU_PERFORM_RESET_API               STD_OFF

/* Pre-compile option for the critical section functionality */
#define MCU_CRITICAL_SECTION_PROTECTION     STD_ON

/* Pre-compile option for the store-restore feature of port pin status */
#define MCU_PORTGROUP_STATUS_BACKUP         STD_OFF

/* Pre-compile option for the WAKE pin functionality for DEEPSTOP_MODE */
#define MCU_DEEPSTOP_WAKE_PIN               STD_OFF

/* Pre-compile option for the IO buffer power supply during DEEPSTOP_MODE */
#define MCU_DEEPSTOP_IOBUFFER_SUPPLY        STD_OFF

/* Pre-compile option for the DEEPSTOP with Forced-Isolated-Area-0 DEEPSTOP */
#define MCU_FORCED_ISO0_DEEPSTOP            STD_OFF

/* Pre-compile option for the MainOsc */
#define MCU_MAINOSC_ENABLE                  STD_ON

/* Pre-compile option for the SubOsc */
#define MCU_SUBOSC_ENABLE                   STD_ON

/* Pre-compile option for the High Speed IntOsc */
#define MCU_HIGHSPEED_RINGOSC_ENABLE        STD_ON

/* Pre-compile option for the PLL0 */
#define MCU_PLL0_ENABLE                     STD_ON

/* Pre-compile option for the PLL1 */
#define MCU_PLL1_ENABLE                     STD_ON

/* Pre-compile option for the PLL2 */
#define MCU_PLL2_ENABLE                     STD_ON

/* Pre-compile option for the IORES0 */
#define MCU_IORES0_ENABLE                   STD_OFF

/* Pre-compile option for the IORES1 */
#define MCU_IORES1_ENABLE                   STD_OFF

/* Pre-compile option for the VCPC0CTL0 */
#define MCU_VCPC0CTL0_ENABLE                STD_ON

/* Pre-compile option for the VCPC0CTL1 */
#define MCU_VCPC0CTL1_ENABLE                STD_ON

/* Loop Count Value for the MCULOOPCOUNT */
#define MCU_LOOPCOUNT_VALUE                 

/* Pbus Count Value for the MCUPBUSWAITCOUNT */
#define MCU_PBUSWAITCOUNT_VALUE             0

/* Pre compile option for Graphics Mode Reset */
#define MCU_GFX_SUPPORT                     STD_OFF

/* Control register value to configure PLL0 with 40 Mhz for ISO1 SW wakeup  */
#define MCU_ISO1WUP_PLLC0_VAL               8389395

/* Precompile option for Iohold Mask */
#define MCU_IOHOLDMASK_REQ                  STD_OFF


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Maximum number of RAM Settings */
#define MCU_MAX_RAMSETTING                  (Mcu_RamSectionType)1

/* Handles for RAM sector setting */
#define MCU_RAM_SETTING_0                   (Mcu_RamSectionType)0

/* Configuration Set Handles */
#define McuModuleConfiguration0 (&Mcu_GstConfiguration[0])
#define McuModuleConfiguration1 (&Mcu_GstConfiguration[1])

/* Mode Setting Handles */
#define McuModeSettingConf0 (Mcu_ModeType)0x00
#define McuModeSettingConf1 (Mcu_ModeType)0x01

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_CFG_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

