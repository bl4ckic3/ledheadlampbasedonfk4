/*============================================================================*/
/* Project      = AUTOSAR NEC MCAL Components                                 */
/* Module       = SchM_Spi.h                                                  */
/* Version      = 3.0.1                                                       */
/* Date         = 18.06.2009                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008 by NEC Electronics (Europe) GmbH,                       */
/*               a company of the NEC Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file is a stub for SchM Component                                     */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* NEC Electronics (Europe) GmbH the following shall apply!                   */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by NEC. Any warranty   */
/* is expressly disclaimed and excluded by NEC, either expressed or implied,  */
/* including but not limited to those for non-infringement of intellectual    */
/* property, merchantability and/or fitness for the particular purpose.       */
/*                                                                            */
/* NEC shall not have any obligation to maintain, service or provide bug      */
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
/* In no event shall NEC be liable to the User for any incidental,            */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. NEC shall not be liable for any services or products         */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by NEC in connection with the Product(s) and/or the   */
/* Application.                                                               */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        V850E/PH03                                    */
/*              Compiler:       GHS V4.2.3                                    */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:  22.08.2008   : Initial Version
 * V3.0.1:  18.06.2009   : As per SCR 145, comments for #endif and 
 *                         schM enter and exit macros are added. 
 */
/******************************************************************************/
#ifndef SCHM_SPI_H
#define SCHM_SPI_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*Exclusive area handling */
#define SchM_Enter_Spi(ExclusiveArea) SchM_Enter_Spi_## ExclusiveArea 
#define SchM_Exit_Spi(ExclusiveArea) SchM_Exit_Spi_## ExclusiveArea

#define SchM_Enter_Spi_SPI_CHIP_SELECT_PROTECTION           __asm("di")
#define SchM_Exit_Spi_SPI_CHIP_SELECT_PROTECTION            __asm("ei")
 
#define SchM_Enter_Spi_SPI_RAM_DATA_PROTECTION              __asm("di")
#define SchM_Exit_Spi_SPI_RAM_DATA_PROTECTION               __asm("ei")

#define SchM_Enter_Spi_SPI_DMA_PROTECTION                   __asm("di")
#define SchM_Exit_Spi_SPI_DMA_PROTECTION                    __asm("ei")


#endif /* SCHM_SPI_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

