/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_Int.c                                                   */
/* Version      = 3.0.4a                                                      */
/* Date         = 16-Nov-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Interrupt Control Functionality.                              */
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
 * V3.0.1:  10.10.2009  : Updated for changes in wake-up support and
 *                        EnableControllerInterrupts has been updated as per
 *                        SCR ANMCANLINFR3_SCR_031.
 * V3.0.2:  21.04.2010  : As per ANMCANLINFR3_SCR_056, provision for Tied Wakeup
 *                        interrupts is added.
 * V3.0.3:  11.05.2010  : "ddMask<xxx>Reg" are changed to "ucMask<xxx>Reg" as
 *                        per guidelines.
 * V3.0.4:  20.06.2011  : data width of interrupt control registers is changed
 *                        from unit8 to unit16 in Can_EnableControllerInterrupts
 *                        API as per SCR ANMCANLINFR3_SCR_107.
 * V3.0.4a: 16.11.2011  : Can_DisableControllerInterrupts and 
 *                        Can_EnableControllerInterrupts are updated due to the
 *                        change of the IC register operation.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can_PBTypes.h"      /* CAN Driver Post-Build Config. Header File */
#include "Can_Int.h"          /* CAN Interrupt Control Header File */
#include "Can_Ram.h"          /* CAN Driver RAM Header File */
#include "Can_Tgt.h"          /* CAN Driver Target Header File */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"              /* DET Header File */
#endif
#include "SchM_Can.h"         /* Scheduler Header File */
#include "Dem.h"              /* DEM Header File */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_INT_C_AR_MAJOR_VERSION  2
#define CAN_INT_C_AR_MINOR_VERSION  2
#define CAN_INT_C_AR_PATCH_VERSION  2

/* File version information */
#define CAN_INT_C_SW_MAJOR_VERSION  3
#define CAN_INT_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CAN_INT_AR_MAJOR_VERSION != CAN_INT_C_AR_MAJOR_VERSION)
  #error "Can_Int.c : Mismatch in Specification Major Version"
#endif
#if (CAN_INT_AR_MINOR_VERSION != CAN_INT_C_AR_MINOR_VERSION)
  #error "Can_Int.c : Mismatch in Specification Minor Version"
#endif
#if (CAN_INT_AR_PATCH_VERSION != CAN_INT_C_AR_PATCH_VERSION)
  #error "Can_Int.c : Mismatch in Specification Patch Version"
#endif
#if (CAN_INT_SW_MAJOR_VERSION != CAN_INT_C_SW_MAJOR_VERSION)
  #error "Can_Int.c : Mismatch in Software Major Version"
#endif
#if (CAN_INT_SW_MINOR_VERSION != CAN_INT_C_SW_MINOR_VERSION)
  #error "Can_Int.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Can_DisableControllerInterrupts
**
** Service ID         : 0x04
**
** Description        : This service disables all interrupts for this CAN
**                      Controller.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Re-entrant
**
** Input Parameters   : Controller
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_GblCanStatus, Can_GpCntrlIdArray, Can_GucIntCounter,
**                      Can_GpFirstController,Can_GucLastCntrlId.
**
**                      Function(s) invoked:
**                      Det_ReportError(),  SchM_Enter_Can(), SchM_Exit_Can()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(void, CAN_AFCAN_PUBLIC_CODE)Can_DisableControllerInterrupts
                                                              (uint8 Controller)
{
  P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                           CAN_AFCAN_PRIVATE_CONST)LpController;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  P2VAR(uint16,AUTOMATIC,CAN_AFCAN_CONFIG_DATA)LpIntCntrlReg;
  uint16 LusTimeOutCount;
  uint8_least LucCount;
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  boolean LblErrFlag;
  #endif

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Initialize the error status flag to false */
  LblErrFlag = CAN_FALSE;
  /* Report to DET, if module is not initialized */
  if (Can_GblCanStatus == CAN_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                        CAN_DISABLE_CNTRL_INT_SID,CAN_E_UNINIT);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  /* Report to DET, if the Controller Id is out of range */
  else if(Controller > Can_GucLastCntrlId)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                              CAN_DISABLE_CNTRL_INT_SID,CAN_E_PARAM_CONTROLLER);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  else
  {
    /* Get the Controller index */
    Controller = Can_GpCntrlIdArray[Controller];
    /* Check whether the Controller index is present or not */
    if(Controller == CAN_LIMIT)
    {
      /* Report to DET */
      Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                              CAN_DISABLE_CNTRL_INT_SID,CAN_E_PARAM_CONTROLLER);
      /* Set the error status flag to true */
      LblErrFlag = CAN_TRUE;
    }
  }
  /* Check whether any development error occurred */
  if(LblErrFlag != CAN_TRUE)
  #endif
  {
    #if (CAN_DEV_ERROR_DETECT == STD_OFF)
    /* Get the Controller index */
    Controller = Can_GpCntrlIdArray[Controller];
    #endif
    /* MISRA Rule         : 21.1
       Message            : Indexing array with value that will apparently be
                            out of bounds.
       Reason             : Negative value is not being used and verified.
       Verification       : However, the part of the code is
                            verified manually and it is not having
                            any impact on code.
    */
    /* Check whether Interrupt counter is equal to zero */
    if(Can_GucIntCounter[Controller] == CAN_ZERO)
    {
      /* Get the pointer to the Controller structure */
      LpController = &Can_GpFirstController[Controller];

      /* Get the pointer to the 16-bit control register structure */
      LpCntrlReg16bit = LpController->pCntrlReg16bit;
      /* Disable Wakeup and TxCancel interrupts in peripheral level */
      LpCntrlReg16bit->usFcnCmieCtl = CAN_CLR_WUP_TXCANCEL_INTERRUPT;
      /* Clear Wakeup and TxCancel interrupt status in peripheral level */
      LpCntrlReg16bit->usFcnCmisCtl = CAN_CLR_WUP_TXCANCEL_INTERRUPT;

      /* Get the pointer to EIC register */
      LpIntCntrlReg = (LpController->pIntCntrlReg);
      /* Initialize EIC Count */
      #if (CAN_WAKEUP_INTERRUPTS_TIED == TRUE)
      LucCount = CAN_THREE;
      #else
      LucCount = CAN_FOUR;
      #endif
      /* Loop to disable all interrupts in EIC */
      do
      {
        *(uint8 *)LpIntCntrlReg |= (uint8)CAN_IRQ_REQ_DIS; 
        /* Get the Timeout count value and store it in a local variable */
        LusTimeOutCount = CAN_TIMEOUT_COUNT;
        /* Check whether controller interrupts are disabled and Timeout count
        is expired or not */
        do
        {
          /* Decrement the Timeout count */
          LusTimeOutCount--;
        }while(((*LpIntCntrlReg & CAN_IRQ_REQ_DIS) != CAN_IRQ_REQ_DIS) &&
                                                 (LusTimeOutCount != CAN_ZERO));
        /* Check whether Timeout count is expired or not */
        if(LusTimeOutCount == CAN_ZERO)
        {
           /* Report to DEM  for hardware failure */
           Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
        }
        /* MISRA Rule         : 17.4
           Message            : Performing pointer arithmetic
                                on pointer 'LpIntCntrlReg'.
           Reason             : pointer arithmetic is performed to achieve
                                better throughput.
           Verification       : However, part of the code is verified
                                manually and it is not having any impact.
        */
        /* Increment the pointer to point to next EIC register */
        LpIntCntrlReg++;
        /* Decrement the EIC Count */
        LucCount--;
      }while(LucCount != CAN_ZERO);
    } /* if(Can_GucIntCounter[Controller] == CAN_ZERO) */
    /* MISRA Rule         : 21.1
       Message            : Indexing array with value that will apparently be
                            out of bounds.
       Reason             : Negative value is not being used and verified.
       Verification       : However, the part of the code is
                            verified manually and it is not having
                            any impact on code.
    */
    /* Increment the interrupt counter */
    Can_GucIntCounter[Controller]++;
  }/* if(LblErrFlag != CAN_TRUE) */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_EnableControllerInterrupts
**
** Service ID         : 0x05
**
** Description        : This service enables all interrupts for this CAN
**                      Controller.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Re-entrant
**
** Input Parameters   : Controller
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_GblCanStatus, Can_GpCntrlIdArray, Can_GucIntCounter,
**                      Can_GpFirstController,Can_GucLastCntrlId.
**
**                      Function(s) invoked:
**                      Det_ReportError(), SchM_Enter_Can(), SchM_Exit_Can()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(void, CAN_AFCAN_PUBLIC_CODE)Can_EnableControllerInterrupts
                                                              (uint8 Controller)
{
  P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                          CAN_AFCAN_PRIVATE_CONST) LpController;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  P2VAR(uint16,AUTOMATIC,CAN_AFCAN_CONFIG_DATA)LpIntCntrlReg;
  uint16 LusTimeOutCount;
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  boolean LblErrFlag;
  #endif

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Initialize the error status flag to false */
  LblErrFlag = CAN_FALSE;
  /* Report to DET, if module is not initialized */
  if (Can_GblCanStatus == CAN_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                        CAN_ENABLE_CNTRL_INT_SID, CAN_E_UNINIT);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  /* Report to DET, if the Controller Id is out of range */
  else if(Controller > Can_GucLastCntrlId)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                              CAN_ENABLE_CNTRL_INT_SID, CAN_E_PARAM_CONTROLLER);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  else
  {
    /* Get the Controller index */
    Controller = Can_GpCntrlIdArray[Controller];
    /* Check if the Controller index is present or not */
    if(Controller == CAN_LIMIT)
    {
      /* Report to DET */
      Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                              CAN_ENABLE_CNTRL_INT_SID, CAN_E_PARAM_CONTROLLER);
      /* Set the error status flag to true */
      LblErrFlag = CAN_TRUE;
    }
  }
  /* Check whether any development error occurred */
  if(LblErrFlag != CAN_TRUE)
  #endif
  {
    #if (CAN_DEV_ERROR_DETECT == STD_OFF)
    /* Get the Controller index */
    Controller = Can_GpCntrlIdArray[Controller];
    #endif
    /* MISRA Rule         : 21.1
       Message            : Indexing array with value that will apparently be
                            out of bounds.(Can_GucIntCounter)
       Reason             : Negative value is not being used and verified.
       Verification       : However, the part of the code is
                            verified manually and it is not having
                            any impact on code.
    */
    /* Check whether interrupt counter is equal to zero or not */
    if(Can_GucIntCounter[Controller] != CAN_ZERO)
    {
      /* Decrement the interrupt counter */
      Can_GucIntCounter[Controller]--;
      /* Check whether interrupt counter is equal to zero */
      if(Can_GucIntCounter[Controller] == CAN_ZERO)
      {
        /* Get the pointer to the Controller structure */
        LpController = &Can_GpFirstController[Controller];

        /* Get the pointer to the 16-bit control register structure */
        LpCntrlReg16bit = LpController->pCntrlReg16bit;
        /* Enable all interrupts in peripheral level */
        LpCntrlReg16bit->usFcnCmieCtl = LpController->usIntEnable;

        /* Get the pointer to EIC register */
        LpIntCntrlReg = (LpController->pIntCntrlReg);
        /* Enable error interrupt in EIC if bus-off configured */
        *(uint8 *)LpIntCntrlReg &= (uint8)(LpController->usMaskERRReg);
        /*  MISRA Rule         :  17.4
            Message            :  Performing pointer arithmetic.
            Reason             :  Increment operator not used to achieve
                                  better throughput.
            Verification       :  However, part of the code is verified
                                  manually and it is not having any impact.
        */
        #if (CAN_WAKEUP_INTERRUPTS_TIED == TRUE)
        /* Increment the pointer to point to next EIC register */
        LpIntCntrlReg++;
        #else
        LpIntCntrlReg += CAN_TWO;
        #endif
        /* Enable receive interrupt in EIC if configured */
        *(uint8 *)LpIntCntrlReg &= (uint8)(LpController->usMaskRECReg);
        /*  MISRA Rule         :  17.4
            Message            :  Performing pointer arithmetic.
            Reason             :  Increment operator not used to achieve
                                  better throughput.
            Verification       :  However, part of the code is verified
                                  manually and it is not having any impact.
        */
        /* Increment the pointer to point to next EIC register */
        LpIntCntrlReg++;
        /* Enable transmit interrupt in EIC if configured */
        *(uint8 *)LpIntCntrlReg &= (uint8)(LpController->usMaskTRXReg);
        /* Get the pointer to wake-up ICR register */
        LpIntCntrlReg = (LpController->pWupIntCntrlReg);
        /* Enable wake-up interrupt in EIC if configured */
        *(uint8 *)LpIntCntrlReg &= (uint8) (LpController->usMaskWUPReg);
      } /* if(Can_GucIntCounter[Controller] == CAN_ZERO) */
    }  /* if(Can_GucIntCounter[Controller] != CAN_ZERO) */
  }/* if(LblErrFlag != CAN_TRUE) */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
