/*============================================================================*/
/* Project      = AUTOSAR NEC Xx4 MCAL Components                             */
/* File name    = Translation_Fx4.h                                           */
/* Version      = 3.0.15a                                                     */
/* Date         = 22-Sep-2010                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2010 by NEC Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* This translation file maps device file macros with user defined (NEC_Xx4)  */
/* macros.  Generator uses this translation file inorder to avoid hardcoding  */
/* of base addressess or the usage of device header file macros directly.     */
/*                                                                            */
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
/*              Devices:        Fx4                                           */
/*              Compiler:       GHS V5.1.6c                                   */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:   22-Jun-2010 : Initial version
 * V3.0.1:   23-Jun-2010 : Macros for port module added.
 * V3.0.2:   30-Jun-2010 : Macros for ICU and ADC Driver are added.
 * V3.0.3:   02-Jul-2010 : Macros for ADC and Timers are updated to have the 
 *                         interrupt number on left hand side.
 * V3.0.4:   06-Jul-2010 : Macros for MCU updated.
 * V3.0.5:   07-Jul-2010 : HW Unit 1 Macros for ADC added.
 * V3.0.6:   08-Jul-2010 : HW Unit 1 channel Macros for ADC added.
 * V3.0.7:   09-Jul-2010 : Macros for SPI are added.
 * V3.0.8:   13-Jul-2010 : Macros for PORT are added.
 * V3.0.9:   19-Jul-2010 : Macros for LIN are updated.
 * V3.0.10:  21-Jul-2010 : Macros for ICU updated.
 * V3.0.11:  26-Jul-2010 : Macros for DLY and PIC Macro are added for PWM.
 * V3.0.12:  28-Jul-2010 : Macro NEC_DLYA0CMPm is updated to NEC_DLYA0CMP0m
 *                         Macros for MCU added.
 * V3.0.13:  29-Jul-2010 : Macros for CAN updated.
 * V3.0.14:  02-Aug-2010 : Macro NEC_DLYAEN is added for PWM module.
 * V3.0.15:  03-Sep-2010 : Macros for ICU are updated for Previous Input
 *                         control register.
 * V3.0.15a: 22-Sep-2010 : Macros for ICU are updated for External Interrupt 
 *                         edge detection registers(INTP11-INTP15)
 */
/******************************************************************************/
  
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                 Macros for Watchdog Driver                                 **
*******************************************************************************/
#define NEC_WDTA0WDTE        WDTA0WDTE
#define NEC_WDTA0EVAC        WDTA0EVAC
#define NEC_WDTA0REF         WDTA0REF
#define NEC_WDTA0MD          WDTA0MD
#define NEC_WDTA1WDTE        WDTA1WDTE
#define NEC_WDTA1EVAC        WDTA1EVAC
#define NEC_WDTA1REF         WDTA1REF
#define NEC_WDTA1MD          WDTA1MD

/*******************************************************************************
**                 Macros for ADC Driver                                      **
*******************************************************************************/
#define NEC_DTRS0            DTRS0
#define NEC_DTRS1            DTRS1
#define NEC_DTRS2            DTRS2
#define NEC_DTRS3            DTRS3
#define NEC_DTRS4            DTRS4
#define NEC_DTRS5            DTRS5
#define NEC_DTRS6            DTRS6
#define NEC_DTRS7            DTRS7

#define NEC_DSA0L            DSA0L
#define NEC_DSA1L            DSA1L
#define NEC_DSA2L            DSA2L
#define NEC_DSA3L            DSA3L
#define NEC_DSA4L            DSA4L
#define NEC_DSA5L            DSA5L
#define NEC_DSA6L            DSA6L
#define NEC_DSA7L            DSA7L

#define NEC_ADCA0DB0CR       ADCA0DB0CR
#define NEC_ADCA0DB1CR       ADCA0DB1CR
#define NEC_ADCA0DB2CR       ADCA0DB2CR

#define NEC_ADCA1DB0CR       ADCA1DB0CR
#define NEC_ADCA1DB1CR       ADCA1DB1CR
#define NEC_ADCA1DB2CR       ADCA1DB2CR

#define NEC_DMACT0IC_119     ICDMA0
#define NEC_DMACT1IC_120     ICDMA1
#define NEC_DMACT2IC_121     ICDMA2
#define NEC_DMACT3IC_122     ICDMA3
#define NEC_DMACT4IC_123     ICDMA4
#define NEC_DMACT5IC_124     ICDMA5
#define NEC_DMACT6IC_125     ICDMA6
#define NEC_DMACT7IC_126     ICDMA7

#define NEC_ADCA0CG0         ADCA0CG0
#define NEC_ADCA0CTL0        ADCA0CTL0

#define NEC_ADCA1CG0         ADCA1CG0
#define NEC_ADCA1CTL0        ADCA1CTL0

#define NEC_ADCA0C00CR       ADCA0C00CR
#define NEC_ADCA0C01CR       ADCA0C01CR
#define NEC_ADCA0C02CR       ADCA0C02CR
#define NEC_ADCA0C03CR       ADCA0C03CR
#define NEC_ADCA0C04CR       ADCA0C04CR
#define NEC_ADCA0C05CR       ADCA0C05CR
#define NEC_ADCA0C06CR       ADCA0C06CR
#define NEC_ADCA0C07CR       ADCA0C07CR
#define NEC_ADCA0C08CR       ADCA0C08CR
#define NEC_ADCA0C09CR       ADCA0C09CR
#define NEC_ADCA0C10CR       ADCA0C10CR
#define NEC_ADCA0C11CR       ADCA0C11CR
#define NEC_ADCA0C12CR       ADCA0C12CR
#define NEC_ADCA0C13CR       ADCA0C13CR
#define NEC_ADCA0C14CR       ADCA0C14CR
#define NEC_ADCA0C15CR       ADCA0C15CR
#define NEC_ADCA0C16CR       ADCA0C16CR
#define NEC_ADCA0C17CR       ADCA0C17CR
#define NEC_ADCA0C18CR       ADCA0C18CR
#define NEC_ADCA0C19CR       ADCA0C19CR
#define NEC_ADCA0C20CR       ADCA0C20CR
#define NEC_ADCA0C21CR       ADCA0C21CR
#define NEC_ADCA0C22CR       ADCA0C22CR
#define NEC_ADCA0C23CR       ADCA0C23CR
#define NEC_ADCA0C24CR       ADCA0C24CR
#define NEC_ADCA0DGCR        ADCA0DGCR

#define NEC_ADCA1C00CR       ADCA1C00CR
#define NEC_ADCA1C01CR       ADCA1C01CR
#define NEC_ADCA1C02CR       ADCA1C02CR
#define NEC_ADCA1C03CR       ADCA1C03CR
#define NEC_ADCA1C04CR       ADCA1C04CR
#define NEC_ADCA1C05CR       ADCA1C05CR
#define NEC_ADCA1C06CR       ADCA1C06CR
#define NEC_ADCA1C07CR       ADCA1C07CR
#define NEC_ADCA1C08CR       ADCA1C08CR
#define NEC_ADCA1C09CR       ADCA1C09CR
#define NEC_ADCA1C10CR       ADCA1C10CR
#define NEC_ADCA1C11CR       ADCA1C11CR
#define NEC_ADCA1C12CR       ADCA1C12CR
#define NEC_ADCA1C13CR       ADCA1C13CR
#define NEC_ADCA1C14CR       ADCA1C14CR
#define NEC_ADCA1C15CR       ADCA1C15CR
#define NEC_ADCA1C16CR       ADCA1C16CR
#define NEC_ADCA1C17CR       ADCA1C17CR
#define NEC_ADCA1C18CR       ADCA1C18CR
#define NEC_ADCA1C19CR       ADCA1C19CR
#define NEC_ADCA1C20CR       ADCA1C20CR
#define NEC_ADCA1C21CR       ADCA1C21CR
#define NEC_ADCA1C22CR       ADCA1C22CR
#define NEC_ADCA1C23CR       ADCA1C23CR
#define NEC_ADCA1C24CR       ADCA1C24CR
#define NEC_ADCA1DGCR        ADCA1DGCR

#define NEC_ADCA0TG0IC_101_102_103       ICADCA0I0
#define NEC_ADCA1TG0IC_143_144_145       ICADCA1I0

#define NEC_DTFR0            DTFR0
#define NEC_DTFR1            DTFR1
#define NEC_DTFR2            DTFR2
#define NEC_DTFR3            DTFR3
#define NEC_DTFR4            DTFR4
#define NEC_DTFR5            DTFR5
#define NEC_DTFR6            DTFR6
#define NEC_DTFR7            DTFR7

#define NEC_DRQCLR           DRQCLR
/*******************************************************************************
**              Common Macros for ICU, GPT and PWM Drivers                    **
*******************************************************************************/

/* Base address of the TAUA0 channel 0 registers structure */
#define NEC_TAUA0CDR0       TAUA0CDR0

/* Base address of the TAUA0 channel 1 registers structure */
#define NEC_TAUA0CDR1       TAUA0CDR1

/* Base address of the TAUA0 channel 2 registers structure */
#define NEC_TAUA0CDR2       TAUA0CDR2

/* Base address of the TAUA0 channel 3 registers structure */
#define NEC_TAUA0CDR3       TAUA0CDR3

/* Base address of the TAUA0 channel 4 registers structure */
#define NEC_TAUA0CDR4       TAUA0CDR4

/* Base address of the TAUA0 channel 5 registers structure */
#define NEC_TAUA0CDR5       TAUA0CDR5

/* Base address of the TAUA0 channel 6 registers structure */
#define NEC_TAUA0CDR6       TAUA0CDR6

/* Base address of the TAUA0 channel 7 registers structure */
#define NEC_TAUA0CDR7       TAUA0CDR7

/* Base address of the TAUA0 channel 8 registers structure */
#define NEC_TAUA0CDR8       TAUA0CDR8

/* Base address of the TAUA0 channel 9 registers structure */
#define NEC_TAUA0CDR9       TAUA0CDR9

/* Base address of the TAUA0 channel 10 registers structure */
#define NEC_TAUA0CDR10      TAUA0CDR10

/* Base address of the TAUA0 channel 11 registers structure */
#define NEC_TAUA0CDR11      TAUA0CDR11

/* Base address of the TAUA0 channel 12 registers structure */
#define NEC_TAUA0CDR12      TAUA0CDR12

/* Base address of the TAUA0 channel 13 registers structure */
#define NEC_TAUA0CDR13      TAUA0CDR13

/* Base address of the TAUA0 channel 14 registers structure */
#define NEC_TAUA0CDR14      TAUA0CDR14

/* Base address of the TAUA0 channel 15 registers structure */
#define NEC_TAUA0CDR15      TAUA0CDR15

/* Base address of the TAUA1 channel 0 registers structure */
#define NEC_TAUA1CDR0       TAUA1CDR0

/* Base address of the TAUA1 channel 1 registers structure */
#define NEC_TAUA1CDR1       TAUA1CDR1

/* Base address of the TAUA1 channel 2 registers structure */
#define NEC_TAUA1CDR2       TAUA1CDR2

/* Base address of the TAUA1 channel 3 registers structure */
#define NEC_TAUA1CDR3       TAUA1CDR3
 
/* Base address of the TAUA1 channel 4 registers structure */
#define NEC_TAUA1CDR4       TAUA1CDR4

/* Base address of the TAUA1 channel 5 registers structure */
#define NEC_TAUA1CDR5       TAUA1CDR5

/* Base address of the TAUA1 channel 6 registers structure */
#define NEC_TAUA1CDR6       TAUA1CDR6

/* Base address of the TAUA1 channel 7 registers structure */
#define NEC_TAUA1CDR7       TAUA1CDR7

/* Base address of the TAUA1 channel 8 registers structure */
#define NEC_TAUA1CDR8       TAUA1CDR8

/* Base address of the TAUA1 channel 9 registers structure */
#define NEC_TAUA1CDR9       TAUA1CDR9

/* Base address of the TAUA1 channel 10 registers structure */
#define NEC_TAUA1CDR10      TAUA1CDR10

/* Base address of the TAUA1 channel 11 registers structure */
#define NEC_TAUA1CDR11      TAUA1CDR11

/* Base address of the TAUA1 channel 12 registers structure */
#define NEC_TAUA1CDR12      TAUA1CDR12

/* Base address of the TAUA1 channel 13 registers structure */
#define NEC_TAUA1CDR13      TAUA1CDR13

/* Base address of the TAUA1 channel 14 registers structure */
#define NEC_TAUA1CDR14      TAUA1CDR14

/* Base address of the TAUA1 channel 15 registers structure */
#define NEC_TAUA1CDR15      TAUA1CDR15

/* Base address of the TAUA2 channel 0 registers structure */
#define NEC_TAUA2CDR0       TAUA2CDR0

/* Base address of the TAUA2 channel 1 registers structure */
#define NEC_TAUA2CDR1       TAUA2CDR1

/* Base address of the TAUA2 channel 2 registers structure */
#define NEC_TAUA2CDR2       TAUA2CDR2

/* Base address of the TAUA2 channel 3 registers structure */
#define NEC_TAUA2CDR3       TAUA2CDR3
 
/* Base address of the TAUA2 channel 4 registers structure */
#define NEC_TAUA2CDR4       TAUA2CDR4

/* Base address of the TAUA2 channel 5 registers structure */
#define NEC_TAUA2CDR5       TAUA2CDR5

/* Base address of the TAUA2 channel 6 registers structure */
#define NEC_TAUA2CDR6       TAUA2CDR6

/* Base address of the TAUA2 channel 7 registers structure */
#define NEC_TAUA2CDR7       TAUA2CDR7

/* Base address of the TAUA2 channel 8 registers structure */
#define NEC_TAUA2CDR8       TAUA2CDR8

/* Base address of the TAUA2 channel 9 registers structure */
#define NEC_TAUA2CDR9       TAUA2CDR9

/* Base address of the TAUA2 channel 10 registers structure */
#define NEC_TAUA2CDR10      TAUA2CDR10

/* Base address of the TAUA2 channel 11 registers structure */
#define NEC_TAUA2CDR11      TAUA2CDR11

/* Base address of the TAUA2 channel 12 registers structure */
#define NEC_TAUA2CDR12      TAUA2CDR12

/* Base address of the TAUA2 channel 13 registers structure */
#define NEC_TAUA2CDR13      TAUA2CDR13

/* Base address of the TAUA2 channel 14 registers structure */
#define NEC_TAUA2CDR14      TAUA2CDR14

/* Base address of the TAUA2 channel 15 registers structure */
#define NEC_TAUA2CDR15      TAUA2CDR15

/* Base address of the TAUA3 channel 0 registers structure */
#define NEC_TAUA3CDR0       TAUA3CDR0

/* Base address of the TAUA3 channel 1 registers structure */
#define NEC_TAUA3CDR1       TAUA3CDR1

/* Base address of the TAUA3 channel 2 registers structure */
#define NEC_TAUA3CDR2       TAUA3CDR2

/* Base address of the TAUA3 channel 3 registers structure */
#define NEC_TAUA3CDR3       TAUA3CDR3
 
/* Base address of the TAUA3 channel 4 registers structure */
#define NEC_TAUA3CDR4       TAUA3CDR4

/* Base address of the TAUA3 channel 5 registers structure */
#define NEC_TAUA3CDR5       TAUA3CDR5

/* Base address of the TAUA3 channel 6 registers structure */
#define NEC_TAUA3CDR6       TAUA3CDR6

/* Base address of the TAUA3 channel 7 registers structure */
#define NEC_TAUA3CDR7       TAUA3CDR7

/* Base address of the TAUA3 channel 8 registers structure */
#define NEC_TAUA3CDR8       TAUA3CDR8

/* Base address of the TAUA3 channel 9 registers structure */
#define NEC_TAUA3CDR9       TAUA3CDR9

/* Base address of the TAUA3 channel 10 registers structure */
#define NEC_TAUA3CDR10      TAUA3CDR10

/* Base address of the TAUA3 channel 11 registers structure */
#define NEC_TAUA3CDR11      TAUA3CDR11

/* Base address of the TAUA3 channel 12 registers structure */
#define NEC_TAUA3CDR12      TAUA3CDR12

/* Base address of the TAUA3 channel 13 registers structure */
#define NEC_TAUA3CDR13      TAUA3CDR13

/* Base address of the TAUA3 channel 14 registers structure */
#define NEC_TAUA3CDR14      TAUA3CDR14

/* Base address of the TAUA3 channel 15 registers structure */
#define NEC_TAUA3CDR15      TAUA3CDR15

/* Base address of the TAUA4 channel 0 registers structure */
#define NEC_TAUA4CDR0       TAUA4CDR0

/* Base address of the TAUA4 channel 1 registers structure */
#define NEC_TAUA4CDR1       TAUA4CDR1

/* Base address of the TAUA4 channel 2 registers structure */
#define NEC_TAUA4CDR2       TAUA4CDR2

/* Base address of the TAUA4 channel 3 registers structure */
#define NEC_TAUA4CDR3       TAUA4CDR3
 
/* Base address of the TAUA4 channel 4 registers structure */
#define NEC_TAUA4CDR4       TAUA4CDR4

/* Base address of the TAUA4 channel 5 registers structure */
#define NEC_TAUA4CDR5       TAUA4CDR5

/* Base address of the TAUA4 channel 6 registers structure */
#define NEC_TAUA4CDR6       TAUA4CDR6

/* Base address of the TAUA4 channel 7 registers structure */
#define NEC_TAUA4CDR7       TAUA4CDR7

/* Base address of the TAUA4 channel 8 registers structure */
#define NEC_TAUA4CDR8       TAUA4CDR8

/* Base address of the TAUA4 channel 9 registers structure */
#define NEC_TAUA4CDR9       TAUA4CDR9

/* Base address of the TAUA4 channel 10 registers structure */
#define NEC_TAUA4CDR10      TAUA4CDR10

/* Base address of the TAUA4 channel 11 registers structure */
#define NEC_TAUA4CDR11      TAUA4CDR11

/* Base address of the TAUA4 channel 12 registers structure */
#define NEC_TAUA4CDR12      TAUA4CDR12

/* Base address of the TAUA4 channel 13 registers structure */
#define NEC_TAUA4CDR13      TAUA4CDR13

/* Base address of the TAUA4 channel 14 registers structure */
#define NEC_TAUA4CDR14      TAUA4CDR14

/* Base address of the TAUA4 channel 15 registers structure */
#define NEC_TAUA4CDR15      TAUA4CDR15

/* Base address of the TAUB1 channel 0 registers structure */
#define NEC_TAUB1CDR0       TAUB1CDR0

/* Base address of the TAUB1 channel 1 registers structure */
#define NEC_TAUB1CDR1       TAUB1CDR1

/* Base address of the TAUB1 channel 2 registers structure */
#define NEC_TAUB1CDR2       TAUB1CDR2

/* Base address of the TAUB1 channel 3 registers structure */
#define NEC_TAUB1CDR3       TAUB1CDR3
 
/* Base address of the TAUB1 channel 4 registers structure */
#define NEC_TAUB1CDR4       TAUB1CDR4

/* Base address of the TAUB1 channel 5 registers structure */
#define NEC_TAUB1CDR5       TAUB1CDR5

/* Base address of the TAUB1 channel 6 registers structure */
#define NEC_TAUB1CDR6       TAUB1CDR6

/* Base address of the TAUB1 channel 7 registers structure */
#define NEC_TAUB1CDR7       TAUB1CDR7

/* Base address of the TAUB1 channel 8 registers structure */
#define NEC_TAUB1CDR8       TAUB1CDR8

/* Base address of the TAUB1 channel 9 registers structure */
#define NEC_TAUB1CDR9       TAUB1CDR9

/* Base address of the TAUB1 channel 10 registers structure */
#define NEC_TAUB1CDR10      TAUB1CDR10

/* Base address of the TAUB1 channel 11 registers structure */
#define NEC_TAUB1CDR11      TAUB1CDR11

/* Base address of the TAUB1 channel 12 registers structure */
#define NEC_TAUB1CDR12      TAUB1CDR12

/* Base address of the TAUB1 channel 13 registers structure */
#define NEC_TAUB1CDR13      TAUB1CDR13

/* Base address of the TAUB1 channel 14 registers structure */
#define NEC_TAUB1CDR14      TAUB1CDR14

/* Base address of the TAUB1 channel 15 registers structure */
#define NEC_TAUB1CDR15      TAUB1CDR15

/* Base address of the TAUC2 channel 0 registers structure */
#define NEC_TAUC2CDR0       TAUC2CDR0

/* Base address of the TAUC2 channel 1 registers structure */
#define NEC_TAUC2CDR1       TAUC2CDR1

/* Base address of the TAUC2 channel 2 registers structure */
#define NEC_TAUC2CDR2       TAUC2CDR2

/* Base address of the TAUC2 channel 3 registers structure */
#define NEC_TAUC2CDR3       TAUC2CDR3
 
/* Base address of the TAUC2 channel 4 registers structure */
#define NEC_TAUC2CDR4       TAUC2CDR4

/* Base address of the TAUC2 channel 5 registers structure */
#define NEC_TAUC2CDR5       TAUC2CDR5

/* Base address of the TAUC2 channel 6 registers structure */
#define NEC_TAUC2CDR6       TAUC2CDR6

/* Base address of the TAUC2 channel 7 registers structure */
#define NEC_TAUC2CDR7       TAUC2CDR7

/* Base address of the TAUC2 channel 8 registers structure */
#define NEC_TAUC2CDR8       TAUC2CDR8

/* Base address of the TAUC2 channel 9 registers structure */
#define NEC_TAUC2CDR9       TAUC2CDR9

/* Base address of the TAUC2 channel 10 registers structure */
#define NEC_TAUC2CDR10      TAUC2CDR10

/* Base address of the TAUC2 channel 11 registers structure */
#define NEC_TAUC2CDR11      TAUC2CDR11

/* Base address of the TAUC2 channel 12 registers structure */
#define NEC_TAUC2CDR12      TAUC2CDR12

/* Base address of the TAUC2 channel 13 registers structure */
#define NEC_TAUC2CDR13      TAUC2CDR13

/* Base address of the TAUC2 channel 14 registers structure */
#define NEC_TAUC2CDR14      TAUC2CDR14

/* Base address of the TAUC2 channel 15 registers structure */
#define NEC_TAUC2CDR15      TAUC2CDR15

/* Base address of the TAUC3 channel 0 registers structure */
#define NEC_TAUC3CDR0       TAUC3CDR0

/* Base address of the TAUC3 channel 1 registers structure */
#define NEC_TAUC3CDR1       TAUC3CDR1

/* Base address of the TAUC3 channel 2 registers structure */
#define NEC_TAUC3CDR2       TAUC3CDR2

/* Base address of the TAUC3 channel 3 registers structure */
#define NEC_TAUC3CDR3       TAUC3CDR3
 
/* Base address of the TAUC3 channel 4 registers structure */
#define NEC_TAUC3CDR4       TAUC3CDR4

/* Base address of the TAUC3 channel 5 registers structure */
#define NEC_TAUC3CDR5       TAUC3CDR5

/* Base address of the TAUC3 channel 6 registers structure */
#define NEC_TAUC3CDR6       TAUC3CDR6

/* Base address of the TAUC3 channel 7 registers structure */
#define NEC_TAUC3CDR7       TAUC3CDR7

/* Base address of the TAUC3 channel 8 registers structure */
#define NEC_TAUC3CDR8       TAUC3CDR8

/* Base address of the TAUC3 channel 9 registers structure */
#define NEC_TAUC3CDR9       TAUC3CDR9

/* Base address of the TAUC3 channel 10 registers structure */
#define NEC_TAUC3CDR10      TAUC3CDR10

/* Base address of the TAUC3 channel 11 registers structure */
#define NEC_TAUC3CDR11      TAUC3CDR11

/* Base address of the TAUC3 channel 12 registers structure */
#define NEC_TAUC3CDR12      TAUC3CDR12

/* Base address of the TAUC3 channel 13 registers structure */
#define NEC_TAUC3CDR13      TAUC3CDR13

/* Base address of the TAUC3 channel 14 registers structure */
#define NEC_TAUC3CDR14      TAUC3CDR14

/* Base address of the TAUC3 channel 15 registers structure */
#define NEC_TAUC3CDR15      TAUC3CDR15

/* Base address of the TAUC4 channel 0 registers structure */
#define NEC_TAUC4CDR0       TAUC4CDR0

/* Base address of the TAUC4 channel 1 registers structure */
#define NEC_TAUC4CDR1       TAUC4CDR1

/* Base address of the TAUC4 channel 2 registers structure */
#define NEC_TAUC4CDR2       TAUC4CDR2

/* Base address of the TAUC4 channel 3 registers structure */
#define NEC_TAUC4CDR3       TAUC4CDR3
 
/* Base address of the TAUC4 channel 4 registers structure */
#define NEC_TAUC4CDR4       TAUC4CDR4

/* Base address of the TAUC4 channel 5 registers structure */
#define NEC_TAUC4CDR5       TAUC4CDR5

/* Base address of the TAUC4 channel 6 registers structure */
#define NEC_TAUC4CDR6       TAUC4CDR6

/* Base address of the TAUC4 channel 7 registers structure */
#define NEC_TAUC4CDR7       TAUC4CDR7

/* Base address of the TAUC4 channel 8 registers structure */
#define NEC_TAUC4CDR8       TAUC4CDR8

/* Base address of the TAUC4 channel 9 registers structure */
#define NEC_TAUC4CDR9       TAUC4CDR9

/* Base address of the TAUC4 channel 10 registers structure */
#define NEC_TAUC4CDR10      TAUC4CDR10

/* Base address of the TAUC4 channel 11 registers structure */
#define NEC_TAUC4CDR11      TAUC4CDR11

/* Base address of the TAUC4 channel 12 registers structure */
#define NEC_TAUC4CDR12      TAUC4CDR12

/* Base address of the TAUC4 channel 13 registers structure */
#define NEC_TAUC4CDR13      TAUC4CDR13

/* Base address of the TAUC4 channel 14 registers structure */
#define NEC_TAUC4CDR14      TAUC4CDR14

/* Base address of the TAUC4 channel 15 registers structure */
#define NEC_TAUC4CDR15      TAUC4CDR15

/* Base address of the TAUC5 channel 0 registers structure */
#define NEC_TAUC5CDR0       TAUC5CDR0

/* Base address of the TAUC5 channel 1 registers structure */
#define NEC_TAUC5CDR1       TAUC5CDR1

/* Base address of the TAUC5 channel 2 registers structure */
#define NEC_TAUC5CDR2       TAUC5CDR2

/* Base address of the TAUC5 channel 3 registers structure */
#define NEC_TAUC5CDR3       TAUC5CDR3
 
/* Base address of the TAUC5 channel 4 registers structure */
#define NEC_TAUC5CDR4       TAUC5CDR4

/* Base address of the TAUC5 channel 5 registers structure */
#define NEC_TAUC5CDR5       TAUC5CDR5

/* Base address of the TAUC5 channel 6 registers structure */
#define NEC_TAUC5CDR6       TAUC5CDR6

/* Base address of the TAUC5 channel 7 registers structure */
#define NEC_TAUC5CDR7       TAUC5CDR7

/* Base address of the TAUC5 channel 8 registers structure */
#define NEC_TAUC5CDR8       TAUC5CDR8

/* Base address of the TAUC5 channel 9 registers structure */
#define NEC_TAUC5CDR9       TAUC5CDR9

/* Base address of the TAUC5 channel 10 registers structure */
#define NEC_TAUC5CDR10      TAUC5CDR10

/* Base address of the TAUC5 channel 11 registers structure */
#define NEC_TAUC5CDR11      TAUC5CDR11

/* Base address of the TAUC5 channel 12 registers structure */
#define NEC_TAUC5CDR12      TAUC5CDR12

/* Base address of the TAUC5 channel 13 registers structure */
#define NEC_TAUC5CDR13      TAUC5CDR13

/* Base address of the TAUC5 channel 14 registers structure */
#define NEC_TAUC5CDR14      TAUC5CDR14

/* Base address of the TAUC5 channel 15 registers structure */
#define NEC_TAUC5CDR15      TAUC5CDR15

/* Base address of the TAUC6 channel 0 registers structure */
#define NEC_TAUC6CDR0       TAUC6CDR0

/* Base address of the TAUC6 channel 1 registers structure */
#define NEC_TAUC6CDR1       TAUC6CDR1

/* Base address of the TAUC6 channel 2 registers structure */
#define NEC_TAUC6CDR2       TAUC6CDR2

/* Base address of the TAUC6 channel 3 registers structure */
#define NEC_TAUC6CDR3       TAUC6CDR3
 
/* Base address of the TAUC6 channel 4 registers structure */
#define NEC_TAUC6CDR4       TAUC6CDR4

/* Base address of the TAUC6 channel 5 registers structure */
#define NEC_TAUC6CDR5       TAUC6CDR5

/* Base address of the TAUC6 channel 6 registers structure */
#define NEC_TAUC6CDR6       TAUC6CDR6

/* Base address of the TAUC6 channel 7 registers structure */
#define NEC_TAUC6CDR7       TAUC6CDR7

/* Base address of the TAUC6 channel 8 registers structure */
#define NEC_TAUC6CDR8       TAUC6CDR8

/* Base address of the TAUC6 channel 9 registers structure */
#define NEC_TAUC6CDR9       TAUC6CDR9

/* Base address of the TAUC6 channel 10 registers structure */
#define NEC_TAUC6CDR10      TAUC6CDR10

/* Base address of the TAUC6 channel 11 registers structure */
#define NEC_TAUC6CDR11      TAUC6CDR11

/* Base address of the TAUC6 channel 12 registers structure */
#define NEC_TAUC6CDR12      TAUC6CDR12

/* Base address of the TAUC6 channel 13 registers structure */
#define NEC_TAUC6CDR13      TAUC6CDR13

/* Base address of the TAUC6 channel 14 registers structure */
#define NEC_TAUC6CDR14      TAUC6CDR14

/* Base address of the TAUC6 channel 15 registers structure */
#define NEC_TAUC6CDR15      TAUC6CDR15

/* Base address of the TAUJ0 channel 0 registers structure */
#define NEC_TAUJ0CDR0       TAUJ0CDR0

/* Base address of the TAUJ0 channel 1 registers structure */
#define NEC_TAUJ0CDR1       TAUJ0CDR1

/* Base address of the TAUJ0 channel 2 registers structure */
#define NEC_TAUJ0CDR2       TAUJ0CDR2

/* Base address of the TAUJ0 channel 3 registers structure */
#define NEC_TAUJ0CDR3       TAUJ0CDR3

/* Base address of the TAUJ1 channel 0 registers structure */
#define NEC_TAUJ1CDR0       TAUJ1CDR0

/* Base address of the TAUJ1 channel 1 registers structure */
#define NEC_TAUJ1CDR1       TAUJ1CDR1

/* Base address of the TAUJ1 channel 2 registers structure */
#define NEC_TAUJ1CDR2       TAUJ1CDR2

/* Base address of the TAUJ1 channel 3 registers structure */
#define NEC_TAUJ1CDR3       TAUJ1CDR3

/* Base address of the TAUJ2 channel 0 registers structure */
#define NEC_TAUJ2CDR0       TAUJ2CDR0

/* Base address of the TAUJ2 channel 1 registers structure */
#define NEC_TAUJ2CDR1       TAUJ2CDR1

/* Base address of the TAUJ2 channel 2 registers structure */
#define NEC_TAUJ2CDR2       TAUJ2CDR2

/* Base address of the TAUJ2 channel 3 registers structure */
#define NEC_TAUJ2CDR3       TAUJ2CDR3

/* Base address of the TAUA Unit user control registers structure */
#define NEC_TAUA0TOL        TAUA0TOL
#define NEC_TAUA1TOL        TAUA1TOL
#define NEC_TAUA2TOL        TAUA2TOL
#define NEC_TAUA3TOL        TAUA3TOL
#define NEC_TAUA4TOL        TAUA4TOL

/* Base address of the TAUA Unit OS control registers structure */
#define NEC_TAUA0TPS        TAUA0TPS
#define NEC_TAUA1TPS        TAUA1TPS
#define NEC_TAUA2TPS        TAUA2TPS
#define NEC_TAUA3TPS        TAUA3TPS
#define NEC_TAUA4TPS        TAUA4TPS

/* Base address of the TAUB Unit user control registers structure */
#define NEC_TAUB1TOL        TAUB1TOL

/* Base address of the TAUC Unit user control registers structure */
#define NEC_TAUC2TOL        TAUC2TOL
#define NEC_TAUC3TOL        TAUC3TOL
#define NEC_TAUC4TOL        TAUC4TOL
#define NEC_TAUC5TOL        TAUC5TOL
#define NEC_TAUC6TOL        TAUC6TOL

/* Base address of the TAUB Unit user control registers structure */
#define NEC_TAUB1TPS        TAUB1TPS

/* Base address of the TAUB Unit user control registers structure */
#define NEC_TAUC2TPS        TAUC2TPS
#define NEC_TAUC3TPS        TAUC3TPS
#define NEC_TAUC4TPS        TAUC4TPS
#define NEC_TAUC5TPS        TAUC5TPS
#define NEC_TAUC6TPS        TAUC6TPS

/* Base address of the TAUJ Unit user control registers structure for PWM */
#define NEC_TAUJ0TE         TAUJ0TE
#define NEC_TAUJ1TE         TAUJ1TE
#define NEC_TAUJ2TE         TAUJ2TE

/* Base address of the TAUJ Unit user control registers structure for GPT */
#define NEC_TAUJ0TS         TAUJ0TS
#define NEC_TAUJ1TS         TAUJ1TS
#define NEC_TAUJ2TS         TAUJ2TS

/* Base address of the TAUJ Unit OS control registers structure */
#define NEC_TAUJ0TPS        TAUJ0TPS
#define NEC_TAUJ1TPS        TAUJ1TPS
#define NEC_TAUJ2TPS        TAUJ2TPS

/* Base address of the TAUA0 registers structure */
#define NEC_TAUA0CMOR0      TAUA0CMOR0
#define NEC_TAUA0CMOR1      TAUA0CMOR1
#define NEC_TAUA0CMOR2      TAUA0CMOR2
#define NEC_TAUA0CMOR3      TAUA0CMOR3
#define NEC_TAUA0CMOR4      TAUA0CMOR4
#define NEC_TAUA0CMOR5      TAUA0CMOR5
#define NEC_TAUA0CMOR6      TAUA0CMOR6
#define NEC_TAUA0CMOR7      TAUA0CMOR7
#define NEC_TAUA0CMOR8      TAUA0CMOR8
#define NEC_TAUA0CMOR9      TAUA0CMOR9
#define NEC_TAUA0CMOR10     TAUA0CMOR10
#define NEC_TAUA0CMOR11     TAUA0CMOR11
#define NEC_TAUA0CMOR12     TAUA0CMOR12
#define NEC_TAUA0CMOR13     TAUA0CMOR13
#define NEC_TAUA0CMOR14     TAUA0CMOR14
#define NEC_TAUA0CMOR15     TAUA0CMOR15

/* Base address of the TAUA1 registers structure */
#define NEC_TAUA1CMOR0      TAUA1CMOR0
#define NEC_TAUA1CMOR1      TAUA1CMOR1
#define NEC_TAUA1CMOR2      TAUA1CMOR2
#define NEC_TAUA1CMOR3      TAUA1CMOR3
#define NEC_TAUA1CMOR4      TAUA1CMOR4
#define NEC_TAUA1CMOR5      TAUA1CMOR5
#define NEC_TAUA1CMOR6      TAUA1CMOR6
#define NEC_TAUA1CMOR7      TAUA1CMOR7
#define NEC_TAUA1CMOR8      TAUA1CMOR8
#define NEC_TAUA1CMOR9      TAUA1CMOR9
#define NEC_TAUA1CMOR10     TAUA1CMOR10
#define NEC_TAUA1CMOR11     TAUA1CMOR11
#define NEC_TAUA1CMOR12     TAUA1CMOR12
#define NEC_TAUA1CMOR13     TAUA1CMOR13
#define NEC_TAUA1CMOR14     TAUA1CMOR14
#define NEC_TAUA1CMOR15     TAUA1CMOR15

/* Base address of the TAUA2 registers structure */
#define NEC_TAUA2CMOR0      TAUA2CMOR0
#define NEC_TAUA2CMOR1      TAUA2CMOR1
#define NEC_TAUA2CMOR2      TAUA2CMOR2
#define NEC_TAUA2CMOR3      TAUA2CMOR3
#define NEC_TAUA2CMOR4      TAUA2CMOR4
#define NEC_TAUA2CMOR5      TAUA2CMOR5
#define NEC_TAUA2CMOR6      TAUA2CMOR6
#define NEC_TAUA2CMOR7      TAUA2CMOR7
#define NEC_TAUA2CMOR8      TAUA2CMOR8
#define NEC_TAUA2CMOR9      TAUA2CMOR9
#define NEC_TAUA2CMOR10     TAUA2CMOR10
#define NEC_TAUA2CMOR11     TAUA2CMOR11
#define NEC_TAUA2CMOR12     TAUA2CMOR12
#define NEC_TAUA2CMOR13     TAUA2CMOR13
#define NEC_TAUA2CMOR14     TAUA2CMOR14
#define NEC_TAUA2CMOR15     TAUA2CMOR15

/* Base address of the TAUA3 registers structure */
#define NEC_TAUA3CMOR0      TAUA3CMOR0
#define NEC_TAUA3CMOR1      TAUA3CMOR1
#define NEC_TAUA3CMOR2      TAUA3CMOR2
#define NEC_TAUA3CMOR3      TAUA3CMOR3
#define NEC_TAUA3CMOR4      TAUA3CMOR4
#define NEC_TAUA3CMOR5      TAUA3CMOR5
#define NEC_TAUA3CMOR6      TAUA3CMOR6
#define NEC_TAUA3CMOR7      TAUA3CMOR7
#define NEC_TAUA3CMOR8      TAUA3CMOR8
#define NEC_TAUA3CMOR9      TAUA3CMOR9
#define NEC_TAUA3CMOR10     TAUA3CMOR10
#define NEC_TAUA3CMOR11     TAUA3CMOR11
#define NEC_TAUA3CMOR12     TAUA3CMOR12
#define NEC_TAUA3CMOR13     TAUA3CMOR13
#define NEC_TAUA3CMOR14     TAUA3CMOR14
#define NEC_TAUA3CMOR15     TAUA3CMOR15

/* Base address of the TAUA4 registers structure */
#define NEC_TAUA4CMOR0      TAUA4CMOR0
#define NEC_TAUA4CMOR1      TAUA4CMOR1
#define NEC_TAUA4CMOR2      TAUA4CMOR2
#define NEC_TAUA4CMOR3      TAUA4CMOR3
#define NEC_TAUA4CMOR4      TAUA4CMOR4
#define NEC_TAUA4CMOR5      TAUA4CMOR5
#define NEC_TAUA4CMOR6      TAUA4CMOR6
#define NEC_TAUA4CMOR7      TAUA4CMOR7
#define NEC_TAUA4CMOR8      TAUA4CMOR8
#define NEC_TAUA4CMOR9      TAUA4CMOR9
#define NEC_TAUA4CMOR10     TAUA4CMOR10
#define NEC_TAUA4CMOR11     TAUA4CMOR11
#define NEC_TAUA4CMOR12     TAUA4CMOR12
#define NEC_TAUA4CMOR13     TAUA4CMOR13
#define NEC_TAUA4CMOR14     TAUA4CMOR14
#define NEC_TAUA4CMOR15     TAUA4CMOR15

/* Base address of the TAUB1 registers structure */
#define NEC_TAUB1CMOR0      TAUB1CMOR0
#define NEC_TAUB1CMOR1      TAUB1CMOR1
#define NEC_TAUB1CMOR2      TAUB1CMOR2
#define NEC_TAUB1CMOR3      TAUB1CMOR3
#define NEC_TAUB1CMOR4      TAUB1CMOR4
#define NEC_TAUB1CMOR5      TAUB1CMOR5
#define NEC_TAUB1CMOR6      TAUB1CMOR6
#define NEC_TAUB1CMOR7      TAUB1CMOR7
#define NEC_TAUB1CMOR8      TAUB1CMOR8
#define NEC_TAUB1CMOR9      TAUB1CMOR9
#define NEC_TAUB1CMOR10     TAUB1CMOR10
#define NEC_TAUB1CMOR11     TAUB1CMOR11
#define NEC_TAUB1CMOR12     TAUB1CMOR12
#define NEC_TAUB1CMOR13     TAUB1CMOR13
#define NEC_TAUB1CMOR14     TAUB1CMOR14
#define NEC_TAUB1CMOR15     TAUB1CMOR15

/* Base address of the TAUC2 registers structure */
#define NEC_TAUC2CMOR0      TAUC2CMOR0
#define NEC_TAUC2CMOR1      TAUC2CMOR1
#define NEC_TAUC2CMOR2      TAUC2CMOR2
#define NEC_TAUC2CMOR3      TAUC2CMOR3
#define NEC_TAUC2CMOR4      TAUC2CMOR4
#define NEC_TAUC2CMOR5      TAUC2CMOR5
#define NEC_TAUC2CMOR6      TAUC2CMOR6
#define NEC_TAUC2CMOR7      TAUC2CMOR7
#define NEC_TAUC2CMOR8      TAUC2CMOR8
#define NEC_TAUC2CMOR9      TAUC2CMOR9
#define NEC_TAUC2CMOR10     TAUC2CMOR10
#define NEC_TAUC2CMOR11     TAUC2CMOR11
#define NEC_TAUC2CMOR12     TAUC2CMOR12
#define NEC_TAUC2CMOR13     TAUC2CMOR13
#define NEC_TAUC2CMOR14     TAUC2CMOR14
#define NEC_TAUC2CMOR15     TAUC2CMOR15

/* Base address of the TAUC3 registers structure */
#define NEC_TAUC3CMOR0      TAUC3CMOR0
#define NEC_TAUC3CMOR1      TAUC3CMOR1
#define NEC_TAUC3CMOR2      TAUC3CMOR2
#define NEC_TAUC3CMOR3      TAUC3CMOR3
#define NEC_TAUC3CMOR4      TAUC3CMOR4
#define NEC_TAUC3CMOR5      TAUC3CMOR5
#define NEC_TAUC3CMOR6      TAUC3CMOR6
#define NEC_TAUC3CMOR7      TAUC3CMOR7
#define NEC_TAUC3CMOR8      TAUC3CMOR8
#define NEC_TAUC3CMOR9      TAUC3CMOR9
#define NEC_TAUC3CMOR10     TAUC3CMOR10
#define NEC_TAUC3CMOR11     TAUC3CMOR11
#define NEC_TAUC3CMOR12     TAUC3CMOR12
#define NEC_TAUC3CMOR13     TAUC3CMOR13
#define NEC_TAUC3CMOR14     TAUC3CMOR14
#define NEC_TAUC3CMOR15     TAUC3CMOR15

/* Base address of the TAUC4 registers structure */
#define NEC_TAUC4CMOR0      TAUC4CMOR0
#define NEC_TAUC4CMOR1      TAUC4CMOR1
#define NEC_TAUC4CMOR2      TAUC4CMOR2
#define NEC_TAUC4CMOR3      TAUC4CMOR3
#define NEC_TAUC4CMOR4      TAUC4CMOR4
#define NEC_TAUC4CMOR5      TAUC4CMOR5
#define NEC_TAUC4CMOR6      TAUC4CMOR6
#define NEC_TAUC4CMOR7      TAUC4CMOR7
#define NEC_TAUC4CMOR8      TAUC4CMOR8
#define NEC_TAUC4CMOR9      TAUC4CMOR9
#define NEC_TAUC4CMOR10     TAUC4CMOR10
#define NEC_TAUC4CMOR11     TAUC4CMOR11
#define NEC_TAUC4CMOR12     TAUC4CMOR12
#define NEC_TAUC4CMOR13     TAUC4CMOR13
#define NEC_TAUC4CMOR14     TAUC4CMOR14
#define NEC_TAUC4CMOR15     TAUC4CMOR15

/* Base address of the TAUC5 registers structure */
#define NEC_TAUC5CMOR0      TAUC5CMOR0
#define NEC_TAUC5CMOR1      TAUC5CMOR1
#define NEC_TAUC5CMOR2      TAUC5CMOR2
#define NEC_TAUC5CMOR3      TAUC5CMOR3
#define NEC_TAUC5CMOR4      TAUC5CMOR4
#define NEC_TAUC5CMOR5      TAUC5CMOR5
#define NEC_TAUC5CMOR6      TAUC5CMOR6
#define NEC_TAUC5CMOR7      TAUC5CMOR7
#define NEC_TAUC5CMOR8      TAUC5CMOR8
#define NEC_TAUC5CMOR9      TAUC5CMOR9
#define NEC_TAUC5CMOR10     TAUC5CMOR10
#define NEC_TAUC5CMOR11     TAUC5CMOR11
#define NEC_TAUC5CMOR12     TAUC5CMOR12
#define NEC_TAUC5CMOR13     TAUC5CMOR13
#define NEC_TAUC5CMOR14     TAUC5CMOR14
#define NEC_TAUC5CMOR15     TAUC5CMOR15

/* Base address of the TAUC6 registers structure */
#define NEC_TAUC6CMOR0      TAUC6CMOR0
#define NEC_TAUC6CMOR1      TAUC6CMOR1
#define NEC_TAUC6CMOR2      TAUC6CMOR2
#define NEC_TAUC6CMOR3      TAUC6CMOR3
#define NEC_TAUC6CMOR4      TAUC6CMOR4
#define NEC_TAUC6CMOR5      TAUC6CMOR5
#define NEC_TAUC6CMOR6      TAUC6CMOR6
#define NEC_TAUC6CMOR7      TAUC6CMOR7
#define NEC_TAUC6CMOR8      TAUC6CMOR8
#define NEC_TAUC6CMOR9      TAUC6CMOR9
#define NEC_TAUC6CMOR10     TAUC6CMOR10
#define NEC_TAUC6CMOR11     TAUC6CMOR11
#define NEC_TAUC6CMOR12     TAUC6CMOR12
#define NEC_TAUC6CMOR13     TAUC6CMOR13
#define NEC_TAUC6CMOR14     TAUC6CMOR14
#define NEC_TAUC6CMOR15     TAUC6CMOR15

/* Base address of the TAUC7 registers structure */
#define NEC_TAUC7CMOR0      TAUC7CMOR0
#define NEC_TAUC7CMOR1      TAUC7CMOR1
#define NEC_TAUC7CMOR2      TAUC7CMOR2
#define NEC_TAUC7CMOR3      TAUC7CMOR3
#define NEC_TAUC7CMOR4      TAUC7CMOR4
#define NEC_TAUC7CMOR5      TAUC7CMOR5
#define NEC_TAUC7CMOR6      TAUC7CMOR6
#define NEC_TAUC7CMOR7      TAUC7CMOR7
#define NEC_TAUC7CMOR8      TAUC7CMOR8
#define NEC_TAUC7CMOR9      TAUC7CMOR9
#define NEC_TAUC7CMOR10     TAUC7CMOR10
#define NEC_TAUC7CMOR11     TAUC7CMOR11
#define NEC_TAUC7CMOR12     TAUC7CMOR12
#define NEC_TAUC7CMOR13     TAUC7CMOR13
#define NEC_TAUC7CMOR14     TAUC7CMOR14
#define NEC_TAUC7CMOR15     TAUC7CMOR15

/* Base address of the TAUJ0 registers structure */
#define NEC_TAUJ0CMOR0      TAUJ0CMOR0
#define NEC_TAUJ0CMOR1      TAUJ0CMOR1
#define NEC_TAUJ0CMOR2      TAUJ0CMOR2
#define NEC_TAUJ0CMOR3      TAUJ0CMOR3

/* Base address of the TAUJ1 registers structure */
#define NEC_TAUJ1CMOR0      TAUJ1CMOR0
#define NEC_TAUJ1CMOR1      TAUJ1CMOR1
#define NEC_TAUJ1CMOR2      TAUJ1CMOR2
#define NEC_TAUJ1CMOR3      TAUJ1CMOR3

/* Base address of the TAUJ2 registers structure */
#define NEC_TAUJ2CMOR0      TAUJ2CMOR0
#define NEC_TAUJ2CMOR1      TAUJ2CMOR1
#define NEC_TAUJ2CMOR2      TAUJ2CMOR2
#define NEC_TAUJ2CMOR3      TAUJ2CMOR3

/* Interrupt control registers for TAUA */
#define NEC_ICTAUA0I0_20       ICTAUA0I0
#define NEC_ICTAUA0I1_21       ICTAUA0I1
#define NEC_ICTAUA0I2_22       ICTAUA0I2
#define NEC_ICTAUA0I3_23       ICTAUA0I3
#define NEC_ICTAUA0I4_24       ICTAUA0I4
#define NEC_ICTAUA0I5_25       ICTAUA0I5
#define NEC_ICTAUA0I6_26       ICTAUA0I6
#define NEC_ICTAUA0I7_27       ICTAUA0I7
#define NEC_ICTAUA0I8_28       ICTAUA0I8
#define NEC_ICTAUA0I9_29       ICTAUA0I9
#define NEC_ICTAUA0I10_30      ICTAUA0I10
#define NEC_ICTAUA0I11_31      ICTAUA0I11
#define NEC_ICTAUA0I12_32      ICTAUA0I12
#define NEC_ICTAUA0I13_33      ICTAUA0I13
#define NEC_ICTAUA0I14_34      ICTAUA0I14
#define NEC_ICTAUA0I15_35      ICTAUA0I15
#define NEC_ICTAUA1I0       ICTAUA1I0
#define NEC_ICTAUA1I1       ICTAUA1I1
#define NEC_ICTAUA1I2       ICTAUA1I2
#define NEC_ICTAUA1I3       ICTAUA1I3
#define NEC_ICTAUA1I4       ICTAUA1I4
#define NEC_ICTAUA1I5       ICTAUA1I5
#define NEC_ICTAUA1I6       ICTAUA1I6
#define NEC_ICTAUA1I7       ICTAUA1I7
#define NEC_ICTAUA1I8       ICTAUA1I8
#define NEC_ICTAUA1I9       ICTAUA1I9
#define NEC_ICTAUA1I10      ICTAUA1I10
#define NEC_ICTAUA1I11      ICTAUA1I11
#define NEC_ICTAUA1I12      ICTAUA1I12
#define NEC_ICTAUA1I13      ICTAUA1I13
#define NEC_ICTAUA1I14      ICTAUA1I14
#define NEC_ICTAUA1I15      ICTAUA1I15
#define NEC_ICTAUA2I0       ICTAUA2I0
#define NEC_ICTAUA2I1       ICTAUA2I1
#define NEC_ICTAUA2I2       ICTAUA2I2
#define NEC_ICTAUA2I3       ICTAUA2I3
#define NEC_ICTAUA2I4       ICTAUA2I4
#define NEC_ICTAUA2I5       ICTAUA2I5
#define NEC_ICTAUA2I6       ICTAUA2I6
#define NEC_ICTAUA2I7       ICTAUA2I7
#define NEC_ICTAUA2I8       ICTAUA2I8
#define NEC_ICTAUA2I9       ICTAUA2I9
#define NEC_ICTAUA2I10      ICTAUA2I10
#define NEC_ICTAUA2I11      ICTAUA2I11
#define NEC_ICTAUA2I12      ICTAUA2I12
#define NEC_ICTAUA2I13      ICTAUA2I13
#define NEC_ICTAUA2I14      ICTAUA2I14
#define NEC_ICTAUA2I15      ICTAUA2I15
#define NEC_ICTAUA3I0       ICTAUA3I0
#define NEC_ICTAUA3I1       ICTAUA3I1
#define NEC_ICTAUA3I2       ICTAUA3I2
#define NEC_ICTAUA3I3       ICTAUA3I3
#define NEC_ICTAUA3I4       ICTAUA3I4
#define NEC_ICTAUA3I5       ICTAUA3I5
#define NEC_ICTAUA3I6       ICTAUA3I6
#define NEC_ICTAUA3I7       ICTAUA3I7
#define NEC_ICTAUA3I8       ICTAUA3I8
#define NEC_ICTAUA3I9       ICTAUA3I9
#define NEC_ICTAUA3I10      ICTAUA3I10
#define NEC_ICTAUA3I11      ICTAUA3I11
#define NEC_ICTAUA3I12      ICTAUA3I12
#define NEC_ICTAUA3I13      ICTAUA3I13
#define NEC_ICTAUA3I14      ICTAUA3I14
#define NEC_ICTAUA3I15      ICTAUA3I15
#define NEC_ICTAUA4I0       ICTAUA4I0
#define NEC_ICTAUA4I1       ICTAUA4I1
#define NEC_ICTAUA4I2       ICTAUA4I2
#define NEC_ICTAUA4I3       ICTAUA4I3
#define NEC_ICTAUA4I4       ICTAUA4I4
#define NEC_ICTAUA4I5       ICTAUA4I5
#define NEC_ICTAUA4I6       ICTAUA4I6
#define NEC_ICTAUA4I7       ICTAUA4I7
#define NEC_ICTAUA4I8       ICTAUA4I8
#define NEC_ICTAUA4I9       ICTAUA4I9
#define NEC_ICTAUA4I10      ICTAUA4I10
#define NEC_ICTAUA4I11      ICTAUA4I11
#define NEC_ICTAUA4I12      ICTAUA4I12
#define NEC_ICTAUA4I13      ICTAUA4I13
#define NEC_ICTAUA4I14      ICTAUA4I14
#define NEC_ICTAUA4I15      ICTAUA4I15

/* Interrupt control registers for TAUB */
#define NEC_ICTAUB1I0_36       ICTAUB1I0
#define NEC_ICTAUB1I1_37       ICTAUB1I1
#define NEC_ICTAUB1I2_38       ICTAUB1I2
#define NEC_ICTAUB1I3_39       ICTAUB1I3
#define NEC_ICTAUB1I4_40       ICTAUB1I4
#define NEC_ICTAUB1I5_41       ICTAUB1I5
#define NEC_ICTAUB1I6_42       ICTAUB1I6
#define NEC_ICTAUB1I7_43       ICTAUB1I7
#define NEC_ICTAUB1I8_44       ICTAUB1I8
#define NEC_ICTAUB1I9_45       ICTAUB1I9
#define NEC_ICTAUB1I10_46      ICTAUB1I10
#define NEC_ICTAUB1I11_47      ICTAUB1I11
#define NEC_ICTAUB1I12_48      ICTAUB1I12
#define NEC_ICTAUB1I13_49      ICTAUB1I13
#define NEC_ICTAUB1I14_50      ICTAUB1I14
#define NEC_ICTAUB1I15_51      ICTAUB1I15

/* Interrupt control registers for TAUC */
#define NEC_ICTAUC2I0_52       ICTAUC2I0
#define NEC_ICTAUC2I1_53       ICTAUC2I1
#define NEC_ICTAUC2I2_54       ICTAUC2I2
#define NEC_ICTAUC2I3_55       ICTAUC2I3
#define NEC_ICTAUC2I4_56       ICTAUC2I4
#define NEC_ICTAUC2I5_57       ICTAUC2I5
#define NEC_ICTAUC2I6_58       ICTAUC2I6
#define NEC_ICTAUC2I7_59       ICTAUC2I7
#define NEC_ICTAUC2I8_60       ICTAUC2I8
#define NEC_ICTAUC2I9_61       ICTAUC2I9
#define NEC_ICTAUC2I10_62      ICTAUC2I10
#define NEC_ICTAUC2I11_63      ICTAUC2I11
#define NEC_ICTAUC2I12_64      ICTAUC2I12
#define NEC_ICTAUC2I13_65      ICTAUC2I13
#define NEC_ICTAUC2I14_66      ICTAUC2I14
#define NEC_ICTAUC2I15_67      ICTAUC2I15
#define NEC_ICTAUC3I0_68       ICTAUC3I0
#define NEC_ICTAUC3I1_69       ICTAUC3I1
#define NEC_ICTAUC3I2_70       ICTAUC3I2
#define NEC_ICTAUC3I3_71       ICTAUC3I3
#define NEC_ICTAUC3I4_72       ICTAUC3I4
#define NEC_ICTAUC3I5_73       ICTAUC3I5
#define NEC_ICTAUC3I6_74       ICTAUC3I6
#define NEC_ICTAUC3I7_75       ICTAUC3I7
#define NEC_ICTAUC3I8_76       ICTAUC3I8
#define NEC_ICTAUC3I9_77       ICTAUC3I9
#define NEC_ICTAUC3I10_78      ICTAUC3I10
#define NEC_ICTAUC3I11_79      ICTAUC3I11
#define NEC_ICTAUC3I12_80      ICTAUC3I12
#define NEC_ICTAUC3I13_81      ICTAUC3I13
#define NEC_ICTAUC3I14_82      ICTAUC3I14
#define NEC_ICTAUC3I15_83      ICTAUC3I15
#define NEC_ICTAUC4I0_84       ICTAUC4I0
#define NEC_ICTAUC4I1_85       ICTAUC4I1
#define NEC_ICTAUC4I2_86       ICTAUC4I2
#define NEC_ICTAUC4I3_87       ICTAUC4I3
#define NEC_ICTAUC4I4_88       ICTAUC4I4
#define NEC_ICTAUC4I5_89       ICTAUC4I5
#define NEC_ICTAUC4I6_90       ICTAUC4I6
#define NEC_ICTAUC4I7_91       ICTAUC4I7
#define NEC_ICTAUC4I8_92       ICTAUC4I8
#define NEC_ICTAUC4I9_93       ICTAUC4I9
#define NEC_ICTAUC4I10_94      ICTAUC4I10
#define NEC_ICTAUC4I11_95      ICTAUC4I11
#define NEC_ICTAUC4I12_96      ICTAUC4I12
#define NEC_ICTAUC4I13_97      ICTAUC4I13
#define NEC_ICTAUC4I14_98      ICTAUC4I14
#define NEC_ICTAUC4I15_99      ICTAUC4I15
/*#define NEC_ICTAUC5I0       ICTAUC5I0
#define NEC_ICTAUC5I1       ICTAUC5I1
#define NEC_ICTAUC5I2       ICTAUC5I2
#define NEC_ICTAUC5I3       ICTAUC5I3
#define NEC_ICTAUC5I4       ICTAUC5I4
#define NEC_ICTAUC5I5       ICTAUC5I5
#define NEC_ICTAUC5I6       ICTAUC5I6
#define NEC_ICTAUC5I7       ICTAUC5I7
#define NEC_ICTAUC5I8       ICTAUC5I8
#define NEC_ICTAUC5I9       ICTAUC5I9
#define NEC_ICTAUC5I10      ICTAUC5I10
#define NEC_ICTAUC5I11      ICTAUC5I11
#define NEC_ICTAUC5I12      ICTAUC5I12
#define NEC_ICTAUC5I13      ICTAUC5I13
#define NEC_ICTAUC5I14      ICTAUC5I14
#define NEC_ICTAUC5I15      ICTAUC5I15
#define NEC_ICTAUC6I0       ICTAUC6I0
#define NEC_ICTAUC6I1       ICTAUC6I1
#define NEC_ICTAUC6I2       ICTAUC6I2
#define NEC_ICTAUC6I3       ICTAUC6I3
#define NEC_ICTAUC6I4       ICTAUC6I4
#define NEC_ICTAUC6I5       ICTAUC6I5
#define NEC_ICTAUC6I6       ICTAUC6I6
#define NEC_ICTAUC6I7       ICTAUC6I7
#define NEC_ICTAUC6I8       ICTAUC6I8
#define NEC_ICTAUC6I9       ICTAUC6I9
#define NEC_ICTAUC6I10      ICTAUC6I10
#define NEC_ICTAUC6I11      ICTAUC6I11
#define NEC_ICTAUC6I12      ICTAUC6I12
#define NEC_ICTAUC6I13      ICTAUC6I13
#define NEC_ICTAUC6I14      ICTAUC6I14
#define NEC_ICTAUC6I15      ICTAUC6I15 */

/* Interrupt control registers for TAUJ */
#define NEC_ICTAUJ0I0_135       ICTAUJ0I0
#define NEC_ICTAUJ0I1_136       ICTAUJ0I1
#define NEC_ICTAUJ0I2_137       ICTAUJ0I2
#define NEC_ICTAUJ0I3_138       ICTAUJ0I3
#define NEC_ICTAUJ1I0_139       ICTAUJ1I0
#define NEC_ICTAUJ1I1_140       ICTAUJ1I1
#define NEC_ICTAUJ1I2_141       ICTAUJ1I2
#define NEC_ICTAUJ1I3_142       ICTAUJ1I3
#define NEC_ICTAUJ2I0       ICTAUJ2I0
#define NEC_ICTAUJ2I1       ICTAUJ2I1
#define NEC_ICTAUJ2I2       ICTAUJ2I2
#define NEC_ICTAUJ2I3       ICTAUJ2I3

/* Interrupt control registers for OSTM0 */
#define NEC_ICOSTM0IIC      ICOSTM0_147
/*******************************************************************************
**                 Macros for PWM Driver                                      **
*******************************************************************************/

/* Delay Macro Control Registers */
#define NEC_DLYA0CTL0         DLYA0CTL00
#define NEC_DLYA0CTL1         DLYA0CTL01
#define NEC_DLYA0CMP00        DLYA0CMP00
#define NEC_DLYA0CMP01        DLYA0CMP01
#define NEC_DLYA0CMP02        DLYA0CMP02
#define NEC_DLYA0CMP03        DLYA0CMP03
#define NEC_DLYA0CMP04        DLYA0CMP04
#define NEC_DLYA0CMP05        DLYA0CMP05
#define NEC_DLYA0CMP06        DLYA0CMP06
#define NEC_DLYA0CMP07        DLYA0CMP07
#define NEC_DLYA0CMP10        DLYA0CMP10
#define NEC_DLYA0CMP11        DLYA0CMP11
#define NEC_DLYA0CMP12        DLYA0CMP12
#define NEC_DLYA0CMP13        DLYA0CMP13
#define NEC_DLYA0CMP14        DLYA0CMP14
#define NEC_DLYA0CMP15        DLYA0CMP15
#define NEC_DLYA0CMP16        DLYA0CMP16
#define NEC_DLYA0CMP17        DLYA0CMP17
#define NEC_DLYA0CMP20        DLYA0CMP20
#define NEC_DLYA0CMP21        DLYA0CMP21
#define NEC_DLYA0CMP22        DLYA0CMP22
#define NEC_DLYA0CMP23        DLYA0CMP23
#define NEC_DLYA0CMP24        DLYA0CMP24
#define NEC_DLYA0CMP25        DLYA0CMP25
#define NEC_DLYA0CMP26        DLYA0CMP26
#define NEC_DLYA0CMP27        DLYA0CMP27
#define NEC_DLYA0CMP30        DLYA0CMP30
#define NEC_DLYA0CMP31        DLYA0CMP31
#define NEC_DLYA0CMP32        DLYA0CMP32
#define NEC_DLYA0CMP33        DLYA0CMP33
#define NEC_DLYA0CMP34        DLYA0CMP34
#define NEC_DLYA0CMP35        DLYA0CMP35
#define NEC_DLYA0CMP36        DLYA0CMP36
#define NEC_DLYA0CMP37        DLYA0CMP37
#define NEC_DLYA0CMP40        DLYA0CMP40
#define NEC_DLYA0CMP41        DLYA0CMP41
#define NEC_DLYA0CMP42        DLYA0CMP42
#define NEC_DLYA0CMP43        DLYA0CMP43
#define NEC_DLYA0CMP44        DLYA0CMP44
#define NEC_DLYA0CMP45        DLYA0CMP45
#define NEC_DLYA0CMP46        DLYA0CMP46
#define NEC_DLYA0CMP47        DLYA0CMP47
#define NEC_DLYA0CMP50        DLYA0CMP50
#define NEC_DLYA0CMP51        DLYA0CMP51
#define NEC_DLYA0CMP52        DLYA0CMP52
#define NEC_DLYA0CMP53        DLYA0CMP53
#define NEC_DLYA0CMP54        DLYA0CMP54
#define NEC_DLYA0CMP55        DLYA0CMP55
#define NEC_DLYA0CMP56        DLYA0CMP56
#define NEC_DLYA0CMP57        DLYA0CMP57
#define NEC_DLYA0CMP60        DLYA0CMP60
#define NEC_DLYA0CMP61        DLYA0CMP61
#define NEC_DLYA0CMP62        DLYA0CMP62
#define NEC_DLYA0CMP63        DLYA0CMP63
#define NEC_DLYA0CMP64        DLYA0CMP64
#define NEC_DLYA0CMP65        DLYA0CMP65
#define NEC_DLYA0CMP66        DLYA0CMP66
#define NEC_DLYA0CMP67        DLYA0CMP67
#define NEC_DLYA0CMP70        DLYA0CMP70
#define NEC_DLYA0CMP71        DLYA0CMP71
#define NEC_DLYA0CMP72        DLYA0CMP72
#define NEC_DLYA0CMP73        DLYA0CMP73
#define NEC_DLYA0CMP74        DLYA0CMP74
#define NEC_DLYA0CMP75        DLYA0CMP75
#define NEC_DLYA0CMP76        DLYA0CMP76
#define NEC_DLYA0CMP77        DLYA0CMP77

/* Delay enable register */
#define NEC_DLYAEN            DLYAEN

/* Synchronous start of TAU Units registers */
/* Synchronous Start Trigger Register */
#define NEC_PIC0SST          PIC0SST

/* Synchronous Start Enable Register 0 for TAUA0 */
#define NEC_PIC0SSER0        PIC0SSER0

/* Synchronous Start Enable Register 1 for TAUA1 */
#define NEC_PIC0SSER1        PIC0SSER1

/* Synchronous Start Enable Register 2 for TAUJ0 and TAUJ1 */
#define NEC_PIC0SSER2        PIC0SSER2

/* Address for the PMCA register */
#define NEC_PMCA0CTL1        PMCA0CTL1

/*******************************************************************************
**                         Macros for ICU Driver                              **
*******************************************************************************/

/* Interrupt control registers for External Interrupts */
#define NEC_ICP0_9            ICP0
#define NEC_ICP1_10           ICP1
#define NEC_ICP2_11           ICP2
#define NEC_ICP3_12           ICP3
#define NEC_ICP4_13           ICP4
#define NEC_ICP5_14           ICP5
#define NEC_ICP6_15           ICP6
#define NEC_ICP7_16           ICP7
#define NEC_ICP8_17           ICP8
#define NEC_ICP9_18           ICP9
#define NEC_ICP10_19          ICP10
#define NEC_ICP11_208         ICP11
#define NEC_ICP12_209         ICP12
#define NEC_ICP13_210         ICP13
#define NEC_ICP14_211         ICP14
#define NEC_ICP15_212         ICP15

/* External Interrupt edge detection registers */
#define NEC_FCLA_INTP0      FCLA0CTL0
#define NEC_FCLA_INTP1      FCLA0CTL1
#define NEC_FCLA_INTP2      FCLA0CTL2
#define NEC_FCLA_INTP3      FCLA0CTL3
#define NEC_FCLA_INTP4      FCLA0CTL4
#define NEC_FCLA_INTP5      FCLA0CTL5
#define NEC_FCLA_INTP6      FCLA0CTL6
#define NEC_FCLA_INTP7      FCLA0CTL7
#define NEC_FCLA_INTP8      FCLA1CTL0
#define NEC_FCLA_INTP9      FCLA1CTL1
#define NEC_FCLA_INTP10     FCLA1CTL2
#define NEC_FCLA_INTP11     FCLA1CTL3
#define NEC_FCLA_INTP12     FCLA1CTL4
#define NEC_FCLA_INTP13     FCLA1CTL5
#define NEC_FCLA_INTP14     FCLA1CTL6
#define NEC_FCLA_INTP15     FCLA1CTL7

/* Previous Input control registers */
#define NEC_TISLTA0          TISLTA0

/*******************************************************************************
**                        Macros for GPT Driver                               **
*******************************************************************************/

/* Base address of the OSTM0 channel 0 registers structure */
#define NEC_OSTM0CMP         OSTM0CMP

/* Base address of the OSTM0 channel 0 registers structure */
#define NEC_OSTM0CTL         OSTM0CTL

/*******************************************************************************
**                 Macros for FLS Software Component                          **
*******************************************************************************/
#define NEC_FLMDCNT         FLMDCNT
#define NEC_FLMDPCMD        FLMDPCMD

/*******************************************************************************
**                 Macros for PORT Driver                                     **
*******************************************************************************/

#define NEC_P0               P0
#define NEC_PSR0             PSR0
#define NEC_PPR0             PPR0
#define NEC_PM0              PM0
#define NEC_PMC0             PMC0
#define NEC_PFC0             PFC0
#define NEC_PFCE0            PFCE0
#define NEC_PNOT0            PNOT0
#define NEC_PMSR0            PMSR0
#define NEC_PMCSR0           PMCSR0
#define NEC_PIBC0            PIBC0
#define NEC_PBDC0            PBDC0
#define NEC_PIPC0            PIPC0
#define NEC_PU0              PU0
#define NEC_PD0              PD0
#define NEC_PODC0            PODC0
#define NEC_PDSC0            PDSC0
#define NEC_PIS0             PIS0
#define NEC_PISE0            PISE0
#define NEC_PPROTS0          PPROTS0
#define NEC_PPCMD0           PPCMD0

#define NEC_P1               P1
#define NEC_PSR1             PSR1
#define NEC_PPR1             PPR1
#define NEC_PM1              PM1
#define NEC_PMC1             PMC1
#define NEC_PFC1             PFC1
#define NEC_PFCE1            PFCE1
#define NEC_PNOT1            PNOT1
#define NEC_PMSR1            PMSR1
#define NEC_PMCSR1           PMCSR1
#define NEC_PIBC1            PIBC1
#define NEC_PBDC1            PBDC1
#define NEC_PIPC1            PIPC1
#define NEC_PU1              PU1
#define NEC_PD1              PD1
#define NEC_PODC1            PODC1
#define NEC_PDSC1            PDSC1
#define NEC_PIS1             PIS1
#define NEC_PISE1            PISE1
#define NEC_PPROTS1          PPROTS1
#define NEC_PPCMD1           PPCMD1

#define NEC_P2               P2
#define NEC_PSR2             PSR2
#define NEC_PPR2             PPR2
#define NEC_PM2              PM2
#define NEC_PMC2             PMC2
#define NEC_PFC2             PFC2
#define NEC_PFCE2            PFCE2
#define NEC_PNOT2            PNOT2
#define NEC_PMSR2            PMSR2
#define NEC_PMCSR2           PMCSR2
#define NEC_PIBC2            PIBC2
#define NEC_PBDC2            PBDC2
#define NEC_PIPC2            PIPC2
#define NEC_PU2              PU2
#define NEC_PD2              PD2
#define NEC_PODC2            PODC2
#define NEC_PDSC2            PDSC2
#define NEC_PIS2             PIS2
#define NEC_PISE2            PISE2
#define NEC_PPROTS2          PPROTS2
#define NEC_PPCMD2           PPCMD2
#define NEC_PROTCMD2         PROTCMD2
#define NEC_PROTS2           PROTS2

#define NEC_P3               P3
#define NEC_PSR3             PSR3
#define NEC_PPR3             PPR3
#define NEC_PM3              PM3
#define NEC_PMC3             PMC3
#define NEC_PFC3             PFC3
#define NEC_PFCE3            PFCE3
#define NEC_PNOT3            PNOT3
#define NEC_PMSR3            PMSR3
#define NEC_PMCSR3           PMCSR3
#define NEC_PIBC3            PIBC3
#define NEC_PBDC3            PBDC3
#define NEC_PIPC3            PIPC3
#define NEC_PU3              PU3
#define NEC_PD3              PD3
#define NEC_PODC3            PODC3
#define NEC_PDSC3            PDSC3
#define NEC_PIS3             PIS3
#define NEC_PISE3            PISE3
#define NEC_PPROTS3          PPROTS3
#define NEC_PPCMD3           PPCMD3

#define NEC_P4               P4
#define NEC_PSR4             PSR4
#define NEC_PPR4             PPR4
#define NEC_PM4              PM4
#define NEC_PMC4             PMC4
#define NEC_PFC4             PFC4
#define NEC_PFCE4            PFCE4
#define NEC_PNOT4            PNOT4
#define NEC_PMSR4            PMSR4
#define NEC_PMCSR4           PMCSR4
#define NEC_PIBC4            PIBC4
#define NEC_PBDC4            PBDC4
#define NEC_PIPC4            PIPC4
#define NEC_PU4              PU4
#define NEC_PD4              PD4
#define NEC_PODC4            PODC4
#define NEC_PDSC4            PDSC4
#define NEC_PIS4             PIS4
#define NEC_PISE4            PISE4
#define NEC_PPROTS4          PPROTS4
#define NEC_PPCMD4           PPCMD4

#define NEC_P10              P10
#define NEC_PSR10            PSR10
#define NEC_PPR10            PPR10
#define NEC_PM10             PM10
#define NEC_PMC10            PMC10
#define NEC_PNOT10           PNOT10
#define NEC_PMSR10           PMSR10
#define NEC_PMCSR10          PMCSR10
#define NEC_PIBC10           PIBC10
#define NEC_PBDC10           PBDC10
#define NEC_PODC10           PODC10
#define NEC_PPROTS10         PPROTS10
#define NEC_PPCMD10          PPCMD10

#define NEC_P11              P11
#define NEC_PSR11            PSR11
#define NEC_PPR11            PPR11
#define NEC_PM11             PM11
#define NEC_PMC11            PMC11
#define NEC_PNOT11           PNOT11
#define NEC_PMSR11           PMSR11
#define NEC_PIBC11           PIBC11
#define NEC_PBDC11           PBDC11
#define NEC_PODC11           PODC11
#define NEC_PPROTS11         PPROTS11
#define NEC_PPCMD11          PPCMD11

#define NEC_P12              P12
#define NEC_PSR12            PSR12
#define NEC_PPR12            PPR12
#define NEC_PM12             PM12
#define NEC_PMC12            PMC12
#define NEC_PNOT12           PNOT12
#define NEC_PMSR12           PMSR12
#define NEC_PMCSR12          PMCSR12
#define NEC_PIBC12           PIBC12
#define NEC_PBDC12           PBDC12
#define NEC_PODC12           PODC12
#define NEC_PPROTS12         PPROTS12
#define NEC_PPCMD12          PPCMD12

#define NEC_P13              P13
#define NEC_PSR13            PSR13
#define NEC_PPR13            PPR13
#define NEC_PM13             PM13
#define NEC_PMC13            PMC13
#define NEC_PFC13            PFC13
#define NEC_PFCE13           PFCE13
#define NEC_PNOT13           PNOT13
#define NEC_PMSR13           PMSR13
#define NEC_PMCSR13          PMCSR13
#define NEC_PIBC13           PIBC13
#define NEC_PBDC13           PBDC13
#define NEC_PODC13           PODC13
#define NEC_PPROTS13         PPROTS13
#define NEC_PPCMD13          PPCMD13

#define NEC_P21              P21
#define NEC_PSR21            PSR21
#define NEC_PPR21            PPR21
#define NEC_PM21             PM21
#define NEC_PMC21            PMC21
#define NEC_PFC21            PFC21
#define NEC_PFCE21           PFCE21
#define NEC_PNOT21           PNOT21
#define NEC_PMSR21           PMSR21
#define NEC_PMCSR21          PMCSR21
#define NEC_PIBC21           PIBC21
#define NEC_PBDC21           PBDC21
#define NEC_PIPC21           PIPC21
#define NEC_PU21             PU21
#define NEC_PD21             PD21
#define NEC_PODC21           PODC21
#define NEC_PDSC21           PDSC21
#define NEC_PIS21            PIS21
#define NEC_PISE21           PISE21
#define NEC_PPROTS21         PPROTS21
#define NEC_PPCMD21          PPCMD21

#define NEC_P24              P24
#define NEC_PSR24            PSR24
#define NEC_PPR24            PPR24
#define NEC_PM24             PM24
#define NEC_PMC24            PMC24
#define NEC_PFC24            PFC24
#define NEC_PFCE24           PFCE24
#define NEC_PNOT24           PNOT24
#define NEC_PMSR24           PMSR24
#define NEC_PMCSR24          PMCSR24
#define NEC_PIBC24           PIBC24
#define NEC_PBDC24           PBDC24
#define NEC_PIPC24           PIPC24
#define NEC_PU24             PU24
#define NEC_PD24             PD24
#define NEC_PODC24           PODC24
#define NEC_PDSC24           PDSC24
#define NEC_PIS24            PIS24
#define NEC_PISE24           PISE24
#define NEC_PPROTS24         PPROTS24
#define NEC_PPCMD24          PPCMD24

#define NEC_P25              P25
#define NEC_PSR25            PSR25
#define NEC_PPR25            PPR25
#define NEC_PM25             PM25
#define NEC_PMC25            PMC25
#define NEC_PFC25            PFC25
#define NEC_PFCE25           PFCE25
#define NEC_PNOT25           PNOT25
#define NEC_PMSR25           PMSR25
#define NEC_PMCSR25          PMCSR25
#define NEC_PIBC25           PIBC25
#define NEC_PBDC25           PBDC25
#define NEC_PIPC25           PIPC25
#define NEC_PU25             PU25
#define NEC_PD25             PD25
#define NEC_PODC25           PODC25
#define NEC_PDSC25           PDSC25
#define NEC_PIS25            PIS25
#define NEC_PISE25           PISE25
#define NEC_PPROTS25         PPROTS25
#define NEC_PPCMD25          PPCMD25

#define NEC_P27              P27
#define NEC_PSR27            PSR27
#define NEC_PPR27            PPR27
#define NEC_PM27             PM27
#define NEC_PMC27            PMC27
#define NEC_PFC27            PFC27
#define NEC_PFCE27           PFCE27
#define NEC_PNOT27           PNOT27
#define NEC_PMSR27           PMSR27
#define NEC_PMCSR27          PMCSR27
#define NEC_PIBC27           PIBC27
#define NEC_PBDC27           PBDC27
#define NEC_PIPC27           PIPC27
#define NEC_PU27             PU27
#define NEC_PD27             PD27
#define NEC_PODC27           PODC27
#define NEC_PDSC27           PDSC27
#define NEC_PIS27            PIS27
#define NEC_PISE27           PISE27
#define NEC_PPROTS27         PPROTS27
#define NEC_PPCMD27          PPCMD27

#define NEC_JP0              JP0
#define NEC_JPSR0            JPSR0
#define NEC_JPPR0            JPPR0
#define NEC_JPM0             JPM0
#define NEC_JPMC0            JPMC0
#define NEC_JPFC0            JPFC0
#define NEC_JPNOT0           JPNOT0
#define NEC_JPMSR0           JPMSR0
#define NEC_JPMCSR0          JPMCSR0
#define NEC_JPIBC0           JPIBC0
#define NEC_JPBDC0           JPBDC0
#define NEC_JPIPC0           JPIPC0
#define NEC_JPU0             JPU0
#define NEC_JPD0             JPD0
#define NEC_JPODC0           JPODC0
#define NEC_JPDSC0           JPDSC0
#define NEC_JPIS0            JPIS0
#define NEC_JPISE0           JPISE0
#define NEC_JPPROTS0         JPPROTS0
#define NEC_JPPCMD0          JPPCMD0

#define NEC_FCLA0CTL0        FCLA0CTL0
#define NEC_FCLA0CTL1        FCLA0CTL1
#define NEC_FCLA0CTL2        FCLA0CTL2
#define NEC_FCLA0CTL3        FCLA0CTL3
#define NEC_FCLA0CTL4        FCLA0CTL4
#define NEC_FCLA0CTL5        FCLA0CTL5
#define NEC_FCLA0CTL6        FCLA0CTL6
#define NEC_FCLA0CTL7        FCLA0CTL7
#define NEC_FCLA1CTL0        FCLA1CTL0
#define NEC_FCLA1CTL1        FCLA1CTL1
#define NEC_FCLA1CTL2        FCLA1CTL2
#define NEC_FCLA1CTL3        FCLA1CTL3
#define NEC_FCLA1CTL4        FCLA1CTL4
#define NEC_FCLA1CTL5        FCLA1CTL5
#define NEC_FCLA1CTL6        FCLA1CTL6
#define NEC_FCLA1CTL7        FCLA1CTL7
#define NEC_FCLA2CTL0        FCLA2CTL0
#define NEC_FCLA2CTL1        FCLA2CTL1
#define NEC_FCLA3CTL0        FCLA3CTL0
#define NEC_FCLA3CTL1        FCLA3CTL1
#define NEC_FCLA3CTL2        FCLA3CTL2
#define NEC_FCLA3CTL3        FCLA3CTL3
#define NEC_FCLA3CTL4        FCLA3CTL4
#define NEC_FCLA3CTL5        FCLA3CTL5
#define NEC_FCLA3CTL6        FCLA3CTL6
#define NEC_FCLA3CTL7        FCLA3CTL7
#define NEC_FCLA4CTL0        FCLA4CTL0
#define NEC_FCLA4CTL1        FCLA4CTL1
#define NEC_FCLA4CTL2        FCLA4CTL2
#define NEC_FCLA4CTL3        FCLA4CTL3
#define NEC_FCLA4CTL4        FCLA4CTL4
#define NEC_FCLA4CTL5        FCLA4CTL5
#define NEC_FCLA4CTL6        FCLA4CTL6
#define NEC_FCLA4CTL7        FCLA4CTL7
#define NEC_FCLA5CTL0        FCLA5CTL0
#define NEC_FCLA5CTL1        FCLA5CTL1
#define NEC_FCLA5CTL2        FCLA5CTL2
#define NEC_FCLA5CTL3        FCLA5CTL3
#define NEC_FCLA5CTL4        FCLA5CTL4
#define NEC_FCLA5CTL5        FCLA5CTL5
#define NEC_FCLA5CTL6        FCLA5CTL6
#define NEC_FCLA5CTL7        FCLA5CTL7
#define NEC_FCLA6CTL0        FCLA6CTL0
#define NEC_FCLA6CTL1        FCLA6CTL1
#define NEC_FCLA6CTL2        FCLA6CTL2
#define NEC_FCLA6CTL3        FCLA6CTL3
#define NEC_FCLA6CTL4        FCLA6CTL4
#define NEC_FCLA6CTL5        FCLA6CTL5
#define NEC_FCLA6CTL6        FCLA6CTL6
#define NEC_FCLA6CTL7        FCLA6CTL7
#define NEC_FCLA7CTL0        FCLA7CTL0
#define NEC_FCLA7CTL1        FCLA7CTL1
#define NEC_FCLA7CTL2        FCLA7CTL2
#define NEC_FCLA7CTL3        FCLA7CTL3
#define NEC_FCLA7CTL4        FCLA7CTL4
#define NEC_FCLA7CTL5        FCLA7CTL5
#define NEC_FCLA8CTL0        FCLA8CTL0
#define NEC_FCLA8CTL1        FCLA8CTL1
#define NEC_FCLA8CTL2        FCLA8CTL2
#define NEC_FCLA8CTL3        FCLA8CTL3
#define NEC_FCLA8CTL4        FCLA8CTL4
#define NEC_FCLA8CTL5        FCLA8CTL5
#define NEC_FCLA8CTL6        FCLA8CTL6
#define NEC_FCLA8CTL7        FCLA8CTL7
#define NEC_FCLA15CTL0       FCLA15CTL0
#define NEC_FCLA15CTL1       FCLA15CTL1
#define NEC_FCLA15CTL2       FCLA15CTL2
#define NEC_FCLA15CTL3       FCLA15CTL3
#define NEC_FCLA15CTL4       FCLA15CTL4
#define NEC_FCLA16CTL0       FCLA16CTL0
#define NEC_FCLA16CTL1       FCLA16CTL1
#define NEC_FCLA16CTL2       FCLA16CTL2
#define NEC_FCLA16CTL3       FCLA16CTL3
#define NEC_FCLA16CTL4       FCLA16CTL4
#define NEC_FCLA21CTL0       FCLA21CTL0
#define NEC_FCLA21CTL1       FCLA21CTL1
#define NEC_FCLA21CTL2       FCLA21CTL2
#define NEC_FCLA21CTL3       FCLA21CTL3
#define NEC_FCLA21CTL4       FCLA21CTL4
#define NEC_FCLA21CTL5       FCLA21CTL5
#define NEC_FCLA21CTL6       FCLA21CTL6
#define NEC_FCLA21CTL7       FCLA21CTL7
#define NEC_FCLA22CTL0       FCLA22CTL0
#define NEC_FCLA22CTL1       FCLA22CTL1
#define NEC_FCLA22CTL2       FCLA22CTL2
#define NEC_FCLA22CTL3       FCLA22CTL3
#define NEC_FCLA22CTL4       FCLA22CTL4
#define NEC_FCLA22CTL5       FCLA22CTL5
#define NEC_FCLA22CTL6       FCLA22CTL6
#define NEC_FCLA22CTL7       FCLA22CTL7
#define NEC_FCLA23CTL0       FCLA23CTL0
#define NEC_FCLA23CTL1       FCLA23CTL1
#define NEC_FCLA23CTL2       FCLA23CTL2
#define NEC_FCLA23CTL3       FCLA23CTL3
#define NEC_FCLA24CTL0       FCLA24CTL0
#define NEC_FCLA24CTL1       FCLA24CTL1
#define NEC_FCLA24CTL2       FCLA24CTL2
#define NEC_FCLA24CTL3       FCLA24CTL3
#define NEC_FCLA25CTL0       FCLA25CTL0
#define NEC_FCLA25CTL1       FCLA25CTL1
#define NEC_FCLA25CTL2       FCLA25CTL2
#define NEC_FCLA25CTL3       FCLA25CTL3
#define NEC_FCLA25CTL4       FCLA25CTL4
#define NEC_FCLA25CTL5       FCLA25CTL5
#define NEC_FCLA25CTL6       FCLA25CTL6
#define NEC_FCLA25CTL7       FCLA25CTL7
#define NEC_FCLA26CTL0       FCLA26CTL0
#define NEC_FCLA26CTL1       FCLA26CTL1
#define NEC_FCLA26CTL2       FCLA26CTL2
#define NEC_FCLA26CTL3       FCLA26CTL3
#define NEC_FCLA26CTL4       FCLA26CTL4
#define NEC_FCLA26CTL5       FCLA26CTL5
#define NEC_FCLA26CTL6       FCLA26CTL6
#define NEC_FCLA26CTL7       FCLA26CTL7
#define NEC_FCLA27CTL0       FCLA27CTL0
#define NEC_FCLA27CTL1       FCLA27CTL1
#define NEC_FCLA27CTL2       FCLA27CTL2
#define NEC_FCLA27CTL3       FCLA27CTL3
#define NEC_FCLA27CTL4       FCLA27CTL4
#define NEC_FCLA27CTL5       FCLA27CTL5
#define NEC_FCLA27CTL6       FCLA27CTL6
#define NEC_FCLA27CTL7       FCLA27CTL7

#define NEC_DNFA0CTL         DNFA0CTL
#define NEC_DNFA0EN          DNFA0EN
#define NEC_DNFA0ENH         DNFA0ENH
#define NEC_DNFA0ENL         DNFA0ENL
#define NEC_DNFA1CTL         DNFA1CTL
#define NEC_DNFA1EN          DNFA1EN
#define NEC_DNFA1ENH         DNFA1ENH
#define NEC_DNFA5CTL         DNFA5CTL
#define NEC_DNFA5EN          DNFA5EN
#define NEC_DNFA5ENH         DNFA5ENH
#define NEC_DNFA5ENL         DNFA5ENL
#define NEC_DNFA8CTL         DNFA8CTL
#define NEC_DNFA8EN          DNFA8EN
#define NEC_DNFA8ENH         DNFA8ENH
#define NEC_DNFA8ENL         DNFA8ENL
#define NEC_DNFA9CTL         DNFA9CTL
#define NEC_DNFA9EN          DNFA9EN
#define NEC_DNFA9ENH         DNFA9ENH
#define NEC_DNFA9ENL         DNFA9ENL
#define NEC_DNFA10CTL        DNFA10CTL
#define NEC_DNFA10EN         DNFA10EN
#define NEC_DNFA10ENH        DNFA10ENH
#define NEC_DNFA10ENL        DNFA10ENL
#define NEC_DNFA11CTL        DNFA11CTL
#define NEC_DNFA11EN         DNFA11EN
#define NEC_DNFA11ENH        DNFA11ENH
#define NEC_DNFA11ENL        DNFA11ENL
#define NEC_DNFA12CTL        DNFA12CTL
#define NEC_DNFA12EN         DNFA12EN
#define NEC_DNFA12ENH        DNFA12ENH
#define NEC_DNFA12ENL        DNFA12ENL

#define NEC_PSC0             PSC0
#define NEC_PSC1             PSC1
#define NEC_PWS0             PWS0
#define NEC_PWS1             PWS1

/*******************************************************************************
**                 Macros for MCU Driver                                      **
*******************************************************************************/
#define NEC_CKSC_000  CKSC_000
#define NEC_CKSC_001  CKSC_001
#define NEC_CKSC_002  CKSC_002
#define NEC_CKSC_003  CKSC_003
#define NEC_CKSC_004  CKSC_004
#define NEC_CKSC_005  CKSC_005
#define NEC_CKSC_006  CKSC_006
#define NEC_CKSC_007  CKSC_007
#define NEC_CKSC_008  CKSC_008
#define NEC_CKSC_009  CKSC_009
#define NEC_CKSC_010  CKSC_010
#define NEC_CKSC_011  CKSC_011
#define NEC_CKSC_012  CKSC_012
#define NEC_CKSC_016  CKSC_016
#define NEC_CKSC_018  CKSC_018
#define NEC_CKSC_019  CKSC_019

#define NEC_CKSC_100  CKSC_100
#define NEC_CKSC_101  CKSC_101
#define NEC_CKSC_102  CKSC_102
#define NEC_CKSC_103  CKSC_103
#define NEC_CKSC_105  CKSC_105
#define NEC_CKSC_106  CKSC_106
#define NEC_CKSC_107  CKSC_107
#define NEC_CKSC_108  CKSC_108
#define NEC_CKSC_109  CKSC_109
#define NEC_CKSC_111  CKSC_111
#define NEC_CKSC_112  CKSC_112
#define NEC_CKSC_113  CKSC_113
#define NEC_CKSC_114  CKSC_114
#define NEC_CKSC_115  CKSC_115
#define NEC_CKSC_119  CKSC_119
#define NEC_CKSC_120  CKSC_120
#define NEC_CKSC_121  CKSC_121
#define NEC_CKSC_122  CKSC_122
#define NEC_CKSC_124  CKSC_124
#define NEC_CKSC_125  CKSC_125
#define NEC_CKSC_128  CKSC_128
#define NEC_CKSC_133  CKSC_133
#define NEC_CKSC_134  CKSC_134
#define NEC_CKSC_135  CKSC_135

#define NEC_CKSC_A00  CKSC_A00
#define NEC_CKSC_A01  CKSC_A01
#define NEC_CKSC_A02  CKSC_A02
#define NEC_CKSC_A03  CKSC_A03
#define NEC_CKSC_A04  CKSC_A04
#define NEC_CKSC_A05  CKSC_A05
#define NEC_CKSC_A06  CKSC_A06
#define NEC_CKSC_A07  CKSC_A07
#define NEC_CKSC_A09  CKSC_A09


#define NEC_PROTCMD0     PROTCMD0     
#define NEC_PROTCMD1     PROTCMD1    

#define NEC_MOSCE        MOSCE        
#define NEC_MOSCC        MOSCC        
#define NEC_MOSCST       MOSCST       
#define NEC_MOSCS        MOSCS

#define NEC_SOSCE        SOSCE        
#define NEC_SOSCC        SOSCC        
#define NEC_SOSCST       SOSCST       
#define NEC_SOSCS        SOSCS  
   
#define NEC_PROTS0       PROTS0
#define NEC_PROTS1       PROTS1   

#define NEC_ROSCE        ROSCE
#define NEC_ROSCS        ROSCS
#define NEC_PLLE0        PLLE0        
#define NEC_PLLST0       PLLST0       
#define NEC_PLLC0        PLLC0        
#define NEC_PLLE1        PLLE1        
#define NEC_PLLST1       PLLST1       
#define NEC_PLLC1        PLLC1        
#define NEC_PLLE2        PLLE2        
#define NEC_PLLST2       PLLST2       
#define NEC_PLLC2        PLLC2        
#define NEC_PLLS0        PLLS0        
#define NEC_PLLS1        PLLS1        
#define NEC_PLLS2        PLLS2        
#define NEC_SWRESA       SWRESA       
#define NEC_WUFL0        WUFL0        
#define NEC_WUFM0        WUFM0        
#define NEC_WUFH0        WUFH0        
#define NEC_WUFL1        WUFL1        
#define NEC_WUFM1        WUFM1        
#define NEC_WUFH1        WUFH1        
#define NEC_WUFCL0       WUFCL0       
#define NEC_WUFCM0       WUFCM0       
#define NEC_WUFCH0       WUFCH0       
#define NEC_WUFCL1       WUFCL1       
#define NEC_WUFCM1       WUFCM1       
#define NEC_WUFCH1       WUFCH1       
#define NEC_OSCWUFMSK    OSCWUFMSK

#define NEC_WUFMSKL0     WUFMSKL0
#define NEC_WUFMSKM0     WUFMSKM0
#define NEC_WUFMSKH0     WUFMSKH0
#define NEC_WUFMSKL1     WUFMSKL1
#define NEC_WUFMSKM1     WUFMSKM1
#define NEC_WUFMSKH1     WUFMSKH1
#define NEC_CLMA0CMPH   CLMA0CMPH
#define NEC_CLMA0CMPL   CLMA0CMPL
#define NEC_CLMA0CTL0   CLMA0CTL0
#define NEC_CLMA0PCMD   CLMA0PCMD
#define NEC_CLMA0PS     CLMA0PS  
#define NEC_CLMA2CMPH   CLMA2CMPH
#define NEC_CLMA2CMPL   CLMA2CMPL
#define NEC_CLMA2CTL0   CLMA2CTL0
#define NEC_CLMA2PCMD   CLMA2PCMD
#define NEC_CLMA2PS     CLMA2PS  
#define NEC_CLMA3CMPH   CLMA3CMPH
#define NEC_CLMA3CMPL   CLMA3CMPL
#define NEC_CLMA3CTL0   CLMA3CTL0
#define NEC_CLMA3PCMD   CLMA3PCMD
#define NEC_CLMA3PS     CLMA3PS  
#define NEC_LVICNT      LVICNT   
#define NEC_RESF        RESF

#define NEC_RESFC       RESFC

#define NEC_BURC        BURC
#define NEC_BURAE       BURAE
#define NEC_BURAEC      BURAEC

#define NEC_FOUTDIV     FOUTDIV
#define NEC_FOUTSTAT    FOUTSTAT
#define NEC_VCPC0CTL0   VCPC0CTL0
#define NEC_VCPC0CTL1   VCPC0CTL1


/*******************************************************************************
**                 Macros for FR Driver                                     **
*******************************************************************************/
#define NEC_FLX0CI          FLX0CI


/*******************************************************************************
**                 Macros for CAN Driver                                  **
*******************************************************************************/
/* Address of the CAN Interrupt  Controller 0 Register */
#define NEC_ICFCN0ERR           ICFCN0ERR   

/* Address of the CAN Interrupt  Controller 1 Register */
#define NEC_ICFCN1ERR           ICFCN1ERR 

/* Address of the CAN Interrupt  Controller 2 Register */
#define NEC_ICFCN2ERR           ICFCN2ERR

/* Address of the CAN Interrupt  Controller 3 Register */
#define NEC_ICFCN3ERR           ICFCN3ERR

/* Address of the CAN Controller 0 Register - 8 bit */
#define NEC_FCN0GMCSPRE         FCN0GMCSPRE  

/* Address of the CAN Controller 0 Register - 16 bit */
#define NEC_FCN0GMCLCTL         FCN0GMCLCTL

/* Address of the CAN Controller 0 Register - 32 bit */
#define NEC_FCN0DNBMRX0         FCN0DNBMRX0    

/* Address of the CAN Controller 1 Register - 8 bit */
#define NEC_FCN1GMCSPRE         FCN1GMCSPRE  

/* Address of the CAN Controller 1 Register - 16 bit */
#define NEC_FCN1GMCLCTL         FCN1GMCLCTL

/* Address of the CAN Controller 1 Register - 32 bit */
#define NEC_FCN1DNBMRX0         FCN1DNBMRX0

/* Address of the CAN Controller 2 Register - 8 bit */
#define NEC_FCN2GMCSPRE         FCN2GMCSPRE  

/* Address of the CAN Controller 2 Register - 16 bit */
#define NEC_FCN2GMCLCTL         FCN2GMCLCTL

/* Address of the CAN Controller 2 Register - 32 bit */
#define NEC_FCN2DNBMRX0         FCN2DNBMRX0

/* Address of the CAN Controller 3 Register - 8 bit */
#define NEC_FCN3GMCSPRE         FCN3GMCSPRE  

/* Address of the CAN Controller 3 Register - 16 bit */
#define NEC_FCN3GMCLCTL         FCN3GMCLCTL

/* Address of the CAN Controller 3 Register - 32 bit */
#define NEC_FCN3DNBMRX0         FCN3DNBMRX0

/* Address of the CAN Controller 0 Wakeup Register */
#define NEC_ICFCN0WUP            ICFCNWUP

/* Address of the CAN Controller 1 Wakeup Register */
#define NEC_ICFCN1WUP            ICFCNWUP

/* Address of the CAN Controller 2 Wakeup Register */
#define NEC_ICFCN2WUP            ICFCNWUP

/* Address of the CAN Controller 3 Wakeup Register */
#define NEC_ICFCN3WUP            ICFCNWUP

/* Related to Message Buffers*/

/*  Addresses for  CAN Controller Hardware 1 Message Buffers*/

/* Address of the CAN Controller Hardware 0 Message Buffer 0 - 8 bit */
#define NEC_FCN0M0DAT0B         FCN0M000DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 0 - 16 bit */
#define NEC_FCN0M0DAT0H         FCN0M000DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 0 - 32 bit */
#define NEC_FCN0M0DAT0W         FCN0M000DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 1 - 8 bit */
#define NEC_FCN0M1DAT0B         FCN0M001DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 1 - 16 bit */
#define NEC_FCN0M1DAT0H         FCN0M001DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 1 - 32 bit */
#define NEC_FCN0M1DAT0W         FCN0M001DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 2 - 8 bit */
#define NEC_FCN0M2DAT0B         FCN0M002DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 2 - 16 bit */
#define NEC_FCN0M2DAT0H         FCN0M002DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 2 - 32 bit */
#define NEC_FCN0M2DAT0W         FCN0M002DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 3 - 8 bit */
#define NEC_FCN0M3DAT0B         FCN0M003DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 3 - 16 bit */
#define NEC_FCN0M3DAT0H         FCN0M003DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 3 - 32 bit */
#define NEC_FCN0M3DAT0W         FCN0M003DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 4 - 8 bit */
#define NEC_FCN0M4DAT0B         FCN0M004DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 4 - 16 bit */
#define NEC_FCN0M4DAT0H         FCN0M004DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 4 - 32 bit */
#define NEC_FCN0M4DAT0W         FCN0M004DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 5 - 8 bit */
#define NEC_FCN0M5DAT0B         FCN0M005DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 5 - 16 bit */
#define NEC_FCN0M5DAT0H         FCN0M005DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 5 - 32 bit */
#define NEC_FCN0M5DAT0W         FCN0M005DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 6 - 8 bit */
#define NEC_FCN0M6DAT0B         FCN0M006DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 6 - 16 bit */
#define NEC_FCN0M6DAT0H         FCN0M006DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 6 - 32 bit */
#define NEC_FCN0M6DAT0W         FCN0M006DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 7 - 8 bit */
#define NEC_FCN0M7DAT0B         FCN0M007DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 7 - 16 bit */
#define NEC_FCN0M7DAT0H         FCN0M007DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer7 - 32 bit */
#define NEC_FCN0M7DAT0W         FCN0M007DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 8 - 8 bit */
#define NEC_FCN0M8DAT0B         FCN0M008DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 8 - 16 bit */
#define NEC_FCN0M8DAT0H         FCN0M008DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 8 - 32 bit */
#define NEC_FCN0M8DAT0W         FCN0M008DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 9 - 8 bit */
#define NEC_FCN0M9DAT0B         FCN0M009DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 9 - 16 bit */
#define NEC_FCN0M9DAT0H         FCN0M009DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 9 - 32 bit */
#define NEC_FCN0M9DAT0W         FCN0M009DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 10 - 8 bit */
#define NEC_FCN0M10DAT0B         FCN0M010DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 10 - 16 bit */
#define NEC_FCN0M10DAT0H         FCN0M010DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 10 - 32 bit */
#define NEC_FCN0M10DAT0W         FCN0M010DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 11 - 8 bit */
#define NEC_FCN0M11DAT0B         FCN0M011DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 10 - 16 bit */
#define NEC_FCN0M11DAT0H         FCN0M011DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 10 - 32 bit */
#define NEC_FCN0M11DAT0W         FCN0M011DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 2 - 8 bit */
#define NEC_FCN0M12DAT0B         FCN0M012DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 12 - 16 bit */
#define NEC_FCN0M12DAT0H         FCN0M012DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 12 - 32 bit */
#define NEC_FCN0M12DAT0W         FCN0M012DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 13 - 8 bit */
#define NEC_FCN0M13DAT0B         FCN0M013DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 13 - 16 bit */
#define NEC_FCN0M13DAT0H         FCN0M013DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 13 - 32 bit */
#define NEC_FCN0M13DAT0W         FCN0M013DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 14 - 8 bit */
#define NEC_FCN0M14DAT0B         FCN0M014DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 14 - 16 bit */
#define NEC_FCN0M14DAT0H         FCN0M014DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 14 - 32 bit */
#define NEC_FCN0M14DAT0W         FCN0M014DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 15 - 8 bit */
#define NEC_FCN0M15DAT0B         FCN0M015DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 15 - 16 bit */
#define NEC_FCN0M15DAT0H         FCN0M015DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 10 - 32 bit */
#define NEC_FCN0M15DAT0W         FCN0M015DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 16 - 8 bit */
#define NEC_FCN0M16DAT0B         FCN0M016DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 16 - 16 bit */
#define NEC_FCN0M16DAT0H         FCN0M016DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 16 - 32 bit */
#define NEC_FCN0M16DAT0W         FCN0M016DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 17 - 8 bit */
#define NEC_FCN0M17DAT0B         FCN0M017DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 17 - 16 bit */
#define NEC_FCN0M17DAT0H         FCN0M017DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 17 - 32 bit */
#define NEC_FCN0M17DAT0W         FCN0M017DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 18 - 8 bit */
#define NEC_FCN0M18DAT0B         FCN0M018DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 18 - 16 bit */
#define NEC_FCN0M18DAT0H         FCN0M018DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 18 - 32 bit */
#define NEC_FCN0M18DAT0W         FCN0M018DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 19 - 8 bit */
#define NEC_FCN0M19DAT0B         FCN0M019DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 19 - 16 bit */
#define NEC_FCN0M19DAT0H         FCN0M019DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 19 - 32 bit */
#define NEC_FCN0M19DAT0W         FCN0M019DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 20 - 8 bit */
#define NEC_FCN0M20DAT0B         FCN0M020DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 20 - 16 bit */
#define NEC_FCN0M20DAT0H         FCN0M020DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 20 - 32 bit */
#define NEC_FCN0M20DAT0W         FCN0M020DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 21 - 8 bit */
#define NEC_FCN0M21DAT0B         FCN0M021DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 21 - 16 bit */
#define NEC_FCN0M21DAT0H         FCN0M021DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 21 - 32 bit */
#define NEC_FCN0M21DAT0W         FCN0M021DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 22 - 8 bit */
#define NEC_FCN0M22DAT0B         FCN0M022DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 22 - 16 bit */
#define NEC_FCN0M22DAT0H         FCN0M022DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 22 - 32 bit */
#define NEC_FCN0M22DAT0W         FCN0M022DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 23 - 8 bit */
#define NEC_FCN0M23DAT0B         FCN0M023DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 23 - 16 bit */
#define NEC_FCN0M23DAT0H         FCN0M023DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 23 - 32 bit */
#define NEC_FCN0M23DAT0W         FCN0M023DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 24 - 8 bit */
#define NEC_FCN0M24DAT0B         FCN0M024DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 24 - 16 bit */
#define NEC_FCN0M24DAT0H         FCN0M024DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 24 - 32 bit */
#define NEC_FCN0M24DAT0W         FCN0M024DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 25 - 8 bit */
#define NEC_FCN0M25DAT0B         FCN0M025DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 25 - 16 bit */
#define NEC_FCN0M25DAT0H         FCN0M025DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 25 - 32 bit */
#define NEC_FCN0M25DAT0W         FCN0M025DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 26 - 8 bit */
#define NEC_FCN0M26DAT0B         FCN0M026DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 26 - 16 bit */
#define NEC_FCN0M26DAT0H         FCN0M026DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 26 - 32 bit */
#define NEC_FCN0M26DAT0W         FCN0M026DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 27 - 8 bit */
#define NEC_FCN0M27DAT0B         FCN0M027DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 27 - 16 bit */
#define NEC_FCN0M27DAT0H         FCN0M027DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 27 - 32 bit */
#define NEC_FCN0M27DAT0W         FCN0M027DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 28 - 8 bit */
#define NEC_FCN0M28DAT0B         FCN0M028DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 28 - 16 bit */
#define NEC_FCN0M28DAT0H         FCN0M028DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 28 - 32 bit */
#define NEC_FCN0M28DAT0W         FCN0M028DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 29 - 8 bit */
#define NEC_FCN0M29DAT0B         FCN0M029DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 29 - 16 bit */
#define NEC_FCN0M29DAT0H         FCN0M029DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 29 - 32 bit */
#define NEC_FCN0M29DAT0W         FCN0M029DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 30 - 8 bit */
#define NEC_FCN0M30DAT0B         FCN0M030DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 30 - 16 bit */
#define NEC_FCN0M30DAT0H         FCN0M030DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 30 - 32 bit */
#define NEC_FCN0M30DAT0W         FCN0M030DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 31 - 8 bit */
#define NEC_FCN0M31DAT0B         FCN0M031DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 31 - 16 bit */
#define NEC_FCN0M31DAT0H         FCN0M031DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 31 - 32 bit */
#define NEC_FCN0M31DAT0W         FCN0M031DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 32 - 8 bit */
#define NEC_FCN0M32DAT0B         FCN0M032DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 32 - 16 bit */
#define NEC_FCN0M32DAT0H         FCN0M032DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 32 - 32 bit */
#define NEC_FCN0M32DAT0W         FCN0M032DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 33 - 8 bit */
#define NEC_FCN0M33DAT0B         FCN0M033DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 33 - 16 bit */
#define NEC_FCN0M33DAT0H         FCN0M033DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 33 - 32 bit */
#define NEC_FCN0M33DAT0W         FCN0M033DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 34 - 8 bit */
#define NEC_FCN0M34DAT0B         FCN0M034DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 34 - 16 bit */
#define NEC_FCN0M34DAT0H         FCN0M034DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 34 - 32 bit */
#define NEC_FCN0M34DAT0W         FCN0M034DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 35 - 8 bit */
#define NEC_FCN0M35DAT0B         FCN0M035DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 35 - 16 bit */
#define NEC_FCN0M35DAT0H         FCN0M035DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 35 - 32 bit */
#define NEC_FCN0M35DAT0W         FCN0M035DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 36 - 8 bit */
#define NEC_FCN0M36DAT0B         FCN0M036DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 36 - 16 bit */
#define NEC_FCN0M36DAT0H         FCN0M036DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 36 - 32 bit */
#define NEC_FCN0M36DAT0W         FCN0M036DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 37 - 8 bit */
#define NEC_FCN0M37DAT0B         FCN0M037DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 37 - 16 bit */
#define NEC_FCN0M37DAT0H         FCN0M037DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 37 - 32 bit */
#define NEC_FCN0M37DAT0W         FCN0M037DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 38 - 8 bit */
#define NEC_FCN0M38DAT0B         FCN0M038DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 38 - 16 bit */
#define NEC_FCN0M38DAT0H         FCN0M038DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 38 - 32 bit */
#define NEC_FCN0M38DAT0W         FCN0M038DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 39 - 8 bit */
#define NEC_FCN0M39DAT0B         FCN0M039DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 39 - 16 bit */
#define NEC_FCN0M39DAT0H         FCN0M039DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 39 - 32 bit */
#define NEC_FCN0M39DAT0W         FCN0M039DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 40 - 8 bit */
#define NEC_FCN0M40DAT0B         FCN0M040DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 40 - 16 bit */
#define NEC_FCN0M40DAT0H         FCN0M040DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 40 - 32 bit */
#define NEC_FCN0M40DAT0W         FCN0M040DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 41 - 8 bit */
#define NEC_FCN0M41DAT0B         FCN0M041DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 41 - 16 bit */
#define NEC_FCN0M41DAT0H         FCN0M041DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 41 - 32 bit */
#define NEC_FCN0M41DAT0W         FCN0M041DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 42 - 8 bit */
#define NEC_FCN0M42DAT0B         FCN0M042DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 42 - 16 bit */
#define NEC_FCN0M42DAT0H         FCN0M042DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 42 - 32 bit */
#define NEC_FCN0M42DAT0W         FCN0M042DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 43 - 8 bit */
#define NEC_FCN0M43DAT0B         FCN0M043DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 43 - 16 bit */
#define NEC_FCN0M43DAT0H         FCN0M043DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 43 - 32 bit */
#define NEC_FCN0M43DAT0W         FCN0M043DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 44 - 8 bit */
#define NEC_FCN0M44DAT0B         FCN0M044DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 44 - 16 bit */
#define NEC_FCN0M44DAT0H         FCN0M044DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 44 - 32 bit */
#define NEC_FCN0M44DAT0W         FCN0M044DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 45 - 8 bit */
#define NEC_FCN0M45DAT0B         FCN0M045DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 45 - 16 bit */
#define NEC_FCN0M45DAT0H         FCN0M045DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 45 - 32 bit */
#define NEC_FCN0M45DAT0W         FCN0M045DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 46 - 8 bit */
#define NEC_FCN0M46DAT0B         FCN0M046DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 46 - 16 bit */
#define NEC_FCN0M46DAT0H         FCN0M046DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 46 - 32 bit */
#define NEC_FCN0M46DAT0W         FCN0M046DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 47 - 8 bit */
#define NEC_FCN0M47DAT0B         FCN0M047DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 47 - 16 bit */
#define NEC_FCN0M47DAT0H         FCN0M047DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 47 - 32 bit */
#define NEC_FCN0M47DAT0W         FCN0M047DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 48 - 8 bit */
#define NEC_FCN0M48DAT0B         FCN0M048DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 48 - 16 bit */
#define NEC_FCN0M48DAT0H         FCN0M048DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 48 - 32 bit */
#define NEC_FCN0M48DAT0W         FCN0M048DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 49 - 8 bit */
#define NEC_FCN0M49DAT0B         FCN0M049DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 49 - 16 bit */
#define NEC_FCN0M49DAT0H         FCN0M049DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 49 - 32 bit */
#define NEC_FCN0M49DAT0W         FCN0M049DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 50 - 8 bit */
#define NEC_FCN0M50DAT0B         FCN0M050DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 50 - 16 bit */
#define NEC_FCN0M50DAT0H         FCN0M050DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 50 - 32 bit */
#define NEC_FCN0M50DAT0W         FCN0M050DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 51 - 8 bit */
#define NEC_FCN0M51DAT0B         FCN0M051DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 51 - 16 bit */
#define NEC_FCN0M51DAT0H         FCN0M051DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 50 - 32 bit */
#define NEC_FCN0M51DAT0W         FCN0M050DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 52 - 8 bit */
#define NEC_FCN0M52DAT0B         FCN0M052DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 52 - 16 bit */
#define NEC_FCN0M52DAT0H         FCN0M052DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 52 - 32 bit */
#define NEC_FCN0M52DAT0W         FCN0M052DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 53 - 8 bit */
#define NEC_FCN0M53DAT0B         FCN0M053DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 53 - 16 bit */
#define NEC_FCN0M53DAT0H         FCN0M053DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 53 - 32 bit */
#define NEC_FCN0M53DAT0W         FCN0M053DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 54 - 8 bit */
#define NEC_FCN0M54DAT0B         FCN0M054DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 54 - 16 bit */
#define NEC_FCN0M54DAT0H         FCN0M054DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 54 - 32 bit */
#define NEC_FCN0M54DAT0W         FCN0M054DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 55 - 8 bit */
#define NEC_FCN0M55DAT0B         FCN0M055DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 55 - 16 bit */
#define NEC_FCN0M55DAT0H         FCN0M055DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 55 - 32 bit */
#define NEC_FCN0M55DAT0W         FCN0M055DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 56 - 8 bit */
#define NEC_FCN0M56DAT0B         FCN0M056DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 56 - 16 bit */
#define NEC_FCN0M56DAT0H         FCN0M056DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 56 - 32 bit */
#define NEC_FCN0M56DAT0W         FCN0M056DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 57 - 8 bit */
#define NEC_FCN0M57DAT0B         FCN0M057DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 57 - 16 bit */
#define NEC_FCN0M57DAT0H         FCN0M057DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 57 - 32 bit */
#define NEC_FCN0M57DAT0W         FCN0M057DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 58 - 8 bit */
#define NEC_FCN0M58DAT0B         FCN0M058DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 58 - 16 bit */
#define NEC_FCN0M58DAT0H         FCN0M058DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 58 - 32 bit */
#define NEC_FCN0M58DAT0W         FCN0M058DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 59 - 8 bit */
#define NEC_FCN0M59DAT0B         FCN0M059DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 59 - 16 bit */
#define NEC_FCN0M59DAT0H         FCN0M059DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 59 - 32 bit */
#define NEC_FCN0M59DAT0W         FCN0M059DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 60 - 8 bit */
#define NEC_FCN0M60DAT0B         FCN0M060DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 60 - 16 bit */
#define NEC_FCN0M60DAT0H         FCN0M060DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 60 - 32 bit */
#define NEC_FCN0M60DAT0W         FCN0M060DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 61 - 8 bit */
#define NEC_FCN0M61DAT0B         FCN0M061DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 61 - 16 bit */
#define NEC_FCN0M61DAT0H         FCN0M061DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 61 - 32 bit */
#define NEC_FCN0M61DAT0W         FCN0M061DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 62- 8 bit */
#define NEC_FCN0M62DAT0B         FCN0M062DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 62 - 16 bit */
#define NEC_FCN0M62DAT0H         FCN0M062DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 62 - 32 bit */
#define NEC_FCN0M62DAT0W         FCN0M062DAT0W


/* Address of the CAN Controller Hardware 0 Message Buffer 63 - 8 bit */
#define NEC_FCN0M63DAT0B         FCN0M063DAT0B

/* Address of the CAN Controller Hardware 0 Message Buffer 63 - 16 bit */
#define NEC_FCN0M63DAT0H         FCN0M063DAT0H

/* Address of the CAN Controller Hardware 0 Message Buffer 63 - 32 bit */
#define NEC_FCN0M63DAT0W        FCN0M063DAT0W

/*  Addresses for  CAN Controller Hardware 1 Message Buffers */

/* Address of the CAN Controller Hardware 1 Message Buffer 0 - 8 bit */
#define NEC_FCN1M0DAT0B         FCN1M000DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 0 - 16 bit */
#define NEC_FCN1M0DAT0H         FCN1M000DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 0 - 32 bit */
#define NEC_FCN1M0DAT0W         FCN1M000DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 1 - 8 bit */
#define NEC_FCN1M1DAT0B         FCN1M001DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 1 - 16 bit */
#define NEC_FCN1M1DAT0H         FCN1M001DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 1 - 32 bit */
#define NEC_FCN1M1DAT0W         FCN1M001DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 2 - 8 bit */
#define NEC_FCN1M2DAT0B         FCN1M002DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 2 - 16 bit */
#define NEC_FCN1M2DAT0H         FCN1M002DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 2 - 32 bit */
#define NEC_FCN1M2DAT0W         FCN1M002DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 3 - 8 bit */
#define NEC_FCN1M3DAT0B         FCN1M003DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 3 - 16 bit */
#define NEC_FCN1M3DAT0H         FCN1M003DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 3 - 32 bit */
#define NEC_FCN1M3DAT0W         FCN1M003DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 4 - 8 bit */
#define NEC_FCN1M4DAT0B         FCN1M004DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 4 - 16 bit */
#define NEC_FCN1M4DAT0H         FCN1M004DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 4 - 32 bit */
#define NEC_FCN1M4DAT0W         FCN1M004DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 5 - 8 bit */
#define NEC_FCN1M5DAT0B         FCN1M005DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 5 - 16 bit */
#define NEC_FCN1M5DAT0H         FCN1M005DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 5 - 32 bit */
#define NEC_FCN1M5DAT0W         FCN1M005DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 6 - 8 bit */
#define NEC_FCN1M6DAT0B         FCN1M006DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 6 - 16 bit */
#define NEC_FCN1M6DAT0H         FCN1M006DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 6 - 32 bit */
#define NEC_FCN1M6DAT0W         FCN1M006DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 7 - 8 bit */
#define NEC_FCN1M7DAT0B         FCN1M007DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 7 - 16 bit */
#define NEC_FCN1M7DAT0H         FCN1M007DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer7 - 32 bit */
#define NEC_FCN1M7DAT0W         FCN1M007DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 8 - 8 bit */
#define NEC_FCN1M8DAT0B         FCN1M008DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 8 - 16 bit */
#define NEC_FCN1M8DAT0H         FCN1M008DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 8 - 32 bit */
#define NEC_FCN1M8DAT0W         FCN1M008DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 9 - 8 bit */
#define NEC_FCN1M9DAT0B         FCN1M009DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 9 - 16 bit */
#define NEC_FCN1M9DAT0H         FCN1M009DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 9 - 32 bit */
#define NEC_FCN1M9DAT0W         FCN1M009DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 10 - 8 bit */
#define NEC_FCN1M10DAT0B         FCN1M010DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 10 - 16 bit */
#define NEC_FCN1M10DAT0H         FCN1M010DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 10 - 32 bit */
#define NEC_FCN1M10DAT0W         FCN1M010DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 11 - 8 bit */
#define NEC_FCN1M11DAT0B         FCN1M011DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 10 - 16 bit */
#define NEC_FCN1M11DAT0H         FCN1M011DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 10 - 32 bit */
#define NEC_FCN1M11DAT0W         FCN1M011DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 2 - 8 bit */
#define NEC_FCN1M12DAT0B         FCN1M012DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 12 - 16 bit */
#define NEC_FCN1M12DAT0H         FCN1M012DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 12 - 32 bit */
#define NEC_FCN1M12DAT0W         FCN1M012DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 13 - 8 bit */
#define NEC_FCN1M13DAT0B         FCN1M013DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 13 - 16 bit */
#define NEC_FCN1M13DAT0H         FCN1M013DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 13 - 32 bit */
#define NEC_FCN1M13DAT0W         FCN1M013DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 14 - 8 bit */
#define NEC_FCN1M14DAT0B         FCN1M014DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 14 - 16 bit */
#define NEC_FCN1M14DAT0H         FCN1M014DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 14 - 32 bit */
#define NEC_FCN1M14DAT0W         FCN1M014DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 15 - 8 bit */
#define NEC_FCN1M15DAT0B         FCN1M015DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 15 - 16 bit */
#define NEC_FCN1M15DAT0H         FCN1M015DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 10 - 32 bit */
#define NEC_FCN1M15DAT0W         FCN1M015DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 16 - 8 bit */
#define NEC_FCN1M16DAT0B         FCN1M016DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 16 - 16 bit */
#define NEC_FCN1M16DAT0H         FCN1M016DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 16 - 32 bit */
#define NEC_FCN1M16DAT0W         FCN1M016DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 17 - 8 bit */
#define NEC_FCN1M17DAT0B         FCN1M017DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 17 - 16 bit */
#define NEC_FCN1M17DAT0H         FCN1M017DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 17 - 32 bit */
#define NEC_FCN1M17DAT0W         FCN1M017DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 18 - 8 bit */
#define NEC_FCN1M18DAT0B         FCN1M018DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 18 - 16 bit */
#define NEC_FCN1M18DAT0H         FCN1M018DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 18 - 32 bit */
#define NEC_FCN1M18DAT0W         FCN1M018DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 19 - 8 bit */
#define NEC_FCN1M19DAT0B         FCN1M019DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 19 - 16 bit */
#define NEC_FCN1M19DAT0H         FCN1M019DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 19 - 32 bit */
#define NEC_FCN1M19DAT0W         FCN1M019DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 20 - 8 bit */
#define NEC_FCN1M20DAT0B         FCN1M020DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 20 - 16 bit */
#define NEC_FCN1M20DAT0H         FCN1M020DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 20 - 32 bit */
#define NEC_FCN1M20DAT0W         FCN1M020DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 21 - 8 bit */
#define NEC_FCN1M21DAT0B         FCN1M021DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 21 - 16 bit */
#define NEC_FCN1M21DAT0H         FCN1M021DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 21 - 32 bit */
#define NEC_FCN1M21DAT0W         FCN1M021DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 22 - 8 bit */
#define NEC_FCN1M22DAT0B         FCN1M022DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 22 - 16 bit */
#define NEC_FCN1M22DAT0H         FCN1M022DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 22 - 32 bit */
#define NEC_FCN1M22DAT0W         FCN1M022DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 23 - 8 bit */
#define NEC_FCN1M23DAT0B         FCN1M023DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 23 - 16 bit */
#define NEC_FCN1M23DAT0H         FCN1M023DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 23 - 32 bit */
#define NEC_FCN1M23DAT0W         FCN1M023DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 24 - 8 bit */
#define NEC_FCN1M24DAT0B         FCN1M024DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 24 - 16 bit */
#define NEC_FCN1M24DAT0H         FCN1M024DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 24 - 32 bit */
#define NEC_FCN1M24DAT0W         FCN1M024DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 25 - 8 bit */
#define NEC_FCN1M25DAT0B         FCN1M025DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 25 - 16 bit */
#define NEC_FCN1M25DAT0H         FCN1M025DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 25 - 32 bit */
#define NEC_FCN1M25DAT0W         FCN1M025DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 26 - 8 bit */
#define NEC_FCN1M26DAT0B         FCN1M026DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 26 - 16 bit */
#define NEC_FCN1M26DAT0H         FCN1M026DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 26 - 32 bit */
#define NEC_FCN1M26DAT0W         FCN1M026DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 27 - 8 bit */
#define NEC_FCN1M27DAT0B         FCN1M027DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 27 - 16 bit */
#define NEC_FCN1M27DAT0H         FCN1M027DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 27 - 32 bit */
#define NEC_FCN1M27DAT0W         FCN1M027DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 28 - 8 bit */
#define NEC_FCN1M28DAT0B         FCN1M020DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 28 - 16 bit */
#define NEC_FCN1M28DAT0H         FCN1M028DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 28 - 32 bit */
#define NEC_FCN1M28DAT0W         FCN1M028DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 29 - 8 bit */
#define NEC_FCN1M29DAT0B         FCN1M029DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 29 - 16 bit */
#define NEC_FCN1M29DAT0H         FCN1M029DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 29 - 32 bit */
#define NEC_FCN1M29DAT0W         FCN1M029DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 30 - 8 bit */
#define NEC_FCN1M30DAT0B         FCN1M030DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 30 - 16 bit */
#define NEC_FCN1M30DAT0H         FCN1M030DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 30 - 32 bit */
#define NEC_FCN1M30DAT0W         FCN1M030DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 31 - 8 bit */
#define NEC_FCN1M31DAT0B         FCN1M031DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 31 - 16 bit */
#define NEC_FCN1M31DAT0H         FCN1M031DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 31 - 32 bit */
#define NEC_FCN1M31DAT0W         FCN1M031DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 32 - 8 bit */
#define NEC_FCN1M32DAT0B         FCN1M032DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 32 - 16 bit */
#define NEC_FCN1M32DAT0H         FCN1M032DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 32 - 32 bit */
#define NEC_FCN1M32DAT0W         FCN1M032DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 33 - 8 bit */
#define NEC_FCN1M33DAT0B         FCN1M033DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 33 - 16 bit */
#define NEC_FCN1M33DAT0H         FCN1M033DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 33 - 32 bit */
#define NEC_FCN1M33DAT0W         FCN1M033DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 34 - 8 bit */
#define NEC_FCN1M34DAT0B         FCN1M034DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 34 - 16 bit */
#define NEC_FCN1M34DAT0H         FCN1M034DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 34 - 32 bit */
#define NEC_FCN1M34DAT0W         FCN1M034DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 35 - 8 bit */
#define NEC_FCN1M35DAT0B         FCN1M035DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 35 - 16 bit */
#define NEC_FCN1M35DAT0H         FCN1M035DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 35 - 32 bit */
#define NEC_FCN1M35DAT0W         FCN1M035DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 36 - 8 bit */
#define NEC_FCN1M36DAT0B         FCN1M036DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 36 - 16 bit */
#define NEC_FCN1M36DAT0H         FCN1M036DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 36 - 32 bit */
#define NEC_FCN1M36DAT0W         FCN1M036DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 37 - 8 bit */
#define NEC_FCN1M37DAT0B         FCN1M037DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 37 - 16 bit */
#define NEC_FCN1M37DAT0H         FCN1M037DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 37 - 32 bit */
#define NEC_FCN1M37DAT0W         FCN1M037DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 38 - 8 bit */
#define NEC_FCN1M38DAT0B         FCN1M038DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 38 - 16 bit */
#define NEC_FCN1M38DAT0H         FCN1M038DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 38 - 32 bit */
#define NEC_FCN1M38DAT0W         FCN1M038DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 39 - 8 bit */
#define NEC_FCN1M39DAT0B         FCN1M039DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 39 - 16 bit */
#define NEC_FCN1M39DAT0H         FCN1M039DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 39 - 32 bit */
#define NEC_FCN1M39DAT0W         FCN1M039DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 40 - 8 bit */
#define NEC_FCN1M40DAT0B         FCN1M040DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 40 - 16 bit */
#define NEC_FCN1M40DAT0H         FCN1M040DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 40 - 32 bit */
#define NEC_FCN1M40DAT0W         FCN1M040DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 41 - 8 bit */
#define NEC_FCN1M41DAT0B         FCN1M041DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 41 - 16 bit */
#define NEC_FCN1M41DAT0H         FCN1M041DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 41 - 32 bit */
#define NEC_FCN1M41DAT0W         FCN1M041DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 42 - 8 bit */
#define NEC_FCN1M42DAT0B         FCN1M042DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 42 - 16 bit */
#define NEC_FCN1M42DAT0H         FCN1M042DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 42 - 32 bit */
#define NEC_FCN1M42DAT0W         FCN1M042DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 43 - 8 bit */
#define NEC_FCN1M43DAT0B         FCN1M043DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 43 - 16 bit */
#define NEC_FCN1M43DAT0H         FCN1M043DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 43 - 32 bit */
#define NEC_FCN1M43DAT0W         FCN1M043DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 44 - 8 bit */
#define NEC_FCN1M44DAT0B         FCN1M044DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 44 - 16 bit */
#define NEC_FCN1M44DAT0H         FCN1M044DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 44 - 32 bit */
#define NEC_FCN1M44DAT0W         FCN1M044DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 45 - 8 bit */
#define NEC_FCN1M45DAT0B         FCN1M045DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 45 - 16 bit */
#define NEC_FCN1M45DAT0H         FCN1M045DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 45 - 32 bit */
#define NEC_FCN1M45DAT0W         FCN1M045DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 46 - 8 bit */
#define NEC_FCN1M46DAT0B         FCN1M046DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 46 - 16 bit */
#define NEC_FCN1M46DAT0H         FCN1M046DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 46 - 32 bit */
#define NEC_FCN1M46DAT0W         FCN1M046DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 47 - 8 bit */
#define NEC_FCN1M47DAT0B         FCN1M047DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 47 - 16 bit */
#define NEC_FCN1M47DAT0H         FCN1M047DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 47 - 32 bit */
#define NEC_FCN1M47DAT0W         FCN1M047DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 48 - 8 bit */
#define NEC_FCN1M48DAT0B         FCN1M048DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 48 - 16 bit */
#define NEC_FCN1M48DAT0H         FCN1M048DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 48 - 32 bit */
#define NEC_FCN1M48DAT0W         FCN1M048DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 49 - 8 bit */
#define NEC_FCN1M49DAT0B         FCN1M049DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 49 - 16 bit */
#define NEC_FCN1M49DAT0H         FCN1M049DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 49 - 32 bit */
#define NEC_FCN1M49DAT0W         FCN1M049DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 50 - 8 bit */
#define NEC_FCN1M50DAT0B         FCN1M050DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 50 - 16 bit */
#define NEC_FCN1M50DAT0H         FCN1M050DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 50 - 32 bit */
#define NEC_FCN1M50DAT0W         FCN1M050DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 51 - 8 bit */
#define NEC_FCN1M51DAT0B         FCN1M051DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 51 - 16 bit */
#define NEC_FCN1M51DAT0H         FCN1M051DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 50 - 32 bit */
#define NEC_FCN1M51DAT0W         FCN1M051DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 52 - 8 bit */
#define NEC_FCN1M52DAT0B         FCN1M052DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 52 - 16 bit */
#define NEC_FCN1M52DAT0H         FCN1M052DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 52 - 32 bit */
#define NEC_FCN1M52DAT0W         FCN1M052DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 53 - 8 bit */
#define NEC_FCN1M53DAT0B         FCN1M053DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 53 - 16 bit */
#define NEC_FCN1M53DAT0H         FCN1M053DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 53 - 32 bit */
#define NEC_FCN1M53DAT0W         FCN1M053DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 54 - 8 bit */
#define NEC_FCN1M54DAT0B         FCN1M054DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 54 - 16 bit */
#define NEC_FCN1M54DAT0H         FCN1M054DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 54 - 32 bit */
#define NEC_FCN1M54DAT0W         FCN1M054DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 55 - 8 bit */
#define NEC_FCN1M55DAT0B         FCN1M055DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 55 - 16 bit */
#define NEC_FCN1M55DAT0H         FCN1M055DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 55 - 32 bit */
#define NEC_FCN1M55DAT0W         FCN1M055DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 56 - 8 bit */
#define NEC_FCN1M56DAT0B         FCN1M056DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 56 - 16 bit */
#define NEC_FCN1M56DAT0H         FCN1M056DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 56 - 32 bit */
#define NEC_FCN1M56DAT0W         FCN1M056DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 57 - 8 bit */
#define NEC_FCN1M57DAT0B         FCN1M057DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 57 - 16 bit */
#define NEC_FCN1M57DAT0H         FCN1M057DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 57 - 32 bit */
#define NEC_FCN1M57DAT0W         FCN1M057DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 58 - 8 bit */
#define NEC_FCN1M58DAT0B         FCN1M058DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 58 - 16 bit */
#define NEC_FCN1M58DAT0H         FCN1M058DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 58 - 32 bit */
#define NEC_FCN1M58DAT0W         FCN1M058DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 59 - 8 bit */
#define NEC_FCN1M59DAT0B         FCN1M059DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 59 - 16 bit */
#define NEC_FCN1M59DAT0H         FCN1M059DAT0H

/* Address of the CAN Controller Hardware1 Message Buffer 59 - 32 bit */
#define NEC_FCN1M59DAT0W         FCN1M059DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 60 - 8 bit */
#define NEC_FCN1M60DAT0B         FCN1M060DAT0B

/* Address of the CAN Controller Hardware 10 Message Buffer 60 - 16 bit */
#define NEC_FCN1M60DAT0H         FCN1M060DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 60 - 32 bit */
#define NEC_FCN1M60DAT0W         FCN1M060DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 61 - 8 bit */
#define NEC_FCN1M61DAT0B         FCN1M061DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 61 - 16 bit */
#define NEC_FCN1M61DAT0H         FCN1M061DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 61 - 32 bit */
#define NEC_FCN1M61DAT0W         FCN1M061DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 62- 8 bit */
#define NEC_FCN1M62DAT0B         FCN1M062DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 62 - 16 bit */
#define NEC_FCN1M62DAT0H         FCN1M062DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 62 - 32 bit */
#define NEC_FCN1M62DAT0W         FCN1M062DAT0W


/* Address of the CAN Controller Hardware 1 Message Buffer 63 - 8 bit */
#define NEC_FCN1M63DAT0B         FCN1M063DAT0B

/* Address of the CAN Controller Hardware 1 Message Buffer 63 - 16 bit */
#define NEC_FCN1M63DAT0H         FCN1M063DAT0H

/* Address of the CAN Controller Hardware 1 Message Buffer 63 - 32 bit */
#define NEC_FCN1M63DAT0W         FCN1M063DAT0W


/*  Addresses for  CAN Controller Hardware 2 Message Buffers*/

/* Address of the CAN Controller Hardware 2 Message Buffer 0 - 8 bit */
#define NEC_FCN2M0DAT0B         FCN2M000DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 0 - 16 bit */
#define NEC_FCN2M0DAT0H         FCN2M000DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 0 - 32 bit */
#define NEC_FCN2M0DAT0W         FCN2M000DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 1 - 8 bit */
#define NEC_FCN2M1DAT0B         FCN2M001DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 1 - 16 bit */
#define NEC_FCN2M1DAT0H         FCN2M001DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 1 - 32 bit */
#define NEC_FCN2M1DAT0W         FCN2M001DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 2 - 8 bit */
#define NEC_FCN2M2DAT0B         FCN2M002DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 2 - 16 bit */
#define NEC_FCN2M2DAT0H         FCN2M002DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 2 - 32 bit */
#define NEC_FCN2M2DAT0W         FCN2M002DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 3 - 8 bit */
#define NEC_FCN2M3DAT0B         FCN2M003DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 3 - 16 bit */
#define NEC_FCN2M3DAT0H         FCN2M003DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 3 - 32 bit */
#define NEC_FCN2M3DAT0W         FCN2M003DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 4 - 8 bit */
#define NEC_FCN2M4DAT0B         FCN2M004DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 4 - 16 bit */
#define NEC_FCN2M4DAT0H         FCN2M004DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 4 - 32 bit */
#define NEC_FCN2M4DAT0W         FCN2M004DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 5 - 8 bit */
#define NEC_FCN2M5DAT0B         FCN2M005DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 5 - 16 bit */
#define NEC_FCN2M5DAT0H         FCN2M005DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 5 - 32 bit */
#define NEC_FCN2M5DAT0W         FCN0M005DAT0W

/* Address of the CAN Controller Hardware 2 Message Buffer 6 - 8 bit */
#define NEC_FCN2M6DAT0B         FCN2M006DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 6 - 16 bit */
#define NEC_FCN2M6DAT0H         FCN2M006DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 6 - 32 bit */
#define NEC_FCN2M6DAT0W         FCN2M006DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 7 - 8 bit */
#define NEC_FCN2M7DAT0B         FCN2M007DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 7 - 16 bit */
#define NEC_FCN2M7DAT0H         FCN2M007DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer7 - 32 bit */
#define NEC_FCN2M7DAT0W         FCN2M007DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 8 - 8 bit */
#define NEC_FCN2M8DAT0B         FCN2M008DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 8 - 16 bit */
#define NEC_FCN2M8DAT0H         FCN2M008DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 8 - 32 bit */
#define NEC_FCN2M8DAT0W         FCN2M008DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 9 - 8 bit */
#define NEC_FCN2M9DAT0B         FCN2M009DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 9 - 16 bit */
#define NEC_FCN2M9DAT0H         FCN2M009DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 9 - 32 bit */
#define NEC_FCN2M9DAT0W         FCN2M009DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 10 - 8 bit */
#define NEC_FCN2M10DAT0B         FCN2M010DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 10 - 16 bit */
#define NEC_FCN2M10DAT0H         FCN2M010DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 10 - 32 bit */
#define NEC_FCN2M10DAT0W         FCN2M010DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 11 - 8 bit */
#define NEC_FCN2M11DAT0B         FCN2M011DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 10 - 16 bit */
#define NEC_FCN2M11DAT0H         FCN2M011DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 10 - 32 bit */
#define NEC_FCN2M11DAT0W         FCN2M011DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 2 - 8 bit */
#define NEC_FCN2M12DAT0B         FCN2M012DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 12 - 16 bit */
#define NEC_FCN2M12DAT0H         FCN2M012DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 12 - 32 bit */
#define NEC_FCN2M12DAT0W         FCN2M012DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 13 - 8 bit */
#define NEC_FCN2M13DAT0B         FCN2M013DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 13 - 16 bit */
#define NEC_FCN2M13DAT0H         FCN2M013DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 13 - 32 bit */
#define NEC_FCN2M13DAT0W         FCN2M013DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 14 - 8 bit */
#define NEC_FCN2M14DAT0B         FCN2M014DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 14 - 16 bit */
#define NEC_FCN2M14DAT0H         FCN2M014DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 14 - 32 bit */
#define NEC_FCN2M14DAT0W         FCN2M014DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 15 - 8 bit */
#define NEC_FCN2M15DAT0B         FCN2M015DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 15 - 16 bit */
#define NEC_FCN2M15DAT0H         FCN2M015DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 10 - 32 bit */
#define NEC_FCN2M15DAT0W         FCN2M015DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 16 - 8 bit */
#define NEC_FCN2M16DAT0B         FCN2M016DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 16 - 16 bit */
#define NEC_FCN2M16DAT0H         FCN2M016DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 16 - 32 bit */
#define NEC_FCN2M16DAT0W         FCN2M016DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 17 - 8 bit */
#define NEC_FCN2M17DAT0B         FCN2M017DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 17 - 16 bit */
#define NEC_FCN2M17DAT0H         FCN2M017DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 17 - 32 bit */
#define NEC_FCN2M17DAT0W         FCN2M017DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 18 - 8 bit */
#define NEC_FCN2M18DAT0B         FCN2M018DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 18 - 16 bit */
#define NEC_FCN2M18DAT0H         FCN2M018DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 18 - 32 bit */
#define NEC_FCN2M18DAT0W         FCN2M018DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 19 - 8 bit */
#define NEC_FCN2M19DAT0B         FCN2M019DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 19 - 16 bit */
#define NEC_FCN2M19DAT0H         FCN2M019DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 19 - 32 bit */
#define NEC_FCN2M19DAT0W         FCN2M019DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 20 - 8 bit */
#define NEC_FCN2M20DAT0B         FCN2M020DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 20 - 16 bit */
#define NEC_FCN2M20DAT0H         FCN2M020DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 20 - 32 bit */
#define NEC_FCN2M20DAT0W         FCN2M020DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 21 - 8 bit */
#define NEC_FCN2M21DAT0B         FCN2M021DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 21 - 16 bit */
#define NEC_FCN2M21DAT0H         FCN2M021DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 21 - 32 bit */
#define NEC_FCN2M21DAT0W         FCN2M021DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 22 - 8 bit */
#define NEC_FCN2M22DAT0B         FCN2M022DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 22 - 16 bit */
#define NEC_FCN2M22DAT0H         FCN2M022DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 22 - 32 bit */
#define NEC_FCN2M22DAT0W         FCN2M022DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 23 - 8 bit */
#define NEC_FCN2M23DAT0B         FCN2M023DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 23 - 16 bit */
#define NEC_FCN2M23DAT0H         FCN2M023DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 23 - 32 bit */
#define NEC_FCN2M23DAT0W         FCN2M023DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 24 - 8 bit */
#define NEC_FCN2M24DAT0B         FCN2M024DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 24 - 16 bit */
#define NEC_FCN2M24DAT0H         FCN2M024DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 24 - 32 bit */
#define NEC_FCN2M24DAT0W         FCN2M024DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 25 - 8 bit */
#define NEC_FCN2M25DAT0B         FCN2M025DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 25 - 16 bit */
#define NEC_FCN2M25DAT0H         FCN2M025DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 25 - 32 bit */
#define NEC_FCN2M25DAT0W         FCN2M025DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 26 - 8 bit */
#define NEC_FCN2M26DAT0B         FCN2M026DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 26 - 16 bit */
#define NEC_FCN2M26DAT0H         FCN2M026DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 26 - 32 bit */
#define NEC_FCN2M26DAT0W         FCN2M026DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 27 - 8 bit */
#define NEC_FCN2M27DAT0B         FCN2M027DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 27 - 16 bit */
#define NEC_FCN2M27DAT0H         FCN2M027DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 27 - 32 bit */
#define NEC_FCN2M27DAT0W         FCN2M027DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 28 - 8 bit */
#define NEC_FCN2M28DAT0B         FCN2M028DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 28 - 16 bit */
#define NEC_FCN2M28DAT0H         FCN2M028DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 28 - 32 bit */
#define NEC_FCN2M28DAT0W         FCN2M028DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 29 - 8 bit */
#define NEC_FCN2M29DAT0B         FCN2M029DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 29 - 16 bit */
#define NEC_FCN2M29DAT0H         FCN2M029DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 29 - 32 bit */
#define NEC_FCN2M29DAT0W         FCN2M029DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 30 - 8 bit */
#define NEC_FCN2M30DAT0B         FCN2M030DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 30 - 16 bit */
#define NEC_FCN2M30DAT0H         FCN2M030DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 30 - 32 bit */
#define NEC_FCN2M30DAT0W         FCN2M030DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 31 - 8 bit */
#define NEC_FCN2M31DAT0B         FCN2M031DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 31 - 16 bit */
#define NEC_FCN2M31DAT0H         FCN2M031DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 31 - 32 bit */
#define NEC_FCN2M31DAT0W         FCN2M031DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 32 - 8 bit */
#define NEC_FCN2M32DAT0B         FCN2M032DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 32 - 16 bit */
#define NEC_FCN2M32DAT0H         FCN2M032DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 32 - 32 bit */
#define NEC_FCN2M32DAT0W         FCN2M032DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 33 - 8 bit */
#define NEC_FCN2M33DAT0B         FCN2M033DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 33 - 16 bit */
#define NEC_FCN2M33DAT0H         FCN2M033DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 33 - 32 bit */
#define NEC_FCN2M33DAT0W         FCN2M033DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 34 - 8 bit */
#define NEC_FCN2M34DAT0B         FCN2M034DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 34 - 16 bit */
#define NEC_FCN2M34DAT0H         FCN2M034DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 34 - 32 bit */
#define NEC_FCN2M34DAT0W         FCN2M034DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 35 - 8 bit */
#define NEC_FCN2M35DAT0B         FCN2M035DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 35 - 16 bit */
#define NEC_FCN2M35DAT0H         FCN2M035DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 35 - 32 bit */
#define NEC_FCN2M35DAT0W         FCN2M035DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 36 - 8 bit */
#define NEC_FCN2M36DAT0B         FCN2M036DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 36 - 16 bit */
#define NEC_FCN2M36DAT0H         FCN2M036DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 36 - 32 bit */
#define NEC_FCN2M36DAT0W         FCN2M036DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 37 - 8 bit */
#define NEC_FCN2M37DAT0B         FCN2M037DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 37 - 16 bit */
#define NEC_FCN2M37DAT0H         FCN2M037DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 37 - 32 bit */
#define NEC_FCN2M37DAT0W         FCN2M037DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 38 - 8 bit */
#define NEC_FCN2M38DAT0B         FCN2M038DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 38 - 16 bit */
#define NEC_FCN2M38DAT0H         FCN2M038DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 38 - 32 bit */
#define NEC_FCN2M38DAT0W         FCN2M038DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 39 - 8 bit */
#define NEC_FCN2M39DAT0B         FCN2M039DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 39 - 16 bit */
#define NEC_FCN2M39DAT0H         FCN2M039DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 39 - 32 bit */
#define NEC_FCN2M39DAT0W         FCN2M039DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 40 - 8 bit */
#define NEC_FCN2M40DAT0B         FCN2M040DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 40 - 16 bit */
#define NEC_FCN2M40DAT0H         FCN2M040DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 40 - 32 bit */
#define NEC_FCN2M40DAT0W         FCN2M040DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 41 - 8 bit */
#define NEC_FCN2M41DAT0B         FCN2M041DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 41 - 16 bit */
#define NEC_FCN2M41DAT0H         FCN2M041DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 41 - 32 bit */
#define NEC_FCN2M41DAT0W         FCN2M041DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 42 - 8 bit */
#define NEC_FCN2M42DAT0B         FCN2M042DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 42 - 16 bit */
#define NEC_FCN2M42DAT0H         FCN2M042DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 42 - 32 bit */
#define NEC_FCN2M42DAT0W         FCN2M042DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 43 - 8 bit */
#define NEC_FCN2M43DAT0B         FCN2M043DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 43 - 16 bit */
#define NEC_FCN2M43DAT0H         FCN2M043DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 43 - 32 bit */
#define NEC_FCN2M43DAT0W         FCN2M043DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 44 - 8 bit */
#define NEC_FCN2M44DAT0B         FCN2M044DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 44 - 16 bit */
#define NEC_FCN2M44DAT0H         FCN2M044DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 44 - 32 bit */
#define NEC_FCN2M44DAT0W         FCN2M044DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 45 - 8 bit */
#define NEC_FCN2M45DAT0B         FCN2M045DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 45 - 16 bit */
#define NEC_FCN2M45DAT0H         FCN2M045DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 45 - 32 bit */
#define NEC_FCN2M45DAT0W         FCN2M045DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 46 - 8 bit */
#define NEC_FCN2M46DAT0B         FCN2M046DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 46 - 16 bit */
#define NEC_FCN2M46DAT0H         FCN2M046DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 46 - 32 bit */
#define NEC_FCN2M46DAT0W         FCN2M046DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 47 - 8 bit */
#define NEC_FCN2M47DAT0B         FCN2M047DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 47 - 16 bit */
#define NEC_FCN2M47DAT0H         FCN2M047DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 47 - 32 bit */
#define NEC_FCN2M47DAT0W         FCN2M047DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 48 - 8 bit */
#define NEC_FCN2M48DAT0B         FCN2M048DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 48 - 16 bit */
#define NEC_FCN2M48DAT0H         FCN2M048DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 48 - 32 bit */
#define NEC_FCN2M48DAT0W         FCN2M048DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 49 - 8 bit */
#define NEC_FCN2M49DAT0B         FCN2M049DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 49 - 16 bit */
#define NEC_FCN2M49DAT0H         FCN2M049DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 49 - 32 bit */
#define NEC_FCN2M49DAT0W         FCN2M049DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 50 - 8 bit */
#define NEC_FCN2M50DAT0B         FCN2M050DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 50 - 16 bit */
#define NEC_FCN2M50DAT0H         FCN2M050DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 50 - 32 bit */
#define NEC_FCN2M50DAT0W         FCN2M050DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 51 - 8 bit */
#define NEC_FCN2M51DAT0B         FCN2M051DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 51 - 16 bit */
#define NEC_FCN2M51DAT0H         FCN2M051DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 50 - 32 bit */
#define NEC_FCN2M51DAT0W         FCN2M050DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 52 - 8 bit */
#define NEC_FCN2M52DAT0B         FCN2M052DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 52 - 16 bit */
#define NEC_FCN2M52DAT0H         FCN2M052DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 52 - 32 bit */
#define NEC_FCN2M52DAT0W         FCN2M052DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 53 - 8 bit */
#define NEC_FCN2M53DAT0B         FCN2M053DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 53 - 16 bit */
#define NEC_FCN2M53DAT0H         FCN2M053DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 53 - 32 bit */
#define NEC_FCN2M53DAT0W         FCN2M053DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 54 - 8 bit */
#define NEC_FCN2M54DAT0B         FCN2M054DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 54 - 16 bit */
#define NEC_FCN2M54DAT0H         FCN2M054DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 54 - 32 bit */
#define NEC_FCN2M54DAT0W         FCN2M054DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 55 - 8 bit */
#define NEC_FCN2M55DAT0B         FCN2M055DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 55 - 16 bit */
#define NEC_FCN2M55DAT0H         FCN2M055DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 55 - 32 bit */
#define NEC_FCN2M55DAT0W         FCN2M055DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 56 - 8 bit */
#define NEC_FCN2M56DAT0B         FCN2M056DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 56 - 16 bit */
#define NEC_FCN2M56DAT0H         FCN2M056DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 56 - 32 bit */
#define NEC_FCN2M56DAT0W         FCN2M056DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 57 - 8 bit */
#define NEC_FCN2M57DAT0B         FCN2M057DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 57 - 16 bit */
#define NEC_FCN2M57DAT0H         FCN2M057DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 57 - 32 bit */
#define NEC_FCN2M57DAT0W         FCN2M057DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 58 - 8 bit */
#define NEC_FCN2M58DAT0B         FCN2M058DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 58 - 16 bit */
#define NEC_FCN2M58DAT0H         FCN2M058DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 58 - 32 bit */
#define NEC_FCN2M58DAT0W         FCN2M058DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 59 - 8 bit */
#define NEC_FCN2M59DAT0B         FCN2M059DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 59 - 16 bit */
#define NEC_FCN2M59DAT0H         FCN2M059DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 59 - 32 bit */
#define NEC_FCN2M59DAT0W         FCN2M059DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 60 - 8 bit */
#define NEC_FCN2M60DAT0B         FCN2M060DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 60 - 16 bit */
#define NEC_FCN2M60DAT0H         FCN2M060DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 60 - 32 bit */
#define NEC_FCN2M60DAT0W         FCN2M060DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 61 - 8 bit */
#define NEC_FCN2M61DAT0B         FCN2M061DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 61 - 16 bit */
#define NEC_FCN2M61DAT0H         FCN2M061DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 61 - 32 bit */
#define NEC_FCN2M61DAT0W         FCN2M061DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 62- 8 bit */
#define NEC_FCN2M62DAT0B         FCN2M062DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 62 - 16 bit */
#define NEC_FCN2M62DAT0H         FCN2M062DAT0H

/* Address of the CAN Controller Hardware  Message Buffer 62 - 32 bit */
#define NEC_FCN2M62DAT0W         FCN2M062DAT0W


/* Address of the CAN Controller Hardware 2 Message Buffer 63 - 8 bit */
#define NEC_FCN2M63DAT0B         FCN2M063DAT0B

/* Address of the CAN Controller Hardware 2 Message Buffer 63 - 16 bit */
#define NEC_FCN2M63DAT0H         FCN2M063DAT0H

/* Address of the CAN Controller Hardware 2 Message Buffer 63 - 32 bit */
#define NEC_FCN2M63DAT0W        FCN2M063DAT0W

/*  Addresses for  CAN Controller Hardware 3 Message Buffers */

/* Address of the CAN Controller Hardware 3 Message Buffer 0 - 8 bit */
#define NEC_FCN3M0DAT0B         FCN3M000DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 0 - 16 bit */
#define NEC_FCN3M0DAT0H         FCN3M000DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 0 - 32 bit */
#define NEC_FCN3M0DAT0W         FCN3M000DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 1 - 8 bit */
#define NEC_FCN3M1DAT0B         FCN3M001DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 1 - 16 bit */
#define NEC_FCN3M1DAT0H         FCN3M001DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 1 - 32 bit */
#define NEC_FCN3M1DAT0W         FCN3M001DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 2 - 8 bit */
#define NEC_FCN3M2DAT0B         FCN3M002DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 2 - 16 bit */
#define NEC_FCN3M2DAT0H         FCN3M002DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 2 - 32 bit */
#define NEC_FCN3M2DAT0W         FCN3M002DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 3 - 8 bit */
#define NEC_FCN3M3DAT0B         FCN3M003DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 3 - 16 bit */
#define NEC_FCN3M3DAT0H         FCN3M003DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 3 - 32 bit */
#define NEC_FCN3M3DAT0W         FCN3M003DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 4 - 8 bit */
#define NEC_FCN3M4DAT0B         FCN3M004DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 4 - 16 bit */
#define NEC_FCN3M4DAT0H         FCN3M004DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 4 - 32 bit */
#define NEC_FCN3M4DAT0W         FCN3M004DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 5 - 8 bit */
#define NEC_FCN3M5DAT0B         FCN3M005DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 5 - 16 bit */
#define NEC_FCN3M5DAT0H         FCN3M005DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 5 - 32 bit */
#define NEC_FCN3M5DAT0W         FCN3M005DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 6 - 8 bit */
#define NEC_FCN3M6DAT0B         FCN3M006DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 6 - 16 bit */
#define NEC_FCN3M6DAT0H         FCN3M006DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 6 - 32 bit */
#define NEC_FCN3M6DAT0W         FCN3M006DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 7 - 8 bit */
#define NEC_FCN3M7DAT0B         FCN3M007DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 7 - 16 bit */
#define NEC_FCN3M7DAT0H         FCN3M007DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer7 - 32 bit */
#define NEC_FCN3M7DAT0W         FCN3M007DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 8 - 8 bit */
#define NEC_FCN3M8DAT0B         FCN3M008DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 8 - 16 bit */
#define NEC_FCN3M8DAT0H         FCN3M008DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 8 - 32 bit */
#define NEC_FCN3M8DAT0W         FCN3M008DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 9 - 8 bit */
#define NEC_FCN3M9DAT0B         FCN3M009DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 9 - 16 bit */
#define NEC_FCN3M9DAT0H         FCN3M009DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 9 - 32 bit */
#define NEC_FCN3M9DAT0W         FCN3M009DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 8 bit */
#define NEC_FCN3M10DAT0B         FCN3M010DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 16 bit */
#define NEC_FCN3M10DAT0H         FCN3M010DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 32 bit */
#define NEC_FCN3M10DAT0W         FCN3M010DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 11 - 8 bit */
#define NEC_FCN3M11DAT0B         FCN3M011DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 16 bit */
#define NEC_FCN3M11DAT0H         FCN3M011DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 32 bit */
#define NEC_FCN3M11DAT0W         FCN3M011DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 2 - 8 bit */
#define NEC_FCN3M12DAT0B         FCN3M012DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 12 - 16 bit */
#define NEC_FCN3M12DAT0H         FCN3M012DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 12 - 32 bit */
#define NEC_FCN3M12DAT0W         FCN3M012DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 13 - 8 bit */
#define NEC_FCN3M13DAT0B         FCN3M013DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 13 - 16 bit */
#define NEC_FCN3M13DAT0H         FCN3M013DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 13 - 32 bit */
#define NEC_FCN3M13DAT0W         FCN3M013DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 14 - 8 bit */
#define NEC_FCN3M14DAT0B         FCN3M014DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 14 - 16 bit */
#define NEC_FCN3M14DAT0H         FCN3M014DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 14 - 32 bit */
#define NEC_FCN3M14DAT0W         FCN3M014DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 15 - 8 bit */
#define NEC_FCN3M15DAT0B         FCN3M015DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 15 - 16 bit */
#define NEC_FCN3M15DAT0H         FCN3M015DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 32 bit */
#define NEC_FCN3M15DAT0W         FCN3M015DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 16 - 8 bit */
#define NEC_FCN3M16DAT0B         FCN3M016DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 16 - 16 bit */
#define NEC_FCN3M16DAT0H         FCN3M016DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 16 - 32 bit */
#define NEC_FCN3M16DAT0W         FCN3M016DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 17 - 8 bit */
#define NEC_FCN3M17DAT0B         FCN3M017DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 17 - 16 bit */
#define NEC_FCN3M17DAT0H         FCN3M017DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 17 - 32 bit */
#define NEC_FCN3M17DAT0W         FCN3M017DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 18 - 8 bit */
#define NEC_FCN3M18DAT0B         FCN3M018DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 18 - 16 bit */
#define NEC_FCN3M18DAT0H         FCN3M018DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 18 - 32 bit */
#define NEC_FCN3M18DAT0W         FCN3M018DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 19 - 8 bit */
#define NEC_FCN3M19DAT0B         FCN3M019DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 19 - 16 bit */
#define NEC_FCN3M19DAT0H         FCN3M019DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 19 - 32 bit */
#define NEC_FCN3M19DAT0W         FCN3M019DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 20 - 8 bit */
#define NEC_FCN3M20DAT0B         FCN3M020DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 20 - 16 bit */
#define NEC_FCN3M20DAT0H         FCN3M020DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 20 - 32 bit */
#define NEC_FCN3M20DAT0W         FCN3M020DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 21 - 8 bit */
#define NEC_FCN3M21DAT0B         FCN3M021DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 21 - 16 bit */
#define NEC_FCN3M21DAT0H         FCN3M021DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 21 - 32 bit */
#define NEC_FCN3M21DAT0W         FCN3M021DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 22 - 8 bit */
#define NEC_FCN3M22DAT0B         FCN3M022DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 22 - 16 bit */
#define NEC_FCN3M22DAT0H         FCN3M022DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 22 - 32 bit */
#define NEC_FCN3M22DAT0W         FCN3M022DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 23 - 8 bit */
#define NEC_FCN3M23DAT0B         FCN3M023DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 23 - 16 bit */
#define NEC_FCN3M23DAT0H         FCN3M023DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 23 - 32 bit */
#define NEC_FCN3M23DAT0W         FCN3M023DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 24 - 8 bit */
#define NEC_FCN3M24DAT0B         FCN3M024DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 24 - 16 bit */
#define NEC_FCN3M24DAT0H         FCN3M024DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 24 - 32 bit */
#define NEC_FCN3M24DAT0W         FCN3M024DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 25 - 8 bit */
#define NEC_FCN3M25DAT0B         FCN3M025DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 25 - 16 bit */
#define NEC_FCN3M25DAT0H         FCN3M025DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 25 - 32 bit */
#define NEC_FCN3M25DAT0W         FCN3M025DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 26 - 8 bit */
#define NEC_FCN3M26DAT0B         FCN3M026DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 26 - 16 bit */
#define NEC_FCN3M26DAT0H         FCN3M026DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 26 - 32 bit */
#define NEC_FCN3M26DAT0W         FCN3M026DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 27 - 8 bit */
#define NEC_FCN3M27DAT0B         FCN3M027DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 27 - 16 bit */
#define NEC_FCN3M27DAT0H         FCN3M027DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 27 - 32 bit */
#define NEC_FCN3M27DAT0W         FCN3M027DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 28 - 8 bit */
#define NEC_FCN3M28DAT0B         FCN3M028DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 28 - 16 bit */
#define NEC_FCN3M28DAT0H         FCN3M028DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 28 - 32 bit */
#define NEC_FCN3M28DAT0W         FCN3M028DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 29 - 8 bit */
#define NEC_FCN3M29DAT0B         FCN3M029DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 29 - 16 bit */
#define NEC_FCN3M29DAT0H         FCN3M029DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 29 - 32 bit */
#define NEC_FCN3M29DAT0W         FCN3M029DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 30 - 8 bit */
#define NEC_FCN3M30DAT0B         FCN3M030DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 30 - 16 bit */
#define NEC_FCN3M30DAT0H         FCN3M030DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 30 - 32 bit */
#define NEC_FCN3M30DAT0W         FCN3M030DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 31 - 8 bit */
#define NEC_FCN3M31DAT0B         FCN3M031DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 31 - 16 bit */
#define NEC_FCN3M31DAT0H         FCN3M031DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 31 - 32 bit */
#define NEC_FCN3M31DAT0W         FCN3M031DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 32 - 8 bit */
#define NEC_FCN3M32DAT0B         FCN3M032DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 32 - 16 bit */
#define NEC_FCN3M32DAT0H         FCN3M032DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 32 - 32 bit */
#define NEC_FCN3M32DAT0W         FCN3M032DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 33 - 8 bit */
#define NEC_FCN3M33DAT0B         FCN3M033DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 33 - 16 bit */
#define NEC_FCN3M33DAT0H         FCN3M033DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 33 - 32 bit */
#define NEC_FCN3M33DAT0W         FCN3M033DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 34 - 8 bit */
#define NEC_FCN3M34DAT0B         FCN3M034DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 34 - 16 bit */
#define NEC_FCN3M34DAT0H         FCN3M034DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 34 - 32 bit */
#define NEC_FCN3M34DAT0W         FCN3M034DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 35 - 8 bit */
#define NEC_FCN3M35DAT0B         FCN3M035DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 35 - 16 bit */
#define NEC_FCN3M35DAT0H         FCN3M035DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 35 - 32 bit */
#define NEC_FCN3M35DAT0W         FCN3M035DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 36 - 8 bit */
#define NEC_FCN3M36DAT0B         FCN3M036DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 36 - 16 bit */
#define NEC_FCN3M36DAT0H         FCN3M036DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 36 - 32 bit */
#define NEC_FCN3M36DAT0W         FCN3M036DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 37 - 8 bit */
#define NEC_FCN3M37DAT0B         FCN3M037DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 37 - 16 bit */
#define NEC_FCN3M37DAT0H         FCN3M037DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 37 - 32 bit */
#define NEC_FCN3M37DAT0W         FCN3M037DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 38 - 8 bit */
#define NEC_FCN3M38DAT0B         FCN3M038DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 38 - 16 bit */
#define NEC_FCN3M38DAT0H         FCN3M038DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 38 - 32 bit */
#define NEC_FCN3M38DAT0W         FCN3M038DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 39 - 8 bit */
#define NEC_FCN3M39DAT0B         FCN3M039DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 39 - 16 bit */
#define NEC_FCN3M39DAT0H         FCN3M039DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 39 - 32 bit */
#define NEC_FCN3M39DAT0W         FCN3M039DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 40 - 8 bit */
#define NEC_FCN3M40DAT0B         FCN3M040DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 40 - 16 bit */
#define NEC_FCN3M40DAT0H         FCN3M040DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 40 - 32 bit */
#define NEC_FCN3M40DAT0W         FCN3M040DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 41 - 8 bit */
#define NEC_FCN3M41DAT0B         FCN3M041DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 41 - 16 bit */
#define NEC_FCN3M41DAT0H         FCN3M041DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 41 - 32 bit */
#define NEC_FCN3M41DAT0W         FCN3M041DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 42 - 8 bit */
#define NEC_FCN3M42DAT0B         FCN3M042DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 42 - 16 bit */
#define NEC_FCN3M42DAT0H         FCN3M042DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 42 - 32 bit */
#define NEC_FCN3M42DAT0W         FCN3M042DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 43 - 8 bit */
#define NEC_FCN3M43DAT0B         FCN3M043DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 43 - 16 bit */
#define NEC_FCN3M43DAT0H         FCN3M043DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 43 - 32 bit */
#define NEC_FCN3M43DAT0W         FCN3M043DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 44 - 8 bit */
#define NEC_FCN3M44DAT0B         FCN3M044DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 44 - 16 bit */
#define NEC_FCN3M44DAT0H         FCN3M044DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 44 - 32 bit */
#define NEC_FCN3M44DAT0W         FCN3M044DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 45 - 8 bit */
#define NEC_FCN3M45DAT0B         FCN3M045DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 45 - 16 bit */
#define NEC_FCN3M45DAT0H         FCN3M045DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 45 - 32 bit */
#define NEC_FCN3M45DAT0W         FCN3M045DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 46 - 8 bit */
#define NEC_FCN3M46DAT0B         FCN3M046DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 46 - 16 bit */
#define NEC_FCN3M46DAT0H         FCN3M046DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 46 - 32 bit */
#define NEC_FCN3M46DAT0W         FCN3M046DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 47 - 8 bit */
#define NEC_FCN3M47DAT0B         FCN3M047DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 47 - 16 bit */
#define NEC_FCN3M47DAT0H         FCN3M047DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 47 - 32 bit */
#define NEC_FCN3M47DAT0W         FCN3M047DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 48 - 8 bit */
#define NEC_FCN3M48DAT0B         FCN3M048DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 48 - 16 bit */
#define NEC_FCN3M48DAT0H         FCN3M048DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 48 - 32 bit */
#define NEC_FCN3M48DAT0W         FCN3M048DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 49 - 8 bit */
#define NEC_FCN3M49DAT0B         FCN3M049DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 49 - 16 bit */
#define NEC_FCN3M49DAT0H         FCN3M049DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 49 - 32 bit */
#define NEC_FCN3M49DAT0W         FCN3M049DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 50 - 8 bit */
#define NEC_FCN3M50DAT0B         FCN3M050DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 50 - 16 bit */
#define NEC_FCN3M50DAT0H         FCN3M050DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 50 - 32 bit */
#define NEC_FCN3M50DAT0W         FCN3M050DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 51 - 8 bit */
#define NEC_FCN3M51DAT0B         FCN3M051DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 51 - 16 bit */
#define NEC_FCN3M51DAT0H         FCN3M051DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 50 - 32 bit */
#define NEC_FCN3M51DAT0W         FCN3M051DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 52 - 8 bit */
#define NEC_FCN3M52DAT0B         FCN3M052DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 52 - 16 bit */
#define NEC_FCN3M52DAT0H         FCN3M052DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 52 - 32 bit */
#define NEC_FCN3M52DAT0W         FCN3M052DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 53 - 8 bit */
#define NEC_FCN3M53DAT0B         FCN3M053DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 53 - 16 bit */
#define NEC_FCN3M53DAT0H         FCN3M053DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 53 - 32 bit */
#define NEC_FCN3M53DAT0W         FCN3M053DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 54 - 8 bit */
#define NEC_FCN3M54DAT0B         FCN3M054DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 54 - 16 bit */
#define NEC_FCN3M54DAT0H         FCN3M054DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 54 - 32 bit */
#define NEC_FCN3M54DAT0W         FCN3M054DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 55 - 8 bit */
#define NEC_FCN3M55DAT0B         FCN3M055DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 55 - 16 bit */
#define NEC_FCN3M55DAT0H         FCN3M055DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 55 - 32 bit */
#define NEC_FCN3M55DAT0W         FCN3M055DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 56 - 8 bit */
#define NEC_FCN3M56DAT0B         FCN3M056DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 56 - 16 bit */
#define NEC_FCN3M56DAT0H         FCN3M056DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 56 - 32 bit */
#define NEC_FCN3M56DAT0W         FCN3M056DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 57 - 8 bit */
#define NEC_FCN3M57DAT0B         FCN3M057DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 57 - 16 bit */
#define NEC_FCN3M57DAT0H         FCN3M057DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 57 - 32 bit */
#define NEC_FCN3M57DAT0W         FCN3M057DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 58 - 8 bit */
#define NEC_FCN3M58DAT0B         FCN3M058DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 58 - 16 bit */
#define NEC_FCN3M58DAT0H         FCN3M058DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 58 - 32 bit */
#define NEC_FCN3M58DAT0W         FCN3M058DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 59 - 8 bit */
#define NEC_FCN3M59DAT0B         FCN3M059DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 59 - 16 bit */
#define NEC_FCN3M59DAT0H         FCN3M059DAT0H

/* Address of the CAN Controller Hardware1 Message Buffer 59 - 32 bit */
#define NEC_FCN3M59DAT0W         FCN3M059DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 60 - 8 bit */
#define NEC_FCN3M60DAT0B         FCN3M060DAT0B

/* Address of the CAN Controller Hardware 30 Message Buffer 60 - 16 bit */
#define NEC_FCN3M60DAT0H         FCN3M060DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 60 - 32 bit */
#define NEC_FCN3M60DAT0W         FCN3M060DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 61 - 8 bit */
#define NEC_FCN3M61DAT0B         FCN3M061DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 61 - 16 bit */
#define NEC_FCN3M61DAT0H         FCN3M061DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 61 - 32 bit */
#define NEC_FCN3M61DAT0W         FCN3M061DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 62- 8 bit */
#define NEC_FCN3M62DAT0B         FCN3M062DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 62 - 16 bit */
#define NEC_FCN3M62DAT0H         FCN3M062DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 62 - 32 bit */
#define NEC_FCN3M62DAT0W         FCN3M062DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 63 - 8 bit */
#define NEC_FCN3M63DAT0B         FCN3M063DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 63 - 16 bit */
#define NEC_FCN3M63DAT0H         FCN3M063DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 63 - 32 bit */
#define NEC_FCN3M63DAT0W         FCN3M063DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 0 - 8 bit */
#define NEC_FCN3M64DAT0B         FCN3M064DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 0 - 16 bit */
#define NEC_FCN3M64DAT0H         FCN3M064DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 0 - 32 bit */
#define NEC_FCN3M64DAT0W         FCN3M064DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 1 - 8 bit */
#define NEC_FCN3M65DAT0B         FCN3M065DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 1 - 16 bit */
#define NEC_FCN3M65DAT0H         FCN3M065DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 1 - 32 bit */
#define NEC_FCN3M65DAT0W         FCN3M065DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 2 - 8 bit */
#define NEC_FCN3M66DAT0B         FCN3M066DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 2 - 16 bit */
#define NEC_FCN3M66DAT0H         FCN3M066DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 2 - 32 bit */
#define NEC_FCN3M66DAT0W         FCN3M066DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 3 - 8 bit */
#define NEC_FCN3M67DAT0B         FCN3M067DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 3 - 16 bit */
#define NEC_FCN3M67DAT0H         FCN3M067DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 3 - 32 bit */
#define NEC_FCN3M67DAT0W         FCN3M067DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 4 - 8 bit */
#define NEC_FCN3M68DAT0B         FCN3M068DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 4 - 16 bit */
#define NEC_FCN3M68DAT0H         FCN3M068DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 4 - 32 bit */
#define NEC_FCN3M68DAT0W         FCN3M068DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 5 - 8 bit */
#define NEC_FCN3M69DAT0B         FCN3M069DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 5 - 16 bit */
#define NEC_FCN3M69DAT0H         FCN3M069DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 5 - 32 bit */
#define NEC_FCN3M69DAT0W         FCN3M069DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 6 - 8 bit */
#define NEC_FCN3M70DAT0B         FCN3M070DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 6 - 16 bit */
#define NEC_FCN3M70DAT0H         FCN3M070DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 6 - 32 bit */
#define NEC_FCN3M70DAT0W         FCN3M070DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 7 - 8 bit */
#define NEC_FCN3M71DAT0B         FCN3M071DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 7 - 16 bit */
#define NEC_FCN3M71DAT0H         FCN3M071DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer7 - 32 bit */
#define NEC_FCN3M71DAT0W         FCN3M071DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 8 - 8 bit */
#define NEC_FCN3M72DAT0B         FCN3M072DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 8 - 16 bit */
#define NEC_FCN3M72DAT0H         FCN3M072DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 8 - 32 bit */
#define NEC_FCN3M72DAT0W         FCN3M072DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 9 - 8 bit */
#define NEC_FCN3M73DAT0B         FCN3M073DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 9 - 16 bit */
#define NEC_FCN3M73DAT0H         FCN3M073DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 9 - 32 bit */
#define NEC_FCN3M73DAT0W         FCN3M073DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 8 bit */
#define NEC_FCN3M74DAT0B         FCN3M074DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 16 bit */
#define NEC_FCN3M74DAT0H         FCN3M074DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 32 bit */
#define NEC_FCN3M74DAT0W         FCN3M074DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 11 - 8 bit */
#define NEC_FCN3M75DAT0B         FCN3M075DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 16 bit */
#define NEC_FCN3M75DAT0H         FCN3M075DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 32 bit */
#define NEC_FCN3M75DAT0W         FCN3M075DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 2 - 8 bit */
#define NEC_FCN3M76DAT0B         FCN3M076DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 12 - 16 bit */
#define NEC_FCN3M76DAT0H         FCN3M076DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 12 - 32 bit */
#define NEC_FCN3M76DAT0W         FCN3M076DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 13 - 8 bit */
#define NEC_FCN3M77DAT0B         FCN3M077DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 13 - 16 bit */
#define NEC_FCN3M77DAT0H         FCN3M077DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 13 - 32 bit */
#define NEC_FCN3M77DAT0W         FCN3M077DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 14 - 8 bit */
#define NEC_FCN3M78DAT0B         FCN3M078DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 14 - 16 bit */
#define NEC_FCN3M78DAT0H         FCN3M078DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 14 - 32 bit */
#define NEC_FCN3M78DAT0W         FCN3M078DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 15 - 8 bit */
#define NEC_FCN3M79DAT0B         FCN3M079DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 15 - 16 bit */
#define NEC_FCN3M79DAT0H         FCN3M079DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 10 - 32 bit */
#define NEC_FCN3M79DAT0W         FCN3M079DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 16 - 8 bit */
#define NEC_FCN3M80DAT0B         FCN3M080DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 16 - 16 bit */
#define NEC_FCN3M80DAT0H         FCN3M080DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 16 - 32 bit */
#define NEC_FCN3M80DAT0W         FCN3M080DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 17 - 8 bit */
#define NEC_FCN3M81DAT0B         FCN3M081DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 17 - 16 bit */
#define NEC_FCN3M81DAT0H         FCN3M081DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 17 - 32 bit */
#define NEC_FCN3M81DAT0W         FCN3M081DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 18 - 8 bit */
#define NEC_FCN3M82DAT0B         FCN3M082DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 18 - 16 bit */
#define NEC_FCN3M82DAT0H         FCN3M082DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 18 - 32 bit */
#define NEC_FCN3M82DAT0W         FCN3M082DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 19 - 8 bit */
#define NEC_FCN3M83DAT0B         FCN3M083DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 19 - 16 bit */
#define NEC_FCN3M83DAT0H         FCN3M083DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 19 - 32 bit */
#define NEC_FCN3M83DAT0W         FCN3M083DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 20 - 8 bit */
#define NEC_FCN3M84DAT0B         FCN3M084DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 20 - 16 bit */
#define NEC_FCN3M84DAT0H         FCN3M084DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 20 - 32 bit */
#define NEC_FCN3M84DAT0W         FCN3M084DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 21 - 8 bit */
#define NEC_FCN3M85DAT0B         FCN3M085DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 21 - 16 bit */
#define NEC_FCN3M85DAT0H         FCN3M085DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 21 - 32 bit */
#define NEC_FCN3M85DAT0W         FCN3M085DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 22 - 8 bit */
#define NEC_FCN3M86DAT0B         FCN3M086DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 22 - 16 bit */
#define NEC_FCN3M86DAT0H         FCN3M086DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 22 - 32 bit */
#define NEC_FCN3M86DAT0W         FCN3M086DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 23 - 8 bit */
#define NEC_FCN3M87DAT0B         FCN3M087DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 23 - 16 bit */
#define NEC_FCN3M87DAT0H         FCN3M087DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 23 - 32 bit */
#define NEC_FCN3M87DAT0W         FCN3M087DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 24 - 8 bit */
#define NEC_FCN3M88DAT0B         FCN3M088DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 24 - 16 bit */
#define NEC_FCN3M88DAT0H         FCN3M088DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 24 - 32 bit */
#define NEC_FCN3M88DAT0W         FCN3M088DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 25 - 8 bit */
#define NEC_FCN3M89DAT0B         FCN3M089DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 25 - 16 bit */
#define NEC_FCN3M89DAT0H         FCN3M089DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 25 - 32 bit */
#define NEC_FCN3M89DAT0W         FCN3M089DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 26 - 8 bit */
#define NEC_FCN3M90DAT0B         FCN3M090DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 26 - 16 bit */
#define NEC_FCN3M90DAT0H         FCN3M090DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 26 - 32 bit */
#define NEC_FCN3M90DAT0W         FCN3M090DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 27 - 8 bit */
#define NEC_FCN3M91DAT0B         FCN3M091DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 27 - 16 bit */
#define NEC_FCN3M91DAT0H         FCN3M091DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 27 - 32 bit */
#define NEC_FCN3M91DAT0W         FCN3M091DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 28 - 8 bit */
#define NEC_FCN3M92DAT0B         FCN3M092DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 28 - 16 bit */
#define NEC_FCN3M92DAT0H         FCN3M092DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 28 - 32 bit */
#define NEC_FCN3M92DAT0W         FCN3M092DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 29 - 8 bit */
#define NEC_FCN3M93DAT0B         FCN3M093DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 29 - 16 bit */
#define NEC_FCN3M93DAT0H         FCN3M093DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 29 - 32 bit */
#define NEC_FCN3M93DAT0W         FCN3M093DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 30 - 8 bit */
#define NEC_FCN3M94DAT0B         FCN3M094DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 30 - 16 bit */
#define NEC_FCN3M94DAT0H         FCN3M094DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 30 - 32 bit */
#define NEC_FCN3M94DAT0W         FCN3M094DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 31 - 8 bit */
#define NEC_FCN3M95DAT0B         FCN3M095DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 31 - 16 bit */
#define NEC_FCN3M95DAT0H         FCN3M095DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 31 - 32 bit */
#define NEC_FCN3M95DAT0W         FCN3M095DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 32 - 8 bit */
#define NEC_FCN3M96DAT0B         FCN3M096DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 32 - 16 bit */
#define NEC_FCN3M96DAT0H         FCN3M096DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 32 - 32 bit */
#define NEC_FCN3M96DAT0W         FCN3M096DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 33 - 8 bit */
#define NEC_FCN3M97DAT0B         FCN3M097DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 33 - 16 bit */
#define NEC_FCN3M97DAT0H         FCN3M097DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 33 - 32 bit */
#define NEC_FCN3M97DAT0W         FCN3M097DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 34 - 8 bit */
#define NEC_FCN3M98DAT0B         FCN3M098DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 34 - 16 bit */
#define NEC_FCN3M98DAT0H         FCN3M098DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 34 - 32 bit */
#define NEC_FCN3M98DAT0W         FCN3M098DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 35 - 8 bit */
#define NEC_FCN3M99DAT0B         FCN3M099DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 35 - 16 bit */
#define NEC_FCN3M99DAT0H         FCN3M099DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 35 - 32 bit */
#define NEC_FCN3M99DAT0W         FCN3M099DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 36 - 8 bit */
#define NEC_FCN3M100DAT0B         FCN3M100DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 36 - 16 bit */
#define NEC_FCN3M100DAT0H         FCN3M100DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 36 - 32 bit */
#define NEC_FCN3M100DAT0W         FCN3M100DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 37 - 8 bit */
#define NEC_FCN3M101DAT0B         FCN3M101DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 37 - 16 bit */
#define NEC_FCN3M101DAT0H         FCN3M101DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 37 - 32 bit */
#define NEC_FCN3M101DAT0W         FCN3M101DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 38 - 8 bit */
#define NEC_FCN3M102DAT0B         FCN3M102DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 38 - 16 bit */
#define NEC_FCN3M102DAT0H        FCN3M102DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 38 - 32 bit */
#define NEC_FCN3M102DAT0W         FCN3M102DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 39 - 8 bit */
#define NEC_FCN3M103DAT0B         FCN3M103DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 39 - 16 bit */
#define NEC_FCN3M103DAT0H         FCN3M103DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 39 - 32 bit */
#define NEC_FCN3M103DAT0W         FCN3M103DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 40 - 8 bit */
#define NEC_FCN3M104DAT0B         FCN3M104DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 40 - 16 bit */
#define NEC_FCN3M104DAT0H         FCN3M104DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 40 - 32 bit */
#define NEC_FCN3M104DAT0W         FCN3M104DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 41 - 8 bit */
#define NEC_FCN3M105DAT0B         FCN3M105DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 41 - 16 bit */
#define NEC_FCN3M105DAT0H         FCN3M105DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 41 - 32 bit */
#define NEC_FCN3M105DAT0W         FCN3M105DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 42 - 8 bit */
#define NEC_FCN3M106DAT0B         FCN3M106DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 42 - 16 bit */
#define NEC_FCN3M106DAT0H         FCN3M106DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 42 - 32 bit */
#define NEC_FCN3M106DAT0W         FCN3M106DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 43 - 8 bit */
#define NEC_FCN3M107DAT0B         FCN3M107DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 43 - 16 bit */
#define NEC_FCN3M107DAT0H         FCN3M107DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 43 - 32 bit */
#define NEC_FCN3M107DAT0W         FCN3M107DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 44 - 8 bit */
#define NEC_FCN3M108DAT0B         FCN3M108DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 44 - 16 bit */
#define NEC_FCN3M108DAT0H         FCN3M108DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 44 - 32 bit */
#define NEC_FCN3M108DAT0W         FCN3M108DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 45 - 8 bit */
#define NEC_FCN3M109DAT0B         FCN3M109DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 45 - 16 bit */
#define NEC_FCN3M109DAT0H         FCN3M109DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 45 - 32 bit */
#define NEC_FCN3M109DAT0W         FCN3M109DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 46 - 8 bit */
#define NEC_FCN3M110DAT0B         FCN3M110DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 46 - 16 bit */
#define NEC_FCN3M110DAT0H         FCN3M110DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 46 - 32 bit */
#define NEC_FCN3M110DAT0W         FCN3M110DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 47 - 8 bit */
#define NEC_FCN3M111DAT0B         FCN3M111DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 47 - 16 bit */
#define NEC_FCN3M111DAT0H         FCN3M111DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 47 - 32 bit */
#define NEC_FCN3M111DAT0W         FCN3M111DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 48 - 8 bit */
#define NEC_FCN3M112DAT0B         FCN3M112DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 48 - 16 bit */
#define NEC_FCN3M112DAT0H         FCN3M112DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 48 - 32 bit */
#define NEC_FCN3M112DAT0W         FCN3M112DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 49 - 8 bit */
#define NEC_FCN3M113DAT0B         FCN3M113DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 49 - 16 bit */
#define NEC_FCN3M113DAT0H         FCN3M113DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 49 - 32 bit */
#define NEC_FCN3M113DAT0W         FCN3M113DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 50 - 8 bit */
#define NEC_FCN3M114DAT0B         FCN3M114DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 50 - 16 bit */
#define NEC_FCN3M114DAT0H         FCN3M114DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 50 - 32 bit */
#define NEC_FCN3M114DAT0W         FCN3M114DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 51 - 8 bit */
#define NEC_FCN3M115DAT0B         FCN3M115DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 51 - 16 bit */
#define NEC_FCN3M115DAT0H         FCN3M115DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 50 - 32 bit */
#define NEC_FCN3M115DAT0W         FCN3M115DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 52 - 8 bit */
#define NEC_FCN3M116DAT0B         FCN3M116DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 52 - 16 bit */
#define NEC_FCN3M116DAT0H         FCN3M116DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 52 - 32 bit */
#define NEC_FCN3M116DAT0W         FCN3M116DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 53 - 8 bit */
#define NEC_FCN3M117DAT0B         FCN3M117DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 53 - 16 bit */
#define NEC_FCN3M117DAT0H         FCN3M117DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 53 - 32 bit */
#define NEC_FCN3M117DAT0W         FCN3M117DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 54 - 8 bit */
#define NEC_FCN3M118DAT0B         FCN3M118DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 54 - 16 bit */
#define NEC_FCN3M118DAT0H         FCN3M118DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 54 - 32 bit */
#define NEC_FCN3M118DAT0W         FCN3M118DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 55 - 8 bit */
#define NEC_FCN3M119DAT0B         FCN3M119DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 55 - 16 bit */
#define NEC_FCN3M119DAT0H         FCN3M119DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 55 - 32 bit */
#define NEC_FCN3M119DAT0W         FCN3M119DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 56 - 8 bit */
#define NEC_FCN3M120DAT0B         FCN3M120DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 56 - 16 bit */
#define NEC_FCN3M120DAT0H         FCN3M120DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 56 - 32 bit */
#define NEC_FCN3M120DAT0W        FCN3M120DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 57 - 8 bit */
#define NEC_FCN3M121DAT0B         FCN3M121DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 57 - 16 bit */
#define NEC_FCN3M121DAT0H         FCN3M121DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 57 - 32 bit */
#define NEC_FCN3M121DAT0W         FCN3M121DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 58 - 8 bit */
#define NEC_FCN3M122DAT0B         FCN3M122DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 58 - 16 bit */
#define NEC_FCN3M122DAT0H        FCN3M122DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 58 - 32 bit */
#define NEC_FCN3M122DAT0W        FCN3M122DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 59 - 8 bit */
#define NEC_FCN3M123DAT0B         FCN3M123DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 59 - 16 bit */
#define NEC_FCN3M123DAT0H         FCN3M123DAT0H

/* Address of the CAN Controller Hardware1 Message Buffer 59 - 32 bit */
#define NEC_FCN3M123DAT0W         FCN3M123DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 60 - 8 bit */
#define NEC_FCN3M124DAT0B         FCN3M124DAT0B

/* Address of the CAN Controller Hardware 30 Message Buffer 60 - 16 bit */
#define NEC_FCN3M124DAT0H         FCN3M124DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 60 - 32 bit */
#define NEC_FCN3M124DAT0W         FCN3M124DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 61 - 8 bit */
#define NEC_FCN3M125DAT0B         FCN3M125DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 61 - 16 bit */
#define NEC_FCN3M125DAT0H         FCN3M125DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 61 - 32 bit */
#define NEC_FCN3M125DAT0W         FCN3M125DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 62- 8 bit */
#define NEC_FCN3M126DAT0B         FCN3M126DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 62 - 16 bit */
#define NEC_FCN3M126DAT0H         FCN3M126DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 62 - 32 bit */
#define NEC_FCN3M126DAT0W         FCN3M126DAT0W


/* Address of the CAN Controller Hardware 3 Message Buffer 63 - 8 bit */
#define NEC_FCN3M127DAT0B         FCN3M127DAT0B

/* Address of the CAN Controller Hardware 3 Message Buffer 63 - 16 bit */
#define NEC_FCN3M127DAT0H         FCN3M127DAT0H

/* Address of the CAN Controller Hardware 3 Message Buffer 63 - 32 bit */
#define NEC_FCN3M127DAT0W         FCN3M127DAT0W

/*******************************************************************************
**                 Macros for SPI Driver                                     **
*******************************************************************************/
/* Base address of the CSIG0  hardware registers structure */
#define NEC_CSIG0CTL0        CSIG0CTL0
#define NEC_CSIG0BCTL0       CSIG0BCTL0
#define NEC_CSIG0CTL1        CSIG0CTL1
#define NEC_CSIG0CTL2        CSIG0CTL2
#define NEC_CSIG0CFG0        CSIG0CFG0
#define NEC_CSIG0TX0W        CSIG0TX0W
#define NEC_CSIG0TX0H        CSIG0TX0H
#define NEC_CSIG0RX0         CSIG0RX0

/* Base address of the CSIG4  hardware registers structure */
#define NEC_CSIG4CTL0        CSIG4CTL0
#define NEC_CSIG4BCTL0       CSIG4BCTL0
#define NEC_CSIG4CTL1        CSIG4CTL1
#define NEC_CSIG4CTL2        CSIG4CTL2
#define NEC_CSIG4CFG0        CSIG4CFG0
#define NEC_CSIG4TX0W        CSIG4TX0W
#define NEC_CSIG4TX0H        CSIG4TX0H
#define NEC_CSIG4RX0         CSIG4RX0

/* Base address of the CSIH0 hardware registers structure */
#define NEC_CSIH0CTL0        CSIH0CTL0
#define NEC_CSIH0CTL1        CSIH0CTL1
#define NEC_CSIH0CTL2        CSIH0CTL2 
#define NEC_CHBA0MCTL1       CSIH0MCTL1
#define NEC_CHBA0MCTL2       CSIH0MCTL2
#define NEC_CSIH0TX0W        CSIH0TX0H
#define NEC_CSIH0TX0H        CSIH0TX0H
#define NEC_CSIH0RX0         CSIH0RX0H
#define NEC_CHBA0MRWP0       CSIH0MRWP0
#define NEC_CHBA0MCTL0       CSIH0MCTL0
#define NEC_CHBA0CFG0        CSIH0CFG0
#define NEC_CHBA0CFG1        CSIH0CFG1
#define NEC_CHBA0CFG2        CSIH0CFG2
#define NEC_CHBA0CFG3        CSIH0CFG3 
#define NEC_CHBA0CFG4        CSIH0CFG4
#define NEC_CHBA0CFG5        CSIH0CFG5 
#define NEC_CHBA0CFG6        CSIH0CFG6
#define NEC_CHBA0CFG7        CSIH0CFG7

/* Base address of the CSIH1 hardware registers structure */
#define NEC_CSIH1CTL0        CSIH1CTL0
#define NEC_CSIH1CTL1        CSIH1CTL1
#define NEC_CSIH1CTL2        CSIH1CTL2 
#define NEC_CHBA1MCTL1       CSIH1MCTL1
#define NEC_CHBA1MCTL2       CSIH1MCTL2
#define NEC_CSIH1TX0W        CSIH1TX0H
#define NEC_CSIH1TX0H        CSIH1TX0H
#define NEC_CSIH1RX0         CSIH1RX0H
#define NEC_CHBA1MRWP0       CSIH1MRWP0
#define NEC_CHBA1MCTL0       CSIH1MCTL0
#define NEC_CHBA1CFG0        CSIH1CFG0
#define NEC_CHBA1CFG1        CSIH1CFG1
#define NEC_CHBA1CFG2        CSIH1CFG2
#define NEC_CHBA1CFG3        CSIH1CFG3 
#define NEC_CHBA1CFG4        CSIH1CFG4
#define NEC_CHBA1CFG5        CSIH1CFG5 
#define NEC_CHBA1CFG6        CSIH1CFG6
#define NEC_CHBA1CFG7        CSIH1CFG7

/* Base address of the CSIH2 hardware registers structure */
#define NEC_CSIH2CTL0        CSIH2CTL0
#define NEC_CSIH2CTL1        CSIH2CTL1
#define NEC_CSIH2CTL2        CSIH2CTL2
#define NEC_CHBA2MCTL0       CSIH2MCTL0
#define NEC_CHBA2MCTL1       CSIH2MCTL1
#define NEC_CSIH2TX0W        CSIH2TX0H
#define NEC_CSIH2TX0H        CSIH2TX0H
#define NEC_CSIH2RX0         CSIH2RX0H
#define NEC_CHBA2MRWP0       CSIH2MRWP0
#define NEC_CHBA2CFG0        CSIH2CFG0
#define NEC_CHBA2CFG1        CSIH2CFG1
#define NEC_CHBA2CFG2        CSIH2CFG2
#define NEC_CHBA2CFG3        CSIH2CFG3 
#define NEC_CHBA2CFG4        CSIH2CFG4
#define NEC_CHBA2CFG5        CSIH2CFG5 
#define NEC_CHBA2CFG6        CSIH2CFG6
#define NEC_CHBA2CFG7        CSIH2CFG7

/* Interrupt control registers for CSIG0 */
#define NEC_ICCSIG0IRE_109  ICCSIG0IRE 
#define NEC_ICCSIG0IR_110   ICCSIG0IR
#define NEC_ICCSIG0IC_111   ICCSIG0IC  

/* Interrupt control registers for CSIG4 */
#define NEC_ICCSIG4IRE_170  ICCSIG4IRE 
#define NEC_ICCSIG4IR_171   ICCSIG4IR
#define NEC_ICCSIG4IC_172   ICCSIG4IC  

/* Interrupt control registers for CSIH0 */
#define NEC_CSIH0TIC_163    ICCSIH0IC           
#define NEC_CSIH0TIJC_164   ICCSIH0IJC
#define NEC_CSIH0TIRE_168   ICCSIH0IRE
#define NEC_CSIH0TIR_169    ICCSIH0IR

/* Interrupt control registers for CSIH1 */
#define NEC_CSIH1TIC_182    ICCSIH1IC           
#define NEC_CSIH1TIJC_183   ICCSIH1IJC
#define NEC_CSIH1TIRE_180   ICCSIH1IRE
#define NEC_CSIH1TIR_181    ICCSIH1IR

/* Interrupt control registers for CSIH2 */
#define NEC_CSIH2TIC_204    ICCSIH2IC           
#define NEC_CSIH2TIJC_205   ICCSIH2IJC
#define NEC_CSIH2TIRE_202   ICCSIH2IRE
#define NEC_CSIH2TIR_203    ICCSIH2IR

/*******************************************************************************
**                 Macros for LIN Driver                                      **
*******************************************************************************/

/* Address of the LIN URTE 2 Control Register0 */
#define NEC_URTE2CTL0       URTE2CTL0

/* Address of the LIN URTE 3 Control Register0 */
#define NEC_URTE3CTL0       URTE3CTL0

/* Address of the LIN URTE 4 Control Register0 */
#define NEC_URTE4CTL0       URTE4CTL0

/* Address of the LIN URTE 5 Control Register0 */
#define NEC_URTE5CTL0       URTE5CTL0

/* Address of the LIN URTE 6 Control Register0 */
#define NEC_URTE6CTL0       URTE6CTL0

/* Address of the LIN URTE 7 Control Register0 */
#define NEC_URTE7CTL0       URTE7CTL0

/* Address of the LIN URTE 10 Control Register0 */
#define NEC_URTE10CTL0      URTE10CTL0

/* Address of the LIN URTE 11 Control Register0 */
#define NEC_URTE11CTL0      URTE11CTL0


#define NEC_LMA2CTL0W  LMA2CTL0W
#define NEC_LMA3CTL0W  LMA3CTL0W
#define NEC_LMA4CTL0W  LMA4CTL0W
#define NEC_LMA5CTL0W  LMA5CTL0W
#define NEC_LMA6CTL0W  LMA6CTL0W
#define NEC_LMA7CTL0W  LMA7CTL0W
#define NEC_LMA10CTL0W  LMA10CTL0W
#define NEC_LMA11CTL0W  LMA11CTL0W

/* Address of the LIN LMA 2 Status Interrupt Register */
#define NEC_ICLMA2IS       ICLMA2IS

/* Address of the LIN LMA 2 Receive Interrupt Register */
#define NEC_ICLMA2IR       ICLMA2IR

/* Address of the LIN LMA 2 Transmit Interrupt Register */
#define NEC_ICLMA2IT       ICLMA2IT

/* Address of the LIN LMA 3 Status Interrupt Register */
#define NEC_ICLMA3IS       ICLMA3IS

/* Address of the LIN LMA 3 Receive Interrupt Register */
#define NEC_ICLMA3IR       ICLMA3IR

/* Address of the LIN LMA 3 Transmit Interrupt Register */
#define NEC_ICLMA3IT       ICLMA3IT

/* Address of the LIN LMA 4 Status Interrupt Register */
#define NEC_ICLMA4IS       ICLMA4IS

/* Address of the LIN LMA 4 Receive Interrupt Register */
#define NEC_ICLMA4IR       ICLMA4IR

/* Address of the LIN LMA 4 Transmit Interrupt Register */
#define NEC_ICLMA4IT       ICLMA4IT

/* Address of the LIN LMA 5 Status Interrupt Register */
#define NEC_ICLMA5IS       ICLMA5IS

/* Address of the LIN LMA 5 Receive Interrupt Register */
#define NEC_ICLMA5IR       ICLMA5IR

/* Address of the LIN LMA 5 Transmit Interrupt Register */
#define NEC_ICLMA5IT       ICLMA5IT

/* Address of the LIN LMA 6 Status Interrupt Register */
#define NEC_ICLMA6IS       ICLMA6IS

/* Address of the LIN LMA 6 Receive Interrupt Register */
#define NEC_ICLMA6IR       ICLMA6IR

/* Address of the LIN LMA 6 Transmit Interrupt Register */
#define NEC_ICLMA6IT       ICLMA6IT

/* Address of the LIN LMA 7 Status Interrupt Register */
#define NEC_ICLMA7IS       ICLMA7IS

/* Address of the LIN LMA 7 Receive Interrupt Register */
#define NEC_ICLMA7IR       ICLMA7IR

/* Address of the LIN LMA 7 Transmit Interrupt Register */
#define NEC_ICLMA7IT       ICLMA7IT

/* Address of the LIN LMA 10 Status Interrupt Register */
#define NEC_ICLMA10IS       ICLMA10IS

/* Address of the LIN LMA 10 Receive Interrupt Register */
#define NEC_ICLMA10IR       ICLMA10IR

/* Address of the LIN LMA 10 Transmit Interrupt Register */
#define NEC_ICLMA10IT       ICLMA10IT

/* Address of the LIN LMA 11 Status Interrupt Register */
#define NEC_ICLMA11IS       ICLMA11IS

/* Address of the LIN LMA 11 Receive Interrupt Register */
#define NEC_ICLMA11IR       ICLMA11IR

/* Address of the LIN LMA 11 Transmit Interrupt Register */
#define NEC_ICLMA11IT       ICLMA11IT

/*******************************************************************************
**                 Macros for IMR Register                                    **
*******************************************************************************/
#define NEC_IMR0       IMR0
#define NEC_IMR1       IMR1
#define NEC_IMR2       IMR2
#define NEC_IMR3       IMR3
#define NEC_IMR4       IMR4
#define NEC_IMR5       IMR5
#define NEC_IMR6       IMR6
#define NEC_IMR7       IMR7
#define NEC_IMR8       IMR8
#define NEC_IMR9       IMR9
#define NEC_IMR10       IMR10
#define NEC_IMR11       IMR11
#define NEC_IMR12       IMR12
#define NEC_IMR13       IMR13
#define NEC_IMR14       IMR14
#define NEC_IMR15       IMR15
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
