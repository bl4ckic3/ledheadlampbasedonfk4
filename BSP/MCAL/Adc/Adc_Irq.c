/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Adc_Irq.c                                                   */
/* Version      = 3.1.3                                                       */
/* Date         = 04-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the ADC Driver Component                                  */
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
 * V3.0.0:  10-Jul-2009  : Initial version
 *
 * V3.0.1:  12-Oct-2009  : As per SCR 052, the following changes are made
 *                         1. Template changes are made.
 *                         2. The prototype of the function call Adc_Isr
 *                            and Adc_DmaIsr are updated based on the priority.
 *
 * V3.0.2:  02-Dec-2009  : As per SCR 157, the passed parameter for Adc_DmaIsr
 *                         function is updated.
 *
 * V3.0.3:  18-Mar-2010  : As per SCR 231, the ISR function names for HW Unit 1
 *                         is updated.
 *
 * V3.0.4:  01-Jul-2010  : As per SCR 295, file is updated to support ISR
 *                         Category configuration by a pre-compile
 *                         option.
 * V3.0.5:  20-Jul-2010  : As per SCR 309, ISR Category options are updated
 *                         from MODE to TYPE.
 *
 * V3.1.0:  27-Jul-2011  : Modified for DK-4
 * V3.1.1:  04-Oct-2011  : Added comments for the violation of MISRA rule 19.1
 * V3.1.2:  14-Feb-2012  : Merged the fixes done for Fx4L Adc driver
 *
 * V3.1.3:  04-Jun-2012  : As per SCR 019, the following changes are made
 *                         1. Compiler version is removed from environment 
 *                            section.
 *                         2. File version is changed.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Adc.h"
#include "Adc_Private.h"
#include "Adc_PBTypes.h"
#include "Adc_LTTypes.h"
#include "Adc_Irq.h"
#include "Adc_Ram.h"

#if(ADC_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Adc.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification version information */
#define ADC_IRQ_C_AR_MAJOR_VERSION    ADC_AR_MAJOR_VERSION_VALUE
#define ADC_IRQ_C_AR_MINOR_VERSION    ADC_AR_MINOR_VERSION_VALUE
#define ADC_IRQ_C_AR_PATCH_VERSION    ADC_AR_PATCH_VERSION_VALUE

/* File version information */
#define ADC_IRQ_C_SW_MAJOR_VERSION    3
#define ADC_IRQ_C_SW_MINOR_VERSION    1
#define ADC_IRQ_C_SW_PATCH_VERSION    3

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (ADC_IRQ_AR_MAJOR_VERSION != ADC_IRQ_C_AR_MAJOR_VERSION)
  #error "Adc_Irq.c : Mismatch in Specification Major Version"
#endif

#if (ADC_IRQ_AR_MINOR_VERSION != ADC_IRQ_C_AR_MINOR_VERSION)
  #error "Adc_Irq.c : Mismatch in Specification Minor Version"
#endif

#if (ADC_IRQ_AR_PATCH_VERSION != ADC_IRQ_C_AR_PATCH_VERSION)
  #error "Adc_Irq.c : Mismatch in Specification Patch Version"
#endif

#if (ADC_IRQ_SW_MAJOR_VERSION != ADC_IRQ_C_SW_MAJOR_VERSION)
  #error "Adc_Irq.c : Mismatch in Major Version"
#endif

#if (ADC_IRQ_SW_MINOR_VERSION != ADC_IRQ_C_SW_MINOR_VERSION)
  #error "Adc_Irq.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : ADCn_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt Service routines for the ADC where
**                        n represents instances of the hardware unit.
**                        component.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
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
**                        Function(s) invoked:
**                        Adc_Isr
*******************************************************************************/

#if (ADC0_CG0_ISR_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
  /* MISRA Rule         : 19.1                            */
  /* Message            : #include statements in a file   */
  /*                      should only be preceded by other*/
  /*                      preprocessor directives or      */
  /*                      comments.                       */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */
#include "MemMap.h"

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC0_CG0_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC0_CG0_ISR)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC0_CG0_ISR(void)
#endif
{
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* HW unit 0 and CGm unit 0 */
  Adc_Isr(ADC_ZERO, ADC_ZERO);
  #else
  /* HW unit 0 */
  Adc_Isr(ADC_ZERO);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* #if (ADC0_CG0_ISR_API == STD_ON) */


#if (ADC0_CG1_ISR_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC0_CG1_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC0_CG1_ISR)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC0_CG1_ISR(void)
#endif
{
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* HW unit 0 and CGm unit 1 */
  Adc_Isr(ADC_ZERO, ADC_ONE);
  #else
  /* HW unit 0 */
  Adc_Isr(ADC_ZERO);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* #if (ADC0_CG1_ISR_API == STD_ON) */


#if (ADC0_CG2_ISR_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC0_CG2_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC0_CG2_ISR)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC0_CG2_ISR(void)
#endif
{
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* HW unit 0 and CGm unit 2 */
  Adc_Isr(ADC_ZERO, ADC_TWO);
  #else
  /* HW unit 0 */
  Adc_Isr(ADC_ZERO);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* #if (ADC0_CG2_ISR_API == STD_ON) */


#if (ADC1_CG0_ISR_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC1_CG0_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC1_CG0_ISR)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC1_CG0_ISR(void)
#endif
{
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* HW unit 1 and CGm unit 0 */
  Adc_Isr(ADC_ONE, ADC_ZERO);
  #else
  /* HW unit 1 */
  Adc_Isr(ADC_ONE);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* #if (ADC1_CG0_ISR_API == STD_ON) */


#if (ADC1_CG1_ISR_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC1_CG1_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC1_CG1_ISR)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC1_CG1_ISR(void)
#endif
{
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* HW unit 1 and CGm unit 1 */
  Adc_Isr(ADC_ONE, ADC_ONE);
  #else
  /* HW unit 1 */
  Adc_Isr(ADC_ONE);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* #if (ADC1_CG1_ISR_API == STD_ON) */


#if (ADC1_CG2_ISR_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC1_CG2_ISR(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC1_CG2_ISR)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC1_CG2_ISR(void)
#endif
{
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* HW unit 1 and CGm unit 2 */
  Adc_Isr(ADC_ONE, ADC_TWO);
  #else
  /* HW unit 1 */
  Adc_Isr(ADC_ONE);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* #if (ADC1_CG2_ISR_API == STD_ON) */


/*******************************************************************************
** Function Name        : ADC_DmaIsrn
**
** Service ID           : NA
**
** Description          : These are DMA Interrupt Service routines for the ADC
**                        where n represents DMA channel Id
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
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
**                        Function(s) invoked:
**                        Adc_Isr
*******************************************************************************/

#if (ADC_DMA_ISR_CH0_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH0(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH0)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH0(void)
#endif
{
  /* DMA Channel 0 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[0], Adc_GpDmaCGUnitMapping[0]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[0]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH1_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH1(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH1)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH1(void)
#endif
{
  /* DMA Channel 1 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[1], Adc_GpDmaCGUnitMapping[1]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[1]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH2_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH2(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH2)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH2(void)
#endif
{
  /* DMA Channel 2 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[2], Adc_GpDmaCGUnitMapping[2]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[2]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH3_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH3(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH3)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH3(void)
#endif
{
  /* DMA Channel 3 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[3], Adc_GpDmaCGUnitMapping[3]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[3]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH4_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH4(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH4)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH4(void)
#endif
{
  /* DMA Channel 4 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[4], Adc_GpDmaCGUnitMapping[4]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[4]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH5_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH5(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH5)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH5(void)
#endif
{
  /* DMA Channel 5 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[5], Adc_GpDmaCGUnitMapping[5]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[5]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH6_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH6(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH6)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH6(void)
#endif
{
  /* DMA Channel 6 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[6], Adc_GpDmaCGUnitMapping[6]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[6]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH7_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH7(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH7)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH7(void)
#endif
{
  /* DMA Channel 7 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[7], Adc_GpDmaCGUnitMapping[7]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[7]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH8_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH8(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH8)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH8(void)
#endif
{
  /* DMA Channel 8 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[8], Adc_GpDmaCGUnitMapping[8]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[8]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH9_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH9(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH9)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH9(void)
#endif
{
  /* DMA Channel 9 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[9], Adc_GpDmaCGUnitMapping[9]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[9]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH10_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH10(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH10)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH10(void)
#endif
{
  /* DMA Channel 10 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[10], Adc_GpDmaCGUnitMapping[10]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[10]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH11_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH11(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH11)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH11(void)
#endif
{
  /* DMA Channel 11 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[11], Adc_GpDmaCGUnitMapping[11]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[11]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH12_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH12(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH12)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH12(void)
#endif
{
  /* DMA Channel 12 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[12], Adc_GpDmaCGUnitMapping[12]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[12]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH13_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH13(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH13)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH13(void)
#endif
{
  /* DMA Channel 13 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[13], Adc_GpDmaCGUnitMapping[13]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[13]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH14_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH14(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH14)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH14(void)
#endif
{
  /* DMA Channel 14 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[14], Adc_GpDmaCGUnitMapping[14]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[14]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

#if (ADC_DMA_ISR_CH15_API == STD_ON)
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/* MCAL_ISR_TYPE_TOOLCHAIN - Toolchain defines the interrupt mapping */
#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
_INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH15(void)
/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
ISR(ADC_DMA_ISR_CH15)
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH15(void)
#endif
{
  /* DMA Channel 15 */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[15], Adc_GpDmaCGUnitMapping[15]);
  #else
  Adc_DmaIsr(Adc_GpDmaHWUnitMapping[15]);
  #endif
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
