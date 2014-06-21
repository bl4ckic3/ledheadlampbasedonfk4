/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Dem_IntErrId.h                                              */
/* Version      = 3.0.5                                                       */
/* Date         = 08-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file is a stub for DEM component                  .                   */
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
 * V3.0.0:  05-Aug-2009  : Initial Version
 *
 * V3.0.1:  13-Apr-2010  : MCU_E_BURAM_WRITE_FAILURE macro added
 *                         MCU_E_POWER_DOWN_MODE_FAILURE macro added
 *
 * V3.0.2:  03-Jan-2011  : FLS_E_COMPARE_FAILED macro added
 *
 * V3.0.3:  17-Jun-2011  : FEE_E_READ_FAILED and FEE_E_WRITE_FAILED 
 *                         macros are added
 *
 * V3.0.3a:  01-Aug-2011 : FLS_E_SET_FREQUENCY_FAILED macro is added
 *
 * V3.0.4: 29-Sep-2011   : PWM_E_REWRITE_FAILED macro added.
 *                         SPI_E_TIMEOUT is added.
 *                         Copyright is updated.
 *
 * V3.0.5:  08-Jun-2012  : 1. Copyright Information is changed.
 *                         2. Compiler version is removed from Environment
 *                            section.

 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
#ifndef DEM_INTERRID_H
#define DEM_INTERRID_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define DEM_INTERRID_AR_MAJOR_VERSION         2
#define DEM_INTERRID_AR_MINOR_VERSION         2
#define DEM_INTERRID_AR_PATCH_VERSION         1

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define FR_E_ACCESS              (uint8)0x0B

#define CANIF_E_INVALID_TXPDUID  (uint8)0x28
#define CANIF_E_INVALID_RXPDUID  (uint8)0x32 
#define CANIF_E_FULL_TX_BUFFER   (uint8)0x3C
#define CANIF_E_STOPPED          (uint8)0x46
#define CAN_E_TIMEOUT            (uint8)0x50
#define WDG_23_DRIVERA_E_DISABLE_REJECTED            (uint8)0x60
#define WDG_23_DRIVERA_E_MODE_SWITCH_FAILED          (uint8)0x70
#define WDG_23_DRVA_E_MODE_SWITCH_FAILED       50
#define WDG_23_DRVA_E_DISABLE_REJECTED         60

#define WDG_23_DRVB_E_MODE_SWITCH_FAILED       50
#define WDG_23_DRVB_E_DISABLE_REJECTED         60

#define MCU_E_CLOCK_FAILURE              (uint8)40
#define MCU_E_WRITE_FAILURE              (uint8)50
#define MCU_E_BURAM_WRITE_FAILURE        (uint8)60
#define MCU_E_POWER_DOWN_MODE_FAILURE    (uint8)70    

#define PWM_E_REWRITE_FAILED        40

#define PORT_E_WRITE_FAILURE  (uint8)41

#define SPI_E_SEQ_FAILED  34
#define SPI_E_TIMEOUT     35

#define FLS_E_ERASE_FAILED   31
#define FLS_E_WRITE_FAILED   30
#define FLS_E_READ_FAILED    33
#define FLS_E_COMPARE_FAILED 34
#define FLS_E_SET_FREQUENCY_FAILED 35

#define FEE_E_WRITE_FAILED   30
#define FEE_E_READ_FAILED    33
#define FEE_FORMAT_FAILED    34
#define FEE_E_STARTUP_FAILED 35


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* DEM_INTERRRID_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
