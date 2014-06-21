/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_GenericTypes.h                                          */
/* Version      = 3.0.2a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* C header file for CAN Driver type definitions.                             */
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
 * V3.0.2:  21.04.2010  : As per ANMCANLINFR3_SCR_056, structure members of
                          Can_PduType are re-arranged as in SWS V2.2.2
 * V3.0.2a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef CAN_GENERICTYPES_H
#define CAN_GENERICTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_GENERICTYPES_AR_MAJOR_VERSION  2
#define CAN_GENERICTYPES_AR_MINOR_VERSION  2
#define CAN_GENERICTYPES_AR_PATCH_VERSION  2

/* File version information */
#define CAN_GENERICTYPES_SW_MAJOR_VERSION  3
#define CAN_GENERICTYPES_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* This is used to provide CAN-ID, DLC and SDU from CanIf to CAN Driver */
typedef struct Can_PduType
{
  /* Pointer to L-SDU */
  uint8 *sdu;
  /* CAN-ID */
  Can_IdType id;
  /* swPduHandle */
  PduIdType swPduHandle ;
  /* DLC */
  uint8 length;
} Can_PduType;

/* State transitions that are used by the function Can_SetControllerMode */
typedef enum
{
  CAN_T_START = 0,
  CAN_T_STOP,
  CAN_T_SLEEP,
  CAN_T_WAKEUP
}Can_StateTransitionType;

/*
CAN_OK      : success
CAN_NOT_OK  : error occured
CAN_BUSY    : Transmit request could not be processed because no
              transmit object was available.
CAN_T_WAKEUP: Wakeup event occured during sleep transition
*/

/* Return values of CAN Driver API */
typedef enum
{
  CAN_OK = 0,
  CAN_NOT_OK,
  CAN_BUSY
}Can_ReturnType;


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CAN_GENERICTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
