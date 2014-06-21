/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Pwm_PBcfg.c                                                 */
/* Version      = 3.1.2                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains post-build time parameters.                             */
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
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    3.1.5
 */ 
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    FK4_4010_PWM_V308_140113_HEADLAMP.arxml
 * GENERATED ON:   8 Apr 2014 - 18:39:24
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Pwm_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PWM_PBCFG_C_AR_MAJOR_VERSION  2
#define PWM_PBCFG_C_AR_MINOR_VERSION  2
#define PWM_PBCFG_C_AR_PATCH_VERSION  0

/* File version information */
#define PWM_PBCFG_C_SW_MAJOR_VERSION   3
#define PWM_PBCFG_C_SW_MINOR_VERSION   1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PWM_PBTYPES_AR_MAJOR_VERSION != PWM_PBCFG_C_AR_MAJOR_VERSION)
  #error "Pwm_PBcfg.c : Mismatch in Specification Major Version"
#endif

#if (PWM_PBTYPES_AR_MINOR_VERSION != PWM_PBCFG_C_AR_MINOR_VERSION)
  #error "Pwm_PBcfg.c : Mismatch in Specification Minor Version"
#endif

#if (PWM_PBTYPES_AR_PATCH_VERSION != PWM_PBCFG_C_AR_PATCH_VERSION)
  #error "Pwm_PBcfg.c : Mismatch in Specification Patch Version"
#endif

#if (PWM_SW_MAJOR_VERSION != PWM_PBCFG_C_SW_MAJOR_VERSION)
  #error "Pwm_PBcfg.c : Mismatch in Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_PBCFG_C_SW_MINOR_VERSION)
  #error "Pwm_PBcfg.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define PWM_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Pwm Channel Configuration */
CONST(Pwm_ConfigType, PWM_CONST) Pwm_GstConfiguration[] =
{
  /*  0 - 1 */
  {
    /* ulStartOfDbToc */
    0x05DE4308,

    /* pTAUABCUnitConfig */
    &Pwm_GstTAUABCUnitConfig[0],

    /* pChannelConfig */
    &Pwm_GstChannelConfig[0],

    /* pChannelTimerMap */
    &Pwm_GaaTimerChIdx[0],

    /* pChannelIdleStatus */
    &Pwm_GaaChannelIdleStatus[0]
  }
};


#define PWM_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


/* Structure for each TAUA Unit Configuration set */
CONST(Tdd_Pwm_TAUABCUnitConfigType,PWM_CONST) Pwm_GstTAUABCUnitConfig[] =
{
  /* TAUA, B or C Index: 0 */
  {
    /* pTAUABCUnitUserCntlRegs */
    (P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF808040ul,

    /* pTAUABCUnitOsCntlRegs */
    (P2VAR(Tdd_Pwm_TAUABCUnitOsRegs, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF808240ul,

    /* usTAUChannelMask */
    0x0055,

    /* usTOMMask */
    0x0054,

    /* usTOCMask */
    0x0000,

    /* usTOLMask */
    0x0054,

    /* usTOMask */
    0x0000,

    /* usTOEMask */
    0x0054,

    /* usPrescaler */
    0xFFF3,

    /* ucBaudRate */
    0xFF,

    /* blConfigurePrescaler */
    PWM_TRUE,

    /* uiPwmTAUType */
    PWM_HW_TAUA
  },

  /* TAUA, B or C Index: 1 */
  {
    /* pTAUABCUnitUserCntlRegs */
    (P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809040ul,

    /* pTAUABCUnitOsCntlRegs */
    (P2VAR(Tdd_Pwm_TAUABCUnitOsRegs, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809240ul,

    /* usTAUChannelMask */
    0xF5FF,

    /* usTOMMask */
    0xA4AA,

    /* usTOCMask */
    0x0000,

    /* usTOLMask */
    0xF1FE,

    /* usTOMask */
    0x0000,

    /* usTOEMask */
    0xA4AA,

    /* usPrescaler */
    0xFFF3,

    /* ucBaudRate */
    0x00,

    /* blConfigurePrescaler */
    PWM_TRUE,

    /* uiPwmTAUType */
    PWM_HW_TAUB
  },

  /* TAUA, B or C Index: 2 */
  {
    /* pTAUABCUnitUserCntlRegs */
    (P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A040ul,

    /* pTAUABCUnitOsCntlRegs */
    (P2VAR(Tdd_Pwm_TAUABCUnitOsRegs, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A240ul,

    /* usTAUChannelMask */
    0x0FFF,

    /* usTOMMask */
    0x0AAA,

    /* usTOCMask */
    0x0000,

    /* usTOLMask */
    0x0FFE,

    /* usTOMask */
    0x0000,

    /* usTOEMask */
    0x0AAA,

    /* usPrescaler */
    0xFFF0,

    /* ucBaudRate */
    0x00,

    /* blConfigurePrescaler */
    PWM_TRUE,

    /* uiPwmTAUType */
    PWM_HW_TAUC
  },

  /* TAUA, B or C Index: 3 */
  {
    /* pTAUABCUnitUserCntlRegs */
    (P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80B040ul,

    /* pTAUABCUnitOsCntlRegs */
    (P2VAR(Tdd_Pwm_TAUABCUnitOsRegs, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80B240ul,

    /* usTAUChannelMask */
    0x000F,

    /* usTOMMask */
    0x000E,

    /* usTOCMask */
    0x0000,

    /* usTOLMask */
    0x000E,

    /* usTOMask */
    0x0000,

    /* usTOEMask */
    0x000E,

    /* usPrescaler */
    0xFFF0,

    /* ucBaudRate */
    0x00,

    /* blConfigurePrescaler */
    PWM_TRUE,

    /* uiPwmTAUType */
    PWM_HW_TAUC
  }
};


/* Structure for each TAUJ Unit Configuration set */
/* CONST(Tdd_Pwm_TAUJUnitConfigType,PWM_CONST) Pwm_GstTAUJUnitConfig[]; */
/* Structure for TAUA or TAUB or TAUC Configuration set */
CONST(Tdd_Pwm_TAUABCProperties,PWM_CONST) Pwm_GstTAUABCChannelConfig[] =
{
  /* TAUA or TAUB or TAUC Channel Index: 0 */
  {
    /* usDefaultPeriod */
    0x0D05,

    /* usChannelMask */
    0x0055
  },

  /* TAUA or TAUB or TAUC Channel Index: 1 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x0004
  },

  /* TAUA or TAUB or TAUC Channel Index: 2 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x0010
  },

  /* TAUA or TAUB or TAUC Channel Index: 3 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x0040
  },

  /* TAUA or TAUB or TAUC Channel Index: 4 */
  {
    /* usDefaultPeriod */
    0x001B,

    /* usChannelMask */
    0x000F
  },

  /* TAUA or TAUB or TAUC Channel Index: 5 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x0002
  },

  /* TAUA or TAUB or TAUC Channel Index: 6 */
  {
    /* usDefaultDuty */
    0x4000,

    /* usChannelMask */
    0x0004
  },

  /* TAUA or TAUB or TAUC Channel Index: 7 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x0008
  },

  /* TAUA or TAUB or TAUC Channel Index: 8 */
  {
    /* usDefaultPeriod */
    0x001B,

    /* usChannelMask */
    0x0003
  },

  /* TAUA or TAUB or TAUC Channel Index: 9 */
  {
    /* usDefaultDuty */
    0x4000,

    /* usChannelMask */
    0x0002
  },

  /* TAUA or TAUB or TAUC Channel Index: 10 */
  {
    /* usDefaultPeriod */
    0x001B,

    /* usChannelMask */
    0x000C
  },

  /* TAUA or TAUB or TAUC Channel Index: 11 */
  {
    /* usDefaultDuty */
    0x4000,

    /* usChannelMask */
    0x0008
  },

  /* TAUA or TAUB or TAUC Channel Index: 12 */
  {
    /* usDefaultPeriod */
    0x001B,

    /* usChannelMask */
    0x0030
  },

  /* TAUA or TAUB or TAUC Channel Index: 13 */
  {
    /* usDefaultDuty */
    0x4000,

    /* usChannelMask */
    0x0020
  },

  /* TAUA or TAUB or TAUC Channel Index: 14 */
  {
    /* usDefaultPeriod */
    0x001B,

    /* usChannelMask */
    0x00C0
  },

  /* TAUA or TAUB or TAUC Channel Index: 15 */
  {
    /* usDefaultDuty */
    0x4000,

    /* usChannelMask */
    0x0080
  },

  /* TAUA or TAUB or TAUC Channel Index: 16 */
  {
    /* usDefaultPeriod */
    0x001B,

    /* usChannelMask */
    0x0300
  },

  /* TAUA or TAUB or TAUC Channel Index: 17 */
  {
    /* usDefaultDuty */
    0x4000,

    /* usChannelMask */
    0x0200
  },

  /* TAUA or TAUB or TAUC Channel Index: 18 */
  {
    /* usDefaultPeriod */
    0x001B,

    /* usChannelMask */
    0x0C00
  },

  /* TAUA or TAUB or TAUC Channel Index: 19 */
  {
    /* usDefaultDuty */
    0x4000,

    /* usChannelMask */
    0x0800
  },

  /* TAUA or TAUB or TAUC Channel Index: 20 */
  {
    /* usDefaultPeriod */
    0x0D05,

    /* usChannelMask */
    0x0003
  },

  /* TAUA or TAUB or TAUC Channel Index: 21 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x0002
  },

  /* TAUA or TAUB or TAUC Channel Index: 22 */
  {
    /* usDefaultPeriod */
    0x0D05,

    /* usChannelMask */
    0x000C
  },

  /* TAUA or TAUB or TAUC Channel Index: 23 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x0008
  },

  /* TAUA or TAUB or TAUC Channel Index: 24 */
  {
    /* usDefaultPeriod */
    0x0D05,

    /* usChannelMask */
    0x0030
  },

  /* TAUA or TAUB or TAUC Channel Index: 25 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x0020
  },

  /* TAUA or TAUB or TAUC Channel Index: 26 */
  {
    /* usDefaultPeriod */
    0x0D05,

    /* usChannelMask */
    0x00C0
  },

  /* TAUA or TAUB or TAUC Channel Index: 27 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x0080
  },

  /* TAUA or TAUB or TAUC Channel Index: 28 */
  {
    /* usDefaultPeriod */
    0x0D05,

    /* usChannelMask */
    0x0500
  },

  /* TAUA or TAUB or TAUC Channel Index: 29 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x0400
  },

  /* TAUA or TAUB or TAUC Channel Index: 30 */
  {
    /* usDefaultPeriod */
    0x0D05,

    /* usChannelMask */
    0x3000
  },

  /* TAUA or TAUB or TAUC Channel Index: 31 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x2000
  },

  /* TAUA or TAUB or TAUC Channel Index: 32 */
  {
    /* usDefaultPeriod */
    0x0D05,

    /* usChannelMask */
    0xC000
  },

  /* TAUA or TAUB or TAUC Channel Index: 33 */
  {
    /* usDefaultDuty */
    0x8000,

    /* usChannelMask */
    0x8000
  }
};


/* Structure for TAUJ Configuration set */
/* CONST(Tdd_Pwm_TAUJProperties,PWM_CONST) Pwm_GstTAUJChannelConfig[]; */
/* Structure for channel Configuration set */
CONST(Tdd_Pwm_ChannelConfigType,PWM_CONST) Pwm_GstChannelConfig[] =
{
  /* Channel Index: 0 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[0],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF808000,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF808200,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x00,

    /* uiPwmTAUType */
    PWM_HW_TAUA,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 1 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[1],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF808008,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF808208,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x00,

    /* uiPwmTAUType */
    PWM_HW_TAUA,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 2 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[2],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF808010,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF808210,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x02,

    /* ucTimerUnitIndex */
    0x00,

    /* uiPwmTAUType */
    PWM_HW_TAUA,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 3 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[3],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF808018,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF808218,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x03,

    /* ucTimerUnitIndex */
    0x00,

    /* uiPwmTAUType */
    PWM_HW_TAUA,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 4 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[20],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809000,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809200,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 5 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[21],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809004,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809204,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 6 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[22],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809008,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809208,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 7 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[23],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80900C,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80920C,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 8 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[24],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809010,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809210,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 9 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[25],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809014,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809214,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 10 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[26],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809018,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809218,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 11 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[27],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80901C,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80921C,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 12 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[28],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809020,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809220,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 13 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[29],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809028,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809228,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 14 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[30],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809030,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809230,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 15 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[31],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809034,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809234,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 16 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[32],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809038,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF809238,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 17 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[33],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80903C,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80923C,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x01,

    /* uiPwmTAUType */
    PWM_HW_TAUB,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 18 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[8],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A000,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A200,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 19 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[9],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A004,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A204,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 20 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[10],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A008,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A208,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 21 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[11],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A00C,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A20C,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 22 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[12],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A010,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A210,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 23 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[13],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A014,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A214,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 24 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[14],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A018,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A218,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 25 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[15],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A01C,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A21C,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 26 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[16],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A020,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A220,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 27 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[17],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A024,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A224,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 28 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[18],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A028,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A228,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 29 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[19],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A02C,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80A22C,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x02,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 30 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[4],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80B000,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80B200,

    /* usCMORegSettingsMask */
    0x0801,

    /* ucMasterOffset */
    0x00,

    /* ucTimerUnitIndex */
    0x03,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_MASTER_CHANNEL
  },

  /* Channel Index: 31 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[5],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80B004,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80B204,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x01,

    /* ucTimerUnitIndex */
    0x03,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 32 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[6],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80B008,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80B208,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x02,

    /* ucTimerUnitIndex */
    0x03,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  },

  /* Channel Index: 33 */
  {
    /* pChannelProp */
    &Pwm_GstTAUABCChannelConfig[7],

    /* pCntlRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80B00C,

    /* pCMORRegs */
    (P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)) 0xFF80B20C,

    /* usCMORegSettingsMask */
    0x0409,

    /* ucMasterOffset */
    0x03,

    /* ucTimerUnitIndex */
    0x03,

    /* uiPwmTAUType */
    PWM_HW_TAUC,

    /* enClassType */
    PWM_VARIABLE_PERIOD,

    /* uiIdleLevel */
    PWM_LOW,

    /* uiTimerMode */
    PWM_SLAVE_CHANNEL
  }
};


/* structure for Synchronous start Configuration */
/* CONST(Tdd_PwmTAUSynchStartUseType, PWM_CONST) Pwm_GstTAUSynchStartConfig[]; */
/* Pwm Channel index array */
CONST(uint8, PWM_PRIVATE_CONST) Pwm_GaaTimerChIdx[52] =
{
  /* Channel Id: 0 */
  0x00,

  /* Channel Id: 1 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 2 */
  0x01,

  /* Channel Id: 3 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 4 */
  0x02,

  /* Channel Id: 5 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 6 */
  0x03,

  /* Channel Id: 7 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 8 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 9 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 10 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 11 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 12 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 13 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 14 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 15 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 16 */
  0x04,

  /* Channel Id: 17 */
  0x05,

  /* Channel Id: 18 */
  0x06,

  /* Channel Id: 19 */
  0x07,

  /* Channel Id: 20 */
  0x08,

  /* Channel Id: 21 */
  0x09,

  /* Channel Id: 22 */
  0x0A,

  /* Channel Id: 23 */
  0x0B,

  /* Channel Id: 24 */
  0x0C,

  /* Channel Id: 25 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 26 */
  0x0D,

  /* Channel Id: 27 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 28 */
  0x0E,

  /* Channel Id: 29 */
  0x0F,

  /* Channel Id: 30 */
  0x10,

  /* Channel Id: 31 */
  0x11,

  /* Channel Id: 32 */
  0x12,

  /* Channel Id: 33 */
  0x13,

  /* Channel Id: 34 */
  0x14,

  /* Channel Id: 35 */
  0x15,

  /* Channel Id: 36 */
  0x16,

  /* Channel Id: 37 */
  0x17,

  /* Channel Id: 38 */
  0x18,

  /* Channel Id: 39 */
  0x19,

  /* Channel Id: 40 */
  0x1A,

  /* Channel Id: 41 */
  0x1B,

  /* Channel Id: 42 */
  0x1C,

  /* Channel Id: 43 */
  0x1D,

  /* Channel Id: 44 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 45 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 46 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 47 */
  PWM_CHANNEL_UNCONFIGURED,

  /* Channel Id: 48 */
  0x1E,

  /* Channel Id: 49 */
  0x1F,

  /* Channel Id: 50 */
  0x20,

  /* Channel Id: 51 */
  0x21
};


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define PWM_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Array for Notification status of timers configured */
/* VAR(uint8, PWM_NOINIT_DATA) Pwm_GaaNotifStatus[]; */

/* Array for Idle state status for all configured channels */
VAR(uint8, PWM_NOINIT_DATA) Pwm_GaaChannelIdleStatus[34];

#define PWM_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/

