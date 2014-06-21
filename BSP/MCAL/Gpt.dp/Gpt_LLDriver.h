/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Gpt_LLDriver.h                                              */
/* Version      = 3.1.2                                                       */
/* Date         = 06-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Low level driver function prototypes of the of GPT      */
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
 * V3.0.0:  23-Oct-2009    : Initial Version
 * V3.0.1:  08-Jul-2010    : As per SCR 299, Pre compile option
 *                           GPT_ENABLE_DISABLE_NOTIFICATION_API
 *                           is removed for the extern declaration
 *                           Gpt_CbkNotification function.
 * V3.1.0:  27-July-2011   : Modified software version to 3.1.0
 * V3.1.1:  16-Feb-2012    : Merged the fixes done for Fx4L Gpt driver
 * V3.1.2:  06-Jun-2012    : As per SCR 029, Environment section is updated to
 *                           remove compiler version.
 */
/******************************************************************************/
#ifndef GPT_LLDRIVER_H
#define GPT_LLDRIVER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define GPT_LLDRIVER_AR_MAJOR_VERSION   GPT_AR_MAJOR_VERSION_VALUE
#define GPT_LLDRIVER_AR_MINOR_VERSION   GPT_AR_MINOR_VERSION_VALUE
#define GPT_LLDRIVER_AR_PATCH_VERSION   GPT_AR_PATCH_VERSION_VALUE

/*  File version information */
#define GPT_LLDRIVER_SW_MAJOR_VERSION   3
#define GPT_LLDRIVER_SW_MINOR_VERSION   1
#define GPT_LLDRIVER_SW_PATCH_VERSION   2

#if (GPT_SW_MAJOR_VERSION != GPT_LLDRIVER_SW_MAJOR_VERSION)
#error "Software major version of Gpt.h and Gpt_LLDriver.h did not match!"
#endif
#if (GPT_SW_MINOR_VERSION!= GPT_LLDRIVER_SW_MINOR_VERSION )
#error "Software minor version of Gpt.h and Gpt_LLDriver.h did not match!"
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

extern FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Init(void);

extern FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_DeInit(void);

extern FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_StopTimer
(Gpt_ChannelType channel);

extern FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_StartTimer
(Gpt_ChannelType channel, Gpt_ValueType value);

extern FUNC(void, GPT_PRIVATE_CODE) Gpt_CbkNotification
(uint8 LucChannelIdx);

#if (GPT_TIME_ELAPSED_API == STD_ON)
extern FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_GetTimeElapsed
(Gpt_ChannelType channel);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
extern FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_GetTimeRemaining
(Gpt_ChannelType channel);
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) \
  && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
extern FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_EnableWakeup
(Gpt_ChannelType channel);

extern FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_DisableWakeup
(Gpt_ChannelType channel);
#endif

#define GPT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif  /* GPT_LLDRIVER_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
