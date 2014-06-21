/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Gpt_PBTypes.h                                               */
/* Version      = 3.0.7a                                                      */
/* Date         = 29-Sep-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros and structure datatypes for post build           */
/* parameters of GPT Driver                                                   */
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
 * V3.0.0:  23-Oct-2009  : Initial Version
 * V3.0.1:  05-Nov-2009  : As per SCR 088, I/O structure is updated to have
 *                         separate base address for USER and OS registers.
 * V3.0.2:  11-Dec-2009  : As per SCR 167, "STagTdd_Gpt_TAUJUnitOsUserRegs" is
 *                         renamed to "STagTdd_Gpt_TAUJUnitOsRegs".
 * V3.0.3:  25-Feb-2010  : As per SCR 194, following changes are made:
 *                         1. Precompile option
 *                         GPT_ENABLE_DISABLE_NOTIFICATION_API is added for the
 *                         'ucNotificationConfig' in the structure
 *                         Tdd_Gpt_ChannelConfigType.
 *                         2. Precompile option is added for the array
 *                         "Gpt_GstTAUUnitConfig" and the structure
 *                         "Tdd_Gpt_TAUUnitConfigType".
 * V3.0.4:  23-Jun-2010  : As per SCR 281, structures are added/modified to
 *                         support TAUB and TAUC timer units.
 * V3.0.5:  08-Jul-2010  : As per SCR 299, in the structure
 *                         Tdd_Gpt_ChannelConfigType, pImrIntrCntlAddress is
 *                         updated to type uint8.
 * V3.0.6:  28-Jul-2010  : As per SCR 317, macro GPT_MODE_OSTM_CONTINUOUS
 *                         is added.
 * V3.0.7:  17-Jun-2011  : As per SCR 474,
 *                         1. Access size is updated for registers TAUAnBRS,
 *                         TAUJnBRS, TAUJnTS, TAUJnTT, TAUJnTO, TAUJnTOE,
 *                         TAUJnTOL, TAUJnRDT, TAUJnTOM, TAUJnRDE, TAUABCnCMURm
 *                         TAUJnCMURm. Structures STagTdd_Gpt_TAUABCUnitOsRegs,
 *                         STagTdd_Gpt_TAUJUnitUserRegs,
 *                         STagTdd_Gpt_TAUJUnitOsRegs,STagTdd_Gpt_TAUABCUserRegs
 *                         STagTdd_Gpt_TAUJUserRegs are modified.
 *                         2. OSTMnTO and OSTMnTOE registers are not available
 *                         in some of the Xx4 devices and also these registers
 *                         are not required for any functionality of the GPT
 *                         Driver Module, hence these registers are removed from
 *                         structure STagTdd_Gpt_OSTMUnitUserRegs.
 * V3.0.7a: 29-Sep-2011  : As per MANTIS #3551, the macro
 *                         GPT_CLEAR_INT_REQUEST_FLAG is added to clear the
 *                         interrupt request flag, and structures are modified
 *                         to support Interrupt control register.
 *                         Copyright is updated.
 */
/******************************************************************************/
#ifndef GPT_PBTYPES_H
#define GPT_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Gpt.h"
#include "V850_Types.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/

/* AUTOSAR specification version information */
#define GPT_PBTYPES_AR_MAJOR_VERSION    GPT_AR_MAJOR_VERSION_VALUE
#define GPT_PBTYPES_AR_MINOR_VERSION    GPT_AR_MINOR_VERSION_VALUE
#define GPT_PBTYPES_AR_PATCH_VERSION    GPT_AR_PATCH_VERSION_VALUE

/* File version information */
#define GPT_PBTYPES_SW_MAJOR_VERSION    3
#define GPT_PBTYPES_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Macros for Hardware Timer type */
#define GPT_HW_TAUA                         (uint8)0x00
#define GPT_HW_TAUB                         (uint8)0x01
#define GPT_HW_TAUC                         (uint8)0x02
#define GPT_HW_TAUJ                         (uint8)0x03
#define GPT_HW_OSTM                         (uint8)0x04

/* Macros for channel modes */
#define GPT_MODE_ONESHOT                    (uint8)0x00
#define GPT_MODE_CONTINUOUS                 (uint8)0x01
#define GPT_MODE_OSTM_CONTINUOUS            (uint8)0x00

#define GPT_TRUE                            (uint8)0x01
#define GPT_FALSE                           (uint8)0x00
#define GPT_ZERO                            (uint8)0x00
#define GPT_ONE                             (uint8)0x01
#define GPT_NO_CBK_CONFIGURED               (uint8)0xFF
#define GPT_INITIALIZED                     (uint8)0x01
#define GPT_UNINITIALIZED                   (uint8)0x00

/* Reset values */
#define GPT_RESET_BYTE                      (uint8)0x00
#define GPT_RESET_WORD                      (uint16)0x0000
#define GPT_RESET_LONG_WORD                 (uint32)0x00000000ul

/* set values */
#define GPT_SET_BYTE                        (uint8)0xFF
#define GPT_SET_WORD                        (uint16)0xFFFF
#define GPT_SET_LONG_WORD                   (uint32)0xFFFFFFFFul

#define GPT_WORD_ONE                        (uint16)0x0001
#define GPT_WORD_ZERO                       (uint16)0x0000

#define GPT_CLEAR_INT_REQUEST_FLAG          (uint16)0xEFFF

/* Macros to avoid Magic numbers */
#define GPT_DBTOC_VALUE \
                                 ((GPT_VENDOR_ID_VALUE << 22) | \
                                  (GPT_MODULE_ID_VALUE << 14) | \
                                  (GPT_SW_MAJOR_VERSION_VALUE << 8) | \
                                  (GPT_SW_MINOR_VERSION_VALUE << 3))

/* Macros for masks */
#define GPT_OSTMTO_MASK                      (uint8)0x00
#define GPT_OSTMTOE_MASK                     (uint8)0x00
#define GPT_OSTM_START_MASK                  (uint8)0x01
#define GPT_OSTM_STOP_MASK                   (uint8)0x01

#define GPT_NOTIFICATION_ENABLED             (uint8)0x01
#define GPT_NOTIFICATION_DISABLED            (uint8)0x00

#define GPT_WAKEUP_NOTIFICATION_ENABLED      (uint8)0x01
#define GPT_WAKEUP_NOTIFICATION_DISABLED     (uint8)0x00

/* Macros to hold timer status */
#define GPT_CH_NOTRUNNING                    (uint8)0x00
#define GPT_CH_RUNNING                       (uint8)0x01

#define GPT_CHANNEL_UNCONFIGURED             (uint8)0xFF

/*******************************************************************************
** Structure for TAUA/TAUB/TAUC unit user register configuration              **
*******************************************************************************/
#if ((GPT_TAUA_UNIT_USED  == STD_ON)||(GPT_TAUB_UNIT_USED  == STD_ON)||\
     (GPT_TAUC_UNIT_USED  == STD_ON))
typedef struct STagTdd_Gpt_TAUABCUnitUserRegs
{
  uint16 volatile usTAUABCnTOL;
  uint16 volatile usReserved1;
  uint16 volatile usTAUABCnRDT;
  uint16 volatile aaReserved2[9];
  uint16 volatile usTAUABCnTO;
  uint16 volatile usReserved3;
  uint16 volatile usTAUABCnTOE;
  uint16 volatile aaReserved4[179];
  uint16 volatile usTAUABCnTS;
  uint16 volatile usReserved5;
  uint16 volatile usTAUABCnTT;
} Tdd_Gpt_TAUABCUnitUserRegs;
#endif
/*******************************************************************************
** Structure for TAUA/TAUB/TAUC unit os register configuration                **
*******************************************************************************/
#if ((GPT_TAUA_UNIT_USED  == STD_ON)||(GPT_TAUB_UNIT_USED  == STD_ON)||\
     (GPT_TAUC_UNIT_USED  == STD_ON))
typedef struct STagTdd_Gpt_TAUABCUnitOsRegs
{
  uint16 volatile usTAUABCnTPS;
  uint16 volatile usReserved1;
  uint8  volatile ucTAUAnBRS;
  uint8  volatile ucReserved2;
  uint16 volatile usReserved3;
  uint16 volatile usTAUABCnTOM;
  uint16 volatile aaReserved4[11];
  uint16 volatile usTAUABCnRDE;
} Tdd_Gpt_TAUABCUnitOsRegs;
#endif
/*******************************************************************************
** Structure for TAUJ unit user configuration                                 **
*******************************************************************************/
#if (GPT_TAUJ_UNIT_USED  == STD_ON)
typedef struct STagTdd_Gpt_TAUJUnitUserRegs
{
  uint8  volatile ucTAUJnTS;
  uint8  volatile ucReserved1;
  uint16 volatile usReserved2;
  uint8  volatile ucTAUJnTT;
  uint8  volatile ucReserved3;
  uint16 volatile usReserved4;
  uint8  volatile ucTAUJnTO;
  uint8  volatile ucReserved5;
  uint16 volatile aaReserved6;
  uint8  volatile ucTAUJnTOE;
  uint8  volatile ucReserved7;
  uint16 volatile aaReserved8;
  uint8  volatile ucTAUJnTOL;
  uint8  volatile ucReserved9;
  uint16 volatile usReserved10;
  uint8  volatile ucTAUJnRDT;
} Tdd_Gpt_TAUJUnitUserRegs;
#endif
/*******************************************************************************
** Structure for TAUJ unit os configuration                                   **
*******************************************************************************/
#if (GPT_TAUJ_UNIT_USED  == STD_ON)
typedef struct STagTdd_Gpt_TAUJUnitOsRegs
{
  uint16 volatile usTAUJnTPS;
  uint16 volatile usReserved1;
  uint8  volatile ucTAUJnBRS;
  uint8  volatile ucReserved2;
  uint16 volatile usReserved3;
  uint8  volatile ucTAUJnTOM;
  uint8  volatile ucReserved4;
  uint16 volatile aaReserved5[3];
  uint8  volatile ucTAUJnRDE;
} Tdd_Gpt_TAUJUnitOsRegs;
#endif
/*******************************************************************************
** Structure for OSTM channel user control register                           **
*******************************************************************************/
#if (GPT_OSTM_UNIT_USED  == STD_ON)
typedef struct STagTdd_Gpt_OSTMUnitUserRegs
{
  uint32 volatile ulOSTMnCMP;
  uint32 volatile ulOSTMnCNT;
  uint8 volatile ucReserved1;
  uint8 volatile aaReserved2[3];
  uint8 volatile ucReserved3;
  uint8 volatile aaReserved4[3];
  uint8 volatile ucOSTMnTE;
  uint8 volatile aaReserved5[3];
  uint8 volatile ucOSTMnTS;
  uint8 volatile aaReserved6[3];
  uint8 volatile ucOSTMnTT;
} Tdd_Gpt_OSTMUnitUserRegs;
#endif
/*******************************************************************************
** Structure for TAUA/TAUB/TAUC channel user control register                 **
*******************************************************************************/
#if ((GPT_TAUA_UNIT_USED  == STD_ON)||(GPT_TAUB_UNIT_USED  == STD_ON)||\
     (GPT_TAUC_UNIT_USED  == STD_ON))
typedef struct STagTdd_Gpt_TAUABCUserRegs
{
  uint16 volatile usTAUABCnCDRm;
  uint16 volatile aaReserved1[63];
  uint16 volatile usTAUABCnCNTm;
  uint16 volatile aaReserved2[31];
  uint8  volatile ucTAUABCnCMURm;
} Tdd_Gpt_TAUABCChannelUserRegs;
#endif
/*******************************************************************************
** Structure for TAUJ channel user control register                           **
*******************************************************************************/
#if (GPT_TAUJ_UNIT_USED  == STD_ON)
typedef struct STagTdd_Gpt_TAUJUserRegs
{
  uint32 volatile ulTAUJnCDRm;
  uint32 volatile aaReserved1[3];
  uint32 volatile ulTAUJnCNTm;
  uint32 volatile aaReserved2[3];
  uint8  volatile ucTAUJnCMURm;
} Tdd_Gpt_TAUJChannelUserRegs;
#endif
/*******************************************************************************
** Structure for TAU  Unit configuration type                                 **
*******************************************************************************/
#if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON)||\
    (GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))
typedef struct STagTdd_Gpt_TAUUnitConfigType
{
  /* Pointer to base address of TAU Unit user control registers */
  P2VAR(void, AUTOMATIC, GPT_CONFIG_DATA)pTAUUnitUserCntlRegs;
  /* Pointer to base address of TAU Unit os control registers */
  P2VAR(void, AUTOMATIC, GPT_CONFIG_DATA)pTAUUnitOsCntlRegs;
  /* TAU Channels Mask value */
  uint16 usTAUChannelMaskValue;
  /* TAU Unit prescaler for clock sources CK0, CK1, CK3 and CK4 */
  #if (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
  uint16 usPrescaler;
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON))
  /* TAU Unit baudrate value */
  uint8 ucBaudRate;
  /* Prescaler shared between ICU/GPT module
   * blConfigurePrescaler = TRUE Prescaler for CK0-CK3 has to be set by GPT
   * blConfigurePrescaler = FALSE Prescaler for CK0-CK3 need not be set by GPT
   */
  #endif
  boolean blConfigurePrescaler;
  #endif
} Tdd_Gpt_TAUUnitConfigType;
#endif
/*******************************************************************************
**                         Structure for GPT Channel RAM data                 **
*******************************************************************************/
typedef struct STagTdd_Gpt_ChannelRamData
{
  /* RAM used to maintain timer status */
  uint8 ucChannelStatus;
  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API)
  /* RAM used to store Notification status */
  uinteger uiNotifyStatus:1;
  #endif
  #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
  /* RAM used to store Wakeup Notification status */
  uinteger uiWakeupStatus:1;
  #endif
} Tdd_Gpt_ChannelRamData;

/*******************************************************************************
** Structure for channel information                                          **
*******************************************************************************/
typedef struct STagGpt_ChannelConfigType
{
  /* Pointer to base address of channel user control register */
  P2VAR(void, AUTOMATIC, GPT_CONFIG_DATA)pBaseCtlAddress;
  /* Pointer to base address of channel CMOR/OSTMnCTL register */
  P2VAR(uint16, AUTOMATIC, GPT_CONFIG_DATA)pCMORorCTLAddress;
  /* Pointer to Timer IMR Interrupt control register */
  P2VAR(uint8, AUTOMATIC, GPT_CONFIG_DATA)pImrIntrCntlAddress;
  /* Pointer to Timer Interrupt Control register */
  P2VAR(uint16, AUTOMATIC, GPT_CONFIG_DATA)pIntrCntlAddress;
  /* Individual channel mask value */
  uint16 usChannelMask;
  /* For channels belonging to TAUA/TAUB/TAUC/TAUJ
   * Bit 3-0: 0001: if GPT_MODE_CONTINOUS/GPT_MODE_ONESHOT
   */
  /* Other bits should be generated with 0 */
  uint16 usModeSettingsMask;
  /* Channel Wakeup Source */
  #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
  EcuM_WakeupSourceType ddWakeupSourceId;
  #endif

  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  /* If the value is equal to GPT_NO_CBK_CONFIGURED then the callback
   * function is not configured. If the value is other than
   * GPT_NO_CBK_CONFIGURED, it indicates index to the configured
   * call back function in the array Gpt_GstChannelNotifFunc
   */
  uint8 ucNotificationConfig;
  #endif

  /* IMR mask value */
  uint8 ucImrMaskValue;

  /* Timer Unit Index in the array Gpt_GstTAUAUnitConfig or
     Gpt_GstTAUJUnitConfig */
  uint8 ucTimerUnitIndex;

  /* Type of GPT timer (TAUA/TAUB/TAUC/TAUJ/OSTM) */
  uinteger uiTimerType:3;

  /* Enabling wakeup capability of CPU for a channel when timeout occurs */
  uinteger uiGptEnableWakeup:1;

  /* Mode for the GPT channel */
  uinteger uiGptChannelMode:1;

} Tdd_Gpt_ChannelConfigType;

/*******************************************************************************
**                      Global configuration constants                        **
*******************************************************************************/

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Array to map channel to timer index */
extern CONST(uint8, GPT_CONST) Gpt_GaaTimerChIdx[];

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define GPT_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* RAM Allocation of Channel data */
extern VAR(Tdd_Gpt_ChannelRamData, GPT_NOINIT_DATA) Gpt_GstChannelRamData[];

#if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON)|| \
    (GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))
/* Array of structures for TAU Unit Channel Configuration */
extern CONST(Tdd_Gpt_TAUUnitConfigType, GPT_CONST) Gpt_GstTAUUnitConfig[];
#endif

/* Array of structures for Channel Configuration */
extern CONST(Tdd_Gpt_ChannelConfigType, GPT_CONST) Gpt_GstChannelConfig[];

#define GPT_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* GPT_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
