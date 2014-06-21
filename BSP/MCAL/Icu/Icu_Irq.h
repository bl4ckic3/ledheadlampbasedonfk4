/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu_Irq.h                                                   */
/* Version      = 3.0.2a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains ISR prototypes for all Timers of ICU Driver             */
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
 * V3.0.1:  28-Jun-2010  : As per SCR 286, the following changes are made:
 *                         1. The macro definitions are added to support
 *                            Timer Array Unit B.
 *                         2. The extern declarations of the interrupt
 *                            service routines are added to support 
 *                            Timer Array Unit B.
 *                         3. File is updated to support an ISR Category
 *                            support configurable by a pre-compile option.
 *
 * V3.0.2:  20-Jul-2010  : As per SCR 308, ICU_INTERRUPT_MODE is renamed 
 *                         as ICU_INTERRUPT_TYPE.
 * V3.0.2a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef ICU_IRQ_H
#define ICU_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define ICU_IRQ_AR_MAJOR_VERSION    ICU_AR_MAJOR_VERSION_VALUE
#define ICU_IRQ_AR_MINOR_VERSION    ICU_AR_MINOR_VERSION_VALUE
#define ICU_IRQ_AR_PATCH_VERSION    ICU_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define ICU_IRQ_SW_MAJOR_VERSION  3
#define ICU_IRQ_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Channel Mapping for TAUA Channels */
#define ICU_TAUA0_CH0        0x00
#define ICU_TAUA0_CH1        0x01
#define ICU_TAUA0_CH2        0x02
#define ICU_TAUA0_CH3        0x03
#define ICU_TAUA0_CH4        0x04
#define ICU_TAUA0_CH5        0x05
#define ICU_TAUA0_CH6        0x06
#define ICU_TAUA0_CH7        0x07
#define ICU_TAUA0_CH8        0x08
#define ICU_TAUA0_CH9        0x09
#define ICU_TAUA0_CH10       0x0A
#define ICU_TAUA0_CH11       0x0B
#define ICU_TAUA0_CH12       0x0C
#define ICU_TAUA0_CH13       0x0D
#define ICU_TAUA0_CH14       0x0E
#define ICU_TAUA0_CH15       0x0F

#define ICU_TAUA1_CH0        0x10
#define ICU_TAUA1_CH1        0x11
#define ICU_TAUA1_CH2        0x12
#define ICU_TAUA1_CH3        0x13
#define ICU_TAUA1_CH4        0x14
#define ICU_TAUA1_CH5        0x15
#define ICU_TAUA1_CH6        0x16
#define ICU_TAUA1_CH7        0x17
#define ICU_TAUA1_CH8        0x18
#define ICU_TAUA1_CH9        0x19
#define ICU_TAUA1_CH10       0x1A
#define ICU_TAUA1_CH11       0x1B
#define ICU_TAUA1_CH12       0x1C
#define ICU_TAUA1_CH13       0x1D
#define ICU_TAUA1_CH14       0x1E
#define ICU_TAUA1_CH15       0x1F

#define ICU_TAUA2_CH0        0x20
#define ICU_TAUA2_CH1        0x21
#define ICU_TAUA2_CH2        0x22
#define ICU_TAUA2_CH3        0x23
#define ICU_TAUA2_CH4        0x24
#define ICU_TAUA2_CH5        0x25
#define ICU_TAUA2_CH6        0x26
#define ICU_TAUA2_CH7        0x27
#define ICU_TAUA2_CH8        0x28
#define ICU_TAUA2_CH9        0x29
#define ICU_TAUA2_CH10       0x2A
#define ICU_TAUA2_CH11       0x2B
#define ICU_TAUA2_CH12       0x2C
#define ICU_TAUA2_CH13       0x2D
#define ICU_TAUA2_CH14       0x2E
#define ICU_TAUA2_CH15       0x2F

#define ICU_TAUA3_CH0        0x30
#define ICU_TAUA3_CH1        0x31
#define ICU_TAUA3_CH2        0x32
#define ICU_TAUA3_CH3        0x33
#define ICU_TAUA3_CH4        0x34
#define ICU_TAUA3_CH5        0x35
#define ICU_TAUA3_CH6        0x36
#define ICU_TAUA3_CH7        0x37
#define ICU_TAUA3_CH8        0x38
#define ICU_TAUA3_CH9        0x39
#define ICU_TAUA3_CH10       0x3A
#define ICU_TAUA3_CH11       0x3B
#define ICU_TAUA3_CH12       0x3C
#define ICU_TAUA3_CH13       0x3D
#define ICU_TAUA3_CH14       0x3E
#define ICU_TAUA3_CH15       0x3F

#define ICU_TAUA4_CH0        0x40
#define ICU_TAUA4_CH1        0x41
#define ICU_TAUA4_CH2        0x42
#define ICU_TAUA4_CH3        0x43
#define ICU_TAUA4_CH4        0x44
#define ICU_TAUA4_CH5        0x45
#define ICU_TAUA4_CH6        0x46
#define ICU_TAUA4_CH7        0x47
#define ICU_TAUA4_CH8        0x48
#define ICU_TAUA4_CH9        0x49
#define ICU_TAUA4_CH10       0x4A
#define ICU_TAUA4_CH11       0x4B
#define ICU_TAUA4_CH12       0x4C
#define ICU_TAUA4_CH13       0x4D
#define ICU_TAUA4_CH14       0x4E
#define ICU_TAUA4_CH15       0x4F

#define ICU_TAUA5_CH0        0x50
#define ICU_TAUA5_CH1        0x51
#define ICU_TAUA5_CH2        0x52
#define ICU_TAUA5_CH3        0x53
#define ICU_TAUA5_CH4        0x54
#define ICU_TAUA5_CH5        0x55
#define ICU_TAUA5_CH6        0x56
#define ICU_TAUA5_CH7        0x57
#define ICU_TAUA5_CH8        0x58
#define ICU_TAUA5_CH9        0x59
#define ICU_TAUA5_CH10       0x5A
#define ICU_TAUA5_CH11       0x5B
#define ICU_TAUA5_CH12       0x5C
#define ICU_TAUA5_CH13       0x5D
#define ICU_TAUA5_CH14       0x5E
#define ICU_TAUA5_CH15       0x5F

#define ICU_TAUA6_CH0        0x60
#define ICU_TAUA6_CH1        0x61
#define ICU_TAUA6_CH2        0x62
#define ICU_TAUA6_CH3        0x63
#define ICU_TAUA6_CH4        0x64
#define ICU_TAUA6_CH5        0x65
#define ICU_TAUA6_CH6        0x66
#define ICU_TAUA6_CH7        0x67
#define ICU_TAUA6_CH8        0x68
#define ICU_TAUA6_CH9        0x69
#define ICU_TAUA6_CH10       0x6A
#define ICU_TAUA6_CH11       0x6B
#define ICU_TAUA6_CH12       0x6C
#define ICU_TAUA6_CH13       0x6D
#define ICU_TAUA6_CH14       0x6E
#define ICU_TAUA6_CH15       0x6F

#define ICU_TAUA7_CH0        0x70
#define ICU_TAUA7_CH1        0x71
#define ICU_TAUA7_CH2        0x72
#define ICU_TAUA7_CH3        0x73
#define ICU_TAUA7_CH4        0x74
#define ICU_TAUA7_CH5        0x75
#define ICU_TAUA7_CH6        0x76
#define ICU_TAUA7_CH7        0x77
#define ICU_TAUA7_CH8        0x78
#define ICU_TAUA7_CH9        0x79
#define ICU_TAUA7_CH10       0x7A
#define ICU_TAUA7_CH11       0x7B
#define ICU_TAUA7_CH12       0x7C
#define ICU_TAUA7_CH13       0x7D
#define ICU_TAUA7_CH14       0x7E
#define ICU_TAUA7_CH15       0x7F

#define ICU_TAUA8_CH0        0x80
#define ICU_TAUA8_CH1        0x81
#define ICU_TAUA8_CH2        0x82
#define ICU_TAUA8_CH3        0x83
#define ICU_TAUA8_CH4        0x84
#define ICU_TAUA8_CH5        0x85
#define ICU_TAUA8_CH6        0x86
#define ICU_TAUA8_CH7        0x87
#define ICU_TAUA8_CH8        0x88
#define ICU_TAUA8_CH9        0x89
#define ICU_TAUA8_CH10       0x8A
#define ICU_TAUA8_CH11       0x8B
#define ICU_TAUA8_CH12       0x8C
#define ICU_TAUA8_CH13       0x8D
#define ICU_TAUA8_CH14       0x8E
#define ICU_TAUA8_CH15       0x8F

/* Channel Mapping for TAUB Channels */
#define ICU_TAUB1_CH0        0x10
#define ICU_TAUB1_CH1        0x11
#define ICU_TAUB1_CH2        0x12
#define ICU_TAUB1_CH3        0x13
#define ICU_TAUB1_CH4        0x14
#define ICU_TAUB1_CH5        0x15
#define ICU_TAUB1_CH6        0x16
#define ICU_TAUB1_CH7        0x17
#define ICU_TAUB1_CH8        0x18
#define ICU_TAUB1_CH9        0x19
#define ICU_TAUB1_CH10       0x1A
#define ICU_TAUB1_CH11       0x1B
#define ICU_TAUB1_CH12       0x1C
#define ICU_TAUB1_CH13       0x1D
#define ICU_TAUB1_CH14       0x1E
#define ICU_TAUB1_CH15       0x1F

#define ICU_TAUB2_CH0        0x20
#define ICU_TAUB2_CH1        0x21
#define ICU_TAUB2_CH2        0x22
#define ICU_TAUB2_CH3        0x23
#define ICU_TAUB2_CH4        0x24
#define ICU_TAUB2_CH5        0x25
#define ICU_TAUB2_CH6        0x26
#define ICU_TAUB2_CH7        0x27
#define ICU_TAUB2_CH8        0x28
#define ICU_TAUB2_CH9        0x29
#define ICU_TAUB2_CH10       0x2A
#define ICU_TAUB2_CH11       0x2B
#define ICU_TAUB2_CH12       0x2C
#define ICU_TAUB2_CH13       0x2D
#define ICU_TAUB2_CH14       0x2E
#define ICU_TAUB2_CH15       0x2F

/* Channel Mapping for TAUJ Channels */
#define ICU_TAUJ0_CH0        0x90
#define ICU_TAUJ0_CH1        0x91
#define ICU_TAUJ0_CH2        0x92
#define ICU_TAUJ0_CH3        0x93

#define ICU_TAUJ1_CH0        0x94
#define ICU_TAUJ1_CH1        0x95
#define ICU_TAUJ1_CH2        0x96
#define ICU_TAUJ1_CH3        0x97

#define ICU_TAUJ2_CH0        0x98
#define ICU_TAUJ2_CH1        0x99
#define ICU_TAUJ2_CH2        0x9A
#define ICU_TAUJ2_CH3        0x9B

/* Channel Mapping for External Interrupt channels */
#define ICU_EXTP_INTP_0      0x9C
#define ICU_EXTP_INTP_1      0x9D
#define ICU_EXTP_INTP_2      0x9E
#define ICU_EXTP_INTP_3      0x9F
#define ICU_EXTP_INTP_4      0xA0
#define ICU_EXTP_INTP_5      0xA1
#define ICU_EXTP_INTP_6      0xA2
#define ICU_EXTP_INTP_7      0xA3
#define ICU_EXTP_INTP_8      0xA4
#define ICU_EXTP_INTP_9      0xA5
#define ICU_EXTP_INTP_10     0xA6
#define ICU_EXTP_INTP_11     0xA7
#define ICU_EXTP_INTP_12     0xA8
#define ICU_EXTP_INTP_13     0xA9
#define ICU_EXTP_INTP_14     0xAA
#define ICU_EXTP_INTP_15     0xAB

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define ICU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* The default option for ISR Category MCAL_ISR_TYPE_TOOLCHAIN */
#ifndef ICU_INTERRUPT_TYPE
#define ICU_INTERRUPT_TYPE MCAL_ISR_TYPE_TOOLCHAIN
#endif
#if (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH3_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH3_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH3_ISR(void);

extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_0_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_1_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_2_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_3_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_4_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_5_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_6_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_7_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_8_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_9_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_10_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_11_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_12_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_13_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_14_ISR(void);
extern _INTERRUPT_ FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_15_ISR(void);

/* MCAL_ISR_TYPE_OS - OS declares the ISR and defines the interrupt mapping */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
      /* Use OS */
      #include "Os.h"
      
/* MCAL_ISR_TYPE_NONE - user writed his own dispatcher for ISR */
#elif (ICU_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)

extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA0_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA1_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA2_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA3_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA4_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA5_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA6_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA7_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUA8_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB1_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUB2_CH15_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ0_CH3_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ1_CH3_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) TAUJ2_CH3_ISR(void);

extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_0_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_1_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_2_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_3_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_4_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_5_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_6_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_7_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_8_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_9_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_10_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_11_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_12_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_13_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_14_ISR(void);
extern  FUNC(void, ICU_PUBLIC_CODE) EXTERNAL_INTERRUPT_15_ISR(void);

#else
#error "ICU_INTERRUPT_TYPE not set."
#endif /* End of ICU_INTERRUPT_TYPE */

#define ICU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"



#endif /* ICU_IRQ_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
