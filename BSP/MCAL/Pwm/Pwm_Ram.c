/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Pwm_Ram.c                                                   */
/* Version      = 3.1.3                                                       */
/* Date         = 06-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global variable declarations                                               */
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
 * V3.0.1:  02-Jul-2010  : As per SCR 290, the global variable "Pwm_GpConfigPtr"
 *                         is removed.
 * V3.0.2:  28-Jul-2010  : As per SCR 321, initialization of the variable
 *                         Pwm_GblDriverStatus is changed from PWM_FALSE to
 *                         PWM_UNINITIALIZED.
 * V3.1.0:  26-Jul-2011  : Ported for the DK4 variant.
 * V3.1.1:  04-Oct-2011  : Added comments for the violation of MISRA rule 19.1.
 * V3.1.2:  05-Mar-2012  : Merged the fixes done for Fx4L PWM driver
 * V3.1.3:  06-Jun-2012  : As per SCR 034, Compiler version is removed from
 *                         Environment section.
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Pwm_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification version information */
#define PWM_RAM_C_AR_MAJOR_VERSION    PWM_AR_MAJOR_VERSION_VALUE
#define PWM_RAM_C_AR_MINOR_VERSION    PWM_AR_MINOR_VERSION_VALUE
#define PWM_RAM_C_AR_PATCH_VERSION    PWM_AR_PATCH_VERSION_VALUE

/* File version information */
#define PWM_RAM_C_SW_MAJOR_VERSION    3
#define PWM_RAM_C_SW_MINOR_VERSION    1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PWM_RAM_AR_MAJOR_VERSION != PWM_RAM_C_AR_MAJOR_VERSION)
  #error "Pwm_Ram.c : Mismatch in Specification Major Version"
#endif

#if (PWM_RAM_AR_MINOR_VERSION != PWM_RAM_C_AR_MINOR_VERSION)
  #error "Pwm_Ram.c : Mismatch in Specification Minor Version"
#endif

#if (PWM_RAM_AR_PATCH_VERSION != PWM_RAM_C_AR_PATCH_VERSION)
  #error "Pwm_Ram.c : Mismatch in Specification Patch Version"
#endif

#if (PWM_SW_MAJOR_VERSION != PWM_RAM_C_SW_MAJOR_VERSION)
  #error "Pwm_Ram.c : Mismatch in Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_RAM_C_SW_MINOR_VERSION)
  #error "Pwm_Ram.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
#define PWM_START_SEC_VAR_NOINIT_UNSPECIFIED
  /* MISRA Rule         : 19.1                            */
  /* Message            : #include statements in a file   */
  /*                      should only be preceded by other*/
  /*                      preprocessor directives or      */
  /*                      comments.                       */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */
#include "MemMap.h"

#if ((PWM_TAUA_UNIT_USED  == STD_ON) || (PWM_TAUB_UNIT_USED  == STD_ON) || \
     (PWM_TAUC_UNIT_USED  == STD_ON))
/* Global pointer variable for TAUA/TAUB/TAUC Unit configuration */
P2CONST(Tdd_Pwm_TAUABCUnitConfigType, PWM_CONST, PWM_CONFIG_CONST)
Pwm_GpTAUABCUnitConfig;
#endif

#if(PWM_TAUJ_UNIT_USED == STD_ON)
/* Global pointer variable for TAUJ Unit configuration */
P2CONST(Tdd_Pwm_TAUJUnitConfigType, PWM_CONST, PWM_CONFIG_CONST)
Pwm_GpTAUJUnitConfig;
#endif

/* Global pointer variable for channel configuration */
P2CONST(Tdd_Pwm_ChannelConfigType, PWM_CONST, PWM_CONFIG_CONST)
Pwm_GpChannelConfig;

#if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
/* Global pointer variable for synch start configuration */
P2CONST(Tdd_PwmTAUSynchStartUseType, PWM_CONST, PWM_CONFIG_CONST)
Pwm_GpSynchStartConfig;
#endif

/* Global pointer variable for channel to timer mapping */
P2CONST(uint8, PWM_CONST, PWM_CONFIG_CONST) Pwm_GpChannelTimerMap;

#if(PWM_NOTIFICATION_SUPPORTED == STD_ON)
/* Global pointer variable for Notification status array */
P2VAR(uint8, AUTOMATIC, PWM_CONFIG_DATA) Pwm_GpNotifStatus;
#endif

/* Global pointer variable for for Idle state status for configured channels */
P2VAR(uint8, AUTOMATIC, PWM_CONFIG_DATA) Pwm_GpChannelIdleStatus;

#define PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */

#define PWM_START_SEC_VAR_1BIT
#include "MemMap.h"/* PRQA S 5087 */

#if (PWM_DEV_ERROR_DETECT == STD_ON)
/* Status of PWM Driver initialization */
VAR(boolean, PWM_INIT_DATA) Pwm_GblDriverStatus = PWM_UNINITIALIZED;
#endif

#define PWM_STOP_SEC_VAR_1BIT
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
