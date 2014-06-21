/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Wdg_23_DriverA_Version.h                                    */
/* Version      = 3.0.1a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking versions of modules        */
/* included by Watchdog Driver                                                */
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
 * V3.0.0:  12-Jun-2009  : Initial Version
 * V3.0.1:  14-Jul-2009  : As per SCR 015, compiler version is changed from 
 *                         V5.0.5 to V5.1.6c in the header of the file.
 * V3.0.1a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef WDG_23_DRIVERA_VERSION_H
#define WDG_23_DRIVERA_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Wdg_23_DriverA.h"

#if (WDG_23_DRIVERA_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#include "Dem.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* Autosar Specification Version */
#define WDG_23_DRIVERA_VERSION_AR_MAJOR_VERSION \
                                           WDG_23_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_23_DRIVERA_VERSION_AR_MINOR_VERSION \
                                           WDG_23_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_23_DRIVERA_VERSION_AR_PATCH_VERSION \
                                           WDG_23_DRIVERA_AR_PATCH_VERSION_VALUE

/* File Version Information */

#define WDG_23_DRIVERA_VERSION_SW_MAJOR_VERSION  3
#define WDG_23_DRIVERA_VERSION_SW_MINOR_VERSION  0

/* Included Files Autosar Specification Version */

#if (WDG_23_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#define WDG_23_DRIVERA_DET_AR_MAJOR_VERSION  2
#define WDG_23_DRIVERA_DET_AR_MINOR_VERSION  2

#endif

#define WDG_23_DRIVERA_DEM_AR_MAJOR_VERSION  2
#define WDG_23_DRIVERA_DEM_AR_MINOR_VERSION  2

#endif /* WDG_23_DRIVERA_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

