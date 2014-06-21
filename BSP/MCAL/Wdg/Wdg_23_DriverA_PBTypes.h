/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Wdg_23_DriverA_PBTypes.h                                    */
/* Version      = 3.0.2a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post Build time Parameters      */
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
 * V3.0.0:   12-Jun-2009 : Initial version
 *
 * V3.0.1:   14-Jul-2009 : As per SCR 015, compiler version is changed from 
 *                         V5.0.5 to V5.1.6c in the header of the file.
 *
 * V3.0.2:   06-Mar-2010 : As per SCR 219, the macros WDG_FALSE and WDG_TRUE
 *                         are added.
 * V3.0.2a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef WDG_23_DRIVERA_PBTYPES_H
#define WDG_23_DRIVERA_PBTYPES_H
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Wdg_23_DriverA.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define WDG_23_DRIVERA_PBTYPES_AR_MAJOR_VERSION    2 
#define WDG_23_DRIVERA_PBTYPES_AR_MINOR_VERSION    2
#define WDG_23_DRIVERA_PBTYPES_AR_PATCH_VERSION    0

/* File version information */
#define WDG_23_DRIVERA_PBTYPES_SW_MAJOR_VERSION    3
#define WDG_23_DRIVERA_PBTYPES_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Type definition for trigger mode */
#define WDG_WINDOW  1

/* General defines */
#define WDG_23_DRIVERA_DBTOC_VALUE \
                            ((WDG_23_DRIVERA_VENDOR_ID_VALUE << 22) | \
                            (WDG_23_DRIVERA_MODULE_ID_VALUE << 14) | \
                            (WDG_23_DRIVERA_SW_MAJOR_VERSION_VALUE << 8) | \
                            (WDG_23_DRIVERA_SW_MINOR_VERSION_VALUE << 3))

/* Value to be written to WDTAWDTE / WDTAEVAC register for stopping the 
watchdog timer */
#define WDG_23_DRIVERA_STOP                (uint8)0x2C

/* Value to be written to WDTAWDTE / WDTAEVAC register to clear and restart 
the timer */
#define WDG_23_DRIVERA_RESTART             (uint8)0xAC

#define WDG_FALSE                           (boolean)0x00
#define WDG_TRUE                            (boolean)0x01

#if(WDG_23_DRIVERA_DEV_ERROR_DETECT == STD_ON)

/* Type defintion for the current state of Watchdog Driver */
typedef enum
{
  WDG_UNINIT = 0,
  WDG_IDLE,
  WDG_BUSY
}Wdg_23_DriverA_StatusType;

#endif /* WDG_23_DRIVERA_DEV_ERROR_DETECT == STD_ON */ 

#endif /* WDG_23_DRIVERA_PBTYPES_H */

/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/

