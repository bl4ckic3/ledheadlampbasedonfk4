/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Adc_Irq.h                                                   */
/* Version      = 3.1.2a                                                      */
/* Date         = 23-Apr-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Interrupt routines.                                           */
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
 *
 * V3.0.2:  01-Jul-2010  : As per SCR 295, file is updated to support ISR
 *                         Category configuration by a pre-compile
 *                         option.
 * V3.0.3:  20-Jul-2010  : As per SCR 309, ISR Category options are updated
 *                         from MODE to TYPE.
 *
 * V3.1.0:  27-Jul-2011  : Modified for DK-4
 * V3.1.1:  14-Feb-2012  : Merged the fixes done for Fx4L Adc driver
 *
 * V3.1.2:  04-Jun-2012  : As per SCR 019, the following changes are made
 *                         1. Compiler version is removed from environment 
 *                            section.
 *                         2. File version is changed.
 *
 * V3.1.2a: 23-Apr-2013  : As per Matis #11228, inclusion location of Os.h
 *                         is changed.
 */
/******************************************************************************/

#ifndef ADC_IRQ_H
#define ADC_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* The default option for ISR Category MCAL_ISR_TYPE_TOOLCHAIN */
#ifndef ADC_INTERRUPT_TYPE
#define ADC_INTERRUPT_TYPE MCAL_ISR_TYPE_TOOLCHAIN
#endif

#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
/* Use OS */
//#include "Os.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define ADC_IRQ_AR_MAJOR_VERSION    ADC_AR_MAJOR_VERSION_VALUE
#define ADC_IRQ_AR_MINOR_VERSION    ADC_AR_MINOR_VERSION_VALUE
#define ADC_IRQ_AR_PATCH_VERSION    ADC_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define ADC_IRQ_SW_MAJOR_VERSION    3
#define ADC_IRQ_SW_MINOR_VERSION    1
#define ADC_IRQ_SW_PATCH_VERSION    2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (ADC_IRQ_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION)
#error "Software major version of Adc.h and Adc_Irq.h did not match!"
#endif
#if (ADC_IRQ_SW_MINOR_VERSION!= ADC_SW_MINOR_VERSION )
#error "Software minor version of Adc.h and Adc_Irq.h did not match!"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"

#if (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
/* Declaration for the ADC Interrupt Service Routines */
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC0_CG0_ISR(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC0_CG1_ISR(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC0_CG2_ISR(void);

extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC1_CG0_ISR(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC1_CG1_ISR(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC1_CG2_ISR(void);

/* Declaration for the ADC DMA Interrupt Service Routines */
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH0(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH1(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH2(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH3(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH4(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH5(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH6(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH7(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH8(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH9(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH10(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH11(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH12(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH13(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH14(void);
extern _INTERRUPT_ FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH15(void);

#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)
/* Declaration for the ADC Interrupt Service Routines */
extern FUNC(void, ADC_PUBLIC_CODE) ADC0_CG0_ISR(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC0_CG1_ISR(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC0_CG2_ISR(void);

extern FUNC(void, ADC_PUBLIC_CODE) ADC1_CG0_ISR(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC1_CG1_ISR(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC1_CG2_ISR(void);

/* Declaration for the ADC DMA Interrupt Service Routines */
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH0(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH1(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH2(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH3(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH4(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH5(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH6(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH7(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH8(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH9(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH10(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH11(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH12(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH13(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH14(void);
extern FUNC(void, ADC_PUBLIC_CODE) ADC_DMA_ISR_CH15(void);

#elif (ADC_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
/* Do nothing to avoid error */

#else
#error "ADC_INTERRUPT_TYPE not set."
#endif

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* ADC_IRQ_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
