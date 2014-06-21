/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Adc_PBcfg.c                                                 */
/* Version      = 3.1.2                                                       */  
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains post-build time parameters.                             */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
 * TOOL VERSION:    3.1.7
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    FK4_4010_ADC_V308_140113_HEADLAMP.arxml
 *                FK4_4010_MCU_V308_140113_HEADLAMP.arxml
 * GENERATED ON:  14 Jan 2014 - 09:27:57
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Adc_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification version information */
#define ADC_PBCFG_C_AR_MAJOR_VERSION  3
#define ADC_PBCFG_C_AR_MINOR_VERSION  0
#define ADC_PBCFG_C_AR_PATCH_VERSION  1

/* File version information */
#define ADC_PBCFG_C_SW_MAJOR_VERSION   3
#define ADC_PBCFG_C_SW_MINOR_VERSION   1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ADC_PBTYPES_AR_MAJOR_VERSION != ADC_PBCFG_C_AR_MAJOR_VERSION)
  #error "Adc_PBcfg.c : Mismatch in Specification Major Version"
#endif

#if (ADC_PBTYPES_AR_MINOR_VERSION != ADC_PBCFG_C_AR_MINOR_VERSION)
  #error "Adc_PBcfg.c : Mismatch in Specification Minor Version"
#endif

#if (ADC_PBTYPES_AR_PATCH_VERSION != ADC_PBCFG_C_AR_PATCH_VERSION)
  #error "Adc_PBcfg.c : Mismatch in Specification Patch Version"
#endif

#if (ADC_SW_MAJOR_VERSION != ADC_PBCFG_C_SW_MAJOR_VERSION)
  #error "Adc_PBcfg.c : Mismatch in Major Version"
#endif

#if (ADC_SW_MINOR_VERSION != ADC_PBCFG_C_SW_MINOR_VERSION)
  #error "Adc_PBcfg.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* RAM Allocation of Channel group data */
VAR(Tdd_Adc_ChannelGroupRamData,ADC_NOINIT_DATA) Adc_GstGroupRamData[2];

/* RAM Allocation of hardware unit data */
VAR(Tdd_Adc_HwUnitRamData, ADC_NOINIT_DATA) Adc_GstHwUnitRamData[2];

/* RAM Allocation of Group Runtime data */
VAR(Tdd_Adc_RunTimeData, ADC_NOINIT_DATA) Adc_GstRunTimeData[2];


#define ADC_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define ADC_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* RAM Initialization of ADC Channel Configuration */
CONST(Adc_ConfigType, ADC_CONST) Adc_GstConfiguration[] =
{
  /* Configuration 0 - AdcConfigSet0 */
  {
    /* ulStartOfDbToc */
    0x05DEC308,

    /* pHWUnitConfig */
    &Adc_GstHWUnitConfig[0],

    /* pGroupConfig */
    &Adc_GstGroupConfig[0],

    /* pGroupRamData */
    &Adc_GstGroupRamData[0],

    /* pHwUnitRamData */
    &Adc_GstHwUnitRamData[0],

    /* pRunTimeData */
    &Adc_GstRunTimeData[0],

    /* ucMaxSwTriggGroups */
    0x02
  }
};



#define ADC_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure IMR Register address and mask value */
CONST(Tdd_AdcImrAddMaskConfigType, ADC_CONST) Adc_GstImrAddMask[] =
{
  /*  0 - ADA0_CG0 */
  {
    /* pImrIntpAddress */
    (P2VAR(uint8, AUTOMATIC, ADC_CONFIG_DATA)) 0xFFFF640Cul,

    /* ucImrMask */
    0xDF
  },

  /*  1 - ADA1_CG0 */
  {
    /* pImrIntpAddress */
    (P2VAR(uint8, AUTOMATIC, ADC_CONFIG_DATA)) 0xFFFF6411ul,

    /* ucImrMask */
    0x7F
  }
};



/* Structure for each Hardware Unit Configuration */
CONST(Tdd_Adc_HwUnitConfigType, ADC_CONST) Adc_GstHWUnitConfig[] =
{
  /*  0 - AdcConfigSet0_ADA0 */
  {
    /* pUserBaseAddress */
    (P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC, ADC_CONFIG_DATA)) 0xFF81D000ul,

    /* pOsBaseAddress */
    (P2VAR(Tdd_AdcConfigOsRegisters, AUTOMATIC, ADC_CONFIG_DATA)) 0xFF81D100ul,

    /* pAdcResult */
    (P2VAR(uint32, AUTOMATIC, ADC_CONFIG_DATA)) 0xFF81D03Cul,

    /* pIntpAddress */
    (P2VAR(uint16, AUTOMATIC, ADC_CONFIG_DATA)) 0xFFFF60CAul,

    /* pImrAddMask */
    &Adc_GstImrAddMask[0],

    /* ulHwUnitSettings */
    0x00000001,

    /* ucStabilzationCount */
    0x08
  },

  /*  1 - AdcConfigSet0_ADA1 */
  {
    /* pUserBaseAddress */
    (P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC, ADC_CONFIG_DATA)) 0xFF81E000ul,

    /* pOsBaseAddress */
    (P2VAR(Tdd_AdcConfigOsRegisters, AUTOMATIC, ADC_CONFIG_DATA)) 0xFF81E100ul,

    /* pAdcResult */
    (P2VAR(uint32, AUTOMATIC, ADC_CONFIG_DATA)) 0xFF81E060ul,

    /* pIntpAddress */
    (P2VAR(uint16, AUTOMATIC, ADC_CONFIG_DATA)) 0xFFFF611Eul,

    /* pImrAddMask */
    &Adc_GstImrAddMask[1],

    /* ulHwUnitSettings */
    0x00000001,

    /* ucStabilzationCount */
    0x08
  }
};



/* Structure for each Group Configuration */
CONST(Tdd_Adc_GroupConfigType, ADC_CONST) Adc_GstGroupConfig[] =
{
  /*  Index: 0 - AdcGroup0 */
  {
    /* pChannelToGroup */
    &Adc_GaaChannelToGroup[0],

    /* ulChannelList */
    0x00000C03,

    /* ddGroupAccessMode */
    ADC_ACCESS_MODE_SINGLE,

    /* ddNumberofSamples */
    0x01,

    /* ucHwUnit */
    0x00,

    /* ucHwCGUnit */
    ADC_CG0,

    /* ucResultAccessMode */
    ADC_ISR_ACCESS,

    /* ucConversionMode */
    ADC_ONCE,

    /* ucChannelCount */
    0x04
  },

  /*  Index: 1 - AdcGroup1 */
  {
    /* pChannelToGroup */
    &Adc_GaaChannelToGroup[4],

    /* ulChannelList */
    0x00000E00,

    /* ddGroupAccessMode */
    ADC_ACCESS_MODE_SINGLE,

    /* ddNumberofSamples */
    0x01,

    /* ucHwUnit */
    0x01,

    /* ucHwCGUnit */
    ADC_CG0,

    /* ucResultAccessMode */
    ADC_ISR_ACCESS,

    /* ucConversionMode */
    ADC_ONCE,

    /* ucChannelCount */
    0x03
  }
};



/* Structure for each Group Configuration */
/* CONST(Tdd_Adc_HWGroupTriggType, ADC_CONST) Adc_GstHWGroupTrigg[]; */

/* Structure for each Group Configuration */
/* CONST(Tdd_Adc_DmaUnitConfig, ADC_CONST) Adc_GstDmaUnitConfig[]; */

/* Channel list */
CONST(Adc_ChannelType, ADC_CONFIG_CONST) Adc_GaaChannelToGroup[] =
{
  /* Channels assigned to Group: 0 */
  0x00, 0x01, 0x0A, 0x0B,

  /* Channels assigned to Group: 1 */
  0x00, 0x01, 0x02
};



/* Mapping of DMA channel Id to the HW unit */
/* CONST(Adc_HwUnitType, ADC_CONFIG_CONST) Adc_GaaHwUnit[]; */

/* Mapping of DMA channel Id to the CGm unit */
/* CONST(uint8, ADC_CONFIG_CONST) Adc_GaaCGUnit[]; */

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
