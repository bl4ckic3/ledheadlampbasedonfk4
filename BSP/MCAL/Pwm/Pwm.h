/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Pwm.h                                                       */
/* Version      = 3.1.3                                                       */
/* Date         = 12-Jul-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of API information.                                              */
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
 * V3.0.1:  02-Jul-2010  : As per SCR 290, structure "Pwm_ConfigType" is
 *                         updated to support TAUB and TAUC timer units.
 * V3.0.2:  28-Jul-2010  : As per SCR 321, unused element in the structure
 *                         Pwm_ConfigType is removed.
 * V3.0.3:  29-Apr-2011  : As per SCR 435, PWM_E_PARAM_VALUE DET is added.
 * V3.1.0:  26-Jul-2011  : Ported for the DK4 variant.
 * V3.1.1:  05-Mar-2012  : Merged the fixes done for Fx4L PWM driver
 * V3.1.2:  06-Jun-2012  : As per SCR 034, following changes are made:
 *                         1. File version is changed.
 *                         2. Compiler version is removed from Environment
 *                            section.
 *                         3. Function Pwm_GetVersionInfo is implemented as
 *                            Macro.
 * V3.1.3:  12-Jul-2012  : As per SCR 051, PWM_SW_PATCH_VERSION is updated.
 */
/******************************************************************************/

#ifndef PWM_H
#define PWM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Pwm_Cfg.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* Version identification */
#define PWM_VENDOR_ID              PWM_VENDOR_ID_VALUE
#define PWM_MODULE_ID              PWM_MODULE_ID_VALUE
#define PWM_INSTANCE_ID            PWM_INSTANCE_ID_VALUE

/* AUTOSAR specification version information */
#define PWM_AR_MAJOR_VERSION       PWM_AR_MAJOR_VERSION_VALUE
#define PWM_AR_MINOR_VERSION       PWM_AR_MINOR_VERSION_VALUE
#define PWM_AR_PATCH_VERSION       PWM_AR_PATCH_VERSION_VALUE

/* Software version information */
#define PWM_SW_MAJOR_VERSION       3
#define PWM_SW_MINOR_VERSION       1
#define PWM_SW_PATCH_VERSION       3

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PWM_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION)
  #error "Pwm.h : Mismatch in Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION)
  #error "Pwm.h : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                     Service Ids                                            **
*******************************************************************************/

/* Service Id of Pwm_Init */
#define PWM_INIT_SID                    (uint8)0x00

/* Service Id of Pwm_DeInit */
#define PWM_DEINIT_SID                  (uint8)0x01

/* Service Id of Pwm_SetDutyCycle */
#define PWM_SET_DUTYCYCLE_SID           (uint8)0x02

/* Service Id of Pwm_SetPeriodAndDuty */
#define PWM_SET_PERIODANDDUTY_SID       (uint8)0x03

/* Service Id of Pwm_SetOutputToIdle */
#define PWM_SET_OUTPUTTOIDLE_SID        (uint8)0x04

/* Service Id of Pwm_GetOutputState */
#define PWM_GET_OUTPUTSTATE_SID         (uint8)0x05

/* Service Id of Pwm_DisableNotification */
#define PWM_DISABLENOTIFICATION_SID     (uint8)0x06

/* Service Id of Pwm_EnableNotification */
#define PWM_ENABLENOTIFICATION_SID      (uint8)0x07

/* Service Id of Pwm_GetVersionInfo */
#define PWM_GET_VERSION_INFO_SID        (uint8)0x08

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* Pwm_Init API called with wrong parameter */
#define PWM_E_PARAM_CONFIG              (uint8)0x10

/* When PWM APIs are invoked before PWM Module Initialisation */
#define PWM_E_UNINIT                    (uint8)0x11

/* When PWM APIs are invoked with invalid channel identifier */
#define PWM_E_PARAM_CHANNEL             (uint8)0x12

/* Invoking the PWM APIs on PWM channel configured as Fixed period */
#define PWM_E_PERIOD_UNCHANGEABLE       (uint8)0x13

/* Pwm_Init API called when PWM module is already initialised */
#define PWM_E_ALREADY_INITIALIZED       (uint8)0x14

/* Invoking Pwm_EnableNotification API for the configured
   channel whose notification is already enabled */
#define PWM_E_ALREADY_ENABLED           (uint8)0xEE

/* Invoking Pwm_DisableNotification API for the configured
   channel whose notification is already disabled */
#define PWM_E_ALREADY_DISABLED          (uint8)0xEF

/* When valid Database is not available */
#define PWM_E_INVALID_DATABASE          (uint8)0xF0

/* Pwm_GetVersionInfo  API called with NULL_PTR parameter */
#define PWM_E_PARAM_POINTER             (uint8)0xF1

/* When PWM APIs Pwm_SetDutyCycle and Pwm_SetPeriodAndDuty are invoked with
 * invalid parameter values */
#define PWM_E_PARAM_VALUE               (uint8)0xF2


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Type definition for Pwm_ChannelType */
typedef uint8  Pwm_ChannelType;

#if(PWM_TAUJ_UNIT_USED == STD_ON)
/* Type definition for Pwm_PeriodType if TAUJ is used */
typedef uint32 Pwm_PeriodType;
#else
/* Type definition for Pwm_PeriodType if only TAUA is used */
typedef uint16 Pwm_PeriodType;
#endif

/* Type definition for Pwm_OutputStateType */
typedef enum
{
  PWM_LOW,
  PWM_HIGH
}Pwm_OutputStateType;

/* Type definition for Pwm_EdgeNotificationType */
typedef enum
{
  PWM_RISING_EDGE,
  PWM_FALLING_EDGE,
  PWM_BOTH_EDGES
}Pwm_EdgeNotificationType;

/* Type definition for Pwm_ChannelClassType */
typedef enum
{
  PWM_VARIABLE_PERIOD,
  PWM_FIXED_PERIOD,
  PWM_FIXED_PERIOD_SHIFTED
}Pwm_ChannelClassType;

/* Structure for Pwm_Init configuration */
/* Overall module configuration data structure */
typedef struct STagPwm_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;

  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) ||\
      (PWM_TAUC_UNIT_USED == STD_ON))
  /* Pointer to PWM Driver TAUA/TAUB/TAUC Unit configuration */
  P2CONST(void, AUTOMATIC, PWM_CONFIG_CONST)pTAUABCUnitConfig;
  #endif

  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer to PWM Driver TAUJ Unit configuration */
  P2CONST(void, AUTOMATIC, PWM_CONFIG_CONST)pTAUJUnitConfig;
  #endif

  /* Pointer to PWM Driver channel configuration */
  P2CONST(void, AUTOMATIC, PWM_CONFIG_CONST)pChannelConfig;

  #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
  /* Pointer to PWM Driver synch start configuration */
  P2CONST(void, AUTOMATIC, PWM_CONFIG_CONST)pSynchStartConfig;
  #endif

  /* Pointer to address of Timer to channel index array */
  P2CONST(uint8, AUTOMATIC,PWM_CONFIG_CONST)pChannelTimerMap;

  #if(PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* Pointer to Array for Notification status of TAU timers configured */
  P2VAR(uint8, AUTOMATIC, PWM_CONFIG_DATA)pNotifStatus;
  #endif

  /* Pointer to Array for Idle state status for all channels configured */
  P2VAR(uint8, AUTOMATIC, PWM_CONFIG_DATA)pChannelIdleStatus;

}Pwm_ConfigType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define PWM_START_SEC_PUBLIC_CODE
#include "MemMap.h"

extern FUNC(void, PWM_PUBLIC_CODE) Pwm_Init
(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST)ConfigPtr);

#if (PWM_DE_INIT_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_DeInit (void);
#endif

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SetDutyCycle
(Pwm_ChannelType ChannelNumber, uint16 DutyCycle);
#endif

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SetPeriodAndDuty
(Pwm_ChannelType ChannelNumber, Pwm_PeriodType  Period, uint16 DutyCycle);
#endif

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_SetOutputToIdle
(Pwm_ChannelType ChannelNumber);
#endif

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
extern FUNC(Pwm_OutputStateType, PWM_PUBLIC_CODE) Pwm_GetOutputState
(Pwm_ChannelType ChannelNumber);
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
extern FUNC(void, PWM_PUBLIC_CODE) Pwm_EnableNotification
(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification);

extern FUNC(void, PWM_PUBLIC_CODE) Pwm_DisableNotification
(Pwm_ChannelType ChannelNumber);
#endif

#if (PWM_VERSION_INFO_API == STD_ON)
#define Pwm_GetVersionInfo(versioninfo)\
{\
    (versioninfo)->vendorID = (uint16)PWM_VENDOR_ID; \
    (versioninfo)->moduleID = (uint16)PWM_MODULE_ID; \
    (versioninfo)->instanceID = (uint8)PWM_INSTANCE_ID; \
    (versioninfo)->sw_major_version = PWM_SW_MAJOR_VERSION; \
    (versioninfo)->sw_minor_version = PWM_SW_MINOR_VERSION; \
    (versioninfo)->sw_patch_version = PWM_SW_PATCH_VERSION; \
}
#endif /*(PWM_VERSION_INFO_API == STD_ON)*/

#define PWM_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define PWM_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(Pwm_ConfigType, PWM_CONST) Pwm_GstConfiguration[];

#define PWM_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#endif  /* PWM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
