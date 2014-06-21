/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Port_Cfg.h                                                  */
/* Version      = 3.0.4                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
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
 * TOOL VERSION:  3.1.7a
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    PORT_REV2_HEADLAMP_V308_UPD4010_140619.arxml
 * GENERATED ON:  19 Jun 2014 - 16:59:42
 */

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_CFG_AR_MAJOR_VERSION  3
#define PORT_CFG_AR_MINOR_VERSION  0
#define PORT_CFG_AR_PATCH_VERSION  1
/* File version information */
#define PORT_CFG_SW_MAJOR_VERSION      3
#define PORT_CFG_SW_MINOR_VERSION      1

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define PORT_AR_MAJOR_VERSION_VALUE  3
#define PORT_AR_MINOR_VERSION_VALUE  0
#define PORT_AR_PATCH_VERSION_VALUE  1
#define PORT_SW_MAJOR_VERSION_VALUE  3
#define PORT_SW_MINOR_VERSION_VALUE  1
#define PORT_SW_PATCH_VERSION_VALUE  5
#define PORT_MODULE_ID_VALUE            124
#define PORT_VENDOR_ID_VALUE            23


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the PORT Driver Component */
#define PORT_INSTANCE_ID_VALUE                    0

/* Enables/Disables Development error detect */
#define PORT_DEV_ERROR_DETECT                     STD_OFF

/* Enables/Disables Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API                STD_ON

/* Enables/Disables Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API                     STD_ON

/* Enables/Disables Port_GetVersionInfo API */
#define PORT_VERSION_INFO_API                     STD_ON

/* Enable/Disable the enter/exit critical section functionality */
#define PORT_CRITICAL_SECTION_PROTECTION          STD_OFF

/* Enables/Disables the checking of port pin backup status */
#define PORT_PIN_STATUS_BACKUP                    STD_OFF

/* Pre-compile option for the PSC0 */
#define PORT_PSC0_ENABLE                          STD_ON

/* Pre-compile option for the PSC1 */
#define PORT_PSC1_ENABLE                          STD_ON

/* Pre-compile option for the PWS0 */
#define PORT_PWS0_ENABLE                          STD_ON

/* Pre-compile option for the PWS1 */
#define PORT_PWS1_ENABLE                          STD_ON

/* Pre-compile option for the IORES0 */
#define PORT_IORES0_ENABLE                        STD_OFF

/* Pre-compile option for Device name */
#define USE_UPD70F3580                     STD_OFF

/* Pre-compile option for Device name */
#define USE_UPD70F3529                STD_OFF

/* Availability of numeric port groups */
#define PORT_NUM_PORT_GROUPS_AVAILABLE            STD_ON

/* Availability of alphabetic port groups */
#define PORT_ALPHA_PORT_GROUPS_AVAILABLE          STD_OFF

/* Enables/Disables Port_GetVersionInfo API */
#define PORT_JTAG_PORT_GROUPS_AVAILABLE           STD_ON

/* The following constant contains total number of pins configured */
#define PORT_TOTAL_NUMBER_OF_PINS                (uint16)128

/* The following constant contains total number of JPSR registers */
#define PORT_JTAG_PSR_REGS                  (uint8)1

/* The following constant contains total number of JPMCSR registers */
#define PORT_JTAG_PMCSR_REGS                (uint8)1

/* The following constant contains total number of  JPODC registers */
#define PORT_JTAG_PODC_REGS                  (uint8)1

/* The following constant contains total number of  JPDSC registers */
#define PORT_JTAG_PDSC_REGS                  (uint8)1

/* The following constant contains total number of  JPUCC registers */
#define PORT_JTAG_PUCC_REGS                  (uint8)0

/* The following constant contains total number of  JPSBC registers */
#define PORT_JTAG_PSBC_REGS                  (uint8)0


/* The following constant contains total number of 8 bit JTAG registers */
#define PORT_JTAG_OTHER_8BIT_REGS           (uint8)6

/* Base Address of numeric port */
#define PORT_USER_BASE_ADDRESS_NUMERIC          (uint32)0xFF400000ul

/* Os Address of numeric port */
#define PORT_OS_BASE_ADDRESS_NUMERIC          (uint32)0xFF404000ul

/* Base Address of JTAG port */
#define PORT_USER_BASE_ADDRESS_JTAG             (uint32)0xFF440000ul

/* Os Address of JTAG port */
#define PORT_OS_BASE_ADDRESS_JTAG             (uint32)0xFF440400ul

/* Protection Command Register 2 */
#define PORT_PROTCMD2                      *((volatile uint8 *)0xFF420300ul)

/* Protection status register2 */
#define PORT_PROTS2                        *((volatile uint8 *)0xFF420304ul)

/* Power save control register 0 */
#define PORT_PSC0                          *((volatile uint32 *)0xFF420000ul)

/* Power save control register 1 */
#define PORT_PSC1                          *((volatile uint32 *)0xFF420008ul)

/* Power status register 0 */
#define PORT_PWS0                          *((volatile uint32 *)0xFF420004ul)

/* Power status register 1 */
#define PORT_PWS1                          *((volatile uint32 *)0xFF42000Cul)



/* Availability of DNFA noise elimination registers */
#define PORT_DNFA_REG_CONFIG               STD_OFF

/* Availability of FCLA noise elimination registers */
#define PORT_FCLA_REG_CONFIG               STD_OFF

/* Availability of Digital noise filter sampling clock control register */
#define PORT_DNFS_AVAILABLE                STD_OFF





/* Port Pin Handles */
#define PortGroup0_PortPin20    (uint16)0
#define PortGroup0_PortPin130    (uint16)1
#define PortGroup0_PortPin110    (uint16)2
#define PortGroup0_PortPin70    (uint16)3
#define PortGroup0_PortPin100    (uint16)4
#define PortGroup0_PortPin80    (uint16)5
#define PortGroup0_PortPin150    (uint16)6
#define PortGroup0_PortPin10    (uint16)7
#define PortGroup0_PortPin60    (uint16)8
#define PortGroup0_PortPin40    (uint16)9
#define PortGroup0_PortPin30    (uint16)10
#define PortGroup0_PortPin120    (uint16)11
#define PortGroup0_PortPin00    (uint16)12
#define PortGroup0_PortPin90    (uint16)13
#define PortGroup0_PortPin140    (uint16)14
#define PortGroup0_PortPin50    (uint16)15
#define PortGroup1_PortPin20    (uint16)16
#define PortGroup1_PortPin60    (uint16)17
#define PortGroup1_PortPin40    (uint16)18
#define PortGroup1_PortPin110    (uint16)19
#define PortGroup1_PortPin140    (uint16)20
#define PortGroup1_PortPin120    (uint16)21
#define PortGroup1_PortPin80    (uint16)22
#define PortGroup1_PortPin90    (uint16)23
#define PortGroup1_PortPin130    (uint16)24
#define PortGroup1_PortPin70    (uint16)25
#define PortGroup1_PortPin150    (uint16)26
#define PortGroup1_PortPin50    (uint16)27
#define PortGroup1_PortPin100    (uint16)28
#define PortGroup1_PortPin30    (uint16)29
#define PortGroup1_PortPin10    (uint16)30
#define PortGroup2_PortPin00    (uint16)31
#define PortGroup2_PortPin10    (uint16)32
#define PortGroup2_PortPin20    (uint16)33
#define PortGroup3_PortPin50    (uint16)34
#define PortGroup3_PortPin30    (uint16)35
#define PortGroup3_PortPin70    (uint16)36
#define PortGroup3_PortPin80    (uint16)37
#define PortGroup3_PortPin10    (uint16)38
#define PortGroup3_PortPin20    (uint16)39
#define PortGroup3_PortPin60    (uint16)40
#define PortGroup3_PortPin40    (uint16)41
#define PortGroup3_PortPin00    (uint16)42
#define PortGroup3_PortPin90    (uint16)43
#define PortGroup4_PortPin100    (uint16)44
#define PortGroup4_PortPin90    (uint16)45
#define PortGroup4_PortPin00    (uint16)46
#define PortGroup4_PortPin80    (uint16)47
#define PortGroup4_PortPin60    (uint16)48
#define PortGroup4_PortPin10    (uint16)49
#define PortGroup4_PortPin70    (uint16)50
#define PortGroup4_PortPin110    (uint16)51
#define PortGroup4_PortPin50    (uint16)52
#define PortGroup4_PortPin30    (uint16)53
#define PortGroup4_PortPin20    (uint16)54
#define PortGroup4_PortPin40    (uint16)55
#define PortGroup10_PortPin80    (uint16)56
#define PortGroup10_PortPin120    (uint16)57
#define PortGroup10_PortPin110    (uint16)58
#define PortGroup10_PortPin90    (uint16)59
#define PortGroup10_PortPin150    (uint16)60
#define PortGroup10_PortPin60    (uint16)61
#define PortGroup10_PortPin70    (uint16)62
#define PortGroup10_PortPin130    (uint16)63
#define PortGroup10_PortPin100    (uint16)64
#define PortGroup10_PortPin140    (uint16)65
#define PortGroup11_PortPin10    (uint16)66
#define PortGroup11_PortPin50    (uint16)67
#define PortGroup11_PortPin60    (uint16)68
#define PortGroup11_PortPin20    (uint16)69
#define PortGroup11_PortPin70    (uint16)70
#define PortGroup11_PortPin00    (uint16)71
#define PortGroup11_PortPin30    (uint16)72
#define PortGroup11_PortPin40    (uint16)73
#define PortGroup12_PortPin50    (uint16)74
#define PortGroup12_PortPin70    (uint16)75
#define PortGroup12_PortPin110    (uint16)76
#define PortGroup12_PortPin00    (uint16)77
#define PortGroup12_PortPin90    (uint16)78
#define PortGroup12_PortPin20    (uint16)79
#define PortGroup12_PortPin150    (uint16)80
#define PortGroup12_PortPin80    (uint16)81
#define PortGroup12_PortPin140    (uint16)82
#define PortGroup12_PortPin30    (uint16)83
#define PortGroup12_PortPin100    (uint16)84
#define PortGroup12_PortPin60    (uint16)85
#define PortGroup12_PortPin40    (uint16)86
#define PortGroup12_PortPin130    (uint16)87
#define PortGroup12_PortPin120    (uint16)88
#define PortGroup12_PortPin10    (uint16)89
#define PortGroup21_PortPin100    (uint16)90
#define PortGroup21_PortPin60    (uint16)91
#define PortGroup21_PortPin50    (uint16)92
#define PortGroup21_PortPin80    (uint16)93
#define PortGroup21_PortPin110    (uint16)94
#define PortGroup21_PortPin30    (uint16)95
#define PortGroup21_PortPin70    (uint16)96
#define PortGroup21_PortPin20    (uint16)97
#define PortGroup21_PortPin40    (uint16)98
#define PortGroup21_PortPin90    (uint16)99
#define PortGroup25_PortPin140    (uint16)100
#define PortGroup25_PortPin70    (uint16)101
#define PortGroup25_PortPin60    (uint16)102
#define PortGroup25_PortPin100    (uint16)103
#define PortGroup25_PortPin50    (uint16)104
#define PortGroup25_PortPin30    (uint16)105
#define PortGroup25_PortPin20    (uint16)106
#define PortGroup25_PortPin00    (uint16)107
#define PortGroup25_PortPin40    (uint16)108
#define PortGroup25_PortPin80    (uint16)109
#define PortGroup25_PortPin110    (uint16)110
#define PortGroup25_PortPin120    (uint16)111
#define PortGroup25_PortPin130    (uint16)112
#define PortGroup25_PortPin10    (uint16)113
#define PortGroup25_PortPin90    (uint16)114
#define PortGroup25_PortPin150    (uint16)115
#define PortGroup27_PortPin20    (uint16)116
#define PortGroup27_PortPin50    (uint16)117
#define PortGroup27_PortPin30    (uint16)118
#define PortGroup27_PortPin00    (uint16)119
#define PortGroup27_PortPin40    (uint16)120
#define PortGroup27_PortPin10    (uint16)121
#define PortGroupJtag0_PortPin10    (uint16)122
#define PortGroupJtag0_PortPin50    (uint16)123
#define PortGroupJtag0_PortPin00    (uint16)124
#define PortGroupJtag0_PortPin20    (uint16)125
#define PortGroupJtag0_PortPin40    (uint16)126
#define PortGroupJtag0_PortPin30    (uint16)127

/* Configuration Set Handles */
#define PortConfigSet0  &Port_GstConfiguration[0]

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PORT_CFG_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
