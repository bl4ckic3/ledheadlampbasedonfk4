/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Pwm_Irq.h                                                   */
/* Version      = 3.1.3a                                                      */
/* Date         = 23-Apr-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of API information.                                              */
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
 * V3.0.0:  18-Aug-2009  : Initial version
 * V3.0.1:  02-Jul-2010  : As per SCR 290, the following changes are made:
 *                         1. The macro definitions are added to support
 *                            TAUB and TAUC timer units.
 *                         2. The extern declarations of the interrupt
 *                            functions are added to support TAUB and TAUC
 *                            timer units.
 *                         3. File is updated to support ISR Category
 *                            configurable by a pre-compile option.
 * V3.0.2:  25-Jul-2010  : As per SCR 305, ISR Category options are updated
 *                         from MODE to TYPE.
 * V3.0.3:  25-Oct-2010  : As per SCR 372, Function Prototypes for TAUJ1 and
 *                         TAUJ2 Unit Channels are corrected for
 *                         MCAL_ISR_TYPE_TOOLCHAIN ISR category.
 * V3.1.0:  26-Jul-2011  : Ported for the DK4 variant.
 * V3.1.1:  21-Sep-2011  : Corrected the location of the TAUB0_CHx_ISR, x=0..15
 *                         under the compiler switch PWM_TAUB_UNIT_USED
 * V3.1.2:  05-Mar-2012  : Merged the fixes done for Fx4L PWM driver
 * V3.1.3:  06-Jun-2012  : As per SCR 034, Compiler version is removed from
 *                         Environment section.
 * V3.1.3a: 23-Apr-2013  : As per Mantis #11228, inclusion location of Os.h
 *                         is changed.
 */
/******************************************************************************/

#ifndef PWM_IRQ_H
#define PWM_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* The default option for ISR Category MCAL_ISR_TYPE_TOOLCHAIN */
#ifndef PWM_INTERRUPT_TYPE
#define PWM_INTERRUPT_TYPE MCAL_ISR_TYPE_TOOLCHAIN
#endif

#if (PWM_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
/* Use OS */
//#include "Os.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Version identification */
#define PWM_IRQ_AR_MAJOR_VERSION    PWM_AR_MAJOR_VERSION_VALUE
#define PWM_IRQ_AR_MINOR_VERSION    PWM_AR_MINOR_VERSION_VALUE
#define PWM_IRQ_AR_PATCH_VERSION    PWM_AR_PATCH_VERSION_VALUE

/* File version information */
#define PWM_IRQ_SW_MAJOR_VERSION    3
#define PWM_IRQ_SW_MINOR_VERSION    1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PWM_SW_MAJOR_VERSION != PWM_IRQ_SW_MAJOR_VERSION)
  #error "Pwm_Irq.h : Mismatch in Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_IRQ_SW_MINOR_VERSION)
  #error "Pwm_Irq.h : Mismatch in Minor Version"
#endif

/* Channel Mapping for TAUA Unit Channels */
#define PWM_TAUA0_CH0       0x00
#define PWM_TAUA0_CH1       0x01
#define PWM_TAUA0_CH2       0x02
#define PWM_TAUA0_CH3       0x03
#define PWM_TAUA0_CH4       0x04
#define PWM_TAUA0_CH5       0x05
#define PWM_TAUA0_CH6       0x06
#define PWM_TAUA0_CH7       0x07
#define PWM_TAUA0_CH8       0x08
#define PWM_TAUA0_CH9       0x09
#define PWM_TAUA0_CH10      0x0A
#define PWM_TAUA0_CH11      0x0B
#define PWM_TAUA0_CH12      0x0C
#define PWM_TAUA0_CH13      0x0D
#define PWM_TAUA0_CH14      0x0E
#define PWM_TAUA0_CH15      0x0F

#define PWM_TAUA1_CH0       0x10
#define PWM_TAUA1_CH1       0x11
#define PWM_TAUA1_CH2       0x12
#define PWM_TAUA1_CH3       0x13
#define PWM_TAUA1_CH4       0x14
#define PWM_TAUA1_CH5       0x15
#define PWM_TAUA1_CH6       0x16
#define PWM_TAUA1_CH7       0x17
#define PWM_TAUA1_CH8       0x18
#define PWM_TAUA1_CH9       0x19
#define PWM_TAUA1_CH10      0x1A
#define PWM_TAUA1_CH11      0x1B
#define PWM_TAUA1_CH12      0x1C
#define PWM_TAUA1_CH13      0x1D
#define PWM_TAUA1_CH14      0x1E
#define PWM_TAUA1_CH15      0x1F

#define PWM_TAUA2_CH0       0x20
#define PWM_TAUA2_CH1       0x21
#define PWM_TAUA2_CH2       0x22
#define PWM_TAUA2_CH3       0x23
#define PWM_TAUA2_CH4       0x24
#define PWM_TAUA2_CH5       0x25
#define PWM_TAUA2_CH6       0x26
#define PWM_TAUA2_CH7       0x27
#define PWM_TAUA2_CH8       0x28
#define PWM_TAUA2_CH9       0x29
#define PWM_TAUA2_CH10      0x2A
#define PWM_TAUA2_CH11      0x2B
#define PWM_TAUA2_CH12      0x2C
#define PWM_TAUA2_CH13      0x2D
#define PWM_TAUA2_CH14      0x2E
#define PWM_TAUA2_CH15      0x2F

#define PWM_TAUA3_CH0       0x30
#define PWM_TAUA3_CH1       0x31
#define PWM_TAUA3_CH2       0x32
#define PWM_TAUA3_CH3       0x33
#define PWM_TAUA3_CH4       0x34
#define PWM_TAUA3_CH5       0x35
#define PWM_TAUA3_CH6       0x36
#define PWM_TAUA3_CH7       0x37
#define PWM_TAUA3_CH8       0x38
#define PWM_TAUA3_CH9       0x39
#define PWM_TAUA3_CH10      0x3A
#define PWM_TAUA3_CH11      0x3B
#define PWM_TAUA3_CH12      0x3C
#define PWM_TAUA3_CH13      0x3D
#define PWM_TAUA3_CH14      0x3E
#define PWM_TAUA3_CH15      0x3F

#define PWM_TAUA4_CH0       0x40
#define PWM_TAUA4_CH1       0x41
#define PWM_TAUA4_CH2       0x42
#define PWM_TAUA4_CH3       0x43
#define PWM_TAUA4_CH4       0x44
#define PWM_TAUA4_CH5       0x45
#define PWM_TAUA4_CH6       0x46
#define PWM_TAUA4_CH7       0x47
#define PWM_TAUA4_CH8       0x48
#define PWM_TAUA4_CH9       0x49
#define PWM_TAUA4_CH10      0x4A
#define PWM_TAUA4_CH11      0x4B
#define PWM_TAUA4_CH12      0x4C
#define PWM_TAUA4_CH13      0x4D
#define PWM_TAUA4_CH14      0x4E
#define PWM_TAUA4_CH15      0x4F

#define PWM_TAUA5_CH0       0x50
#define PWM_TAUA5_CH1       0x51
#define PWM_TAUA5_CH2       0x52
#define PWM_TAUA5_CH3       0x53
#define PWM_TAUA5_CH4       0x54
#define PWM_TAUA5_CH5       0x55
#define PWM_TAUA5_CH6       0x56
#define PWM_TAUA5_CH7       0x57
#define PWM_TAUA5_CH8       0x58
#define PWM_TAUA5_CH9       0x59
#define PWM_TAUA5_CH10      0x5A
#define PWM_TAUA5_CH11      0x5B
#define PWM_TAUA5_CH12      0x5C
#define PWM_TAUA5_CH13      0x5D
#define PWM_TAUA5_CH14      0x5E
#define PWM_TAUA5_CH15      0x5F

#define PWM_TAUA6_CH0       0x60
#define PWM_TAUA6_CH1       0x61
#define PWM_TAUA6_CH2       0x62
#define PWM_TAUA6_CH3       0x63
#define PWM_TAUA6_CH4       0x64
#define PWM_TAUA6_CH5       0x65
#define PWM_TAUA6_CH6       0x66
#define PWM_TAUA6_CH7       0x67
#define PWM_TAUA6_CH8       0x68
#define PWM_TAUA6_CH9       0x69
#define PWM_TAUA6_CH10      0x6A
#define PWM_TAUA6_CH11      0x6B
#define PWM_TAUA6_CH12      0x6C
#define PWM_TAUA6_CH13      0x6D
#define PWM_TAUA6_CH14      0x6E
#define PWM_TAUA6_CH15      0x6F

#define PWM_TAUA7_CH0       0x70
#define PWM_TAUA7_CH1       0x71
#define PWM_TAUA7_CH2       0x72
#define PWM_TAUA7_CH3       0x73
#define PWM_TAUA7_CH4       0x74
#define PWM_TAUA7_CH5       0x75
#define PWM_TAUA7_CH6       0x76
#define PWM_TAUA7_CH7       0x77
#define PWM_TAUA7_CH8       0x78
#define PWM_TAUA7_CH9       0x79
#define PWM_TAUA7_CH10      0x7A
#define PWM_TAUA7_CH11      0x7B
#define PWM_TAUA7_CH12      0x7C
#define PWM_TAUA7_CH13      0x7D
#define PWM_TAUA7_CH14      0x7E
#define PWM_TAUA7_CH15      0x7F

#define PWM_TAUA8_CH0       0x80
#define PWM_TAUA8_CH1       0x81
#define PWM_TAUA8_CH2       0x82
#define PWM_TAUA8_CH3       0x83
#define PWM_TAUA8_CH4       0x84
#define PWM_TAUA8_CH5       0x85
#define PWM_TAUA8_CH6       0x86
#define PWM_TAUA8_CH7       0x87
#define PWM_TAUA8_CH8       0x88
#define PWM_TAUA8_CH9       0x89
#define PWM_TAUA8_CH10      0x8A
#define PWM_TAUA8_CH11      0x8B
#define PWM_TAUA8_CH12      0x8C
#define PWM_TAUA8_CH13      0x8D
#define PWM_TAUA8_CH14      0x8E
#define PWM_TAUA8_CH15      0x8F

/* Channel Mapping for TAUB Unit Channels */
#define PWM_TAUB0_CH0       0x00
#define PWM_TAUB0_CH1       0x01
#define PWM_TAUB0_CH2       0x02
#define PWM_TAUB0_CH3       0x03
#define PWM_TAUB0_CH4       0x04
#define PWM_TAUB0_CH5       0x05
#define PWM_TAUB0_CH6       0x06
#define PWM_TAUB0_CH7       0x07
#define PWM_TAUB0_CH8       0x08
#define PWM_TAUB0_CH9       0x09
#define PWM_TAUB0_CH10      0x0A
#define PWM_TAUB0_CH11      0x0B
#define PWM_TAUB0_CH12      0x0C
#define PWM_TAUB0_CH13      0x0D
#define PWM_TAUB0_CH14      0x0E
#define PWM_TAUB0_CH15      0x0F

#define PWM_TAUB1_CH0       0x10
#define PWM_TAUB1_CH1       0x11
#define PWM_TAUB1_CH2       0x12
#define PWM_TAUB1_CH3       0x13
#define PWM_TAUB1_CH4       0x14
#define PWM_TAUB1_CH5       0x15
#define PWM_TAUB1_CH6       0x16
#define PWM_TAUB1_CH7       0x17
#define PWM_TAUB1_CH8       0x18
#define PWM_TAUB1_CH9       0x19
#define PWM_TAUB1_CH10      0x1A
#define PWM_TAUB1_CH11      0x1B
#define PWM_TAUB1_CH12      0x1C
#define PWM_TAUB1_CH13      0x1D
#define PWM_TAUB1_CH14      0x1E
#define PWM_TAUB1_CH15      0x1F

#define PWM_TAUB2_CH0       0x20
#define PWM_TAUB2_CH1       0x21
#define PWM_TAUB2_CH2       0x22
#define PWM_TAUB2_CH3       0x23
#define PWM_TAUB2_CH4       0x24
#define PWM_TAUB2_CH5       0x25
#define PWM_TAUB2_CH6       0x26
#define PWM_TAUB2_CH7       0x27
#define PWM_TAUB2_CH8       0x28
#define PWM_TAUB2_CH9       0x29
#define PWM_TAUB2_CH10      0x2A
#define PWM_TAUB2_CH11      0x2B
#define PWM_TAUB2_CH12      0x2C
#define PWM_TAUB2_CH13      0x2D
#define PWM_TAUB2_CH14      0x2E
#define PWM_TAUB2_CH15      0x2F

/* Channel Mapping for TAUC Unit Channels */
#define PWM_TAUC2_CH0       0x20
#define PWM_TAUC2_CH1       0x21
#define PWM_TAUC2_CH2       0x22
#define PWM_TAUC2_CH3       0x23
#define PWM_TAUC2_CH4       0x24
#define PWM_TAUC2_CH5       0x25
#define PWM_TAUC2_CH6       0x26
#define PWM_TAUC2_CH7       0x27
#define PWM_TAUC2_CH8       0x28
#define PWM_TAUC2_CH9       0x29
#define PWM_TAUC2_CH10      0x2A
#define PWM_TAUC2_CH11      0x2B
#define PWM_TAUC2_CH12      0x2C
#define PWM_TAUC2_CH13      0x2D
#define PWM_TAUC2_CH14      0x2E
#define PWM_TAUC2_CH15      0x2F

#define PWM_TAUC3_CH0       0x30
#define PWM_TAUC3_CH1       0x31
#define PWM_TAUC3_CH2       0x32
#define PWM_TAUC3_CH3       0x33
#define PWM_TAUC3_CH4       0x34
#define PWM_TAUC3_CH5       0x35
#define PWM_TAUC3_CH6       0x36
#define PWM_TAUC3_CH7       0x37
#define PWM_TAUC3_CH8       0x38
#define PWM_TAUC3_CH9       0x39
#define PWM_TAUC3_CH10      0x3A
#define PWM_TAUC3_CH11      0x3B
#define PWM_TAUC3_CH12      0x3C
#define PWM_TAUC3_CH13      0x3D
#define PWM_TAUC3_CH14      0x3E
#define PWM_TAUC3_CH15      0x3F

#define PWM_TAUC4_CH0       0x40
#define PWM_TAUC4_CH1       0x41
#define PWM_TAUC4_CH2       0x42
#define PWM_TAUC4_CH3       0x43
#define PWM_TAUC4_CH4       0x44
#define PWM_TAUC4_CH5       0x45
#define PWM_TAUC4_CH6       0x46
#define PWM_TAUC4_CH7       0x47
#define PWM_TAUC4_CH8       0x48
#define PWM_TAUC4_CH9       0x49
#define PWM_TAUC4_CH10      0x4A
#define PWM_TAUC4_CH11      0x4B
#define PWM_TAUC4_CH12      0x4C
#define PWM_TAUC4_CH13      0x4D
#define PWM_TAUC4_CH14      0x4E
#define PWM_TAUC4_CH15      0x4F

#define PWM_TAUC5_CH0       0x50
#define PWM_TAUC5_CH1       0x51
#define PWM_TAUC5_CH2       0x52
#define PWM_TAUC5_CH3       0x53
#define PWM_TAUC5_CH4       0x54
#define PWM_TAUC5_CH5       0x55
#define PWM_TAUC5_CH6       0x56
#define PWM_TAUC5_CH7       0x57
#define PWM_TAUC5_CH8       0x58
#define PWM_TAUC5_CH9       0x59
#define PWM_TAUC5_CH10      0x5A
#define PWM_TAUC5_CH11      0x5B
#define PWM_TAUC5_CH12      0x5C
#define PWM_TAUC5_CH13      0x5D
#define PWM_TAUC5_CH14      0x5E
#define PWM_TAUC5_CH15      0x5F

#define PWM_TAUC6_CH0       0x60
#define PWM_TAUC6_CH1       0x61
#define PWM_TAUC6_CH2       0x62
#define PWM_TAUC6_CH3       0x63
#define PWM_TAUC6_CH4       0x64
#define PWM_TAUC6_CH5       0x65
#define PWM_TAUC6_CH6       0x66
#define PWM_TAUC6_CH7       0x67
#define PWM_TAUC6_CH8       0x68
#define PWM_TAUC6_CH9       0x69
#define PWM_TAUC6_CH10      0x6A
#define PWM_TAUC6_CH11      0x6B
#define PWM_TAUC6_CH12      0x6C
#define PWM_TAUC6_CH13      0x6D
#define PWM_TAUC6_CH14      0x6E
#define PWM_TAUC6_CH15      0x6F

#define PWM_TAUC7_CH0       0x70
#define PWM_TAUC7_CH1       0x71
#define PWM_TAUC7_CH2       0x72
#define PWM_TAUC7_CH3       0x73
#define PWM_TAUC7_CH4       0x74
#define PWM_TAUC7_CH5       0x75
#define PWM_TAUC7_CH6       0x76
#define PWM_TAUC7_CH7       0x77
#define PWM_TAUC7_CH8       0x78
#define PWM_TAUC7_CH9       0x79
#define PWM_TAUC7_CH10      0x7A
#define PWM_TAUC7_CH11      0x7B
#define PWM_TAUC7_CH12      0x7C
#define PWM_TAUC7_CH13      0x7D
#define PWM_TAUC7_CH14      0x7E
#define PWM_TAUC7_CH15      0x7F

#define PWM_TAUC8_CH0       0x80
#define PWM_TAUC8_CH1       0x81
#define PWM_TAUC8_CH2       0x82
#define PWM_TAUC8_CH3       0x83
#define PWM_TAUC8_CH4       0x84
#define PWM_TAUC8_CH5       0x85
#define PWM_TAUC8_CH6       0x86
#define PWM_TAUC8_CH7       0x87
#define PWM_TAUC8_CH8       0x88
#define PWM_TAUC8_CH9       0x89
#define PWM_TAUC8_CH10      0x8A
#define PWM_TAUC8_CH11      0x8B
#define PWM_TAUC8_CH12      0x8C
#define PWM_TAUC8_CH13      0x8D
#define PWM_TAUC8_CH14      0x8E
#define PWM_TAUC8_CH15      0x8F

/* Channel Mapping for TAUJ Unit Channels */
#define PWM_TAUJ0_CH0       0x90
#define PWM_TAUJ0_CH1       0x91
#define PWM_TAUJ0_CH2       0x92
#define PWM_TAUJ0_CH3       0x93

#define PWM_TAUJ1_CH0       0x94
#define PWM_TAUJ1_CH1       0x95
#define PWM_TAUJ1_CH2       0x96
#define PWM_TAUJ1_CH3       0x97

#define PWM_TAUJ2_CH0       0x98
#define PWM_TAUJ2_CH1       0x99
#define PWM_TAUJ2_CH2       0x9A
#define PWM_TAUJ2_CH3       0x9B

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define PWM_START_SEC_PUBLIC_CODE
#include "MemMap.h"

#if (PWM_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)

#if (PWM_TAUA_UNIT_USED == STD_ON)/*PWM_TAUA_UNIT_USED == STD_ON*/
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH15_ISR(void);

#endif /*PWM_TAUA_UNIT_USED == STD_ON*/

#if (PWM_TAUB_UNIT_USED == STD_ON)/*PWM_TAUB_UNIT_USED == STD_ON*/

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH15_ISR(void);


extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH15_ISR(void);

#endif	/*PWM_TAUB_UNIT_USED == STD_ON*/

#if (PWM_TAUC_UNIT_USED == STD_ON)/*PWM_TAUC_UNIT_USED == STD_ON*/

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH15_ISR(void);

#endif /*PWM_TAUC_UNIT_USED == STD_ON*/

#if (PWM_TAUJ_UNIT_USED == STD_ON)/*PWM_TAUJ_UNIT_USED == STD_ON*/

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ0_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ0_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ0_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ0_CH3_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ1_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ1_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ1_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ1_CH3_ISR(void);

extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, PWM_PUBLIC_CODE) TAUJ2_CH3_ISR(void);

#endif /*PWM_TAUJ_UNIT_USED == STD_ON*/

#elif (PWM_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)

#if (PWM_TAUA_UNIT_USED == STD_ON)/*PWM_TAUA_UNIT_USED == STD_ON*/

extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA0_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA1_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA2_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA3_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA4_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA5_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA6_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA7_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUA8_CH15_ISR(void);

#endif	/*PWM_TAUA_UNIT_USED == STD_ON*/

#if (PWM_TAUB_UNIT_USED == STD_ON)/*PWM_TAUB_UNIT_USED == STD_ON*/

extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB0_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB1_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUB2_CH15_ISR(void);

#endif	/*PWM_TAUB_UNIT_USED == STD_ON*/

#if (PWM_TAUC_UNIT_USED == STD_ON)/*PWM_TAUC_UNIT_USED == STD_ON*/

extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC2_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC3_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC4_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC5_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC6_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC7_CH15_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH3_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH4_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH5_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH6_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH7_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH8_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH9_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH10_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH11_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH12_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH13_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH14_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUC8_CH15_ISR(void);

#endif 	/*PWM_TAUC_UNIT_USED == STD_ON*/

#if (PWM_TAUJ_UNIT_USED == STD_ON)/*PWM_TAUJ_UNIT_USED == STD_ON*/

extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ0_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ0_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ0_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ0_CH3_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ1_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ1_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ1_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ1_CH3_ISR(void);

extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ2_CH0_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ2_CH1_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ2_CH2_ISR(void);
extern  FUNC(void, PWM_PUBLIC_CODE) TAUJ2_CH3_ISR(void);

#endif	/*PWM_TAUJ_UNIT_USED == STD_ON*/

#elif (PWM_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
/* Do nothing to avoid error */

#else
#error "PWM_INTERRUPT_TYPE not set."
#endif /* End of PWM_INTERRUPT_TYPE */

#define PWM_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif  /* PWM_IRQ_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
