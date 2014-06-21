/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Gpt_Irq.h                                                   */
/* Version      = 3.1.3a                                                      */
/* Date         = 23-Apr-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains ISR prototypes for all Timers of GPT Driver             */
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

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*
 * V3.0.0:  23-Oct-2009    : Initial Version
 * V3.0.1:  11-Dec-2009    : As per SCR 167,
 *                           1.The macro definition of GPT_OSTM1_CH0 is added.
 *                           2.The extern declaration of the interrupt function
 *                             of OSTM1 is added.
 * V3.0.2:  23-Jun-2010    : As per SCR 281, the following changes are made:
 *                           1. The macro definitions are added to support
 *                              TAUB and TAUC timer units.
 *                           2. The extern declarations of the interrupt
 *                              functions are added to support TAUB and TAUC
 *                              timer units.
 *                           3. File is updated to support ISR Category
 *                              configurable by a pre-compile option.
 * V3.0.3:  08-Jul-2010    : As per SCR 299, ISR Category options are updated
 *                           from MODE to TYPE.
 * V3.1.0:  27-July-2011   : Channel mapping MCAL_ISR_TYPE_TOOLCHAIN for TAUB0
 *                            timer channels added
 * V3.1.1:  16-Feb-2012    :  Merged the fixes done for Fx4L Gpt driver
 * V3.1.2:  06-Jun-2012    :  As per SCR 029, Environment section is updated to
 *                            remove compiler version.
 * V3.1.3:  23-Oct-2012    :  As per MNT_0007541 the following changes are made:
 *                            1. Version check for SW major version and minor 
 *                               version performed with the versions defined 
 *                               in Gpt.h inorder to make all versions of the 
 *                               module internal  c and h files identical.
 * V3.1.3a: 23-Apr-2013    :  As per Mantis #11228, inclusion location of Os.h
 *                            is changed.
 */
/*****************************************************************************/
#ifndef GPT_IRQ_H
#define GPT_IRQ_H

/******************************************************************************
**                      Include Section                                      **
******************************************************************************/
/* The default option for ISR Category MCAL_ISR_TYPE_TOOLCHAIN */
#ifndef GPT_INTERRUPT_TYPE
#define GPT_INTERRUPT_TYPE MCAL_ISR_TYPE_TOOLCHAIN
#endif

#if (GPT_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
/* Use OS */
#include "Os.h"
#endif
/******************************************************************************
**                      Version Information                                 **
******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define GPT_IRQ_AR_MAJOR_VERSION    GPT_AR_MAJOR_VERSION_VALUE
#define GPT_IRQ_AR_MINOR_VERSION    GPT_AR_MINOR_VERSION_VALUE
#define GPT_IRQ_AR_PATCH_VERSION    GPT_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define GPT_IRQ_SW_MAJOR_VERSION    3
#define GPT_IRQ_SW_MINOR_VERSION    1
#define GPT_IRQ_SW_PATCH_VERSION    3

#if (GPT_SW_MAJOR_VERSION != GPT_IRQ_SW_MAJOR_VERSION)
#error "Software major version of Gpt.h and Gpt_Irq.h did not match!"
#endif
#if (GPT_SW_MINOR_VERSION!= GPT_IRQ_SW_MINOR_VERSION )
#error "Software minor version of Gpt.h and Gpt_Irq.h did not match!"
#endif

/******************************************************************************
**                      Global Symbols                                       **
******************************************************************************/

/* Channel Mapping for TAUA Unit Channels */
#define GPT_TAUA0_CH0       0x00
#define GPT_TAUA0_CH1       0x01
#define GPT_TAUA0_CH2       0x02
#define GPT_TAUA0_CH3       0x03
#define GPT_TAUA0_CH4       0x04
#define GPT_TAUA0_CH5       0x05
#define GPT_TAUA0_CH6       0x06
#define GPT_TAUA0_CH7       0x07
#define GPT_TAUA0_CH8       0x08
#define GPT_TAUA0_CH9       0x09
#define GPT_TAUA0_CH10      0x0A
#define GPT_TAUA0_CH11      0x0B
#define GPT_TAUA0_CH12      0x0C
#define GPT_TAUA0_CH13      0x0D
#define GPT_TAUA0_CH14      0x0E
#define GPT_TAUA0_CH15      0x0F

#define GPT_TAUA1_CH0       0x10
#define GPT_TAUA1_CH1       0x11
#define GPT_TAUA1_CH2       0x12
#define GPT_TAUA1_CH3       0x13
#define GPT_TAUA1_CH4       0x14
#define GPT_TAUA1_CH5       0x15
#define GPT_TAUA1_CH6       0x16
#define GPT_TAUA1_CH7       0x17
#define GPT_TAUA1_CH8       0x18
#define GPT_TAUA1_CH9       0x19
#define GPT_TAUA1_CH10      0x1A
#define GPT_TAUA1_CH11      0x1B
#define GPT_TAUA1_CH12      0x1C
#define GPT_TAUA1_CH13      0x1D
#define GPT_TAUA1_CH14      0x1E
#define GPT_TAUA1_CH15      0x1F

#define GPT_TAUA2_CH0       0x20
#define GPT_TAUA2_CH1       0x21
#define GPT_TAUA2_CH2       0x22
#define GPT_TAUA2_CH3       0x23
#define GPT_TAUA2_CH4       0x24
#define GPT_TAUA2_CH5       0x25
#define GPT_TAUA2_CH6       0x26
#define GPT_TAUA2_CH7       0x27
#define GPT_TAUA2_CH8       0x28
#define GPT_TAUA2_CH9       0x29
#define GPT_TAUA2_CH10      0x2A
#define GPT_TAUA2_CH11      0x2B
#define GPT_TAUA2_CH12      0x2C
#define GPT_TAUA2_CH13      0x2D
#define GPT_TAUA2_CH14      0x2E
#define GPT_TAUA2_CH15      0x2F

#define GPT_TAUA3_CH0       0x30
#define GPT_TAUA3_CH1       0x31
#define GPT_TAUA3_CH2       0x32
#define GPT_TAUA3_CH3       0x33
#define GPT_TAUA3_CH4       0x34
#define GPT_TAUA3_CH5       0x35
#define GPT_TAUA3_CH6       0x36
#define GPT_TAUA3_CH7       0x37
#define GPT_TAUA3_CH8       0x38
#define GPT_TAUA3_CH9       0x39
#define GPT_TAUA3_CH10      0x3A
#define GPT_TAUA3_CH11      0x3B
#define GPT_TAUA3_CH12      0x3C
#define GPT_TAUA3_CH13      0x3D
#define GPT_TAUA3_CH14      0x3E
#define GPT_TAUA3_CH15      0x3F

#define GPT_TAUA4_CH0       0x40
#define GPT_TAUA4_CH1       0x41
#define GPT_TAUA4_CH2       0x42
#define GPT_TAUA4_CH3       0x43
#define GPT_TAUA4_CH4       0x44
#define GPT_TAUA4_CH5       0x45
#define GPT_TAUA4_CH6       0x46
#define GPT_TAUA4_CH7       0x47
#define GPT_TAUA4_CH8       0x48
#define GPT_TAUA4_CH9       0x49
#define GPT_TAUA4_CH10      0x4A
#define GPT_TAUA4_CH11      0x4B
#define GPT_TAUA4_CH12      0x4C
#define GPT_TAUA4_CH13      0x4D
#define GPT_TAUA4_CH14      0x4E
#define GPT_TAUA4_CH15      0x4F

#define GPT_TAUA5_CH0       0x50
#define GPT_TAUA5_CH1       0x51
#define GPT_TAUA5_CH2       0x52
#define GPT_TAUA5_CH3       0x53
#define GPT_TAUA5_CH4       0x54
#define GPT_TAUA5_CH5       0x55
#define GPT_TAUA5_CH6       0x56
#define GPT_TAUA5_CH7       0x57
#define GPT_TAUA5_CH8       0x58
#define GPT_TAUA5_CH9       0x59
#define GPT_TAUA5_CH10      0x5A
#define GPT_TAUA5_CH11      0x5B
#define GPT_TAUA5_CH12      0x5C
#define GPT_TAUA5_CH13      0x5D
#define GPT_TAUA5_CH14      0x5E
#define GPT_TAUA5_CH15      0x5F

#define GPT_TAUA6_CH0       0x60
#define GPT_TAUA6_CH1       0x61
#define GPT_TAUA6_CH2       0x62
#define GPT_TAUA6_CH3       0x63
#define GPT_TAUA6_CH4       0x64
#define GPT_TAUA6_CH5       0x65
#define GPT_TAUA6_CH6       0x66
#define GPT_TAUA6_CH7       0x67
#define GPT_TAUA6_CH8       0x68
#define GPT_TAUA6_CH9       0x69
#define GPT_TAUA6_CH10      0x6A
#define GPT_TAUA6_CH11      0x6B
#define GPT_TAUA6_CH12      0x6C
#define GPT_TAUA6_CH13      0x6D
#define GPT_TAUA6_CH14      0x6E
#define GPT_TAUA6_CH15      0x6F

#define GPT_TAUA7_CH0       0x70
#define GPT_TAUA7_CH1       0x71
#define GPT_TAUA7_CH2       0x72
#define GPT_TAUA7_CH3       0x73
#define GPT_TAUA7_CH4       0x74
#define GPT_TAUA7_CH5       0x75
#define GPT_TAUA7_CH6       0x76
#define GPT_TAUA7_CH7       0x77
#define GPT_TAUA7_CH8       0x78
#define GPT_TAUA7_CH9       0x79
#define GPT_TAUA7_CH10      0x7A
#define GPT_TAUA7_CH11      0x7B
#define GPT_TAUA7_CH12      0x7C
#define GPT_TAUA7_CH13      0x7D
#define GPT_TAUA7_CH14      0x7E
#define GPT_TAUA7_CH15      0x7F

#define GPT_TAUA8_CH0       0x80
#define GPT_TAUA8_CH1       0x81
#define GPT_TAUA8_CH2       0x82
#define GPT_TAUA8_CH3       0x83
#define GPT_TAUA8_CH4       0x84
#define GPT_TAUA8_CH5       0x85
#define GPT_TAUA8_CH6       0x86
#define GPT_TAUA8_CH7       0x87
#define GPT_TAUA8_CH8       0x88
#define GPT_TAUA8_CH9       0x89
#define GPT_TAUA8_CH10      0x8A
#define GPT_TAUA8_CH11      0x8B
#define GPT_TAUA8_CH12      0x8C
#define GPT_TAUA8_CH13      0x8D
#define GPT_TAUA8_CH14      0x8E
#define GPT_TAUA8_CH15      0x8F

/* Channel Mapping for TAUB Unit Channels */
#define GPT_TAUB0_CH0       0x00
#define GPT_TAUB0_CH1       0x01
#define GPT_TAUB0_CH2       0x02
#define GPT_TAUB0_CH3       0x03
#define GPT_TAUB0_CH4       0x04
#define GPT_TAUB0_CH5       0x05
#define GPT_TAUB0_CH6       0x06
#define GPT_TAUB0_CH7       0x07
#define GPT_TAUB0_CH8       0x08
#define GPT_TAUB0_CH9       0x09
#define GPT_TAUB0_CH10      0x0A
#define GPT_TAUB0_CH11      0x0B
#define GPT_TAUB0_CH12      0x0C
#define GPT_TAUB0_CH13      0x0D
#define GPT_TAUB0_CH14      0x0E
#define GPT_TAUB0_CH15      0x0F

#define GPT_TAUB1_CH0       0x10
#define GPT_TAUB1_CH1       0x11
#define GPT_TAUB1_CH2       0x12
#define GPT_TAUB1_CH3       0x13
#define GPT_TAUB1_CH4       0x14
#define GPT_TAUB1_CH5       0x15
#define GPT_TAUB1_CH6       0x16
#define GPT_TAUB1_CH7       0x17
#define GPT_TAUB1_CH8       0x18
#define GPT_TAUB1_CH9       0x19
#define GPT_TAUB1_CH10      0x1A
#define GPT_TAUB1_CH11      0x1B
#define GPT_TAUB1_CH12      0x1C
#define GPT_TAUB1_CH13      0x1D
#define GPT_TAUB1_CH14      0x1E
#define GPT_TAUB1_CH15      0x1F

#define GPT_TAUB2_CH0       0x20
#define GPT_TAUB2_CH1       0x21
#define GPT_TAUB2_CH2       0x22
#define GPT_TAUB2_CH3       0x23
#define GPT_TAUB2_CH4       0x24
#define GPT_TAUB2_CH5       0x25
#define GPT_TAUB2_CH6       0x26
#define GPT_TAUB2_CH7       0x27
#define GPT_TAUB2_CH8       0x28
#define GPT_TAUB2_CH9       0x29
#define GPT_TAUB2_CH10      0x2A
#define GPT_TAUB2_CH11      0x2B
#define GPT_TAUB2_CH12      0x2C
#define GPT_TAUB2_CH13      0x2D
#define GPT_TAUB2_CH14      0x2E
#define GPT_TAUB2_CH15      0x2F

/* Channel Mapping for TAUC Unit Channels */
#define GPT_TAUC2_CH0       0x20
#define GPT_TAUC2_CH1       0x21
#define GPT_TAUC2_CH2       0x22
#define GPT_TAUC2_CH3       0x23
#define GPT_TAUC2_CH4       0x24
#define GPT_TAUC2_CH5       0x25
#define GPT_TAUC2_CH6       0x26
#define GPT_TAUC2_CH7       0x27
#define GPT_TAUC2_CH8       0x28
#define GPT_TAUC2_CH9       0x29
#define GPT_TAUC2_CH10      0x2A
#define GPT_TAUC2_CH11      0x2B
#define GPT_TAUC2_CH12      0x2C
#define GPT_TAUC2_CH13      0x2D
#define GPT_TAUC2_CH14      0x2E
#define GPT_TAUC2_CH15      0x2F

#define GPT_TAUC3_CH0       0x30
#define GPT_TAUC3_CH1       0x31
#define GPT_TAUC3_CH2       0x32
#define GPT_TAUC3_CH3       0x33
#define GPT_TAUC3_CH4       0x34
#define GPT_TAUC3_CH5       0x35
#define GPT_TAUC3_CH6       0x36
#define GPT_TAUC3_CH7       0x37
#define GPT_TAUC3_CH8       0x38
#define GPT_TAUC3_CH9       0x39
#define GPT_TAUC3_CH10      0x3A
#define GPT_TAUC3_CH11      0x3B
#define GPT_TAUC3_CH12      0x3C
#define GPT_TAUC3_CH13      0x3D
#define GPT_TAUC3_CH14      0x3E
#define GPT_TAUC3_CH15      0x3F

#define GPT_TAUC4_CH0       0x40
#define GPT_TAUC4_CH1       0x41
#define GPT_TAUC4_CH2       0x42
#define GPT_TAUC4_CH3       0x43
#define GPT_TAUC4_CH4       0x44
#define GPT_TAUC4_CH5       0x45
#define GPT_TAUC4_CH6       0x46
#define GPT_TAUC4_CH7       0x47
#define GPT_TAUC4_CH8       0x48
#define GPT_TAUC4_CH9       0x49
#define GPT_TAUC4_CH10      0x4A
#define GPT_TAUC4_CH11      0x4B
#define GPT_TAUC4_CH12      0x4C
#define GPT_TAUC4_CH13      0x4D
#define GPT_TAUC4_CH14      0x4E
#define GPT_TAUC4_CH15      0x4F

#define GPT_TAUC5_CH0       0x50
#define GPT_TAUC5_CH1       0x51
#define GPT_TAUC5_CH2       0x52
#define GPT_TAUC5_CH3       0x53
#define GPT_TAUC5_CH4       0x54
#define GPT_TAUC5_CH5       0x55
#define GPT_TAUC5_CH6       0x56
#define GPT_TAUC5_CH7       0x57
#define GPT_TAUC5_CH8       0x58
#define GPT_TAUC5_CH9       0x59
#define GPT_TAUC5_CH10      0x5A
#define GPT_TAUC5_CH11      0x5B
#define GPT_TAUC5_CH12      0x5C
#define GPT_TAUC5_CH13      0x5D
#define GPT_TAUC5_CH14      0x5E
#define GPT_TAUC5_CH15      0x5F

#define GPT_TAUC6_CH0       0x60
#define GPT_TAUC6_CH1       0x61
#define GPT_TAUC6_CH2       0x62
#define GPT_TAUC6_CH3       0x63
#define GPT_TAUC6_CH4       0x64
#define GPT_TAUC6_CH5       0x65
#define GPT_TAUC6_CH6       0x66
#define GPT_TAUC6_CH7       0x67
#define GPT_TAUC6_CH8       0x68
#define GPT_TAUC6_CH9       0x69
#define GPT_TAUC6_CH10      0x6A
#define GPT_TAUC6_CH11      0x6B
#define GPT_TAUC6_CH12      0x6C
#define GPT_TAUC6_CH13      0x6D
#define GPT_TAUC6_CH14      0x6E
#define GPT_TAUC6_CH15      0x6F

#define GPT_TAUC7_CH0       0x70
#define GPT_TAUC7_CH1       0x71
#define GPT_TAUC7_CH2       0x72
#define GPT_TAUC7_CH3       0x73
#define GPT_TAUC7_CH4       0x74
#define GPT_TAUC7_CH5       0x75
#define GPT_TAUC7_CH6       0x76
#define GPT_TAUC7_CH7       0x77
#define GPT_TAUC7_CH8       0x78
#define GPT_TAUC7_CH9       0x79
#define GPT_TAUC7_CH10      0x7A
#define GPT_TAUC7_CH11      0x7B
#define GPT_TAUC7_CH12      0x7C
#define GPT_TAUC7_CH13      0x7D
#define GPT_TAUC7_CH14      0x7E
#define GPT_TAUC7_CH15      0x7F

#define GPT_TAUC8_CH0       0x80
#define GPT_TAUC8_CH1       0x81
#define GPT_TAUC8_CH2       0x82
#define GPT_TAUC8_CH3       0x83
#define GPT_TAUC8_CH4       0x84
#define GPT_TAUC8_CH5       0x85
#define GPT_TAUC8_CH6       0x86
#define GPT_TAUC8_CH7       0x87
#define GPT_TAUC8_CH8       0x88
#define GPT_TAUC8_CH9       0x89
#define GPT_TAUC8_CH10      0x8A
#define GPT_TAUC8_CH11      0x8B
#define GPT_TAUC8_CH12      0x8C
#define GPT_TAUC8_CH13      0x8D
#define GPT_TAUC8_CH14      0x8E
#define GPT_TAUC8_CH15      0x8F

/* Channel Mapping for TAUJ Unit Channels */
#define GPT_TAUJ0_CH0       0x90
#define GPT_TAUJ0_CH1       0x91
#define GPT_TAUJ0_CH2       0x92
#define GPT_TAUJ0_CH3       0x93

#define GPT_TAUJ1_CH0       0x94
#define GPT_TAUJ1_CH1       0x95
#define GPT_TAUJ1_CH2       0x96
#define GPT_TAUJ1_CH3       0x97

#define GPT_TAUJ2_CH0       0x98
#define GPT_TAUJ2_CH1       0x99
#define GPT_TAUJ2_CH2       0x9A
#define GPT_TAUJ2_CH3       0x9B

/* Channel Mapping for OSTM Unit Channels */
#define GPT_OSTM0_CH0       0x9C
#define GPT_OSTM1_CH0       0x9D
/******************************************************************************
**                      Global Data Types                                    **
******************************************************************************/

/******************************************************************************
**                      Function Prototypes                                  **
******************************************************************************/

#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

#if (GPT_INTERRUPT_TYPE == MCAL_ISR_TYPE_TOOLCHAIN)
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH3_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH4_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH5_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH6_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH7_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH8_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH9_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH10_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH11_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH12_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH13_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH14_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH15_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ0_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ0_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ0_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ0_CH3_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ1_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ1_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ1_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ1_CH3_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ2_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ2_CH1_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ2_CH2_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) TAUJ2_CH3_ISR(void);

extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) OSTM0_CH0_ISR(void);
extern _INTERRUPT_ FUNC(void, GPT_PUBLIC_CODE) OSTM1_CH0_ISR(void);

#elif (GPT_INTERRUPT_TYPE == MCAL_ISR_TYPE_NONE)

extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA0_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA1_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA2_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA3_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA4_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA5_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA6_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA7_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUA8_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB0_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB1_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUB2_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC2_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC3_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC4_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC5_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC6_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC7_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH3_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH4_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH5_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH6_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH7_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH8_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH9_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH10_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH11_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH12_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH13_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH14_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUC8_CH15_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ0_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ0_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ0_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ0_CH3_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ1_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ1_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ1_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ1_CH3_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ2_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ2_CH1_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ2_CH2_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) TAUJ2_CH3_ISR(void);

extern  FUNC(void, GPT_PUBLIC_CODE) OSTM0_CH0_ISR(void);
extern  FUNC(void, GPT_PUBLIC_CODE) OSTM1_CH0_ISR(void);

#elif (GPT_INTERRUPT_TYPE == MCAL_ISR_TYPE_OS)
/* Do nothing to avoid error */

#else
#error "GPT_INTERRUPT_TYPE not set."
#endif /* End of GPT_INTERRUPT_TYPE */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif  /* GPT_IRQ_H */

/******************************************************************************
**                      End of File                                          **
******************************************************************************/
