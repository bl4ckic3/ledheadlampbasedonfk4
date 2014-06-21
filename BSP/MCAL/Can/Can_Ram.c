/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_Ram.c                                                   */
/* Version      = 3.0.3a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of initialized and unintialized global variables and constants.  */
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
 * V3.0.2:  11.05.2010  : Declaration of "Can_GaaTxCancelCtr" is removed
 *                        (and moved to Can_PBCfg.c) for multiple
 *                        configuration support as per ANMCANLINFR3_SCR_060.
 * V3.0.3:  21.07.2010  : CAN_ZERO is changed as CAN_UNINITIALIZED as per 
 *                        ANMCANLINFR3_SCR_073.
 * V3.0.3a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can_PBTypes.h"      /* CAN Driver Post-Build Config. Header File */
#include "Can_Ram.h"          /* Module RAM header */
#include "Can_Tgt.h"          /* CAN Driver Target Header File */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_RAM_C_AR_MAJOR_VERSION  2
#define CAN_RAM_C_AR_MINOR_VERSION  2
#define CAN_RAM_C_AR_PATCH_VERSION  2

/* File version information */
#define CAN_RAM_C_SW_MAJOR_VERSION  3
#define CAN_RAM_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CAN_RAM_AR_MAJOR_VERSION != CAN_RAM_C_AR_MAJOR_VERSION)
  #error "Can_Ram.c : Mismatch in Specification Major Version"
#endif
#if (CAN_RAM_AR_MINOR_VERSION != CAN_RAM_C_AR_MINOR_VERSION)
  #error "Can_Ram.c : Mismatch in Specification Minor Version"
#endif
#if (CAN_RAM_AR_PATCH_VERSION != CAN_RAM_C_AR_PATCH_VERSION)
  #error "Can_Ram.c : Mismatch in Specification Patch Version"
#endif
#if (CAN_RAM_SW_MAJOR_VERSION != CAN_RAM_C_SW_MAJOR_VERSION)
  #error "Can_Ram.c : Mismatch in Software Major Version"
#endif
#if (CAN_RAM_SW_MINOR_VERSION != CAN_RAM_C_SW_MINOR_VERSION)
  #error "Can_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CAN_AFCAN_START_SEC_VAR_8BIT
#include "MemMap.h"

/* Global variable to store initialization status of CAN Driver */
VAR (boolean, CAN_AFCAN_INIT_DATA) Can_GblCanStatus = CAN_UNINITIALIZED;
#if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
/* Global flag to store the status of Tx Cancel Interrupt status considering
                                                          all the controllers */
VAR (boolean, CAN_AFCAN_NOINIT_DATA) Can_GblTxCancelIntFlg;
#endif

#define CAN_AFCAN_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

/* Global variable to store index of first Hth Id of the CAN Driver */
VAR (uint8, CAN_AFCAN_NOINIT_DATA) Can_GucFirstHthId;
/* Global variable to store index counter for controlling interrupt */
VAR (uint8, CAN_AFCAN_NOINIT_DATA)
                                Can_GucIntCounter[CAN_MAX_NUMBER_OF_CONTROLLER];
#if (CAN_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store index of last Hth Id of the CAN Driver */
VAR (uint8, CAN_AFCAN_NOINIT_DATA) Can_GucLastHthId;
/* Global variable to store index of last Controller Id of the CAN Driver */
VAR (uint8, CAN_AFCAN_NOINIT_DATA) Can_GucLastCntrlId;
#endif

#define CAN_AFCAN_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store pointer to first Controller structure */
P2CONST(Can_ControllerConfigType, CAN_AFCAN_CONST, CAN_AFCAN_PRIVATE_CONST)
                                                      Can_GpFirstController;
/* Global variable to store pointer to first Hth structure */
P2CONST(Tdd_Can_AFCan_Hth, CAN_AFCAN_CONST,
                                         CAN_AFCAN_PRIVATE_CONST)Can_GpFirstHth;
/* Global variable to store pointer of CntrlId array */
P2CONST(uint8, CAN_AFCAN_CONST, CAN_AFCAN_PRIVATE_CONST) Can_GpCntrlIdArray;

#define CAN_AFCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
