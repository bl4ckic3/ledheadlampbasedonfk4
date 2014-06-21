/*============================================================================*/
/* Project      = AUTOSAR NEC Xx4 MCAL Components                             */
/* Module       = MemMap.h                                                    */
/* Version      = 3.0.8                                                       */
/* Date         = 20-May-2010                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009 by NEC Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision for sections for Memory Mapping                                  */
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
/*              Devices:        Xx4                                           */
/*              Compiler:       GHS V5.1.6c                                   */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:   30-Mar-2009 : Initial version
 * V3.0.1:   23-Jun-2009 : As per SCR 012,
 *                         1. Memory sections for mapping global constants of
 *                            unspecified size for post build parameters is
 *                            added.
 *                         2. The sections for FlexRay Driver, CAN Driver,
 *                            LIN and LINIF are removed.
 *                         3. Memory sections for WDG DRIVER B is added.
 * V3.0.2:   14-Jul-2009 : As per SCR 015, compiler version is changed from 
 *                         V5.0.5 to V5.1.6c in the header of the file.
 * V3.0.3:   22-Oct-2009 : As per SCR 051, sections for FlexRay Driver and CAN
 *                         Driver are added.
 * V3.0.4:   11-Nov-2009 : As per SCR 122, section names of public and private 
 *                         code of FLS are modified.
 * V3.0.5:   09-Feb-2010 : As per SCR 184, sections of public, private and
 *                         application code of FEE are modified.
 * V3.0.6:   01-Mar-2010 : As per SCR 205, for Fee module section of EEL_data is
 *                         changed to DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED.
 * V3.0.7:   08-Apr-2010 : As per SCR 246, for Mcu module memory section of 
 *                         MCU_CFG_BURAM_UNSPECIFIED added.
 * V3.0.8:   20-May-2010 : As per SCR 264, memory section is updated for LIN 
 *                         module.
 */
/******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define MEMMAP_AR_MAJOR_VERSION   1
#define MEMMAP_AR_MINOR_VERSION   1
#define MEMMAP_AR_PATCH_VERSION   0

/*
 * File version information
 */
#define MEMMAP_SW_MAJOR_VERSION   3
#define MEMMAP_SW_MINOR_VERSION   0
#define MEMMAP_SW_PATCH_VERSION   0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Module section mapping                                **
*******************************************************************************/
/*
 * The symbol 'START_WITH_IF' is undefined.
 *
 * Thus, the preprocessor continues searching for defined symbols
 * This first #ifdef makes integration of delivered parts of MemMap.h
 * easier because every supplier starts with #elif
 */
#if defined (START_WITH_IF)

/* -------------------------------------------------------------------------- */
/*             MCU                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (MCU_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (MCU_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (MCU_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (MCU_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (MCU_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (MCU_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (MCU_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (MCU_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (MCU_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (MCU_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (MCU_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (MCU_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  MCU_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (MCU_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (MCU_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  MCU_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (MCU_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (MCU_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (MCU_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  MCU_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (MCU_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  MCU_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif
   
#elif defined (MCU_START_SEC_BURAM_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  MCU_START_SEC_BURAM_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".MCU_CFG_BURAM_UNSPECIFIED"
   #endif
#elif defined (MCU_STOP_SEC_BURAM_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  MCU_STOP_SEC_BURAM_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (MCU_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  MCU_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".MCU_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (MCU_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  MCU_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (MCU_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  MCU_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (MCU_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (MCU_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  MCU_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (MCU_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (MCU_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  MCU_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (MCU_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
 
#elif defined (MCU_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  MCU_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (MCU_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  MCU_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (MCU_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  MCU_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (MCU_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  MCU_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (MCU_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".MCU_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (MCU_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  MCU_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".MCU_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (MCU_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  MCU_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".MCU_PUBLIC_CODE_ROM"
   #endif
#elif defined (MCU_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  MCU_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (MCU_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  MCU_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".MCU_PRIVATE_CODE_ROM"
   #endif
#elif defined (MCU_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  MCU_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (MCU_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  MCU_START_SEC_APPL_CODE
     #pragma ghs section text=".MCU_APPL_CODE_ROM"
   #endif
#elif defined (MCU_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  MCU_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
   
/* -------------------------------------------------------------------------- */
/*             LIN                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (LIN_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (LIN_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (LIN_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (LIN_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (LIN_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (LIN_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (LIN_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (LIN_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (LIN_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (LIN_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (LIN_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (LIN_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  LIN_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (LIN_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (LIN_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  LIN_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (LIN_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (LIN_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  LIN_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (LIN_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  LIN_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (LIN_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  LIN_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif
   
#elif defined (LIN_START_SEC_BURAM_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  LIN_START_SEC_BURAM_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".LIN_CFG_BURAM_UNSPECIFIED"
   #endif
#elif defined (LIN_STOP_SEC_BURAM_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  LIN_STOP_SEC_BURAM_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (LIN_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  LIN_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".LIN_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (LIN_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  LIN_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (LIN_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  LIN_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (LIN_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (LIN_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  LIN_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (LIN_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (LIN_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  LIN_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (LIN_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
 
#elif defined (LIN_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  LIN_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (LIN_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  LIN_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (LIN_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  LIN_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (LIN_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  LIN_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (LIN_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".LIN_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (LIN_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  LIN_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".LIN_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (LIN_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  LIN_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (LIN_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  LIN_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".LIN_PUBLIC_CODE_ROM"
   #endif
#elif defined (LIN_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  LIN_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (LIN_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  LIN_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".LIN_PRIVATE_CODE_ROM"
   #endif
#elif defined (LIN_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  LIN_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (LIN_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  LIN_START_SEC_APPL_CODE
     #pragma ghs section text=".LIN_APPL_CODE_ROM"
   #endif
#elif defined (LIN_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  LIN_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
  
/* -------------------------------------------------------------------------- */
/*             GPT                                                            */
/* -------------------------------------------------------------------------- */
   
#elif defined (GPT_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (GPT_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (GPT_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (GPT_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (GPT_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (GPT_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (GPT_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (GPT_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (GPT_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (GPT_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (GPT_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (GPT_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  GPT_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (GPT_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (GPT_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  GPT_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (GPT_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (GPT_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  GPT_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (GPT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (GPT_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  GPT_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (GPT_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  GPT_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (GPT_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  GPT_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".GPT_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (GPT_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  GPT_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (GPT_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  GPT_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (GPT_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (GPT_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  GPT_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (GPT_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (GPT_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  GPT_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (GPT_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
 
#elif defined (GPT_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  GPT_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (GPT_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  GPT_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (GPT_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  GPT_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (GPT_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  GPT_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (GPT_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".GPT_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (GPT_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  GPT_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".GPT_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (GPT_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  GPT_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".GPT_PUBLIC_CODE_ROM"
   #endif
#elif defined (GPT_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  GPT_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (GPT_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  GPT_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".GPT_PRIVATE_CODE_ROM"
   #endif
#elif defined (GPT_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  GPT_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (GPT_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  GPT_START_SEC_APPL_CODE
     #pragma ghs section text=".GPT_APPL_CODE_ROM"
   #endif
#elif defined (GPT_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  GPT_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/* -------------------------------------------------------------------------- */
/*             WDG DRIVER A                                                   */
/* -------------------------------------------------------------------------- */

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_1BIT
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef CONFIG_VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".WDG23_A_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef CONFIG_VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
  
#elif defined (WDG_23_DRIVERA_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
 
#elif defined (WDG_23_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".WDG23_A_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
 
#elif defined (WDG_23_DRIVERA_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".WDG23_A_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".WDG23_A_PUBLIC_CODE_ROM"
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (WDG_23_DRIVERA_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".WDG23_A_PRIVATE_CODE_ROM"
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (WDG_23_DRIVERA_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERA_START_SEC_APPL_CODE
     #pragma ghs section text=".WDG23_A_APPL_CODE_ROM"
   #endif
#elif defined (WDG_23_DRIVERA_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERA_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/* -------------------------------------------------------------------------- */
/*             WDG DRIVER B                                                   */
/* -------------------------------------------------------------------------- */

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_1BIT
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef CONFIG_VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".WDG23_A_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef CONFIG_VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
  
#elif defined (WDG_23_DRIVERB_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
 
#elif defined (WDG_23_DRIVERB_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".WDG23_A_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
 
#elif defined (WDG_23_DRIVERB_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".WDG23_A_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".WDG23_A_PUBLIC_CODE_ROM"
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (WDG_23_DRIVERB_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".WDG23_A_PRIVATE_CODE_ROM"
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (WDG_23_DRIVERB_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERB_START_SEC_APPL_CODE
     #pragma ghs section text=".WDG23_A_APPL_CODE_ROM"
   #endif
#elif defined (WDG_23_DRIVERB_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  WDG_23_DRIVERB_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/*----------------------------------------------
*          COMM 
----------------------------------------------*/
 /*****************************CODE SECTIONS**********************/
#elif defined (COMM_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  COMM_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (COMM_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  COMM_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined  (COMM_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  COMM_START_SEC_APPL_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (COMM_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  COMM_STOP_SEC_APPL_CODE
     #undef  APPL_CODE_SEC_STARTED
     #define DEFAULT_STOP_SEC_CODE
   #endif
   
/* CONST sections */
#elif defined (COMM_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  COMM_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (COMM_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_8BIT_SEC_STARTED
     #undef COMM_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

 #elif defined (COMM_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED
     #undef  COMM_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (COMM_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_16BIT_SEC_STARTED
     #undef COMM_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif

 #elif defined (COMM_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  COMM_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (COMM_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef COMM_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (COMM_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  COMM_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
  #endif
#elif defined (COMM_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  COMM_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
/*****************Varible sections***************************/
/* VAR NOINIT sections */
#elif defined (COMM_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  COMM_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (COMM_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  COMM_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (COMM_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  COMM_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (COMM_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  COMM_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

 #elif defined (COMM_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  COMM_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (COMM_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  COMM_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (COMM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  COMM_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define  DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
 /********************* VAR ZERO INIT sections*********** */ 
#elif defined (COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

/* VAR NVRAM sections */
   
#elif defined (COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif
/* Postbuild CFG CONST sections */

/* Root pointer to postbuild data */
#elif defined (COMM_START_SEC_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  COMM_START_SEC_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (COMM_STOP_SEC_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  COMM_STOP_SEC_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
/**********************************************************************************************************************
 *  COMM END
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  CanSM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#elif defined (CANSM_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  CANSM_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (CANSM_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  CANSM_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined  (CANSM_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  CANSM_START_SEC_APPL_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (CANSM_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CANSM_STOP_SEC_APPL_CODE
     #undef  APPL_CODE_SEC_STARTED
     #define DEFAULT_STOP_SEC_CODE
   #endif
 /*******  CONST sections  ********************************************************************************************/  
/* CONST sections */
#elif defined (CANSM_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  CANSM_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (CANSM_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_8BIT_SEC_STARTED
     #undef CANSM_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

 #elif defined (CANSM_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED
     #undef  CANSM_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (CANSM_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_16BIT_SEC_STARTED
     #undef CANSM_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif

 #elif defined (CANSM_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  CANSM_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (CANSM_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef CANSM_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif
   
/* FAST CONST sections */
   
/* Postbuild CFG CONST sections */

/* Root pointer to postbuild data */
#elif defined (CANSM_START_SEC_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANSM_START_SEC_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (CANSM_STOP_SEC_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANSM_STOP_SEC_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
/* Root table for postbuild data */
 #elif defined (CANSM_START_SEC_PBCFG)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANSM_START_SEC_PBCFG
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (CANSM_STOP_SEC_PBCFG)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANSM_STOP_SEC_PBCFG
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
/*****************Varible sections***************************/
/* VAR NOINIT sections */
#elif defined (CANSM_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  CANSM_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (CANSM_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  CANSM_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define  DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
 /********************* VAR ZERO INIT sections*********** */ 
#elif defined (CANSM_START_SEC_VAR_ZERO_INIT_8BIT)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  CANSM_START_SEC_VAR_ZERO_INIT_8BIT
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif
/**********************************************************************************************************************
 *  CanSM END
 *********************************************************************************************************************/
/***************************DCM***************************************************/

/******************code******************/
   
#elif defined (DCM_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  DCM_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (DCM_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  DCM_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (DCM_APPL_START_SEC_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  DCM_APPL_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (DCM_APPL_STOP_SEC_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  DCM_APPL_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
/*****CONST************/
#elif defined (DCM_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  DCM_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (DCM_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_8BIT_SEC_STARTED
     #undef DCM_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

 #elif defined (DCM_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED
     #undef  DCM_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (DCM_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_16BIT_SEC_STARTED
     #undef DCM_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif

 #elif defined (DCM_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  DCM_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (DCM_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef DCM_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif
   
 #elif defined (DCM_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  DCM_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (DCM_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_UNSPECIFIED_SEC_STARTED
     #undef DCM_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif   

/************NOINIT VARIBLE************/ 
  
 #elif defined  (DCM_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  DCM_START_SEC_VAR_NOINIT_8BIT
     #define  DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (DCM_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  DCM_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif 

 #elif defined  (DCM_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  DCM_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (DCM_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  DCM_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif 
   
 #elif defined  (DCM_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  DCM_START_SEC_VAR_NOINIT_32BIT
     #define  DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (DCM_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  DCM_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif 
   
 #elif defined  (DCM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  DCM_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (DCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  DCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED

   #endif 
 /* vars saved in non volatile memory */
 #elif defined  (DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif 
 

   
/** DEM ***************************************************************************/

                                               

 /*****************************CODE SECTIONS**********************/
#elif defined (DEM_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  DEM_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (DEM_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  DEM_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
/* vars initialized by startup code */
#elif defined  (DEM_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  DEM_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (DEM_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DEM_STOP_SEC_VAR_8BIT
     #undef  VAR_8BIT_SEC_STARTED
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

   #elif defined  (DEM_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  DEM_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (DEM_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  DEM_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif
 /* never initialized vars with high number of accesses */
 #elif defined  (DEM_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  DEM_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (DEM_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  DEM_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

  #elif defined  (DEM_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  DEM_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (DEM_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  DEM_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

  #elif defined  (DEM_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  DEM_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (DEM_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  DEM_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

/* never initialized vars */
 #elif defined  (DEM_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  DEM_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (DEM_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  DEM_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif 

 #elif defined  (DEM_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  DEM_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (DEM_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  DEM_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif 
   
 #elif defined  (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif 
 /* vars saved in non volatile memory */
 #elif defined  (DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif 
 
/* global or static constants */
#elif defined (DEM_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  DEM_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (DEM_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_8BIT_SEC_STARTED
     #undef DEM_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

 #elif defined (DEM_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef DEM_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (DEM_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef DEM_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (DEM_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  DEM_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (DEM_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  DEM_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
/* global or static constants (linktime) */
#elif defined (DEM_START_SEC_CONST_LCFG)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  DEM_START_SEC_CONST_LCFG
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (DEM_STOP_SEC_CONST_LCFG)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  DEM_STOP_SEC_CONST_LCFG
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
 /* global or static constants (postbuild) */
   
#elif defined (DEM_START_SEC_PBCONST_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  DEM_START_SEC_PBCONST_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (DEM_STOP_SEC_PBCONST_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  DEM_STOP_SEC_PBCONST_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
   #elif defined (DEM_START_SEC_PBCONST)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  DEM_START_SEC_PBCONST
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (DEM_STOP_SEC_PBCONST)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  DEM_STOP_SEC_PBCONST
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
/** End of DEM *******************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* CAN driver start MemMap.inc                                                                                       */
/*-------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------- Code ---------------------------------------------------------------------------*/
#elif defined (CAN_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  CAN_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (CAN_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  CAN_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined  (CAN_START_SEC_CODE_APPL)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  CAN_START_SEC_CODE_APPL
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (CAN_STOP_SEC_CODE_APPL)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  CAN_STOP_SEC_CODE_APPL
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (CAN_START_SEC_STATIC_CODE)
   #ifdef STATIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define STATIC_CODE_SEC_STARTED
     #undef  CAN_START_SEC_STATIC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (CAN_STOP_SEC_STATIC_CODE)
   #ifndef STATIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  STATIC_CODE_SEC_STARTED
     #undef  CAN_STOP_SEC_STATIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/*---------------------------------- Const --------------------------------------------------------------------------*/

#elif defined (CAN_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  CAN_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (CAN_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_8BIT_SEC_STARTED
     #undef CAN_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

 #elif defined (CAN_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED
     #undef  CAN_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (CAN_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_16BIT_SEC_STARTED
     #undef CAN_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif

 #elif defined (CAN_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  CAN_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (CAN_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef CAN_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (CAN_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CAN_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (CAN_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CAN_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (CAN_START_SEC_PBCFG)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CAN_START_SEC_PBCFG
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (CAN_STOP_SEC_PBCFG)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CAN_STOP_SEC_PBCFG
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
#elif defined (CAN_START_SEC_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CAN_START_SEC_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (CAN_STOP_SEC_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CAN_STOP_SEC_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

/*---------------------------------- RAM ----------------------------------------------------------------------------*/

 #elif defined  (CAN_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif 

 #elif defined  (CAN_START_SEC_VAR_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  CAN_START_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (CAN_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif 
/*-------------------------------------------------------------------------------------------------------------------*/
/* End CAN driver end MemMap.inc                                                                                         */
/*-------------------------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#elif defined (PDUR_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  PDUR_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (PDUR_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  PDUR_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
/*******  CONST sections  ********************************************************************************************/
   
/* CONST sections */
   
#elif defined (PDUR_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  PDUR_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (PDUR_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_8BIT_SEC_STARTED
     #undef PDUR_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

 #elif defined (PDUR_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED
     #undef  PDUR_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (PDUR_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_16BIT_SEC_STARTED
     #undef PDUR_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif

 #elif defined (PDUR_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef PDUR_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (PDUR_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef PDUR_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (PDUR_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  PDUR_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (PDUR_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  PDUR_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
/* Root table for postbuild data */

 #elif defined (PDUR_START_SEC_PBCFG)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  PDUR_START_SEC_PBCFG
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (PDUR_STOP_SEC_PBCFG)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  PDUR_STOP_SEC_PBCFG
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
#elif defined (PDUR_START_SEC_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  PDUR_START_SEC_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (PDUR_STOP_SEC_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  PDUR_STOP_SEC_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif  
/*****************Varible sections***************************/

/* VAR INIT sections */
#elif defined (PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
     #define  DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
   
/* VAR NOINIT sections */

#elif defined (PDUR_START_SEC_VAR_NOINIT_BOOLEAN)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  PDUR_START_SEC_VAR_NOINIT_BOOLEAN
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif
   
#elif defined (PDUR_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  PDUR_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (PDUR_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  PDUR_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define  DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
 
/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/  


/*-------------------------------------------------------------------------------------------------------------------*/
/* CANIF                                                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/

/* Code */
#elif defined (CANIF_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  CANIF_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (CANIF_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  CANIF_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined  (CANIF_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  CANIF_START_SEC_APPL_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (CANIF_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  CANIF_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/*---------------------------------- Const --------------------------------------------------------------------------*/

#elif defined (CANIF_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  CANIF_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (CANIF_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_8BIT_SEC_STARTED
     #undef CANIF_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

 #elif defined (CANIF_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  CANIF_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (CANIF_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef CANIF_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (CANIF_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (CANIF_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (CANIF_START_SEC_PBCFG)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_START_SEC_PBCFG
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (CANIF_STOP_SEC_PBCFG)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_STOP_SEC_PBCFG
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
#elif defined (CANIF_START_SEC_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_START_SEC_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (CANIF_STOP_SEC_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_STOP_SEC_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

/* Var noinit unspecified */
   
 #elif defined  (CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif 
   
/* Var zero init unspecified */
   
 #elif defined  (CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif 

/* Var init unspecified */

 #elif defined  (CANIF_START_SEC_VAR_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_START_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif 
/*-------------------------------------------------------------------------------------------------------------------*/
/* CANIF                                                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------------------------*/
/* trcv                                                                                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

 /*mapped to default code section*/
   
#elif defined (CANTRCV_30_TJA1145_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  CANTRCV_30_TJA1145_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (CANTRCV_30_TJA1145_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  CANTRCV_30_TJA1145_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
   
   
 /*default const section */
   
#elif defined (CANTRCV_30_TJA1145_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTRCV_30_TJA1145_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (CANTRCV_30_TJA1145_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTRCV_30_TJA1145_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif


/* Var noinit unspecified */
   
 #elif defined  (CANTRCV_30_TJA1145_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CANTRCV_30_TJA1145_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (CANTRCV_30_TJA1145_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CANTRCV_30_TJA1145_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif 
   
 #elif defined (CANTRCV_30_TJA1145_START_SEC_PBCFG)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTRCV_30_TJA1145_START_SEC_PBCFG
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (CANTRCV_30_TJA1145_STOP_SEC_PBCFG)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTRCV_30_TJA1145_STOP_SEC_PBCFG
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
#elif defined (CANTRCV_30_TJA1145_START_SEC_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTRCV_30_TJA1145_START_SEC_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (CANTRCV_30_TJA1145_STOP_SEC_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTRCV_30_TJA1145_STOP_SEC_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif  

/**********************************************************************************************************************
 *  END OF cantrcv
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Com START 
 *********************************************************************************************************************/
/*******  CODE sections **********************************************************************************************/

#elif defined (COM_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  COM_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (COM_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  COM_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined  (COM_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  COM_START_SEC_APPL_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (COM_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  COM_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/*---------------------------------- Const --------------------------------------------------------------------------*/

 #elif defined (COM_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  COM_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (COM_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef COM_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (COM_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  COM_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (COM_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  COM_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (COM_START_SEC_PBCFG)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  COM_START_SEC_PBCFG
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (COM_STOP_SEC_PBCFG)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  COM_STOP_SEC_PBCFG
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
#elif defined (COM_START_SEC_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  COM_START_SEC_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (COM_STOP_SEC_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  COM_STOP_SEC_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

/*******  VAR sections  **********************************************************************************************/

   
/* Var INIT SECTIONS */
   
 #elif defined  (COM_START_SEC_VAR_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  COM_START_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (COM_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  COM_STOP_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif 

/* Var  NOINIT SECTIONS*/
   
#elif defined (COM_START_SEC_VAR_NOINIT_BOOLEAN)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef COM_START_SEC_VAR_NOINIT_BOOLEAN
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (COM_STOP_SEC_VAR_NOINIT_BOOLEAN)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  COM_STOP_SEC_VAR_NOINIT_BOOLEAN
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif
   
#elif defined (COM_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  COM_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (COM_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  COM_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (COM_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  COM_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (COM_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  COM_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif   

#elif defined (COM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else 
     #define  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef   COM_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define  DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif   

/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANNM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#elif defined (CANNM_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  CANNM_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (CANNM_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  CANNM_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
   
/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
   
#elif defined (CANNM_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  CANNM_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (CANNM_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_8BIT_SEC_STARTED
     #undef CANNM_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif


 #elif defined (CANNM_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  CANNM_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (CANNM_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef CANNM_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (CANNM_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (CANNM_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
/* Postbuild CFG CONST sections */
   
#elif defined (CANNM_START_SEC_PBCFG)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_START_SEC_PBCFG
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (CANNM_STOP_SEC_PBCFG)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_STOP_SEC_PBCFG
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
#elif defined (CANNM_START_SEC_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_START_SEC_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (CANNM_STOP_SEC_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_STOP_SEC_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
/*****************Varible sections***************************/
   
/* VAR NOINIT sections */
   
#elif defined (CANNM_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  CANNM_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (CANNM_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  CANNM_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (CANNM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define  DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (CANNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
   
/* VAR FAST NOINIT sections */
   
#elif defined (CANNM_START_SEC_VAR_FAST_NOINIT_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  CANNM_START_SEC_VAR_FAST_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (CANNM_STOP_SEC_VAR_FAST_NOINIT_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  CANNM_STOP_SEC_VAR_FAST_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (CANNM_START_SEC_VAR_FAST_NOINIT_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  CANNM_START_SEC_VAR_FAST_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (CANNM_STOP_SEC_VAR_FAST_NOINIT_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  CANNM_STOP_SEC_VAR_FAST_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (CANNM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (CANNM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
   
/* VAR FAST ZERO INIT sections */

#elif defined (CANNM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (CANNM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  CANNM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

/**********************************************************************************************************************
 *  CANNM END
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  CANTP START
 *********************************************************************************************************************/
/*******  CODE sections **********************************************************************************************/

#elif defined (CANTP_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  CANTP_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (CANTP_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  CANTP_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
/******************** CONST section **************************************************************/

#elif defined (CANTP_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED
     #undef  CANTP_START_SEC_CONST_16BIT 
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (CANTP_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_16BIT_SEC_STARTED
     #undef CANTP_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif


 #elif defined (CANTP_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  CANTP_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (CANTP_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef CANTP_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

/* Postbuild CFG CONST sections */
   
#elif defined (CANTP_START_SEC_CONST_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTP_START_SEC_CONST_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (CANTP_STOP_SEC_CONST_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTP_STOP_SEC_CONST_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
#elif defined (CANTP_START_SEC_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTP_START_SEC_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (CANTP_STOP_SEC_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTP_STOP_SEC_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

   #elif defined (CANTP_START_SEC_CONST_PBCFG)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTP_START_SEC_CONST_PBCFG
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (CANTP_STOP_SEC_CONST_PBCFG)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  CANTP_STOP_SEC_CONST_PBCFG
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

/**************************************VAR SECTIONS********************************************************/
#elif defined (CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define  DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (CANTP_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  CANTP_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (CANTP_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  CANTP_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif
   
#elif defined (CANTP_START_SEC_VAR_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  CANTP_START_SEC_VAR_INIT_UNSPECIFIED
     #define  DEFAULT_START_SEC_VAR_INIT_UNSPECIFIED
   #endif
#elif defined (CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_INIT_UNSPECIFIED
   #endif
   
/**********************************************************************************************************************
 *  CANTP END
 *********************************************************************************************************************/

   
/**********************************************************************************************************************
 *  NM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#elif defined (NM_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  NM_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (NM_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  NM_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
   
/*******  CONST sections  ********************************************************************************************/
   
#elif defined (NM_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  NM_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (NM_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_8BIT_SEC_STARTED
     #undef NM_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif


 #elif defined (NM_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  NM_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (NM_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef NM_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (NM_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  NM_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (NM_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  NM_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   

/*****************Varible sections***************************/
   
/* VAR NOINIT sections */
   
#elif defined (NM_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  NM_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (NM_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  NM_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif
   
/* VAR FAST NOINIT sections */
   
#elif defined (NM_START_SEC_VAR_FAST_NOINIT_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  NM_START_SEC_VAR_FAST_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (NM_STOP_SEC_VAR_FAST_NOINIT_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  NM_STOP_SEC_VAR_FAST_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (NM_START_SEC_VAR_FAST_NOINIT_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  NM_START_SEC_VAR_FAST_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (NM_STOP_SEC_VAR_FAST_NOINIT_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  NM_STOP_SEC_VAR_FAST_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (NM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  NM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (NM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  NM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
   
/* VAR FAST ZERO INIT sections */

#elif defined (NM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  NM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (NM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  NM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
   
/**********************************************************************************************************************
 *  NM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BSWM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#elif defined (BSWM_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  BSWM_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (BSWM_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  BSWM_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
   
/*******  CONST sections  ********************************************************************************************/
   
#elif defined (BSWM_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  BSWM_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (BSWM_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  BSWM_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif
   
#elif defined (BSWM_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  BSWM_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (BSWM_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  BSWM_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
 #elif defined (BSWM_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED
     #undef  BSWM_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (BSWM_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_32BIT_SEC_STARTED
     #undef BSWM_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

/*****************Varible sections***************************/
   
/* VAR NOINIT sections */
   
#elif defined (BSWM_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  BSWM_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (BSWM_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  BSWM_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (BSWM_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  BSWM_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (BSWM_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  BSWM_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif   

#elif defined (BSWM_START_SEC_VAR_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  BSWM_START_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif   
/**********************************************************************************************************************
 *  BSWM END
 *********************************************************************************************************************/
   
/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#elif defined (ECUM_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  ECUM_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (ECUM_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  ECUM_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (ECUM_START_SEC_CODE_SET_BOOT_TARGET)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  ECUM_START_SEC_CODE_SET_BOOT_TARGET
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (ECUM_STOP_SEC_CODE_SET_BOOT_TARGET)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
     #define DEFAULT_STOP_SEC_CODE
   #endif
   
#elif defined (ECUM_START_SEC_CODE_GET_BOOT_TARGET)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  ECUM_START_SEC_CODE_GET_BOOT_TARGET
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (ECUM_STOP_SEC_CODE_GET_BOOT_TARGET)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
     #define DEFAULT_STOP_SEC_CODE
   #endif
   
   
/*******  CONST sections  ********************************************************************************************/
   
#elif defined (ECUM_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED
     #undef  ECUM_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (ECUM_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #undef CONST_8BIT_SEC_STARTED
     #undef  ECUM_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif	 
#elif defined (ECUM_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #define  CONST_UNSPECIFIED_SEC_STARTED
     #undef  ECUM_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (ECUM_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_UNSPECIFIED_SEC_STARTED
     #undef ECUM_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

/* Root table for postbuild data */
#elif defined (ECUM_START_SEC_CONST_PBCFG_ROOT)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #define  CONST_UNSPECIFIED_SEC_STARTED
     #undef  ECUM_START_SEC_CONST_PBCFG_ROOT
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (ECUM_STOP_SEC_CONST_PBCFG_ROOT)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_UNSPECIFIED_SEC_STARTED
     #undef ECUM_STOP_SEC_CONST_PBCFG_ROOT
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
#elif defined (ECUM_START_SEC_CONST_PBCFG)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #define  CONST_UNSPECIFIED_SEC_STARTED
     #undef  ECUM_START_SEC_CONST_PBCFG
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (ECUM_STOP_SEC_CONST_PBCFG)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_UNSPECIFIED_SEC_STARTED
     #undef ECUM_STOP_SEC_CONST_PBCFG
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
/*****************Varible sections***************************/

/* VAR INIT sections */
   
#elif defined (ECUM_START_SEC_VAR_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  ECUM_START_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif
   
/* VAR NOINIT sections */
   
#elif defined (ECUM_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  ECUM_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (ECUM_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  ECUM_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (ECUM_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  ECUM_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (ECUM_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  ECUM_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif   

/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM END
 *********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* VStdLib start MemMap.inc                                                                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------- Code ---------------------------------------------------------------------------*/

#elif defined (VSTDLIB_START_SEC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  VSTDLIB_START_SEC_CODE
     #define DEFAULT_START_SEC_CODE
   #endif
#elif defined (VSTDLIB_STOP_SEC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  VSTDLIB_STOP_SEC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
   
/*******  CONST sections  ********************************************************************************************/
   
	 
#elif defined (VSTDLIB_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #define  CONST_UNSPECIFIED_SEC_STARTED
     #undef  VSTDLIB_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif   
#elif defined (VSTDLIB_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef CONST_UNSPECIFIED_SEC_STARTED
     #undef VSTDLIB_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
/*---------------------------------- RAM ----------------------------------------------------------------------------*/

  
#elif defined (VSTDLIB_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  VSTDLIB_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (VSTDLIB_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  VSTDLIB_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif
/*-------------------------------------------------------------------------------------------------------------------*/
/* VStdLib end MemMap.inc                                                                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

  
/* -------------------------------------------------------------------------- */
/*             PORT                                                           */
/* -------------------------------------------------------------------------- */

#elif defined (PORT_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (PORT_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (PORT_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (PORT_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (PORT_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (PORT_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (PORT_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (PORT_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (PORT_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (PORT_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (PORT_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (PORT_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  PORT_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (PORT_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (PORT_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  PORT_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (PORT_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (PORT_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  PORT_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (PORT_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  PORT_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (PORT_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  PORT_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (PORT_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  PORT_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".PORT_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (PORT_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  PORT_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (PORT_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  PORT_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (PORT_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (PORT_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  PORT_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (PORT_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (PORT_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  PORT_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (PORT_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
 
#elif defined (PORT_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  PORT_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (PORT_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  PORT_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (PORT_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  PORT_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (PORT_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  PORT_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (PORT_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".PORT_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (PORT_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  PORT_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".PORT_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (PORT_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  PORT_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (PORT_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  PORT_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".PORT_PUBLIC_CODE_ROM"
   #endif
#elif defined (PORT_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  PORT_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (PORT_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  PORT_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".PORT_PRIVATE_CODE_ROM"
   #endif
#elif defined (PORT_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  PORT_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (PORT_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  PORT_START_SEC_APPL_CODE
     #pragma ghs section text=".PORT_APPL_CODE_ROM"
   #endif
#elif defined (PORT_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  PORT_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/* -------------------------------------------------------------------------- */
/*             DIO                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (DIO_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (DIO_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (DIO_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (DIO_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (DIO_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (DIO_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (DIO_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (DIO_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (DIO_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (DIO_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (DIO_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (DIO_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  DIO_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (DIO_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (DIO_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  DIO_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (DIO_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (DIO_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  DIO_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (DIO_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (DIO_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  DIO_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (DIO_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  DIO_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (DIO_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  DIO_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".DIO_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (DIO_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  DIO_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (DIO_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  DIO_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (DIO_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (DIO_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  DIO_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (DIO_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (DIO_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  DIO_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (DIO_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
 
#elif defined (DIO_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  DIO_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (DIO_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  DIO_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (DIO_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  DIO_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (DIO_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  DIO_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (DIO_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".DIO_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (DIO_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  DIO_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".DIO_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (DIO_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  DIO_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (DIO_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  DIO_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".DIO_PUBLIC_CODE_ROM"
   #endif
#elif defined (DIO_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  DIO_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (DIO_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  DIO_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".DIO_PRIVATE_CODE_ROM"
   #endif
#elif defined (DIO_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  DIO_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (DIO_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  DIO_START_SEC_APPL_CODE
     #pragma ghs section text=".DIO_APPL_CODE_ROM"
   #endif
#elif defined (DIO_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  DIO_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/* -------------------------------------------------------------------------- */
/*             PWM                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (PWM_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (PWM_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (PWM_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (PWM_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (PWM_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (PWM_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (PWM_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (PWM_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  PWM_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (PWM_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  PWM_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (PWM_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  PWM_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  PWM_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  PWM_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".PWM_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (PWM_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (PWM_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  PWM_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (PWM_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (PWM_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  PWM_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (PWM_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (PWM_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  PWM_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (PWM_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
 
#elif defined (PWM_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  PWM_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (PWM_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (PWM_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  PWM_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (PWM_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".PWM_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  PWM_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".PWM_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (PWM_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  PWM_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".PWM_PUBLIC_CODE_ROM"
   #endif
#elif defined (PWM_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  PWM_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (PWM_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  PWM_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".PWM_PRIVATE_CODE_ROM"
   #endif
#elif defined (PWM_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  PWM_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (PWM_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  PWM_START_SEC_APPL_CODE
     #pragma ghs section text=".PWM_APPL_CODE_ROM"
   #endif
#elif defined (PWM_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  PWM_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/* -------------------------------------------------------------------------- */
/*             SPI                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (SPI_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (SPI_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (SPI_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (SPI_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (SPI_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (SPI_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (SPI_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (SPI_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (SPI_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (SPI_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (SPI_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (SPI_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  SPI_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (SPI_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (SPI_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  SPI_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (SPI_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (SPI_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (SPI_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  SPI_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (SPI_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  SPI_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (SPI_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  SPI_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".SPI_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (SPI_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  SPI_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (SPI_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  SPI_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (SPI_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (SPI_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  SPI_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (SPI_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (SPI_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  SPI_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (SPI_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
 
#elif defined (SPI_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  SPI_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (SPI_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  SPI_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (SPI_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  SPI_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (SPI_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  SPI_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (SPI_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".SPI_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (SPI_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  SPI_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".SPI_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (SPI_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  SPI_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (SPI_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  SPI_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".SPI_PUBLIC_CODE_ROM"
   #endif
#elif defined (SPI_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  SPI_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (SPI_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  SPI_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".SPI_PRIVATE_CODE_ROM"
   #endif
#elif defined (SPI_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  SPI_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (SPI_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  SPI_START_SEC_APPL_CODE
     #pragma ghs section text=".SPI_APPL_CODE_ROM"
   #endif
#elif defined (SPI_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  SPI_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/* -------------------------------------------------------------------------- */
/*             ADC                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (ADC_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (ADC_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (ADC_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (ADC_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (ADC_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (ADC_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (ADC_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (ADC_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (ADC_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (ADC_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (ADC_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (ADC_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  ADC_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (ADC_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (ADC_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  ADC_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (ADC_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (ADC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (ADC_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  ADC_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (ADC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  ADC_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".ADC_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (ADC_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  ADC_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (ADC_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  ADC_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (ADC_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (ADC_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  ADC_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (ADC_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (ADC_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  ADC_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (ADC_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
 
#elif defined (ADC_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  ADC_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (ADC_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  ADC_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (ADC_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  ADC_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (ADC_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  ADC_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (ADC_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".ADC_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (ADC_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  ADC_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".ADC_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (ADC_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  ADC_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (ADC_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  ADC_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".ADC_PUBLIC_CODE_ROM"
   #endif
#elif defined (ADC_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  ADC_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (ADC_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  ADC_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".ADC_PRIVATE_CODE_ROM"
   #endif
#elif defined (ADC_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  ADC_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (ADC_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  ADC_START_SEC_APPL_CODE
     #pragma ghs section text=".ADC_APPL_CODE_ROM"
   #endif
#elif defined (ADC_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  ADC_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

/* -------------------------------------------------------------------------- */
/*             ICU                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (ICU_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (ICU_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (ICU_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (ICU_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (ICU_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (ICU_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (ICU_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (ICU_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (ICU_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (ICU_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (ICU_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (ICU_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  ICU_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (ICU_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (ICU_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  ICU_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (ICU_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (ICU_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  ICU_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (ICU_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (ICU_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  ICU_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (ICU_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  ICU_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (ICU_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  ICU_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".ICU_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (ICU_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  ICU_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (ICU_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  ICU_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (ICU_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (ICU_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  ICU_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (ICU_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (ICU_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  ICU_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (ICU_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
 
#elif defined (ICU_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  ICU_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (ICU_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  ICU_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (ICU_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  ICU_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (ICU_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  ICU_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (ICU_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".ICU_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (ICU_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  ICU_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".ICU_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (ICU_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  ICU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (ICU_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  ICU_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".ICU_PUBLIC_CODE_ROM"
   #endif
#elif defined (ICU_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  ICU_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (ICU_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  ICU_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".ICU_PRIVATE_CODE_ROM"
   #endif
#elif defined (ICU_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  ICU_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (ICU_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  ICU_START_SEC_APPL_CODE
     #pragma ghs section text=".ICU_APPL_CODE_ROM"
   #endif
#elif defined (ICU_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  ICU_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
/* ---------------------------------------------------------------------------*/
/*                   FlexRay Driver                                           */
/* ---------------------------------------------------------------------------*/
#elif defined (FR_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (FR_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (FR_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (FR_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (FR_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (FR_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (FR_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (FR_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (FR_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (FR_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (FR_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (FR_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  FR_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (FR_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (FR_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  FR_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (FR_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (FR_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  FR_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

   #elif defined (FR_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FR_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#elif defined (FR_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FR_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   
#elif defined (FR_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  FR_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (FR_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  FR_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (FR_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  FR_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".FR_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (FR_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  FR_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (FR_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  FR_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (FR_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  FR_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (FR_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  FR_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (FR_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  FR_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (FR_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  FR_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (FR_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  FR_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif
 
#elif defined (FR_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  FR_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (FR_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  FR_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (FR_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  FR_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (FR_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  FR_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif
   
#elif defined (FR_START_SEC_CONFIG_CONST_UNSPECIFIED)
   #undef      FR_START_SEC_CONFIG_CONST_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section rosdata=".FR_CFG_CONST_UNSPEC"
#elif defined (FR_STOP_SEC_CONFIG_CONST_UNSPECIFIED)
   #undef      FR_STOP_SEC_CONFIG_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   
#elif defined (FR_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
   #undef      FR_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section rosdata=".FR_DBTOC_CFG_CONST_UNSPEC"
#elif defined (FR_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
   #undef      FR_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
    #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED

#elif defined (FR_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  FR_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".FR_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (FR_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  FR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (FR_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED 
     #undef  FR_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".FR_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (FR_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  FR_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (FR_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  FR_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".FR_PUBLIC_CODE_ROM"
   #endif
#elif defined (FR_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  FR_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (FR_START_SEC_CODE)
   #undef      FR_START_SEC_CODE
   #pragma ghs section text=".FR_CODE_ROM"
#elif defined (FR_STOP_SEC_CODE)
   #undef      FR_STOP_SEC_CODE
   #pragma ghs section text=default 

#elif defined (FR_START_SEC_STATIC_CODE)
   #undef      FR_START_SEC_STATIC_CODE
   #pragma ghs section text=".FR_STATIC_CODE_ROM"
#elif defined (FR_STOP_SEC_STATIC_CODE)
   #undef      FR_STOP_SEC_STATIC_CODE
   #pragma ghs section text=default  

#elif defined (FR_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  FR_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".FR_PRIVATE_CODE_ROM"
   #endif
#elif defined (FR_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  FR_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
 
#elif defined (FR_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  FR_START_SEC_APPL_CODE
     #pragma ghs section text=".FR_APPL_CODE_ROM"
   #endif
#elif defined (FR_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  FR_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif  

/* ---------------------------------------------------------------------------*/
/*                   FEE                                                      */
/* ---------------------------------------------------------------------------*/

#elif defined (FEE_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  FEE_START_SEC_VAR_1BIT
     #pragma ghs startsda
     #pragma ghs section sbss=".EEL_Data"
   #endif
#elif defined (FEE_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  FEE_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (FEE_START_SEC_VAR_NOINIT_1BIT)
   #ifdef   VAR_NOINIT_1BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_NOINIT_1BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_NOINIT_1BIT
    #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef  VAR_NOINIT_1BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef   FEE_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (FEE_START_SEC_VAR_FAST_1BIT)
   #ifdef  VAR_FAST_1BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_FAST_1BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_FAST_1BIT
    #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_FAST_1BIT)
   #ifndef  VAR_FAST_1BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_FAST_1BIT
    #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (FEE_START_SEC_VAR_8BIT)
   #ifdef  VAR_8BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_8BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_8BIT
    #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_8BIT)
   #ifndef  VAR_8BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_8BIT
    #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (FEE_START_SEC_VAR_NOINIT_8BIT)
   #ifdef  VAR_NOINIT_8BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else   
    #define VAR_NOINIT_8BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef  VAR_NOINIT_8BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_NOINIT_8BIT
    #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (FEE_START_SEC_VAR_FAST_8BIT)
   #ifdef  VAR_FAST_8BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_FAST_8BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_FAST_8BIT
    #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_FAST_8BIT)
   #ifndef  VAR_FAST_8BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_FAST_8BIT
    #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (FEE_START_SEC_VAR_16BIT)
   #ifdef  VAR_16BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_16BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_16BIT
    #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_16BIT)
   #ifndef  VAR_16BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_16BIT
    #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (FEE_START_SEC_VAR_NOINIT_16BIT)
   #ifdef  VAR_NOINIT_16BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_NOINIT_16BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_NOINIT_16BIT
    #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef  VAR_NOINIT_16BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_NOINIT_16BIT
    #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (FEE_START_SEC_VAR_FAST_16BIT)
   #ifdef  VAR_FAST_16BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_FAST_16BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_FAST_16BIT
    #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_FAST_16BIT)
   #ifndef  VAR_FAST_16BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_FAST_16BIT
    #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (FEE_START_SEC_VAR_32BIT)
   #ifdef  VAR_32BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_32BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_32BIT
    #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_32BIT)
   #ifndef  VAR_32BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_32BIT
    #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (FEE_START_SEC_VAR_NOINIT_32BIT)
   #ifdef  VAR_NOINIT_32BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_NOINIT_32BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_NOINIT_32BIT
    #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef  VAR_NOINIT_32BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_NOINIT_32BIT
    #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (FEE_START_SEC_VAR_FAST_32BIT)
   #ifdef  VAR_FAST_32BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_FAST_32BIT_SEC_STARTED
    #undef  FEE_START_SEC_VAR_FAST_32BIT
    #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (FEE_STOP_SEC_VAR_FAST_32BIT)
   #ifndef  VAR_FAST_32BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_FAST_32BIT
    #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (FEE_START_SEC_VAR_UNSPECIFIED)
   #ifdef  VAR_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_UNSPECIFIED_SEC_STARTED
    #undef  FEE_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (FEE_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef  VAR_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_UNSPECIFIED
    #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (FEE_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
    #undef  FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
   
#elif defined (FEE_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef  VAR_FAST_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_FAST_UNSPECIFIED_SEC_STARTED
    #undef  FEE_START_SEC_VAR_FAST_UNSPECIFIED
    #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (FEE_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef  VAR_FAST_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
    #undef  FEE_STOP_SEC_VAR_FAST_UNSPECIFIED
    #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (FEE_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
    #undef  FEE_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
    #pragma ghs startsda
    #pragma ghs section sbss=".FEE_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (FEE_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
    #undef  FEE_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
    #pragma ghs section sbss=default
    #pragma ghs endsda
   #endif

#elif defined (FEE_START_SEC_CONST_1BIT)
   #ifdef  CONST_1BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define CONST_1BIT_SEC_STARTED
    #undef  FEE_START_SEC_CONST_1BIT
    #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (FEE_STOP_SEC_CONST_1BIT)
   #ifndef  CONST_1BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_CONST_1BIT
    #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (FEE_START_SEC_CONST_8BIT)
   #ifdef  CONST_8BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define CONST_8BIT_SEC_STARTED
    #undef  FEE_START_SEC_CONST_8BIT
    #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (FEE_STOP_SEC_CONST_8BIT)
   #ifndef  CONST_8BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_CONST_8BIT
    #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (FEE_START_SEC_CONST_16BIT)
   #ifdef  CONST_16BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define CONST_16BIT_SEC_STARTED
    #undef  FEE_START_SEC_CONST_16BIT
    #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (FEE_STOP_SEC_CONST_16BIT)
   #ifndef  CONST_16BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
    #undef  FEE_STOP_SEC_CONST_16BIT
    #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif

#elif defined (FEE_START_SEC_CONST_32BIT)
   #ifdef  CONST_32BIT_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define CONST_32BIT_SEC_STARTED
   #undef  FEE_START_SEC_CONST_32BIT
   #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (FEE_STOP_SEC_CONST_32BIT)
   #ifndef  CONST_32BIT_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
   #undef  FEE_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (FEE_START_SEC_CONST_UNSPECIFIED)
   #ifdef  CONST_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define CONST_UNSPECIFIED_SEC_STARTED
    #undef  FEE_START_SEC_CONST_UNSPECIFIED
    #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (FEE_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef  CONST_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
    #undef  FEE_STOP_SEC_CONST_UNSPECIFIED
    #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (FEE_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #undef  FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #pragma ghs startsda
    #pragma ghs section rosdata=".FEE_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #undef  FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (FEE_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED
    #undef  FEE_START_SEC_DBTOC_DATA_UNSPECIFIED
    #pragma ghs startsda
    #pragma ghs section rosdata=".FEE_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (FEE_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
    #undef  FEE_STOP_SEC_DBTOC_DATA_UNSPECIFIED
    #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (FEE_START_SEC_PUBLIC_CODE)
   #ifdef  PUBLIC_CODE_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define PUBLIC_CODE_SEC_STARTED
    #undef  FEE_START_SEC_PUBLIC_CODE
    #pragma ghs section text=".FEE_PUBLIC_CODE_ROM"
   #endif
#elif defined (FEE_STOP_SEC_PUBLIC_CODE)
   #ifndef  PUBLIC_CODE_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
    #undef  FEE_STOP_SEC_PUBLIC_CODE
    #define DEFAULT_STOP_SEC_CODE
   #endif
   
#elif defined (FEE_START_SEC_PRIVATE_CODE)
   #ifdef  PRIVATE_CODE_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define PRIVATE_CODE_SEC_STARTED
    #undef  FEE_START_SEC_PRIVATE_CODE
    #pragma ghs section text=".FEE_PRIVATE_CODE_ROM"
   #endif
#elif defined (FEE_STOP_SEC_PRIVATE_CODE)
   #ifndef  PRIVATE_CODE_SEC_STARTED
    #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
    #undef  FEE_STOP_SEC_PRIVATE_CODE
    #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (FEE_START_SEC_APPL_CODE)
   #ifdef  APPL_CODE_SEC_STARTED
    #error "Memory section is not stopped"
   #else
    #define APPL_CODE_SEC_STARTED
    #undef  FEE_START_SEC_APPL_CODE
    #pragma ghs section text=".FEE_APPL_CODE_ROM"
   #endif
#elif defined (FEE_STOP_SEC_APPL_CODE)
   #ifndef  APPL_CODE_SEC_STARTED
    #error "Memory section is not started"
   #else
    #undef  FEE_STOP_SEC_APPL_CODE
    #define DEFAULT_STOP_SEC_CODE
   #endif

/* -------------------------------------------------------------------------- */
/*             FLS                                                            */
/* -------------------------------------------------------------------------- */
#elif defined (FLS_START_SEC_VAR_1BIT)
   #ifdef VAR_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_1BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_1BIT   
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_1BIT)
   #ifndef VAR_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_1BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_1BIT
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif
   
#elif defined (FLS_START_SEC_VAR_NOINIT_1BIT)
   #ifdef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_1BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_NOINIT_1BIT)
   #ifndef VAR_NOINIT_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_1BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_NOINIT_1BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif	 


#elif defined (FLS_START_SEC_VAR_FAST_1BIT)
   #ifdef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_1BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_FAST_1BIT
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_FAST_1BIT)
   #ifndef VAR_FAST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_1BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_FAST_1BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

   	 
   #elif defined (FLS_START_SEC_VAR_8BIT)
   #ifdef VAR_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_8BIT
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_8BIT)
   #ifndef VAR_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_8BIT
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif   
	  

#elif defined (FLS_START_SEC_VAR_NOINIT_8BIT)
   #ifdef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_NOINIT_8BIT)
   #ifndef VAR_NOINIT_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_NOINIT_8BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

   
 #elif defined (FLS_START_SEC_VAR_FAST_8BIT)
   #ifdef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_FAST_8BIT
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_FAST_8BIT)
   #ifndef VAR_FAST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_FAST_8BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif  
   
 
#elif defined (FLS_START_SEC_VAR_16BIT)
   #ifdef VAR_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_16BIT
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_16BIT)
   #ifndef VAR_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_16BIT
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif
   
 #elif defined (FLS_START_SEC_VAR_NOINIT_16BIT)
   #ifdef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_NOINIT_16BIT)
   #ifndef VAR_NOINIT_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_NOINIT_16BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif
 
   
#elif defined (FLS_START_SEC_VAR_FAST_16BIT)
   #ifdef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_FAST_16BIT
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_FAST_16BIT)
   #ifndef VAR_FAST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_FAST_16BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif
   
#elif defined (FLS_START_SEC_VAR_32BIT)
   #ifdef VAR_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_32BIT
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_32BIT)
   #ifndef VAR_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_32BIT
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif
   

#elif defined (FLS_START_SEC_VAR_NOINIT_32BIT)
   #ifdef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_NOINIT_32BIT)
   #ifndef VAR_NOINIT_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_NOINIT_32BIT
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (FLS_START_SEC_VAR_FAST_32BIT)
   #ifdef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32BIT_SEC_STARTED
     #undef  FLS_START_SEC_VAR_FAST_32BIT
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_FAST_32BIT)
   #ifndef VAR_FAST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_FAST_32BIT
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

   #elif defined (FLS_START_SEC_VAR_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED 
     #undef  FLS_START_SEC_VAR_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (FLS_STOP_SEC_VAR_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (FLS_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  FLS_START_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (FLS_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
  

   #elif defined (FLS_START_SEC_VAR_FAST_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED 
     #undef  FLS_START_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (FLS_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_FAST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

 
#elif defined (FLS_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED 
     #undef  FLS_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".FLS_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (FLS_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif


#elif defined (FLS_START_SEC_CONST_1BIT)
   #ifdef CONST_1BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_1BIT_SEC_STARTED 
     #undef  FLS_START_SEC_CONST_1BIT
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (FLS_STOP_SEC_CONST_1BIT)
   #ifndef CONST_1BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_1BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_CONST_1BIT
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif  
 
   
#elif defined (FLS_START_SEC_CONST_8BIT)
   #ifdef CONST_8BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8BIT_SEC_STARTED 
     #undef  FLS_START_SEC_CONST_8BIT
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (FLS_STOP_SEC_CONST_8BIT)
   #ifndef CONST_8BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_CONST_8BIT
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif  
 
#elif defined (FLS_START_SEC_CONST_16BIT)
   #ifdef CONST_16BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16BIT_SEC_STARTED 
     #undef  FLS_START_SEC_CONST_16BIT
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (FLS_STOP_SEC_CONST_16BIT)
   #ifndef CONST_16BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_CONST_16BIT
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif  
      
 #elif defined (FLS_START_SEC_CONST_32BIT)
   #ifdef CONST_32BIT_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32BIT_SEC_STARTED 
     #undef  FLS_START_SEC_CONST_32BIT
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (FLS_STOP_SEC_CONST_32BIT)
   #ifndef CONST_32BIT_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32BIT_SEC_STARTED
     #undef  FLS_STOP_SEC_CONST_32BIT
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif  
   
#elif defined (FLS_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED 
     #undef  FLS_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (FLS_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (FLS_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs section text=".FLS_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CODE
   #endif   


#elif defined (FLS_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  FLS_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs section text=".FLS_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (FLS_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CODE
   #endif   

#elif defined (FLS_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  FLS_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".FLS_PUBLIC_CODE_RAM"
   #endif
#elif defined (FLS_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  FLS_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (FLS_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  FLS_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".FLS_PRIVATE_CODE_RAM"
   #endif
#elif defined (FLS_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  FLS_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (FLS_START_SEC_SCHEDULER_CODE)
   #ifdef SCHEDULER_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define SCHEDULER_CODE_SEC_STARTED
     #undef  FLS_START_SEC_SCHEDULER_CODE
     #pragma ghs section text=".FLS_PRIVATE_CODE_RAM"
   #endif
#elif defined (FLS_STOP_SEC_SCHEDULER_CODE)
   #ifndef SCHEDULER_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  SCHEDULER_CODE_SEC_STARTED
     #undef  FLS_STOP_SEC_SCHEDULER_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (FLS_START_SEC_BUFFER_CODE)
   #undef      FLS_START_SEC_BUFFER_CODE
     #pragma ghs section sbss=".FLS_BUFFER_CODE_RAM"
#elif defined (FLS_STOP_SEC_BUFFER_CODE)
   #undef      FLS_STOP_SEC_BUFFER_CODE
     #pragma ghs section sbss=default

#elif defined (FLS_START_SEC_APPL_CODE)
   #undef      FLS_START_SEC_APPL_CODE
   #pragma ghs section text=".FLS_APPL_CODE_ROM"
#elif defined (FLS_STOP_SEC_APPL_CODE)
   #undef      FLS_STOP_SEC_APPL_CODE
   #define DEFAULT_STOP_SEC_CODE
   
/* -------------------------------------------------------------------------- */
/* Code sections                                                                   */
/* -------------------------------------------------------------------------- */

/*Code section - TEXT_SECT*/
#elif defined (CODE_START_TEXT_SECT)
   #undef      CODE_START_TEXT_SECT
   #pragma ghs section text="TEXT_SECT"
#elif defined (CODE_STOP_TEXT_SECT)
   #undef      CODE_STOP_TEXT_SECT
   #pragma ghs section text=default

/*Code section - APP_VECT*/
#elif defined(CODE_START_APP_VECT)
    #undef CODE_START_APP_VECT
    #pragma ghs section text="APP_VECT"
#elif defined(CODE_STOP_APP_VECT)
    #undef CODE_STOP_APP_VECT
    #pragma ghs section text=default

/*Code section - ISR_SECT*/
#elif defined(CODE_START_ISR_SECT)
    #undef CODE_START_ISR_SECT
    #pragma ghs section text="ISR_SECT"
#elif defined(CODE_STOP_ISR_SECT)
    #undef CODE_STOP_ISR_SECT
    #pragma ghs section text=default
    
/* -------------------------------------------------------------------------- */
/* Calibrations                                                                   */
/* -------------------------------------------------------------------------- */

#endif  /* START_WITH_IF */


/*******************************************************************************
**                      Default section mapping                               **
*******************************************************************************/
/* general start of #elif chain whith #if                                     */
#if defined (START_WITH_IF)

/* -------------------------------------------------------------------------- */
/* RAM variables initialized from ROM on reset                                */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_1BIT)
   #undef      DEFAULT_START_SEC_VAR_1BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".RAM_1BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_1BIT)
   #undef      DEFAULT_STOP_SEC_VAR_1BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_8BIT)
   #undef      DEFAULT_START_SEC_VAR_8BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".RAM_8BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_16BIT)
   #undef      DEFAULT_START_SEC_VAR_16BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".RAM_16BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_32BIT)
   #undef      DEFAULT_START_SEC_VAR_32BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".RAM_32BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section sdata=".RAM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #pragma ghs section sdata=default
   #pragma ghs endsda

/* -------------------------------------------------------------------------- */
/* RAM variables not initialized                                              */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_NOINIT_1BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_1BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_1BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_8BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_16BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_32BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #pragma ghs section sbss=default
   #pragma ghs endsda

/* -------------------------------------------------------------------------- */
/* RAM variables frequently used or accessed bitwise                          */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_FAST_1BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_1BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_1BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_1BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_8BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_16BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_32BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #pragma ghs section sdata=default
   #pragma ghs endsda

/* -------------------------------------------------------------------------- */
/* ROM constants                                                              */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CONST_1BIT)
   #undef      DEFAULT_START_SEC_CONST_1BIT
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_1BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_1BIT)
   #undef      DEFAULT_STOP_SEC_CONST_1BIT
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_8BIT)
   #undef      DEFAULT_START_SEC_CONST_8BIT
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_8BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_16BIT)
   #undef      DEFAULT_START_SEC_CONST_16BIT
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_16BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_32BIT)
   #undef      DEFAULT_START_SEC_CONST_32BIT
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_32BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #pragma ghs section rosdata=default
   #pragma ghs endsda
/* -------------------------------------------------------------------------- */
/* ROM FAR constants                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CONST_1BIT_FAR)
   #undef      DEFAULT_START_SEC_CONST_1BIT_FAR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_FAR_ROM_1BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_1BIT_FAR)
   #undef      DEFAULT_STOP_SEC_CONST_1BIT_FAR
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_8BIT_FAR)
   #undef      DEFAULT_START_SEC_CONST_8BIT_FAR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_FAR_ROM_8BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_FAR)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_FAR
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_16BIT_FAR)
   #undef      DEFAULT_START_SEC_CONST_16BIT_FAR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_FAR_ROM_16BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_FAR)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_FAR
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_32BIT_FAR)
   #undef      DEFAULT_START_SEC_CONST_32BIT_FAR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_FAR_ROM_32BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_FAR)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_FAR
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_FAR)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_FAR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_FAR_ROM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_FAR)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_FAR
   #pragma ghs section rosdata=default
   #pragma ghs endsda
/* -------------------------------------------------------------------------- */
/* ROM code                                                                   */
/* -------------------------------------------------------------------------- */

/*move DEFAULT_START_SEC_CODE*/


    
/* ---------------------------------------------------------------------------*/
/* End of default section mapping                                             */
/* ---------------------------------------------------------------------------*/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif  /* START_WITH_IF */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
