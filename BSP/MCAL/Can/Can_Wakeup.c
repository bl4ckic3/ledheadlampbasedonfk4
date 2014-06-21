/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_Wakeup.c                                                */
/* Version      = 3.0.1a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Wake-up occurrence.                                           */
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
 * V3.0.0:  12.12.2008  : Initial Version
 * V3.0.1:  21.10.2009  : Updated compiler version as per
 *                        SCR ANMCANLINFR3_SCR_031.
 *
 * V3.0.1a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can_PBTypes.h"      /* CAN Driver Post-Build Config. Header File */
#include "Can_Wakeup.h"       /* CAN Wakeup Header File */
#include "Can_Ram.h"          /* CAN Driver RAM Header File */
#include "Can_Tgt.h"          /* CAN Driver Target Header File */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"              /* DET Header File */
#endif
#include "SchM_Can.h"         /* Scheduler Header File */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_WAKEUP_C_AR_MAJOR_VERSION  2
#define CAN_WAKEUP_C_AR_MINOR_VERSION  2
#define CAN_WAKEUP_C_AR_PATCH_VERSION  2

/* File version information */
#define CAN_WAKEUP_C_SW_MAJOR_VERSION  3
#define CAN_WAKEUP_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CAN_WAKEUP_AR_MAJOR_VERSION != CAN_WAKEUP_C_AR_MAJOR_VERSION)
  #error "Can_Wakeup.c : Mismatch in Specification Major Version"
#endif
#if (CAN_WAKEUP_AR_MINOR_VERSION != CAN_WAKEUP_C_AR_MINOR_VERSION)
  #error "Can_Wakeup.c : Mismatch in Specification Minor Version"
#endif
#if (CAN_WAKEUP_AR_PATCH_VERSION != CAN_WAKEUP_C_AR_PATCH_VERSION)
  #error "Can_Wakeup.c : Mismatch in Specification Patch Version"
#endif
#if (CAN_WAKEUP_SW_MAJOR_VERSION != CAN_WAKEUP_C_SW_MAJOR_VERSION)
  #error "Can_Wakeup.c : Mismatch in Software Major Version"
#endif
#if (CAN_WAKEUP_SW_MINOR_VERSION != CAN_WAKEUP_C_SW_MINOR_VERSION)
  #error "Can_Wakeup.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Can_CheckWakeup
**
** Service ID         : 0x0b
**
** Description        : This service checks if a wakeup has occurred for the
**                      given controller.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : Controller
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK / E_NOT_OK)
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_GblCanStatus, Can_GucFirstHthId, Can_GucLastHthId,
**                      Can_GpFirstHth
**
**                    : Function(s) invoked:
**                      Det_ReportError()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType,CAN_AFCAN_PUBLIC_CODE) Can_CheckWakeup
                                                              (uint8 Controller)
{
  #if(CAN_WAKEUP_SUPPORT == STD_ON)
  P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                          CAN_AFCAN_PRIVATE_CONST) LpController;
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_PRIVATE_DATA) LpWakeuporEvent;
  #endif
  Std_ReturnType LenStdReturnType;

  /* Initialize StdReturnType to E_OK */
  LenStdReturnType = E_OK;
   #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (Can_GblCanStatus == CAN_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                           CAN_CHK_WAKEUP_SID, CAN_E_UNINIT);
    /* Set StdReturnType to E_NOT_OK */
    LenStdReturnType = E_NOT_OK;
  }
  /* Report to DET, if the Controller Id is out of range */
  else if(Controller > Can_GucLastCntrlId)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                CAN_CHK_WAKEUP_SID, CAN_E_PARAM_CONTROLLER);
    /* Set StdReturnType to E_NOT_OK */
    LenStdReturnType = E_NOT_OK;
  }
  else
  {
    /* Get the Controller index */
    Controller = Can_GpCntrlIdArray[Controller];
    /* Report to DET, if the Controller index is not present */
    if(Controller == CAN_LIMIT)
    {
      /* Report to DET */
      Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                 CAN_CHK_WAKEUP_SID, CAN_E_PARAM_CONTROLLER);
      /* Set StdReturnType to E_NOT_OK */
      LenStdReturnType = E_NOT_OK;
    }
  }
  /* Check whether any development error occurred */
  if(LenStdReturnType != E_NOT_OK)
  #endif /* #if (CAN_DEV_ERROR_DETECT == STD_ON) */
  {

    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    /*  MISRA Rule        :  17.4
        Message           :  Performing pointer arithmetic
        Reason            :  Increment operator not used to achieve better
                             throughput.
        Verification      :  However, part of the code is verified manually and
                             it is not having any impact.
    */
    /* Get the pointer to the Controller structure */
    LpController = Can_GpFirstController + Can_GpCntrlIdArray[Controller];
    /* Get the pointer to the Wakeup status flag */
    LpWakeuporEvent = (LpController->pWkpStsFlag);
    /* Check,if the wakeup status is set */
    if(*LpWakeuporEvent == CAN_WAKEUP)
    {
      /* Enable protection for exclusive area */
      SchM_Enter_Can(CAN_INTERRUPT_CONTROL_PROTECTION_AREA);
      /* Clear the wakeup status flag */
      *(LpWakeuporEvent) &= CAN_DISABLEWAKEUP;
      /* Disable protection for exclusive area */
      SchM_Exit_Can(CAN_INTERRUPT_CONTROL_PROTECTION_AREA);
    }
    else
    {
      /* Set StdReturnType to E_NOT_OK */
      LenStdReturnType = E_NOT_OK;
    }
    #endif
  }
  return(LenStdReturnType);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
