/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Pwm_Cfg.h                                                   */
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
 * TOOL VERSION:    3.1.5
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    FK4_4010_PWM_V308_140113_HEADLAMP.arxml
 * GENERATED ON:   8 Apr 2014 - 18:39:24
 */

#ifndef PWM_CFG_H
#define PWM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define PWM_CFG_AR_MAJOR_VERSION  2
#define PWM_CFG_AR_MINOR_VERSION  2
#define PWM_CFG_AR_PATCH_VERSION  0

/* File version information */
#define PWM_CFG_SW_MAJOR_VERSION       3
#define PWM_CFG_SW_MINOR_VERSION       1

/*******************************************************************************
**                       Common Publish Information                           **
*******************************************************************************/

#define PWM_AR_MAJOR_VERSION_VALUE     2
#define PWM_AR_MINOR_VERSION_VALUE     2
#define PWM_AR_PATCH_VERSION_VALUE     0

#define PWM_SW_MAJOR_VERSION_VALUE     3
#define PWM_SW_MINOR_VERSION_VALUE     1
#define PWM_SW_PATCH_VERSION_VALUE     2

#define PWM_VENDOR_ID_VALUE            23
#define PWM_MODULE_ID_VALUE            121


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the PWM Driver*/
#define PWM_INSTANCE_ID_VALUE               0

/* Enables/Disables Development error detection */
#define PWM_DEV_ERROR_DETECT                STD_OFF

/* Enables/Disables Pwm Notification */
#define PWM_NOTIFICATION_SUPPORTED          STD_OFF

/* Enables/Disables GetVersionInfo API */
#define PWM_VERSION_INFO_API                STD_OFF

/* Enables/Disables the Pwm_DeInit API */
#define PWM_DE_INIT_API                     STD_OFF

/* Enables/Disables the Pwm_SetDutyCycle API */
#define PWM_SET_DUTY_CYCLE_API              STD_ON

/* Enables/Disables the Pwm_SetPeriodAndDuty API */
#define PWM_SET_PERIOD_AND_DUTY_API         STD_ON

/* Enables/Disables the Pwm_SetOutputToIdle API */
#define PWM_SET_OUTPUT_TO_IDLE_API          STD_ON

/* Enables/Disables the Pwm_GetOutputState API */
#define PWM_GET_OUTPUT_STATE_API            STD_OFF

/* Enables/Disables the DELAY Macro support */
#define PWM_DELAY_MACRO_SUPPORT             STD_OFF

/* Enables/Disables Synchronous start between the TAU units
         (TAUA0, TAUA1, TAUJ0, TAUJ1)  */
#define PWM_SYNCHSTART_BETWEEN_TAU_USED     STD_OFF

/* Enable/disable the Critical section protection */
#define PWM_CRITICAL_SECTION_PROTECTION     STD_ON

/* Enable/disable the setting of Prescaler, baudrate and
         blConfigurePrescaler by the PWM Driver */
#define PWM_CONFIG_PRESCALER_SUPPORTED      STD_ON

/* Total number of PWM channels configured */
#define PWM_TOTAL_CHANNELS_CONFIGURED       34

/* Total number of PWM  TAUA, TAUB and TAUC channels configured */
#define PWM_TOTAL_TAUABC_CHANNELS_CONFIG    34

/* Total number of PWM TAUJ channels configured */
#define PWM_TOTAL_TAUJ_CHANNELS_CONFIG      0

/*Total number of PWM TAU units configured*/
#define PWM_TOTAL_TAUABC_UNITS_CONFIG       4

/*Total number of PWM TAU units configured*/
#define PWM_TOTAL_TAUJ_UNITS_CONFIG       0

/*Maximum PWM Channel ID configured */
#define PWM_MAX_CHANNEL_ID_CONFIGURED       51

/* Indicates the inclusion of notification function */
#define PWM_TAUA_UNIT_USED                  STD_ON

/* Indicates the inclusion of notification function */
#define PWM_TAUB_UNIT_USED                  STD_ON

/* Indicates the inclusion of notification function */
#define PWM_TAUC_UNIT_USED                  STD_ON

/* Indicates the inclusion of notification function */
#define PWM_TAUJ_UNIT_USED                 STD_OFF



/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/

/* Macros for enabling/disabling ISRS */
#define PWM_TAUA0_CH0_ISR_API    STD_OFF
#define PWM_TAUA0_CH10_ISR_API    STD_OFF
#define PWM_TAUA0_CH11_ISR_API    STD_OFF
#define PWM_TAUA0_CH12_ISR_API    STD_OFF
#define PWM_TAUA0_CH13_ISR_API    STD_OFF
#define PWM_TAUA0_CH14_ISR_API    STD_OFF
#define PWM_TAUA0_CH15_ISR_API    STD_OFF
#define PWM_TAUA0_CH1_ISR_API    STD_OFF
#define PWM_TAUA0_CH2_ISR_API    STD_OFF
#define PWM_TAUA0_CH3_ISR_API    STD_OFF
#define PWM_TAUA0_CH4_ISR_API    STD_OFF
#define PWM_TAUA0_CH5_ISR_API    STD_OFF
#define PWM_TAUA0_CH6_ISR_API    STD_OFF
#define PWM_TAUA0_CH7_ISR_API    STD_OFF
#define PWM_TAUA0_CH8_ISR_API    STD_OFF
#define PWM_TAUA0_CH9_ISR_API    STD_OFF
#define PWM_TAUA1_CH0_ISR_API    STD_OFF
#define PWM_TAUA1_CH10_ISR_API    STD_OFF
#define PWM_TAUA1_CH11_ISR_API    STD_OFF
#define PWM_TAUA1_CH12_ISR_API    STD_OFF
#define PWM_TAUA1_CH13_ISR_API    STD_OFF
#define PWM_TAUA1_CH14_ISR_API    STD_OFF
#define PWM_TAUA1_CH15_ISR_API    STD_OFF
#define PWM_TAUA1_CH1_ISR_API    STD_OFF
#define PWM_TAUA1_CH2_ISR_API    STD_OFF
#define PWM_TAUA1_CH3_ISR_API    STD_OFF
#define PWM_TAUA1_CH4_ISR_API    STD_OFF
#define PWM_TAUA1_CH5_ISR_API    STD_OFF
#define PWM_TAUA1_CH6_ISR_API    STD_OFF
#define PWM_TAUA1_CH7_ISR_API    STD_OFF
#define PWM_TAUA1_CH8_ISR_API    STD_OFF
#define PWM_TAUA1_CH9_ISR_API    STD_OFF
#define PWM_TAUA2_CH0_ISR_API    STD_OFF
#define PWM_TAUA2_CH10_ISR_API    STD_OFF
#define PWM_TAUA2_CH11_ISR_API    STD_OFF
#define PWM_TAUA2_CH12_ISR_API    STD_OFF
#define PWM_TAUA2_CH13_ISR_API    STD_OFF
#define PWM_TAUA2_CH14_ISR_API    STD_OFF
#define PWM_TAUA2_CH15_ISR_API    STD_OFF
#define PWM_TAUA2_CH1_ISR_API    STD_OFF
#define PWM_TAUA2_CH2_ISR_API    STD_OFF
#define PWM_TAUA2_CH3_ISR_API    STD_OFF
#define PWM_TAUA2_CH4_ISR_API    STD_OFF
#define PWM_TAUA2_CH5_ISR_API    STD_OFF
#define PWM_TAUA2_CH6_ISR_API    STD_OFF
#define PWM_TAUA2_CH7_ISR_API    STD_OFF
#define PWM_TAUA2_CH8_ISR_API    STD_OFF
#define PWM_TAUA2_CH9_ISR_API    STD_OFF
#define PWM_TAUA3_CH0_ISR_API    STD_OFF
#define PWM_TAUA3_CH10_ISR_API    STD_OFF
#define PWM_TAUA3_CH11_ISR_API    STD_OFF
#define PWM_TAUA3_CH12_ISR_API    STD_OFF
#define PWM_TAUA3_CH13_ISR_API    STD_OFF
#define PWM_TAUA3_CH14_ISR_API    STD_OFF
#define PWM_TAUA3_CH15_ISR_API    STD_OFF
#define PWM_TAUA3_CH1_ISR_API    STD_OFF
#define PWM_TAUA3_CH2_ISR_API    STD_OFF
#define PWM_TAUA3_CH3_ISR_API    STD_OFF
#define PWM_TAUA3_CH4_ISR_API    STD_OFF
#define PWM_TAUA3_CH5_ISR_API    STD_OFF
#define PWM_TAUA3_CH6_ISR_API    STD_OFF
#define PWM_TAUA3_CH7_ISR_API    STD_OFF
#define PWM_TAUA3_CH8_ISR_API    STD_OFF
#define PWM_TAUA3_CH9_ISR_API    STD_OFF
#define PWM_TAUA4_CH0_ISR_API    STD_OFF
#define PWM_TAUA4_CH10_ISR_API    STD_OFF
#define PWM_TAUA4_CH11_ISR_API    STD_OFF
#define PWM_TAUA4_CH12_ISR_API    STD_OFF
#define PWM_TAUA4_CH13_ISR_API    STD_OFF
#define PWM_TAUA4_CH14_ISR_API    STD_OFF
#define PWM_TAUA4_CH15_ISR_API    STD_OFF
#define PWM_TAUA4_CH1_ISR_API    STD_OFF
#define PWM_TAUA4_CH2_ISR_API    STD_OFF
#define PWM_TAUA4_CH3_ISR_API    STD_OFF
#define PWM_TAUA4_CH4_ISR_API    STD_OFF
#define PWM_TAUA4_CH5_ISR_API    STD_OFF
#define PWM_TAUA4_CH6_ISR_API    STD_OFF
#define PWM_TAUA4_CH7_ISR_API    STD_OFF
#define PWM_TAUA4_CH8_ISR_API    STD_OFF
#define PWM_TAUA4_CH9_ISR_API    STD_OFF
#define PWM_TAUA5_CH0_ISR_API    STD_OFF
#define PWM_TAUA5_CH10_ISR_API    STD_OFF
#define PWM_TAUA5_CH11_ISR_API    STD_OFF
#define PWM_TAUA5_CH12_ISR_API    STD_OFF
#define PWM_TAUA5_CH13_ISR_API    STD_OFF
#define PWM_TAUA5_CH14_ISR_API    STD_OFF
#define PWM_TAUA5_CH15_ISR_API    STD_OFF
#define PWM_TAUA5_CH1_ISR_API    STD_OFF
#define PWM_TAUA5_CH2_ISR_API    STD_OFF
#define PWM_TAUA5_CH3_ISR_API    STD_OFF
#define PWM_TAUA5_CH4_ISR_API    STD_OFF
#define PWM_TAUA5_CH5_ISR_API    STD_OFF
#define PWM_TAUA5_CH6_ISR_API    STD_OFF
#define PWM_TAUA5_CH7_ISR_API    STD_OFF
#define PWM_TAUA5_CH8_ISR_API    STD_OFF
#define PWM_TAUA5_CH9_ISR_API    STD_OFF
#define PWM_TAUA6_CH0_ISR_API    STD_OFF
#define PWM_TAUA6_CH10_ISR_API    STD_OFF
#define PWM_TAUA6_CH11_ISR_API    STD_OFF
#define PWM_TAUA6_CH12_ISR_API    STD_OFF
#define PWM_TAUA6_CH13_ISR_API    STD_OFF
#define PWM_TAUA6_CH14_ISR_API    STD_OFF
#define PWM_TAUA6_CH15_ISR_API    STD_OFF
#define PWM_TAUA6_CH1_ISR_API    STD_OFF
#define PWM_TAUA6_CH2_ISR_API    STD_OFF
#define PWM_TAUA6_CH3_ISR_API    STD_OFF
#define PWM_TAUA6_CH4_ISR_API    STD_OFF
#define PWM_TAUA6_CH5_ISR_API    STD_OFF
#define PWM_TAUA6_CH6_ISR_API    STD_OFF
#define PWM_TAUA6_CH7_ISR_API    STD_OFF
#define PWM_TAUA6_CH8_ISR_API    STD_OFF
#define PWM_TAUA6_CH9_ISR_API    STD_OFF
#define PWM_TAUA7_CH0_ISR_API    STD_OFF
#define PWM_TAUA7_CH10_ISR_API    STD_OFF
#define PWM_TAUA7_CH11_ISR_API    STD_OFF
#define PWM_TAUA7_CH12_ISR_API    STD_OFF
#define PWM_TAUA7_CH13_ISR_API    STD_OFF
#define PWM_TAUA7_CH14_ISR_API    STD_OFF
#define PWM_TAUA7_CH15_ISR_API    STD_OFF
#define PWM_TAUA7_CH1_ISR_API    STD_OFF
#define PWM_TAUA7_CH2_ISR_API    STD_OFF
#define PWM_TAUA7_CH3_ISR_API    STD_OFF
#define PWM_TAUA7_CH4_ISR_API    STD_OFF
#define PWM_TAUA7_CH5_ISR_API    STD_OFF
#define PWM_TAUA7_CH6_ISR_API    STD_OFF
#define PWM_TAUA7_CH7_ISR_API    STD_OFF
#define PWM_TAUA7_CH8_ISR_API    STD_OFF
#define PWM_TAUA7_CH9_ISR_API    STD_OFF
#define PWM_TAUA8_CH0_ISR_API    STD_OFF
#define PWM_TAUA8_CH10_ISR_API    STD_OFF
#define PWM_TAUA8_CH11_ISR_API    STD_OFF
#define PWM_TAUA8_CH12_ISR_API    STD_OFF
#define PWM_TAUA8_CH13_ISR_API    STD_OFF
#define PWM_TAUA8_CH14_ISR_API    STD_OFF
#define PWM_TAUA8_CH15_ISR_API    STD_OFF
#define PWM_TAUA8_CH1_ISR_API    STD_OFF
#define PWM_TAUA8_CH2_ISR_API    STD_OFF
#define PWM_TAUA8_CH3_ISR_API    STD_OFF
#define PWM_TAUA8_CH4_ISR_API    STD_OFF
#define PWM_TAUA8_CH5_ISR_API    STD_OFF
#define PWM_TAUA8_CH6_ISR_API    STD_OFF
#define PWM_TAUA8_CH7_ISR_API    STD_OFF
#define PWM_TAUA8_CH8_ISR_API    STD_OFF
#define PWM_TAUA8_CH9_ISR_API    STD_OFF
#define PWM_TAUB0_CH0_ISR_API    STD_OFF
#define PWM_TAUB0_CH10_ISR_API    STD_OFF
#define PWM_TAUB0_CH11_ISR_API    STD_OFF
#define PWM_TAUB0_CH12_ISR_API    STD_OFF
#define PWM_TAUB0_CH13_ISR_API    STD_OFF
#define PWM_TAUB0_CH14_ISR_API    STD_OFF
#define PWM_TAUB0_CH15_ISR_API    STD_OFF
#define PWM_TAUB0_CH1_ISR_API    STD_OFF
#define PWM_TAUB0_CH2_ISR_API    STD_OFF
#define PWM_TAUB0_CH3_ISR_API    STD_OFF
#define PWM_TAUB0_CH4_ISR_API    STD_OFF
#define PWM_TAUB0_CH5_ISR_API    STD_OFF
#define PWM_TAUB0_CH6_ISR_API    STD_OFF
#define PWM_TAUB0_CH7_ISR_API    STD_OFF
#define PWM_TAUB0_CH8_ISR_API    STD_OFF
#define PWM_TAUB0_CH9_ISR_API    STD_OFF
#define PWM_TAUB1_CH0_ISR_API    STD_OFF
#define PWM_TAUB1_CH10_ISR_API    STD_OFF
#define PWM_TAUB1_CH11_ISR_API    STD_OFF
#define PWM_TAUB1_CH12_ISR_API    STD_OFF
#define PWM_TAUB1_CH13_ISR_API    STD_OFF
#define PWM_TAUB1_CH14_ISR_API    STD_OFF
#define PWM_TAUB1_CH15_ISR_API    STD_OFF
#define PWM_TAUB1_CH1_ISR_API    STD_OFF
#define PWM_TAUB1_CH2_ISR_API    STD_OFF
#define PWM_TAUB1_CH3_ISR_API    STD_OFF
#define PWM_TAUB1_CH4_ISR_API    STD_OFF
#define PWM_TAUB1_CH5_ISR_API    STD_OFF
#define PWM_TAUB1_CH6_ISR_API    STD_OFF
#define PWM_TAUB1_CH7_ISR_API    STD_OFF
#define PWM_TAUB1_CH8_ISR_API    STD_OFF
#define PWM_TAUB1_CH9_ISR_API    STD_OFF
#define PWM_TAUB2_CH0_ISR_API    STD_OFF
#define PWM_TAUB2_CH10_ISR_API    STD_OFF
#define PWM_TAUB2_CH11_ISR_API    STD_OFF
#define PWM_TAUB2_CH12_ISR_API    STD_OFF
#define PWM_TAUB2_CH13_ISR_API    STD_OFF
#define PWM_TAUB2_CH14_ISR_API    STD_OFF
#define PWM_TAUB2_CH15_ISR_API    STD_OFF
#define PWM_TAUB2_CH1_ISR_API    STD_OFF
#define PWM_TAUB2_CH2_ISR_API    STD_OFF
#define PWM_TAUB2_CH3_ISR_API    STD_OFF
#define PWM_TAUB2_CH4_ISR_API    STD_OFF
#define PWM_TAUB2_CH5_ISR_API    STD_OFF
#define PWM_TAUB2_CH6_ISR_API    STD_OFF
#define PWM_TAUB2_CH7_ISR_API    STD_OFF
#define PWM_TAUB2_CH8_ISR_API    STD_OFF
#define PWM_TAUB2_CH9_ISR_API    STD_OFF
#define PWM_TAUC2_CH0_ISR_API    STD_OFF
#define PWM_TAUC2_CH10_ISR_API    STD_OFF
#define PWM_TAUC2_CH11_ISR_API    STD_OFF
#define PWM_TAUC2_CH12_ISR_API    STD_OFF
#define PWM_TAUC2_CH13_ISR_API    STD_OFF
#define PWM_TAUC2_CH14_ISR_API    STD_OFF
#define PWM_TAUC2_CH15_ISR_API    STD_OFF
#define PWM_TAUC2_CH1_ISR_API    STD_OFF
#define PWM_TAUC2_CH2_ISR_API    STD_OFF
#define PWM_TAUC2_CH3_ISR_API    STD_OFF
#define PWM_TAUC2_CH4_ISR_API    STD_OFF
#define PWM_TAUC2_CH5_ISR_API    STD_OFF
#define PWM_TAUC2_CH6_ISR_API    STD_OFF
#define PWM_TAUC2_CH7_ISR_API    STD_OFF
#define PWM_TAUC2_CH8_ISR_API    STD_OFF
#define PWM_TAUC2_CH9_ISR_API    STD_OFF
#define PWM_TAUC3_CH0_ISR_API    STD_OFF
#define PWM_TAUC3_CH10_ISR_API    STD_OFF
#define PWM_TAUC3_CH11_ISR_API    STD_OFF
#define PWM_TAUC3_CH12_ISR_API    STD_OFF
#define PWM_TAUC3_CH13_ISR_API    STD_OFF
#define PWM_TAUC3_CH14_ISR_API    STD_OFF
#define PWM_TAUC3_CH15_ISR_API    STD_OFF
#define PWM_TAUC3_CH1_ISR_API    STD_OFF
#define PWM_TAUC3_CH2_ISR_API    STD_OFF
#define PWM_TAUC3_CH3_ISR_API    STD_OFF
#define PWM_TAUC3_CH4_ISR_API    STD_OFF
#define PWM_TAUC3_CH5_ISR_API    STD_OFF
#define PWM_TAUC3_CH6_ISR_API    STD_OFF
#define PWM_TAUC3_CH7_ISR_API    STD_OFF
#define PWM_TAUC3_CH8_ISR_API    STD_OFF
#define PWM_TAUC3_CH9_ISR_API    STD_OFF
#define PWM_TAUC4_CH0_ISR_API    STD_OFF
#define PWM_TAUC4_CH10_ISR_API    STD_OFF
#define PWM_TAUC4_CH11_ISR_API    STD_OFF
#define PWM_TAUC4_CH12_ISR_API    STD_OFF
#define PWM_TAUC4_CH13_ISR_API    STD_OFF
#define PWM_TAUC4_CH14_ISR_API    STD_OFF
#define PWM_TAUC4_CH15_ISR_API    STD_OFF
#define PWM_TAUC4_CH1_ISR_API    STD_OFF
#define PWM_TAUC4_CH2_ISR_API    STD_OFF
#define PWM_TAUC4_CH3_ISR_API    STD_OFF
#define PWM_TAUC4_CH4_ISR_API    STD_OFF
#define PWM_TAUC4_CH5_ISR_API    STD_OFF
#define PWM_TAUC4_CH6_ISR_API    STD_OFF
#define PWM_TAUC4_CH7_ISR_API    STD_OFF
#define PWM_TAUC4_CH8_ISR_API    STD_OFF
#define PWM_TAUC4_CH9_ISR_API    STD_OFF
#define PWM_TAUC5_CH0_ISR_API    STD_OFF
#define PWM_TAUC5_CH10_ISR_API    STD_OFF
#define PWM_TAUC5_CH11_ISR_API    STD_OFF
#define PWM_TAUC5_CH12_ISR_API    STD_OFF
#define PWM_TAUC5_CH13_ISR_API    STD_OFF
#define PWM_TAUC5_CH14_ISR_API    STD_OFF
#define PWM_TAUC5_CH15_ISR_API    STD_OFF
#define PWM_TAUC5_CH1_ISR_API    STD_OFF
#define PWM_TAUC5_CH2_ISR_API    STD_OFF
#define PWM_TAUC5_CH3_ISR_API    STD_OFF
#define PWM_TAUC5_CH4_ISR_API    STD_OFF
#define PWM_TAUC5_CH5_ISR_API    STD_OFF
#define PWM_TAUC5_CH6_ISR_API    STD_OFF
#define PWM_TAUC5_CH7_ISR_API    STD_OFF
#define PWM_TAUC5_CH8_ISR_API    STD_OFF
#define PWM_TAUC5_CH9_ISR_API    STD_OFF
#define PWM_TAUC6_CH0_ISR_API    STD_OFF
#define PWM_TAUC6_CH10_ISR_API    STD_OFF
#define PWM_TAUC6_CH11_ISR_API    STD_OFF
#define PWM_TAUC6_CH12_ISR_API    STD_OFF
#define PWM_TAUC6_CH13_ISR_API    STD_OFF
#define PWM_TAUC6_CH14_ISR_API    STD_OFF
#define PWM_TAUC6_CH15_ISR_API    STD_OFF
#define PWM_TAUC6_CH1_ISR_API    STD_OFF
#define PWM_TAUC6_CH2_ISR_API    STD_OFF
#define PWM_TAUC6_CH3_ISR_API    STD_OFF
#define PWM_TAUC6_CH4_ISR_API    STD_OFF
#define PWM_TAUC6_CH5_ISR_API    STD_OFF
#define PWM_TAUC6_CH6_ISR_API    STD_OFF
#define PWM_TAUC6_CH7_ISR_API    STD_OFF
#define PWM_TAUC6_CH8_ISR_API    STD_OFF
#define PWM_TAUC6_CH9_ISR_API    STD_OFF
#define PWM_TAUC7_CH0_ISR_API    STD_OFF
#define PWM_TAUC7_CH10_ISR_API    STD_OFF
#define PWM_TAUC7_CH11_ISR_API    STD_OFF
#define PWM_TAUC7_CH12_ISR_API    STD_OFF
#define PWM_TAUC7_CH13_ISR_API    STD_OFF
#define PWM_TAUC7_CH14_ISR_API    STD_OFF
#define PWM_TAUC7_CH15_ISR_API    STD_OFF
#define PWM_TAUC7_CH1_ISR_API    STD_OFF
#define PWM_TAUC7_CH2_ISR_API    STD_OFF
#define PWM_TAUC7_CH3_ISR_API    STD_OFF
#define PWM_TAUC7_CH4_ISR_API    STD_OFF
#define PWM_TAUC7_CH5_ISR_API    STD_OFF
#define PWM_TAUC7_CH6_ISR_API    STD_OFF
#define PWM_TAUC7_CH7_ISR_API    STD_OFF
#define PWM_TAUC7_CH8_ISR_API    STD_OFF
#define PWM_TAUC7_CH9_ISR_API    STD_OFF
#define PWM_TAUC8_CH0_ISR_API    STD_OFF
#define PWM_TAUC8_CH10_ISR_API    STD_OFF
#define PWM_TAUC8_CH11_ISR_API    STD_OFF
#define PWM_TAUC8_CH12_ISR_API    STD_OFF
#define PWM_TAUC8_CH13_ISR_API    STD_OFF
#define PWM_TAUC8_CH14_ISR_API    STD_OFF
#define PWM_TAUC8_CH15_ISR_API    STD_OFF
#define PWM_TAUC8_CH1_ISR_API    STD_OFF
#define PWM_TAUC8_CH2_ISR_API    STD_OFF
#define PWM_TAUC8_CH3_ISR_API    STD_OFF
#define PWM_TAUC8_CH4_ISR_API    STD_OFF
#define PWM_TAUC8_CH5_ISR_API    STD_OFF
#define PWM_TAUC8_CH6_ISR_API    STD_OFF
#define PWM_TAUC8_CH7_ISR_API    STD_OFF
#define PWM_TAUC8_CH8_ISR_API    STD_OFF
#define PWM_TAUC8_CH9_ISR_API    STD_OFF
#define PWM_TAUJ0_CH0_ISR_API    STD_OFF
#define PWM_TAUJ0_CH1_ISR_API    STD_OFF
#define PWM_TAUJ0_CH2_ISR_API    STD_OFF
#define PWM_TAUJ0_CH3_ISR_API    STD_OFF
#define PWM_TAUJ1_CH0_ISR_API    STD_OFF
#define PWM_TAUJ1_CH1_ISR_API    STD_OFF
#define PWM_TAUJ1_CH2_ISR_API    STD_OFF
#define PWM_TAUJ1_CH3_ISR_API    STD_OFF
#define PWM_TAUJ2_CH0_ISR_API    STD_OFF
#define PWM_TAUJ2_CH1_ISR_API    STD_OFF
#define PWM_TAUJ2_CH2_ISR_API    STD_OFF
#define PWM_TAUJ2_CH3_ISR_API    STD_OFF


/*******************************************************************************
**                      Channel Handles                                       **
*******************************************************************************/


/* PWM Channel Handles */
#define   PwmChannel0      (uint8)0
#define   PwmChannel1      (uint8)2
#define   PwmChannel2      (uint8)4
#define   PwmChannel3      (uint8)6
#define   PwmChannel20      (uint8)16
#define   PwmChannel21      (uint8)17
#define   PwmChannel22      (uint8)18
#define   PwmChannel23      (uint8)19
#define   PwmChannel24      (uint8)20
#define   PwmChannel25      (uint8)21
#define   PwmChannel26      (uint8)22
#define   PwmChannel27      (uint8)23
#define   PwmChannel28      (uint8)24
#define   PwmChannel29      (uint8)26
#define   PwmChannel30      (uint8)28
#define   PwmChannel31      (uint8)29
#define   PwmChannel32      (uint8)30
#define   PwmChannel33      (uint8)31
#define   PwmChannel8      (uint8)32
#define   PwmChannel9      (uint8)33
#define   PwmChannel10      (uint8)34
#define   PwmChannel11      (uint8)35
#define   PwmChannel12      (uint8)36
#define   PwmChannel13      (uint8)37
#define   PwmChannel14      (uint8)38
#define   PwmChannel15      (uint8)39
#define   PwmChannel16      (uint8)40
#define   PwmChannel17      (uint8)41
#define   PwmChannel18      (uint8)42
#define   PwmChannel19      (uint8)43
#define   PwmChannel4      (uint8)48
#define   PwmChannel5      (uint8)49
#define   PwmChannel6      (uint8)50
#define   PwmChannel7      (uint8)51

/* Configuration Set Handles */
#define   PwmChannelConfigSet0    &Pwm_GstConfiguration[0]


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PWM_CFG_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/

