/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Mcu_Ram.h                                                   */
/* Version      = 3.0.1                                                      */
/* Date         = 15-Mar-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2010-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the extern declarations of global RAM variables of MCU  */
/* Driver                                                                     */
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
/*              Devices:        Fx4                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0: 02-Jul-2010  : Initial Version
 * V3.0.0a: 18-Oct-2011 : Copyright is updated.
 * V3.0.1: 15-Mar-2013  : As per SCR 091, The following changes have been made,
 *                        1. Alignment is changed as per code guidelines.
 */
/******************************************************************************/
#ifndef MCU_RAM_H
#define MCU_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Mcu.h"
#include "Mcu_PBTypes.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define MCU_RAM_AR_MAJOR_VERSION    MCU_AR_MAJOR_VERSION_VALUE
#define MCU_RAM_AR_MINOR_VERSION    MCU_AR_MINOR_VERSION_VALUE
#define MCU_RAM_AR_PATCH_VERSION    MCU_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define MCU_RAM_SW_MAJOR_VERSION    3
#define MCU_RAM_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store the config pointer */
extern P2CONST(Mcu_ConfigType, MCU_CONST, MCU_CONFIG_CONST) Mcu_GpConfigPtr;

/* Global pointer variable for MCU Clock Setting configuration */
extern P2CONST(Tdd_Mcu_ClockSetting, MCU_CONST, MCU_CONFIG_CONST)
                                                             Mcu_GpClockSetting;

#define MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define MCU_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
/* Global pointer to CKSC register offset */
extern P2CONST(uint16, AUTOMATIC, MCU_CONFIG_CONST) Mcu_GpCkscRegOffset;

#define MCU_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"

#define MCU_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"
/* Global pointer to CKSC register value */
extern P2CONST(uint32, AUTOMATIC, MCU_CONFIG_CONST) Mcu_GpCkscRegValue;

#define MCU_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"

#define MCU_START_SEC_VAR_1BIT
#include "MemMap.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store Initialization status of MCU Driver */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblDriverStatus;
#endif

#define MCU_STOP_SEC_VAR_1BIT
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_RAM_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
