/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Dio_Version.c                                               */
/* Version      = 3.1.2                                                       */
/* Date         = 05-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking of modules included by DIO    */
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
/* or implied,including but not limited to those for non-infringement of      */
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
 * V3.0.0:  04-Sep-2009  : Initial Version
 * 
 * V3.0.1:  31-Mar-2010  : As per SCR 238, new line added at the end of file.
 * V3.1.0:  27-Jul-2011  : Updated software version to 3.1.0 .
 * V3.1.1:  10-feb-2012  : Merged the fixes done to Fx4L Dio driver.
 * V3.1.2:  05-Jun-2012  : As per SCR 027, following changes are made:
 *                         1. File version is changed.
 *                         2. Compiler version is removed from Environment
 *                            section.
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dio_Version.h"
#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define DIO_VERSION_C_AR_MAJOR_VERSION    DIO_AR_MAJOR_VERSION_VALUE
#define DIO_VERSION_C_AR_MINOR_VERSION    DIO_AR_MINOR_VERSION_VALUE
#define DIO_VERSION_C_AR_PATCH_VERSION    DIO_AR_PATCH_VERSION_VALUE

/* File version information */
#define DIO_VERSION_C_SW_MAJOR_VERSION    3
#define DIO_VERSION_C_SW_MINOR_VERSION    1
#define DIO_VERSION_C_SW_PATCH_VERSION    2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/* Dio Version Check */
#if (DIO_VERSION_AR_MAJOR_VERSION != DIO_VERSION_C_AR_MAJOR_VERSION)
  #error "Dio_Version.c : Mismatch in Specification Major Version"
#endif

#if (DIO_VERSION_AR_MINOR_VERSION != DIO_VERSION_C_AR_MINOR_VERSION)
  #error "Dio_Version.c : Mismatch in Specification Minor Version"
#endif

#if (DIO_VERSION_AR_PATCH_VERSION != DIO_VERSION_C_AR_PATCH_VERSION)
  #error "Dio_Version.c : Mismatch in Specification Patch Version"
#endif

#if (DIO_SW_MAJOR_VERSION != DIO_VERSION_C_SW_MAJOR_VERSION)
  #error "Dio_Version.c : Mismatch in Major Version"
#endif

#if (DIO_SW_MINOR_VERSION != DIO_VERSION_C_SW_MINOR_VERSION)
  #error "Dio_Version.c : Mismatch in Minor Version"
#endif

/* Det Module Version Check */
#if (DIO_DEV_ERROR_DETECT == STD_ON)
#if (DET_AR_MAJOR_VERSION != DIO_DET_AR_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif

#if (DET_AR_MINOR_VERSION != DIO_DET_AR_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
