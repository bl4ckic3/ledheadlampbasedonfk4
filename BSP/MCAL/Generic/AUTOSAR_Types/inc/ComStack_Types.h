/*============================================================================*/
/* Project      = AUTOSAR NEC Xx4 MCAL Components                             */
/* File name    = ComStack_Types.h                                            */
/* Version      = 3.0.1                                                       */
/* Date         = 14-Jul-2009                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009 by NEC Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision for Communication Stack dependent types                          */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* NEC Electronics Corporation the following shall apply!                     */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by NEC. Any warranty   */
/* is expressly disclaimed and excluded by NEC, either expressed or implied,  */
/* including but not limited to those for non-infringement of intellectual    */
/* property, merchantability and/or fitness for the particular purpose.       */
/*                                                                            */
/* NEC shall not have any obligation to maintain, service or provide bug      */
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
/* In no event shall NEC be liable to the User for any incidental,            */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. NEC shall not be liable for any services or products         */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by NEC in connection with the Product(s) and/or the   */
/* Application.                                                               */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        Xx4                                           */
/*              Compiler:       GHS V5.1.6c                                   */
/*============================================================================*/


/*******************************************************************************
**                      Revision History                                      **
*******************************************************************************/
/*
 * V3.0.0:  30-Mar-2009  : Initial Version
 * V3.0.1:  14-Jul-2009  : As per SCR 015, compiler version is changed from 
 *                         V4.2.3 to V5.1.6c in the header of the file.
 */
/******************************************************************************/

#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"                  /* standard AUTOSAR types           */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define COMSTACK_TYPES_AR_MAJOR_VERSION 2
#define COMSTACK_TYPES_AR_MINOR_VERSION 2
#define COMSTACK_TYPES_AR_PATCH_VERSION 0

/*
 * File version information
 */
#define COMSTACK_TYPES_SW_MAJOR_VERSION 3
#define COMSTACK_TYPES_SW_MINOR_VERSION 0
#define COMSTACK_TYPES_SW_PATCH_VERSION 0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* COMTYPE018 General return codes for NotifResultType */
#define NTFRSLT_OK                     0x00
#define NTFRSLT_E_NOT_OK               0x01
#define NTFRSLT_E_TIMEOUT_A            0x02
#define NTFRSLT_E_TIMEOUT_BS           0x03
#define NTFRSLT_E_TIMEOUT_CR           0x04
#define NTFRSLT_E_WRONG_SN             0x05
#define NTFRSLT_E_INVALID_FS           0x06
#define NTFRSLT_E_UNEXP_PDU            0x07
#define NTFRSLT_E_WFT_OVRN             0x08
#define NTFRSLT_E_NO_BUFFER            0x09
#define NTFRSLT_E_CANCELATION_OK       0x0A
#define NTFRSLT_E_CANCELATION_NOT_OK   0x0B

/* COMTYPE021 General return codes for BusTrcvErrorType */
#define BUSTRCV_OK           0x00
#define BUSTRCV_E_ERROR      0x01

/*******************************************************************************
**                      Global Data Types (ECU dependent)                     **
*******************************************************************************/

/* Chapter 8.1.1 */
typedef uint8        PduIdType;     /* Type of PDU ID.
                                       Allowed ranges: uint8 .. uint16 */

/* Chapter 8.1.2 */
typedef uint16       PduLengthType; /* Type of PDU Length.
                                       Allowed ranges: uint8 .. uint32 */

/* Chapter 8.1.5 */
typedef uint8        NotifResultType;

/* Chapter 8.1.6 */
typedef uint8        BusTrcvErrorType;

/* Chapter 8.1.7 */
typedef uint8        NetworkHandleType;

/*******************************************************************************
**                      Global Data Types (ECU independent)                   **
*******************************************************************************/

/* Chapter 8.1.3 */
typedef struct
{
  P2VAR(uint8,AUTOMATIC,AUTOSAR_COMSTACKDATA) SduDataPtr;
  PduLengthType  SduLength;
} PduInfoType;                   /* Basic information about a PDU of any type*/

/* Chapter 8.1.4 */
typedef enum
{
  BUFREQ_OK,
  BUFREQ_E_NOT_OK,
  BUFREQ_E_BUSY,
  BUFREQ_E_OVFL
} BufReq_ReturnType;                 /* result of a buffer request          */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* COMSTACK_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
