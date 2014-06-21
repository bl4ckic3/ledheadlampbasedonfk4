/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu.h                                                       */
/* Version      = 3.0.3a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, ICU type definitions, structure data types and  */
/* API function prototypes of ICU Driver                                      */
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
 * V3.0.1:  29-Oct-2009  : As per SCR 074, 'Std_Types.h' is included.
 *
 * V3.0.2:  28-Jun-2010  : As per SCR 286, structure "Icu_ConfigType" is
 *                         updated to support Timer Array Unit B.
 *
 * V3.0.3:  20-Jul-2010  : As per SCR 308, the structure 'Icu_ConfigType' is
 *                         updated with pre-compile options for timer channels.
 * V3.0.3a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef ICU_H
#define ICU_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Icu_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define ICU_AR_MAJOR_VERSION  ICU_AR_MAJOR_VERSION_VALUE
#define ICU_AR_MINOR_VERSION  ICU_AR_MINOR_VERSION_VALUE
#define ICU_AR_PATCH_VERSION  ICU_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define ICU_SW_MAJOR_VERSION  ICU_SW_MAJOR_VERSION_VALUE
#define ICU_SW_MINOR_VERSION  ICU_SW_MINOR_VERSION_VALUE
#define ICU_SW_PATCH_VERSION  ICU_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Vendor and Module IDs */
#define ICU_VENDOR_ID                       ICU_VENDOR_ID_VALUE
#define ICU_MODULE_ID                       ICU_MODULE_ID_VALUE
#define ICU_INSTANCE_ID                     ICU_INSTANCE_ID_VALUE

/* Service IDs */
/* Service ID of Icu_Init */
#define ICU_INIT_SID                        (uint8)0x00
/* Service ID of Icu_DeInit */
#define ICU_DEINIT_SID                      (uint8)0x01
/* Service ID of Icu_SetMode */
#define ICU_SET_MODE_SID                    (uint8)0x02
/* Service ID of Icu_DisableWakeup */
#define ICU_DISABLE_WAKEUP_SID              (uint8)0x03
/* Service ID of Icu_EnableWakeup */
#define ICU_ENABLE_WAKEUP_SID               (uint8)0x04
/* Service ID of Icu_SetActivationCondition */
#define ICU_SET_ACTIVATION_CONDITION_SID    (uint8)0x05
/* Service ID of Icu_DisableNotification */
#define ICU_DISABLE_NOTIFICATION_SID        (uint8)0x06
/* Service ID of Icu_EnableNotification */
#define ICU_ENABLE_NOTIFICATION_SID         (uint8)0x07
/* Service ID of Icu_GetInputState */
#define ICU_GET_INPUT_STATE_SID             (uint8)0x08
/* Service ID of Icu_StartTimestamp */
#define ICU_START_TIMESTAMP_SID             (uint8)0x09
/* Service ID of Icu_StopTimestamp */
#define ICU_STOP_TIMESTAMP_SID              (uint8)0x0A
/* Service ID of Icu_GetTimestampIndex */
#define ICU_GET_TIMESTAMP_INDEX_SID         (uint8)0x0B
/* Service ID of Icu_ResetEdgeCount */
#define ICU_RESET_EDGE_COUNT_SID            (uint8)0x0C
/* Service ID of Icu_EnableEdgeCount */
#define ICU_ENABLE_EDGE_COUNT_SID           (uint8)0x0D
/* Service ID of Icu_DisableEdgeCount */
#define ICU_DISABLE_EDGE_COUNT_SID          (uint8)0x0E
/* Service ID of Icu_GetEdgeNumbers */
#define ICU_GET_EDGE_NUMBERS_SID            (uint8)0x0F
/* Service ID of Icu_GetTimeElapsed */
#define ICU_GET_TIME_ELAPSED_SID            (uint8)0x10
/* Service ID of Icu_GetDutyCycleValues */
#define ICU_GET_DUTY_CYCLE_VALUES_SID       (uint8)0x11
/* Service ID of Icu_GetVersionInfo */
#define ICU_GET_VERSION_INFO_SID            (uint8)0x12
/* Service ID of Icu_StartSignalMeasurement */
#define ICU_START_SIGNAL_MEASUREMENT_SID    (uint8)0x13
/* Service ID of Icu_StopSignalMeasurement */
#define ICU_STOP_SIGNAL_MEASUREMENT_SID     (uint8)0x14

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* DET code to report a wrong parameter passed to Icu_Init API
 */
#define ICU_E_PARAM_CONFIG                  (uint8)0x0A

/* DET code to report that API service used with an invalid Channel Identifier
 * or Channel is not configured for the functionality of the calling API.
 */
#define ICU_E_PARAM_CHANNEL                 (uint8)0x0B

/* DET code to report that API service used with an invalid
 * or not feasible activation.
 */
#define ICU_E_PARAM_ACTIVATION              (uint8)0x0C

/* DET code to report that API service used with an invalid
 * application-buffer pointer.
 */
#define ICU_E_PARAM_BUFFER_PTR              (uint8)0x0D

/* DET code to report that API service used with an invalid buffer size
 */
#define ICU_E_PARAM_BUFFER_SIZE             (uint8)0x0E

/* DET code to report that API service Icu_SetMode used
 * with an invalid operation mode
 */
#define ICU_E_PARAM_MODE                    (uint8)0x0F

/* DET code to report that API service used without module initialization
 */
#define ICU_E_UNINIT                        (uint8)0x14

/* DET code to report that the API Icu_StopTimestamp used
 * on a channel which was not started or already stopped.
 */
#define ICU_E_NOT_STARTED                   (uint8)0x15

/* DET code to report that the API Icu_SetMode used
 * during a running operation.
 */
#define ICU_E_BUSY_OPERATION                (uint8)0x16

/* DET code to report that ICU is already initialized
 * when Icu_Init() is called
 */
#define ICU_E_ALREADY_INITIALIZED           (uint8)0x17

/* API service Icu_Init called without a database is reported using following
 * error code
 */
#define ICU_E_INVALID_DATABASE              (uint8)0xEF

/* DET code to report that the API Icu_GetVersionInfo invoked
 * with a null pointer.
 */
#define ICU_E_PARAM_POINTER                 (uint8)0xF0

/* DET code to report that Icu API service Icu_DisableNotification
 * is invoked for the channelfor which the notification is already disabled
 */
#define ICU_E_ALREADY_DISABLED              (uint8)0xF1

/* DET code to report that Icu API service Icu_EnableNotification
 * is invoked for the channelfor which the notification is already enabled
 */
#define ICU_E_ALREADY_ENABLED               (uint8)0xF2

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Numeric identifier of an ICU Channel */
typedef uint8 Icu_ChannelType;

/* Definition of the type of activation of an ICU Channel */
typedef enum Icu_ActivationType
{
  ICU_FALLING_EDGE,
  ICU_RISING_EDGE,
  ICU_BOTH_EDGES
} Icu_ActivationType;

/* Width of the buffer for storing time in terms of timer ticks  */
typedef uint32 Icu_ValueType;


/* Input state of an ICU channel */
typedef enum Icu_InputStateType
{
  ICU_IDLE,
  ICU_ACTIVE
} Icu_InputStateType;

/* Operation Mode of the ICU Module */
typedef enum Icu_ModeType
{
  ICU_MODE_NORMAL,
  ICU_MODE_SLEEP
} Icu_ModeType;

/* Type which contains the values needed for calculating duty cycles */

typedef struct STag_Icu_DutyCycleType
{
  Icu_ValueType ActiveTime;
  Icu_ValueType PeriodTime;
} Icu_DutyCycleType;

/* Type to abstract the return value of the service Icu_GetTimestampIndex() */
typedef uint16 Icu_IndexType;

/* Type to abstract the return value of the service Icu_GetEdgeNumbers() */
typedef uint16 Icu_EdgeNumberType;

/* Definition of the measurement mode type */
typedef enum Icu_MeasurementModeType
{
  ICU_MODE_SIGNAL_EDGE_DETECT,
  ICU_MODE_SIGNAL_MEASUREMENT,
  ICU_MODE_TIMESTAMP,
  ICU_MODE_EDGE_COUNTER
} Icu_MeasurementModeType;

/* Definition of the signal measurement property type */
typedef enum Icu_SignalMeasurementPropertyType
{
  ICU_LOW_TIME,
  ICU_HIGH_TIME,
  ICU_PERIOD_TIME,
  ICU_DUTY_CYCLE
} Icu_SignalMeasurementPropertyType;

/* Definition of the timestamp measurement property type */
typedef enum Icu_TimestampBufferType
{
  ICU_LINEAR_BUFFER,
  ICU_CIRCULAR_BUFFER
} Icu_TimestampBufferType;

/* Data Structure for ICU for Initializing the ICU Module */
typedef struct STagTdd_Icu_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;
  /* Pointer to ICU driver channel configuration */
  P2CONST(void, AUTOMATIC, ICU_CONFIG_CONST) pChannelConfig;
  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)||\
  (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer to ICU driver Timer channel configuration */
  P2CONST(void, AUTOMATIC, ICU_CONFIG_CONST) pTimerChannelConfig;
  /* Pointer to ICU hardware unit configuration */
  P2CONST(void, AUTOMATIC, ICU_CONFIG_CONST) pHWUnitConfig;
  #endif
  /* Pointer to Previous input configuration */
  #if(ICU_PREVIOUS_INPUT_USED == STD_ON)
  P2CONST(void, AUTOMATIC, ICU_CONFIG_CONST) pPrevInputConfig;
  #endif
  /* Pointer to the address of internal RAM data */
  P2VAR (void, AUTOMATIC, ICU_CONFIG_DATA) pRamAddress;
  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)||\
  (ICU_TAUB_UNIT_USED == STD_ON))
  /* Pointer to the address of Signal Measure RAM data */
  P2VAR (void, AUTOMATIC, ICU_CONFIG_DATA) pSignalMeasureAddress;
  /* Pointer to the address of TimeStamp RAM data */
  P2VAR (void, AUTOMATIC, ICU_CONFIG_DATA) pTimeStampAddress;
  /* Pointer to the address of Edge Count RAM data */
  P2VAR (void, AUTOMATIC, ICU_CONFIG_DATA) pEdgeCountRamAddress;
  #endif
  /* Pointer variable for ICU Channel Map */
  P2CONST(uint8, ICU_CONST, ICU_CONFIG_CONST) pChannelMap;
} Icu_ConfigType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

extern FUNC(void, ICU_PUBLIC_CODE) Icu_Init
(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr);

#if (ICU_DE_INIT_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_DeInit(void);
#endif

#if (ICU_SET_MODE_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_SetMode(Icu_ModeType Mode);
#endif

#if (ICU_DISABLE_WAKEUP_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_DisableWakeup(Icu_ChannelType Channel);
#endif

#if(ICU_ENABLE_WAKEUP_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_EnableWakeup(Icu_ChannelType Channel);
#endif

extern FUNC(void, ICU_PUBLIC_CODE) Icu_SetActivationCondition
(Icu_ChannelType Channel, Icu_ActivationType Activation);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_DisableNotification
(Icu_ChannelType Channel);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_EnableNotification
(Icu_ChannelType Channel);

#if (ICU_GET_INPUT_STATE_API == STD_ON)
extern FUNC(Icu_InputStateType, ICU_PUBLIC_CODE) Icu_GetInputState
(Icu_ChannelType Channel);
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_StartTimestamp(Icu_ChannelType Channel,
P2VAR (Icu_ValueType, AUTOMATIC, ICU_APPL_DATA)BufferPtr,
uint16 BufferSize, uint16 NotifyInterval);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_StopTimestamp (Icu_ChannelType Channel);

extern FUNC(Icu_IndexType, ICU_PUBLIC_CODE) Icu_GetTimestampIndex
(Icu_ChannelType Channel);
#endif

#if(ICU_EDGE_COUNT_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_ResetEdgeCount(Icu_ChannelType Channel);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_EnableEdgeCount(Icu_ChannelType Channel);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_DisableEdgeCount
(Icu_ChannelType Channel);

extern FUNC(Icu_EdgeNumberType, ICU_PUBLIC_CODE) Icu_GetEdgeNumbers
(Icu_ChannelType Channel);
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE) Icu_StartSignalMeasurement
(Icu_ChannelType Channel);

extern FUNC(void, ICU_PUBLIC_CODE) Icu_StopSignalMeasurement
(Icu_ChannelType Channel);
#endif

#if(ICU_GET_TIME_ELAPSED_API == STD_ON)
extern FUNC(Icu_ValueType, ICU_PUBLIC_CODE) Icu_GetTimeElapsed
(Icu_ChannelType Channel);
#endif

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE)
Icu_GetDutyCycleValues(Icu_ChannelType Channel,
P2VAR(Icu_DutyCycleType,  AUTOMATIC, ICU_APPL_DATA) DutyCycleValues);
#endif

#if (ICU_GET_VERSION_INFO_API == STD_ON)
extern FUNC(void, ICU_PUBLIC_CODE)Icu_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, ICU_APPL_DATA) versioninfo);
#endif

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define ICU_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Declaration for ICU Database */
extern CONST(Icu_ConfigType, ICU_CONST) Icu_GstConfiguration[];

#define ICU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* ICU_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
