/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Dio_Lcfg.c                                                  */
/* Version      = 3.1.2                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSAR DIO Link Time Source Register                         */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  3.1.4
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    FK4_4010_DIO_V308_140401_HEADLAMP.arxml
 * GENERATED ON:   1 Apr 2014 - 10:46:38
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dio_LTTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define DIO_LCFG_C_AR_MAJOR_VERSION  2
#define DIO_LCFG_C_AR_MINOR_VERSION  2
#define DIO_LCFG_C_AR_PATCH_VERSION  0

/* File version information */
#define DIO_LCFG_C_SW_MAJOR_VERSION  3
#define DIO_LCFG_C_SW_MINOR_VERSION  1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (DIO_LTTYPES_AR_MAJOR_VERSION != DIO_LCFG_C_AR_MAJOR_VERSION)
  #error "Dio_Lcfg.c : Mismatch in Specification Major Version"
#endif

#if (DIO_LTTYPES_AR_MINOR_VERSION != DIO_LCFG_C_AR_MINOR_VERSION)
  #error "Dio_Lcfg.c : Mismatch in Specification Minor Version"
#endif

#if (DIO_LTTYPES_AR_PATCH_VERSION != DIO_LCFG_C_AR_PATCH_VERSION)
  #error "Dio_Lcfg.c : Mismatch in Specification Patch Version"
#endif

#if (DIO_SW_MAJOR_VERSION != DIO_LCFG_C_SW_MAJOR_VERSION)
  #error "Dio_Lcfg.c : Mismatch in Major Version"
#endif

#if (DIO_SW_MINOR_VERSION != DIO_LCFG_C_SW_MINOR_VERSION)
  #error "Dio_Lcfg.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define DIO_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Structure of DIO Port Group Configuration */
CONST (Tdd_Dio_PortGroup, DIO_CONST) Dio_GstPortGroup[] =
{
  /* Port: 0 - DioPort0 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400100,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Port: 1 - DioPort1 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400104,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Port: 2 - DioPort10 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400128,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Port: 3 - DioPort25 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Port: 4 - DioPort27 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF40016C,

    /* blJtagPort */
    DIO_FALSE
  }
};


/* Data Structure of DIO Port Channel Configuration */
CONST(Tdd_Dio_PortChannel, DIO_CONST) Dio_GstPortChannel[] =
{
  /* Channel: 0 - DioChannel0_0 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400100,

    /* usMask */
    0x0001,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 1 - DioChannel0_10 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400100,

    /* usMask */
    0x0400,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 2 - DioChannel0_7 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400100,

    /* usMask */
    0x0080,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 3 - DioChannel10_10 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400128,

    /* usMask */
    0x0400,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 4 - DioChannel10_11 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400128,

    /* usMask */
    0x0800,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 5 - DioChannel1_10 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400104,

    /* usMask */
    0x0400,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 6 - DioChannel1_11 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400104,

    /* usMask */
    0x0800,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 7 - DioChannel1_12 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400104,

    /* usMask */
    0x1000,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 8 - DioChannel1_7 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400104,

    /* usMask */
    0x0080,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 9 - DioChannel1_8 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400104,

    /* usMask */
    0x0100,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 10 - DioChannel1_9 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400104,

    /* usMask */
    0x0200,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 11 - DioChannel25_1 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x0002,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 12 - DioChannel25_10 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x0400,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 13 - DioChannel25_11 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x0800,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 14 - DioChannel25_12 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x1000,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 15 - DioChannel25_13 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x2000,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 16 - DioChannel25_14 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x4000,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 17 - DioChannel25_5 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x0020,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 18 - DioChannel25_6 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x0040,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 19 - DioChannel25_7 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x0080,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 20 - DioChannel25_8 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x0100,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 21 - DioChannel25_9 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x0200,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 22 - DioChannel27_0 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF40016C,

    /* usMask */
    0x0001,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 23 - DioChannel27_1 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF40016C,

    /* usMask */
    0x0002,

    /* blJtagPort */
    DIO_FALSE
  },

  /* Channel: 24 - DioChannel27_2 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF40016C,

    /* usMask */
    0x0004,

    /* blJtagPort */
    DIO_FALSE
  }
};


/* Data Structure of DIO Port Channel Group Configuration */
CONST(Dio_ChannelGroupType, DIO_CONST) Dio_GstChannelGroupData[] =
{
  /* ChannelGroup: 0 - DioChannelGroup0 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400100,

    /* usMask */
    0x0000,

    /* ucOffset */
    0x00,

    /* blJtagPort */
    DIO_FALSE
  },

  /* ChannelGroup: 1 - DioChannelGroup1 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400104,

    /* usMask */
    0x0000,

    /* ucOffset */
    0x00,

    /* blJtagPort */
    DIO_FALSE
  },

  /* ChannelGroup: 2 - DioChannelGroup10 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400128,

    /* usMask */
    0x0000,

    /* ucOffset */
    0x00,

    /* blJtagPort */
    DIO_FALSE
  },

  /* ChannelGroup: 3 - DioChannelGroup25 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF400164,

    /* usMask */
    0x0000,

    /* ucOffset */
    0x00,

    /* blJtagPort */
    DIO_FALSE
  },

  /* ChannelGroup: 4 - DioChannelGroup27 */
  {
    /* pPortAddress */
    (P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA))0xFF40016C,

    /* usMask */
    0x0000,

    /* ucOffset */
    0x00,

    /* blJtagPort */
    DIO_FALSE
  }
};



#define DIO_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/

