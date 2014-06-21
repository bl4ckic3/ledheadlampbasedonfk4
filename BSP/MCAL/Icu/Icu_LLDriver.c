/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu_LLDriver.c                                              */
/* Version      = 3.0.10a                                                     */
/* Date         = 04-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Low Level function implementations of ICU Driver        */
/* Component                                                                  */
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
 * V3.0.0:  26-Aug-2009  : Initial version
 *
 * V3.0.1:  29-Oct-2009  : As per SCR 074, unnecessary MISRA messages
 *                         are removed.
 *
 * V3.0.2:  05-Nov-2009  : As per SCR 088, I/O structure is updated to have
 *                         separate base address for USER and OS registers.
 *
 * V3.0.3:  08-Dec-2009  : As per SCR 154, name of global pointer for
 *                         previous input structure is corrected and
 *                         Icu_HWSetMode() is updated.
 *
 * V3.0.4:  25-Feb-2010  : As per SCR 192, following changes are done:
 *                         1. The structure 'Tdd_Icu_ExtIntpConfigType' is
 *                            removed from the function Icu_HWSetActivation.
 *                         2. The edge counting functionality for TAUJ
 *                            channel is removed from Icu_HWSetActivation
 *                            function.
 *
 * V3.0.5:  17-Mar-2010  : As per SCR 230, comments of #endif are updated.
 *
 * V3.0.6:  28-Jun-2010  : As per SCR 286, following changes are done:
 *                         1. All the functions are modified to support the
 *                            use of Timer Array Unit B.
 *                         2. The interrupts are enabled/disabled using
 *                            IMR registers.
 *
 * V3.0.7:  20-Jul-2010  : As per SCR 308, the functions Icu_HWInit,
 *                         Icu_HWDeInit Icu_HWSetActivation and Icu_TimerIsr
 *                         are updated with pre-compile options for
 *                         timer channels.
 *
 * V3.0.8:  26-Aug-2010  : As per SCR 335, following changes are done:
 *                         1. The Active time and Period time
 *                         are initialized to zero in
 *                         Icu_HWSignalMeasurementInit.
 *                         2. The check for valid data in case of
 *                         signal measurement mode is removed from the function
 *                         Icu_ServiceSignalMeasurement.
 *                         3. The functions Icu_HWInit,
 *                         Icu_HWStartCountMeasurement and
 *                         Icu_HWStopCountMeasurement are updated to enable
 *                         channel interrupts.
 *
 * V3.0.9:  03-Jan-2011  : As per SCR 388, in Icu_HWResetEdgeCount function
 *                         check to call Icu_HWStartCountMeasurement is
 *                         removed.
 *
 * V3.0.10: 24-Jun-2011  : As per SCR 477, following changes are done:
 *                         1. Access size is updated for registers
 *                            TAUAnBRS, TAUJnBRS, TAUJnTS, TAUJnTT, TAUJnTE,
 *                            TAUABnCMURm, TAUABnCSRm, TAUABnCSCm, TAUJnCMURm,
 *                            TAUJnCSRm, TAUJnCSCm.
 *                         2. Data type of local variable LusOverflowFlag is
 *                            changed to LucOverflowFlag.
 *
 * V3.0.10a: 04-Oct-2011 : As per MANTIS #3551, following changes are done:
 *                         1. The function Icu_HWInit is updated to clear
 *                            the interrupt request flag before enabling
 *                            interrupt.
 *                         2. The functions Icu_HWSetMode and
 *                            Icu_HWStartCountMeasurement are updated to
 *                            disable interrupt and clear the interrupt
 *                            request flag before enabling interrupt.
 *                         As per MANTIS #3708, following changes are done:
 *                         1. The function Icu_HWSignalMeasurementInit is
 *                            updated to reset the ulPrevSignalActiveTime
 *                         2. The function Icu_ServiceSignalMeasurememt is
 *                            updated to set active time when measurement
 *                            property is ICU_PERIOD_TIME.
 *                         As per MANTIS #3904, following changes are done:
 *                         1. The functions Icu_ServiceSignalMeasurement and
 *                            Icu_TimerIsr are updated to clear the Overflow
 *                            flag via the register CSCm.
 *                         As per MANTIS #4016, Icu_HWDeInit is updated to
 *                         swap the reset operation between CDRm and CMORm.
 *                         As per MANTIS #4019, Icu_ServiceSignalMeasurement
 *                         is updated to return the captured value as maximum
 *                         count when overflow occurs.
 *                         As per MANTIS #4019, Icu_TimerIsr is updated to
 *                         return always counted capture value without
 *                         considering overflow.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Icu.h"
#include "Icu_PBTypes.h"
#include "Icu_LTTypes.h"
#include "Icu_LLDriver.h"
#include "Icu_Ram.h"
#if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM_Cbk.h"
#endif
#if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Icu.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define ICU_LLDRIVER_C_AR_MAJOR_VERSION    ICU_AR_MAJOR_VERSION_VALUE
#define ICU_LLDRIVER_C_AR_MINOR_VERSION    ICU_AR_MINOR_VERSION_VALUE
#define ICU_LLDRIVER_C_AR_PATCH_VERSION    ICU_AR_PATCH_VERSION_VALUE

/* File version information */
#define ICU_LLDRIVER_C_SW_MAJOR_VERSION    3
#define ICU_LLDRIVER_C_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (ICU_LLDRIVER_AR_MAJOR_VERSION != ICU_LLDRIVER_C_AR_MAJOR_VERSION)
  #error "Icu_LLDriver.c : Mismatch in Specification Major Version"
#endif

#if (ICU_LLDRIVER_AR_MINOR_VERSION != ICU_LLDRIVER_C_AR_MINOR_VERSION)
  #error "Icu_LLDriver.c : Mismatch in Specification Minor Version"
#endif

#if (ICU_LLDRIVER_AR_PATCH_VERSION != ICU_LLDRIVER_C_AR_PATCH_VERSION)
  #error "Icu_LLDriver.c : Mismatch in Specification Patch Version"
#endif

#if (ICU_LLDRIVER_SW_MAJOR_VERSION != ICU_LLDRIVER_C_SW_MAJOR_VERSION)
  #error "Icu_LLDriver.c : Mismatch in Major Version"
#endif

#if (ICU_LLDRIVER_SW_MINOR_VERSION != ICU_LLDRIVER_C_SW_MINOR_VERSION)
  #error "Icu_LLDriver.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Icu_HWEdgeCountingInit
**
** Service ID           : None
**
** Description          : This service initializes the channel configured for
**                        edge counting mode.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : LpChannelConfig, LpTimerChannelConfig
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpEdgeCountData
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWEdgeCountingInit
(P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)LpChannelConfig,
P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig)

{
  /* Pointer definition for Edge Count Channel properties */
  P2CONST(Tdd_Icu_EdgeCountConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpEdgeCount;
  /* Local variable used to store the default active edge */
  uint8 LucDefaultEdge;
  /* Local variable used to store the Ram index */
  uint8 LucIndex;

  /* Load the default edge */
  LucDefaultEdge = LpChannelConfig->uiIcuDefaultStartEdge;

  /* Read the edge count channel properties and the ram index */
  LpEdgeCount = LpTimerChannelConfig->pChannelProp;
  LucIndex = LpEdgeCount->ucEdgeCounterRamIndex;
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Store the default active as channel activation edge */
  (Icu_GpEdgeCountData + LucIndex)->ucActiveEdge = LucDefaultEdge;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Reset the edge count overflow flag */
  (Icu_GpEdgeCountData + LucIndex)->uiTimerOvfFlag = ICU_FALSE;
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_HWTimestampInit
**
** Service ID           : None
**
** Description          : This service is used to initialize the channel
**                        configured for Timestamp Measurement mode.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : LpChannelConfig, LpTimerChannelConfig
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpTimeStampData
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWTimestampInit
(P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)LpChannelConfig,
P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig)
{
  /* Pointer definition for Timestamp Channel properties */
  P2CONST(Tdd_Icu_TimeStampMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                   LpTimestamp;
  /* Local variable used to store the channel index */
  uint8 LucIndex;

  /* Load the Timestamp Channel pointer */
  LpTimestamp = LpTimerChannelConfig->pChannelProp;
  LucIndex = LpTimestamp->ucTimeStampRamDataIndex;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Read the default active edge and store into RAM */
  (Icu_GpTimeStampData + LucIndex)->ucActiveEdge =
                                         LpChannelConfig->uiIcuDefaultStartEdge;
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_HWSignalMeasurementInit
**
** Service ID           : None
**
** Description          : This service initializes the channel configured in
**                        Signal Measurement Mode.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : LpTimerChannelConfig
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpSignalMeasurementData
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWSignalMeasurementInit
(P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpTimerChannelConfig)
{
  /* Pointer definition for Signal Measurement Channel properties */
  P2CONST(Tdd_Icu_SignalMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                        LpSignalMeasureChannel;
  /* Local variable used to store the Timer Instance */
  uint8 LucIndex;

  /* Load the Signal Measurement Channel pointer */
  LpSignalMeasureChannel = LpTimerChannelConfig->pChannelProp;

  /* Read the Signal Measurement Channel ram index */
  LucIndex = LpSignalMeasureChannel->ucSignalMeasureRamDataIndex;
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

   /* Initialize the Signal Active time to zero */
  (Icu_GpSignalMeasurementData + LucIndex)->ulSignalActiveTime = ICU_ZERO;
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */
   /* Initialize the Signal Period time to zero */
  (Icu_GpSignalMeasurementData + LucIndex)->ulSignalPeriodTime = ICU_ZERO;
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */
   /* Initialize the Signal Period time to zero */
  (Icu_GpSignalMeasurementData + LucIndex)->ulPrevSignalActiveTime = ICU_ZERO;
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_HWInit
**
** Service ID           : None
**
** Description          : This service initializes the hardware for all the
**                        configured channels based on the measurement mode.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelConfig, Icu_GpTimerChannelConfig,
**                        Icu_GpTAUUnitConfig, Icu_GpPreviousInputConfig
**
**                        Function(s) invoked:
**                        Icu_HWSetActivation, Icu_HWEdgeCountingInit,
**                        Icu_HWTimestampInit, Icu_HWSignalMeasurementInit
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWInit(void)
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpChannelConfig;
  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)\
  ||(ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  #endif
  #if(((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)\
  ||(ICU_TAUB_UNIT_USED == STD_ON)) && (ICU_PRESCALER_CONFIGURED))
  /* Defining a pointer to the TAU configuration parameters */
  P2CONST(Tdd_Icu_TAUUnitConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpTAUUnitConfig;
  #endif
  #if(ICU_PREVIOUS_INPUT_USED == STD_ON)
  /* Defining a pointer to the previous input configurtaion parameters */
  P2CONST(Tdd_IcuPreviousInputUseType, AUTOMATIC, ICU_CONFIG_CONST)
                                                         LpPreviousInputConfig;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint8, AUTOMATIC,ICU_CONFIG_DATA) LpPrevInputCntrlReg;
  #endif
  #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) && \
  (ICU_PRESCALER_CONFIGURED))
  /* Pointer pointing to the TAUA/B Unit control registers */
  P2VAR(Tdd_Icu_TAUABUnitOsRegs, AUTOMATIC, ICU_CONFIG_DATA) LpTAUABUnitOsReg;
  #endif
  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUA/B channel control registers */
  P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC, ICU_CONFIG_DATA)
                                                            LpTAUABChannelReg;
  #endif

  #if((ICU_TAUJ_UNIT_USED == STD_ON) && (ICU_PRESCALER_CONFIGURED))
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(Tdd_Icu_TAUJUnitOsRegs, AUTOMATIC, ICU_CONFIG_DATA) LpTAUJUnitOsReg;
  #endif
  #if(ICU_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ channel control registers */
  P2VAR(Tdd_Icu_TAUJChannelUserRegs, AUTOMATIC, ICU_CONFIG_DATA)
                                                              LpTAUJChannelReg;
  #endif
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint16, AUTOMATIC,ICU_CONFIG_DATA) LpIntrCntlReg;
  /* Defining a pointer to the Interrupt Mask Register */
  P2VAR(uint8, AUTOMATIC,ICU_CONFIG_DATA) LpImrIntpCntrlReg;

  #if(ICU_EDGE_DETECTION_API == STD_ON)
  /* Local variable to store the default activation edge */
  Icu_ActivationType LucDefaultActivation;
  #endif /* End of (ICU_EDGE_DETECTION_API == STD_ON) */

  /* Local variable to store the measurement mode of a channel */
  Icu_MeasurementModeType LddMeasurementMode;
  uint8 LucCnt;

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Icu_GpChannelConfig;

  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON) \
  || (ICU_TAUB_UNIT_USED == STD_ON))
  LpTimerChannelConfig = Icu_GpTimerChannelConfig;
  #endif
  #if(((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)\
  ||(ICU_TAUB_UNIT_USED == STD_ON)) && (ICU_PRESCALER_CONFIGURED))
  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig = Icu_GpTAUUnitConfig;
  #endif

  #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  SchM_Enter_Icu (ICU_CHANNEL_DATA_PROTECTION);
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  #if(ICU_TIMER_CH_CONFIGURED == STD_ON)
  #if(ICU_PRESCALER_CONFIGURED == STD_ON)

  if(LpTAUUnitConfig->uiConfigurePrescaler == ICU_ONE)
  {
    for(LucCnt = ICU_ZERO; LucCnt < ICU_TOTAL_TAU_UNITS_CONFIGURED; LucCnt++)
    {
      #if(((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON))\
      ||(ICU_TAUB_UNIT_USED == STD_ON))
      if((LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUA) ||
                             (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUB))
      #endif
      {
        #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
        /* Initialize pointer to the base address of the current timer unit */
        LpTAUABUnitOsReg = (P2VAR(Tdd_Icu_TAUABUnitOsRegs, AUTOMATIC,
                          ICU_CONFIG_CONST))LpTAUUnitConfig->pTAUnitOsCntlRegs;

        /* Set the values of prescaler and baud rate to
         * TPS and BRS registers respectively
         */
        LpTAUABUnitOsReg->usTAUABnTPS = LpTAUUnitConfig->usPrescaler;
        #if(ICU_TAUA_UNIT_USED == STD_ON)
        if(LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUA)
        {
          LpTAUABUnitOsReg->ucTAUAnBRS = LpTAUUnitConfig->ucBaudRate;
        }
        #endif
        #endif /* End of
        ((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
      }
      #if(((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON))\
      ||(ICU_TAUB_UNIT_USED == STD_ON))
      else /* (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUJ) */
      #endif
      {
        #if(ICU_TAUJ_UNIT_USED == STD_ON)
        /* Initialize pointer to the base address of the current timer unit */
        LpTAUJUnitOsReg = (P2VAR(Tdd_Icu_TAUJUnitOsRegs, AUTOMATIC,
                          ICU_CONFIG_CONST))LpTAUUnitConfig->pTAUnitOsCntlRegs;
        /* Set the values of prescaler and baud rate to
         * TPS and BRS registers respectively
         */
        LpTAUJUnitOsReg->usTAUJnTPS = LpTAUUnitConfig->usPrescaler;
        LpTAUJUnitOsReg->ucTAUJnBRS = LpTAUUnitConfig->ucBaudRate;
        #endif  /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
      }
      /* MISRA Rule         : 17.4                             */
      /* Message            : Increment or decrement operation */
      /*                      performed on pointer.            */
      /* Reason             : Increment operator is used to    */
      /*                      achieve better throughput.       */
      /* Verification       : However, part of the code is     */
      /*                      verified manually and it is not  */
      /*                      having any impact.               */
      LpTAUUnitConfig++;
    } /* End of TAU units for loop */
  }
  #endif /* End of (ICU_PRESCALER_CONFIGURED == STD_ON) */
  #endif /* End of (ICU_TIMER_CH_CONFIGURED == STD_ON) */

  #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Critical Section */
  SchM_Exit_Icu (ICU_CHANNEL_DATA_PROTECTION);
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  #if(ICU_PREVIOUS_INPUT_USED == STD_ON)
  #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  SchM_Enter_Icu (ICU_CHANNEL_DATA_PROTECTION);
  #endif

  /* Update the previous input use pointer to point to the current channel */
  LpPreviousInputConfig = Icu_GpPreviousInputConfig;

  for(LucCnt = ICU_ZERO; LucCnt < ICU_TOTAL_UNITS_FOR_PREVINPUT; LucCnt++)
  {
    LpPrevInputCntrlReg =  LpPreviousInputConfig->pPreviousInputCntlRegs;
    *LpPrevInputCntrlReg |= LpPreviousInputConfig->ucPreviousInputMask;
    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */
    LpPreviousInputConfig++;
  }
  #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Critical Section */
  SchM_Exit_Icu (ICU_CHANNEL_DATA_PROTECTION);
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON)*/
  #endif /* End of (ICU_PREVIOUS_INPUT_USED == STD_ON) */

  #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  SchM_Enter_Icu (ICU_CHANNEL_DATA_PROTECTION);
  #endif /* end of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  for(LucCnt = ICU_ZERO; LucCnt < ICU_MAX_CHANNEL; LucCnt++)
  {
    /* Read the channel's measurement mode */
    LddMeasurementMode = (Icu_MeasurementModeType)
                                        (LpChannelConfig->uiIcuMeasurementMode);
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    if((LpChannelConfig->uiIcuChannelType == ICU_HW_TAUA) ||
                             (LpChannelConfig->uiIcuChannelType == ICU_HW_TAUB))
    #endif
    {
      #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      /* Initialize pointer to the base address of the current channel */
      LpTAUABChannelReg =
      (P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                                  LpChannelConfig->pCntlRegs;
      /* If the measurement mode is edge counter, put the defined
         count value to CDR Register */
      if(LddMeasurementMode == ICU_MODE_EDGE_COUNTER)
      {
        LpTAUABChannelReg->usTAUABnCDRm = ICU_TAUAB_START_DWNCNT_VAL;
      }

      /* Read the value of Channel Mode OS Register configured */
      *(LpTimerChannelConfig->pCMORRegs) =
                              LpTimerChannelConfig->usChannelModeOSRegSettings;

      /* Read the value of Channel Mode User Register configured */
      LpTAUABChannelReg->ucTAUABnCMURm = \
                            LpTimerChannelConfig->ucChannelModeUserRegSettings;

      /* Reset Channel Status Clear Trigger Register */
      LpTAUABChannelReg->ucTAUABnCSCm = ICU_ONE;
      #endif /* End of
          ((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
    }
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        && (ICU_TAUJ_UNIT_USED == STD_ON))
    else if(LpChannelConfig->uiIcuChannelType == ICU_HW_TAUJ)
    #endif
    {
      #if(ICU_TAUJ_UNIT_USED == STD_ON)
      /* Initialize pointer to the base address of the current channel */
      LpTAUJChannelReg =
      (P2VAR(Tdd_Icu_TAUJChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                                  LpChannelConfig->pCntlRegs;

      /* If the measurement mode is edge counter, put the defined
       * count value to CDR Register
       */
      if(LddMeasurementMode == ICU_MODE_EDGE_COUNTER)
      {
        LpTAUJChannelReg->ulTAUJnCDRm = ICU_TAUJ_START_DWNCNT_VAL;
      }

      /* Read the value of Channel Mode OS Register configured */
      *(LpTimerChannelConfig->pCMORRegs) =
                              LpTimerChannelConfig->usChannelModeOSRegSettings;

      /* Read the value of Channel Mode User Register configured */
      LpTAUJChannelReg->ucTAUJnCMURm =
                             LpTimerChannelConfig->ucChannelModeUserRegSettings;

      /* Reset Channel Status Clear Trigger Register */
      LpTAUJChannelReg->ucTAUJnCSCm = ICU_ONE;
      #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
    }
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        && (ICU_TAUJ_UNIT_USED == STD_ON))
    else
    {
      /* To avoid MISRA warning */
    }
    #endif

    switch(LddMeasurementMode)
    {
      #if (ICU_EDGE_DETECTION_API == STD_ON)
      /* Edge Detection Mode */
      case ICU_MODE_SIGNAL_EDGE_DETECT:
      {
        /* Clear the interrupt request flag */
        LpIntrCntlReg = LpChannelConfig->pIntrCntlRegs;
        *(LpIntrCntlReg) &= ICU_CLEAR_INT_REQUEST_FLAG;
        /* Enabling the Interrupt processing */
        LpImrIntpCntrlReg = LpChannelConfig->pImrIntrCntlRegs;
        *(LpImrIntpCntrlReg) &= LpChannelConfig->ucImrMaskValue;

        /* Read the default edge configured for the channel */
        LucDefaultActivation = (Icu_ActivationType)
                                        LpChannelConfig->uiIcuDefaultStartEdge;
        /* Configure external interrupt for the active edge */
        Icu_HWSetActivation(LucCnt, LucDefaultActivation);
        break;
      }
      #endif /* End of (ICU_EDGE_DETECTION_API == STD_ON) */
      #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUB_UNIT_USED == STD_ON))
      /* Edge Counter Mode */
      case ICU_MODE_EDGE_COUNTER:
      {
        /* Configure the channel in Edge Counter Mode */
        Icu_HWEdgeCountingInit(LpChannelConfig, LpTimerChannelConfig);
        break;
      }
      #endif
      #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                          || (ICU_TAUJ_UNIT_USED == STD_ON))
      /* Timestamp Mode */
      case ICU_MODE_TIMESTAMP:
      {
        /* Configure the channel in Timestamp Mode */
        Icu_HWTimestampInit(LpChannelConfig, LpTimerChannelConfig);
        break;
      }
      #endif
      #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                          || (ICU_TAUJ_UNIT_USED == STD_ON))
      /* Signal Measurement Mode */
      case ICU_MODE_SIGNAL_MEASUREMENT:
      {
        /* Configure the channel in Signal Measurement Mode */
        Icu_HWSignalMeasurementInit(LpTimerChannelConfig);
        break;
      }
      #endif
      default:
      {
        /* Execution should never get here */
        break;
      }
    } /* End of switch case */

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */
    /* Increment the channel pointer */
    LpChannelConfig++;
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        || (ICU_TAUJ_UNIT_USED == STD_ON))
    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */
    /* Increment the timer channel pointer */
    LpTimerChannelConfig++;
    #endif
    /* End of (((ICU_TAUA_UNIT_USED == STD_ON) \
    || (ICU_TAUB_UNIT_USED == STD_ON)) || (ICU_TAUJ_UNIT_USED == STD_ON))
     */
  } /* End of channels for loop */

  #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Critical Section */
  SchM_Exit_Icu (ICU_CHANNEL_DATA_PROTECTION);
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#if(ICU_DE_INIT_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_HWDeInit
**
** Service ID           : None
**
** Description          : This service De-Initializes the hardware for all the
**                        configured channels based on the measurement mode.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelConfig, Icu_GpTimerChannelConfig,
**                        Icu_GpTAUUnitConfig, Icu_GpPreviousInputConfig
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWDeInit(void)
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpChannelConfig;
  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)\
  ||(ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  #endif
  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUA/B channel control registers */
  P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC, ICU_CONFIG_DATA)
                                                              LpTAUABChannelReg;
  #endif
  #if(ICU_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ channel control registers */
  P2VAR(Tdd_Icu_TAUJChannelUserRegs, AUTOMATIC, ICU_CONFIG_DATA)
                                                               LpTAUJChannelReg;
  #endif
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint8, AUTOMATIC,ICU_CONFIG_DATA) LpImrIntpCntrlReg;

  #if(ICU_PREVIOUS_INPUT_USED == STD_ON)
  /* Defining a pointer to the previous input configurtaion parameters */
  P2CONST(Tdd_IcuPreviousInputUseType, AUTOMATIC, ICU_CONFIG_CONST)
                                                         LpPreviousInputConfig;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint8, AUTOMATIC,ICU_CONFIG_DATA) LpPrevInputCntrlReg;
  #endif

  #if(ICU_EDGE_DETECTION_API == STD_ON)
  /* Defining a pointer to point to the External Interrupt registers */
  P2VAR(uint8, AUTOMATIC,ICU_CONFIG_DATA) LpExtIntpRegs;
  #endif /* End of (ICU_EDGE_DETECTION_API == STD_ON) */
  #if(ICU_EDGE_DETECTION_API == STD_ON)
  /* Local variable to store the measurement mode of a channel */
  Icu_MeasurementModeType LddMeasurementMode;
  #endif
  uint8 LucCnt;

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Icu_GpChannelConfig;
  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)\
  ||(ICU_TAUB_UNIT_USED == STD_ON))
  LpTimerChannelConfig = Icu_GpTimerChannelConfig;
  #endif

  #if(ICU_PREVIOUS_INPUT_USED == STD_ON)
  #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  SchM_Enter_Icu (ICU_CHANNEL_DATA_PROTECTION);
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Update the previous input use pointer to point to the current channel */
  LpPreviousInputConfig = Icu_GpPreviousInputConfig;

  for(LucCnt = ICU_ZERO; LucCnt < ICU_TOTAL_UNITS_FOR_PREVINPUT; LucCnt++)
  {
    LpPrevInputCntrlReg = LpPreviousInputConfig->pPreviousInputCntlRegs;
    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operators shall not be applied to    */
    /*                      operands whose underlying type is signed.    */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V6.2.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */

    *LpPrevInputCntrlReg &= ~LpPreviousInputConfig->ucPreviousInputMask;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */
    LpPreviousInputConfig++;
  }
  #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Critical Section */
  SchM_Exit_Icu (ICU_CHANNEL_DATA_PROTECTION);
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #endif /* End of (ICU_PREVIOUS_INPUT_USED == STD_ON) */

  #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  SchM_Enter_Icu (ICU_CHANNEL_DATA_PROTECTION);
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  for (LucCnt = ICU_ZERO; LucCnt < ICU_MAX_CHANNEL; LucCnt++)
  {
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        && (ICU_TAUJ_UNIT_USED == STD_ON))
    if((LpChannelConfig->uiIcuChannelType == ICU_HW_TAUA)
       || (LpChannelConfig->uiIcuChannelType == ICU_HW_TAUB))
    #endif
    {
      #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      /* Initialize pointer to the base address of the current channel */
      LpTAUABChannelReg =
      (P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                                  LpChannelConfig->pCntlRegs;
      /* Reset the value of Channel Mode OS Register */
      *(LpTimerChannelConfig->pCMORRegs) = ICU_WORD_ZERO;

      /* Reset the value of Channel Data Register */
      LpTAUABChannelReg->usTAUABnCDRm = ICU_WORD_ZERO;

      /* Reset the value of Channel Mode User Register */
      LpTAUABChannelReg->ucTAUABnCMURm = ICU_ZERO;

      /* Reset Channel Status Clear Trigger Register */
      LpTAUABChannelReg->ucTAUABnCSCm = ICU_ZERO;
      #endif
    }
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        && (ICU_TAUJ_UNIT_USED == STD_ON))
    else if(LpChannelConfig->uiIcuChannelType == ICU_HW_TAUJ)
    #endif
    {
      #if(ICU_TAUJ_UNIT_USED == STD_ON)
      /* Initialize pointer to the base address of the current channel */
      LpTAUJChannelReg =
      (P2VAR(Tdd_Icu_TAUJChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                                  LpChannelConfig->pCntlRegs;

      /* Reset the value of Channel Mode OS Register */
      *(LpTimerChannelConfig->pCMORRegs) = ICU_WORD_ZERO;

      /* Reset the value of Channel Data Register */
      LpTAUJChannelReg->ulTAUJnCDRm = ICU_DOUBLE_ZERO;

      /* Reset the value of Channel Mode User Register */
      LpTAUJChannelReg->ucTAUJnCMURm = ICU_ZERO;

      /* Reset Channel Status Clear Trigger Register */
      LpTAUJChannelReg->ucTAUJnCSCm = ICU_ZERO;
      #endif
    }
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                        && (ICU_TAUJ_UNIT_USED == STD_ON))
    else
    {
      /* To avoid MISRA warning */
    }
    #endif
    /* Disabling the Interrupt processing */
    LpImrIntpCntrlReg = LpChannelConfig->pImrIntrCntlRegs;

    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operations on the signed data will   */
    /*                      give implementation defined results          */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V6.2.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */
    *(LpImrIntpCntrlReg) |= ~(LpChannelConfig->ucImrMaskValue);

    /* Check channel connected to Timers based on the measurement mode */
    #if(ICU_EDGE_DETECTION_API == STD_ON)
    /* Read the channel's measurement mode */
    LddMeasurementMode = (Icu_MeasurementModeType)
                                        (LpChannelConfig->uiIcuMeasurementMode);
    /* Edge Detection Mode */
    if(LddMeasurementMode == ICU_MODE_SIGNAL_EDGE_DETECT)
    {
      /* Read the base configuration interrupt address */
      LpExtIntpRegs = LpChannelConfig->pCntlRegs;
      /* Set FCLAnCTLm register to the reset value */
      *(LpExtIntpRegs) = ICU_ZERO;
    }
    #endif /* End of (ICU_EDGE_DETECTION_API == STD_ON) */
    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */
    /* Increment the channel pointer */
    LpChannelConfig++;
    #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)\
    ||(ICU_TAUB_UNIT_USED == STD_ON))
    /* Increment the timer channel pointer */
    LpTimerChannelConfig++;
    #endif
  } /* End of channels for loop */

  #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Critical Section */
  SchM_Exit_Icu (ICU_CHANNEL_DATA_PROTECTION);
  #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of (ICU_DE_INIT_API == STD_ON) */

#if(ICU_SET_MODE_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_HWSetMode
**
** Service ID           : None
**
** Description          : This service sets the operating mode of the ICU
**                        Driver.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : Mode
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelConfig, Icu_GpChannelRamData
**                        Icu_GenModuleMode
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWSetMode(Icu_ModeType Mode)
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpChannelConfig;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint16, AUTOMATIC,ICU_CONFIG_DATA) LpIntrCntlReg;
  /* Defining a pointer to the Interrupt Mask Register */
  P2VAR(uint8, AUTOMATIC,ICU_CONFIG_DATA) LpImrIntpCntrlReg;
  /* Local variable to store wakeup status */
  uint8 LucWakeupStatus;
  /* Local variable to loop through the channels */
  uint8 LucChannelNo;

  for(LucChannelNo = ICU_ZERO; LucChannelNo < ICU_MAX_CHANNEL; LucChannelNo++)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Update the channel configuration pointer to the current channel */
    LpChannelConfig = Icu_GpChannelConfig + LucChannelNo;

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Read the current channel wakeup status */
    LucWakeupStatus = (Icu_GpChannelRamData + LucChannelNo)->uiWakeupEnable;

    /* Load the interrupt control register */
    LpIntrCntlReg = LpChannelConfig->pIntrCntlRegs;
    /* Load the interrupt mask register */
    LpImrIntpCntrlReg = LpChannelConfig->pImrIntrCntlRegs;
    /* Check for the current wakeup status of the channel */
    if(LucWakeupStatus == ICU_FALSE)
    {
      if(Mode == ICU_MODE_SLEEP)
      {
        /* MISRA Rule         : 12.7                                         */
        /* Message            : Bitwise operations on the signed data will   */
        /*                      give implementation defined results          */
        /* Reason             : Though the bitwise operation is performed on */
        /*                      unsigned data, this warning is generated by  */
        /*                      the QAC tool V6.2.1 as an indirect result of */
        /*                      integral promotion in complex bitwise        */
        /*                      operations.                                  */
        /* Verification       : However, this part of the code is verified   */
        /*                      manually and it is not having any impact.    */

        /* Disable Interrupt */
        *(LpImrIntpCntrlReg) |= ~(LpChannelConfig->ucImrMaskValue);
      }
      else /* Mode = ICU_MODE_NORMAL */
      {
        /* Disable Interrupt */
        *(LpImrIntpCntrlReg) |= ~(LpChannelConfig->ucImrMaskValue);
        /* Clear the interrupt request flag */
        *(LpIntrCntlReg) &= ICU_CLEAR_INT_REQUEST_FLAG;
        /* Enable Interrupt */
        *(LpImrIntpCntrlReg) &= LpChannelConfig->ucImrMaskValue;
      }
    }
  }
  /* Update the ICU Driver Mode */
  Icu_GenModuleMode = Mode;
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of (ICU_SET_MODE_API == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_HWSetActivation
**
** Service ID           : None
**
** Description          : This service configures the hardware to the active
**                        edges of the requested channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LucChannel, LucActiveEdge
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : NA
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelConfig, Icu_GpEdgeCountData
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWSetActivation
(uint8 LucChannel, Icu_ActivationType LucActiveEdge)
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpChannelConfig;
  #if(ICU_EDGE_DETECTION_API == STD_ON)
  /* Defining a pointer to point to the External Interrupt registers */
  P2VAR(uint8, AUTOMATIC, ICU_CONFIG_DATA) LpExtIntpRegs;
  #endif /* End of (ICU_EDGE_DETECTION_API == STD_ON) */

  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUA/B registers */
  P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC, ICU_CONFIG_DATA)
                                                              LpTAUABChannelReg;
  #endif
  #if(ICU_TAUJ_UNIT_USED == STD_ON)
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Tdd_Icu_TAUJChannelUserRegs, AUTOMATIC, ICU_CONFIG_DATA)
                                                               LpTAUJChannelReg;
  #endif
  #if((ICU_EDGE_DETECTION_API == STD_ON) || (ICU_TAUA_UNIT_USED == STD_ON) || \
  (ICU_TAUB_UNIT_USED == STD_ON))
  /* To store Channel Measurement Mode */
  Icu_MeasurementModeType LddMeasurementMode;
  #endif
  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  /* Pointer definition for Edge Count Channel properties */
  P2CONST(Tdd_Icu_EdgeCountConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpEdgeCount;
  uint8 LucIndex;
  #endif
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Icu_GpChannelConfig + LucChannel;
  /* Update the timer channel configuration pointer to point to the
   * current channel
   */
  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  LpTimerChannelConfig = Icu_GpTimerChannelConfig + LucChannel;
  #endif
  #if((ICU_EDGE_DETECTION_API == STD_ON) || (ICU_TAUA_UNIT_USED == STD_ON) || \
  (ICU_TAUB_UNIT_USED == STD_ON))
  /* Read measurement mode */
  LddMeasurementMode =
               (Icu_MeasurementModeType)(LpChannelConfig->uiIcuMeasurementMode);
  #endif
  #if(ICU_EDGE_DETECTION_API == STD_ON)
  if(LddMeasurementMode == ICU_MODE_SIGNAL_EDGE_DETECT)
  {
    /* Read the address of filter control register */
    LpExtIntpRegs = LpChannelConfig->pCntlRegs;

    /* Mask the bypass bits of filter control register */
    *(LpExtIntpRegs) &= ICU_BYPASS_MASK;

    if(LucActiveEdge == ICU_BOTH_EDGES)
    {
      /* Set the edge detection bits in the filter control register
       * as per mask
       */
      *(LpExtIntpRegs) |= ICU_BOTH_EDGES_MASK;
    }
    else if(LucActiveEdge == ICU_FALLING_EDGE)
    {
      /* Set the edge detection bits in the filter control register
       * as per mask
       */
      *(LpExtIntpRegs) |= ICU_FALLING_EDGE_MASK;
    }
    else /* (LucActiveEdge == ICU_RISING_EDGE) */
    {
      /* Set the edge detection bits in the filter control register
       * as per mask
       */
      *(LpExtIntpRegs) |= ICU_RISING_EDGE_MASK;
    }
  }
  else /* LddMeasurementMode = ICU_MODE_EDGE_COUNTER or ICU_MODE_TIMESTAMP */
  #endif /* End of (ICU_EDGE_DETECTION_API == STD_ON) */
  {
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    if((LpChannelConfig->uiIcuChannelType == ICU_HW_TAUA) ||
                           (LpChannelConfig->uiIcuChannelType == ICU_HW_TAUB))
    #endif
    {
      #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      /* Initialize pointer to the base address of the current channel */
      LpTAUABChannelReg =
      (P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                                LpChannelConfig->pCntlRegs;
      if(LddMeasurementMode == ICU_MODE_EDGE_COUNTER)
      {
        /* Read the current active edge */
        LpEdgeCount = LpTimerChannelConfig->pChannelProp;
        LucIndex = LpEdgeCount->ucEdgeCounterRamIndex;
        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */

        /* Enable Edge Counting only if there is no timer overflow */
        if((Icu_GpEdgeCountData + LucIndex)->uiTimerOvfFlag == ICU_FALSE)
        {
          /* Set the active edge */
          LpTAUABChannelReg->ucTAUABnCMURm = LucActiveEdge;
        }
      }
      else /* if (LddMeasurementMode == ICU_MODE_TIMESTAMP) */
      {
        /* Set the active edge */
        LpTAUABChannelReg->ucTAUABnCMURm = LucActiveEdge;
      }
      #endif
    }
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    else if(LpChannelConfig->uiIcuChannelType == ICU_HW_TAUJ)
    #endif
    {
      #if(ICU_TAUJ_UNIT_USED == STD_ON)
      /* Initialize pointer to the base address of the current channel */
      LpTAUJChannelReg =
      (P2VAR(Tdd_Icu_TAUJChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                                LpChannelConfig->pCntlRegs;

      /* TAUJ does't support edge counter mode. so, set the active edge
       * for timestamp mode only
       */
      LpTAUJChannelReg->ucTAUJnCMURm = LucActiveEdge;
      #endif
    }
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    else
    {
      /* To avoid MISRA warning */
    }
    #endif
  }
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_HWStartCountMeasurement
**
** Service ID           : None
**
** Description          : This service routine starts the count measurement
**                        for starting edge counting or signal measurement or
**                        timestamp measurement.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpTimerChannelConfig
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWStartCountMeasurement
(Icu_ChannelType LddChannel)
{
  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)\
  ||(ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the TAU configuration parameters */
  P2CONST(Tdd_Icu_TAUUnitConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpTAUUnitConfig;
   /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpChannelConfig;
   /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  /* Local variable to store the measurement mode of a channel */
  Icu_MeasurementModeType LddMeasurementMode;
  /* Pointer definition for Signal Measurement Channel properties */
  P2CONST(Tdd_Icu_SignalMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                        LpSignalMeasure;

  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint16, AUTOMATIC,ICU_CONFIG_DATA) LpIntrCntlReg;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint8, AUTOMATIC,ICU_CONFIG_DATA) LpImrIntpCntrlReg;
  #endif

  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUA/B user registers */
  P2VAR(Tdd_Icu_TAUABUnitUserRegs, AUTOMATIC, ICU_CONFIG_DATA)
                                                            LpTAUABUnitUserReg;
  #endif

  #if(ICU_TAUJ_UNIT_USED == STD_ON)
  /* Defining a pointer to point to the TAUJ user registers */
  P2VAR(Tdd_Icu_TAUJUnitUserRegs, AUTOMATIC, ICU_CONFIG_DATA) LpTAUJUnitUserReg;
  #endif

  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)\
  ||(ICU_TAUB_UNIT_USED == STD_ON))
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Read channel configuration pointer */
  LpChannelConfig = Icu_GpChannelConfig + LddChannel;

  /* Read timer channel configuration pointer */
  LpTimerChannelConfig = Icu_GpTimerChannelConfig + LddChannel;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig =
                  Icu_GpTAUUnitConfig + LpTimerChannelConfig->ucTimerUnitIndex;

  /* Disabling the Interrupt processing */
  LpImrIntpCntrlReg = LpChannelConfig->pImrIntrCntlRegs;
  *(LpImrIntpCntrlReg) |= ~(LpChannelConfig->ucImrMaskValue);
  /* Clear the interrupt request flag */
  LpIntrCntlReg = LpChannelConfig->pIntrCntlRegs;
  *(LpIntrCntlReg) &= ICU_CLEAR_INT_REQUEST_FLAG;
  /* Enabling the Interrupt processing */
  *(LpImrIntpCntrlReg) &= LpChannelConfig->ucImrMaskValue;
  /* Read the channel's measurement mode */
  LddMeasurementMode = (Icu_MeasurementModeType)
                                        (LpChannelConfig->uiIcuMeasurementMode);
  if(LddMeasurementMode == ICU_MODE_SIGNAL_MEASUREMENT)
  {
    /* Read the channel properties */
    LpSignalMeasure = LpTimerChannelConfig->pChannelProp;
    /* If the channel is duty cycle channel, then enable interrupt for the
       next channel also */
    if(LpSignalMeasure->blDutyCycleChannel == ICU_TRUE)
    {
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Read channel configuration pointer */
      LpChannelConfig = Icu_GpChannelConfig + LddChannel + ICU_ONE;
      /* Disabling the Interrupt processing */
      LpImrIntpCntrlReg = LpChannelConfig->pImrIntrCntlRegs;
      *(LpImrIntpCntrlReg) |= ~(LpChannelConfig->ucImrMaskValue);
      /* Clear the interrupt request flag */
      LpIntrCntlReg = LpChannelConfig->pIntrCntlRegs;
      *(LpIntrCntlReg) &= ICU_CLEAR_INT_REQUEST_FLAG;
      /* Enabling the Interrupt processing */
      *(LpImrIntpCntrlReg) &= LpChannelConfig->ucImrMaskValue;
    }
  }
  #endif /* End of ((ICU_TAUA_UNIT_USED == STD_ON)||
  (ICU_TAUJ_UNIT_USED == STD_ON) ||(ICU_TAUB_UNIT_USED == STD_ON) */

  #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
  if((LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUA) ||
                             (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUB))
  #endif
  {
    #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
    /* Initialize pointer to the base address of the current timer unit */
    LpTAUABUnitUserReg =
    (P2VAR(Tdd_Icu_TAUABUnitUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                         LpTAUUnitConfig->pTAUnitUserCntlRegs;

    /* Set the bit corresponding to the channel no. in TS register */
    LpTAUABUnitUserReg->usTAUABnTS |= LpChannelConfig->usChannelMaskValue;
    #endif /* End of
         ((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
  }
  #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
  else /* (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUJ) */
  #endif
  {
    #if(ICU_TAUJ_UNIT_USED == STD_ON)
    /* Initialize pointer to the base address of the current timer unit */
    LpTAUJUnitUserReg =
    (P2VAR(Tdd_Icu_TAUJUnitUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                          LpTAUUnitConfig->pTAUnitUserCntlRegs;

    /* Set the bit corresponding to the channel no. in TS register */
    LpTAUJUnitUserReg->ucTAUJnTS |= (uint8)LpChannelConfig->usChannelMaskValue;
    #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
  }
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "Memmap.h"

/*******************************************************************************
** Function Name        : Icu_HWStopCountMeasurement
**
** Service ID           : None
**
** Description          : This service routine stops the count measurement
**                        for starting edge counting or signal measurement or
**                        timestamp measurement.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpTimerChannelConfig
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWStopCountMeasurement
(Icu_ChannelType LddChannel)
{
  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON) \
  ||(ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpChannelConfig;
   /* Defining a pointer to the timer channel configuration parameters */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  /* Defining a pointer to the TAU configuration parameters */
  P2CONST(Tdd_Icu_TAUUnitConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpTAUUnitConfig;
  /* Local variable to store the measurement mode of a channel */
  Icu_MeasurementModeType LddMeasurementMode;
  /* Pointer definition for Signal Measurement Channel properties */
  P2CONST(Tdd_Icu_SignalMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpSignalMeasure;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint8, AUTOMATIC,ICU_CONFIG_DATA) LpImrIntpCntrlReg;
  #endif

  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUA/B registers */
  P2VAR(Tdd_Icu_TAUABUnitUserRegs, AUTOMATIC, ICU_CONFIG_DATA)
                                                            LpTAUABUnitUserReg;
  #endif

  #if(ICU_TAUJ_UNIT_USED == STD_ON)
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Tdd_Icu_TAUJUnitUserRegs, AUTOMATIC, ICU_CONFIG_DATA) LpTAUJUnitUserReg;
  #endif

  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)\
  ||(ICU_TAUB_UNIT_USED == STD_ON))
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Read channel configuration pointer */
  LpChannelConfig = Icu_GpChannelConfig + LddChannel;

  /* Read timer channel configuration pointer */
  LpTimerChannelConfig = Icu_GpTimerChannelConfig + LddChannel;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig =
                  Icu_GpTAUUnitConfig + LpTimerChannelConfig->ucTimerUnitIndex;

  /* Disabling the Interrupt processing */
  LpImrIntpCntrlReg = LpChannelConfig->pImrIntrCntlRegs;

  /* MISRA Rule         : 12.7                                         */
  /* Message            : Bitwise operations on the signed data will   */
  /*                      give implementation defined results          */
  /* Reason             : Though the bitwise operation is performed on */
  /*                      unsigned data, this warning is generated by  */
  /*                      the QAC tool V6.2.1 as an indirect result of */
  /*                      integral promotion in complex bitwise        */
  /*                      operations.                                  */
  /* Verification       : However, this part of the code is verified   */
  /*                      manually and it is not having any impact.    */
  *(LpImrIntpCntrlReg) |= ~(LpChannelConfig->ucImrMaskValue);
  /* Read the channel's measurement mode */
  LddMeasurementMode = (Icu_MeasurementModeType)
                                        (LpChannelConfig->uiIcuMeasurementMode);
  if(LddMeasurementMode == ICU_MODE_SIGNAL_MEASUREMENT)
  {
    /* Read the channel properties */
    LpSignalMeasure = LpTimerChannelConfig->pChannelProp;
    /* If the channel is duty cycle channel, then enable interrupt for the
       next channel also */
    if(LpSignalMeasure->blDutyCycleChannel == ICU_TRUE)
    {
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Read channel configuration pointer */
      LpChannelConfig = Icu_GpChannelConfig + LddChannel + ICU_ONE;
      /* Disabling the Interrupt processing */
      LpImrIntpCntrlReg = LpChannelConfig->pImrIntrCntlRegs;

      /* MISRA Rule         : 12.7                                         */
      /* Message            : Bitwise operations on the signed data will   */
      /*                      give implementation defined results          */
      /* Reason             : Though the bitwise operation is performed on */
      /*                      unsigned data, this warning is generated by  */
      /*                      the QAC tool V6.2.1 as an indirect result of */
      /*                      integral promotion in complex bitwise        */
      /*                      operations.                                  */
      /* Verification       : However, this part of the code is verified   */
      /*                      manually and it is not having any impact.    */
      *(LpImrIntpCntrlReg) |= ~(LpChannelConfig->ucImrMaskValue);
    }
  }
  #endif /* End of ((ICU_TAUA_UNIT_USED == STD_ON)||
  (ICU_TAUJ_UNIT_USED == STD_ON) ||(ICU_TAUB_UNIT_USED == STD_ON) */

  #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                      && (ICU_TAUJ_UNIT_USED == STD_ON))
  if((LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUA) ||
                               (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUB))
  #endif
  {
    #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
    /* Initialize pointer to the base address of the current timer unit */
    LpTAUABUnitUserReg =
    (P2VAR(Tdd_Icu_TAUABUnitUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                         LpTAUUnitConfig->pTAUnitUserCntlRegs;

    /* Set the bit corresponding to the channel no. in TT register */
    LpTAUABUnitUserReg->usTAUABnTT |= LpChannelConfig->usChannelMaskValue;
    #endif
  }
  #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                      && (ICU_TAUJ_UNIT_USED == STD_ON))
  else /* (LpTAUUnitConfig->ucIcuUnitType == ICU_HW_TAUJ) */
  #endif
  {
    #if(ICU_TAUJ_UNIT_USED == STD_ON)
    /* Initialize pointer to the base address of the current timer unit */
    LpTAUJUnitUserReg =
    (P2VAR(Tdd_Icu_TAUJUnitUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                         LpTAUUnitConfig->pTAUnitUserCntlRegs;

    /* Set the bit corresponding to the channel no. in TT register */
    LpTAUJUnitUserReg->ucTAUJnTT |= (uint8)LpChannelConfig->usChannelMaskValue;
   #endif
  }
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "Memmap.h"

#if(ICU_EDGE_COUNT_API == STD_ON)
#if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
/*******************************************************************************
** Function Name        : Icu_HWResetEdgeCount
**
** Service ID           : None
**
** Description          : This service resets the Timer Counter of the channel
**                        which is configured in Edge Counting Mode.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LucChannel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelConfig, Icu_GpEdgeCountData,
**                        Icu_GpChannelRamData
**
**                        Function(s) invoked:
**                        Icu_HWStartCountMeasurement
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWResetEdgeCount(uint8 LucChannel)
{
  /* Defining a pointer to point to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                LpChannelConfig;
  /* Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpTimerChannelConfig;
  /* Pointer definition for Edge Count Channel properties */
  P2CONST(Tdd_Icu_EdgeCountConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpEdgeCount;
  /* Defining a pointer to point to the TAUA/B registers */
  P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC,ICU_CONFIG_DATA)
                                                              LpTAUABChannelReg;
  uint8 LucIndex;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Icu_GpChannelConfig + LucChannel;

  /* Update the channel configuration pointer to point to the current channel */
  LpTimerChannelConfig = Icu_GpTimerChannelConfig + LucChannel;

  /* Initialize pointer to the base address of the current channel */
  LpTAUABChannelReg =
  (P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                                LpChannelConfig->pCntlRegs;
  /* Reset the Timer Counter */
  LpTAUABChannelReg->usTAUABnCDRm = ICU_TIMER_RESET_VAL;

  /* Read the channel properties */
  LpEdgeCount = LpTimerChannelConfig->pChannelProp;
  LucIndex = LpEdgeCount->ucEdgeCounterRamIndex;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Reset the overflow flag */
  (Icu_GpEdgeCountData + LucIndex)->uiTimerOvfFlag = ICU_FALSE;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Re-enable Edge Counting */
  Icu_HWStartCountMeasurement(LucChannel);
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of
           ((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
#endif /* End of (ICU_EDGE_COUNT_API == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_HWGetEdgeNumbers
**
** Service ID           : None
**
** Description          : This service routine counts the number of edges
**                        for the given channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelConfig, Icu_GpEdgeCountData
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_HWGetEdgeNumbers(Icu_ChannelType LddChannel)
{
  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                LpChannelConfig;

  /* Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpTimerChannelConfig;
  /* Pointer definition for Signal Measurement Channel properties */
  P2CONST(Tdd_Icu_EdgeCountConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                    LpEdgeCount;
  /* Pointer definition for Signal Measurement RAM data */
  P2VAR(Tdd_Icu_EdgeCountChannelRamDataType, AUTOMATIC,ICU_CONFIG_DATA)
                                                                LpEdgeCountData;
  /* Defining a pointer to point to the TAUA/B registers */
  P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC,ICU_CONFIG_DATA)
                                                              LpTAUABChannelReg;
  uint8 LucRamIndex;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Read channel configuration pointer */
  LpChannelConfig = Icu_GpChannelConfig + LddChannel;

  /* Read timer channel configuration pointer */
  LpTimerChannelConfig = Icu_GpTimerChannelConfig + LddChannel;

  /* Read the channel properties */
  LpEdgeCount = LpTimerChannelConfig->pChannelProp;
  /* Read the channel ram index */
  LucRamIndex = LpEdgeCount->ucEdgeCounterRamIndex;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  LpEdgeCountData = Icu_GpEdgeCountData + LucRamIndex;
  /* Initialize pointer to the base address of the current channel */
  LpTAUABChannelReg =
  (P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                                LpChannelConfig->pCntlRegs;
  /* Storing the Edge count value into RAM */
  LpEdgeCountData->usIcuEdgeCount =
             LpTAUABChannelReg->usTAUABnCDRm - LpTAUABChannelReg->usTAUABnCNTm;
  #endif
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "Memmap.h"

#if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON) || \
(ICU_TAUB_UNIT_USED == STD_ON))
/*******************************************************************************
** Function Name        : Icu_ServiceSignalMeasurement
**
** Service ID           : None
**
** Description          : This service routine calculates the channel's Signal
**                        Time (Low, High, Period or Duty) based on its
**                        configuration.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelConfig, Icu_GpSignalMeasurementData
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE)Icu_ServiceSignalMeasurement
(Icu_ChannelType LddChannel)
{
  /* Defining a pointer to point to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpChannelConfig;

  /* Define a pointer to point to the timer channel configuration parameters */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  /* Pointer definition for Signal Measurement Channel properties */
  P2CONST(Tdd_Icu_SignalMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                              LpSignalMeasure;
  /* Pointer definition for Signal Measurement RAM data */
  P2VAR(Tdd_Icu_SignalMeasureChannelRamDataType, AUTOMATIC,ICU_CONFIG_DATA)
                                                          LpSignalMeasureData;
  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUA/B registers */
  P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC,ICU_CONFIG_DATA)
                                                              LpTAUABChannelReg;
  #endif
  #if(ICU_TAUJ_UNIT_USED == STD_ON)
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Tdd_Icu_TAUJChannelUserRegs, AUTOMATIC,ICU_CONFIG_DATA)
                                                               LpTAUJChannelReg;
  #endif

  Icu_SignalMeasurementPropertyType LddMeasureProperty;
  uint8 LucOverflowFlag = ICU_ZERO;
  uint8 LucRamIndex;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Read channel configuration pointer */
  LpChannelConfig = Icu_GpChannelConfig + LddChannel;

  /* Read timer channel configuration pointer */
  LpTimerChannelConfig = Icu_GpTimerChannelConfig + LddChannel;

  /* Read the channel properties */
  LpSignalMeasure = LpTimerChannelConfig->pChannelProp;
  /* Read the channel ram index */
  LucRamIndex = LpSignalMeasure->ucSignalMeasureRamDataIndex;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Read channel measurement property */
  LpSignalMeasureData = Icu_GpSignalMeasurementData + LucRamIndex;
  LddMeasureProperty = (Icu_SignalMeasurementPropertyType)
  LpSignalMeasure->uiSignalMeasurementProperty;

  #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
  if((LpChannelConfig->uiIcuChannelType == ICU_HW_TAUA) ||
                           (LpChannelConfig->uiIcuChannelType == ICU_HW_TAUB))
  #endif
  {
    #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
    /* Initialize pointer to the base address of the current channel */
    LpTAUABChannelReg =
    (P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                            LpChannelConfig->pCntlRegs;

    /* Set the value of overflow flag as per the value set in CSR register */
    LucOverflowFlag = LpTAUABChannelReg->ucTAUABnCSRm & ICU_OVERFLOW_BIT_MASK;

    if((LddMeasureProperty == (ICU_HIGH_TIME)) ||
                                     (LddMeasureProperty == (ICU_LOW_TIME)))
    /* Calculate Active time */
    {
      if(LucOverflowFlag == ICU_ZERO)
      {
        LpSignalMeasureData->ulSignalActiveTime =
            ((LpTAUABChannelReg->usTAUABnCDRm) + 1);
      }
      else
      {
        /* Maximum count value */
        LpSignalMeasureData->ulSignalActiveTime = ICU_TAUAB_MAX_CNT_VAL;
      }
    }
    else /* (LddMeasureProperty == (ICU_PERIOD_TIME)) */
    {
      LpSignalMeasureData->ulPrevSignalActiveTime =
                                       LpSignalMeasureData->ulSignalActiveTime;
      if(LucOverflowFlag == ICU_ZERO)
      {
        /* Calculate Period time */
        LpSignalMeasureData->ulSignalPeriodTime =
            ((LpTAUABChannelReg->usTAUABnCDRm) + 1);
      }
      else
      {
        /* Maximum count value */
        LpSignalMeasureData->ulSignalPeriodTime = ICU_TAUAB_MAX_CNT_VAL;
      }
    }
    /* Clear the Overflow flag */
      LpTAUABChannelReg->ucTAUABnCSCm = ICU_ONE;
    #endif /* End of
          ((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
  }
  #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
  else if(LpChannelConfig->uiIcuChannelType == ICU_HW_TAUJ)
  #endif
  {
    #if(ICU_TAUJ_UNIT_USED == STD_ON)
    /* Initialize pointer to the base address of the current channel */
    LpTAUJChannelReg =
    (P2VAR(Tdd_Icu_TAUJChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                            LpChannelConfig->pCntlRegs;
    /* Set the value of overflow flag as per the value set in CSR register */
    LucOverflowFlag = LpTAUJChannelReg->ucTAUJnCSRm & ICU_OVERFLOW_BIT_MASK;

    if ((LddMeasureProperty == (ICU_HIGH_TIME)) ||
                                     (LddMeasureProperty == (ICU_LOW_TIME)))
    /* Calculate Active time */
    {
      if(LucOverflowFlag == ICU_ZERO)
      {
        LpSignalMeasureData->ulSignalActiveTime =
            ((LpTAUJChannelReg->ulTAUJnCDRm) + 1);
      }
      else
      {
        /* Maximum count value */
        LpSignalMeasureData->ulSignalActiveTime = ICU_TAUJ_MAX_CNT_VAL;
      }
    }
    else /* (LddMeasureProperty == (ICU_PERIOD_TIME)) */
    {
      LpSignalMeasureData->ulPrevSignalActiveTime =
                                     LpSignalMeasureData->ulSignalActiveTime;
      if(LucOverflowFlag == ICU_ZERO)
      {
        /* Calculate Period time */
        LpSignalMeasureData->ulSignalPeriodTime =
            ((LpTAUJChannelReg->ulTAUJnCDRm) + 1);
      }
      else
      {
        /* Maximum count value */
        LpSignalMeasureData->ulSignalPeriodTime = ICU_TAUJ_MAX_CNT_VAL;
      }
    }
    /* Clear the Overflow flag */
    LpTAUJChannelReg->ucTAUJnCSCm = ICU_ONE;
    #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
  }
  #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
  else
  {
    /* To avoid MISRA warning */
  }
  #endif
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of
        * ((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON) || \
        * (ICU_TAUB_UNIT_USED == STD_ON))
        */

/*******************************************************************************
** Function Name        : Icu_ServiceTimestamp
**
** Service ID           : None
**
** Description          : This service routine captures the channel's Timestamp
**                        data based on its active edge configuration.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannel, LulCapturedTimestampVal
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelConfig, Icu_GpTimeStampData,
**                        Icu_GstChannelFunc
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE)Icu_ServiceTimestamp
(Icu_ChannelType LddChannel, uint32 LulCapturedTimestampVal)
{
  /* Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpTimerChannelConfig;
  /* Pointer definition for Timestamp Channel properties */
  P2CONST(Tdd_Icu_TimeStampMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                    LpTimestamp;
  P2VAR(Tdd_Icu_TimeStampChannelRamDataType, AUTOMATIC,ICU_CONFIG_DATA)
                                                                LpTimestampdata;
  /* Local variable used to store the ram index of the channel */
  uint8 LucRamIndex;
  #if(ICU_NOTIFICATION_CONFIG == STD_ON)
  /* Local variable for the index to the call-back function */
  uint8 LucIndex;
  #endif
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Load timer channel configuration pointer and channel properties */
  LpTimerChannelConfig = Icu_GpTimerChannelConfig + LddChannel;
  LpTimestamp = LpTimerChannelConfig->pChannelProp;
  /* Read channel ram index */
  LucRamIndex = LpTimestamp->ucTimeStampRamDataIndex;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Read the Timestamp channel data pointer */
  LpTimestampdata = Icu_GpTimeStampData + LucRamIndex;

  /* Check if timestamp capturing reached end of the buffer */
  if((LpTimestampdata->usTimestampIndex) < (LpTimestampdata->usBufferSize))
  {
    /* Update the buffer pointer with current timestamp */
    *(LpTimestampdata->pBufferPointer) = LulCapturedTimestampVal;
    (LpTimestampdata->usTimestampIndex)++;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */
    (LpTimestampdata->pBufferPointer)++;
    (LpTimestampdata->usTimestampsCounter)++;

    /*
     * Notify if the configured number of timestamps are captured and
     * notification is enabled
     */

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    #if(ICU_NOTIFICATION_CONFIG == STD_ON)
    if(((LpTimestampdata->usTimestampsCounter) ==
    (LpTimestampdata->usNotifyInterval)) &&
    (((Icu_GpChannelRamData + LddChannel)->uiNotificationEnable) == ICU_TRUE))
    {
      /* Reset the number of timestamp captured counter */
      LpTimestampdata->usTimestampsCounter = ICU_ZERO;

      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Read the function pointer address */
      LucIndex = (Icu_GpChannelConfig + LddChannel)->ucIcuNotificationIndex;
      if(LucIndex != ICU_NO_CBK_CONFIGURED)
      {
        Icu_GstChannelFunc[LucIndex].pIcuNotificationPointer();
      }
    }
    #endif  /*if (ICU_NOTIFICATION_CONFIG == STD_ON) */
    /* Check whether the timestamp index has reached the end of buffer */
    if((LpTimestampdata->usTimestampIndex) >= (LpTimestampdata->usBufferSize))
    {
      /*  Check if buffer is configured as circular */
      if(LpTimestamp->uiTimestampMeasurementProperty == ICU_CIRCULAR_BUFFER)
      {
        /* Reset buffer pointer and index */
        LpTimestampdata->usTimestampIndex = ICU_ZERO;
        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */
        LpTimestampdata->pBufferPointer -= LpTimestampdata->usBufferSize;
      }
    }
  }
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON) \
|| (ICU_TAUB_UNIT_USED == STD_ON))
/*******************************************************************************
** Function Name        : Icu_TimerIsr
**
** Service ID           : None
**
** Description          : This service routine invokes the required function
**                        based on the channel configuration for further
**                        calculations.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelConfig, Icu_GpChannelMap,
**                        Icu_GpChannelRamData, Icu_GenModuleMode
**
**                        Function(s) invoked:
**                        Icu_ServiceSignalMeasurement, Icu_ServiceTimestamp,
**                        EcuM_CheckWakeup
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_TimerIsr(Icu_ChannelType LddChannel)
{
  /* Defining a pointer to point to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpChannelConfig;
  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Define a pointer to point to the timer channel configuration parameters */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  /* Pointer definition for Edge Count Channel properties */
  P2CONST(Tdd_Icu_EdgeCountConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpEdgeCount;
  /* Defining a pointer to point to the TAUA/B registers */
  P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC,ICU_CONFIG_DATA)
                                                              LpTAUABChannelReg;
  #endif
  #if(ICU_TAUJ_UNIT_USED == STD_ON)
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Tdd_Icu_TAUJChannelUserRegs, AUTOMATIC,ICU_CONFIG_DATA)
                                                               LpTAUJChannelReg;
  #endif

  Icu_MeasurementModeType LddMeasurementMode;
  Icu_ChannelType LddChannelMap;
  uint32 LulCapturedTimestampVal;

  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  uint8 LucIndex;
  #endif

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Load Channel index of Icu_GstChannelConfig */
  LddChannelMap = *(Icu_GpChannelMap + LddChannel);
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Update the channel pointer to point to the current channel */
  LpChannelConfig = Icu_GpChannelConfig + LddChannelMap;
  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  /* Update the timer channel pointer to point to the current channel */
  LpTimerChannelConfig = Icu_GpTimerChannelConfig + LddChannelMap;
  #endif
  /* Read the channel's measurement property */
  LddMeasurementMode =
              (Icu_MeasurementModeType)(LpChannelConfig->uiIcuMeasurementMode);

  /* Check whether the channel is configured for Signal Measurement */
  if(LddMeasurementMode == ICU_MODE_SIGNAL_MEASUREMENT)
  {
    /* Process Signal Measurement */
    Icu_ServiceSignalMeasurement(LddChannelMap);
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Set channel input status as active */
    (Icu_GpChannelRamData + LddChannelMap)->uiChannelStatus = ICU_ACTIVE;
  }
  /* Check whether the channel is configured for Timestamp */
  else if(LddMeasurementMode == ICU_MODE_TIMESTAMP)
  {
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                           && (ICU_TAUJ_UNIT_USED == STD_ON))
    if((LpChannelConfig->uiIcuChannelType == ICU_HW_TAUA) ||
                           (LpChannelConfig->uiIcuChannelType == ICU_HW_TAUB))
    #endif
    {
      #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
      /* Initialize pointer to the base address of the current channel */
      LpTAUABChannelReg =
      (P2VAR(Tdd_Icu_TAUABChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                                LpChannelConfig->pCntlRegs;

      /* Calculate captured value */
      LulCapturedTimestampVal = ((LpTAUABChannelReg->usTAUABnCDRm) + 1);

      /* Process Timestamp */
      Icu_ServiceTimestamp(LddChannelMap, LulCapturedTimestampVal);
      #endif /* End of
          ((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
    }
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    else if(LpChannelConfig->uiIcuChannelType == ICU_HW_TAUJ)
    #endif
    {
      #if(ICU_TAUJ_UNIT_USED == STD_ON)
      /* Initialize pointer to the base address of the current channel */
      LpTAUJChannelReg =
      (P2VAR(Tdd_Icu_TAUJChannelUserRegs, AUTOMATIC, ICU_CONFIG_CONST))
                                                LpChannelConfig->pCntlRegs;

      /* Calculate captured value */
      LulCapturedTimestampVal = ((LpTAUJChannelReg->ulTAUJnCDRm) + 1);

      /* Process Timestamp */
      Icu_ServiceTimestamp(LddChannelMap, LulCapturedTimestampVal);
      #endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */
    }
    #if(((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) \
                                             && (ICU_TAUJ_UNIT_USED == STD_ON))
    else
    {
      /* To avoid MISRA warning */
    }
    #endif
  }
  else /* if(LddMeasurementMode == ICU_MODE_EDGE_COUNTER) */
  {
    #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
    /* Read the edge count channel properties and the ram index */
    LpEdgeCount = LpTimerChannelConfig->pChannelProp;
    LucIndex = LpEdgeCount->ucEdgeCounterRamIndex;

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Reset the edge count overflow flag */
   (Icu_GpEdgeCountData + LucIndex)->uiTimerOvfFlag = ICU_TRUE;
   #endif /* End of
          ((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
  }

  #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  /* If Module was in SLEEP mode and reporting wakeup is enabled */
  if(Icu_GenModuleMode == ICU_MODE_SLEEP)
  {
    /* Report Wakeup Event to EcuM */
    EcuM_CheckWakeup(LpChannelConfig->ddEcuMChannelWakeupInfo);
  }
  #endif /* End of (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of
        * ((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON) \
        * || (ICU_TAUB_UNIT_USED == STD_ON))
        */

/*******************************************************************************
** Function Name        : Icu_ExternalInterruptIsr
**
** Service ID           : None
**
** Description          : This service routine is invoked from all the external
**                        interrupts which takes care of calling the
**                        notification functions.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddChannel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelConfig, Icu_GpChannelMap,
**                        Icu_GpChannelRamData, Icu_GstChannelFunc
**
**                        Function(s) invoked:
**                        EcuM_CheckWakeup
*******************************************************************************/
#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ICU_PRIVATE_CODE) Icu_ExternalInterruptIsr
(Icu_ChannelType LddChannel)
{
  Icu_ChannelType LddChannelMap;
  #if(ICU_NOTIFICATION_CONFIG == STD_ON)
  uint8 LucIndex;
  #endif /* End of (ICU_NOTIFICATION_CONFIG == STD_ON) */

  /* Defining a pointer to point to the channel configuration parameters */
  #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                              LpChannelConfig;
  #endif /* End of (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Load Channel index of Icu_GstChannelConfig */
  LddChannelMap = *(Icu_GpChannelMap + LddChannel);
  #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Update the channel pointer to point to the current channel */
  LpChannelConfig = Icu_GpChannelConfig + LddChannelMap;
  #endif /* End of (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  #if(ICU_NOTIFICATION_CONFIG == STD_ON)
  /* Check if notification is enabled */
  if(((Icu_GpChannelRamData + LddChannelMap)->uiNotificationEnable) ==
                                                                      ICU_TRUE)
  {
    /* Read the function pointer address */
    LucIndex = (Icu_GpChannelConfig + LddChannelMap)->ucIcuNotificationIndex;
    if(LucIndex != ICU_NO_CBK_CONFIGURED)
    {
      Icu_GstChannelFunc[LucIndex].pIcuNotificationPointer();
    }
  }
  #endif /* End of (ICU_NOTIFICATION_CONFIG == STD_ON) */

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Set channel input status as active */
  (Icu_GpChannelRamData + LddChannelMap)->uiChannelStatus = ICU_ACTIVE;

  #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  /* If Module was in SLEEP mode and reporting wakeup is enabled */
  if(Icu_GenModuleMode == ICU_MODE_SLEEP)
  {
    /* Report Wakeup Event to EcuM */
    EcuM_CheckWakeup(LpChannelConfig->ddEcuMChannelWakeupInfo);
  }
  #endif /* End of (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
}

#define ICU_STOP_SEC_PRIVATE_CODE
#include "Memmap.h"

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/