/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Gpt_PBcfg.c                                                 */
/* Version      = 3.0.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
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
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:              : Initial version
 */
/******************************************************************************/
/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    3.0.11a
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    FK4_4010_GPT_V304_130924_NEWCLEAPLUS.arxml
 * GENERATED ON:  26 Sep 2013 - 12:55:15
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Gpt_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*
 * AUTOSAR specification version information
 */
#define GPT_PBCFG_C_AR_MAJOR_VERSION  2
#define GPT_PBCFG_C_AR_MINOR_VERSION  2
#define GPT_PBCFG_C_AR_PATCH_VERSION  0
/*
 * File version information
 */
#define GPT_PBCFG_C_SW_MAJOR_VERSION     3
#define GPT_PBCFG_C_SW_MINOR_VERSION     0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (GPT_PBTYPES_AR_MAJOR_VERSION != GPT_PBCFG_C_AR_MAJOR_VERSION)
  #error "Gpt_PBcfg.c : Mismatch in Specification Major Version"
#endif

#if (GPT_PBTYPES_AR_MINOR_VERSION != GPT_PBCFG_C_AR_MINOR_VERSION)
  #error "Gpt_PBcfg.c : Mismatch in Specification Minor Version"
#endif

#if (GPT_PBTYPES_AR_PATCH_VERSION != GPT_PBCFG_C_AR_PATCH_VERSION)
  #error "Gpt_PBcfg.c : Mismatch in Specification Patch Version"
#endif

#if (GPT_PBTYPES_SW_MAJOR_VERSION != GPT_PBCFG_C_SW_MAJOR_VERSION)
  #error "Gpt_PBcfg.c : Mismatch in Major Version"
#endif

#if (GPT_PBTYPES_SW_MINOR_VERSION != GPT_PBCFG_C_SW_MINOR_VERSION)
  #error "Gpt_PBcfg.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define GPT_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Initialization of GPT Channel Configuration */
CONST(Gpt_ConfigType, GPT_CONST) Gpt_GstConfiguration[] =
{
  /* Configuration Set 0 */
  {
    /* ulStartOfDbToc */
    0x05D90300,

    /* pChannelConfig */
    &Gpt_GstChannelConfig[0],

    /* pChannelTimerMap */
    &Gpt_GaaTimerChIdx[0],

    /* pChannelRamData */
    &Gpt_GstChannelRamData[0]
  }
};



#define GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for each TAU Unit Configuration set */
/* CONST(Tdd_Gpt_TAUUnitConfigType,GPT_CONST) Gpt_GstTAUUnitConfig[]; */

/* Structure for each Config Set */
CONST(Tdd_Gpt_ChannelConfigType, GPT_CONST) Gpt_GstChannelConfig[] =
{
  /* Index: 0 */
  {
    /* pBaseCtlAddress */
    (P2VAR(void, AUTOMATIC, GPT_CONFIG_DATA)) 0xFF800000ul,

    /* pCMORorCTLAddress */
    (P2VAR(uint16, AUTOMATIC, GPT_CONFIG_DATA)) 0xFF800020,

    /* pImrIntrCntlAddress */
    (P2VAR(void, AUTOMATIC, GPT_CONFIG_DATA))0xFFFF6412ul,

    /* pIntrCntlAddress */
    (P2VAR(uint16, AUTOMATIC, GPT_CONFIG_DATA))0xFFFF6126ul,

    /* usChannelMask */
    0x0001,

    /* usModeSettingsMask */
    0x4000,

    /* ddWakeupSourceId */
    0x00,

    /* ucNotificationConfig */
    0x00,

    /* ucImrMaskValue */
    0xF7,

    /* ucTimerUnitIndex */
    0xFF,

    /* uiTimerType */
    GPT_HW_OSTM,

    /* uiGptEnableWakeup */
    GPT_FALSE,

    /* uiGptChannelMode */
    GPT_MODE_CONTINUOUS
  }
};



/* Array to map channel to timer index */
CONST(uint8, GPT_CONST) Gpt_GaaTimerChIdx[157] =
{
  /* Index:  0 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  1 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  2 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  3 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  4 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  5 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  6 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  7 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  8 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  9 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  10 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  11 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  12 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  13 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  14 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  15 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  16 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  17 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  18 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  19 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  20 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  21 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  22 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  23 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  24 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  25 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  26 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  27 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  28 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  29 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  30 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  31 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  32 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  33 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  34 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  35 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  36 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  37 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  38 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  39 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  40 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  41 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  42 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  43 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  44 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  45 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  46 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  47 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  48 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  49 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  50 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  51 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  52 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  53 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  54 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  55 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  56 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  57 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  58 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  59 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  60 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  61 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  62 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  63 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  64 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  65 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  66 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  67 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  68 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  69 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  70 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  71 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  72 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  73 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  74 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  75 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  76 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  77 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  78 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  79 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  80 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  81 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  82 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  83 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  84 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  85 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  86 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  87 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  88 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  89 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  90 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  91 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  92 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  93 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  94 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  95 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  96 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  97 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  98 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  99 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  100 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  101 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  102 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  103 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  104 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  105 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  106 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  107 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  108 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  109 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  110 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  111 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  112 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  113 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  114 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  115 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  116 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  117 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  118 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  119 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  120 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  121 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  122 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  123 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  124 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  125 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  126 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  127 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  128 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  129 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  130 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  131 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  132 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  133 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  134 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  135 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  136 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  137 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  138 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  139 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  140 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  141 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  142 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  143 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  144 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  145 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  146 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  147 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  148 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  149 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  150 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  151 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  152 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  153 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  154 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  155 */
  GPT_CHANNEL_UNCONFIGURED,

  /* Index:  156 */
  0x00
};



#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define GPT_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* RAM Allocation of Channel data */
VAR(Tdd_Gpt_ChannelRamData,GPT_NOINIT_DATA) Gpt_GstChannelRamData[1];

#define GPT_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
