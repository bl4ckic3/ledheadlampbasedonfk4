/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Gpt.h                                                       */
/* Version      = 3.0.5a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, GPT type definitions, structure data types and  */
/* API function prototypes of GPT Driver                                      */
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

/******************************************************************************
**                      Revision Control History                             **
*******************************************************************************/
/*
 * V3.0.0:  23-Oct-2009    : Initial Version
 * V3.0.1:  09-Nov-2009    : Std_Types.h is included.
 * V3.0.2:  25-Feb-2010    : As per SCR 194, precompile option for TAU is added
 *                           in the structure "Gpt_ConfigType" for the member
 *                           "pTAUUnitConfig".
 * V3.0.3:  23-Jun-2010    : As per SCR 281, structure "Gpt_ConfigType" is
 *                           updated to support TAUB and TAUC timer units.
 * V3.0.4:  28-Jul-2010    : As per SCR 317, Std_Types.h is removed.
 * V3.0.5:  13-Sep-2010    : As per SCR 353, Std_Types.h is included.
 * V3.0.5a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/
#ifndef GPT_H
#define GPT_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Gpt_Cfg.h"
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM_Cbk.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* Version identification */
#define GPT_VENDOR_ID              GPT_VENDOR_ID_VALUE
#define GPT_MODULE_ID              GPT_MODULE_ID_VALUE
#define GPT_INSTANCE_ID            GPT_INSTANCE_ID_VALUE

/* AUTOSAR specification version information */
#define GPT_AR_MAJOR_VERSION       GPT_AR_MAJOR_VERSION_VALUE
#define GPT_AR_MINOR_VERSION       GPT_AR_MINOR_VERSION_VALUE
#define GPT_AR_PATCH_VERSION       GPT_AR_PATCH_VERSION_VALUE

/* File version information */
#define GPT_SW_MAJOR_VERSION       GPT_SW_MAJOR_VERSION_VALUE
#define GPT_SW_MINOR_VERSION       GPT_SW_MINOR_VERSION_VALUE
#define GPT_SW_PATCH_VERSION       GPT_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                        Service IDs                                         **
*******************************************************************************/

/* Service Id of Gpt_GetVersionInfo */
#define GPT_GET_VERSION_INFO_SID   (uint8)0x00
/* Service Id of Gpt_Init */
#define GPT_INIT_SID               (uint8)0x01
/* Service Id of Gpt_DeInit */
#define GPT_DEINIT_SID             (uint8)0x02
/* Service Id of Gpt_GetTimeElapsed */
#define GPT_GET_TIME_ELAPSED_SID   (uint8)0x03
/* Service Id of Gpt_GetTimeRemaining */
#define GPT_GET_TIME_REMAINING_SID (uint8)0x04
/* Service Id of Gpt_StartTimer */
#define GPT_START_TIMER_SID        (uint8)0x05
/* Service Id of Gpt_StopTimer */
#define GPT_STOP_TIMER_SID         (uint8)0x06
/* Service Id of Gpt_EnableNotification */
#define GPT_ENABLE_NOTIFY_SID      (uint8)0x07
/* Service Id of Gpt_DisableNotification */
#define GPT_DISABLE_NOTIFY_SID     (uint8)0x08
/* Service Id of Gpt_SetMode */
#define GPT_SET_MODE_SID           (uint8)0x09
/* Service Id of Gpt_DisableWakeup */
#define GPT_DISABLE_WAKEUP_SID     (uint8)0x0A
/* Service Id of Gpt_EnableWakeup */
#define GPT_ENABLE_WAKEUP_SID      (uint8)0x0B
/* Service Id of  Gpt_Cbk_CheckWakeup */
#define GPT_CBK_CHECK_WAKEUP_SID   (uint8)0x0C

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* DET code to report uninitialized state */
#define GPT_E_UNINIT               (uint8)0x0A

/* DET code to report Timer is already running */
#define GPT_E_BUSY                 (uint8)0x0B

/* DET code to report Timer has not been started yet */
#define GPT_E_NOT_STARTED          (uint8)0x0C

/* DET code to report Timer already Initialized */
#define GPT_E_ALREADY_INITIALIZED  (uint8)0x0D

/* DET code to report invalid Channel Identifier */
#define GPT_E_PARAM_CHANNEL        (uint8)0x14

/* DET code to report invalid timer value */
#define GPT_E_PARAM_VALUE          (uint8)0x15

/* DET code to report Gpt_Init called with NULL as parameter */
#define GPT_E_PARAM_CONFIG         (uint8)0x1E

/* DET code to report invalid mode parameter */
#define GPT_E_PARAM_MODE           (uint8)0x1F

/* DET code to report invalid database */
#define GPT_E_INVALID_DATABASE     (uint8)0xEF

/* DET code to report Gpt_GetVersionInfo called with NULL as parameter */
#define GPT_E_PARAM_POINTER        (uint8)0xF0

/* DET code to report that Gpt API service Gpt_DisableNotification
 * is invoked for the channel for which the notification is already disabled
 */
#define GPT_E_ALREADY_DISABLED     (uint8)0xF1

/* DET code to report that Gpt API service Gpt_EnableNotification
 * is invoked for the channelfor which the notification is already enabled
 */
#define GPT_E_ALREADY_ENABLED      (uint8)0xF2

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Type describing the timeout value */
typedef uint32 Gpt_ValueType;

/* Type describing the channel ID */
typedef uint8 Gpt_ChannelType;

/* Type describing the GPT modes */
typedef enum GptModeType
{
  GPT_MODE_NORMAL = 0,
  GPT_MODE_SLEEP
} Gpt_ModeType;

/* Data Structure for GPT required for Initializing the GPT timer unit */
typedef struct STagGpt_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON)||\
      (GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))
  /* Pointer to GPT driver channel configuration */
  P2CONST(void, AUTOMATIC, GPT_CONFIG_CONST) pTAUUnitConfig;
  #endif
  /* Pointer to GPT driver channel configuration */
  P2CONST(void, AUTOMATIC, GPT_CONFIG_CONST) pChannelConfig;
  /* Pointer to address of Timer to channel index array */
  P2CONST(uint8, AUTOMATIC, GPT_CONFIG_CONST)pChannelTimerMap;
  /* Pointer to address of internal RAM data */
  P2VAR(void, AUTOMATIC, GPT_CONFIG_DATA) pChannelRamAddress;

} Gpt_ConfigType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

#if (GPT_VERSION_INFO_API == STD_ON)
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) versioninfo);
#endif

extern FUNC(void, GPT_PUBLIC_CODE) Gpt_Init
(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr);

#if (GPT_DE_INIT_API == STD_ON)
extern FUNC (void, GPT_PUBLIC_CODE) Gpt_DeInit (void);
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
extern FUNC(Gpt_ValueType, GPT_PUBLIC_CODE) Gpt_GetTimeElapsed
(Gpt_ChannelType channel);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
extern FUNC(Gpt_ValueType, GPT_PUBLIC_CODE) Gpt_GetTimeRemaining
(Gpt_ChannelType channel);
#endif

extern FUNC(void, GPT_PUBLIC_CODE) Gpt_StartTimer
(Gpt_ChannelType channel, Gpt_ValueType value);

extern FUNC(void, GPT_PUBLIC_CODE) Gpt_StopTimer
(Gpt_ChannelType channel);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON )
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_EnableNotification
(Gpt_ChannelType channel);
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_DisableNotification
(Gpt_ChannelType channel);
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
 (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_SetMode
(Gpt_ModeType mode);
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
 (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_DisableWakeup
(Gpt_ChannelType channel);
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
 (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
extern FUNC(void, GPT_PUBLIC_CODE) Gpt_EnableWakeup
(Gpt_ChannelType channel);
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && \
 (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
extern FUNC(void, GPT_PUBLIC_CODE)Gpt_Cbk_CheckWakeup
(EcuM_WakeupSourceType wakeupSource);
#endif
#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define GPT_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(Gpt_ConfigType, GPT_CONST) Gpt_GstConfiguration[];

#define GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#endif  /* GPT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
