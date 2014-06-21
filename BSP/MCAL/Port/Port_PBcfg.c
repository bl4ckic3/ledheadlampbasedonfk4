/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* file name    = Port_PBcfg.c                                                */
/* Version      = 3.1.4                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Post-Build time parameters.                             */
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
 * TOOL VERSION:  3.1.7a
 */

/*******************************************************************************
**                      Input File                                            **
*******************************************************************************/
/*
 * INPUT FILE:    PORT_REV2_HEADLAMP_V308_UPD4010_140619.arxml
 * GENERATED ON:  19 Jun 2014 - 16:59:42
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Port_PBTypes.h"

/*******************************************************************************
**                       Version Information                                  **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_PBCFG_C_AR_MAJOR_VERSION    3
#define PORT_PBCFG_C_AR_MINOR_VERSION    0
#define PORT_PBCFG_C_AR_PATCH_VERSION    1

/* File version information */
#define PORT_PBCFG_C_SW_MAJOR_VERSION  3
#define PORT_PBCFG_C_SW_MINOR_VERSION  1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PORT_PBTYPES_AR_MAJOR_VERSION != PORT_PBCFG_C_AR_MAJOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Specification Major Version"
#endif

#if (PORT_PBTYPES_AR_MINOR_VERSION != PORT_PBCFG_C_AR_MINOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Specification Minor Version"
#endif

#if (PORT_PBTYPES_AR_PATCH_VERSION != PORT_PBCFG_C_AR_PATCH_VERSION)
  #error "Port_PBcfg.c : Mismatch in Specification Patch Version"
#endif

#if (PORT_SW_MAJOR_VERSION != PORT_PBCFG_C_SW_MAJOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Major Version"
#endif

#if (PORT_SW_MINOR_VERSION != PORT_PBCFG_C_SW_MINOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define PORT_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* The following structure indicates the starting point of database */
CONST(Port_ConfigType, PORT_CONST) Port_GstConfiguration[] =
{
  /* Configuration 0 - 0 */
  {
    /* ulStartOfDbToc */
    0x05DF0308,

    /* pPortNumRegs */
    &Port_Num_Regs[0],

    /* pPortNumFuncCtrlRegs */
    &Port_Num_FuncCtrlRegs[0],

    /* pPortNumPMSRRegs */
    &Port_Num_PMSRRegs[0],

    /* pPortJRegs */
    &Port_JTAG_Regs[0],

    /* pPortJFuncCtrlRegs */
    &Port_JTAG_FuncCtrlRegs[0],

    /* pPortJPMSRRegs */
    &Port_JTAG_PMSRRegs[0],

    /* pPinDirChangeable */
    NULL_PTR,

    /* pPinModeChangeableGroups */
    NULL_PTR,

    /* pPinModeChangeableDetails */
    NULL_PTR,

    /* ucNoOfNumPSRRegs */
    0x0B,

    /* ucNoOfNumPMCSRRegs */
    0x0A,

    /* ucNoOfNumOther16BitRegs */
    0x3C,

    /* ucNoOfNumPODCRegs */
    0x0B,

    /* ucNoOfNumPDSCRegs */
    0x07,

    /* ucNoOfNumPUCCRegs */
    0x00,

    /* ucNoOfNumPSBCRegs */
    0x00,

    /* ucNoOfNumFuncCtrlRegs */
    0x10,

    /* ucNoOfJFuncCtrlRegs */
    0x01,

    /* ucNoOfPinsDirChangeable */
    0x00,

    /* ucNoOfPinsModeChangeable */
    0x00
  }
};


#define PORT_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*
 * Array of structures of all port group registers, except PMSR, PFCE, PFC and
 * PMCSR, in the sequence of PSR, PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC,
 * PODC, PDSC, PUCC and PSBC.
 */
CONST(Tdd_Port_Regs, PORT_CONST) Port_Num_Regs[] =
{
  /*  0 - ConfigSet_0_Port_Group_0_Register_PSR_0 */
  {
    /* usRegAddrOffset */
    0x0100,

    /* usInitModeRegVal */
    0x0000
  },

  /*  1 - ConfigSet_0_Port_Group_1_Register_PSR_1 */
  {
    /* usRegAddrOffset */
    0x0104,

    /* usInitModeRegVal */
    0x0000
  },

  /*  2 - ConfigSet_0_Port_Group_2_Register_PSR_2 */
  {
    /* usRegAddrOffset */
    0x0108,

    /* usInitModeRegVal */
    0x0000
  },

  /*  3 - ConfigSet_0_Port_Group_3_Register_PSR_3 */
  {
    /* usRegAddrOffset */
    0x010C,

    /* usInitModeRegVal */
    0x0001
  },

  /*  4 - ConfigSet_0_Port_Group_4_Register_PSR_4 */
  {
    /* usRegAddrOffset */
    0x0110,

    /* usInitModeRegVal */
    0x0000
  },

  /*  5 - ConfigSet_0_Port_Group_10_Register_PSR_10 */
  {
    /* usRegAddrOffset */
    0x0128,

    /* usInitModeRegVal */
    0xA000
  },

  /*  6 - ConfigSet_0_Port_Group_11_Register_PSR_11 */
  {
    /* usRegAddrOffset */
    0x012C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  7 - ConfigSet_0_Port_Group_12_Register_PSR_12 */
  {
    /* usRegAddrOffset */
    0x0130,

    /* usInitModeRegVal */
    0x0003
  },

  /*  8 - ConfigSet_0_Port_Group_21_Register_PSR_21 */
  {
    /* usRegAddrOffset */
    0x0154,

    /* usInitModeRegVal */
    0x0200
  },

  /*  9 - ConfigSet_0_Port_Group_25_Register_PSR_25 */
  {
    /* usRegAddrOffset */
    0x0164,

    /* usInitModeRegVal */
    0x0000
  },

  /*  10 - ConfigSet_0_Port_Group_27_Register_PSR_27 */
  {
    /* usRegAddrOffset */
    0x016C,

    /* usInitModeRegVal */
    0x0008
  },

  /*  11 - ConfigSet_0_Port_Group_0_Register_PIS_0 */
  {
    /* usRegAddrOffset */
    0x0700,

    /* usInitModeRegVal */
    0x0000
  },

  /*  12 - ConfigSet_0_Port_Group_1_Register_PIS_1 */
  {
    /* usRegAddrOffset */
    0x0704,

    /* usInitModeRegVal */
    0x0000
  },

  /*  13 - ConfigSet_0_Port_Group_2_Register_PIS_2 */
  {
    /* usRegAddrOffset */
    0x0708,

    /* usInitModeRegVal */
    0x0000
  },

  /*  14 - ConfigSet_0_Port_Group_3_Register_PIS_3 */
  {
    /* usRegAddrOffset */
    0x070C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  15 - ConfigSet_0_Port_Group_4_Register_PIS_4 */
  {
    /* usRegAddrOffset */
    0x0710,

    /* usInitModeRegVal */
    0x0000
  },

  /*  16 - ConfigSet_0_Port_Group_21_Register_PIS_21 */
  {
    /* usRegAddrOffset */
    0x0754,

    /* usInitModeRegVal */
    0x0000
  },

  /*  17 - ConfigSet_0_Port_Group_25_Register_PIS_25 */
  {
    /* usRegAddrOffset */
    0x0764,

    /* usInitModeRegVal */
    0x0000
  },

  /*  18 - ConfigSet_0_Port_Group_27_Register_PIS_27 */
  {
    /* usRegAddrOffset */
    0x076C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  19 - ConfigSet_0_Port_Group_0_Register_PISE_0 */
  {
    /* usRegAddrOffset */
    0x0800,

    /* usInitModeRegVal */
    0x0000
  },

  /*  20 - ConfigSet_0_Port_Group_1_Register_PISE_1 */
  {
    /* usRegAddrOffset */
    0x0804,

    /* usInitModeRegVal */
    0x0000
  },

  /*  21 - ConfigSet_0_Port_Group_2_Register_PISE_2 */
  {
    /* usRegAddrOffset */
    0x0808,

    /* usInitModeRegVal */
    0x0000
  },

  /*  22 - ConfigSet_0_Port_Group_3_Register_PISE_3 */
  {
    /* usRegAddrOffset */
    0x080C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  23 - ConfigSet_0_Port_Group_4_Register_PISE_4 */
  {
    /* usRegAddrOffset */
    0x0810,

    /* usInitModeRegVal */
    0x0000
  },

  /*  24 - ConfigSet_0_Port_Group_21_Register_PISE_21 */
  {
    /* usRegAddrOffset */
    0x0854,

    /* usInitModeRegVal */
    0x0000
  },

  /*  25 - ConfigSet_0_Port_Group_25_Register_PISE_25 */
  {
    /* usRegAddrOffset */
    0x0864,

    /* usInitModeRegVal */
    0x0000
  },

  /*  26 - ConfigSet_0_Port_Group_27_Register_PISE_27 */
  {
    /* usRegAddrOffset */
    0x086C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  27 - ConfigSet_0_Port_Group_0_Register_PIBC_0 */
  {
    /* usRegAddrOffset */
    0x0000,

    /* usInitModeRegVal */
    0x0001
  },

  /*  28 - ConfigSet_0_Port_Group_1_Register_PIBC_1 */
  {
    /* usRegAddrOffset */
    0x0004,

    /* usInitModeRegVal */
    0x0000
  },

  /*  29 - ConfigSet_0_Port_Group_2_Register_PIBC_2 */
  {
    /* usRegAddrOffset */
    0x0008,

    /* usInitModeRegVal */
    0x0000
  },

  /*  30 - ConfigSet_0_Port_Group_3_Register_PIBC_3 */
  {
    /* usRegAddrOffset */
    0x000C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  31 - ConfigSet_0_Port_Group_4_Register_PIBC_4 */
  {
    /* usRegAddrOffset */
    0x0010,

    /* usInitModeRegVal */
    0x0000
  },

  /*  32 - ConfigSet_0_Port_Group_10_Register_PIBC_10 */
  {
    /* usRegAddrOffset */
    0x0028,

    /* usInitModeRegVal */
    0x0000
  },

  /*  33 - ConfigSet_0_Port_Group_11_Register_PIBC_11 */
  {
    /* usRegAddrOffset */
    0x002C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  34 - ConfigSet_0_Port_Group_12_Register_PIBC_12 */
  {
    /* usRegAddrOffset */
    0x0030,

    /* usInitModeRegVal */
    0x0002
  },

  /*  35 - ConfigSet_0_Port_Group_21_Register_PIBC_21 */
  {
    /* usRegAddrOffset */
    0x0054,

    /* usInitModeRegVal */
    0x0000
  },

  /*  36 - ConfigSet_0_Port_Group_25_Register_PIBC_25 */
  {
    /* usRegAddrOffset */
    0x0064,

    /* usInitModeRegVal */
    0x7FE2
  },

  /*  37 - ConfigSet_0_Port_Group_27_Register_PIBC_27 */
  {
    /* usRegAddrOffset */
    0x006C,

    /* usInitModeRegVal */
    0x0007
  },

  /*  38 - ConfigSet_0_Port_Group_0_Register_PIPC_0 */
  {
    /* usRegAddrOffset */
    0x0200,

    /* usInitModeRegVal */
    0x0000
  },

  /*  39 - ConfigSet_0_Port_Group_1_Register_PIPC_1 */
  {
    /* usRegAddrOffset */
    0x0204,

    /* usInitModeRegVal */
    0x0000
  },

  /*  40 - ConfigSet_0_Port_Group_3_Register_PIPC_3 */
  {
    /* usRegAddrOffset */
    0x020C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  41 - ConfigSet_0_Port_Group_4_Register_PIPC_4 */
  {
    /* usRegAddrOffset */
    0x0210,

    /* usInitModeRegVal */
    0x0000
  },

  /*  42 - ConfigSet_0_Port_Group_21_Register_PIPC_21 */
  {
    /* usRegAddrOffset */
    0x0254,

    /* usInitModeRegVal */
    0x0000
  },

  /*  43 - ConfigSet_0_Port_Group_25_Register_PIPC_25 */
  {
    /* usRegAddrOffset */
    0x0264,

    /* usInitModeRegVal */
    0x0000
  },

  /*  44 - ConfigSet_0_Port_Group_0_Register_PU_0 */
  {
    /* usRegAddrOffset */
    0x0300,

    /* usInitModeRegVal */
    0x0000
  },

  /*  45 - ConfigSet_0_Port_Group_1_Register_PU_1 */
  {
    /* usRegAddrOffset */
    0x0304,

    /* usInitModeRegVal */
    0x0000
  },

  /*  46 - ConfigSet_0_Port_Group_2_Register_PU_2 */
  {
    /* usRegAddrOffset */
    0x0308,

    /* usInitModeRegVal */
    0x0000
  },

  /*  47 - ConfigSet_0_Port_Group_3_Register_PU_3 */
  {
    /* usRegAddrOffset */
    0x030C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  48 - ConfigSet_0_Port_Group_4_Register_PU_4 */
  {
    /* usRegAddrOffset */
    0x0310,

    /* usInitModeRegVal */
    0x0000
  },

  /*  49 - ConfigSet_0_Port_Group_21_Register_PU_21 */
  {
    /* usRegAddrOffset */
    0x0354,

    /* usInitModeRegVal */
    0x0000
  },

  /*  50 - ConfigSet_0_Port_Group_25_Register_PU_25 */
  {
    /* usRegAddrOffset */
    0x0364,

    /* usInitModeRegVal */
    0x0000
  },

  /*  51 - ConfigSet_0_Port_Group_27_Register_PU_27 */
  {
    /* usRegAddrOffset */
    0x036C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  52 - ConfigSet_0_Port_Group_0_Register_PD_0 */
  {
    /* usRegAddrOffset */
    0x0400,

    /* usInitModeRegVal */
    0x0000
  },

  /*  53 - ConfigSet_0_Port_Group_1_Register_PD_1 */
  {
    /* usRegAddrOffset */
    0x0404,

    /* usInitModeRegVal */
    0x0000
  },

  /*  54 - ConfigSet_0_Port_Group_2_Register_PD_2 */
  {
    /* usRegAddrOffset */
    0x0408,

    /* usInitModeRegVal */
    0x0000
  },

  /*  55 - ConfigSet_0_Port_Group_3_Register_PD_3 */
  {
    /* usRegAddrOffset */
    0x040C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  56 - ConfigSet_0_Port_Group_4_Register_PD_4 */
  {
    /* usRegAddrOffset */
    0x0410,

    /* usInitModeRegVal */
    0x0000
  },

  /*  57 - ConfigSet_0_Port_Group_21_Register_PD_21 */
  {
    /* usRegAddrOffset */
    0x0454,

    /* usInitModeRegVal */
    0x0000
  },

  /*  58 - ConfigSet_0_Port_Group_25_Register_PD_25 */
  {
    /* usRegAddrOffset */
    0x0464,

    /* usInitModeRegVal */
    0x0000
  },

  /*  59 - ConfigSet_0_Port_Group_27_Register_PD_27 */
  {
    /* usRegAddrOffset */
    0x046C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  60 - ConfigSet_0_Port_Group_0_Register_PBDC_0 */
  {
    /* usRegAddrOffset */
    0x0100,

    /* usInitModeRegVal */
    0x0000
  },

  /*  61 - ConfigSet_0_Port_Group_1_Register_PBDC_1 */
  {
    /* usRegAddrOffset */
    0x0104,

    /* usInitModeRegVal */
    0x0000
  },

  /*  62 - ConfigSet_0_Port_Group_2_Register_PBDC_2 */
  {
    /* usRegAddrOffset */
    0x0108,

    /* usInitModeRegVal */
    0x0000
  },

  /*  63 - ConfigSet_0_Port_Group_3_Register_PBDC_3 */
  {
    /* usRegAddrOffset */
    0x010C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  64 - ConfigSet_0_Port_Group_4_Register_PBDC_4 */
  {
    /* usRegAddrOffset */
    0x0110,

    /* usInitModeRegVal */
    0x0000
  },

  /*  65 - ConfigSet_0_Port_Group_10_Register_PBDC_10 */
  {
    /* usRegAddrOffset */
    0x0128,

    /* usInitModeRegVal */
    0x0000
  },

  /*  66 - ConfigSet_0_Port_Group_11_Register_PBDC_11 */
  {
    /* usRegAddrOffset */
    0x012C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  67 - ConfigSet_0_Port_Group_12_Register_PBDC_12 */
  {
    /* usRegAddrOffset */
    0x0130,

    /* usInitModeRegVal */
    0x0000
  },

  /*  68 - ConfigSet_0_Port_Group_21_Register_PBDC_21 */
  {
    /* usRegAddrOffset */
    0x0154,

    /* usInitModeRegVal */
    0x0000
  },

  /*  69 - ConfigSet_0_Port_Group_25_Register_PBDC_25 */
  {
    /* usRegAddrOffset */
    0x0164,

    /* usInitModeRegVal */
    0x0000
  },

  /*  70 - ConfigSet_0_Port_Group_27_Register_PBDC_27 */
  {
    /* usRegAddrOffset */
    0x016C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  71 - ConfigSet_0_Port_Group_0_Register_PODC_0 */
  {
    /* usRegAddrOffset */
    0x0500,

    /* usInitModeRegVal */
    0x0000
  },

  /*  72 - ConfigSet_0_Port_Group_1_Register_PODC_1 */
  {
    /* usRegAddrOffset */
    0x0504,

    /* usInitModeRegVal */
    0x0000
  },

  /*  73 - ConfigSet_0_Port_Group_2_Register_PODC_2 */
  {
    /* usRegAddrOffset */
    0x0508,

    /* usInitModeRegVal */
    0x0000
  },

  /*  74 - ConfigSet_0_Port_Group_3_Register_PODC_3 */
  {
    /* usRegAddrOffset */
    0x050C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  75 - ConfigSet_0_Port_Group_4_Register_PODC_4 */
  {
    /* usRegAddrOffset */
    0x0510,

    /* usInitModeRegVal */
    0x0000
  },

  /*  76 - ConfigSet_0_Port_Group_10_Register_PODC_10 */
  {
    /* usRegAddrOffset */
    0x0528,

    /* usInitModeRegVal */
    0x0000
  },

  /*  77 - ConfigSet_0_Port_Group_11_Register_PODC_11 */
  {
    /* usRegAddrOffset */
    0x052C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  78 - ConfigSet_0_Port_Group_12_Register_PODC_12 */
  {
    /* usRegAddrOffset */
    0x0530,

    /* usInitModeRegVal */
    0x0000
  },

  /*  79 - ConfigSet_0_Port_Group_21_Register_PODC_21 */
  {
    /* usRegAddrOffset */
    0x0554,

    /* usInitModeRegVal */
    0x0000
  },

  /*  80 - ConfigSet_0_Port_Group_25_Register_PODC_25 */
  {
    /* usRegAddrOffset */
    0x0564,

    /* usInitModeRegVal */
    0x0000
  },

  /*  81 - ConfigSet_0_Port_Group_27_Register_PODC_27 */
  {
    /* usRegAddrOffset */
    0x056C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  82 - ConfigSet_0_Port_Group_0_Register_PDSC_0 */
  {
    /* usRegAddrOffset */
    0x0600,

    /* usInitModeRegVal */
    0x0000
  },

  /*  83 - ConfigSet_0_Port_Group_1_Register_PDSC_1 */
  {
    /* usRegAddrOffset */
    0x0604,

    /* usInitModeRegVal */
    0x0000
  },

  /*  84 - ConfigSet_0_Port_Group_2_Register_PDSC_2 */
  {
    /* usRegAddrOffset */
    0x0608,

    /* usInitModeRegVal */
    0x0000
  },

  /*  85 - ConfigSet_0_Port_Group_3_Register_PDSC_3 */
  {
    /* usRegAddrOffset */
    0x060C,

    /* usInitModeRegVal */
    0x0000
  },

  /*  86 - ConfigSet_0_Port_Group_4_Register_PDSC_4 */
  {
    /* usRegAddrOffset */
    0x0610,

    /* usInitModeRegVal */
    0x0000
  },

  /*  87 - ConfigSet_0_Port_Group_25_Register_PDSC_25 */
  {
    /* usRegAddrOffset */
    0x0664,

    /* usInitModeRegVal */
    0x0000
  },

  /*  88 - ConfigSet_0_Port_Group_27_Register_PDSC_27 */
  {
    /* usRegAddrOffset */
    0x066C,

    /* usInitModeRegVal */
    0x0000
  }
};



/*
 * Array of structures of all function control port group registers, in the
 * sequence of PFCE, PFC and PMCSR.
 */
CONST(Tdd_Port_FuncCtrlRegs, PORT_CONST) Port_Num_FuncCtrlRegs[] =
{
  /*  0 - ConfigSet_0_Port_Group_0_PFCE_Register_0 */
  {
    /* usRegAddrOffset */
    0x0600,

    /* usInitModeRegVal */
    0x0002,

    /* usSetModeRegVal */
    0x0002
  },

  /*  1 - ConfigSet_0_Port_Group_1_PFCE_Register_1 */
  {
    /* usRegAddrOffset */
    0x0604,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  2 - ConfigSet_0_Port_Group_2_PFCE_Register_2 */
  {
    /* usRegAddrOffset */
    0x0608,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  3 - ConfigSet_0_Port_Group_3_PFCE_Register_3 */
  {
    /* usRegAddrOffset */
    0x060C,

    /* usInitModeRegVal */
    0x01A0,

    /* usSetModeRegVal */
    0x0000
  },

  /*  4 - ConfigSet_0_Port_Group_4_PFCE_Register_4 */
  {
    /* usRegAddrOffset */
    0x0610,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  5 - ConfigSet_0_Port_Group_21_PFCE_Register_21 */
  {
    /* usRegAddrOffset */
    0x0654,

    /* usInitModeRegVal */
    0x0150,

    /* usSetModeRegVal */
    0x0000
  },

  /*  6 - ConfigSet_0_Port_Group_25_PFCE_Register_25 */
  {
    /* usRegAddrOffset */
    0x0664,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  7 - ConfigSet_0_Port_Group_27_PFCE_Register_27 */
  {
    /* usRegAddrOffset */
    0x066C,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  8 - ConfigSet_0_Port_Group_0_PFC_Register_0 */
  {
    /* usRegAddrOffset */
    0x0500,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  9 - ConfigSet_0_Port_Group_1_PFC_Register_1 */
  {
    /* usRegAddrOffset */
    0x0504,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  10 - ConfigSet_0_Port_Group_2_PFC_Register_2 */
  {
    /* usRegAddrOffset */
    0x0508,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  11 - ConfigSet_0_Port_Group_3_PFC_Register_3 */
  {
    /* usRegAddrOffset */
    0x050C,

    /* usInitModeRegVal */
    0x01A0,

    /* usSetModeRegVal */
    0x0000
  },

  /*  12 - ConfigSet_0_Port_Group_4_PFC_Register_4 */
  {
    /* usRegAddrOffset */
    0x0510,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  13 - ConfigSet_0_Port_Group_21_PFC_Register_21 */
  {
    /* usRegAddrOffset */
    0x0554,

    /* usInitModeRegVal */
    0x0150,

    /* usSetModeRegVal */
    0x0000
  },

  /*  14 - ConfigSet_0_Port_Group_25_PFC_Register_25 */
  {
    /* usRegAddrOffset */
    0x0564,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  15 - ConfigSet_0_Port_Group_27_PFC_Register_27 */
  {
    /* usRegAddrOffset */
    0x056C,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  16 - ConfigSet_0_Port_Group_0_PMCSR_Register_0 */
  {
    /* usRegAddrOffset */
    0x0900,

    /* usInitModeRegVal */
    0x0372,

    /* usSetModeRegVal */
    0x0022
  },

  /*  17 - ConfigSet_0_Port_Group_1_PMCSR_Register_1 */
  {
    /* usRegAddrOffset */
    0x0904,

    /* usInitModeRegVal */
    0x0054,

    /* usSetModeRegVal */
    0x0000
  },

  /*  18 - ConfigSet_0_Port_Group_2_PMCSR_Register_2 */
  {
    /* usRegAddrOffset */
    0x0908,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  19 - ConfigSet_0_Port_Group_3_PMCSR_Register_3 */
  {
    /* usRegAddrOffset */
    0x090C,

    /* usInitModeRegVal */
    0x03FA,

    /* usSetModeRegVal */
    0x0000
  },

  /*  20 - ConfigSet_0_Port_Group_4_PMCSR_Register_4 */
  {
    /* usRegAddrOffset */
    0x0910,

    /* usInitModeRegVal */
    0x0A2D,

    /* usSetModeRegVal */
    0x0000
  },

  /*  21 - ConfigSet_0_Port_Group_10_PMCSR_Register_10 */
  {
    /* usRegAddrOffset */
    0x0928,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  22 - ConfigSet_0_Port_Group_12_PMCSR_Register_12 */
  {
    /* usRegAddrOffset */
    0x0930,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  23 - ConfigSet_0_Port_Group_21_PMCSR_Register_21 */
  {
    /* usRegAddrOffset */
    0x0954,

    /* usInitModeRegVal */
    0x0150,

    /* usSetModeRegVal */
    0x0000
  },

  /*  24 - ConfigSet_0_Port_Group_25_PMCSR_Register_25 */
  {
    /* usRegAddrOffset */
    0x0964,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  25 - ConfigSet_0_Port_Group_27_PMCSR_Register_27 */
  {
    /* usRegAddrOffset */
    0x096C,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  }
};



/* Array of structures for 32-Bit PMSR Registers*/
CONST(Tdd_Port_PMSRRegs, PORT_CONST) Port_Num_PMSRRegs[] =
{
  /*  0 - ConfigSet_0_Port_Group_0_PMSR0_0 */
  {
    /* ulMaskAndConfigValue */
    0xFFFFFA6F,

    /* usRegAddrOffset */
    0x0800,

    /* usInitModeRegVal */
    0xFA6F
  },

  /*  1 - ConfigSet_0_Port_Group_1_PMSR1_1 */
  {
    /* ulMaskAndConfigValue */
    0xFFFFE02A,

    /* usRegAddrOffset */
    0x0804,

    /* usInitModeRegVal */
    0xE02A
  },

  /*  2 - ConfigSet_0_Port_Group_2_PMSR2_2 */
  {
    /* ulMaskAndConfigValue */
    0xFFFF0007,

    /* usRegAddrOffset */
    0x0808,

    /* usInitModeRegVal */
    0x0007
  },

  /*  3 - ConfigSet_0_Port_Group_3_PMSR3_3 */
  {
    /* ulMaskAndConfigValue */
    0xFFFF0125,

    /* usRegAddrOffset */
    0x080C,

    /* usInitModeRegVal */
    0x0125
  },

  /*  4 - ConfigSet_0_Port_Group_4_PMSR4_4 */
  {
    /* ulMaskAndConfigValue */
    0xFFFF05D2,

    /* usRegAddrOffset */
    0x0810,

    /* usInitModeRegVal */
    0x05D2
  },

  /*  5 - ConfigSet_0_Port_Group_10_PMSR10_5 */
  {
    /* ulMaskAndConfigValue */
    0xFFFF5FC0,

    /* usRegAddrOffset */
    0x0828,

    /* usInitModeRegVal */
    0x5FC0
  },

  /*  6 - ConfigSet_0_Port_Group_11_PMSR11_6 */
  {
    /* ulMaskAndConfigValue */
    0xFFFF00FF,

    /* usRegAddrOffset */
    0x082C,

    /* usInitModeRegVal */
    0x00FF
  },

  /*  7 - ConfigSet_0_Port_Group_12_PMSR12_7 */
  {
    /* ulMaskAndConfigValue */
    0xFFFFFF50,

    /* usRegAddrOffset */
    0x0830,

    /* usInitModeRegVal */
    0xFF50
  },

  /*  8 - ConfigSet_0_Port_Group_21_PMSR21_8 */
  {
    /* ulMaskAndConfigValue */
    0xFFFF0EAC,

    /* usRegAddrOffset */
    0x0854,

    /* usInitModeRegVal */
    0x0EAC
  },

  /*  9 - ConfigSet_0_Port_Group_25_PMSR25_9 */
  {
    /* ulMaskAndConfigValue */
    0xFFFFFFFF,

    /* usRegAddrOffset */
    0x0864,

    /* usInitModeRegVal */
    0xFFFF
  },

  /*  10 - ConfigSet_0_Port_Group_27_PMSR27_10 */
  {
    /* ulMaskAndConfigValue */
    0xFFFF003F,

    /* usRegAddrOffset */
    0x086C,

    /* usInitModeRegVal */
    0x003F
  }
};




/*
 * Array of structures of all Alphabetic port group registers, except PMSR,
 * PFCE, PFC and PMCSR, in the sequence of PSR, PIS, PISE, PISA, PIBC, PIPC, PU,
 * PD, PBDC, PODC, PDSC, PUCC and PSBC.
 */
/* CONST(Tdd_Port_Regs, PORT_CONST) Port_Alpha_Regs[]; */

 /*
 * Array of structures of Alphabetic registers of all function control
 * port group registers, in the
 * sequence of PFCE, PFC and PMCSR.
 */
/* CONST(Tdd_Port_FuncCtrlRegs, PORT_CONST) Port_Alpha_FuncCtrlRegs[];*/

/* Array of structures for 32-Bit PMSR Registers */
/* CONST(Tdd_Port_PMSRRegs, PORT_CONST) Port_Alpha_PMSRRegs[]; */

/*
 * Array of structures of all JTAG port group registers, except PMSR,
 * PFCE, PFC and PMCSR, in the sequence of PSR, PIS, PISE, PISA, PIBC, PIPC, PU,
 * PD, PBDC, PODC, PDSC, PUCC and PSBC.
 */
CONST(Tdd_Port_Regs, PORT_CONST) Port_JTAG_Regs[] =
{
  /*  0 - ConfigSet_0_Port_Group_0_Register_JPSR_0 */
  {
    /* usRegAddrOffset */
    0x0010,

    /* usInitModeRegVal */
    0x0000
  },

  /*  1 - ConfigSet_0_Port_Group_0_Register_JPIS_0 */
  {
    /* usRegAddrOffset */
    0x0070,

    /* usInitModeRegVal */
    0x0000
  },

  /*  2 - ConfigSet_0_Port_Group_0_Register_JPISE_0 */
  {
    /* usRegAddrOffset */
    0x0080,

    /* usInitModeRegVal */
    0x0000
  },

  /*  3 - ConfigSet_0_Port_Group_0_Register_JPIBC_0 */
  {
    /* usRegAddrOffset */
    0x0000,

    /* usInitModeRegVal */
    0x0000
  },

  /*  4 - ConfigSet_0_Port_Group_0_Register_JPU_0 */
  {
    /* usRegAddrOffset */
    0x0030,

    /* usInitModeRegVal */
    0x0000
  },

  /*  5 - ConfigSet_0_Port_Group_0_Register_JPD_0 */
  {
    /* usRegAddrOffset */
    0x0040,

    /* usInitModeRegVal */
    0x0000
  },

  /*  6 - ConfigSet_0_Port_Group_0_Register_JPBDC_0 */
  {
    /* usRegAddrOffset */
    0x0010,

    /* usInitModeRegVal */
    0x0000
  },

  /*  7 - ConfigSet_0_Port_Group_0_Register_JPODC_0 */
  {
    /* usRegAddrOffset */
    0x0050,

    /* usInitModeRegVal */
    0x0000
  },

  /*  8 - ConfigSet_0_Port_Group_0_Register_JPDSC_0 */
  {
    /* usRegAddrOffset */
    0x0060,

    /* usInitModeRegVal */
    0x0000
  }
};



/*
 * Array of structures of all function control port group registers, in the
 * sequence of PFCE, PFC and PMCSR.
 */
CONST(Tdd_Port_FuncCtrlRegs, PORT_CONST) Port_JTAG_FuncCtrlRegs[] =
{
  /*  0 - ConfigSet_0_Port_Group_0_JPFC_Register_0 */
  {
    /* usRegAddrOffset */
    0x0050,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  },

  /*  1 - ConfigSet_0_Port_Group_0_JPMCSR_Register_0 */
  {
    /* usRegAddrOffset */
    0x0090,

    /* usInitModeRegVal */
    0x0000,

    /* usSetModeRegVal */
    0x0000
  }
};



/* Array of structures for 32-Bit PMSR Registers */
CONST(Tdd_Port_PMSRRegs, PORT_CONST) Port_JTAG_PMSRRegs[] =
{
  /*  0 - ConfigSet_0_Port_Group_0_JPMSR0_0 */
  {
    /* ulMaskAndConfigValue */
    0xFFFF003C,

    /* usRegAddrOffset */
    0x0080,

    /* usInitModeRegVal */
    0x003C
  }
};



/*
 * Array provides information of port groups which contain run time mode
 * changeable port pins.
 */
/* CONST(Tdd_Port_PinModeChangeableGroups, PORT_CONST) \
                                              Port_GstSetModeGroupsList[]; */

/*
 * Array contains details of port pins, whose mode can be changed during run
 * time.
 */
/* CONST(Tdd_Port_PinModeChangeableDetails, PORT_CONST) \
                                          Port_GstSetModePinDetailsList[]; */

/*
 * Array contains list of port pins whose direction can be changed during
 * run time.
 */
/* CONST(Tdd_Port_PinsDirChangeable, PORT_CONST) \
                                           Port_GstPinDirChangeableList[]; */

/* Array of structures for Digital Filter registers */
/* CONST(Tdd_Port_DNFARegs, PORT_CONST) Port_DNFARegs[]; */

/* Array for Analog Filter registers */
/* CONST(Tdd_Port_FCLARegs, PORT_CONST) Port_FCLARegs[]; */

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

