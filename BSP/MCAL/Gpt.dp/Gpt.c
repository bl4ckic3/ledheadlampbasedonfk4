/*============================================================================*/
/* Module       = Gpt.c                                                       */
/* Version      = 3.1.4a                                                      */
/* Date         = 19-Feb-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API function implementations of GPT Driver              */
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
 * V3.0.0:  23-Oct-2009    : Initial Version
 * V3.0.1:  25-Feb-2010    : As per SCR 194 following changes are made:
 *                           1. In Gpt_Init API pre-compile option is added
 *                           for "Gpt_GpTAUUnitConfig"
 *                           2. In the description of the API
 *                           Gpt_DisableNotification 'Gpt_GstChannelFunc' is
 *                           removed from the Remarks.
 * V3.0.2:  07-Apr-2010    : As per SCR 244, the API Gpt_Cbk_CheckWakeup is
 *                           updated for the initialization of the RAM variable
 *                           after successful initialization of the module.
 * V3.0.3:  23-Jun-2010    : As per SCR 281, Gpt_Init is updated to support
 *                           TAUB and TAUC timer units.
 * V3.0.4:  03-Jan-2011    : As per SCR 389, In version imformation section
 *                           "GPT_C_SW_PATCH_VERSION" macro is removed.
 * V3.1.0:  27-Jul-2011    : Modified software version to 3.1.0
 * V3.1.1:  04-Oct-2011    : Added comments for the violation of MISRA
 *                           rule 19.1.
 * V3.1.2:  16-Feb-2012    : Merged the fixes done for Fx4L Gpt driver
 * V3.1.3:  06-Jun-2012    : As per SCR 029, following changes are made:
 *                           1. Gpt software patch version is updated.
 *                           2. API Gpt_GetVersionInfo is removed.
 *                           3. Det error check conditional branch is corrected.
 *                           4. Environment section is updated to remove
 *                              compiler version.
 * V3.1.4:  31-Dec-2012    : As per MNT_0008440, the following changes are made:
 *                           1.As per MANTIS #7368 API "Gpt_EnableNotification"
 *                             updated.
 * V3.1.4a: 19-Feb-2013    : Merged the fixes done fo Sx4-H
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Gpt.h"
#include "Gpt_PBTypes.h"
#include "Gpt_LLDriver.h"
#include "Gpt_LTTypes.h"
#include "Gpt_Ram.h"
#if (GPT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM_Cbk.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define GPT_C_AR_MAJOR_VERSION    GPT_AR_MAJOR_VERSION_VALUE
#define GPT_C_AR_MINOR_VERSION    GPT_AR_MINOR_VERSION_VALUE
#define GPT_C_AR_PATCH_VERSION    GPT_AR_PATCH_VERSION_VALUE

/* File version information */
#define GPT_C_SW_MAJOR_VERSION    3
#define GPT_C_SW_MINOR_VERSION    1
#define GPT_C_SW_PATCH_VERSION    4

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (GPT_AR_MAJOR_VERSION != GPT_C_AR_MAJOR_VERSION)
  #error "Gpt.c : Mismatch in Specification Major Version"
#endif

#if (GPT_AR_MINOR_VERSION != GPT_C_AR_MINOR_VERSION)
  #error "Gpt.c : Mismatch in Specification Minor Version"
#endif

#if (GPT_AR_PATCH_VERSION != GPT_C_AR_PATCH_VERSION)
  #error "Gpt.c : Mismatch in Specification Patch Version"
#endif

#if (GPT_SW_MAJOR_VERSION != GPT_C_SW_MAJOR_VERSION)
  #error "Gpt.c : Mismatch in Major Version"
#endif

#if (GPT_SW_MINOR_VERSION != GPT_C_SW_MINOR_VERSION)
  #error "Gpt.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Gpt_Init
**
** Service ID         : 0x01
**
** Description        : This API performs the initialization of GPT Driver
**                      component.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Reentrant
**
** Input Parameters   : configPtr
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelConfig,
**                      Gpt_GpChannelRamData, Gpt_GpChannelTimerMap,
**                      Gpt_GucGptDriverMode
**
**                      Function(s) invoked:
**                      Det_ReportError, Gpt_HW_Init
**
*******************************************************************************/
#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_Init
(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr)
{

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Local Flag to check DET Error */
  LblDetErrFlag = GPT_FALSE;
  /* Check if config pointer is NULL pointer */
  if(NULL_PTR == configPtr)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID,
    GPT_E_PARAM_CONFIG);

    LblDetErrFlag = GPT_TRUE;
  }

  if(GPT_INITIALIZED == Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID,
    GPT_E_ALREADY_INITIALIZED);

    LblDetErrFlag = GPT_TRUE;
  }

  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Rule         : 1.2                                      */
    /* Message            : Dereferencing pointer value that is      */
    /*                      apparently NULL.                         */
    /* Reason             : "Config" pointer is checked and verified */
    /*                      when DET is switched STD_ON.             */
    /* Verification       : However, the part of the code is         */
    /*                      verified manually and it is not having   */
    /*                      any impact on code.                      */

    /* Check if the database is present */
    if(GPT_DBTOC_VALUE == (configPtr->ulStartOfDbToc))
    {
      #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON) \
          || (GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))
      Gpt_GpTAUUnitConfig = configPtr->pTAUUnitConfig;
      #endif /*((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON) \
          || (GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))*/

      /* Store the global pointer to first channel Configuration */
      Gpt_GpChannelConfig = configPtr->pChannelConfig;
      /* Store the global pointer to First channel's Ram data */
      Gpt_GpChannelRamData = configPtr->pChannelRamAddress;
      /* Store the global pointer to channel-timer map */
      Gpt_GpChannelTimerMap = configPtr->pChannelTimerMap;
      /* Invoke low level driver for initializing the hardware */
      Gpt_HW_Init();

      #if (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Set Driver state to initialized */
      Gpt_GblDriverStatus = GPT_INITIALIZED;
      #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */

      /* Set the Driver Mode to Normal */
      Gpt_GucGptDriverMode = GPT_MODE_NORMAL;
    }
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID,
      GPT_E_INVALID_DATABASE);
    }
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  }
}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name      : Gpt_DeInit
**
** Service ID         : 0x02
**
** Description        : This service performs de-initialization of the
**                      GPT Driver component.
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelRamData
**
**                      Function(s) invoked:
**                      Det_ReportError,
**                      Gpt_HW_DeInit
**
*******************************************************************************/
#if (GPT_DE_INIT_API == STD_ON)

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_DeInit(void)
{
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Defining a local pointer to point to the Channel Ram Data */
  P2VAR(Tdd_Gpt_ChannelRamData,AUTOMATIC,GPT_CONFIG_DATA)LpRamData;
  /* Initialize local variable to first channel */
  uint8 LucChannelID;
  boolean LblDetErrFlag;
  LpRamData = Gpt_GpChannelRamData;
  LucChannelID = GPT_ZERO;
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Local Flag to check DET Error */
  LblDetErrFlag = GPT_FALSE;

  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DEINIT_SID,
      GPT_E_UNINIT);
    LblDetErrFlag = GPT_TRUE;
  }
  else
  {
    do
    {
      if(GPT_CH_RUNNING == LpRamData->ucChannelStatus)
      {
        LblDetErrFlag = GPT_TRUE;
      }
      /* MISRA Rule         : 17.4                             */
      /* Message            : Increment or decrement operation */
      /*                      performed on pointer.            */
      /* Reason             : Increment operator is used to    */
      /*                      achieve better throughput.       */
      /* Verification       : However, part of the code is     */
      /*                      verified manually and it is not  */
      /*                      having any impact.               */

      LpRamData++;
      LucChannelID++;
    }while((GPT_TOTAL_CHANNELS_CONFIG != LucChannelID)
            && (GPT_FALSE == LblDetErrFlag));

    if(GPT_TRUE == LblDetErrFlag)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DEINIT_SID,
      GPT_E_BUSY);
    }

  }
  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Invoke low level driver for de-initializing the hardware */
    Gpt_HW_DeInit();
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Set Driver state to uninitialized */
    Gpt_GblDriverStatus = GPT_UNINITIALIZED;
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  }
}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* (GPT_DE_INIT_API == STD_ON) */

/*******************************************************************************
** Function Name      : Gpt_GetTimeElapsed
**
** Service ID         : 0x03
**
** Description        : This API is used to read the time elapsed for a
**                      particular channel from the start of channel.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : channel
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : value
**
** Preconditions      : None
**
** Remarks            : Global Variable(s):
**                      Gpt_GblDriverStatus, Gpt_GpChannelTimerMap,
**                      Gpt_GpChannelRamData
**
**                      Function(s) invoked:
**                      Det_ReportError,
**                      Gpt_HW_GetTimeElapsed
**
*******************************************************************************/
#if (GPT_TIME_ELAPSED_API == STD_ON)

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Gpt_ValueType, GPT_PUBLIC_CODE) Gpt_GetTimeElapsed
(Gpt_ChannelType channel)
{

  Gpt_ChannelType LddChannel;
  Gpt_ValueType LddTimeElapsed;

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */

  LddTimeElapsed = GPT_ZERO;

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  LblDetErrFlag = GPT_FALSE;
  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_TIME_ELAPSED_SID,
      GPT_E_UNINIT);
    LblDetErrFlag = GPT_TRUE;
  }

  /* Check if the channel is in the desired range */
  if(channel > GPT_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_TIME_ELAPSED_SID,
      GPT_E_PARAM_CHANNEL);
    LblDetErrFlag = GPT_TRUE;
  }

  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {                                        /* Block Comment - 1 */
    LddChannel = Gpt_GpChannelTimerMap[channel];

    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the channel is not configured */
    if(GPT_CHANNEL_UNCONFIGURED == LddChannel)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_TIME_ELAPSED_SID,
        GPT_E_PARAM_CHANNEL);
    }
    else
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    {                                      /* Block Comment - 2 */
      #if (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Check if the timer is not started */
      if(GPT_CH_RUNNING != Gpt_GpChannelRamData[LddChannel].ucChannelStatus)
      {
        /* Report to DET */
        Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_GET_TIME_ELAPSED_SID, GPT_E_NOT_STARTED);
      }
      else
      #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
      {
        /* Call to the HW Function */
        LddTimeElapsed = Gpt_HW_GetTimeElapsed(LddChannel);
      }

    } /* End of Block Comment - 2 */

  } /* End of Block Comment - 1 */
  return (LddTimeElapsed);
}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* (GPT_TIME_ELAPSED_API == STD_ON) */

/*******************************************************************************
** Function Name      : Gpt_GetTimeRemaining
**
** Service ID         : 0x04
**
** Description        : This API is used to read the time remaining for the
**                      channel to reach timeout.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : channel
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelRamData,
**                      Gpt_GpChannelTimerMap
**
**                      Function(s) invoked:
**                      Det_ReportError,
**                      Gpt_HW_GetTimeRemaining
**
*******************************************************************************/

#if (GPT_TIME_REMAINING_API == STD_ON)

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Gpt_ValueType, GPT_PUBLIC_CODE) Gpt_GetTimeRemaining
(Gpt_ChannelType channel)
{
  Gpt_ChannelType LddChannel;
  Gpt_ValueType LddTimeRemaining;

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */

  LddTimeRemaining = GPT_ZERO;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  LblDetErrFlag = GPT_FALSE;

  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_TIME_REMAINING_SID,
      GPT_E_UNINIT);
    LblDetErrFlag = GPT_TRUE;
  }
  /* Check if the channel is in the desired range */
  if(channel > GPT_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_TIME_REMAINING_SID,
      GPT_E_PARAM_CHANNEL);
    LblDetErrFlag = GPT_TRUE;
  }

  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {                                        /* Block Comment - 1 */
    LddChannel = Gpt_GpChannelTimerMap[channel];

    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the channel is not configured */
    if(GPT_CHANNEL_UNCONFIGURED == LddChannel)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
       GPT_GET_TIME_REMAINING_SID, GPT_E_PARAM_CHANNEL);
    }
    else
    #endif  /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    {                                       /* Block Comment - 2 */
      #if (GPT_DEV_ERROR_DETECT == STD_ON)

      /* Check if the timer is not started */
      if(GPT_CH_RUNNING != Gpt_GpChannelRamData[LddChannel].ucChannelStatus)
      {
        /* Report to DET */
        Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
        GPT_GET_TIME_REMAINING_SID, GPT_E_NOT_STARTED);
      }
      else
      #endif/* (GPT_DEV_ERROR_DETECT == STD_ON) */
      {
        /* Call to the HW Function */
        LddTimeRemaining = Gpt_HW_GetTimeRemaining(LddChannel);
      }

    } /* End of Block Comment - 2 */

  } /* End of Block Comment - 1 */

  return (LddTimeRemaining);
}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* (GPT_TIME_REMAINING_API == STD_ON) */

/*******************************************************************************
** Function Name      : Gpt_StartTimer
**
** Service ID         : 0x05
**
** Description        : This API starts the particular timer channel.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : channel, value
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelTimerMap,
**                      Gpt_GpChannelRamData
**
**                      Function(s) invoked:
**                      Det_ReportError,
**                      Gpt_HW_StartTimer
**
*******************************************************************************/
#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_StartTimer
(Gpt_ChannelType  channel,Gpt_ValueType value)
{
  Gpt_ChannelType LddChannel;

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = GPT_FALSE;
  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_START_TIMER_SID,
      GPT_E_UNINIT);
    LblDetErrFlag = GPT_TRUE;
  }
  /* Check if the channel is in the desired range */
  if(channel > GPT_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_START_TIMER_SID,
      GPT_E_PARAM_CHANNEL);
    LblDetErrFlag = GPT_TRUE;
  }
  /* Check if the channel value is ZERO */
  if(GPT_ZERO == value)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_START_TIMER_SID,
      GPT_E_PARAM_VALUE);
    LblDetErrFlag = GPT_TRUE;
  }

  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {
    LddChannel = Gpt_GpChannelTimerMap[channel];

    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the channel is not configured */
    if(GPT_CHANNEL_UNCONFIGURED == LddChannel)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_START_TIMER_SID,
        GPT_E_PARAM_CHANNEL);
    }
    /* Check if the timer is already running */
    else if(GPT_CH_RUNNING == Gpt_GpChannelRamData[LddChannel].ucChannelStatus)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_START_TIMER_SID,
        GPT_E_BUSY);
    }
    else
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    {
      /* Call to the HW function */
      Gpt_HW_StartTimer(LddChannel, value);
    }
  } /* End of Block Comment - 1 */
}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */


/*******************************************************************************
** Function Name      : Gpt_StopTimer
**
** Service ID         : 0x06
**
** Description        : This API stops the particular channel
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : channel
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelTimerMap
**                      Gpt_GpChannelRamData
**
**                      Function(s) invoked:
**                      Det_ReportError,
**                      Gpt_HW_StopTimer
**
*******************************************************************************/
#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_StopTimer(Gpt_ChannelType  channel)
{
  Gpt_ChannelType LddChannel;

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = GPT_FALSE;
  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_STOP_TIMER_SID,
      GPT_E_UNINIT);
    LblDetErrFlag = GPT_TRUE;
  }
  /* Check if the channel is in the desired range */
  if(channel > GPT_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_STOP_TIMER_SID,
      GPT_E_PARAM_CHANNEL);
    LblDetErrFlag = GPT_TRUE;
  }

  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {                                        /* Block Comment - 1 */
    LddChannel = Gpt_GpChannelTimerMap[channel];

    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the channel is not configured */
    if(GPT_CHANNEL_UNCONFIGURED == LddChannel)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_STOP_TIMER_SID,
        GPT_E_PARAM_CHANNEL);
    }
    else
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    {                                      /* Block Comment - 2 */

      /* Check if the timer is started */
      if(GPT_CH_RUNNING == Gpt_GpChannelRamData[LddChannel].ucChannelStatus)
      {
        /* Call to the HW function */
        Gpt_HW_StopTimer(LddChannel);
      }
      else
      {
       /* To Avoid MISRA Warning */
      }
    } /* End of Block Comment - 2 */

  } /* End of Block Comment - 1 */
}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name      : Gpt_EnableNotification
**
** Service ID         : 0x07
**
** Description        : This API enables the notification for particular channel
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : channel
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelRamData,
**                      Gpt_GpChannelTimerMap, Gpt_GstChannelFunc
**
**                      Function(s) invoked:
**                      Det_ReportError
**
*******************************************************************************/

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_EnableNotification(Gpt_ChannelType  channel)
{
  P2CONST(Tdd_Gpt_ChannelFuncType, AUTOMATIC, GPT_APPL_CODE) LpChannelFunc;
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)LpChannel;
  Gpt_ChannelType LddChannel;
  uint8 LucNotificationIdx;

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = GPT_FALSE;

  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_NOTIFY_SID,
    GPT_E_UNINIT);
    LblDetErrFlag = GPT_TRUE;
  }
  /* Check if the channel is in the desired range */
  if(channel > GPT_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_NOTIFY_SID,
    GPT_E_PARAM_CHANNEL);
    LblDetErrFlag = GPT_TRUE;
  }

  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {                                        /* Block Comment - 1 */
    LddChannel = Gpt_GpChannelTimerMap[channel];

    LpChannel = &Gpt_GpChannelConfig[LddChannel];

    LucNotificationIdx = LpChannel->ucNotificationConfig;

    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the channel is not configured */
    if(GPT_CHANNEL_UNCONFIGURED == LddChannel)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_NOTIFY_SID,
      GPT_E_PARAM_CHANNEL);
    }
    /* Check if the Notification is not configured */
    else if(GPT_NO_CBK_CONFIGURED == LucNotificationIdx)
    {
        /* Report to DET */
        Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_NOTIFY_SID,
        GPT_E_PARAM_CHANNEL);
    }
    else if
       /* MISRA Rule         : 17.4                             */
       /* Message            : Increment or decrement operation */
       /*                      performed on pointer.            */
       /* Reason             : Increment operator is used to    */
       /*                      achieve better throughput.       */
       /* Verification       : However, part of the code is     */
       /*                      verified manually and it is not  */
       /*                      having any impact.               */
       (GPT_TRUE == (Gpt_GpChannelRamData + LddChannel)->uiNotifyStatus)
    {
      /* Report Error to Det */
      Det_ReportError (GPT_MODULE_ID, GPT_INSTANCE_ID,
                         GPT_ENABLE_NOTIFY_SID, GPT_E_ALREADY_ENABLED);
    }
    else
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    {
      LpChannelFunc = &Gpt_GstChannelFunc[LucNotificationIdx];
      /* Check if the Notification Function is configured */
      if(NULL_PTR !=  LpChannelFunc->pGptNotificationPointer_Channel)
      {
        /* Enabling the normal Notification */
        Gpt_GpChannelRamData[LddChannel].uiNotifyStatus = GPT_TRUE;

      }
      else
      {
        /* To Avoid MISRA Warning */
      }
    }

  } /* End of Block Comment - 1 */

}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */

/*******************************************************************************
** Function Name      : Gpt_DisableNotification
**
** Service ID         : 0x08
**
** Description        : This API disables notification for particular channel
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : channel
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelRamData,
**                      Gpt_GpChannelTimerMap
**
**                      Function(s) invoked:
**                      Det_ReportError
**
*******************************************************************************/

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_DisableNotification(Gpt_ChannelType  channel)
{
  Gpt_ChannelType LddChannel;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = GPT_FALSE;
  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_NOTIFY_SID,
    GPT_E_UNINIT);

    LblDetErrFlag = GPT_TRUE;
  }
  /* Check if the channel is in the desired range */
  if(channel > GPT_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_NOTIFY_SID,
    GPT_E_PARAM_CHANNEL);

    LblDetErrFlag = GPT_TRUE;
  }

  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {
    LddChannel = Gpt_GpChannelTimerMap[channel];

    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the channel is not configured */
    if(GPT_CHANNEL_UNCONFIGURED == LddChannel)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_NOTIFY_SID,
      GPT_E_PARAM_CHANNEL);
    }
    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */
    else if
       (GPT_FALSE == (Gpt_GpChannelRamData + LddChannel)->uiNotifyStatus)
    {
      /* Report Error to Det */
      Det_ReportError (GPT_MODULE_ID, GPT_INSTANCE_ID,
                         GPT_DISABLE_NOTIFY_SID, GPT_E_ALREADY_DISABLED);
    }
    else
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    {
      /* Disabling the Notification */
      Gpt_GpChannelRamData[LddChannel].uiNotifyStatus = GPT_FALSE;
    }
  }
}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */

/*******************************************************************************
** Function Name      : Gpt_SetMode
**
** Service ID         : 0x09
**
** Description        : This API is used to set the GPT Driver mode
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non Re-entrant
**
** Input Parameters   : mode
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelConfig,
**                      Gpt_GucGptDriverMode
**
**                      Function(s) invoked:
**                      Det_ReportError,
**                      Gpt_HW_StopTimer
**
*******************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON)  \
  && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, GPT_PUBLIC_CODE) Gpt_SetMode(Gpt_ModeType mode)
{
  /* Defining a local pointer to point to the Channel Config Data */
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)LpChannel;

  #if(GPT_REPORT_WAKEUP_SOURCE == STD_ON)
  /* Local variable notification status */
  uint8 LucWakeupStatus;
  #endif /* (STD_ON = GPT_REPORT_WAKEUP_SOURCE) */

  /* Local Channel Index */
  uint8 LucChannelID = GPT_ZERO;

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = GPT_FALSE;

  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SET_MODE_SID,
    GPT_E_UNINIT);

    LblDetErrFlag = GPT_TRUE;
  }
  /* MISRA Rule         : 13.7                             */
  /* Message            : The result of this logical opera */
  /*                      tion is always false.            */
  /* Reason             : Logical operation performed to   */
  /*                      check the mode of the GPT driver */
  /* Verification       : However, part of the code is     */
  /*                      verified manually and it is not  */
  /*                      having any impact.               */

  /* Check if the GPT mode is correct */
  if((GPT_MODE_NORMAL != mode) && (GPT_MODE_SLEEP != mode))
  /* MISRA Rule         : 14.1                             */
  /* Message            : This statement is unreachable.   */
  /* Reason             : As per AUTOSAR all the input     */
  /*                      parameters of an API have to be  */
  /*                      verified.                        */
  /* Verification       : However, part of the code is     */
  /*                      verified manually and it is not  */
  /*                      having any impact.               */
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SET_MODE_SID,
    GPT_E_PARAM_MODE);

    LblDetErrFlag = GPT_TRUE;
  }

  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Updating the local pointer to channel config data */
    LpChannel = Gpt_GpChannelConfig;
    Gpt_GucGptDriverMode = mode;
    if(GPT_MODE_SLEEP == mode)
    {
      do
      {
        /* Check for disable wakeup status of a channel */
        if(GPT_FALSE == (LpChannel->uiGptEnableWakeup))
        {
          Gpt_HW_StopTimer(LucChannelID);
        }
        else
        {
            /* To Avoid MISRA Warning */
        }
        /* Copy the notification status */
        LucWakeupStatus = Gpt_GpChannelRamData[LucChannelID].uiWakeupStatus;

        /* Check for disable wakeup status */
        if(GPT_WAKEUP_NOTIFICATION_DISABLED == LucWakeupStatus)
        {
          /* Disabling wakeup notification of the timer channel */
          Gpt_HW_DisableWakeup(LucChannelID);
        }
        else
        {
            /* To Avoid MISRA Warning */
        }
        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */

        LpChannel++;
        LucChannelID++;
      }while(GPT_TOTAL_CHANNELS_CONFIG != LucChannelID);
    }
    else
    {
        /* To Avoid MISRA Warning */
    }
  }
}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) */
/* (GPT_REPORT_WAKEUP_SOURCE == STD_ON) */

/*******************************************************************************
** Function Name      : Gpt_DisableWakeup
**
** Service ID         : 0x0A
**
** Description        : This API disables the wakeup notification for a
**                      particular channel
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : channel
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelConfig,
**                      Gpt_GpChannelTimerMap
**
**                      Function(s) invoked:
**                      Det_ReportError,
**                      Gpt_HW_DisableWakeup
**
*******************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON)  \
 && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_DisableWakeup(Gpt_ChannelType channel)
{
  Gpt_ChannelType LddChannel;

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = GPT_FALSE;

  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_WAKEUP_SID,
    GPT_E_UNINIT);
    LblDetErrFlag = GPT_TRUE;
  }
  /* Check if the channel mode is correct */
  if(channel > GPT_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_WAKEUP_SID,
    GPT_E_PARAM_CHANNEL);
    LblDetErrFlag = GPT_TRUE;
  }


  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {                                        /* Block comment - 1 */
    LddChannel = Gpt_GpChannelTimerMap[channel];

    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the channel is not configured */
    if(GPT_CHANNEL_UNCONFIGURED == LddChannel)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_WAKEUP_SID,
        GPT_E_PARAM_CHANNEL);
    }
    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    else if(GPT_ZERO == (Gpt_GpChannelConfig + LddChannel)->uiGptEnableWakeup)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_WAKEUP_SID,
        GPT_E_PARAM_CHANNEL);
    }
    else
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    {
      /* Check if the GPT driver is in sleep mode */
      if(GPT_MODE_SLEEP == Gpt_GucGptDriverMode)
      {
        /* Disabling wakeup notification of the timer channel */
        Gpt_HW_DisableWakeup(LddChannel);
      }
      #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
      else
      {
        /* Storing Wakeup Notification in Normal Mode */
         Gpt_GpChannelRamData[LddChannel].uiWakeupStatus = GPT_ZERO;
      }
      #endif /* (GPT_REPORT_WAKEUP_SOURCE == STD_ON) */
    }

  } /* End of Block comment - 1 */
}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  &&
          (GPT_REPORT_WAKEUP_SOURCE == STD_ON) */

/*******************************************************************************
** Function Name      : Gpt_EnableWakeup
**
** Service ID         : 0x0B
**
** Description        : This API enables the wakeup notification for a
**                      particular channel
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : channel
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelConfig,
**                      Gpt_GpChannelTimerMap
**
**                      Function(s) invoked:
**                      Det_ReportError, Gpt_HW_EnableWakeup
**
*******************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON)  \
  && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_EnableWakeup(Gpt_ChannelType channel)
{
  Gpt_ChannelType LddChannel;

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = GPT_FALSE;

  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_WAKEUP_SID,
    GPT_E_UNINIT);

    LblDetErrFlag = GPT_TRUE;
  }
  /* Check if the channel mode is correct */
  if(channel > GPT_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_WAKEUP_SID,
    GPT_E_PARAM_CHANNEL);

    LblDetErrFlag = GPT_TRUE;
  }


  if(GPT_FALSE == LblDetErrFlag)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {                                        /* Block comment - 1 */

    LddChannel = Gpt_GpChannelTimerMap[channel];

    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the channel is not configured */
    if(GPT_CHANNEL_UNCONFIGURED == LddChannel)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_WAKEUP_SID,
      GPT_E_PARAM_CHANNEL);
    }
    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    else if(GPT_ZERO == (Gpt_GpChannelConfig + LddChannel)->uiGptEnableWakeup)
    {
      /* Report to DET */
      Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_WAKEUP_SID,
      GPT_E_PARAM_CHANNEL);
    }
    else
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    {
      /* Check if the GPT driver is in sleep mode */
      if(GPT_MODE_SLEEP == Gpt_GucGptDriverMode)
      {
        /* Enabling Wakeup Notification */
        Gpt_HW_EnableWakeup(LddChannel);
      }
      #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
      else
      {
        /* Storing Notification in normal mode */
        Gpt_GpChannelRamData[LddChannel].uiWakeupStatus = GPT_ONE;
      }
      #endif /* (GPT_REPORT_WAKEUP_SOURCE == STD_ON) */
    }

  } /* End of Block comment - 1 */
}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  &&
          (GPT_REPORT_WAKEUP_SOURCE == STD_ON) */

/*******************************************************************************
** Function Name      : Gpt_Cbk_CheckWakeup
**
** Service ID         : 0x0C
**
** Description        : This API checks the wakeup notification for a
**                      particular channel
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : wakeupSource
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
**                      Gpt_GblDriverStatus, Gpt_GpChannelConfig
**                      Gpt_GpChannelRamData
**
**                      Function(s) invoked:
**                      Det_ReportError and EcuM_SetWakeupEvent
**
*******************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON)  \
  && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

void Gpt_Cbk_CheckWakeup( EcuM_WakeupSourceType wakeupSource )
{
  /* Defining a local pointer to point to the Channel Config Data */
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)LpChannel;

  boolean LblWakeupFlag;

  uint8 LucChannelID = GPT_ZERO;

  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Check if the GPT Driver is initialized properly */
  if(GPT_INITIALIZED != Gpt_GblDriverStatus)
  {
    /* Report to DET */
    Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_CBK_CHECK_WAKEUP_SID,
    GPT_E_UNINIT);
  }
  else
  #endif/* (GPT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Update the local pointer to channel config */
    LpChannel = Gpt_GpChannelConfig;

    do
    {
      /* Copy the Wakeup status */
      LblWakeupFlag = Gpt_GpChannelRamData[LucChannelID].uiWakeupStatus;

      /* Check whether the notification is from the configured Channel */
      if(((LpChannel->ddWakeupSourceId) == wakeupSource) &&
         (GPT_TRUE == LblWakeupFlag))
      {
         /* Invoke the EcuM Set Wakeup API*/
         EcuM_SetWakeupEvent(wakeupSource);

         /* Reset wakeup flag for channel */
         Gpt_GpChannelRamData[LucChannelID].uiWakeupStatus = GPT_ZERO;

         /* Update the channel ID with maximum number of channel configured */
         LucChannelID = GPT_TOTAL_CHANNELS_CONFIG;
      }
      else
      {
        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */

        LpChannel++;
        LucChannelID++;
      }

    }while(GPT_TOTAL_CHANNELS_CONFIG != LucChannelID);

  }

}

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  &&
          (GPT_REPORT_WAKEUP_SOURCE == STD_ON) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
