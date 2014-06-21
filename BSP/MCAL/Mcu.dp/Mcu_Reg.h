/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Mcu_Reg.h                                                   */
/* Version      = 3.1.8                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains register addresses used.                                */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  3.1.13
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    FK4_4010_MCU_V308_140113_HEADLAMP.arxml
 * GENERATED ON:  16 Jan 2014 - 08:46:12
 */


#ifndef MCU_REG_H
#define MCU_REG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* This macro containes the base address of CKSC_000 register */
#define MCU_CKSC000_BASE_ADDRESS             ((uint32)0xFF422030ul)

/* Protection Command Register 0 */
#define MCU_PROTCMD0                        *((volatile uint8  *)0xFF424000ul)

/* Protection Command Register 1 */
#define MCU_PROTCMD1                        *((volatile uint8  *)0xFF428000ul)

/* Protection Command Register 2 */
#define MCU_PROTCMD2                        *((volatile uint8  *)0xFF420300ul)

/* Main OSC enable register */
#define MCU_MOSCE                           *((volatile uint32  *)0xFF421010ul)

/* Main OSC control register */
#define MCU_MOSCC                           *((volatile uint32  *)0xFF421018ul)

/* Main OSC stabilization time setting register */
#define MCU_MOSCST                          *((volatile uint32  *)0xFF42101Cul)

/* Main OSC status register */
#define MCU_MOSCS                           *((volatile uint32  *)0xFF421014ul)

/* Protection status register0 */
#define MCU_PROTS0                          *((volatile uint8  *)0xFF424004ul)

/* Protection status register1 */
#define MCU_PROTS1                          *((volatile uint8  *)0xFF428004ul)

/* Protection status register2 */
#define MCU_PROTS2                          *((volatile uint8  *)0xFF420304ul)

/* Ring OSC enable register */
#define MCU_ROSCE                           *((volatile uint32  *)0xFF421000ul)

/* Ring OSC status register */
#define MCU_ROSCS                           *((volatile uint32  *)0xFF421004ul)

/* PLL0 enable register */
#define MCU_PLLE0                           *((volatile uint32  *)0xFF425000ul)

/* PLL0 stabilization time setting register */
#define MCU_PLLST0                          *((volatile uint32  *)0xFF42500Cul)

/* PLL0 Control register */
#define MCU_PLLC0                           *((volatile uint32  *)0xFF425008ul)

/* PLL0 status register */
#define MCU_PLLS0                           *((volatile uint32  *)0xFF425004ul)

/* PLL1 enable register */
#define MCU_PLLE1                           *((volatile uint32  *)0xFF425010ul)

/* PLL1 stabilization time setting register */
#define MCU_PLLST1                          *((volatile uint32  *)0xFF42501Cul)

/* PLL1 Control register */
#define MCU_PLLC1                           *((volatile uint32  *)0xFF425018ul)

/* PLL1 status register */
#define MCU_PLLS1                           *((volatile uint32  *)0xFF425014ul)

/* PLL2 enable register */
#define MCU_PLLE2                           *((volatile uint32  *)0xFF425020ul)

/* PLL2 stabilization time setting register */
#define MCU_PLLST2                          *((volatile uint32  *)0xFF42502Cul)

/* PLL2 Control register */
#define MCU_PLLC2                           *((volatile uint32  *)0xFF425028ul)

/* PLL2 status register */
#define MCU_PLLS2                           *((volatile uint32  *)0xFF425024ul)

/* Reset factor register */
#define MCU_RESF                            *((volatile uint32  *)0xFF420160ul)

/* Software reset register */
#define MCU_SWRESA                          *((volatile uint32  *)0xFF420204ul)

/* Power save control register 0 */
#define MCU_PSC0                            *((volatile uint32  *)0xFF420000ul)

/* Power save control register 1 */
#define MCU_PSC1                            *((volatile uint32  *)0xFF420008ul)

/* Power status register 0 */
#define MCU_PWS0                            *((volatile uint32  *)0xFF420004ul)

/* Power status register 1 */
#define MCU_PWS1                            *((volatile uint32  *)0xFF42000Cul)

/* OSC wake up factor mask register */
#define MCU_OSCWUFMSK                       *((volatile uint32  *)0xFF4201A4ul)

/* LVI control register */
#define MCU_LVICNT                          *((volatile uint32  *)0xFF420200ul)

/* Reset factor clear register */
#define MCU_RESFC                           *((volatile uint32  *)0xFF420168ul)

/* FOUT Divider register  */
#define MCU_FOUTDIV                         *((volatile uint16  *)0xFF81B000ul)

/* Voltage comparator channel 0 control register */
#define MCU_VCPC0CTL0                       *((volatile uint8  *)0xFF818000ul)

/* Voltage comparator channel 1 control register */
#define MCU_VCPC0CTL1                       *((volatile uint8  *)0xFF818004ul)

/* Sub OSC status register */
#define MCU_SOSCS                           *((volatile uint32  *)0xFF421024ul)

/* Sub OSC enable register */
#define MCU_SOSCE                           *((volatile uint32  *)0xFF421020ul)

/* Sub OSC stabilization time setting register */
#define MCU_SOSCST                          *((volatile uint32  *)0xFF42102Cul)

/* CLMA0 Control register 1 */
#define MCU_CLMA0CTL1                       *((volatile uint8  *)0xFF802004ul)

/* CLMA0 Comparison register H */
#define MCU_CLMA0CMPH                       *((volatile uint16  *)0xFF80200Cul)

/* CLMA0 Comparison register L */
#define MCU_CLMA0CMPL                       *((volatile uint16  *)0xFF802008ul)

/* CLMA0 Control register 0 */
#define MCU_CLMA0CTL0                       *((volatile uint8  *)0xFF802000ul)

/* CLMA0 Protection command register */
#define MCU_CLMA0PCMD                       *((volatile uint8  *)0xFF802010ul)

/* CLMA0 Protection status register */
#define MCU_CLMA0PS                         *((volatile uint8  *)0xFF802014ul)

/* CLMA2 Control register 1 */
#define MCU_CLMA2CTL1                       *((volatile uint8  *)0xFF804004ul)

/* CLMA2 Comparison register H */
#define MCU_CLMA2CMPH                       *((volatile uint16  *)0xFF80400Cul)

/* CLMA2 Comparison register L */
#define MCU_CLMA2CMPL                       *((volatile uint16  *)0xFF804008ul)

/* CLMA2 Control register 0 */
#define MCU_CLMA2CTL0                       *((volatile uint8  *)0xFF804000ul)

/* CLMA2 Protection command register */
#define MCU_CLMA2PCMD                       *((volatile uint8  *)0xFF804010ul)

/* CLMA2 Protection status register */
#define MCU_CLMA2PS                         *((volatile uint8  *)0xFF804014ul)

/* CLMA3 Control register 1 */
#define MCU_CLMA3CTL1                       *((volatile uint8  *)0xFF805004ul)

/* CLMA3 Comparison register H */
#define MCU_CLMA3CMPH                       *((volatile uint16  *)0xFF80500Cul)

/* CLMA3 Comparison register L */
#define MCU_CLMA3CMPL                       *((volatile uint16  *)0xFF805008ul)

/* CLMA3 Control register 0 */
#define MCU_CLMA3CTL0                       *((volatile uint8  *)0xFF805000ul)

/* CLMA3 Protection command register */
#define MCU_CLMA3PCMD                       *((volatile uint8  *)0xFF805010ul)

/* CLMA3 Protection status register */
#define MCU_CLMA3PS                         *((volatile uint8  *)0xFF805014ul)


/* Wake up factor registers for ISO0 area */
#define MCU_WUFL0                           *((volatile uint32  *)0xFF420100ul)
#define MCU_WUFM0                           *((volatile uint32  *)0xFF420110ul)
#define MCU_WUFH0                           *((volatile uint32  *)0xFF420120ul)

/* Wake up factor registers for ISO1 area */
#define MCU_WUFL1                           *((volatile uint32  *)0xFF420130ul)
#define MCU_WUFM1                           *((volatile uint32  *)0xFF420140ul)
#define MCU_WUFH1                           *((volatile uint32  *)0xFF420150ul)

/* Wake up factor clear registers for ISO0 area */
#define MCU_WUFCL0                          *((volatile uint32  *)0xFF420108ul)
#define MCU_WUFCM0                          *((volatile uint32  *)0xFF420118ul)
#define MCU_WUFCH0                          *((volatile uint32  *)0xFF420128ul)

/* Wake up factor clear registers for ISO1 area */
#define MCU_WUFCL1                          *((volatile uint32  *)0xFF420138ul)
#define MCU_WUFCM1                          *((volatile uint32  *)0xFF420148ul)
#define MCU_WUFCH1                          *((volatile uint32  *)0xFF420158ul)

/* Wake up factor mask registers for ISO0 area */
#define MCU_WUFMSKL0                        *((volatile uint32  *)0xFF420104ul)
#define MCU_WUFMSKM0                        *((volatile uint32  *)0xFF420114ul)
#define MCU_WUFMSKH0                        *((volatile uint32  *)0xFF420124ul)

/* Wake up factor mask registers for ISO1 area */
#define MCU_WUFMSKL1                        *((volatile uint32  *)0xFF420134ul)
#define MCU_WUFMSKM1                        *((volatile uint32  *)0xFF420144ul)
#define MCU_WUFMSKH1                        *((volatile uint32  *)0xFF420154ul)



/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_REG_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

