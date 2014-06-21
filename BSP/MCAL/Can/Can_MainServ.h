/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_MainServ.h                                              */
/* Version      = 3.0.2a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* C header file for Can_MainServ.c                                           */
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
 * V3.0.0:  12.12.2008  : Initial Version
 * V3.0.1:  21.10.2009  : Updated compiler version as per
 *                        SCR ANMCANLINFR3_SCR_031.
 * V3.0.2:  31.12.2010  : As per SCR ANMCANLINFR3_SCR_087, 
 *                       space between '#' and 'if' is removed.
 * V3.0.2a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef CAN_MAINSERV_H
#define CAN_MAINSERV_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Can.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_MAINSERV_AR_MAJOR_VERSION  2
#define CAN_MAINSERV_AR_MINOR_VERSION  2
#define CAN_MAINSERV_AR_PATCH_VERSION  2

/* File version information */
#define CAN_MAINSERV_SW_MAJOR_VERSION  3
#define CAN_MAINSERV_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PRIVATE_CODE
#include "MemMap.h"

extern FUNC(void, CAN_AFCAN_PRIVATE_CODE) Can_TxConfirmationProcessing
(CONSTP2VAR(Tdd_Can_AFCan_16bit_CntrlReg, AUTOMATIC,
                 CAN_AFCAN_PRIVATE_CONST)LpCntrlReg16bit,sint16 LssHthOffSetId);

#if(CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
extern FUNC(void, CAN_AFCAN_PRIVATE_CODE) Can_TxCancellationProcessing
(P2CONST(Can_ControllerConfigType,AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                              LpController, boolean LblIntFlag);

#endif

extern FUNC(void, CAN_AFCAN_PRIVATE_CODE) Can_RxProcessing
(P2CONST(Tdd_Can_AFCan_8bit_CntrlReg, AUTOMATIC, CAN_AFCAN_PRIVATE_CONST)
                                                                 LpCntrlReg8bit,
CONSTP2VAR(Tdd_Can_AFCan_16bit_CntrlReg, AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit,
uint8 LucHrhOffSetId);
#define CAN_AFCAN_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* CAN_MAINSERV_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
