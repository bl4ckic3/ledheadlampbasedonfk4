/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu_LLDriver.h                                              */
/* Version      = 3.0.2a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Low level driver function prototypes of the ICU         */
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
 * V3.0.0:  26-Aug-2009  : Initial version
 *
 * V3.0.1:  25-Feb-2010  : As per SCR 192, the prototypes of the functions
 *                         Icu_HWEdgeCountingInit, Icu_HWTimestampInit and
 *                         Icu_HWSignalMeasurementInit are updated.
 *
 * V3.0.2:  28-Jun-2010  : As per SCR 286, following changes are done:
 *                         1. Precompile option for Icu_HWResetEdgeCount
 *                            is modified to support Timer Array Unit B.
 *                         2. Tab spaces are removed.
 * V3.0.2a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef ICU_LLDRIVER_H
#define ICU_LLDRIVER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define ICU_LLDRIVER_AR_MAJOR_VERSION   ICU_AR_MAJOR_VERSION_VALUE
#define ICU_LLDRIVER_AR_MINOR_VERSION   ICU_AR_MINOR_VERSION_VALUE
#define ICU_LLDRIVER_AR_PATCH_VERSION   ICU_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define ICU_LLDRIVER_SW_MAJOR_VERSION  3
#define ICU_LLDRIVER_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define ICU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWEdgeCountingInit
(P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)LpChannelConfig,
 P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWTimestampInit
(P2CONST(Tdd_Icu_ChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)LpChannelConfig,
P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWSignalMeasurementInit
(P2CONST(Tdd_Icu_TimerChannelConfigType, AUTOMATIC, ICU_CONFIG_CONST)
                                                          LpTimerChannelConfig);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWInitInputSelection
(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWInit(void);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWSetActivation
(uint8 LucChannel, Icu_ActivationType LucActiveEdge);

#if (ICU_DE_INIT_API == STD_ON)
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWDeInitInputSelection(void);
#endif

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWDeInit(void);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWSetMode(Icu_ModeType Mode);

#if((ICU_TAUA_UNIT_USED == STD_ON) || (ICU_TAUB_UNIT_USED == STD_ON))
extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWResetEdgeCount(uint8 LucChannel);
#endif

extern FUNC(Icu_EdgeNumberType, ICU_PRIVATE_CODE) Icu_HWReadEdgeCount
(uint8 LucChannel);

extern FUNC(void, ICU_PRIVATE_CODE)Icu_ServiceSignalMeasurement
(Icu_ChannelType LddChannel);

extern FUNC(void, ICU_PRIVATE_CODE)Icu_ServiceTimestamp
(Icu_ChannelType LddChannel, uint32 LulCapturedTimestampVal);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_TimerIsr(Icu_ChannelType LddChannel);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_ExternalInterruptIsr
(Icu_ChannelType LddChannel);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWStartCountMeasurement
(Icu_ChannelType LddChannel);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWStopCountMeasurement
(Icu_ChannelType LddChannel);

extern FUNC(void, ICU_PRIVATE_CODE) Icu_HWGetEdgeNumbers
(Icu_ChannelType LddChannel);

#define ICU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* ICU_LLDRIVER_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
