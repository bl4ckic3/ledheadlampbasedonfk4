/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Pwm.c                                                       */
/* Version      = 3.1.5                                                       */
/* Date         = 05-Nov-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* API function implementations of PWM Driver Component                       */
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
 * V3.0.0:  18-Aug-2009  : Initial version
 * V3.0.1:  28-Oct-2009  : Updated as per the SCR 054
 *                         Pwm_HW_Callback function added
 * V3.0.2:  07-Apr-2010  : As per SCR 243, the APIs Pwm_SetDutyCycle,
 *                         Pwm_SetPeriodAndDuty, Pwm_SetOutputToIdle,
 *                         Pwm_GetOutputState, Pwm_DisableNotification,
 *                         Pwm_EnableNotification are updated for the
 *                         initialization of the RAM variable after
 *                         successful initialization of the module.
 * V3.0.3:  02-Jul-2010  : As per SCR 290, Pwm_Init is updated to support
 *                         TAUB and TAUC timer units.
 * V3.0.4:  25-Jul-2010  : As per SCR 305, precompile options PWM_TAUB_UNIT_USED
 *                         and PWM_TAUC_UNIT_USED are added in Pwm_Init API.
 * V3.0.5:  29-Apr-2011  : As per SCR 435, Pwm_SetPeriodAndDuty and
 *                         Pwm_SetDutyCycle APIs are added with new DET checks
 *                         for Period and Duty values.
 * V3.1.0:  26-Jul-2011  : Ported for the DK4 variant.
 * V3.1.1:  04-Oct-2011  : Added comments for the violation of MISRA rule 19.1.
 * V3.1.2:  12-Jan-2012  :TEL have fixed The Issues reported by  mantis id
 *                       :  #4246,#4210,#4207,#4206,#4202,#4259,#4257,#4248.
 * V3.1.3:  05-Mar-2012  : Merged the fixes done for Fx4L PWM driver
 * V3.1.4:  06-Jun-2012  : As per SCR 034, following changes are made:
 *                         1. Pwm_GetVersionInfo API is removed and implemented
 *                            as macro.
 *                         2. Conditional check for DET errors is corrected.
 *                         3. Compiler version is removed from Environment
 *                            section.
 *                         4. Pwm_SetPeriodAndDuty Api is updated for DET error
 *                            check when Period is 0.
 * V3.1.5:  05-Nov-2012  : As per MNT_0007541, section "Remarks" is updated for
 *                         APIs "Pwm_SetPeriodAndDuty", "Pwm_SetOutputToIdle".
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Pwm.h"
#include "Pwm_LLDriver.h"
#include "Pwm_Ram.h"
#if(PWM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Pwm.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification version information */
#define PWM_C_AR_MAJOR_VERSION    PWM_AR_MAJOR_VERSION_VALUE
#define PWM_C_AR_MINOR_VERSION    PWM_AR_MINOR_VERSION_VALUE
#define PWM_C_AR_PATCH_VERSION    PWM_AR_PATCH_VERSION_VALUE

/* File version information */
#define PWM_C_SW_MAJOR_VERSION    3
#define PWM_C_SW_MINOR_VERSION    1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PWM_AR_MAJOR_VERSION != PWM_C_AR_MAJOR_VERSION)
  #error "Pwm.c : Mismatch in Specification Major Version"
#endif

#if (PWM_AR_MINOR_VERSION != PWM_C_AR_MINOR_VERSION)
  #error "Pwm.c : Mismatch in Specification Minor Version"
#endif

#if (PWM_AR_PATCH_VERSION != PWM_C_AR_PATCH_VERSION)
  #error "Pwm.c : Mismatch in Specification Patch Version"
#endif

#if (PWM_SW_MAJOR_VERSION != PWM_C_SW_MAJOR_VERSION)
  #error "Pwm.c : Mismatch in Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_C_SW_MINOR_VERSION)
  #error "Pwm.c : Mismatch in Minor Version"
#endif

/******************************************************************************
**                         Global Data                                       **
******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Pwm_Init
**
** Service ID           : 0x00
**
** Description          : This API performs the initialisation of PWM Driver
**                        component.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
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
**                        Pwm_GblDriverStatus, Pwm_GpTAUABCUnitConfig,
**                        Pwm_GpTAUJUnitConfig, Pwm_GpChannelConfig,
**                        Pwm_GpSynchStartConfig, Pwm_GpChannelTimerMap
**                        Pwm_GpNotifStatus, Pwm_GpChannelIdleStatus
**                        Function(s) invoked:
**                        Det_ReportError, Pwm_HW_Init
*******************************************************************************/

#define PWM_START_SEC_PUBLIC_CODE
  /* MISRA Rule         : 19.1                            */
  /* Message            : #include statements in a file   */
  /*                      should only be preceded by other*/
  /*                      preprocessor directives or      */
  /*                      comments.                       */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */
#include "MemMap.h"

FUNC(void, PWM_PUBLIC_CODE) Pwm_Init
(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr)
{

  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = PWM_FALSE;

  /* Check if the PWM Driver is already initialized */
  if(PWM_INITIALIZED == Pwm_GblDriverStatus)
  {
    /* Report Error to DET */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_INIT_SID,
                                                PWM_E_ALREADY_INITIALIZED);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  /* Check if ConfigPtr is NULL_PTR */
  if (NULL_PTR == ConfigPtr)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_INIT_SID,
                                             PWM_E_PARAM_CONFIG);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  else
  {
  /* For Misra Compliance */
  }

  if(PWM_FALSE == LblDetErrFlag)
  #endif /* End of (PWM_DEV_ERROR_DETECT == STD_ON) */
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
    if(PWM_DBTOC_VALUE == ConfigPtr->ulStartOfDbToc)
    {
      #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
          (PWM_TAUC_UNIT_USED == STD_ON))
      /* MISRA Rule         : 1.2                                      */
      /* Message            : Dereferencing pointer value that is      */
      /*                      apparently NULL.                         */
      /* Reason             : "Config" pointer is checked and verified */
      /*                      when DET is switched STD_ON.             */
      /* Verification       : However, the part of the code is         */
      /*                      verified manually and it is not having   */
      /*                      any impact on code.                      */

      /*
       * Save the start of TAUA/TAUB/TAUC Unit Configuration in the global
       * pointer
       */
      Pwm_GpTAUABCUnitConfig = ConfigPtr->pTAUABCUnitConfig;
      #endif

      #if(PWM_TAUJ_UNIT_USED == STD_ON)
      /* Save the start of TAUJ Unit Configuration in the global pointer */
       Pwm_GpTAUJUnitConfig = ConfigPtr->pTAUJUnitConfig;
      #endif
      /* Save the start of channel Configuration in the global pointer */
      Pwm_GpChannelConfig = ConfigPtr->pChannelConfig;

      #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
      /* Save the start of synch start Configuration in the global pointer */
      Pwm_GpSynchStartConfig = ConfigPtr->pSynchStartConfig;
      #endif

      /* Save the start of channel-timer map in the global pointer */
      Pwm_GpChannelTimerMap = ConfigPtr->pChannelTimerMap;

      #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
      /* Save the start of Notification status array in the global pointer */
      Pwm_GpNotifStatus = ConfigPtr->pNotifStatus;
      #endif
      /* Save the start of Idle state status array in the global pointer */
      Pwm_GpChannelIdleStatus = ConfigPtr->pChannelIdleStatus;
      /* Initialize all PWM channels */
      Pwm_HW_Init();

      #if (PWM_DEV_ERROR_DETECT == STD_ON)
      /* Set PWM Driver status to initialized */
      Pwm_GblDriverStatus = PWM_INITIALIZED;
      #endif
    }
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* If there is no valid database present */
    else
    {
      /* Report to DET */
      Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,PWM_INIT_SID,
                                          PWM_E_INVALID_DATABASE);
    }
    #endif /* End of (PWM_DEV_ERROR_DETECT == STD_ON) */
  } /* End of if(LblDetErrFlag == PWM_FALSE) */
}

#define PWM_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Pwm_DeInit
**
** Service ID           : 0x01
**
** Description          : This service performs de-initialisation of the PWM
**                        Driver component.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile option
**                          PWM_DE_INIT_API is STD_ON.
**
** Remarks              : Global Variable(s):
**                        Pwm_GblDriverStatus
**                        Function(s) invoked:
**                        Det_ReportError, Pwm_HW_DeInit
*******************************************************************************/
#if (PWM_DE_INIT_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, PWM_PUBLIC_CODE) Pwm_DeInit(void)
{

  #if (PWM_DEV_ERROR_DETECT == STD_ON)

  /* Check if PWM Driver is initialized */
  if (Pwm_GblDriverStatus != PWM_INITIALIZED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_DEINIT_SID,
                                                      PWM_E_UNINIT);
  }
  else
  #endif /* End of (PWM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* De-Initialise all PWM channels */
    Pwm_HW_DeInit();

    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* Set PWM Driver status to uninitialized */
    Pwm_GblDriverStatus = PWM_UNINITIALIZED;
    #endif
  }
}

#define PWM_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of (PWM_DE_INIT_API == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_SetDutyCycle
**
** Service ID           : 0x02
**
** Description          : This API is used to set the required Duty cycle for a
**                        PWM channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber, DutyCycle.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_SET_DUTY_CYCLE_API is STD_ON.
**
** Remarks              : Global Variable(s):
**                        Pwm_GblDriverStatus, Pwm_GpChannelTimerMap
**                        Function(s) invoked:
**                        Det_ReportError, Pwm_HW_SetDuty
*******************************************************************************/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, PWM_PUBLIC_CODE) Pwm_SetDutyCycle
(Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{

  Pwm_ChannelType LddChannelId;

  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = PWM_FALSE;

  /* Check if PWM Driver is initialized */
  if (Pwm_GblDriverStatus != PWM_INITIALIZED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_DUTYCYCLE_SID,
                                                            PWM_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  /* Check ChannelNumber is in the valid range */
  if (ChannelNumber > PWM_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_DUTYCYCLE_SID,
                                                     PWM_E_PARAM_CHANNEL);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }

  /* Check for valid Duty range */
  if (DutyCycle > MAX_DUTY_CYCLE)
  {
     /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_DUTYCYCLE_SID,
                                                         PWM_E_PARAM_VALUE);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  else
  {
  /* For Misra Compliance */
  }

  if(PWM_FALSE == LblDetErrFlag)
  #endif /* #if (PWM_DEV_ERROR_DETECT == STD_ON) */
  {
    LddChannelId = Pwm_GpChannelTimerMap[ChannelNumber];

    #if(PWM_DEV_ERROR_DETECT == STD_ON)
    /* Check ChannelNumber is configured */
    if (PWM_CHANNEL_UNCONFIGURED == LddChannelId)
    {
      /* Report to DET module */
      Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_DUTYCYCLE_SID,
                                                       PWM_E_PARAM_CHANNEL);
    }
    else
    #endif
    {
      /* Set the Duty cycle for the required channel */
      Pwm_HW_SetDutyCycle(LddChannelId, DutyCycle);
    }
  }
}

#define PWM_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of (PWM_SET_DUTY_CYCLE_API == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_SetPeriodAndDuty
**
** Service ID           : 0x03
**
** Description          : This API is used to set the required Period and Duty
**                        cycle for a PWM channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber, Period, DutyCycle.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_SET_PERIOD_AND_DUTY_API is STD_ON.
**
** Remarks              : Global Variable(s):
**                        Pwm_GblDriverStatus, Pwm_GpChannelConfig,
**                        Pwm_GpChannelTimerMap
**                        Function(s) invoked:
**                        Det_ReportError, Pwm_HW_SetPeriodAndDuty
*******************************************************************************/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, PWM_PUBLIC_CODE) Pwm_SetPeriodAndDuty
(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle)
{
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Pointer pointing to the channel configuration */
  P2CONST(Tdd_Pwm_ChannelConfigType,AUTOMATIC,PWM_CONFIG_CONST)LpChannel;
  #endif
  Pwm_ChannelType LddChannelId;

  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = PWM_FALSE;

  /* Check if PWM Driver is initialized */
  if (Pwm_GblDriverStatus != PWM_INITIALIZED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_PERIODANDDUTY_SID,
                                                                PWM_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  /* Check ChannelNumber is in the valid range */
  if (ChannelNumber > PWM_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_PERIODANDDUTY_SID,
                                                         PWM_E_PARAM_CHANNEL);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }

  /* Check for valid Period */
  if (((PWM_TAUJ_UNIT_USED != STD_ON) \
                       && (Period > PWM_TAUABC_MAX_PERIOD_VALUE)) || \
                       (PWM_ZERO == Period))

  {
     /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_PERIODANDDUTY_SID,
                                                         PWM_E_PARAM_VALUE);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  /* Check for valid Duty range */
  if (DutyCycle > MAX_DUTY_CYCLE)
  {
     /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_PERIODANDDUTY_SID,
                                                         PWM_E_PARAM_VALUE);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  else
  {
  /* For Misra Compliance */
  }

  if(PWM_FALSE == LblDetErrFlag)
  #endif /* #if (PWM_DEV_ERROR_DETECT == STD_ON) */
  {

    LddChannelId = Pwm_GpChannelTimerMap[ChannelNumber];
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    LpChannel = &Pwm_GpChannelConfig[LddChannelId];
    /* Check ChannelNumber is configured */
    if (PWM_CHANNEL_UNCONFIGURED == LddChannelId)
    {
      /* Report to DET module */
      Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_PERIODANDDUTY_SID,
                                                         PWM_E_PARAM_CHANNEL);
    }
    /* Check if Channel configured in Master Mode and Check if the Channel
     * is of fixed period type
     */
    else if ((PWM_MASTER_CHANNEL == LpChannel->uiTimerMode) &&
             ((PWM_FIXED_PERIOD == LpChannel->enClassType) ||
              (PWM_FIXED_PERIOD_SHIFTED == LpChannel->enClassType)))
    {
      /* Report to DET module */
      Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                      PWM_SET_PERIODANDDUTY_SID, PWM_E_PERIOD_UNCHANGEABLE);
    }
    else
    #endif
    {
      /* Set Period and Duty cycle for the required channel */
      Pwm_HW_SetPeriodAndDuty(LddChannelId, Period, DutyCycle);
    }
  }
}

#define PWM_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_SetOutputToIdle
**
** Service ID           : 0x04
**
** Description          : This API is used to set the output of PWM channel to
**                        its configured Idle state.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile option
**                          PWM_SET_OUTPUT_TO_IDLE_API is STD_ON.
**
** Remarks              : Global Variable(s):
**                        Pwm_GblDriverStatus
**                        Function(s) invoked:
**                        Det_ReportError, Pwm_HW_SetOutputToIdle
*******************************************************************************/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, PWM_PUBLIC_CODE) Pwm_SetOutputToIdle
(Pwm_ChannelType ChannelNumber)
{
  Pwm_ChannelType LddChannelId;

  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = PWM_FALSE;

  /* Check if PWM Driver is initialized */
  if (Pwm_GblDriverStatus != PWM_INITIALIZED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_OUTPUTTOIDLE_SID,
                                                               PWM_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  /* Check ChannelNumber is in the valid range */
  if (ChannelNumber > PWM_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_OUTPUTTOIDLE_SID,
                                                        PWM_E_PARAM_CHANNEL);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  else
  {
  /* For Misra Compliance */
  }

  if(PWM_FALSE == LblDetErrFlag)
  #endif /* End of (PWM_DEV_ERROR_DETECT == STD_ON) */
  {
    LddChannelId = Pwm_GpChannelTimerMap[ChannelNumber];

    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* Check ChannelNumber is configured */
    if (PWM_CHANNEL_UNCONFIGURED == LddChannelId)
    {
      /* Report to DET module */
      Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SET_OUTPUTTOIDLE_SID,
                                                        PWM_E_PARAM_CHANNEL);
    }
    else
    #endif /* End of (PWM_DEV_ERROR_DETECT == STD_ON) */
    {
      /* Set the output of a channel to its Idle state */
      Pwm_HW_SetOutputToIdle(LddChannelId);
    }
  }
}

#define PWM_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_GetOutputState
**
** Service ID           : 0x05
**
** Description          : This API is used to get the output state of PWM
**                        channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Pwm_OutputStateType (PWM_LOW / PWM_HIGH)
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile
**                          option PWM_GET_OUTPUT_STATE_API is STD_ON.
**
** Remarks              : Global Variable(s):
**                        Pwm_GblDriverStatus
**                        Function(s) invoked:
**                        Det_ReportError, Pwm_HW_GetOutputState
*******************************************************************************/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Pwm_OutputStateType, PWM_PUBLIC_CODE) Pwm_GetOutputState
(Pwm_ChannelType ChannelNumber)
{
  Pwm_ChannelType LddChannelId;
  Pwm_OutputStateType LddRetOutputState;

  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = PWM_FALSE;

  /* Initialise the return value in case of DET error */
  LddRetOutputState = PWM_LOW;

  /* Check if PWM Driver is initialized */
  if (Pwm_GblDriverStatus != PWM_INITIALIZED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_GET_OUTPUTSTATE_SID,
                                                              PWM_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  /* Check ChannelNumber is in the valid range */
  if (ChannelNumber > PWM_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_GET_OUTPUTSTATE_SID,
                                                       PWM_E_PARAM_CHANNEL);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  else
  {
  /* For Misra Compliance */
  }

  if(PWM_FALSE == LblDetErrFlag)
  #endif /* End of (PWM_DEV_ERROR_DETECT == STD_ON) */
  {
    LddChannelId = Pwm_GpChannelTimerMap[ChannelNumber];
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* Check ChannelNumber is configured */
    if (PWM_CHANNEL_UNCONFIGURED == LddChannelId)
    {
      /* Report to DET module */
      Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_GET_OUTPUTSTATE_SID,
                                                         PWM_E_PARAM_CHANNEL);
    }
    else
    #endif /* End of (PWM_DEV_ERROR_DETECT == STD_ON) */
    {
      /* Get the output state of a PWM channel */
      LddRetOutputState = Pwm_HW_GetOutputState(LddChannelId);
    }
  }
  return LddRetOutputState;
}

#define PWM_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of (PWM_GET_OUTPUT_STATE_API == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_DisableNotification
**
** Service ID           : 0x06
**
** Description          : This API is used to disable the notifications of a
**                        PWM channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile option
**                          PWM_NOTIFICATION_SUPPORTED is STD_ON.
**
** Remarks              : Global Variable(s):
**                        Pwm_GblDriverStatus, Pwm_GpChannelTimerMap,
**                        Pwm_GpChannelConfig, Pwm_GpNotifStatus
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
#if(PWM_NOTIFICATION_SUPPORTED == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, PWM_PUBLIC_CODE) Pwm_DisableNotification
(Pwm_ChannelType ChannelNumber)
{
  Pwm_ChannelType LddChannelId;
  /* Pointer to channel configuration */
  P2CONST(Tdd_Pwm_ChannelConfigType,AUTOMATIC,PWM_CONFIG_CONST)LpChannelConfig;

  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = PWM_FALSE;

  /* Check if PWM Driver is initialized */
  if (Pwm_GblDriverStatus != PWM_INITIALIZED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                    PWM_DISABLENOTIFICATION_SID,PWM_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  /* Check ChannelNumber is in the valid range */
  if (ChannelNumber > PWM_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                    PWM_DISABLENOTIFICATION_SID,PWM_E_PARAM_CHANNEL);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  else
  {
  /* For Misra Compliance */
  }

  if(PWM_FALSE == LblDetErrFlag)
  #endif /* End of (PWM_DEV_ERROR_DETECT == STD_ON) */
  {
    LddChannelId = Pwm_GpChannelTimerMap[ChannelNumber];

    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* Check ChannelNumber is configured */
    if (PWM_CHANNEL_UNCONFIGURED == LddChannelId)
    {
      /* Report to DET module */
      Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                      PWM_DISABLENOTIFICATION_SID,PWM_E_PARAM_CHANNEL);
    }
    /* Check the notification is already disabled */
    else if (PWM_FALSE == Pwm_GpNotifStatus[LddChannelId])
    {
      /* Report to DET module */
      Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                      PWM_DISABLENOTIFICATION_SID,PWM_E_ALREADY_DISABLED);
    }
    else
    #endif /* End of (PWM_DEV_ERROR_DETECT == STD_ON) */
    {
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */
      LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;

      /* Check whether any notifications is configured for this channel */
      if (PWM_NO_CBK_CONFIGURED != LpChannelConfig->ucNotificationConfig)
      {
        /* MISRA Rule         : 12.7                                     */
        /* Message            : Bitwise operations on the signed data    */
        /*                      will give implementation defined results */
        /* Reason             : Though the bitwise operation is          */
        /*                      performed on unsigned data, this warning */
        /*                      is generated by the QAC tool V6.2.1 as   */
        /*                      an indirect result of integral promotion */
        /*                      in complex bitwise                       */
        /*                      operations.                              */
        /* Verification       : However, this part of the code is        */
        /*                      verified manually and it is not having   */
        /*                      any impact.                              */
        /* Disabling the interrupt processing of the current channel */
        *(LpChannelConfig->pImrIntrCntlRegs) |=
          ~(LpChannelConfig->ucImrMaskValue);
        /* Notification is disabled */
        Pwm_GpNotifStatus[LddChannelId] = PWM_FALSE;
      }
      else
      {
      /* For Misra Compliance */
      }
    }
  }
}

#define PWM_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of (PWM_NOTIFICATION_SUPPORTED == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_EnableNotification
**
** Service ID           : 0x07
**
** Description          : This API is used to enable the notifications for a
**                        PWM channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : ChannelNumber, Notification
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : 1.PWM Driver should be initialized.
**                        2.This API is available only if the pre-compile option
**                          PWM_NOTIFICATION_SUPPORTED is STD_ON.
**
** Remarks              : Global Variable(s):
**                        Pwm_GblDriverStatus, Pwm_GpChannelTimerMap,
**                        Pwm_GpChannelConfig, Pwm_GpNotifStatus
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

#define PWM_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, PWM_PUBLIC_CODE) Pwm_EnableNotification
(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification)
{
  /* Pointer to channel configuration */
  P2CONST(Tdd_Pwm_ChannelConfigType,AUTOMATIC,PWM_CONFIG_CONST)LpChannelConfig;
  Pwm_ChannelType LddChannelId;

  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = PWM_FALSE;

  /* Check if PWM Driver is initialized */
  if (PWM_INITIALIZED != Pwm_GblDriverStatus)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_ENABLENOTIFICATION_SID,
                                                                 PWM_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  /* Check ChannelNumber is in the valid range */
  if (ChannelNumber > PWM_MAX_CHANNEL_ID_CONFIGURED)
  {
    /* Report to DET module */
    Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_ENABLENOTIFICATION_SID,
                                                          PWM_E_PARAM_CHANNEL);
    /* Set error status flag to true */
    LblDetErrFlag = PWM_TRUE;
  }
  else
  {
  /* For Misra Compliance */
  }

  if(PWM_FALSE == LblDetErrFlag)
  #endif /* End of (PWM_DEV_ERROR_DETECT == STD_ON) */
  {
    LddChannelId = Pwm_GpChannelTimerMap[ChannelNumber];

    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* Check ChannelNumber is configured */
    if (PWM_CHANNEL_UNCONFIGURED == LddChannelId)
    {
      /* Report to DET module */
      Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                      PWM_ENABLENOTIFICATION_SID, PWM_E_PARAM_CHANNEL);
    }
    else if (PWM_TRUE == Pwm_GpNotifStatus[LddChannelId])
    {
      /* Report to DET module */
      Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID,
                      PWM_ENABLENOTIFICATION_SID, PWM_E_ALREADY_ENABLED);
    }
    else
    #endif /* #if (PWM_DEV_ERROR_DETECT == STD_ON) */
    {
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;
      /* Check for channel in the Slave Mode */
      if(PWM_MASTER_CHANNEL != LpChannelConfig->uiTimerMode)
      {
        if(PWM_BOTH_EDGES == Notification)
        {
          /* Check whether any notification is configured for this channel */
          if(PWM_NO_CBK_CONFIGURED != LpChannelConfig->ucNotificationConfig)
          {
            /* Set the Notification enable status as PWM_TRUE
             * for this channel
             */
            Pwm_GpNotifStatus[LddChannelId] = PWM_TRUE;

            /* MISRA Rule         : 12.7                                   */
            /* Message            : Bitwise operations on the signed data  */
            /*                      will give implementation defined       */
            /*                      results.                               */
            /* Reason             : Though the bitwise operation is        */
            /*                      performed on unsigned data, this       */
            /*                      warning is generated by the QAC tool   */
            /*                      V6.2.1 as an indirect result of        */
            /*                      integral promotion in complex bitwise  */
            /*                      operations.                            */
            /* Verification       : However, this part of the code is      */
            /*                      verified manually and it is not having */
            /*                      any impact.                            */

            /* Check whether the interrupt channel is enable */
            if ((*(LpChannelConfig->pImrIntrCntlRegs)
                 | ~(LpChannelConfig->ucImrMaskValue)) != PWM_ZERO)
            {
              /* MISRA Rule         : 12.7                                   */
              /* Message            : Bitwise operations on the signed data  */
              /*                      will give implementation defined       */
              /*                      results.                               */
              /* Reason             : Though the bitwise operation is        */
              /*                      performed on unsigned data, this       */
              /*                      warning is generated by the QAC tool   */
              /*                      V6.2.1 as an indirect result of        */
              /*                      integral promotion in complex bitwise  */
              /*                      operations.                            */
              /* Verification       : However, this part of the code is      */
              /*                      verified manually and it is not having */
              /*                      any impact.                            */

              /* Disabling the interrupt processing of the current channel */
              *(LpChannelConfig->pImrIntrCntlRegs) |=
                ~(LpChannelConfig->ucImrMaskValue);
              /* Clearing the interrupt request flag */
              *(LpChannelConfig->pIntrCntlRegs) &= PWM_CLEAR_INT_REQUEST_FLAG;
              /* Enable the interrupt processing of the current channel */
              *(LpChannelConfig->pImrIntrCntlRegs) &=
                LpChannelConfig->ucImrMaskValue;
            }
          }
          else
          {
          /* For Misra Compliance */
          }


          /* Get Master's channel ID */
          LddChannelId -= LpChannelConfig->ucMasterOffset;

          /* MISRA Rule         : 17.4                            */
          /* Message            : Performing pointer arithmetic.  */
          /* Reason             : For code optimization.          */
          /* Verification       : However, part of the code is    */
          /*                      verified manually and it is not */
          /*                      having any impact.              */

          /* Get Master's channel Config */
          LpChannelConfig -= LpChannelConfig->ucMasterOffset;

          /* Check whether any notification is configured for this channel */
          if(PWM_NO_CBK_CONFIGURED != LpChannelConfig->ucNotificationConfig)
          {
            /* Set the Notification enable status as PWM_TRUE
             * for Master channel
             */
            Pwm_GpNotifStatus[LddChannelId] = PWM_TRUE;

            /* MISRA Rule         : 12.7                                   */
            /* Message            : Bitwise operations on the signed data  */
            /*                      will give implementation defined       */
            /*                      results.                               */
            /* Reason             : Though the bitwise operation is        */
            /*                      performed on unsigned data, this       */
            /*                      warning is generated by the QAC tool   */
            /*                      V6.2.1 as an indirect result of        */
            /*                      integral promotion in complex bitwise  */
            /*                      operations.                            */
            /* Verification       : However, this part of the code is      */
            /*                      verified manually and it is not having */
            /*                      any impact.                            */

            /* Check whether the interrupt channel is enable */
            if ((*(LpChannelConfig->pImrIntrCntlRegs)
                 | ~(LpChannelConfig->ucImrMaskValue)) != PWM_ZERO)
            {
              /* MISRA Rule         : 12.7                                   */
              /* Message            : Bitwise operations on the signed data  */
              /*                      will give implementation defined       */
              /*                      results.                               */
              /* Reason             : Though the bitwise operation is        */
              /*                      performed on unsigned data, this       */
              /*                      warning is generated by the QAC tool   */
              /*                      V6.2.1 as an indirect result of        */
              /*                      integral promotion in complex bitwise  */
              /*                      operations.                            */
              /* Verification       : However, this part of the code is      */
              /*                      verified manually and it is not having */
              /*                      any impact.                            */

              /* Disabling the interrupt processing of the current channel */
              *(LpChannelConfig->pImrIntrCntlRegs) |=
                ~(LpChannelConfig->ucImrMaskValue);
              /* Clearing the interrupt request flag */
              *(LpChannelConfig->pIntrCntlRegs) &= PWM_CLEAR_INT_REQUEST_FLAG;
              /* Enable the interrupt processing of the current channel */
              *(LpChannelConfig->pImrIntrCntlRegs) &=
                LpChannelConfig->ucImrMaskValue;
            }
          }
          else
          {
          /* For Misra Compliance */
          }
        }
        else if (PWM_RISING_EDGE == Notification)
        {
          /* MISRA Rule         : 17.4                            */
          /* Message            : Performing pointer arithmetic.  */
          /* Reason             : For code optimization.          */
          /* Verification       : However, part of the code is    */
          /*                      verified manually and it is not */
          /*                      having any impact.              */

          /* Get Master's channel Config */
          LpChannelConfig -= LpChannelConfig->ucMasterOffset;
          /* Get Master's channel ID */
          LddChannelId -= LpChannelConfig->ucMasterOffset;

          /* Check whether any notification is configured for this channel */
          if(PWM_NO_CBK_CONFIGURED != LpChannelConfig->ucNotificationConfig)
          {
            /* Set the Notification enable status as PWM_TRUE
             * for this channel
             */
            Pwm_GpNotifStatus[LddChannelId] = PWM_TRUE;

            /* MISRA Rule         : 12.7                                   */
            /* Message            : Bitwise operations on the signed data  */
            /*                      will give implementation defined       */
            /*                      results.                               */
            /* Reason             : Though the bitwise operation is        */
            /*                      performed on unsigned data, this       */
            /*                      warning is generated by the QAC tool   */
            /*                      V6.2.1 as an indirect result of        */
            /*                      integral promotion in complex bitwise  */
            /*                      operations.                            */
            /* Verification       : However, this part of the code is      */
            /*                      verified manually and it is not having */
            /*                      any impact.                            */

            /* Check whether the interrupt channel is enable */
            if ((*(LpChannelConfig->pImrIntrCntlRegs)
                 | ~(LpChannelConfig->ucImrMaskValue)) != PWM_ZERO)
            {
              /* MISRA Rule         : 12.7                                   */
              /* Message            : Bitwise operations on the signed data  */
              /*                      will give implementation defined       */
              /*                      results.                               */
              /* Reason             : Though the bitwise operation is        */
              /*                      performed on unsigned data, this       */
              /*                      warning is generated by the QAC tool   */
              /*                      V6.2.1 as an indirect result of        */
              /*                      integral promotion in complex bitwise  */
              /*                      operations.                            */
              /* Verification       : However, this part of the code is      */
              /*                      verified manually and it is not having */
              /*                      any impact.                            */

              /* Disabling the interrupt processing of the current channel */
              *(LpChannelConfig->pImrIntrCntlRegs) |=
                ~(LpChannelConfig->ucImrMaskValue);
              /* Clearing the interrupt request flag */
              *(LpChannelConfig->pIntrCntlRegs) &= PWM_CLEAR_INT_REQUEST_FLAG;
              /* Enable the interrupt processing of the current channel */
              *(LpChannelConfig->pImrIntrCntlRegs) &=
                LpChannelConfig->ucImrMaskValue;
            }
          }
        }
        /* For FALLING EDGE Notification */
        else
        {
          /* Set the Notification enable status as PWM_TRUE
           * for this channel
           */
          Pwm_GpNotifStatus[LddChannelId] = PWM_TRUE;

          /* MISRA Rule         : 12.7                                     */
          /* Message            : Bitwise operations on the signed data    */
          /*                      will give implementation defined results */
          /* Reason             : Though the bitwise operation is          */
          /*                      performed on unsigned data, this warning */
          /*                      is generated by the QAC tool V6.2.1 as   */
          /*                      an indirect result of integral promotion */
          /*                      in complex bitwise                       */
          /*                      operations.                              */
          /* Verification       : However, this part of the code is        */
          /*                      verified manually and it is not having   */
          /*                      any impact.                              */

          /* Check whether the interrupt channel is enable */
          if ((*(LpChannelConfig->pImrIntrCntlRegs)
               | ~(LpChannelConfig->ucImrMaskValue)) != PWM_ZERO)
          {
            /* MISRA Rule         : 12.7                                     */
            /* Message            : Bitwise operations on the signed data    */
            /*                      will give implementation defined results */
            /* Reason             : Though the bitwise operation is          */
            /*                      performed on unsigned data, this warning */
            /*                      is generated by                          */
            /*                      the QAC tool V6.2.1 as an indirect result*/
            /*                      of integral promotion in complex bitwise */
            /*                      operations.                              */
            /* Verification       : However, this part of the code is        */
            /*                      verified manually and it is not having   */
            /*                      any impact.                              */

            /* Disabling the interrupt processing of the current channel */
            *(LpChannelConfig->pImrIntrCntlRegs) |=
              ~(LpChannelConfig->ucImrMaskValue);
            /* Clearing the interrupt request flag */
            *(LpChannelConfig->pIntrCntlRegs) &= PWM_CLEAR_INT_REQUEST_FLAG;
            /* Enable the interrupt processing of the current channel */
            *(LpChannelConfig->pImrIntrCntlRegs) &=
              LpChannelConfig->ucImrMaskValue;
          }
        }
      }/* End of if(PWM_MASTER_CHANNEL != LpChannelConfig->uiTimerMode) */
      else
      {
      /* For Misra Compliance */
      }
    }
  } /* End of if(LblDetErrFlag == PWM_FALSE) */
}

#define PWM_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of (PWM_NOTIFICATION_SUPPORTED == STD_ON) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
