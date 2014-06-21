/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Fee_Ram.h                                                   */
/* Version      = 3.0.2a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains global variable declarations of FEE Component           */
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
 * V3.0.0:  02-Nov-2009  : Initial version
 * V3.0.1:  20-Jan-2010  : As per SCR 184, the comment for Fee_GstVar is
 *                         updated
 * V3.0.2:  31-Aug-2010  : As per SCR 348, updated Include Section
 * V3.0.2a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef FEE_RAM_H
#define FEE_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"
#include "Fee_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define FEE_RAM_AR_MAJOR_VERSION    FEE_AR_MAJOR_VERSION_VALUE
#define FEE_RAM_AR_MINOR_VERSION    FEE_AR_MINOR_VERSION_VALUE
#define FEE_RAM_AR_PATCH_VERSION    FEE_AR_PATCH_VERSION_VALUE

/* File version information */
#define FEE_RAM_SW_MAJOR_VERSION    3
#define FEE_RAM_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Structure variable that contains FEE Global variables */
extern VAR(Tdd_Fee_GstVar, FEE_NOINIT_DATA) Fee_GstVar;

#define FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


#if (FEE_DEV_ERROR_DETECT == STD_ON)

#define FEE_START_SEC_VAR_1BIT
#include "MemMap.h"

/* Variable to hold the status of Initialization */
extern VAR(boolean, FEE_INIT_DATA) Fee_GblInitStatus;

#define FEE_STOP_SEC_VAR_1BIT
#include "MemMap.h"

#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif  /* FEE_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
