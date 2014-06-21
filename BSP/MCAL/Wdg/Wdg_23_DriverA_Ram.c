/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Wdg_23_DriverA_Ram.c                                        */
/* Version      = 3.0.1a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Watchdog Driver                        */
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
 * V3.0.0:  12-Jun-2009   : Initial Version
 * V3.0.1:  14-Jul-2009   : As per SCR 015, compiler version is changed from 
 *                          V5.0.5 to V5.1.6c in the header of the file.
 * V3.0.1a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Wdg_23_DriverA_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* Autosar Specification Version information */
#define WDG_23_DRIVERA_RAM_C_AR_MAJOR_VERSION  \
                                         WDG_23_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_23_DRIVERA_RAM_C_AR_MINOR_VERSION  \
                                         WDG_23_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_23_DRIVERA_RAM_C_AR_PATCH_VERSION  \
                                         WDG_23_DRIVERA_AR_PATCH_VERSION_VALUE

/* File version information */
#define WDG_23_DRIVERA_RAM_C_SW_MAJOR_VERSION  3
#define WDG_23_DRIVERA_RAM_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (WDG_23_DRIVERA_RAM_AR_MAJOR_VERSION != \
                          WDG_23_DRIVERA_RAM_C_AR_MAJOR_VERSION)
  #error "WDG_23_DriverA_Ram.c : Mismatch in Specification Major Version"
#endif
#if (WDG_23_DRIVERA_RAM_AR_MINOR_VERSION != \
                          WDG_23_DRIVERA_RAM_C_AR_MINOR_VERSION)
  #error "WDG_23_DriverA_Ram.c : Mismatch in Specification Minor Version"
#endif
#if (WDG_23_DRIVERA_RAM_AR_PATCH_VERSION != \
                          WDG_23_DRIVERA_RAM_C_AR_PATCH_VERSION)
  #error "WDG_23_DriverA_Ram.c : Mismatch in Specification Patch Version"
#endif

#if (WDG_23_DRIVERA_RAM_SW_MAJOR_VERSION != \
                          WDG_23_DRIVERA_RAM_C_SW_MAJOR_VERSION)
   #error "WDG_23_DriverA_Ram.c : Mismatch in Major Version"
#endif
#if (WDG_23_DRIVERA_RAM_SW_MINOR_VERSION != \
                          WDG_23_DRIVERA_RAM_C_SW_MINOR_VERSION)
   #error "WDG_23_DriverA_Ram.c : Mismatch in Minor Version"
#endif

/******************************************************************************
**                      Global Data Types                                    **
******************************************************************************/

#if (WDG_23_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#define WDG_23_DRIVERA_START_SEC_VAR_UNSPECIFIED 
#include "MemMap.h"

/* Global variable to store the current watchdog driver state */
VAR(Wdg_23_DriverA_StatusType, WDG_23_DRIVERA_INIT_DATA) 
                                                Wdg_GddDriverState = WDG_UNINIT;

#define WDG_23_DRIVERA_STOP_SEC_VAR_UNSPECIFIED 
#include "MemMap.h"

#endif

#define WDG_23_DRIVERA_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

/* Global variable to store the current watchdog driver mode */
VAR(WdgIf_ModeType, WDG_23_DRIVERA_NOINIT_DATA) Wdg_GddCurrentMode;

/* Global database pointer */
P2CONST(Wdg_23_DriverA_ConfigType, AUTOMATIC, 
              WDG_23_DRIVERA_CONFIG_CONST)Wdg_23_DriverA_GpConfigPtr;

#define WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
