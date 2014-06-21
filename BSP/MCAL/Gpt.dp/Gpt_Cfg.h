/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Gpt_Cfg.h                                                   */
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
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  3.1.6
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    FK4_4010_GPT_V308_140113_HEADLAMP.arxml
 * GENERATED ON:  15 Jan 2014 - 13:14:57
 */
#ifndef GPT_CFG_H
#define GPT_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define GPT_CFG_AR_MAJOR_VERSION  2
#define GPT_CFG_AR_MINOR_VERSION  2
#define GPT_CFG_AR_PATCH_VERSION  0
/*
 * File version information
 */
#define GPT_CFG_SW_MAJOR_VERSION       3
#define GPT_CFG_SW_MINOR_VERSION       1

/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define GPT_AR_MAJOR_VERSION_VALUE  2
#define GPT_AR_MINOR_VERSION_VALUE  2
#define GPT_AR_PATCH_VERSION_VALUE  0

#define GPT_SW_MAJOR_VERSION_VALUE  3
#define GPT_SW_MINOR_VERSION_VALUE  1
#define GPT_SW_PATCH_VERSION_VALUE  2

#define GPT_VENDOR_ID_VALUE  23
#define GPT_MODULE_ID_VALUE  100


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the Gpt Component*/
#define GPT_INSTANCE_ID_VALUE          0

/* Enables/Disables Development error detection */
#define GPT_DEV_ERROR_DETECT                STD_OFF

/* Enables/Disables wakeup source reporting */
#define GPT_REPORT_WAKEUP_SOURCE            STD_OFF

/* Enables/Disables the inclusion of Gpt_DeInit API */
#define GPT_DE_INIT_API                     STD_ON

/* Enables/Disables inclusion of Gpt_GetTimeElapsed API */
#define GPT_TIME_ELAPSED_API                STD_ON

/* Enables/Disables inclusion of Gpt_GetTimeRemaining API */
#define GPT_TIME_REMAINING_API              STD_ON

/* Enables/Disables GetVersionInfo API */
#define GPT_VERSION_INFO_API                STD_OFF

/* Enables/Disables inclusion of Gpt_EnableNotification
              and Gpt_DisableNotification */
#define GPT_ENABLE_DISABLE_NOTIFICATION_API STD_ON

/* Enables/Disables inclusion of Gpt_SetMode, Gpt_EnableWakeup and
             Gpt_DisableWakeup */
#define GPT_WAKEUP_FUNCTIONALITY_API        STD_OFF

/* Enable/disable the Critical section protection */
#define GPT_CRITICAL_SECTION_PROTECTION     STD_ON

/* Enable/disable the setting of Prescaler, baudrate and
                blConfigurePrescaler by the GPT Driver */
#define GPT_CONFIG_PRESCALER_SUPPORTED      STD_OFF

/* Enable/Disable the TAUA unit depending on the TAUA channels configured */
#define GPT_TAUA_UNIT_USED                  STD_OFF

/* Enable/Disable the TAUB unit depending on the TAUB channels configured */
#define GPT_TAUB_UNIT_USED                  STD_OFF

/* Enable/Disable the TAUC unit depending on the TAUC channels configured */
#define GPT_TAUC_UNIT_USED                  STD_OFF

/* Enable/Disable the TAUJ unit depending on the TAUJ channels configured */
#define GPT_TAUJ_UNIT_USED                  STD_ON

/* Enable/Disable the GPT OSTM unit depending on the OSTM channel */
#define GPT_OSTM_UNIT_USED                  STD_OFF

/* Total number of GPT TAUA and TAUJ units configured */
#define GPT_TOTAL_TAU_UNITS_CONFIGURED      1

/* Total number of GPT TAUA units configured */
#define GPT_TOTAL_TAUA_UNITS_CONFIG         0

/* Total number of GPT TAUB units configured */
#define GPT_TOTAL_TAUB_UNITS_CONFIG         0

/* Total number of GPT TAUC units configured */
#define GPT_TOTAL_TAUC_UNITS_CONFIG         0

/* Total number of GPT TAUJ units configured */
#define GPT_TOTAL_TAUJ_UNITS_CONFIG         1

/* Total number of GPT TAUA channels configured */
#define GPT_TOTAL_TAUA_CHANNELS_CONFIG      0

/* Total number of GPT TAUB channels configured */
#define GPT_TOTAL_TAUB_CHANNELS_CONFIG      0

/* Total number of GPT TAUC channels configured */
#define GPT_TOTAL_TAUC_CHANNELS_CONFIG      0

/* Total number of GPT  TAUA, TAUB and TAUC channels configured */
#define GPT_TOTAL_TAUABC_CHANNELS_CONFIG    0

/* Total number of GPT  TAUA, TAUB and TAUC units configured */
#define GPT_TOTAL_TAUABC_UNITS_CONFIG       0

/* Total number of GPT TAUJ channels configured */
#define GPT_TOTAL_TAUJ_CHANNELS_CONFIG      1

/* Total number of GPT Channels configured */
#define GPT_TOTAL_CHANNELS_CONFIG           1

/* Total number of GPT OSTM unit depending on the OSTM channel configured */
#define GPT_TOTAL_OSTM_UNITS_CONFIGURED     0

/* Maximum GPT Channel ID configure */
#define GPT_MAX_CHANNEL_ID_CONFIGURED       144


/* Macros for enabling/disabling ISRS */
#define GPT_OSTM0_CH0_ISR_API    STD_OFF
#define GPT_OSTM1_CH0_ISR_API    STD_OFF
#define GPT_TAUA0_CH0_ISR_API    STD_OFF
#define GPT_TAUA0_CH10_ISR_API    STD_OFF
#define GPT_TAUA0_CH11_ISR_API    STD_OFF
#define GPT_TAUA0_CH12_ISR_API    STD_OFF
#define GPT_TAUA0_CH13_ISR_API    STD_OFF
#define GPT_TAUA0_CH14_ISR_API    STD_OFF
#define GPT_TAUA0_CH15_ISR_API    STD_OFF
#define GPT_TAUA0_CH1_ISR_API    STD_OFF
#define GPT_TAUA0_CH2_ISR_API    STD_OFF
#define GPT_TAUA0_CH3_ISR_API    STD_OFF
#define GPT_TAUA0_CH4_ISR_API    STD_OFF
#define GPT_TAUA0_CH5_ISR_API    STD_OFF
#define GPT_TAUA0_CH6_ISR_API    STD_OFF
#define GPT_TAUA0_CH7_ISR_API    STD_OFF
#define GPT_TAUA0_CH8_ISR_API    STD_OFF
#define GPT_TAUA0_CH9_ISR_API    STD_OFF
#define GPT_TAUA1_CH0_ISR_API    STD_OFF
#define GPT_TAUA1_CH10_ISR_API    STD_OFF
#define GPT_TAUA1_CH11_ISR_API    STD_OFF
#define GPT_TAUA1_CH12_ISR_API    STD_OFF
#define GPT_TAUA1_CH13_ISR_API    STD_OFF
#define GPT_TAUA1_CH14_ISR_API    STD_OFF
#define GPT_TAUA1_CH15_ISR_API    STD_OFF
#define GPT_TAUA1_CH1_ISR_API    STD_OFF
#define GPT_TAUA1_CH2_ISR_API    STD_OFF
#define GPT_TAUA1_CH3_ISR_API    STD_OFF
#define GPT_TAUA1_CH4_ISR_API    STD_OFF
#define GPT_TAUA1_CH5_ISR_API    STD_OFF
#define GPT_TAUA1_CH6_ISR_API    STD_OFF
#define GPT_TAUA1_CH7_ISR_API    STD_OFF
#define GPT_TAUA1_CH8_ISR_API    STD_OFF
#define GPT_TAUA1_CH9_ISR_API    STD_OFF
#define GPT_TAUA2_CH0_ISR_API    STD_OFF
#define GPT_TAUA2_CH10_ISR_API    STD_OFF
#define GPT_TAUA2_CH11_ISR_API    STD_OFF
#define GPT_TAUA2_CH12_ISR_API    STD_OFF
#define GPT_TAUA2_CH13_ISR_API    STD_OFF
#define GPT_TAUA2_CH14_ISR_API    STD_OFF
#define GPT_TAUA2_CH15_ISR_API    STD_OFF
#define GPT_TAUA2_CH1_ISR_API    STD_OFF
#define GPT_TAUA2_CH2_ISR_API    STD_OFF
#define GPT_TAUA2_CH3_ISR_API    STD_OFF
#define GPT_TAUA2_CH4_ISR_API    STD_OFF
#define GPT_TAUA2_CH5_ISR_API    STD_OFF
#define GPT_TAUA2_CH6_ISR_API    STD_OFF
#define GPT_TAUA2_CH7_ISR_API    STD_OFF
#define GPT_TAUA2_CH8_ISR_API    STD_OFF
#define GPT_TAUA2_CH9_ISR_API    STD_OFF
#define GPT_TAUA3_CH0_ISR_API    STD_OFF
#define GPT_TAUA3_CH10_ISR_API    STD_OFF
#define GPT_TAUA3_CH11_ISR_API    STD_OFF
#define GPT_TAUA3_CH12_ISR_API    STD_OFF
#define GPT_TAUA3_CH13_ISR_API    STD_OFF
#define GPT_TAUA3_CH14_ISR_API    STD_OFF
#define GPT_TAUA3_CH15_ISR_API    STD_OFF
#define GPT_TAUA3_CH1_ISR_API    STD_OFF
#define GPT_TAUA3_CH2_ISR_API    STD_OFF
#define GPT_TAUA3_CH3_ISR_API    STD_OFF
#define GPT_TAUA3_CH4_ISR_API    STD_OFF
#define GPT_TAUA3_CH5_ISR_API    STD_OFF
#define GPT_TAUA3_CH6_ISR_API    STD_OFF
#define GPT_TAUA3_CH7_ISR_API    STD_OFF
#define GPT_TAUA3_CH8_ISR_API    STD_OFF
#define GPT_TAUA3_CH9_ISR_API    STD_OFF
#define GPT_TAUA4_CH0_ISR_API    STD_OFF
#define GPT_TAUA4_CH10_ISR_API    STD_OFF
#define GPT_TAUA4_CH11_ISR_API    STD_OFF
#define GPT_TAUA4_CH12_ISR_API    STD_OFF
#define GPT_TAUA4_CH13_ISR_API    STD_OFF
#define GPT_TAUA4_CH14_ISR_API    STD_OFF
#define GPT_TAUA4_CH15_ISR_API    STD_OFF
#define GPT_TAUA4_CH1_ISR_API    STD_OFF
#define GPT_TAUA4_CH2_ISR_API    STD_OFF
#define GPT_TAUA4_CH3_ISR_API    STD_OFF
#define GPT_TAUA4_CH4_ISR_API    STD_OFF
#define GPT_TAUA4_CH5_ISR_API    STD_OFF
#define GPT_TAUA4_CH6_ISR_API    STD_OFF
#define GPT_TAUA4_CH7_ISR_API    STD_OFF
#define GPT_TAUA4_CH8_ISR_API    STD_OFF
#define GPT_TAUA4_CH9_ISR_API    STD_OFF
#define GPT_TAUA5_CH0_ISR_API    STD_OFF
#define GPT_TAUA5_CH10_ISR_API    STD_OFF
#define GPT_TAUA5_CH11_ISR_API    STD_OFF
#define GPT_TAUA5_CH12_ISR_API    STD_OFF
#define GPT_TAUA5_CH13_ISR_API    STD_OFF
#define GPT_TAUA5_CH14_ISR_API    STD_OFF
#define GPT_TAUA5_CH15_ISR_API    STD_OFF
#define GPT_TAUA5_CH1_ISR_API    STD_OFF
#define GPT_TAUA5_CH2_ISR_API    STD_OFF
#define GPT_TAUA5_CH3_ISR_API    STD_OFF
#define GPT_TAUA5_CH4_ISR_API    STD_OFF
#define GPT_TAUA5_CH5_ISR_API    STD_OFF
#define GPT_TAUA5_CH6_ISR_API    STD_OFF
#define GPT_TAUA5_CH7_ISR_API    STD_OFF
#define GPT_TAUA5_CH8_ISR_API    STD_OFF
#define GPT_TAUA5_CH9_ISR_API    STD_OFF
#define GPT_TAUA6_CH0_ISR_API    STD_OFF
#define GPT_TAUA6_CH10_ISR_API    STD_OFF
#define GPT_TAUA6_CH11_ISR_API    STD_OFF
#define GPT_TAUA6_CH12_ISR_API    STD_OFF
#define GPT_TAUA6_CH13_ISR_API    STD_OFF
#define GPT_TAUA6_CH14_ISR_API    STD_OFF
#define GPT_TAUA6_CH15_ISR_API    STD_OFF
#define GPT_TAUA6_CH1_ISR_API    STD_OFF
#define GPT_TAUA6_CH2_ISR_API    STD_OFF
#define GPT_TAUA6_CH3_ISR_API    STD_OFF
#define GPT_TAUA6_CH4_ISR_API    STD_OFF
#define GPT_TAUA6_CH5_ISR_API    STD_OFF
#define GPT_TAUA6_CH6_ISR_API    STD_OFF
#define GPT_TAUA6_CH7_ISR_API    STD_OFF
#define GPT_TAUA6_CH8_ISR_API    STD_OFF
#define GPT_TAUA6_CH9_ISR_API    STD_OFF
#define GPT_TAUA7_CH0_ISR_API    STD_OFF
#define GPT_TAUA7_CH10_ISR_API    STD_OFF
#define GPT_TAUA7_CH11_ISR_API    STD_OFF
#define GPT_TAUA7_CH12_ISR_API    STD_OFF
#define GPT_TAUA7_CH13_ISR_API    STD_OFF
#define GPT_TAUA7_CH14_ISR_API    STD_OFF
#define GPT_TAUA7_CH15_ISR_API    STD_OFF
#define GPT_TAUA7_CH1_ISR_API    STD_OFF
#define GPT_TAUA7_CH2_ISR_API    STD_OFF
#define GPT_TAUA7_CH3_ISR_API    STD_OFF
#define GPT_TAUA7_CH4_ISR_API    STD_OFF
#define GPT_TAUA7_CH5_ISR_API    STD_OFF
#define GPT_TAUA7_CH6_ISR_API    STD_OFF
#define GPT_TAUA7_CH7_ISR_API    STD_OFF
#define GPT_TAUA7_CH8_ISR_API    STD_OFF
#define GPT_TAUA7_CH9_ISR_API    STD_OFF
#define GPT_TAUA8_CH0_ISR_API    STD_OFF
#define GPT_TAUA8_CH10_ISR_API    STD_OFF
#define GPT_TAUA8_CH11_ISR_API    STD_OFF
#define GPT_TAUA8_CH12_ISR_API    STD_OFF
#define GPT_TAUA8_CH13_ISR_API    STD_OFF
#define GPT_TAUA8_CH14_ISR_API    STD_OFF
#define GPT_TAUA8_CH15_ISR_API    STD_OFF
#define GPT_TAUA8_CH1_ISR_API    STD_OFF
#define GPT_TAUA8_CH2_ISR_API    STD_OFF
#define GPT_TAUA8_CH3_ISR_API    STD_OFF
#define GPT_TAUA8_CH4_ISR_API    STD_OFF
#define GPT_TAUA8_CH5_ISR_API    STD_OFF
#define GPT_TAUA8_CH6_ISR_API    STD_OFF
#define GPT_TAUA8_CH7_ISR_API    STD_OFF
#define GPT_TAUA8_CH8_ISR_API    STD_OFF
#define GPT_TAUA8_CH9_ISR_API    STD_OFF
#define GPT_TAUB0_CH0_ISR_API    STD_OFF
#define GPT_TAUB0_CH10_ISR_API    STD_OFF
#define GPT_TAUB0_CH11_ISR_API    STD_OFF
#define GPT_TAUB0_CH12_ISR_API    STD_OFF
#define GPT_TAUB0_CH13_ISR_API    STD_OFF
#define GPT_TAUB0_CH14_ISR_API    STD_OFF
#define GPT_TAUB0_CH15_ISR_API    STD_OFF
#define GPT_TAUB0_CH1_ISR_API    STD_OFF
#define GPT_TAUB0_CH2_ISR_API    STD_OFF
#define GPT_TAUB0_CH3_ISR_API    STD_OFF
#define GPT_TAUB0_CH4_ISR_API    STD_OFF
#define GPT_TAUB0_CH5_ISR_API    STD_OFF
#define GPT_TAUB0_CH6_ISR_API    STD_OFF
#define GPT_TAUB0_CH7_ISR_API    STD_OFF
#define GPT_TAUB0_CH8_ISR_API    STD_OFF
#define GPT_TAUB0_CH9_ISR_API    STD_OFF
#define GPT_TAUB1_CH0_ISR_API    STD_OFF
#define GPT_TAUB1_CH10_ISR_API    STD_OFF
#define GPT_TAUB1_CH11_ISR_API    STD_OFF
#define GPT_TAUB1_CH12_ISR_API    STD_OFF
#define GPT_TAUB1_CH13_ISR_API    STD_OFF
#define GPT_TAUB1_CH14_ISR_API    STD_OFF
#define GPT_TAUB1_CH15_ISR_API    STD_OFF
#define GPT_TAUB1_CH1_ISR_API    STD_OFF
#define GPT_TAUB1_CH2_ISR_API    STD_OFF
#define GPT_TAUB1_CH3_ISR_API    STD_OFF
#define GPT_TAUB1_CH4_ISR_API    STD_OFF
#define GPT_TAUB1_CH5_ISR_API    STD_OFF
#define GPT_TAUB1_CH6_ISR_API    STD_OFF
#define GPT_TAUB1_CH7_ISR_API    STD_OFF
#define GPT_TAUB1_CH8_ISR_API    STD_OFF
#define GPT_TAUB1_CH9_ISR_API    STD_OFF
#define GPT_TAUB2_CH0_ISR_API    STD_OFF
#define GPT_TAUB2_CH10_ISR_API    STD_OFF
#define GPT_TAUB2_CH11_ISR_API    STD_OFF
#define GPT_TAUB2_CH12_ISR_API    STD_OFF
#define GPT_TAUB2_CH13_ISR_API    STD_OFF
#define GPT_TAUB2_CH14_ISR_API    STD_OFF
#define GPT_TAUB2_CH15_ISR_API    STD_OFF
#define GPT_TAUB2_CH1_ISR_API    STD_OFF
#define GPT_TAUB2_CH2_ISR_API    STD_OFF
#define GPT_TAUB2_CH3_ISR_API    STD_OFF
#define GPT_TAUB2_CH4_ISR_API    STD_OFF
#define GPT_TAUB2_CH5_ISR_API    STD_OFF
#define GPT_TAUB2_CH6_ISR_API    STD_OFF
#define GPT_TAUB2_CH7_ISR_API    STD_OFF
#define GPT_TAUB2_CH8_ISR_API    STD_OFF
#define GPT_TAUB2_CH9_ISR_API    STD_OFF
#define GPT_TAUC2_CH0_ISR_API    STD_OFF
#define GPT_TAUC2_CH10_ISR_API    STD_OFF
#define GPT_TAUC2_CH11_ISR_API    STD_OFF
#define GPT_TAUC2_CH12_ISR_API    STD_OFF
#define GPT_TAUC2_CH13_ISR_API    STD_OFF
#define GPT_TAUC2_CH14_ISR_API    STD_OFF
#define GPT_TAUC2_CH15_ISR_API    STD_OFF
#define GPT_TAUC2_CH1_ISR_API    STD_OFF
#define GPT_TAUC2_CH2_ISR_API    STD_OFF
#define GPT_TAUC2_CH3_ISR_API    STD_OFF
#define GPT_TAUC2_CH4_ISR_API    STD_OFF
#define GPT_TAUC2_CH5_ISR_API    STD_OFF
#define GPT_TAUC2_CH6_ISR_API    STD_OFF
#define GPT_TAUC2_CH7_ISR_API    STD_OFF
#define GPT_TAUC2_CH8_ISR_API    STD_OFF
#define GPT_TAUC2_CH9_ISR_API    STD_OFF
#define GPT_TAUC3_CH0_ISR_API    STD_OFF
#define GPT_TAUC3_CH10_ISR_API    STD_OFF
#define GPT_TAUC3_CH11_ISR_API    STD_OFF
#define GPT_TAUC3_CH12_ISR_API    STD_OFF
#define GPT_TAUC3_CH13_ISR_API    STD_OFF
#define GPT_TAUC3_CH14_ISR_API    STD_OFF
#define GPT_TAUC3_CH15_ISR_API    STD_OFF
#define GPT_TAUC3_CH1_ISR_API    STD_OFF
#define GPT_TAUC3_CH2_ISR_API    STD_OFF
#define GPT_TAUC3_CH3_ISR_API    STD_OFF
#define GPT_TAUC3_CH4_ISR_API    STD_OFF
#define GPT_TAUC3_CH5_ISR_API    STD_OFF
#define GPT_TAUC3_CH6_ISR_API    STD_OFF
#define GPT_TAUC3_CH7_ISR_API    STD_OFF
#define GPT_TAUC3_CH8_ISR_API    STD_OFF
#define GPT_TAUC3_CH9_ISR_API    STD_OFF
#define GPT_TAUC4_CH0_ISR_API    STD_OFF
#define GPT_TAUC4_CH10_ISR_API    STD_OFF
#define GPT_TAUC4_CH11_ISR_API    STD_OFF
#define GPT_TAUC4_CH12_ISR_API    STD_OFF
#define GPT_TAUC4_CH13_ISR_API    STD_OFF
#define GPT_TAUC4_CH14_ISR_API    STD_OFF
#define GPT_TAUC4_CH15_ISR_API    STD_OFF
#define GPT_TAUC4_CH1_ISR_API    STD_OFF
#define GPT_TAUC4_CH2_ISR_API    STD_OFF
#define GPT_TAUC4_CH3_ISR_API    STD_OFF
#define GPT_TAUC4_CH4_ISR_API    STD_OFF
#define GPT_TAUC4_CH5_ISR_API    STD_OFF
#define GPT_TAUC4_CH6_ISR_API    STD_OFF
#define GPT_TAUC4_CH7_ISR_API    STD_OFF
#define GPT_TAUC4_CH8_ISR_API    STD_OFF
#define GPT_TAUC4_CH9_ISR_API    STD_OFF
#define GPT_TAUC5_CH0_ISR_API    STD_OFF
#define GPT_TAUC5_CH10_ISR_API    STD_OFF
#define GPT_TAUC5_CH11_ISR_API    STD_OFF
#define GPT_TAUC5_CH12_ISR_API    STD_OFF
#define GPT_TAUC5_CH13_ISR_API    STD_OFF
#define GPT_TAUC5_CH14_ISR_API    STD_OFF
#define GPT_TAUC5_CH15_ISR_API    STD_OFF
#define GPT_TAUC5_CH1_ISR_API    STD_OFF
#define GPT_TAUC5_CH2_ISR_API    STD_OFF
#define GPT_TAUC5_CH3_ISR_API    STD_OFF
#define GPT_TAUC5_CH4_ISR_API    STD_OFF
#define GPT_TAUC5_CH5_ISR_API    STD_OFF
#define GPT_TAUC5_CH6_ISR_API    STD_OFF
#define GPT_TAUC5_CH7_ISR_API    STD_OFF
#define GPT_TAUC5_CH8_ISR_API    STD_OFF
#define GPT_TAUC5_CH9_ISR_API    STD_OFF
#define GPT_TAUC6_CH0_ISR_API    STD_OFF
#define GPT_TAUC6_CH10_ISR_API    STD_OFF
#define GPT_TAUC6_CH11_ISR_API    STD_OFF
#define GPT_TAUC6_CH12_ISR_API    STD_OFF
#define GPT_TAUC6_CH13_ISR_API    STD_OFF
#define GPT_TAUC6_CH14_ISR_API    STD_OFF
#define GPT_TAUC6_CH15_ISR_API    STD_OFF
#define GPT_TAUC6_CH1_ISR_API    STD_OFF
#define GPT_TAUC6_CH2_ISR_API    STD_OFF
#define GPT_TAUC6_CH3_ISR_API    STD_OFF
#define GPT_TAUC6_CH4_ISR_API    STD_OFF
#define GPT_TAUC6_CH5_ISR_API    STD_OFF
#define GPT_TAUC6_CH6_ISR_API    STD_OFF
#define GPT_TAUC6_CH7_ISR_API    STD_OFF
#define GPT_TAUC6_CH8_ISR_API    STD_OFF
#define GPT_TAUC6_CH9_ISR_API    STD_OFF
#define GPT_TAUC7_CH0_ISR_API    STD_OFF
#define GPT_TAUC7_CH10_ISR_API    STD_OFF
#define GPT_TAUC7_CH11_ISR_API    STD_OFF
#define GPT_TAUC7_CH12_ISR_API    STD_OFF
#define GPT_TAUC7_CH13_ISR_API    STD_OFF
#define GPT_TAUC7_CH14_ISR_API    STD_OFF
#define GPT_TAUC7_CH15_ISR_API    STD_OFF
#define GPT_TAUC7_CH1_ISR_API    STD_OFF
#define GPT_TAUC7_CH2_ISR_API    STD_OFF
#define GPT_TAUC7_CH3_ISR_API    STD_OFF
#define GPT_TAUC7_CH4_ISR_API    STD_OFF
#define GPT_TAUC7_CH5_ISR_API    STD_OFF
#define GPT_TAUC7_CH6_ISR_API    STD_OFF
#define GPT_TAUC7_CH7_ISR_API    STD_OFF
#define GPT_TAUC7_CH8_ISR_API    STD_OFF
#define GPT_TAUC7_CH9_ISR_API    STD_OFF
#define GPT_TAUC8_CH0_ISR_API    STD_OFF
#define GPT_TAUC8_CH10_ISR_API    STD_OFF
#define GPT_TAUC8_CH11_ISR_API    STD_OFF
#define GPT_TAUC8_CH12_ISR_API    STD_OFF
#define GPT_TAUC8_CH13_ISR_API    STD_OFF
#define GPT_TAUC8_CH14_ISR_API    STD_OFF
#define GPT_TAUC8_CH15_ISR_API    STD_OFF
#define GPT_TAUC8_CH1_ISR_API    STD_OFF
#define GPT_TAUC8_CH2_ISR_API    STD_OFF
#define GPT_TAUC8_CH3_ISR_API    STD_OFF
#define GPT_TAUC8_CH4_ISR_API    STD_OFF
#define GPT_TAUC8_CH5_ISR_API    STD_OFF
#define GPT_TAUC8_CH6_ISR_API    STD_OFF
#define GPT_TAUC8_CH7_ISR_API    STD_OFF
#define GPT_TAUC8_CH8_ISR_API    STD_OFF
#define GPT_TAUC8_CH9_ISR_API    STD_OFF
#define GPT_TAUJ0_CH0_ISR_API    STD_ON
#define GPT_TAUJ0_CH1_ISR_API    STD_OFF
#define GPT_TAUJ0_CH2_ISR_API    STD_OFF
#define GPT_TAUJ0_CH3_ISR_API    STD_OFF
#define GPT_TAUJ1_CH0_ISR_API    STD_OFF
#define GPT_TAUJ1_CH1_ISR_API    STD_OFF
#define GPT_TAUJ1_CH2_ISR_API    STD_OFF
#define GPT_TAUJ1_CH3_ISR_API    STD_OFF
#define GPT_TAUJ2_CH0_ISR_API    STD_OFF
#define GPT_TAUJ2_CH1_ISR_API    STD_OFF
#define GPT_TAUJ2_CH2_ISR_API    STD_OFF
#define GPT_TAUJ2_CH3_ISR_API    STD_OFF

/* GPT Channel Handles */
#define GptChannelConfiguration0 (uint8)0x90                    

/* Configuration Set Handles */
#define GptChannelConfigSet0  &Gpt_GstConfiguration[0]


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* GPT_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
