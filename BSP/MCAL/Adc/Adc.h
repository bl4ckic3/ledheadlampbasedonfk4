/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Adc.h                                                       */
/* Version      = 3.1.3                                                       */
/* Date         = 04-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, ADC type definitions, structure data types and  */
/* API function prototypes of ADC Driver                                      */
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
 * V3.0.0:  10-Jul-2009  : Initial version
 *
 * V3.0.1:  12-Oct-2009  : As per SCR 052, the following changes are made
 *                         1. Template changes are made.
 *
 * V3.0.2:  02-Dec-2009  : As per SCR 157, Adc_ConfigType is updated to add
 *                         pDmaHWUnitMapping and pDmaCGUnitMapping.
 *
 * V3.0.3:  27-Aug-2010  : As per SCR 338, file include section is updated to
 *                         include Std_Types.h file.
 *
 * V3.1.0:  27-Jul-2011  : Modified for DK-4
 * V3.1.1:  14-Feb-2012  : Merged the fixes done for Fx4L Adc driver
 * V3.1.2:  16-May-2012  : As per SCR 006, Module version is changed.
 *
 * V3.1.3:  04-Jun-2012  : As per SCR 019, the following changes are made
 *                         1. Compiler version is removed from environment 
 *                            section.
 *                         2. Module version is changed.
 *                         3. Function Adc_GetVersionInfo is implemented as 
 *                            Macro.
 */
/******************************************************************************/

#ifndef ADC_H
#define ADC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Adc_Cfg.h"
#include "Std_Types.h" /* AUTOSAR standard types */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

#define ADC_VENDOR_ID         ADC_VENDOR_ID_VALUE
#define ADC_MODULE_ID         ADC_MODULE_ID_VALUE
#define ADC_INSTANCE_ID       ADC_INSTANCE_ID_VALUE

/*
 * AUTOSAR specification version information
 */
#define ADC_AR_MAJOR_VERSION  ADC_AR_MAJOR_VERSION_VALUE
#define ADC_AR_MINOR_VERSION  ADC_AR_MINOR_VERSION_VALUE
#define ADC_AR_PATCH_VERSION  ADC_AR_PATCH_VERSION_VALUE

/*
 * Software version information
 */
#define ADC_SW_MAJOR_VERSION  3
#define ADC_SW_MINOR_VERSION  1
#define ADC_SW_PATCH_VERSION  3

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (ADC_CFG_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION)
#error "Software major version of Adc.h and Adc_Cfg.h did not match!"
#endif
#if (ADC_CFG_SW_MINOR_VERSION!= ADC_SW_MINOR_VERSION )
#error "Software minor version of Adc.h and Adc_Cfg.h did not match!"
#endif

/*******************************************************************************
**                     Service Ids                                            **
*******************************************************************************/

/* Service Id of Adc_Init */
#define ADC_INIT_SID                        (uint8)0x00
/* Service Id of Adc_DeInit */
#define ADC_DEINIT_SID                      (uint8)0x01
/* Service Id of Adc_StartGroupConversion */
#define ADC_START_GROUP_CONVERSION_SID      (uint8)0x02
/* Service Id of Adc_StopGroupConversion */
#define ADC_STOP_GROUP_CONVERSION_SID       (uint8)0x03
/* Service Id of Adc_ReadGroup */
#define ADC_READ_GROUP_SID                  (uint8)0x04
/* Service Id of Adc_EnableHardwareTrigger */
#define ADC_ENABLE_HARWARE_TRIGGER_SID      (uint8)0x05
/* Service Id of Adc_DisableHardwareTrigger */
#define ADC_DISABLE_HARWARE_TRIGGER_SID     (uint8)0x06
/* Service Id of Adc_EnableGroupNotification */
#define ADC_ENABLE_GROUP_NOTIFICATION_SID   (uint8)0x07
/* Service Id of Adc_DisableGroupNotification */
#define ADC_DISABLE_GROUP_NOTIFICATION_SID  (uint8)0x08
/* Service Id of Adc_GetGroupStatus */
#define ADC_GET_GROUP_STATUS_SID            (uint8)0x09
/* Service Id of Adc_GetVersionInfo */
#define ADC_GET_VERSION_INFO_SID            (uint8)0x0A
/* Service Id of Adc_GetStreamLastPointer */
#define ADC_GET_STREAM_LAST_POINTER_SID     (uint8)0x0B
/* Service Id of Adc_SetupResultBuffer */
#define ADC_SETUP_RESULT_BUFFER_SID         (uint8)0x0C

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* API service called without module initialization is reported using following
error code */
#define ADC_E_UNINIT                            0x0A

/* API services Adc_StartGroupConversion and Adc_DeInit called when the timer
is already running is reported using following error code */
#define ADC_E_BUSY                              0x0B

/* API service Adc_StopGroupConversion called while no conversion was running
is reported using following error code */
#define ADC_E_IDLE                              0x0C

/* API service Adc_Init called while ADC is already initialized
is reported using following error code */
#define ADC_E_ALREADY_INITIALIZED               0x0D

/* API service Adc_Init called with incorrect configuration
is reported using following error code */
#define ADC_E_PARAM_CONFIG                      0x0E

/* API service called with invalid Group ID is reported using following error
code */
#define ADC_E_PARAM_GROUP                       0x15

/* API services Adc_StartGroupConversion or Adc_StopGroupConversion called on a
 group with trigger source configured as hardware is reported using following
 error code */
/* API services Adc_EnableHardwareTrigger or Adc_DisableHardwareTrigger called
on a group with trigger source configured as software is reported using
following error code */
#define ADC_E_WRONG_TRIGG_SRC                   0x17

/* API services Adc_EnableGroupNotification or Adc_DisableGroupNotification
called on a group whose configuration set has no notification available is
reported using following error code */
#define ADC_E_NOTIF_CAPABILITY                  0x18

/* API services Adc_StartGroupConversion or Adc_EnableHardwareTrigger
called on a group whose result buffer pointer not initialized is
reported using following error code */
#define ADC_E_BUFFER_UNINIT                     0x19

/* API service Adc_Init called without/with a wrong database is reported using
following error code */
#define ADC_E_INVALID_DATABASE                  0xEF

/* API service Adc_GetVersionInfo called with parameter versioninfo pointer as
NULL is reported using following error code */
#define ADC_E_PARAM_POINTER                     0xF0

/* Priority Implementation values  */
#define ADC_PRIORITY_NONE                       0
#define ADC_PRIORITY_HW                         1
#define ADC_PRIORITY_HW_SW                      2
#define ADC_PRIORITY_SW                         3

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Numeric identifier of an ADC channel */
typedef uint8 Adc_ChannelType;

/* Numeric identifier of channel resolution in number of bits */
typedef uint8 Adc_ResolutionType;

/* Numeric identifier of an ADC channel group */
typedef uint8 Adc_GroupType;

/* Adc converted value type */
typedef uint16 Adc_ValueGroupType;

/* Number of samples of the streaming buffer group */
typedef uint8 Adc_StreamNumSampleType;

/* Numeric ID of an ADC Hw Unit */
typedef uint8 Adc_HwUnitType;

/* Type for the reload value of the ADC module embedded timer */
typedef uint8 Adc_HwTriggerTimerType;

/* Current status of the conversion of the requested ADC Channel group */
typedef enum Adc_StatusType
{
  ADC_IDLE,
  ADC_BUSY,
  ADC_COMPLETED,
  ADC_STREAM_COMPLETED
} Adc_StatusType;

/* Type for configuring the trigger source for an ADC Channel group */
typedef enum Adc_TriggerSourceType
{
  ADC_TRIGG_SRC_SW,
  ADC_TRIGG_SRC_HW
} Adc_TriggerSourceType;

/* Type for configuring the conversion mode of an ADC Channel group */
typedef enum Adc_GroupConvModeType
{
  ADC_CONV_MODE_ONESHOT,
  ADC_CONV_MODE_CONTINUOUS
} Adc_GroupConvModeType;

/* Type for configuring the streaming access mode buffer type. */
typedef enum Adc_StreamBufferModeType
{
  ADC_STREAM_BUFFER_LINEAR,
  ADC_STREAM_BUFFER_CIRCULAR
} Adc_StreamBufferModeType;

/* Type for configuring the access mode to group conversion results */
typedef enum Adc_GroupAccessModeType
{
  ADC_ACCESS_MODE_SINGLE,
  ADC_ACCESS_MODE_STREAMING
} Adc_GroupAccessModeType;

/* Type for replacement mechanism, which is used on ADC group level */
typedef enum Adc_GroupReplacementType
{
  ADC_GROUP_REPL_ABORT_RESTART,
  ADC_GROUP_REPL_SUSPEND_RESUME
} Adc_GroupReplacementType;

/* Type for configuring on which edge of the hardware trigger signal the
 * driver should reach, i.e. start the conversion
 */
typedef enum Adc_HwTriggerSignalType
{
  ADC_HW_TRIG_RISING_EDGE,
  ADC_HW_TRIG_FALLING_EDGE,
  ADC_HW_TRIG_BOTH_EDGES
} Adc_HwTriggerSignalType;

/* Type for configuring the result data alignment */
typedef enum AdcResultAlignment
{
  ADC_RIGHT_ALIGNMENT,
  ADC_LEFT_ALIGNMENT
} AdcResultAlignment;

/* Priority level of the channel. Lowest priority is 0 */
typedef uint8 Adc_GroupPriorityType;

/* Data Structure required for initializing the ADC unit */
typedef struct STagTdd_Adc_ConfigType
{
  /* Database start value - ADC_DBTOC_VALUE */
  uint32 ulStartOfDbToc;
  /* Pointer to ADC hardware unit configuration */
  P2CONST(void, AUTOMATIC, ADC_CONFIG_CONST) pHWUnitConfig;
  /* Pointer to ADC group configuration */
  P2CONST(void, AUTOMATIC, ADC_CONFIG_CONST) pGroupConfig;
  #if (ADC_HW_TRIGGER_API == STD_ON)
  /* Pointer to ADC HW trigger values */
  P2CONST(void, AUTOMATIC, ADC_CONFIG_CONST) pGroupHWTrigg;
  #endif
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* Pointer to DMA  data */
  P2CONST(void,AUTOMATIC,ADC_CONFIG_DATA) pDmaUnitConfig;
  /* Pointer to DMA HW unit array mapping */
  P2CONST(void,AUTOMATIC,ADC_CONFIG_DATA) pDmaHWUnitMapping;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* Pointer to DMA CGm unit array mapping */
  P2CONST(void,AUTOMATIC,ADC_CONFIG_DATA) pDmaCGUnitMapping;
  #endif
  #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */
  /* Pointer to channel group ram data */
  P2VAR(void,AUTOMATIC,ADC_CONFIG_DATA) pGroupRamData;
  /* Pointer to Hardware Unit ram data */
  P2VAR(void,AUTOMATIC,ADC_CONFIG_DATA) pHwUnitRamData;
  /* Pointer to Runtime data */
  P2VAR(void,AUTOMATIC,ADC_CONFIG_DATA) pRunTimeData;
  /* Max number of SW triggered groups configured in corresponding
     configuration */
  uint8 ucMaxSwTriggGroups;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* Max number of DMA channel Ids configured in corresponding
     configuration */
  uint8 ucMaxDmaChannels;
  #endif
} Adc_ConfigType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"

extern FUNC(void, ADC_PUBLIC_CODE) Adc_Init
(P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) ConfigPtr);

extern FUNC(void, ADC_PUBLIC_CODE) Adc_DeInit(void);

extern FUNC(void, ADC_PUBLIC_CODE)
Adc_StartGroupConversion(Adc_GroupType Group);

extern FUNC(void, ADC_PUBLIC_CODE)
Adc_StopGroupConversion(Adc_GroupType Group);

extern FUNC(Std_ReturnType, ADC_PUBLIC_CODE)
Adc_ReadGroup (Adc_GroupType Group,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) DataBufferPtr);

extern FUNC(void, ADC_PUBLIC_CODE)
Adc_EnableHardwareTrigger(Adc_GroupType Group);

extern FUNC(void, ADC_PUBLIC_CODE)
Adc_DisableHardwareTrigger(Adc_GroupType Group);

extern FUNC(void, ADC_PUBLIC_CODE)
Adc_EnableGroupNotification(Adc_GroupType Group);

extern FUNC(void, ADC_PUBLIC_CODE)
Adc_DisableGroupNotification(Adc_GroupType Group);

extern FUNC(Adc_StatusType, ADC_PUBLIC_CODE)
Adc_GetGroupStatus(Adc_GroupType Group);

extern FUNC(Adc_StreamNumSampleType, ADC_PUBLIC_CODE) Adc_GetStreamLastPointer
(Adc_GroupType Group, P2VAR(P2VAR(Adc_ValueGroupType,
AUTOMATIC, ADC_CONFIG_DATA), AUTOMATIC,ADC_CONFIG_DATA) PtrToSamplePtr);

#if (ADC_VERSION_INFO_API == STD_ON)

#define Adc_GetVersionInfo(versioninfo)\
 { \
   (versioninfo)->vendorID = (uint16)ADC_VENDOR_ID; \
   (versioninfo)->moduleID = (uint16)ADC_MODULE_ID; \
   (versioninfo)->instanceID = (uint8)ADC_INSTANCE_ID; \
   (versioninfo)->sw_major_version = ADC_SW_MAJOR_VERSION; \
   (versioninfo)->sw_minor_version = ADC_SW_MINOR_VERSION; \
   (versioninfo)->sw_patch_version = ADC_SW_PATCH_VERSION; \
 }
#endif /*(ADC_VERSION_INFO_API == STD_ON)*/

extern FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_SetupResultBuffer
(Adc_GroupType Group,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) DataBufferPtr);

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define ADC_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Declaration for ADC Database */
extern CONST(Adc_ConfigType, ADC_CONST) Adc_GstConfiguration[];

#define ADC_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* ADC_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
