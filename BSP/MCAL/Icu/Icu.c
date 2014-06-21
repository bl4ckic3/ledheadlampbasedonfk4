/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu.c                                                       */
/* Version      = 3.0.7a                                                      */
/* Date         = 22-Sep-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API implementations of Icu Driver Component.            */
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
 * V3.0.1:  29-Oct-2009  : As per SCR 074, a MISRA message is added at
 *                         line number 2581.
 *
 * V3.0.2:  25-Feb-2010  : As per SCR 192, pointer to the ICU Channel
 *                         properties based on Measurement Mode is moved from
 *                         'Tdd_Icu_ChannelConfigType' structure to
 *                         'Tdd_Icu_TimerChannelConfigType' structure.
 *
 * V3.0.3:  18-Mar-2010  : As per SCR 230, APIs are updated to avoid
 *                         reading from uninitialized pointers.
 *
 * V3.0.4:  06-Apr-2010  : As per SCR 242, condition check for DET error
 *                         ICU_E_PARAM_MODE is updated in API Icu_SetMode.
 *
 * V3.0.5:  28-Jun-2010  : As per SCR 286, following changes are done:
 *                         1. The API Icu_EnableNotification is updated to
 *                            use IMR registers to enable/disable interrupts.
 *                         2. The edge count functionality is modified to
 *                            support the use of Timer Array Unit B.
 *
 * V3.0.6:  20-Jul-2010  : As per SCR 308, the API Icu_Init() is updated with
 *                         pre-compile options for timer channels.
 *
 * V3.0.7:  26-Aug-2010  : As per SCR 335, following changes are done:
 *                         1. The APIs Icu_GetTimeElapsed and
 *                         Icu_GetDutyCycleValues are updated to modify the
 *                         signal measurement functionality.
 *                         2. The APIs Icu_Init, Icu_StartTimestamp and
 *                         Icu_GetTimestampIndex are updated to modify
 *                         the timestamping functionality.
 *                         3. SW Patch version details are removed.
 * V3.0.7a  22-Sep-2011  : As per MANTIS 3551, the API Icu_EnableNotification
 *                         is updated to add clearing interrupt request flag.
 *                         As per MANTIS 3708, the API Icu_GetDutyCycleValues
 *                         is updated to modify the previous active time.
 *                         Copyright is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Icu.h"
#include "Icu_PBTypes.h"
#include "Icu_LTTypes.h"
#include "Icu_LLDriver.h"
#include "Icu_Irq.h"
#include "Icu_Ram.h"
#if (ICU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Icu.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification version information */
#define ICU_C_AR_MAJOR_VERSION    ICU_AR_MAJOR_VERSION_VALUE
#define ICU_C_AR_MINOR_VERSION    ICU_AR_MINOR_VERSION_VALUE
#define ICU_C_AR_PATCH_VERSION    ICU_AR_PATCH_VERSION_VALUE

/* File version information */
#define ICU_C_SW_MAJOR_VERSION    3
/* MISRA Rule         : 1.1                                      */
/* Message            : Number of macro definitions should not   */
/*                      exceed 1024.                             */
/* Reason             : Since there are more number of macros    */
/*                      used, this warning occurs  .             */
/* Verification       : However, the part of the code is         */
/*                      verified manually and it is not having   */
/*                      any impact on code.                      */
#define ICU_C_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (ICU_AR_MAJOR_VERSION != ICU_C_AR_MAJOR_VERSION)
  #error "Icu.c : Mismatch in Specification Major Version"
#endif

#if (ICU_AR_MINOR_VERSION != ICU_C_AR_MINOR_VERSION)
  #error "Icu.c : Mismatch in Specification Minor Version"
#endif

#if (ICU_AR_PATCH_VERSION != ICU_C_AR_PATCH_VERSION)
  #error "Icu.c : Mismatch in Specification Patch Version"
#endif

#if (ICU_SW_MAJOR_VERSION != ICU_C_SW_MAJOR_VERSION)
  #error "Icu.c : Mismatch in Major Version"
#endif

#if (ICU_SW_MINOR_VERSION != ICU_C_SW_MINOR_VERSION)
  #error "Icu.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Icu_Init
**
** Service ID           : 0x00
**
** Description          : This API performs the initialization of the Icu Driver
**                        Component.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : ConfigPtr
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
**                        Icu_GpConfigPtr, Icu_GpChannelConfig,
**                        Icu_GpTimerChannelConfig, Icu_GpChannelMap,
**                        Icu_GpTAUUnitConfig, Icu_GpPreviousInputConfig
**                        Icu_GpChannelRamData, Icu_GpSignalMeasurementData,
**                        Icu_GpTimeStampData, Icu_GpEdgeCountData,
**                        Icu_GblDriverStatus, Icu_GenModuleMode
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWInit
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_Init
(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr)
{
  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)||\
  (ICU_TAUB_UNIT_USED == STD_ON))
  /* Defining a pointer to the channel config parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannel;
  /* Defining a pointer to the channel config parameters */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                 LpTimerChannel;
  /* Pointer definition for Timestamp Channel properties */
  P2CONST(Tdd_Icu_TimeStampMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                    LpTimestamp;
  /* Local variable to store Measurement Mode */
  Icu_MeasurementModeType LddMeasurementMode;
  uint8 LucIndex;
  #endif
  /* Defining a pointer to the Channel Ram Data */
  P2VAR(Tdd_Icu_ChannelRamDataType, AUTOMATIC,ICU_CONFIG_DATA) LpRamData;
  /* Local variable to hold the channel number */
  uint8 LucChannelNo;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;
  /* Check if the ICU Driver is already initialized */
  if(Icu_GblDriverStatus == ICU_INITIALIZED)
  {
    /* Report Error to DET */
    Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_INIT_SID,
                                                    ICU_E_ALREADY_INITIALIZED);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }

  /* Check if the Configuration pointer is NULL */
  if(ConfigPtr == NULL_PTR)
  {
    /* Report Error to Det */
    Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_INIT_SID,
                                                           ICU_E_PARAM_CONFIG);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Rule         : 1.2                                      */
    /* Message            : Dereferencing pointer value that is      */
    /*                      apparently NULL.                         */
    /* Reason             : "Config" pointer is checked and verified */
    /*                      when DET is switched STD_ON.             */
    /* Verification       : However, the part of the code is         */
    /*                      verified manually and it is not having   */
    /*                      any impact on code.                      */

    /* Check if the database is flashed on the target device */
    if((ConfigPtr->ulStartOfDbToc) == ICU_DBTOC_VALUE)
    {
      /* Update the global pointer with the database configuration pointer */
      Icu_GpConfigPtr = ConfigPtr;
      /*
       * Update the global pointer with the first channel's configuration
       * database address
       */
      Icu_GpChannelConfig = ConfigPtr->pChannelConfig;
      #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)||\
      (ICU_TAUB_UNIT_USED == STD_ON))
      /*
       * Update the global pointer with the first Timer channel's configuration
       * database address
       */
      Icu_GpTimerChannelConfig = ConfigPtr->pTimerChannelConfig;
      /* Update the global pointer with the ICU Hardware unit configuration */
      Icu_GpTAUUnitConfig = ConfigPtr->pHWUnitConfig;
      #endif
      #if(ICU_PREVIOUS_INPUT_USED == STD_ON)
      /* Update the global pointer with the Previous input configuration */
      Icu_GpPreviousInputConfig = ConfigPtr->pPrevInputConfig;
      #endif
      /* Update the global pointer with the first channel's ram address */
      Icu_GpChannelRamData = ConfigPtr->pRamAddress;
      #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)||\
      (ICU_TAUB_UNIT_USED == STD_ON))
      /*
       * Update the global pointer with the first channel's address
       * of Signal Measurement mode type channel's RAM data
       */
      Icu_GpSignalMeasurementData = ConfigPtr->pSignalMeasureAddress;
      /*
       * Update the global pointer with the first channel's address
       * of Timestamp mode type channel's RAM data
       */
      Icu_GpTimeStampData = ConfigPtr->pTimeStampAddress;
      /*
       * Update the global pointer with the first channel's address
       * of Edge Count mode type channel's RAM data
       */
      Icu_GpEdgeCountData = ConfigPtr->pEdgeCountRamAddress;
      #endif
      /* Update the global pointer with the channel's map */
      Icu_GpChannelMap = ConfigPtr->pChannelMap;
      /* Initialize all the configured Icu Channels */
      for(LucChannelNo = ICU_ZERO; LucChannelNo < ICU_MAX_CHANNEL;
                                                                LucChannelNo++)
      {
        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */

        /* Load the channel data pointer */
        LpRamData = Icu_GpChannelRamData + LucChannelNo;
        /* Initialize each channel status as idle */
        LpRamData->uiChannelStatus = ICU_IDLE;
        /* Disable each channel wakeup from sleep mode */
        LpRamData->uiWakeupEnable = ICU_FALSE;
        /* Disable notification for each channel */
        LpRamData->uiNotificationEnable = ICU_FALSE;

        #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)||\
        (ICU_TAUB_UNIT_USED == STD_ON))
        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */
        /* Load the channel pointer */
        LpChannel = Icu_GpChannelConfig + LucChannelNo;
        /* Load the timer channel pointer */
        LpTimerChannel = Icu_GpTimerChannelConfig + LucChannelNo;

        /* Read the Measurement mode of the channel */
        LddMeasurementMode =
                  (Icu_MeasurementModeType)LpChannel->uiIcuMeasurementMode;

        /* Check whether measurement mode is timestamp */
        if(LddMeasurementMode == ICU_MODE_TIMESTAMP)
        {
          /* Load the Timestamp Channel pointer */
          LpTimestamp = LpTimerChannel->pChannelProp;
          /* Read the current activation edge from RAM */
          LucIndex = LpTimestamp->ucTimeStampRamDataIndex;

          /* MISRA Rule         : 17.4                            */
          /* Message            : Performing pointer arithmetic.  */
          /* Reason             : For code optimization.          */
          /* Verification       : However, part of the code is    */
          /*                      verified manually and it is not */
          /*                      having any impact.              */

          /* Reset the flag to indicate that the timestamping is not started */
          (Icu_GpTimeStampData + LucIndex)->blTimestampingStarted = ICU_FALSE;
        }
        #endif
      }
      /* Invoke low level driver for initializing the hardware */
      Icu_HWInit();
      #if(ICU_DEV_ERROR_DETECT == STD_ON)
      /* Set Icu Driver status as initialized */
      Icu_GblDriverStatus = ICU_INITIALIZED;
      #endif
      /* Set Icu Driver Mode as normal */
      Icu_GenModuleMode = ICU_MODE_NORMAL;
    }
    #if(ICU_DEV_ERROR_DETECT == STD_ON)
    /*If there is no valid database is present */
    else
    {
      /* Report to DET */
      Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,ICU_INIT_SID,
                                                       ICU_E_INVALID_DATABASE);
    }
    #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#if (ICU_DE_INIT_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_DeInit
**
** Service ID           : 0x01
**
** Description          : This API performs the De-Initialization of the Icu
**                        Driver Component by making all the registers to the
**                        power on reset state.
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
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GblDriverStatus
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWDeInit
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_DeInit(void)
{
  /* Defining a pointer to the Timer registers */
  P2VAR(Tdd_Icu_ChannelRamDataType, AUTOMATIC,ICU_CONFIG_DATA) LpRamData;

  /* Local variable to hold the channel number */
  uint8 LucChannelNo;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
   /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_DEINIT_SID,
                                                                 ICU_E_UNINIT);
  }
  else
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    for(LucChannelNo = ICU_ZERO; LucChannelNo < ICU_MAX_CHANNEL;
                                                               LucChannelNo++)
    {
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Load the channel data pointer */
      LpRamData = Icu_GpChannelRamData + LucChannelNo;
      /* Initialize each channel status as idle */
      LpRamData->uiChannelStatus = ICU_IDLE;
      /* Disable each channel wakeup from sleep mode */
      LpRamData->uiWakeupEnable = ICU_FALSE;
      /* Disable notification for each channel */
      LpRamData->uiNotificationEnable = ICU_FALSE;
    }
    /* Invoke low level driver for De-Initializing the hardware */
    Icu_HWDeInit();
    #if(ICU_DEV_ERROR_DETECT == STD_ON)
    /* Set Icu Driver status as un-initialized */
    Icu_GblDriverStatus = ICU_UNINITIALIZED;
    #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_DE_INIT_API == STD_ON) */

#if (ICU_SET_MODE_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_SetMode
**
** Service ID           : 0x02
**
** Description          : This API service will set the operation mode of the
**                        Icu Driver.
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
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GblDriverStatus, Icu_GpChannelConfig
**                        Icu_GpChannelRamData
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWSetMode
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_SetMode(Icu_ModeType Mode)
{
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannel;
  /* Local variable to store Measurement Mode */
  Icu_MeasurementModeType LddMeasurementMode;
  /* Local variable to loop through the channels */
  uint8 LucChannelNo = ICU_ZERO;
  /* Local variable to store the channel status */
  uint8 LenChannelStatus;
  /* Local variable to store error status */
  uint8 LucRunningOperation = ICU_FALSE;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;

  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_SET_MODE_SID,
                                                                 ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }

  /* MISRA Rule         : 13.7                             */
  /* Message            : The result of this logical       */
  /*                      operation or control expression  */
  /*                      is always 'false'.               */
  /* Reason             : As per AUTOSAR all the input     */
  /*                      parameters of an API have to be  */
  /*                      verified.                        */
  /* Verification       : However, part of the code is     */
  /*                      verified manually and it is not  */
  /*                      having any impact.               */

  /* Check if mode is neither ICU_MODE_NORMAL nor ICU_MODE_SLEEP */
  if((Mode != ICU_MODE_NORMAL) && (Mode != ICU_MODE_SLEEP))
  /* MISRA Rule         : 14.1                             */
  /* Message            : This statement is unreachable.   */
  /* Reason             : As per AUTOSAR all the input     */
  /*                      parameters of an API have to be  */
  /*                      verified.                        */
  /* Verification       : However, part of the code is     */
  /*                      verified manually and it is not  */
  /*                      having any impact.               */
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_SET_MODE_SID,
                                                             ICU_E_PARAM_MODE);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif  /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    do
    {
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Load the channel pointer */
      LpChannel = Icu_GpChannelConfig + LucChannelNo;
      /* Read the Measurement mode of the channel */
      LddMeasurementMode =
                    (Icu_MeasurementModeType)LpChannel->uiIcuMeasurementMode;

      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Read the channel status */
      LenChannelStatus =
                     (Icu_GpChannelRamData + LucChannelNo)->uiChannelStatus;

      /* Check whether Timestamping or Edge counting is in progress */
      if (((LddMeasurementMode == ICU_MODE_EDGE_COUNTER) ||
      (LddMeasurementMode == ICU_MODE_TIMESTAMP)) &&
      (LenChannelStatus == ICU_ACTIVE))
      {
        /* Update running operation as TRUE */
        LucRunningOperation = ICU_TRUE;
      }
      LucChannelNo++;
    } while((LucChannelNo < ICU_MAX_CHANNEL) &&
                                            (LucRunningOperation != ICU_TRUE));
  }
  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  if((Mode == ICU_MODE_SLEEP) && (LucRunningOperation == ICU_TRUE))
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_SET_MODE_SID,
                                                        ICU_E_BUSY_OPERATION);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Set operation mode to SLEEP provided there is no running operation */
    if((Mode == ICU_MODE_NORMAL) || (LucRunningOperation == ICU_FALSE))
    {
      Icu_HWSetMode(Mode);
    }
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_SET_MODE_API == STD_ON) */

#if(ICU_DISABLE_WAKEUP_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_DisableWakeup
**
** Service ID           : 0x03
**
** Description          : This API service will disable the wakeup interrupt of
**                        the requested Icu channel. The requested channel must
**                        be wakeup capable.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GblDriverStatus, Icu_GpChannelConfig,
**                        Icu_GpChannelRamData, Icu_GpChannelMap
**
**                        Function(s) invoked:
**                        Det_ReportError
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_DisableWakeup (Icu_ChannelType Channel)
{
  Icu_ChannelType LddChannel;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;

  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_DISABLE_WAKEUP_SID,
                                                                 ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_DISABLE_WAKEUP_SID,
                                                          ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuWakeupCapability == ICU_FALSE))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_DISABLE_WAKEUP_SID,
                                                          ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Store the disabled wakeup status into RAM */
    (Icu_GpChannelRamData + LddChannel)->uiWakeupEnable = ICU_FALSE;
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_DISABLE_WAKEUP_API == STD_ON) */

#if(ICU_ENABLE_WAKEUP_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_EnableWakeup
**
** Service ID           : 0x04
**
** Description          : This API service will enable the wakeup interrupt of
**                        the requested Icu channel. The requested channel must
**                        be wakeup capable.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GblDriverStatus, Icu_GpChannelRamData,
**                        Icu_GpChannelMap, Icu_GpChannelConfig
**
**                        Function(s) invoked:
**                        Det_ReportError
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_EnableWakeup(Icu_ChannelType Channel)
{
  Icu_ChannelType LddChannel;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;

  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_ENABLE_WAKEUP_SID,
                                                                 ICU_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_ENABLE_WAKEUP_SID,
                                                          ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuWakeupCapability == ICU_FALSE))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_ENABLE_WAKEUP_SID,
                                                          ICU_E_PARAM_CHANNEL);
      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Store the enabled wakeup status into RAM */
    (Icu_GpChannelRamData + LddChannel)->uiWakeupEnable = ICU_TRUE;
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_ENABLE_WAKEUP_API == STD_ON) */

/*******************************************************************************
** Function Name        : Icu_SetActivationCondition
**
** Service ID           : 0x05
**
** Description          : This API service will set the activation edge
**                        according to the Activation parameter for the given
**                        channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel, Activation
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GpChannelConfig,
**                        Icu_GblDriverStatus, Icu_GpChannelRamData,
**                        Icu_GpTimeStampData, Icu_GpEdgeCountData
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWSetActivation
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_SetActivationCondition
(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
  /* Defining a pointer to point to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannel;
  /* Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                 LpTimerChannel;
  /* Pointer definition for Timestamp Channel properties */
  P2CONST(Tdd_Icu_TimeStampMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
  LpTimestamp;
  /* Pointer definition for Edge Count Channel properties */
  P2CONST(Tdd_Icu_EdgeCountConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpEdgeCount;
  Icu_MeasurementModeType LddMeasurementMode;
  uint8 LddChannel;
  uint8 LucIndex;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;

  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                               ICU_SET_ACTIVATION_CONDITION_SID, ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  /* MISRA Rule         : 13.7                             */
  /* Message            : The result of this logical       */
  /*                      operation or control expression  */
  /*                      is always 'false'.               */
  /* Reason             : As per AUTOSAR all the input     */
  /*                      parameters of an API have to be  */
  /*                      verified.                        */
  /* Verification       : However, part of the code is     */
  /*                      verified manually and it is not  */
  /*                      having any impact.               */
  if(Activation > ICU_BOTH_EDGES)
  /* MISRA Rule         : 14.1                             */
  /* Message            : This statement is unreachable.   */
  /* Reason             : As per AUTOSAR all the input     */
  /*                      parameters of an API have to be  */
  /*                      verified.                        */
  /* Verification       : However, part of the code is     */
  /*                      verified manually and it is not  */
  /*                      having any impact.               */
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                     ICU_SET_ACTIVATION_CONDITION_SID, ICU_E_PARAM_ACTIVATION);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                        ICU_SET_ACTIVATION_CONDITION_SID, ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode
                                              == ICU_MODE_SIGNAL_MEASUREMENT))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                        ICU_SET_ACTIVATION_CONDITION_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Load channel pointer */
    LpChannel = Icu_GpChannelConfig + LddChannel;
    /* Read the Channel Measurement Mode */
    LddMeasurementMode =
                      (Icu_MeasurementModeType)LpChannel->uiIcuMeasurementMode;

    /* Load timer channel pointer */
    LpTimerChannel = Icu_GpTimerChannelConfig + LddChannel;

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Initialize channel status as idle */
    (Icu_GpChannelRamData + LddChannel)->uiChannelStatus = ICU_IDLE;
    if(LddMeasurementMode == ICU_MODE_TIMESTAMP)
    {
      /* Load the Timestamp Channel pointer */
      LpTimestamp = LpTimerChannel->pChannelProp;
      /* Read the current activation edge from RAM */
      LucIndex = LpTimestamp->ucTimeStampRamDataIndex;

      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */
      (Icu_GpTimeStampData + LucIndex)->ucActiveEdge = Activation;
      Icu_HWSetActivation (LddChannel, Activation);
    }
    else if(LddMeasurementMode == ICU_MODE_EDGE_COUNTER)
    {
      /* Load the Edge Count Channel pointer */
      LpEdgeCount = LpTimerChannel->pChannelProp;
      /* Read the current activation edge from RAM */
      LucIndex = LpEdgeCount->ucEdgeCounterRamIndex;

      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */
      (Icu_GpEdgeCountData + LucIndex)->ucActiveEdge = Activation;
      Icu_HWSetActivation (LddChannel, Activation);
    }
    #if(ICU_EDGE_DETECTION_API == STD_ON)
    else /* if(LddMeasurementMode == ICU_MODE_SIGNAL_EDGE_DETECT) */
    {
      /* Activate External Interrupt as requested */
      Icu_HWSetActivation (LddChannel, Activation);
    }
    #endif /* End of (ICU_EDGE_DETECTION_API == STD_ON) */
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_DisableNotification
**
** Service ID           : 0x06
**
** Description          : This API service will disable the Icu signal
**                        notification of the requested channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GblDriverStatus,
**                        Icu_GpChannelConfig, Icu_GpChannelRamData
**
**                        Function(s) invoked:
**                        Det_ReportError
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_DisableNotification(Icu_ChannelType Channel)
{
  Icu_ChannelType LddChannel;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;
  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                   ICU_DISABLE_NOTIFICATION_SID, ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                            ICU_DISABLE_NOTIFICATION_SID, ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode ==
    ICU_MODE_SIGNAL_MEASUREMENT) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode ==
                                                        ICU_MODE_EDGE_COUNTER))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                            ICU_DISABLE_NOTIFICATION_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    else if((Icu_GpChannelRamData + LddChannel)->uiNotificationEnable
                                                                  == ICU_FALSE)
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                         ICU_DISABLE_NOTIFICATION_SID, ICU_E_ALREADY_DISABLED);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
    else
    {
      /* To avoid MISRA warning */
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Store the disabled notification into RAM */
    (Icu_GpChannelRamData + LddChannel)->uiNotificationEnable = ICU_FALSE;
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_EnableNotification
**
** Service ID           : 0x07
**
** Description          : This API service will disable the Icu signal
**                        notification of the requested channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GblDriverStatus,
**                        Icu_GpChannelConfig, Icu_GpChannelRamData
**
**                        Function(s) invoked:
**                        Det_ReportError
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_EnableNotification(Icu_ChannelType Channel)
{
  #if(ICU_EDGE_DETECTION_API == STD_ON)
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint16, AUTOMATIC,ICU_CONFIG_DATA) LpIntrCntlReg;
  /* Defining a pointer to the Interrupt Mask Register */
  P2VAR(uint8, AUTOMATIC,ICU_CONFIG_DATA) LpImrIntpCntrlReg;
  #endif /* End of (ICU_EDGE_DETECTION_API == STD_ON) */

  Icu_ChannelType LddChannel;

  #if(ICU_EDGE_DETECTION_API == STD_ON)
  /* Defining a pointer to the channel configuration parameters */
  P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST) LpChannel;
  Icu_MeasurementModeType LddMeasurementMode;
  #endif

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;
  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                    ICU_ENABLE_NOTIFICATION_SID, ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                           ICU_ENABLE_NOTIFICATION_SID, ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    if((LddChannel == ICU_CHANNEL_UNCONFIGURED)
    || ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode
    == ICU_MODE_SIGNAL_MEASUREMENT) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode
    == ICU_MODE_EDGE_COUNTER))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                             ICU_ENABLE_NOTIFICATION_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    else if((Icu_GpChannelRamData + LddChannel)->uiNotificationEnable
                                                                    == ICU_TRUE)
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                            ICU_ENABLE_NOTIFICATION_SID, ICU_E_ALREADY_ENABLED);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
    else
    {
      /* To avoid MISRA warning */
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    #if(ICU_EDGE_DETECTION_API == STD_ON)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Update the channel configuration pointer to point to the current
       channel */
    LpChannel = Icu_GpChannelConfig + LddChannel;
    /* Read the channel's measurement mode */
    LddMeasurementMode =
                      (Icu_MeasurementModeType)LpChannel->uiIcuMeasurementMode;
    #endif

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Store enabled notification into RAM */
    (Icu_GpChannelRamData + LddChannel)->uiNotificationEnable = ICU_TRUE;

    #if(ICU_EDGE_DETECTION_API == STD_ON)
    /*
     * Cancel pending interrupts in case the channel is configured for
     * edge detection functionality
     */
    if(LddMeasurementMode == ICU_MODE_SIGNAL_EDGE_DETECT)
    {
      /* Load the interrupt control register */
      LpImrIntpCntrlReg = LpChannel->pImrIntrCntlRegs;
      /* Disable channel Interrupt */
      *(LpImrIntpCntrlReg) |= ~(LpChannel->ucImrMaskValue);
      /* Load interrupt control register and disable interrupt */
      LpIntrCntlReg = LpChannel->pIntrCntlRegs;
      /* Clear the interrupt request flag */
      *(LpIntrCntlReg) &= ICU_CLEAR_INT_REQUEST_FLAG;
      /* Enable channel Interrupt */
      *(LpImrIntpCntrlReg) &= LpChannel->ucImrMaskValue;
    }
    #endif /* End of (ICU_EDGE_DETECTION_API == STD_ON) */
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_GetInputState
**
** Service ID           : 0x08
**
** Description          : This API service will return the status of the Icu
**                        input.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Icu_InputStateType
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GblDriverStatus,
**                        Icu_GpChannelConfig, Icu_GpChannelRamData
**
**                        Function(s) invoked:
**                        Det_ReportError, SchM_Enter_Icu, SchM_Exit_Icu
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Icu_InputStateType, ICU_PUBLIC_CODE) Icu_GetInputState
                                                      (Icu_ChannelType Channel)
{
  Icu_ChannelType LddChannel;
  Icu_InputStateType LddChannelState = ICU_IDLE;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;
  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to DET */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_GET_INPUT_STATE_SID,
                                                                 ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to DET */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_GET_INPUT_STATE_SID,
                                                        ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    if(LddChannel == ICU_CHANNEL_UNCONFIGURED)
    {
      /* Report Error to DET */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_GET_INPUT_STATE_SID,
                                                          ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    if(((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode !=
    ICU_MODE_SIGNAL_EDGE_DETECT) &&
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode !=
    ICU_MODE_SIGNAL_MEASUREMENT))
    {
      /* Report Error to DET */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_GET_INPUT_STATE_SID,
                                                          ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    SchM_Enter_Icu (ICU_CHANNEL_DATA_PROTECTION);
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Read the channel input status */
    LddChannelState =
       (Icu_InputStateType)(Icu_GpChannelRamData + LddChannel)->uiChannelStatus;

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Store channel status as idle */
    (Icu_GpChannelRamData + LddChannel)->uiChannelStatus = ICU_IDLE;

    #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    SchM_Exit_Icu (ICU_CHANNEL_DATA_PROTECTION);
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  return(LddChannelState);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_GET_INPUT_STATE_API == STD_ON) */

#if (ICU_TIMESTAMP_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_StartTimestamp
**
** Service ID           : 0x09
**
** Description          : This API service starts the capturing of timer values
**                        on the edges activated (rising/falling/both) to an
**                        externalbuffer at the beginning of the buffer.
**
** Sync/Async           : Asynchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel, BufferPtr, BufferSize, NotifyInterval
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GpChannelConfig,
**                        Icu_GblDriverStatus, Icu_GpTimeStampData,
**                        Icu_GpChannelRamData
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWStartCountMeasurement
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_StartTimestamp (Icu_ChannelType Channel,
P2VAR (Icu_ValueType, AUTOMATIC, ICU_APPL_DATA)BufferPtr,
uint16 BufferSize, uint16 NotifyInterval)
{
  /* Pointer for Timestamp Channel properties */
  P2CONST(Tdd_Icu_TimeStampMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                    LpTimestamp;

  /* Pointer to point to the timer channel configuration parameters */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                 LpTimerChannel;
  /* Local pointer variable for Timestamp channel data */
  P2VAR(Tdd_Icu_TimeStampChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA)
                                                                LpTimeStampData;
  Icu_ChannelType LddChannel;
  uint8 LucIndex;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;

  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_START_TIMESTAMP_SID,
                                                                 ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_START_TIMESTAMP_SID,
                                                        ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode
    != ICU_MODE_TIMESTAMP))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_START_TIMESTAMP_SID,
                                                          ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }

    /* Check if pointer passed is Null */
    if(BufferPtr == NULL_PTR)
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_START_TIMESTAMP_SID,
                                                       ICU_E_PARAM_BUFFER_PTR);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
    if(BufferSize == ICU_ZERO)
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_START_TIMESTAMP_SID,
                                                      ICU_E_PARAM_BUFFER_SIZE);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Read timer channel configuration pointer */
    LpTimerChannel = Icu_GpTimerChannelConfig + LddChannel;

    /* Load the Timestamp Channel pointer */
    LpTimestamp = LpTimerChannel->pChannelProp;
    LucIndex = LpTimestamp->ucTimeStampRamDataIndex;

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Initialize Timestamp RAM data */
    LpTimeStampData = Icu_GpTimeStampData + LucIndex;
    LpTimeStampData->pBufferPointer = BufferPtr;
    LpTimeStampData->usBufferSize = BufferSize;
    LpTimeStampData->usTimestampIndex = ICU_ZERO;
    LpTimeStampData->usTimestampsCounter = ICU_ZERO;
    LpTimeStampData->usNotifyInterval = NotifyInterval;

    /* Activate Timestamp capturing */
    Icu_HWStartCountMeasurement (LddChannel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Initialize channel status as active */
    (Icu_GpChannelRamData + LddChannel)->uiChannelStatus = ICU_ACTIVE;
    /* MISRA Rule         : 17.4
       Message            : Performing pointer arithmetic.
       Reason             : For code optimization.
       Verification       : However, part of the code is
                            verified manually and it is not
                            having any impact.
    */
    /* Set the flag to indicate that the timestamping is started */
    (Icu_GpTimeStampData + LucIndex)->blTimestampingStarted = ICU_TRUE;
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_StopTimestamp
**
** Service ID           : 0x0A
**
** Description          : This API service stops the timestamp measurement of
**                        the requested channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GpChannelConfig,
**                        Icu_GpChannelRamData
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWStopCountMeasurement
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_StopTimestamp(Icu_ChannelType Channel)
{
  Icu_ChannelType LddChannel;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;

  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_STOP_TIMESTAMP_SID,
                                                                  ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_STOP_TIMESTAMP_SID,
                                                      ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode !=
    ICU_MODE_TIMESTAMP))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_STOP_TIMESTAMP_SID,
                                                        ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    else if((Icu_GpChannelRamData + LddChannel)->uiChannelStatus == ICU_IDLE)
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_STOP_TIMESTAMP_SID,
                                                            ICU_E_NOT_STARTED);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
    else
    {
      /* To avoid MISRA warning */
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Disable Timestamp capturing */
    Icu_HWStopCountMeasurement (LddChannel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    /* Initialize channel status as idle */
    (Icu_GpChannelRamData + LddChannel)->uiChannelStatus = ICU_IDLE;
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_GetTimestampIndex
**
** Service ID           : 0x0B
**
** Description          : This API service reads the timestamp index the next to
**                        be written for the requested channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Icu_IndexType
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GblDriverStatus,
**                        Icu_GpChannelRamData, Icu_GpTimeStampData
**
**                        Function(s) invoked:
**                        Det_ReportError, SchM_Enter_Icu, SchM_Exit_Icu
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Icu_IndexType, ICU_PUBLIC_CODE) Icu_GetTimestampIndex
(Icu_ChannelType Channel)
{
  /* Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                LpTimerChannel;
  /* Pointer definition for Timestamp Channel properties */
  P2CONST(Tdd_Icu_TimeStampMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                   LpTimestamp;

  uint16 LusTimestampIndex = ICU_ZERO;
  Icu_ChannelType LddChannel;
  uint8 LucIndex;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;
  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {

    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                    ICU_GET_TIMESTAMP_INDEX_SID, ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                           ICU_GET_TIMESTAMP_INDEX_SID, ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode
    != ICU_MODE_TIMESTAMP))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                             ICU_GET_TIMESTAMP_INDEX_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Read timer channel configuration pointer */
    LpTimerChannel = Icu_GpTimerChannelConfig + LddChannel;
    /* Load the Timestamp Channel pointer */
    LpTimestamp = LpTimerChannel->pChannelProp;
    LucIndex = LpTimestamp->ucTimeStampRamDataIndex;

    #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    SchM_Enter_Icu (ICU_TIMESTAMP_DATA_PROTECTION);
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* If timestamping is started, then only return timestamp index value */
    if ((Icu_GpTimeStampData + LucIndex)->blTimestampingStarted == ICU_TRUE)
    {
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      LusTimestampIndex = (Icu_GpTimeStampData + LucIndex)->usTimestampIndex;
    }

    #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    SchM_Exit_Icu (ICU_TIMESTAMP_DATA_PROTECTION);
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  return(LusTimestampIndex);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_TIMESTAMP_API == STD_ON) */

#if(ICU_EDGE_COUNT_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_ResetEdgeCount
**
** Service ID           : 0x0C
**
** Description          : This API resets the value of the counted edges.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GblDriverStatus, Icu_GpChannelConfig,
**                        Icu_GpChannelMap
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWResetEdgeCount
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_ResetEdgeCount(Icu_ChannelType Channel)
{
  #if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
  Icu_ChannelType LddChannel;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;

  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_RESET_EDGE_COUNT_SID,
                                                                 ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_RESET_EDGE_COUNT_SID,
                                                        ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode !=
                                                        ICU_MODE_EDGE_COUNTER))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_RESET_EDGE_COUNT_SID,
                                                          ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Invoke the Low Level Driver for resetting the edge count */
    Icu_HWResetEdgeCount (LddChannel);
  }
  #endif /* End of
           ((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON)) */
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_EnableEdgeCount
**
** Service ID           : 0x0D
**
** Description          : This API service enables the counting of edges of the
**                        requested channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GpChannelConfig,
**                        Icu_GblDriverStatus, Icu_GpEdgeCountData
**                        Icu_GpChannelRamData
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWStartCountMeasurement,
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_EnableEdgeCount(Icu_ChannelType Channel)
{
  Icu_ChannelType LddChannel;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;

  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_ENABLE_EDGE_COUNT_SID,
                                                                 ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                             ICU_ENABLE_EDGE_COUNT_SID, ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode
    != ICU_MODE_EDGE_COUNTER))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                               ICU_ENABLE_EDGE_COUNT_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Start count measurement for the channel */
    Icu_HWStartCountMeasurement(LddChannel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    /* Initialize the channel status as active */
    (Icu_GpChannelRamData + LddChannel)->uiChannelStatus = ICU_ACTIVE;
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_DisableEdgeCount
**
** Service ID           : 0x0E
**
** Description          : This API service disables the counting of edges of the
**                        requested channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GblDriverStatus,
**                        Icu_GpChannelRamData, Icu_GpChannelConfig
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWStopCountMeasurement
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_DisableEdgeCount(Icu_ChannelType Channel)
{
  Icu_ChannelType LddChannel;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;
  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_DISABLE_EDGE_COUNT_SID,
                                                                  ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                            ICU_DISABLE_EDGE_COUNT_SID, ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode !=
    ICU_MODE_EDGE_COUNTER))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_DISABLE_EDGE_COUNT_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Invoke the Low Level Driver for disabling the edge count */
    Icu_HWStopCountMeasurement(LddChannel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Initialize the channel status as idle */
    (Icu_GpChannelRamData + LddChannel)->uiChannelStatus = ICU_IDLE;
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_GetEdgeNumbers
**
** Service ID           : 0x0F
**
** Description          : This API service reads the number of counted edges
**                        after the last reset of edges happened.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Icu_EdgeNumberType
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GblDriverStatus,
**                        Icu_GpChannelConfig
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWGetEdgeNumbers
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Icu_EdgeNumberType, ICU_PUBLIC_CODE) Icu_GetEdgeNumbers
(Icu_ChannelType Channel)
{
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
  Icu_ChannelType LddChannel;
  Icu_EdgeNumberType LddEdgeCount = ICU_ZERO;
  uint8 LucRamIndex;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;
  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_GET_EDGE_NUMBERS_SID,
                                                                ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                              ICU_GET_EDGE_NUMBERS_SID, ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode !=
    ICU_MODE_EDGE_COUNTER))
    {
      /* Report Error to Det */
      Det_ReportError(ICU_MODULE_ID, ICU_INSTANCE_ID,
                                ICU_GET_EDGE_NUMBERS_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

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

    Icu_HWGetEdgeNumbers(LddChannel);
    LddEdgeCount = LpEdgeCountData->usIcuEdgeCount;
  }
  return(LddEdgeCount);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_EDGE_COUNT_API == STD_ON) */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_StartSignalMeasurement
**
** Service ID           : 0x13
**
** Description          : This API starts the measurement of signals beginning
**                        with the configured default start edge which occurs
**                        first after the call of this service.
**
** Sync/Async           : Asynchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GpChannelConfig,
**                        Icu_GblDriverStatus, Icu_GpChannelRamData
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWStartCountMeasurement
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_StartSignalMeasurement(Icu_ChannelType Channel)
{
  Icu_ChannelType LddChannel;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;
  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                               ICU_START_SIGNAL_MEASUREMENT_SID, ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                      ICU_START_SIGNAL_MEASUREMENT_SID, ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode
    != ICU_MODE_SIGNAL_MEASUREMENT))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                        ICU_START_SIGNAL_MEASUREMENT_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Start count measurement for the channel */
    Icu_HWStartCountMeasurement(LddChannel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Initialize channel status as idle */
    (Icu_GpChannelRamData + LddChannel)->uiChannelStatus = ICU_IDLE;
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Icu_StopSignalMeasurement
**
** Service ID           : 0x14
**
** Description          : This API stops the measurement of signals of the
**                        given channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GpChannelConfig,
**                        Icu_GblDriverStatus, Icu_GpChannelRamData
**
**                        Function(s) invoked:
**                        Det_ReportError, Icu_HWStopCountMeasurement
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_StopSignalMeasurement(Icu_ChannelType Channel)
{
  Icu_ChannelType LddChannel;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;
  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                ICU_STOP_SIGNAL_MEASUREMENT_SID, ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                       ICU_STOP_SIGNAL_MEASUREMENT_SID, ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    (((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode) !=
    ICU_MODE_SIGNAL_MEASUREMENT))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                         ICU_STOP_SIGNAL_MEASUREMENT_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Disable Timestamp capturing */
    Icu_HWStopCountMeasurement (LddChannel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Initialize channel status as idle */
    (Icu_GpChannelRamData + LddChannel)->uiChannelStatus = ICU_IDLE;
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

#if(ICU_GET_TIME_ELAPSED_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_GetTimeElapsed
**
** Service ID           : 0x10
**
** Description          : This API service reads the elapsed signal time (Low
**                        Time,High Time or Period Time) of the requested
**                        channel as configured.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Icu_ValueType
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GpChannelConfig,
**                        Icu_GblDriverStatus, Icu_GpSignalMeasurementData
**
**                        Function(s) invoked:
**                        Det_ReportError, SchM_Enter_Icu, SchM_Exit_Icu
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Icu_ValueType, ICU_PUBLIC_CODE) Icu_GetTimeElapsed(Icu_ChannelType Channel)
{
  /* Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                           LpTimerChannelConfig;
  /* Pointer definition for Signal Measurement Channel properties */
  P2CONST(Tdd_Icu_SignalMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                                LpSignalMeasure;

  /* Local pointer to the address of Signal Measure RAM data */
  P2VAR(Tdd_Icu_SignalMeasureChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA)
  LpSignalMeasurementData;
  Icu_SignalMeasurementPropertyType LddMeasureProperty;
  Icu_ChannelType LddChannel;
  Icu_ValueType LddSignalTime = ICU_ZERO;
  uint8 LucIndex;

  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;
  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_GET_TIME_ELAPSED_SID,
                                                                 ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_GET_TIME_ELAPSED_SID,
                                                         ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode
    != ICU_MODE_SIGNAL_MEASUREMENT))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_GET_TIME_ELAPSED_SID,
                                                           ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);
    #endif

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Read timer channel configuration pointer */
    LpTimerChannelConfig = Icu_GpTimerChannelConfig + LddChannel;

    /* Read the channel properties */
    LpSignalMeasure = LpTimerChannelConfig->pChannelProp;

    LddMeasureProperty = (Icu_SignalMeasurementPropertyType)
                                 LpSignalMeasure->uiSignalMeasurementProperty;

    LpSignalMeasure = LpTimerChannelConfig->pChannelProp;
    LucIndex = LpSignalMeasure->ucSignalMeasureRamDataIndex;

    #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    SchM_Enter_Icu (ICU_SIGNALMEASURE_DATA_PROTECTION);
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    LpSignalMeasurementData = Icu_GpSignalMeasurementData + LucIndex;
    /* Check for the status of Channel */
    if((Icu_GpChannelRamData + LddChannel)->uiChannelStatus == ICU_ACTIVE)
    {
      if((LddMeasureProperty == (ICU_HIGH_TIME)) ||
                         (LddMeasureProperty == (ICU_LOW_TIME)))
      {
        /* Read the captured Signal Active Time */
        LddSignalTime = LpSignalMeasurementData->ulSignalActiveTime;
        LpSignalMeasurementData->ulSignalActiveTime = ICU_ZERO;
      }
      else /* (LddMeasureProperty == ICU_PERIOD_TIME) */
      {
        /* Read the captured Signal Period Time */
        LddSignalTime = LpSignalMeasurementData->ulSignalPeriodTime;
        LpSignalMeasurementData->ulSignalPeriodTime = ICU_ZERO;
      }
    }

    #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    SchM_Exit_Icu (ICU_SIGNALMEASURE_DATA_PROTECTION);
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  return(LddSignalTime);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_GET_TIME_ELAPSED_API == STD_ON) */

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_GetDutyCycleValues
**
** Service ID           : 0x11
**
** Description          : This API service reads the coherent high time and
**                        period time for the requested Icu channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Channel
**
** InOut Parameters     : None
**
** Output Parameters    : DutyCycleValues
**
** Return parameter     : None
**
** Preconditions        : The Icu Driver must be initialized.
**
** Remarks              : Global Variable(s):
**                        Icu_GpChannelMap, Icu_GpChannelConfig,
**                        Icu_GblDriverStatus, Icu_GpSignalMeasurementData
**
**                        Function(s) invoked:
**                        Det_ReportError, SchM_Enter_Icu, SchM_Exit_Icu
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE) Icu_GetDutyCycleValues(Icu_ChannelType Channel,
P2VAR(Icu_DutyCycleType,  AUTOMATIC, ICU_APPL_DATA) DutyCycleValues)
{
  /* Defining a pointer to point to the timer channel configuration
   * parameters
   */
  P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig;
  /* Pointer definition for Signal Measurement Channel properties */
  P2CONST(Tdd_Icu_SignalMeasureConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                               LpSignalMeasure;
  /* Local pointer to the address of Signal Measure RAM data */
  P2VAR(Tdd_Icu_SignalMeasureChannelRamDataType, AUTOMATIC, ICU_CONFIG_DATA)
                                                       LpSignalMeasurementData;
  /* Local variable to store the duty cycle values */

  Icu_ChannelType LddChannel;
  uint8 LucIndex;
  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Set error status flag to false */
  boolean LblDetErrFlag = ICU_FALSE;

  /* Check if the Icu Module is not initialized */
  if(Icu_GblDriverStatus != ICU_INITIALIZED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                                  ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_UNINIT);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(Channel > ICU_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report Error to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                         ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_PARAM_CHANNEL);

    /* Set error status flag to true */
    LblDetErrFlag = ICU_TRUE;
  }
  if(LblDetErrFlag == ICU_FALSE)
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    if((LddChannel == ICU_CHANNEL_UNCONFIGURED) ||
    ((Icu_GpChannelConfig + LddChannel)->uiIcuMeasurementMode
    != ICU_MODE_SIGNAL_MEASUREMENT))
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                           ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Read timer channel configuration pointer */
    LpTimerChannelConfig = Icu_GpTimerChannelConfig + LddChannel;
    /* Load channel properties */
    LpSignalMeasure = LpTimerChannelConfig->pChannelProp;
    /* Check if the channel is configured for duty cycle measurement */
    if(LpSignalMeasure->blDutyCycleChannel != ICU_TRUE)
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                           ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_PARAM_CHANNEL);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
    /* Check if pointer passed is Null */
    if(DutyCycleValues == NULL_PTR)
    {
      /* Report Error to Det */
      Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID,
                        ICU_GET_DUTY_CYCLE_VALUES_SID, ICU_E_PARAM_BUFFER_PTR);

      /* Set error status flag to true */
      LblDetErrFlag = ICU_TRUE;
    }
  }
  if(LblDetErrFlag == ICU_FALSE)
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (ICU_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Load Channel index of Icu_GstChannelConfig */
    LddChannel = *(Icu_GpChannelMap + Channel);

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Read timer channel configuration pointer */
    LpTimerChannelConfig = Icu_GpTimerChannelConfig + LddChannel;
    /* Load channel properties */
    LpSignalMeasure = LpTimerChannelConfig->pChannelProp;
    #endif

    /* MISRA Rule         : 9.1                                            */
    /* Message            : The variable '-identifier-' is possibly        */
    /*                      unset at this point.                           */
    /* Reason             : This variable is initialized at two places     */
    /*                      under different pre-compile options            */
    /* Verification       : However, it is maually verified that atleast   */
    /*                      one of the pre-compile options will be ON and  */
    /*                      hence this variable will be always initialzed  */
    /*                      Hence,this is not having any impact.           */

    /* Read channel's RAM Index */
    LucIndex = LpSignalMeasure->ucSignalMeasureRamDataIndex;

    #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Critical Section */
    SchM_Enter_Icu (ICU_SIGNALMEASURE_DATA_PROTECTION);
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    LpSignalMeasurementData = Icu_GpSignalMeasurementData + LucIndex;

    /* Check for the status of Channel */
    if((Icu_GpChannelRamData + LddChannel)->uiChannelStatus == ICU_ACTIVE)
    {
      if(LpSignalMeasurementData->ulSignalPeriodTime > ICU_ZERO)
      {
        /* MISRA Rule         : 1.2                                      */
        /* Message            : Dereferencing pointer value that is      */
        /*                      apparently NULL.                         */
        /* Reason             : "DutyCycleValues" pointer is checked     */
        /*                      and verified when DET is switched STD_ON */
        /* Verification       : However, the part of the code is         */
        /*                      verified manually and it is not having   */
        /*                      any impact on code.                      */
        /* Read the captured Signal Active Time */
        DutyCycleValues->ActiveTime =
                               LpSignalMeasurementData->ulPrevSignalActiveTime;

        /* MISRA Rule         : 1.2                                      */
        /* Message            : Dereferencing pointer value that is      */
        /*                      apparently NULL.                         */
        /* Reason             : "DutyCycleValues" pointer is checked     */
        /*                      and verified when DET is switched STD_ON */
        /* Verification       : However, the part of the code is         */
        /*                      verified manually and it is not having   */
        /*                      any impact on code.                      */
        /* Read the captured Signal Period Time */
        DutyCycleValues->PeriodTime =
                               LpSignalMeasurementData->ulSignalPeriodTime;
        LpSignalMeasurementData->ulSignalPeriodTime = ICU_ZERO;
      }
      else
      {
        DutyCycleValues->ActiveTime = ICU_ZERO;
        DutyCycleValues->PeriodTime = ICU_ZERO;
      }
    }
    #if(ICU_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Critical Section */
    SchM_Exit_Icu (ICU_SIGNALMEASURE_DATA_PROTECTION);
    #endif /* End of (ICU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) */

#if (ICU_GET_VERSION_INFO_API == STD_ON)
/*******************************************************************************
** Function Name        : Icu_GetVersionInfo
**
** Service ID           : 0x12
**
** Description          : This API reads the Version Information of Icu Driver.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : versioninfo
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        None
**
**                        Function(s) invoked:
**                        Det_ReportError
**
*******************************************************************************/
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, ICU_PUBLIC_CODE)Icu_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, ICU_APPL_DATA) versioninfo)
{
  #if(ICU_DEV_ERROR_DETECT == STD_ON)
  /* Check if pointer passed is Null */
  if(versioninfo == NULL_PTR)
  {
    /* Report to Det */
    Det_ReportError (ICU_MODULE_ID, ICU_INSTANCE_ID, ICU_GET_VERSION_INFO_SID,
                                                          ICU_E_PARAM_POINTER);
  }
  else
  #endif /* End of (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Update the vendor Id */
    versioninfo->vendorID = ICU_VENDOR_ID;
    /* Update the module Id */
    versioninfo->moduleID = ICU_MODULE_ID;
    /* Copy the instance Id */
    versioninfo->instanceID = ICU_INSTANCE_ID;
    /* Update Software Major Version */
    versioninfo->sw_major_version = ICU_SW_MAJOR_VERSION;
    /* Update Software Minor Version */
    versioninfo->sw_minor_version = ICU_SW_MINOR_VERSION;
    /* Update Software Patch Version */
    versioninfo->sw_patch_version = ICU_SW_PATCH_VERSION;
  }
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (ICU_GET_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/