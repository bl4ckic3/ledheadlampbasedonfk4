/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Pwm_PBTypes.h                                               */
/* Version      = 3.1.6                                                       */
/* Date         = 05-Nov-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains post-compile time parameters.                           */
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
 * V3.0.0:  18-Aug-2009  : Initial version
 *
 * V3.0.1:  28-Oct-2009  : Updated as per the SCR 054
 *                         ucPolarity is removed.
 *
 * V3.0.2:  05-Nov-2009  : As per SCR 088, I/O structure is updated to have
 *                         separate base address for USER and OS registers.
 *
 * V3.0.3:  02-Jul-2010  : As per SCR 290, structures are added/modified to
 *                         support TAUB and TAUC timer units.
 *
 * V3.0.4:  29-Apr-2011  : As per SCR 435, PWM_CORRECTION_MASK macro is added
 *                         TAUABC_MAX_DUTY_REG_VALUE and TAUJ_MAX_DUTY_REG_VALUE
 *                         macros are removed.
 * V3.0.5:  21-Jun-2011  : As per SCR 478, the following changes are made:
 *                         1 Structures Tdd_Pwm_TAUABCUnitOsRegs,
 *                           Tdd_Pwm_TAUJUnitUserRegs,Tdd_Pwm_TAUJUnitOsRegs,
 *                           Tdd_Pwm_TAUABCChannelUserRegs and
 *                           Tdd_Pwm_TAUJChannelUserRegs are modified for change
 *                           in the register sizes of their elements.
 *                         2 The element usChannelMask from stucture
 *                           Tdd_Pwm_ChannelConfigType is moved to
 *                           individual Tdd_Pwm_TAUABCProperties and
 *                           Tdd_Pwm_TAUJProperties structures with change in
 *                           size.
 * V3.1.0:  26-Jul-2011  : Ported for the DK4 variant.
 * V3.1.2:  12-Jan-2012  : TEL have fixed The Issues reported by  mantis id
 *                       :  #4246,#4210,#4207,#4206,#4202,#4259,#4257,#4248.
 * V3.1.3:  05-Mar-2012  : Merged the fixes done for Fx4L PWM driver
 * V3.1.4:  31-Mar-2012  : Remove an unwanted check from prescalar baudrate
 * V3.1.5:  06-Jun-2012  : As per SCR 034, Compiler version is removed from
 *                         Environment section.
 * V3.1.6:  05-Nov-2012  : As per MNT_0007541,comment added at each "#endif".
 */
/******************************************************************************/

#ifndef PWM_PBTYPES_H
#define PWM_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Pwm.h"
#include "V850_Types.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PWM_PBTYPES_AR_MAJOR_VERSION       PWM_AR_MAJOR_VERSION_VALUE
#define PWM_PBTYPES_AR_MINOR_VERSION       PWM_AR_MINOR_VERSION_VALUE
#define PWM_PBTYPES_AR_PATCH_VERSION       PWM_AR_PATCH_VERSION_VALUE

/* File version information */
#define PWM_PBTYPES_SW_MAJOR_VERSION       3
#define PWM_PBTYPES_SW_MINOR_VERSION       1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PWM_SW_MAJOR_VERSION != PWM_PBTYPES_SW_MAJOR_VERSION)
  #error "Pwm_PBTypes.h : Mismatch in Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_PBTYPES_SW_MINOR_VERSION)
  #error "Pwm_PBTypes.h : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/
#define PWM_ZERO                           (uint8)0x00
#define PWM_ONE                            (uint8)0x01
#define PWM_TWO                            (uint8)0x02
#define PWM_THREE                          (uint8)0x03
#define PWM_FOUR                           (uint8)0x04

#define PWM_TRUE                           (uint8)0x01
#define PWM_FALSE                          (uint8)0x00

#define PWM_INITIALIZED                    (uint8)0x01
#define PWM_UNINITIALIZED                  (uint8)0x00

#define PWM_NO_CBK_CONFIGURED              0xFF
#define PWM_CHANNEL_UNCONFIGURED           0xFF

/* Macros to avoid Magic numbers */
#define PWM_DBTOC_VALUE                   ((PWM_VENDOR_ID_VALUE << 22) | \
                                           (PWM_MODULE_ID_VALUE << 14) | \
                                           (PWM_SW_MAJOR_VERSION_VALUE << 8) | \
                                           (PWM_SW_MINOR_VERSION_VALUE << 3))

/* Macros for Hardware Timer type */
#define PWM_HW_TAUA                        (uint8)0x00
#define PWM_HW_TAUB                        (uint8)0x01
#define PWM_HW_TAUC                        (uint8)0x02
#define PWM_HW_TAUJ                        (uint8)0x03

/* Macro for Timer Unit Type*/
#define PWM_TAUA0                          (uint8)0x00
#define PWM_TAUA1                          (uint8)0x01
#define PWM_TAUJ                           (uint8)0x02

/* Macros for Timer Mode type */
#define PWM_MASTER_CHANNEL                 (uint8)0x00
#define PWM_SLAVE_CHANNEL                  (uint8)0x01

/* Macro for setting the PWM mode in Control registers */
#define MIN_DUTY_CYCLE                     0x0000
#define MAX_DUTY_CYCLE                     0x8000
#define PWM_TAUABC_MAX_PERIOD_VALUE        (uint16)0xFFFF
#define PWM_PERIOD_LIMIT                   (uint16)0xFFFF
#define PWM_DUTY_CALC_DIV                  (uint8)0x0F

/* Reset values */
#define PWM_RESET_WORD                     0x0000
#define PWM_RESET_LONG_WORD                0x00000000

/* set values */
#define PWM_SET_WORD                       0xFFFF
#define PWM_SET_LONG_WORD                  (uint32)0xFFFFFFFFul

#define PWM_SYNCH_TAUJ_MASK                0x000F

#define PWM_CORRECTION_MASK                (uint32)0x00007FFF

#define PWM_CLEAR_INT_REQUEST_FLAG          (uint16)0xEFFF

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**           Structure for TAUA/TAUB/TAUC User control registers              **
*******************************************************************************/
#if ((PWM_TAUA_UNIT_USED  == STD_ON)||(PWM_TAUB_UNIT_USED  == STD_ON)||\
    (PWM_TAUC_UNIT_USED  == STD_ON))
typedef struct STagTdd_Pwm_TAUABCUnitUserRegs
{
  uint16 volatile usTAUABCnTOL;
  uint16 volatile usReserved1;
  uint16 volatile usTAUABCnRDT;
  uint16 volatile aaReserved2;
  uint16 volatile usTAUABCnRSF;
  uint16 volatile aaReserved3[7];
  uint16 volatile usTAUABCnTO;
  uint16 volatile usReserved4;
  uint16 volatile usTAUABCnTOE;
  uint16 volatile aaReserved5[177];
  uint16 volatile usTAUABCnTE;
  uint16 volatile usReserved6;
  uint16 volatile usTAUABCnTS;
  uint16 volatile usReserved7;
  uint16 volatile usTAUABCnTT;
}Tdd_Pwm_TAUABCUnitUserRegs;
#endif

/*******************************************************************************
**            Structure for TAUA/TAUB/TAUC OS control registers               **
*******************************************************************************/
#if ((PWM_TAUA_UNIT_USED  == STD_ON)||(PWM_TAUB_UNIT_USED  == STD_ON)||\
    (PWM_TAUC_UNIT_USED  == STD_ON))
typedef struct STagTdd_Pwm_TAUABCUnitOsRegs
{
  uint16 volatile usTAUABCnTPS;
  uint16 volatile usReserved1;
  uint8 volatile ucTAUAnBRS;
  uint8 volatile ucReserved2;
  uint16 volatile usReserved3;
  uint16 volatile usTAUABCnTOM;
  uint16 volatile usReserved4;
  uint16 volatile usTAUABnTOC;
  uint16 volatile aaReserved5[9];
  uint16 volatile usTAUABCnRDE;
}Tdd_Pwm_TAUABCUnitOsRegs;
#endif /*#if((PWM_TAUA_UNIT_USED  == STD_ON)||(PWM_TAUB_UNIT_USED  == STD_ON)||\
          (PWM_TAUC_UNIT_USED  == STD_ON)) */

/*******************************************************************************
**                 Structure for TAUJ User control registers                  **
*******************************************************************************/
#if (PWM_TAUJ_UNIT_USED  == STD_ON)
typedef struct STagTdd_Pwm_TAUJUnitUserRegs
{
  uint8 volatile ucTAUJnTE;
  uint8 volatile ucReserved1;
  uint16 volatile usReserved2;
  uint8 volatile ucTAUJnTS;
  uint8 volatile ucReserved3;
  uint16 volatile usReserved4;
  uint8 volatile ucTAUJnTT;
  uint8 volatile ucReserved5;
  uint16 volatile usReserved6;
  uint8 volatile ucTAUJnTO;
  uint8 volatile ucReserved7;
  uint16 volatile usReserved8;
  uint8 volatile ucTAUJnTOE;
  uint8 volatile ucReserved9;
  uint16 volatile usReserved10;
  uint8 volatile ucTAUJnTOL;
  uint8 volatile ucReserved11;
  uint16 volatile usReserved12;
  uint8 volatile ucTAUJnRDT;
  uint8 volatile ucReserved13;
  uint16 volatile usReserved14;
  uint16 volatile ucTAUJnRSF;
}Tdd_Pwm_TAUJUnitUserRegs;
#endif /* #if(PWM_TAUJ_UNIT_USED  == STD_ON) */

/*******************************************************************************
**                Structure for TAUJ Unit OS control registers                **
*******************************************************************************/
#if (PWM_TAUJ_UNIT_USED  == STD_ON)
typedef struct STagTdd_Pwm_TAUJUnitOsRegs
{
  uint16 volatile usTAUJnTPS;
  uint16 volatile usReserved1;
  uint8 volatile ucTAUJnBRS;
  uint8 volatile ucReserved2;
  uint16 volatile usReserved3;
  uint8 volatile ucTAUJnTOM;
  uint8 volatile ucReserved4;
  uint16 volatile usReserved5;
  uint8 volatile ucTAUJnTOC;
  uint8 volatile ucReserved6;
  uint16 volatile usReserved7;
  uint8 volatile ucTAUJnRDE;
}Tdd_Pwm_TAUJUnitOsRegs;
#endif /* #if (PWM_TAUJ_UNIT_USED  == STD_ON) */

/*******************************************************************************
**        Structure for TAUA/TAUB/TAUC channel User control registers         **
*******************************************************************************/
#if ((PWM_TAUA_UNIT_USED  == STD_ON)||(PWM_TAUB_UNIT_USED  == STD_ON)||\
    (PWM_TAUC_UNIT_USED  == STD_ON))
typedef struct STagTdd_Pwm_TAUABCUserRegs
{
  uint16 volatile usTAUABCnCDRm;
  uint16 volatile aaReserved1[63];
  uint16 volatile usTAUABCnCNTm;
  uint16 volatile aaReserved2[31];
  uint8 volatile ucTAUABCnCMURm;
}Tdd_Pwm_TAUABCChannelUserRegs;
#endif

/*******************************************************************************
**             Structure for TAUJ channel User control registers              **
*******************************************************************************/
#if (PWM_TAUJ_UNIT_USED  == STD_ON)
typedef struct STagTdd_Pwm_TAUJUserRegs
{
  uint32 volatile ulTAUJnCDRm;
  uint32 volatile aaReserved1[3];
  uint32 volatile ulTAUJnCNTm;
  uint32 volatile aaReserved2[3];
  uint8 volatile ucTAUJnCMURm;
}Tdd_Pwm_TAUJChannelUserRegs;
#endif

/*******************************************************************************
**         Data Structure for TAUA/TAUB/TAUC Unit configuration type          **
*******************************************************************************/
#if ((PWM_TAUA_UNIT_USED  == STD_ON) || (PWM_TAUB_UNIT_USED  == STD_ON) || \
     (PWM_TAUC_UNIT_USED  == STD_ON))
typedef struct STagTdd_Pwm_TAUABCUnitConfigType
{
  /* pointer to base address of TAUA/TAUB/TAUC Unit user control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                        pTAUABCUnitUserCntlRegs;
  /* pointer to base address of TAUA/TAUB/TAUC Unit OS control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitOsRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                        pTAUABCUnitOsCntlRegs;
  #if(PWM_DELAY_MACRO_SUPPORT == STD_ON)
  /* void pointer to base address of Delay control register */
  P2VAR(uint32, AUTOMATIC, PWM_CONFIG_DATA) pDelayCntlRegs;
  /* Mask value for delay enable */
  uint32 ulDelayEnableMask;
  #endif
  /* Mask value for all channels in a TAUA/TAUB/TAUC */
  uint16 usTAUChannelMask;
  /* Mask value for the TOM register based on configuration of channels */
  uint16 usTOMMask;
  #if((PWM_TAUA_UNIT_USED == STD_ON)||(PWM_TAUB_UNIT_USED == STD_ON))
  /* Mask value for the TOC register based on configuration of channels */
  uint16 usTOCMask;
  #endif
  /* Mask value for the TOL register based on configuration of channels */
  uint16 usTOLMask;
  /* Mask value for the TO register based on configuration of channels */
  uint16 usTOMask;
  /* Mask value for the TOE register based on configuration of channels */
  uint16 usTOEMask;
  /* TAU Unit prescaler for clock sources CK0, CK1, CK3 and CK4 */
  #if (PWM_CONFIG_PRESCALER_SUPPORTED == STD_ON)
  uint16 usPrescaler;
  #if(PWM_TAUA_UNIT_USED == STD_ON)
  /* TAU Unit baudrate value */
  uint8  ucBaudRate;
  /*
   * Prescaler shared between ICU/GPT module
   * blConfigurePrescaler = TRUE Prescaler for CK0-CK3 has to be set by PWM
   * blConfigurePrescaler = FALSE Prescaler for CK0-CK3 need not be set by PWM
   */
  #endif  /* #if(PWM_TAUA_UNIT_USED == STD_ON) */
  boolean blConfigurePrescaler;
  #endif /* #if (PWM_CONFIG_PRESCALER_SUPPORTED == STD_ON) */
  /* PWM Unit type, the channel belongs to TAUA or TAUB or TAUC or TAUJ */
  uinteger uiPwmTAUType:2;
}Tdd_Pwm_TAUABCUnitConfigType;
#endif /*#if((PWM_TAUA_UNIT_USED == STD_ON)||(PWM_TAUB_UNIT_USED == STD_ON)||\
              (PWM_TAUC_UNIT_USED == STD_ON)) */

/*******************************************************************************
**          Data structure for TAUJ Unit configuration type                   **
*******************************************************************************/
#if (PWM_TAUJ_UNIT_USED  == STD_ON)
typedef struct STagTdd_Pwm_TAUJUnitConfigType
{
  /* pointer to base address of TAUJ Unit user control registers */
  P2VAR(Tdd_Pwm_TAUJUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                         pTAUJUnitUserCntlRegs;
  /* pointer to base address of TAUJ Unit os control registers */
  P2VAR(Tdd_Pwm_TAUJUnitOsRegs, AUTOMATIC, PWM_CONFIG_DATA)pTAUJUnitOsCntlRegs;
  /* Mask value for all channels in a TAUA*/
  uint16 usTAUChannelMask;
  /* Mask value for the TOM register based on configuration of channels */
  uint16 usTOMMask;
  /* Mask value for the TOL register based on configuration of channels */
  uint16 usTOLMask;
  /* Mask value for the TO register based on configuration of channels */
  uint16 usTOMask;
  /* Mask value for the TOE register based on configuration of channels */
  uint16 usTOEMask;
  /* TAU Unit prescaler for clock sources CK0, CK1, CK3 and CK4 */
  #if(PWM_CONFIG_PRESCALER_SUPPORTED == STD_ON)
  uint16 usPrescaler;
  /* TAU Unit baudrate value */
  uint8  ucBaudRate;
  /*
   * Prescaler shared between ICU/GPT module
   * blConfigurePrescaler = TRUE Prescaler for CK0-CK3 has to be set by PWM
   * blConfigurePrescaler = FALSE Prescaler for CK0-CK3 need not be set by PWM
   */
  boolean blConfigurePrescaler;
  #endif /* #if(PWM_CONFIG_PRESCALER_SUPPORTED == STD_ON) */
}Tdd_Pwm_TAUJUnitConfigType;
#endif /* #if (PWM_TAUJ_UNIT_USED  == STD_ON) */

/*******************************************************************************
** Structure for the start of various timer array units at the same time      **
** Valid for TAUA0, TAUA1 TAUJ0, TAUJ1                                        **
*******************************************************************************/
#if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
typedef struct STagTdd_PwmSynchStartTAUType
{
  /*
   * Pointer to the address of synchronous start between different
   * TAU Unit control registers
   */
  P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA) pPICCntlRegs;
  /*
   * Mask to Enable the TAUA & TAUJ Units, if any of the channels of
   * TAUA & TAUJ units configured for the Synchronous start
   * PIC0SSER0: Bit 15 - 0: Channels 15 - 0 for TAUA0
   * PIC0SSER1: Bit 15 - 0: Channels 15 - 0 for TAUA1
   * PIC0SSER2: Bit  7 - 4: Channels  3 - 0 for TAUJ1
   *            Bit  3 - 0: Channels  3 - 0 for TAUJ0
   */
  uint16 usSyncTAUMask;
  /* PWM channel type, the channel belongs to TAUA0 or TAUA1 or TAUJ */
  uint8 ucTAUUnitType;
}Tdd_PwmTAUSynchStartUseType;
#endif /* #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON) */

/*******************************************************************************
** Structure for configuring 16-bit period value for TAUA/TAUB/TAUC timers    **
*******************************************************************************/
#if ((PWM_TAUA_UNIT_USED  == STD_ON) || (PWM_TAUB_UNIT_USED  == STD_ON) || \
     (PWM_TAUC_UNIT_USED  == STD_ON))
typedef struct STagTdd_Pwm_TAUABCProperties
{
  #if(PWM_DELAY_MACRO_SUPPORT == STD_ON)
  /* pointer to base address of Delay Compare register of this channel */
  P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)pDlyCompRegs;
  /* Delay value (0 - 2^12) */
  uint16 usDelayValue;
  #endif /* #if(PWM_DELAY_MACRO_SUPPORT == STD_ON) */
  /* Default Period of channel in timer ticks (0 - 2^16) */
  Pwm_PeriodType ddDefaultPeriodOrDuty;
  /* Individual channel mask value */
  uint16 usChannelMask;
}Tdd_Pwm_TAUABCProperties;
#endif /*#if((PWM_TAUA_UNIT_USED == STD_ON)||(PWM_TAUB_UNIT_USED == STD_ON) ||\
              (PWM_TAUC_UNIT_USED  == STD_ON)) */
/*******************************************************************************
**       Structure for configuring 32-bit period value for TAUJ timers        **
*******************************************************************************/
#if (PWM_TAUJ_UNIT_USED  == STD_ON)
typedef struct STagTdd_Pwm_TAUJProperties
{
  /* Default Period of channel in timer ticks (0 - 2^32) */
  Pwm_PeriodType ddDefaultPeriodOrDuty;
  /* Individual channel mask value */
  uint8 ucChannelMask;
}Tdd_Pwm_TAUJProperties;
#endif /* #if (PWM_TAUJ_UNIT_USED  == STD_ON) */

/*******************************************************************************
**            Data structure for PWM channel configuration                    **
*******************************************************************************/
typedef struct STagPwm_ChannelConfigType
{
  /* Pointer to the PWM Channel properties based on Timer Type */
  P2CONST(void, AUTOMATIC, PWM_CONFIG_CONST)pChannelProp;
  /* void pointer to user base address of Timer control register */
  P2VAR(void, AUTOMATIC, PWM_CONFIG_DATA)pCntlRegs;
  /* pointer to base address of CMOR register */
  P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)pCMORRegs;
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* void pointer to base address of Timer Interrupt control register */
  P2VAR(uint8, AUTOMATIC, PWM_CONFIG_DATA)pImrIntrCntlRegs;
  P2VAR(uint16, AUTOMATIC, PWM_CONFIG_DATA)pIntrCntlRegs;
  #endif
  /*
   * Bit 15-14:    00: This bits are already set during initialization for
   *                   clock source
   * Bit 13-12:    00: Selects the Operation Clock
   * Bit    11:     0: The channel operates as the slave channel in the
   *                   synchronous channel operation function.
   *                1: The channel operates as the master channel in the
   *                   synchronous channel operation function.
   * Bit 10- 8:   000: Valid only in software trigger start.
   *              100: Selects the INTn output signal of the master channel
   *              101: Selects the INTn output signal of the upper channel,
   *                   regardless of the setting of the master
   * Bit  7- 6:    00: Not Used, so set to 00
   * Bit  4- 0: 00001: Interval Timer mode *a
   *            01001: One Count mode *b
   *            10101: Pulse One Count mode *b
   *(Bit 0: *a: Outputs INTn (timer interrupt) at the start of count operation.
   *        *b: Enables start trigger detected during count operation)
   */
  uint16 usCMORegSettingsMask;

  #if(PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /*
   * If the value is equal to PWM_NO_CBK_CONFIGURED then the callback
   * function is not configured. If the value is other than
   * PWM_NO_CBK_CONFIGURED, it indicates index to the configured
   * call back function in the array Pwm_GstChannelNotifFunc
   */
  uint8 ucNotificationConfig;
  /* Mask value of the IMR Interrupt control register */
  uint8 ucImrMaskValue;
  #endif /* #if(PWM_NOTIFICATION_SUPPORTED == STD_ON) */
  /*
   * Offset with respect to base Timer control register of the master
   * channel of corresponding channel
   */
  uint8 ucMasterOffset;

  /*
   * Timer Unit Index in the Array Pwm_GstTAUABCUnitConfig /
   * Pwm_GstTAUJUnitConfig based on the channel belongs to
   * TAUA or TAUB or TAUC or TAUJ
   */
  uint8 ucTimerUnitIndex;
  /* PWM channel type, the channel belongs to TAUA or TAUB or TAUC or TAUJ */
  uinteger uiPwmTAUType:2;
  /*
   * Class type of the PWM channel (Fixed Period /Fixed Period Shifted /
   * Variable period)
   */
  Pwm_ChannelClassType enClassType;
  /* Idle state of the channel (HIGH/LOW) */
  uinteger uiIdleLevel:1;
  /*
   * uiTimerMode = true means channel acts as master channel
   * uiTimerMode = false means channel acts as slave channel
   */
  uinteger uiTimerMode:1;
}Tdd_Pwm_ChannelConfigType;

/*******************************************************************************
**                      Global configuration constants                        **
*******************************************************************************/

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#if ((PWM_TAUA_UNIT_USED  == STD_ON) || (PWM_TAUB_UNIT_USED  == STD_ON) || \
     (PWM_TAUC_UNIT_USED  == STD_ON))
/* Array of structures for TAUA/B/C Unit Channel Configuration */
extern CONST(Tdd_Pwm_TAUABCUnitConfigType, PWM_CONST) Pwm_GstTAUABCUnitConfig[];

/* Array of structures for Timer unit A/B/C channel Configuration */
extern CONST(Tdd_Pwm_TAUABCProperties, PWM_CONST) Pwm_GstTAUABCChannelProp[];
#endif

#if (PWM_TAUJ_UNIT_USED  == STD_ON)
/* Array of structures for TAUJ Unit Configuration */
extern CONST(Tdd_Pwm_TAUJUnitConfigType, PWM_CONST) Pwm_GstTAUJUnitConfig[];

/* Array of structures for Timer unit J channel Configuration */
extern CONST(Tdd_Pwm_TAUJProperties, PWM_CONST) Pwm_GstTAUJChannelProp[];
#endif

/* Array of structures for Channel Configuration */
extern CONST(Tdd_Pwm_ChannelConfigType, PWM_CONST) Pwm_GstChannelConfig[];

#if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
/* Array of structures for Synchronous start Configuration */
extern CONST(Tdd_PwmTAUSynchStartUseType, PWM_CONST)
                                             Pwm_GstTAUSynchStartConfig[];
#endif

/* Array to map channel to timer index */
extern CONST(uint8, PWM_CONST) Pwm_GaaTimerChIdx[];

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define PWM_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(PWM_NOTIFICATION_SUPPORTED == STD_ON)
/* Array for Notification status of timers configured */
extern VAR(uint8, PWM_NOINIT_DATA) Pwm_GaaNotifStatus[];
#endif

/* Array for Idle state status for all configured channels */
extern VAR(uint8, PWM_NOINIT_DATA) Pwm_GaaChannelIdleStatus[];

#define PWM_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PWM_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
