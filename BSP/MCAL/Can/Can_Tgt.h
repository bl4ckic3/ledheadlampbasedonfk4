/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_Tgt.h                                                   */
/* Version      = 3.0.4a                                                      */
/* Date         = 27.10.2011                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of macros used by CAN Driver internally                          */
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
 * V3.0.2:  21.04.2010  : 1. CAN_MBON_BIT_SET is added for ensuring MBON bit
 *                        status during power save mode As per
 *                        ANMCANLINFR3_SCR_056.
 *                        2. CAN_DLC_REG_MASK, CAN_MCONF_REG_MASK and 
 *                        CAN_MIDH_REG_MASK are newly added for masking.
 * V3.0.3:  03.02.2011  : Tabs are removed as per ANMCANLINFR3_SCR_093.
 * V3.0.4:  20.06.2011  : 1. CAN_TRANSMISSION_STS, CAN_ELEVEN_DBT_COUNT, 
 *                        CAN_CLR_ABT_BIT macros are newly added for masking as 
 *                        per ANMCANLINFR3_SCR_107.
 *                        2. CAN_IRQ_REQ_DIS, CAN_IRQ_REQ_ENB macros are 
 *                        changed to unit16.
 * V3.0.4a: 27.10.2011  : 1. Copyright is updated.
 *                        2. CAN_CLR_INT_REQ macro is added as per MTS #3641.
 *                        3. CAN_IRQ_REQ_DIS and CAN_IRQ_REQ_ENB macros are 
 *                           updated.
 */
/******************************************************************************/

#ifndef CAN_TGT_H
#define CAN_TGT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can.h"  /* CAN Driver Header File */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_CANTGT_AR_MAJOR_VERSION  2
#define CAN_CANTGT_AR_MINOR_VERSION  2
#define CAN_CANTGT_AR_PATCH_VERSION  2

/* File version information */
#define CAN_CANTGT_SW_MAJOR_VERSION  3
#define CAN_CANTGT_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Start address of database  */
#define CAN_DBTOC_VALUE \
        ((CAN_VENDOR_ID_VALUE << 22) | \
        (CAN_MODULE_ID_VALUE << 14) | \
        (CAN_SW_MAJOR_VERSION_VALUE << 8) | \
        (CAN_SW_MINOR_VERSION_VALUE << 3))

/* Limit check */
#define CAN_LIMIT                       (uint8)0xFF

/* CAN uninitialized status */
#define CAN_UNINITIALIZED               (uint8)0
/* CAN initialized status */
#define CAN_INITIALIZED                 (uint8)1

/* Flag not set */
#define CAN_FALSE                       (uint8)0
/* Flag set */
#define CAN_TRUE                        (uint8)1

#define CAN_ZERO                        (uint8)0
#define CAN_ONE                         (uint8)1
#define CAN_TWO                         (uint8)2
#define CAN_THREE                       (uint8)3
#define CAN_FOUR                        (uint8)4
#define CAN_EIGHT                       (uint8)8
#define CAN_IRQ_REQ_DIS                 (uint16)0x0080
#define CAN_IRQ_REQ_ENB                 (uint16)0x0000
#define CAN_SHIFT_TWO                   (uint8)2
#define CAN_DISABLEWAKEUP               (uint8)0xF0
#define CAN_WAKEUP                      (uint8)0xFF
/*    */
#define CAN_ELEVEN_DBT_COUNT            (uint16)0x1504

/* Clear Global operating mode */
#define CAN_CLR_GOM                     (uint16)0x0001
/* Clear all interrupts */
#define CAN_CLR_ALL_INTERRUPT           (uint16)0x007F
/* Clear Wakeup and TxCancel interrupt/status */
#define CAN_CLR_WUP_TXCANCEL_INTERRUPT  (uint16)0x0060
/* Clear Message buffer MUC, MOW, IE, DN, TRQ and RDY bits*/
#define CAN_CLR_CTRL_BIT                (uint16)0x001F
/* Clear Message buffer data update */
#define CAN_CLR_DN_BIT                  (uint16)0x0004
/* Clear Extended format mode identifier */
#define CAN_CLR_IDE_BIT                 (uint16)0x7FFF
/* Clear Message buffer ready bit */
#define CAN_CLR_RDY_BIT                 (uint16)0x0001
/* Clear Recieve history list overflow */
#define CAN_CLR_ROVF_BIT                (uint16)0x0001
/* Clear Recieve interrupt */
#define CAN_CLR_RX_INTERRUPT            (uint16)0x0002
/*  Clear Sleep power save mode */
#define CAN_CLR_SLEEP_MODE              (uint16)0x0018
/* Clear Transmit history list overflow */
#define CAN_CLR_TOVF_BIT                (uint16)0x0001
/* Clear Message buffer transmission request */
#define CAN_CLR_TRQ_BIT                 (uint16)0x0002
/* Clear Transmit interrupt status bit */
#define CAN_CLR_TX_INTERRUPT            (uint16)0x0001
/* Clear Wakeup interrupt status bit */
#define CAN_CLR_WAKEUP_INTERRUPT        (uint16)0x0020
/* Clear Transmit Cancellation interrupt status bit */
#define CAN_CLR_TXCANCEL_INTERRUPT      (uint16)0x0040
/* Clear Arbitration, Protocol and Module error interrupt status bits */
#define CAN_CLR_ERR_INTERRUPT           (uint16)0x001C
/* Enable Wakeup interrupt */
#define CAN_ENB_WAKEUP_INTERRUPT        (uint16)0x2000
/* Clear Automatic block transmission */
#define CAN_CLR_ABT_BIT                 (uint16)0x0001
/* Clear interrupt request flag */
#define CAN_CLR_INT_REQ                 (uint16)0xEFFF

/* Message buffer enable */
#define CAN_SET_MSG_BUFFER_EN           (uint8)0x01
/* System clock */
#define CAN_SET_SYSTEM_CLOCK            (uint8)0x00
/* Message buffer interrupt request enable */
#define CAN_SET_MBUF_INT_EN             (uint16)0x0800
/* Force shut down */
#define CAN_SET_EFSD                    (uint16)0x0200
/* Global operating mode */
#define CAN_SET_GOM                     (uint16)0x0100
/* Error counter clear */
#define CAN_SET_CCERC_BIT               (uint16)0x8000
/* Message buffer ready */
#define CAN_SET_RDY_BIT                 (uint16)0x0100
/* Message buffer transmission message request */
#define CAN_SET_TRQ_BIT                 (uint16)0x0200
/* Extended format mode identifier */
#define CAN_SET_IDE_BIT                 (uint32)0x80000000ul
/* Initialization mode */
#define CAN_SET_INIT_OPMODE             (uint16)0x0007
/* Recieve-only operating mode */
#define CAN_SET_RECEIVE_ONLY_MODE       (uint16)0x0304
/* Sleep power save mode  */
#define CAN_SET_SLEEP_MODE              (uint16)0x0810
/* Normal operating mode */
#define CAN_SET_START_MODE              (uint16)0x0100
/* Transmission status bit */
#define CAN_TRANSMISSION_STS            (uint16)0x0100

/* MBON bit status */
#define CAN_MBON_BIT_STS                (uint16)0x8000
/* MBON bit set status */
#define CAN_MBON_BIT_SET                (uint16)0x8001
/* BusOff status */
#define CAN_BUSOFF_STS                  (uint8)0x10
/* Message buffer data update status */
#define CAN_DN_BIT_STS                  (uint16)0x0004
/* Message buffer data update/updating status */
#define CAN_DN_MUC_BIT_STS              (uint16)0x2004
/* Initialization mode status */
#define CAN_INIT_OPMODE_STS             (uint16)0x0007
/* Recieve-only mode status */
#define CAN_RECEIVE_ONLY_MODE_STS       (uint16)0x0003
/* Message buffer ready status */
#define CAN_RDY_BIT_STS                 (uint16)0x0001
/* Message buffer transmission message status */
#define CAN_TRQ_BIT_STS                 (uint16)0x0002
/* Transmit history pointer match status */
#define CAN_TCP_BIT_STS                 (uint16)0x0200
/* Transmit history pointer match status */
#define CAN_THPM_BIT_STS                (uint16)0x0002
/* Recieve history pointer match status */
#define CAN_RHPM_BIT_STS                (uint16)0x0002

/* Extended identifier check */
#define CAN_EXTENDED_TYPE               (uint8)0x01
/* Message buffer disable */
#define CAN_MSG_BUFFER_DISABLE          (uint8)0x00
/* Extended format mode identifier mask */
#define CAN_MASK_IDE_BIT                (uint16)0x8000

/* Recieve interrupt mask */
#define CAN_REC_INT_MASK                (uint16)0x0200
/* Transmit interrupt mask */
#define CAN_TX_INT_MASK                 (uint16)0x0100
/* Wakeup interrupt mask */
#define CAN_WAKEUP_INT_MASK             (uint16)0x2000
/* Error interrupt mask */
#define CAN_ERR_INT_MASK                (uint16)0x0400
/* Transmit Cancellation interrupt mask */
#define CAN_TXCANCEL_INT_MASK           (uint16)0x4000

/* Recieve interrupt status mask */
#define CAN_REC_STS_MASK                (uint16)0x0002
/* Transmit interrupt status mask */
#define CAN_TX_STS_MASK                 (uint16)0x0001
/* Wakeup interrupt status mask */
#define CAN_WAKEUP_STS_MASK             (uint16)0x0020
/* Error interrupt status mask */
#define CAN_ERR_STS_MASK                (uint16)0x0004
/* Transmit Cancellation interrupt status mask */
#define CAN_TXCANCEL_STS_MASK           (uint16)0x0040

/* Message Data Length Register Mask for caution */
#define CAN_DLC_REG_MASK                (uint8)0x0F
/* Message configuration Register Mask for caution */
#define CAN_MCONF_REG_MASK              (uint8)0xFD
/* MID1H Register Mask for caution */
#define CAN_MIDH_REG_MASK               (uint16)0x9FFF

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CAN_TGT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
