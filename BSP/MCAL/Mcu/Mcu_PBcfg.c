/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Mcu_PBcfg.c                                                 */
/* Version      = 3.1.7a                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSAR MCU post build parameters.                            */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  3.1.13
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    FK4_4010_MCU_V308_140113_HEADLAMP.arxml
 * GENERATED ON:  14 Jan 2014 - 12:18:18
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Mcu_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define MCU_PBCFG_C_AR_MAJOR_VERSION  2
#define MCU_PBCFG_C_AR_MINOR_VERSION  2
#define MCU_PBCFG_C_AR_PATCH_VERSION  1

/* File version information */
#define MCU_PBCFG_C_SW_MAJOR_VERSION  3
#define MCU_PBCFG_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (MCU_PBTYPES_AR_MAJOR_VERSION != MCU_PBCFG_C_AR_MAJOR_VERSION)
  #error "Mcu_PBcfg.c : Mismatch in Specification Major Version"
#endif

#if (MCU_PBTYPES_AR_MINOR_VERSION != MCU_PBCFG_C_AR_MINOR_VERSION)
  #error "Mcu_PBcfg.c : Mismatch in Specification Minor Version"
#endif

#if (MCU_PBTYPES_AR_PATCH_VERSION != MCU_PBCFG_C_AR_PATCH_VERSION)
  #error "Mcu_PBcfg.c : Mismatch in Specification Patch Version"
#endif

#if (MCU_SW_MAJOR_VERSION != MCU_PBCFG_C_SW_MAJOR_VERSION)
  #error "Mcu_PBcfg.c : Mismatch in Major Version"
#endif

#if (MCU_SW_MINOR_VERSION != MCU_PBCFG_C_SW_MINOR_VERSION)
  #error "Mcu_PBcfg.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define MCU_START_SEC_BURAM_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global RAM array for back up of Port group registers */
/* VAR(uint32, MCU_CONFIG_DATA) Mcu_GaaRamPortGroup[]; */
/* Pointer to array of early wakeup factors in BURAM */
/*VAR(uint32, MCU_CONFIG_DATA)  Mcu_GaaRamIso0EarlyWUF[3];*/
/* Pointer to early wakeup factor status flag in BURAM */
/*VAR(uint8, MCU_CONFIG_DATA)  Mcu_EarlyWakeupStatus;*/

#define MCU_STOP_SEC_BURAM_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define MCU_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for MCU Init configuration */
CONST(Mcu_ConfigType, MCU_CONST) Mcu_GstConfiguration[1] =
{
  /* Structure for initialization of database: 0 */
  {
    /* ulStartOfDbToc */
    0x05D94300,

    /* ulHighRingStabCount */
    0x00044444,

    /* ulMainClockStabCount */
    0x000020C4,

    /* ulLVIindicatingReg */
    0x00000000,

    /* pClkSettingIndexMap */
    &Mcu_GaaClkSettingIndexMap[0],

    /* pClockSetting */
    &Mcu_GstClockSetting[0],

    /* pModeSetting */
    &Mcu_GstModeSetting[0],

    /* pCkscRegOffset */
    &Mcu_GaaCkscRegOffset[0],

    /* pCkscRegValue */
    &Mcu_GaaCkscRegValue[0],

    /* usCLMA0CMPL */
    0x01D5,

    /* usCLMA0CMPH */
    0x0261,

    /* usCLMA3CMPL */
    0x008D,

    /* usCLMA3CMPH */
    0x00B7,

    /* ucVCPC0CTLreg0 */
    0x00,

    /* ucVCPC0CTLreg1 */
    0x00,

    /* ucCLMEnable */
    0x00,

    /* ucCLMOutputSignal */
    0x00,

    /* blClockFailureNotify */
    MCU_FALSE
  }
};


#define MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Structure for MCU clock setting configuration */
CONST(Tdd_Mcu_ClockSetting, MCU_CONST) Mcu_GstClockSetting[1] =
{
  /* Index: 0 */
  {
    /* ulPLL0ControlValue */
    0x00840213,

    /* ulPLL1ControlValue */
    0x00000000,

    /* ulPLL2ControlValue */
    0x00000000,

    /* ulSubOscStabTime */
    0x00000000,

    /* ulPLL0StabTime */
    0x00000006,

    /* ulPLL1StabTime */
    0x00000000,

    /* ulPLL2StabTime */
    0x00000000,

    /* ulMainOscStabTime */
    0x0000000D,

    /* usFoutDivReg */
    0x0000,

    /* ucSelectedSrcClock */
    0x0D,

    /* ucMosccRegValue */
    0x02,

    /* ucSelectedSTPMK */
    0x0D,

    /* ucNoOfIso0CkscReg */
    0x02,

    /* ucNoOfIso1CkscReg */
    0x03,

    /* ucNoOfAwoCkscReg */
    0x00,

    /* ucNoOfPllIso0CkscReg */
    0x01,

    /* ucNoOfPllIso1CkscReg */
    0x00,

    /* ucNoOfPllAwoCkscReg */
    0x00,

    /* ucCkscIndexOffset */
    0x00,

    /* ucCkscPllIndexOffset */
    0x05
  }
};


/* Structure for MCU mode setting configuration */
CONST(Tdd_Mcu_ModeSetting, MCU_CONST) Mcu_GstModeSetting[1] =
{
  /* Index: 0 */
  {
    /* ulPowerDownWakeupTypeL0 */
    0xFFFFFFFF,

    /* ulPowerDownWakeupTypeM0 */
    0xFFFFFFFF,

    /* ulPowerDownWakeupTypeH0 */
    0xFFFFFFFF,

    /* ulPowerDownWakeupTypeL1 */
    0xFFFFFFFF,

    /* ulPowerDownWakeupTypeM1 */
    0xFFFFFFFF,

    /* ulPowerDownWakeupTypeH1 */
    0xFFFFFFFF,

    /* ulOscWufMsk */
    0x00000003,

    /* ucPSC0RegValue */
    0x0D,

    /* ucPSC1RegValue */
    0x0D,

    /* ucModeType */
    MCU_RUN_MODE
  }
};


/* Array for CKSC register offset */
CONST(uint16, MCU_CONST)Mcu_GaaCkscRegOffset[6] =
{
  /* Index: 0 */
  0x00C0,

  /* Index: 1 */
  0x0060,

  /* Index: 2 */
  0x40B0,

  /* Index: 3 */
  0x40C0,

  /* Index: 4 */
  0x4060,

  /* Index: 5 */
  0x0000
};


/* Array for CKSC register value */
CONST(uint32, MCU_CONST)Mcu_GaaCkscRegValue[6] =
{
  /* Index: 0 */
  0x00000018,

  /* Index: 1 */
  0x00000018,

  /* Index: 2 */
  0x00000018,

  /* Index: 3 */
  0x00000018,

  /* Index: 4 */
  0x00000018,

  /* Index: 5 */
  0x00000028
};


/* Clock setting index mapping array */
/* Clock setting indices are organized in following order for each configured
   configuration set:

   Configuration Set         -> [1, 2, 3, 4....]

   MCU_CLK_SETTING_8MHZ      -> [0, 3, 6, 9....]
   MCU_CLK_SETTING_MAIN_OSCI -> [1, 4, 7, 10....]
   MCU_CLK_SETTING_PLL0      -> [2, 5, 8, 11....]
*/
CONST(uint8, MCU_CONST)Mcu_GaaClkSettingIndexMap[3] =
{
  /* Index: 0 */
  0xFF,

  /* Index: 1 */
  0xFF,

  /* Index: 2 */
  0x00
};



/* Array of Port Group Configuration */
/* CONST(Tdd_Mcu_PortGroupAddress, MCU_CONST) Mcu_GaaPortGroup[0]; */

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/

