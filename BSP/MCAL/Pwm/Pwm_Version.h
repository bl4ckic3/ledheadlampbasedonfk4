/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Pwm_Version.h                                               */
/* Version      = 3.1.2                                                       */
/* Date         = 06-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking versions of modules        */
/* included by PWM Driver                                                     */
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
 * V3.0.0:  18-Aug-2009  : Initial version
 * V3.1.0:  26-Jul-2011  : Ported for the DK4 variant.
 * V3.1.1:  05-Mar-2012  : Merged the fixes done for Fx4L PWM driver
 * V3.1.2:  06-Jun-2012  : As per SCR 034, Compiler version is removed from
 *                         Environment section.
 */
/******************************************************************************/

#ifndef PWM_VERSION_H
#define PWM_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define PWM_VERSION_AR_MAJOR_VERSION  PWM_AR_MAJOR_VERSION_VALUE
#define PWM_VERSION_AR_MINOR_VERSION  PWM_AR_MINOR_VERSION_VALUE
#define PWM_VERSION_AR_PATCH_VERSION  PWM_AR_PATCH_VERSION_VALUE

/* Software Version Information */
#define PWM_VERSION_SW_MAJOR_VERSION  3
#define PWM_VERSION_SW_MINOR_VERSION  1

/* Included Files AUTOSAR Specification Version */
#if(PWM_DEV_ERROR_DETECT == STD_ON)
#define PWM_DET_AR_MAJOR_VERSION      2
#define PWM_DET_AR_MINOR_VERSION      2
#endif

#if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
#define PWM_SCHM_AR_MAJOR_VERSION     1
#define PWM_SCHM_AR_MINOR_VERSION     1
#endif

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PWM_SW_MAJOR_VERSION != PWM_VERSION_SW_MAJOR_VERSION)
  #error "Pwm_Version.h : Mismatch in Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_VERSION_SW_MINOR_VERSION)
  #error "Pwm_Version.h : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#endif /* PWM_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
