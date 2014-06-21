/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Adc_Private.c                                               */
/* Version      = 3.1.6                                                       */
/* Date         = 28-Mar-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Internal functions implementation of ADC Driver Component                  */
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
 *                         2. Prototype of the functions Adc_Isr and ADC_DmaIsr
 *                            are updated based on the priority configured.
 *                         3. Internal ISR function call based on priority is
 *                            updated in the function Adc_Isr.
 *                         4. Adc_DmaIsr is updated to set the NTCV bit.
 *                         5. Adc_ConfigureGroupForConversion is updated to
 *                            load the channel list value.
 *                         6. Adc_ConfigureGroupForConversion is updated to set
 *                            INF bit.
 *                         7. Adc_EnableHWGroup is updated for PIC macro
 *                            enhancement.
 *                         8. Adc_DisableHWGroup is updated to clear the
 *                            channel list to avoid conversion.
 *
 * V3.0.2:  05-Nov-2009  : As per SCR 088, I/O structure is updated to have
 *                         separate base address for USER and OS registers.
 *
 * V3.0.3:  02-Dec-2009  : As per SCR 157, the following changes are made
 *                         1. Adc_ConfigureGroupForConversion is
 *                            updated to clear the pending interrupt before
 *                            enabling the DMA channel.
 *                         2. Adc_GroupCompleteMode is included within the
 *                            pre-compile option.
 *
 * V3.0.4:  05-Jan-2010  : As per SCR 179, Adc_GucResultRead and
 *                         Adc_GblSampleComp are replaced by group RAM variable.
 *
 * V3.0.5:  26-Feb-2010  : As per SCR 200, the following changes are made
 *                         1. Adc_DisableHWGroup is updated to disable the
 *                            interrupt configured for the CGm unit mapped for
 *                            the requested group.
 *                         2. Adc_ConfigureGroupForConversion is updated for
 *                            group status change when poped from the queue.
 *
 * V3.0.6:  03-Mar-2010  : As per SCR 209, initiating the conversion of the
 *                         channel group, is moved after the status is
 *                         changed to ADC_BUSY in the internal function
 *                         'Adc_ConfigureGroupForConversion', to avoid the
 *                         probability of channel completion interrupt occurring
 *                         before the status is set to ADC_BUSY and causing
 *                         undesired output.
 *
 * V3.0.7:  01-Jul-2010  : As per SCR 295, the following changes are made
 *                         1. Adc_Isr and Adc_DmaIsr are updated to get
 *                            the HW unit index from the mapping array
 *                            Adc_GaaHwUnitIndex.
 *                         2. Queue status updation is updated in the functions
 *                            Adc_PopFromQueue and Adc_SearchnDelete.
 *                         3. Adc_GaaStreamEnableMask[] and
 *                            Adc_GaaOperationMask[] are added.
 *                         4. Interrupt control register is replaced by IMR
 *                            register.
 *
 * V3.0.8:  20-Jul-2010  : As per SCR 309, the following changes are made
 *                         1. Queue status updation is updated in the functions
 *                            Adc_PushToQueue, Adc_PopFromQueue and
 *                            Adc_SearchnDelete.
 *                         2. In structure Tdd_Adc_HwUnitConfigType, parameter
 *                            pCGmDmaConfig is deleted. So the function
 *                            Adc_ConfigureGroupForConversion is adapted to use
 *                            ucDmaChannelIndex parameter from the structure
 *                            Tdd_Adc_GroupConfigType.
 *
 * V3.0.9:  28-Jul-2010  : As per SCR 316, the following changes are made
 *                         1. Updated the functions Adc_DisableHWGroup and
 *                            Adc_ConfigureGroupForConversion for clearing
 *                            the pending interrupt.
 *                         2. Updated Indent for the function Adc_PopFromQueue.
 *                         3. Unnecessary pre-compile option is removed in the
 *                            function Adc_ConfigureGroupForConversion and
 *                            comments are updated.
 *
 * V3.0.10: 22-Jun-2011  : As per SCR 475, access of DMA channel Id in the 
 *                         function pointer 'LpCGmDmaConfig' is updated
 *
 * V3.1.0:  27-Jul-2011  : Modified for DK-4
 * V3.1.1:  04-Oct-2011  : Added comments for the violation of MISRA rule 19.1

 * V3.1.2:  14-Feb-2012  : Merged the fixes done for Fx4L Adc driver
 *
 * V3.1.3:  11-May-2012  : As per SCR 006, following changes are made:
 *                         1. New line is added at the end of file.
 *                         2. File version is changed.
 *
 * V3.1.4:  04-Jun-2012  : As per SCR 019, following changes are made:
 *                         1. Adc_ConfigureGroupForConversion()
 *                         function is updated to correct the DMA pointer
 *                         access.
 *                         2. File version is changed.
 * V3.1.5:  19-Nov-2012  : As per MNT_0007541, comment added at "#endif'
 *                         in function "Adc_ConfigureGroupForConversion".
 * V3.1.6:  28-Mar-2013  : As per SCR 083 for MNT_0009451,
 *                         1. "Adc_ChannelCompleteMode" & "Adc_GroupCompleteMode 
 *                            is implemented as reentrant
 *                         2. Copyright information is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Adc.h"
#include "Adc_Private.h"
#include "Adc_LTTypes.h"
#include "Adc_Ram.h"
#if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Adc.h"
#endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define ADC_PRIVATE_C_AR_MAJOR_VERSION  ADC_AR_MAJOR_VERSION_VALUE
#define ADC_PRIVATE_C_AR_MINOR_VERSION  ADC_AR_MINOR_VERSION_VALUE
#define ADC_PRIVATE_C_AR_PATCH_VERSION  ADC_AR_PATCH_VERSION_VALUE

/* File version information */
#define ADC_PRIVATE_C_SW_MAJOR_VERSION  3
#define ADC_PRIVATE_C_SW_MINOR_VERSION  1
#define ADC_PRIVATE_C_SW_PATCH_VERSION  4

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (ADC_PRIVATE_AR_MAJOR_VERSION != ADC_PRIVATE_C_AR_MAJOR_VERSION)
  #error "Adc_Private.c : Mismatch in Specification Major Version"
#endif

#if (ADC_PRIVATE_AR_MINOR_VERSION != ADC_PRIVATE_C_AR_MINOR_VERSION)
  #error "Adc_Private.c : Mismatch in Specification Minor Version"
#endif

#if (ADC_PRIVATE_AR_PATCH_VERSION != ADC_PRIVATE_C_AR_PATCH_VERSION)
  #error "Adc_Private.c : Mismatch in Specification Patch Version"
#endif

#if (ADC_PRIVATE_SW_MAJOR_VERSION != ADC_PRIVATE_C_SW_MAJOR_VERSION)
  #error "Adc_Private.c : Mismatch in Major Version"
#endif

#if (ADC_PRIVATE_SW_MINOR_VERSION != ADC_PRIVATE_C_SW_MINOR_VERSION)
  #error "Adc_Private.c : Mismatch in Minor Version"
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
#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
          (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
#if (ADC_HW_TRIGGER_API == STD_ON)
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
STATIC CONST(uint16, ADC_CONST) Adc_GaaStreamEnableMask[ADC_FIVE] =
{
  ADC_DUMMY,
  ADC_ONE_TIME_CONVERSION,
  ADC_TWO_TIME_CONVERSION,
  ADC_THREE_TIME_CONVERSION,
  ADC_FOUR_TIME_CONVERSION
};
#define ADC_STOP_SEC_CONST_16BIT
#include "MemMap.h"/* PRQA S 5087 */
#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
          (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */


#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
              (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
#define ADC_START_SEC_CONST_32BIT
#include "MemMap.h"/* PRQA S 5087 */
STATIC CONST(uint32, ADC_CONST) Adc_GaaOperationMask[ADC_TWO] =
{
  ADC_CG0_CONV_CONTINUOUS,
  ADC_CG0_CONV_ONCE
};
#define ADC_STOP_SEC_CONST_32BIT
#include "MemMap.h"/* PRQA S 5087 */
#endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
              (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
           ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
/*******************************************************************************
** Function Name        : Adc_PushToQueue
**
** Service ID           : NA
**
** Description          : This function add the requested group into Queue.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
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
**                        Adc_GpGroupConfig, Adc_GpHwUnitConfig,
**                        Adc_GpHwUnitRamData
**                        Function(s) invoked:
**                        None
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PRIVATE_CODE) Adc_PushToQueue(Adc_GroupType LddGroup)
{
  P2CONST(Tdd_Adc_HwUnitConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpHwUnit;
  P2VAR(Tdd_Adc_HwUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpHwUnitData;
  P2VAR(Adc_GroupType, AUTOMATIC, ADC_CONFIG_DATA) LpQueue;
  Adc_HwUnitType LddHwUnit;
  uint8 LucLoopCount;
  uint8 LucQueueSize;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
          (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  uint8 LucPriority;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
          (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */

  /* Read for hardware unit and the Priority Queue */
  LddHwUnit = Adc_GpGroupConfig[LddGroup].ucHwUnit;
  /* Initialise HW RAM data to a local pointer */
  LpHwUnitData = &Adc_GpHwUnitRamData[LddHwUnit];
  LpHwUnit = &Adc_GpHwUnitConfig[LddHwUnit];
  LpQueue = LpHwUnit->pQueue;

  /* Read the configured priority queue size */
  LucQueueSize = LpHwUnit->ucAdcQueueSize;

  /* Read the queue counter */
  LucLoopCount = LpHwUnitData->ucQueueCounter;

  /* Set the flag indicating that group is present in the queue */
  Adc_GpGroupRamData[LddGroup].ucGrpPresent = ADC_TRUE;

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
              (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* Store the group into queue if queue is empty */
  if(LpHwUnitData->ucQueueStatus == ADC_QUEUE_EMPTY)
  #else
  /* Store the group into queue if queue is empty or not full */
  if((LpHwUnitData->ucQueueStatus == ADC_QUEUE_EMPTY) || \
                       (LpHwUnitData->ucQueueStatus == ADC_QUEUE_FILLED))
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
              (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
  {
    LpQueue[LucLoopCount] = LddGroup;
    /* Increment the queue counter */
    LpHwUnitData->ucQueueCounter++;
  }
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
          (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  else /* Queue not empty */
  {
    /* Read the priority of the requested group */
    LucPriority = Adc_GpGroupConfig[LddGroup].ddGroupPriority;

    /* Place the requested group in the queue based on this priority */
    do
    {
     /* MISRA Rule         : 17.4                                          */
     /* Message            : Array indexing shall be the only allowed      */
     /*                      form of pointer arithmetic                    */
     /* Reason             : To access the channel parameters              */
     /* Verification       : However, part of the code is verified manually*/
     /*                      and it is not having any impact.              */
      if(((LucLoopCount != ADC_ZERO) &&
      ((Adc_GpGroupConfig +
          LpQueue[LucLoopCount - ADC_ONE])->ddGroupPriority >= LucPriority)))
      {
        LpQueue[LucLoopCount] = LpQueue[LucLoopCount - ADC_ONE];
      }
      else
      {
        LpQueue[LucLoopCount] = LddGroup;
        LucLoopCount = ADC_ZERO;
      }
     /* MISRA Rule         : 12.13                                     */
     /* Message            : The increment (++) and decrement (--)     */
     /*                      operators should not be mixed with other  */
     /*                      operators in an expression.               */
     /* Reason             : To make the comparison till the 0th       */
     /*                      element in the priority queue.            */
     /* Verification       : However, part of the code is verified     */
     /*                      manually and it is not having any impact. */
    } while((LucLoopCount--) > ADC_ZERO);

    /* Increment the queue counter */
    LpHwUnitData->ucQueueCounter++;
  }
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
          (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */

  /* Check whether the Queue is Full */
  if(LpHwUnitData->ucQueueCounter >= LucQueueSize)
  {
    /* Set queue status as full */
    LpHwUnitData->ucQueueStatus = ADC_QUEUE_FULL;
  }
  else
  {
    /* Set queue status as filled */
    LpHwUnitData->ucQueueStatus = ADC_QUEUE_FILLED;
  }
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                               (ADC_ENABLE_QUEUING == STD_ON))) */

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
/*******************************************************************************
** Function Name        : Adc_PopFromQueue
**
** Service ID           : NA
**
** Description          : This function returns the highest priority group that
**                        was pushed in the Queue.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddHwUnit
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Group
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Adc_GpHwUnitConfig, Adc_GpHwUnitRamData,
**                        Adc_GpGroupRamData
**                        Function(s) invoked:
**                        None
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Adc_GroupType, ADC_PRIVATE_CODE) Adc_PopFromQueue(Adc_HwUnitType LddHwUnit)
{
  P2VAR(Tdd_Adc_HwUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpHwUnitData;
  P2VAR(Adc_GroupType, AUTOMATIC, ADC_CONFIG_DATA) LpQueue;
  Adc_GroupType LddGroup;
  uint8 LucQueueCounter;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                          (ADC_ENABLE_QUEUING == STD_ON))
  uint8 LucLoopCount = ADC_ZERO;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                          (ADC_ENABLE_QUEUING == STD_ON)) */
  /* Initialise HW RAM data to a local pointer */
  LpHwUnitData = &Adc_GpHwUnitRamData[LddHwUnit];
  LpQueue = Adc_GpHwUnitConfig[LddHwUnit].pQueue;

  /* Read the highest priority task from the queue */
  LucQueueCounter = LpHwUnitData->ucQueueCounter;

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
        (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))

  /* Get the Group which is of next priority level */
  LddGroup = LpQueue[LucQueueCounter - ADC_ONE];

  #elif ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                          (ADC_ENABLE_QUEUING == STD_ON))

  /* Decrement the queue counter value by one */
  LucQueueCounter--;
  /* Get the group which was requested just after the immediate
     conversion completed group */
  LddGroup = LpQueue[ADC_ZERO];
  do
  {
    /* Re-arrange the queue based on which channel group was requested first */
    LpQueue[LucLoopCount] = LpQueue[LucLoopCount + ADC_ONE];
    /* Increment the loop count */
    LucLoopCount++;

  }while(LucLoopCount < LucQueueCounter);

  #endif /*  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
        (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */

  /* Check whether the Queue is cleared */
  if(LpHwUnitData->ucQueueCounter > ADC_ZERO)
  {
    /* Update the queue counter */
    LpHwUnitData->ucQueueCounter--;
    if(LpHwUnitData->ucQueueCounter == ADC_ZERO)
    {
      /* Set queue status as empty */
      LpHwUnitData->ucQueueStatus = ADC_QUEUE_EMPTY;
    }
    else
    {
      /* Set queue status as filled */
      LpHwUnitData->ucQueueStatus = ADC_QUEUE_FILLED;
    }
  }
  /* Clear the flag indicating group is no longer in queue */
  Adc_GpGroupRamData[LddGroup].ucGrpPresent = ADC_FALSE;
  return(LddGroup);
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
       (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON))) */

/*******************************************************************************
** Function Name        : Adc_Isr
**
** Service ID           : NA
**
** Description          : This function is an interrupt service routine for ADC.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : LddHwUnit, LucCGUnit
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
**                        Adc_GpHwUnitRamData, Adc_GpGroupConfig
**                        Function(s) invoked:
**                        Adc_ServiceScanMode, Adc_ServiceSelectMode
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
FUNC(void, ADC_PRIVATE_CODE) Adc_Isr(Adc_HwUnitType LddHwUnit,
                                                 uint8 LucCGUnit)
#else
FUNC(void, ADC_PRIVATE_CODE) Adc_Isr(Adc_HwUnitType LddHwUnit)
#endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
{
  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
  /* Local variable to store the replacement type */
  Adc_GroupReplacementType LucGroupReplacement;
  #endif /* #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) */
  /* Local variable to store the group number */
  uint8 LucCurrentGroup;

  /* Get the requested HW unit's index */
  LddHwUnit = Adc_GaaHwUnitIndex[LddHwUnit];

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* Read the current conversion group number */
  LucCurrentGroup =
                Adc_GpHwUnitRamData[LddHwUnit].ddCurrentConvGroup[LucCGUnit];
  #else
  /* Read the current conversion group number */
  LucCurrentGroup =
                Adc_GpHwUnitRamData[LddHwUnit].ddCurrentConvGroup[ADC_ZERO];
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */

  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
  /* Read the ISR type configured for the HW unit */
  LucGroupReplacement = Adc_GpGroupConfig[LucCurrentGroup].ddGroupReplacement;
  /* Check if group is configured in abort/restart mode */
  if(LucGroupReplacement == ADC_GROUP_REPL_ABORT_RESTART)
  {
    /* Invoke group complete function */
    Adc_GroupCompleteMode(LucCurrentGroup, LddHwUnit);
  }
  else /* channel complete function */
  {
    /* Invoke channel complete function */
    Adc_ChannelCompleteMode(LucCurrentGroup, LddHwUnit);
  }
  #elif (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
  /* Invoke group complete function */
  Adc_GroupCompleteMode(LucCurrentGroup, LddHwUnit);
  #else /* if priority is ADC_PRIORITY_HW or ADC_PRIORITY_HW_SW */
  /* Invoke channel complete function */
  Adc_ChannelCompleteMode(LucCurrentGroup, LddHwUnit);
  #endif
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#if (ADC_DMA_MODE_ENABLE == STD_ON)
/*******************************************************************************
** Function Name        : Adc_DmaIsr
**
** Service ID           : NA
**
** Description          : This function is an DMA Completer interrupt service
**                        routine for ADC.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddHwUnit, LucCGUnit
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
**                        Adc_GpHwUnitRamData, Adc_GpGroupConfig
**                        Function(s) invoked:
**                        Adc_ServiceScanMode, Adc_ServiceSelectMode
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
FUNC(void, ADC_PRIVATE_CODE) Adc_DmaIsr(Adc_HwUnitType LddHwUnit,
                                                 uint8 LucCGUnit)
#else
FUNC(void, ADC_PRIVATE_CODE) Adc_DmaIsr(Adc_HwUnitType LddHwUnit)
#endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
{
  P2VAR(Tdd_Adc_ChannelGroupRamData, AUTOMATIC,ADC_CONFIG_DATA) LpGroupData;
  /* Local variable to store the group number */
  Adc_GroupType LddGroup;
  volatile uint8 LucHwCGUnit;
  /* Get the requested HW unit's index */
  LddHwUnit = Adc_GaaHwUnitIndex[LddHwUnit];

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  /* Read the current conversion group number */
  LddGroup = Adc_GpHwUnitRamData[LddHwUnit].ddCurrentConvGroup[LucCGUnit];
  #else
  /* Read the current conversion group number */
  LddGroup = Adc_GpHwUnitRamData[LddHwUnit].ddCurrentConvGroup[ADC_ZERO];
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */

  /* Read the group data pointer */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  /* Set group status as conversion completed */
  LpGroupData->ddGroupStatus = ADC_STREAM_COMPLETED;

  #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Invoke notification function if enabled */
  if((LpGroupData->ucNotifyStatus == ADC_TRUE) &&
      (Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer != NULL_PTR))
  {
    Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer();
  }
  #endif /* #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
  /* Check if the operation mode is continuous */
  if(Adc_GpGroupConfig[LddGroup].ucConversionMode == ADC_ONCE)
  {
    if(Adc_GpHwUnitRamData[LddHwUnit].ucQueueStatus != ADC_QUEUE_EMPTY)
    {
        /* Fetch the highest priority group from the queue */
        LddGroup = Adc_PopFromQueue(LddHwUnit);
        /* If Group Priority Enabled */
        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
        /* MISRA Rule         : 12.7                                        */
        /* Message            : Bitwise operators shall not be applied to   */
        /*                      operands whose underlying type is signed.   */
        /* Reason             : Though the bitwise operation is performed on*/
        /*                      unsigned data, this warning is generated by */
        /*                      the QAC tool V6.2.1 as an indirect result of*/
        /*                      integral promotion in complex bitwise       */
        /*                      operations.                                 */
        /* Verification       : However, this part of the code is verified  */
        /*                      manually and it is not having any impact.   */
        /* Set the flag indicating the group is popped out of the queue */
        Adc_GucPopFrmQueue |= (ADC_ONE << LddHwUnit);
        #endif /*  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
        /* Set the Global variable indicating the HW unit is busy */
        Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
        /* Initiate the group conversion */
        Adc_ConfigureGroupForConversion(LddGroup);
    }
  }
  #endif  /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON))) */
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */

#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
/*******************************************************************************
** Function Name        : Adc_ChannelCompleteMode
**
** Service ID           : NA
**
** Description          : This function is invoked from ADC ISR for servicing
**                        the groups configured in select operation mode.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup, LddHwUnit
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
**                        Adc_GpGroupConfig, Adc_GpGroupRamData,
**                        Adc_GstChannelGrpFunc, Adc_GucMaxSwTriggGroups
**                        Adc_GpHwUnitRamData, Adc_GpHwUnitConfig
**                        Function(s) invoked:
**                        Adc_PopFromQueue, Adc_ConfigureGroupForConversion
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PRIVATE_CODE) Adc_ChannelCompleteMode(Adc_GroupType LddGroup,
                                                    Adc_HwUnitType LddHwUnit)
{
  P2CONST(Tdd_Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2CONST(uint8, AUTOMATIC,ADC_CONFIG_DATA) LpChannelToGroup;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                      (ADC_ENABLE_QUEUING == STD_ON)) || \
              (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
  P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC,ADC_CONFIG_DATA)
                                                        LpAdcUserRegisters;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                      (ADC_ENABLE_QUEUING == STD_ON)) || \
              (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */
  P2VAR(Tdd_Adc_ChannelGroupRamData, AUTOMATIC,ADC_CONFIG_DATA) LpGroupData;
  P2VAR(Tdd_Adc_RunTimeData, AUTOMATIC,ADC_CONFIG_DATA) LpRunTimeData;
  P2VAR(uint32, AUTOMATIC,ADC_CONFIG_DATA) LpResultRegister;
  Adc_ChannelType LddChannel;
  /*  MISRA Rule         : 18.4                                           */
  /*  Message            : Unions shall not be used.                      */
  /*  Reason             : To access the converted values                 */
  /*  Verification       : However, part of the code is verified manually */
  /*                       and it is not having any impact.               */
  UInt LusConvertedValue;
  uint8 LucHwCGUnit;
  boolean LblPopGroupFrmQueue = ADC_FALSE;

  /* Read the hardware unit of the group */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* Get the base address of the first channel configured for the
     requested group */
  LpChannelToGroup = LpGroup->pChannelToGroup;

  /* Get the CGm unit to which the channel group is mapped */
  LucHwCGUnit = LpGroup->ucHwCGUnit;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                      (ADC_ENABLE_QUEUING == STD_ON)) || \
              (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
  /* Read the base address of the hardware unit */
  LpAdcUserRegisters = Adc_GpHwUnitConfig[LddHwUnit].pUserBaseAddress;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                      (ADC_ENABLE_QUEUING == STD_ON)) || \
              (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */

  /* Read the group's runtime data pointer */
  LpRunTimeData =
   &Adc_GpRunTimeData[(LddHwUnit * ADC_NUMBER_OF_CG_UNITS) + LucHwCGUnit];

  /* Read the group data pointer */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];

  /* Read the base address of ADC Result Register */
  LpResultRegister = Adc_GpHwUnitConfig[LddHwUnit].pAdcResult;

  /* MISRA Rule         : 17.4                                          */
  /* Message            : Array indexing shall be the only allowed      */
  /*                      form of pointer arithmetic                    */
  /* Reason             : To access the channel parameters              */
  /* Verification       : However, part of the code is verified manually*/
  /*                      and it is not having any impact.              */
  /* Read the conversion completed channel number */
  LddChannel = *(LpChannelToGroup + LpRunTimeData->ucChannelsCompleted);

  /* Check if critical section protection is required */
  #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter the critical section protection */
  SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
  #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* MISRA Rule         : 17.4                                          */
  /* Message            : Array indexing shall be the only allowed      */
  /*                      form of pointer arithmetic                    */
  /* Reason             : To access the channel parameters              */
  /* Verification       : However, part of the code is verified manually*/
  /*                      and it is not having any impact.              */
  /* Read the channel's converted value */
  LusConvertedValue.Value = *(LpResultRegister + LddChannel);

  /* Check if critical section protection is required */
  #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit the critical section protection */
  SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
  #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Load the buffer with 12-bit or 10-bit resolution value */
  *(LpRunTimeData->pBuffer) = LusConvertedValue.UChar.LoByte;

  /* Update the number of channels that completed conversion */
  LpRunTimeData->ucChannelsCompleted++;
  /* Increment buffer pointer for the next channel */
  (LpRunTimeData->pBuffer) += LpRunTimeData->ucStreamingSamples;
  /*  MISRA Rule         : 17.4                                          */
  /*  Message            : Array indexing shall be the only allowed      */
  /*                       form of pointer arithmetic                    */
  /*  Reason             : For optimisation.                             */
  /*  Verification       : However, part of the code is verified manually*/
  /*                       and it is not having any impact.              */
  (LpRunTimeData->pChannel)++;

  /* Check if the result access mode is streaming */
  if(LpGroup->ddGroupAccessMode == ADC_ACCESS_MODE_STREAMING)
  {
    /* Check if the conversion of all the channels in the group is completed */
    if(LpRunTimeData->ucChannelsCompleted == LpRunTimeData->ucChannelCount)
    {
      /* Check if the last streaming values were read */
      if(LpGroupData->blResultRead == ADC_TRUE)
      {
        /* Set group status as conversion completed */
        LpGroupData->ddGroupStatus = ADC_COMPLETED;
      }
      /* Update the completed conversion samples */
      LpRunTimeData->ucSamplesCompleted++;
    }
    /* Check if the conversion of all the samples is completed */
    if(LpRunTimeData->ucSamplesCompleted == LpRunTimeData->ucStreamingSamples)
    {
      /* Set group status as conversion completed */
      LpGroupData->ddGroupStatus = ADC_STREAM_COMPLETED;
      /* All the samples are completed */
      LpGroupData->blSampleComp = ADC_TRUE;
      /* Set the flag indicating Adc_ReadGroup or Adc_GetStreamLastPointer
         should be called */
      LpGroupData->blResultRead = ADC_FALSE;
    }
  }

  /* Check if the conversion of all the channels in the group is completed */
  if(LpRunTimeData->ucChannelsCompleted == LpRunTimeData->ucChannelCount)
  {
    /* Reset the number of conversion completed channel count */
    LpRunTimeData->ucChannelsCompleted = ADC_ZERO;

    /* Check if the result access mode is Single */
    if(LpGroup->ddGroupAccessMode == ADC_ACCESS_MODE_SINGLE)
    {
      /* Update the completed conversion samples */
      LpRunTimeData->ucSamplesCompleted++;
      /* Set group status as conversion completed */
      LpGroupData->ddGroupStatus = ADC_STREAM_COMPLETED;
    }

    /* Reload the first channel address for conversion */
    LpRunTimeData->pChannel = LpGroup->pChannelToGroup;
    /* Reload the the result buffer pointer */
    LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer;
    /* Check if the operation mode is continuous */
    if(LpGroup->ucConversionMode == ADC_CONTINUOUS)
    {
      #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      /* Invoke notification function if enabled */
      if((LpGroupData->ucNotifyStatus == ADC_TRUE) &&
        (Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer != NULL_PTR))
      {
        Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer();
      }
      #endif /* #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
      /* Check if the conversion of all the samples is completed */
      if(LpRunTimeData->ucSamplesCompleted ==
                                        LpRunTimeData->ucStreamingSamples)
      {
        /* Re initialise the completed number of samples to zero */
        LpRunTimeData->ucSamplesCompleted = ADC_ZERO;
      }
    }
    else /* ADC_CONV_MODE_ONESHOT / ADC_STREAM_BUFFER_LINEAR */
    {
     /* Reading of the next channel is not required as the conversion
      * of the group is completed.
      */
      LblPopGroupFrmQueue = ADC_TRUE;

      /* Check if it is linear buffer conversion and all samples are
          not complete */
      if((LpGroup->ddGroupAccessMode == ADC_ACCESS_MODE_STREAMING) &&
                                   (LpGroupData->blSampleComp == ADC_FALSE))
      {
        /* Clear the flag indicating no group should be popped from queue
           since streaming is not complete */
        LblPopGroupFrmQueue = ADC_FALSE;
        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                    (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
        if(LddGroup < Adc_GucMaxSwTriggGroups)
        {
          /* Initiate conversion */
          LpAdcUserRegisters->ucADCAnTRG0[LucHwCGUnit * ADC_FOUR] |=
                                                   ADC_START_CONVERSION;
        }
        #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                    (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */
      }
      #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      /* Invoke notification function if enabled */
      if((LpGroupData->ucNotifyStatus == ADC_TRUE) &&
        (Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer != NULL_PTR))
      {
        Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer();
      }
      #endif /* #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

      /* Is Group Priority Enabled */
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
      #if(ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
      if((LblPopGroupFrmQueue == ADC_TRUE) &&
      (LddGroup < Adc_GucMaxSwTriggGroups) &&
      (Adc_GpHwUnitRamData[LddHwUnit].ucQueueStatus != ADC_QUEUE_EMPTY))
      #else
      if((LblPopGroupFrmQueue == ADC_TRUE) &&
      (Adc_GpHwUnitRamData[LddHwUnit].ucQueueStatus != ADC_QUEUE_EMPTY))
      #endif /* #if(ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */

      {
        /* Fetch the highest priority group from the queue */
        LddGroup = Adc_PopFromQueue(LddHwUnit);
        /* If Group Priority Enabled */
        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
         /* MISRA Rule         : 12.7                                        */
         /* Message            : Bitwise operators shall not be applied to   */
         /*                      operands whose underlying type is signed.   */
         /* Reason             : Though the bitwise operation is performed on*/
         /*                      unsigned data, this warning is generated by */
         /*                      the QAC tool V6.2.1 as an indirect result of*/
         /*                      integral promotion in complex bitwise       */
         /*                      operations.                                 */
         /* Verification       : However, this part of the code is verified  */
         /*                      manually and it is not having any impact.   */
         /* Set the flag indicating the group is popped out of the queue */
        Adc_GucPopFrmQueue |= (ADC_ONE << LddHwUnit);
        #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
           (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
        /* Set the Global variable indicating the HW unit is busy */
        Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
        /* Initiate the group conversion */
        Adc_ConfigureGroupForConversion(LddGroup);
      }
      #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                 (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                   ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON))) */
    }
    if((LblPopGroupFrmQueue == ADC_FALSE) &&
            (LpGroup->ddGroupAccessMode == ADC_ACCESS_MODE_STREAMING))
    {
      /*  MISRA Rule         : 17.4                                          */
      /*  Message            : Array indexing shall be the only allowed      */
      /*                       form of pointer arithmetic                    */
      /*  Reason             : For optimisation.                             */
      /*  Verification       : However, part of the code is verified manually*/
      /*                       and it is not having any impact.              */
      /* Increment the result buffer by number of samples completed */
      LpRunTimeData->pBuffer += LpRunTimeData->ucSamplesCompleted;
    }
  }
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
/*******************************************************************************
** Function Name        : Adc_GroupCompleteMode
**
** Service ID           : NA
**
** Description          : This function is invoked from ADC ISR for servicing
**                        the groups configured in scan operation mode.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup, LddHwUnit
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
**                        Adc_GpGroupConfig, Adc_GpGroupRamData,
**                        Adc_GucMaxSwTriggGroups, Adc_GstChannelGrpFunc,
**                        Adc_GpHwUnitRamData, Adc_GpRunTimeData,
**                        Adc_GpHwUnitConfig, Adc_GucMaxSwTriggGroups
**                        Function(s) invoked:
**                        Adc_PopFromQueue, Adc_ConfigureGroupForConversion
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PRIVATE_CODE) Adc_GroupCompleteMode(Adc_GroupType LddGroup,
                                                   Adc_HwUnitType LddHwUnit)
{
  P2CONST(Tdd_Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  P2CONST(uint8, AUTOMATIC,ADC_CONFIG_DATA) LpChannelToGroup;
  P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC,ADC_CONFIG_DATA)
                                                       LpAdcUserRegisters;
  P2VAR(Tdd_Adc_ChannelGroupRamData, AUTOMATIC,ADC_CONFIG_DATA) LpGroupData;
  P2VAR(Tdd_Adc_RunTimeData, AUTOMATIC,ADC_CONFIG_DATA) LpRunTimeData;
  P2VAR(uint32, AUTOMATIC,ADC_CONFIG_DATA) LpResultRegister;
  P2VAR(uint16, AUTOMATIC,ADC_CONFIG_DATA) LpBuffer;
  Adc_ChannelType LddChannel;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
    (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
  uint8 LucHwCGUnit;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
    (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */
  uint8 LucChannelCount;
  uint8_least LucLoop;
  /*  MISRA Rule         : 18.4                                           */
  /*  Message            : Unions shall not be used.                      */
  /*  Reason             : To access the converted values                 */
  /*  Verification       : However, part of the code is verified manually */
  /*                       and it is not having any impact.               */
  UInt LusConvertedValue;
  uint8 LucBufferOffset;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON))
  boolean LblPopGroupFrmQueue;
  #endif /*  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON)) */

  /* Read the hardware unit of the group */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* Read the group data pointer */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];

  /* Get the CGm unit to which the channel group is mapped */
  LucHwCGUnit = LpGroup->ucHwCGUnit;

  /* Read the group's runtime data pointer */
  LpRunTimeData =
   &Adc_GpRunTimeData[(LddHwUnit * ADC_NUMBER_OF_CG_UNITS) + LucHwCGUnit];

  /* Read the base address of ADC Result Register */
  LpResultRegister = Adc_GpHwUnitConfig[LddHwUnit].pAdcResult;

 /* Get the base address of the first channel configured for the
    requested group */
  LpChannelToGroup = LpGroup->pChannelToGroup;

  /* Load the current group's first channel buffer pointer */
  LpBuffer = LpRunTimeData->pBuffer;

  /* Load number of channels configured for group */
  LucChannelCount = LpRunTimeData->ucChannelCount;
  for(LucLoop = ADC_ZERO; LucLoop < LucChannelCount; LucLoop++)
  {
    /*  MISRA Rule         : 17.4                                          */
    /*  Message            : Array indexing shall be the only allowed      */
    /*                       form of pointer arithmetic                    */
    /*  Reason             : To access the channel parameters              */
    /*  Verification       : However, part of the code is verified manually*/
    /*                       and it is not having any impact.              */
    /* Read the conversion completed channel number */
    LddChannel = *(LpChannelToGroup + LucLoop);
    /* Read the channel's converted value */
    LusConvertedValue.Value = *(LpResultRegister + LddChannel);

    /* Read the offset of the buffer for normal mode */
    LucBufferOffset = (uint8)LucLoop;

    /* Check if the group is configured in streaming access mode */
    if(LpGroup->ddGroupAccessMode == ADC_ACCESS_MODE_STREAMING)
    {
      /* Read the offset for the buffer pointer based on
      ** number of channels and completed samples.
      */
      LucBufferOffset *= LpRunTimeData->ucStreamingSamples;
    }

    /* Check if critical section protection is required */
    #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter the critical section protection */
    SchM_Enter_Adc(ADC_RAMDATA_PROTECTION);
    #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Copy the converted value to the internal buffer */
    LpBuffer[LucBufferOffset] = LusConvertedValue.UChar.LoByte;

    /* Check if critical section protection is required */
    #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit the critical section protection */
    SchM_Exit_Adc(ADC_RAMDATA_PROTECTION);
    #endif /* #if(ADC_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }

  /* Read the base address of the hardware unit */
  LpAdcUserRegisters = Adc_GpHwUnitConfig[LddHwUnit].pUserBaseAddress;

  /* Update the completed conversion samples */
  LpRunTimeData->ucSamplesCompleted++;
  /* Check if the result access mode is Single */
  if(LpGroup->ddGroupAccessMode == ADC_ACCESS_MODE_SINGLE)
  {
    /* Set group status as conversion completed */
    LpGroupData->ddGroupStatus = ADC_STREAM_COMPLETED;

    #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* Invoke notification function if enabled */
    if((LpGroupData->ucNotifyStatus == ADC_TRUE) &&
      (Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer != NULL_PTR))
    {
      Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer();
    }
    #endif /* #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

    /* Check if the conversion mode is continuous */
    if(LpGroup->ucConversionMode == ADC_CONTINUOUS)
    {
      /* Clear the number of samples completed */
      LpRunTimeData->ucSamplesCompleted = ADC_ZERO;
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON))
      LblPopGroupFrmQueue = ADC_FALSE;
      #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON)) */
    }
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON))
    else /* ADC_CONV_MODE_ONESHOT */
    {
      LblPopGroupFrmQueue = ADC_TRUE;
    }
    #endif/* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON)) */
  }
  else /* ADC_ACCESS_MODE_STREAMING */
  {
    /*  MISRA Rule         : 17.4                                          */
    /*  Message            : Array indexing shall be the only allowed      */
    /*                       form of pointer arithmetic                    */
    /*  Reason             : For optimisation.                             */
    /*  Verification       : However, part of the code is verified manually*/
    /*                       and it is not having any impact.              */
    /* Update the buffer pointer to point to the next sample */
    (LpRunTimeData->pBuffer)++;
    /* Check if the conversion of all the samples are completed */
    if(LpRunTimeData->ucSamplesCompleted == LpRunTimeData->ucStreamingSamples)
    {
      /* Set group status as conversion completed */
      LpGroupData->ddGroupStatus = ADC_STREAM_COMPLETED;
      /* Set the flag indicating Adc_ReadGroup or Adc_GetStreamLastPointer
         should be called */
      LpGroupData->blResultRead = ADC_FALSE;

      #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      /* Invoke notification function if enabled */
      if((LpGroupData->ucNotifyStatus == ADC_TRUE) &&
        (Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer != NULL_PTR))
      {
        Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer();
      }
      #endif /* #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
      /* Check if the conversion mode is circular buffer */
      if(LpGroup->ucConversionMode == ADC_CONTINUOUS)
      {
        /* Update the number of channels that completed conversion */
        LpRunTimeData->ucSamplesCompleted = ADC_ZERO;
        LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer;
        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON))
        LblPopGroupFrmQueue = ADC_FALSE;
        #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON)) */
      }
      else /* ADC_STREAM_BUFFER_LINEAR */
      {
        /* Check if the group is configured for hardware trigger */
        if(LddGroup >= Adc_GucMaxSwTriggGroups)
        {
          /* Reset number of samples completed */
          LpRunTimeData->ucSamplesCompleted = ADC_ZERO;
          /* Reset the buffer pointer */
          LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer;
        }
        #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON))
        LblPopGroupFrmQueue = ADC_TRUE;
        #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON)) */
      }
    }
    else /* All samples not completed */
    {
      /* Check if the last streaming values were read */
      if(LpGroupData->blResultRead == ADC_TRUE)
      {
        /* Set group status as conversion completed */
        LpGroupData->ddGroupStatus = ADC_COMPLETED;
      }
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON))
      /* Conversion of the group is not completed */
      LblPopGroupFrmQueue = ADC_FALSE;
      #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                                              (ADC_ENABLE_QUEUING == STD_ON)) */
      #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
            ((ADC_ENABLE_QUEUING == STD_ON) && \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))|| \
        (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
      /* Check if the conversion mode is linear buffer */
      if((LpGroup->ucConversionMode == ADC_ONCE) &&
                                     (LddGroup < Adc_GucMaxSwTriggGroups))
      {
        /* Initiate conversion */
        LpAdcUserRegisters->ucADCAnTRG0[LucHwCGUnit * ADC_FOUR] |=
                                                    ADC_START_CONVERSION;
      }
      #endif/* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
            ((ADC_ENABLE_QUEUING == STD_ON) && \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))|| \
        (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */
      #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      /* Invoke notification function if enabled */
      if((LpGroupData->ucNotifyStatus == ADC_TRUE) &&
        (Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer != NULL_PTR))
      {
        Adc_GstChannelGrpFunc[LddGroup].pGroupNotificationPointer();
      }
      #endif /* #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    }
  }

  /* If Group Priority Enabled or the first come first serve mechanism is
     enabled */
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
  /* Check if the completed group conversion mode is oneshot */
  if(LblPopGroupFrmQueue == ADC_TRUE)
  {
    /* Check if the queue is not empty */
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
      /* Fetch the highest priority group from the queue and
      ** initiate the group conversion
      */
      /* Set the Global variable indicating the HW unit is busy */
      Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
      Adc_ConfigureGroupForConversion(Adc_PopFromQueue(LddHwUnit));
    }
  }
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON))) */
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                      (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */

/*******************************************************************************
** Function Name        : Adc_ConfigureGroupForConversion
**
** Service ID           : NA
**
** Description          : This function configures the requested group for
**                        conversion.
**
** Sync/Async           : Asynchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
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
**                        Adc_GpGroupConfig, Adc_GpHwUnitConfig,
**                        Adc_GucMaxSwTriggGroups, Adc_GpHwUnitRamData,
**                        Adc_GpRunTimeData, Adc_GpGroupRamData
**                        Function(s) invoked:
**                        None
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PRIVATE_CODE) Adc_ConfigureGroupForConversion(
                                                 Adc_GroupType LddGroup)
{
  P2CONST(Tdd_Adc_GroupConfigType, AUTOMATIC, ADC_CONFIG_CONST) LpGroup;
  #if(ADC_DMA_MODE_ENABLE == STD_ON)
  P2CONST(Tdd_Adc_DmaUnitConfig, AUTOMATIC, ADC_CONFIG_DATA) LpCGmDmaConfig;
  P2VAR(Tdd_Adc_DmaAddrRegs, AUTOMATIC, ADC_CONFIG_DATA) LpDmaRegisters;
  #endif /* #if(ADC_DMA_MODE_ENABLE == STD_ON) */
  P2VAR(Tdd_Adc_HwUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpHwUnitData;
  P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC, ADC_CONFIG_DATA)
                                                       LpAdcUserRegisters;
  P2VAR(Tdd_AdcConfigOsRegisters, AUTOMATIC, ADC_CONFIG_DATA)
                                                         LpAdcOsRegisters;
  P2VAR(Tdd_Adc_ChannelGroupRamData, AUTOMATIC, ADC_CONFIG_DATA) LpGroupData;
  P2VAR(Tdd_Adc_RunTimeData, AUTOMATIC,ADC_CONFIG_DATA) LpRunTimeData;
  /* Defining a pointer to the IMR structure */
  P2CONST(Tdd_AdcImrAddMaskConfigType, AUTOMATIC, ADC_CONFIG_DATA)
                                                             LpAdcImrAddMask;
  P2VAR(uint16, AUTOMATIC, ADC_CONFIG_DATA) LpIntpCntrlReg;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* Defining a pointer to the Interrupt Control Register */
  P2VAR(uint8, AUTOMATIC, ADC_CONFIG_DATA) LpDmaIntpCntrlReg;
  #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */
  Adc_HwUnitType LddHwUnit;
  uint8 LucHwCGUnit;

  /* Read the hardware unit of the group */
  LpGroup = &Adc_GpGroupConfig[LddGroup];
  /* Get the CGm unit to which the channel group is mapped */
  LucHwCGUnit = LpGroup->ucHwCGUnit;
  LddHwUnit = LpGroup->ucHwUnit;
  /* Initialise HW RAM data to a local pointer */
  LpHwUnitData = &Adc_GpHwUnitRamData[LddHwUnit];
  /* Initialise Group RAM data to a local pointer */
  LpGroupData = &Adc_GpGroupRamData[LddGroup];

  /* Read the group data pointer */
  LpRunTimeData =
   &Adc_GpRunTimeData[(LddHwUnit * ADC_NUMBER_OF_CG_UNITS) + LucHwCGUnit];
  /* Initialise the number of channels present in the group */
  LpRunTimeData->ucChannelCount = LpGroup->ucChannelCount;
  /* Read the number of samples configured for that group */
  LpRunTimeData->ucStreamingSamples = LpGroup->ddNumberofSamples;
  /* Initialise the channel pointer */
  LpRunTimeData->pChannel = LpGroup->pChannelToGroup;

  /* Initialise the number of converted channels to zero */
  LpRunTimeData->ucChannelsCompleted = ADC_ZERO;
  /* Check if Group Priority is enabled */
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
  if((Adc_GucPopFrmQueue & (ADC_ONE << LddHwUnit)) != ADC_ZERO)
  {
    /* Initialise the number of conversion rounds completed before getting
       aborted or suspended */
    LpRunTimeData->ucSamplesCompleted = LpGroupData->ucReSamplesCompleted;
    /* Clear the samples completed RAM variable */
    LpGroupData->ucReSamplesCompleted = ADC_ZERO;
    /*  MISRA Rule         : 17.4                                          */
    /*  Message            : Array indexing shall be the only allowed      */
    /*                       form of pointer arithmetic                    */
    /*  Reason             : To access the channel parameters              */
    /*  Verification       : However, part of the code is verified manually*/
    /*                       and it is not having any impact.              */
    /* Initialise the group's buffer pointer from the channel
       which was suspended or aborted */
    LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer +
                                        LpRunTimeData->ucSamplesCompleted;
    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
    if(LpGroup->ddGroupReplacement == ADC_GROUP_REPL_SUSPEND_RESUME)
    #endif /* #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) */
    {
      /* Initialise the number of converted channels to previously
         stopped channel count value */
      LpRunTimeData->ucChannelsCompleted = LpGroupData->ucReChannelsCompleted;
      /* Clear the channels completed RAM variable */
      LpGroupData->ucReChannelsCompleted = ADC_ZERO;
      /* Initialise the group's buffer pointer from the channel
         which was suspended */
      LpRunTimeData->pBuffer += LpRunTimeData->ucChannelsCompleted;
      /* Initialise the channel pointer */
      LpRunTimeData->pChannel += LpRunTimeData->ucChannelsCompleted;
    }
  }
  else
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                   (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
  {
    /* Initialise the streaming samples counter */
    LpRunTimeData->ucSamplesCompleted = ADC_ZERO;
    /* Initialise the group's buffer pointer */
    LpRunTimeData->pBuffer = LpGroupData->pChannelBuffer;
    /* Set the flag indicating all the samples are not completed */
    LpGroupData->blSampleComp = ADC_FALSE;
    /* Set the flag indicating Group is not read so far */
    LpGroupData->blResultRead = ADC_TRUE;
  }
  #if ((ADC_HW_TRIGGER_API == STD_ON) && \
                     (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW))
  /* Update the type of group which is in conversion */
  if(LddGroup >= Adc_GucMaxSwTriggGroups)
  {
    /* Set the RAM variable indicating current group active in HW unit is HW */
    LpHwUnitData->ddTrigSource = ADC_TRIGG_SRC_HW;
  }
  else
  {
    /* Set the RAM variable indicating current group active in HW unit is SW */
    LpHwUnitData->ddTrigSource = ADC_TRIGG_SRC_SW;
  }
  #endif /* #if ((ADC_HW_TRIGGER_API == STD_ON) && \
                     (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)) */
  /* Read the user base configuration address of the hardware unit */
  LpAdcUserRegisters = Adc_GpHwUnitConfig[LddHwUnit].pUserBaseAddress;
  /* Read the os base configuration address of the hardware unit */
  LpAdcOsRegisters = Adc_GpHwUnitConfig[LddHwUnit].pOsBaseAddress;

  #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW)
  if(LpGroup->ddGroupReplacement == ADC_GROUP_REPL_SUSPEND_RESUME)
  {
    /* Initialise the interrupt register with channel list */
    LpAdcUserRegisters->ulADCAnIOCm[LucHwCGUnit] = LpGroup->ulChannelList;
  }
  else
  {
    /* Load the register with zero, so interrupt is generated at the end
       of channel list */
    LpAdcUserRegisters->ulADCAnIOCm[LucHwCGUnit] = ADC_ZERO_LONG;
  }
  #elif (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
  /* Load the register with zero, so interrupt is generated at the end
       of channel list */
  LpAdcUserRegisters->ulADCAnIOCm[LucHwCGUnit] = ADC_ZERO_LONG;
  #else /* If priority is ADC_PRIORITY_HW_SW or ADC_PRIORITY_HW */
  /* Initialise the interrupt register with channel list */
  LpAdcUserRegisters->ulADCAnIOCm[LucHwCGUnit] = LpGroup->ulChannelList;
  #endif /* #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) */

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
            (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
  /* Clear the ADC enable bit ADCAnCE */
  LpAdcOsRegisters->usADCAnCTL0 &= ADC_DISABLE_BIT;
  /* Clear the operation mode configured previously */
  LpAdcOsRegisters->ulADCAnCTL1 &= ADC_OPERATION_CLEAR_MASK;
  /* Configure the hardware unit with the group's operation mode */
  LpAdcOsRegisters->ulADCAnCTL1 |=
                        Adc_GaaOperationMask[LpGroup->ucConversionMode];
  /* Clear Streaming samples selection bits */
  LpAdcOsRegisters->usADCAnCTL0 &= ADC_CG0_STREAM_CLEAR_MASK;
  #if (ADC_HW_TRIGGER_API == STD_ON)
  /* Check if the group access is streaming access and HW triggered group */
  if((LpGroup->ddGroupAccessMode == ADC_ACCESS_MODE_STREAMING) &&
                                     (LddGroup >= Adc_GucMaxSwTriggGroups))
  {
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
    /* Set Streaming samples selection bits */
    LpAdcOsRegisters->usADCAnCTL0 |=
    (Adc_GaaStreamEnableMask[LpGroup->ddNumberofSamples] <<
                                                (LucHwCGUnit * ADC_TWO));
  }
  #endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
            (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
               (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
  LpHwUnitData->ddCurrentPriority[LucHwCGUnit] = LpGroup->ddGroupPriority;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
               (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
  /* Update the hardware unit ram data with the current group information */
  LpHwUnitData->ddCurrentConvGroup[LucHwCGUnit] = LddGroup;

  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  if(LpGroup->ucResultAccessMode == ADC_DMA_ACCESS)
  {
    /* Initialise the register for channels configured */
    LpAdcUserRegisters->ulADCAnIOCm[LucHwCGUnit] = LpGroup->ulChannelList;
    LpCGmDmaConfig = &Adc_GpDmaUnitConfig[LpGroup->ucDmaChannelIndex];
    LpDmaRegisters = LpCGmDmaConfig->pDmaCntlRegBase;
    /* Clear the DTE bit */
    LpDmaRegisters->ucDTSn &= ADC_DMA_DISABLE;
    /* MISRA Rule     : 11.3                                             */
    /* Message        : A cast should not be performed between a         */
    /*                  pointer type and an integral type.               */
    /* Reason         : This is to get the DMA destination address       */
    /* Verification   : However, the part of the code is                 */
    /*                  verified manually and it is not having           */
    /*                  any impact on code.                              */
    /* Load the destination address register */
    LpDmaRegisters->ulDDAn = (uint32)LpRunTimeData->pBuffer;
    /* Load the transfer count value to the DMA register */
    LpDmaRegisters->usDTCn =
       (uint16)(LpGroup->ucChannelCount - LpRunTimeData->ucChannelsCompleted);
    if(LpGroup->ucConversionMode == ADC_CONTINUOUS)
    {
      #if(ADC_CPU_CORE == ADC_E2M)
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
      /* Set NTCV bit to 1 in next count register and load the
      channel count value */
      LpDmaRegisters->usDNTCn =
      (uint16)((LpGroup->ucChannelCount - LpRunTimeData->ucChannelsCompleted) | \
                                                    ADC_DMA_SET_NEXT);
      /* Set the INF bit so that NTCV is retained */
      LpDmaRegisters->usDTCTn |= ADC_DMA_SET_INF;
      #endif /* #if(ADC_CPU_CORE == ADC_E2M) */
      /* Set the MLE bit for continuous data transfer */
      LpDmaRegisters->usDTCTn |= ADC_DMA_CONTINUOUS;
    }
    else
    {
      /* Clear the MLE bit for continuous data transfer */
      LpDmaRegisters->usDTCTn &= ADC_DMA_ONCE;
    }
    /* Enable the DMA interrupt control register */
    LpDmaIntpCntrlReg = LpCGmDmaConfig->pDmaImrIntCntlReg;
    /* Enable the DMA channel interrupt */
    *LpDmaIntpCntrlReg &= LpCGmDmaConfig->ucDmaImrMask;

    /* Disable the interrupt */
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

    /* MISRA Rule     : 11.3                                             */
    /* Message        : A cast should not be performed between a         */
    /*                  pointer type and an integral type.               */
    /* Reason         : This is to access the hardware registers in the  */
    /*                  code.                                            */
    /* Verification   : However, the part of the code is                 */
    /*                  verified manually and it is not having           */
    /*                  any impact on code.                              */
    /* Clear the pending HW interrupt for the DMA channel */
    ADC_DMA_DRQCLR |= LpCGmDmaConfig->usDmaChannelMask;
    
    if((LpDmaRegisters->ucDTSn & ADC_DMA_TRANSFER_COMPLETION) == 
                                    ADC_DMA_TRANSFER_COMPLETION)
    {
      /* Clear the TC bit */
      LpDmaRegisters->ucDTSn &= ADC_DMA_TRANSFER_CLEAR;
    }
    
    /* DMA transfer enable */
    LpDmaRegisters->ucDTSn = ADC_DMA_ENABLE;
  }
  else
  #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */
  {
    #if (ADC_DMA_MODE_ENABLE == STD_ON)
    #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
         (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
    if(LpGroup->ucDmaChannelIndex != ADC_NO_DMA_CHANNEL_INDEX)
    {
      LpCGmDmaConfig = &Adc_GpDmaUnitConfig[LpGroup->ucDmaChannelIndex];
      /* Disable the DMA interrupt for the DMA channel Id configured
         for the CGm unit in which the group is mapped */
      LpDmaIntpCntrlReg = LpCGmDmaConfig->pDmaImrIntCntlReg;
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
      /* Disable the DMA channel interrupt */
      *LpDmaIntpCntrlReg |= ~LpCGmDmaConfig->ucDmaImrMask;
    }
    #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
              (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */
    #endif /* (ADC_DMA_MODE_ENABLE == STD_ON) */
    /* Clear the pending interrupt for the CGm unit to which the
       group is mapped */
    LpIntpCntrlReg = Adc_GpHwUnitConfig[LddHwUnit].pIntpAddress;
    LpIntpCntrlReg = &LpIntpCntrlReg[LucHwCGUnit];
    *LpIntpCntrlReg &= ADC_CLEAR_INT_REQUEST_FLAG;
    /* Enable the interrupt for the CGm unit to which the group is mapped */
    LpAdcImrAddMask = Adc_GpHwUnitConfig[LddHwUnit].pImrAddMask;
    LpAdcImrAddMask = &LpAdcImrAddMask[LucHwCGUnit];
    *(LpAdcImrAddMask->pImrIntpAddress) &= (LpAdcImrAddMask->ucImrMask);
  }
  /* Load the Channels that needs to be converted */
  LpAdcUserRegisters->ulADCAnCGm[LucHwCGUnit] =
    (LpGroup->ulChannelList & \
          (ADC_COMPLETE_CHANNEL_MASK << LpRunTimeData->ucChannelsCompleted));

  /* Check if the priority ADC_PRIORITY_SW or ADC_PRIORITY_HW_SW is selected */
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
  /* Is the group not popped from queue or group status is still idle */
  if(((Adc_GucPopFrmQueue & (ADC_ONE << LddHwUnit)) == ADC_ZERO) || \
  (Adc_GpGroupRamData[LddGroup].ddGroupStatus == ADC_IDLE))
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
               (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
  {
    /* Set the group status as busy */
    LpGroupData->ddGroupStatus = ADC_BUSY;
  }

  /* Enable ADC Driver */
  LpAdcOsRegisters->usADCAnCTL0 |= ADC_ENABLE_BIT;
  /* Check if the requested group is SW triggered */
  if (LddGroup < Adc_GucMaxSwTriggGroups)
  {
    /* Initiate conversion */
    LpAdcUserRegisters->ucADCAnTRG0[LucHwCGUnit * ADC_FOUR] |=
                                                     ADC_START_CONVERSION;
  }
  Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_FALSE;

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                    (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW))
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
  /* Check if the Group is poped from the queue and configured for
     continuous and resume conversion */
  if(((Adc_GucPopFrmQueue & (ADC_ONE << LddHwUnit)) != ADC_ZERO) && \
    (LpGroup->ucConversionMode == ADC_CONTINUOUS) && \
    (LpGroup->ddGroupReplacement == ADC_GROUP_REPL_SUSPEND_RESUME))
  #elif (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  /* Check if the Group is poped from the queue and configured for
     continuous conversion */
  if(((Adc_GucPopFrmQueue & (ADC_ONE << LddHwUnit)) != ADC_ZERO) && \
    (LpGroup->ucConversionMode == ADC_CONTINUOUS))
  #endif
  {
    /* load the channel list configured for the group so that in the next
       iteration all the channels are converted from the beginning */
    LpAdcUserRegisters->ulADCAnCGm[LucHwCGUnit] = LpGroup->ulChannelList;
  }
  /* Reset the flag to false */
  Adc_GucPopFrmQueue &= ~(ADC_ONE << LddHwUnit);
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                    (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)) */
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Adc_StateTransition
**
** Service ID           : NA
**
** Description          : This function does the state transition of the Group
**                        after the call of the API Adc_ReadGroup or
**                        Adc_GetStreamLastPointer.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
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
**                        Adc_GpGroupConfig, Adc_GpGroupRamData,
**                        Adc_GucMaxSwTriggGroups
**                        Function(s) invoked:
**                        Adc_ConfigureGroupForConversion
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PRIVATE_CODE) Adc_StateTransition(Adc_GroupType LddGroup)
{
  P2VAR(Tdd_Adc_ChannelGroupRamData, AUTOMATIC,ADC_CONFIG_DATA) LpGroupData;
  
  volatile Adc_HwUnitType LddHwUnit;
  volatile uint8 LucHwCGUnit;
  
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  /* Check if the group status is stream completed */
  if(LpGroupData->ddGroupStatus == ADC_STREAM_COMPLETED)
  {
    if(Adc_GpGroupConfig[LddGroup].ucConversionMode == ADC_CONTINUOUS)
    {
      LpGroupData->ddGroupStatus = ADC_BUSY;
    }
    else if(Adc_GpGroupConfig[LddGroup].ucConversionMode == ADC_ONCE)
    {
      if(LddGroup >= Adc_GucMaxSwTriggGroups)
      {
        /* Set the Global variable indicating the HW unit is busy */
        Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
        /*
         * Configure the group for conversion for the subsequent hardware
         * or timer trigger, within this function the group status will be
         * changed to ADC_BUSY
         */
        Adc_ConfigureGroupForConversion(LddGroup);
      }
      else
      {
        LpGroupData->ddGroupStatus = ADC_IDLE;
      }
    }
    else
    {
      /* To avoid QAC warning */
    }
  }
  else if(LpGroupData->ddGroupStatus == ADC_COMPLETED)
  {
    LpGroupData->ddGroupStatus = ADC_BUSY;
  }
  else
  {
    /* To avoid QAC warning */
  }
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Function Name        : Adc_EnableHWGroup
**
** Service ID           : NA
**
** Description          : This function enables the ongoing HW triggered group
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
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
**                        Adc_GpGroupConfig, Adc_GpGroupRamData,
**                        Adc_GpHwUnitConfig, Adc_GpHWGroupTrigg,
**                        Adc_GucMaxSwTriggGroups
**                        Function(s) invoked:
**                        Adc_ConfigureGroupForConversion
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PRIVATE_CODE) Adc_EnableHWGroup(Adc_GroupType LddGroup)
{
  volatile Adc_HwUnitType LddHwUnit;
  volatile uint8 LucHwCGUnit;
  
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
  P2VAR(Tdd_AdcConfigOsRegisters, AUTOMATIC,ADC_CONFIG_DATA) LpAdcOsRegisters;
  #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON)
  P2VAR(Tdd_AdcPicRegisters, AUTOMATIC,ADC_CONFIG_DATA) LpAdcPicRegisters;
  #endif /* #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON) */
  Adc_GroupType LddVirGroup;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */

  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))

  /* Get the index to HW trigger details of requested group */
  LddVirGroup = LddGroup - Adc_GucMaxSwTriggGroups;
  /* Get the Hardware Unit to which the group belongs */
  LddHwUnit = Adc_GpGroupConfig[LddGroup].ucHwUnit;

  /* Get the base configuration address of the hardware unit */
  LpAdcOsRegisters = Adc_GpHwUnitConfig[LddHwUnit].pOsBaseAddress;

  #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON)
  /* Get the base configuration address of the hardware unit */
  LpAdcPicRegisters = Adc_GpHwUnitConfig[LddHwUnit].pPicBaseAddress;
  /* load the TAUA0 interrupts configured for this channel group */
  LpAdcPicRegisters->usPIC0ADTEN40n[ADC_ZERO] =
                    Adc_GpHWGroupTrigg[LddVirGroup].usTAUA0TriggerMask;
  /* load the TAUA1 interrupts configured for this channel group */
  LpAdcPicRegisters->usPIC0ADTEN41n[ADC_ZERO] =
                    Adc_GpHWGroupTrigg[LddVirGroup].usTAUA1TriggerMask;
  #endif /* #if (ADC_TO_TIMER_CONNECT_SUPPORT == STD_ON) */

  /* Clear the external trigger bits in ADCAnCTL1 */
  LpAdcOsRegisters->ulADCAnCTL1 &= ADC_CG0_EXTTRIG_CLEAR_MASK;

  /* Configure for HW edge trigger value */
  LpAdcOsRegisters->ulADCAnCTL1 |=
               Adc_GpHWGroupTrigg[LddVirGroup].ulExtTrigEnableMask;
  /* Configure for HW trigger values configured */
  LpAdcOsRegisters->usADCAnTSELm[ADC_ZERO] =
                  Adc_GpHWGroupTrigg[LddVirGroup].usHWTriggerMask;
  #endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
                  (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)) */

  /* Set the Global variable indicating the HW unit is busy */
  Adc_GaaHwUnitStatus[((LddHwUnit * ADC_THREE) + LucHwCGUnit)] = ADC_TRUE;
  /* Configure the group for conversion */
  Adc_ConfigureGroupForConversion(LddGroup);
  /* Set the Trigger status for the group as true */
  Adc_GpGroupRamData[LddGroup].ucHwTriggStatus = ADC_TRUE;
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Function Name        : Adc_DisableHWGroup
**
** Service ID           : NA
**
** Description          : This function disables the ongoing HW triggered group
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup
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
**                        Adc_GpGroupConfig, Adc_GpGroupRamData,
**                        Adc_GpHwUnitConfig
**                        Function(s) invoked:
**                        None
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PRIVATE_CODE) Adc_DisableHWGroup(Adc_GroupType LddGroup)
{
  P2VAR(Tdd_AdcConfigUserRegisters, AUTOMATIC,ADC_CONFIG_DATA)
                                                         LpAdcUserRegisters;
  P2VAR(Tdd_Adc_ChannelGroupRamData, AUTOMATIC,ADC_CONFIG_DATA) LpGroupData;
  P2CONST(Tdd_AdcImrAddMaskConfigType, AUTOMATIC, ADC_CONFIG_DATA)
                                                           LpAdcImrAddMask;
  P2VAR(uint16, AUTOMATIC, ADC_CONFIG_DATA) LpIntpCntrlReg;
  Adc_HwUnitType LddHwUnit;
  uint8 LucHwCGUnit;
  LpGroupData = &Adc_GpGroupRamData[LddGroup];
  /* Read the Hardware Unit to which the group belongs */
  LddHwUnit = Adc_GpGroupConfig[LddGroup].ucHwUnit;

  LpAdcUserRegisters = Adc_GpHwUnitConfig[LddHwUnit].pUserBaseAddress;

  /* Get the CGm unit to which the channel group is mapped */
  LucHwCGUnit = Adc_GpGroupConfig[LddGroup].ucHwCGUnit;
  /* Stop the conversion of the channel group */
  LpAdcUserRegisters->ucADCAnTRG4[LucHwCGUnit * ADC_FOUR] = \
                                                  ADC_STOP_CONVERSION;
  /* Clear the channel list to avoid conversion on next HW trigger */
  LpAdcUserRegisters->ulADCAnCGm[LucHwCGUnit] = ADC_CLEAR_CHANNEL_LIST;
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

  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Store disabled notification into RAM */
  LpGroupData->ucNotifyStatus = ADC_FALSE;
  #endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
  /* Set the Group status to idle */
  LpGroupData->ddGroupStatus = ADC_IDLE;

  /* Set the group enable hardware trigger status to false */
  LpGroupData->ucHwTriggStatus = ADC_FALSE;
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
        (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
             ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                              (ADC_ENABLE_QUEUING == STD_ON)))
/*******************************************************************************
** Function Name        : Adc_SearchnDelete
**
** Service ID           : NA
**
** Description          : This function is called by the Adc_StopGroupConverion
**                        API to search if the requested group is in the queue
**                        and remove it from the queue.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddGroup, LddHwUnit
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
**                        Adc_GpGroupRamData,
**                        Adc_GpHwUnitConfig, Adc_GpHwUnitRamData
**                        Function(s) invoked:
**                        Adc_ConfigureGroupForConversion
*******************************************************************************/

#define ADC_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, ADC_PRIVATE_CODE) Adc_SearchnDelete(Adc_GroupType LddGroup,
                                                     Adc_HwUnitType LddHwUnit)
{
  P2VAR(Tdd_Adc_HwUnitRamData, AUTOMATIC, ADC_CONFIG_DATA) LpHwUnitData;
  P2VAR(Adc_GroupType, AUTOMATIC, ADC_CONFIG_DATA) LpQueue;
  uint8 LucQueueSize;
  uint8_least LucLoopCount;

  /* Initialise the loop count to zero */
  LucLoopCount = ADC_ZERO;
  /* Initialise HW RAM data to a local pointer */
  LpHwUnitData = &Adc_GpHwUnitRamData[LddHwUnit];
  /* Get the base address of the Queue */
  LpQueue = Adc_GpHwUnitConfig[LddHwUnit].pQueue;
  /* Read the configured priority queue size */
  LucQueueSize = LpHwUnitData->ucQueueCounter;

  /* Find the requested group in the queue and re-arrange the
     queue by deleting the requested group */
  while(LucLoopCount < LucQueueSize)
  {
    if(LddGroup == LpQueue[LucLoopCount])
    {
      /* Decrement the queue size by one */
      LucQueueSize--;
      /* Update the queue counter value */
      LpHwUnitData->ucQueueCounter = LucQueueSize;
      /* Re-arrange the queue after deleting the requested group */
      while(LucLoopCount < LucQueueSize)
      {
        LpQueue[LucLoopCount] = LpQueue[LucLoopCount + ADC_ONE];
        LucLoopCount++;
      }
      /* To exit from the while loop */
      LucLoopCount = LucQueueSize;
    }
    LucLoopCount++;
  }
  /* Clear the flag indicating group removed from the queue */
  Adc_GpGroupRamData[LddGroup].ucGrpPresent = ADC_FALSE;
  /* Update the queue status */
  if(LpHwUnitData->ucQueueCounter == ADC_ZERO)
  {
    /* Set queue status as empty */
    LpHwUnitData->ucQueueStatus = ADC_QUEUE_EMPTY;
  }
  else
  {
    /* Set queue status as filled */
    LpHwUnitData->ucQueueStatus = ADC_QUEUE_FILLED;
  }
}

#define ADC_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_SW) || \
             (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                   ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                            (ADC_ENABLE_QUEUING == STD_ON))) */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
