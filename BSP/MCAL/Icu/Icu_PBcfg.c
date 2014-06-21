/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu_PBcfg.c                                                 */
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
/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:  3.0.13a
 */ 
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    FK4_4010_ICU_V304_130924_NEWCLEAPLUS.arxml
 * GENERATED ON:  30 Sep 2013 - 10:23:54
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Icu.h"
#include "Icu_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define ICU_PBCFG_C_AR_MAJOR_VERSION  3
#define ICU_PBCFG_C_AR_MINOR_VERSION  0
#define ICU_PBCFG_C_AR_PATCH_VERSION  0

/* File version information */
#define ICU_PBCFG_C_SW_MAJOR_VERSION  3
#define ICU_PBCFG_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Specification Major Version Check */
#if (ICU_PBTYPES_AR_MAJOR_VERSION != ICU_PBCFG_C_AR_MAJOR_VERSION)
  #error "Icu_PBcfg.c : Mismatch in Specification Major version"
#endif

/* Specification Minor Version Check */
#if (ICU_PBTYPES_AR_MINOR_VERSION != ICU_PBCFG_C_AR_MINOR_VERSION)
  #error "Icu_PBcfg.c : Mismatch in Specification Minor version"
#endif

/* Specification Patch Version Check */
#if (ICU_PBTYPES_AR_PATCH_VERSION != ICU_PBCFG_C_AR_PATCH_VERSION)
  #error "Icu_PBcfg.c : Mismatch in Specification Patch version"
#endif

/* Major version check */
#if (ICU_PBTYPES_SW_MAJOR_VERSION != ICU_PBCFG_C_SW_MAJOR_VERSION)
  #error "Icu_PBcfg.c : Mismatch in Major version"
#endif

/* Minor version check */
#if (ICU_PBTYPES_SW_MINOR_VERSION != ICU_PBCFG_C_SW_MINOR_VERSION)
  #error "Icu_PBcfg.c : Mismatch in Minor version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define ICU_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* RAM Allocation of Channel data */
VAR(Tdd_Icu_ChannelRamDataType,ICU_NOINIT_DATA) Icu_GstChannelRamData[3];

/* RAM Allocation of Timestamp channel data */
/* VAR(Tdd_Icu_TimeStampChannelRamDataType,ICU_NOINIT_DATA) Icu_GstTimestampRamData[]; */

/* RAM Allocation of Signal Measure Channel data */
VAR(Tdd_Icu_SignalMeasureChannelRamDataType,ICU_NOINIT_DATA) Icu_GstSignalMeasureRamData[2];

/* RAM Allocation of Edge Counting Channel data */
/* VAR(Tdd_Icu_EdgeCountChannelRamDataType,ICU_NOINIT_DATA) Icu_GstEdgeCountRamData[]; */

#define ICU_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define ICU_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for each Config Set */
CONST(Icu_ConfigType, ICU_CONST) Icu_GstConfiguration[] =
{
  /* Structure for initialization of database 0 */
  {
    /* ulStartOfDbToc */
    0x05DE8300,

    /* pChannelConfig */
    &Icu_GstChannelConfig[0],

    /* pTimerChannelConfig */
    &Icu_GstTimerChannelConfig[0],

    /* pHWUnitConfig */
    &Icu_GstTAUUnitConfig[0],

    /* pRamAddress */
    &Icu_GstChannelRamData[0],

    /* pSignalMeasureAddress */
    &Icu_GstSignalMeasureRamData[0],

    /* pTimeStampAddress */
    NULL_PTR,

    /* pEdgeCountRamAddress */
    NULL_PTR,

    /* pChannelMap */
    &Icu_GaaChannelMap[0]
  }
};



#define ICU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Array of structures for Hardware Configuration */
CONST(Tdd_Icu_TAUUnitConfigType, ICU_CONST) Icu_GstTAUUnitConfig[] =
{
  /* Configuration 0 */
  {
    /* pTAUnitUserCntlRegs */
    (P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)) 0xFF808040ul,

    /* pTAUnitOsCntlRegs */
    (P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)) 0xFF808240ul,

    /* usPrescaler */
    0xC963,

    /* ucIcuUnitType */
    ICU_HW_TAUA,

    /* usTAUChannelMaskValue */
    0x0010,

    /* ucBaudRate */
    0xFF,

    /* uiConfigurePrescaler */
    ICU_TRUE
  },

  /* Configuration 1 */
  {
    /* pTAUnitUserCntlRegs */
    (P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)) 0xFF809040ul,

    /* pTAUnitOsCntlRegs */
    (P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)) 0xFF809240ul,

    /* usPrescaler */
    0xC963,

    /* ucIcuUnitType */
    ICU_HW_TAUB,

    /* usTAUChannelMaskValue */
    0x0000,

    /* ucBaudRate */
    0x00,

    /* uiConfigurePrescaler */
    ICU_TRUE
  }
};



/* Edge counting channel configuration data */
/* CONST(Tdd_Icu_EdgeCountConfigType, ICU_CONST) Icu_GstEdgeCountConfig[]; */

/* Signal Measurement channel configuration data */
CONST(Tdd_Icu_SignalMeasureConfigType, ICU_CONST) Icu_GstSignalMeasureConfig[] =
{
  /* Index: 0 */
  {
    /* uiSignalMeasurementProperty */
    ICU_HIGH_TIME,

    /* ucSignalMeasureRamDataIndex */
    0x00,

    /* blDutyCycleChannel */
    ICU_TRUE
  },

  /* Index: 1 */
  {
    /* uiSignalMeasurementProperty */
    ICU_PERIOD_TIME,

    /* ucSignalMeasureRamDataIndex */
    0x00,

    /* blDutyCycleChannel */
    ICU_TRUE
  }
};



/* Timestamping channel configuration data */
/* CONST(Tdd_Icu_TimeStampMeasureConfigType, ICU_CONST) Icu_GstTimestampMeasureConfig[]; */

/* Configuration of each ICU Channel */
CONST(Tdd_Icu_ChannelConfigType, ICU_CONST) Icu_GstChannelConfig[] =
{
  /* Index: 0 */
  {
    /* pCntlRegs */
    (P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)) 0xFF808010,

    /* pImrIntrCntlRegs */
    (P2VAR(uint8, AUTOMATIC, ICU_CONFIG_DATA))0xFFFF6403ul,

    /* pIntrCntlRegs */
    (P2VAR(uint16, AUTOMATIC, ICU_CONFIG_DATA)) 0xFFFF6030ul,

    /* usChannelMaskValue */
    0x0030,

    /* ucIcuNotificationIndex */
    ICU_NO_CBK_CONFIGURED,

    /* ucImrMaskValue */
    0xFE,

    /* uiIcuMeasurementMode */
    ICU_MODE_SIGNAL_MEASUREMENT,

    /* uiIcuDefaultStartEdge */
    ICU_BOTH_EDGES,

    /* uiIcuChannelType */
    ICU_HW_TAUA
  },

  /* Index: 1 */
  {
    /* pCntlRegs */
    (P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)) 0xFF808014,

    /* pImrIntrCntlRegs */
    (P2VAR(uint8, AUTOMATIC, ICU_CONFIG_DATA))0xFFFF6403ul,

    /* pIntrCntlRegs */
    (P2VAR(uint16, AUTOMATIC, ICU_CONFIG_DATA)) 0xFFFF6032ul,

    /* usChannelMaskValue */
    0x0030,

    /* ucIcuNotificationIndex */
    ICU_NO_CBK_CONFIGURED,

    /* ucImrMaskValue */
    0xFD,

    /* uiIcuMeasurementMode */
    ICU_MODE_SIGNAL_MEASUREMENT,

    /* uiIcuDefaultStartEdge */
    ICU_RISING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_TAUA
  },

  /* Index: 2 */
  {
    /* pCntlRegs */
    (P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)) 0xFF414034,

    /* pImrIntrCntlRegs */
    (P2VAR(uint8, AUTOMATIC, ICU_CONFIG_DATA)) 0xFFFF641Aul,

    /* pIntrCntlRegs */
    (P2VAR(uint16, AUTOMATIC, ICU_CONFIG_DATA)) 0xFFFF61A4ul,

    /* usChannelMaskValue */
    0x2000,

    /* ucIcuNotificationIndex */
    0x00,

    /* ucImrMaskValue */
    0xFB,

    /* uiIcuMeasurementMode */
    ICU_MODE_SIGNAL_EDGE_DETECT,

    /* uiIcuDefaultStartEdge */
    ICU_FALLING_EDGE,

    /* uiIcuChannelType */
    ICU_HW_EXT_INTP
  }
};



/* Configuration of each ICU Timer Channel */
CONST(Tdd_Icu_TimerChannelConfigType, ICU_CONST) Icu_GstTimerChannelConfig[] =
{
  /* Index: 0 */
  {
    /* *pChannelProp */
    &Icu_GstSignalMeasureConfig[0],

    /* pCMORRegs */
    (P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)) 0xFF808210,

    /* usChannelModeOSRegSettings */
    0x024C,

    /* ucChannelModeUserRegSettings */
    0x03,

    /* ucTimerUnitIndex */
    0x00
  },

  /* Index: 1 */
  {
    /* *pChannelProp */
    &Icu_GstSignalMeasureConfig[1],

    /* pCMORRegs */
    (P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)) 0xFF808214,

    /* usChannelModeOSRegSettings */
    0x0144,

    /* ucChannelModeUserRegSettings */
    0x01,

    /* ucTimerUnitIndex */
    0x00
  }
};


   
/* Array of structures for Previous Input Configuration */
/* CONST(Tdd_IcuPreviousInputUseType, ICU_CONST) Icu_GstPreviousInputConfig[]; */
  
/* ICU Channel Map Array*/
CONST(uint8, ICU_PRIVATE_CONST) Icu_GaaChannelMap[170] =
{
  /* Channel Id:  0 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  1 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  2 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  3 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  4 */
  0x00,

  /* Channel Id:  5 */
  0x01,

  /* Channel Id:  6 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  7 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  8 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  9 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  10 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  11 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  12 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  13 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  14 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  15 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  16 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  17 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  18 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  19 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  20 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  21 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  22 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  23 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  24 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  25 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  26 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  27 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  28 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  29 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  30 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  31 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  32 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  33 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  34 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  35 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  36 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  37 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  38 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  39 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  40 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  41 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  42 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  43 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  44 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  45 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  46 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  47 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  48 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  49 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  50 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  51 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  52 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  53 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  54 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  55 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  56 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  57 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  58 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  59 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  60 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  61 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  62 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  63 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  64 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  65 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  66 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  67 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  68 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  69 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  70 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  71 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  72 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  73 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  74 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  75 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  76 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  77 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  78 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  79 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  80 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  81 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  82 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  83 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  84 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  85 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  86 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  87 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  88 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  89 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  90 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  91 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  92 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  93 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  94 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  95 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  96 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  97 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  98 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  99 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  100 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  101 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  102 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  103 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  104 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  105 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  106 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  107 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  108 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  109 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  110 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  111 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  112 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  113 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  114 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  115 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  116 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  117 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  118 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  119 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  120 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  121 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  122 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  123 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  124 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  125 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  126 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  127 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  128 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  129 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  130 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  131 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  132 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  133 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  134 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  135 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  136 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  137 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  138 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  139 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  140 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  141 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  142 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  143 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  144 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  145 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  146 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  147 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  148 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  149 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  150 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  151 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  152 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  153 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  154 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  155 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  156 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  157 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  158 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  159 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  160 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  161 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  162 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  163 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  164 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  165 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  166 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  167 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  168 */
  ICU_CHANNEL_UNCONFIGURED,

  /* Channel Id:  169 */
  0x02
};


  
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
