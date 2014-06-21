/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Fee_Cfg.h                                                   */
/* Version      = 3.0.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
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
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:              : Initial version
 */
/******************************************************************************/

/*******************************************************************************
**                    FEE Component Generation Tool Version                   **
*******************************************************************************/
/*
 * TOOL VERSION:    3.0.6a
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    FK4_4010_FEE_V304_130924_NEWCLEAPLUS.arxml
 * GENERATED ON:  26 Sep 2013 - 09:00:16
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Fee.h"
#include "Fee_Types.h"

/*******************************************************************************
**                     Version Information                                    **
*******************************************************************************/

/*
 * AUTOSAR specification version information
 */
#define FEE_CFG_C_AR_MAJOR_VERSION  1
#define FEE_CFG_C_AR_MINOR_VERSION  2
#define FEE_CFG_C_AR_PATCH_VERSION  0
/*
 * File version information
 */
#define FEE_CFG_C_SW_MAJOR_VERSION        3
#define FEE_CFG_C_SW_MINOR_VERSION        0


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (FEE_CFG_AR_MAJOR_VERSION != FEE_CFG_C_AR_MAJOR_VERSION)
        #error "Fee_Cfg.c : Mismatch in Specification Major Version"
#endif
#if (FEE_CFG_AR_MINOR_VERSION != FEE_CFG_C_AR_MINOR_VERSION)
        #error "Fee_Cfg.c : Mismatch in Specification Minor Version"
#endif
#if (FEE_CFG_AR_PATCH_VERSION != FEE_CFG_C_AR_PATCH_VERSION)
        #error "Fee_Cfg.c : Mismatch in Specification Patch Version"
#endif
#if (FEE_CFG_SW_MAJOR_VERSION != FEE_CFG_C_SW_MAJOR_VERSION)
        #error "Fee_Cfg.c : Mismatch in Major Version"
#endif
#if (FEE_CFG_SW_MINOR_VERSION != FEE_CFG_C_SW_MINOR_VERSION)
        #error "Fee_Cfg.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define FEE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(Tdd_Fee_BlockConfigType, FEE_CONST) Fee_GstBlockConfiguration[4] =
{
  /* BLOCK:  0 - 2 */
  {
    /* usFeeBlockNumber */
    0x0002,

    /* usFeeBlockSize */
    0x0064,

    /* blFeeImmediateData */
    FEE_FALSE
  },

  /* BLOCK:  1 - 4 */
  {
    /* usFeeBlockNumber */
    0x0004,

    /* usFeeBlockSize */
    0x00C8,

    /* blFeeImmediateData */
    FEE_FALSE
  },

  /* BLOCK:  2 - 8 */
  {
    /* usFeeBlockNumber */
    0x0008,

    /* usFeeBlockSize */
    0x01F4,

    /* blFeeImmediateData */
    FEE_FALSE
  },

  /* BLOCK:  3 - 16 */
  {
    /* usFeeBlockNumber */
    0x0010,

    /* usFeeBlockSize */
    0x03E8,

    /* blFeeImmediateData */
    FEE_FALSE
  }
};


#if (FEE_UPPER_LAYER_NOTIFICATION == STD_ON)

/* CONST(Tdd_Fee_FuncType, FEE_CONST) Fee_GstFunctionNotification[]; */
#endif

#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

