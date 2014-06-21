/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = CanIf.h                                                     */
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

#ifndef CANIF_H
#define CANIF_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"       /* Com Stack Types Header File */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Vendor ID */
#define CANIF_VENDOR_ID (uint8)23

/* Module ID */
#define CANIF_MODULE_ID (uint16)60

/* AUTOSAR SPECIFICATION VERSION */
#define CANIF_AR_MAJOR_VERSION  3
#define CANIF_AR_MINOR_VERSION  0
#define CANIF_AR_PATCH_VERSION  2

/* SOFTWARE VERSION INFORMATION */
#define CANIF_SW_MAJOR_VERSION  3
#define CANIF_SW_MINOR_VERSION  0
#define CANIF_SW_PATCH_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Return value of the WakeupSourceType. */
typedef enum
{
  CANIF_CONTROLLER_WAKEUP = 0,
  CANIF_TRANSCEIVER_WAKEUP
}CanIf_WakeupSourceType;

/* Return value of the CanIf_TransceiverModeType. */
typedef enum
{
  CANIF_TRCV_MODE_NORMAL = 0,
  CANIF_TRCV_MODE_STANDBY,
  CANIF_TRCV_MODE_SLEEP
}CanIf_TransceiverModeType;

/* Return value of the CanIf_TrcvWakeupReasonType. */
typedef enum
{
  CANIF_TRCV_WU_ERROR = 0,
  CANIF_TRCV_WU_NOT_SUPPORTED,
  CANIF_TRCV_WU_BY_BUS,
  CANIF_TRCV_WU_INTERNALLY,
  CANIF_TRCV_WU_RESET,
  CANIF_TRCV_WU_POWER_ON
}CanIf_TrcvWakeupReasonType;

/* Return value of the CanIf_TrcvWakeupModeType. */
typedef enum
{
  CANIF_TRCV_WU_ENABLE = 0,
  CANIF_TRCV_WU_DISABLE,
  CANIF_TRCV_WU_CLEAR  
}CanIf_TrcvWakeupModeType;

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CANIF_H */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
