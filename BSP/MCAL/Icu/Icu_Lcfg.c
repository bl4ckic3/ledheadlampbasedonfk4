/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu_Lcfg.c                                                  */
/* Version      = 3.0.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Link time parameters.                                   */
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
 * TOOL VERSION:    3.0.13a
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

#include "Icu_LTTypes.h"
#include "Icu_Cbk.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define ICU_LCFG_C_AR_MAJOR_VERSION  3
#define ICU_LCFG_C_AR_MINOR_VERSION  0
#define ICU_LCFG_C_AR_PATCH_VERSION  0

/* File version information */
#define ICU_LCFG_C_SW_MAJOR_VERSION  3
#define ICU_LCFG_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/* Specification Major Version Check */
#if (ICU_LTTYPES_AR_MAJOR_VERSION != ICU_LCFG_C_AR_MAJOR_VERSION)
  #error "Icu_Lcfg.c : Mismatch in Specification Major version"
#endif

/* Specification Minor Version Check */
#if (ICU_LTTYPES_AR_MINOR_VERSION != ICU_LCFG_C_AR_MINOR_VERSION)
  #error "Icu_Lcfg.c : Mismatch in Specification Minor version"
#endif

/* Specification Patch Version Check */
#if (ICU_LTTYPES_AR_PATCH_VERSION != ICU_LCFG_C_AR_PATCH_VERSION)
  #error "Icu_Lcfg.c : Mismatch in Specification Patch version"
#endif

/* Major version check */
#if (ICU_LTTYPES_SW_MAJOR_VERSION != ICU_LCFG_C_SW_MAJOR_VERSION)
  #error "Icu_Lcfg.c : Mismatch in Major version"
#endif

/* Minor version check */
#if (ICU_LTTYPES_SW_MINOR_VERSION != ICU_LCFG_C_SW_MINOR_VERSION)
  #error "Icu_Lcfg.c : Mismatch in Minor version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define ICU_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* ICU Channel Callback function Configuration */
CONST(Tdd_Icu_ChannelFuncType, ICU_CONST) Icu_GstChannelFunc[] =
{
  /* index: 0 */
  {
    /* *pIcuNotificationPointer */
    &INTP3_Notification
  }
};



#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
