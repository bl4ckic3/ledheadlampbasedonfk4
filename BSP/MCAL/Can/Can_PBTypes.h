/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_PBTypes.h                                               */
/* Version      = 3.0.3a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSAR CAN Post Build time parameters.                       */
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
 * V3.0.2:  11.05.2010  : Can_AFCan_GaaConfigType is added for multiple
 *                        configuration support as per ANMCANLINFR3_SCR_060.
 * V3.0.3:  12.09.2010  : As per ANMCANLINFR3_SCR_083, Can_AFCan_GstConfigType
 *                        is removed.
 * V3.0.3a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef CAN_PBTYPES_H
#define CAN_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can.h"    /* CAN Driver Module header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_PBTYPES_AR_MAJOR_VERSION  2
#define CAN_PBTYPES_AR_MINOR_VERSION  2
#define CAN_PBTYPES_AR_PATCH_VERSION  2

/* File version information */
#define CAN_PBTYPES_SW_MAJOR_VERSION  3
#define CAN_PBTYPES_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Hardware Recieve Handle Structure */
typedef struct STagTdd_Can_AFCan_Hrh
{
  /* Pointer to Base Address of 8-bit Message Buffer Registers  */
  P2VAR(Tdd_Can_AFCan_8bit_MsgBuffer, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)
                                                                pMsgBuffer8bit;
  /* Pointer to Base Address of 16-bit Message Buffer Registers  */
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)
                                                                pMsgBuffer16bit;
  /* Pointer to Base Address of 32-bit Message Buffer Registers  */
  P2VAR(Tdd_Can_AFCan_32bit_MsgBuffer, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)
                                                                pMsgBuffer32bit;
  /* CAN-ID */
  #if(CAN_STANDARD_CANID == STD_OFF)
   /* CAN-ID Low */
  uint16 usCanIdLow;
  #endif
  /* CAN-ID High */
  uint16 usCanIdHigh;
  /* Receive : MCONF Register */
  uint8 ucMConfigReg;
}Tdd_Can_AFCan_Hrh;

/* Hardware Transmit Handle Structure */
typedef struct STagTdd_Can_AFCan_Hth
{
  /* Pointer to Base Address of 8-bit Message Buffer Registers  */
  P2VAR(Tdd_Can_AFCan_8bit_MsgBuffer, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)
                                                                pMsgBuffer8bit;
  /* Pointer to Base Address of 16-bit Message Buffer Registers  */
  P2VAR(Tdd_Can_AFCan_16bit_MsgBuffer, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)
                                                                pMsgBuffer16bit;
  /* Pointer to Base Address of 32-bit Message Buffer Registers  */
  P2VAR(Tdd_Can_AFCan_32bit_MsgBuffer, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)
                                                                pMsgBuffer32bit;
  /* Store CanTxPduId */
  P2VAR(PduIdType, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)pCanTxPduId;
  #if(CAN_MULTIPLEX_TRANSMISSION == STD_ON)
  /* Access Flag */
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)pHwAccessFlag;
  #endif
  /* ucController */
  uint8 ucController;
}Tdd_Can_AFCan_Hth;

/*******************************************************************************
**                      Extern declarations for Global Data                   **
*******************************************************************************/

#define CAN_AFCAN_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/* Global array for byte allocation */
extern VAR(uint8,CAN_AFCAN_NOINIT_DATA)Can_AFCan_GaaPBByteArray[];
/* Global array to store CanTxPduId */
extern VAR(PduIdType,CAN_AFCAN_NOINIT_DATA)Can_AFCan_GaaCanTxPduId[];
#if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
/* Global array for storing the Tx Cancellation status of BasicCan Hth */
extern VAR(uint8, CAN_AFCAN_NOINIT_DATA) Can_AFCan_GaaTxCancelStsFlgs[];
#endif
#define CAN_AFCAN_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/* Global array for Hth structure */
extern CONST(Tdd_Can_AFCan_Hth,CAN_AFCAN_CONST) Can_AFCan_GaaHth[];
/* Global array for Hrh structure */
extern CONST(Tdd_Can_AFCan_Hrh,CAN_AFCAN_CONST) Can_AFCan_GaaHrh[];
/* Global array for filter mask structure */;
extern CONST(Tdd_Can_AFCan_HwFilterMask, CAN_AFCAN_CONST)
                                                      Can_AFCan_GaaFilterMask[];
/* Global array for ControllerIdArray */
extern CONST(uint8, CAN_AFCAN_CONST) Can_AFCan_GaaCntrlArrayId[];
#if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
/* Global array for BasicCanHth Id*/
extern CONST(uint8, CAN_AFCAN_CONST) Can_AFCan_GaaBasicCanHth[];
#endif
#define CAN_AFCAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#endif /* CAN_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
