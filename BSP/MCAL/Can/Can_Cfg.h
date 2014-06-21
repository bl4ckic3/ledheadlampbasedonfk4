/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_Cfg.h                                                   */
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
**                    CAN Driver Generation Tool Version                      **
*******************************************************************************/
/*
 * TOOL VERSION:  3.0.13a
*/

#ifndef CAN_CFG_H 
#define CAN_CFG_H


/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    FK4_4010_MCU_V304_130427.arxml
 *                EcuM_Can.arxml
 *                FK4_4010_CAN_TST.arxml
 * GENERATED ON:  24 Jul 2013 - 16:51:03
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* Autosar Specification Version Information */
#define CAN_CFG_AR_MAJOR_VERSION   2
#define CAN_CFG_AR_MINOR_VERSION   2
#define CAN_CFG_AR_PATCH_VERSION   2

/* File Version Information */
#define CAN_CFG_SW_MAJOR_VERSION   3
#define CAN_CFG_SW_MINOR_VERSION   0


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Common Published Information */
#define CAN_AR_MAJOR_VERSION_VALUE   2
#define CAN_AR_MINOR_VERSION_VALUE   2
#define CAN_AR_PATCH_VERSION_VALUE   2

#define CAN_SW_MAJOR_VERSION_VALUE   3
#define CAN_SW_MINOR_VERSION_VALUE   0
#define CAN_SW_PATCH_VERSION_VALUE   0


/* CAN Module Id */
#define CAN_MODULE_ID_VALUE          (uint16)80

/* CAN Vendor Id */
#define CAN_VENDOR_ID_VALUE          (uint16)23

/* CAN Instance Id */
#define CAN_INSTANCE_ID_VALUE        (uint8)0


/* Pre-compile option for Development Error Detect */
#define CAN_DEV_ERROR_DETECT                   STD_ON
/* Pre-compile option for Standard CAN-ID */
#define CAN_STANDARD_CANID                     STD_ON
/* Pre-compile option for Multiplexed Transmission */
#define CAN_MULTIPLEX_TRANSMISSION             STD_OFF
/* Pre-compile option for Version Info API */
#define CAN_VERSION_INFO_API                   STD_OFF
/* Pre-compile option for Can Wakeup Support */
#define CAN_WAKEUP_SUPPORT                     STD_ON
/* Pre-compile option for Can Transmit Cancellation Support */
#define CAN_HW_TRANSMIT_CANCELLATION_SUPPORT   STD_OFF
/* Pre-compile option for Can Wakeup Interrupts Tied */
#define CAN_WAKEUP_INTERRUPTS_TIED             STD_ON


/* Pre-compile option for Busoff Period */
#define CAN_MAINFUNCTION_BUSOFF_PERIOD 1

/* Pre-compile option for Read Period */
#define CAN_MAINFUNCTION_READ_PERIOD 1

/* Pre-compile option for Wakeup Period */
#define CAN_MAINFUNCTION_WAKEUP_PERIOD 1

/* Pre-compile option for Write Period */
#define CAN_MAINFUNCTION_WRITE_PERIOD 1


/* Pre-compile option for Busoff Interrupt */
#define CAN_CONTROLLER1_BUSOFF_INTERRUPT STD_OFF
#define CAN_CONTROLLER0_BUSOFF_INTERRUPT STD_OFF
#define CAN_CONTROLLER2_BUSOFF_INTERRUPT STD_OFF
#define CAN_CONTROLLER3_BUSOFF_INTERRUPT STD_OFF
#define CAN_CONTROLLER4_BUSOFF_INTERRUPT STD_OFF
#define CAN_CONTROLLER5_BUSOFF_INTERRUPT STD_OFF

/* Pre-compile option for Wakeup Interrupt */
#define CAN_CONTROLLER1_WAKEUP_INTERRUPT STD_OFF
#define CAN_CONTROLLER0_WAKEUP_INTERRUPT STD_OFF
#define CAN_CONTROLLER2_WAKEUP_INTERRUPT STD_OFF
#define CAN_CONTROLLER3_WAKEUP_INTERRUPT STD_OFF
#define CAN_CONTROLLER4_WAKEUP_INTERRUPT STD_OFF
#define CAN_CONTROLLER5_WAKEUP_INTERRUPT STD_OFF

/* Pre-compile option for Rx Interrupt */
#define CAN_CONTROLLER1_RX_INTERRUPT STD_OFF
#define CAN_CONTROLLER0_RX_INTERRUPT STD_OFF
#define CAN_CONTROLLER2_RX_INTERRUPT STD_OFF
#define CAN_CONTROLLER3_RX_INTERRUPT STD_OFF
#define CAN_CONTROLLER4_RX_INTERRUPT STD_OFF
#define CAN_CONTROLLER5_RX_INTERRUPT STD_OFF

/* Pre-compile option for Tx Interrupt */
#define CAN_CONTROLLER1_TX_INTERRUPT STD_OFF
#define CAN_CONTROLLER0_TX_INTERRUPT STD_OFF
#define CAN_CONTROLLER2_TX_INTERRUPT STD_OFF
#define CAN_CONTROLLER3_TX_INTERRUPT STD_OFF
#define CAN_CONTROLLER4_TX_INTERRUPT STD_OFF
#define CAN_CONTROLLER5_TX_INTERRUPT STD_OFF


/* Pre-compile option for Tx Polling */
#define CAN_TX_POLLING STD_ON

/* Pre-compile option for Rx Polling */
#define CAN_RX_POLLING STD_ON

/* Pre-compile option for BusOff Polling */
#define CAN_BUSOFF_POLLING STD_ON

/* Pre-compile option for Wakeup Polling */
#define CAN_WAKEUP_POLLING STD_ON


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* Timeout Count */
#define CAN_TIMEOUT_COUNT                 (uint16)2000

/* Maximum number of Controllers */
#define CAN_MAX_NUMBER_OF_CONTROLLER      (uint8_least)2



typedef uint16 Can_IdType;

/*******************************************************************************
**                          Handles                                           **
*******************************************************************************/
/* Hardware Objects Configuration Handle */
#define CanHardwareObject_1                 0
#define CanHardwareObject_2                 1
#define CanHardwareObject_3                 2
#define CanHardwareObject_4                 3

/* CAN Controller Configuration Handle */
#define CanController_1                     0
#define CanController_2                     1



/* Configuration Set Handles */
#define CanConfigSet_1 &Can_AFCan_GaaConfigType[0]

/* CAN Controller Configuration Handles */
#define CanControllerCanConfigSet_1 &Can_AFCan_GaaControllerConfigType[0] 

#endif /* CAN_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
