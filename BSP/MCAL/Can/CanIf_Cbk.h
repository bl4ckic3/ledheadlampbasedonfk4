/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = CanIf_Cbk.h                                                 */
/* Version      = 3.0.0a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of external declaration of constants, global data, type          */
/* definitions, APIs and service IDs.                                         */
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
**                      Revision History                                      **
*******************************************************************************/
/*
 * V3.0.0:  12.12.2008  : Initial Version
 * V3.0.0a: 18-Oct-2011  : Copyright is updated.
 */

#ifndef CANIF_CBK_H
#define CANIF_CBK_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Can.h"       /* CAN Driver Header File */ 

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/



/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/* BusOff event referring to a CAN Controller */
extern void CanIf_ControllerBusOff (uint8 Controller);

/* RxIndication event referring to a CAN Network */
extern void CanIf_RxIndication (uint8 Hrh, Can_IdType CanId, uint8 CanDlc, 
                                                         const uint8 *CanSduPtr);

/* TxConfirmaton event referring to a CAN Network */
extern void CanIf_TxConfirmation(PduIdType CanTxPduId);

/* TxCancelConfirmation event referring to a CAN Network */
extern void CanIf_CancelTxConfirmation
(P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr);


/* TxCancelConfirmation event referring to a CAN Network */
extern void CanIf_ReadRxData(uint8 Hrh,uint8 Dlc,uint8 * CanSduRxDataO);

#endif /* CANIF_CBK_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
