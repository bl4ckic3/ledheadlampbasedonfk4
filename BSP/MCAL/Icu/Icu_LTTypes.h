/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu_LTTypes.h                                               */
/* Version      = 3.0.0a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains structure datatype for link time parameters of ICU      */
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
/*              Devices:        Xx4                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:  26-Aug-2009  : Initial version
 * V3.0.0a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef ICU_LTTYPES_H
#define ICU_LTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Icu.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define ICU_LTTYPES_AR_MAJOR_VERSION    ICU_AR_MAJOR_VERSION_VALUE
#define ICU_LTTYPES_AR_MINOR_VERSION    ICU_AR_MINOR_VERSION_VALUE
#define ICU_LTTYPES_AR_PATCH_VERSION    ICU_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define ICU_LTTYPES_SW_MAJOR_VERSION  3
#define ICU_LTTYPES_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Structure of function pointer for Callback notification function */
typedef struct STagTdd_Icu_ChannelFuncType
{
  /* Pointer to callback notification function */
  P2FUNC (void, ICU_APPL_CODE, pIcuNotificationPointer)(void);
} Tdd_Icu_ChannelFuncType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define ICU_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Declaration for ICU Channel Callback functions Configuration */
extern CONST(Tdd_Icu_ChannelFuncType, ICU_CONST) Icu_GstChannelFunc[];

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#endif /* ICU_LTTYPES_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
