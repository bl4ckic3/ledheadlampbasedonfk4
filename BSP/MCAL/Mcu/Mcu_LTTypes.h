/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Mcu_LTTypes.h                                               */
/* Version      = 3.0.1                                                       */
/* Date         = 09-Apr-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2010-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of RAM configuration Parameters    */
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
 * V3.0.0:  02-Jul-2010 : Initial Version
 * V3.0.1:  09-Apr-2013 : Merged Sx4-H V3.00 as below.
 *                        As per MANTIS 5337, updated to ulRamSectionSize.
 */
/******************************************************************************/

#ifndef MCU_LTTYPES_H
#define MCU_LTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Mcu.h"    /* To include the standard types */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification information */
#define MCU_LTTYPES_AR_MAJOR_VERSION  MCU_AR_MAJOR_VERSION_VALUE
#define MCU_LTTYPES_AR_MINOR_VERSION  MCU_AR_MINOR_VERSION_VALUE
#define MCU_LTTYPES_AR_PATCH_VERSION  MCU_AR_PATCH_VERSION_VALUE

/* File version information */
#define MCU_LTTYPES_SW_MAJOR_VERSION  3
#define MCU_LTTYPES_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* RAM Sector Data Structure */

typedef struct STagMcuRamSectorSetting
{
  /* Value of RAM Starting Address */
  P2VAR(uint8, AUTOMATIC, MCU_CONFIG_DATA)pRamStartAddress;
  /* Size of RAM Section  */
  uint32 ulRamSectionSize;
  /* RAM Initial Value */
  uint8  ucRamInitValue;
} Tdd_Mcu_RamSetting;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Array of structures for RAM Sector */
extern CONST(Tdd_Mcu_RamSetting, MCU_CONST) Mcu_GstRamSetting[];

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/

#endif /* MCU_LTTYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/

