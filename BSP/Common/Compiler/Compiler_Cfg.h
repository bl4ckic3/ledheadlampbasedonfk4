/*============================================================================*/
/* Project        = AUTOSAR NEC Xx4 MCAL Components                           */
/* Module         = Compiler_Cfg.h                                            */
/* Version        = 3.0.2                                                     */
/* Date           = 14-Jul-2009                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009 by NEC Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains compiler macros                                         */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* NEC Electronics Corporation the following shall apply!                     */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by NEC. Any warranty   */
/* is expressly disclaimed and excluded by NEC, either expressed or implied,  */
/* including but not limited to those for non-infringement of intellectual    */
/* property, merchantability and/or fitness for the particular purpose.       */
/*                                                                            */
/* NEC shall not have any obligation to maintain, service or provide bug      */
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
/* In no event shall NEC be liable to the User for any incidental,            */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. NEC shall not be liable for any services or products         */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by NEC in connection with the Product(s) and/or the   */
/* Application.                                                               */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        Xx4                                           */
/*              Compiler:       GHS V5.1.6c                                   */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:  30-Mar-2009  : Initial Version
 * V3.0.1:  23-Jun-2009  : As per SCR 012, compiler macros for Watchdog Driver
 *                         B is added.
 * V3.0.2:  14-Jul-2009  : As per SCR 015, compiler version is changed from 
 *                         V5.0.5 to V5.1.6c in the header of the file.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define COMPILER_CFG_AR_MAJOR_VERSION  2
#define COMPILER_CFG_AR_MINOR_VERSION  0
#define COMPILER_CFG_AR_PATCH_VERSION  0

/*
 * File version information
 */
#define COMPILER_CFG_SW_MAJOR_VERSION  3
#define COMPILER_CFG_SW_MINOR_VERSION  0
#define COMPILER_CFG_SW_PATCH_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define V_SUPPRESS_EXTENDED_VERSION_CHECK
//#define V_EXTENDED_BUILD_LIB_CHECK
#define V_USE_DUMMY_STATEMENT  STD_ON
/*******************************************************************************
 **                      Configuration data                                   **
*******************************************************************************/
/*
 * The following memory and pointer classes can be configured per module.
 * These #defines are passed to the compiler abstraction macros in Compiler.h
 *
 * Note:
 * module internal functions (statics) that get into one section
 * (together with API) shall fit into one page.
 */

/* ---------------------------------------------------------------------------*/
/*                   MCU                                                      */
/* ---------------------------------------------------------------------------*/

#define MCU_PUBLIC_CODE                /* API functions                       */
#define MCU_PUBLIC_CONST               /* API constants                       */

#define MCU_PRIVATE_CODE               /* Internal functions                  */

#define MCU_PRIVATE_DATA               /* Module internal data                */
#define MCU_PRIVATE_CONST              /* Internal ROM Data                   */

#define MCU_APPL_CODE                  /* callbacks of the Application        */
#define MCU_APPL_CONST                 /* Applications' ROM Data              */
#define MCU_APPL_DATA                  /* Applications' RAM Data              */
#define MCU_FAST_DATA                  /* 'Near' RAM Data                     */


#define MCU_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define MCU_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define MCU_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define MCU_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define MCU_CONST                      /* Data Constants                      */

/* ---------------------------------------------------------------------------*/
/*                   GPT                                                      */
/* ---------------------------------------------------------------------------*/

#define GPT_PUBLIC_CODE                /* API functions                       */
#define GPT_PUBLIC_CONST               /* API constants                       */

#define GPT_PRIVATE_CODE               /* Internal functions                  */

#define GPT_PRIVATE_DATA               /* Module internal data                */
#define GPT_PRIVATE_CONST              /* Internal ROM Data                   */

#define GPT_APPL_CODE                  /* callbacks of the Application        */
#define GPT_APPL_CONST                 /* Applications' ROM Data              */
#define GPT_APPL_DATA                  /* Applications' RAM Data              */
#define GPT_FAST_DATA                  /* 'Near' RAM Data                     */


#define GPT_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define GPT_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define GPT_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define GPT_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define GPT_CONST                      /* Data Constants                      */

/* ---------------------------------------------------------------------------*/
/*                   WDG   DRIVER A                                           */
/* ---------------------------------------------------------------------------*/

#define WDG_23_DRIVERA_PUBLIC_CODE        /* API functions                    */
#define WDG_23_DRIVERA_PUBLIC_CONST       /* API constants                    */

#define WDG_23_DRIVERA_PRIVATE_CODE       /* Internal functions               */

#define WDG_23_DRIVERA_PRIVATE_DATA       /* Module internal data             */
#define WDG_23_DRIVERA_PRIVATE_CONST      /* Internal ROM Data                */

#define WDG_23_DRIVERA_APPL_CODE          /* callbacks of the Application     */
#define WDG_23_DRIVERA_APPL_CONST         /* Applications' ROM Data           */
#define WDG_23_DRIVERA_APPL_DATA          /* Applications' RAM Data           */
#define WDG_23_DRIVERA_FAST_DATA          /* 'Near' RAM Data                  */


#define WDG_23_DRIVERA_CONFIG_CONST       /* Desc. Tables -> Config-dependent */
#define WDG_23_DRIVERA_CONFIG_DATA        /* Config. dependent (reg. size)
                                             data                             */

#define WDG_23_DRIVERA_INIT_DATA          /* Data which is initialized during
                                             Startup                          */
#define WDG_23_DRIVERA_NOINIT_DATA        /* Data which is not initialized
                                             during Startup                   */
#define WDG_23_DRIVERA_CONST              /* Data Constants                   */

/* ---------------------------------------------------------------------------*/
/*                   WDG   DRIVER B                                           */
/* ---------------------------------------------------------------------------*/

#define WDG_23_DRIVERB_PUBLIC_CODE        /* API functions                    */
#define WDG_23_DRIVERB_PUBLIC_CONST       /* API constants                    */

#define WDG_23_DRIVERB_PRIVATE_CODE       /* Internal functions               */

#define WDG_23_DRIVERB_PRIVATE_DATA       /* Module internal data             */
#define WDG_23_DRIVERB_PRIVATE_CONST      /* Internal ROM Data                */

#define WDG_23_DRIVERB_APPL_CODE          /* callbacks of the Application     */
#define WDG_23_DRIVERB_APPL_CONST         /* Applications' ROM Data           */
#define WDG_23_DRIVERB_APPL_DATA          /* Applications' RAM Data           */
#define WDG_23_DRIVERB_FAST_DATA          /* 'Near' RAM Data                  */


#define WDG_23_DRIVERB_CONFIG_CONST       /* Desc. Tables -> Config-dependent */
#define WDG_23_DRIVERB_CONFIG_DATA        /* Config. dependent (reg. size)
                                             data                             */

#define WDG_23_DRIVERB_INIT_DATA          /* Data which is initialized during
                                             Startup                          */
#define WDG_23_DRIVERB_NOINIT_DATA        /* Data which is not initialized
                                             during Startup                   */
#define WDG_23_DRIVERB_CONST              /* Data Constants                   */

/* ---------------------------------------------------------------------------*/
/*                   PORT                                                     */
/* ---------------------------------------------------------------------------*/

#define PORT_PUBLIC_CODE                /* API functions                      */
#define PORT_PUBLIC_CONST               /* API constants                      */

#define PORT_PRIVATE_CODE               /* Internal functions                 */

#define PORT_PRIVATE_DATA               /* Module internal data               */
#define PORT_PRIVATE_CONST              /* Internal ROM Data                  */

#define PORT_APPL_CODE                  /* callbacks of the Application       */
#define PORT_APPL_CONST                 /* Applications' ROM Data             */
#define PORT_APPL_DATA                  /* Applications' RAM Data             */
#define PORT_FAST_DATA                  /* 'Near' RAM Data                    */


#define PORT_CONFIG_CONST               /* Desc. Tables -> Config-dependent   */
#define PORT_CONFIG_DATA                /* Config. dependent (reg. size) data */

#define PORT_INIT_DATA                  /* Data which is initialized during
                                           Startup                            */
#define PORT_NOINIT_DATA                /* Data which is not initialized during
                                           Startup                            */
#define PORT_CONST                      /* Data Constants                     */

/* ---------------------------------------------------------------------------*/
/*                   DIO                                                      */
/* ---------------------------------------------------------------------------*/

#define DIO_PUBLIC_CODE                /* API functions                       */
#define DIO_PUBLIC_CONST               /* API constants                       */

#define DIO_PRIVATE_CODE               /* Internal functions                  */

#define DIO_PRIVATE_DATA               /* Module internal data                */
#define DIO_PRIVATE_CONST              /* Internal ROM Data                   */

#define DIO_APPL_CODE                  /* callbacks of the Application        */
#define DIO_APPL_CONST                 /* Applications' ROM Data              */
#define DIO_APPL_DATA                  /* Applications' RAM Data              */
#define DIO_FAST_DATA                  /* 'Near' RAM Data                     */


#define DIO_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define DIO_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define DIO_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define DIO_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define DIO_CONST                      /* Data Constants                      */

/* ---------------------------------------------------------------------------*/
/*                   FEE                                                      */
/* ---------------------------------------------------------------------------*/

#define FEE_PUBLIC_CODE                /* API functions                       */
#define FEE_PUBLIC_CONST               /* API constants                       */

#define FEE_PRIVATE_CODE               /* Internal functions                  */

#define FEE_PRIVATE_DATA               /* Module internal data                */
#define FEE_PRIVATE_CONST              /* Internal ROM Data                   */

#define FEE_APPL_CODE                  /* callbacks of the Application        */
#define FEE_APPL_CONST                 /* Applications' ROM Data              */
#define FEE_APPL_DATA                  /* Applications' RAM Data              */
#define FEE_FAST_DATA                  /* 'Near' RAM Data                     */


#define FEE_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define FEE_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define FEE_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define FEE_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define FEE_CONST                      /* Data Constants                      */

/* ---------------------------------------------------------------------------*/
/*                   PWM                                                      */
/* ---------------------------------------------------------------------------*/

#define PWM_PUBLIC_CODE                /* API functions                       */
#define PWM_PUBLIC_CONST               /* API constants                       */

#define PWM_PRIVATE_CODE               /* Internal functions                  */

#define PWM_PRIVATE_DATA               /* Module internal data                */
#define PWM_PRIVATE_CONST              /* Internal ROM Data                   */

#define PWM_APPL_CODE                  /* callbacks of the Application        */
#define PWM_APPL_CONST                 /* Applications' ROM Data              */
#define PWM_APPL_DATA                  /* Applications' RAM Data              */
#define PWM_FAST_DATA                  /* 'Near' RAM Data                     */


#define PWM_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define PWM_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define PWM_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define PWM_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define PWM_CONST                      /* Data Constants                      */

/* ---------------------------------------------------------------------------*/
/*                   SPI                                                      */
/* ---------------------------------------------------------------------------*/

#define SPI_PUBLIC_CODE                /* API functions                       */
#define SPI_PUBLIC_CONST               /* API constants                       */

#define SPI_PRIVATE_CODE               /* Internal functions                  */

#define SPI_PRIVATE_DATA               /* Module internal data                */
#define SPI_PRIVATE_CONST              /* Internal ROM Data                   */

#define SPI_APPL_CODE                  /* callbacks of the Application        */
#define SPI_APPL_CONST                 /* Applications' ROM Data              */
#define SPI_APPL_DATA                  /* Applications' RAM Data              */
#define SPI_FAST_DATA                  /* 'Near' RAM Data                     */


#define SPI_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define SPI_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define SPI_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define SPI_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define SPI_CONST                      /* Data Constants                      */

/* ---------------------------------------------------------------------------*/
/*                   ADC                                                      */
/* ---------------------------------------------------------------------------*/

#define ADC_PUBLIC_CODE                /* API functions                       */
#define ADC_PUBLIC_CONST               /* API constants                       */

#define ADC_PRIVATE_CODE               /* Internal functions                  */

#define ADC_PRIVATE_DATA               /* Module internal data                */
#define ADC_PRIVATE_CONST              /* Internal ROM Data                   */

#define ADC_APPL_CODE                  /* callbacks of the Application        */
#define ADC_APPL_CONST                 /* Applications' ROM Data              */
#define ADC_APPL_DATA                  /* Applications' RAM Data              */
#define ADC_FAST_DATA                  /* 'Near' RAM Data                     */


#define ADC_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define ADC_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define ADC_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define ADC_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define ADC_CONST                      /* Data Constants                      */

/* ---------------------------------------------------------------------------*/
/*                   ICU                                                      */
/* ---------------------------------------------------------------------------*/

#define ICU_PUBLIC_CODE                /* API functions                       */
#define ICU_PUBLIC_CONST               /* API constants                       */

#define ICU_PRIVATE_CODE               /* Internal functions                  */

#define ICU_PRIVATE_DATA               /* Module internal data                */
#define ICU_PRIVATE_CONST              /* Internal ROM Data                   */

#define ICU_APPL_CODE                  /* callbacks of the Application        */
#define ICU_APPL_CONST                 /* Applications' ROM Data              */
#define ICU_APPL_DATA                  /* Applications' RAM Data              */
#define ICU_FAST_DATA                  /* 'Near' RAM Data                     */


#define ICU_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define ICU_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define ICU_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define ICU_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define ICU_CONST                      /* Data Constants                      */


/* -------------------------------------------------------------------------- */
/*             FlexRay Driver                                                 */
/* -------------------------------------------------------------------------- */
#define FR_PRIVATE_CODE                /* module internal functions           */
#define FR_PRIVATE_CONST               /* module internal consts              */
#define FR_FAST_DATA                   /* module internal data in fast RAM    */
#define FR_PRIVATE_DATA                /* module internal data                */

#define FR_PUBLIC_CODE                 /* API functions                       */
#define FR_PUBLIC_CONST                /* API constants                       */
#define FR_CODE
#define FR_APPL_CODE                   /* callbacks of the Application        */
#define FR_APPL_CONST                  /* Applications' ROM Data              */
#define FR_VAR

#define FR_INIT_DATA                   /* module variables                    */
#define FR_CONST                       /* module constants                    */

#define FR_NOINIT_DATA                 /* module variables that are           */
                                              /* not initialized              */
#define FR_VAR_POWER_ON_INIT           /* module variables that are           */
                                             /* initialized on Powerup        */

/*
 * the applications' data blocks must have the same classifier
 * like the EEPIF expects
 */
#define FR_APPL_DATA              /* Applications' Ram Data                   */
#define FR_CONFIG_CONST           /* Descriptor Tables -> Config-dependent    */
#define FR_CONFIG_DATA            /* Configuration dependent (reg. size) data */
#define FR_DATA                   /* Global Variables                         */

/* ---------------------------------------------------------------------------*/
/*                   CAN                                                      */
/* ---------------------------------------------------------------------------*/

#define CAN_AFCAN_PUBLIC_CODE          /* API functions                       */
#define CAN_AFCAN_PUBLIC_CONST         /* API constants                       */

#define CAN_AFCAN_PRIVATE_CODE         /* Internal functions                  */

#define CAN_AFCAN_PRIVATE_DATA         /* Module internal data                */
#define CAN_AFCAN_PRIVATE_CONST        /* Internal ROM Data                   */

#define CAN_AFCAN_APPL_CODE            /* callbacks of the Application        */
#define CAN_AFCAN_APPL_CONST           /* Applications' ROM Data              */
#define CAN_AFCAN_APPL_DATA            /* Applications' RAM Data              */
#define CAN_AFCAN_FAST_DATA            /* 'Near' RAM Data                     */


#define CAN_AFCAN_CONFIG_CONST         /* Desc. Tables -> Config-dependent    */
#define CAN_AFCAN_CONFIG_DATA          /* Config. dependent (reg. size) data  */

#define CAN_AFCAN_INIT_DATA            /* Data which is initialized during
                                          Startup                             */
#define CAN_AFCAN_NOINIT_DATA          /* Data which is not initialized during
                                          Startup                             */
#define CAN_AFCAN_CONST                /* Data Constants                      */


/* ---------------------------------------------------------------------------*/
/*                   LIN                                                      */
/* ---------------------------------------------------------------------------*/

#define LIN_PUBLIC_CODE                /* API functions                       */
#define LIN_PUBLIC_CONST               /* API constants                       */

#define LIN_PRIVATE_CODE               /* Internal functions                  */

#define LIN_PRIVATE_DATA               /* Module internal data                */
#define LIN_PRIVATE_CONST              /* Internal ROM Data                   */

#define LIN_APPL_CODE                  /* callbacks of the Application        */
#define LIN_APPL_CONST                 /* Applications' ROM Data              */
#define LIN_APPL_DATA                  /* Applications' RAM Data              */
#define LIN_FAST_DATA                  /* 'Near' RAM Data                     */


#define LIN_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define LIN_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define LIN_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define LIN_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define LIN_CONST                      /* Data Constants                      */

/* ---------------------------------------------------------------------------*/
/*                   FLS                                                      */
/* ---------------------------------------------------------------------------*/

#define FLS_PUBLIC_CODE                /* API functions                       */
#define FLS_PUBLIC_CONST               /* API constants                       */

#define FLS_PRIVATE_CODE               /* Internal functions                  */

#define FLS_PRIVATE_DATA               /* Module internal data                */
#define FLS_PRIVATE_CONST              /* Internal ROM Data                   */

#define FLS_APPL_CODE                  /* callbacks of the Application        */
#define FLS_APPL_CONST                 /* Applications' ROM Data              */
#define FLS_APPL_DATA                  /* Applications' RAM Data              */
#define FLS_FAST_DATA                  /* 'Near' RAM Data                     */


#define FLS_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define FLS_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define FLS_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define FLS_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define FLS_CONST                      /* Data Constants                      */





/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

/*define error code or information code*/
#define IOHWAB_CODE

#define IOHWAB_VAR

#define IOHWAB_APPL_DATA
#define IOHWAB_APPL_CODE

#define IOHWAB_CONST











/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#endif /* COMPILER_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
