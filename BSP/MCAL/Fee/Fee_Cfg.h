/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Fee_Cfg.h                                                   */
/* Version      = 3.0.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
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
/******************************************************************************/

/*******************************************************************************
**                    FEE Component Generation Tool Version                   **
*******************************************************************************/
/*
 * TOOL VERSION:  3.0.6a
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    FK4_4010_FEE_V304_130924_NEWCLEAPLUS.arxml
 * GENERATED ON:  26 Sep 2013 - 09:00:16
 */

#ifndef FEE_CFG_H
#define FEE_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "MemIf_Types.h"



/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*
 * AUTOSAR specification version information
 */
#define FEE_CFG_AR_MAJOR_VERSION  1
#define FEE_CFG_AR_MINOR_VERSION  2
#define FEE_CFG_AR_PATCH_VERSION  0
/*
 * File version information
 */
#define FEE_CFG_SW_MAJOR_VERSION          3
#define FEE_CFG_SW_MINOR_VERSION          0

/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define FEE_AR_MAJOR_VERSION_VALUE        1
#define FEE_AR_MINOR_VERSION_VALUE        2
#define FEE_AR_PATCH_VERSION_VALUE        0

#define FEE_SW_MAJOR_VERSION_VALUE        3
#define FEE_SW_MINOR_VERSION_VALUE        0
#define FEE_SW_PATCH_VERSION_VALUE        0

#define FEE_VENDOR_ID_VALUE               (uint16)23
#define FEE_MODULE_ID_VALUE               (uint16)21


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* This defines the instance ID of the module */
#define FEE_INSTANCE_ID_VALUE               (uint8)0

/* To enable / disable development error detection */
#define FEE_DEV_ERROR_DETECT                STD_OFF

/* To enable / disable the Fee_GetVersionInfo API */
#define FEE_VERSION_INFO_API                STD_ON

/* Macro enabled when the upper layer notifications are configured */
#define FEE_UPPER_LAYER_NOTIFICATION        STD_OFF

/* To enable / disable automatic formatting of flash */
#define FEE_AUTO_FORMAT_FLASH               STD_ON

/* Macro enabled when notifications are configured or Dataset selection bits is 
   not configured */
#define FEE_NVM_CBK_PRESENT                 STD_OFF

/* To enable / disable FEE_Init function */
#define FEE_STARTUP_INTERNAL                STD_OFF

/* To enable / disable the Read and Write function with or without limitation */
#define FEE_STARTUP_LIMITED_ACCESS          STD_OFF

/* Enable/disable the Critical section protection */
#define FEE_CRITICAL_SECTION_PROTECTION     STD_OFF



/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/
/* Following option should be used to define the size in bytes to which logical
   blocks shall be aligned */
#define FEE_VIRTUAL_PAGE_SIZE               (uint16)0x0004

/* Defines the number of Blocks configured */
#define FEE_NUM_BLOCKS                      0x04


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* FEE_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

