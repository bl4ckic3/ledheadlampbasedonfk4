/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Fee_Types.h                                                 */
/* Version      = 3.0.4a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains type declarations of FEE Component                      */
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
 * V3.0.1:  09-Feb-2010  : As per SCR 184 and 188, following changes are made:
 *                         1. A macro FEE_UNINIT is added and the
 *                         value of the macro FEE_IDLE is changed from 0 to 8
 *                         2. The macro definition of FEE_ERASE_NOTIFICATION
 *                         is removed.
 * V3.0.2:  01-Apr-2010  : As per SCR 234, a macro FEE_INVALID_BLOCK_IDX is
 *                         added.
 * V3.0.3:  31-Aug-2010  : As per SCR 348, included Std_Types.h.
 * V3.0.4:  12-Oct-2010  : As per SCR 367, macros FEE_INITIALIZED and
 *                         FEE_UNINITIALIZED are modified.
 * V3.0.4a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef FEE_TYPES_H
#define FEE_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "EEL.h"
#include "FDL.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define FEE_TYPES_AR_MAJOR_VERSION    FEE_AR_MAJOR_VERSION_VALUE
#define FEE_TYPES_AR_MINOR_VERSION    FEE_AR_MINOR_VERSION_VALUE
#define FEE_TYPES_AR_PATCH_VERSION    FEE_AR_PATCH_VERSION_VALUE

/* File version information */
#define FEE_TYPES_SW_MAJOR_VERSION    3
#define FEE_TYPES_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Common macros */
#define FEE_ZERO                      (uint8)0
#define FEE_ONE                       (uint16)1
#define FEE_TRUE                      (uint8)1
#define FEE_FALSE                     (uint8)0

/* States to hold initialization status */
#define FEE_INITIALIZED               (boolean)TRUE
#define FEE_UNINITIALIZED             (boolean)FALSE

/* States to hold cancel request status */
#define FEE_CANCEL_INPROG             (uint8)1
#define FEE_REQ_AFT_CAN_ACCEPTED      (uint8)2

/* Main states of FEE software component */
#define FEE_UNINIT                    (uint8)0
#define FEE_IDLE                      (uint8)8
#define FEE_STARTUP                   (uint8)1
#define FEE_BUSY_FLASH_OPERATION      (uint8)2
#define FEE_FORMAT                    (uint8)4


#define FEE_JOB_COMPLETED             (uint8)5
#define FEE_JOB_CANCELLED             (uint8)6
#define FEE_JOB_INPROG                (uint8)7

#define FEE_INVALID_BLOCK_IDX         (uint16)0xFFFF


/* Structure to hold block configuration */
typedef struct STagFee_BlockConfigType
{
  uint16 usFeeBlockNumber;
  uint16 usFeeBlockSize;
  boolean blFeeImmediateData;
} Tdd_Fee_BlockConfigType;

/* Structure to hold function pointer for notifications */
typedef struct STagFee_FuncType
{
  P2FUNC (void, FEE_APPL_CODE, pFee_JobEndNotification) (void);
  P2FUNC (void, FEE_APPL_CODE, pFee_JobErrorNotification) (void);

} Tdd_Fee_FuncType;

/* Global Structure to handle the Global Variables */
typedef struct STagTdd_Fee_GstVar
{
  /* Variable to hold the Normal command */
  VAR(eel_request_t, FEE_NOINIT_DATA) GstRequest;
  
  /* Variable to hold the Immediate command after Fee_Cancel */
  VAR(eel_request_t, FEE_NOINIT_DATA) GstNewReq;

  /* Variable to hold the result of request */
  VAR(MemIf_JobResultType, FEE_NOINIT_DATA) GenJobResult;
  
  /* Variable to hold the state of FEE software component */
  VAR(uint8, FEE_NOINIT_DATA) GucState;
  
  /* Variable to hold the state of Previous request */
  VAR(uint8, FEE_NOINIT_DATA) GucPreviousJobState;
 
}Tdd_Fee_GstVar;

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define FEE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*
 * This array defines the structure for each block configured
 * in input ARXML file
 */
extern CONST(Tdd_Fee_BlockConfigType, FEE_CONST) Fee_GstBlockConfiguration[];

/* This structure contains the function pointer for callback functions */
extern CONST(Tdd_Fee_FuncType, FEE_CONST) Fee_GstFunctionNotification;

#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif  /* FEE_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
