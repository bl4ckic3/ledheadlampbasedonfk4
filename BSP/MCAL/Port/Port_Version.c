/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Port_Version.c                                              */
/* Version      = 3.1.3                                                       */
/* Date         = 06-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for modules included by PORT  */
/* Driver                                                                     */
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
 * V3.0.0:  27-Jul-2009  : Initial Version
 * V3.1.0:  26-Jul-2011  : Initial Version DK4 variant
 * V3.1.1:  15-Sep-2011  : As per the DK-4H requirements
 *                         1. Added DK4-H specific JTAG information.
 *                         2. Added compiler switch for USE_UPD70F3529 device
 *                            name.
 * V3.1.2:  16-Feb-2012  : Merged the fixes done for Fx4L.
 * V3.1.3:  06-Jun-2012  : As per SCR 033, Compiler version is removed from
 *                         Environment section.
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Port_Version.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_VERSION_C_AR_MAJOR_VERSION    PORT_AR_MAJOR_VERSION_VALUE
#define PORT_VERSION_C_AR_MINOR_VERSION    PORT_AR_MINOR_VERSION_VALUE
#define PORT_VERSION_C_AR_PATCH_VERSION    PORT_AR_PATCH_VERSION_VALUE

/* File version information */
#define PORT_VERSION_C_SW_MAJOR_VERSION    3
#define PORT_VERSION_C_SW_MINOR_VERSION    1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PORT_VERSION_AR_MAJOR_VERSION != PORT_VERSION_C_AR_MAJOR_VERSION)
  #error "Port_Version.c : Mismatch in Specification Major Version"
#endif
#if (PORT_VERSION_AR_MINOR_VERSION != PORT_VERSION_C_AR_MINOR_VERSION)
  #error "Port_Version.c : Mismatch in Specification Minor Version"
#endif
#if (PORT_VERSION_AR_PATCH_VERSION != PORT_VERSION_C_AR_PATCH_VERSION)
  #error "Port_Version.c : Mismatch in Specification Patch Version"
#endif

#if (PORT_SW_MAJOR_VERSION != PORT_VERSION_C_SW_MAJOR_VERSION)
  #error "Port_Version.c : Mismatch in Major Version"
#endif
#if (PORT_SW_MINOR_VERSION!= PORT_VERSION_C_SW_MINOR_VERSION)
  #error "Port_Version.c : Mismatch in Minor Version"
#endif

#if(PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
#if (SCHM_AR_MAJOR_VERSION != PORT_SCHM_AR_MAJOR_VERSION)
  #error "SchM.h : Mismatch in Specification Major Version"
#endif
#if (SCHM_AR_MINOR_VERSION != PORT_SCHM_AR_MINOR_VERSION)
  #error "SchM.h : Mismatch in Specification Minor Version"
#endif
#endif

#if (PORT_DEV_ERROR_DETECT == STD_ON)
#if (DET_AR_MAJOR_VERSION != PORT_DET_AR_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif
#if (DET_AR_MINOR_VERSION != PORT_DET_AR_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
