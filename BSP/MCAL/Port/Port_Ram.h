/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Port_Ram.h                                                  */
/* Version      = 3.1.4                                                       */
/* Date         = 10-Jul-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the extern declarations of global RAM variables of PORT */
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
 *
 * V3.0.1:  27-Aug-2011  : As per SCR 502, Copyright Information is changed.
 * V3.0.2:  05-Jan-2012  : As part of Improvement fix,following changes are
 *                         made:
 *                        1.Version check for SW major version and minor
 *                          version added.
 * V3.1.2:  16-Feb-2012  :  Merged the fixes done for Fx4L.
 * V3.1.3:  06-Jun-2012  : As per SCR 033, File version is changed.
 * V3.1.4:  10-Jul-2012  : As per SCR 047, File version is changed.
 */
/******************************************************************************/

#ifndef PORT_RAM_H
#define PORT_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Port.h"
#include "Port_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_RAM_AR_MAJOR_VERSION    PORT_AR_MAJOR_VERSION_VALUE
#define PORT_RAM_AR_MINOR_VERSION    PORT_AR_MINOR_VERSION_VALUE
#define PORT_RAM_AR_PATCH_VERSION    PORT_AR_PATCH_VERSION_VALUE

/* File version information */
#define PORT_RAM_SW_MAJOR_VERSION   3
#define PORT_RAM_SW_MINOR_VERSION   1
#define PORT_RAM_SW_PATCH_VERSION   4

#if (PORT_SW_MAJOR_VERSION   != PORT_RAM_SW_MAJOR_VERSION )
#error "Software major version of Port_Ram.h and Port.h did not match!"
#endif
#if ( PORT_SW_MINOR_VERSION!= PORT_RAM_SW_MINOR_VERSION)
#error "Software minor version of Port_Ram.h and Port.h did not match!"
#endif


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define PORT_START_SEC_VAR_1BIT
#include "MemMap.h"

/* Global variable to store Initialization status of Port Driver Component */
extern VAR (boolean, PORT_INIT_DATA) Port_GblDriverStatus;

#define PORT_STOP_SEC_VAR_1BIT
#include "MemMap.h"

#define PORT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store pointer to Configuration */
extern P2CONST(Port_ConfigType, PORT_CONST, PORT_CONFIG_CONST)Port_GpConfigPtr;

#define PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PORT_RAM_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
