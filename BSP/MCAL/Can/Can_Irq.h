/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_Irq.h                                                   */
/* Version      = 3.0.6a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* C header file for Can_Irq.c                                                */
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
 * V3.0.1:  14.10.2009  : Updated for changes in wake-up support as per
 *                        SCR ANMCANLINFR3_SCR_031.
 * V3.0.2:  30.10.2009  : Memory section has been updated as per the SCR
 *                        ANMCANLINFR3_SCR_037.
 * V3.0.3:  21.04.2010  : As per ANMCANLINFR3_SCR_056, provision for Tied Wakeup
 *                        interrupts is added.
 * V3.0.4:  30.06.2010  : As per ANMCANLINFR3_SCR_067, file is updated to
 *                        support and ISR Category support configurable by a
 *                        pre-compile option.
 * V3.0.5:  08.07.2010  : As per ANMCANLINFR3_SCR_068, ISR Category options are
 *                        updated from MODE to TYPE.
 * V3.0.6:  12.09.2010  : As per ANMCANLINFR3_SCR_085, extern declaration of
 *                        ISRs are updated for channel 3,4 and 5.
 * V3.0.6a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef CAN_IRQ_H
#define CAN_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can.h"   /* CAN Module Header File */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_IRQ_AR_MAJOR_VERSION  2
#define CAN_IRQ_AR_MINOR_VERSION  2
#define CAN_IRQ_AR_PATCH_VERSION  2

/* File version information */
#define CAN_IRQ_SW_MAJOR_VERSION  3
#define CAN_IRQ_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/* The default option for ISR Category MCAL_ISR_TYPE_TOOLCHAIN */
#ifndef CAN_INTERRUPT_TYPE
#define CAN_INTERRUPT_TYPE MCAL_ISR_TYPE_TOOLCHAIN
#endif

#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER0_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER1_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER2_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER3_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER4_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER5_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER0_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER1_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER2_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER3_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER4_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER5_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER0_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER1_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER2_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER3_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER4_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER5_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#if (CAN_WAKEUP_INTERRUPTS_TIED == TRUE)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                  CAN_WAKEUP_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#else
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP0_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP1_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP2_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP3_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP4_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern _INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP5_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
   /* Use OS */
   #include "Os.h"

#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER0_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER1_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER2_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER3_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER4_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER5_RX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER0_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER1_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER2_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER3_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER4_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                   CAN_CONTROLLER5_TX_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER0_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER1_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER2_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER3_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER4_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                               CAN_CONTROLLER5_BUSOFF_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#if (CAN_WAKEUP_INTERRUPTS_TIED == TRUE)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                  CAN_WAKEUP_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#else
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP0_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP1_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP2_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP3_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP4_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
                                                 CAN_WAKEUP5_TXCANCEL_ISR(void);
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif
#else
#error "CAN_INTERRUPT_TYPE not set."
#endif

#endif /* CAN_IRQ_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
