/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Icu_PBTypes.h                                               */
/* Version      = 3.0.8a                                                      */
/* Date         = 22-Sep-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros and structure datatypes for post build           */
/* parameters of ICU Driver                                                   */
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
 * V3.0.0:  26-Aug-2009  : Initial version
 *
 * V3.0.1:  05-Nov-2009  : As per SCR 088, I/O structure is updated to have
 *                         separate base address for USER and OS registers.
 *
 * V3.0.2:  30-Nov-2009  : As per SCR 154, pointer class PWM_CONFIG_DATA is
 *                         changed to ICU_CONFIG_DATA in the
 *                         structure STagTdd_Icu_TimerChannelConfigType.
 *
 * V3.0.3:  25-Feb-2010  : As per SCR 192, following changes are done:
 *                         1. A macro ICU_BYPASS_MASK is added.
 *                         2. The structure 'Tdd_Icu_ExtIntpConfigType'
 *                            is removed.
 *                         3. Pointer to the ICU Channel properties based
 *                            on Measurement Mode is moved from
 *                            'Tdd_Icu_ChannelConfigType' structure to
 *                            'Tdd_Icu_TimerChannelConfigType' structure.
 *
 * V3.0.4:  28-Jun-2010  : As per SCR 286, structures are modified to
 *                         support Timer Array Unit B.
 *
 * V3.0.5:  20-Jul-2010  : As per SCR 308, comments are updated for
 *                         Timer Array Unit B.
 *
 * V3.0.6:  26-Aug-2010  : As per SCR 335, following changes are done:
 *                         1. The elements uiDataValid and
 *                            uiFirstEdge are removed from and
 *                            blDutyCycleChannel is added in the structure
 *                            Tdd_Icu_SignalMeasureChannelRamDataType.
 *                         2. An element blTimestampingStarted is
 *                            added in structure
 *                            Tdd_Icu_TimeStampChannelRamDataType to check
 *                            whether timestamping is started or not.
 *
 * V3.0.7:  07-Apr-2011  : As per SCR 433, the type of "ICU_TAUAB_MAX_CNT_VAL"
 *                         is changed from uint16 to uint32.
 *
 * V3.0.8:  24-Jun-2011  : As per SCR 477, following changes are done:
 *                         1. Access size is updated for registers
 *                            TAUAnBRS, TAUJnBRS, TAUJnTS, TAUJnTT, TAUJnTE,
 *                            TAUABnCMURm, TAUABnCSRm, TAUABnCSCm, TAUJnCMURm,
 *                            TAUJnCSRm, TAUJnCSCm. Structures
 *                            STagTdd_Icu_TAUABUnitOsRegs,
 *                            STagTdd_Icu_TAUJUnitUserRegs,
 *                            STagTdd_Icu_TAUJUnitOsRegs,
 *                            STagTdd_Icu_TAUABChannelUserRegs,
 *                            STagTdd_Icu_TAUJChannelUserRegs are modified.
 *                         2. In structure STagTdd_Icu_TimerChannelConfigType,
 *                            data type is updated for variable
 *                            usChannelModeUserRegSettings to
 *                            ucChannelModeUserRegSettings.
 *                         3. ICU_OVERFLOW_BIT_MASK macro type is changed to
 *                            uint8 from uint16.
 *
 * V3.0.8a:  22-Sep-2011 : As per MANTIS #3551, the macro
 *                         ICU_CLEAR_INT_REQUEST_FLAG is added to clear the
 *                         interrupt request flag.
 *                         As per MANTIS #3708, the variable
 *                         ulPrevSignalActiveTime is added.
 *                         As per MANTIS #4019, when overflow occurs, a captured
 *                         timestamp value shall be always maximum count value
 *                         for each timer.(TAUA or TAUB = 0xFFFF,
 *                         TAUJ = 0xFFFFFFFF).
 *                         Therefore ICU_TAUAB_MAX_CNT_VAL is updated to 0xFFFF.
 *                         Copyright is updated.
 */
/******************************************************************************/

#ifndef ICU_PBTYPES_H
#define ICU_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Icu.h"
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM.h"
#endif
#include "V850_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define ICU_PBTYPES_AR_MAJOR_VERSION       ICU_AR_MAJOR_VERSION_VALUE
#define ICU_PBTYPES_AR_MINOR_VERSION       ICU_AR_MINOR_VERSION_VALUE
#define ICU_PBTYPES_AR_PATCH_VERSION       ICU_AR_PATCH_VERSION_VALUE

/*
 * File version information
 */
#define ICU_PBTYPES_SW_MAJOR_VERSION  3
#define ICU_PBTYPES_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define ICU_TRUE                            (boolean)0x01
#define ICU_FALSE                           (boolean)0x00
#define ICU_INITIALIZED                     (boolean)0x01
#define ICU_UNINITIALIZED                   (boolean)0x00
#define ICU_NO_CBK_CONFIGURED               (uint8)0xFF

/* Macro to avoid Magic numbers */
#define ICU_DBTOC_VALUE \
                                         ((ICU_VENDOR_ID_VALUE << 22) | \
                                          (ICU_MODULE_ID_VALUE << 14) | \
                                          (ICU_SW_MAJOR_VERSION_VALUE << 8) | \
                                          (ICU_SW_MINOR_VERSION_VALUE << 3))

#define ICU_CHANNEL_UNCONFIGURED            (uint8)0xFF
#define ICU_HW_EXT_INTP                     (uint8)0x00
#define ICU_HW_TAUA                         (uint8)0x01
#define ICU_HW_TAUB                         (uint8)0x02
#define ICU_HW_TAUJ                         (uint8)0x03

#define ICU_ZERO                            (uint8)0x00
#define ICU_ONE                             (uint8)0x01

#define ICU_WORD_ONE                        (uint16)0x0001
#define ICU_WORD_ZERO                       (uint16)0x0000
#define ICU_DOUBLE_ZERO                     (uint32)0x00000000

#define ICU_OVERFLOW_BIT_MASK               (uint8)0x01

#define ICU_TAUAB_MAX_CNT_VAL               (uint16)0xFFFF
#define ICU_TAUJ_MAX_CNT_VAL                (uint32)0xFFFFFFFFul

#define ICU_TIMER_RESET_VAL                 (uint16)0xFFFF
#define ICU_TAUAB_START_DWNCNT_VAL          (uint16)0xFFFF
#define ICU_TAUJ_START_DWNCNT_VAL           (uint32)0xFFFFFFFFul


#define ICU_BYPASS_MASK                     (uint8)0xF8
#define ICU_BOTH_EDGES_MASK                 (uint8)0x03
#define ICU_FALLING_EDGE_MASK               (uint8)0x02
#define ICU_RISING_EDGE_MASK                (uint8)0x01

#define ICU_CLEAR_INT_REQUEST_FLAG          (uint16)0xEFFF

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
** Data structure for Timer Array Units A and B user control registers        **
*******************************************************************************/

#if ((ICU_TAUA_UNIT_USED  == STD_ON)||(ICU_TAUB_UNIT_USED  == STD_ON))
typedef struct STagTdd_Icu_TAUABUnitUserRegs
{
  uint16 volatile usTAUABnTOL;
  uint16 volatile usReserved1;
  uint16 volatile usTAUABnRDT;
  uint16 volatile usReserved2;
  uint16 volatile usTAUABnRSF;
  uint16 volatile usReserved3;
  uint16 volatile usTAUABnTRO;
  uint16 volatile usReserved4;
  uint16 volatile usTAUABnTME;
  uint16 volatile usReserved5;
  uint16 volatile usTAUABnTDL;
  uint16 volatile usReserved6;
  uint16 volatile usTAUABnTO;
  uint16 volatile usReserved7;
  uint16 volatile usTAUABnTOE;
  uint16 volatile aaReserved8[177];
  uint16 volatile usTAUABnTE;
  uint16 volatile usReserved9;
  uint16 volatile usTAUABnTS;
  uint16 volatile usReserved10;
  uint16 volatile usTAUABnTT;
}Tdd_Icu_TAUABUnitUserRegs;
#endif

/*******************************************************************************
** Data structure for Timer Array Units A and B os control registers          **
*******************************************************************************/

#if ((ICU_TAUA_UNIT_USED  == STD_ON)||(ICU_TAUB_UNIT_USED  == STD_ON))
typedef struct STagTdd_Icu_TAUABUnitOsRegs
{
  uint16 volatile usTAUABnTPS;
  uint16 volatile usReserved1;
  uint8  volatile ucTAUAnBRS;
}Tdd_Icu_TAUABUnitOsRegs;
#endif

/*******************************************************************************
** Data structure for Timer Array Units J user control registers              **
*******************************************************************************/
#if(ICU_TAUJ_UNIT_USED == STD_ON)
typedef struct STagTdd_Icu_TAUJUnitUserRegs
{
  uint8  volatile ucTAUJnTE;
  uint8  volatile ucReserved1;
  uint16 volatile usReserved2;
  uint8  volatile ucTAUJnTS;
  uint8  volatile ucReserved3;
  uint16 volatile usReserved4;
  uint8  volatile ucTAUJnTT;
}Tdd_Icu_TAUJUnitUserRegs;
#endif /*   #if(ICU_TAUJ_UNIT_USED == STD_ON) */

/*******************************************************************************
** Data structure for Timer Array Units J os control registers                **
*******************************************************************************/
#if(ICU_TAUJ_UNIT_USED == STD_ON)
typedef struct STagTdd_Icu_TAUJUnitOsRegs
{
  uint16 volatile usTAUJnTPS;
  uint16 volatile usReserved1;
  uint8  volatile ucTAUJnBRS;
}Tdd_Icu_TAUJUnitOsRegs;
#endif /*   #if(ICU_TAUJ_UNIT_USED == STD_ON) */

/*******************************************************************************
** Data structure for Timer Array Units A and B channel user control          **
** registers                                                                  **
*******************************************************************************/
#if ((ICU_TAUA_UNIT_USED  == STD_ON)||(ICU_TAUB_UNIT_USED  == STD_ON))
typedef struct STagTdd_Icu_TAUABChannelUserRegs
{
  uint16 volatile usTAUABnCDRm;
  uint16 volatile aaReserved1[63];
  uint16 volatile usTAUABnCNTm;
  uint16 volatile aaReserved2[31];
  uint8  volatile ucTAUABnCMURm;
  uint8  volatile ucReserved3;
  uint16 volatile aaReserved4[63];
  uint8  volatile ucTAUABnCSRm;
  uint8  volatile ucReserved5;
  uint16 volatile aaReserved6[31];
  uint8  volatile ucTAUABnCSCm;
}Tdd_Icu_TAUABChannelUserRegs;
#endif /* End of
        * ((ICU_TAUA_UNIT_USED  == STD_ON)||(ICU_TAUB_UNIT_USED  == STD_ON))
        */

/*******************************************************************************
** Data structure for Timer Array Units J channel user control registers      **
*******************************************************************************/
#if(ICU_TAUJ_UNIT_USED == STD_ON)
typedef struct STagTdd_Icu_TAUJChannelUserRegs
{
  uint32 volatile ulTAUJnCDRm;
  uint32 volatile aaReserved1[3];
  uint32 volatile ulTAUJnCNTm;
  uint32 volatile aaReserved2[3];
  uint8  volatile ucTAUJnCMURm;
  uint8  volatile ucReserved3;
  uint16 volatile aaReserved4[7];
  uint8  volatile ucTAUJnCSRm;
  uint8  volatile ucReserved5;
  uint16 volatile aaReserved6[7];
  uint8  volatile ucTAUJnCSCm;
}Tdd_Icu_TAUJChannelUserRegs;
#endif /* End of (ICU_TAUJ_UNIT_USED == STD_ON) */

/*******************************************************************************
** Structure for TAU Unit configuration type                                  **
*******************************************************************************/
#if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)||\
    (ICU_TAUB_UNIT_USED == STD_ON))
typedef struct STagTdd_Icu_TAUUnitConfigType
{
  /* void pointer to base address of Timer Array Unit user control register */
  P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)pTAUnitUserCntlRegs;
  /* void pointer to base address of Timer Array Unit os control register */
  P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA)pTAUnitOsCntlRegs;

  #if (ICU_PRESCALER_CONFIGURED == STD_ON)
  /* TAU Unit prescaler for clock sources CK0, CK1, CK2, CK3 */
  uint16 usPrescaler;
  #endif
  /* TAUnit type
   * ICU_HW_TAUA - 0
   * ICU_HW_TAUB - 1
   * ICU_HW_TAUJ - 2
   */
  uint8  ucIcuUnitType;
  /* Mask value for all channels in a TAU */
  uint16 usTAUChannelMaskValue;
  #if (ICU_PRESCALER_CONFIGURED == STD_ON)
  #if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON))
  /* TAU Unit baudrate value for CK3 */
  uint8 ucBaudRate;
  /* Prescaler shared between PWM/GPT/ICU modules
   * 1: Prescaler for CK0 - CK3 has to be set by ICU
   * 0: Prescaler for CK0 - CK3 need not be set by ICU
   */
  #endif
  uinteger uiConfigurePrescaler:1;
  #endif
} Tdd_Icu_TAUUnitConfigType;
#endif
/*******************************************************************************
** Structure for using previous input(the spilt of one Port pin signal to two **
** TAU inputs): Applicable to TAUA0 & TAUA4                                   **
*******************************************************************************/
#if(ICU_PREVIOUS_INPUT_USED == STD_ON)
typedef struct STagTdd_IcuPreviousInputUseType
{
  /* void pointer to base address of Previous Input control registers
   */
  P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA) pPreviousInputCntlRegs;
  /* Registers TISLTA0 or TISLTA4:
   * Bit0: 1: Port pin signal is split into  TAUATTIN0 & TAUATTIN1
   * Bit1: 1: Port pin signal is split into  TAUATTIN2 & TAUATTIN3
   * Bit2: 1: Port pin signal is split into  TAUATTIN4 & TAUATTIN5
   * Bit3: 1: Port pin signal is split into  TAUATTIN6 & TAUATTIN7
   * Bit4: 1: Port pin signal is split into  TAUATTIN8 & TAUATTIN9
   * Bit5: 1: Port pin signal is split into  TAUATTIN10 & TAUATTIN11
   * Bit6: 1: Port pin signal is split into  TAUATTIN12 & TAUATTIN13
   * Bit7: 1: Port pin signal is split into  TAUATTIN14 & TAUATTIN15
   */
  uint8 ucPreviousInputMask;
  /* Index of Timer Unit in the Array Icu_GstTAUUnitConfig */
  uint8 ucTimerUnitIndex;
} Tdd_IcuPreviousInputUseType;
#endif

/*******************************************************************************
** Structure for configuring Edge Counting Timer channel                      **
*******************************************************************************/
typedef struct STagTdd_Icu_EdgeCountConfigType
{
  uint8 ucEdgeCounterRamIndex;
} Tdd_Icu_EdgeCountConfigType;

/*******************************************************************************
** Structure for configuring Signal Measurement Timer channel                 **
*******************************************************************************/
typedef struct STagTdd_Icu_SignalMeasureConfigType
{
  /*
   * ICU_LOW_TIME - 0
   * ICU_HIGH_TIME - 1
   * ICU_PERIOD_TIME - 2
   * ICU_DUTY_CYCLE - 3
   */
  uinteger uiSignalMeasurementProperty:2;
  uint8 ucSignalMeasureRamDataIndex;
  boolean blDutyCycleChannel;
} Tdd_Icu_SignalMeasureConfigType;

/*******************************************************************************
** Structure for configuring Timestamp Timer channel                          **
*******************************************************************************/
typedef struct STagTdd_Icu_TimeStampMeasureConfigType
{
  /*
   * ICU_LINEAR_BUFFER - 0
   * ICU_CIRCULAR_BUFFER - 1
   */
  uinteger uiTimestampMeasurementProperty:1;
  uint8 ucTimeStampRamDataIndex;
} Tdd_Icu_TimeStampMeasureConfigType;

/*******************************************************************************
** Structure to channel data into RAM                                         **
*******************************************************************************/
typedef struct STagTdd_Icu_ChannelRamDataType
{
  uinteger uiChannelStatus:1;
  uinteger uiWakeupEnable:1;
  uinteger uiNotificationEnable:1;
} Tdd_Icu_ChannelRamDataType;

/*******************************************************************************
** Structure to store Edge Counting channel data into RAM                     **
*******************************************************************************/
typedef struct STagTdd_Icu_EdgeCountChannelRamDataType
{
  uint8 ucActiveEdge;
  uinteger uiTimerOvfFlag:1;
  uint16 usIcuEdgeCount;
} Tdd_Icu_EdgeCountChannelRamDataType;

/*******************************************************************************
** Structure to store Timestamp channel data into RAM                         **
*******************************************************************************/
typedef struct STagTdd_Icu_TimeStampChannelRamDataType
{
  P2VAR(uint32,AUTOMATIC,ICU_CONFIG_DATA) pBufferPointer;
  uint16 usBufferSize;
  uint16 usTimestampIndex;
  uint16 usTimestampsCounter;
  uint16 usNotifyInterval;
  uint8 ucActiveEdge;
  boolean blTimestampingStarted;
} Tdd_Icu_TimeStampChannelRamDataType;

/*******************************************************************************
** Structure to store Signal Measurement channel data into RAM                **
*******************************************************************************/
typedef struct STagTdd_Icu_SignalMeasureChannelRamDataType
{
  uint32 ulSignalActiveTime;
  uint32 ulSignalPeriodTime;
  uint32 ulPrevSignalActiveTime;
} Tdd_Icu_SignalMeasureChannelRamDataType;

/*******************************************************************************
** Structure for ICU Channel information                                      **
*******************************************************************************/
typedef struct STagTdd_Icu_ChannelConfigType
{
  /* void pointer to base address of channel user control register structure */
  P2VAR(void, AUTOMATIC, ICU_CONFIG_DATA) pCntlRegs;
  /* uint8 pointer to base address of channel Interrupt mask register */
  P2VAR(uint8, AUTOMATIC, ICU_CONFIG_DATA) pImrIntrCntlRegs;
  /* uint16 pointer to base address of channel Interrupt control register */
  P2VAR(uint16, AUTOMATIC, ICU_CONFIG_DATA) pIntrCntlRegs;

  /* The wakeup value to be transmitted to EcuM */
  #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  EcuM_WakeupSourceType ddEcuMChannelWakeupInfo;
  #endif
  /* Individual channel mask value */
  uint16 usChannelMaskValue;
  /* The notification index that needs to be used.
   * If no notification is configured then NO_CBK_CONFIGURED
   * should be generated.
   */
  uint8 ucIcuNotificationIndex;
  /* IMR mask value */
  uint8 ucImrMaskValue;
  /* Measurement Mode of the ICU channel */
  /* ICU_MODE_SIGNAL_EDGE_DETECT - 0
   * ICU_MODE_SIGNAL_MEASUREMENT - 1
   * ICU_MODE_TIMESTAMP - 2
   * ICU_MODE_EDGE_COUNTER - 3
   */
  uinteger uiIcuMeasurementMode:2;
  /* Default Edge detection of the ICU channel */
  /* ICU_FALLING_EDGE - 0
   * ICU_RISING_EDGE - 1
   * ICU_BOTH_EDGES - 2
   */
  uinteger uiIcuDefaultStartEdge:2;
  /* Input capture channel type */
  /* ICU_HW_EXT_INTP - 0
   * ICU_HW_TAUA - 1
   * ICU_HW_TAUB - 2
   * ICU_HW_TAUJ - 3
   */
  uinteger uiIcuChannelType:2;
  /* Wakeup capability of the channel */
  uinteger uiIcuWakeupCapability:1;
} Tdd_Icu_ChannelConfigType;

/*******************************************************************************
** Structure for ICU Timer Channel information                                **
*******************************************************************************/
typedef struct STagTdd_Icu_TimerChannelConfigType
{
  /* Pointer to the ICU Channel properties based on Measurement Mode */
  P2CONST(void, AUTOMATIC, ICU_CONFIG_CONST) pChannelProp;
  /* pointer to base address of CMOR register */
  P2VAR(uint16, AUTOMATIC, ICU_CONFIG_DATA)pCMORRegs;
  /*
   * Bit 15-14:  00: This bits are already set during initialization for
   *                 clock source
   *
   * Bit 13-12:  00: Selects the prescaler output signal
   *                 (ICU_MODE_SIGNAL_MEASUREMENT) / (ICU_MODE_TIMESTAMP)
   *             01: Selects TINn input valid edge detection signal
   *                 (ICU_MODE_EDGE_COUNTER)
   *
   * Bit 11:     0: Independent Channel operation functions
   *
   * Bit 10-8:   000: Selects software start trigger (ICU_MODE_EDGE_COUNTER)
   *             001: Selects the TINn input valid edge detection signal
   *                  (ICU_MODE_SIGNAL_MEASUREMENT)(ICU_PERIOD_TIME)
   *                  / (ICU_MODE_TIMESTAMP)
   *
   *             010: Selects the TINn input valid edge detection signal as the
   *                  start signal and the reverse edge detection signal as the
   *                  stop signal.
   *                  (ICU_MODE_SIGNAL_MEASUREMENT)(ICU_HIGH_TIME, ICU_LOW_TIME)
   *
   * Bit 7-6:    00: Not used  (ICU_MODE_EDGE_COUNTER)
   *
   *             01: Sets OVF when the counter reaches FFFFH,
   *                 clears OVF when CSCn:CLOV = 1
   *                 Captures the counter value upon detection of a TINn
   *                 input valid edge.
   *                 (ICU_MODE_SIGNAL_MEASUREMENT) (ICU_PERIOD_TIME)
   *                 (ICU_HIGH_TIME, ICU_LOW_TIME), (ICU_MODE_TIMESTAMP)
   *
   * Bit 4-1:    0010: Sets the Capture mode.
   *                   (ICU_MODE_SIGNAL_MEASUREMENT) (ICU_PERIOD_TIME)
   *
   *             0011: Event Count Mode (ICU_MODE_EDGE_COUNTER)
   *
   *             0110: Sets the Capture & One Count mode
   *                  (ICU_MODE_SIGNAL_MEASUREMENT)(ICU_HIGH_TIME, ICU_LOW_TIME)
   *
   *             1011: Sets the Count Capture mode (ICU_MODE_TIMESTAMP)
   *
   * Bit0:       0: Neither outputs INTn nor toggles TOUTn at operation startup
   *             1: Outputs INTn at operation startup
   */
  uint16 usChannelModeOSRegSettings;
  /*
   * Bit 1-0: (ICU_MODE_SIGNAL_MEASUREMENT) (ICU_PERIOD_TIME),
   *          (ICU_MODE_EDGE_COUNTER), (ICU_MODE_TIMESTAMP)
   *          00: Selects falling edge detection
   *          01: Selects rising edge detection
   *          10: Selects rising and falling edge detection
   *          11: Setting prohibited (rising and falling edge detection)
   *
   *          (ICU_MODE_SIGNAL_MEASUREMENT) (ICU_HIGH_TIME, ICU_LOW_TIME)
   *          10: Low width measurement
   *          11: High width measurement
   *
   */
  uint8 ucChannelModeUserRegSettings;
  /* Index of Timer Unit in the Array Icu_GstTAUUnitConfig */
  uint8 ucTimerUnitIndex;

} Tdd_Icu_TimerChannelConfigType;

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Declaration for ICU Channel Configuration */
extern CONST(Tdd_Icu_ChannelConfigType, ICU_CONST) Icu_GstChannelConfig[];

/* Declaration for ICU Channel Configuration */
extern CONST(Tdd_Icu_TimerChannelConfigType, ICU_CONST)
                                                Icu_GstTimerChannelConfig[];

/* Declaration for Timestamp ICU Channel Configuration */
extern CONST(Tdd_Icu_TimeStampMeasureConfigType, ICU_CONST)
                                             Icu_GstTimestampMeasureConfig[];

/* Declaration for Edge Counting ICU Channel Configuration */
extern CONST(Tdd_Icu_EdgeCountConfigType, ICU_CONST) Icu_GstEdgeCountConfig[];

/* Declaration for SignalMeasurement ICU Channel Configuration */
extern CONST(Tdd_Icu_SignalMeasureConfigType, ICU_CONST)
                                                 Icu_GstSignalMeasureConfig[];

#if((ICU_TAUA_UNIT_USED == STD_ON)||(ICU_TAUJ_UNIT_USED == STD_ON)|| \
    (ICU_TAUB_UNIT_USED == STD_ON))
/* Array of structures for Hardware Configuration */
extern CONST(Tdd_Icu_TAUUnitConfigType, ICU_CONST) Icu_GstTAUUnitConfig[];
#endif

#if(ICU_PREVIOUS_INPUT_USED == STD_ON)
/* Array of structures for Previous Input Configuration */
extern CONST(Tdd_IcuPreviousInputUseType, ICU_CONST)
                                                  Icu_GstPreviousInputConfig[];
#endif

/* Array to map channel index */
extern CONST(uint8, ICU_CONST) Icu_GaaChannelMap[];

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


#define ICU_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* RAM Allocation of Channel data */
extern VAR(Tdd_Icu_ChannelRamDataType, ICU_NOINIT_DATA) Icu_GstChannelRamData[];

/* RAM Allocation of Timestamp channel data */
extern VAR(Tdd_Icu_TimeStampChannelRamDataType, ICU_NOINIT_DATA)
                                                     Icu_GstTimestampRamData[];

/* RAM Allocation of Signal Measure Channel data */
extern VAR(Tdd_Icu_SignalMeasureChannelRamDataType, ICU_NOINIT_DATA)
                                                 Icu_GstSignalMeasureRamData[];

/* RAM Allocation of Edge Counting Channel data */
extern VAR(Tdd_Icu_EdgeCountChannelRamDataType,ICU_NOINIT_DATA)
                                                     Icu_GstEdgeCountRamData[];

#define ICU_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ICU_PBTYPES_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
