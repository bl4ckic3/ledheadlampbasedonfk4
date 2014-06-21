/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Fee.c                                                       */
/* Version      = 3.0.9a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API function implementations of FEE Component           */
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
 * V3.0.0:  05-Nov-2009  : Initial version
 * V3.0.1:  10-Nov-2009  : As per SCR 118, API Fee_Cancel is updated
 * V3.0.2:  20-Nov-2009  : As per SCR 148, API Fee_MainFunction is updated
 * V3.0.3:  09-Feb-2010  : As per SCR 184 and 188, following changes are made:
 *                         1. The APIs Fee_Init and Fee_MainFunction are
 *                         updated for FEE_STARTUP_INTERNAL
 *                         2. The API Fee_EraseImmediateBlock is updated for the
 *                         GucState and the end notification.
 *                         3. SchM_Enter and SchM_Exit are added for the APIs 
 *                         Fee_Read, Fee_Write and Fee_InvalidateBlock.
 *                         4. SchM_Enter and SchM_Exit are removed from
 *                         Fee_GetStatus and Fee_MainFunction, during the Starup
 *                         process.
 *                         5. In Fee_GetStatus API, the check for
 *                         "driverStatus_str.operationStatus_enu == 
 *                         EEL_OPERATION_BUSY" is replaced by
 *                         "Fee_GstVar.GucState != FEE_IDLE"
 * V3.0.4: 01-Mar-2010  :  As per SCR 205, following changes are made:
 *                         1. MEMIF_JOB_OK is removed in
 *                         Fee_MainFunction for the FEE_STARTUP condition.
 *                         2. Misra comments are added in Fee_Init API.
 * V3.0.5: 05-Mar-2010  :  As per SCR 218, in Fee_Init and Fee_MainFunction
 *                         EEL_Handler is invoked before EEL_Execute.
 * V3.0.6: 12-Mar-2010  :  As per SCR 223, description of the APIs is updated.
 * V3.0.7: 01-Apr-2010  :  As per SCR 234, the APIs Fee_Read, Fee_Write 
 *                         Fee_InvalidateBlock and Fee_EraseImmediateBlock are
 *                         updated for retrieving the index of configured
 *                         FeeBlockNumber from array Fee_GstBlockConfiguration.
 * V3.0.8: 24-Jun-2010  :  As per SCR 287, following changes are made:
 *                         1. The APIs Fee_GetStatus, Fee_MainFunction are 
 *                         updated.
 *                         2. Comments for invalidate command is corrected.
 * V3.0.9: 10-Jul-2010  :  As per SCR 301, comment is updated for the Format
 *                         command in the API Fee_MainFunction.
 * V3.0.9a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fee.h"
#include "Fee_Types.h"
#include "Fee_InternalFct.h"
#include "Fee_Ram.h"
#if (FEE_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
//#include "Dem.h"
#if(FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
//#include "SchM_Fee.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define FEE_C_AR_MAJOR_VERSION    FEE_AR_MAJOR_VERSION_VALUE
#define FEE_C_AR_MINOR_VERSION    FEE_AR_MINOR_VERSION_VALUE
#define FEE_C_AR_PATCH_VERSION    FEE_AR_PATCH_VERSION_VALUE

/* File version information */
#define FEE_C_SW_MAJOR_VERSION    3
#define FEE_C_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (FEE_AR_MAJOR_VERSION != FEE_C_AR_MAJOR_VERSION)
  #error "Fee.c : Mismatch in Specification Major Version"
#endif

#if (FEE_AR_MINOR_VERSION != FEE_C_AR_MINOR_VERSION)
  #error "Fee.c : Mismatch in Specification Minor Version"
#endif

#if (FEE_AR_PATCH_VERSION != FEE_C_AR_PATCH_VERSION)
  #error "Fee.c : Mismatch in Specification Patch Version"
#endif

#if (FEE_SW_MAJOR_VERSION != FEE_C_SW_MAJOR_VERSION)
  #error "Fee.c : Mismatch in Major Version"
#endif

#if (FEE_SW_MINOR_VERSION != FEE_C_SW_MINOR_VERSION)
  #error "Fee.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Fee_Init
**
** Service ID         : 0x00
**
** Description        : This API performs the initialization of FEE software
**                      component.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable(s):
**                      Fee_GstVar, Fee_GblInitStatus
**
**                      Function(s) invoked:
**                      FAL_Init, EEL_Init, EEL_Startup, EEL_Handler,
**                      EEL_Execute, EEL_GetDriverStatus, Det_ReportError
**                      Dem_ReportErrorStatus
**
*******************************************************************************/
#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, FEE_PUBLIC_CODE) Fee_Init(void)
{
  volatile fal_status_t LenFalStatus;
  volatile eel_status_t LenEelStatus;

  #if (FEE_STARTUP_INTERNAL == STD_ON)
  eel_driver_status_t driverStatus_str;
  #endif

  boolean LblInitFail;
  /* Update the default value of flag as initialization pass */
  LblInitFail = FEE_FALSE;

  #if (FEE_DEV_ERROR_DETECT == STD_ON)
  /* Check if the FEE Component is already initialized */
  if(Fee_GblInitStatus == FEE_INITIALIZED)
  {
    /* Report Error to DET */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INIT_SID,
                                                FEE_E_ALREADY_INITIALIZED);
  }
  else
  #endif /* End of (FEE_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Invoke the initialization function of FAL */
    LenFalStatus = FAL_Init(&eelApp_falConfig_enu);

    /* Check if LenFalStatus is FAL_OK */
    if(LenFalStatus == FAL_OK)
    {
      /* Invoke the initialization function of EEL */
      LenEelStatus = EEL_Init(&eelApp_eelConfig,EEL_OPERATION_MODE_NORMAL);

      /* Check if LenEelStatus is EEL_OK */
      if(LenEelStatus == EEL_OK)
      {
        /* Invoke the startup function of EEL */
        LenEelStatus = EEL_Startup();

        /* Check if LenEelStatus is EEL_OK */
        if(LenEelStatus == EEL_OK)
        {
          #if (FEE_STARTUP_INTERNAL == STD_ON)
          do
          {
            /* Invoke the Handler function */
            EEL_Handler();
            /* Invoke EEL_GetDriverStatus function to get driver status */
            (void)EEL_GetDriverStatus(&driverStatus_str);

            /* Check operation status is EEL_OPERATION_PASSIVE */
            if(driverStatus_str.operationStatus_enu == EEL_OPERATION_PASSIVE)
            {
              /* Report failure of startup to DEM */
              Dem_ReportErrorStatus((Dem_EventIdType)FEE_E_STARTUP_FAILED,
                                 (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);

              /* Update the flag for initialization fail */
              LblInitFail = FEE_TRUE;
            }

            #if (FEE_AUTO_FORMAT_FLASH == STD_ON)
            /* Check backround status is EEL_ERR_POOL_INCONSISTENT */
            if(driverStatus_str.backgroundStatus_enu ==
                                             EEL_ERR_POOL_INCONSISTENT)
            {
              /* If no active section is found, update the command to Format */
              Fee_GstVar.GstRequest.command_enu = EEL_CMD_FORMAT;
              /* Set job result to MEMIF_BLOCK_INCONSISTENT */
              Fee_GstVar.GenJobResult = MEMIF_BLOCK_INCONSISTENT;

              /* Update the flag for initialization fail */
              LblInitFail = FEE_FALSE;

              /* 
               * Invoke the Handler function to proceed EEL state for format
               * acceptance
               */ 
              EEL_Handler();

              /*
               * Invoke the API to perform the operation based on updated
               * command
               */
              EEL_Execute(&Fee_GstVar.GstRequest);
              do
              {
                /* Invoke the Handler function */
                EEL_Handler();
              }while((Fee_GstVar.GstRequest.status_enu == EEL_BUSY));

              /* Check request status is EEL_OK */
              if(Fee_GstVar.GstRequest.status_enu == EEL_OK)
              {
                /* Invoke the initialization function of EEL */
                LenEelStatus =
                        EEL_Init(&eelApp_eelConfig, EEL_OPERATION_MODE_NORMAL);

                /* MISRA Rule         : 1.1                            */
                /* Message            : Nesting of control statements  */
                /*                      exceeds 15                     */
                /* Reason             : It is used to achieve better   */
                /*                      throughput instead of invoking */
                /*                      a function call.               */
                /* Verification       : However, part of the code      */
                /*                      is verified with compiler and  */
                /*                      it is not having any impact.   */

                /* Check LenEelStatus is EEL_OK */
                if(LenEelStatus == EEL_OK)
                {
                  /* Invoke the startup function of EEL */
                  LenEelStatus = EEL_Startup();

                  /* Check LenEelStatus is EEL_OK */
                  if(LenEelStatus != EEL_OK)
                  {
                    /* Update the flag for initialization fail */
                    LblInitFail = FEE_TRUE;
                  }
                }
                /* MISRA Rule         : 1.1                            */
                /* Message            : Nesting of control statements  */
                /*                      exceeds 15                     */
                /* Reason             : It is used to achieve better   */
                /*                      throughput instead of invoking */
                /*                      a function call.               */
                /* Verification       : However, part of the code      */
                /*                      is verified with compiler and  */
                /*                      it is not having any impact.   */
                else
                {
                  /* Update the flag for initialization fail */
                  LblInitFail = FEE_TRUE;
                }
              }
              else
              {
                /* Update the flag for initialization fail */
                LblInitFail = FEE_TRUE;

                /* Report failure of format job request to DEM */
                Dem_ReportErrorStatus((Dem_EventIdType)FEE_FORMAT_FAILED,
                  (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);
              }
            } /* End of (driverStatus_str.backgroundStatus_enu ==
                                            EEL_ERR_POOL_INCONSISTENT) */
            #endif /* End of (FEE_AUTO_FORMAT_FLASH == STD_ON) */
          }
          #if (FEE_STARTUP_LIMITED_ACCESS == STD_OFF)
          /* Wait until the system is completely up and running (or error) */
          while((driverStatus_str.accessStatus_enu != EEL_ACCESS_UNLOCKED) &&
                (LblInitFail == FEE_FALSE));
          #else
          /* Wait until early read/write is possible (or error) */
          while((driverStatus_str.accessStatus_enu != EEL_ACCESS_READ_WRITE) &&
                 (LblInitFail == FEE_FALSE));
          #endif /* End of else part of
                  * (FEE_STARTUP_LIMITED_ACCESS == STD_OFF)
                  */
          /* Is LblInitFail false, indicating initialization is successfull */
          if (LblInitFail == FEE_FALSE)
          {
            /*
             * Initialize the current state, job result and previous job
             * request state
             */
            Fee_GstVar.GucState = FEE_IDLE;
            Fee_GstVar.GenJobResult = MEMIF_JOB_OK;
            Fee_GstVar.GucPreviousJobState = FEE_JOB_COMPLETED;

            #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_GblInitStatus = FEE_INITIALIZED;
            #endif
          }
          #else  /* else part of (FEE_STARTUP_INTERNAL == STD_ON) */
          /*
           * Initialize the current state, job result and previous job
           * request state
           */
          Fee_GstVar.GucState = FEE_STARTUP;
          Fee_GstVar.GenJobResult = MEMIF_JOB_OK;
          Fee_GstVar.GucPreviousJobState = FEE_JOB_COMPLETED;

          /*
           * This is used to check the initialization of the component
           * only if DET is enabled
           */
          #if (FEE_DEV_ERROR_DETECT == STD_ON)
          Fee_GblInitStatus = FEE_INITIALIZED;
          #endif
          #endif /* End of else part of (FEE_STARTUP_INTERNAL == STD_ON) */
        }
        else
        {
          /* Update the flag for initialization fail */
          LblInitFail = FEE_TRUE;
        }
      }
      else
      {
        /* Update the flag for initialization fail */
        LblInitFail = FEE_TRUE;
      }
    }
    else
    {
      /* Update the flag for initialization fail */
      LblInitFail = FEE_TRUE;
    }
    /* Check LblInitFail for initialization fail */
    if(LblInitFail == FEE_TRUE)
    {
      /*
       * Initialize the current state, job result and previous job
       * request state
       */
      Fee_GstVar.GucState = FEE_UNINIT;
      Fee_GstVar.GenJobResult = MEMIF_JOB_OK;
      Fee_GstVar.GucPreviousJobState = FEE_JOB_COMPLETED;
    }
  }
}

#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Fee_SetMode
**
** Service ID         : 0x01
**
** Description        : This API does not provide any functionality to the user
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : Mode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable(s):
**                      None
**
**                      Function(s) invoked:
**                      None
**
*******************************************************************************/

#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, FEE_PUBLIC_CODE) Fee_SetMode(MemIf_ModeType Mode)
{
  /* This API does not provide any functionality to the user */
}
#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Fee_Read
**
** Service ID         : 0x02
**
** Description        : Service for calling the read function of the
**                      underlying Flash Emulation Library
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : BlockNumber, BlockOffset, DataBufferPtr, Length
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : LenReqResult
**
** Preconditions      : FEE software component should be initialized
**
** Remarks            : Global Variable(s):
**                      Fee_GblInitStatus, Fee_GstBlockConfiguration,
**                      Fee_GstVar
**
**                      Function(s) invoked:
**                      Det_ReportError, Fee_BlockCfgLookUp, EEL_Execute
**                      SchM_Enter_Fee, SchM_Exit_Fee
**
*******************************************************************************/
#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC (Std_ReturnType, FEE_PUBLIC_CODE) Fee_Read (uint16 BlockNumber,
  uint16 BlockOffset, P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA) DataBufferPtr,
  uint16 Length)
{
  P2VAR(eel_request_t, AUTOMATIC, FEE_PRIVATE_DATA)LpStRequest;
  Std_ReturnType LenReqResult;

  #if (FEE_DEV_ERROR_DETECT == STD_ON)
  P2CONST(Tdd_Fee_BlockConfigType, AUTOMATIC, FEE_PRIVATE_CONST)LpBlockConfig;
  uint16 LusBlockIdx;
  #endif

  LenReqResult = E_OK;

  /* Report DET error if the module is uninitialized */
  #if (FEE_DEV_ERROR_DETECT == STD_ON)
  if(Fee_GblInitStatus != FEE_INITIALIZED)
  {
    /* Report Error to DET */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_SID,
      FEE_E_UNINIT);
    /* Set return value LenReqResult to E_NOT_OK */
    LenReqResult = E_NOT_OK;
  }
  /*
   * Retrieve the index of the parameter BlockNumber from the array
   * "Fee_GstBlockConfiguration"
   */
  LusBlockIdx = Fee_BlockCfgLookUp(BlockNumber);
  /*
   * Report invalid block number DET error if the block number is not configured
   */
  if(LusBlockIdx == FEE_INVALID_BLOCK_IDX)
  {
    /* Report Error to DET */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_SID,
      FEE_E_INVALID_BLOCK_NO);
    /* Set return value LenReqResult to E_NOT_OK */
    LenReqResult = E_NOT_OK;
  }
  else
  {
    /* Get the pointer to Block Configuration array */
    LpBlockConfig = &Fee_GstBlockConfiguration[LusBlockIdx];
    /*
     * Report invalid block length DET error if the block length is
     * not correct
     */
    if((BlockOffset + Length) > LpBlockConfig->usFeeBlockSize)
    {
      /* Report Error to DET */
      Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_SID,
                                                 FEE_E_INVALID_BLOCK_LEN);
      /* Set return value LenReqResult to E_NOT_OK */
      LenReqResult = E_NOT_OK;
    }
  }
  /* Check return value LenReqResult is E_OK */
  if(LenReqResult == E_OK)
  #endif
  {
    #if (FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
    SchM_Enter_Fee(FEE_STATUS_PROTECTION);
    #endif
    /* Check if no request is in progress */
    if(Fee_GstVar.GucState == FEE_IDLE)
    {
      LpStRequest = &Fee_GstVar.GstRequest;
      /* Setup the calling structure for invoking read function of EEL */
      LpStRequest->address_pu08 = DataBufferPtr;
      LpStRequest->identifier_u16 = BlockNumber;
      LpStRequest->length_u16 = Length;
      LpStRequest->offset_u16 = BlockOffset;
      LpStRequest->command_enu = EEL_CMD_READ;
      /* Invoke EEL_Execute function with request structure */
      EEL_Execute(LpStRequest);

      /* Check if the current request is accepted by EEL */
      if(LpStRequest->status_enu == EEL_BUSY)
      {
        /* Set return value LenReqResult is E_OK */
        LenReqResult = E_OK;
        /* Update the result to job pending */
        Fee_GstVar.GenJobResult = MEMIF_JOB_PENDING;
        /* Set current state GucState is FEE_BUSY_FLASH_OPERATION */
        Fee_GstVar.GucState = FEE_BUSY_FLASH_OPERATION;
      }
      else
      {
        /* Set return value LenReqResult is E_NOT_OK */
        LenReqResult = E_NOT_OK;
      }
    }
    /* Check if the current operation during cancel request is in progress */
    else if(Fee_GstVar.GucState == FEE_JOB_CANCELLED)
    {
      /*
       * Set the state to indicate that a read/write/invalidate request is
       * accepted when the current operation is in progress while processing
       * cancel request
       */
      Fee_GstVar.GucPreviousJobState = FEE_JOB_INPROG;
      /*
       * Store the calling structure for processing request after
       * cancel completion
       */
      LpStRequest = &Fee_GstVar.GstNewReq;
      LpStRequest->address_pu08 = DataBufferPtr;
      LpStRequest->length_u16 = Length;
      LpStRequest->offset_u16 = BlockOffset;
      LpStRequest->command_enu = EEL_CMD_READ;
      LpStRequest->identifier_u16 = BlockNumber;

      /* Update the result to job pending */
      Fee_GstVar.GenJobResult = MEMIF_JOB_PENDING;
    }
    else
    {
      /* Set return value LenReqResult is E_NOT_OK */
      LenReqResult = E_NOT_OK;
    }
    #if (FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
    SchM_Exit_Fee(FEE_STATUS_PROTECTION);
    #endif

  } /* End of else part of if (LenReqResult == E_OK) */

  return(LenReqResult);
}

#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Fee_Write
**
** Service ID         : 0x03
**
** Description        : Service for calling the write function of the underlying
**                      driver
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : BlockNumber, DataBufferPtr
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : LenReqResult
**
** Preconditions      : FEE software component should be initialized
**
** Remarks            : Global Variable(s):
**                      Fee_GblInitStatus, Fee_GstBlockConfiguration,
**                      Fee_GstVar
**
**                      Function(s) invoked:
**                      Det_ReportError, Fee_BlockCfgLookUp, EEL_Execute
**                      SchM_Enter_Fee, SchM_Exit_Fee
**
*******************************************************************************/
#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC (Std_ReturnType, FEE_PUBLIC_CODE) Fee_Write(
uint16 BlockNumber, P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA)DataBufferPtr)
{
  P2CONST(Tdd_Fee_BlockConfigType, AUTOMATIC, FEE_PRIVATE_CONST)LpBlockConfig;
  P2VAR(eel_request_t, AUTOMATIC, FEE_PRIVATE_DATA)LpStRequest;

  uint16 LusBlockIdx;
  Std_ReturnType LenReqResult;
  boolean LblImmData;

  LenReqResult = E_OK;
  /*
   * Retrieve the index of the parameter BlockNumber from the array
   * "Fee_GstBlockConfiguration"
   */
  LusBlockIdx = Fee_BlockCfgLookUp(BlockNumber);

  /* Report DET error if the module is uninitialized */
  #if (FEE_DEV_ERROR_DETECT == STD_ON)
  if(Fee_GblInitStatus != FEE_INITIALIZED)
  {
    /* Report Error to DET */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_SID,
      FEE_E_UNINIT);
    /* Set return value LenReqResult to E_NOT_OK */
    LenReqResult = E_NOT_OK;
  }
  /*
   * Report invalid block number DET error if the block number is not configured
   */
  if(LusBlockIdx == FEE_INVALID_BLOCK_IDX)
  {
    /* Report Error to DET */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_SID,
      FEE_E_INVALID_BLOCK_NO);
    /* Set return value LenReqResult to E_NOT_OK */
    LenReqResult = E_NOT_OK;
  }
  /* Check return value LenReqResult is E_OK */
  if(LenReqResult == E_OK)
  #endif
  {
    /* Get the pointer to Block Configuration array */
    LpBlockConfig = &Fee_GstBlockConfiguration[LusBlockIdx];

    #if (FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
    SchM_Enter_Fee(FEE_STATUS_PROTECTION);
    #endif
    /* Check if no request is in progress */
    if(Fee_GstVar.GucState == FEE_IDLE)
    {

      LpStRequest = &Fee_GstVar.GstRequest;

      /* Setup the calling structure for invoking write function of EEL */
      LblImmData = LpBlockConfig->blFeeImmediateData;
      LpStRequest->address_pu08 = DataBufferPtr;
      LpStRequest->length_u16 = LpBlockConfig->usFeeBlockSize;
      LpStRequest->identifier_u16 = BlockNumber;
      LpStRequest->offset_u16 = FEE_ZERO;

      /* Check immediate data is FEE_TRUE */
      if(LblImmData == FEE_TRUE)
      {
        /* Setup the calling structure for invoking write function of EEL */
        LpStRequest->command_enu = EEL_CMD_WRITE_IMM;
      }
      else
      {
        /* Setup the calling structure for invoking write function of EEL */
        LpStRequest->command_enu = EEL_CMD_WRITE;
      }
      /* Invoke EEL_Execute function with request structure */
      EEL_Execute(LpStRequest);

      /* Check if the current request is accepted by EEL */
      if (LpStRequest->status_enu == EEL_BUSY)
      {
        /* Set return value LenReqResult is E_OK */
        LenReqResult = E_OK;
        /* Update the result to job pending */
        Fee_GstVar.GenJobResult = MEMIF_JOB_PENDING;
        /* Set current state GucState is FEE_BUSY_FLASH_OPERATION */
        Fee_GstVar.GucState = FEE_BUSY_FLASH_OPERATION;
      }
      else
      {
        /* Set return value LenReqResult is E_NOT_OK */
        LenReqResult = E_NOT_OK;
      }
    }
    /* Check if the current operation during cancel request is in progress */
    else if(Fee_GstVar.GucState == FEE_JOB_CANCELLED)
    {
      /* Update the block type based on the configured block type */
      LblImmData = LpBlockConfig->blFeeImmediateData;
      /* Set new request to current request */
      LpStRequest = &Fee_GstVar.GstNewReq;
      /*
       * Store the calling structure for processing request after
       * cancel completion
       */
      LpStRequest->address_pu08 = DataBufferPtr;
      LpStRequest->length_u16 = LpBlockConfig->usFeeBlockSize;
      LpStRequest->offset_u16 = FEE_ZERO;
      LpStRequest->identifier_u16 = BlockNumber;
      /* Check immediate data is FEE_TRUE */
      if(LblImmData == FEE_TRUE)
      {
        /* Setup the calling structure for invoking write function of EEL */
        LpStRequest->command_enu = EEL_CMD_WRITE_IMM;
      }
      else
      {
        /* Setup the calling structure for invoking write function of EEL */
        LpStRequest->command_enu = EEL_CMD_WRITE;
      }

      /*
       * Set the state to indicate that a read/write/invalidate request is
       * accepted when the current operation is in progress while processing
       * cancel request
       */
      Fee_GstVar.GucPreviousJobState = FEE_JOB_INPROG;

      /* Update the result to job pending */
      Fee_GstVar.GenJobResult = MEMIF_JOB_PENDING;
    }
    else
    {
      /* Set return value LenReqResult is E_NOT_OK */
      LenReqResult = E_NOT_OK;
    }
    #if (FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
    SchM_Exit_Fee(FEE_STATUS_PROTECTION);
    #endif
    
  } /* End of else part of if (LenReqResult == E_OK) */

  return(LenReqResult);
}

#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Fee_Cancel
**
** Service ID         : 0x04
**
** Description        : Service for canceling the current request that is being
**                      processed.
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : FEE software component should be initialized
**
** Remarks            : Global Variable(s):
**                      Fee_GstVar, Fee_GblInitStatus
**
**                      Function(s) invoked:
**                      Det_ReportError, SchM_Enter_Fee, SchM_Exit_Fee
**
*******************************************************************************/
#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, FEE_PUBLIC_CODE) Fee_Cancel(void)
{
  /* Report DET error if the module is uninitialized */
  #if (FEE_DEV_ERROR_DETECT == STD_ON)
  if (Fee_GblInitStatus != FEE_INITIALIZED)
  {
    /* Report Error to DET */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_SID,
      FEE_E_UNINIT);
  }
  else
  #endif
  {
    /* Check if any request is in progress */
    if(Fee_GstVar.GucState != FEE_IDLE)
    {
      #if (FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
      SchM_Enter_Fee(FEE_STATUS_PROTECTION);
      #endif

      /* Set the state to FEE_JOB_CANCELLED */
      Fee_GstVar.GucState = FEE_JOB_CANCELLED;

      #if (FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
      SchM_Exit_Fee(FEE_STATUS_PROTECTION);
      #endif

      /* Set job result to MEMIF_JOB_CANCELLED */
      Fee_GstVar.GenJobResult = MEMIF_JOB_CANCELLED;
    }
  }
}

#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Fee_GetStatus
**
** Service ID         : 0x05
**
** Description        : Service for reading the status of FEE software component
**                      or EEL.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : LenStatus
**
** Preconditions      : FEE software component should be initialized
**
** Remarks            : Global Variable(s):
**                      Fee_GstVar, Fee_GblInitStatus
**
**                      Function(s) invoked:
**                      Det_ReportError, EEL_GetDriverStatus
**
******************************************************************************/
#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(MemIf_StatusType, FEE_PUBLIC_CODE) Fee_GetStatus(void)
{

  MemIf_StatusType LenStatus;
  eel_driver_status_t driverStatus_str;
  /* Initialize the status as busy internal */
  LenStatus = MEMIF_BUSY_INTERNAL;
  /* Report DET error if the module is uninitialized */
  #if (FEE_DEV_ERROR_DETECT == STD_ON)
  if (Fee_GblInitStatus != FEE_INITIALIZED)
  {
    /* Report Error to DET */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETSTATUS_SID,
                                                        FEE_E_UNINIT);
    /* Set status to MEMIF_UNINIT */
    LenStatus = MEMIF_UNINIT;
  }
  else
  #endif
  {
    /* Invoke EEL_GetDriverStatus function to get driver status */
    (void)EEL_GetDriverStatus(&driverStatus_str);

    /*
     * To report idle status, check if the EEL Driver is idle
     * (or passive after error) and Fee itself is idle
     */
    if(((driverStatus_str.operationStatus_enu == EEL_OPERATION_IDLE) || 
        (driverStatus_str.operationStatus_enu == EEL_OPERATION_PASSIVE)) &&
        (Fee_GstVar.GucState == FEE_IDLE))
    {
      /* Set status to MEMIF_IDLE */
      LenStatus = MEMIF_IDLE;     
    }
    /* Check if Fee is busy */
    else if(Fee_GstVar.GucState != FEE_IDLE)
    {
      /* 
       * Check the Fee state to report the status as Idle when the driver is  
       * busy due to ongoing request during cancel processing
       */
      if(Fee_GstVar.GucState == FEE_JOB_CANCELLED)
      {
        /* Set status to MEMIF_IDLE */
        LenStatus = MEMIF_IDLE;
      }
      else
      {
        /* Set status to MEMIF_BUSY */
        LenStatus = MEMIF_BUSY;
      }
    }
    else
    {
      /* To avoid MISRA warnings */
    }
  }
  return(LenStatus);
}

#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Fee_GetJobResult
**
** Service ID         : 0x06
**
** Description        : Service for reading the job result of current request
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : LenJobResult
**
** Preconditions      : FEE software component should be initialized
**
** Remarks            : Global Variable(s):
**                      Fee_GstVar, Fee_GblInitStatus
**
**                      Function(s) invoked:
**                      Det_ReportError
**
******************************************************************************/
#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(MemIf_JobResultType, FEE_PUBLIC_CODE) Fee_GetJobResult(void)
{
  MemIf_JobResultType LenJobResult;

 /* Report DET error if the module is uninitialized */
  #if (FEE_DEV_ERROR_DETECT == STD_ON)
  if (Fee_GblInitStatus != FEE_INITIALIZED)
  {
    /* Report Error to DET */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETJOBRESULT_SID,
      FEE_E_UNINIT);
    /* Set job result to MEMIF_JOB_FAILED */
    LenJobResult = MEMIF_JOB_FAILED;
  }
  else
  #endif
  {
    /* Return the current job result */
    LenJobResult = Fee_GstVar.GenJobResult;
  }

  return(LenJobResult);
}

#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Fee_InvalidateBlock
**
** Service ID         : 0x07
**
** Description        : Service for invalidating the configured block
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : BlockNumber
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : LenReqResult
**
** Preconditions      : FEE software component should be initialized
**
** Remarks            : Global Variable(s):
**                      Fee_GblInitStatus, Fee_GstVar, Fee_GstBlockConfiguration
**
**                      Function(s) invoked:
**                      Det_ReportError, Fee_BlockCfgLookUp, EEL_Execute,
**                      SchM_Enter_Fee, SchM_Exit_Fee
**
*******************************************************************************/
#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, FEE_PUBLIC_CODE) Fee_InvalidateBlock (uint16 BlockNumber)
{
  P2CONST(Tdd_Fee_BlockConfigType, AUTOMATIC, FEE_PRIVATE_CONST)LpBlockConfig;
  P2VAR(eel_request_t, AUTOMATIC, FEE_PRIVATE_DATA)LpStRequest;
  Std_ReturnType LenReqResult;
  uint16 LusBlockIdx;
  boolean LblImmData;

  LenReqResult = E_OK;
  /*
   * Retrieve the index of the parameter BlockNumber from the array
   * "Fee_GstBlockConfiguration"
   */
  LusBlockIdx = Fee_BlockCfgLookUp(BlockNumber);

  /* Report DET error if the module is uninitialized */
  #if (FEE_DEV_ERROR_DETECT == STD_ON)
  if(Fee_GblInitStatus != FEE_INITIALIZED)
  {
    /* Report Error to DET */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_SID,
      FEE_E_UNINIT);
    /* Set return value LenReqResult to E_NOT_OK */
    LenReqResult = E_NOT_OK;
  }
  /*
   * Report invalid block number DET error if the block number is not configured
   */
  if(LusBlockIdx == FEE_INVALID_BLOCK_IDX)
  {
    /* Report Error to DET */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_SID,
      FEE_E_INVALID_BLOCK_NO);
    /* Set return value LenReqResult to E_NOT_OK */
    LenReqResult = E_NOT_OK;
  }
  /* Check return value LenReqResult is E_OK */
  if(LenReqResult == E_OK)
  #endif
  {
    /* Get the pointer to Block Configuration array */
    LpBlockConfig = &Fee_GstBlockConfiguration[LusBlockIdx];

    #if (FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
    SchM_Enter_Fee(FEE_STATUS_PROTECTION);
    #endif
    /* Check if no request is in progress */
    if(Fee_GstVar.GucState == FEE_IDLE)
    {
      /* Update the block type based on the configured block type */
      LblImmData = LpBlockConfig->blFeeImmediateData;
      LpStRequest = &Fee_GstVar.GstRequest;
      /* Setup calling structure for invoking invalidate function of EEL */
      LpStRequest->identifier_u16 = BlockNumber;

      /* Check immediate data is FEE_TRUE */
      if(LblImmData == FEE_TRUE)
      {
        /* Setup calling structure for invoking invalidate function of EEL */
        LpStRequest->command_enu = EEL_CMD_INVALIDATE_IMM;
      }
      else
      {
        /* Setup calling structure for invoking invalidate function of EEL */
        LpStRequest->command_enu = EEL_CMD_INVALIDATE;
      }
      /* Invoke EEL_Execute function with request structure */
      EEL_Execute(LpStRequest);

      /* Check if the current request is accepted by EEL */
      if (LpStRequest->status_enu == EEL_BUSY)
      {
        /* Update return value LenReqResult to E_OK */
        LenReqResult = E_OK;
        /* Update the result to job pending */
        Fee_GstVar.GenJobResult = MEMIF_JOB_PENDING;
        /* Set current state GucState is FEE_BUSY_FLASH_OPERATION */
        Fee_GstVar.GucState = FEE_BUSY_FLASH_OPERATION;
      }
      else
      {
        /* Set return value LenReqResult is E_NOT_OK */
        LenReqResult = E_NOT_OK;
      }
    }
    /* Check if the current operation during cancel request is in progress */
    else if(Fee_GstVar.GucState == FEE_JOB_CANCELLED)
    {
      /* Update the block type based on the configured block type */
      LblImmData = LpBlockConfig->blFeeImmediateData;
      /* Set the new request to current request */
      LpStRequest = &Fee_GstVar.GstNewReq;
      /*
       * Store the calling structure for processing request after
       * cancel completion
       */
      LpStRequest->identifier_u16 = BlockNumber;

      /* Check immediate data is FEE_TRUE */
      if(LblImmData == FEE_TRUE)
      {
        /*
         * Setup the calling structure for invoking invalidate function
         * of EEL
         */
        LpStRequest->command_enu = EEL_CMD_INVALIDATE_IMM;
      }
      else
      {
        /*
         * Setup the calling structure for invoking invalidate function
         * of EEL
         */
        LpStRequest->command_enu = EEL_CMD_INVALIDATE;
      }

      /*
       * Set the state to indicate that a read/write/invalidate request is
       * accepted when the current operation is in progress while processing
       * cancel request
       */
      Fee_GstVar.GucPreviousJobState = FEE_JOB_INPROG;

      /* Update job result to MEMIF_JOB_PENDING */
      Fee_GstVar.GenJobResult = MEMIF_JOB_PENDING;
    }
    else
    {
      /* Set return value LenReqResult is E_NOT_OK */
      LenReqResult = E_NOT_OK;
    }
    #if (FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
    SchM_Exit_Fee(FEE_STATUS_PROTECTION);
    #endif
  }
  return(LenReqResult);
}

#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Fee_GetVersionInfo
**
** Service ID         : 0x08
**
** Description        : This API reads the version information of FEE software
**                      component.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : VersionInfoPtr
**
** Return parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable(s):
**                      None
**
**                      Function(s) invoked:
**                      Det_ReportError
**
*******************************************************************************/
#if (FEE_VERSION_INFO_API == STD_ON)

#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, FEE_PUBLIC_CODE)Fee_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA)VersionInfoPtr)
{
  #if (FEE_DEV_ERROR_DETECT == STD_ON)
  /* Check if parameter passed is equal to Null pointer */
  if(VersionInfoPtr == NULL_PTR)
  {
    /* Report error to DET  */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GET_VERSION_INFO_SID,
      FEE_E_PARAM_POINTER);
  }
  else
  #endif /* (FEE_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    VersionInfoPtr->vendorID = FEE_VENDOR_ID;
    /* Copy the module Id */
    VersionInfoPtr->moduleID = FEE_MODULE_ID;
    /* Copy the instance Id */
    VersionInfoPtr->instanceID = FEE_INSTANCE_ID;
    /* Copy Software Major Version */
    VersionInfoPtr->sw_major_version = FEE_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    VersionInfoPtr->sw_minor_version = FEE_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    VersionInfoPtr->sw_patch_version = FEE_SW_PATCH_VERSION;
  }
}
#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (FEE_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
** Function Name      : Fee_EraseImmediateBlock
**
** Service ID         : 0x09
**
** Description        : Service for erasing block. This API will not provide any
**                      functionality to the user. It returns E_OK and updates
**                      the job result as MEMIF_JOB_OK asynchronously
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : BlockNumber
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : LenReqResult
**
** Preconditions      : FEE software component should be initialized
**
** Remarks            : Global Variable(s):
**                      Fee_GblInitStatus, Fee_GstVar
**
**                      Function(s) invoked:
**                      Det_ReportError, Fee_BlockCfgLookUp,
**                      pFee_JobEndNotification
**
*******************************************************************************/
#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, FEE_PUBLIC_CODE) Fee_EraseImmediateBlock
  (uint16 BlockNumber)
{
  Std_ReturnType LenReqResult;
  #if (FEE_DEV_ERROR_DETECT == STD_ON)  
  uint16 LusBlockIdx;
  #endif
  /* Checks if callback is configured and invokes the callback function */
  #if (FEE_UPPER_LAYER_NOTIFICATION == STD_ON)
  /* Pointer to function pointer structure */
  P2CONST(Tdd_Fee_FuncType, AUTOMATIC, FEE_PRIVATE_CONST) LpFuncNotification;
  /* Initialize the notification function pointer */
  LpFuncNotification = &Fee_GstFunctionNotification;
  #endif

  LenReqResult = E_OK;

  /* Report DET error if the module is uninitialized */
  #if (FEE_DEV_ERROR_DETECT == STD_ON)
  if (Fee_GblInitStatus != FEE_INITIALIZED)
  {
    /* Report error to DET  */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_SID,
      FEE_E_UNINIT);
    /* Set return value LenReqResult to E_NOT_OK */
    LenReqResult = E_NOT_OK;
  }
  /*
   * Retrieve the index of the parameter BlockNumber from the array
   * "Fee_GstBlockConfiguration"
   */
  LusBlockIdx = Fee_BlockCfgLookUp(BlockNumber);
  /*
   * Report invalid block number DET error if the block number is not configured
   */
  if(LusBlockIdx == FEE_INVALID_BLOCK_IDX)
  {
    /* Report error to DET  */
    Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_SID,
      FEE_E_INVALID_BLOCK_NO);
    /* Set return value LenReqResult to E_NOT_OK */
    LenReqResult = E_NOT_OK;
  }
  /* Check LenReqResult is E_OK */
  if(LenReqResult == E_OK)
  #endif
  {
    if((Fee_GstVar.GucState != FEE_IDLE) &&
       (Fee_GstVar.GucState != FEE_JOB_CANCELLED))
    {
      /* Set return value LenReqResult to E_NOT_OK */
      LenReqResult = E_NOT_OK;
    }
    #if (FEE_UPPER_LAYER_NOTIFICATION == STD_ON)
    /* Check current state is FEE_IDLE or FEE_JOB_CANCELLED */
    else
    {
      /*
       * Notify the upper layer for completion of Erase request if Notification
       * for the upper layer is configured. Erase request is accepted only
       * when no request is in progress
       */
      /* Invoke the successful callback notification */
      LpFuncNotification->pFee_JobEndNotification();
    }
    #endif
  }
  return(LenReqResult);
}

#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Fee_MainFunction
**
** Service ID         : 0x12
**
** Description        : This scheduler function will asynchronously handle the
**                      requested jobs and the internal management operations
**
** Sync/Async         : NA
**
** Re-entrancy        : NA
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable(s):
**                      Fee_GstVar
**
**                      Function(s) invoked:
**                      EEL_Init, EEL_Startup, EEL_Handler, EEL_Execute, 
**                      Fee_EndProcessBlock, EEL_GetDriverStatus,
**                      SchM_Enter_Fee, SchM_Exit_Fee, Dem_ReportErrorStatus
**
*******************************************************************************/
#define FEE_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, FEE_PUBLIC_CODE) Fee_MainFunction(void)
{
  boolean LblEndProcess;
  eel_status_t LenStatus;

  #if(FEE_STARTUP_INTERNAL == STD_OFF)
  eel_status_t LenEelStatus;
  eel_driver_status_t driverStatus_str;
  #endif

  /* Set end process flag to FEE_FALSE */
  LblEndProcess = FEE_FALSE;

  /* Invoke the Handler function */
  EEL_Handler();

  #if(FEE_STARTUP_INTERNAL == STD_OFF)
  /* Check current state is FEE_STARTUP */
  if(Fee_GstVar.GucState == FEE_STARTUP)
  {
    /* Invoke EEL_GetDriverStatus function to get driver status */
    (void)EEL_GetDriverStatus(&driverStatus_str);

    #if (FEE_STARTUP_LIMITED_ACCESS == STD_OFF)
    /* Wait until the system is completely up and running (or error) */
    if(driverStatus_str.accessStatus_enu == EEL_ACCESS_UNLOCKED)
    {
      /* Set current state to FEE_IDLE */
      Fee_GstVar.GucState = FEE_IDLE;
    }
    #else /* else part of (FEE_STARTUP_LIMITED_ACCESS == STD_OFF) */
    /* Wait until early read/write is possible (or error) */
    if(driverStatus_str.accessStatus_enu == EEL_ACCESS_READ_WRITE)
    {
      /* Set current state to FEE_IDLE */
      Fee_GstVar.GucState = FEE_IDLE;
    }
    #endif/* End of (FEE_STARTUP_LIMITED_ACCESS == STD_OFF) */

    #if (FEE_AUTO_FORMAT_FLASH == STD_ON)
    /* Check backround status is EEL_ERR_POOL_INCONSISTENT */
    if(driverStatus_str.backgroundStatus_enu == EEL_ERR_POOL_INCONSISTENT)
    {
      /* Setup the calling structure for invoking format function of EEL */
      Fee_GstVar.GstRequest.command_enu = EEL_CMD_FORMAT;
      /* Set job result to MEMIF_BLOCK_INCONSISTENT */
      Fee_GstVar.GenJobResult = MEMIF_BLOCK_INCONSISTENT;

      /* 
       * Invoke the Handler function to proceed EEL state for format
       * acceptance
       */ 
      EEL_Handler();
      /* Invoke the API to perform the operation based on updated command */
      EEL_Execute(&Fee_GstVar.GstRequest);
      /* Check request status is EEL_BUSY */
      if(Fee_GstVar.GstRequest.status_enu == EEL_BUSY)
      {
        /* Update current state to FEE_FORMAT */
        Fee_GstVar.GucState = FEE_FORMAT;
      }
      /* Check request status is EEL_OK */
      else if(Fee_GstVar.GstRequest.status_enu == EEL_OK)
      {
        /* Invoke the initialization function of EEL */
        LenEelStatus = EEL_Init(&eelApp_eelConfig, EEL_OPERATION_MODE_NORMAL);
        /* Check LenEelStatus is EEL_OK */
        if(LenEelStatus == EEL_OK)
        {
          /* Invoke the startup function of EEL */
          LenEelStatus = EEL_Startup();
          /* Check LenEelStatus is EEL_OK */
          if(LenEelStatus == EEL_OK)
          {
            /* Update current state to FEE_STARTUP */
            Fee_GstVar.GucState = FEE_STARTUP;
          }
        }
      }
      else
      {
        /* Update current state to FEE_UNINIT */
        Fee_GstVar.GucState = FEE_UNINIT;

        /* Report failure of format request to DEM */
        //Dem_ReportErrorStatus((Dem_EventIdType)FEE_FORMAT_FAILED,
        //(Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);
      }
    }
    #endif /* End of (FEE_AUTO_FORMAT_FLASH == STD_ON) */
    /* Check operation status is EEL_OPERATION_PASSIVE */
    if(driverStatus_str.operationStatus_enu == EEL_OPERATION_PASSIVE)
    {
      /* Report failure of startup to DEM */
      //Dem_ReportErrorStatus((Dem_EventIdType)FEE_E_STARTUP_FAILED,
      //  (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);

    }
  }
  #if (FEE_AUTO_FORMAT_FLASH == STD_ON)
  /* Check current state is FEE_FORMAT */
  else if(Fee_GstVar.GucState == FEE_FORMAT)
  {
    /* Check request status is not EEL_BUSY */
    if(Fee_GstVar.GstRequest.status_enu != EEL_BUSY)
    {
      /* Check request status is EEL_OK */
      if(Fee_GstVar.GstRequest.status_enu == EEL_OK)
      {
        /* Invoke the initialization function of EEL */
        LenEelStatus = EEL_Init(&eelApp_eelConfig, EEL_OPERATION_MODE_NORMAL);
        /* Check LenEelStatus is EEL_OK*/
        if(LenEelStatus == EEL_OK)
        {
          /* Invoke the startup function of EEL */
          LenEelStatus = EEL_Startup();
          /* Check LenEelStatus is EEL_OK*/
          if(LenEelStatus == EEL_OK)
          {
            /* Update current state to FEE_STARTUP */
            Fee_GstVar.GucState = FEE_STARTUP;
          }
        }
      }
      else
      {
        /* Update current state to FEE_UNINIT */
        Fee_GstVar.GucState = FEE_UNINIT;

        /* Report failure of format request to DEM */
        //Dem_ReportErrorStatus((Dem_EventIdType)FEE_FORMAT_FAILED,
        //(Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);

      }
    } /* End of (Fee_GstVar.GstRequest.status_enu != EEL_BUSY) */
  }
  #endif /* End of (FEE_AUTO_FORMAT_FLASH == STD_ON) */
  else
  #endif /* End of (FEE_STARTUP_INTERNAL == STD_OFF) */
  {
    /* Check if the current request issued to EEL is complete */
    if(Fee_GstVar.GstRequest.status_enu != EEL_BUSY)
    {
      /* Check if the ongoing job before the cancel request is processed */
      if(Fee_GstVar.GucPreviousJobState == FEE_JOB_INPROG)
      {
        /*
         * Process the operation (read/write/invalidate) requested when the
         * cancel processing was happening in background
         */
        Fee_GstVar.GstRequest = Fee_GstVar.GstNewReq;

        /*
         * Invoke the function to perform pending read/write/invalidate
         * operation
         */

        /* Invoke the API to perform the operation based on updated command */
        EEL_Execute(&Fee_GstVar.GstRequest);

        /* Check if the request is accepted by EEL */
        if (Fee_GstVar.GstRequest.status_enu == EEL_BUSY)
        {
          #if (FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
            SchM_Enter_Fee(FEE_STATUS_PROTECTION);
          #endif
          /* Update current state to FEE_BUSY_FLASH_OPERATION */
          Fee_GstVar.GucState = FEE_BUSY_FLASH_OPERATION;

          #if (FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
            SchM_Exit_Fee(FEE_STATUS_PROTECTION);
          #endif
        }
        else
        {
          /* Update the request status */
          LenStatus = Fee_GstVar.GstRequest.status_enu;
          /* Set LblEndProcess flag to FEE_TRUE */
          LblEndProcess = FEE_TRUE;
        }
        /* Update previous job state to FEE_JOB_COMPLETED */
        Fee_GstVar.GucPreviousJobState = FEE_JOB_COMPLETED;
      }
      /* Check current state is FEE_JOB_CANCELLED */
      else if(Fee_GstVar.GucState == FEE_JOB_CANCELLED)
      {
        /* Update current state  to FEE_IDLE */
        Fee_GstVar.GucState = FEE_IDLE;
      }
      /* Check current state is FEE_BUSY_FLASH_OPERATION */
      else if(Fee_GstVar.GucState == FEE_BUSY_FLASH_OPERATION)
      {
        /* Update the request status */
        LenStatus = Fee_GstVar.GstRequest.status_enu;
        /* Set LblEndProcess flag to FEE_TRUE */
        LblEndProcess = FEE_TRUE;
      }
      else
      {
        /* Loop added to avoid QAC warning */
      }
    } /* End of if (GstRequest.status_enu != EEL_BUSY) */
  } /* End of else part of (Fee_GstVar.GucState == FEE_STARTUP) */

  /* Check LblEndProcess is not FEE_FALSE */
  if (LblEndProcess != FEE_FALSE)
  {
    /*
     * Update the result to be returned to upper layer based on result
     * returned by the EEL
     */

    /* MISRA Rule   : 9.1                                              */
    /* Message      : The variable '-identifier-' is possibly unset    */
    /*                at this point.                                   */
    /* Reason       : 'LenStatus' is updated whenever the status_enu   */
    /*                is updated by the EEL_Handler function.          */
    /* Verification : However, the part of the code is verified        */
    /*                manually and it is not having any impact on code.*/
    switch(LenStatus)
    {
      case EEL_OK:
      case EEL_ERR_BLOCK_EXCLUDED:
      case EEL_ERR_FIX_DONE:
      case EEL_ERR_ERASESUSPEND_OVERFLOW:
        /* Set job result to MEMIF_JOB_OK */
        Fee_GstVar.GenJobResult = MEMIF_JOB_OK;
      break;
      case EEL_ERR_NO_INSTANCE:
        /* 
         * Set job result to MEMIF_BLOCK_INVALID, either no DS corresponding
         * to the ID could be found or the data has been invalidated explicitely
         */
        Fee_GstVar.GenJobResult = MEMIF_BLOCK_INVALID;
      break;

      default:
        /* Set job result to MEMIF_JOB_FAILED */
        Fee_GstVar.GenJobResult = MEMIF_JOB_FAILED;
      break;

    } /* end of switch (LenStatus) */

    /* End the processing of the current request */
    Fee_EndProcessBlock(Fee_GstVar.GenJobResult);
  } /* End of (LblEndProcess != FEE_FALSE)*/
} /* End of Main function */

#define FEE_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
