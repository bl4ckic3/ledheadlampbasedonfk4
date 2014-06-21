/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = EcuM_Cbk.h                                                  */
/* Version      = 3.0.1a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file is a stub for EcuM Component                                     */
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
 * V3.0.0:  06-Jul-2009  : Initial Version
 *
 * V3.0.1:  24-Feb-2010  : Unused macro is removed.
 * V3.0.1a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef ECUM_CBK_H
#define ECUM_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"     /* To include AUTOSAR standard types */
#include "EcuM.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

#define ECUM_AR_MAJOR_VERSION  1
#define ECUM_AR_MINOR_VERSION  2

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define  CAN_WKP_SRC_1               (EcuM_WakeupSourceType)2
#define  CAN_WKP_SRC_2               (EcuM_WakeupSourceType)4
#define  CAN_WKP_SRC_3               (EcuM_WakeupSourceType)6
#define  CAN_WKP_SRC_4               (EcuM_WakeupSourceType)8

#define  EcumWkSourcePower           (EcuM_WakeupSourceType)0  
#define  EcumWkSourceReset           (EcuM_WakeupSourceType)1
#define  GPT_WKP_SRC_1               (EcuM_WakeupSourceType)8
#define  GPT_WKP_SRC_2               (EcuM_WakeupSourceType)4
#define  GPT_WKP_SRC_3               (EcuM_WakeupSourceType)6
#define  GPT_WKP_SRC_4               (EcuM_WakeupSourceType)2   

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
extern void EcuM_SetWakeupEvent(EcuM_WakeupSourceType WakeupSource);
extern void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType WakeupSource);
extern void EcuM_CheckWakeupEvent(EcuM_WakeupSourceType WakeupSource);
extern void EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource);

#endif /* ECUM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
