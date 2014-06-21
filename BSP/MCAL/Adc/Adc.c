/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Adc.c                                                       */
/* Version      = 3.1.4                                                       */
/* Date         = 20-Mar-2013                                                 */    
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* API function implementations of ADC Driver Component                       */
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
 *                         1. Template changes are made.
 *                         2. Adc_Init is updated to initialize HW unit
 *                            settings when the priority is ADC_PRIORITY_HW_SW
 *                            or ADC_PRIORITY_HW
 *                         3. Adc_DeInit is updated to deinitialize configured
 *                            DMA channels.
 *                         4. Adc_StartGroupConversion is updated in DET
 *                            section to replace LddCurrentGroup to Group.
 *                         5. Adc_DisableHardwareTrigger is updated to
 *                            optimize DET section and queuing concept.
 *
 * V3.0.2:  05-Nov-2009  : As per SCR 088, I/O structure is updated to have
 *                         separate base address for USER and OS registers.
 *
 * V3.0.3:  08-Nov-2009  : As per SCR 109, Adc_Init and Adc_DeInit is updated
 *                         to check if Adc_GucMaxDmaChannels is not equal to 0
 *                         before initialization or deinitialization of DMA.
 *
 * V3.0.4:  02-Dec-2009  : As per SCR 157, the following changes are made
 *                         1. Adc_GpRunTimeData declaration is changed.
 *                         2. Pre-compile option is updated to use
 *                            ADC_ENABLE_QUEUING along with priority
 *                            ADC_PRIORITY_NONE.
 *                         3. Adc_GucPopFrmQueue is put within pre-compile
 *                            option.
 *
 * V3.0.5:  05-Jan-2010  : As per SCR 179, the following changes are made
 *                         1. Declaration of the local variable LddCurrentGroup
 *                            in the function Adc_StartGroupConversion is
 *                            corrected.
 *                         2. Adc_GucResultRead is replaced by group RAM
 *                            variable.
 *                         3. Offset of the PIC registers are corrected.
 *
 * V3.0.6:  26-Feb-2010  : As per SCR 200, the following changes are made
 *                         1. Adc_StopGroupConversion is updated
 *                            to disable the interrupt configured for the CGm
 *                            unit mapped for the requested group.
 *                         2. Adc_Init is updated for the pre-compile option
 *                            of the RAM variables ucQueueStatus and
 *                            ucQueueCounter.
 *
 * V3.0.7:  18-Mar-2010  : As per SCR 231, the following changes are made:
 *                         1. APIs Adc_StartGroupConversion,
 *                            Adc_StopGroupConversion, Adc_EnableHardwareTrigger
 *                            and Adc_DisableHardwareTrigger are updated to
 *                            avoid reading from uninitialized pointers.
 *                         2. API Adc_GetStreamLastPointer is updated to return
 *                            completed number of samples for DMA access.
 *
 * V3.0.8:  01-Jul-2010  : As per SCR 295, following changes are made:
 *                         1. Adc_StartGroupConversion is updated
 *                            to report DET error when called in ADC_COMPLETED
 *                            group conversion state.
 *                         2. Adc_GaaCGmConvStatusMask[] is added.
 *                         3. Interrupt control register is replaced by IMR
 *                            register.
 *
 * V3.0.9:  28-Jul-2010  : As per SCR 316, updated the function
 *                         Adc_StopGroupConversion for clearing the pending
 *                         interrupt.
 *
 * V3.0.10: 14-Sep-2010  : As per SCR 354, updated the function
 *                         Adc_StopGroupConversion for reporting the DET error
 *                         ADC_E_IDLE.
 *
 * V3.0.11: 26-Oct-2010  : As per SCR 371, updated pre-compile option for 
 *                          Adc_GaaCGmConvStatusMask variable declaration.
 *
 * V3.0.12: 07-Jan-2011  : As per SCR 391, tab spaces are removed.
 * 
 * V3.0.13: 20-Jun-2011  : As per SCR 475, function Adc_Init is updated 
 *                         to change the type of the pointer 'LpDmaTrigFactor' 
 *                         from 'uint32' to 'uint16'.   
 *
 * V3.1.0:  27-Jul-2011  : Modified for DK-4
 * V3.1.1:  04-Oct-2011  : Added comments for the violation of MISRA rule 19.1,
 *                         1.2,8.7
 * V3.1.2:  14-Feb-2012  : Merged the fixes done for Fx4L Adc driver
 *
 * V3.1.3:  04-Jun-2012  : As per SCR 019, following changes are made:
 *                         1. Compiler version is removed from environment 
 *                            section.
 *                         2. File version is changed.
 *                         3. Adc_GetVersionInfo API is removed.
 * V3.1.4:  20-Mar-2013  : As per SCR 083 for MNT_0009451 and MNT_0009843, 
 *                         following changes are made:
 *                         1. Adc_StartGroupConversion is implemented as 
 *                            reentrant
 *                         2. Copyright information is updated.
 *                         3. "ADCAnCNT" register is initialzed before 
 *                            "ADCAnCTL1" register.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Adc.h"
#include "Adc_Private.h"
#include "Adc_PBTypes.h"
#include "Adc_LTTypes.h"
#include "Adc_Ram.h"
#if(ADC_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
#if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Adc.h"
#endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define ADC_C_AR_MAJOR_VERSION    ADC_AR_MAJOR_VERSION_VALUE
#define ADC_C_AR_MINOR_VERSION    ADC_AR_MINOR_VERSION_VALUE
#define ADC_C_AR_PATCH_VERSION    ADC_AR_PATCH_VERSION_VALUE

/* File version information */
#define ADC_C_SW_MAJOR_VERSION    3
#define ADC_C_SW_MINOR_VERSION    1
#define ADC_C_SW_PATCH_VERSION    3

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ADC_AR_MAJOR_VERSION != ADC_C_AR_MAJOR_VERSION)
  #error "Adc.c : Mismatch in Specification Major Version"
#endif

#if (ADC_AR_MINOR_VERSION != ADC_C_AR_MINOR_VERSION)
  #error "Adc.c : Mismatch in Specification Minor Version"
#endif

#if (ADC_AR_PATCH_VERSION != ADC_C_AR_PATCH_VERSION)
  #error "Adc.c : Mismatch in Specification Patch Version"
#endif

#if (ADC_SW_MAJOR_VERSION != ADC_C_SW_MAJOR_VERSION)
  #error "Adc.c : Mismatch in Major Version"
#endif

#if (ADC_SW_MINOR_VERSION != ADC_C_SW_MINOR_VERSION)
  #error "Adc.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
/* MISRA Rule         : 8.7                                          */
/* Message            : Objects shall be defined at block scope if   */
/*                      they are only accessed from within a single  */
/*                      function.                                    */
/* Reason             : By Moving the array into the function used   */
/*                      the stack size will be more, hence this is   */
/*                      defined outside.                             */
/* Verification       : However, this part of the code is verified   */
/*                      manually and it is not having any impact.    */
#if  ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
      ((ADC_HW_TRIGGER_API == STD_ON) && \
       ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
        (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))))

#define ADC_START_SEC_CONST_16BIT
  /* MISRA Rule         : 19.1                            */
  /* Message            : #include statements in a file   */
  /*                      should only be preceded by other*/
  /*                      preprocessor directives or      */
  /*                      comments.                       */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */
#include "MemMap.h"

STATIC CONST(uint16, ADC_CONST) Adc_GaaCGmConvStatusMask[ADC_THREE] =
{
  ADC_CG0_CONV_STATUS_MASK,
  ADC_CG1_CONV_STATUS_MASK,
  ADC_CG2_CONV_STATUS_MASK
};

#define ADC_STOP_SEC_CONST_16BIT
#include "MemMap.h"/* PRQA S 5087 */
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
      ((ADC_HW_TRIGGER_API == STD_ON) && \
       ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
        (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)))) */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Adc_Init
**
** Service ID           : 0x00
**
** Description          : This API performs the initialization of the ADC Driver
**                        component.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : ConfigPtr
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Adc_GpConfigPtr, Adc_GpHwUnitConfig,
**                        Adc_GpGroupConfig, Adc_GpRunTimeData,
**                        Adc_GpGroupRamData, Adc_GucMaxSwTriggGroups
**                        Adc_GpHwUnitRamData, Adc_GblDriverStatus,
**                        Adc_GpDmaUnitConfig
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PUBLIC_CODE) Adc_Init
(P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) ConfigPtr)
{
  #if(ADC_DMA_MODE_ENABLE == STD_ON)
  P2CONST(Tdd_Adc_DmaUnitConfig, AUTOMATIC, ADC_CONFIG_DATA) LpCGmDmaConfig;
  P2VAR(Tdd_Adc_DmaAddrRegs, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegisters;
  P2VAR(uint16, AUTOMATIC, ADC_CONFIG_DATA) LpDmaTrigFactor;
  #endif /* #if(ADC_DMA_MODE_ENABLE == STD_ON) */
  P2VAR(Tdd_Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  #if(ADC_DIAG_CHANNEL_SUPPORTED == STD_ON)
  /* Pointer to the hardware unit User base configuration address */
  P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC, ADC_CONFIG_DATA)
                                                       LpAdcUserRegisters;
  #endif /* #if(ADC_DIAG_CHANNEL_SUPPORTED == STD_ON) */
  /* Pointer to the hardware unit Os base configuration address */
  P2VAR(Tdd_AdcConfigOsRegisters, AUTOMATIC, ADC_CONFIG_DATA) LpAdcOsRegisters;
  #if (ADC_HW_TRIGGER_API == STD_ON)
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
            (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW))
  #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON)
  P2VAR(Tdd_AdcPicRegisters, AUTOMATIC,ADC_CONFIG_DATA) LpAdcPicRegisters;
  #endif /* #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON) */
  P2CONST(Tdd_Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  Adc_GroupType LddVirGroup;
  uint8 LucHwCGUnit;
  #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON)
  uint8 LddHwUnit;
  #endif /* #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON) */
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
            (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW)) */
  #endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */
  uint8_least LucLoopCount;
  #if  (ADC_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to false */
  LblDetErrFlag = ADC_FALSE;
  /* Check if the ADC Driver is already initialised */
  if(Adc_GblDriverStatus == ADC_TRUE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_INIT_SID,
                                                ADC_E_ALREADY_INITIALIZED);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  /* Check if the Configuration pointer is NULL */
  if(ConfigPtr == NULL_PTR)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                            ADC_INIT_SID, ADC_E_PARAM_CONFIG);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  /* Check if any DET was reported */
  if(LblDetErrFlag == ADC_FALSE)
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
          /* MISRA Rule         : 1.2
             Message            : Dereferencing pointer value that is apparently
                                  NULL.
             Reason             : "ConfigPtr" pointer is checked and verified when
                                  DET is switched STD_ON.
             Verification       : However, the part of the code is
                                  verified manually and it is not having
                                  any impact on code.
          */
    /* Initialise the module only if Database is present */
    if((ConfigPtr->ulStartOfDbToc) == ADC_DBTOC_VALUE)
    {
      /* Update all the global pointers with the relevant addresses */
      Adc_GpConfigPtr = ConfigPtr;
      Adc_GpHwUnitConfig = ConfigPtr->pHWUnitConfig;
      Adc_GpGroupConfig = ConfigPtr->pGroupConfig;
      #if (ADC_HW_TRIGGER_API == STD_ON)
      Adc_GpHWGroupTrigg = ConfigPtr->pGroupHWTrigg;
      #endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */
      Adc_GpGroupRamData = ConfigPtr->pGroupRamData;
      Adc_GpHwUnitRamData = ConfigPtr->pHwUnitRamData;
      Adc_GpRunTimeData = ConfigPtr->pRunTimeData;
      Adc_GucMaxSwTriggGroups = ConfigPtr->ucMaxSwTriggGroups;

      #if (ADC_DMA_MODE_ENABLE == STD_ON)
      /* Initialize the global pointer for HW unit mapping */
      Adc_GpDmaHWUnitMapping = ConfigPtr->pDmaHWUnitMapping;
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
      /* Initialize the global pointer for CG unit mapping */
      Adc_GpDmaCGUnitMapping = ConfigPtr->pDmaCGUnitMapping;
      #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
      Adc_GucMaxDmaChannels = ConfigPtr->ucMaxDmaChannels;
      if(Adc_GucMaxDmaChannels != ADC_ZERO)
      {
        Adc_GpDmaUnitConfig = ConfigPtr->pDmaUnitConfig;
        for(LucLoopCount = ADC_ZERO; LucLoopCount <
                       (uint8_least)Adc_GucMaxDmaChannels; LucLoopCount++)
        {
          LpCGmDmaConfig = &Adc_GpDmaUnitConfig[LucLoopCount];
          LpDmaRegisters = LpCGmDmaConfig->pDmaCntlRegBase;
          /* Clear the DTE bit */
          LpDmaRegisters->ucDTSn &= ADC_DMA_DISABLE;
          /* Load the source address register */
          LpDmaRegisters->ulDSAn = LpCGmDmaConfig->ulDmaBuffRegCGm;
          #if(ADC_CPU_CORE == ADC_E2M)
          /* Load the source chip select register */
          LpDmaRegisters->usDSCn = ADC_DMA_SRC_SELECT;
          /* Set NSAV bit to 0 in higher address byte */
          LpDmaRegisters->usDNSAnH &= ADC_DMA_CLEAR_NEXT;
          /* Load the destination chip select register */
          LpDmaRegisters->usDDCn = ADC_DMA_DEST_SELECT;
          /* Set NDAV bit to 0 in higher address byte */
          LpDmaRegisters->usDNDAnH &= ADC_DMA_CLEAR_NEXT;
          /* Load the transfer request select register */
          LpDmaRegisters->usDTRSn = ADC_DMA_TRANSFER;
          #endif /* #if(ADC_CPU_CORE == ADC_E2M) */
          LpDmaTrigFactor = LpCGmDmaConfig->pDmaDTFRRegAddr;
          /* Load the triger factor configured for the CGm unit */
          *LpDmaTrigFactor = LpCGmDmaConfig->usDmaDtfrRegValue;
          /* Load the transfer control register */
          LpDmaRegisters->usDTCTn = ADC_DMA_SETTINGS;
        }
      }
      #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */

      for(LucLoopCount = ADC_ZERO; LucLoopCount <
                               (uint8_least)ADC_MAX_HW_UNITS; LucLoopCount++)
      {
        /* Read the base configuration register of the hardware unit */
        LpAdcOsRegisters = Adc_GpHwUnitConfig[LucLoopCount].pOsBaseAddress;
        /* Set the Stabilization counter value */
        LpAdcOsRegisters->ucADCAnCNT =
                          Adc_GpHwUnitConfig[LucLoopCount].ucStabilzationCount;
		/*
         * Set the HW unit register as per the configuration for power on,
         * Discharge function, resolution, conversion frequency and result
         * alignment
         */
        LpAdcOsRegisters->ulADCAnCTL1 =
                            Adc_GpHwUnitConfig[LucLoopCount].ulHwUnitSettings;
        /* Set the number of sample fixed for each CGm unit */
        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
                   (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
        LpAdcOsRegisters->usADCAnCTL0 =
                          Adc_GpHwUnitConfig[LucLoopCount].usStreamEnableMask;
        #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
                   (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
        #if(ADC_DIAG_CHANNEL_SUPPORTED == STD_ON)
        /* Read the user base configuration register of the hardware unit */
        LpAdcUserRegisters = Adc_GpHwUnitConfig[LucLoopCount].pUserBaseAddress;
        /* Set the diagnostic reference voltage configured for the
           diagnostic channel configured */
        LpAdcUserRegisters->usADCAnDGCTL0 =
                          Adc_GpHwUnitConfig[LucLoopCount].usDiagnosticValue;
        #endif /* #if(ADC_DIAG_CHANNEL_SUPPORTED == STD_ON) */


        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
        (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
        ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
        /* Initialise queue */
        Adc_GpHwUnitRamData[LucLoopCount].ucQueueStatus = ADC_QUEUE_EMPTY;
        Adc_GpHwUnitRamData[LucLoopCount].ucQueueCounter = ADC_ZERO;
        #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                  ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                 (ADC_ENABLE_QUEUING == STD_ON))) */
      }

      for(LucLoopCount = ADC_ZERO; LucLoopCount <
                                   (uint8_least)ADC_MAX_GROUPS; LucLoopCount++)
      {
        LpGroupData = &Adc_GpGroupRamData[LucLoopCount];
        /* Initialise all the groups as idle */
        LpGroupData->ddGroupStatus = ADC_IDLE;
        #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        /* Disable notifications */
        LpGroupData->ucNotifyStatus = ADC_FALSE;
        #endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
        /* Disable buffer address initialization */
        LpGroupData->ucBufferStatus = ADC_FALSE;
        #endif /*#if(ADC_DEV_ERROR_DETECT == STD_ON) */
        #if (ADC_HW_TRIGGER_API == STD_ON)
        /* Disable hardware trigger status */
        LpGroupData->ucHwTriggStatus = ADC_FALSE;
        #endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */

        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
        /* Initialize the channels completed to zero */
        LpGroupData->ucReChannelsCompleted = ADC_ZERO;
        /* Initialize the samples completed to zero */
        LpGroupData->ucReSamplesCompleted = ADC_ZERO;
        #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */

        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
        /* Clear the flag indicating no group is present in queue */
        LpGroupData->ucGrpPresent = ADC_FALSE;
        #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                      (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                       (ADC_ENABLE_QUEUING == STD_ON))) */
        /* Clear the flag indicating result data is not read */
        LpGroupData->blResultRead = ADC_FALSE;
      }
      #if (ADC_HW_TRIGGER_API == STD_ON)
      #if((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
            (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW))
      if(Adc_GpHWGroupTrigg != NULL_PTR)
      {
        for(LucLoopCount = Adc_GucMaxSwTriggGroups; LucLoopCount <
                             (uint8_least)ADC_MAX_GROUPS; LucLoopCount++)
        {
          /* Get the pointer to the group configuration */
          LpGroup = &Adc_GpGroupConfig[LucLoopCount];
          /* Get the CGm unit to which the group is configured */
          LucHwCGUnit = LpGroup->ucHwCGUnit;
          /* Get the index in the Adc_GstHWGroupTrigg array */
          LddVirGroup = LucLoopCount - Adc_GucMaxSwTriggGroups;

          #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON)
          /* Get the HW unit to which the group is configured */
          LddHwUnit = LpGroup->ucHwUnit;
          /* Get the base configuration address of the hardware unit */
          LpAdcPicRegisters = Adc_GpHwUnitConfig[LddHwUnit].pPicBaseAddress;
          /* Load the TAUA0 interrupts configured for this channel group */
          LpAdcPicRegisters->usPIC0ADTEN40n[LucHwCGUnit * ADC_TWO] =
                            Adc_GpHWGroupTrigg[LddVirGroup].usTAUA0TriggerMask;
          /* Load the TAUA1 interrupts configured for this channel group */
          LpAdcPicRegisters->usPIC0ADTEN41n[LucHwCGUnit * ADC_TWO] =
                            Adc_GpHWGroupTrigg[LddVirGroup].usTAUA1TriggerMask;
          #endif /* #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON) */

          /* Load HW trigger values configured */
          LpAdcOsRegisters->usADCAnTSELm[LucHwCGUnit * ADC_TWO] =
                  Adc_GpHWGroupTrigg[LddVirGroup].usHWTriggerMask;
        }
      }
      #endif /*  #if((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
            (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW)) */
      #endif /*  #if (ADC_HW_TRIGGER_API == STD_ON) */

      #if  (ADC_DEV_ERROR_DETECT == STD_ON)
      /* Set ADC driver as initialised */
      Adc_GblDriverStatus = ADC_TRUE;
      #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
               (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
      /* Clear the pop from queue flag */
      Adc_GucPopFrmQueue = ADC_ZERO;
      #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
               (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
      for (LucLoopCount = ADC_ZERO; LucLoopCount < \
                                             (uint8_least)0x06; LucLoopCount++)
      {
        Adc_GaaHwUnitStatus[LucLoopCount] = ADC_FALSE;
      }
    }
    #if  (ADC_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* Report Error to DET */
      Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                   ADC_INIT_SID, ADC_E_INVALID_DATABASE);
    }
    #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  }
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#if (ADC_DEINIT_API == STD_ON)
/*******************************************************************************
** Function Name        : Adc_DeInit
**
** Service ID           : 0x01
**
** Description          : This API performs the De-Initialization of the
**                        ADC Driver component by making all the registers to
**                        the power on reset state.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus, Adc_GpGroupRamData,
**                        Adc_GpHwUnitConfig, Adc_GpHwUnitRamData
**                        Function(s) invoked:
**                        Det_ReportError,
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PUBLIC_CODE) Adc_DeInit(void)
{
  #if(ADC_DMA_MODE_ENABLE == STD_ON)
  P2CONST(Tdd_Adc_DmaUnitConfig, AUTOMATIC, ADC_CONFIG_DATA) LpCGmDmaConfig;
  P2VAR(Tdd_Adc_DmaAddrRegs, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegisters;
  #endif /* #if(ADC_DMA_MODE_ENABLE == STD_ON) */
  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Pointer to the hardware unit user base configuration address */
  P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC,ADC_CONFIG_DATA)
                                                         LpAdcUserRegisters;
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  /* Pointer to the hardware unit os base configuration address */
  P2VAR(Tdd_AdcConfigOsRegisters, AUTOMATIC,ADC_CONFIG_DATA)
                                                         LpAdcOsRegisters;
  /* Local variable for loop count */
  uint8_least LucLoopCount;

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  LblDetErrFlag = ADC_FALSE;
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                                ADC_DEINIT_SID, ADC_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  else
  {
    LucLoopCount = ADC_ZERO;
    do
    {
      LpAdcUserRegisters = Adc_GpHwUnitConfig[LucLoopCount].pUserBaseAddress;
      /* Check if the requested hardware unit is busy */
      if((LpAdcUserRegisters->ulADCAnSTR2 & ADC_HW_UNIT_STATUS) != ADC_ZERO)
      {
        /* Report Error to DET */
        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_DEINIT_SID,
                                                              ADC_E_BUSY);
        /* Set error status flag to true */
        LblDetErrFlag = ADC_TRUE;
      }
      LucLoopCount++;
    }while((LucLoopCount < (uint8_least)ADC_MAX_HW_UNITS) &&
                                           (LblDetErrFlag != ADC_TRUE));
  }
  if(LblDetErrFlag == ADC_FALSE)
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    for(LucLoopCount = ADC_ZERO; LucLoopCount <
                             (uint8_least)ADC_MAX_HW_UNITS; LucLoopCount++)
    {
      /* Read the os base configuration register of the hardware unit */
      LpAdcOsRegisters = Adc_GpHwUnitConfig[LucLoopCount].pOsBaseAddress;
      /*
       * Reset the HW unit register for power of,
       * Discharge function, resolution, conversion frequency and result
       * alignment
       */
      LpAdcOsRegisters->ulADCAnCTL1 = ADC_ZERO_LONG;
      /* Reset the Stabilization counter value */
      LpAdcOsRegisters->ucADCAnCNT = ADC_ZERO;
      /* Reset usADCAnCTL0 register */
      LpAdcOsRegisters->usADCAnCTL0 = ADC_ZERO_SHORT;
    }

    for(LucLoopCount = ADC_ZERO; LucLoopCount <
                              (uint8_least) ADC_MAX_GROUPS; LucLoopCount++)
    {
      /* Set group status as idle */
      Adc_GpGroupRamData[LucLoopCount].ddGroupStatus = ADC_IDLE;
      #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      /* Disable notifications */
      Adc_GpGroupRamData[LucLoopCount].ucNotifyStatus = ADC_FALSE;
      #endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    }

    #if (ADC_DMA_MODE_ENABLE == STD_ON)
    if(Adc_GucMaxDmaChannels != ADC_ZERO)
    {
      for(LucLoopCount = ADC_ZERO; LucLoopCount <
                           (uint8_least)Adc_GucMaxDmaChannels; LucLoopCount++)
      {
        /* Get the pointer to DMA configuration */
        LpCGmDmaConfig = &Adc_GpDmaUnitConfig[LucLoopCount];
        LpDmaRegisters = LpCGmDmaConfig->pDmaCntlRegBase;
        /* Clear the DTE bit */
        LpDmaRegisters->ucDTSn &= ADC_DMA_DISABLE;
      }
    }
    #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */

    #if  (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Set the ADC driver as uninitialised */
    Adc_GblDriverStatus = ADC_FALSE;
    #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  }
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* ADC_DEINIT_API == STD_ON */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/*******************************************************************************
** Function Name        : Adc_StartGroupConversion
**
** Service ID           : 0x02
**
** Description          : This API service service shall start the conversion of
**                        all channels of the requested ADC Channel group.
**                        Depending on the group configuration single-shot or
**                        continuous conversion is started.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus, Adc_GpHwUnitConfig,
**                        Adc_GpGroupRamData, Adc_GpHwUnitRamData,
**                        Adc_GpGroupConfig, Adc_GucMaxSwTriggGroups
**                        Function(s) invoked:
**                        Det_ReportError, Adc_ConfigureGroupForConversion,
**                        Adc_PushToQueue
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PUBLIC_CODE) Adc_StartGroupConversion(Adc_GroupType Group)
{
  #if((ADC_DEV_ERROR_DETECT == STD_ON) || \
  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
  ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
  (ADC_ENABLE_QUEUING == STD_ON)))
  P2VAR(Tdd_Adc_HwUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpHwUnitData;
  #endif /* #if((ADC_DEV_ERROR_DETECT == STD_ON) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
         ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
              (ADC_ENABLE_QUEUING == STD_ON))) */
  /* Pointer definition to store the base address of the ADC registers */
  P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC,ADC_CONFIG_DATA)
                                                   LpAdcUserRegisters;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
        (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  P2VAR(Tdd_Adc_RunTimeData, AUTOMATIC,ADC_CONFIG_DATA) LpRunTimeData;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
        (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
     (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
     (ADC_DEV_ERROR_DETECT == STD_ON))
  /* Local variable to store the current conversion group ID */
  Adc_GroupType LddCurrentGroup;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                (ADC_DEV_ERROR_DETECT == STD_ON)) */
  /* Local variable to store the hardware unit number */
  Adc_HwUnitType LddHwUnit;
  uint8 LucHwCGUnit;
  #if  (ADC_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to false */
  LblDetErrFlag = ADC_FALSE;
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_START_GROUP_CONVERSION_SID, ADC_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  /* Check if the group requested is invalid */
  else if(Group >= ADC_MAX_GROUPS)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                           ADC_START_GROUP_CONVERSION_SID, ADC_E_PARAM_GROUP);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  else
  {
     /* Read the Hardware Unit to which the group belongs */
     LddHwUnit = Adc_GpGroupConfig[Group].ucHwUnit;
     /* Initialise HW RAM data to a local pointer */
     LpHwUnitData = &Adc_GpHwUnitRamData[LddHwUnit];
     /* Get the CGm unit to which the channel group is mapped */
     LucHwCGUnit = Adc_GpGroupConfig[Group].ucHwCGUnit;
     /* Get the current group under conversion */
     LddCurrentGroup = LpHwUnitData->ddCurrentConvGroup[LucHwCGUnit];
     /* Check if the requested group is HW triggered */
     if(Group >= Adc_GucMaxSwTriggGroups)
     {
       /* Report Error to DET */
       Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                       ADC_START_GROUP_CONVERSION_SID, ADC_E_WRONG_TRIGG_SRC);
       /* Set error status flag to true */
       LblDetErrFlag = ADC_TRUE;
     }
     if(Adc_GpGroupRamData[Group].ucBufferStatus == ADC_FALSE)
     {
       /* Report Error to DET */
       Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_START_GROUP_CONVERSION_SID, ADC_E_BUFFER_UNINIT);
       /* Set error status flag to true */
       LblDetErrFlag = ADC_TRUE;
     }
     #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
     if(Adc_GpGroupRamData[Group].ucGrpPresent == ADC_TRUE)
     {
       /* Report Error to DET */
       Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
       /* Set error status flag to true */
       LblDetErrFlag = ADC_TRUE;
     }
     #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                   (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                   ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON))) */
     if((LddCurrentGroup == Group) &&
     (Adc_GpGroupRamData[Group].ddGroupStatus != ADC_IDLE) &&
     (Adc_GpGroupConfig[Group].ucConversionMode == ADC_CONTINUOUS))
     {
       /* Report Error to DET */
       Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
       /* Set error status flag to true */
       LblDetErrFlag = ADC_TRUE;
     }
     if((LddCurrentGroup == Group) &&
     (Adc_GpGroupRamData[Group].ddGroupStatus != ADC_IDLE) &&
     (Adc_GpGroupRamData[Group].ddGroupStatus != ADC_STREAM_COMPLETED) &&
     (Adc_GpGroupConfig[Group].ucConversionMode == ADC_ONCE))
     {
       /* Report Error to DET */
       Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
       /* Set error status flag to true */
       LblDetErrFlag = ADC_TRUE;
     }
  }
  /* Check if any DET was reported */
  if(LblDetErrFlag == ADC_FALSE)
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Read the Hardware Unit to which the group belongs */
    LddHwUnit = Adc_GpGroupConfig[Group].ucHwUnit;
    /* Read the base configuration address of the hardware unit */
    LpAdcUserRegisters = Adc_GpHwUnitConfig[LddHwUnit].pUserBaseAddress;
    /* Get the CGm unit to which the channel group is mapped */
    LucHwCGUnit = Adc_GpGroupConfig[Group].ucHwCGUnit;

    /* Check if Group Priority and queue are disabled */
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                           (ADC_ENABLE_QUEUING == STD_OFF))
    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operators shall not be applied to    */
    /*                      operands whose underlying type is signed.    */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V6.2.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */
    /* Check if the requested hardware unit is busy */
    if(((LpAdcUserRegisters->ulADCAnSTR2 & \
          Adc_GaaCGmConvStatusMask[LucHwCGUnit]) != ADC_ZERO) || \
     (Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] == ADC_TRUE))
    {
      #if(ADC_DEV_ERROR_DETECT == STD_ON)
      /* Report Error to DET */
      Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
      #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
    }
    else /* Hardware Unit is not busy. Conversion can be taken up */
    {
      /* Set the Global variable indicating the HW unit is busy */
      Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
      Adc_ConfigureGroupForConversion(Group);
    }
    /* Group Priority is enabled */
    #elif ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
    /* Check if the requested hardware unit is busy */
    if(((LpAdcUserRegisters->ulADCAnSTR2 &
                  Adc_GaaCGmConvStatusMask[LucHwCGUnit]) != ADC_ZERO) || \
     (Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] == ADC_TRUE))
    {
      /* Initialise HW RAM data to a local pointer */
      LpHwUnitData = &Adc_GpHwUnitRamData[LddHwUnit];
      /* Check if critical section protection is required */
      #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter the critical section protection */
      SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
      #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Check if the current group priority is less than requested */
      if(LpHwUnitData->ddCurrentPriority[LucHwCGUnit] <
                                    Adc_GpGroupConfig[Group].ddGroupPriority)
      {
        /* Fetch the group id of the current conversion group */
        LddCurrentGroup = LpHwUnitData->ddCurrentConvGroup[LucHwCGUnit];
        #if ((ADC_HW_TRIGGER_API == STD_ON) && \
                           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW))
        /* Check if the ongoing lower priority group is HW triggered */
        if(LpHwUnitData->ddTrigSource == ADC_TRIGG_SRC_HW)
        {
          /* Disable the lower ongoing HW triggered group */
          Adc_DisableHWGroup(LddCurrentGroup);
          /* Set the Global variable indicating the HW unit is busy */
          Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = \
                                                                       ADC_TRUE;
          /* Start conversion of requested higher SW triggered group */
          Adc_ConfigureGroupForConversion(Group);
        }
        else
        #endif /* #if ((ADC_HW_TRIGGER_API == STD_ON) && \
                           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)) */
        {
          /* Check if the queue is full */
          if(LpHwUnitData->ucQueueStatus != ADC_QUEUE_FULL)
          {
            /* Get the runtime data pointer */
            LpRunTimeData =
            &Adc_GpRunTimeData[(LddHwUnit * ADC_NUMBER_OF_CG_UNITS) + \
                                                     LucHwCGUnit];
            /* Stop the conversion of the requested channel group */
            LpAdcUserRegisters->ucADCAnTRG4[LucHwCGUnit * ADC_FOUR] =
                                                      ADC_STOP_CONVERSION;
            /* Push the current conversion group into queue */
            Adc_PushToQueue(LddCurrentGroup);
            /* Check if the group as to be resumed from where it had stopped
             before */
            #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
            if(Adc_GpGroupConfig[LddCurrentGroup].ddGroupReplacement ==
                                            ADC_GROUP_REPL_SUSPEND_RESUME)
            #endif /* #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) */
            {
              /* Load the number of channels converted before suspension */
              Adc_GpGroupRamData[LddCurrentGroup].ucReChannelsCompleted =
                         LpRunTimeData->ucChannelsCompleted;
            }
            /* Load the number of samples converted before aborting or
             suspension */
            Adc_GpGroupRamData[LddCurrentGroup].ucReSamplesCompleted =
                       LpRunTimeData->ucSamplesCompleted;
            /* Set the Global variable indicating the HW unit is busy */
            Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = \
                                                                     ADC_TRUE;
            /* Configure the requested group for conversion */
            Adc_ConfigureGroupForConversion(Group);
          }
          #if(ADC_DEV_ERROR_DETECT == STD_ON)
          else
          {
            /* Report Error to DET */
            Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
          }
          #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
        }
      }
      else if(LpHwUnitData->ucQueueStatus != ADC_QUEUE_FULL)
      {
        /* Push the requested group to queue if its priority is less
        ** than the current conversion group.
        */
        Adc_PushToQueue(Group);
      }
      else
      {
        #if(ADC_DEV_ERROR_DETECT == STD_ON)

        /* Report Error to DET */
        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);

        #endif /* #if(ADC_DEV_ERROR_DETECT == ON) */
      }
      /* Check if critical section protection is required */
      #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit the critical section protection */
      SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
      #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
    }
    else /* First group requested for conversion */
    {
      /* Set the Global variable indicating the HW unit is busy */
      Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
      /* Configure the requested group for conversion */
      Adc_ConfigureGroupForConversion(Group);
    }
    #elif (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW)
    /* Check if the requested corresponding CGm unit to which group is mapped
       is busy */
    if(((LpAdcUserRegisters->ulADCAnSTR2 &
            Adc_GaaCGmConvStatusMask[LucHwCGUnit]) == ADC_ZERO) && \
     (Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] == ADC_TRUE))
    {
      /* Set the Global variable indicating the HW unit is busy */
      Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
      /* Configure the requested group for conversion */
      Adc_ConfigureGroupForConversion(Group);
    }
    #if(ADC_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* Report Error to DET */
      Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                              ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
    }
    #endif /* #if(ADC_DEV_ERROR_DETECT == ON) */

    #elif ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                           (ADC_ENABLE_QUEUING == STD_ON))
    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operators shall not be applied to    */
    /*                      operands whose underlying type is signed.    */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V6.2.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */
    /* Check if the requested hardware unit is busy */
    if(((LpAdcUserRegisters->ulADCAnSTR2 &
                     Adc_GaaCGmConvStatusMask[LucHwCGUnit]) != ADC_ZERO) || \
     (Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] == ADC_TRUE))
    {
      /* Initialise HW RAM data to a local pointer */
      LpHwUnitData = &Adc_GpHwUnitRamData[LddHwUnit];
      /* Push the requested group into the first come first serve mechanism
         queue */
      if(LpHwUnitData->ucQueueStatus != ADC_QUEUE_FULL)
      {
        /* Check if critical section protection is required */
        #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter the critical section protection */
        SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
        #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
        Adc_PushToQueue(Group);
        /* Check if critical section protection is required */
        #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit the critical section protection */
        SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
        #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
      }
      #if(ADC_DEV_ERROR_DETECT == STD_ON)
      else
      {
        /* Report Error to DET */
        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_START_GROUP_CONVERSION_SID, ADC_E_BUSY);
      }
      #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
    }
    else /* Hardware unit is not busy. Conversion can be taken up */
    {
      /* Set the Global variable indicating the HW unit is busy */
      Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
      Adc_ConfigureGroupForConversion(Group);
    }
    #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                           (ADC_ENABLE_QUEUING == STD_OFF)) */
  }
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* ADC_ENABLE_START_STOP_GROUP_API == STD_ON */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/*******************************************************************************
** Function Name        : Adc_StopGroupConversion
**
** Service ID           : 0x03
**
** Description          : This API service shall stop conversion of the
**                        requested ADC Channel group.
**                        Depending on the group configuration single-shot or
**                        continuous conversion is started.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus, Adc_GpGroupConfig,
**                        Adc_GpHwUnitConfig, Adc_GpGroupRamData,
**                        Adc_GpHwUnitRamData, Adc_GucMaxSwTriggGroups
**                        Function(s) invoked:
**                        Det_ReportError, Adc_ConfigureGroupForConversion,
**                        Adc_SearchnDelete, Adc_PopFromQueue
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PUBLIC_CODE) Adc_StopGroupConversion(Adc_GroupType Group)
{
  /* Pointer to the hardware unit user base configuration address */
  P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC,ADC_CONFIG_DATA)
                                                          LpAdcUserRegisters;
  /* Defining a pointer to the IMR structure */
  P2CONST(Tdd_AdcImrAddMaskConfigType, AUTOMATIC, ADC_CONFIG_DATA)
                                                            LpAdcImrAddMask;
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint16, AUTOMATIC, ADC_CONFIG_DATA) LpIntpCntrlReg;

  /* Local variable to store the hardware unit number */
  Adc_HwUnitType LddHwUnit;
  uint8 LucHwCGUnit;
  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to false */
  LblDetErrFlag = ADC_FALSE;
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                 ADC_STOP_GROUP_CONVERSION_SID, ADC_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  /* Check if the group requested is invalid */
  else if(Group >= ADC_MAX_GROUPS)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_STOP_GROUP_CONVERSION_SID, ADC_E_PARAM_GROUP);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  else
  {
    if(Group >= Adc_GucMaxSwTriggGroups)
    {
      /* Report Error to DET */
      Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_STOP_GROUP_CONVERSION_SID, ADC_E_WRONG_TRIGG_SRC);
      /* Set error status flag to true */
      LblDetErrFlag = ADC_TRUE;
    }
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
    if((Adc_GpGroupRamData[Group].ddGroupStatus == ADC_IDLE) &&
                      (Adc_GpGroupRamData[Group].ucGrpPresent == ADC_FALSE))
    #else
    if(Adc_GpGroupRamData[Group].ddGroupStatus == ADC_IDLE)
    #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                  ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                     (ADC_ENABLE_QUEUING == STD_ON))) */
    {
      /* Report Error to DET */
      Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                     ADC_STOP_GROUP_CONVERSION_SID, ADC_E_IDLE);
      /* Set error status flag to true */
      LblDetErrFlag = ADC_TRUE;
    }
  }
  /* Check if any DET was reported */
  if(LblDetErrFlag == ADC_FALSE)
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Read the Hardware Unit to which the group belongs */
    LddHwUnit = Adc_GpGroupConfig[Group].ucHwUnit;
    /* Get the CGm unit to which the channel group is mapped */
    LucHwCGUnit = Adc_GpGroupConfig[Group].ucHwCGUnit;

    /* Read the user base configuration address of the hardware unit */
    LpAdcUserRegisters = Adc_GpHwUnitConfig[LddHwUnit].pUserBaseAddress;

    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW)
    /* Check if CGm unit mapped to the requested group is busy */
    if(((LpAdcUserRegisters->ulADCAnSTR2 &
               Adc_GaaCGmConvStatusMask[LucHwCGUnit]) != ADC_ZERO) || \
     (Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] == ADC_TRUE))
    #else
    /* Check if ongoing conversion is of requested group */
    if(Adc_GpHwUnitRamData[LddHwUnit].ddCurrentConvGroup[LucHwCGUnit] == Group)
    #endif /* #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) */
    {
      /* Stop the conversion of the requested channel group */
      LpAdcUserRegisters->ucADCAnTRG4[LucHwCGUnit * ADC_FOUR] = \
                                                         ADC_STOP_CONVERSION;
      /* Clear the channels configured for the requested group */
      LpAdcUserRegisters->ulADCAnIOCm[LucHwCGUnit] = ADC_CLEAR_CHANNEL_LIST;
      /* Disable the interrupt for the CGm unit to which the group is mapped */
      LpAdcImrAddMask = Adc_GpHwUnitConfig[LddHwUnit].pImrAddMask;
      LpAdcImrAddMask = &LpAdcImrAddMask[LucHwCGUnit];
      /* MISRA Rule         : 12.7                                         */
      /* Message            : Bitwise operators shall not be applied to    */
      /*                      operands whose underlying type is signed.    */
      /* Reason             : Though the bitwise operation is performed on */
      /*                      unsigned data, this warning is generated by  */
      /*                      the QAC tool V6.2.1 as an indirect result of */
      /*                      integral promotion in complex bitwise        */
      /*                      operations.                                  */
      /* Verification       : However, this part of the code is verified   */
      /*                      manually and it is not having any impact.    */
      *(LpAdcImrAddMask->pImrIntpAddress) |= ~(LpAdcImrAddMask->ucImrMask);
      /* Clear the pending interrupt for the CGm unit to which the
         group is mapped */
      LpIntpCntrlReg = Adc_GpHwUnitConfig[LddHwUnit].pIntpAddress;
      LpIntpCntrlReg = &LpIntpCntrlReg[LucHwCGUnit];
      *LpIntpCntrlReg &= ADC_CLEAR_INT_REQUEST_FLAG;
      /* Group Priority is enabled or queue is enabled */
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
      /* Fetch the next group for conversion if the queue is not empty */
      if(Adc_GpHwUnitRamData[LddHwUnit].ucQueueStatus != ADC_QUEUE_EMPTY)
      {
        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
        /* MISRA Rule         : 12.7                                         */
        /* Message            : Bitwise operators shall not be applied to    */
        /*                      operands whose underlying type is signed.    */
        /* Reason             : Though the bitwise operation is performed on */
        /*                      unsigned data, this warning is generated by  */
        /*                      the QAC tool V6.2.1 as an indirect result of */
        /*                      integral promotion in complex bitwise        */
        /*                      operations.                                  */
        /* Verification       : However, this part of the code is verified   */
        /*                      manually and it is not having any impact.    */
        /* Set the flag indicating the group is popped out of the queue */
        Adc_GucPopFrmQueue |= (ADC_ONE << LddHwUnit);
        #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
        /* Check if critical section protection is required */
        #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter the critical section protection */
        SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
        #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
        /* Set the Global variable indicating the HW unit is busy */
        Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
        Adc_ConfigureGroupForConversion(Adc_PopFromQueue(LddHwUnit));
        /* Check if critical section protection is required */
        #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit the critical section protection */
        SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
        #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
      }
      #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON))) */
    }
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
    else if(Adc_GpGroupRamData[Group].ucGrpPresent == ADC_TRUE)
    {
      /* Search and delete the requested group from the queue */
      Adc_SearchnDelete(Group, LddHwUnit);
    }
    else
    {
      /* To avoid QAC warning */
    }
    #endif /*   #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON))) */
    /* Set the group status as idle */
    Adc_GpGroupRamData[Group].ddGroupStatus = ADC_IDLE;
    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* Store disabled notification into RAM */
    Adc_GpGroupRamData[Group].ucNotifyStatus = ADC_FALSE;
    #endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
  }
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* ADC_ENABLE_START_STOP_GROUP_API == STD_ON */

#if (ADC_READ_GROUP_API == STD_ON)
/*******************************************************************************
** Function Name        : Adc_ReadGroup
**
** Service ID           : 0x04
**
** Description          : This API service shall read the group conversion
**                        result of the last completed conversion round of
**                        requested group
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group and DataBufferPtr
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Std_ReturnType
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus, Adc_GpGroupConfig,
**                        Adc_GpGroupRamData
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Std_ReturnType, ADC_PUBLIC_CODE)
Adc_ReadGroup (Adc_GroupType Group,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) DataBufferPtr)
{
  P2CONST(Tdd_Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_CONFIG_DATA) LpChannelBuffer;
  P2VAR(Tdd_Adc_RunTimeData, AUTOMATIC,ADC_CONFIG_DATA) LpRunTimeData;
  Std_ReturnType LddReadStatus;
  Adc_HwUnitType LddHwUnit;
  uint8 LucHwCGUnit;
  uint8 LucNoOfSamples;
  /* Assuming the API will be called for single access mode */
  uint8 LucLoopCount = ADC_ONE;

  /* Initialise the return value */
  LddReadStatus = E_NOT_OK;

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                      ADC_READ_GROUP_SID, ADC_E_UNINIT);
  }
  /* Check if the requested group is invalid */
  else if(Group >= ADC_MAX_GROUPS)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                 ADC_READ_GROUP_SID, ADC_E_PARAM_GROUP);
  }
  else if(Adc_GpGroupRamData[Group].ddGroupStatus == ADC_IDLE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                 ADC_READ_GROUP_SID, ADC_E_IDLE);
  }
  else
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Read the hardware unit of the group */
    LpGroup = &Adc_GpGroupConfig[Group];
    /* Read the Hardware Unit to which the group belongs */
    LddHwUnit = LpGroup->ucHwUnit;
    /* Get the CGm unit to which the channel group is mapped */
    LucHwCGUnit = LpGroup->ucHwCGUnit;
    /* Read the group data pointer */
    LpRunTimeData =
      &Adc_GpRunTimeData[(LddHwUnit * ADC_NUMBER_OF_CG_UNITS) + LucHwCGUnit];

    /* Get the base address of the Group buffer */
    LpChannelBuffer = Adc_GpGroupRamData[Group].pChannelBuffer;
    /* Get the number of samples configured for the group */
    LucNoOfSamples = LpGroup->ddNumberofSamples;
    if(LpGroup->ddGroupAccessMode == ADC_ACCESS_MODE_STREAMING)
    {
      /* Get the number of samples completed in the requested group */
      LucLoopCount = LpRunTimeData->ucSamplesCompleted;
    }
    /* Initialise the pointer to the latest sample of the first channel */
    LpChannelBuffer = &LpChannelBuffer[LucLoopCount - ADC_ONE];
    /* Initialise the loop count to zero */
    LucLoopCount = ADC_ZERO;
    do
    {
      /* Load the converted values to the application buffer */
      DataBufferPtr[LucLoopCount] =
                    LpChannelBuffer[LucLoopCount * LucNoOfSamples];
      /* Increment to the next buffer index */
      LucLoopCount++;
    }
    while(LucLoopCount < LpGroup->ucChannelCount);

    /* Check if critical section protection is required */
    #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter the critical section protection */
    SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
    #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Change the group status of the group whose values are read */
    Adc_StateTransition(Group);
    /* Check if critical section protection is required */
    #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit the critical section protection */
    SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
    #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operators shall not be applied to    */
    /*                      operands whose underlying type is signed.    */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V6.2.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */
    /* Set the flag indicating result data is read */
    Adc_GpGroupRamData[Group].blResultRead = ADC_TRUE;
    /* Update the return value */
    LddReadStatus = E_OK;
  }
  return(LddReadStatus);
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* ADC_READ_GROUP_API == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Function Name        : Adc_EnableHardwareTrigger
**
** Service ID           : 0x05
**
** Description          : This API service will enable the hardware trigger
**                        for the requested ADC Channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus, Adc_GpHwUnitConfig,
**                        Adc_GpGroupConfig, Adc_GpConfigPtr,
**                        Adc_GpGroupRamData, Adc_GucMaxSwTriggGroups
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PUBLIC_CODE) Adc_EnableHardwareTrigger(Adc_GroupType Group)
{
  #if(ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
  P2VAR(Tdd_Adc_RunTimeData, AUTOMATIC,ADC_CONFIG_DATA) LpRunTimeData;
  #endif /* #if(ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) */

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
      (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
  /* Pointer to the hardware unit user base configuration address */
  P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC,ADC_CONFIG_DATA)
                                                            LpAdcUserRegisters;
  /* Local variable to store the hardware unit number */
  Adc_HwUnitType LddHwUnit;
  /* Local variable to store the CGm unit number */
  uint8 LucHwCGUnit;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
      (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */

  #if(ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
  Adc_GroupType LddCurrentGroup;
  #endif /* #if(ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) */

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to false */
  LblDetErrFlag = ADC_FALSE;
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_ENABLE_HARWARE_TRIGGER_SID, ADC_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  /* Check if the requested group is invalid */
  else if(Group >= ADC_MAX_GROUPS)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                           ADC_ENABLE_HARWARE_TRIGGER_SID, ADC_E_PARAM_GROUP);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  else
  {
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
    /* Read the Hardware Unit to which the group belongs */
    LddHwUnit = Adc_GpGroupConfig[Group].ucHwUnit;
    /* Read the user base configuration address of the hardware unit */
    LpAdcUserRegisters = Adc_GpHwUnitConfig[LddHwUnit].pUserBaseAddress;
    /* Get the CGm unit to which the channel group is mapped */
    LucHwCGUnit = Adc_GpGroupConfig[Group].ucHwCGUnit;
    #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                     (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */
    /* Check if requested group is SW triggered group */
    if(Group < Adc_GucMaxSwTriggGroups)
    {
      /* Report Error to DET */
      Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                         ADC_ENABLE_HARWARE_TRIGGER_SID, ADC_E_WRONG_TRIGG_SRC);
      /* Set error status flag to true */
      LblDetErrFlag = ADC_TRUE;
    }
    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operators shall not be applied to    */
    /*                      operands whose underlying type is signed.    */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V6.2.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */
    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
    /* Check if HW unit is busy */
    if(((LpAdcUserRegisters->ulADCAnSTR2 & Adc_GaaCGmConvStatusMask[LucHwCGUnit])
        != ADC_ZERO) || \
     (Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] == ADC_TRUE))
    {
      /* Report Error to DET */
      Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_ENABLE_HARWARE_TRIGGER_SID, ADC_E_BUSY);
      /* Set error status flag to true */
      LblDetErrFlag = ADC_TRUE;
    }
    #endif /* #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) */
    /* Check if the group is already enabled */
    if(Adc_GpGroupRamData[Group].ucHwTriggStatus == ADC_TRUE)
    {
      /* Report Error to DET */
      Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                  ADC_ENABLE_HARWARE_TRIGGER_SID, ADC_E_BUSY);
      /* Set error status flag to true */
      LblDetErrFlag = ADC_TRUE;
    }
    /* Check if result buffer is initialized for requested group */
    if(Adc_GpGroupRamData[Group].ucBufferStatus == ADC_FALSE)
    {
      /* Report Error to DET */
      Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                         ADC_ENABLE_HARWARE_TRIGGER_SID, ADC_E_BUFFER_UNINIT);
      /* Set error status flag to true */
      LblDetErrFlag = ADC_TRUE;
    }
  }
  /* Check if any DET was reported */
  if(LblDetErrFlag == ADC_FALSE)
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if the priority is ADC_PRIORITY_HW or ADC_PRIORITY_HW_SW */
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
          (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))

    Adc_EnableHWGroup(Group);

    #elif ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                 (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))

    #if (ADC_DEV_ERROR_DETECT == STD_OFF)
    /* Read the Hardware Unit to which the group belongs */
    LddHwUnit = Adc_GpGroupConfig[Group].ucHwUnit;
    /* Read the user base configuration address of the hardware unit */
    LpAdcUserRegisters = Adc_GpHwUnitConfig[LddHwUnit].pUserBaseAddress;
    /* Get the CGm unit to which the channel group is mapped */
    LucHwCGUnit = Adc_GpGroupConfig[Group].ucHwCGUnit;
    #endif /* #if (ADC_DEV_ERROR_DETECT == STD_OFF) */

    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operators shall not be applied to    */
    /*                      operands whose underlying type is signed.    */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V6.2.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */
    if(((LpAdcUserRegisters->ulADCAnSTR2 &
              Adc_GaaCGmConvStatusMask[LucHwCGUnit]) == ADC_ZERO) || \
     (Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] == ADC_TRUE))
    {
      Adc_EnableHWGroup(Group);
    }
    #if(ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
    else if(Adc_GpHwUnitRamData[LddHwUnit].ddCurrentPriority[LucHwCGUnit] <
                                   Adc_GpGroupConfig[Group].ddGroupPriority)
    {
      /* Fetch the group id of the current conversion group */
      LddCurrentGroup =
             Adc_GpHwUnitRamData[LddHwUnit].ddCurrentConvGroup[LucHwCGUnit];
      /* Check if the current ongoing conversion is of SW triggered group */
      if(Adc_GpHwUnitRamData[LddHwUnit].ddTrigSource == ADC_TRIGG_SRC_SW)
      {
        /* Check if the queue is full */
        if(Adc_GpHwUnitRamData[LddHwUnit].ucQueueStatus != ADC_QUEUE_FULL)
        {
          /* Check if critical section protection is required */
          #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter the critical section protection */
          SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
          #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
          /* Stop the conversion of the channel group */
          LpAdcUserRegisters->ucADCAnTRG4[LucHwCGUnit * ADC_FOUR] =
                                                      ADC_STOP_CONVERSION;
          /* Push the current conversion group into queue */
          Adc_PushToQueue(LddCurrentGroup);
          /* Check if critical section protection is required */
          #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter the critical section protection */
          SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
          #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
          /* Read the group data pointer */
          LpRunTimeData = &Adc_GpRunTimeData
                        [(LddHwUnit * ADC_NUMBER_OF_CG_UNITS) + LucHwCGUnit];
          /* Check if the group as to be resumed from where it had stopped
           before */
          if(Adc_GpGroupConfig[LddCurrentGroup].ddGroupReplacement ==
                                          ADC_GROUP_REPL_SUSPEND_RESUME)
          {
            /* Load the number of channels converted before suspension */
            Adc_GpGroupRamData[LddCurrentGroup].ucReChannelsCompleted =
                       LpRunTimeData->ucChannelsCompleted;
          }
          /* Load the number of samples converted before aborting or
           suspension */
          Adc_GpGroupRamData[LddCurrentGroup].ucReSamplesCompleted =
                     LpRunTimeData->ucSamplesCompleted;
          /* Configure the requested group for conversion */
          Adc_EnableHWGroup(Group);
        }
        #if(ADC_DEV_ERROR_DETECT == STD_ON)
        else
        {
          /* Report Error to DET */
          Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                              ADC_ENABLE_HARWARE_TRIGGER_SID, ADC_E_BUSY);
        }
        #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
      }
      else
      {
        Adc_DisableHWGroup(LddCurrentGroup);
        Adc_EnableHWGroup(Group);
      }
    }
    #endif /* #if(ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) */
    else
    {
      #if(ADC_DEV_ERROR_DETECT == STD_ON)
      /* Report Error to DET */
      Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_ENABLE_HARWARE_TRIGGER_SID, ADC_E_BUSY);
      #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
    }
    #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
                  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
  }
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Function Name        : Adc_DisableHardwareTrigger
**
** Service ID           : 0x06
**
** Description          : This API service will disables the hardware trigger
**                        for the requested ADC Channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus, Adc_GpHwUnitConfig,
**                        Adc_GpGroupRamData, Adc_GucMaxSwTriggGroups
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PUBLIC_CODE) Adc_DisableHardwareTrigger(Adc_GroupType Group)
{
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
              ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                             (ADC_ENABLE_QUEUING == STD_ON)))
  Adc_HwUnitType LddHwUnit;
  volatile uint8 LucHwCGUnit;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
              ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                             (ADC_ENABLE_QUEUING == STD_ON))) */

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                               ADC_DISABLE_HARWARE_TRIGGER_SID, ADC_E_UNINIT);
  }
  /* Check if the requested group is invalid */
  else if(Group >= ADC_MAX_GROUPS)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                          ADC_DISABLE_HARWARE_TRIGGER_SID, ADC_E_PARAM_GROUP);
  }
  /* Check if requested group is SW triggered group */
  else if(Group < Adc_GucMaxSwTriggGroups)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                      ADC_DISABLE_HARWARE_TRIGGER_SID, ADC_E_WRONG_TRIGG_SRC);
  }
  /* Check if HW trigger was enabled for requested group */
  else if(Adc_GpGroupRamData[Group].ucHwTriggStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                      ADC_DISABLE_HARWARE_TRIGGER_SID, ADC_E_IDLE);
  }
  else
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    if(Adc_GpGroupRamData[Group].ucHwTriggStatus == ADC_TRUE)
    {
      /* Disable the ongoing HW triggered group */
      Adc_DisableHWGroup(Group);

      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
              ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                             (ADC_ENABLE_QUEUING == STD_ON)))
      /* Read the Hardware Unit to which the group belongs */
      LddHwUnit = Adc_GpGroupConfig[Group].ucHwUnit;
      /* Fetch the next group for conversion if the queue is not empty */
      if(Adc_GpHwUnitRamData[LddHwUnit].ucQueueStatus != ADC_QUEUE_EMPTY)
      {
        #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
        /* MISRA Rule         : 12.7                                         */
        /* Message            : Bitwise operators shall not be applied to    */
        /*                      operands whose underlying type is signed.    */
        /* Reason             : Though the bitwise operation is performed on */
        /*                      unsigned data, this warning is generated by  */
        /*                      the QAC tool V6.2.1 as an indirect result of */
        /*                      integral promotion in complex bitwise        */
        /*                      operations.                                  */
        /* Verification       : However, this part of the code is verified   */
        /*                      manually and it is not having any impact.    */
        /* Set the flag indicating the group is popped out of the queue */
        Adc_GucPopFrmQueue |= (ADC_ONE << LddHwUnit);
        #endif /* #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) */

        /* Check if critical section protection is required */
        #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter the critical section protection */
        SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
        #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
        /* Set the Global variable indicating the HW unit is busy */
        Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
        Adc_ConfigureGroupForConversion(Adc_PopFromQueue(LddHwUnit));
        /* Check if critical section protection is required */
        #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit the critical section protection */
        SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
        #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
      }
      #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
              ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                           (ADC_ENABLE_QUEUING == STD_ON))) */
    }
  }
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/*******************************************************************************
** Function Name        : Adc_EnableGroupNotification
**
** Service ID           : 0x07
**
** Description          : This API service will enable the ADC Driver
**                        notification of the requested channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus, Adc_GpGroupRamData
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PUBLIC_CODE) Adc_EnableGroupNotification(Adc_GroupType Group)
{
  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                             ADC_ENABLE_GROUP_NOTIFICATION_SID, ADC_E_UNINIT);
  }
  /* Check if the requested group is invalid */
  else if(Group >= ADC_MAX_GROUPS)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                        ADC_ENABLE_GROUP_NOTIFICATION_SID, ADC_E_PARAM_GROUP);
  }
  else if(Adc_GstChannelGrpFunc[Group].pGroupNotificationPointer == NULL_PTR)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                   ADC_ENABLE_GROUP_NOTIFICATION_SID, ADC_E_NOTIF_CAPABILITY);
  }
  else
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter the critical section protection */
    SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
    #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Store the enabled notification into RAM */
    Adc_GpGroupRamData[Group].ucNotifyStatus = ADC_TRUE;
    #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit the critical section protection */
    SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
    #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/*******************************************************************************
** Function Name        : Adc_DisableGroupNotification
**
** Service ID           : 0x08
**
** Description          : This API service will disable the ADC Driver
**                        notification of the requested channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus, Adc_GpGroupRamData
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PUBLIC_CODE) Adc_DisableGroupNotification(Adc_GroupType Group)
{
  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_DISABLE_GROUP_NOTIFICATION_SID, ADC_E_UNINIT);
  }
  /* Check if the requested group is invalid */
  else if(Group >= ADC_MAX_GROUPS)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                       ADC_DISABLE_GROUP_NOTIFICATION_SID, ADC_E_PARAM_GROUP);
  }
  else if(Adc_GstChannelGrpFunc[Group].pGroupNotificationPointer == NULL_PTR)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                  ADC_DISABLE_GROUP_NOTIFICATION_SID, ADC_E_NOTIF_CAPABILITY);
  }
  else
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    
    #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter the critical section protection */
    SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
    #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Store the disabled notification into RAM */
    Adc_GpGroupRamData[Group].ucNotifyStatus = ADC_FALSE;
    #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit the critical section protection */
    SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
    #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

/*******************************************************************************
** Function Name        : Adc_GetGroupStatus
**
** Service ID           : 0x09
**
** Description          : This API service shall return the conversion status of
**                        requested ADC Channel group.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Adc_StatusType
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus, Adc_GpGroupRamData
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Adc_StatusType, ADC_PUBLIC_CODE) Adc_GetGroupStatus(Adc_GroupType Group)
{
  /* Local variable to store the group status */
  Adc_StatusType LddGroupStatus;

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */

  /* Default value that to be returned in case of error */
  LddGroupStatus = ADC_IDLE;

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to false */
  LblDetErrFlag = ADC_FALSE;
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                      ADC_GET_GROUP_STATUS_SID, ADC_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  /* Check if the requested group is invalid */
  if(Group >= ADC_MAX_GROUPS)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                 ADC_GET_GROUP_STATUS_SID, ADC_E_PARAM_GROUP);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  /* Check if any DET was reported */
  if(LblDetErrFlag == ADC_FALSE)
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if critical section protection is required */
    #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter the critical section protection */
    SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
    #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Read the group status */
    LddGroupStatus = Adc_GpGroupRamData[Group].ddGroupStatus;

    /* Check if critical section protection is required */
    #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit the critical section protection */
    SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
    #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  return(LddGroupStatus);
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Adc_GetStreamLastPointer
**
** Service ID           : 0x0B
**
** Description          : This API service shall return the pointer to the last
**                        converted value for the group configured in streaming
**                        access mode.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group
**
** InOut Parameters     : None
**
** Output Parameters    : PtrToSamplePtr (pointer of Adc_ValueGroupType)
**
** Return parameter     : Adc_StreamNumSampleType
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus, Adc_GpGroupConfig,
**                        Adc_GpGroupRamData
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Adc_StreamNumSampleType, ADC_PUBLIC_CODE) Adc_GetStreamLastPointer
(Adc_GroupType Group, P2VAR(P2VAR(Adc_ValueGroupType,
AUTOMATIC, ADC_CONFIG_DATA), AUTOMATIC,ADC_CONFIG_DATA) PtrToSamplePtr)
{
  P2CONST(Tdd_Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2VAR(uint16, AUTOMATIC,ADC_CONFIG_DATA) LpBuffer;
  P2VAR(Tdd_Adc_RunTimeData, AUTOMATIC,ADC_CONFIG_DATA) LpRunTimeData;
  Adc_StreamNumSampleType LddSampleCount;
  Adc_HwUnitType LddHwUnit;
  uint8 LucHwCGUnit;
  uint8 LucNumofChannels;

  /* Default value to be returned in case of error */
  *PtrToSamplePtr = NULL_PTR;
  LddSampleCount = ADC_ZERO;

  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                ADC_GET_STREAM_LAST_POINTER_SID, ADC_E_UNINIT);
  }
  /* Check if the requested group is invalid */
  else if(Group >= ADC_MAX_GROUPS)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                           ADC_GET_STREAM_LAST_POINTER_SID, ADC_E_PARAM_GROUP);
  }
  else if(Adc_GpGroupRamData[Group].ddGroupStatus == ADC_IDLE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                               ADC_GET_STREAM_LAST_POINTER_SID, ADC_E_IDLE);
  }
  else
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    if((Adc_GpGroupRamData[Group].ddGroupStatus == ADC_COMPLETED) ||
      (Adc_GpGroupRamData[Group].ddGroupStatus == ADC_STREAM_COMPLETED))
    {
      /* Read the hardware unit of the group */
      LpGroup = &Adc_GpGroupConfig[Group];
      /* Read the Hardware Unit to which the group belongs */
      LddHwUnit = LpGroup->ucHwUnit;
      /* Read the configured number of samples for the group */
      LddSampleCount = LpGroup->ddNumberofSamples;

      /* Read the base pointer of the streaming group */
      LpBuffer = Adc_GpGroupRamData[Group].pChannelBuffer;
      /* Read the number of channels in the group */
      LucNumofChannels = LpGroup->ucChannelCount;
      /* Load the pointer of the last converted value */
      *PtrToSamplePtr =
                    &LpBuffer[((LddSampleCount * LucNumofChannels) - ADC_ONE)];

      /* Get the CGm unit to which the channel group is mapped */
      LucHwCGUnit = LpGroup->ucHwCGUnit;
      /* Read the group data pointer */
      LpRunTimeData =
       &Adc_GpRunTimeData[(LddHwUnit * ADC_NUMBER_OF_CG_UNITS) + LucHwCGUnit];
      /* Get the number of samples completed for the requested group */
      LddSampleCount = LpRunTimeData->ucSamplesCompleted;
      /* Check if the group is configured for DMA access */
      if(LpGroup->ucResultAccessMode == ADC_DMA_ACCESS)
      {
        /* Update the return value to one */
        LddSampleCount = ADC_ONE;
      }
      /* Check if critical section protection is required */
      #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter the critical section protection */
      SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
      #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Change the group status of the group whose values are read */
      Adc_StateTransition(Group);
      /* Check if critical section protection is required */
      #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit the critical section protection */
      SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
      #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* MISRA Rule         : 12.7                                         */
      /* Message            : Bitwise operators shall not be applied to    */
      /*                      operands whose underlying type is signed.    */
      /* Reason             : Though the bitwise operation is performed on */
      /*                      unsigned data, this warning is generated by  */
      /*                      the QAC tool V6.2.1 as an indirect result of */
      /*                      integral promotion in complex bitwise        */
      /*                      operations.                                  */
      /* Verification       : However, this part of the code is verified   */
      /*                      manually and it is not having any impact.    */
      /* Set the flag indicating result data is read */
      Adc_GpGroupRamData[Group].blResultRead = ADC_TRUE;
    }
  }
  /* Return the number of samples */
  return(LddSampleCount);
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Adc_SetupResultBuffer
**
** Service ID           : 0x0C
**
** Description          : Initializes the group specific ADC result buffer
**                        pointer as configured to point to the DataBufferPtr.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : Group and DataBufferPtr
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Std_ReturnType
**
** Preconditions        : The ADC Driver must be initialised first by invoking
**                        API Adc_Init().
**
** Remarks              : Global Variable(s):
**                        Adc_GblDriverStatus
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/

#define ADC_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Std_ReturnType, ADC_PUBLIC_CODE) Adc_SetupResultBuffer
(Adc_GroupType Group,
P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_CONST) DataBufferPtr)
{
  Std_ReturnType LddSetupStatus;
  #if(ADC_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  /* Initialise the return value */
  LddSetupStatus = E_NOT_OK;

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status flag to false */
  LblDetErrFlag = ADC_FALSE;
  /* Check if the ADC Module is not initialised */
  if(Adc_GblDriverStatus == ADC_FALSE)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                                    ADC_SETUP_RESULT_BUFFER_SID, ADC_E_UNINIT);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  /* Check if the Group requested is valid */
  if(Group >= ADC_MAX_GROUPS)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_SETUP_RESULT_BUFFER_SID, ADC_E_PARAM_GROUP);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  if(DataBufferPtr == NULL_PTR)
  {
    /* Report Error to DET */
    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
                            ADC_SETUP_RESULT_BUFFER_SID, ADC_E_PARAM_POINTER);
    /* Set error status flag to true */
    LblDetErrFlag = ADC_TRUE;
  }
  /* Check if any DET was reported */
  if(LblDetErrFlag == ADC_FALSE)
  #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Initialise the group result buffer pointer with the address passed */
    Adc_GpGroupRamData[Group].pChannelBuffer = DataBufferPtr;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Set the buffer initialization status */
    Adc_GpGroupRamData[Group].ucBufferStatus = ADC_TRUE;
    #endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
    /* Update the return value */
    LddSetupStatus = E_OK;
  }
  return(LddSetupStatus);
}

#define ADC_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */


/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
