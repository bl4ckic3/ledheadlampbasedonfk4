/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu_Cfg.h                                                   */
/* Version      = 3.0.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
/*                                                                            */
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
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:              : Initial version
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  3.0.13a
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    FK4_4010_ICU_V304_130924_NEWCLEAPLUS.arxml
 * GENERATED ON:  30 Sep 2013 - 10:23:54
 */
#ifndef ICU_CFG_H
#define ICU_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define ICU_CFG_AR_MAJOR_VERSION  3
#define ICU_CFG_AR_MINOR_VERSION  0
#define ICU_CFG_AR_PATCH_VERSION  0

/* File version information */
#define ICU_CFG_SW_MAJOR_VERSION  3
#define ICU_CFG_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define ICU_AR_MAJOR_VERSION_VALUE  3
#define ICU_AR_MINOR_VERSION_VALUE  0
#define ICU_AR_PATCH_VERSION_VALUE  0

#define ICU_SW_MAJOR_VERSION_VALUE  3
#define ICU_SW_MINOR_VERSION_VALUE  0
#define ICU_SW_PATCH_VERSION_VALUE  0

#define ICU_VENDOR_ID_VALUE  (uint16)23
#define ICU_MODULE_ID_VALUE  (uint16)122


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the ICU Driver*/
#define ICU_INSTANCE_ID_VALUE               (uint8)0

/*Maximum number of channels configured*/
#define ICU_MAX_CHANNEL                      3

/* Total number of ICU TAU units configured for previous input used */
#define ICU_TOTAL_UNITS_FOR_PREVINPUT        0

/*Total number of ICU TAU units configured*/
#define ICU_TOTAL_TAU_UNITS_CONFIGURED       2

/*Maximum ICU Channel ID configured */
#define ICU_MAX_CHANNEL_ID_CONFIGURED       169

/*  Enables/Disables Development error detection  */
#define ICU_DEV_ERROR_DETECT                STD_OFF

/*  Enables/Disables wakeup source reporting  */
#define ICU_REPORT_WAKEUP_SOURCE            STD_OFF

/*  Enables/Disables the inclusion of Icu_DeInit API  */
#define ICU_DE_INIT_API                     STD_OFF

/*  Enables/Disables the inclusion of modules version information  */
#define ICU_GET_VERSION_INFO_API            STD_ON

/*  Enables/Disables the inclusion of Icu_SetMode API  */
#define ICU_SET_MODE_API                    STD_OFF

/*  Enables/Disables the inclusion of Icu_DisableWakeup  */
#define ICU_DISABLE_WAKEUP_API              STD_OFF

/*  Enables/Disables the inclusion of Icu_EnableWakeup API  */
#define ICU_ENABLE_WAKEUP_API               STD_OFF

/*  Enables/Disables the inclusion of Icu_GetInputState API  */
#define ICU_GET_INPUT_STATE_API             STD_OFF

/*  Enables/Disables the inclusion of Icu_StartTimestamp, 
      Icu_StopTimestamp and Icu_GetTimestampIndex APIs  */
#define ICU_TIMESTAMP_API                   STD_OFF

/*  Enables/Disables the inclusion of Icu_ResetEdgeCount, 
      Icu_EnableEdgeCount, Icu_DisableEdgeCount and Icu_GetEdgeNumbers APIs  */
#define ICU_EDGE_COUNT_API                  STD_OFF

/*  Enables/Disables the inclusion of Icu_GetTimeElapsed API  */
#define ICU_GET_TIME_ELAPSED_API            STD_OFF

/*  Enables/Disables the inclusion of Icu_GetDutyCycleValues API  */
#define ICU_GET_DUTY_CYCLE_VALUES_API       STD_ON

/*  Enables/Disables Icu_StartSignalMeasurement and 
      Icu_StopSignalMeasurement APIs  */
#define ICU_SIGNAL_MEASUREMENT_API          STD_ON

/*  Adds / removes all services related to the edge 
      detection functionality from the code  */
#define ICU_EDGE_DETECTION_API              STD_ON

/*  Enables/Disables the spilt of one Port pin signal to two TAU inputs  */
#define ICU_PREVIOUS_INPUT_USED             STD_OFF

/*  Macro for critical section  */
#define ICU_CRITICAL_SECTION_PROTECTION     STD_ON

/*  Enable/disable the setting of Prescaler, baudrate and
      blConfigurePrescaler by the ICU Driver  */
#define ICU_PRESCALER_CONFIGURED            STD_ON

/* Indicates the inclusion of notification function */
#define ICU_NOTIFICATION_CONFIG             STD_ON

/* Enables/Disables the use of TAUA unit depending on the TAUA channels configured*/
#define ICU_TAUA_UNIT_USED                  STD_ON

/* Enables/Disables the use of TAUB unit depending on the TAUB channels configured */
#define ICU_TAUB_UNIT_USED                  STD_ON

/* Enables/Disables the use of TAUJ unit depending on the TAUJ channels configured */
#define ICU_TAUJ_UNIT_USED                 STD_OFF

/* Indicates whether the timer channels configured or not*/
#define ICU_TIMER_CH_CONFIGURED             STD_ON




/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/
#define ICU_EXT_INTP_0_ISR_API    STD_OFF
#define ICU_EXT_INTP_10_ISR_API    STD_OFF
#define ICU_EXT_INTP_11_ISR_API    STD_OFF
#define ICU_EXT_INTP_12_ISR_API    STD_OFF
#define ICU_EXT_INTP_13_ISR_API    STD_ON
#define ICU_EXT_INTP_14_ISR_API    STD_OFF
#define ICU_EXT_INTP_15_ISR_API    STD_OFF
#define ICU_EXT_INTP_1_ISR_API    STD_OFF
#define ICU_EXT_INTP_2_ISR_API    STD_OFF
#define ICU_EXT_INTP_3_ISR_API    STD_OFF
#define ICU_EXT_INTP_4_ISR_API    STD_OFF
#define ICU_EXT_INTP_5_ISR_API    STD_OFF
#define ICU_EXT_INTP_6_ISR_API    STD_OFF
#define ICU_EXT_INTP_7_ISR_API    STD_OFF
#define ICU_EXT_INTP_8_ISR_API    STD_OFF
#define ICU_EXT_INTP_9_ISR_API    STD_OFF
#define ICU_TAUA0_CH0_ISR_API    STD_OFF
#define ICU_TAUA0_CH10_ISR_API    STD_OFF
#define ICU_TAUA0_CH11_ISR_API    STD_OFF
#define ICU_TAUA0_CH12_ISR_API    STD_OFF
#define ICU_TAUA0_CH13_ISR_API    STD_OFF
#define ICU_TAUA0_CH14_ISR_API    STD_OFF
#define ICU_TAUA0_CH15_ISR_API    STD_OFF
#define ICU_TAUA0_CH1_ISR_API    STD_OFF
#define ICU_TAUA0_CH2_ISR_API    STD_OFF
#define ICU_TAUA0_CH3_ISR_API    STD_OFF
#define ICU_TAUA0_CH4_ISR_API    STD_ON
#define ICU_TAUA0_CH5_ISR_API    STD_ON
#define ICU_TAUA0_CH6_ISR_API    STD_OFF
#define ICU_TAUA0_CH7_ISR_API    STD_OFF
#define ICU_TAUA0_CH8_ISR_API    STD_OFF
#define ICU_TAUA0_CH9_ISR_API    STD_OFF
#define ICU_TAUA1_CH0_ISR_API    STD_OFF
#define ICU_TAUA1_CH10_ISR_API    STD_OFF
#define ICU_TAUA1_CH11_ISR_API    STD_OFF
#define ICU_TAUA1_CH12_ISR_API    STD_OFF
#define ICU_TAUA1_CH13_ISR_API    STD_OFF
#define ICU_TAUA1_CH14_ISR_API    STD_OFF
#define ICU_TAUA1_CH15_ISR_API    STD_OFF
#define ICU_TAUA1_CH1_ISR_API    STD_OFF
#define ICU_TAUA1_CH2_ISR_API    STD_OFF
#define ICU_TAUA1_CH3_ISR_API    STD_OFF
#define ICU_TAUA1_CH4_ISR_API    STD_OFF
#define ICU_TAUA1_CH5_ISR_API    STD_OFF
#define ICU_TAUA1_CH6_ISR_API    STD_OFF
#define ICU_TAUA1_CH7_ISR_API    STD_OFF
#define ICU_TAUA1_CH8_ISR_API    STD_OFF
#define ICU_TAUA1_CH9_ISR_API    STD_OFF
#define ICU_TAUA2_CH0_ISR_API    STD_OFF
#define ICU_TAUA2_CH10_ISR_API    STD_OFF
#define ICU_TAUA2_CH11_ISR_API    STD_OFF
#define ICU_TAUA2_CH12_ISR_API    STD_OFF
#define ICU_TAUA2_CH13_ISR_API    STD_OFF
#define ICU_TAUA2_CH14_ISR_API    STD_OFF
#define ICU_TAUA2_CH15_ISR_API    STD_OFF
#define ICU_TAUA2_CH1_ISR_API    STD_OFF
#define ICU_TAUA2_CH2_ISR_API    STD_OFF
#define ICU_TAUA2_CH3_ISR_API    STD_OFF
#define ICU_TAUA2_CH4_ISR_API    STD_OFF
#define ICU_TAUA2_CH5_ISR_API    STD_OFF
#define ICU_TAUA2_CH6_ISR_API    STD_OFF
#define ICU_TAUA2_CH7_ISR_API    STD_OFF
#define ICU_TAUA2_CH8_ISR_API    STD_OFF
#define ICU_TAUA2_CH9_ISR_API    STD_OFF
#define ICU_TAUA3_CH0_ISR_API    STD_OFF
#define ICU_TAUA3_CH10_ISR_API    STD_OFF
#define ICU_TAUA3_CH11_ISR_API    STD_OFF
#define ICU_TAUA3_CH12_ISR_API    STD_OFF
#define ICU_TAUA3_CH13_ISR_API    STD_OFF
#define ICU_TAUA3_CH14_ISR_API    STD_OFF
#define ICU_TAUA3_CH15_ISR_API    STD_OFF
#define ICU_TAUA3_CH1_ISR_API    STD_OFF
#define ICU_TAUA3_CH2_ISR_API    STD_OFF
#define ICU_TAUA3_CH3_ISR_API    STD_OFF
#define ICU_TAUA3_CH4_ISR_API    STD_OFF
#define ICU_TAUA3_CH5_ISR_API    STD_OFF
#define ICU_TAUA3_CH6_ISR_API    STD_OFF
#define ICU_TAUA3_CH7_ISR_API    STD_OFF
#define ICU_TAUA3_CH8_ISR_API    STD_OFF
#define ICU_TAUA3_CH9_ISR_API    STD_OFF
#define ICU_TAUA4_CH0_ISR_API    STD_OFF
#define ICU_TAUA4_CH10_ISR_API    STD_OFF
#define ICU_TAUA4_CH11_ISR_API    STD_OFF
#define ICU_TAUA4_CH12_ISR_API    STD_OFF
#define ICU_TAUA4_CH13_ISR_API    STD_OFF
#define ICU_TAUA4_CH14_ISR_API    STD_OFF
#define ICU_TAUA4_CH15_ISR_API    STD_OFF
#define ICU_TAUA4_CH1_ISR_API    STD_OFF
#define ICU_TAUA4_CH2_ISR_API    STD_OFF
#define ICU_TAUA4_CH3_ISR_API    STD_OFF
#define ICU_TAUA4_CH4_ISR_API    STD_OFF
#define ICU_TAUA4_CH5_ISR_API    STD_OFF
#define ICU_TAUA4_CH6_ISR_API    STD_OFF
#define ICU_TAUA4_CH7_ISR_API    STD_OFF
#define ICU_TAUA4_CH8_ISR_API    STD_OFF
#define ICU_TAUA4_CH9_ISR_API    STD_OFF
#define ICU_TAUA5_CH0_ISR_API    STD_OFF
#define ICU_TAUA5_CH10_ISR_API    STD_OFF
#define ICU_TAUA5_CH11_ISR_API    STD_OFF
#define ICU_TAUA5_CH12_ISR_API    STD_OFF
#define ICU_TAUA5_CH13_ISR_API    STD_OFF
#define ICU_TAUA5_CH14_ISR_API    STD_OFF
#define ICU_TAUA5_CH15_ISR_API    STD_OFF
#define ICU_TAUA5_CH1_ISR_API    STD_OFF
#define ICU_TAUA5_CH2_ISR_API    STD_OFF
#define ICU_TAUA5_CH3_ISR_API    STD_OFF
#define ICU_TAUA5_CH4_ISR_API    STD_OFF
#define ICU_TAUA5_CH5_ISR_API    STD_OFF
#define ICU_TAUA5_CH6_ISR_API    STD_OFF
#define ICU_TAUA5_CH7_ISR_API    STD_OFF
#define ICU_TAUA5_CH8_ISR_API    STD_OFF
#define ICU_TAUA5_CH9_ISR_API    STD_OFF
#define ICU_TAUA6_CH0_ISR_API    STD_OFF
#define ICU_TAUA6_CH10_ISR_API    STD_OFF
#define ICU_TAUA6_CH11_ISR_API    STD_OFF
#define ICU_TAUA6_CH12_ISR_API    STD_OFF
#define ICU_TAUA6_CH13_ISR_API    STD_OFF
#define ICU_TAUA6_CH14_ISR_API    STD_OFF
#define ICU_TAUA6_CH15_ISR_API    STD_OFF
#define ICU_TAUA6_CH1_ISR_API    STD_OFF
#define ICU_TAUA6_CH2_ISR_API    STD_OFF
#define ICU_TAUA6_CH3_ISR_API    STD_OFF
#define ICU_TAUA6_CH4_ISR_API    STD_OFF
#define ICU_TAUA6_CH5_ISR_API    STD_OFF
#define ICU_TAUA6_CH6_ISR_API    STD_OFF
#define ICU_TAUA6_CH7_ISR_API    STD_OFF
#define ICU_TAUA6_CH8_ISR_API    STD_OFF
#define ICU_TAUA6_CH9_ISR_API    STD_OFF
#define ICU_TAUA7_CH0_ISR_API    STD_OFF
#define ICU_TAUA7_CH10_ISR_API    STD_OFF
#define ICU_TAUA7_CH11_ISR_API    STD_OFF
#define ICU_TAUA7_CH12_ISR_API    STD_OFF
#define ICU_TAUA7_CH13_ISR_API    STD_OFF
#define ICU_TAUA7_CH14_ISR_API    STD_OFF
#define ICU_TAUA7_CH15_ISR_API    STD_OFF
#define ICU_TAUA7_CH1_ISR_API    STD_OFF
#define ICU_TAUA7_CH2_ISR_API    STD_OFF
#define ICU_TAUA7_CH3_ISR_API    STD_OFF
#define ICU_TAUA7_CH4_ISR_API    STD_OFF
#define ICU_TAUA7_CH5_ISR_API    STD_OFF
#define ICU_TAUA7_CH6_ISR_API    STD_OFF
#define ICU_TAUA7_CH7_ISR_API    STD_OFF
#define ICU_TAUA7_CH8_ISR_API    STD_OFF
#define ICU_TAUA7_CH9_ISR_API    STD_OFF
#define ICU_TAUA8_CH0_ISR_API    STD_OFF
#define ICU_TAUA8_CH10_ISR_API    STD_OFF
#define ICU_TAUA8_CH11_ISR_API    STD_OFF
#define ICU_TAUA8_CH12_ISR_API    STD_OFF
#define ICU_TAUA8_CH13_ISR_API    STD_OFF
#define ICU_TAUA8_CH14_ISR_API    STD_OFF
#define ICU_TAUA8_CH15_ISR_API    STD_OFF
#define ICU_TAUA8_CH1_ISR_API    STD_OFF
#define ICU_TAUA8_CH2_ISR_API    STD_OFF
#define ICU_TAUA8_CH3_ISR_API    STD_OFF
#define ICU_TAUA8_CH4_ISR_API    STD_OFF
#define ICU_TAUA8_CH5_ISR_API    STD_OFF
#define ICU_TAUA8_CH6_ISR_API    STD_OFF
#define ICU_TAUA8_CH7_ISR_API    STD_OFF
#define ICU_TAUA8_CH8_ISR_API    STD_OFF
#define ICU_TAUA8_CH9_ISR_API    STD_OFF
#define ICU_TAUB1_CH0_ISR_API    STD_OFF
#define ICU_TAUB1_CH10_ISR_API    STD_OFF
#define ICU_TAUB1_CH11_ISR_API    STD_OFF
#define ICU_TAUB1_CH12_ISR_API    STD_OFF
#define ICU_TAUB1_CH13_ISR_API    STD_OFF
#define ICU_TAUB1_CH14_ISR_API    STD_OFF
#define ICU_TAUB1_CH15_ISR_API    STD_OFF
#define ICU_TAUB1_CH1_ISR_API    STD_OFF
#define ICU_TAUB1_CH2_ISR_API    STD_OFF
#define ICU_TAUB1_CH3_ISR_API    STD_OFF
#define ICU_TAUB1_CH4_ISR_API    STD_OFF
#define ICU_TAUB1_CH5_ISR_API    STD_OFF
#define ICU_TAUB1_CH6_ISR_API    STD_OFF
#define ICU_TAUB1_CH7_ISR_API    STD_OFF
#define ICU_TAUB1_CH8_ISR_API    STD_OFF
#define ICU_TAUB1_CH9_ISR_API    STD_OFF
#define ICU_TAUB2_CH0_ISR_API    STD_OFF
#define ICU_TAUB2_CH10_ISR_API    STD_OFF
#define ICU_TAUB2_CH11_ISR_API    STD_OFF
#define ICU_TAUB2_CH12_ISR_API    STD_OFF
#define ICU_TAUB2_CH13_ISR_API    STD_OFF
#define ICU_TAUB2_CH14_ISR_API    STD_OFF
#define ICU_TAUB2_CH15_ISR_API    STD_OFF
#define ICU_TAUB2_CH1_ISR_API    STD_OFF
#define ICU_TAUB2_CH2_ISR_API    STD_OFF
#define ICU_TAUB2_CH3_ISR_API    STD_OFF
#define ICU_TAUB2_CH4_ISR_API    STD_OFF
#define ICU_TAUB2_CH5_ISR_API    STD_OFF
#define ICU_TAUB2_CH6_ISR_API    STD_OFF
#define ICU_TAUB2_CH7_ISR_API    STD_OFF
#define ICU_TAUB2_CH8_ISR_API    STD_OFF
#define ICU_TAUB2_CH9_ISR_API    STD_OFF
#define ICU_TAUJ0_CH0_ISR_API    STD_OFF
#define ICU_TAUJ0_CH1_ISR_API    STD_OFF
#define ICU_TAUJ0_CH2_ISR_API    STD_OFF
#define ICU_TAUJ0_CH3_ISR_API    STD_OFF
#define ICU_TAUJ1_CH0_ISR_API    STD_OFF
#define ICU_TAUJ1_CH1_ISR_API    STD_OFF
#define ICU_TAUJ1_CH2_ISR_API    STD_OFF
#define ICU_TAUJ1_CH3_ISR_API    STD_OFF
#define ICU_TAUJ2_CH0_ISR_API    STD_OFF
#define ICU_TAUJ2_CH1_ISR_API    STD_OFF
#define ICU_TAUJ2_CH2_ISR_API    STD_OFF
#define ICU_TAUJ2_CH3_ISR_API    STD_OFF


/*******************************************************************************
**                      Channel Handles                                       **
*******************************************************************************/

/* ICU Channel Handles */
#define   IcuChannel0      (uint8)4
#define   IcuChannel2      (uint8)169

/* Configuration Set Handles */
#define IcuConfigSet0    &Icu_GstConfiguration[0]


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ICU_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
