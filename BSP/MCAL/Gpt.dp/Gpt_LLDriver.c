/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Gpt_LLDriver.c                                              */
/* Version      = 3.1.7                                                       */
/* Date         = 23-Oct-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Low level driver function definitions of the of GPT     */
/* Driver                                                                     */
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

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*
 * V3.0.0:  23-Oct-2009  : Initial Version
 * V3.0.1:  05-Nov-2009  : As per SCR 088, I/O structure is updated to have
 *                         separate base address for USER and OS registers.
 * V3.0.2:  09-Nov-2009  : As per SCR 127, In Gpt_Hw_Init and Gpt_Hw_DeInit
 *                         GPT_TOTAL_OSTM_CHANNELS_CONFIG is replaced by
 *                         GPT_TOTAL_OSTM_UNITS_CONFIGURED.
 * V3.0.3:  25-Feb-2010  : As per SCR 194, in functions Gpt_HW_Init and
 *                         Gpt_HW_DeInit assigning value to the "LucSaveCount"
 *                         is made in precompile switch GPT_TAUA_UNIT_USED.
 * V3.0.4:  23-Jun-2010  : As per SCR 281, all the API s are modified to
 *                         support TAUB and TAUC timers.
 * V3.0.5:  08-Jul-2010  : As per SCR 299, following changes are made:
                           1. In function Gpt_HW_DeInit Pre-Compile option for
 *                         TAUB and TAUC are removed for initializing
 *                         Lastcount.
 *                         2. In function Gpt_HW_DeInit Pre-Compile option for
 *                         TAUB and TAUC are added for updating the TAU
 *                         configuration pointer to point to the current TAU.
 * V3.0.6:  28-Jul-2010  : As per SCR 317, following changes are made:
 *                         1. In function Gpt_HW_Init, interrupts are disabled
 *                         and the macro GPT_MODE_CONTINUOUS is replaced by
 *                         GPT_MODE_OSTM_CONTINUOUS.
 *                         2. In functions Gpt_HW_StartTimer and
 *                         Gpt_HW_StopTimer, interrupt enabling and disabling
 *                         are added.
 *                         3. Gpt_HW_EnableWakeup and Gpt_HW_DisableWakeup
 *                         APIs are modified for interrupt enabling/disabling.
 * V3.0.7:  17-Jun-2011  : As per SCR 474, following changes are made:
 *                         1. Access size is updated for registers TAUAnBRS,
 *                         TAUJnBRS, TAUJnTS, TAUJnTT, TAUJnTOE.
 *                         2. OSTMnTO and OSTMnTOE registers are not available
 *                         in some of the Xx4 devices and also these registers
 *                         are not required for any functionality of the GPT
 *                         Driver Module, hence initializing and deinitializing
 *                         of these registers in functions Gpt_HW_Init() and
 *                         Gpt_HW_DeInit() has been removed
 * V3.1.0:  27-Jul-2011  : Modified software version to 3.1.0
 * V3.1.1:  04-Oct-2011  : Added comments for the violation of MISRA rule 19.1.
 * V3.1.2:  11-Jan-2012  : Following changes are made:
 *                         1.In function Gpt_HW_DeInit, OSTM counter disable
 *                         (TE=0) before reset the OSTMn register in Gpt_DeInit,
 *                         hence disable the counter.
 *                         2.TAUABCnCNTm,TAUJnCNTm registers are read only hence
 *                          removed write oparation.
 * V3.1.3:  16-Feb-2012  : Merged the fixes done for Fx4L Gpt driver
 * V3.1.4:  06-Jun-2012  : As per SCR 029, following changes are made:
 *                         1. Environment section is updated to remove compiler
 *                            version.
 *                         2. In Gpt_HW_DeInit writing value to usTAUABCnTOE and
 *                            ucTAUJnTOE registers are corrected.
 * V3.1.5:  11-Jul-2012  : As per SCR 042 TAUABCnTOE and TAUJnTOE registers 
 *                         access is removed from Gpt_HW_DeInit.
 * V3.1.6:  30-Jul-2012  : As per SCR 068 following changes are made:
 *                         1. TAUABCnTOE and TAUJnTOE registers access is 
 *                            removed from Gpt_HW_Init.
 *                         2. "LpTAUJUnitUserReg" and "LpTAUABCUnitUserReg" are 
 *                            removed in Gpt_HW_Init API.
 * V3.1.7:  23-Oct-2012  : As per MNT_0008440, the following changes are made:
 *                         1.As per Mantis #6129 function "Gpt_CbkNotification" 
 *                           is updated.
 *                         2.As per MANTIS #8519 access of registers "ucTAUJnTT,
 *                           ucTAUJnTS and ucTAUJnRDT" are corrected.
 */
/*****************************************************************************/

/******************************************************************************
**                      Include Section                                      **
******************************************************************************/
#include "Gpt.h"
#include "Gpt_Ram.h"
#include "Gpt_LLDriver.h"
#include "Gpt_LTTypes.h"

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM_Cbk.h"
#endif

#if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Gpt.h"
#endif

/******************************************************************************
**                      Version Information                                   *
******************************************************************************/

/* AUTOSAR Specification version information */
#define GPT_LLDRIVER_C_AR_MAJOR_VERSION  GPT_AR_MAJOR_VERSION_VALUE
#define GPT_LLDRIVER_C_AR_MINOR_VERSION  GPT_AR_MINOR_VERSION_VALUE
#define GPT_LLDRIVER_C_AR_PATCH_VERSION  GPT_AR_PATCH_VERSION_VALUE

/* File version information */
#define GPT_LLDRIVER_C_SW_MAJOR_VERSION  3
#define GPT_LLDRIVER_C_SW_MINOR_VERSION  1

/******************************************************************************
**                      Version Check                                        **
******************************************************************************/
#if (GPT_LLDRIVER_AR_MAJOR_VERSION != GPT_LLDRIVER_C_AR_MAJOR_VERSION)
  #error "Gpt_LLDriver.c : Mismatch in Specification Major Version"
#endif

#if (GPT_LLDRIVER_AR_MINOR_VERSION != GPT_LLDRIVER_C_AR_MINOR_VERSION)
  #error "Gpt_LLDriver.c : Mismatch in Specification Minor Version"
#endif

#if (GPT_LLDRIVER_AR_PATCH_VERSION != GPT_LLDRIVER_C_AR_PATCH_VERSION)
  #error "Gpt_LLDriver.c : Mismatch in Specification Patch Version"
#endif

#if (GPT_SW_MAJOR_VERSION != GPT_LLDRIVER_C_SW_MAJOR_VERSION)
  #error "Gpt_LLDriver.c : Mismatch in Major Version"
#endif

#if (GPT_SW_MINOR_VERSION != GPT_LLDRIVER_C_SW_MINOR_VERSION)
  #error "Gpt_LLDriver.c : Mismatch in Minor Version"
#endif

/******************************************************************************
**                         Global Data                                       **
******************************************************************************/

/******************************************************************************
**                      Function Definitions                                 **
******************************************************************************/

/******************************************************************************
** Function Name     : Gpt_HW_Init
**
** Service ID        : NA
**
** Description       : This is GPT Driver component support function.
**                     This function sets the clock prescaler,timer mode.
**                     This function also disables the interrupts and resets
**                     the interrupt request pending flags.
**
** Sync/Async        : Synchronous
**
** Reentrancy        : Reentrant
**
** Input Parameters  : channel
**
** InOut Parameter   : None
**
** Output Parameters : None
**
** Return Value      : None
**
** Pre-condition     : None
**
** Remarks           : Global Variable(s):
**                     Gpt_GpChannelConfig
**
**                     Function(s) invoked:
**                     None
**
******************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
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

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Init(void)
{
  /* Pointer to the channel configuration */
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)
                                                     LpChannelConfig;
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON) \
      || (GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAU Unit configuration */
  P2CONST(Tdd_Gpt_TAUUnitConfigType,AUTOMATIC,GPT_CONFIG_CONST)
                                                     LpTAUUnitConfig;
  #endif

  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))
  
  #if(GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit os control registers */
  P2VAR(Tdd_Gpt_TAUABCUnitOsRegs,AUTOMATIC,GPT_CONFIG_DATA) LpTAUABCUnitOsReg;
  #endif /* GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON */

  #endif /* (GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON)||
            (GPT_TAUC_UNIT_USED == STD_ON) */

  #if(GPT_TAUJ_UNIT_USED == STD_ON)
  
  #if(GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(Tdd_Gpt_TAUJUnitOsRegs,AUTOMATIC,GPT_CONFIG_DATA) LpTAUJUnitOsReg;
  #endif /* GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON */

  #endif /* GPT_TAUJ_UNIT_USED == STD_ON */

  #if((GPT_TAUJ_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))
  uint8 Lastcount;
  #endif

  #if((GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))
  uint8 LucUnitCount;
  #endif

  uint8 LucCount;
  #if((GPT_TAUJ_UNIT_USED == STD_ON)||(GPT_OSTM_UNIT_USED == STD_ON))
  /* Save count from the TAUA channel loop */
  uint8_least LucSaveCount = GPT_ZERO;
  #endif
  /* MISRA Rule         : 17.4                             */
  /* Message            : Increment or decrement operation */
  /*                      performed on pointer.            */
  /* Reason             : Increment operator is used to    */
  /*                      achieve better throughput.       */
  /* Verification       : However, part of the code is     */
  /*                      verified manually and it is not  */
  /*                      having any impact.               */

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Gpt_GpChannelConfig;
  #if((GPT_TAUJ_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))
  Lastcount = GPT_ZERO;
  #endif

  #if((GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))
  LucUnitCount = GPT_ZERO;
  #endif

  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON) \
      || (GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))
  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig = Gpt_GpTAUUnitConfig;
  #endif

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Gpt(GPT_TIMERREG_PROTECTION);
  #endif

  #if(GPT_TAUA_UNIT_USED == STD_ON)
  for(LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUA_UNITS_CONFIG;
                                                       LucCount++)
  {
    #if(GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
    /* Initialize the pointer to os register base address */
    LpTAUABCUnitOsReg = LpTAUUnitConfig->pTAUUnitOsCntlRegs;
    /* Check for Prescaler setting by the GPT module for TAUAn Unit */
    if(GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
    {
       /* Load the configured prescaler value */
       LpTAUABCUnitOsReg->usTAUABCnTPS = LpTAUUnitConfig->usPrescaler;
       /* Load the configured baudrate value */
       LpTAUABCUnitOsReg->ucTAUAnBRS = LpTAUUnitConfig->ucBaudRate;
    }
    else
    {
     /* To Avoid MISRA Warning */
    }
    #endif /* End of (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON) */

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer for the next TAUA Unit */
    LpTAUUnitConfig++;
    #if((GPT_TAUJ_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
        || (GPT_TAUC_UNIT_USED == STD_ON))
    Lastcount++;
    #endif
  }
  #endif /* End of (GPT_TAUA_UNIT_USED == STD_ON) */

  #if((GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))
  /* Increment LucUnitCount to total TAUB and TAUC units configured */
  LucUnitCount = (GPT_TOTAL_TAUB_UNITS_CONFIG + GPT_TOTAL_TAUC_UNITS_CONFIG +
                  Lastcount);
  for(LucCount = Lastcount; LucCount < LucUnitCount; LucCount++)
  {
    #if(GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
    /* Initialize the pointer to os register base address */
    LpTAUABCUnitOsReg = LpTAUUnitConfig->pTAUUnitOsCntlRegs;
    /* Check for Prescaler setting by the GPT module for TAUBn Unit */
    if(GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
    {
       /* Load the configured prescaler value */
       LpTAUABCUnitOsReg->usTAUABCnTPS = LpTAUUnitConfig->usPrescaler;
    }
    else
    {
     /* To Avoid MISRA Warning */
    }
    #endif /* End of (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON) */

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer for the next TAUB/TAUC Unit */
    LpTAUUnitConfig++;
    #if(GPT_TAUJ_UNIT_USED == STD_ON)
    Lastcount++;
    #endif
  }
  #endif /* End of (GPT_TAUB_UNIT_USED == STD_ON)||
          * (GPT_TAUC_UNIT_USED == STD_ON)
          */

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERREG_PROTECTION);
  #endif

  #if(GPT_TAUJ_UNIT_USED == STD_ON)

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Gpt(GPT_TIMERREG_PROTECTION);
  #endif

  for(LucCount = Lastcount; LucCount < GPT_TOTAL_TAU_UNITS_CONFIGURED;
      LucCount++)
  {
    #if(GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON)
    /* Initialize the pointer to os register base address */
    LpTAUJUnitOsReg = LpTAUUnitConfig->pTAUUnitOsCntlRegs;
    /* Check for Prescaler setting by the GPT module for TAUJn Unit */
    if(GPT_TRUE == LpTAUUnitConfig->blConfigurePrescaler)
    {
       /* Load the configured prescaler value */
       LpTAUJUnitOsReg->usTAUJnTPS = LpTAUUnitConfig->usPrescaler;
       /* Load the configured baudrate value */
       LpTAUJUnitOsReg->ucTAUJnBRS = LpTAUUnitConfig->ucBaudRate;
    }
    else
    {
     /* To Avoid MISRA Warning */
    }
    #endif /* End of (GPT_CONFIG_PRESCALER_SUPPORTED == STD_ON) */

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to the next TAUJ Unit */
    LpTAUUnitConfig++;
  }

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERREG_PROTECTION);
  #endif

  #endif /* End of (GPT_TAUJ_UNIT_USED == STD_ON) */

  /* check for TAUA/TAUB/TAUC Units Used */
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Gpt(GPT_TIMERREG_PROTECTION);
  #endif

  for(LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUABC_CHANNELS_CONFIG;
                                                           LucCount++)
  {

    *(LpChannelConfig->pCMORorCTLAddress) =
                              LpChannelConfig->usModeSettingsMask;
    /* Check the Notification is configured for the current channel */
    if(GPT_NO_CBK_CONFIGURED != LpChannelConfig->ucImrMaskValue)
    {
      /* MISRA Rule         : 12.7                                         */
      /* Message            : Bitwise operations on the signed data will   */
      /*                      give implementation defined results          */
      /* Reason             : Though the bitwise operation is performed on */
      /*                      unsigned data, this warning is generated by  */
      /*                      the QAC tool V6.2.1 as an indirect result of */
      /*                      integral promotion in complex bitwise        */
      /*                      operations.                                  */
      /* Verification       : However, this part of the code is verified   */
      /*                      manually and it is not having any impact.    */

      /* Disable the Interrupt processing of the current channel */
      *(LpChannelConfig->pImrIntrCntlAddress) |=
                                            ~(LpChannelConfig->ucImrMaskValue);
      /* Clear the pending interrupt request flag */
      *(LpChannelConfig->pIntrCntlAddress) &= GPT_CLEAR_INT_REQUEST_FLAG;
    }
    else
    {
     /* To Avoid MISRA Warning */
    }
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    /* Set the Notification status as GPT_FALSE */
    Gpt_GpChannelRamData[LucCount].uiNotifyStatus = GPT_FALSE;
    #endif
    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* Assign the Wakeup status to the Channel */
    Gpt_GpChannelRamData[LucCount].uiWakeupStatus = GPT_FALSE;
    #endif
    /* Assign the timer status to the Channel */
    Gpt_GpChannelRamData[LucCount].ucChannelStatus = GPT_CH_NOTRUNNING;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to the next channel */
    LpChannelConfig++;

  }

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERREG_PROTECTION);
  #endif

  #if((GPT_TAUJ_UNIT_USED == STD_ON)||(GPT_OSTM_UNIT_USED == STD_ON))
  LucSaveCount = LucCount;
  #endif

  #endif /* End of (GPT_TAUA_UNIT_USED == STD_ON)|| \
          * (GPT_TAUB_UNIT_USED == STD_ON)|| \
          * (GPT_TAUC_UNIT_USED == STD_ON)
          */

  /* check for TAUJ Units Used */
  #if(GPT_TAUJ_UNIT_USED == STD_ON)
  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Gpt(GPT_TIMERREG_PROTECTION);
  #endif

  for(LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUJ_CHANNELS_CONFIG;
                                                          LucCount++)
  {
    *(LpChannelConfig->pCMORorCTLAddress) =
                                 LpChannelConfig->usModeSettingsMask;
    /* Check the Notification is configured for the current channel */
    if(GPT_NO_CBK_CONFIGURED != LpChannelConfig->ucImrMaskValue)
    {
      /* MISRA Rule         : 12.7                                         */
      /* Message            : Bitwise operations on the signed data will   */
      /*                      give implementation defined results          */
      /* Reason             : Though the bitwise operation is performed on */
      /*                      unsigned data, this warning is generated by  */
      /*                      the QAC tool V6.2.1 as an indirect result of */
      /*                      integral promotion in complex bitwise        */
      /*                      operations.                                  */
      /* Verification       : However, this part of the code is verified   */
      /*                      manually and it is not having any impact.    */

      /* Disable the Interrupt processing of the current channel */
      *(LpChannelConfig->pImrIntrCntlAddress) |=
                                            ~(LpChannelConfig->ucImrMaskValue);
      /* Clear the pending interrupt request flag */
      *(LpChannelConfig->pIntrCntlAddress) &= GPT_CLEAR_INT_REQUEST_FLAG;
  }
    else
    {
        /* To Avoid MISRA Warning */
    }
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    /* Set the Notification status as GPT_FALSE */
    Gpt_GpChannelRamData[LucSaveCount].uiNotifyStatus = GPT_FALSE;
    #endif
    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* Assign the Wakeup status to the Channel */
    Gpt_GpChannelRamData[LucSaveCount].uiWakeupStatus = GPT_FALSE;
    #endif
    /* Assign the timer status to the Channel */
    Gpt_GpChannelRamData[LucSaveCount].ucChannelStatus = GPT_CH_NOTRUNNING;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer for the next TAUJ channel */
    LpChannelConfig++;
    LucSaveCount++;
  }

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERREG_PROTECTION);
  #endif
  #endif /* End of (GPT_TAUJ_UNIT_USED == STD_ON) */

  /* check for OSTM Units Used */
  #if(GPT_OSTM_UNIT_USED == STD_ON)

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Gpt(GPT_TIMERREG_PROTECTION);
  #endif
  for(LucCount = GPT_ZERO; LucCount < GPT_TOTAL_OSTM_UNITS_CONFIGURED;
                                                          LucCount++)
  {

    /* MISRA Rule         : 11.4                             */
    /* Message            : A cast should not be performed   */
    /*                      between a pointer to object type */
    /*                      and a different pointer to object*/
    /*                      type.                            */
    /* Reason             : This is to access the CTL reg    */
    /*                      of type 8 bit.                   */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    *((uint8*)(LpChannelConfig->pCMORorCTLAddress)) = GPT_MODE_OSTM_CONTINUOUS;
    /* Check the Notification is configured for the current channel */
    if(GPT_NO_CBK_CONFIGURED != LpChannelConfig->ucImrMaskValue)
    {
      /* MISRA Rule         : 12.7                                         */
      /* Message            : Bitwise operations on the signed data will   */
      /*                      give implementation defined results          */
      /* Reason             : Though the bitwise operation is performed on */
      /*                      unsigned data, this warning is generated by  */
      /*                      the QAC tool V6.2.1 as an indirect result of */
      /*                      integral promotion in complex bitwise        */
      /*                      operations.                                  */
      /* Verification       : However, this part of the code is verified   */
      /*                      manually and it is not having any impact.    */

      /* Disable the Interrupt processing of the current channel */
      *(LpChannelConfig->pImrIntrCntlAddress) |=
                                            ~(LpChannelConfig->ucImrMaskValue);
      /* Clear the pending interrupt request flag */
      *(LpChannelConfig->pIntrCntlAddress) &= GPT_CLEAR_INT_REQUEST_FLAG;
  }
    else
    {
        /* To Avoid MISRA Warning */
    }
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    /* Set the Notification status as GPT_FALSE */
    Gpt_GpChannelRamData[LucSaveCount].uiNotifyStatus = GPT_FALSE;
    #endif
    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* Assign the Wakeup status to the Channel */
    Gpt_GpChannelRamData[LucSaveCount].uiWakeupStatus = GPT_FALSE;
    #endif
    /* Assign the timer status to the Channel */
    Gpt_GpChannelRamData[LucSaveCount].ucChannelStatus = GPT_CH_NOTRUNNING;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer for the next OSTM channel */
    LpChannelConfig++;
    LucSaveCount++;
  }

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERREG_PROTECTION);
  #endif

  #endif /* End of (GPT_OSTM_UNIT_USED == STD_ON) */
}

#define GPT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

/******************************************************************************
** Function Name     : Gpt_HW_DeInit
**
** Service ID        : NA
**
** Description       : This is GPT Driver component support function.
**                     This function resets all the HW Registers.
**
** Sync/Async        : Synchronous
**
** Reentrancy        : Non Reentrant
**
** Input Parameters  : channel
**
** InOut Parameter   : None
**
** Output Parameters : None
**
** Return Value      : None
**
** Pre-condition     : None
**
** Remarks           : Global Variable(s):
**                     Gpt_GpChannelConfig
**
**                     Function(s) invoked:
**                     None
**
******************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_DeInit (void)
{

  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)
                                                     LpChannelConfig;
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON) \
      || (GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUA/TAUB/TAUC/TAUJ Unit configuration */
  P2CONST(Tdd_Gpt_TAUUnitConfigType,AUTOMATIC,GPT_CONFIG_CONST)
                                                     LpTAUUnitConfig;
  #endif

  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
       || (GPT_TAUC_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit control registers */
  P2VAR(Tdd_Gpt_TAUABCUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA)
                                                      LpTAUABCUnitUserReg;
  /* Pointer used for TAUA/TAUB/TAUC channel control registers */
  P2VAR(Tdd_Gpt_TAUABCChannelUserRegs,AUTOMATIC,GPT_CONFIG_DATA)
                                                      LpTAUABCChannelReg;
  #endif

  #if(GPT_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(Tdd_Gpt_TAUJUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA) LpTAUJUnitUserReg;
  /* Pointer used for TAUJ channel control registers */
  P2VAR(Tdd_Gpt_TAUJChannelUserRegs,AUTOMATIC,GPT_CONFIG_DATA) LpTAUJChannelReg;
  #endif

  #if(GPT_OSTM_UNIT_USED == STD_ON)
  /* Pointer pointing to the OSTM Unit control registers */
  P2VAR(Tdd_Gpt_OSTMUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA) LpOSTMUnitReg;
  #endif

  #if(GPT_TAUJ_UNIT_USED == STD_ON)
  uint8 Lastcount;
  #endif

  uint8 LucCount;

  #if(GPT_TAUJ_UNIT_USED == STD_ON || GPT_OSTM_UNIT_USED == STD_ON )
  /* Save count from the TAUA channel loop */
  uint8_least LucSaveCount = GPT_ZERO;
  #endif

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = Gpt_GpChannelConfig;
  /* Initialize the loop count value */
  LucCount = GPT_ZERO;

  #if(GPT_TAUJ_UNIT_USED == STD_ON)
  Lastcount = GPT_ZERO;
  #endif

  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON))
  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig = Gpt_GpTAUUnitConfig;
  #endif

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Gpt(GPT_TIMERREG_PROTECTION);
  #endif
  /* Check for TAUA/TAUB/TAUC Units Used */
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))
  for(LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUABC_UNITS_CONFIG; LucCount++)
  {
    /* Update pointer for the user base address of the TAUA/TAUB/TAUC unit
     * registers
     */
    LpTAUABCUnitUserReg = LpTAUUnitConfig->pTAUUnitUserCntlRegs;

    /* Set the configured channel bits to disable the count operation */
    LpTAUABCUnitUserReg->usTAUABCnTT  = LpTAUUnitConfig->usTAUChannelMaskValue;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to the next TAUA/TAUB/TAUC unit */
    LpTAUUnitConfig++;
    #if(GPT_TAUJ_UNIT_USED == STD_ON)
    Lastcount++;
    #endif
  }
  #endif /* ((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON)||\
      (GPT_TAUC_UNIT_USED == STD_ON)) */

  /* Check for TAUA/TAUB/TAUC Units Used */
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))
  for(LucCount = GPT_ZERO; LucCount < GPT_TOTAL_TAUABC_CHANNELS_CONFIG;
                                                          LucCount++)
  {
    LpTAUABCChannelReg =
    (P2VAR(Tdd_Gpt_TAUABCChannelUserRegs, AUTOMATIC, GPT_CONFIG_CONST))
                                          LpChannelConfig->pBaseCtlAddress;

    /* Reset the CMORm register of the configured channel */
    *(LpChannelConfig->pCMORorCTLAddress) = GPT_RESET_WORD;

    /* Reset the CDRm register of the configured channel */
    LpTAUABCChannelReg->usTAUABCnCDRm  = GPT_RESET_WORD;

    #if(GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    /* Check the Notification is configured for the current channel */
    if (GPT_NO_CBK_CONFIGURED != LpChannelConfig->ucImrMaskValue)
    {
      /* MISRA Rule         : 12.7                                         */
      /* Message            : Bitwise operations on the signed data will   */
      /*                      give implementation defined results          */
      /* Reason             : Though the bitwise operation is performed on */
      /*                      unsigned data, this warning is generated by  */
      /*                      the QAC tool V6.2.1 as an indirect result of */
      /*                      integral promotion in complex bitwise        */
      /*                      operations.                                  */
      /* Verification       : However, this part of the code is verified   */
      /*                      manually and it is not having any impact.    */

      /* Disable the Interrupt processing of the current channel */
      *(LpChannelConfig->pImrIntrCntlAddress) |=
                                            ~(LpChannelConfig->ucImrMaskValue);
    }
    else
    {
     /* To Avoid MISRA Warning */
    }
    /* Set the Notification status as GPT_FALSE */
    Gpt_GpChannelRamData[LucCount].uiNotifyStatus = GPT_FALSE;
    #endif /* (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */

    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* Assign the Wakeup status to the Channel */
    Gpt_GpChannelRamData[LucCount].uiWakeupStatus = GPT_FALSE;
    #endif
    /* Assign the timer status to the Channel */
    Gpt_GpChannelRamData[LucCount].ucChannelStatus = GPT_CH_NOTRUNNING;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to the next TAUA/TAUB/TAUC channel */
    LpChannelConfig++;
  }
  #endif /* ((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON)||\
      (GPT_TAUC_UNIT_USED == STD_ON)) */

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERREG_PROTECTION);
  #endif

  #if((GPT_TAUJ_UNIT_USED == STD_ON)||(GPT_OSTM_UNIT_USED == STD_ON))
  LucSaveCount = LucCount;
  #endif

  /* Check for TAUJ Units Used */
  #if(GPT_TAUJ_UNIT_USED == STD_ON)

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Gpt(GPT_TIMERREG_PROTECTION);
  #endif

  for(LucCount = Lastcount; LucCount < GPT_TOTAL_TAU_UNITS_CONFIGURED;
                                                           LucCount++)
  {
    /* Update pointer for user base address of the TAUJ unit registers */
    LpTAUJUnitUserReg = LpTAUUnitConfig->pTAUUnitUserCntlRegs;
    /* Set the configured channel bits to disable the count operation */
    LpTAUJUnitUserReg->ucTAUJnTT  &=
                               (uint8)LpTAUUnitConfig->usTAUChannelMaskValue;


    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to next TAUJ unit */
    LpTAUUnitConfig++;
  }

  for(LucCount = GPT_ZERO;LucCount < GPT_TOTAL_TAUJ_CHANNELS_CONFIG;
                                                         LucCount++)
  {
    LpTAUJChannelReg =
   (P2VAR(Tdd_Gpt_TAUJChannelUserRegs, AUTOMATIC, GPT_CONFIG_CONST))
                                          LpChannelConfig->pBaseCtlAddress;
    /* Reset the CMORm register of the configured channel */
    *(LpChannelConfig->pCMORorCTLAddress) = GPT_RESET_WORD;

    /* Reset the CDRm register of the configured channel */
    LpTAUJChannelReg->ulTAUJnCDRm  = GPT_RESET_LONG_WORD;

  #if(GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    /* Check the Notification is configured for the current channel */
    if (GPT_NO_CBK_CONFIGURED != LpChannelConfig->ucImrMaskValue)
    {
     /* MISRA Rule         : 12.7                                         */
     /* Message            : Bitwise operations on the signed data will   */
     /*                      give implementation defined results          */
     /* Reason             : Though the bitwise operation is performed on */
     /*                      unsigned data, this warning is generated by  */
     /*                      the QAC tool V6.2.1 as an indirect result of */
     /*                      integral promotion in complex bitwise        */
     /*                      operations.                                  */
     /* Verification       : However, this part of the code is verified   */
     /*                      manually and it is not having any impact.    */

     /* Disable the Interrupt processing of the current channel */
     *(LpChannelConfig->pImrIntrCntlAddress) |=
                                            ~(LpChannelConfig->ucImrMaskValue);
    }
    else
    {
     /* To Avoid MISRA Warning */
    }
    /* Set the Notification status as GPT_FALSE */
    Gpt_GpChannelRamData[LucSaveCount].uiNotifyStatus = GPT_FALSE;
    #endif /* (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */

    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* Assign the Wakeup status to the Channel */
    Gpt_GpChannelRamData[LucSaveCount].uiWakeupStatus = GPT_FALSE;
    #endif
    /* Assign the timer status to the Channel */
    Gpt_GpChannelRamData[LucSaveCount].ucChannelStatus = GPT_CH_NOTRUNNING;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to the next TAUJ channel */
    LpChannelConfig++;
    LucSaveCount++;
  }
  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERREG_PROTECTION);
  #endif
  #endif /* (GPT_TAUJ_UNIT_USED == STD_ON) */

  /* Check for OSTM Units Used */
  #if(GPT_OSTM_UNIT_USED == STD_ON)

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Gpt(GPT_TIMERREG_PROTECTION);
  #endif
  for(LucCount = GPT_ZERO;LucCount < GPT_TOTAL_OSTM_UNITS_CONFIGURED;
                                                         LucCount++)
  {
    LpOSTMUnitReg =
    (P2VAR(Tdd_Gpt_OSTMUnitUserRegs, AUTOMATIC, GPT_CONFIG_CONST))
                                    LpChannelConfig->pBaseCtlAddress;

    /* Reset the CMP register of the configured channel */
    LpOSTMUnitReg->ulOSTMnCMP  = GPT_RESET_LONG_WORD;


    /* MISRA Rule         : 11.4                              */
    /* Message            : A cast should not be performed    */
    /*                      between a pointer to object type  */
    /*                      and a different pointer to object */
    /*                      type.                             */
    /* Reason             : This is to access the CTL reg     */
    /*                      of type 8 bit.                    */
    /* Verification       : However, part of the code is      */
    /*                      verified manually and it is not   */
    /*                      having any impact.                */

  /* Disable the counter before reset OSTMn register */
   LpOSTMUnitReg->ucOSTMnTT  = GPT_OSTMTTF_STOP_MASK;
    *((uint8*)(LpChannelConfig->pCMORorCTLAddress)) = GPT_RESET_BYTE;

    #if(GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    /* Check the Notification is configured for the current channel */
    if (GPT_NO_CBK_CONFIGURED != LpChannelConfig->ucImrMaskValue)
    {
      /* MISRA Rule         : 12.7                                         */
      /* Message            : Bitwise operations on the signed data will   */
      /*                      give implementation defined results          */
      /* Reason             : Though the bitwise operation is performed on */
      /*                      unsigned data, this warning is generated by  */
      /*                      the QAC tool V6.2.1 as an indirect result of */
      /*                      integral promotion in complex bitwise        */
      /*                      operations.                                  */
      /* Verification       : However, this part of the code is verified   */
      /*                      manually and it is not having any impact.    */

      /* Disable the Interrupt processing of the current channel */
      *(LpChannelConfig->pImrIntrCntlAddress) |=
                                            ~(LpChannelConfig->ucImrMaskValue);
    }
    else
    {
     /* To Avoid MISRA Warning */
    }
    /* Set the Notification status as GPT_FALSE */
    Gpt_GpChannelRamData[LucSaveCount].uiNotifyStatus = GPT_FALSE;
    #endif /* (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */

    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* Assign the Wakeup status to the Channel */
    Gpt_GpChannelRamData[LucSaveCount].uiWakeupStatus = GPT_FALSE;
    #endif
    /* Assign the timer status to the Channel */
    Gpt_GpChannelRamData[LucSaveCount].ucChannelStatus = GPT_CH_NOTRUNNING;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to the next OSTM channel */
    LpChannelConfig++;
    LucSaveCount++;
  }

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERREG_PROTECTION);
  #endif
  #endif /* (GPT_OSTM_UNIT_USED == STD_ON) */
}

#define GPT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

/******************************************************************************
** Function Name     : Gpt_HW_GetTimeElapsed
**
** Service ID        : NA
**
** Description       : This is GPT Driver component support function.
**                     This function returns the time elapsed for a channel by
**                     accessing the respective timer registers.
**
** Sync/Async        : Synchronous
**
** Reentrancy        : Reentrant
**
** Input Parameters  : channel
**
** InOut Parameter   : None
**
** Output Parameters : None
**
** Return Value      : Gpt_ValueType
**
** Pre-condition     : None
**
** Remarks           : Global Variable(s):
**                     Gpt_GpChannelConfig, Gpt_GpChannelRamData
**
**                     Function(s) invoked:
**                     None
**
******************************************************************************/
#if (GPT_TIME_ELAPSED_API == STD_ON)

#define GPT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_GetTimeElapsed
    (Gpt_ChannelType channel)
{
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUA\TAUB\TAUC registers */
  P2VAR(Tdd_Gpt_TAUABCChannelUserRegs,AUTOMATIC,GPT_CONFIG_DATA)
                                                          LpTAUABCChannelRegs;
  #endif

  #if(GPT_TAUJ_UNIT_USED == STD_ON)
   /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Tdd_Gpt_TAUJChannelUserRegs,AUTOMATIC,GPT_CONFIG_DATA)LpTAUJChannelRegs;
  #endif

  #if(GPT_OSTM_UNIT_USED == STD_ON)
   /* Defining a pointer to point to the OSTM registers */
  P2VAR(Tdd_Gpt_OSTMUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA)LpOSTMUnitRegs;
  #endif

   /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Tdd_Gpt_ChannelRamData,AUTOMATIC,GPT_CONFIG_DATA)LpRamData;
  /* Updating the channel config parameter to the current channel */
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)LpChannel;
  /* Return Value */
  Gpt_ValueType LddTimeElapsed;
  uint8 LucTimerType;

  /* Initialize Return Value to zero */
  LddTimeElapsed = GPT_ZERO;
  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[channel];
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->uiTimerType;
  LpRamData = &Gpt_GpChannelRamData[channel];

  switch(LucTimerType)
  {
    case GPT_HW_TAUA:
    case GPT_HW_TAUB:
    case GPT_HW_TAUC:
      #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
          || (GPT_TAUC_UNIT_USED == STD_ON))

      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area  */
      SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
      #endif
      if( GPT_CH_NOTRUNNING == LpRamData->ucChannelStatus)
      {
        LddTimeElapsed = GPT_ZERO;
      }
      else
      {
        LpTAUABCChannelRegs =
        (P2VAR(Tdd_Gpt_TAUABCChannelUserRegs, AUTOMATIC, GPT_CONFIG_DATA))
                            LpChannel->pBaseCtlAddress;
        /* Assign the final return value */
        LddTimeElapsed =
        LpTAUABCChannelRegs->usTAUABCnCDRm \
                                -  LpTAUABCChannelRegs->usTAUABCnCNTm;
      }
      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
      #endif

      #endif
      /* End of
         ((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON)||\
          (GPT_TAUC_UNIT_USED == STD_ON)) */
    break;

    case GPT_HW_TAUJ:
      #if(GPT_TAUJ_UNIT_USED == STD_ON)

      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area  */
      SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
      #endif
      if( GPT_CH_NOTRUNNING == LpRamData->ucChannelStatus)
      {
        LddTimeElapsed = GPT_ZERO;
      }
      else
      {
        LpTAUJChannelRegs =
        (P2VAR(Tdd_Gpt_TAUJChannelUserRegs, AUTOMATIC, GPT_CONFIG_DATA))
                            LpChannel->pBaseCtlAddress;
        /* Assign the final return value */
        LddTimeElapsed =
        LpTAUJChannelRegs->ulTAUJnCDRm - LpTAUJChannelRegs->ulTAUJnCNTm;
      }
      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
      #endif

      #endif/* End of (GPT_TAUJ_UNIT_USED == STD_ON) */
    break;

    case GPT_HW_OSTM:
      #if(GPT_OSTM_UNIT_USED == STD_ON)

      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area  */
      SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
      #endif
      if( GPT_CH_NOTRUNNING == LpRamData->ucChannelStatus)
      {
        LddTimeElapsed = GPT_ZERO;
      }
      else
      {
        LpOSTMUnitRegs = (P2VAR(Tdd_Gpt_OSTMUnitUserRegs, AUTOMATIC,
                          GPT_CONFIG_DATA))
                            LpChannel->pBaseCtlAddress;
        /* Assign the final return value */
        LddTimeElapsed = LpOSTMUnitRegs->ulOSTMnCMP -
                         LpOSTMUnitRegs->ulOSTMnCNT;
      }
      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
      #endif

      #endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
    break;

    default:
    break;
  }
  return (LddTimeElapsed);
}

#define GPT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of (GPT_TIME_ELAPSED_API == STD_ON) */

/******************************************************************************
** Function Name     : Gpt_HW_GetTimeRemaining
**
** Service ID        : NA
**
** Description       : This is GPT Driver component support function.
**                     This function returns the time remaining for
**                     the channel's next timeout by
**                     accessing the respective timer registers.
**
** Sync/Async        : Synchronous
**
** Reentrancy        : Reentrant
**
** Input Parameters  : channel
**
** InOut Parameter   : None
**
** Output Parameters : None
**
** Return Value      : Gpt_ValueType
**
** Pre-condition     : None
**
** Remarks           : Global Variable(s):
**                     Gpt_GpChannelConfig, Gpt_GpChannelRamData
**
**                     Function(s) invoked:
**                     None
**
******************************************************************************/
#if (GPT_TIME_REMAINING_API == STD_ON)

#define GPT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_GetTimeRemaining
(Gpt_ChannelType channel)
{
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUA/TAUB/TAUC registers */
  P2VAR(Tdd_Gpt_TAUABCChannelUserRegs,AUTOMATIC,GPT_CONFIG_DATA)
                                                          LpTAUABCChannelRegs;
  #endif

  #if(GPT_TAUJ_UNIT_USED == STD_ON)
   /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Tdd_Gpt_TAUJChannelUserRegs,AUTOMATIC,GPT_CONFIG_DATA)LpTAUJChannelRegs;
  #endif

  #if(GPT_OSTM_UNIT_USED == STD_ON)
   /* Defining a pointer to point to the OSTM registers */
  P2VAR(Tdd_Gpt_OSTMUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA)LpOSTMUnitRegs;
  #endif

   /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Tdd_Gpt_ChannelRamData,AUTOMATIC,GPT_CONFIG_DATA)LpRamData;
  /* Updating the channel config parameter to the current channel */
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)LpChannel;
  Gpt_ValueType LddTimeRemaining;
  uint8 LucTimerType;

  /* Initialize Return Value to zero */
  LddTimeRemaining = GPT_ZERO;
  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[channel];
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->uiTimerType;
  LpRamData = &Gpt_GpChannelRamData[channel];

  switch(LucTimerType)
  {
    case GPT_HW_TAUA:
    case GPT_HW_TAUB:
    case GPT_HW_TAUC:
      #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
          || (GPT_TAUC_UNIT_USED == STD_ON))

      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
      #endif
      if( GPT_CH_NOTRUNNING == LpRamData->ucChannelStatus)
      {
        LddTimeRemaining = GPT_ZERO;
      }
      else
      {
        LpTAUABCChannelRegs =
        (P2VAR(Tdd_Gpt_TAUABCChannelUserRegs, AUTOMATIC, GPT_CONFIG_DATA))
                          LpChannel->pBaseCtlAddress;

        /* Assign the final return value */
        LddTimeRemaining = LpTAUABCChannelRegs->usTAUABCnCNTm;
      }
      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
      #endif

      #endif
      /* End of
        ((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON)||\
         (GPT_TAUC_UNIT_USED == STD_ON)) */
    break;

    case GPT_HW_TAUJ:
      #if(GPT_TAUJ_UNIT_USED == STD_ON)

      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
      #endif
      if( GPT_CH_NOTRUNNING == LpRamData->ucChannelStatus)
      {
        LddTimeRemaining = GPT_ZERO;
      }
      else
      {
        LpTAUJChannelRegs =
        (P2VAR(Tdd_Gpt_TAUJChannelUserRegs, AUTOMATIC, GPT_CONFIG_DATA))
                            LpChannel->pBaseCtlAddress;

        /* Assign the final return value */
        LddTimeRemaining = LpTAUJChannelRegs->ulTAUJnCNTm;
      }
      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
      #endif

      #endif/* End of (GPT_TAUJ_UNIT_USED == STD_ON) */
    break;

    case GPT_HW_OSTM:
      #if(GPT_OSTM_UNIT_USED == STD_ON)

      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area  */
      SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
      #endif
      if( GPT_CH_NOTRUNNING == LpRamData->ucChannelStatus)
      {
        LddTimeRemaining = GPT_ZERO;
      }
      else
      {
        LpOSTMUnitRegs = (P2VAR(Tdd_Gpt_OSTMUnitUserRegs, AUTOMATIC,
                          GPT_CONFIG_DATA))LpChannel->pBaseCtlAddress;
        /* Assign the final return value */
        LddTimeRemaining = LpOSTMUnitRegs->ulOSTMnCNT;
      }
      #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
      #endif

      #endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
    break;

    default:
    break;
  }
  return (LddTimeRemaining);
}

#define GPT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* (GPT_TIME_REMAINING_API == STD_ON) */

/******************************************************************************
** Function Name     : Gpt_HW_StartTimer
**
** Service ID        : NA
**
** Description       : This is GPT Driver component support function.
**                     This function starts the timer channel by loading the
**                     compare registers and enabling the clock.
**
** Sync/Async        : Synchronous
**
** Reentrancy        : Reentrant
**
** Input Parameters  : channel, value
**
** InOut Parameter   : None
**
** Output Parameters : None
**
** Return Value      : None
**
** Pre-condition     : None
**
** Remarks           : Global Variable(s):
**                     Gpt_GpChannelConfig, Gpt_GpChannelRamData
**
**                     Function(s) invoked:
**                     SchM_Enter_Gpt, SchM_Exit_Gpt
**
******************************************************************************/

#define GPT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_StartTimer
(Gpt_ChannelType channel, Gpt_ValueType value)
{
  /* Updating the channel config parameter to the current channel */
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)LpChannel;

  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUA/TAUB/TAUC registers */
  P2VAR(Tdd_Gpt_TAUABCUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA)
                                                       LpTAUABCUnitUserRegs;
  /* Defining a pointer to point to the channel control registers of
     TAUA/TAUB/TAUC */
  P2VAR(Tdd_Gpt_TAUABCChannelUserRegs,AUTOMATIC,GPT_CONFIG_DATA)
                                                       LpTAUABCChannelRegs;
  #endif

  #if(GPT_TAUJ_UNIT_USED == STD_ON)
   /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Tdd_Gpt_TAUJUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA)LpTAUJUnitUserRegs;
  /* Defining a pointer to point to the channel control registers of TAUA */
  P2VAR(Tdd_Gpt_TAUJChannelUserRegs,AUTOMATIC,GPT_CONFIG_DATA)LpTAUJChannelRegs;
  #endif

  #if(GPT_OSTM_UNIT_USED == STD_ON)
   /* Defining a pointer to point to the OSTM registers */
  P2VAR(Tdd_Gpt_OSTMUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA)LpOSTMUnitRegs;
  #endif
   /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Tdd_Gpt_ChannelRamData,AUTOMATIC,GPT_CONFIG_DATA)LpRamData;

  uint8 LucTimerType;
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
          || (GPT_TAUC_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON))
  /*To hold the Timer CDR register value */
  Gpt_ValueType u32_TAUX_CDR_Value;
  /*Subtract 1 to get the excat CDR counter value*/
  u32_TAUX_CDR_Value = value - 1;
  #endif
  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[channel];
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->uiTimerType;

  LpRamData = &Gpt_GpChannelRamData[channel];

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area  */
  SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
  #endif
  if(GPT_NO_CBK_CONFIGURED != LpChannel->ucImrMaskValue)
  {
    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operations on the signed data will   */
    /*                      give implementation defined results          */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V7.1.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */

    /* Disable the Interrupt processing of the current channel */
    *(LpChannel->pImrIntrCntlAddress) |= ~(LpChannel->ucImrMaskValue);
    /* Clear the pending interrupt request flag */
    *(LpChannel->pIntrCntlAddress) &= GPT_CLEAR_INT_REQUEST_FLAG;
    /* Enable the Interrupt processing of the current channel */
    *(LpChannel->pImrIntrCntlAddress) &= LpChannel->ucImrMaskValue;
  }
  else
  {
     /* To Avoid MISRA Warning */
  }

  switch(LucTimerType)
  {
    case GPT_HW_TAUA:
    case GPT_HW_TAUB:
    case GPT_HW_TAUC:
      #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
          || (GPT_TAUC_UNIT_USED == STD_ON))

      LpTAUABCUnitUserRegs =
      (P2VAR(Tdd_Gpt_TAUABCUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA))
         Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex].pTAUUnitUserCntlRegs;
      LpTAUABCChannelRegs = (P2VAR(Tdd_Gpt_TAUABCChannelUserRegs,
                              AUTOMATIC,GPT_CONFIG_DATA))
           LpChannel->pBaseCtlAddress;
      /* Load the value into the Data register */
      LpTAUABCChannelRegs->usTAUABCnCDRm = (uint16)(u32_TAUX_CDR_Value);

      /* Start the timer TAUA/TAUB/TAUC */
      LpTAUABCUnitUserRegs->usTAUABCnTS = LpChannel->usChannelMask;

      #endif /* End of
          ((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON)||\
           (GPT_TAUC_UNIT_USED == STD_ON)) */
    break;

    case GPT_HW_TAUJ:
      #if(GPT_TAUJ_UNIT_USED == STD_ON)
      LpTAUJUnitUserRegs =
      (P2VAR(Tdd_Gpt_TAUJUnitUserRegs, AUTOMATIC, GPT_CONFIG_DATA))
       Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex].pTAUUnitUserCntlRegs;
      LpTAUJChannelRegs = (P2VAR(Tdd_Gpt_TAUJChannelUserRegs,AUTOMATIC,
                             GPT_CONFIG_DATA))LpChannel->pBaseCtlAddress;
      /* Load the value into the Data register */
      LpTAUJChannelRegs->ulTAUJnCDRm = u32_TAUX_CDR_Value;

      /* Start the timer TAUJ */
      LpTAUJUnitUserRegs->ucTAUJnTS = (uint8)LpChannel->usChannelMask;

      #endif /* End of (GPT_TAUJ_UNIT_USED == STD_ON) */
    break;

    case GPT_HW_OSTM:
      #if(GPT_OSTM_UNIT_USED == STD_ON)
      LpOSTMUnitRegs =
      (P2VAR(Tdd_Gpt_OSTMUnitUserRegs, AUTOMATIC, GPT_CONFIG_DATA))
                          LpChannel->pBaseCtlAddress;
      /* Load the value into the Data register */
      LpOSTMUnitRegs->ulOSTMnCMP = (value - ((uint32)GPT_ONE));
      /* Start the timer OSTM */
      LpOSTMUnitRegs->ucOSTMnTS = GPT_OSTM_START_MASK;

      #endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
    break;

    default:
    break;
  }
  /* Assign the timer status to the Channel */
  LpRamData->ucChannelStatus = GPT_CH_RUNNING;

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
  #endif
}

#define GPT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

/******************************************************************************
** Function Name     : Gpt_HW_StopTimer
**
** Service ID        : NA
**
** Description       : This is GPT Driver component support function.
**                     This function stops the channel
**                     by disabling the interrupt and/or the clock.
**
** Sync/Async        : Synchronous
**
** Reentrancy        : Reentrant
**
** Input Parameters  : channel
**
** InOut Parameter   : None
**
** Output Parameters : None
**
** Return Value      : None
**
** Pre-condition     : None
**
** Remarks           : Global Variable(s):
**                     Gpt_GpChannelConfig, Gpt_GpChannelRamData
**
**                     Function(s) invoked:
**                     SchM_Enter_Gpt, SchM_Exit_Gpt
**
******************************************************************************/

#define GPT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_StopTimer(Gpt_ChannelType channel)
{
  /* Updating the channel config parameter to the current channel */
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)LpChannel;
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the TAUA registers */
  P2VAR(Tdd_Gpt_TAUABCUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA)
                                                  LpTAUABCUnitUserRegs;
  #endif
  #if(GPT_TAUJ_UNIT_USED == STD_ON)
   /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Tdd_Gpt_TAUJUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA)LpTAUJUnitUserRegs;
  #endif
  #if(GPT_OSTM_UNIT_USED == STD_ON)
   /* Defining a pointer to point to the OSTM registers */
  P2VAR(Tdd_Gpt_OSTMUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA)LpOSTMUnitRegs;
  #endif
   /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Tdd_Gpt_ChannelRamData,AUTOMATIC,GPT_CONFIG_DATA)LpRamData;

  uint8 LucTimerType;

  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[channel];
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->uiTimerType;

  /* MISRA Rule         : 17.4                             */
  /* Message            : Increment or decrement operation */
  /*                      performed on pointer.            */
  /* Reason             : Increment operator is used to    */
  /*                      achieve better throughput.       */
  /* Verification       : However, part of the code is     */
  /*                      verified manually and it is not  */
  /*                      having any impact.               */

  LpRamData = Gpt_GpChannelRamData+channel;

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
  #endif
  if(GPT_NO_CBK_CONFIGURED != LpChannel->ucImrMaskValue)
  {
    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operations on the signed data will   */
    /*                      give implementation defined results          */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V6.2.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */

    /* Disable the Interrupt processing of the current channel */
    *(LpChannel->pImrIntrCntlAddress) |=
                                      ~(LpChannel->ucImrMaskValue);
  }
  else
  {
     /* To Avoid MISRA Warning */
  }

  switch(LucTimerType)
  {
    case GPT_HW_TAUA:
    case GPT_HW_TAUB:
    case GPT_HW_TAUC:
      #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
          || (GPT_TAUC_UNIT_USED == STD_ON))
      LpTAUABCUnitUserRegs =
      (P2VAR(Tdd_Gpt_TAUABCUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA))
        Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex].pTAUUnitUserCntlRegs;
      /* Stop the timer TAUA/TAUB/TAUC */
      LpTAUABCUnitUserRegs->usTAUABCnTT = LpChannel->usChannelMask;

      #endif
      /* End of
        ((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON)||\
         (GPT_TAUC_UNIT_USED == STD_ON)) */
    break;

    case GPT_HW_TAUJ:
      #if(GPT_TAUJ_UNIT_USED == STD_ON)
      LpTAUJUnitUserRegs =
      (P2VAR(Tdd_Gpt_TAUJUnitUserRegs, AUTOMATIC, GPT_CONFIG_DATA))
         Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex].pTAUUnitUserCntlRegs;
      /* Stop the timer TAUJ */
      LpTAUJUnitUserRegs->ucTAUJnTT = (uint8)LpChannel->usChannelMask;

      #endif/* End of (GPT_TAUJ_UNIT_USED == STD_ON) */
    break;

    case GPT_HW_OSTM:
      #if(GPT_OSTM_UNIT_USED == STD_ON)
      LpOSTMUnitRegs =
       (P2VAR(Tdd_Gpt_OSTMUnitUserRegs, AUTOMATIC, GPT_CONFIG_DATA))
                            LpChannel->pBaseCtlAddress;
      /* Stop the timer OSTM */
      LpOSTMUnitRegs->ucOSTMnTT = GPT_OSTM_STOP_MASK;

      #endif/* End of (GPT_OSTM_UNIT_USED == STD_ON) */
    break;

    default:
    break;

  }
  /* Assign the timer status to the Channel */
  LpRamData->ucChannelStatus = GPT_CH_NOTRUNNING;

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
  #endif
}

#define GPT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

/******************************************************************************
** Function Name     : Gpt_HW_DisableWakeup
**
** Service ID        : NA
**
** Description       : This is GPT Driver component support function. This
**                     function disables the interrupt for the wakeup channel.
**
** Sync/Async        : Synchronous
**
** Reentrancy        : Reentrant
**
** Input Parameters  : channel
**
** InOut Parameter   : None
**
** Output Parameters : None
**
** Return Value      : None
**
** Pre-condition     : None
**
** Remarks           : Global Variable(s):
**                     Gpt_GpChannelConfig
**
**                     Function(s) invoked:
**                     SchM_Enter_Gpt, SchM_Exit_Gpt
**
******************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) \
  && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

#define GPT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_DisableWakeup(Gpt_ChannelType channel)
{
  /* Updating the channel config parameter to the current channel */
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)LpChannelConfig;

  LpChannelConfig = &Gpt_GpChannelConfig[channel];

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
  #endif
  if((GPT_NO_CBK_CONFIGURED != LpChannelConfig->ucImrMaskValue)&&
     (GPT_MODE_ONESHOT != LpChannelConfig->uiGptChannelMode))
  {
    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operations on the signed data will   */
    /*                      give implementation defined results          */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V6.2.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */

    /* Disabling the Interrupt processing of the current channel */
    *(LpChannelConfig->pImrIntrCntlAddress) |=
                                        ~(LpChannelConfig->ucImrMaskValue);
  }
  else
  {
    /* To avoid QAC warning*/
  }
  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)

  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
  #endif
}

#define GPT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  &&
          (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) */

/******************************************************************************
** Function Name     : Gpt_HW_EnableWakeup
**
** Service ID        : NA
**
** Description       : This is GPT Driver component support function.This
**                     function enables the interrupt for the wakeup channel
**
** Sync/Async        : Synchronous
**
** Reentrancy        : Reentrant
**
** Input Parameters  : channel
**
** InOut Parameter   : None
**
** Output Parameters : None
**
** Return Value      : None
**
** Pre-condition     : None
**
** Remarks           : Global Variable(s):
**                     Gpt_GpChannelConfig
**
**                     Function(s) invoked:
**                     SchM_Enter_Gpt, SchM_Exit_Gpt
**
******************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) \
  && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))

#define GPT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_EnableWakeup(Gpt_ChannelType channel)
{
  /* Updating the channel config parameter to the current channel */
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)LpChannelConfig;

  LpChannelConfig = &Gpt_GpChannelConfig[channel];

  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area  */
  SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
  #endif
  if((GPT_NO_CBK_CONFIGURED != LpChannelConfig->ucImrMaskValue)&&
     (GPT_MODE_ONESHOT != LpChannelConfig->uiGptChannelMode))
  {
    /* MISRA Rule         : 12.7                                         */
    /* Message            : Bitwise operations on the signed data will   */
    /*                      give implementation defined results          */
    /* Reason             : Though the bitwise operation is performed on */
    /*                      unsigned data, this warning is generated by  */
    /*                      the QAC tool V7.1.1 as an indirect result of */
    /*                      integral promotion in complex bitwise        */
    /*                      operations.                                  */
    /* Verification       : However, this part of the code is verified   */
    /*                      manually and it is not having any impact.    */

    /* Disable the Interrupt processing of the current channel */
    *(LpChannelConfig->pImrIntrCntlAddress) |=
                                            ~(LpChannelConfig->ucImrMaskValue);
    /* Clear the pending interrupt request flag */
    *(LpChannelConfig->pIntrCntlAddress) &= GPT_CLEAR_INT_REQUEST_FLAG;
    /* Enable the Interrupt processing of the current channel */
    *(LpChannelConfig->pImrIntrCntlAddress) &= LpChannelConfig->ucImrMaskValue;
  }
  else
  {
    /* To avoid QAC warning*/
  }
  #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
  #endif
}

#define GPT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  &&
          (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) */

/******************************************************************************
** Function Name     : Gpt_CbkNotification
**
** Service ID        : NA
**
** Description       : This routine is used to invoke the callback notification
**                     or wakeup notification based on timer mode.
**
** Sync/Async        : Synchronous
**
** Reentrancy        : Reentrant
**
** Input Parameters  : LucChannelIdx
**
** InOut Parameter   : None
**
** Output Parameters : None
**
** Return Value      : None
**
** Pre-condition     : None
**
** Remarks           : Global Variable(s):
**                     Gpt_GstChannelFunc, Gpt_GpChannelRamData,
**                     Gpt_GpChannelTimerMap, Gpt_GucGptDriverMode
**
**                     Function(s) invoked:
**                     EcuM_CheckWakeup, GptNotification_Channel(Configured
**                     Notification function for the corresponding channel)
**
******************************************************************************/

#define GPT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_CbkNotification(uint8 LucChannelIdx)
{
  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  /* Pointer to Function pointer Table */
  P2CONST(Tdd_Gpt_ChannelFuncType, AUTOMATIC, GPT_APPL_CODE) LpChannelFunc;
  uint8 LucNotificationIdx;
  #endif

  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit control registers */
  P2VAR(Tdd_Gpt_TAUABCUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA)
                                                  LpTAUABCUnitUserRegs;
  #endif

  #if(GPT_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit user control registers */
  P2VAR(Tdd_Gpt_TAUJUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA) LpTAUJUnitUserRegs;
  #endif

  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON))
   /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Tdd_Gpt_ChannelRamData,AUTOMATIC,GPT_CONFIG_DATA)LpRamData;
  uint8 LucTimerType;
  #endif
  /* Updating the channel config parameter to the current channel */
  P2CONST(Tdd_Gpt_ChannelConfigType,AUTOMATIC,GPT_CONFIG_CONST)LpChannel;
  uint8 LucChIdx;


  /* MISRA Rule         : 17.4                             */
  /* Message            : Increment or decrement operation */
  /*                      performed on pointer.            */
  /* Reason             : Increment operator is used to    */
  /*                      achieve better throughput.       */
  /* Verification       : However, part of the code is     */
  /*                      verified manually and it is not  */
  /*                      having any impact.               */

  LucChIdx = *(Gpt_GpChannelTimerMap + LucChannelIdx);

  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LucChIdx];
  #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
      || (GPT_TAUC_UNIT_USED == STD_ON)||(GPT_TAUJ_UNIT_USED == STD_ON))
  /* Updating the Timertype of the current channel */
  LucTimerType = LpChannel->uiTimerType;
  /* Updating the channel ram data to the current channel */
  LpRamData = &Gpt_GpChannelRamData[LucChIdx];

  if(GPT_MODE_ONESHOT == LpChannel->uiGptChannelMode)
  {
    switch(LucTimerType)
    {
      case GPT_HW_TAUA:
      case GPT_HW_TAUB:
      case GPT_HW_TAUC:
        #if((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON) \
            || (GPT_TAUC_UNIT_USED == STD_ON))

        #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
        #endif
        /* Initialize pointer to the base address of the currect timer unit */
        LpTAUABCUnitUserRegs =
        (P2VAR(Tdd_Gpt_TAUABCUnitUserRegs,AUTOMATIC,GPT_CONFIG_DATA))
          Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex].pTAUUnitUserCntlRegs;

        /* Stop the timer TAUA/TAUB/TAUC */
        LpTAUABCUnitUserRegs->usTAUABCnTT = LpChannel->usChannelMask;
        /* Assign the timer status to the Channel */
        LpRamData->ucChannelStatus = GPT_CH_NOTRUNNING;

        #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
        #endif

        #endif
      /* End of
         ((GPT_TAUA_UNIT_USED == STD_ON)||(GPT_TAUB_UNIT_USED == STD_ON)||\
          (GPT_TAUC_UNIT_USED == STD_ON)) */
      break;

      case GPT_HW_TAUJ:
        #if(GPT_TAUJ_UNIT_USED == STD_ON)

        #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area  */
        SchM_Enter_Gpt(GPT_TIMERINT_PROTECTION);
        #endif
        /* Initialize pointer to the base address of the currect timer unit */
        LpTAUJUnitUserRegs =
        (P2VAR(Tdd_Gpt_TAUJUnitUserRegs, AUTOMATIC, GPT_CONFIG_DATA))
         Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex].pTAUUnitUserCntlRegs;

        /* Stop the timer TAUJ */
        LpTAUJUnitUserRegs->ucTAUJnTT = (uint8)LpChannel->usChannelMask;
        /* Assign the timer status to the Channel */
        LpRamData->ucChannelStatus = GPT_CH_NOTRUNNING;

        #if(GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Gpt(GPT_TIMERINT_PROTECTION);
        #endif

        #endif/* End of (GPT_TAUJ_UNIT_USED == STD_ON) */
      break;

      default:
      break;
    }
  }
  else
  {
     /* To Avoid MISRA Warning */
  }
  #endif/* End of ((GPT_TAUA_UNIT_USED == STD_ON)||
         * (GPT_TAUB_UNIT_USED == STD_ON)||(GPT_TAUC_UNIT_USED == STD_ON)
         * (GPT_TAUJ_UNIT_USED == STD_ON))
         */

  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  /* copy the driver status */
  if(GPT_MODE_NORMAL == Gpt_GucGptDriverMode)
  {
     /* Invoke callback notification if notification is enabled */
     if (GPT_TRUE == Gpt_GpChannelRamData[LucChIdx].uiNotifyStatus)
     {
         LucNotificationIdx = LpChannel->ucNotificationConfig;
         LpChannelFunc = &Gpt_GstChannelFunc[LucNotificationIdx];
         /* Invoke the callback function */
         LpChannelFunc->pGptNotificationPointer_Channel();
     } /*
       * End of Gpt_GpChannelRamData[LucChannelIdx].uiNotifyStatus ==
       * GPT_TRUE
       */
     else
    {
     /* To Avoid MISRA Warning */
    }
  }
  else
  #endif/* End of (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */
  {
    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /*
     * If the driver is in Sleep mode and wakeup notification is enabled,
     * invoke ECU Wakeup function
     */
    EcuM_CheckWakeup(((Gpt_GpChannelConfig + LucChIdx)->ddWakeupSourceId));

    /* Set the wakeup status to true */
    Gpt_GpChannelRamData[LucChIdx].uiWakeupStatus = GPT_ONE;
    #endif/* End of (GPT_REPORT_WAKEUP_SOURCE == STD_ON) */
  }
}

#define GPT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

/******************************************************************************
**                          End of File                                      **
******************************************************************************/
