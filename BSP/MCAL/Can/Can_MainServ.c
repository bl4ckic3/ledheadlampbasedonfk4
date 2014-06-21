/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_MainServ.c                                              */
/* Version      = 3.0.3a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Main Service Routines Functionality.                          */
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
 * V3.0.1:  20.10.2009  : Updated compiler version as per
 *                        SCR ANMCANLINFR3_SCR_031.
 * V3.0.2:  31.12.2010  : As per ANMCANLINFR3_SCR_087, space between
 *                        '#' and 'if' is removed.
 * V3.0.3:  20.06.2011  : As per ANMCANLINFR3_SCR_107, 
 *                        1. FCNnGMCLSSMO (MBON) flag check is implemented in 
 *                        Can_MainFunction_write().
 *                        2. In Can_TxCancellationProcessing, FCNnMmCTL register
 *                        is read only one time.
 * V3.0.3a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can_PBTypes.h"      /* CAN Driver Post-Build Config. Header File */
#include "Can_MainServ.h"     /* CAN Main Processing Header File */
#include "Can_Ram.h"          /* CAN Driver RAM Header File */
#include "Can_ModeCntrl.h"    /* CAN Mode Control Service Header File */
#include "Can_Tgt.h"          /* CAN Driver Target Header File */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"              /* DET Header File */
#endif
#if(CAN_WAKEUP_SUPPORT == STD_ON)
#include "EcuM_Cbk.h"         /* ECUM callback and callout Header File */
#endif
#include "SchM_Can.h"         /* Scheduler Header File */
#include "CanIf_Cbk.h"        /* CAN Interface call-back Header File */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_MAINSERV_C_AR_MAJOR_VERSION  2
#define CAN_MAINSERV_C_AR_MINOR_VERSION  2
#define CAN_MAINSERV_C_AR_PATCH_VERSION  2

/* File version information */
#define CAN_MAINSERV_C_SW_MAJOR_VERSION  3
#define CAN_MAINSERV_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CAN_MAINSERV_AR_MAJOR_VERSION != CAN_MAINSERV_C_AR_MAJOR_VERSION)
  #error "Can_MainServ.c : Mismatch in Specification Major Version"
#endif
#if (CAN_MAINSERV_AR_MINOR_VERSION != CAN_MAINSERV_C_AR_MINOR_VERSION)
  #error "Can_MainServ.c : Mismatch in Specification Minor Version"
#endif
#if (CAN_MAINSERV_AR_PATCH_VERSION != CAN_MAINSERV_C_AR_PATCH_VERSION)
  #error "Can_MainServ.c : Mismatch in Specification Patch Version"
#endif
#if (CAN_MAINSERV_SW_MAJOR_VERSION != CAN_MAINSERV_C_SW_MAJOR_VERSION)
  #error "Can_MainServ.c : Mismatch in Software Major Version"
#endif
#if (CAN_MAINSERV_SW_MINOR_VERSION != CAN_MAINSERV_C_SW_MINOR_VERSION)
  #error "Can_MainServ.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Can_MainFunction_Write
**
** Service ID         : 0x01
**
** Description        : This service performs the polling of transmit
**                      confirmation that is configured statically as
**                      'to be polled'.
**
** Sync/Async         : None
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : None
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
**                      Can_GblCanStatus, Can_GpFirstController
**
**                    : Function(s) invoked:
**                      Det_ReportError(), Can_TxConfirmationProcessing(),
**                      Can_TxCancellationProcessing()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(void, CAN_AFCAN_PUBLIC_CODE) Can_MainFunction_Write(void)
{
  P2CONST(Can_ControllerConfigType,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                                                   LpController;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC, CAN_AFCAN_PRIVATE_DATA)
                                                                LpCntrlReg16bit;
  uint8_least LucNoOfController;

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (Can_GblCanStatus == CAN_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                              CAN_MAIN_WRITE_SID, CAN_E_UNINIT);
  }
  else
  #endif
  {
    /* Get the pointer to first Controller structure */
    LpController = Can_GpFirstController;
    /* Get the number of Controllers configured */
    LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
    /* Loop for number of Controllers configured */
    do
    {
      /* Get the pointer to control register structure */
      LpCntrlReg16bit = LpController->pCntrlReg16bit;
      /* Check whether polling method is configured or not */
      if(((LpController->usIntEnable) & (CAN_TX_INT_MASK)) == CAN_FALSE)
      {        
        /* Check whether transmit interrupt is enabled or not */
        if((LpCntrlReg16bit->usFcnCmisCtl & CAN_TX_STS_MASK) == CAN_TX_STS_MASK)
        {
          /* Check whether MBON bit is set or not */
          if((LpCntrlReg16bit->usFcnGmclCtl & CAN_MBON_BIT_STS) != CAN_ZERO)
          {
            /* Invoke internal function to process transmit confirmation */
            Can_TxConfirmationProcessing(LpCntrlReg16bit,
                                                   LpController->ssHthOffSetId);
          }
        }
      }
      if(((LpController->usIntEnable) & (CAN_TXCANCEL_INT_MASK)) == CAN_FALSE)
      {
        #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
        if((LpCntrlReg16bit->usFcnCmisCtl & CAN_TXCANCEL_STS_MASK) ==
                                                          CAN_TXCANCEL_STS_MASK)
        {
          /* Check whether MBON bit is set or not */
          if((LpCntrlReg16bit->usFcnGmclCtl & CAN_MBON_BIT_STS) != CAN_ZERO)
          {
            /* Invoke internal function to process transmit cancellation */
            Can_TxCancellationProcessing(LpController, CAN_FALSE);
          }
        }
        #endif
      }
      /* MISRA Rule         : 17.4
         Message            : Increment or decrement operation performed
                              on pointer(LpController).
         Reason             : Increment operator is used to achieve
                              better throughput.
         Verification       : However, part of the code is verified
                              manually and it is not having any impact.
      */
      /* Increment the pointer to point to next Controller structure */
      LpController++;
      /* Decrement the number of Controllers count configured */
      LucNoOfController--;
      /* MISRA Rule         : 13.7
         Message            : The result of this logical operation is always
                              'false'. The value of this 'do - while' control
                              expression is always 'false'. The loop will be
                              executed once.
         Reason             : The result of this logical operation is always 
                              false since only one controller is configured. 
                              However, when two or more controllers are 
                              configured this warning ceases to exist.
         Verification       : However, part of the code is verified manually
                              and it is not having any impact.
      */
    }while(LucNoOfController != CAN_ZERO);
  } /* if (Can_GblCanStatus == CAN_UNINITIALIZED) */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_MainFunction_Read
**
** Service ID         : 0x08
**
** Description        : This service performs the polling of receive
**                      indications that are configured statically as 'to be
**                      polled'.
**
** Sync/Async         : None
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : None
**
** Input Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_GblCanStatus, Can_GpFirstController
**
**                    : Function(s) invoked:
**                      Can_RxProcessing() , Det_ReportError()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(void, CAN_AFCAN_PUBLIC_CODE) Can_MainFunction_Read(void)
{
  P2CONST(Can_ControllerConfigType,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                                                   LpController;
  P2CONST(Tdd_Can_AFCan_8bit_CntrlReg,AUTOMATIC, CAN_AFCAN_PRIVATE_DATA)
                                                                LpCntrlReg8bit;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC, CAN_AFCAN_PRIVATE_DATA)
                                                                LpCntrlReg16bit;
  uint8_least LucNoOfController;

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (Can_GblCanStatus == CAN_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                                CAN_MAIN_READ_SID,CAN_E_UNINIT);
  }
  else
  #endif
  {
    /* Get the pointer to first Controller structure */
    LpController = Can_GpFirstController;

    /* Get the number of Controllers configured */
    LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;

    /* Loop for the number of Controllers configured */
    do
    {
      /* Check whether polling method is configured or not */
      if(((LpController->usIntEnable) & (CAN_REC_INT_MASK)) == CAN_FALSE)
      {
        /* Get the pointer to 8-bit control register structure */
        LpCntrlReg8bit = LpController->pCntrlReg8bit;
        /* Get the pointer to 16-bit control register structure */
        LpCntrlReg16bit = LpController->pCntrlReg16bit;
        /* Check whether receive interrupt is enabled or not */
        if(((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_REC_STS_MASK)) ==
                                                              CAN_REC_STS_MASK)
        {
          /* Check whether MBON bit is set or not */
          if((LpCntrlReg16bit->usFcnGmclCtl & CAN_MBON_BIT_STS) != CAN_ZERO)
          {
            /* Invoke internal function for receive processing  */
            Can_RxProcessing(LpCntrlReg8bit, LpCntrlReg16bit,
                                                  LpController->ucHrhOffSetId);
          }
        }
      }
      /* Decrement the number of Controllers count configured */
      LucNoOfController--;
      /* MISRA Rule         : 17.4
         Message            : Increment or decrement operation performed
                              on pointer(LpController).
         Reason             : Increment operator is used to achieve
                              better throughput.
         Verification       : However, part of the code is verified
                              manually and it is not having any impact.
      */
      /* Increment the pointer to point to next Controller structure */
      LpController++;
      /* MISRA Rule         : 13.7
         Message            : The result of this logical operation is always
                              'false'. The value of this 'do - while' control
                              expression is always 'false'. The loop will be
                              executed once.
         Reason             : The result of this logical operation is always 
                              false since only one controller is configured. 
                              However, when two or more controllers are 
                              configured this warning ceases to exist.
         Verification       : However, part of the code is verified manually
                              and it is not having any impact.
      */
    }while (LucNoOfController!= CAN_ZERO);
  }
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_MainFunction_BusOff
**
** Service ID         : 0x09
**
** Description        : This service performs the polling of BusOff events
**                      that are configured statically as 'to be polled'.
**
** Sync/Async         : None
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : None
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
**                      Can_GblCanStatus, Can_GpFirstController
**
**                    : Function(s) invoked:
**                      Det_ReportError(), Can_StopMode(),
**                      CanIf_ControllerBusOff()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(void, CAN_AFCAN_PUBLIC_CODE) Can_MainFunction_BusOff(void)
{
P2CONST(Can_ControllerConfigType,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                                                   LpController;
P2VAR(Tdd_Can_AFCan_8bit_CntrlReg,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg8bit;
P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
uint8_least LucNoOfController;

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (Can_GblCanStatus == CAN_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                             CAN_MAIN_BUSOFF_SID, CAN_E_UNINIT);
  }
  else
  #endif
  {
   /* Get the pointer to first Controller structure */
    LpController = Can_GpFirstController;
    /* Get the number of Controllers configured */
    LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
    /* Loop for the number of Controllers configured  */
    do
    {
      /* Check whether polling method is configured or not */
      if(((LpController->usIntEnable) & (CAN_ERR_INT_MASK)) == CAN_FALSE)
      {
        /* Get the pointer to 8-bit control register structure */
        LpCntrlReg8bit = LpController->pCntrlReg8bit;
        /* Get the pointer to 16-bit control register structure */
        LpCntrlReg16bit = LpController->pCntrlReg16bit;
        /* Check whether receive interrupt is enabled or not */
        if(((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_ERR_STS_MASK)) ==
                                                              CAN_ERR_STS_MASK)
        {
          /* Check whether BusOff flag is enabled or not */
          if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_BUSOFF_STS)) ==
                                                                CAN_BUSOFF_STS)
          {
            /*  MISRA Rule      : 16.10
                Message         : Function returns a value which is not being
                                  used.
                Reason          : Return value not used to achieve better
                                  throughput.
                Verification    : However, part of the code is verified manually
                                  and it is not having any impact.
            */
            /* Invoke Can_StopMode internal function to set to initialization
                                                                         mode */
            Can_StopMode(LpController);
            /* Invoke CanIf_ControllerBusOff call-back function to give busoff
               notification */
            CanIf_ControllerBusOff(LpController->ucCntrlRegId);
          }
        }
      }
      /* Decrement the number of Controllers count configured */
      LucNoOfController--;
      /* MISRA Rule         : 17.4
         Message            : Increment or decrement operation performed
                              on pointer(LpController).
         Reason             : Increment operator is used to achieve
                              better throughput.
         Verification       : However, part of the code is verified
                              manually and it is not having any impact.
      */
      /* Increment the pointer to point to next Controller structure */
      LpController++;
      /* MISRA Rule         : 13.7
         Message            : The result of this logical operation is always
                              'false'. The value of this 'do - while' control
                              expression is always 'false'. The loop will be
                              executed once.
         Reason             : The result of this logical operation is always 
                              false since only one controller is configured. 
                              However, when two or more controllers are 
                              configured this warning ceases to exist.
         Verification       : However, part of the code is verified manually
                              and it is not having any impact.
      */
    }while (LucNoOfController != CAN_ZERO);
  }
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_MainFunction_Wakeup
**
** Service ID         : 0x10
**
** Description        : This service performs the polling of wake-up events
**                      that are configured statically as 'to be polled'.
**
** Sync/Async         : None
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : None
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
**                      Can_GblCanStatus, Can_GpFirstController
**
**                    : Function(s) invoked:
**                      Det_ReportError(),Can_WakeupMode(),
**                      CanIf_SetWakeupEvent()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(void,CAN_AFCAN_PUBLIC_CODE) Can_MainFunction_Wakeup(void)
{
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2CONST(Can_ControllerConfigType,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                                                   LpController;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_PRIVATE_DATA) LpWakeuporEvent;
  uint8_least LucNoOfController;
  #endif

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (Can_GblCanStatus == CAN_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                             CAN_MAIN_WAKEUP_SID, CAN_E_UNINIT);
  }
  else
  #endif
  {
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    /* Get the pointer to first Controller structure */
    LpController = Can_GpFirstController;

    /* Get the number of Controllers configured */
    LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
    /* Loop for the number of Controllers configured */
    do
    {
      /* Check whether polling method is configured or not */
      if(((LpController->usIntEnable) & (CAN_WAKEUP_INT_MASK)) ==
                                                                      CAN_FALSE)
      {
        /* Get the pointer to control register structure */
        LpCntrlReg16bit = LpController->pCntrlReg16bit;
        /* Check whether Wakeup interrupt is enabled or not */
        if(((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_WAKEUP_STS_MASK)) ==
                                                            CAN_WAKEUP_STS_MASK)
        {
          /* Get the pointer to the Wakeup status flag */
          LpWakeuporEvent = (LpController->pWkpStsFlag);
          /*  MISRA Rule   : 16.10
              Message      : Function returns a value which is not being used
              Reason       : Return value not used to achieve better throughput.
              Verification : However, part of the code is verified manually
                             and it is not having any impact.
          */
          /* Invoke internal function to process wakeup */
          Can_WakeupMode(LpController);
          /* Store the wakeup event */
          *LpWakeuporEvent = CAN_WAKEUP;
        }
      }
      /* Decrement the number of Controllers count configured */
      LucNoOfController--;
      /* MISRA Rule         : 17.4
         Message            : Increment or decrement operation performed
                              on pointer(LpController).
         Reason             : Increment operator is used to achieve
                              better throughput.
         Verification       : However, part of the code is verified
                              manually and it is not having any impact.
      */
      /* Increment the pointer to point to next Controller structure */
      LpController++;
      /* MISRA Rule         : 13.7
         Message            : The result of this logical operation is always
                              'false'. The value of this 'do - while' control
                              expression is always 'false'. The loop will be
                              executed once.
         Reason             : The result of this logical operation is always 
                              false since only one controller is configured. 
                              However, when two or more controllers are 
                              configured this warning ceases to exist.
         Verification       : However, part of the code is verified manually
                              and it is not having any impact.
      */
    }while (LucNoOfController != CAN_ZERO);
    #endif /* #if (CAN_WAKEUP_SUPPORT == STD_ON) */
  }
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_TxConfirmationProcessing
**
** Service ID         : Not Applicable
**
** Description        : This service notifies the upper layer about transmit
**                      confirmation.
**
** Sync/Async         : None
**
** Re-entrancy        : Re-entrant
**
** Input Parameters   : LpCntrlReg, LssHthOffSetId
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_GpFirstHth
**
**                    : Function(s) invoked:
**                      CanIf_TxConfirmation()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PRIVATE_CODE
#include "MemMap.h"
FUNC(void, CAN_AFCAN_PRIVATE_CODE) Can_TxConfirmationProcessing
(CONSTP2VAR(Tdd_Can_AFCan_16bit_CntrlReg, AUTOMATIC,
                  CAN_AFCAN_PRIVATE_CONST)LpCntrlReg16bit,sint16 LssHthOffSetId)
{
  P2CONST(Tdd_Can_AFCan_Hth,AUTOMATIC,CAN_PRIVATE_CONST)LpHth;
  /*  MISRA Rule        : 18.4
      Message           : An object of union type has been defined.
      Reason            : Data access of larger data types is used to achieve
                          better throughput.
      Verification      : However, part of the code is verified manually and
                          it is not having any impact.
  */
  Tun_Can_AFCan_WordAccess LunWordAccess;
  uint8 LucHth;

  /* Get the value of TGPT Register */
  LunWordAccess.usWord = (LpCntrlReg16bit->usFcnCmtgTx);
  /* Loop for number of transmit messages */
  do
  {
    /* Clear transmission interrupt bit of Interrupt Status register */
    (LpCntrlReg16bit->usFcnCmisCtl) = (CAN_CLR_TX_INTERRUPT);
    /* Clear transmit history overflow bit of TGPT register */
    (LpCntrlReg16bit->usFcnCmtgTx) = (CAN_CLR_TOVF_BIT);
    /* Get the corresponding Hth value from the message buffer */
    LucHth = (uint8)
      ((sint16)LunWordAccess.Tst_ByteAccess.ucHighByte + LssHthOffSetId);
    /* Get the pointer to Hth structure */
    LpHth = &Can_GpFirstHth[LucHth];
    /* Invoke CanIf_TxConfirmation call-back function to give transmit
                                                                 confirmation*/
    CanIf_TxConfirmation(*(LpHth->pCanTxPduId));
    /* Get the value of TGPT Register */
    LunWordAccess.usWord = (LpCntrlReg16bit->usFcnCmtgTx);
   /* Check whether receive history list is empty */
  } while(((LunWordAccess.Tst_ByteAccess.ucLowByte) & (CAN_THPM_BIT_STS)) !=
                                                             CAN_THPM_BIT_STS);
}
#define CAN_AFCAN_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_TxCancellationProcessing
**
** Service ID         : Not Applicable
**
** Description        : This service checks whether transmit cancellation is
**                      successful and notifies the upper layer about transmit
**                      cancellation. If cancellation fails and the message get
**                      transmitted, it will invoke Tx Confirmation notification
**
** Sync/Async         : None
**
** Re-entrancy        : Re-entrant
**
** Input Parameters   : LpCntrlReg, LssHthOffSetId
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_GpFirstHth, Can_AFCan_GaaTxCancelStsFlgs[]
**                      Can_GaaTxCancelCtr[]
**
**                    : Function(s) invoked:
**                      CanIf_CancelTxConfirmation(), CanIf_TxConfirmation()
**
*******************************************************************************/
#if(CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
#define CAN_AFCAN_START_SEC_PRIVATE_CODE
#include "MemMap.h"
FUNC(void, CAN_AFCAN_PRIVATE_CODE) Can_TxCancellationProcessing
(P2CONST(Can_ControllerConfigType,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                               LpController, boolean LblIntFlag)
{
  P2CONST(Tdd_Can_AFCan_Hth,AUTOMATIC,CAN_PRIVATE_CONST)LpHth;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  P2VAR(Tdd_Can_AFCan_8bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                               LpMsgBuffer8bit;
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                               LpMsgBuffer16bit;

  P2VAR(Can_PduType, AUTOMATIC, CAN_PRIVATE_DATA)LpPduInfoPtr;
  P2VAR(uint8,AUTOMATIC, CAN_AFCAN_PRIVATE_DATA)LpCanSduPtr;
  P2VAR(uint8,AUTOMATIC, CAN_AFCAN_PRIVATE_DATA)LpMsgDataBuffer;
  Can_PduType LddPduInfo;
  uint8 LaaCanSdu[CAN_EIGHT];
  /*  MISRA Rule        : 18.4
      Message           : An object of union type has been defined.
                          (Tun_Can_CanId/Tun_Can_WordAccess)
      Reason            : Data access of larger data types is used to achieve
                          better throughput.
      Verification      : However, part of the code is verified manually and
                          it is not having any impact.
  */
  Tun_Can_AFCan_CanId Lun_Can_CanId;
  uint8_least LucCount;
  uint8_least LucDlc;
  uint8 LucArrPosition;
  uint8 LucMask;
  uint8 LucHth;
  uint16 LusTempVal;

  /* Get the array position for first BasicCAN Hth of this controller */
  LucArrPosition = LpController->ucBasicCanHthOffset;
  /* Initialize the BasicCAN Hth count of the controller to zero */
  LucCount = CAN_ZERO;
  /* Loop as many times as the number of BasicCAN Hth of the controller */
  while(LucCount < (LpController->ucNoOfBasicCanHth))
  {
    /* Set value for masking the status of Tx cancel status flag of the Hth */
    LucMask = (CAN_ONE << (LucArrPosition % CAN_EIGHT));
    /* Check whether the status flag for Tx cancellation is set for the Hth */
    if((Can_AFCan_GaaTxCancelStsFlgs[(LucArrPosition >> CAN_THREE)] & LucMask)
                                                                     == LucMask)
    {
      /* Get the Hth Id from Basic Hth Array */
      LucHth = Can_AFCan_GaaBasicCanHth[LucArrPosition];
      /* Get the Hth */
      LucHth -= Can_GucFirstHthId;
      /* Get the pointer to the corresponding Hth structure */
      LpHth = &Can_GpFirstHth[LucHth];
      /* Get the pointer to 8-bit message buffer register */
      LpMsgBuffer8bit = LpHth->pMsgBuffer8bit;
      /* Get the pointer to 16-bit message buffer register */
      LpMsgBuffer16bit = LpHth->pMsgBuffer16bit;
      /* Get pointer to PduInfo */
      LpPduInfoPtr = &LddPduInfo;
      /* Get the pointer to 16-Bit control register structure */
      LpCntrlReg16bit = LpController->pCntrlReg16bit;
      /* Clear transmission interrupt bit of Interrupt Status register */
      (LpCntrlReg16bit->usFcnCmisCtl) = (CAN_CLR_TXCANCEL_INTERRUPT);
      /* Clear transmission interrupt bit of Interrupt Status register */
      (LpCntrlReg16bit->usFcnCmisCtl) = (CAN_CLR_ERR_INTERRUPT);
      /* Read FCNnMmCTL register */
      LusTempVal = LpMsgBuffer16bit->usFcnMmCtl;
      /* Check whether TRQ and TCP are cleared for Tx Cancellation */
      if(((LusTempVal & CAN_TRQ_BIT_STS) != CAN_TRQ_BIT_STS)
       && ((LusTempVal & CAN_TCP_BIT_STS) != CAN_TCP_BIT_STS))
      {
        /* Check whether Multiplexed transmission is on or not */
        #if (CAN_MULTIPLEX_TRANSMISSION == STD_ON)
        /* Disable global interrupts */
        SchM_Enter_Can(CAN_WRITE_PROTECTION_AREA);
        /* Set the global flag to one to indicate access of hardware buffer */
        *(LpHth->pHwAccessFlag) = CAN_TRUE;
        /* Enable global interrupts */
        SchM_Exit_Can(CAN_WRITE_PROTECTION_AREA);
        #endif /* #if(CAN_MULTIPLEX_TRANSMISSION == STD_ON) */
        #if (CAN_STANDARD_CANID == STD_OFF)
        /* Check whether  CAN-ID is of Extended Type */
        if((LpMsgBuffer16bit->usFcnMmMid1h & CAN_MASK_IDE_BIT) ==
                                                               CAN_MASK_IDE_BIT)
        {
          /* Write 16-28 Id bits of message Id high register */
          Lun_Can_CanId.Tst_CanId.usCanIdHigh = 
                                               (LpMsgBuffer16bit->usFcnMmMid1h);
          /* Write 0-15 Id bits of message Id low register */
          Lun_Can_CanId.Tst_CanId.usCanIdLow = (LpMsgBuffer16bit->usFcnMmMid0h);
        }
        else
        {
          /* Make higher word equal to zero */
          Lun_Can_CanId.Tst_CanId.usCanIdHigh = CAN_ZERO;
          /* Write 18-28 Id bits of message Id high register */
          Lun_Can_CanId.Tst_CanId.usCanIdLow = (LpMsgBuffer16bit->usFcnMmMid1h)
                                                                   >> (CAN_TWO);
        }
        #else
        /* Write 18-28 Id bits of message Id high register */
        Lun_Can_CanId.Tst_CanId.usCanIdLow = (LpMsgBuffer16bit->usFcnMmMid1h) >>
                                                                      (CAN_TWO);
        #endif
        /* Copy CanId to PduInfoPtr */
        LpPduInfoPtr->id = Lun_Can_CanId.ulCanId ;
        /* Get the DLC length from the corresponding message buffer DLC
                                                                      register*/
        LucDlc = LpMsgBuffer8bit->ucFcnMmDtlgb;
        /* Copy DLC to PduInfoPtr */
        LpPduInfoPtr->length = (uint8)LucDlc;
        /* Get the pointer to message data byte register */
        LpMsgDataBuffer = LpMsgBuffer8bit->aaDataBuffer;
        /* Get the start address of sdu pointer */
        LpCanSduPtr = &LaaCanSdu[CAN_ZERO];
        /* Loop until the DLC length is equal to zero to copy data */
        while(LucDlc != CAN_ZERO)
        {
          /* Transfer the data from the corresponding message data byte
                                                                     register */
          *(LpCanSduPtr) = *(LpMsgDataBuffer);
          /* MISRA Rule          : 17.4
             Message             : Increment or decrement operation performed
                                   on pointer(LpCanSduPtr).
             Reason              : Increment operator is used to achieve
                                   better throughput.
             Verification        : However, part of the code is verified
                                   manually and it is not having any impact.
          */
          /* Increment the Sdu pointer */
          LpCanSduPtr++;
          /*  MISRA Rule         :  17.4
              Message            :  Performing pointer arithmetic.
              Reason             :  Increment operator not used to achieve
                                    better throughput.
              Verification       :  However, part of the code is verified
                                    manually and it is not having any impact.
          */
          /* Increment the Message data buffer pointer */
          LpMsgDataBuffer += CAN_FOUR;
          /* Decrement the DLC length */
          LucDlc--;
        }
        /* Check whether Multiplexed transmission is on or not */
        #if (CAN_MULTIPLEX_TRANSMISSION == STD_ON)
        /* Disable global interrupts */
        SchM_Enter_Can(CAN_WRITE_PROTECTION_AREA);
        /* Set the global flag to one to indicate access of hardware buffer */
        *(LpHth->pHwAccessFlag) = CAN_FALSE;
        /* Enable global interrupts */
        SchM_Exit_Can(CAN_WRITE_PROTECTION_AREA);
        #endif /* #if(CAN_MULTIPLEX_TRANSMISSION == STD_ON) */
        /* Copy sdu pointer to PduInfoPtr */
        LpPduInfoPtr->sdu = LpCanSduPtr;
        /* Copy swPduHandle to PduInfoPtr */
        LpPduInfoPtr->swPduHandle = *(LpHth->pCanTxPduId);
        /* Invoke CanIf_CancelTxConfirmation call-back function to give
                                                  transmit cancel confirmation*/
        CanIf_CancelTxConfirmation(LpPduInfoPtr);
        /* Clear global Tx Cancel Status flag of the BasicCAN Hth */
        Can_AFCan_GaaTxCancelStsFlgs[(LucArrPosition >> CAN_THREE)] &= 
                                                             (uint8) (~LucMask);
        if(LblIntFlag == CAN_TRUE)
        {
          /* Clear global Tx Cancel flag */
          Can_GblTxCancelIntFlg = CAN_FALSE;
        }
        else
        {
          /* Decrement global Tx Cancel counter of the controller */
          Can_GaaTxCancelCtr[(LpHth->ucController)] -= CAN_ONE;
        }
      } /* End of if for TRQ and TCP flag check */
      /* Check whether TRQ is cleared and TCP is set for Tx Confirmation */
      else if(((LusTempVal & CAN_TRQ_BIT_STS) != CAN_TRQ_BIT_STS)
            && ((LusTempVal & CAN_TCP_BIT_STS) == CAN_TCP_BIT_STS))
      {
        /* Invoke CanIf_TxConfirmation call-back function to give transmit
                                                                  confirmation*/
        CanIf_TxConfirmation(*(LpHth->pCanTxPduId));
        /* Clear global Tx Cancel Status flag of the BasicCAN Hth */
        Can_AFCan_GaaTxCancelStsFlgs[(LucArrPosition >> CAN_THREE)] &=
                                                             (uint8) (~LucMask);
        if(LblIntFlag == CAN_TRUE)
        {
          /* Clear global Tx Cancel flag */
          Can_GblTxCancelIntFlg = CAN_FALSE;
        }
        else
        {
          /* Decrement global Tx Cancel counter of the controller */
          Can_GaaTxCancelCtr[(LpHth->ucController)] -= CAN_ONE;
        }
      } /* End of else-if for TRQ and TCP flag check */
      else
      {
        /* To avoid QAC Warning */
      }
    } /* if(Can_AFCan_GaaTxCancelStsFlgs) */
    /* Increment the array position to point to next BasicCAN Hth of the
                                                                   controller */
    LucArrPosition++;
    /* Increment BasicCAN Hth count of the controller */
    LucCount++;
  } /* while(LucCount < (LpController->ucNoOfBasicCanHth)) */
}
#define CAN_AFCAN_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Can_RxProcessing
**
** Service ID         : Not Applicable
**
** Description        : This service notifies the upper layer about receive
**                      indication.
**
** Sync/Async         : None
**
** Re-entrancy        : Re-entrant
**
** Input Parameters   : LpCntrlReg, LucHrhOffSetId
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      None
**
**                    : Function(s) invoked:
**                      CanIf_RxIndication()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PRIVATE_CODE
#include "MemMap.h"
FUNC(void, CAN_AFCAN_PRIVATE_CODE) Can_RxProcessing
(P2CONST(Tdd_Can_AFCan_8bit_CntrlReg, AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                                                 LpCntrlReg8bit,
CONSTP2VAR(Tdd_Can_AFCan_16bit_CntrlReg, AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit,
uint8 LucHrhOffSetId)
{
  P2CONST(Tdd_Can_AFCan_8bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpMsgBuffer8bit;
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                               LpMsgBuffer16bit;
  P2CONST(Tdd_Can_AFCan_8bit_MsgBuffer,AUTOMATIC,
                                   CAN_AFCAN_PRIVATE_CONST)LpFirstMsgBuffer8bit;
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer,AUTOMATIC,
                                  CAN_AFCAN_PRIVATE_CONST)LpFirstMsgBuffer16bit;
  P2VAR(uint8,AUTOMATIC, CAN_AFCAN_PRIVATE_DATA)LpCanSduPtr;
  P2CONST(uint8,AUTOMATIC, CAN_AFCAN_PRIVATE_DATA)LpMsgDataBuffer;
  uint8 LaaCanSdu[CAN_EIGHT];
  /*  MISRA Rule        : 18.4
      Message           : An object of union type has been defined.
                          (Tun_Can_CanId/Tun_Can_WordAccess)
      Reason            : Data access of larger data types is used to achieve
                          better throughput.
      Verification      : However, part of the code is verified manually and
                          it is not having any impact.
  */
  Tun_Can_AFCan_CanId Lun_Can_CanId;
  Tun_Can_AFCan_WordAccess LunWordAccess;
  uint8_least LucCounter;
  uint8_least LucDlc;
  uint8 LucHrh;
  uint8 LucCanDlc;

  /* Get the value of RGPT Register */
  LunWordAccess.usWord = (LpCntrlReg16bit->usFcnCmrgRx);
  /* Get the pointer to first 8-bit message buffer register */
  LpFirstMsgBuffer8bit = LpCntrlReg8bit->ddMsgBuffer;
  /* Get the pointer to first 16-bit message buffer register */
  LpFirstMsgBuffer16bit = LpCntrlReg16bit->ddMsgBuffer;
  /* Loop for number of receive messages */
  do
  {
    /* Get the pointer to 8-bit message buffer registers */
    LpMsgBuffer8bit =
                 &LpFirstMsgBuffer8bit[LunWordAccess.Tst_ByteAccess.ucHighByte];
    /* Get the pointer to 16-bit message buffer registers */
    LpMsgBuffer16bit =
                &LpFirstMsgBuffer16bit[LunWordAccess.Tst_ByteAccess.ucHighByte];
    /* Clear receive interrupt bit of Interrupt Status register */
    (LpCntrlReg16bit->usFcnCmisCtl) = (CAN_CLR_RX_INTERRUPT);
    /* Clear receive history list overflow bit of RGPT register */
    (LpCntrlReg16bit->usFcnCmrgRx) = (CAN_CLR_ROVF_BIT);
    /* Check whether DN bit is set or not */
    if((LpMsgBuffer16bit->usFcnMmCtl & CAN_DN_MUC_BIT_STS) == CAN_DN_BIT_STS)
    {
      /* Set the Counter to two */
      LucCounter = CAN_TWO;
      do
      {
        /* Decrement the Counter */
        LucCounter--;
        /* Clear DN bit */
        LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_DN_BIT;
        #if (CAN_STANDARD_CANID == STD_OFF)
        /* Check whether received CAN-ID is of Extended Type */
        if((LpMsgBuffer16bit->usFcnMmMid1h & CAN_MASK_IDE_BIT) ==
                                                               CAN_MASK_IDE_BIT)
        {
          /* Read 16-28 Id bits of message Id high register */
          Lun_Can_CanId.Tst_CanId.usCanIdHigh = 
                                               (LpMsgBuffer16bit->usFcnMmMid1h);
          /* Read 0-15 Id bits of message Id low register */
          Lun_Can_CanId.Tst_CanId.usCanIdLow = LpMsgBuffer16bit->usFcnMmMid0h;
        }
        else
        {
          /* Make higher word equal to zero */
          Lun_Can_CanId.Tst_CanId.usCanIdHigh = CAN_ZERO;
          /* Read 18-28 Id bits of message Id high register */
          Lun_Can_CanId.Tst_CanId.usCanIdLow = (LpMsgBuffer16bit->usFcnMmMid1h)
                                                                   >> (CAN_TWO);
        }
        #else
        /* Read 18-28 Id bits of message Id high register */
        Lun_Can_CanId.Tst_CanId.usCanIdLow = (LpMsgBuffer16bit->usFcnMmMid1h) >>
                                                                      (CAN_TWO);
        #endif

        /* Get the DLC length from the corresponding message buffer DLC
                                                                      register*/
        LucCanDlc = LpMsgBuffer8bit->ucFcnMmDtlgb;
        /* Get the local copy of DLC length */
        LucDlc = LucCanDlc;
        /* Get the pointer to message data byte register */
        LpMsgDataBuffer = LpMsgBuffer8bit->aaDataBuffer;
        /* Get the start address of sdu pointer */
        LpCanSduPtr = &LaaCanSdu[CAN_ZERO];
        /* Loop until the DLC length is equal to zero to copy data */
        while(LucDlc != CAN_ZERO)
        {
          /* Transfer the data from the corresponding message data byte
                                                                     register */
          *(LpCanSduPtr) = *(LpMsgDataBuffer);

          /* MISRA Rule         : 17.4
             Message             : Increment or decrement operation performed
                                   on pointer 'LpCanSduPtr'.
             Reason              : Increment operator is used to achieve
                                   better throughput.
             Verification        : However, part of the code is verified
                                   manually and it is not having any impact.
          */
          /*Increment the Sdu pointer */
          LpCanSduPtr++;
          /* MISRA Rule         : 17.4
             Message            : Performing pointer arithmetic
                                  on pointer 'LpMsgDataBuffer'.
             Reason             : Pointer arithmetic is performed to achieve
                                  better throughput.
             Verification       : However, part of the code is verified
                                  manually and it is not having any impact.
          */
          /*Increment the Message data buffer pointer */
          LpMsgDataBuffer += CAN_FOUR;
          /* Decrement the DLC length */
          LucDlc--;
        }
         /* Check whether both DN and MUC bits are cleared or not */
        if((LpMsgBuffer16bit->usFcnMmCtl & CAN_DN_MUC_BIT_STS) == CAN_ZERO)
        {
         /* Get the corresponding Hrh value from the message buffer */
         LucHrh= LunWordAccess.Tst_ByteAccess.ucHighByte + LucHrhOffSetId;
         #if (CAN_STANDARD_CANID == STD_OFF)
         /* Invoke CanIf_RxIndication call-back function to give receive
                                                                   indication */
         CanIf_RxIndication(LucHrh, Lun_Can_CanId.ulCanId, LucCanDlc,
         (P2CONST(uint8, AUTOMATIC, CAN_PRIVATE_CONST))&LaaCanSdu[CAN_ZERO]);
         #else
         /* Invoke CanIf_RxIndication call-back function to give receive
                                                                   indication */
         CanIf_RxIndication(LucHrh, Lun_Can_CanId.Tst_CanId.usCanIdLow,
         LucCanDlc,
         (P2CONST(uint8, AUTOMATIC, CAN_PRIVATE_CONST))&LaaCanSdu[CAN_ZERO]);
         #endif
         /* Set the Counter to zero to break the loop */
         LucCounter = CAN_ZERO;
        } /* if((LpMsgBuffer16bit->usFcnMmCtl & CAN_DN_MUC_BIT_STS) == 
                                                                    CAN_ZERO) */
      }while (LucCounter != CAN_ZERO);
    } /* if((LpMsgBuffer16bit->usFcnMmCtl & CAN_DN_MUC_BIT_STS) == 
                                                               CAN_DN_BIT_STS)*/

    /* Read the value of RGPT Register */
    LunWordAccess.usWord = (LpCntrlReg16bit->usFcnCmrgRx);
   /* Check whether receive history list is empty */
  }while(((LunWordAccess.Tst_ByteAccess.ucLowByte) & (CAN_RHPM_BIT_STS)) !=
                                                              CAN_RHPM_BIT_STS);
}

#define CAN_AFCAN_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
