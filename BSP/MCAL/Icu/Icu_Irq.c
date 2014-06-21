/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu_Irq.c                                                   */
/* Version      = 3.0.2a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains ISR functions for all Timers and External Interrupts of */
/* the ICU Driver Component                                                   */
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
 * V3.0.0:  26-Aug-2009  : Initial version
 *
 * V3.0.1:  28-Jun-2010  : As per SCR 286, following changes are made:
 *                           1. ISRs for Timer Array Unit B are added.
 *                           2. File is updated to support an ISR Category
 *                              support configurable by a pre-compile option.
 *
 * V3.0.2:  20-Jul-2010  : As per SCR 308, ICU_INTERRUPT_MODE is renamed 
 *                         as ICU_INTERRUPT_TYPE.
 * V3.0.2a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Icu.h"
#include "Icu_Irq.h"
#include "Icu_PBTypes.h"
#include "Icu_LLDriver.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define ICU_IRQ_C_AR_MAJOR_VERSION    ICU_AR_MAJOR_VERSION_VALUE
#define ICU_IRQ_C_AR_MINOR_VERSION    ICU_AR_MINOR_VERSION_VALUE
#define ICU_IRQ_C_AR_PATCH_VERSION    ICU_AR_PATCH_VERSION_VALUE

/* File version information */
#define ICU_IRQ_C_SW_MAJOR_VERSION    3
#define ICU_IRQ_C_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/


#if (ICU_IRQ_AR_MAJOR_VERSION != ICU_IRQ_C_AR_MAJOR_VERSION)
  #error "Icu_Irq.c : Mismatch in Specification Major Version"
#endif

#if (ICU_IRQ_AR_MINOR_VERSION != ICU_IRQ_C_AR_MINOR_VERSION)
  #error "Icu_Irq.c : Mismatch in Specification Minor Version"
#endif

#if (ICU_IRQ_AR_PATCH_VERSION != ICU_IRQ_C_AR_PATCH_VERSION)
  #error "Icu_Irq.c : Mismatch in Specification Patch Version"
#endif

#if (ICU_IRQ_SW_MAJOR_VERSION != ICU_IRQ_C_SW_MAJOR_VERSION)
  #error "Icu_Irq.c : Mismatch in Major Version"
#endif

#if (ICU_IRQ_SW_MINOR_VERSION != ICU_IRQ_C_SW_MINOR_VERSION)
  #error "Icu_Irq.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : TAUAn_CHm_ISR
**
** Service ID           : None
**
** Description          : These are Interrupt Service routines for the Timer
**                        TAUA, where n represents TAU number and
**                        m represents channel number associated with each
**                        TAU.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        None
**
**                        Function(s) invoked:
**                        Icu_TimerIsr
**
*******************************************************************************/

#if (ICU_TAUA0_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH0_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH1_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH2_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH3_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH4_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH5_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH6_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH7_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH8_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH9_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH10_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH11_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH12_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH13_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH14_ISR_API == STD_ON) */

#if (ICU_TAUA0_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA0_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA0_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA0_CH15_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH0_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH1_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH2_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH3_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH4_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH5_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH6_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH7_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH8_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH9_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH10_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH11_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH12_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH13_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH14_ISR_API == STD_ON) */

#if (ICU_TAUA1_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA1_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA1_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA1_CH15_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH0_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH1_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH2_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH3_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH4_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH5_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH6_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH7_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH8_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH9_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH10_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH11_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH12_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH13_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH14_ISR_API == STD_ON) */

#if (ICU_TAUA2_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA2_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA2_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA2_CH15_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH0_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH1_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH2_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH3_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH4_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH5_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH6_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH7_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH8_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH9_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH10_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH11_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH12_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH13_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH14_ISR_API == STD_ON) */

#if (ICU_TAUA3_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA3_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA3_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA3_CH15_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH0_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH1_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH2_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH3_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH4_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH5_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH6_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH7_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH8_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH9_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH10_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH11_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH12_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH13_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH14_ISR_API == STD_ON) */

#if (ICU_TAUA4_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA4_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA4_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA4_CH15_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH0_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH1_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH2_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH3_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH4_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH5_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH6_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH7_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH8_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH9_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH10_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH11_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH12_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH13_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH14_ISR_API == STD_ON) */

#if (ICU_TAUA5_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA5_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA5_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA5_CH15_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH0_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH1_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH2_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH3_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH4_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH5_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH6_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH7_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH8_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH9_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH10_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH11_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH12_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH13_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH14_ISR_API == STD_ON) */

#if (ICU_TAUA6_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA6_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA6_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA6_CH15_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH0_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH1_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH2_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH3_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH4_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH5_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH6_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH7_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH8_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH9_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH10_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH11_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH12_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH13_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH14_ISR_API == STD_ON) */

#if (ICU_TAUA7_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA7_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA7_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA7_CH15_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH0_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH1_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH2_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH3_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH4_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH5_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH6_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH7_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH8_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH9_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH10_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH11_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH12_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH13_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH14_ISR_API == STD_ON) */

#if (ICU_TAUA8_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUA8_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUA8_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUA8_CH15_ISR_API == STD_ON) */

/*******************************************************************************
** Function Name        : TAUBn_CHm_ISR
**
** Service ID           : None
**
** Description          : These are Interrupt Service routines for the Timer
**                        TAUB, where n represents TAU number and
**                        m represents channel number associated with each
**                        TAU.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        None
**
**                        Function(s) invoked:
**                        Icu_TimerIsr
**
*******************************************************************************/
#if (ICU_TAUB1_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH0_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH1_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH2_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH3_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH4_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH5_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH6_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH7_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH8_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH9_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH10_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH11_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH12_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH13_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH14_ISR_API == STD_ON) */

#if (ICU_TAUB1_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB1_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB1_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB1_CH15_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH0_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH1_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH2_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH3_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH4_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH4_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH5_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH5_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH6_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH6_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH7_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH7_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH8_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH8_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH9_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH9_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH10_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH10_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH11_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH11_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH12_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH12_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH13_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH13_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH14_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH14_ISR_API == STD_ON) */

#if (ICU_TAUB2_CH15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUB2_CH15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH15_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUB2_CH15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUB2_CH15_ISR_API == STD_ON) */


#if (ICU_TAUJ0_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ0_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ0_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ0_CH0_ISR_API == STD_ON) */

#if (ICU_TAUJ0_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ0_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ0_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ0_CH1_ISR_API == STD_ON) */

#if (ICU_TAUJ0_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ0_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ0_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ0_CH2_ISR_API == STD_ON) */

#if (ICU_TAUJ0_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ0_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ0_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ0_CH3_ISR_API == STD_ON) */

#if (ICU_TAUJ1_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ1_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ1_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ1_CH0_ISR_API == STD_ON) */

#if (ICU_TAUJ1_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ1_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ1_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ1_CH1_ISR_API == STD_ON) */

#if (ICU_TAUJ1_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ1_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ1_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ1_CH2_ISR_API == STD_ON) */

#if (ICU_TAUJ1_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ1_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ1_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ1_CH3_ISR_API == STD_ON) */

#if (ICU_TAUJ2_CH0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ2_CH0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH0_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ2_CH0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ2_CH0_ISR_API == STD_ON) */

#if (ICU_TAUJ2_CH1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ2_CH1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH1_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ2_CH1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ2_CH1_ISR_API == STD_ON) */

#if (ICU_TAUJ2_CH2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ2_CH2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH2_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ2_CH2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ2_CH2_ISR_API == STD_ON) */

#if (ICU_TAUJ2_CH3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(TAUJ2_CH3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH3_ISR(void)
#endif
{
  Icu_TimerIsr(ICU_TAUJ2_CH3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_TAUJ2_CH3_ISR_API == STD_ON) */

/*******************************************************************************
** Function Name        : EXTERNAL_INTERRUPT_n_ISR
**
** Service ID           : None
**
** Description          : These are Interrupt Service routines for the External
**                        Interrupts where n represents instances of external
**                        interrupts (0 to 15).
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        None
**
**                        Function(s) invoked:
**                        Icu_ExternalInterruptIsr
**
*******************************************************************************/
#if (ICU_EXT_INTP_0_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_0_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_0_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_0_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_0);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_0_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_1_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_1_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_1_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_1_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_1);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_1_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_2_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_2_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_2_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_2_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_2);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_2_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_3_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_3_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_3_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_3_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_3);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_3_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_4_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_4_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_4_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_4_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_4);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_4_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_5_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_5_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_5_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_5_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_5);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_5_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_6_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_6_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_6_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_6_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_6);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_6_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_7_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_7_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_7_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_7_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_7);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_7_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_8_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_8_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_8_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_8_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_8);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_8_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_9_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_9_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_9_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_9_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_9);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_9_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_10_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_10_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_10_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_10_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_10);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_10_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_11_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_11_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_11_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_11_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_11);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_11_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_12_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_12_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_12_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_12_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_12);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_12_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_13_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_13_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_13_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_13_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_13);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_13_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_14_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_14_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_14_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_14_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_14);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_14_ISR_API == STD_ON) */

#if (ICU_EXT_INTP_15_ISR_API == STD_ON)
#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_15_ISR(void)

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(EXTERNAL_INTERRUPT_15_ISR)

/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_15_ISR(void)
#endif
{
  Icu_ExternalInterruptIsr(ICU_EXTP_INTP_15);
}

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (ICU_EXT_INTP_15_ISR_API == STD_ON) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
