/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu_Ram.h                                                   */
/* Version      = 3.0.1a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Global variable declarations of ICU Driver              */
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
 * V3.0.1:  28-Jun-2010  : As per SCR 286, precompile option is updated for 
 *                         the pointer variable "Icu_GpTAUUnitConfig" to
 *                         support the use of Timer Array Unit B.
 * V3.0.1a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef ICU_RAM_H
#define ICU_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define ICU_RAM_AR_MAJOR_VERSION    ICU_AR_MAJOR_VERSION_VALUE
#define ICU_RAM_AR_MINOR_VERSION    ICU_AR_MINOR_VERSION_VALUE
#define ICU_RAM_AR_PATCH_VERSION    ICU_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define ICU_RAM_SW_MAJOR_VERSION  3
#define ICU_RAM_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define ICU_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global pointer variable for database */
extern P2CONST(Icu_ConfigType, ICU_CONST, ICU_CONFIG_CONST) Icu_GpConfigPtr;

/* Global pointer variable for channel configuration */
extern P2CONST(Tdd_Icu_ChannelConfigType, ICU_CONST, ICU_CONFIG_CONST)
                                                        Icu_GpChannelConfig;

/* Global pointer variable for Timer channel configuration */
extern P2CONST(Tdd_Icu_TimerChannelConfigType, ICU_CONST, ICU_CONFIG_CONST)
                                                   Icu_GpTimerChannelConfig;

#if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)||\
    (ICU_TAUB_UNIT_USED == STD_ON))
/* Global pointer variable for ICU hardware unit configuration */
extern P2CONST(Tdd_Icu_TAUUnitConfigType, ICU_CONST, ICU_CONFIG_CONST)
                                                        Icu_GpTAUUnitConfig;
#endif

#if(ICU_PREVIOUS_INPUT_USED == STD_ON)
/* Global pointer variable for Previous input configuration */
extern P2CONST(Tdd_IcuPreviousInputUseType, ICU_CONST, ICU_CONFIG_CONST)
                                                  Icu_GpPreviousInputConfig;
#endif

/* Global pointer variable for channel RAM data */
extern P2VAR(Tdd_Icu_ChannelRamDataType, ICU_NOINIT_DATA, ICU_CONFIG_DATA)
                                                       Icu_GpChannelRamData;

/* Global pointer to the address of Edge Count RAM data */
extern P2VAR(Tdd_Icu_EdgeCountChannelRamDataType, ICU_NOINIT_DATA,
                                       ICU_CONFIG_DATA) Icu_GpEdgeCountData;

/* Global pointer variable for Timestamp channel RAM data */
extern P2VAR(Tdd_Icu_TimeStampChannelRamDataType, ICU_NOINIT_DATA,
                                       ICU_CONFIG_DATA) Icu_GpTimeStampData;

/* Global pointer to the address of Signal Measure RAM data */
extern P2VAR(Tdd_Icu_SignalMeasureChannelRamDataType, ICU_NOINIT_DATA,
                               ICU_CONFIG_DATA) Icu_GpSignalMeasurementData;

/* Holds the status of ICU Driver Component */
extern VAR(Icu_ModeType, ICU_NOINIT_DATA) Icu_GenModuleMode;

#define ICU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


#define ICU_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

/* Global pointer variable for channel to timer mapping */
extern P2CONST(uint8, ICU_CONST, ICU_CONFIG_CONST) Icu_GpChannelMap;

#define ICU_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"


#define ICU_START_SEC_VAR_1BIT
#include "MemMap.h"

#if(ICU_DEV_ERROR_DETECT == STD_ON)
/* Holds the status of Initialization */
extern VAR(boolean, ICU_INIT_DATA) Icu_GblDriverStatus;
#endif

#define ICU_STOP_SEC_VAR_1BIT
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ICU_RAM_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
