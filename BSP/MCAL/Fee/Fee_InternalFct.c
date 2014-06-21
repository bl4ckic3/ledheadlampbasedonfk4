/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Fee_InternalFct.c                                           */
/* Version      = 3.0.6a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains internal function definitions of FEE Component          */
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
 * V3.0.1:  20-Jan-2010  : As per SCR 184, following changes are made:
 *                         1. In the function 'Fee_EndProcessBlock', check for
 *                         the Format request to invoke DEM error is removed.
 *                         2. A comment is provided to the '#endif' of the
 *                         function 'Fee_BlockCfgLookUp'.
 * V3.0.2:  12-Mar-2010  : As per SCR 223, function Fee_BlockCfgLookUp is
 *                         updated for binary search.
 * V3.0.3:  01-Apr-2010  : As per SCR 234, following changes are made:
 *                         1. The function Fee_BlockCfgLookUp is
 *                         updated with type of return parameter LusBlkFoundIdx 
 *                         as uint16 for retrieving the index of configured
 *                         FeeBlockNumber in array Fee_GstBlockConfiguration.
 *                         2. The precompile option FEE_DEV_ERROR_DETECT for the
 *                          function Fee_BlockCfgLookUp is removed.
 * V3.0.4:  24-Jun-2010  : As per SCR 287, comments are updated.
 * V3.0.5:  03-Jan-2011  : As per SCR 394, updated function 
 *                         Fee_EndProcessBlock() to change the state of FEE
 *                         before job notification.
 * V3.0.6:  17-Jun-2011  : As per SCR 472, Function Fee_EndProcessBlock() 
 *                         is updated to change the DEM error name
 *                         from FLS_E_READ_FAILED to FEE_E_READ_FAILED and 
 *                         FLS_E_WRITE_FAILED to FEE_E_WRITE_FAILED.
 * V3.0.6a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fee.h"
#include "EEL.h"
#include "Fee_InternalFct.h"
#include "Fee_Types.h"
#include "Fee_Ram.h"
//#include "Dem.h"
#if(FEE_CRITICAL_SECTION_PROTECTION == STD_ON)
//#include "SchM_Fee.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define FEE_INTERNALFCT_C_AR_MAJOR_VERSION    FEE_AR_MAJOR_VERSION_VALUE
#define FEE_INTERNALFCT_C_AR_MINOR_VERSION    FEE_AR_MINOR_VERSION_VALUE
#define FEE_INTERNALFCT_C_AR_PATCH_VERSION    FEE_AR_PATCH_VERSION_VALUE

/* File version information */
#define FEE_INTERNALFCT_C_SW_MAJOR_VERSION    3
#define FEE_INTERNALFCT_C_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (FEE_INTERNALFCT_AR_MAJOR_VERSION != FEE_INTERNALFCT_C_AR_MAJOR_VERSION)
  #error "Fee_InternalFct.c : Mismatch in Specification Major Version"
#endif

#if (FEE_INTERNALFCT_AR_MINOR_VERSION != FEE_INTERNALFCT_C_AR_MINOR_VERSION)
  #error "Fee_InternalFct.c : Mismatch in Specification Minor Version"
#endif

#if (FEE_INTERNALFCT_AR_PATCH_VERSION != FEE_INTERNALFCT_C_AR_PATCH_VERSION)
  #error "Fee_InternalFct.c : Mismatch in Specification Patch Version"
#endif

#if (FEE_INTERNALFCT_SW_MAJOR_VERSION != FEE_INTERNALFCT_C_SW_MAJOR_VERSION)
  #error "Fee_InternalFct.c : Mismatch in Major Version"
#endif

#if (FEE_INTERNALFCT_SW_MINOR_VERSION != FEE_INTERNALFCT_C_SW_MINOR_VERSION)
  #error "Fee_InternalFct.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Fee_EndProcessBlock
**
** Service ID         : NA
**
** Description        : Function to end the processing of any read, write and
**                      invalidate request
*
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : LenRequestResult
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : FEE software component should be initialised
**
** Remarks            : Global Variable(s):
**                      Fee_GstFunctionNotification, Fee_GstVar
**
**                      Function(s) invoked:
**                      pFee_JobEndNotification, pFee_JobErrorNotification,
**                      Dem_ReportErrorStatus
**
*******************************************************************************/
#define FEE_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, FEE_PRIVATE_CODE) Fee_EndProcessBlock(MemIf_JobResultType
  LenRequestResult)
{
  /* Checks if callback is configured and invokes the callback function */
  #if (FEE_UPPER_LAYER_NOTIFICATION == STD_ON)
  /* Pointer to function pointer structure */
  P2CONST(Tdd_Fee_FuncType, AUTOMATIC, FEE_PRIVATE_CONST) LpFuncNotification;

  /* Initialise the notification function pointer */
  LpFuncNotification = &Fee_GstFunctionNotification;
  #endif

  /* Update the state to idle and job result to passed result */
  Fee_GstVar.GenJobResult = LenRequestResult;
  Fee_GstVar.GucState = FEE_IDLE;

  #if (FEE_UPPER_LAYER_NOTIFICATION == STD_ON)
  /* Check LenRequestResult is MEMIF_JOB_OK */
  if (LenRequestResult == MEMIF_JOB_OK)
  {
    /* Invoke the successful callback notification */
    LpFuncNotification->pFee_JobEndNotification();
  }
  else
  #else
  if (LenRequestResult != MEMIF_JOB_OK)
  #endif
  {
    #if (FEE_UPPER_LAYER_NOTIFICATION == STD_ON)
    /* Invoke the unsuccessful callback notification */
    LpFuncNotification->pFee_JobErrorNotification();
    #endif

    /* Check request command is EEL_CMD_READ */
    if (Fee_GstVar.GstRequest.command_enu == EEL_CMD_READ)
    {
      /* Report failure of read job request to DEM */
      //Dem_ReportErrorStatus((Dem_EventIdType)FEE_E_READ_FAILED,
      //(Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);

    }
    /* Check request command is EEL_CMD_WRITE or EEL_CMD_WRITE_IMM */
    else if((Fee_GstVar.GstRequest.command_enu == EEL_CMD_WRITE) ||
             (Fee_GstVar.GstRequest.command_enu == EEL_CMD_WRITE_IMM))
    {
      /* Report failure of write job request to DEM */
      //Dem_ReportErrorStatus((Dem_EventIdType)FEE_E_WRITE_FAILED,
      //  (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* Added for QAC */
    }

  } /* End of else part of if (LenRequestResult == MEMIF_JOB_OK) */

} /* End of function body */

#define FEE_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Fee_BlockCfgLookUp
**
** Service ID         : NA
**
** Description        : Function to search the BlockNumber in BlockConfiguration
**                      array structure.
*
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : BlockNumber
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : LusBlkIndex
**
** Preconditions      : FEE software component should be initialised
**
** Remarks            : Global Variable(s):
**                      Fee_GstBlockConfiguration
**
**                      Function(s) invoked:
**                      None
**
*******************************************************************************/
#define FEE_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(uint16, FEE_PRIVATE_CODE) Fee_BlockCfgLookUp(uint16 BlockNumber)
{
  /* Update the pointer to first element of the structure array */
  P2CONST(Tdd_Fee_BlockConfigType, AUTOMATIC, FEE_PRIVATE_DATA)
    LpBlockConfig = &Fee_GstBlockConfiguration[FEE_ZERO];

  /* Initialize the bottom index to first element */
  uint16 LusBottomIdx = FEE_ONE;

  /* Initialize the top index to last element of structure array */
  uint16 LusTopIdx = FEE_NUM_BLOCKS - FEE_ONE;

  /*
   * Initialize the default value to 0xFFFF which is other than
   * blocks configured
   */
  uint16 LusBlkFoundIdx = FEE_INVALID_BLOCK_IDX;

  /* Point to the centre element in structure array */
  uint16 LusMidIdx;
  
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Check whether BlockNumber is in range */
  if((BlockNumber >= (LpBlockConfig->usFeeBlockNumber)) &&
     (BlockNumber <= ((LpBlockConfig + LusTopIdx)->usFeeBlockNumber)))
  {
    /* 
     * Check whether requested BlockNumber is not equal to first BlockNumber
     * of the list
     */
    if(BlockNumber != (LpBlockConfig->usFeeBlockNumber))
    {
      do
      {
        /* Get the middle index number */
        LusMidIdx = ((LusTopIdx + LusBottomIdx) >> FEE_ONE);
      
        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */
                                                          
        /* Compare BlockNumber with the requested one */
        if(((LpBlockConfig + LusMidIdx)->usFeeBlockNumber) == BlockNumber)
        {
          /* Update the block index found  */
          LusBlkFoundIdx = LusMidIdx;

          /* Set LusTopIdx to zero to break the loop */
          LusTopIdx = FEE_ZERO;
        }
        else
        {
          /* MISRA Rule         : 17.4                            */
          /* Message            : Performing pointer arithmetic.  */
          /* Reason             : For code optimization.          */
          /* Verification       : However, part of the code is    */
          /*                      verified manually and it is not */
          /*                      having any impact.              */
                                                          
          /* Compare the BlockNumber with the requested one */
          if(BlockNumber < ((LpBlockConfig + LusMidIdx)->usFeeBlockNumber))
          {
            /* MISRA Rule         : 21.1                                      */
            /* Message            : An integer expression with a value that   */
            /*                      apparently negative is being converted    */
            /*                      to an unsigned type.                      */
            /* Reason             : This is to update the local variable.     */
            /* Verification       : However, part of the code is verified     */
            /*                      manually and it is not having any impact. */

            /* If the priority is lower, update LusTopIdx */
            LusTopIdx = LusMidIdx - FEE_ONE;
          }
          else
          {
            /* If the priority is higher, update LusBottomIdx */
            LusBottomIdx = LusMidIdx + FEE_ONE;
          }
        }
      }while(LusBottomIdx <= LusTopIdx);
    }
    else
    {
      /* Update the block index found  */
      LusBlkFoundIdx = FEE_ZERO;
    }
  }
  /* Return block index if found, else return zero */
  return (LusBlkFoundIdx);
  
} /* End of function body */

#define FEE_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
