/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Wdg_23_DriverA_PBcfg.c                                      */
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
 *  V3.0.0:              : Initial version
 */
/******************************************************************************/
 
/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  3.0.8a
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    FK4_4010_WDGA_V304_120319.arxml
 * GENERATED ON:  19 Mar 2012 - 13:36:07
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Wdg_23_DriverA_PBTypes.h" 
#include "Wdg_23_DriverA.h"
/*******************************************************************************
**                     Version Information                                    **
*******************************************************************************/

/* AUTOSAR specification version information */
#define WDG_23_DRIVERA_PBCFG_C_AR_MAJOR_VERSION    2
#define WDG_23_DRIVERA_PBCFG_C_AR_MINOR_VERSION    2
#define WDG_23_DRIVERA_PBCFG_C_AR_PATCH_VERSION    0

/* File version information */
#define WDG_23_DRIVERA_PBCFG_C_SW_MAJOR_VERSION    3 
#define WDG_23_DRIVERA_PBCFG_C_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_23_DRIVERA_PBTYPES_AR_MAJOR_VERSION != \
                                  WDG_23_DRIVERA_PBCFG_C_AR_MAJOR_VERSION)
  #error "Wdg_23_DriverA_PBcfg.c : Mismatch in Specification Major Version"
#endif

#if (WDG_23_DRIVERA_PBTYPES_AR_MINOR_VERSION != \
                                  WDG_23_DRIVERA_PBCFG_C_AR_MINOR_VERSION)
  #error "Wdg_23_DriverA_PBcfg.c : Mismatch in Specification Minor Version"
#endif

#if (WDG_23_DRIVERA_PBTYPES_AR_PATCH_VERSION != \
                                  WDG_23_DRIVERA_PBCFG_C_AR_PATCH_VERSION)
  #error "Wdg_23_DriverA_PBcfg.c : Mismatch in Specification Patch Version"
#endif

#if (WDG_23_DRIVERA_PBTYPES_SW_MAJOR_VERSION != \
                                  WDG_23_DRIVERA_PBCFG_C_SW_MAJOR_VERSION)
  #error "Wdg_23_DriverA_PBcfg.c : Mismatch in Major Version"
#endif

#if (WDG_23_DRIVERA_PBTYPES_SW_MINOR_VERSION != \
                                  WDG_23_DRIVERA_PBCFG_C_SW_MINOR_VERSION) 
  #error "Wdg_23_DriverA_PBcfg.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define WDG_23_DRIVERA_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for Watchdog Driver Init configuration */
CONST(Wdg_23_DriverA_ConfigType,WDG_23_DRIVERA_CONFIG_CONST)\
Wdg_23_DriverA_GstConfiguration[] =
{
  /* Configuration 0 - 1 */
  {
    /* ulStartOfDbToc */
    0x05D98300,

    /* ucWdtamdSlowValue */
    0x77,

    /* ucWdtamdFastValue */
    0x07,

    /* ucWdtamdDefaultValue */
    0x77,

    /* ucWdtamdDefaultModeValue */
    WDGIF_SLOW_MODE
  }
};


#define WDG_23_DRIVERA_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
