/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_Write.c                                                 */
/* Version      = 3.0.6a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Transmission of L-PDU(s).                                                  */
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
 * V3.0.2:  20.01.2010  : Memory section for Can_TxCancel() is updated as per
 *                        SCR ANMCANLINFR3_SCR_042.
 * V3.0.3:  21.04.2010  : As per ANMCANLINFR3_SCR_056, DLC and MIDH registers
 *                        are write protected with respective masks.
 * V3.0.4:  28.07.2010  : As per ANMCANLINFR3_SCR_077, CAN_TRUE changed as 
 *                        CAN_INITIALIZED in line 194.
 * V3.0.5:  31.12.2010  : As per ANMCANLINFR3_SCR_087, space between
 *                         '#' and 'if' is removed.
 * V3.0.6:  20.06.2011  : As per ANMCANLINFR3_SCR_107, clearing RDY flag process
                          is moved into the do-while loop in Can_Write().
 * V3.0.6a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can_PBTypes.h"      /* CAN Driver Post-Build Config. Header File */
#include "Can_Write.h"        /* CAN Transmission Header File */
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
#define CAN_WRITE_C_AR_MAJOR_VERSION  2
#define CAN_WRITE_C_AR_MINOR_VERSION  2
#define CAN_WRITE_C_AR_PATCH_VERSION  2

/* File version information */
#define CAN_WRITE_C_SW_MAJOR_VERSION  3
#define CAN_WRITE_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CAN_WRITE_AR_MAJOR_VERSION != CAN_WRITE_C_AR_MAJOR_VERSION)
  #error "Can_Write.c : Mismatch in Specification Major Version"
#endif
#if (CAN_WRITE_AR_MINOR_VERSION != CAN_WRITE_C_AR_MINOR_VERSION)
  #error "Can_Write.c : Mismatch in Specification Minor Version"
#endif
#if (CAN_WRITE_AR_PATCH_VERSION != CAN_WRITE_C_AR_PATCH_VERSION)
  #error "Can_Write.c : Mismatch in Specification Patch Version"
#endif
#if (CAN_WRITE_SW_MAJOR_VERSION != CAN_WRITE_C_SW_MAJOR_VERSION)
  #error "Can_Write.c : Mismatch in Software Major Version"
#endif
#if (CAN_WRITE_SW_MINOR_VERSION != CAN_WRITE_C_SW_MINOR_VERSION)
  #error "Can_Write.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Can_Write
**
** Service ID         : 0x06
**
** Description        : This service writes the L-PDU in an appropriate buffer
**                      inside the CAN Controller hardware. The CAN Driver
**                      stores the swPduhandle that is given inside parameter
**                      PduInfo until it calls the CanIf_TxConfirmation.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Re-entrant
**
** Input Parameters   : Hth, PduInfo
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Can_ReturnType (CAN_OK / CAN_NOT_OK / CAN_BUSY)
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_GblCanStatus, Can_GucFirstHthId, Can_GucLastHthId,
**                      Can_GpFirstHth
**
**                    : Function(s) invoked:
**                      Det_ReportError(),SchM_Enter_Can(), SchM_Exit_Can(),
**                      Dem_ReportErrorStatus()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(Can_ReturnType, CAN_AFCAN_PUBLIC_CODE) Can_Write(uint8 Hth,
                  P2CONST(Can_PduType, AUTOMATIC, CAN_AFCAN_APPL_CONST) PduInfo)
{
  #if(CAN_STANDARD_CANID == STD_OFF)
  /*  MISRA Rule        : 18.4
      Message           : An object of union type has been defined.
      Reason            : Data access of larger data types is used to achieve
                          better throughput.
      Verification      : However, part of the code is verified manually and
                          it is not having any impact.
  */
  Tun_Can_AFCan_CanId Lun_Can_CanId;
  #endif
  P2CONST(Tdd_Can_AFCan_Hth,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)LpHth;
  P2VAR(Tdd_Can_AFCan_8bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_DATA)
                                                                LpMsgBuffer8bit;
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_DATA)
                                                               LpMsgBuffer16bit;
  P2VAR(uint8,AUTOMATIC, CAN_AFCAN_PRIVATE_DATA)LpCanSduPtr;
  P2VAR(uint8,AUTOMATIC, CAN_AFCAN_PRIVATE_DATA)LpMsgDataBuffer;
  Can_ReturnType LenCanReturnType;
  uint8 LucLength;
  uint16 LusTimeOutCount;
  #if(CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
  P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                          CAN_AFCAN_PRIVATE_CONST) LpController;
  boolean LblTxCancelStarted;
  #endif

  /* Initialize CanReturnType to CAN_BUSY */
  LenCanReturnType = CAN_BUSY;
  #if  (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if(Can_GblCanStatus != CAN_INITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE, CAN_WRITE_SID,
                                                                 CAN_E_UNINIT);
    /* Set CanReturnType to CAN_NOT_OK */
    LenCanReturnType = CAN_NOT_OK;
  }
  /* Report to DET, if Hth is out of range */
  else if((Hth < Can_GucFirstHthId) || (Hth > Can_GucLastHthId))
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE, CAN_WRITE_SID,
                                                            CAN_E_PARAM_HANDLE);
    /* Set CanReturnType to CAN_NOT_OK */
    LenCanReturnType = CAN_NOT_OK;
  }
  else
  {
    /* To avoid QAC warning */
  }
  /* Report to DET, if PduInfo pointer is  NULL */
  if (PduInfo == NULL_PTR)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE, CAN_WRITE_SID,
                                                           CAN_E_PARAM_POINTER);
    /* Set CanReturnType to CAN_NOT_OK */
    LenCanReturnType = CAN_NOT_OK;
  }
  /* Report to DET, if SduPtr is NULL */
  else if((PduInfo->sdu) == NULL_PTR)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE, CAN_WRITE_SID,
                                                           CAN_E_PARAM_POINTER);
    /* Set CanReturnType to CAN_NOT_OK */
    LenCanReturnType = CAN_NOT_OK;
  }
  /* Report to DET, if DLC length is more than eight byte */
  else if((PduInfo->length) > CAN_EIGHT)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE, CAN_WRITE_SID,
                                                               CAN_E_PARAM_DLC);
    /* Set CanReturnType to CAN_NOT_OK */
    LenCanReturnType = CAN_NOT_OK;
  }
  else
  {
    /* To avoid QAC warning */
  }
  /* Check whether any development error occurred */
  if(LenCanReturnType != CAN_NOT_OK)
  #endif
  {
    /* Get the Hth */
    Hth -= Can_GucFirstHthId;
    /* Get the pointer to the corresponding Hth structure */
    LpHth = &Can_GpFirstHth[Hth];
    /* Get the pointer to 8-bit message buffer register */
    LpMsgBuffer8bit = LpHth->pMsgBuffer8bit;
    /* Get the pointer to 16-bit message buffer register */
    LpMsgBuffer16bit = LpHth->pMsgBuffer16bit;
    /* Check whether transmit request is set */
    if((LpMsgBuffer16bit->usFcnMmCtl & CAN_TRQ_BIT_STS) != CAN_TRQ_BIT_STS)
    {
      #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
      /* Check whether Tx Cancellation of any message is in progress */
      if((Can_GblTxCancelIntFlg == CAN_FALSE) &&
         (Can_GaaTxCancelCtr[LpHth->ucController] == CAN_ZERO))
      #endif
      {
        /* Check whether Multiplexed transmission is on or not */
        #if (CAN_MULTIPLEX_TRANSMISSION == STD_ON)
        /* Check whether global flag for other hardware is already set or not */
        if(*(LpHth->pHwAccessFlag) != CAN_TRUE)
        #endif /*#if(CAN_MULTIPLEX_TRANSMISSION == STD_ON) */
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
          /* MISRA Rule         : 1.2
             Message            : Dereferencing pointer value that is apparently
                                  NULL.
             Reason             : "PduInfo" pointer is checked and verified when
                                  DET is switched STD_ON.
             Verification       : However, the part of the code is
                                  verified manually and it is not having
                                  any impact on code.
          */
          /* Store swPduHandle */
          *(LpHth->pCanTxPduId) = PduInfo->swPduHandle;
          /* Get the Timeout count value and store it in a local variable */
          LusTimeOutCount = CAN_TIMEOUT_COUNT;
          /* Loop until RDY bit cleared or Timeout count expired */
          do
          {
            /* Clear RDY bit to lock the buffer */
            LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_RDY_BIT;
           /* Decrement the Timeout count */
            LusTimeOutCount--;
           /* Check whether RDY bit is cleared and Timeout count is expired or
                                                                        not */
          } while(((LpMsgBuffer16bit->usFcnMmCtl & CAN_RDY_BIT_STS) != CAN_ZERO)
                                              && (LusTimeOutCount != CAN_ZERO));
          /* Check whether Timeout count is expired or not */
          if(LusTimeOutCount != CAN_ZERO)
          {
            /* Get the DLC length from PduInfo structure */
            LucLength = (PduInfo->length);
            /* Store the received DLC */
            LpMsgBuffer8bit->ucFcnMmDtlgb = LucLength & CAN_DLC_REG_MASK;
            /* Check whether the configured CAN-ID is Standard or Extended */
            #if(CAN_STANDARD_CANID == STD_OFF)
            Lun_Can_CanId.ulCanId = PduInfo->id;
            /* Check whether configured CAN-ID is Standard or Extended */
            if(((Lun_Can_CanId.ulCanId) & (CAN_SET_IDE_BIT)) != CAN_FALSE)
            {
              /* Set the Extended CAN-ID Higher bit - 16 to 28 */
              LpMsgBuffer16bit->usFcnMmMid1h =
                      (Lun_Can_CanId.Tst_CanId.usCanIdHigh) & CAN_MIDH_REG_MASK;
              /* Set the Extended CAN-ID Lower bit - 0 to 15 */
              LpMsgBuffer16bit->usFcnMmMid0h =
                                          (Lun_Can_CanId.Tst_CanId.usCanIdLow);
            }
            else
            {
              /* Set the Standard CAN-ID Higher bit - 18 to 28 */
              LpMsgBuffer16bit->usFcnMmMid1h = ((uint16)((PduInfo->id) <<
                                          (CAN_SHIFT_TWO))) & CAN_MIDH_REG_MASK;
            }
            #else
            /* Set the Standard CAN-ID Higher bit - 18 to 28 */
            LpMsgBuffer16bit->usFcnMmMid1h = ((uint16)((PduInfo->id) <<
                                          (CAN_SHIFT_TWO))) & CAN_MIDH_REG_MASK;
            #endif /* #if(CAN_STANDARD_CANID == STD_OFF) */

            /* Get the pointer to sdu from PduInfo structure */
            LpCanSduPtr = (PduInfo->sdu);
            /* Get the pointer to message data byte register */
            LpMsgDataBuffer = LpMsgBuffer8bit->aaDataBuffer;
            /* Loop until the DLC length is equal to zero to copy data */
            while(LucLength != CAN_ZERO)
            {
              /* Transfer the data to corresponding message data bye register */
              *LpMsgDataBuffer = *LpCanSduPtr;
              /* MISRA Rule         : 17.4
                 Message            : Performing pointer arithmetic
                                      on pointer 'LpMsgDataBuffer'.
                 Reason             : Pointer arithmetic is performed to achieve
                                      better throughput.
                 Verification       : However, part of the code is verified
                                      manually and it is not having any impact.
              */
              /* Increment the message buffer pointer to point to next
              message data byte register*/
              LpMsgDataBuffer += CAN_FOUR;
              /* MISRA Rule         : 17.4
                 Message            : Increment or decrement operation performed
                                      on pointer LpCanSduPtr.
                 Reason             : Increment operator is used to achieve
                                      better throughput.
                 Verification       : However, part of the code is verified
                                      manually and it is not having any impact.
              */
              /* Increment sdu pointer */
              LpCanSduPtr++;
              /*Decrement the DLC Length*/
              LucLength--;
            }
            /* Set RDY bit */
            LpMsgBuffer16bit->usFcnMmCtl = CAN_SET_RDY_BIT;
            /* Set TRQ bit */
            LpMsgBuffer16bit->usFcnMmCtl = CAN_SET_TRQ_BIT;
            /* Check whether Multiplexed transmission is on or not */
            #if (CAN_MULTIPLEX_TRANSMISSION == STD_ON)
             /* Disable global interrupts */
            SchM_Enter_Can(CAN_WRITE_PROTECTION_AREA);
            /* Set the global flag to zero */
            *(LpHth->pHwAccessFlag) = CAN_FALSE;
            /* Enable global interrupts */
            SchM_Exit_Can(CAN_WRITE_PROTECTION_AREA);
            #endif
            /* Set CanReturnType to CAN_OK */
            LenCanReturnType = CAN_OK;
          } /* if(LusTimeOutCount != CAN_ZERO) */
          else
          {
            /* Set CanReturn Type to CAN_NOT_OK */
            LenCanReturnType = CAN_NOT_OK;
            /* Report to DEM for timeout error */
            Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
          }
        } /* if(*(LpHth->pHwAccessFlag) == CAN_FALSE) */
      } /* if(Can_GaaTxCancelCtr = CAN_FALSE) */
    } /* if((LpMsgBuffer16bit->usFcnMmCtl & CAN_TRQ_BIT_STS) ==
                                                            CAN_TRQ_BIT_STS) */

    /* Check whether transmission cancellation is on or not */
    #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
    /* Check whether Transmission is pending for the Hth */
    else
    {
      /* Get the pointer to Controller structure */
      LpController = &Can_GpFirstController[LpHth->ucController];
      /* Check whether Interrupt bit of the Hth is enabled */
      if(((LpController->usIntEnable) & (CAN_TXCANCEL_INT_MASK)) ==
                                                          CAN_TXCANCEL_INT_MASK)
      {
        /* Check whether any Tx Cancellation is already in progress through
                                                  interrupt mode of operation */
        if(Can_GblTxCancelIntFlg == CAN_FALSE)
        {
          /* Invoke internal function to initiate Tx Cancellation, if the new
                         message has higher priority than the pending message */
          LblTxCancelStarted = Can_TxCancel(Hth, PduInfo);
          /* Set global Tx Cancel flag, if Tx Cancellation is started */
          if(LblTxCancelStarted == CAN_TRUE)
          {
            Can_GblTxCancelIntFlg = CAN_TRUE;
          }
        }
      }
      else
      {
        /* Invoke internal function to initiate Tx Cancellation, if the new
                         message has higher priority than the pending message */
        LblTxCancelStarted = Can_TxCancel(Hth, PduInfo);
        /* Increment global Tx Cancel counter of the controller, if
                                                  Tx Cancellation  is started */
        if((LblTxCancelStarted == CAN_TRUE) &&
                                           (Can_GblTxCancelIntFlg == CAN_FALSE))
        {
          Can_GaaTxCancelCtr[LpHth->ucController]++;
        }
      } /* End of check for Tx Cancel Interrupt */
    } /* End of else part of TRQ Bit check */
    #endif /* #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON) */
  } /* if(LenCanReturnType != CAN_NOT_OK) */
  return(LenCanReturnType); /* Return CanReturnType */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_TxCancel
**
** Service ID         : Not Applicable
**
** Description        : This service checks the priority of new message with the
**                      pending message and initiates transmit cancellation if
**                      it has high priority.
**
** Sync/Async         : None
**
** Re-entrancy        : Re-entrant
**
** Input Parameters   : LucHth, LpPduInfo
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : The CAN Driver must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_AFCan_GaaBasicCanHth[],
**                      Can_AFCan_GaaTxCancelStsFlgs[]
**
**                    : Function(s) invoked:
**                      SchM_Enter_Can(), SchM_Exit_Can()
**
*******************************************************************************/
#if(CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
#define CAN_AFCAN_START_SEC_PRIVATE_CODE
#include "MemMap.h"
FUNC(boolean, CAN_AFCAN_PRIVATE_CODE)Can_TxCancel(uint8 LucHth,
P2CONST(Can_PduType, AUTOMATIC, CAN_AFCAN_PRIVATE_CONST) LpPduInfo)
{
  P2CONST(Tdd_Can_AFCan_Hth,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)LpHth;
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_DATA)
                                                               LpMsgBuffer16bit;
  P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                          CAN_AFCAN_PRIVATE_CONST)LpController;
  #if(CAN_STANDARD_CANID == STD_OFF)
  /*  MISRA Rule        : 18.4
      Message           : An object of union type has been defined.
      Reason            : Data access of larger data types is used to achieve
                          better throughput.
      Verification      : However, part of the code is verified manually and
                          it is not having any impact.
  */
  Tun_Can_AFCan_CanId Lun_Can_CanId;
  #endif
  uint8_least LucCount;
  uint8_least LucArrPosition;
  boolean LblTxCancelFlag;

  /* Get the pointer to the corresponding Hth structure */
  LpHth = &Can_GpFirstHth[LucHth];
  /* Get the pointer to message buffer */
  LpMsgBuffer16bit = LpHth->pMsgBuffer16bit;
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LpHth->ucController];
  /* Get the array position for first BasicCAN Hth of this controller */
  LucArrPosition = LpController->ucBasicCanHthOffset;
  LucHth += Can_GucFirstHthId;
  /* Initialize the local Tx Cancel flag to false */
  LblTxCancelFlag = CAN_FALSE;
  /* Initialize the BasicCAN Hth count of the controller to zero */
  LucCount = CAN_ZERO;
  /* Loop as many times as the number of BasicCAN Hth of the controller */
  while(LucCount < (LpController->ucNoOfBasicCanHth))
  {
    /* Check whether the Hth of the controller is of BasicCAN type */
    if((LucHth == Can_AFCan_GaaBasicCanHth[LucArrPosition]) &&
      (*(LpHth->pHwAccessFlag) != CAN_TRUE))
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
      Lun_Can_CanId.ulCanId = LpPduInfo->id;
      /* Check whether configured CAN-ID is Standard or Extended */
      if(((Lun_Can_CanId.ulCanId) & (CAN_SET_IDE_BIT)) != CAN_FALSE)
      {
        /* Check whether the CAN-ID of new message is lower than the
                                                              pending message */
        if((Lun_Can_CanId.Tst_CanId.usCanIdHigh <=
          LpMsgBuffer16bit->usFcnMmMid1h) && (Lun_Can_CanId.Tst_CanId.usCanIdLow
          < LpMsgBuffer16bit->usFcnMmMid0h))
        {
          /* Set local Tx Cancel flag to start cancellation of low priority
                                                              pending message */
          LblTxCancelFlag = CAN_TRUE;
        }
      }
      else
      {
        Lun_Can_CanId.Tst_CanId.usCanIdHigh =
          ((Lun_Can_CanId.Tst_CanId.usCanIdHigh) << (CAN_SHIFT_TWO));
        /* Check whether the CAN-ID of new message is lower than the
                                                              pending message */
        if(Lun_Can_CanId.Tst_CanId.usCanIdHigh < LpMsgBuffer16bit->usFcnMmMid1h)
        {
          /* Set local Tx Cancel flag to start cancellation of low priority
                                                              pending message */
          LblTxCancelFlag = CAN_TRUE;
        }
      }
      #else
      /* Set the Standard CAN-ID Higher bit - 18 to 28 */
      if(((uint16)((LpPduInfo->id) << (CAN_SHIFT_TWO))) <
                                                LpMsgBuffer16bit->usFcnMmMid1h)
      {
        /* Set local Tx Cancel flag to start cancellation of low priority
                                                              pending message */
        LblTxCancelFlag = CAN_TRUE;
      }
      #endif /* #if(CAN_STANDARD_CANID == STD_OFF) */
      if(LblTxCancelFlag == CAN_TRUE)
      {
        /* Clear TRQ bit to start cancellation of pending message in the
                                                               message buffer */
        LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_TRQ_BIT;
        /* Set the Tx Cancellation Status flag of the Hth */
        Can_AFCan_GaaTxCancelStsFlgs[(LucArrPosition >> CAN_THREE)] |=
                                     (uint8)(CAN_ONE << (LucCount % CAN_EIGHT));
        /* Set the BasicCAN Hth count to maximum to exit the while loop */
        LucArrPosition = LpController->ucNoOfBasicCanHth;
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
    } /* if(Hth != Can_AFCan_GaaBasicCanHth[LucCount]) */
    /* Increment the array position to point to next BasicCAN Hth of the
                                                                   controller */
    LucArrPosition++;
    /* Increment BasicCAN Hth count of the controller */
    LucCount++;
  } /* while(LucCount < Can_GucNoOfBasicCanHth) */
  return(LblTxCancelFlag); /* Return LblTxCancelFlag */
}
#define CAN_AFCAN_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
