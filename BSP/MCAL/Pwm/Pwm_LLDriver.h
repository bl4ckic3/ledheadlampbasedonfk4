/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Pwm_LLDriver.h                                              */
/* Version      = 3.1.4                                                       */
/* Date         = 06-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of prototypes for internal functions.                            */
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
 * V3.0.1:  28-Oct-2009  : Updated as per the SCR 054
 *                         extern function for Pwm_HW_Callback is added
 * V3.1.0:  26-Jul-2011  : Ported for the DK4 variant.
 * V3.1.2:  12-Jan-2012  :TEL have fixed The Issues reported by  mantis id
 *                       :  #4246,#4210,#4207,#4206,#4202,#4259,#4257,#4248.
 * V3.1.3:  05-Mar-2012  : Merged the fixes done for Fx4L PWM driver
 * V3.1.4:  06-Jun-2012  : As per SCR 034, Compiler version is removed from
 *                         Environment section.
 */
/******************************************************************************/

#ifndef PWM_LLDRIVER_H
#define PWM_LLDRIVER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Pwm_LTTypes.h"
#include "Pwm_PBTypes.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* AUTOSAR specification version information */
#define PWM_LLDRIVER_AR_MAJOR_VERSION   PWM_AR_MAJOR_VERSION_VALUE
#define PWM_LLDRIVER_AR_MINOR_VERSION   PWM_AR_MINOR_VERSION_VALUE
#define PWM_LLDRIVER_AR_PATCH_VERSION   PWM_AR_PATCH_VERSION_VALUE

/* File version information */
#define PWM_LLDRIVER_SW_MAJOR_VERSION   3
#define PWM_LLDRIVER_SW_MINOR_VERSION   1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PWM_SW_MAJOR_VERSION != PWM_LLDRIVER_SW_MAJOR_VERSION)
  #error "Pwm_LLDriver.h : Mismatch in Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_LLDRIVER_SW_MINOR_VERSION)
  #error "Pwm_LLDriver.h : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define PWM_START_SEC_PRIVATE_CODE
#include "MemMap.h"

extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_Init (void);

#if (PWM_DE_INIT_API == STD_ON)
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_DeInit (void);
#endif

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
extern FUNC (void, PWM_PRIVATE_CODE) Pwm_HW_SetOutputToIdle
(Pwm_ChannelType LddChannelId);
#endif

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
extern FUNC (Pwm_OutputStateType, PWM_PRIVATE_CODE) Pwm_HW_GetOutputState
(Pwm_ChannelType LddChannelId);
#endif

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
extern FUNC (void, PWM_PRIVATE_CODE) Pwm_HW_SetDutyCycle
(Pwm_ChannelType LddChannelId, uint16 LusDutyCycle);

extern FUNC (void, PWM_PRIVATE_CODE) Pwm_HW_SetDuty_FixedPeriodShifted
(Pwm_ChannelType LddChannelId, uint16 LusDutyCycle);
#endif

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
extern FUNC (void, PWM_PRIVATE_CODE) Pwm_HW_SetPeriodAndDuty
(Pwm_ChannelType LddChannelId, Pwm_PeriodType  LddPeriod, uint16 LusDutyCycle);
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
extern FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_Callback
(Pwm_ChannelType LucChannelIdx);
#endif

extern FUNC(Pwm_PeriodType, PWM_PRIVATE_CODE) Pwm_HW_CalculateDuty
(Pwm_PeriodType LddAbsolutePeriod, Pwm_PeriodType LddRelativeDuty,
 uint8 LucTAUType);
#define PWM_STOP_SEC_PRIVATE_CODE

#include "MemMap.h"

#endif  /* PWM_LLDRIVER_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
