/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Pwm_LTTypes.h                                               */
/* Version      = 3.1.2                                                       */
/* Date         = 06-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSAR PWM Link Time Parameters                              */
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
 * V3.0.1:  25-Jul-2010  : As per SCR 305, indentation is updated for the
 *                         structure "Tdd_Pwm_NotificationType".
 * V3.1.0:  26-Jul-2011  : Ported for the DK4 variant.
 * V3.1.1:  05-Mar-2012  : Merged the fixes done for Fx4L PWM driver
 * V3.1.2:  06-Jun-2012  : As per SCR 034, Compiler version is removed from
 *                         Environment section.
 */
/******************************************************************************/

#ifndef PWM_LTTYPES_H
#define PWM_LTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Pwm.h"
#include "Pwm_Cbk.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* AUTOSAR Specification information */
#define PWM_LTTYPES_AR_MAJOR_VERSION    PWM_AR_MAJOR_VERSION_VALUE
#define PWM_LTTYPES_AR_MINOR_VERSION    PWM_AR_MINOR_VERSION_VALUE
#define PWM_LTTYPES_AR_PATCH_VERSION    PWM_AR_PATCH_VERSION_VALUE

/* File version information */
#define PWM_LTTYPES_SW_MAJOR_VERSION    3
#define PWM_LTTYPES_SW_MINOR_VERSION    1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PWM_SW_MAJOR_VERSION != PWM_LTTYPES_SW_MAJOR_VERSION)
  #error "Pwm_LTTypes.h : Mismatch in Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_LTTYPES_SW_MINOR_VERSION)
  #error "Pwm_LTTypes.h : Mismatch in Minor Version"
#endif


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Structure of function pointer for Callback notification function */
typedef struct STagPwm_NotificationType
{
  /* Pointer to callback notification */
  P2FUNC (void, PWM_APPL_CODE, pPwmEdgeNotifPtr)(void);

}Tdd_Pwm_NotificationType;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Declaration for PWM Channel Callback functions Configuration */
extern CONST(Tdd_Pwm_NotificationType, PWM_CONST) Pwm_GstChannelNotifFunc[];

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PWM_LTTYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
