/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Adc_Private.h                                               */
/* Version      = 3.1.2                                                       */
/* Date         = 04-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Private functions declarations.                                            */
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
 *                         1. Prototype of the functions Adc_Isr and Adc_DmaIsr
 *                            are updated.
 *
 * V3.1.0:  27-Jul-2011  : Modified for DK-4
 * V3.1.1:  14-Feb-2012  : Merged the fixes done for Fx4L Adc driver
 *
 * V3.1.2:  04-Jun-2012  : As per SCR 019, the following changes are made
 *                         1. Compiler version is removed from environment 
 *                            section.
 *                         2. File version is changed.
 */
/******************************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Adc_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define ADC_PRIVATE_AR_MAJOR_VERSION    ADC_AR_MAJOR_VERSION_VALUE
#define ADC_PRIVATE_AR_MINOR_VERSION    ADC_AR_MINOR_VERSION_VALUE
#define ADC_PRIVATE_AR_PATCH_VERSION    ADC_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define ADC_PRIVATE_SW_MAJOR_VERSION    3
#define ADC_PRIVATE_SW_MINOR_VERSION    1
#define ADC_PRIVATE_SW_PATCH_VERSION    2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (ADC_PRIVATE_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION)
#error "Software major version of Adc.h and Adc_Private.h did not match!"
#endif
#if (ADC_PRIVATE_SW_MINOR_VERSION!= ADC_SW_MINOR_VERSION )
#error "Software minor version of Adc.h and Adc_Private.h did not match!"
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

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, ADC_PRIVATE_CODE) Adc_PushToQueue(Adc_GroupType LddGroup);
FUNC(Adc_GroupType, ADC_PRIVATE_CODE) Adc_PopFromQueue
                                                 (Adc_HwUnitType LddHwUnit);
FUNC(void, ADC_PRIVATE_CODE) Adc_ConfigureGroupForConversion
                                                   (Adc_GroupType LddGroup);

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
FUNC(void, ADC_PRIVATE_CODE) Adc_Isr(Adc_HwUnitType LddHwUnit,
                                                     uint8 LucCGUnit);
#else
FUNC(void, ADC_PRIVATE_CODE) Adc_Isr(Adc_HwUnitType LddHwUnit);
#endif

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
FUNC(void, ADC_PRIVATE_CODE) Adc_DmaIsr(Adc_HwUnitType LddHwUnit,
                                                 uint8 LucCGUnit);
#else
FUNC(void, ADC_PRIVATE_CODE) Adc_DmaIsr(Adc_HwUnitType LddHwUnit);
#endif

FUNC(void, ADC_PRIVATE_CODE) Adc_ServiceSelectMode
                          (Adc_GroupType LddGroup, Adc_HwUnitType LddHwUnit);
FUNC(void, ADC_PRIVATE_CODE) Adc_ServiceScanMode(Adc_GroupType LddGroup,
                                                   Adc_HwUnitType LddHwUnit);
FUNC(void, ADC_PRIVATE_CODE) Adc_StateTransition(Adc_GroupType LddGroup);

FUNC(void, ADC_PRIVATE_CODE) Adc_SearchnDelete(Adc_GroupType LddGroup,
                                                   Adc_HwUnitType LddHwUnit);
FUNC(void, ADC_PRIVATE_CODE) Adc_EnableHWGroup(Adc_GroupType LddGroup);
FUNC(void, ADC_PRIVATE_CODE) Adc_DisableHWGroup(Adc_GroupType LddGroup);

FUNC(void, ADC_PRIVATE_CODE) Adc_GroupCompleteMode(Adc_GroupType LddGroup,
                                                   Adc_HwUnitType LddHwUnit);
FUNC(void, ADC_PRIVATE_CODE) Adc_ChannelCompleteMode(Adc_GroupType LddGroup,
                                                    Adc_HwUnitType LddHwUnit);

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* ADC_PRIVATE_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
