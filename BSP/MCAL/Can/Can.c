/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can.c                                                       */
/* Version      = 3.0.6a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Initialization and Version Control Functionality.             */
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
 * V3.0.1:  10.10.2009  : DET Updated for supporting INVALID_DATABASE and
 *                        updated for changes in wake-up support as per
 *                        SCR ANMCANLINFR3_SCR_031.
 * V3.0.2:  20.01.2010  : Can_Init.c file renamed to Can.c as per
 *                        SCR ANMCANLINFR3_SCR_042.
 * V3.0.3:  21.04.2010  : As per ANMCANLINFR3_SCR_056,
 *                        1. Provision for Tied Wakeup interrupts is added.
 *                        2. MCONF and MIDH registers are write protected with
 *                           respective masks.
 * V3.0.4:  11.05.2010  : 1. CAN_MAX_NUMBER_OF_BASICCANHTH is replaced with
 *                        ucMaxNofBasicCanHth for multiple configuration support
 *                        as per ANMCANLINFR3_SCR_060.
 *                        2. "ddMask<xxx>Reg" are changed to "ucMask<xxx>Reg" as
 *                        per guidelines.
 * V3.0.5:  31.12.2010  : Can.h and CanIf_Cbk.h files are included
 *                        SCR ANMCANLINFR3_SCR_087.
 * V3.0.6:  20.06.2011  : As per SCR ANMCANLINFR3_SCR_107,
 *                        1. data width of interrupt control registers is  
 *                        changed from unit8 to unit16 in Can_Init().
 *                        2. Clearing of error counters of FCN procedure is  
 *                        implemented in API Can_Initcontroller().
 * V3.0.6a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can.h"              /* CAN Driver Header File */
#include "CanIf_Cbk.h"        /* CAN Interface call-back Header File */
#include "Can_PBTypes.h"      /* CAN Driver Post-Build Config. Header File */
#include "Can_Init.h"         /* CAN Initialization Header File */
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
#define CAN_INIT_C_AR_MAJOR_VERSION  2
#define CAN_INIT_C_AR_MINOR_VERSION  2
#define CAN_INIT_C_AR_PATCH_VERSION  2

/* File version information */
#define CAN_INIT_C_SW_MAJOR_VERSION  3
#define CAN_INIT_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CAN_INIT_AR_MAJOR_VERSION != CAN_INIT_C_AR_MAJOR_VERSION)
  #error "Can_Init.c : Mismatch in Specification Major Version"
#endif
#if (CAN_INIT_AR_MINOR_VERSION != CAN_INIT_C_AR_MINOR_VERSION)
  #error "Can_Init.c : Mismatch in Specification Minor Version"
#endif
#if (CAN_INIT_AR_PATCH_VERSION != CAN_INIT_C_AR_PATCH_VERSION)
  #error "Can_Init.c : Mismatch in Specification Patch Version"
#endif
#if (CAN_INIT_SW_MAJOR_VERSION != CAN_INIT_C_SW_MAJOR_VERSION)
  #error "Can_Init.c : Mismatch in Software Major Version"
#endif
#if (CAN_INIT_SW_MINOR_VERSION != CAN_INIT_C_SW_MINOR_VERSION)
  #error "Can_Init.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Can_Init
**
** Service ID         : 0x00
**
** Description        : This service initializes the static variables and CAN HW
**                      Unit global hardware settings for the further processing
**                      and initiates the setup of all CAN Controller specific
**                      settings.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : Config
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_GblCanStatus,Can_GpCntrlIdArray,Can_GpFirstHth,
**                      Can_GpFirstController,Can_GucLastHthId,Can_GucFirstHthId
**                      Can_GucLastCntrlId
**
**                      Function(s) invoked:
**                      Det_ReportError(), Dem_ReportErrorStatus()
**
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(void, CAN_AFCAN_PUBLIC_CODE)Can_Init
(P2CONST(Can_ConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST) Config)
{
  P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                          CAN_AFCAN_PRIVATE_CONST) LpController;
  P2CONST(Tdd_Can_AFCan_Hrh,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST) LpHrh;
  P2CONST(Tdd_Can_AFCan_Hth,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST) LpHth;
  P2VAR(Tdd_Can_AFCan_8bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                 LpCntrlReg8bit;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  P2VAR(Tdd_Can_AFCan_8bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_DATA)
                                                                LpMsgBuffer8bit;
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_DATA)
                                                               LpMsgBuffer16bit;
  P2VAR(Tdd_Can_AFCan_HwFilterMaskReg,AUTOMATIC,
                                         CAN_AFCAN_PRIVATE_DATA) LpHwFilterMask;
  P2CONST(Tdd_Can_AFCan_HwFilterMask,AUTOMATIC,
                                          CAN_AFCAN_PRIVATE_CONST) LpFilterMask;
  P2VAR(uint16,AUTOMATIC,CAN_AFCAN_CONFIG_DATA)LpIntCntrlReg;

  uint16_least LusTimeOutCount1;
  uint8_least LucNoOfController;
  uint8 LucCntrlCount;
  uint8_least LucCount;
  uint8_least LucMsgBufferCount;
  boolean LblErrFlag;

  #if  (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Initialize the error status flag to false */
  LblErrFlag = CAN_FALSE;
  /* Report to DET, if module is initialized */
  if(Can_GblCanStatus == CAN_INITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE, CAN_INIT_SID,
                                                              CAN_E_TRANSITION);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  /* Report to DET, if Config pointer is equal to Null */
  if (Config == NULL_PTR)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE, CAN_INIT_SID,
                                                           CAN_E_PARAM_POINTER);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  else
  {
    /* Report to DET, if database is not valid */
    if(Config->ulStartOfDbToc != CAN_DBTOC_VALUE)
    {
      /* Report to DET */
      Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE, CAN_INIT_SID,
                                                        CAN_E_INVALID_DATABASE);
      /* Set the error status flag to true */
      LblErrFlag = CAN_TRUE;
    }
  }
  /* Check whether any development error occurred */
  if(LblErrFlag != CAN_TRUE)
  #endif /*#if(CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Rule         : 1.2
       Message            : Dereferencing pointer value that is apparently
                            NULL.
       Reason             : "Config" pointer is checked and verified when
                            DET is switched STD_ON.
       Verification       : However, the part of the code is
                            verified manually and it is not having
                            any impact on code.
    */
    /* Get the index of first Hth configured */
    Can_GucFirstHthId = Config->ucFirstHthId;
    /* Get the pointer to first Controller structure */
    Can_GpFirstController = Config->pFirstController;

    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    /* Get the index of last Hth configured */
    Can_GucLastHthId = Config->ucLastHthId;
    /* Get the index of last Controller configured */
    Can_GucLastCntrlId = Config->ucLastCntrlId;
    #endif

    /* Get the pointer to first Hth structure */
    Can_GpFirstHth =(P2CONST(Tdd_Can_AFCan_Hth,AUTOMATIC,
                                     CAN_AFCAN_PRIVATE_CONST))Config->pFirstHth;
    /* Get the pointer to first Cntrl Id Array */
    Can_GpCntrlIdArray = Config->pCntrlIdArray;
    /* Get the number of Controllers into local variable */
    LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
    /* Get the pointer to first Controller structure */
    LpController = Can_GpFirstController;
    /* Initialize for number of controllers count */
    LucCntrlCount = CAN_ZERO;
    /* Loop for the number of controllers */
    do
    {
      /* Get the pointer to 8-bit control register structure */
      LpCntrlReg8bit = LpController->pCntrlReg8bit;
      /* Get the pointer to 16-bit control register structure */
      LpCntrlReg16bit = LpController->pCntrlReg16bit;
      /* Get the Timeout count value and store it in a local variable */
      LusTimeOutCount1 = CAN_TIMEOUT_COUNT;
      /* Initialize error flag to true */
      LblErrFlag = CAN_TRUE;
      /* Loop until GOM bit is cleared */
      do
      {
        /* Enable force shut down bit */
        LpCntrlReg16bit->usFcnGmclCtl = CAN_SET_EFSD;
        /* Disable the CAN module */
        LpCntrlReg16bit->usFcnGmclCtl = CAN_CLR_GOM;
        /* Decrement timeout count by one */
        LusTimeOutCount1--;
      }while((LpCntrlReg16bit->usFcnGmclCtl != CAN_ZERO) &&
                                                (LusTimeOutCount1 != CAN_ZERO));
      /* Check whether Timeout count is expired or not */
      if(LusTimeOutCount1 != CAN_ZERO)
      {
        /* Set error flag to false */
        LblErrFlag = CAN_FALSE;
        /* Set the CAN module system clock */
        LpCntrlReg8bit->ucFcnGmcsPre = CAN_SET_SYSTEM_CLOCK;
        /* Enable CAN module */
        LpCntrlReg16bit->usFcnGmclCtl = CAN_SET_GOM;
        /* Clear all interrupt flags of Interrupt Status register*/
        LpCntrlReg16bit->usFcnCmisCtl = CAN_CLR_ALL_INTERRUPT;
        /* Set CCERC bit to clear INFO and ERC registers */
        LpCntrlReg16bit->usFcnCmclCtl = CAN_SET_CCERC_BIT;
        /* Set the bit rate prescaler register */
        LpCntrlReg8bit->ucFcnCmbrPrs = LpController->ucBRP;
        /* Set the bit rate register */
        LpCntrlReg16bit->usFcnCmbtCtl = LpController->usBTR;
        /* Set interrupt enable register */
        LpCntrlReg16bit->usFcnCmieCtl = LpController->usIntEnable;

        /* Get the number of masks configured and store it in a local
           variable */
        LucCount = (LpController->ucNoOfFilterMask);
        /* Check whether any mask is configured or not */
        if (LucCount != CAN_ZERO)
        {
          /* Get the pointer to filter mask structure from Controller
             structure */
          LpFilterMask = LpController->pFilterMask;
          /* Get the pointer to the first filtermask from control register
             structure */
          LpHwFilterMask = LpCntrlReg16bit->ddHwFilterMask;
          /* Loop for the number of the masks configured */
          do
          {
            /* Set the Low Mask control register */
            LpHwFilterMask->ucFcnCmmkCtl01h = LpFilterMask->usMaskLow;
            /* Set the High Mask control register */
            LpHwFilterMask->ucFcnCmmkCtl02h = LpFilterMask->usMaskHigh;
            /* MISRA Rule         : 17.4
               Message            : Increment or decrement operation performed
                                    on pointer(LpHwFilterMask/LpFilterMask).
               Reason             : Increment operator is used to achieve
                                    better throughput.
               Verification       : However, part of the code is verified
                                    manually and it is not having any impact.
            */
            /* Increment the pointer to point to the next filter mask
               registers */
            LpHwFilterMask++;
            /* Increment the pointer to point to the next filter mask
               structure */
            LpFilterMask++;
            /* Decrement the number of masks count configured */
            LucCount--;
          }while(LucCount != CAN_ZERO);
        }/* if (LucCount != CAN_ZERO) */

        /* Get the pointer to first message buffer from 8-bit control register
           structure */
        LpMsgBuffer8bit = LpCntrlReg8bit->ddMsgBuffer;
        /* Get the pointer to first message buffer from 16-bit control register
           structure */
        LpMsgBuffer16bit = LpCntrlReg16bit->ddMsgBuffer;
        /* Get the number of CAN Message Buffers of the controller and store it
           in a local variable */
        LucCount = LpController->ucMaxNoOfMsgBufs;
        /* Get the no. of Hrh configured and store it in a local variable */
        LucMsgBufferCount = LpController->ucNoOfHrh;
        /* Check whether any Hrh is configured or not */
        if(LucMsgBufferCount != CAN_ZERO)
        {
          /* Get the pointer to first Hrh from Controller structure */
          LpHrh = (P2CONST(Tdd_Can_AFCan_Hrh,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST))
                                                           LpController->pHrh;
          /* Loop for the number of Hrh configured */
          do
          {
            /* Get the Timeout count value and store it in a local variable */
            LusTimeOutCount1 = CAN_TIMEOUT_COUNT;
            /* Clear control  bit */
            LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_CTRL_BIT;
            /* Loop until RDY bit is cleared or Timeout count expired */
            do
            {
              /* Decrement the Timeout count */
              LusTimeOutCount1--;
              /* Check whether RDY bit is cleared and Timeout count is
                 expired or not */
            }while(((LpMsgBuffer16bit->usFcnMmCtl & CAN_RDY_BIT_STS) !=
                                   CAN_ZERO) && (LusTimeOutCount1 != CAN_ZERO));
            /* Check whether Timeout count is expired or not */
            if (LusTimeOutCount1 != CAN_ZERO)
            {
              /*
                Check whether the configured CAN-ID is Standard or Extended
              */
              #if(CAN_STANDARD_CANID == STD_OFF)
              /* Set the Extended CAN-ID Higher bit - 16 to 28 */
              LpMsgBuffer16bit->usFcnMmMid1h = LpHrh->usCanIdHigh &
                                                              CAN_MIDH_REG_MASK;
              /* Set the Extended CAN-ID Lower bit - 0 to 15 */
              LpMsgBuffer16bit->usFcnMmMid0h = LpHrh->usCanIdLow;
              #else
              /* Set the Standard CAN-ID Higher bit - 18 to 28 */
              LpMsgBuffer16bit->usFcnMmMid1h = LpHrh->usCanIdHigh &
                                                              CAN_MIDH_REG_MASK;
              #endif /* #if(CAN_STANDARD_CANID == OFF) */
              /* Set the message buffer type */
              LpMsgBuffer8bit->ucFcnMmStrb = LpHrh->ucMConfigReg &
                                                             CAN_MCONF_REG_MASK;
              /* Enable message buffer interrupt request bit */
              LpMsgBuffer16bit->usFcnMmCtl = CAN_SET_MBUF_INT_EN;
              /* Set RDY bit */
              LpMsgBuffer16bit->usFcnMmCtl = CAN_SET_RDY_BIT;
              /* MISRA Rule         : 17.4
                 Message            : Increment or decrement operation
                                      performed on pointer(LpHrh/LpMsgBuffer).
                 Reason             : Increment operator is used to achieve
                                      better throughput.
                 Verification       : However, part of the code is verified
                                      manually and it is not having any
                                      impact.
              */
              /* Increment the pointer to point to next Hrh structure */
              LpHrh++;
              /* Increment the pointer to point to next 8-bit message buffer
                 structure */
              LpMsgBuffer8bit++;
              /* Increment the pointer to point to next 16-bit message buffer
                 structure */
              LpMsgBuffer16bit++;
              /* Decrement the number of Hrh count configured */
              LucMsgBufferCount--;
              /* Decrement LucCount by one */
              LucCount--;
            } /* if (LusTimeOutCount1 != CAN_ZERO) */
            else
            {
              /* Set the Hrh count to zero to break the loop */
              LucMsgBufferCount = CAN_ZERO;
              /* Report to DEM  for hardware failure */
              Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
              /* Set the error flag status to true */
              LblErrFlag = CAN_TRUE;
            }
          }while(LucMsgBufferCount != CAN_ZERO);
        } /* if(LucCount != CAN_ZERO) */
        /* Get the number of Hth configured and store it in a local variable*/
        LucMsgBufferCount = LpController->ucNoOfHth;
        /* Check whether any Hth configured and any error message occurred */
        if((LucMsgBufferCount != CAN_ZERO) && (LblErrFlag != CAN_TRUE))
        {
          /* Get the pointer to first Hth from Controller structure */
          LpHth = (P2CONST(Tdd_Can_AFCan_Hth,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST))
                                                          LpController->pHth;
          /* Loop for the number of Hth configured */
          do
          {
            /* Get the Timeout count value and store it in a local variable */
            LusTimeOutCount1 = CAN_TIMEOUT_COUNT;
            /* Clear RDY bit */
            LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_CTRL_BIT;
            /* Loop until RDY bit cleared or Timeout count expired */
            do
            {
              /* Decrement the Timeout count */
              LusTimeOutCount1--;
              /* Check whether RDY bit is cleared and Timeout count is
                 expired or not */
            }while(((LpMsgBuffer16bit->usFcnMmCtl & CAN_RDY_BIT_STS) !=
                                   CAN_ZERO) && (LusTimeOutCount1 != CAN_ZERO));
            /* Check whether Timeout count is expired or not */
            if (LusTimeOutCount1 != CAN_ZERO)
            {
              /* Check whether Multiplexed transmission is on or not */
              #if (CAN_MULTIPLEX_TRANSMISSION == STD_ON)
              /* Set the global flag to zero */
              *(LpHth->pHwAccessFlag) = CAN_FALSE;
              #endif

              /* Set the message buffer type */
              LpMsgBuffer8bit->ucFcnMmStrb = CAN_SET_MSG_BUFFER_EN &
                                                             CAN_MCONF_REG_MASK;
              /* Enable message buffer interrupt request bit */
              LpMsgBuffer16bit->usFcnMmCtl = CAN_SET_MBUF_INT_EN;
              /* Set RDY bit */
              LpMsgBuffer16bit->usFcnMmCtl = CAN_SET_RDY_BIT;
              /* MISRA Rule         : 17.4
                 Message            : Increment or decrement operation
                                      performed on pointer(LpHth/LpMsgBuffer).
                 Reason             : Increment operator is used to achieve
                                      better throughput.
                 Verification       : However, part of the code is verified
                                      manually and it is not having any impact
              */
              /* Increment the pointer to point to the next Hth structure */
              LpHth++;
              /* Increment the 8-bit message buffer register */
              LpMsgBuffer8bit++;
              /* Increment the 16-bit message buffer register */
              LpMsgBuffer16bit++;
              /* Decrement the count */
              LucCount--;
              /* Decrement the number of Hth count configured */
              LucMsgBufferCount--;
            }
            else
            {
              /* Set the Hth count to zero to break the loop */
              LucMsgBufferCount = CAN_ZERO;
              /* Report to DEM */
              Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
              /* Set the error flag status to true */
              LblErrFlag = CAN_TRUE;
            }
          }while( LucMsgBufferCount != CAN_ZERO);
        }  /* if(LucCount != CAN_ZERO) */
        /* Loop to disable all the message buffers during initialization */
        while((LucCount != CAN_ZERO) && (LblErrFlag != CAN_FALSE))
        {
          /* Clear RDY,DN,TRQ,IE and MOW Bit */
          LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_CTRL_BIT;
          /* Get the Timeout count value and store it in a local variable */
          LusTimeOutCount1 = CAN_TIMEOUT_COUNT;
          /* Loop until RDY bit is cleared or Timeout count is expired */
          do
          {
            /* Decrement the Timeout Count */
            LusTimeOutCount1--;
            /* Check whether RDY bit is cleared and Timeout count is expired
                                                                      or not*/
          } while(((LpMsgBuffer16bit->usFcnMmCtl & CAN_RDY_BIT_STS) != CAN_ZERO)
                                             && (LusTimeOutCount1 != CAN_ZERO));
          /* Disable the message buffer */
          LpMsgBuffer8bit->ucFcnMmStrb = CAN_MSG_BUFFER_DISABLE &
                                                             CAN_MCONF_REG_MASK;
          /* MISRA Rule         : 17.4
             Message            : Increment or decrement operation
                                  performed on pointer(LpMsgBuffer).
             Reason             : Increment operator is used to achieve
                                  better throughput.
             Verification       : However, part of the code is verified
                                  manually and it is not having any impact.
          */
          /* Increment the pointer to point to next 8-bit message buffer */
          LpMsgBuffer8bit++;
          /* Increment the pointer to point to next 16-bit message buffer */
          LpMsgBuffer16bit++;
          /* Decrement the message buffer count */
          LucCount--;
        }
      }
      /* Check whether the error flag is false or not */
      if(LblErrFlag == CAN_FALSE)
      {
        /* Initialize Interrupt Counter to zero */
        Can_GucIntCounter[LucCntrlCount] = CAN_ZERO;
        #if  (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Set the Controller to stop mode */
        *(LpController->pCntrlMode) = (uint8)CAN_T_STOP;
        #endif /*#if(CAN_DEV_ERROR_DETECT == STD_ON) */
        /* Enable protection for exclusive area */
        SchM_Enter_Can(CAN_INTERRUPT_CONTROL_PROTECTION_AREA);
        /* Get the pointer to ICR register */
        LpIntCntrlReg = (LpController->pIntCntrlReg);
        /* Enable error interrupt in EIC if bus-off configured */
        *LpIntCntrlReg &= (LpController->usMaskERRReg);
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
        /*  Enable receive interrupt in EIC if configured */
        *LpIntCntrlReg &= (LpController->usMaskRECReg);
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
        *LpIntCntrlReg &= (LpController->usMaskTRXReg);
        /* Get the pointer to wake-up ICR register */
        LpIntCntrlReg = (LpController->pWupIntCntrlReg);
        /* Enable wake-up interrupt in EIC if configured */
        *LpIntCntrlReg &= (LpController->usMaskWUPReg);
        /* Disable protection for exclusive area */
        SchM_Exit_Can(CAN_INTERRUPT_CONTROL_PROTECTION_AREA);
      }
      /* Check whether the error status flag is true or not */
      else
      {
        /* Report to DEM */
        Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
      }
      /* Decrement the number of Controller */
      LucNoOfController--;
      /* MISRA Rule         : 17.4
         Message            : Increment or decrement operation
                              performed on pointer(LpController).
         Reason             : Increment operator is used to achieve
                              better throughput.
         Verification       : However, part of the code is verified
                              manually and it is not having any impact.
      */
      /* Increment the pointer to point to the next Controller structure */
      LpController++;
      /* Increment LucCntrlCount by one */
      LucCntrlCount++;
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
      /* Check whether the number of Controller equals to zero and error flag is
                                                                  true or not */
    }while((LucNoOfController != CAN_ZERO) && (LblErrFlag == CAN_FALSE));

    #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
    /* Set local counter start count as zero */
    LucCount = CAN_ZERO;
    /* Check for maximum number of TxCancel counter */
    while(LucCount <= (((Config->ucMaxNofBasicCanHth) - CAN_ONE) >> CAN_THREE))
    {
      /* Initialize TxCancel counter to zero */
      Can_GaaTxCancelCtr[LucCount] = CAN_ZERO;
      /* Increment local counter */
      LucCount++;
    }
    /* Initialize TxCancel Interrupt Flag to false */
    Can_GblTxCancelIntFlg = CAN_FALSE;
    #endif
    /* Check whether the error flag is false or not */
    if(LblErrFlag == CAN_FALSE)
    {
      /* Set the CAN status as initialized */
      Can_GblCanStatus = CAN_INITIALIZED;
    }
  }/* if(LblErrFlag != CAN_TRUE) */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_Initcontroller
**
** Service ID         : 0x02
**
** Description        : This service executes CAN Controller (re)initialization.
**                      A logical number is assigned to each set statically. The
**                      parameter *Config selects the configuration set that is
**                      used for initialization .
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : Controller, Config
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : CanDriver module must be initialized.
**
** Remarks            : Global Variable(s) referred in this function:
**                      Can_GblCanStatus, Can_GpFirstController
**                      Can_GucLastCntrlId
**
**                      Function(s) invoked:
**                      Det_ReportError()
*
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(void, CAN_AFCAN_PUBLIC_CODE) Can_InitController (uint8 Controller,
      P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST) Config)
{
  P2CONST(Can_ControllerConfigType,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                   LpController;
  P2VAR(Tdd_Can_AFCan_8bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                 LpCntrlReg8bit;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  P2VAR(Tdd_Can_AFCan_HwFilterMaskReg,AUTOMATIC,
                                         CAN_AFCAN_PRIVATE_DATA) LpHwFilterMask;
  P2CONST(Tdd_Can_AFCan_HwFilterMask,AUTOMATIC,
                                          CAN_AFCAN_PRIVATE_CONST) LpFilterMask;
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_DATA)
                                                               LpMsgBuffer16bit;
  P2VAR(Tdd_Can_AFCan_8bit_MsgBuffer,AUTOMATIC,CAN_AFCAN_PRIVATE_DATA)
                                                                LpMsgBuffer8bit;
  P2CONST(Tdd_Can_AFCan_Hrh,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST) LpHrh;
  P2CONST(Tdd_Can_AFCan_Hth,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST) LpHth;
  #if  (CAN_DEV_ERROR_DETECT == STD_ON)
  boolean LblErrFlag;
  #endif
  uint16_least LusTimeOutCount, LusTimeOutCount1;
  uint16 LusElevenDbtCount;
  uint8 LucCount;
  uint8_least LucMsgBufferCount;

  #if  (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Initialize the error status flag to false */
  LblErrFlag = CAN_FALSE;
  /* Report to DET, if Config pointer is equal to Null */
  if (Config == NULL_PTR)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                        CAN_INIT_CNTRL_SID,CAN_E_PARAM_POINTER);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  /* Report to DET, if module is not initialized */
  if (Can_GblCanStatus == CAN_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                              CAN_INIT_CNTRL_SID, CAN_E_UNINIT);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  /* Report to DET,if the Controller Id is out of range */
  else if (Controller > Can_GucLastCntrlId)
  {
    /* Report to DET */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                    CAN_INIT_CNTRL_SID, CAN_E_PARAM_CONTROLLER);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
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
                                    CAN_INIT_CNTRL_SID, CAN_E_PARAM_CONTROLLER);
       /* Set the error status flag to true */
      LblErrFlag = CAN_TRUE;
    }
    else
    {
      /* Get the pointer to Controller structure */
      LpController = &Can_GpFirstController[Controller];
      /* Check whether the Controller is in stop mode */
      if(*(LpController->pCntrlMode) != (uint8)CAN_T_STOP)
      {
        /* Report to DET */
        Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                          CAN_INIT_CNTRL_SID, CAN_E_TRANSITION);
        /* Set the error status flag to true */
        LblErrFlag = CAN_TRUE;
      } /* if(*(LpController->pCntrlMode) != (uint8)CAN_T_STOP) */
    }
  }
  /* Check whether any development error occurred */
  if(LblErrFlag != CAN_TRUE)
  #endif /* #if(CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    #if  (CAN_DEV_ERROR_DETECT == STD_OFF)
    /* Get the Controller Index value */
    Controller = Can_GpCntrlIdArray[Controller];
    /* Get the pointer to Controller structure */
    LpController = &Can_GpFirstController[Controller];
    #endif
    /*  MISRA Rule         :  9.1
        Message            :  The variable(LpController) may be unset at this
                              point.
        Reason             :  This is to achieve throughput in the code.
        Verification       :  It is assured that variable is initialized
                              correctly before actually being used by the
                              embedded portion.
    */
    /* Get the pointer to 8-bit control register structure */
    LpCntrlReg8bit = LpController->pCntrlReg8bit;
    /* Get the pointer to 16-bit control register structure */
    LpCntrlReg16bit = LpController->pCntrlReg16bit;
    /* Get the pointer to first message buffer from 16-bit control register
           structure */
    LpMsgBuffer16bit = LpCntrlReg16bit->ddMsgBuffer;
    
    /* Stop Automatic block transmission */
    LpCntrlReg16bit->usFcnGmabCtl = CAN_CLR_ABT_BIT;
    /* Get the Timeout count value and store it in a local variable */
      LusTimeOutCount = CAN_TIMEOUT_COUNT;
    /* Loop until ABTT bit is cleared */
    do
    {
      /* Decrement the Timeout count */
      LusTimeOutCount--;
      /* Check whether ABTT bit is cleared and Timeout count is
                 expired or not */
    }while(((LpCntrlReg16bit->usFcnGmabCtl & CAN_CLR_ABT_BIT) != 
                                    CAN_ZERO) && (LusTimeOutCount != CAN_ZERO));
    /* Check whether Timeout count is expired or not */
    if (LusTimeOutCount != CAN_ZERO)
    {
      /* Clear TRQ bit to start cancellation of pending messages */
      LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_TRQ_BIT;
      /* Get the DBT count value and store it in a local variable */
      LusElevenDbtCount = CAN_ELEVEN_DBT_COUNT;
      /* Wait for 11 CAN data bits */
      do
      {
        LusElevenDbtCount--;
      }while(LusElevenDbtCount != CAN_ZERO);
      /* Get the Timeout count value and store it in a local variable */
      LusTimeOutCount = CAN_TIMEOUT_COUNT;
      /* Loop until ABTT bit is cleared */
      do
      {
        /* Decrement the Timeout Count */
        LusTimeOutCount--;
        /* Check whether Transmission progress bit is cleared and Timeout count 
                                                             is expired or not*/
      }while(((LpCntrlReg16bit->usFcnCmclCtl & CAN_TRANSMISSION_STS) != 
                                    CAN_ZERO) && (LusTimeOutCount != CAN_ZERO));
      /* Check whether Timeout count is expired or not */
      if(LusTimeOutCount != CAN_ZERO)
      {
        /* Set the operation mode as initialization mode */
        LpCntrlReg16bit->usFcnCmclCtl = CAN_SET_INIT_OPMODE;
        
        /* Get the Timeout count value and store it in a local variable */
        LusTimeOutCount = CAN_TIMEOUT_COUNT;
        /* Loop to clear to INIT mode */
        do
        {
          /* Decrement the TimeoutCount */
         LusTimeOutCount--;
          /* Check whether initialization mode is set and Timeout count is 
                                                               expired or not */
        }while(((LpCntrlReg16bit->usFcnCmclCtl & CAN_SET_INIT_OPMODE) != 
                                    CAN_ZERO) && (LusTimeOutCount != CAN_ZERO));
        /* Check whether TimeOutCount is equal to zero */
        if(LusTimeOutCount != CAN_ZERO)
        {
          /* Disable CAN module */
          LpCntrlReg16bit->usFcnGmclCtl = CAN_CLR_GOM;
          if((LpCntrlReg16bit->usFcnGmclCtl & CAN_CLR_GOM) == CAN_CLR_GOM)
          {
            /* Enable Forced shutdown of CAN module */
            LpCntrlReg16bit->usFcnGmclCtl = CAN_SET_EFSD;
            /* Disable the CAN module */
            LpCntrlReg16bit->usFcnGmclCtl = CAN_CLR_GOM;
            /* Decrement timeout count by one */
          }
          /* Enable CAN module */
          LpCntrlReg16bit->usFcnGmclCtl = CAN_SET_GOM;
          
          /* Get the pointer to first message buffer from 8-bit control register
                               structure */
          LpMsgBuffer8bit = LpCntrlReg8bit->ddMsgBuffer;
          /* Get the pointer to first message buffer from 16-bit control register
                               structure */
          LpMsgBuffer16bit = LpCntrlReg16bit->ddMsgBuffer;
          /* Get the number of CAN Message Buffers of the controller and store it
                                in a local variable */
          LucCount = LpController->ucMaxNoOfMsgBufs;
          /* Get the no. of Hrh configured and store it in a local variable */
          LucMsgBufferCount = LpController->ucNoOfHrh;
          /* Check whether any Hrh is configured or not */
          if(LucMsgBufferCount != CAN_ZERO)
          {
            /* Get the pointer to first Hrh from Controller structure */
            LpHrh = (P2CONST(Tdd_Can_AFCan_Hrh,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST))
                                                           LpController->pHrh;
            /* Loop for the number of Hrh configured */
            do
            {
              /* Get the Timeout count value and store it in a local variable */
              LusTimeOutCount1 = CAN_TIMEOUT_COUNT;
              /* Clear control  bit */
              LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_CTRL_BIT;
              /* Loop until RDY bit is cleared or Timeout count expired */
              do
              {
                /* Decrement the Timeout count */
                LusTimeOutCount1--;
                /* Check whether RDY bit is cleared and Timeout count is
                                            expired or not */
              }while(((LpMsgBuffer16bit->usFcnMmCtl & CAN_RDY_BIT_STS) !=
                                   CAN_ZERO) && (LusTimeOutCount1 != CAN_ZERO));
              /* Check whether Timeout count is expired or not */
              if (LusTimeOutCount1 != CAN_ZERO)
              {
                /*  Check whether the configured CAN-ID is Standard or Extended  */
                #if(CAN_STANDARD_CANID == STD_OFF)
                /* Set the Extended CAN-ID Higher bit - 16 to 28 */
                LpMsgBuffer16bit->usFcnMmMid1h = LpHrh->usCanIdHigh &
                                                              CAN_MIDH_REG_MASK;
                /* Set the Extended CAN-ID Lower bit - 0 to 15 */
                LpMsgBuffer16bit->usFcnMmMid0h = LpHrh->usCanIdLow;
                #else
                /* Set the Standard CAN-ID Higher bit - 18 to 28 */
                LpMsgBuffer16bit->usFcnMmMid1h = LpHrh->usCanIdHigh &
                                                              CAN_MIDH_REG_MASK;
                #endif /* #if(CAN_STANDARD_CANID == OFF) */
                /* Set the message buffer type */
                LpMsgBuffer8bit->ucFcnMmStrb = LpHrh->ucMConfigReg &
                                                             CAN_MCONF_REG_MASK;
                /* Enable message buffer interrupt request bit */
                LpMsgBuffer16bit->usFcnMmCtl = CAN_SET_MBUF_INT_EN;
                /* Set RDY bit */
                LpMsgBuffer16bit->usFcnMmCtl = CAN_SET_RDY_BIT;
                /* MISRA Rule         : 17.4
                   Message            : Increment or decrement operation
                                        performed on pointer(LpHrh/LpMsgBuffer).
                   Reason             : Increment operator is used to achieve
                                        better throughput.
                   Verification       : However, part of the code is verified
                                        manually and it is not having any
                                        impact.
                */
                /* Increment the pointer to point to next Hrh structure */
                LpHrh++;
                /* Increment the pointer to point to next 8-bit message buffer
                                               structure */
                LpMsgBuffer8bit++;
                /* Increment the pointer to point to next 16-bit message buffer
                                                structure */
                LpMsgBuffer16bit++;
                /* Decrement the number of Hrh count configured */
                LucMsgBufferCount--;
                /* Decrement LucCount by one */
                LucCount--;
              } /* if (LusTimeOutCount1 != CAN_ZERO) */
              else
              {
                /* Set the Hrh count to zero to break the loop */
                LucMsgBufferCount = CAN_ZERO;
                /* Report to DEM  for hardware failure */
                Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
              }
            }while(LucMsgBufferCount != CAN_ZERO);
          } /* if(LucCount != CAN_ZERO) */
          /* Get the number of Hth configured and store it in a local variable*/
          LucMsgBufferCount = LpController->ucNoOfHth;
          /* Check whether any Hth configured and any error message occurred */
          if(LucMsgBufferCount != CAN_ZERO)
          {
            /* Get the pointer to first Hth from Controller structure */
            LpHth = (P2CONST(Tdd_Can_AFCan_Hth,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST))
                                                          LpController->pHth;
            /* Loop for the number of Hth configured */
            do
            {
              /* Get the Timeout count value and store it in a local variable */
              LusTimeOutCount1 = CAN_TIMEOUT_COUNT;
              /* Clear RDY bit */
              LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_CTRL_BIT;
              /* Loop until RDY bit cleared or Timeout count expired */
              do
              {
                /* Decrement the Timeout count */
                LusTimeOutCount1--;
                /* Check whether RDY bit is cleared and Timeout count is
                                                 expired or not */
              }while(((LpMsgBuffer16bit->usFcnMmCtl & CAN_RDY_BIT_STS) !=
                                   CAN_ZERO) && (LusTimeOutCount1 != CAN_ZERO));
              /* Check whether Timeout count is expired or not */
              if (LusTimeOutCount1 != CAN_ZERO)
              {
                /* Check whether Multiplexed transmission is on or not */
                #if (CAN_MULTIPLEX_TRANSMISSION == STD_ON)
                /* Set the global flag to zero */
                *(LpHth->pHwAccessFlag) = CAN_FALSE;
                #endif

                /* Set the message buffer type */
                LpMsgBuffer8bit->ucFcnMmStrb = CAN_SET_MSG_BUFFER_EN &
                                                             CAN_MCONF_REG_MASK;
                /* Enable message buffer interrupt request bit */
                LpMsgBuffer16bit->usFcnMmCtl = CAN_SET_MBUF_INT_EN;
                /* Set RDY bit */
                LpMsgBuffer16bit->usFcnMmCtl = CAN_SET_RDY_BIT;
                /* MISRA Rule         : 17.4
                   Message            : Increment or decrement operation
                                        performed on pointer(LpHth/LpMsgBuffer).
                   Reason             : Increment operator is used to achieve
                                        better throughput.
                   Verification       : However, part of the code is verified
                                        manually and it is not having any impact
                */
                /* Increment the pointer to point to the next Hth structure */
                LpHth++;
                /* Increment the 8-bit message buffer register */
                LpMsgBuffer8bit++;
                /* Increment the 16-bit message buffer register */
                LpMsgBuffer16bit++;
                /* Decrement the count */
                LucCount--;
                /* Decrement the number of Hth count configured */
                LucMsgBufferCount--;
              }
              else
              {
                /* Set the Hth count to zero to break the loop */
                LucMsgBufferCount = CAN_ZERO;
                /* Report to DEM */
                Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
              }
            }while( LucMsgBufferCount != CAN_ZERO);
          }  /* if(LucCount != CAN_ZERO) */
          /* Loop to disable all the message buffers during initialization */
          while(LucCount != CAN_ZERO)
          {
            /* Clear RDY,DN,TRQ,IE and MOW Bit */
            LpMsgBuffer16bit->usFcnMmCtl = CAN_CLR_CTRL_BIT;
            /* Get the Timeout count value and store it in a local variable */
            LusTimeOutCount1 = CAN_TIMEOUT_COUNT;
            /* Loop until RDY bit is cleared or Timeout count is expired */
            do
            {
              /* Decrement the Timeout Count */
              LusTimeOutCount1--;
              /* Check whether RDY bit is cleared and Timeout count is expired
                                                                      or not*/
            } while(((LpMsgBuffer16bit->usFcnMmCtl & CAN_RDY_BIT_STS) != CAN_ZERO)
                                             && (LusTimeOutCount1 != CAN_ZERO));
            /* Disable the message buffer */
            LpMsgBuffer8bit->ucFcnMmStrb = CAN_MSG_BUFFER_DISABLE &
                                                             CAN_MCONF_REG_MASK;
            /* MISRA Rule         : 17.4
               Message            : Increment or decrement operation
                                    performed on pointer(LpMsgBuffer).
               Reason             : Increment operator is used to achieve
                                    better throughput.
               Verification       : However, part of the code is verified
                                    manually and it is not having any impact.
            */
            /* Increment the pointer to point to next 8-bit message buffer */
            LpMsgBuffer8bit++;
            /* Increment the pointer to point to next 16-bit message buffer */
            LpMsgBuffer16bit++;
            /* Decrement the message buffer count */
            LucCount--;
          }         
          /* Set CCERC bit to clear INFO and ERC registers */
          LpCntrlReg16bit->usFcnCmclCtl = CAN_SET_CCERC_BIT;
          /* Set the bit rate prescaler register */
          LpCntrlReg8bit->ucFcnCmbrPrs = LpController->ucBRP;
          /* Set the bit rate register */
          LpCntrlReg16bit->usFcnCmbtCtl = LpController->usBTR;
          /* Clear all interrupt flags of Interrupt Status register*/
          LpCntrlReg16bit->usFcnCmisCtl = CAN_CLR_ALL_INTERRUPT;
          /* Set interrupt enable register */
          LpCntrlReg16bit->usFcnCmieCtl = LpController->usIntEnable;
          /* Get the number of masks configured and store it in a local
                                                                     variable */
          LucCount = (LpController->ucNoOfFilterMask);
          /* Check whether any mask is configured or not */
          if (LucCount != CAN_ZERO)
          {
            /* Get the pointer to filter mask structure from Controller
                                                                    structure */
            LpFilterMask = LpController->pFilterMask;
            /* Get the pointer to the first filtermask from control register
                                                                    structure */
            LpHwFilterMask = LpCntrlReg16bit->ddHwFilterMask;
            /* Loop for the number of the masks configured */
            do
            {
              /* Set the Low Mask control register */
              LpHwFilterMask->ucFcnCmmkCtl01h = LpFilterMask->usMaskLow;
              /* Set the High Mask control register */
              LpHwFilterMask->ucFcnCmmkCtl02h = LpFilterMask->usMaskHigh;
              /* MISRA Rule         : 17.4
                 Message            : Increment or decrement operation performed
                                      on pointer(LpHwFilterMask/LpFilterMask).
                 Reason             : Increment operator is used to achieve
                                      better throughput.
                 Verification       : However, part of the code is verified
                                      manually and it is not having any impact.
              */
              /* Increment the pointer to point to the next filter mask
                                                                    registers */
              LpHwFilterMask++;
              /* Increment the pointer to point to the next filter mask
                                                                    structure */
              LpFilterMask++;
              /* Decrement the number of masks count configured */
              LucCount--;
            }while(LucCount != CAN_ZERO);
          }/* if (LucCount != CAN_ZERO) */ 
        }
        else
        {
          /* Report to DEM  for hardware failure */
          Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
        }
      }
      else
      {
        /* Report to DEM  for hardware failure */
       Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
      }
    } /* if (LusTimeOutCount1 != CAN_ZERO) */
    else
    {
      /* Report to DEM  for hardware failure */
       Dem_ReportErrorStatus(CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);  
    }
  }
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Can_GetVersionInfo
**
** Service ID         : 0x07
**
** Description        : This service returns the version information of this
**                      module.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : versioninfo
**
** Return parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable(s) referred in this function:
**                      None
**
**                      Function(s) invoked:
**                      Det_ReportError()
**
*******************************************************************************/

#if (CAN_VERSION_INFO_API == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(void,CAN_AFCAN_PUBLIC_CODE) Can_GetVersionInfo
        (P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_AFCAN_APPL_DATA) versioninfo)
{
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
 /* Report to DET, if versioninfo pointer is equal to Null */
  if(versioninfo == NULL_PTR)
  {
    /* Report to DET  */
    Det_ReportError(CAN_MODULE_ID_VALUE, CAN_INSTANCE_ID_VALUE,
                                  CAN_GET_VERSIONINFO_SID,CAN_E_PARAM_POINTER);
  }
  else
  #endif /*#if(CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = CAN_VENDOR_ID_VALUE;
    /* Copy the module Id */
    versioninfo->moduleID = CAN_MODULE_ID_VALUE;
     /* Copy the instance Id */
    versioninfo->instanceID = CAN_INSTANCE_ID_VALUE;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = CAN_SW_MAJOR_VERSION_VALUE;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = CAN_SW_MINOR_VERSION_VALUE;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = CAN_SW_PATCH_VERSION_VALUE;
  }
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
