/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Adc_Cfg.h                                                   */
/* Version      = 3.1.2                                                       */
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
 * TOOL VERSION:    3.1.7
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    FK4_4010_ADC_V308_140113_HEADLAMP.arxml
 *                FK4_4010_MCU_V308_140113_HEADLAMP.arxml
 * GENERATED ON:  14 Jan 2014 - 09:27:57
 */

#ifndef ADC_CFG_H
#define ADC_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define ADC_CFG_AR_MAJOR_VERSION  3
#define ADC_CFG_AR_MINOR_VERSION  0
#define ADC_CFG_AR_PATCH_VERSION  1

/* File version information */
#define ADC_CFG_SW_MAJOR_VERSION       3
#define ADC_CFG_SW_MINOR_VERSION       1

/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define ADC_AR_MAJOR_VERSION_VALUE     3
#define ADC_AR_MINOR_VERSION_VALUE     0
#define ADC_AR_PATCH_VERSION_VALUE     1

#define ADC_SW_MAJOR_VERSION_VALUE     3
#define ADC_SW_MINOR_VERSION_VALUE     1
#define ADC_SW_PATCH_VERSION_VALUE     3

#define ADC_VENDOR_ID_VALUE            23
#define ADC_MODULE_ID_VALUE            123


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the ADC Driver */
#define ADC_INSTANCE_ID_VALUE                     0

/* Enables/Disables Development error detection */
#define ADC_DEV_ERROR_DETECT                       STD_OFF

/* Enables/Disables GetVersionInfo API */
#define ADC_VERSION_INFO_API                       STD_OFF

/* Enables/Disables the inclusion of Adc_DeInit API */
#define ADC_DEINIT_API                             STD_OFF

/* Enables/Disables the inclusion of first come first serve 
          mechanism */
#define ADC_ENABLE_QUEUING                         STD_OFF

/* Enables/Disables Adc_StartGroupConversion and Adc_StopGroupConversion
          functions */
#define ADC_ENABLE_START_STOP_GROUP_API            STD_ON

/* Enables/Disables Adc_EnableHardwareTrigger and
          Adc_DisableHardwareTrigger functions */
#define ADC_HW_TRIGGER_API                         STD_OFF

/* Enables/Disables Adc_ReadGroup function */
#define ADC_READ_GROUP_API                         STD_OFF

/* Enables/Disables Notification functions */
#define ADC_GRP_NOTIF_CAPABILITY                   STD_OFF

/* Enables/Disables priority mechanism functions */
#define ADC_PRIORITY_IMPLEMENTATION                ADC_PRIORITY_NONE

/* Number of hardware units configured */
#define ADC_MAX_HW_UNITS                           2

/* Enables/Disables DMA ISR for DMA channel 1 */
#define ADC_DMA_MODE_ENABLE                        STD_OFF

/* Enables/Disables the enter/exit critical section functionality */
#define ADC_CRITICAL_SECTION_PROTECTION            STD_ON

/* Enables/Disables ISR for CG0 unit of HW 0 */
#define ADC0_CG0_ISR_API                           STD_ON

/* Enables/Disables ISR for CG1 unit of HW 0 */
#define ADC0_CG1_ISR_API                           STD_OFF

/* Enables/Disables ISR for CG2 unit of HW 0 */
#define ADC0_CG2_ISR_API                           STD_OFF

/* Enables/Disables ISR for CG0 unit of HW 1 */
#define ADC1_CG0_ISR_API                           STD_ON

/* Enables/Disables ISR for CG1 unit of HW 1 */
#define ADC1_CG1_ISR_API                           STD_OFF

/* Enables/Disables ISR for CG2 unit of HW 1 */
#define ADC1_CG2_ISR_API                           STD_OFF

/* Enables/Disables DMA ISR for DMA channel 0 */
#define ADC_DMA_ISR_CH0_API                        STD_OFF

/* Enables/Disables DMA ISR for DMA channel 1 */
#define ADC_DMA_ISR_CH1_API                        STD_OFF

/* Enables/Disables DMA ISR for DMA channel 2 */
#define ADC_DMA_ISR_CH2_API                        STD_OFF

/* Enables/Disables DMA ISR for DMA channel 3 */
#define ADC_DMA_ISR_CH3_API                        STD_OFF

/* Enables/Disables DMA ISR for DMA channel 4 */
#define ADC_DMA_ISR_CH4_API                        STD_OFF

/* Enables/Disables DMA ISR for DMA channel 5 */
#define ADC_DMA_ISR_CH5_API                        STD_OFF

/* Enables/Disables DMA ISR for DMA channel 6 */
#define ADC_DMA_ISR_CH6_API                        STD_OFF

/* Enables/Disables DMA ISR for DMA channel 7 */
#define ADC_DMA_ISR_CH7_API                        STD_OFF

/* Enables/Disables DMA ISR for DMA channel 8 */
#define ADC_DMA_ISR_CH8_API                        STD_OFF

/* Enables/Disables DMA ISR for DMA channel 9 */
#define ADC_DMA_ISR_CH9_API                        STD_OFF

/* Enables/Disables DMA ISR for DMA channel 10 */
#define ADC_DMA_ISR_CH10_API                       STD_OFF

/* Enables/Disables DMA ISR for DMA channel 11 */
#define ADC_DMA_ISR_CH11_API                       STD_OFF

/* Enables/Disables DMA ISR for DMA channel 12 */
#define ADC_DMA_ISR_CH12_API                       STD_OFF

/* Enables/Disables DMA ISR for DMA channel 13 */
#define ADC_DMA_ISR_CH13_API                       STD_OFF

/* Enables/Disables DMA ISR for DMA channel 14 */
#define ADC_DMA_ISR_CH14_API                       STD_OFF

/* Enables/Disables DMA ISR for DMA channel 15 */
#define ADC_DMA_ISR_CH15_API                       STD_OFF

/* Maximum number of Groups configured */
#define ADC_MAX_GROUPS                             2

/* Enables/Disables the diagnostic channel functionality */
#define ADC_DIAG_CHANNEL_SUPPORTED                 STD_OFF

/* Enables/Disables the timer connection functionality */
#define ADC_TO_TIMER_CONNECT_SUPPORT               STD_OFF

/* Number of CGm units enabled */
#define ADC_NUMBER_OF_CG_UNITS                     (uint8)1

/* Represents CPU core */
#define ADC_CPU_CORE                               ADC_E2M

/* ADC Channel Group Handles */
#define AdcGroup0              0x00
#define AdcGroup1              0x01

/* Configuration Set Handles */
#define AdcConfigSet0  &Adc_GstConfiguration[0]


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ADC_CFG_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
