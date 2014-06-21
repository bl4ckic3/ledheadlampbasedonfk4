/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_ModeCntrl.c                                             */
/* Version      = 3.0.5a                                                      */
/* Date         = 27.10.2011                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Controller Mode Control Functionality.                        */
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
 * V3.0.1:  10.10.2009  : Updated for changes in wake-up support as per
 *                        SCR ANMCANLINFR3_SCR_031.
 * V3.0.2:  21.04.2010  : As per ANMCANLINFR3_SCR_056,
 *                        1. Provision for Tied Wakeup interrupts is added.
 *                        2. Clearing of power save mode is ensured by
 *                           checking MBON bit status.
 * V3.0.3:  28.07.2010  : Timeout count is added in Can_StartMode as per
 *                        SCR ANMCANLINFR3_SCR_077.
 * V3.0.4:  14.03.2011  : Bus-Off flag check is updated in "Can_StartMode"
 *                        as per ANMCANLINFR3_SCR_096.
 * V3.0.5:  20.06.2011  : TimeoutCount assignment is moved to outside if loop
 *                        in "Can_StopMode" as per ANMCANLINFR3_SCR_107.
 * V3.0.5a: 27.10.2011  : 1. Copyright is updated.
 *                        2.Pointer-operation and clearing Interrupt Request 
 *                          Flag are updated in "Can_StopMode" as per MTS #3641.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can_PBTypes.h"      /* CAN Driver Post-Build Config. Header File */
#include "Can_ModeCntrl.h"    /* CAN Mode Control Header File */
#include "Can_Int.h"          /* CAN Interrupt Control Header File */
#include "Can_Ram.h"          /* CAN Driver RAM Header File */
#include "Can_Tgt.h"          /* CAN Driver Target Header File */
#include "Dem.h"              /* DEM Header File */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"              /* DET Header File */
#endif
#include "SchM_Can.h"         /* Scheduler Header File */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_MODECNTRL_C_AR_MAJOR_VERSION  2
#define CAN_MODECNTRL_C_AR_MINOR_VERSION  2
#define CAN_MODECNTRL_C_AR_PATCH_VERSION  2

/* File version information */
#define CAN_MODECNTRL_C_SW_MAJOR_VERSION  3
#define CAN_MODECNTRL_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CAN_MODECNTRL_AR_MAJOR_VERSION != CAN_MODECNTRL_C_AR_MAJOR_VERSION)
  #error "Can_ModeCntrl.c : Mismatch in Specification Major Version"
#endif
#if (CAN_MODECNTRL_AR_MINOR_VERSION != CAN_MODECNTRL_C_AR_MINOR_VERSION)
  #error "Can_ModeCntrl.c : Mismatch in Specification Minor Version"
#endif
#if (CAN_MODECNTRL_AR_PATCH_VERSION != CAN_MODECNTRL_C_AR_PATCH_VERSION)
  #error "Can_ModeCntrl.c : Mismatch in Specification Patch Version"
#endif
#if (CAN_MODECNTRL_SW_MAJOR_VERSION != CAN_MODECNTRL_C_SW_MAJOR_VERSION)
  #error "Can_ModeCntrl.c : Mismatch in Software Major Version"
#endif
#if (CAN_MODECNTRL_SW_MINOR_VERSION != CAN_MODECNTRL_C_SW_MINOR_VERSION)
  #error "Can_ModeCntrl.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CAN_AFCAN_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(Tdd_Can_AFCan_ModeFuncPtr, CAN_AFCAN_PRIVATE_CONST)
                                                 Can_GstModeFuncPtr[CAN_FOUR] =
{
  {
    Can_StartMode
  },
  {
    Can_StopMode
  },
  {
    Can_SleepMode
  },
  {
    Can_WakeupMode
  }
};

#define CAN_AFCAN_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Can_SetControllerMode
**
** Service ID         : 0x03
**
** Description        : This service calls the corresponding CAN Driver service
**                      for changing the CAN Controller Mode. It initiates a
**                      transition to the requested CAN Controller Mode.
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : Controller, Transition
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Can_ReturnType (CAN_OK / CAN_NOT_OK)
**
** Preconditions      : The CAN Driver must be initialized and during the
**                      function executes the Wake-up interrupt must be disabled
**                      so that the Wake-up status can be checked inside this
**                      function.
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_GblCanStatus, Can_GpCntrlIdArray,
**                      Can_GpFirstController, Can_GstModeFuncPtr,
**                      Can_GucLastCntrlId
**
**                    : Function(s) invoked:
**                      Det_ReportError()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(Can_ReturnType, CAN_AFCAN_PUBLIC_CODE) Can_SetControllerMode
                         (uint8 Controller, Can_StateTransitionType Transition)
{
  P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                          CAN_AFCAN_PRIVATE_CONST) LpController;
  Can_ReturnType LenCanReturnType;
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  uint8 LucCurrentMode;
  #endif

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Initialize CanReturnType to CAN_OK */
  LenCanReturnType = CAN_OK;
  /* Report to DET, if module is not initialized */
  if (Can_GblCanStatus == CAN_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                            CAN_SET_MODECNTRL_SID,CAN_E_UNINIT);
    /* Set CanReturnType to CAN_NOT_OK */
    LenCanReturnType = CAN_NOT_OK;
  }
  /* Report to DET, if the Controller Id is out of range */
  else if(Controller > Can_GucLastCntrlId)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                 CAN_SET_MODECNTRL_SID, CAN_E_PARAM_CONTROLLER);
    /* Set CanReturnType to CAN_NOT_OK */
    LenCanReturnType = CAN_NOT_OK;
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
                                 CAN_SET_MODECNTRL_SID, CAN_E_PARAM_CONTROLLER);
      /* Set CanReturnType to CAN_NOT_OK */
      LenCanReturnType = CAN_NOT_OK;
    }
    else
    {
      /* Get the pointer to the corresponding Controller structure */
      LpController = &Can_GpFirstController[Controller];
      /* Get the current mode of the Controller */
      LucCurrentMode = *(LpController->pCntrlMode);
      /* Report to DET, if the transition is not valid */
      if((((LucCurrentMode == (uint8)CAN_T_SLEEP) &&
        (Transition == (uint8)CAN_T_START))) ||
        (((LucCurrentMode == (uint8)CAN_T_START) &&
        (Transition == (uint8)CAN_T_SLEEP))) ||
        (((LucCurrentMode == (uint8)CAN_T_START) &&
        (Transition == (uint8)CAN_T_WAKEUP))) ||
        (((LucCurrentMode == (uint8)CAN_T_STOP) &&
        (Transition == (uint8)CAN_T_WAKEUP))))
      {
        /* Report to DET */
        Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                       CAN_SET_MODECNTRL_SID, CAN_E_TRANSITION);
        /* Set CanReturnType to CAN_NOT_OK */
        LenCanReturnType = CAN_NOT_OK;
      }
    }
  }
  /* MISRA Rule         : 13.7
     Message            : The result of this logical operation is always 'false'
     Reason             : Since e-num type is used it is not possible to
                          provide out of range value but as per AUTOSAR
                          all the input parameters of an API have to be
                          verified.
     Verification       : However, the part of the code is verified manually and
                          it is not having any impact on code.
  */
  /* MISRA Rule         : 14.1
     Message            : This statement is unreachable.
     Reason             : Since e-num type is used it is not possible to
                          provide out of range value but as per AUTOSAR
                          all the input parameters of an API have to be
                          verified.
     Verification       : However, the part of the code is verified manually and
                          it is not having any impact on code.
  */
  /* Report to DET, if the transition is out of range */
  if (Transition > CAN_T_WAKEUP)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                       CAN_SET_MODECNTRL_SID, CAN_E_TRANSITION);
    /* Set CanReturnType to CAN_NOT_OK */
    LenCanReturnType = CAN_NOT_OK;
  }
  /* Check whether any development error occurred */
  if(LenCanReturnType != CAN_NOT_OK)
  #endif /* #if (CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (CAN_DEV_ERROR_DETECT == STD_OFF)
    /*  MISRA Rule        :  17.4
        Message           :  Performing pointer arithmetic
        Reason            :  Increment operator not used to achieve better
                             throughput.
        Verification      :  However, part of the code is verified manually and
                             it is not having any impact.
    */
    /* Get the pointer to the Controller structure */
    LpController = Can_GpFirstController + Can_GpCntrlIdArray[Controller];
    #endif /* #if(CAN_DEV_ERROR_DETECT == STD_OFF) */
    /*  MISRA Rule         :  9.1
        Message            :  The variable(LpController) is possibly unset at
                              this point.
        Reason             :  This is to achieve throughput in the code.
        Verification       :  It is assured that variable is initialized
                              correctly before actually being used by the
                              embedded portion.
    */
    /* Invoke corresponding function based on the transition */
    LenCanReturnType = (Can_GstModeFuncPtr[Transition].pModeFuncPtr
                                                                (LpController));
  } /* if(LenCanReturnType != CAN_NOT_OK) */
  /* Return LenCanReturnType */
  return(LenCanReturnType);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_SleepMode
**
** Service ID         : Not Applicable
**
** Description        : This service initiates a transition to sleep mode.
**
** Sync/Async         : None
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : LpController
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Can_ReturnType (CAN_OK / CAN_NOT_OK)
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      None
**
**                    : Function(s) invoked:
**                      Dem_ReportErrorStatus()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PRIVATE_CODE
#include "MemMap.h"
FUNC(Can_ReturnType, CAN_AFCAN_PRIVATE_CODE) Can_SleepMode
(P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                           CAN_AFCAN_PRIVATE_CONST)LpController)
{
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  uint16_least LusTimeOutCount;
  Can_ReturnType LenCanReturnType;

  /* Get the pointer to 16-bit control register structure */
  LpCntrlReg16bit = LpController->pCntrlReg16bit;
  /* Set the operation mode to receive only mode */
  LpCntrlReg16bit->usFcnCmclCtl = CAN_SET_RECEIVE_ONLY_MODE;
  /* Get the Timeout count value and store it in a local variable */
  LusTimeOutCount = CAN_TIMEOUT_COUNT;
  /* Loop until receive only mode is set */
  do
  {
    /* Decrement the Timeout count */
    LusTimeOutCount--;
    /* Check whether receive-only mode is set and Timeout count is expired or
                                                                          not */
  }while(((LpCntrlReg16bit->usFcnCmclCtl & CAN_RECEIVE_ONLY_MODE_STS) !=
                   CAN_RECEIVE_ONLY_MODE_STS) && (LusTimeOutCount != CAN_ZERO));

  /* Set CanReturn Type to CAN_NOT_OK */
  LenCanReturnType = CAN_NOT_OK;
  /* Check whether Timeout count is expired or not */
  if(LusTimeOutCount != CAN_ZERO)
  {
    /* Get the Timeout count value and store it in a local variable */
    LusTimeOutCount = CAN_TIMEOUT_COUNT;
    /* Set the power save mode as sleep mode */
    LpCntrlReg16bit->usFcnCmclCtl = CAN_SET_SLEEP_MODE;
    do
    {
      /* Decrement the Timeout count */
      LusTimeOutCount--;
      /* Check whether MBON bit is cleared and Timeout count is expired or
                                                                          not */
    }while(((LpCntrlReg16bit->usFcnGmclCtl & CAN_MBON_BIT_STS) != CAN_ZERO)
                                              && (LusTimeOutCount != CAN_ZERO));
    /* Check whether Timeout count is expired or not */
    if(LusTimeOutCount != CAN_ZERO)
    {
      #if  (CAN_DEV_ERROR_DETECT == STD_ON)
      /* Set the Controller to sleep mode */
      *(LpController->pCntrlMode) = (uint8)CAN_T_SLEEP;
      #endif /* #if(CAN_DEV_ERROR_DETECT == STD_ON) */
      /* Set CanReturn Type to CAN_OK */
      LenCanReturnType = CAN_OK;
    }
    else
    {
      /* Report to DEM  for hardware failure */
      Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
    }
  } /* if(LusTimeOutCount != CAN_ZERO) */
  /* Return LenCanReturnType */
  return(LenCanReturnType);
  #else
  return(CAN_OK);
  #endif

}
#define CAN_AFCAN_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_WakeupMode
**
** Service ID         : Not Applicable
**
** Description        : This service initiates the transition to wakeup from
**                      sleep Mode.
**
** Sync/Async         : None
**
** Re-entrancy        : Re-entrant
**
** Input Parameters   : LpController
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Can_ReturnType (CAN_OK / CAN_NOT_OK)
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      None
**
**                    : Function(s) invoked:
**                      Dem_ReportErrorStatus()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PRIVATE_CODE
#include "MemMap.h"
FUNC(Can_ReturnType, CAN_AFCAN_PRIVATE_CODE) Can_WakeupMode
(P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                           CAN_AFCAN_PRIVATE_CONST)LpController)
{
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  uint16_least LusTimeOutCount;
  Can_ReturnType LenCanReturnType;

  /* Set CanReturn Type to CAN_NOT_OK */
  LenCanReturnType = CAN_NOT_OK;
  /* Get the pointer to 16-bit control register structure */
  LpCntrlReg16bit = LpController->pCntrlReg16bit;
  /* Clear the power save mode */
  LpCntrlReg16bit->usFcnCmclCtl = CAN_CLR_SLEEP_MODE;



  /* Get the Timeout count value and store it in a local variable */
  LusTimeOutCount = CAN_TIMEOUT_COUNT;
  /* Loop to check clearing power save mode */
  do
  {
    /* Decrement the Timeout count */
    --LusTimeOutCount;
    /* Check whether MBON bit is set and Timeout count is expired or not */
  } while(((LpCntrlReg16bit->usFcnGmclCtl & CAN_MBON_BIT_SET) !=
                            CAN_MBON_BIT_SET) && (LusTimeOutCount != CAN_ZERO));
  /* Check whether Timeout count is expired or not */
  if((LusTimeOutCount != CAN_ZERO) ||
                ((LpCntrlReg16bit->usFcnGmclCtl & CAN_MBON_BIT_SET) == CAN_ONE))
  {
    /* Clear the wakeup interrupt flag */
    LpCntrlReg16bit->usFcnCmisCtl = CAN_CLR_WAKEUP_INTERRUPT;
    /* Set the operation mode as initialization mode */
    LpCntrlReg16bit->usFcnCmclCtl = CAN_SET_INIT_OPMODE;
    /* Get the Timeout count value and store it in a local variable */
    LusTimeOutCount = CAN_TIMEOUT_COUNT;
    /* Loop to clear start mode */
    do
    {
      /* Decrement the TimeoutCount */
      LusTimeOutCount--;
      /* Check whether initialization mode is set and Timeout count is expired
                                                                       or not */
    }while(((LpCntrlReg16bit->usFcnCmclCtl & CAN_SET_INIT_OPMODE) != CAN_ZERO)
                                              && (LusTimeOutCount != CAN_ZERO));
    /* Check whether Timeout count is expired or not */
    if(LusTimeOutCount != CAN_ZERO)
    {
      #if  (CAN_DEV_ERROR_DETECT == STD_ON)
      /* Set the controller to wakeup mode */
      *(LpController->pCntrlMode) = (uint8)CAN_T_STOP;
      #endif
      /* Set CanReturn Type to CAN_OK */
      LenCanReturnType = CAN_OK;
    }
    else
    {
      /* Report to DEM for hardware failure */
      Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
    }
  }
  else
  {
    /* Report to DEM for hardware failure */
    Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
  }
  /* Return LenCanReturnType */
  return(LenCanReturnType);
  #else
  return(CAN_OK);
  #endif
}
#define CAN_AFCAN_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_StartMode
**
** Service ID         : Not Applicable
**
** Description        : This service initiates the transition to the normal
**                      operating mode with complete functionality.
**
** Sync/Async         : None
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : LpController
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Can_ReturnType (CAN_OK / CAN_NOT_OK)
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      None
**
**                    : Function(s) invoked:
**                      None
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PRIVATE_CODE
#include "MemMap.h"
FUNC(Can_ReturnType, CAN_AFCAN_PRIVATE_CODE) Can_StartMode
(P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                           CAN_AFCAN_PRIVATE_CONST)LpController)
{
  P2CONST(Tdd_Can_AFCan_Hrh,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST) LpHrh;
  P2VAR(Tdd_Can_AFCan_8bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                 LpCntrlReg8bit;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_DATA)
                                                               LpMsgBuffer16bit;
  /*  MISRA Rule        : 18.4
      Message           : An object of union type has been defined.
      Reason            : Data access of larger data types is used to achieve
                          better throughput.
      Verification      : However, part of the code is verified manually and
                          it is not having any impact.
  */
  Tun_Can_AFCan_WordAccess LunWordAccess;
  Can_ReturnType LenCanReturnType;
  uint8_least LucNoOfHoh;
  uint16_least LusTimeOutCount;

  /* Get the pointer to 8-bit control register structure */
  LpCntrlReg8bit = LpController->pCntrlReg8bit;
  /* Get the pointer to 16-bit control register structure */
  LpCntrlReg16bit = LpController->pCntrlReg16bit;
  /* Check whether BusOff flag is enabled or not */
  if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_BUSOFF_STS)) == CAN_BUSOFF_STS)
  {
    /* Set CCERC bit to clear INFO and ERC registers */
    LpCntrlReg16bit->usFcnCmclCtl = CAN_SET_CCERC_BIT;
  }
  /* Clear all interrupt flags of Interrupt Status register*/
  (LpCntrlReg16bit->usFcnCmisCtl) = (CAN_CLR_ALL_INTERRUPT);

  /* Clear the receive history list overflow bit */
  (LpCntrlReg16bit->usFcnCmrgRx) = (CAN_CLR_ROVF_BIT);
  /* Get the value of RGPT Register */
  LunWordAccess.usWord = (LpCntrlReg16bit->usFcnCmrgRx);

  /* Get the Timeout count value and store it in a local variable */
  LusTimeOutCount = CAN_TIMEOUT_COUNT;
  /* Check whether any message buffers are updated, if so clear */
  if((LunWordAccess.Tst_ByteAccess.ucLowByte) != CAN_RHPM_BIT_STS)
  {
    /* Loop to clear receive history list register */
    do
    {
      /* Decrement the TimeoutCount */
      LusTimeOutCount--;
      /* Get the value of RGPT Register */
      LunWordAccess.usWord = (LpCntrlReg16bit->usFcnCmrgRx);
      /* Check whether receive history list is empty */
    }while((((LunWordAccess.Tst_ByteAccess.ucLowByte) & (CAN_RHPM_BIT_STS)) !=
                            CAN_RHPM_BIT_STS) && (LusTimeOutCount != CAN_ZERO));
  } /* if((LunWordAccess.Tst_ByteAccess.ucLowByte) != CAN_RHPM_BIT_STS) */

  /* Check whether TimeOutCount is equal to zero */
  if(LusTimeOutCount == CAN_ZERO)
  {
    /* Report to DEM  for hardware failure */
    Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
    /* Set CanReturn Type to CAN_NOT_OK */
    LenCanReturnType = CAN_NOT_OK;
  }
  else
  {
    /* Get the number of Hrh configured and store it in local variable */
    LucNoOfHoh = LpController->ucNoOfHrh;
    /* Check whether any Hrh is configured or not */
    if(LucNoOfHoh != CAN_ZERO)
    {
      /* Get the pointer to Hrh structure */
      LpHrh = LpController->pHrh;
      /* Loop for the number of Hrh configured */
      do
      {
        /* Get the pointer to message buffer */
        LpMsgBuffer16bit = LpHrh->pMsgBuffer16bit;
        /*Clear DN bit */
        LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_DN_BIT;
        /* MISRA Rule         : 17.4
           Message            : Increment or decrement operation performed
                                on pointer(LpHrh).
           Reason             : Increment operator is used to achieve
                                better throughput.
           Verification       : However, part of the code is verified
                                manually and it is not having any impact.
        */
        /* Increment the pointer pointing to next Hrh structure */
        LpHrh++;
        /* Decrement the number of Hrh count configured */
        LucNoOfHoh--;
      }while(LucNoOfHoh != CAN_ZERO);
    } /* while(LucNoOfHrh != CAN_ZERO) */

    /* Clear the transmit history list overflow bit */
    (LpCntrlReg16bit->usFcnCmtgTx) = (CAN_CLR_TOVF_BIT);
    /* Get the value of TGPT Register */
    LunWordAccess.usWord = (LpCntrlReg16bit->usFcnCmtgTx);

    /* Check whether any message buffers are updated, if so clear */
    if(((LunWordAccess.Tst_ByteAccess.ucLowByte) & (CAN_THPM_BIT_STS)) !=
                                                                 CAN_THPM_BIT_STS)
    {
      /* Loop to clear transmit history list register */
      do
      {
        /* Get the value of TGPT Register */
        LunWordAccess.usWord = (LpCntrlReg16bit->usFcnCmtgTx);
      }while(((LunWordAccess.Tst_ByteAccess.ucLowByte) & (CAN_THPM_BIT_STS)) !=
                                                                CAN_THPM_BIT_STS);
    } /*if(((LunWordAccess.Tst_ByteAccess.ucLowByte) & (CAN_THPM_BIT_STS)) !=
                                                               CAN_THPM_BIT_STS)*/

    /* Enable all the interrupts */
    LpCntrlReg16bit->usFcnCmieCtl = LpController->usIntEnable;

    /* Set the operation mode as normal operating mode*/
    LpCntrlReg16bit->usFcnCmclCtl = CAN_SET_START_MODE;

    #if  (CAN_DEV_ERROR_DETECT == STD_ON)
    /* Set the Controller to start mode */
    *(LpController->pCntrlMode) = (uint8)CAN_T_START;
    #endif /* #if(CAN_DEV_ERROR_DETECT == STD_ON) */
    /* Set CanReturn Type to CAN_OK */
    LenCanReturnType = CAN_OK;
  }
  /* Return LenCanReturnType */
  return(LenCanReturnType);
}
#define CAN_AFCAN_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_StopMode
**
** Service ID         : Not Applicable
**
** Description        : This service initiates the transition to stop mode.
**
** Sync/Async         : None
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : LpController
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Can_ReturnType (CAN_OK / CAN_NOT_OK)
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      None
**
**                    : Function(s) invoked:
**                      Dem_ReportErrorStatus()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PRIVATE_CODE
#include "MemMap.h"
FUNC(Can_ReturnType, CAN_AFCAN_PRIVATE_CODE) Can_StopMode
(P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                           CAN_AFCAN_PRIVATE_CONST)LpController)
{
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  P2CONST(Tdd_Can_AFCan_Hth,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST) LpHth;
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_DATA)
                                                               LpMsgBuffer16bit;
  P2VAR(uint16,AUTOMATIC,CAN_AFCAN_CONFIG_DATA)LpIntCntrlReg;
  Can_ReturnType LenCanReturnType;
  uint16_least LusTimeOutCount;
  uint8_least LucNoOfCount;

  /* Get the pointer to the 16-bit control register structure */
  LpCntrlReg16bit = LpController->pCntrlReg16bit;

  #if  (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Set the Controller to stop mode */
  *(LpController->pCntrlMode) = (uint8)CAN_T_STOP;
  #endif /*  #if(CAN_DEV_ERROR_DETECT == STD_ON) */

  /* Get the number of Hth configured and store it in a local variable */
  LucNoOfCount = LpController->ucNoOfHth;
  /* Check whether any Hth is configured or not */
  if(LucNoOfCount != CAN_ZERO)
  {
    /* Get the pointer to Hth structure */
    LpHth = LpController->pHth;
    /* Loop for number of Hth */
    do
    {
      /* Get the pointer to the corresponding 16-bit message buffer register */
      LpMsgBuffer16bit = LpHth->pMsgBuffer16bit;
      /* Clear TRQ Bit */
      LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_TRQ_BIT;
       /* Check whether Multiplexed transmission is on or not */
      #if (CAN_MULTIPLEX_TRANSMISSION == STD_ON)
      /* Set the global flag to zero */
      *(LpHth->pHwAccessFlag) = CAN_FALSE;
      #endif
      /* MISRA Rule         : 17.4
         Message            : Increment or decrement operation performed
                              on pointer(LpHth).
         Reason             : Increment operator is used to achieve
                              better throughput.
         Verification       : However, part of the code is verified
                              manually and it is not having any impact.
      */
      /* Increment the pointer to point to next Hth structure */
      LpHth++;
      /* Decrement the number of Hth count configured */
      LucNoOfCount--;
    }while(LucNoOfCount != CAN_ZERO);
  }

  /* Set the operation mode as initialization mode */
  LpCntrlReg16bit->usFcnCmclCtl = CAN_SET_INIT_OPMODE;

  /* Get the Timeout count value and store it in a local variable */
  LusTimeOutCount = CAN_TIMEOUT_COUNT;
  /* Loop to clear start mode */
  do
  {
    /* Decrement the TimeoutCount */
    LusTimeOutCount--;
    /* Check whether initialization mode is set and Timeout count is expired or
                                                                        not */
  }while(((LpCntrlReg16bit->usFcnCmclCtl & CAN_SET_INIT_OPMODE) != CAN_ZERO)
                                            && (LusTimeOutCount != CAN_ZERO));

  /* Clear all interrupt flags of Interrupt Status register*/
  LpCntrlReg16bit->usFcnCmisCtl = CAN_CLR_ALL_INTERRUPT;
  /* Disable all interrupts */
  LpCntrlReg16bit->usFcnCmieCtl = CAN_CLR_ALL_INTERRUPT;
  /* Enable Wakeup */
  LpCntrlReg16bit->usFcnCmieCtl = ((LpController->usIntEnable) &
                                                    (CAN_ENB_WAKEUP_INTERRUPT));

  /* Get the pointer to EIC register */
  LpIntCntrlReg = (LpController->pIntCntrlReg);
  /* Initialize EIC Count */
  #if (CAN_WAKEUP_INTERRUPTS_TIED == TRUE)
  LucNoOfCount = CAN_THREE;
  #else
  LucNoOfCount = CAN_FOUR;
  #endif
  /* MISRA Rule         : 17.4
     Message            : Increment or decrement operation
                          performed on pointer(LpIntCntrlReg).
     Reason             : Increment operator is used to achieve
                          better throughput.
     Verification       : However, part of the code is verified
                          manually and it is not having any impact.
  */
  /* Loop to disable other interrupts in EIC */
  do
  {
    /* Clear Pending Interrupt status in EIRF bit */
    *LpIntCntrlReg &= CAN_CLR_INT_REQ;
    /*  MISRA Rule         :  17.4
        Message            :  Performing pointer arithmetic.
        Reason             :  Increment operator not used to achieve
                              better throughput.
        Verification       :  However, part of the code is verified
                              manually and it is not having any impact.
    */
    /* Increment the pointer to point to next EIC register */
    LpIntCntrlReg++;
    /* Decrement the EIC Count */
    LucNoOfCount--;
  }while(LucNoOfCount != CAN_ZERO);

  /* Set CanReturn Type to CAN_OK */
  LenCanReturnType = CAN_OK;

  /* Check whether TimeOutCount is equal to zero */
  if(LusTimeOutCount == CAN_ZERO)
  {
    /* Report to DEM  for hardware failure */
    Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
    /* Set CanReturn Type to CAN_NOT_OK */
    LenCanReturnType = CAN_NOT_OK;
  }
  /* Return LenCanReturnType */
  return(LenCanReturnType);
}
#define CAN_AFCAN_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
