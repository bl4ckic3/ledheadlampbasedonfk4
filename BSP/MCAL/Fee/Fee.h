/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Fee.h                                                       */
/* Version      = 3.0.1a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, FEE type definitions, structure data types and  */
/* API function prototypes of FEE Component                                   */
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
 * V3.0.1:  31-Aug-2010  : As per SCR 348, updated Include Section
 * V3.0.1a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef  FEE_H
#define  FEE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Fee_Cfg.h"
#include "EEL_Descriptor.h"
#include "FDL_Descriptor.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* Version identification */
#define FEE_VENDOR_ID              FEE_VENDOR_ID_VALUE
#define FEE_MODULE_ID              FEE_MODULE_ID_VALUE
#define FEE_INSTANCE_ID            FEE_INSTANCE_ID_VALUE


/* AUTOSAR specification version information */
#define FEE_AR_MAJOR_VERSION       FEE_AR_MAJOR_VERSION_VALUE
#define FEE_AR_MINOR_VERSION       FEE_AR_MINOR_VERSION_VALUE
#define FEE_AR_PATCH_VERSION       FEE_AR_PATCH_VERSION_VALUE

/* File version information */
#define FEE_SW_MAJOR_VERSION       FEE_SW_MAJOR_VERSION_VALUE
#define FEE_SW_MINOR_VERSION       FEE_SW_MINOR_VERSION_VALUE
#define FEE_SW_PATCH_VERSION       FEE_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                        Service IDs                                         **
*******************************************************************************/

/* Service Id of Fee_Init */
#define FEE_INIT_SID                 (uint8)0x00
/* Service Id of Fee_SetMode */
#define FEE_SETMODE_SID              (uint8)0x01
/* Service Id of Fee_Read */
#define FEE_READ_SID                 (uint8)0x02
/* Service Id of Fee_Write */
#define FEE_WRITE_SID                (uint8)0x03
/* Service Id of Fee_Cancel */
#define FEE_CANCEL_SID               (uint8)0x04
/* Service Id of Fee_GetStatus */
#define FEE_GETSTATUS_SID            (uint8)0x05
/* Service Id of Fee_GetJobResult */
#define FEE_GETJOBRESULT_SID         (uint8)0x06
/* Service Id of Fee_InvalidateBlock */
#define FEE_INVALIDATEBLOCK_SID      (uint8)0x07
/* Service Id of Fee_GetVersionInfo */
#define FEE_GET_VERSION_INFO_SID     (uint8)0x08
/* Service Id of Fee_EraseImmediateBlock */
#define FEE_ERASEIMMEDIATEBLOCK_SID  (uint8)0x09


/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/


/* API service called with invalid block number */
#define FEE_E_INVALID_BLOCK_NO       (uint8)0x02

/* API service called with invalid length */
#define FEE_E_INVALID_BLOCK_LEN      (uint8)0x05

/* API service called before initialization */
#define FEE_E_UNINIT                 (uint8)0xEF

/* API service Fee_GetVersionInfo invoked with invalid pointer */
#define FEE_E_PARAM_POINTER          (uint8)0xF0

/* API service Fee_Init called when already initialized */
#define FEE_E_ALREADY_INITIALIZED    (uint8)0xF1

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* API declaration for main function */
extern FUNC(void, FEE_PUBLIC_CODE) Fee_MainFunction(void);

/* API declaration for initialization function */
extern FUNC(void, FEE_PUBLIC_CODE) Fee_Init(void);

/* API declaration for read function */
extern FUNC(Std_ReturnType, FEE_PUBLIC_CODE) Fee_Read
  (
   uint16 BlockNumber, uint16 BlockOffset,
   P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA)DataBufferPtr, uint16 Length
  );

/* API declaration for setmode function */
extern FUNC(void, FEE_PUBLIC_CODE) Fee_SetMode(MemIf_ModeType Mode);

/* API declaration for write function */
extern FUNC(Std_ReturnType, FEE_PUBLIC_CODE) Fee_Write
  (
   uint16 BlockNumber, P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA)DataBufferPtr
  );

/* API declaration for cancel function */
extern FUNC(void, FEE_PUBLIC_CODE) Fee_Cancel(void);

/* API declaration for get status function */
extern FUNC(MemIf_StatusType, FEE_PUBLIC_CODE) Fee_GetStatus(void);

/* API declaration for get job result function */
extern FUNC(MemIf_JobResultType, FEE_PUBLIC_CODE) Fee_GetJobResult(void);

/* API declaration for invalidate block function */
extern FUNC(Std_ReturnType, FEE_PUBLIC_CODE) Fee_InvalidateBlock
  (uint16 BlockNumber);

/* API declaration for erase function */
extern FUNC(Std_ReturnType, FEE_PUBLIC_CODE) Fee_EraseImmediateBlock
  (uint16 BlockNumber);

#if (FEE_VERSION_INFO_API == STD_ON)
/* API declaration for version information function */
extern FUNC(void, FEE_PUBLIC_CODE) Fee_GetVersionInfo
  (
  P2VAR(Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA) VersionInfoPtr
  );
#endif

#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif  /* FEE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
