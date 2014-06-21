/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Mcu_PBTypes.h                                               */
/* Version      = 3.0.9                                                       */
/* Date         = 18-Jul-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2010-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post-build Time Parameters      */
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
/*              Devices:        Fx4                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0: 02-Jul-2010 : Initial Version
 *
 * V3.0.1: 28-Jul-2010 : As per SCR 320 following changes are made,
 *                       1 ucFoutDivReg element added in Tdd_Mcu_ClockSetting
 *                       2 MCU_ISO1_DEEPSTOP_MODE_REGSTP and
 *                         MCU_ISO0_DEEPSTOP_MODE_REGSTP macros added with
 *                         precompile option of MCU_DEEPSTOP_WAKE_PIN.
 *                       3 MCU_FOUT_DISABLE_MASK and MCU_VCPC_ENABLE_VALUE
 *                         macros are added.
 *
 * V3.0.2: 06-Jan-2011 : As per SCR 392 following macros are added,
 *                       MCU_CKSC_AW06_ADDRESS,
 *                       and MCU_CKSC_8MHZ_INITIAL_VAL.
 *
 * V3.0.3: 25-Feb-2011 : As per SCR 420 MCU_WRITE_DATA macro value modified.
 *
 * V3.0.4: 17-Jun-2011 : As per SCR 468 following changes are made
 *                       1 Data types corrected for elements in
 *                         Tdd_Mcu_ClockSetting and Tdd_Mcu_ModeSetting
 *                         data structures.
 *                       2 MCU_INVERTED_ZERO and MCU_VCPC_ENABLE_MASK macros are
 *                         added.
 *                       3 Precompile option added for voltage comparator and IO
 *                         Reset register related data elements and macros.
 *
 * V3.0.5: 29-Jun-2011 : As per SCR 481, MCU_INVERTED_ZERO macro is removed.
 * V3.0.5a: 18-Oct-2011  : Copyright is updated.
 *
 * V3.0.6: 17-May-2012 : As per SCR 014, following changes are made:
 *                       1 Precompile options added for elements
 *                         ulPLL2ControlValue, ulSubOscStabTime and
 *                         ulPLL2StabTime in Tdd_Mcu_ClockSetting structure.
 *                       2 MCU_CKSC000_PLL_LOW_VAL, MCU_CKSC000_PLL_HIGH_VAL
 *                         and MCU_PLL_DISABLE macros are removed and macro
 *                         MCU_PWS_PSS_MSK is added.
 *
 * V3.0.7: 15-Mar-2013 : As per SCR 091, The following changes have been made,
 *                       1. Alignment is changed as per code guidelines.
 *                       2. As per OPCN requirement, Macro added for
 *                          Mcu_ConfigureAWO7 API.
 *                       3. As mantis #5465, Macro "MCU_PSC1_ISOWU_MSK" is Added
 *                          as part of Mcu_Iso1SoftWakeUp API.
 *                       4. "MCU_MAINOSC_STAB" Macro is added as part of
 *                           Mcu_RestartClocks API.
 *                       5. "MCU_CKSC_STAB_COUNT" macro is added as part of the
 *                           Mcu_RestartClocks API.
 *                       6. MCU_IOHOLD_MASK_CLEAR macro is added.
 * V3.0.8: 12-Jul-2013 : As per mantis 11731 and SCR xxx, following changes
 *                       are made:
 *                       Macro "MCU_LONG_WORD_EIGHTEEN and
 *                       MCU_LONG_WORD_SEVENTYFOUR" are added.
 * V3.0.9: 18-Jul-2013 : As per Mantis 11731 and SCR xxx Mcaro
 *                       "MCU_LONG_WORD_TEN and MCU_LONG_WORD_TWENTYTWO"
 *                       are added.
 */
/******************************************************************************/

#ifndef MCU_PBTYPES_H
#define MCU_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Mcu.h"    /* To include the component file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define MCU_PBTYPES_AR_MAJOR_VERSION  MCU_AR_MAJOR_VERSION_VALUE
#define MCU_PBTYPES_AR_MINOR_VERSION  MCU_AR_MINOR_VERSION_VALUE
#define MCU_PBTYPES_AR_PATCH_VERSION  MCU_AR_PATCH_VERSION_VALUE

/* File version information */
#define MCU_PBTYPES_SW_MAJOR_VERSION  3
#define MCU_PBTYPES_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Macros to avoid Magic numbers */
#define MCU_DBTOC_VALUE \
                                      ((MCU_VENDOR_ID_VALUE << 22) | \
                                       (MCU_MODULE_ID_VALUE << 14) | \
                                       (MCU_SW_MAJOR_VERSION_VALUE << 8) | \
                                       (MCU_SW_MINOR_VERSION_VALUE << 3))

#define MCU_CLMA2_CMPH                (uint16)0x0272

#define MCU_CLMA2_CMPL                (uint16)0x01C6

#define MCU_ZERO                      (uint8)0x00

#define MCU_LONG_WORD_ZERO            (uint32)0x00000000ul

#define MCU_LONG_WORD_ONE             (uint32)0x00000001ul

#define MCU_LONG_WORD_TWO             (uint32)0x00000002ul

#define MCU_LONG_WORD_FOUR            (uint32)0x00000004ul

#define MCU_LONG_WORD_FIVE            (uint32)0x00000005ul

#define MCU_LONG_WORD_SEVEN           (uint32)0x00000007ul

#define MCU_LONG_WORD_TEN             (uint32)0x0000000Aul

#define MCU_LONG_WORD_TWENTYTWO       (uint32)0x00000022ul

#define MCU_LONG_WORD_EIGHTEEN        (uint32)0x00000018ul

#define MCU_LONG_WORD_SEVENTYFOUR     (uint32)0x00000074ul

#define MCU_WAKEUP_FACTOR_CLR         (uint32)0xFFFFFFFFul

#define MCU_IOHOLD_MASK               (uint32)0x00000002ul

#define MCU_PSC1_ISOWU_MSK            (uint32)0x00000004ul

#define MCU_PSS_ONE                   (uint32)0x00000080ul

#define MCU_PSS_ZERO                  (uint32)0x00000001ul

#define MCU_ONE                       (uint8)0x01

#define MCU_INVERTED_ONE              (uint8)0xFE

#define MCU_FIVE                      (uint8)0x05

#define MCU_RESF_CLEAR                (uint32)0x000001EFul

#define MCU_IOHOLD_MASK_CLEAR         (uint32)0x00000020ul

#define MCU_INITIALIZED               (uint8)0x01

#define MCU_UNINITIALIZED             (uint8)0x00

#define MCU_TRUE                      (uint8)0x01

#define MCU_FALSE                     (uint8)0x00

/* Value for selection of clock source as MainOSC */
#define MCU_MAIN_OSC_SELECTED         (uint8)0x01

/* Value for selection of clock source as SubOSC */
#define MCU_SUB_OSC_SELECTED          (uint8)0x02

/* Value for selection of clock source as 8 MHz */
#define MCU_8MHZ_OSC_SELECTED         (uint8)0x04

/* Value for selection of clock source as PLL0 */
#define MCU_PLL0_CLOCK_SELECTED       (uint8)0x08

/* Value for selection of clock source as PLL1 */
#define MCU_PLL1_CLOCK_SELECTED       (uint8)0x10

/* Value for selection of clock source as PLL2 */
#define MCU_PLL2_CLOCK_SELECTED       (uint8)0x20

/* Value for invalid setting*/
#define MCU_INVALID_SETTING           (uint8)0xFF

/* Definition of uninitialized RESET value */
#define MCU_RESET_UNINIT              (uint8)0xFF

/* Definition for Reset source check values */
#define MCU_POR                       (uint32)0x00000000ul
#define MCU_SWR                       (uint32)0x00000001ul
#define MCU_WDR0                      (uint32)0x00000002ul
#define MCU_WDR1                      (uint32)0x00000004ul
#define MCU_CLM0                      (uint32)0x00000008ul
#define MCU_CLM2                      (uint32)0x00000020ul
#define MCU_CLM3                      (uint32)0x00000040ul
#define MCU_LVI                       (uint32)0x00000080ul
#define MCU_TER                       (uint32)0x00000100ul
#define MCU_DEBR                      (uint32)0x00000200ul

/* Data to be written to the protection command register to enable
 * writing to the write protected register
 */
#define MCU_WRITE_DATA                (uint8)0xA5

/* Definitions of values to be written to Software reset register
 * to perform reset
 */
#define MCU_RES_CORRECT_VAL           (uint32)0x00000001ul
#define MCU_RES_INVERTED_VAL          (uint32)0xFFFFFFFEul

/* Maximum number of Clock setting */
#define MCU_MAX_CLK_SET               (uint8)0x03

/* Maximum number of Mode setting */
#define MCU_MAX_MODE_SET              (uint8)0x08

#define MCU_MAIN_OSC_MASKED           (uint8)0x01

#define MCU_SUB_OSC_MASKED            (uint8)0x02

#define MCU_RING_OSC_MASKED           (uint8)0x04

#define MCU_PLL0_MASKED               (uint8)0x08

#define MCU_PLL1_MASKED               (uint8)0x10

#define MCU_PLL2_MASKED               (uint8)0x20

#define MCU_MAIN_OSC_ON               (uint32)0x00000002ul

#define MCU_SUB_OSC_ON                (uint32)0x00000002ul

#define MCU_RING_OSC_ON               (uint32)0x00000002ul

#define MCU_PLL0_ON                   (uint32)0x00000002ul

#define MCU_PLL1_ON                   (uint32)0x00000002ul

#define MCU_PLL2_ON                   (uint32)0x00000002ul

#define MCU_ISO1_STOP_MODE            (uint32)0x00000001ul

#define MCU_ISO0_STOP_MODE            (uint32)0x00000001ul

#define MCU_MAINOSC_STAB              (uint32)0x0000000Ful

#define MCU_CKSC_STAB_COUNT           (uint32)0x0000FFFFul

/* Defines for AWO7 clock modifications in STOP and DEEPSTOP mode */
#define MCU_CKSCAO7_REGISTER          *((volatile uint32  *)0xFF422070ul)

#define MCU_CSCSTATAO7_REGISTER       *((volatile uint32  *)0xFF422074ul)

#define MCU_CKSCAO7_MASK              (uint32)0x0000000Eul

#define MCU_CKSCAO7_SLOW_VAL          (uint32)0x0000000Aul

#define MCU_CKSCAO7_DEFAULT_VAL       (uint32)0x00000006ul


#if (MCU_DEEPSTOP_WAKE_PIN == STD_ON)
#define MCU_ISO1_DEEPSTOP_MODE_REGSTP (uint32)0x00000013ul
#define MCU_ISO0_DEEPSTOP_MODE_REGSTP (uint32)0x00000013ul
#endif

#define MCU_ISO1_DEEPSTOP_MODE        (uint32)0x00000003ul
#define MCU_ISO0_DEEPSTOP_MODE        (uint32)0x00000003ul

#define MCU_IOHOLD_CLR                (uint32)0x00000008ul

#define MCU_PSS_ZERO_ISO_ONE          (uint32)0x00000001ul

#define MCU_POWER_ON_MASK             (uint32)0x00000004ul

#define MCU_CLMA0_ENABLE              (uint8)0x01

#define MCU_CLMA2_ENABLE              (uint8)0x04

#define MCU_CLMA3_ENABLE              (uint8)0x08

#define MCU_LONG_WORD_THREE           (uint32)0x00000003ul

#define MCU_ISO0_RUN_MODE             (uint32)0x00000001ul

#define MCU_ISO1_RUN_MODE             (uint32)0x00000001ul

#define MCU_MODE_ISO1_STOP            (uint32)0x00000081ul

#define MCU_MODE_ISO1_DEEPSTOP        (uint32)0x00000082ul

#define MCU_PWS_REG_MASK              (uint32)0x00000081ul

#define MCU_PWS_DEEPSTOP_STS          (uint32)0x00000080ul

#define MCU_WUFH0_MASK                (uint32)0x00007FFFul

#define MCU_PLL_CLKSTAB_MASK          (uint32)0x00000001ul

#define MCU_BURWE_SET_VALUE           (uint8)0x01

#define MCU_ROSCE_STPMK               (uint32)0x00000004ul

#define MCU_LOOPCOUNT_MAX_VAL         (uint32)0xFFFFFFFFul

#define MCU_MSB_MASK                  (uint32)0xFFFF0000ul

#define MCU_HIGH_RING_STAB_CNT        (uint32)0x85099E00ul

#define MCU_MAIN_CLK_STAB_CNT         (uint32)0xC78E6D00ul

#define MCU_PLL_CLK_STAB_CNT          (uint32)0xFFFFFFFFul

#define MCU_CKSC_MASK_VALUE           (uint32)0xFFFFFFFEul

#define MCU_PSC1_POF_MASK             (uint32)0x00000002ul

#define MCU_FOUT_DISABLE_MASK         (uint16)0x0000

#if ((MCU_VCPC0CTL0_ENABLE == STD_ON) || (MCU_VCPC0CTL1_ENABLE == STD_ON))
#define MCU_VCPC_ENABLE_VALUE         (uint8)0x80
#define MCU_VCPC_ENABLE_MASK          (uint8)0x7F
#endif

#define MCU_CKSC000_ADDRESS           ((uint32)0xFF426000ul)

#define MCU_CKSC000_INITIAL_VAL       (uint32)0x00000074ul

#define MCU_CKSC_AW06_ADDRESS         ((uint32 *)0xFF422060ul)

#define MCU_CKSC_8MHZ_INITIAL_VAL     (uint32)0x0000000Eul

#define MCU_PWS_PSS_MSK               (uint32)0x00000080ul

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                Port Control Registers Data Structure                       **
*******************************************************************************/

typedef struct STagMcuPortRegisters
{
  uint32 ulPSRn;
} Tdd_Mcu_PortRegisters;

/*******************************************************************************
**                      Clock Setting Data Structure                          **
*******************************************************************************/

typedef struct STagMcuClockSetting
{
  /* Details of PLL/SSCG for PLL0*/
  uint32 ulPLL0ControlValue;
  /* Details of PLL/SSCG for PLL1*/
  uint32 ulPLL1ControlValue;
  #if (MCU_PLL2_ENABLE == STD_ON)
  /* Details of PLL/SSCG for PLL2*/
  uint32 ulPLL2ControlValue;
  #endif
  #if (MCU_SUBOSC_ENABLE == STD_ON)
   /* Sub Oscillator Stabilization Time */
  uint32 ulSubOscStabTime;
  #endif
  /* PLL0 Oscillator Stabilization Time */
  uint32 ulPLL0StabTime;
  /* PLL1 Oscillator Stabilization Time */
  uint32 ulPLL1StabTime;
  #if (MCU_PLL2_ENABLE == STD_ON)
  /* PLL2 Oscillator Stabilization Time */
  uint32 ulPLL2StabTime;
  #endif
  /* Main Oscillator Stabilization Time */
  uint32 ulMainOscStabTime;
  /* FOUT Clock Divider register */
  uint16 usFoutDivReg;
  /* Details of selected clock sources */
  uint8 ucSelectedSrcClock;
  /* Value for MOSCC register */
  uint8 ucMosccRegValue;
  /* Selection of STPMK bit in all clock sources */
  uint8 ucSelectedSTPMK;
  /* Value of number of clock registers ISo0 selected */
  uint8 ucNoOfIso0CkscReg;
  /* Value of number of clock registers ISo1 selected */
  uint8 ucNoOfIso1CkscReg;
  /* Value of number of clock registers for AWO selected */
  uint8 ucNoOfAwoCkscReg;
  /* Value of number of PLL clock registers ISo0 selected */
  uint8 ucNoOfPllIso0CkscReg;
  /* Value of number of PLL clock registers for ISo1 selected */
  uint8 ucNoOfPllIso1CkscReg;
   /* Value of number of PLL  clock registers for AWO selected */
  uint8 ucNoOfPllAwoCkscReg;
  /* CKSC Index offset */
  uint8 ucCkscIndexOffset;
  /* PLL CKSC Index offset */
  uint8 ucCkscPllIndexOffset;
} Tdd_Mcu_ClockSetting;

/*******************************************************************************
**Structure pointing to the Pn register address of each Port group configured **
*******************************************************************************/

typedef struct STagMcuPortGroupAddress
{
  P2VAR(Tdd_Mcu_PortRegisters, AUTOMATIC, MCU_CONFIG_DATA)pPortGroupAddress;
} Tdd_Mcu_PortGroupAddress;

/*******************************************************************************
**                  Power Mode Setting Data Structure                         **
*******************************************************************************/

typedef struct STagMcuModeSetting
{
  /* Value of Power Down Wakeup Type for ISO0 L0Area */
  uint32 ulPowerDownWakeupTypeL0;
  /* Value of Power Down Wakeup Type for ISO0 M0Area */
  uint32 ulPowerDownWakeupTypeM0;
  /* Value of Power Down Wakeup Type for ISO0 H0Area */
  uint32 ulPowerDownWakeupTypeH0;
  /* Value of Power Down Wakeup Type for ISO1 L1Area */
  uint32 ulPowerDownWakeupTypeL1;
  /* Value of Power Down Wakeup Type for ISO1 M1Area */
  uint32 ulPowerDownWakeupTypeM1;
  /* Value of Power Down Wakeup Type for ISO1 H1Area */
  uint32 ulPowerDownWakeupTypeH1;
  /* Value to Enable/Disable wakeup for ISO0 and ISO1 area */
  uint32 ulOscWufMsk;
  /* Value of Power Down Mode control register0 */
  uint8 ucPSC0RegValue;
  /* Value of Power Down Mode control register1 */
  uint8 ucPSC1RegValue;
  #if(MCU_IORES0_ENABLE == STD_ON)
  /* IO reset register0 to reset different ports before power down */
  uint8 ucIOResetReg0;
  #endif  /* #if(MCU_IORES0_ENABLE == STD_ON) */
  #if(MCU_IORES1_ENABLE == STD_ON)
  /* IO reset register1 to reset different ports before power down */
  uint8 ucIOResetReg1;
  #endif /* #if(MCU_IORES1_ENABLE == STD_ON) */
  /* Power down modes */
  uint8 ucModeType;

} Tdd_Mcu_ModeSetting;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Global array for offset of configured CKSC registers */
extern CONST(uint16, MCU_CONST)Mcu_GaaCkscRegOffset[];

/* Global array for the value of configured CKSC registers */
extern CONST(uint32, MCU_CONST)Mcu_GaaCkscRegValue[];

/* Global array for Clock Setting Configuration */
extern CONST(Tdd_Mcu_ClockSetting, MCU_CONST) Mcu_GstClockSetting[];

/* Global array for Mode Setting Configuration */
extern CONST(Tdd_Mcu_ModeSetting, MCU_CONST) Mcu_GstModeSetting[];

/* Global array for Clock setting Index Mapping */
extern CONST(uint8, MCU_CONST)Mcu_GaaClkSettingIndexMap[];

/* Global array of port registers */
extern CONST(Tdd_Mcu_PortGroupAddress, MCU_CONST) Mcu_GaaPortGroup[];

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define MCU_START_SEC_BURAM_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global RAM array for back up of Port group registers */
extern VAR(uint32, MCU_CONFIG_DATA) Mcu_GaaRamPortGroup[];

#define MCU_STOP_SEC_BURAM_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#endif /* MCU_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
