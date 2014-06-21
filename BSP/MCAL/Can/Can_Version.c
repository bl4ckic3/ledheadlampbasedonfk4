/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_Version.c                                               */
/* Version      = 3.0.1a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Version Information.                                          */
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
 * V3.0.0:  12.12.2008  : Initial Version
 * V3.0.1:  21.10.2009  : Updated compiler version as per
 *                        SCR ANMCANLINFR3_SCR_031.
 * V3.0.1a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can.h"              /* CAN Driver Header File */
#if(CAN_WAKEUP_SUPPORT == STD_ON)
#include "EcuM.h"             /* ECUM Header File */
#endif
#include "Can_Version.h"      /* CAN Version Header File */
#include "Dem.h"              /* DEM Header File */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"              /* DET Header File */
#endif
#include "SchM.h"             /* Scheduler Header File */
#include "CanIf.h"            /* CANIF Header File */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_VERSION_C_AR_MAJOR_VERSION  2
#define CAN_VERSION_C_AR_MINOR_VERSION  2
#define CAN_VERSION_C_AR_PATCH_VERSION  2

/* File version information */
#define CAN_VERSION_C_SW_MAJOR_VERSION  3
#define CAN_VERSION_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CAN_VERSION_AR_MAJOR_VERSION != CAN_VERSION_C_AR_MAJOR_VERSION)
  #error "Can_Version.c : Mismatch in Specification Major Version"
#endif

#if (CAN_VERSION_AR_MINOR_VERSION != CAN_VERSION_C_AR_MINOR_VERSION)
  #error "Can_Version.c : Mismatch in Specification Minor Version"
#endif

#if (CAN_VERSION_AR_PATCH_VERSION != CAN_VERSION_C_AR_PATCH_VERSION)
  #error "Can_Version.c : Mismatch in Specification Patch Version"
#endif

#if (CAN_VERSION_SW_MAJOR_VERSION != CAN_VERSION_C_SW_MAJOR_VERSION)
  #error "Can_Version.c : Mismatch in Major Version"
#endif

#if (CAN_VERSION_SW_MINOR_VERSION != CAN_VERSION_C_SW_MINOR_VERSION)
  #error "Can_Version.c : Mismatch in Minor Version"
#endif

#if (CANIF_AR_MAJOR_VERSION != CAN_CANIF_AR_MAJOR_VERSION)
  #error "CanIf.h : Mismatch in Specification Major Version"
#endif

#if (CANIF_AR_MINOR_VERSION != CAN_CANIF_AR_MINOR_VERSION)
  #error "CanIf.h : Mismatch in Specification Minor Version"
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
#if (DET_AR_MAJOR_VERSION != CAN_DET_AR_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif

#if (DET_AR_MINOR_VERSION != CAN_DET_AR_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif

#if (DEM_AR_MAJOR_VERSION != CAN_DEM_AR_MAJOR_VERSION)
  #error "Dem.h : Mismatch in Specification Major Version"
#endif

#if (DEM_AR_MINOR_VERSION != CAN_DEM_AR_MINOR_VERSION)
  #error "Dem.h : Mismatch in Specification Minor Version"
#endif

#if (SCHM_AR_MAJOR_VERSION != CAN_SCHM_AR_MAJOR_VERSION)
  #error "SchM.h : Mismatch in Specification Major Version"
#endif

#if (SCHM_AR_MINOR_VERSION != CAN_SCHM_AR_MINOR_VERSION)
  #error "SchM.h : Mismatch in Specification Minor Version"
#endif

#if(CAN_WAKEUP_SUPPORT == STD_ON)
#if (ECUM_AR_MAJOR_VERSION != CAN_ECUM_AR_MAJOR_VERSION)
  #error "EcuM.h : Mismatch in Specification Major Version"
#endif

#if (ECUM_AR_MINOR_VERSION != CAN_ECUM_AR_MINOR_VERSION)
  #error "Ecum_Cbk.h : Mismatch in Specification Minor Version"
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
