/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Adc_LTTypes.h                                               */
/* Version      = 3.1.2                                                       */
/* Date         = 04-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSAR ADC Link Time Parameters                              */
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
 * V3.0.2:  01-Jul-2010  : As per SCR 295, extern declaration for array
 *                         Adc_GaaHwUnitIndex[] is added.
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

#ifndef ADC_LTTYPES_H
#define ADC_LTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Adc.h"
#include "Adc_Cbk.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification information */
#define ADC_LTTYPES_AR_MAJOR_VERSION    ADC_AR_MAJOR_VERSION_VALUE
#define ADC_LTTYPES_AR_MINOR_VERSION    ADC_AR_MINOR_VERSION_VALUE
#define ADC_LTTYPES_AR_PATCH_VERSION    ADC_AR_PATCH_VERSION_VALUE

/* File version information */
#define ADC_LTTYPES_SW_MAJOR_VERSION    3
#define ADC_LTTYPES_SW_MINOR_VERSION    1
#define ADC_LTTYPES_SW_PATCH_VERSION    2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (ADC_LTTYPES_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION)
#error "Software major version of Adc.h and Adc_LTTypes.h did not match!"
#endif
#if (ADC_LTTYPES_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION )
#error "Software minor version of Adc.h and Adc_LTTypes.h did not match!"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Structure of function pointer for Callback notification function */
typedef struct STagTdd_Adc_GroupNotifyFuncType
{
  /* Pointer to callback notification */
  P2FUNC (void, ADC_APPL_CODE, pGroupNotificationPointer)(void);

} Tdd_Adc_GroupNotifyFuncType;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/

#define ADC_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Prototype for the group notification function */
extern CONST(Tdd_Adc_GroupNotifyFuncType, ADC_CONST) Adc_GstChannelGrpFunc[];

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define ADC_START_SEC_CONST_8BIT
#include "MemMap.h"

/* Declaration for Hardware Index Mapping array */
extern CONST(uint8, ADC_CONST) Adc_GaaHwUnitIndex[];

#define ADC_STOP_SEC_CONST_8BIT
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ADC_LTTYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
