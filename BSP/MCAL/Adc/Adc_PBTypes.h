/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Adc_PBTypes.h                                               */
/* Version      = 3.1.2                                                       */
/* Date         = 04-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
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
/*              Devices:        Xx4                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:  10-Jul-2009  : Initial version
 *
 * V3.0.1:  12-Oct-2009  : As per SCR 052, the following changes are made
 *                         1. Unnecessary macros are removed and macros
 *                            required are added.
 *                         2. IO structure required for PIC macro is added and
 *                            Tdd_Adc_HWGroupTriggType is updated for PIC macro
 *                            enhancement.
 *                         3. Tdd_Adc_HwUnitConfigType, Tdd_Adc_GroupConfigType,
 *                            Tdd_Adc_HwUnitRamData are updated.
 *                         4. Size of the array in the extern of
 *                            Adc_GstRunTimeData is updated.
 *
 * V3.0.2:  05-Nov-2009  : As per SCR 088, I/O structure is updated to have
 *                         separate base address for USER and OS registers.
 *
 * V3.0.3:  02-Dec-2009  : As per SCR 157, the following changes are made
 *                         1. Structure Tdd_Adc_DmaUnitConfig is updated.
 *                         2. Adc_GpRunTimeData declaration is changed.
 *
 * V3.0.4:  05-Jan-2010  : As per SCR 179, Tdd_Adc_ChannelGroupRamData
 *                         structure is updated.
 *
 * V3.0.5:  26-Feb-2010  : As per SCR 200, the following changes are made:
 *                         1. A macro ADC_CLEAR_CHANNEL_LIST is added.
 *                         2. Queue related RAM variables and parameters are
 *                            optimized by adding pre-compile option.
 *
 * V3.0.6:  01-Jul-2010  : As per SCR 295, interrupt control register is
 *                         replaced by IMR register.
 *
 * V3.0.7:  20-Jul-2010  : As per SCR 309, following changes are made:
 *                         1. In structure Tdd_Adc_GroupConfigType, new
 *                            parameter ucDmaChannelIndex is added.
 *                         2. In structure Tdd_Adc_HwUnitConfigType, parameter
 *                            pCGmDmaConfig is deleted.
 *
 * V3.0.8:  28-Jul-2010  : As per SCR 316, following changes are made:
 *                         1. pIntpAddress parameter is added to
 *                            structure Tdd_Adc_HwUnitConfigType, which will be
 *                            used to clear the pending interrupts.
 *                         2. Macro ADC_CLEAR_INT_REQUEST_FLAG is added.
 *
 * V3.1.0:  27-Jul-2011  : Modified for DK-4.
 * V3.1.1:  14-Feb-2012  : Merged the fixes done for Fx4L Adc driver.
 *
 * V3.1.2:  04-Jun-2012  : As per SCR 019, following changes are made:
 *                         1. New macro ADC_NO_DMA_CHANNEL_INDEX is added.
 *                         2. Compiler version is removed from environment 
 *                            section.
 *                         3. File version is changed.
 */
/******************************************************************************/

#ifndef ADC_PBTYPES_H
#define ADC_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Adc.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define ADC_PBTYPES_AR_MAJOR_VERSION   ADC_AR_MAJOR_VERSION_VALUE
#define ADC_PBTYPES_AR_MINOR_VERSION   ADC_AR_MINOR_VERSION_VALUE
#define ADC_PBTYPES_AR_PATCH_VERSION   ADC_AR_PATCH_VERSION_VALUE

/* File version information */
#define ADC_PBTYPES_SW_MAJOR_VERSION   3
#define ADC_PBTYPES_SW_MINOR_VERSION   1
#define ADC_PBTYPES_SW_PATCH_VERSION   2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (ADC_SW_MAJOR_VERSION != ADC_PBTYPES_SW_MAJOR_VERSION)
#error "Software major version of Adc_PBTypes.h and Adc.h did not match!"
#endif
#if (ADC_SW_MINOR_VERSION != ADC_PBTYPES_SW_MINOR_VERSION)
#error "Software minor version of Adc_PBTypes.h and Adc.h did not match!"
#endif

#define ADC_DBTOC_VALUE \
                                         ((ADC_VENDOR_ID_VALUE << 22) | \
                                          (ADC_MODULE_ID_VALUE << 14) | \
                                          (ADC_SW_MAJOR_VERSION_VALUE << 8) | \
                                          (ADC_SW_MINOR_VERSION_VALUE << 3))

#define ADC_FALSE                           (uint8)0
#define ADC_TRUE                            (uint8)1
#define ADC_ZERO                            (uint8)0
#define ADC_ONE                             (uint8)1
#define ADC_TWO                             (uint8)2
#define ADC_THREE                           (uint8)3
#define ADC_FOUR                            (uint8)4
#define ADC_FIVE                            (uint8)5

#define ADC_ZERO_SHORT                      (uint16)0
#define ADC_ZERO_LONG                       (uint32)0

/* Adc Conversion operation */
#define ADC_CONTINUOUS                      (uint8)0
#define ADC_ONCE                            (uint8)1

/* Start/Stop ADC Conversion macros */
#define ADC_START_CONVERSION                (uint8)0x01
#define ADC_STOP_CONVERSION                 (uint8)0x01
#define ADC_RESULT_FLAG_MASK                (uint8)0x00

/* Complete channel list mask */
#define ADC_COMPLETE_CHANNEL_MASK           (uint32)0xFFFFFFFFul
/* Clear channel list mask */
#define ADC_CLEAR_CHANNEL_LIST              (uint32)0x00000000ul

/* Queue status macros */
#define ADC_QUEUE_EMPTY                     (uint8)0
#define ADC_QUEUE_FILLED                    (uint8)1
#define ADC_QUEUE_FULL                      (uint8)2

/* ADC enable */
#define ADC_ENABLE_BIT                      (uint16)0x0080
/* ADC disable */
#define ADC_DISABLE_BIT                     (uint16)0xFF7F

/* DMA disable */
#define ADC_DMA_DISABLE                     (uint8)0xFE
/* DMA enable */
#define ADC_DMA_ENABLE                      (uint8)0x01
/* DMA channel not configured */
#define ADC_NO_DMA_CHANNEL_INDEX            (uint8)0xFF
/* DMA transfer request */
#define ADC_DMA_TRANSFER                    (uint16)0x0001
/* DMA source chip select */
#define ADC_DMA_SRC_SELECT                  (uint16)0x0002
/* DMA destination chip select */
#define ADC_DMA_DEST_SELECT                 (uint16)0x0002
/* DMA setting value */
#define ADC_DMA_SETTINGS                    (uint16)0x2081
/* DMA MLE bit set mask value */
#define ADC_DMA_CONTINUOUS                  (uint16)0x1000
/* DMA MLE bit set mask value */
#define ADC_DMA_ONCE                        (uint16)0xEFFF
/* DMA mask to avoid reading from next location */
#define ADC_DMA_CLEAR_NEXT                  (uint16)0x7FFF
/* DMA mask to read from next location */
#define ADC_DMA_SET_NEXT                    (uint16)0x8000
/* DMA mask to set the INF bit */
#define ADC_DMA_SET_INF                     (uint16)0x0800
/* DMA transfer completion status */
#define ADC_DMA_TRANSFER_COMPLETION         (uint8)0x80
/* DMA transfer completion status clear */
#define ADC_DMA_TRANSFER_CLEAR              (uint8)0x7F

/* Streaming number of samples mask */
#define ADC_DUMMY                           (uint16)0x0000
#define ADC_ONE_TIME_CONVERSION             (uint16)0x0000
#define ADC_TWO_TIME_CONVERSION             (uint16)0x0001
#define ADC_THREE_TIME_CONVERSION           (uint16)0x0002
#define ADC_FOUR_TIME_CONVERSION            (uint16)0x0003

/* Macro to clear the interrupt request flag EIRFn */
#define ADC_CLEAR_INT_REQUEST_FLAG          (uint16)0xEFFF

/* Streaming clear mask */
#define ADC_CG0_STREAM_CLEAR_MASK           (uint16)0xFFFC
#define ADC_CG1_STREAM_CLEAR_MASK           (uint16)0xFFF3
#define ADC_CG2_STREAM_CLEAR_MASK           (uint16)0xFFCF

/* Operation mode and Trans mode clear mask */
#define ADC_OPERATION_CLEAR_MASK            (uint32)0xFFCFFFEFul

/* Operation mode enable mask */
#define ADC_CG0_CONV_ONCE                   (uint32)0x00200010ul
#define ADC_CG0_CONV_CONTINUOUS             (uint32)0x00300010ul

/* External and Timer Trigger clear mask */
#define ADC_CG0_EXTTRIG_CLEAR_MASK          (uint32)0xF3FFFFFFul

/* ADC CGm unit macros */
#define ADC_CG0                             (uint8)0x00
#define ADC_CG1                             (uint8)0x01
#define ADC_CG2                             (uint8)0x02

/* ADC CGm unit conversion status macro */
#define ADC_CG0_CONV_STATUS_MASK            (uint16)0x0001
#define ADC_CG1_CONV_STATUS_MASK            (uint16)0x0002
#define ADC_CG2_CONV_STATUS_MASK            (uint16)0x0004
#define ADC_HW_UNIT_STATUS                  (uint16)0x0007

/* ADC Result access */
#define ADC_DMA_ACCESS                      (uint8)0x00
#define ADC_ISR_ACCESS                      (uint8)0x01

/* CPU core of the device under test */
#define ADC_E2M                             0
#define ADC_E2K                             1

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
** Union for accessing the 16-bit converted digital values from 32-bit        **
** register. This Union is also used for reading 32-bit address and writing   **
** into two 16-bit registers in case of DMA.                                  **
*******************************************************************************/
typedef union
{
  uint32 Value;
  struct
  {
    uint16 LoByte;
    uint16 HiByte;
  }UChar;
}UInt;

/*******************************************************************************
** Structure for HW Unit Registers, which are used to read or write           **
** the status or configured values for proper working of the ADC driver       **
*******************************************************************************/
typedef struct STagTdd_AdcConfigUserRegisters
{
  uint32 volatile ulADCAnCGm[3];
  uint32 volatile ulADCAnIOCm[3];
  uint32 aaReserved1[5];
  uint16 volatile ulADCAnSTR2;
  uint16 aaReserved2[55];
  uint16 volatile usADCAnDGCR;
  uint16 aaReserved3[3];
  uint8 volatile ucADCAnTRG0[1];
  uint8 aaReserved4[15];
  uint8 volatile ucADCAnTRG4[1];
  uint8 aaReserved5[39];
  uint16 volatile usADCAnDGCTL0;
} Tdd_AdcConfigUserRegisters;

typedef struct STagTdd_AdcConfigOsRegisters
{
  uint16 volatile usADCAnCTL0;
  uint16 aaReserved7;
  uint32 volatile ulADCAnCTL1;
  uint16 volatile usADCAnTSELm[3];
  uint16 aaReserved8[3];
  uint8 volatile ucADCAnCNT;
} Tdd_AdcConfigOsRegisters;

/*******************************************************************************
** Structure for PIC macro registers setting the TAUA0 and TAUA1 timer        **
** interrupts                                                                 **
*******************************************************************************/
typedef struct STagTdd_AdcPicRegisters
{
  uint16 volatile usPIC0ADTEN40n[1];
  uint16 aaReserved1[5];
  uint16 volatile usPIC0ADTEN41n[1];
} Tdd_AdcPicRegisters;

/*******************************************************************************
** Structure for DMAC Registers, which are used to read or write              **
** the status or configured values for proper working of the DMAC             **
*******************************************************************************/
typedef struct STagAdc_DmaRegs
{
  #if(ADC_CPU_CORE == ADC_E2M)
  /* Transfer request select register */
  uint16 volatile usDTRSn;
  uint16 aaReserved1;
  #endif
  /* Address for source address register */
  uint32 volatile ulDSAn;
  /* Source chip select register */
  uint16 volatile usDSCn;
  uint16 aaReserved2;
  /* Address for next lower source address register */
  uint16 volatile usDNSAnL;
  /* Address for next higher source address register */
  uint16 volatile usDNSAnH;
  uint16 aaReserved3[2];
  /* Address for lower destination address register */
  uint32 volatile ulDDAn;
  /* Destination chip select register */
  uint16 volatile usDDCn;
  uint16 aaReserved4;
  /* Address for next lower destination address register */
  uint16 volatile usDNDAnL;
  /* Address for next higher destination address register */
  uint16 volatile usDNDAnH;
  uint16 aaReserved5;
  /* Transfer count register */
  uint16 volatile usDTCn;
  /* Transfer next count register */
  uint16 volatile usDNTCn;
  uint16 volatile usDTCCn;
  /* Transfer control register */
  uint16 volatile usDTCTn;
  /* Transfer status register */
  uint8 volatile ucDTSn;
} Tdd_Adc_DmaAddrRegs;

/*******************************************************************************
** Structure for DMA channel configuration for CGm unit                       **
*******************************************************************************/
#if (ADC_DMA_MODE_ENABLE == STD_ON)
typedef struct STagTdd_Adc_DmaUnitConfig
{
  /* Address for DMA control registers */
  P2VAR(Tdd_Adc_DmaAddrRegs, AUTOMATIC, ADC_CONFIG_DATA)pDmaCntlRegBase;
  /* Address for DMA IMR control registers */
  P2VAR(void, AUTOMATIC, ADC_CONFIG_DATA)pDmaImrIntCntlReg;
  /* Address for DTFR control registers */
  P2VAR(void,AUTOMATIC,ADC_CONFIG_DATA)pDmaDTFRRegAddr;
  /* DMA channel Id mask */
  uint16 usDmaChannelMask;
  /* DMA Buffer register of CGm */
  uint32 ulDmaBuffRegCGm;
  /* DTFR register value */
  uint16 usDmaDtfrRegValue;
  /* Imr register mask value for the DMA channel */
  uint8 ucDmaImrMask;
} Tdd_Adc_DmaUnitConfig;
#endif

/*******************************************************************************
** Structure for IMR register address and corresponding mask generation.      **
*******************************************************************************/
typedef struct STagTdd_AdcImrAddMaskConfigType
{
  P2VAR(uint8, AUTOMATIC, ADC_CONFIG_DATA) pImrIntpAddress;
  uint8 ucImrMask;
}Tdd_AdcImrAddMaskConfigType;

/*******************************************************************************
** Structure for HW Unit configuration                                        **
*******************************************************************************/
typedef struct STagTdd_Adc_HwUnitConfigType
{
  /* Pointer to user base address of ADC Control registers */
  P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC, ADC_CONFIG_DATA)
                                                           pUserBaseAddress;
  /* Pointer to os base address of ADC Control registers */
  P2VAR(Tdd_AdcConfigOsRegisters, AUTOMATIC, ADC_CONFIG_DATA) pOsBaseAddress;
  #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON)
  /* Pointer to base address of PIC Control registers */
  P2VAR(Tdd_AdcPicRegisters, AUTOMATIC, ADC_CONFIG_DATA) pPicBaseAddress;
  #endif
  /* Pointer to base address of ADC Result Register */
  P2VAR(uint32, AUTOMATIC, ADC_CONFIG_DATA) pAdcResult;
  /* Pointer to ADC HW unit CG0 interrupt control register */
  P2VAR(uint16, AUTOMATIC, ADC_CONFIG_DATA) pIntpAddress;
  /* Pointer to CG0 ADC IMR register and Mask value */
  P2CONST(Tdd_AdcImrAddMaskConfigType, AUTOMATIC, ADC_CONFIG_DATA) pImrAddMask;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /* Pointer to the Priority Queue */
  P2VAR(Adc_GroupType, AUTOMATIC, ADC_CONFIG_DATA) pQueue;
  #endif
  /*
   * Bit 24 = 0/1 indicates right/left alignment of conversion result
   * Bit 17 = 0/1 indicates off/on discharge control
   * Bit 16 = 0 indicates do not clear conversion result after read-out
   * Bit 15 = 0/1 indicates 12/10 bit resolution mode
   * Bit 11, 10,9,8 = A/D frequency configuration
   * Bit 3 = 0/1 indicates OFF/ON ADC buffer amplifier
   * Bit 0 = 1 indicating ADC Power ON
   */

  /* The following values should be generated only if priority configured
   * is ADC_PRIORITY_HW or ADC_PRIORITY_HW_SW other wise the value should be
   * generated as zero */
  /*
   * Group mapped to CG2 unit
   * Bit 31,30 = 00 if the group(s) mapped is SW triggered
   *           = 01 if the group mapped is HW triggered and rising edge
   *           = 10 if the group mapped is HW triggered and falling edge
   *           = 11 if the group mapped is HW triggered and both edge
   * Group mapped to CG1 unit
   * Bit 29,28 = 00 if the group(s) mapped is SW triggered
   *           = 01 if the group mapped is HW triggered and rising edge
   *           = 10 if the group mapped is HW triggered and falling edge
   *           = 11 if the group mapped is HW triggered and both edge
   * Group mapped to CG0 unit
   * Bit 27,26 = 00 if the group(s) mapped is SW triggered
   *           = 01 if the group mapped is HW triggered and rising edge
   *           = 10 if the group mapped is HW triggered and falling edge
   *           = 11 if the group mapped is HW triggered and both edge
   * Bit 21,20 = 10 if all the group(s) mapped to CG0 unit are one-shot
   *           = 11 if all the group(s) mapped to CG0 unit are continuous
   * Bit 6 = 0/1 indicates immediately/finished transition of CG2 unit to halt
   * Bit 5 = 0/1 indicates immediately/finished transition of CG1 unit to
   *                                                                   CG2/halt
   * Bit 4 = 0/1 indicates immediately/finished transition of CG0 unit to
   *                                                               CG1/CG2/halt
   */
  uint32 ulHwUnitSettings;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* Enable mask for configuration no of samples */
  uint16 usStreamEnableMask;
  #endif

  #if(ADC_DIAG_CHANNEL_SUPPORTED == STD_ON)
  /* Self-Diagnostic reference voltage setting */
  uint16 usDiagnosticValue;
  #endif
  /* Stabilization counter value */
  uint8 ucStabilzationCount;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      (ADC_ENABLE_QUEUING == STD_ON))
  /* Maximum Queue Size when software priority or
     first come first serve mechanism is enabled */
  uint8 ucAdcQueueSize;
  #endif
} Tdd_Adc_HwUnitConfigType;

/*******************************************************************************
** Structure for Group configuration                                          **
*******************************************************************************/
typedef struct STagTdd_Adc_GroupConfigType
{
  /* Pointer to the first channel of the group */
  P2CONST(uint8, AUTOMATIC, ADC_CONFIG_DATA) pChannelToGroup;
  /* Channel list */
  uint32 ulChannelList;
  /* Result access mode configuration - Single or Streaming Buffer */
  Adc_GroupAccessModeType ddGroupAccessMode;
  /* Number of Samples in Streaming Access Mode */
  Adc_StreamNumSampleType ddNumberofSamples;
  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
  /* Replacement mechanism, which is used on ADC group level */
  Adc_GroupReplacementType ddGroupReplacement;
  #endif
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* Software Priority configured for the group */
  Adc_GroupPriorityType ddGroupPriority;
  #endif
  /* Index of the hardware unit to which the group belongs */
  uint8 ucHwUnit;
  /* CGm unit to which group is configured */
  uint8 ucHwCGUnit;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* Index of the DMA channel Id configured for this group in the array
     Adc_GstDmaUnitConfig[] */
  uint8 ucDmaChannelIndex;
  #endif
  /* Result access by DMA or ISR */
  uint8 ucResultAccessMode;
  /* Conversion is continuous or only once */
  uint8 ucConversionMode;
  /* Number of channels configured in the group */
  uint8 ucChannelCount;
} Tdd_Adc_GroupConfigType;

/*******************************************************************************
** Structure for HW trigger group configuration                               **
*******************************************************************************/
#if (ADC_HW_TRIGGER_API == STD_ON)
typedef struct STagTdd_Adc_HWGroupTriggType
{
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
  /* CGm unit external trigger enable value */
  uint32 ulExtTrigEnableMask;
  #endif
  /* ADC Unit HW Trigger Mask value */
  uint16 usHWTriggerMask;
  #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON)
  /* TAUA0 interrupts configured mask value */
  uint16 usTAUA0TriggerMask;
  /* TAUA1 interrupts configured mask value */
  uint16 usTAUA1TriggerMask;
  #endif
} Tdd_Adc_HWGroupTriggType;
#endif

/*******************************************************************************
** Structure for channel group RAM data                                       **
*******************************************************************************/
typedef struct STagTdd_Adc_ChannelGroupRamData
{
  /* ADC Group's Buffer Pointer */
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_PUBLIC_CODE) pChannelBuffer;
  /* Stores the conversion status of the requested group */
  Adc_StatusType ddGroupStatus;
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Stores the Group Notification Status */
  uint8 ucNotifyStatus;
  #endif
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Stores the buffer pointer initialization Status */
  uint8 ucBufferStatus;
  #endif
  #if (ADC_HW_TRIGGER_API == STD_ON)
  /* Stores the enable hardware trigger status */
  uint8 ucHwTriggStatus;
  #endif
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* Stores the channel count converted before getting interrupted by
     higher priority group */
  uint8 ucReChannelsCompleted;
  /* Stores the count of conversion rounds completed before
     getting interrupted by higher priority group */
  uint8 ucReSamplesCompleted;
  #endif
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /* Stored the status if the group is present in queue */
  uint8 ucGrpPresent;
  #endif
  /* Indicates if the conversion of all the samples are completed */
  boolean blSampleComp;
  /* Indicates if the ADC_COMPLETED status has to be prevented once the
     Group reaches the status of ADC_STREAM_COMPLETED */
  boolean blResultRead;
} Tdd_Adc_ChannelGroupRamData;

/*******************************************************************************
** Structure for HW unit RAM data                                             **
*******************************************************************************/
typedef struct STagTdd_Adc_HwUnitRamData
{
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
  /* Stores the current conversion group */
  Adc_GroupType ddCurrentConvGroup[1];
  #else
  /* Stores the current conversion group */
  Adc_GroupType ddCurrentConvGroup[3];
  #endif

  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
  /* Stores the current conversion group priority */
  Adc_GroupPriorityType ddCurrentPriority[1];
  #elif (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  /* Stores the current conversion group priority */
  Adc_GroupPriorityType ddCurrentPriority[3];
  #endif

  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
  /* Stores Trigger source type of the current conversion group SW/HW */
  Adc_TriggerSourceType ddTrigSource;
  #endif
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /* Stores the queue status */
  uint8 ucQueueStatus;
  /* Stores the queue counter */
  uint8 ucQueueCounter;
  #endif
} Tdd_Adc_HwUnitRamData;

/*******************************************************************************
** Structure for run time data                                                **
*******************************************************************************/
typedef struct STagTdd_Adc_RunTimeData
{
  /* ADC Group's Buffer Pointer */
  P2VAR(uint16, AUTOMATIC, ADC_CONFIG_DATA) pBuffer;
  /* ADC Group's channel Pointer */
  P2CONST(uint8, AUTOMATIC, ADC_CONFIG_DATA) pChannel;
  /* Stores the count of number of channels in the group */
  uint8 ucChannelCount;
  /* Stores the count of conversion completed channels */
  uint8 ucChannelsCompleted;
  /* Stores the count of streaming samples */
  uint8 ucStreamingSamples;
  /* Stores the count of conversion completed samples */
  uint8 ucSamplesCompleted;
} Tdd_Adc_RunTimeData;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Declaration for Hardware Unit Configuration */
extern CONST(Tdd_Adc_HwUnitConfigType, ADC_CONST) Adc_GstHWUnitConfig[];
/* Declaration for Group Configuration */
extern CONST(Tdd_Adc_GroupConfigType, ADC_CONST) Adc_GstGroupConfig[];
#if (ADC_HW_TRIGGER_API == STD_ON)
/* Declaration for HW Group Configuration */
extern CONST(Tdd_Adc_HWGroupTriggType, ADC_CONST) Adc_GstHWGroupTrigg[];
#endif
#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* Declaration for DMA Channel Configuration */
extern CONST(Tdd_Adc_DmaUnitConfig, ADC_CONST) Adc_GstDmaUnitConfig[];
/* Declaration for DMA Channel to HW unit mapping Configuration */
extern CONST(Adc_HwUnitType, ADC_CONFIG_CONST) Adc_GaaHwUnit[];
/* Declaration for DMA Channel to CGm unit mapping Configuration */
extern CONST(uint8, ADC_CONFIG_CONST) Adc_GaaCGUnit[];
#endif
/* Declaration for Channel to Group Configuration */
extern CONST(Adc_ChannelType, ADC_CONFIG_CONST) Adc_GaaChannelToGroup[];
/* Structure IMR Register address and mask value */
extern CONST(Tdd_AdcImrAddMaskConfigType, ADC_CONFIG_CONST) Adc_GstImrAddMask[];

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* RAM Allocation of Group data */
extern VAR(Tdd_Adc_ChannelGroupRamData, ADC_NOINIT_DATA) Adc_GstGroupRamData[];
/* RAM Allocation of hardware unit data */
extern VAR(Tdd_Adc_HwUnitRamData, ADC_NOINIT_DATA) Adc_GstHwUnitRamData[];

/* RAM Allocation of Group Runtime data */
extern VAR(Tdd_Adc_RunTimeData, ADC_NOINIT_DATA) Adc_GstRunTimeData[];

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
/* Hardware Unit Queue Size */
extern VAR(Adc_GroupType, ADC_NOINIT_DATA) Adc_HwUnitPriorityQueue[];
#endif

#define ADC_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ADC_PBTYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
