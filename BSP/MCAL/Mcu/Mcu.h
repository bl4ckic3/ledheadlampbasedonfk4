/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Mcu.h                                                       */
/* Version      = 3.0.4                                                       */
/* Date         = 15-Mar-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2010-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, MCU type definitions, structure data types and  */
/* API function prototypes of MCU Driver                                      */
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
/*              Devices:        Fx4                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0: 02-Jul-2010 : Initial Version
 *
 * V3.0.1: 28-Jul-2010 : As per SCR 320 following change is made:
 *                       ucVCPC0CTLreg0, ucVCPC0CTLreg1 elements are added in
 *                       Mcu_ConfigType structure.
 * V3.0.2: 17-Jun-2011 : As per SCR 468 following change is made:
 *                       pre compile options added for ucVCPC0CTLreg0 and
 *                       ucVCPC0CTLreg1 elements in Mcu_ConfigType structure and
 *                       data type for element ulLVIindicationReg corrected.
 * V3.0.2a: 18-Oct-2011  : Copyright is updated.
 *
 * V3.0.3:  06-Jun-2012  : As per SCR 031, API Mcu_GetVersionInfo is implemented
 *                         as Macro.
 * V3.0.4: 15-Mar-2013  : As per SCR 091, The following changes have been made,
 *                        1. Alignment is changed as per code guidelines.
 *                        2. Service id is corrected for API
 *                           Mcu_MaskClear_WakeUpFactor.
 *                        3. 'MCU_E_PARAM_POINTER' macro is removed.
 */
/******************************************************************************/

#ifndef MCU_H
#define MCU_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcu_Cfg.h"   /* MCU Driver Configuration Header */

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define MCU_AR_MAJOR_VERSION       MCU_AR_MAJOR_VERSION_VALUE
#define MCU_AR_MINOR_VERSION       MCU_AR_MINOR_VERSION_VALUE
#define MCU_AR_PATCH_VERSION       MCU_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define MCU_SW_MAJOR_VERSION       MCU_SW_MAJOR_VERSION_VALUE
#define MCU_SW_MINOR_VERSION       MCU_SW_MINOR_VERSION_VALUE
#define MCU_SW_PATCH_VERSION       MCU_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Vendor and Module IDs */
#define MCU_VENDOR_ID                       MCU_VENDOR_ID_VALUE
#define MCU_MODULE_ID                       MCU_MODULE_ID_VALUE
#define MCU_INSTANCE_ID                     MCU_INSTANCE_ID_VALUE

/* Service IDs */
/* Service Id of Mcu_Init API */
#define MCU_INIT_SID                        (uint8)0x00
/* Service Id of Mcu_InitRamSection API */
#define MCU_INITRAMSECTION_SID              (uint8)0x01
/* Service Id of Mcu_InitClock API */
#define MCU_INITCLOCK_SID                   (uint8)0x02
/* Service Id of Mcu_DistributePllClock API */
#define MCU_DISTRIBUTEPLLCLOCK_SID          (uint8)0x03
/* Service Id of Mcu_GetPllStatus API */
#define MCU_GETPLLSTATUS_SID                (uint8)0x04
/* Service Id of Mcu_GetResetReason API */
#define MCU_GETRESETREASON_SID              (uint8)0x05
/* Service Id of Mcu_GetResetRawValue API */
#define MCU_GETRESETRAWVAULE_SID            (uint8)0x06
/* Service Id of Mcu_PerformReset API */
#define MCU_PERFORMRESET_SID                (uint8)0x07
/* Service Id of Mcu_SetMode API */
#define MCU_SETMODE_SID                     (uint8)0x08
/* Service Id of Mcu_GetVersionInfo API */
#define MCU_GETVERSIONINFO_SID              (uint8)0x09
/* Service Id of Mcu_MaskClear_WakeUpFactor API */
#define MCU_MASKCLEAR_WAKEUPFACTOR_SID      (uint8)0x0A

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* DET Code to report NULL pointer passed to Mcu_Init API */
#define MCU_E_PARAM_CONFIG            (uint8)0x0A

/* DET Code for invalid Clock Setting */
#define MCU_E_PARAM_CLOCK             (uint8)0x0B

/* DET Code for invalid Operation Mode */
#define MCU_E_PARAM_MODE              (uint8)0x0C

/* DET Code for invalid RAM Section handle */
#define MCU_E_PARAM_RAMSECTION        (uint8)0x0D

/* DET Code to report that PLL Clock is not locked */
#define MCU_E_PLL_NOT_LOCKED          (uint8)0x0E

/* DET code to report uninitialized state */
#define MCU_E_UNINIT                  (uint8)0x0F

/* DET code to report invalid database */
#define MCU_E_INVALID_DATABASE        (uint8)0xED

/* DET code to report invalid power mode */
#define MCU_E_INVALID_MODE            (uint8)0xEF

/* DET code to report invalid clock setting */
#define MCU_E_INVALID_CLK_SETTING     (uint8)0xF0

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Type definition for Mcu_ClockType used by the API Mcu_InitClock */
typedef uint8 Mcu_ClockType;

/* Type definition for Mcu_RawResetType used by the API Mcu_GetResetRawValue */
typedef uint32 Mcu_RawResetType;

/* Type definition for Mcu_ModeType used by the API Mcu_SetMode */
typedef uint8 Mcu_ModeType;

/* Type definition for Mcu_RamSectionType used by the API Mcu_InitRamSection */
typedef uint8 Mcu_RamSectionType;

/* Structure for MCU Init Configuration */
typedef struct STagMcu_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;
  /* Count for stabilization at Ring Oscillator clock */
  uint32 ulHighRingStabCount;
  /* Count for stabilization at Main clock */
  uint32 ulMainClockStabCount;
  /* Element to handle the detection level of voltage */
  uint32 ulLVIindicationReg;
  /* Address for Clock setting Index Mapping array */
  P2CONST(uint8, AUTOMATIC, MCU_CONFIG_CONST) pClkSettingIndexMap;
  /* Pointer to MCU Clock Setting configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pClockSetting;
  /* Pointer to MCU Operating Mode configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pModeSetting;
  /* Pointer to CKSC register offset */
  P2CONST(uint16, AUTOMATIC, MCU_CONFIG_CONST) pCkscRegOffset;
  /* Pointer to CKSC register value */
  P2CONST(uint32, AUTOMATIC, MCU_CONFIG_CONST) pCkscRegValue;
  #if(MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  /* Pointer to array of port registers */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pPortGroupSetting;
  /* Pointer to array of RAM area */
  P2VAR(uint32, AUTOMATIC, MCU_CONFIG_CONST) pPortRamArea;
  #endif /* #if(MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */
  /* Element containing value of CLMA0CMPL register */
  uint16 usCLMA0CMPL;
  /* Element containing value of CLMA0CMPH register */
  uint16 usCLMA0CMPH;
  /* Element containing value of CLMA3CMPL register */
  uint16 usCLMA3CMPL;
  /* Element containing value of CLMA3CMPH register */
  uint16 usCLMA3CMPH;
  #if(MCU_VCPC0CTL0_ENABLE == STD_ON)
  /* Element containing value of VCPC0CTL0 register for channnel 0 */
  uint8 ucVCPC0CTLreg0;
  #endif /* #if(MCU_VCPC0CTL0_ENABLE == STD_ON) */
  #if(MCU_VCPC0CTL1_ENABLE == STD_ON)
  /* Element containing value of VCPC0CTL1 register for channnel 1 */
  uint8 ucVCPC0CTLreg1;
  #endif /* #if(MCU_VCPC0CTL1_ENABLE == STD_ON) */
  #if(MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  /* Element which contains total number of ports configured */
  uint8 ucNumOfPortGroup;
  #endif
  /* Element to enable or disable the operation of clock monitor function */
  uint8 ucCLMEnable;
  /* Element to select the output signal */
  uint8 ucCLMOutputSignal;
  /* Clock Failure Notification Enable or Disable */
  boolean blClockFailureNotify;
} Mcu_ConfigType;

/* Status value returned by the API Mcu_GetPllStatus */
typedef enum
{
  MCU_PLL_LOCKED = 0,
  MCU_PLL_UNLOCKED,
  MCU_PLL_STATUS_UNDEFINED
} Mcu_PllStatusType;

/* Type of reset supported by the hardware */
typedef enum
{
  MCU_POWER_ON_RESET = 0,
  MCU_SW_RESET,
  MCU_WATCHDOG0_RESET,
  MCU_WATCHDOG1_RESET,
  MCU_CLM0_RESET,
  MCU_CLM1_RESET,
  MCU_CLM2_RESET,
  MCU_CLM3_RESET,
  MCU_LVI_RESET,
  MCU_TERMINAL_RESET,
  MCU_AWO_ISO0_ISO1_WAKEUP,
  MCU_AWO_ISO0_WAKEUP,
  MCU_ISO1_WAKEUP,
  MCU_RESET_UNDEFINED,
  MCU_RESET_UNKNOWN
} Mcu_ResetType;

/* Handles for clock setting */

/* Clock setting for High Speed Ring Oscillator */
#define MCU_CLK_SETTING_RINGOSC                     (Mcu_ClockType)0x00
/* Clock setting for Main Oscillator */
#define MCU_CLK_SETTING_MAINOSC                     (Mcu_ClockType)0x01
/* Clock setting for PLL0 */
#define MCU_CLK_SETTING_PLL0                        (Mcu_ClockType)0x02

/* Handles for Mode setting */

/* Mode setting:  RUN_MODE */
#define MCU_RUN_MODE                                (Mcu_ModeType)0x00
/* Mode setting:  RUN_MODE_ISO1_STOP */
#define MCU_RUN_MODE_ISO1_STOP                      (Mcu_ModeType)0x01
/* Mode setting:  STOP_MODE */
#define MCU_STOP_MODE                               (Mcu_ModeType)0x02
/* Mode setting:  RUN_MODE_ISO1_DEEPSTOP */
#define MCU_RUN_MODE_ISO1_DEEPSTOP                  (Mcu_ModeType)0x03
/* Mode setting:  STOP_MODE_ISO1_DEEPSTOP */
#define MCU_STOP_MODE_ISO1_DEEPSTOP                 (Mcu_ModeType)0x04
/* Mode Setting:  DEEPSTOP_MODE */
#define MCU_DEEPSTOP_MODE                           (Mcu_ModeType)0x05
/* Mode setting: HALT */
#define MCU_HALT_MODE                               (Mcu_ModeType)0x06
/* Mode Setting:  STOP_MODE_ISO1_ON */
#define MCU_STOP_MODE_ISO1_ON                       (Mcu_ModeType)0x07


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_Init
(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr);

extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitRamSection
(Mcu_RamSectionType RamSection);

extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitClock
(Mcu_ClockType ClockSetting);

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_DistributePllClock (void);

extern FUNC(Mcu_PllStatusType, MCU_PUBLIC_CODE) Mcu_GetPllStatus (void);

extern FUNC(Mcu_ResetType, MCU_PUBLIC_CODE) Mcu_GetResetReason (void);

extern FUNC(Mcu_RawResetType, MCU_PUBLIC_CODE) Mcu_GetResetRawValue (void);

#if (MCU_PERFORM_RESET_API == STD_ON)
extern FUNC(void, MCU_PUBLIC_CODE) Mcu_PerformReset (void);
#endif

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_SetMode (Mcu_ModeType McuMode);

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_MaskClear_WakeUpFactor \
                                                         (Mcu_ModeType McuMode);
#if (MCU_VERSION_INFO_API == STD_ON)
#define Mcu_GetVersionInfo(versioninfo)\
 { \
   (versioninfo)->vendorID = (uint16)MCU_VENDOR_ID; \
   (versioninfo)->moduleID = (uint16)MCU_MODULE_ID; \
   (versioninfo)->instanceID = (uint8)MCU_INSTANCE_ID; \
   (versioninfo)->sw_major_version = MCU_SW_MAJOR_VERSION; \
   (versioninfo)->sw_minor_version = MCU_SW_MINOR_VERSION; \
   (versioninfo)->sw_patch_version = MCU_SW_PATCH_VERSION; \
 }
#endif /* (MCU_VERSION_INFO_API == STD_ON) */

#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define MCU_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for MCU Init configuration */
extern CONST(Mcu_ConfigType, MCU_CONST) Mcu_GstConfiguration[];

#define MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* MCU_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
