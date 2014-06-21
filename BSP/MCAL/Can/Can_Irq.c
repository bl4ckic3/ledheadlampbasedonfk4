/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_Irq.c                                                   */
/* Version      = 3.0.7a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Interrupt Service Routines Functionality.                     */
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
 * V3.0.1:  10.10.2009  : Updated for changes in wake-up support as per
 *                        SCR ANMCANLINFR3_SCR_031.
 * V3.0.2:  20.01.2010  : Pre-compiler switch has been updated as per
 *                        SCR ANMCANLINFR3_SCR_042.
 * V3.0.3:  21.04.2010  : As per ANMCANLINFR3_SCR_056, provision for Tied Wakeup
 *                        interrupts is added.
 * V3.0.4:  11.05.2010  : In CAN_WAKEUP_TXCANCEL_ISR, "TRUE" is changed to
 *                        "STD_ON".
 * V3.0.5:  30.06.2010  : As per ANMCANLINFR3_SCR_067, file is updated to
 *                        support and ISR Category support configurable by a
 *                        pre-compile option.
 * V3.0.6:  08.07.2010  : As per ANMCANLINFR3_SCR_068, ISR Category options are
 *                        updated from MODE to TYPE.
 * V3.0.7:  31.12.2010  : As per SCR ANMCANLINFR3_SCR_087, 
 *                        1. EcuM callback file is included when
 *                           CanWakeupSupport is True.
 *                        2. Space between '#' and 'if' is removed.
 * V3.0.7a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Can_PBTypes.h"      /* CAN Driver Post-Build Config. Header File */
#include "Can_Irq.h"          /* CAN Interrupt Service Header File */
#include "Can_MainServ.h"     /* CAN Main Service Header File */
#include "Can_ModeCntrl.h"    /* CAN Mode Control Service Header File */
#include "Can_Ram.h"          /* CAN Driver RAM Header File */
#include "Can_Tgt.h"          /* CAN Driver Target Header File */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"              /* DET Header File */
#endif
#include "CanIf_Cbk.h"        /* CAN Interface call-back Header File */
#if (CAN_WAKEUP_SUPPORT == STD_ON)
#include "EcuM_Cbk.h"        /* EcuM call-back Header File */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_IRQ_C_AR_MAJOR_VERSION  2
#define CAN_IRQ_C_AR_MINOR_VERSION  2
#define CAN_IRQ_C_AR_PATCH_VERSION  2

/* File version information */
#define CAN_IRQ_C_SW_MAJOR_VERSION  3
#define CAN_IRQ_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CAN_IRQ_AR_MAJOR_VERSION != CAN_IRQ_C_AR_MAJOR_VERSION)
  #error "Can_Irq.c : Mismatch in Specification Major Version"
#endif
#if (CAN_IRQ_AR_MINOR_VERSION != CAN_IRQ_C_AR_MINOR_VERSION)
  #error "Can_Irq.c : Mismatch in Specification Minor Version"
#endif
#if (CAN_IRQ_AR_PATCH_VERSION != CAN_IRQ_C_AR_PATCH_VERSION)
  #error "Can_Irq.c : Mismatch in Specification Patch Version"
#endif
#if (CAN_IRQ_SW_MAJOR_VERSION != CAN_IRQ_C_SW_MAJOR_VERSION)
  #error "Can_Irq.c : Mismatch in Software Major Version"
#endif
#if (CAN_IRQ_SW_MINOR_VERSION != CAN_IRQ_C_SW_MINOR_VERSION)
  #error "Can_Irq.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#if (CAN_CONTROLLER0_RX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER0_RX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER0_RX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER0_RX_ISR(void)
#endif
{

  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER0];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */
  /* Invoke Can_RxProcessing internal function for receive processing */
  Can_RxProcessing(CAN_CONTROLLER0_8BIT_BASE_ADDRESS,
  CAN_CONTROLLER0_16BIT_BASE_ADDRESS, LpController->ucHrhOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER1_RX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER1_RX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER1_RX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER1_RX_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER1];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */
  /* Invoke Can_RxProcessing internal function for receive processing */
  Can_RxProcessing(CAN_CONTROLLER1_8BIT_BASE_ADDRESS,
  CAN_CONTROLLER1_16BIT_BASE_ADDRESS, LpController->ucHrhOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER2_RX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER2_RX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER2_RX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER2_RX_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER2];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */
  /* Invoke Can_RxProcessing internal function for receive processing */
  Can_RxProcessing(CAN_CONTROLLER2_8BIT_BASE_ADDRESS,
  CAN_CONTROLLER2_16BIT_BASE_ADDRESS, LpController->ucHrhOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER3_RX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER3_RX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER3_RX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER3_RX_ISR(void)
#endif
{

  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER3];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */
  /* Invoke Can_RxProcessing internal function for receive processing */
  Can_RxProcessing(CAN_CONTROLLER3_8BIT_BASE_ADDRESS,
  CAN_CONTROLLER3_16BIT_BASE_ADDRESS, LpController->ucHrhOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER4_RX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER4_RX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER4_RX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER4_RX_ISR(void)
#endif
{

  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER4];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */
  /* Invoke Can_RxProcessing internal function for receive processing */
  Can_RxProcessing(CAN_CONTROLLER4_8BIT_BASE_ADDRESS,
  CAN_CONTROLLER4_16BIT_BASE_ADDRESS, LpController->ucHrhOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER5_RX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER5_RX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER5_RX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER5_RX_ISR(void)
#endif
{

  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER5];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */
  /* Invoke Can_RxProcessing internal function for receive processing */
  Can_RxProcessing(CAN_CONTROLLER5_8BIT_BASE_ADDRESS,
  CAN_CONTROLLER5_16BIT_BASE_ADDRESS, LpController->ucHrhOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER0_TX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER0_TX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER0_TX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER0_TX_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER0];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */

  /* Invoke Can_TxConfirmation internal function for transmit confirmation
                                                                  processing */
  Can_TxConfirmationProcessing(CAN_CONTROLLER0_16BIT_BASE_ADDRESS,
                                                   LpController->ssHthOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER1_TX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER1_TX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER1_TX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER1_TX_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER1];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */

  /* Invoke Can_TxConfirmation internal function for transmit confirmation
                                                                  processing */
  Can_TxConfirmationProcessing(CAN_CONTROLLER1_16BIT_BASE_ADDRESS,
                                                   LpController->ssHthOffSetId);
}

#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER2_TX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER2_TX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER2_TX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER2_TX_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER2];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */

  /* Invoke Can_TxConfirmation internal function for transmit confirmation
                                                                  processing */
  Can_TxConfirmationProcessing(CAN_CONTROLLER2_16BIT_BASE_ADDRESS,
                                                   LpController->ssHthOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER3_TX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER3_TX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER3_TX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER3_TX_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER3];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */

  /* Invoke Can_TxConfirmation internal function for transmit confirmation
                                                                  processing */
  Can_TxConfirmationProcessing(CAN_CONTROLLER3_16BIT_BASE_ADDRESS,
                                                   LpController->ssHthOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER4_TX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER4_TX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER4_TX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER4_TX_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER4];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */

  /* Invoke Can_TxConfirmation internal function for transmit confirmation
                                                                  processing */
  Can_TxConfirmationProcessing(CAN_CONTROLLER4_16BIT_BASE_ADDRESS,
                                                   LpController->ssHthOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER5_TX_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER5_TX_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER5_TX_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER5_TX_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  uint8 LucControllerId;

  /* Get the index to Controller Id */
  LucControllerId = Can_GpCntrlIdArray[CAN_CONTROLLER5];
  /* Get the pointer to Controller structure */
  LpController = &Can_GpFirstController[LucControllerId];

  /* MISRA Rule         : 11.3
     Message            : Cast between a pointer to object and an integral type.
     Reason             : This is to access the hardware registers in
                          the code.
     Verification       : However, the part of the code is
                          verified manually and it is not having
                          any impact on code.
  */

  /* Invoke Can_TxConfirmation internal function for transmit confirmation
                                                                  processing */
  Can_TxConfirmationProcessing(CAN_CONTROLLER5_16BIT_BASE_ADDRESS,
                                                   LpController->ssHthOffSetId);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER0_BUSOFF_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER0_BUSOFF_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER0_BUSOFF_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER0_BUSOFF_ISR(void)
#endif
{
  P2VAR(Tdd_Can_AFCan_8bit_CntrlReg, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                 LpCntrlReg8bit;
  /* MISRA Rule        : 11.3
     Message           : Cast between a pointer to object and an integral type.
     Reason            : This is to access the hardware registers in
                         the code.
     Verification      : However, the part of the code is verified manually and
                         it is not having any impact on code.
  */
  /* Get the pointer to control register structure */
  LpCntrlReg8bit = CAN_CONTROLLER0_8BIT_BASE_ADDRESS;
  /* Check whether BusOff event is occurred or not */
  if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_BUSOFF_STS)) == CAN_BUSOFF_STS)
  {
    /*  MISRA Rule        : 16.10
        Message           : Function returns a value which is not being used
        Reason            : Return value not used to achieve better throughput.
        Verification      : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Invoke Can_StopMode internal function to set to initialization mode */
    Can_StopMode(&Can_GpFirstController[CAN_CONTROLLER0]);
    /* Invoke CanIf_ControllerBusOff call-back function to give busoff
                                                                 notification */
    CanIf_ControllerBusOff(CAN_CONTROLLER0);
  } /* if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_ONE)) == CAN_TRUE) */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER1_BUSOFF_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER1_BUSOFF_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER1_BUSOFF_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER1_BUSOFF_ISR(void)
#endif
{
  P2VAR(Tdd_Can_AFCan_8bit_CntrlReg, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                 LpCntrlReg8bit;
  /* MISRA Rule        : 11.3
     Message           : Cast between a pointer to object and an integral type.
     Reason            : This is to access the hardware registers in
                         the code.
     Verification      : However, the part of the code is verified manually and
                         it is not having any impact on code.
  */
  /* Get the pointer to control register structure */
  LpCntrlReg8bit = CAN_CONTROLLER1_8BIT_BASE_ADDRESS;
  /* Check whether BusOff event is occurred or not */
  if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_BUSOFF_STS)) == CAN_BUSOFF_STS)
  {
    /* MISRA Rule      : 16.10
       Message         : Function returns a value which is not being used
       Reason          : Return value not used to achieve better throughput.
       Verification    : However, part of the code is verified manually
                         and it is not having any impact.
    */
    /* Invoke Can_StopMode internal function to set to initialization mode */
    Can_StopMode(&Can_GpFirstController[CAN_CONTROLLER1]);
    /* Invoke CanIf_ControllerBusOff call-back function to give busoff
                                                                 notification */
    CanIf_ControllerBusOff(CAN_CONTROLLER1);
  } /* if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_ONE)) == CAN_TRUE) */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER2_BUSOFF_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER2_BUSOFF_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER2_BUSOFF_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER2_BUSOFF_ISR(void)
#endif
{
  P2VAR(Tdd_Can_AFCan_8bit_CntrlReg, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                 LpCntrlReg8bit;
  /* MISRA Rule        : 11.3
     Message           : Cast between a pointer to object and an integral type.
     Reason            : This is to access the hardware registers in
                         the code.
     Verification      : However, the part of the code is verified manually and
                         it is not having any impact on code.
  */
  /* Get the pointer to control register structure */
  LpCntrlReg8bit = CAN_CONTROLLER2_8BIT_BASE_ADDRESS;
  /* Check whether BusOff event is occurred or not */
  if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_BUSOFF_STS)) == CAN_BUSOFF_STS)
  {
    /*  MISRA Rule        : 16.10
        Message           : Function returns a value which is not being used
        Reason            : Return value not used to achieve better throughput.
        Verification      : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Invoke Can_StopMode internal function to set to initialization mode */
    Can_StopMode(&Can_GpFirstController[CAN_CONTROLLER2]);
    /* Invoke CanIf_ControllerBusOff call-back function to give busoff
                                                                 notification */
    CanIf_ControllerBusOff(CAN_CONTROLLER2);
  } /* if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_ONE)) == CAN_TRUE) */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER3_BUSOFF_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER3_BUSOFF_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER3_BUSOFF_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER3_BUSOFF_ISR(void)
#endif
{
  P2VAR(Tdd_Can_AFCan_8bit_CntrlReg, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                 LpCntrlReg8bit;
  /* MISRA Rule        : 11.3
     Message           : Cast between a pointer to object and an integral type.
     Reason            : This is to access the hardware registers in
                         the code.
     Verification      : However, the part of the code is verified manually and
                         it is not having any impact on code.
  */
  /* Get the pointer to control register structure */
  LpCntrlReg8bit = CAN_CONTROLLER3_8BIT_BASE_ADDRESS;
  /* Check whether BusOff event is occurred or not */
  if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_BUSOFF_STS)) == CAN_BUSOFF_STS)
  {
    /*  MISRA Rule        : 16.10
        Message           : Function returns a value which is not being used
        Reason            : Return value not used to achieve better throughput.
        Verification      : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Invoke Can_StopMode internal function to set to initialization mode */
    Can_StopMode(&Can_GpFirstController[CAN_CONTROLLER3]);
    /* Invoke CanIf_ControllerBusOff call-back function to give busoff
                                                                 notification */
    CanIf_ControllerBusOff(CAN_CONTROLLER3);
  } /* if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_ONE)) == CAN_TRUE) */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER4_BUSOFF_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER4_BUSOFF_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER4_BUSOFF_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER4_BUSOFF_ISR(void)
#endif
{
  P2VAR(Tdd_Can_AFCan_8bit_CntrlReg, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                 LpCntrlReg8bit;
  /* MISRA Rule        : 11.3
     Message           : Cast between a pointer to object and an integral type.
     Reason            : This is to access the hardware registers in
                         the code.
     Verification      : However, the part of the code is verified manually and
                         it is not having any impact on code.
  */
  /* Get the pointer to control register structure */
  LpCntrlReg8bit = CAN_CONTROLLER4_8BIT_BASE_ADDRESS;
  /* Check whether BusOff event is occurred or not */
  if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_BUSOFF_STS)) == CAN_BUSOFF_STS)
  {
    /*  MISRA Rule        : 16.10
        Message           : Function returns a value which is not being used
        Reason            : Return value not used to achieve better throughput.
        Verification      : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Invoke Can_StopMode internal function to set to initialization mode */
    Can_StopMode(&Can_GpFirstController[CAN_CONTROLLER4]);
    /* Invoke CanIf_ControllerBusOff call-back function to give busoff
                                                                 notification */
    CanIf_ControllerBusOff(CAN_CONTROLLER4);
  } /* if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_ONE)) == CAN_TRUE) */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER5_BUSOFF_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_CONTROLLER5_BUSOFF_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_CONTROLLER5_BUSOFF_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_CONTROLLER5_BUSOFF_ISR(void)
#endif
{
  P2VAR(Tdd_Can_AFCan_8bit_CntrlReg, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                 LpCntrlReg8bit;
  /* MISRA Rule        : 11.3
     Message           : Cast between a pointer to object and an integral type.
     Reason            : This is to access the hardware registers in
                         the code.
     Verification      : However, the part of the code is verified manually and
                         it is not having any impact on code.
  */
  /* Get the pointer to control register structure */
  LpCntrlReg8bit = CAN_CONTROLLER5_8BIT_BASE_ADDRESS;
  /* Check whether BusOff event is occurred or not */
  if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_BUSOFF_STS)) == CAN_BUSOFF_STS)
  {
    /*  MISRA Rule        : 16.10
        Message           : Function returns a value which is not being used
        Reason            : Return value not used to achieve better throughput.
        Verification      : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Invoke Can_StopMode internal function to set to initialization mode */
    Can_StopMode(&Can_GpFirstController[CAN_CONTROLLER5]);
    /* Invoke CanIf_ControllerBusOff call-back function to give busoff
                                                                 notification */
    CanIf_ControllerBusOff(CAN_CONTROLLER5);
  } /* if(((LpCntrlReg8bit->ucFcnCminStr) & (CAN_ONE)) == CAN_TRUE) */
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_WAKEUP_INTERRUPTS_TIED == STD_ON)
#if ((CAN_WAKEUP_SUPPORT == STD_ON) || \
                               (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_WAKEUP_TXCANCEL_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_WAKEUP_TXCANCEL_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_WAKEUP_TXCANCEL_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_PRIVATE_DATA) LpWakeuporEvent;
  #endif
  uint8_least LucNoOfController;

  /* Get the pointer to first Controller structure */
  LpController = Can_GpFirstController;
  /* Get the number of Controllers configured */
  LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
  /* Loop for the number of Controllers to check for which controller the
                                                   interrupt has occurred */
  /* Get the pointer to control register structure */
  LpCntrlReg16bit = LpController->pCntrlReg16bit;

  do
  {
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    /* Check whether polling method is configured or not */
    if((((LpController->usIntEnable) & (CAN_WAKEUP_INT_MASK)) ==
                                                        CAN_WAKEUP_INT_MASK) &&
    (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_WAKEUP_STS_MASK)) ==
                                                          CAN_WAKEUP_STS_MASK))
    {
      /* Get the pointer to the Wakeup status flag */
      LpWakeuporEvent = (LpController->pWkpStsFlag);
      /*  MISRA Rule        : 16.10
          Message           : Function returns a value which is not being used
          Reason            : Return value not used to achieve better
                              throughput.
          Verification      : However, part of the code is verified manually
                              and it is not having any impact.
      */
      /* Invoke Can_WakeupMode internalfunction to wakeup the Controller */
      Can_WakeupMode(LpController);
      /* Store the wakeup event */
      *LpWakeuporEvent = CAN_WAKEUP;
      /* Invoke EcuM_CheckWakeup call-back function to give wakeup
                                                                 notification */
      EcuM_CheckWakeup (LpController->ddWakeupSourceId);
      /* Set the Controller Count to 1 to quit from the do-while loop */
      LucNoOfController = CAN_ONE;
    } /* End of check for Wakeup Interrupt */
    else
    #endif
    {
      #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
      if((((LpController->usIntEnable) & (CAN_TXCANCEL_INT_MASK)) ==
                                                          CAN_TXCANCEL_INT_MASK)
      && (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_TXCANCEL_STS_MASK)) ==
                                                       CAN_TXCANCEL_STS_MASK))
      {
        /* Invoke Can_TxCancelConfirmation internal function for transmit
                                         cancellation confirmation processing */
        Can_TxCancellationProcessing(LpController, CAN_TRUE);
        /* Set the Controller Count to 1 to quit from the do-while loop */
        LucNoOfController = CAN_ONE;
      }
      #endif
    }
    /* MISRA Rule         : 17.4
       Message            : Increment or decrement operation
                            performed on pointer(LpController).
       Reason             : Increment operator is used to achieve
                            better throughput.
       Verification       : However, part of the code is verified
                            manually and it is not having any impact.
    */
    /* Increment the pointer to point to next Controller structure */
    LpController++;
    /* Decrement the number of Controller */
    LucNoOfController--;
    /* MISRA Rule         : 13.7
       Message            : The result of this logical operation is always
                            'false'. The value of this 'do - while' control
                            expression is always 'false'. The loop will be
                            executed once.
       Reason             : The result of this logical operation is always
                            false since only one controller is configured.
                            However, when two or more controllers are
                            configured this warning ceases to exist.
       Verification       : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Check whether the number of Controller equals to zero */
  }while(LucNoOfController != CAN_ZERO);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#else
#if (CAN_CONTROLLER0_WAKEUP_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_WAKEUP0_TXCANCEL_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_WAKEUP0_TXCANCEL_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_WAKEUP0_TXCANCEL_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                              (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  #endif
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_PRIVATE_DATA) LpWakeuporEvent;
  #endif
  uint8_least LucNoOfController;

  /* Get the pointer to first Controller structure */
  LpController = Can_GpFirstController;
  /* Get the number of Controllers configured */
  LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
  /* Loop for the number of Controllers to check for which controller the
                                                   interrupt has occurred */
  /* Get the pointer to control register structure */
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                              (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  LpCntrlReg16bit = LpController->pCntrlReg16bit;
  #endif
  do
  {
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    /* Check whether polling method is configured or not */
    if((((LpController->usIntEnable) & (CAN_WAKEUP_INT_MASK)) ==
                                                        CAN_WAKEUP_INT_MASK) &&
    (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_WAKEUP_STS_MASK)) ==
                                                          CAN_WAKEUP_STS_MASK))
    {
      /* Get the pointer to the Wakeup status flag */
      LpWakeuporEvent = (LpController->pWkpStsFlag);
      /*  MISRA Rule        : 16.10
          Message           : Function returns a value which is not being used
          Reason            : Return value not used to achieve better
                              throughput.
          Verification      : However, part of the code is verified manually
                              and it is not having any impact.
      */
      /* Invoke Can_WakeupMode internalfunction to wakeup the Controller */
      Can_WakeupMode(LpController);
      /* Store the wakeup event */
      *LpWakeuporEvent = CAN_WAKEUP;
      /* Invoke EcuM_CheckWakeup call-back function to give wakeup
                                                                 notification */
      EcuM_CheckWakeup (LpController->ddWakeupSourceId);
      /* Set the Controller Count to 1 to quit from the do-while loop */
      LucNoOfController = CAN_ONE;
    } /* End of check for Wakeup Interrupt */
    else
    #endif
    {
      #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
      if((((LpController->usIntEnable) & (CAN_TXCANCEL_INT_MASK)) ==
                                                          CAN_TXCANCEL_INT_MASK)
      && (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_TXCANCEL_STS_MASK)) ==
                                                       CAN_TXCANCEL_STS_MASK))
      {
        /* Invoke Can_TxCancelConfirmation internal function for transmit
                                         cancellation confirmation processing */
        Can_TxCancellationProcessing(LpController, CAN_TRUE);
        /* Set the Controller Count to 1 to quit from the do-while loop */
        LucNoOfController = CAN_ONE;
      }
      #endif
    }
    /* MISRA Rule         : 17.4
       Message            : Increment or decrement operation
                            performed on pointer(LpController).
       Reason             : Increment operator is used to achieve
                            better throughput.
       Verification       : However, part of the code is verified
                            manually and it is not having any impact.
    */
    /* Increment the pointer to point to next Controller structure */
    LpController++;
    /* Decrement the number of Controller */
    LucNoOfController--;
    /* MISRA Rule         : 13.7
       Message            : The result of this logical operation is always
                            'false'. The value of this 'do - while' control
                            expression is always 'false'. The loop will be
                            executed once.
       Reason             : The result of this logical operation is always
                            false since only one controller is configured.
                            However, when two or more controllers are
                            configured this warning ceases to exist.
       Verification       : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Check whether the number of Controller equals to zero */
  }while(LucNoOfController != CAN_ZERO);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER1_WAKEUP_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_WAKEUP1_TXCANCEL_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_WAKEUP1_TXCANCEL_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_WAKEUP1_TXCANCEL_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                              (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  #endif
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_PRIVATE_DATA) LpWakeuporEvent;
  #endif
  uint8_least LucNoOfController;

  /* Get the pointer to first Controller structure */
  LpController = Can_GpFirstController;
  /* Get the number of Controllers configured */
  LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
  /* Loop for the number of Controllers to check for which controller the
                                                   interrupt has occurred */
  /* Get the pointer to control register structure */
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                              (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  LpCntrlReg16bit = LpController->pCntrlReg16bit;
  #endif
  do
  {
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    /* Check whether polling method is configured or not */
    if((((LpController->usIntEnable) & (CAN_WAKEUP_INT_MASK)) ==
                                                        CAN_WAKEUP_INT_MASK) &&
    (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_WAKEUP_STS_MASK)) ==
                                                          CAN_WAKEUP_STS_MASK))
    {
      /* Get the pointer to the Wakeup status flag */
      LpWakeuporEvent = (LpController->pWkpStsFlag);
      /*  MISRA Rule        : 16.10
          Message           : Function returns a value which is not being used
          Reason            : Return value not used to achieve better
                              throughput.
          Verification      : However, part of the code is verified manually
                              and it is not having any impact.
      */
      /* Invoke Can_WakeupMode internalfunction to wakeup the Controller */
      Can_WakeupMode(LpController);
      /* Store the wakeup event */
      *LpWakeuporEvent = CAN_WAKEUP;
      /* Invoke EcuM_CheckWakeup call-back function to give wakeup
                                                                 notification */
      EcuM_CheckWakeup (LpController->ddWakeupSourceId);
      /* Set the Controller Count to 1 to quit from the do-while loop */
      LucNoOfController = CAN_ONE;
    } /* End of check for Wakeup Interrupt */
    else
    #endif
    {
      #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
      if((((LpController->usIntEnable) & (CAN_TXCANCEL_INT_MASK)) ==
                                                          CAN_TXCANCEL_INT_MASK)
      && (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_TXCANCEL_STS_MASK)) ==
                                                       CAN_TXCANCEL_STS_MASK))
      {
        /* Invoke Can_TxCancelConfirmation internal function for transmit
                                         cancellation confirmation processing */
        Can_TxCancellationProcessing(LpController, CAN_TRUE);
        /* Set the Controller Count to 1 to quit from the do-while loop */
        LucNoOfController = CAN_ONE;
      }
      #endif
    }
    /* MISRA Rule         : 17.4
       Message            : Increment or decrement operation
                            performed on pointer(LpController).
       Reason             : Increment operator is used to achieve
                            better throughput.
       Verification       : However, part of the code is verified
                            manually and it is not having any impact.
    */
    /* Increment the pointer to point to next Controller structure */
    LpController++;
    /* Decrement the number of Controller */
    LucNoOfController--;
    /* MISRA Rule         : 13.7
       Message            : The result of this logical operation is always
                            'false'. The value of this 'do - while' control
                            expression is always 'false'. The loop will be
                            executed once.
       Reason             : The result of this logical operation is always
                            false since only one controller is configured.
                            However, when two or more controllers are
                            configured this warning ceases to exist.
       Verification       : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Check whether the number of Controller equals to zero */
  }while(LucNoOfController != CAN_ZERO);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER2_WAKEUP_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_WAKEUP2_TXCANCEL_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_WAKEUP2_TXCANCEL_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_WAKEUP2_TXCANCEL_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                              (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  #endif
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_PRIVATE_DATA) LpWakeuporEvent;
  #endif
  uint8_least LucNoOfController;

  /* Get the pointer to first Controller structure */
  LpController = Can_GpFirstController;
  /* Get the number of Controllers configured */
  LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
  /* Loop for the number of Controllers to check for which controller the
                                                   interrupt has occurred */
  /* Get the pointer to control register structure */
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                              (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  LpCntrlReg16bit = LpController->pCntrlReg16bit;
  #endif
  do
  {
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    /* Check whether polling method is configured or not */
    if((((LpController->usIntEnable) & (CAN_WAKEUP_INT_MASK)) ==
                                                        CAN_WAKEUP_INT_MASK) &&
    (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_WAKEUP_STS_MASK)) ==
                                                          CAN_WAKEUP_STS_MASK))
    {
      /* Get the pointer to the Wakeup status flag */
      LpWakeuporEvent = (LpController->pWkpStsFlag);
      /*  MISRA Rule        : 16.10
          Message           : Function returns a value which is not being used
          Reason            : Return value not used to achieve better
                              throughput.
          Verification      : However, part of the code is verified manually
                              and it is not having any impact.
      */
      /* Invoke Can_WakeupMode internalfunction to wakeup the Controller */
      Can_WakeupMode(LpController);
      /* Store the wakeup event */
      *LpWakeuporEvent = CAN_WAKEUP;
      /* Invoke EcuM_CheckWakeup call-back function to give wakeup
                                                                 notification */
      EcuM_CheckWakeup (LpController->ddWakeupSourceId);
      /* Set the Controller Count to 1 to quit from the do-while loop */
      LucNoOfController = CAN_ONE;
    } /* End of check for Wakeup Interrupt */
    else
    #endif
    {
      #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
      if((((LpController->usIntEnable) & (CAN_TXCANCEL_INT_MASK)) ==
                                                          CAN_TXCANCEL_INT_MASK)
      && (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_TXCANCEL_STS_MASK)) ==
                                                       CAN_TXCANCEL_STS_MASK))
      {
        /* Invoke Can_TxCancelConfirmation internal function for transmit
                                         cancellation confirmation processing */
        Can_TxCancellationProcessing(LpController, CAN_TRUE);
        /* Set the Controller Count to 1 to quit from the do-while loop */
        LucNoOfController = CAN_ONE;
      }
      #endif
    }
    /* MISRA Rule         : 17.4
       Message            : Increment or decrement operation
                            performed on pointer(LpController).
       Reason             : Increment operator is used to achieve
                            better throughput.
       Verification       : However, part of the code is verified
                            manually and it is not having any impact.
    */
    /* Increment the pointer to point to next Controller structure */
    LpController++;
    /* Decrement the number of Controller */
    LucNoOfController--;
    /* MISRA Rule         : 13.7
       Message            : The result of this logical operation is always
                            'false'. The value of this 'do - while' control
                            expression is always 'false'. The loop will be
                            executed once.
       Reason             : The result of this logical operation is always
                            false since only one controller is configured.
                            However, when two or more controllers are
                            configured this warning ceases to exist.
       Verification       : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Check whether the number of Controller equals to zero */
  }while(LucNoOfController != CAN_ZERO);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER3_WAKEUP_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_WAKEUP3_TXCANCEL_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_WAKEUP3_TXCANCEL_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_WAKEUP3_TXCANCEL_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_PRIVATE_DATA) LpWakeuporEvent;
  #endif
  uint8_least LucNoOfController;

  /* Get the pointer to first Controller structure */
  LpController = Can_GpFirstController;
  /* Get the number of Controllers configured */
  LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
  /* Loop for the number of Controllers to check for which controller the
                                                   interrupt has occurred */
  /* Get the pointer to control register structure */
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                              (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  LpCntrlReg16bit = LpController->pCntrlReg16bit;
 #endif
  do
  {
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    /* Check whether polling method is configured or not */
    if((((LpController->usIntEnable) & (CAN_WAKEUP_INT_MASK)) ==
                                                        CAN_WAKEUP_INT_MASK) &&
    (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_WAKEUP_STS_MASK)) ==
                                                          CAN_WAKEUP_STS_MASK))
    {
      /* Get the pointer to the Wakeup status flag */
      LpWakeuporEvent = (LpController->pWkpStsFlag);
      /*  MISRA Rule        : 16.10
          Message           : Function returns a value which is not being used
          Reason            : Return value not used to achieve better
                              throughput.
          Verification      : However, part of the code is verified manually
                              and it is not having any impact.
      */
      /* Invoke Can_WakeupMode internalfunction to wakeup the Controller */
      Can_WakeupMode(LpController);
      /* Store the wakeup event */
      *LpWakeuporEvent = CAN_WAKEUP;
      /* Invoke EcuM_CheckWakeup call-back function to give wakeup
                                                                 notification */
      EcuM_CheckWakeup (LpController->ddWakeupSourceId);
      /* Set the Controller Count to 1 to quit from the do-while loop */
      LucNoOfController = CAN_ONE;
    } /* End of check for Wakeup Interrupt */
    else
    #endif
    {
      #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
      if((((LpController->usIntEnable) & (CAN_TXCANCEL_INT_MASK)) ==
                                                          CAN_TXCANCEL_INT_MASK)
      && (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_TXCANCEL_STS_MASK)) ==
                                                       CAN_TXCANCEL_STS_MASK))
      {
        /* Invoke Can_TxCancelConfirmation internal function for transmit
                                         cancellation confirmation processing */
        Can_TxCancellationProcessing(LpController, CAN_TRUE);
        /* Set the Controller Count to 1 to quit from the do-while loop */
        LucNoOfController = CAN_ONE;
      }
      #endif
    }
    /* MISRA Rule         : 17.4
       Message            : Increment or decrement operation
                            performed on pointer(LpController).
       Reason             : Increment operator is used to achieve
                            better throughput.
       Verification       : However, part of the code is verified
                            manually and it is not having any impact.
    */
    /* Increment the pointer to point to next Controller structure */
    LpController++;
    /* Decrement the number of Controller */
    LucNoOfController--;
    /* MISRA Rule         : 13.7
       Message            : The result of this logical operation is always
                            'false'. The value of this 'do - while' control
                            expression is always 'false'. The loop will be
                            executed once.
       Reason             : The result of this logical operation is always
                            false since only one controller is configured.
                            However, when two or more controllers are
                            configured this warning ceases to exist.
       Verification       : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Check whether the number of Controller equals to zero */
  }while(LucNoOfController != CAN_ZERO);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER4_WAKEUP_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_WAKEUP4_TXCANCEL_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_WAKEUP4_TXCANCEL_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_WAKEUP4_TXCANCEL_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                               (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  #endif
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_PRIVATE_DATA) LpWakeuporEvent;
  #endif
  uint8_least LucNoOfController;

  /* Get the pointer to first Controller structure */
  LpController = Can_GpFirstController;
  /* Get the number of Controllers configured */
  LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
  /* Loop for the number of Controllers to check for which controller the
                                                   interrupt has occurred */
  /* Get the pointer to control register structure */
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                               (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  LpCntrlReg16bit = LpController->pCntrlReg16bit;
  #endif

  do
  {
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    /* Check whether polling method is configured or not */
    if((((LpController->usIntEnable) & (CAN_WAKEUP_INT_MASK)) ==
                                                        CAN_WAKEUP_INT_MASK) &&
    (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_WAKEUP_STS_MASK)) ==
                                                          CAN_WAKEUP_STS_MASK))
    {
      /* Get the pointer to the Wakeup status flag */
      LpWakeuporEvent = (LpController->pWkpStsFlag);
      /*  MISRA Rule        : 16.10
          Message           : Function returns a value which is not being used
          Reason            : Return value not used to achieve better
                              throughput.
          Verification      : However, part of the code is verified manually
                              and it is not having any impact.
      */
      /* Invoke Can_WakeupMode internalfunction to wakeup the Controller */
      Can_WakeupMode(LpController);
      /* Store the wakeup event */
      *LpWakeuporEvent = CAN_WAKEUP;
      /* Invoke EcuM_CheckWakeup call-back function to give wakeup
                                                                 notification */
      EcuM_CheckWakeup (LpController->ddWakeupSourceId);
      /* Set the Controller Count to 1 to quit from the do-while loop */
      LucNoOfController = CAN_ONE;
    } /* End of check for Wakeup Interrupt */
    else
    #endif
    {
      #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
      if((((LpController->usIntEnable) & (CAN_TXCANCEL_INT_MASK)) ==
                                                          CAN_TXCANCEL_INT_MASK)
      && (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_TXCANCEL_STS_MASK)) ==
                                                       CAN_TXCANCEL_STS_MASK))
      {
        /* Invoke Can_TxCancelConfirmation internal function for transmit
                                         cancellation confirmation processing */
        Can_TxCancellationProcessing(LpController, CAN_TRUE);
        /* Set the Controller Count to 1 to quit from the do-while loop */
        LucNoOfController = CAN_ONE;
      }
      #endif
    }
    /* MISRA Rule         : 17.4
       Message            : Increment or decrement operation
                            performed on pointer(LpController).
       Reason             : Increment operator is used to achieve
                            better throughput.
       Verification       : However, part of the code is verified
                            manually and it is not having any impact.
    */
    /* Increment the pointer to point to next Controller structure */
    LpController++;
    /* Decrement the number of Controller */
    LucNoOfController--;
    /* MISRA Rule         : 13.7
       Message            : The result of this logical operation is always
                            'false'. The value of this 'do - while' control
                            expression is always 'false'. The loop will be
                            executed once.
       Reason             : The result of this logical operation is always
                            false since only one controller is configured.
                            However, when two or more controllers are
                            configured this warning ceases to exist.
       Verification       : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Check whether the number of Controller equals to zero */
  }while(LucNoOfController != CAN_ZERO);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

#if (CAN_CONTROLLER5_WAKEUP_INTERRUPT == STD_ON)
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, CAN_AFCAN_PUBLIC_CODE) CAN_WAKEUP5_TXCANCEL_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(CAN_WAKEUP5_TXCANCEL_ISR)
#elif (CAN_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, CAN_AFCAN_PUBLIC_CODE)CAN_WAKEUP5_TXCANCEL_ISR(void)
#endif
{
  P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST)
                                                                   LpController;
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                              (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg,AUTOMATIC,CAN_AFCAN_PRIVATE_CONST)
                                                                LpCntrlReg16bit;
  #endif
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_PRIVATE_DATA) LpWakeuporEvent;
  #endif
  uint8_least LucNoOfController;

  /* Get the pointer to first Controller structure */
  LpController = Can_GpFirstController;
  /* Get the number of Controllers configured */
  LucNoOfController = CAN_MAX_NUMBER_OF_CONTROLLER;
  /* Loop for the number of Controllers to check for which controller the
                                                   interrupt has occurred */
  /* Get the pointer to control register structure */
  #if ((CAN_WAKEUP_SUPPORT == STD_ON)|| \
                              (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON))
  LpCntrlReg16bit = LpController->pCntrlReg16bit;
  #endif

  do
  {
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    /* Check whether polling method is configured or not */
    if((((LpController->usIntEnable) & (CAN_WAKEUP_INT_MASK)) ==
                                                        CAN_WAKEUP_INT_MASK) &&
    (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_WAKEUP_STS_MASK)) ==
                                                          CAN_WAKEUP_STS_MASK))
    {
      /* Get the pointer to the Wakeup status flag */
      LpWakeuporEvent = (LpController->pWkpStsFlag);
      /*  MISRA Rule        : 16.10
          Message           : Function returns a value which is not being used
          Reason            : Return value not used to achieve better
                              throughput.
          Verification      : However, part of the code is verified manually
                              and it is not having any impact.
      */
      /* Invoke Can_WakeupMode internalfunction to wakeup the Controller */
      Can_WakeupMode(LpController);
      /* Store the wakeup event */
      *LpWakeuporEvent = CAN_WAKEUP;
      /* Invoke EcuM_CheckWakeup call-back function to give wakeup
                                                                 notification */
      EcuM_CheckWakeup (LpController->ddWakeupSourceId);
      /* Set the Controller Count to 1 to quit from the do-while loop */
      LucNoOfController = CAN_ONE;
    } /* End of check for Wakeup Interrupt */
    else
    #endif
    {
      #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
      if((((LpController->usIntEnable) & (CAN_TXCANCEL_INT_MASK)) ==
                                                          CAN_TXCANCEL_INT_MASK)
      && (((LpCntrlReg16bit->usFcnCmisCtl) & (CAN_TXCANCEL_STS_MASK)) ==
                                                       CAN_TXCANCEL_STS_MASK))
      {
        /* Invoke Can_TxCancelConfirmation internal function for transmit
                                         cancellation confirmation processing */
        Can_TxCancellationProcessing(LpController, CAN_TRUE);
        /* Set the Controller Count to 1 to quit from the do-while loop */
        LucNoOfController = CAN_ONE;
      }
      #endif
    }
    /* MISRA Rule         : 17.4
       Message            : Increment or decrement operation
                            performed on pointer(LpController).
       Reason             : Increment operator is used to achieve
                            better throughput.
       Verification       : However, part of the code is verified
                            manually and it is not having any impact.
    */
    /* Increment the pointer to point to next Controller structure */
    LpController++;
    /* Decrement the number of Controller */
    LucNoOfController--;
    /* MISRA Rule         : 13.7
       Message            : The result of this logical operation is always
                            'false'. The value of this 'do - while' control
                            expression is always 'false'. The loop will be
                            executed once.
       Reason             : The result of this logical operation is always
                            false since only one controller is configured.
                            However, when two or more controllers are
                            configured this warning ceases to exist.
       Verification       : However, part of the code is verified manually
                            and it is not having any impact.
    */
    /* Check whether the number of Controller equals to zero */
  }while(LucNoOfController != CAN_ZERO);
}
#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif
#endif


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
