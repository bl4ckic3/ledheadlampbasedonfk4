/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Pwm_LLDriver.c                                              */
/* Version      = 3.1.10                                                      */
/* Date         = 06-Sep-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Low level Driver code of the PWM Driver Component                          */
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
 * V3.0.1:  28-Oct-2009  : As per SCR 054, Pwm_HW_Callback function is added.
 *
 * V3.0.2:  05-Nov-2009  : As per SCR 088, I/O structure is updated to have
 *                         separate base address for USER and OS registers.
 *
 * V3.0.3:  02-Jul-2010  : As per SCR 290, the functions Pwm_HW_Init,
 *                         Pwm_HW_DeInit, Pwm_HW_SetDutyCycle,
 *                         Pwm_HW_SetDuty_FixedPeriodShifted,
 *                         Pwm_HW_SetPeriodAndDuty, Pwm_HW_SetOutputToIdle,
 *                         Pwm_HW_GetOutputState and Pwm_HW_CalculateDuty are
 *                         updated for the implementation of TAUB and TAUC
 *                         timers.
 *
 * V3.0.4:  25-Jul-2010  : As per SCR 305, precompile option PWM_TAUA_UNIT_USED
 *                         is added for the BRS register settings in function
 *                         Pwm_HW_Init
 *
 * V3.0.5:  02-Aug-2010  : As per SCR 329, implementation DLYAEN register is
 *                         made.
 *
 * V3.0.6:  10-Feb-2011  : As per SCR 417, In Pwm_HW_GetOutputState api
 *                         functionality of masking is corrected by using bit
 *                         wise "&" operator.
 *
 * V3.0.7:  29-Apr-2011  : As per SCR 435, In Functions Pwm_HW_Init and
 *                         Pwm_HW_CalculateDuty calculation of Period and Duty
 *                         are modified.
 *
 * V3.0.8:  21-Jun-2011  : As per SCR 478, the functions Pwm_HW_Init,
 *                         Pwm_HW_DeInit, Pwm_HW_SetDutyCycle,
 *                         Pwm_HW_SetDuty_FixedPeriodShifted,
 *                         Pwm_HW_SetPeriodAndDuty, Pwm_HW_SetOutputToIdle and
 *                         Pwm_HW_GetOutputState are
 *                         modified for the implementation of change in size of
 *                         Registers from 16 bit to 8 bit.
 * V3.1.0:  26-Jul-2011  : Ported for the DK4 variant.
 * V3.1.1:  04-Oct-2011  : Added comments for the violation of MISRA rule 19.1.
 * V3.1.2:  12-Jan-2012  : TEL have fixed The Issues reported by  mantis id
 *                       :  #4246,#4210,#4207,#4206,#4202,#4259,#4257,#4248.
 * V3.1.3:  05-Mar-2012  : Merged the fixes done for Fx4L PWM driver
 * V3.1.4:  31-Mar-2012  : Corrected disabling Interrupt processing in function
 *                         Pwm_HW_DeInit
 * V3.1.5:  11-Jun-2012  : As per SCR 034, following changes are made:
 *                         1. Compiler version is removed from Environment
 *                            section.
 *                         2. Check routine of simultaneous rewrite flag is
 *                            added in Pwm_HW_SetDutyCycle,
 *                            Pwm_HW_SetDuty_FixedPeriodShifted and
 *                            Pwm_HW_SetPeriodAndDuty functions.
 *                         3. Inclusion of Dem.h is added.
 *                         4. Functionality of channel stop trigger register
 *                            TAUJnTT is corrected in Pwm_HW_DeInit function.
 *
 *                         As per MANTIS #4820, Pwm_HW_Init is updated:
 *                         1. Setting the SSER register is moved after setting
 *                            TAUA/B/C register.
 *                         As per MANTIS #4818, Pwm_HW_DeInit is updated:
 *                         1. Remove the decision operation for idle level.
 *                         As per MANTIS #4819, Pwm_HW_Init is updated:
 *                         1. Remove the unnecessary setting of pDlyCompRegs.
 *
 * V3.1.6:  12-Jul-2012  : As per SCR 051, following changes are made:
 *                         1. Sequence of Timer Unit setting and PIC0SSER0,
 *                            PIC0SSER2 is correct in Pwm_HW_Init.
 *                         2. Handling of PWM_CRITICAL_SECTION_PROTECTION is
 *                            corrected in Pwm_HW_Init.
 *
 * V3.1.7:  30-Jul-2012  : As per SCR 070, following changes are made:
 *                         1. Pre-compile option for timer units corrected in
 *                            Pwm_HW_Init.
 *                         2. Functionality related to LucSaveCount is
 *                            corrected in Pwm_HW_Init.
 * V3.1.8:  05-Nov-2012  : As per MNT_0007541,
 *                         1.Comment added at each "#endif".
 *                         2.Access of registers "usTAUABnTOC,usTAUABCnTOL,
 *                           usTAUABCnRDE, usTAUABCnTOE,usTAUABCnTS,ucTAUJnRDE,
 *                           ucTAUJnTOE,ucTAUJnTT,ucTAUJnTS and ucTAUJnRDT" are
 *                           modified.
 * V3.1.9:  20-Dec-2012  : As per MNT_0008440, following changes are made:
 *                         1.AS per MANTIS #4905, setting order of delay macro
 *                           is corrected in functions "Pwm_HW_Init" and
 *                           "Pwm_HW_DeInit".
 *                         2.As per MANTIS #8519 access of registers "ucTAUJnTT,
 *                           ucTAUJnTS and ucTAUJnRDT" are corrected.
 *                         3.As per MANTIS #8211 handling of
 *                           PWM_CRITICAL_SECTION_PROTECTION is corrected in
 *                           Pwm_HW_Init.
 *                         4.As per MANTIS #7882 functions "Pwm_HW_SetDutyCycle"
 *                           and "Pwm_HW_SetPeriodAndDuty" are updated.
 *                         5.As per MANTIS #4829 function "Pwm_HW_DeInit" is
 *                           modified.
 * V3.1.10; 06-Sep-2013  : As per MNT_0004821, checking of RSF and report to
 *                         DEM are removed from the APIs Pwm_HW_SetDutyCycle,
 *                         Pwm_HW_SetDuty_FixedPeriodShifted and
 *                         Pwm_HW_SetPeriodAndDuty.
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Pwm.h"
#include "Pwm_Ram.h"
#include "Pwm_LLDriver.h"
#include "Pwm_LTTypes.h"
#include "Dem.h"
#if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Pwm.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification version information */
#define PWM_LLDRIVER_C_AR_MAJOR_VERSION  PWM_AR_MAJOR_VERSION_VALUE
#define PWM_LLDRIVER_C_AR_MINOR_VERSION  PWM_AR_MINOR_VERSION_VALUE
#define PWM_LLDRIVER_C_AR_PATCH_VERSION  PWM_AR_PATCH_VERSION_VALUE

/* File version information */
#define PWM_LLDRIVER_C_SW_MAJOR_VERSION  3
#define PWM_LLDRIVER_C_SW_MINOR_VERSION  1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PWM_LLDRIVER_AR_MAJOR_VERSION != PWM_LLDRIVER_C_AR_MAJOR_VERSION)
  #error "Pwm_LLDriver.c : Mismatch in Specification Major Version"
#endif

#if (PWM_LLDRIVER_AR_MINOR_VERSION != PWM_LLDRIVER_C_AR_MINOR_VERSION)
  #error "Pwm_LLDriver.c : Mismatch in Specification Minor Version"
#endif

#if (PWM_LLDRIVER_AR_PATCH_VERSION != PWM_LLDRIVER_C_AR_PATCH_VERSION)
  #error "Pwm_LLDriver.c : Mismatch in Specification Patch Version"
#endif

#if (PWM_SW_MAJOR_VERSION != PWM_LLDRIVER_C_SW_MAJOR_VERSION)
  #error "Pwm_LLDriver.c : Mismatch in Major Version"
#endif

#if (PWM_SW_MINOR_VERSION != PWM_LLDRIVER_C_SW_MINOR_VERSION)
  #error "Pwm_LLDriver.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Pwm_HW_Init
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function sets the clock prescaler,PWM mode,
**                        Period, Duty cycle and polarity for all configured
**                        channels. This function also disables the interrupts
**                        (Notifications) and resets the interrupt request
**                        pending flags.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : NA
**
** Remarks              : Global Variable(s):
**                        Pwm_GpTAUABCUnitConfig, Pwm_GpTAUJUnitConfig,
**                        Pwm_GpSynchStartConfig,Pwm_GpChannelConfig,
**                        Pwm_GpNotifStatus, Pwm_GpChannelIdleStatus.
**                        Function(s) invoked:
**                        SchM_Enter_Pwm, SchM_Exit_Pwm
*******************************************************************************/
#define PWM_START_SEC_PRIVATE_CODE
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

FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_Init(void)
{
  /* Pointer to the channel configuration */
  P2CONST(Tdd_Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpChannelConfig;
  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit configuration */
  P2CONST(Tdd_Pwm_TAUABCUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpTAUABCUnitConfig;

  /* Pointer pointing to the TAUA/TAUB/TAUC Unit user control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCUnitUserReg;

  /* Pointer pointing to the TAUA/TAUB/TAUC Unit OS control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitOsRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCUnitOsReg;

  /* Pointer used for TAUA/TAUB/TAUC channel control registers */
  P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCChannelReg;

  /* Pointer used for TAUA/TAUB/TAUC Master channel control registers */
  P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCMasterChannelReg;

  /* Pointer to the TAUA/TAUB/TAUC Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCProperties;
  #endif /* #if((PWM_TAUA_UNIT_USED == STD_ON) || \
                (PWM_TAUB_UNIT_USED == STD_ON) || \
                (PWM_TAUC_UNIT_USED == STD_ON)) */

  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Tdd_Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpTAUJUnitConfig;

  /* Pointer pointing to the TAUJ Unit user control registers */
  P2VAR(Tdd_Pwm_TAUJUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJUnitUserReg;

  /* Pointer pointing to the TAUJ Unit os control registers */
  P2VAR(Tdd_Pwm_TAUJUnitOsRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJUnitOsReg;

  /* Pointer used for TAUJ channel control registers */
  P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJChannelReg;

  /* Pointer used for TAUJ Master channel control registers */
  P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJMasterChannelReg;

  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJProperties;
  /* MISRA Msg          : 3:3197                            */
  /* Message            : This initialization is redundant  */
  /*                      The value of 'LucSaveCount' is    */
  /*                      never used before being modified. */
  /* Reason             : This is done to initialise        */
  /*                      variables with specific values    */
  /*                      before they are used.             */
  /* Verification       : However, part of the code is      */
  /*                      verified manually and it is not   */
  /*                      having any impact.                */
  /* Save count from the TAUA/TAUB/TAUC channel loop */
  uint8_least LucSaveCount = PWM_ZERO;
  #endif /* #if(PWM_TAUJ_UNIT_USED == STD_ON) */

  #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
  /* Pointer to the structure for Synchronous start between TAU Units */
  P2CONST(Tdd_PwmTAUSynchStartUseType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpTAUSynchStart;
  uint16 LusSyncMask;
  #endif

  Pwm_PeriodType LddMasterPeriod;
  Pwm_PeriodType LddSlaveDuty;
  uint16 LusChannelOutput;
  /* MISRA Msg          : 3:3197                            */
  /* Message            : This initialization is redundant  */
  /*                      The value of 'LucCount' is    */
  /*                      never used before being modified. */
  /* Reason             : This is done to initialise        */
  /*                      variables with specific values    */
  /*                      before they are used.             */
  /* Verification       : However, part of the code is      */
  /*                      verified manually and it is not   */
  /*                      having any impact.                */
  uint8_least LucCount = PWM_ZERO;
  uint8 LucVar;

  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))
  /* Update the TAUA/TAUB/TAUC config pointer to point to the current TAU */
  LpTAUABCUnitConfig = Pwm_GpTAUABCUnitConfig;
  #endif
  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  /* Update the TAUJ config pointer to point to the current TAUJ */
  LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig;
  #endif
  #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
  /*
   * Update the SynchStart config pointer to point to the current
   * SynchStart
   */
  LpTAUSynchStart =  Pwm_GpSynchStartConfig;
  #endif

  LpChannelConfig = Pwm_GpChannelConfig;

  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
       (PWM_TAUC_UNIT_USED == STD_ON))

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  #if(PWM_DELAY_MACRO_SUPPORT == STD_ON)
  /* Load the Delay Divider value */
  PWM_DELAY_DIVIDER_REG = PWM_DELAY_DIVIDER;

  /* Loop to set the attributes of TAUA/TAUB/TAUC channels */
  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUABC_CHANNELS_CONFIG;
                                                          LucCount++)
  {
    /* MISRA Rule         : 11.5                                      */
    /* Message            : Dangerous pointer cast results in loss of */
    /*                      const qualification.                      */
    /* Reason             : This is to achieve throughput in the      */
    /*                      code.                                     */
    /* Verification       : However, the part of the code is          */
    /*                      verified manually and it is not having    */
    /*                      any impact on code.                       */

    /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
    LpTAUABCProperties =
    (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

    /* Check whether the delay is configured for the particular timer channel */
    if(LpTAUABCProperties->pDlyCompRegs != NULL_PTR)
    {
      /*
       * Load the Delay value in to the Delay compare register
       * of the Delay Macro.
       */
      *(LpTAUABCProperties->pDlyCompRegs) = LpTAUABCProperties->usDelayValue;
    }

    /* Increment the pointer to the next channel */
    LpChannelConfig++;
  }

  LpChannelConfig = Pwm_GpChannelConfig;
  #endif /* End of (PWM_DELAY_MACRO_SUPPORT == STD_ON) */

  /*
   * Loop to set
   * 1. The configured prescaler for the TAUA, TAUB, TAUC units and
   * 2. The bits of Delay control register for the channels that are configured
   * with Delay value for the TAUA, TAUB, TAUC units
   */
  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUABC_UNITS_CONFIG; LucCount++)
  {
    #if(PWM_CONFIG_PRESCALER_SUPPORTED == STD_ON)
    /*
     * Check for Prescaler setting by the PWM module for TAUAn/TAUBn/TAUCn
     * Unit
     */
    if(PWM_TRUE == LpTAUABCUnitConfig->blConfigurePrescaler)
    {
      /* Get the pointer to the TAUA/TAUB/TAUC OS control registers */
      LpTAUABCUnitOsReg = LpTAUABCUnitConfig->pTAUABCUnitOsCntlRegs;
      /* Load the configured prescaler value */
      LpTAUABCUnitOsReg->usTAUABCnTPS = LpTAUABCUnitConfig->usPrescaler;

      #if(PWM_TAUA_UNIT_USED == STD_ON)
      if(PWM_HW_TAUA == LpTAUABCUnitConfig->uiPwmTAUType)
      {
        /* Load the configured baudrate value */
        LpTAUABCUnitOsReg->ucTAUAnBRS = LpTAUABCUnitConfig->ucBaudRate;
      }
      else
      {
      /* For Misra Compliance */
      }
      #endif

    }
    else
    {
     /* For Misra Compliance */
    }
    #endif /* End of (PWM_CONFIG_PRESCALER_SUPPORTED == STD_ON) */
    #if(PWM_DELAY_MACRO_SUPPORT == STD_ON)
    if(NULL_PTR != LpTAUABCUnitConfig->pDelayCntlRegs)
    {
      /*
       * Set the corresponding bits of the Delay control register
       * for the channels configured with Delay value
       */
      *(LpTAUABCUnitConfig->pDelayCntlRegs) |=
                                    LpTAUABCUnitConfig->ulDelayEnableMask;
    }
    else
    {
     /* For Misra Compliance */
    }
    #endif /* End of (PWM_DELAY_MACRO_SUPPORT == STD_ON) */

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to the next TAUA/TAUB/TAUC Unit */
    LpTAUABCUnitConfig++;
  }

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  #endif /* End of ((PWM_TAUA_UNIT_USED == STD_ON) ||
          * (PWM_TAUB_UNIT_USED == STD_ON) || (PWM_TAUC_UNIT_USED == STD_ON))
          */

  #if(PWM_TAUJ_UNIT_USED == STD_ON)

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  #if(PWM_CONFIG_PRESCALER_SUPPORTED == STD_ON)
  /* Loop to set the configured prescaler for the TAUJ units */
  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUJ_UNITS_CONFIG; LucCount++)
  {
    /* Check for Prescaler setting by the PWM module for TAUJn Unit */
    if(PWM_TRUE == LpTAUJUnitConfig->blConfigurePrescaler)
    {
      LpTAUJUnitOsReg = LpTAUJUnitConfig->pTAUJUnitOsCntlRegs;
      /* Load the configured prescaler value */
      LpTAUJUnitOsReg->usTAUJnTPS = LpTAUJUnitConfig->usPrescaler;
      /* Load the configured baudrate value */
      LpTAUJUnitOsReg->ucTAUJnBRS = LpTAUJUnitConfig->ucBaudRate;
    }
    else
    {
     /* For Misra Compliance */
    }
    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to the next TAUJ Unit */
    LpTAUJUnitConfig++;
  }
  #endif /* End of (PWM_CONFIG_PRESCALER_SUPPORTED == STD_ON) */

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  #endif /* End of (PWM_TAUJ_UNIT_USED == STD_ON) */

  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  /* Loop to set the attributes of TAUA/TAUB/TAUC channels */
  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUABC_CHANNELS_CONFIG;
                                                          LucCount++)
  {
    LpTAUABCChannelReg =
    (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_CONST))
                                          LpChannelConfig->pCntlRegs;

    /* MISRA Rule         : 11.5                                      */
    /* Message            : Dangerous pointer cast results in loss of */
    /*                      const qualification.                      */
    /* Reason             : This is to achieve throughput in the      */
    /*                      code.                                     */
    /* Verification       : However, the part of the code is          */
    /*                      verified manually and it is not having    */
    /*                      any impact on code.                       */

    /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
    LpTAUABCProperties =
    (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

    /* Check for channel in the Master Mode */
    if(PWM_MASTER_CHANNEL == LpChannelConfig->uiTimerMode)
    {
      /*
       * Update the CMORm register of Master with the
       * usCMORegSettingsMask based on the configuration
       */
      *LpChannelConfig->pCMORRegs = LpChannelConfig->usCMORegSettingsMask;

      /*
       * Update the CDRm register with default period based on the
       * configuration
       */
      LpTAUABCChannelReg->usTAUABCnCDRm  =
                (uint16)(LpTAUABCProperties->ddDefaultPeriodOrDuty - 1);
    }
    /* Channel in Slave Mode */
    else
    {
      /* Master offset from the slave channel */
      LucVar = LpChannelConfig->ucMasterOffset;

      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Pointer to the Master channel registers */
      LpTAUABCMasterChannelReg =
      (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_CONST))
                                     (LpChannelConfig-LucVar)->pCntlRegs;

      /* Get Master's period */
      LddMasterPeriod = LpTAUABCMasterChannelReg->usTAUABCnCDRm;
      /* Get Slave's Duty */
      LddSlaveDuty = LpTAUABCProperties->ddDefaultPeriodOrDuty;
      /* Get the TAU Type in to the local variable */
      LucVar = LpChannelConfig->uiPwmTAUType;
      /*
       * Update the CMORm register of Slave with the usCMORegSettingsMask
       * based on the configuration
       */
      *LpChannelConfig->pCMORRegs = LpChannelConfig->usCMORegSettingsMask;

      /* Load the Absolute duty value in to the CDR Register */
      LpTAUABCChannelReg->usTAUABCnCDRm = (uint16)
              Pwm_HW_CalculateDuty(LddMasterPeriod, LddSlaveDuty, LucVar);
    }

    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Check the Notification is configured for the current channel */
    if (PWM_NO_CBK_CONFIGURED != LpChannelConfig->ucNotificationConfig)
    {
      /* Clearing the interrupt request flag */
      *(LpChannelConfig->pIntrCntlRegs) &= PWM_CLEAR_INT_REQUEST_FLAG;
      /* Enable the Interrupt processing of the current channel */
      *(LpChannelConfig->pImrIntrCntlRegs) &= LpChannelConfig->ucImrMaskValue;
    }
    else
    {
     /* For Misra Compliance */
    }
    /* Set the Notification status as PWM_FALSE */
    Pwm_GpNotifStatus[LucCount] = PWM_FALSE;
    #endif /* #if (PWM_NOTIFICATION_SUPPORTED == STD_ON) */

    /* Initialise the Idle state status of this channel as PWM_FALSE */
    Pwm_GpChannelIdleStatus[LucCount] = PWM_FALSE;

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
  } /* End of TAUA/TAUB/TAUC Channels 'for' loop */

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  #endif /* End of ((PWM_TAUA_UNIT_USED == STD_ON) ||
                    (PWM_TAUB_UNIT_USED == STD_ON) ||
                    (PWM_TAUC_UNIT_USED == STD_ON)) */
  #if(PWM_TAUJ_UNIT_USED == STD_ON)

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  LucSaveCount = LucCount;

  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUJ_CHANNELS_CONFIG;
                                                          LucCount++)
  {
    LpTAUJChannelReg =
    (P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_CONST))
                                          LpChannelConfig->pCntlRegs;

    /* MISRA Rule         : 11.5                                      */
    /* Message            : Dangerous pointer cast results in loss of */
    /*                      const qualification.                      */
    /* Reason             : This is to achieve throughput in the      */
    /*                      code.                                     */
    /* Verification       : However, the part of the code is          */
    /*                      verified manually and it is not having    */
    /*                      any impact on code.                       */

    LpTAUJProperties =
    (P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

    /* Check for channel in the Master Mode*/
    if(PWM_MASTER_CHANNEL == LpChannelConfig->uiTimerMode)
    {

      /* Update the CMORm register of Master with the
       * usCMORegSettingsMask based on the configuration
       */
      *LpChannelConfig->pCMORRegs = LpChannelConfig->usCMORegSettingsMask;

      /* Update the CDRm register with default period based on the
       * configuration
       */
      LpTAUJChannelReg->ulTAUJnCDRm =
                  (LpTAUJProperties->ddDefaultPeriodOrDuty - 1);
    }
    /* Channel in Slave Mode */
    else
    {
      /* Master offset from the slave channel */
      LucVar = LpChannelConfig->ucMasterOffset;

      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Pointer to the Master channel registers */
      LpTAUJMasterChannelReg =
      (P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_CONST))
                                    (LpChannelConfig-LucVar)->pCntlRegs;

      /* Get Master's period */
      LddMasterPeriod = LpTAUJMasterChannelReg->ulTAUJnCDRm;

      /* Get Slave's Duty */
      LddSlaveDuty = LpTAUJProperties->ddDefaultPeriodOrDuty;

      /* Get the TAU Type in to the local variable */
      LucVar = LpChannelConfig->uiPwmTAUType;

      /*
       * Update the CMORm register of Slave with the usCMORegSettingsMask
       *  based on the configuration
       */
      *LpChannelConfig->pCMORRegs = LpChannelConfig->usCMORegSettingsMask;

      LpTAUJChannelReg->ulTAUJnCDRm =
          Pwm_HW_CalculateDuty(LddMasterPeriod, LddSlaveDuty, LucVar);
    }

    #if(PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Check the Notification is configured for the current channel */
    if (PWM_NO_CBK_CONFIGURED != LpChannelConfig->ucNotificationConfig)
    {
      /* Clearing the interrupt request flag */
      *(LpChannelConfig->pIntrCntlRegs) &= PWM_CLEAR_INT_REQUEST_FLAG;
      /* Enable the Interrupt processing of the current channel */
      *(LpChannelConfig->pImrIntrCntlRegs) &= LpChannelConfig->ucImrMaskValue;
    }
    else
    {
     /* For Misra Compliance */
    }
    /* Set the Notification status as PWM_FALSE */
    Pwm_GpNotifStatus[LucSaveCount] = PWM_FALSE;
    #endif

    /* Initialise the Idle state status of this channel as PWM_FALSE */
    Pwm_GpChannelIdleStatus[LucSaveCount] = PWM_FALSE;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer for the next channel */
    LpChannelConfig++;
    LucSaveCount++;
  }/* End of TAUJ channels for loop */

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif
  #endif /* End of (PWM_TAUJ_UNIT_USED == STD_ON) */

  #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif
  /*
   * Loop to enable synchronous start between TAU units for the channels that
   * are configured for the synchronous start operation
   */
  for(LucCount = PWM_ZERO; LucCount < (uint8_least)
      PWM_TOTAL_UNITS_FOR_SYNCHSTART; LucCount++)
  {
    /*
     * Set the bits of the corresponding channel of the respective
     * Timer Unit as configured for the synchronous start
     */
    *(LpTAUSynchStart->pPICCntlRegs)|= LpTAUSynchStart->usSyncTAUMask;

    /* MISRA Rule         : 17.4                                          */
    /* Message            : Increment or decrement operation performed on */
    /*                      pointer.                                      */
    /* Reason             : Increment operator is used to achieve better  */
    /*                      throughput.                                   */
    /* Verification       : However, part of the code is verified         */
    /*                      manually and it is not having any impact.     */

    /* Increment the pointer to the next Synchronous start Unit */
    LpTAUSynchStart++;
  }
  /* Update the synchronous start pointer */
  LpTAUSynchStart =  Pwm_GpSynchStartConfig;

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  #endif /* End of (PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON) */

  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
  (PWM_TAUC_UNIT_USED == STD_ON))

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  /* Update the TAUA/TAUB/TAUC unit config pointer */
  LpTAUABCUnitConfig = Pwm_GpTAUABCUnitConfig;

  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUABC_UNITS_CONFIG;
                                                         LucCount++)
  {
    /*
     * Update the pointer for the base address of the TAUA/TAUB/TAUC unit
     * registers
     */
    LpTAUABCUnitUserReg = LpTAUABCUnitConfig->pTAUABCUnitUserCntlRegs;
    LpTAUABCUnitOsReg = LpTAUABCUnitConfig->pTAUABCUnitOsCntlRegs;

    /* Set the corresponding bits as per the configured Idle state */
    LusChannelOutput = LpTAUABCUnitUserReg->usTAUABCnTO;
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
    LusChannelOutput &= ~LpTAUABCUnitConfig->usTAUChannelMask;
    LusChannelOutput |= LpTAUABCUnitConfig->usTOMask;
    LpTAUABCUnitUserReg->usTAUABCnTO = LusChannelOutput;

    /* Set the Mode (Synchronous/Independent channel operation mode)*/
    LpTAUABCUnitOsReg->usTAUABCnTOM |= LpTAUABCUnitConfig->usTOMMask;
    #if((PWM_TAUA_UNIT_USED == STD_ON)||(PWM_TAUB_UNIT_USED == STD_ON))
    /* Check whether the current channel not belongs to TUAC */
    if(PWM_HW_TAUC != LpTAUABCUnitConfig->uiPwmTAUType)
    {
      /*
       * set the corresponding bits to specify the TOm (channel output bit)
       * operation mode.
       */
      LpTAUABCUnitOsReg->usTAUABnTOC |= LpTAUABCUnitConfig->usTOCMask;
    }
    else
    {
     /* For Misra Compliance */
    }
    #endif
    /* Set the corresponding bits as per the configured Polarity */
    LpTAUABCUnitUserReg->usTAUABCnTOL |= LpTAUABCUnitConfig->usTOLMask;
    /*
     * Set the corresponding bits to Enable simultaneous rewrite of
     * the data register.
     */
    LpTAUABCUnitOsReg->usTAUABCnRDE |= LpTAUABCUnitConfig->usTAUChannelMask;
    /* Set the corresponding bits to enable/disable TOm operation */
    LpTAUABCUnitUserReg->usTAUABCnTOE |= LpTAUABCUnitConfig->usTOEMask;

    #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
    /* Check TAUA0 channels configured for Synchronous start */
    if(PWM_TAUA0 == LpTAUSynchStart->ucTAUUnitType)
    {
      /*
       * Set the channel bits that are not configured for
       * synchronous start, to enable the count operation
       */
      LpTAUABCUnitUserReg->usTAUABCnTS  =
      (LpTAUABCUnitConfig->usTAUChannelMask ^ LpTAUSynchStart->usSyncTAUMask);
    }
    /* Check TAUA1 channels configured for Synchronous start */
    else if(PWM_TAUA1 == LpTAUSynchStart->ucTAUUnitType)
    {
      /*
       * Set the channel bits that are not configured for
       * synchronous start, to enable the count operation
       */
      LpTAUABCUnitUserReg->usTAUABCnTS  =
      (LpTAUABCUnitConfig->usTAUChannelMask ^ LpTAUSynchStart->usSyncTAUMask);
    }
    else
    {
      /* Set the corresponding channel bit to enable the count operation */
      LpTAUABCUnitUserReg->usTAUABCnTS  = LpTAUABCUnitConfig->usTAUChannelMask;
    }
    /* MISRA Rule           : 13.7                                            */
    /*   Message            : The result of this logical operation is always  */
    /*                        'true'. The value of this control expression is */
    /*                        always 'true'.                                  */
    /*   Reason             : This is used for a counting operation.          */
    /*   Verification       : However, part of the code is verified manually  */
    /*                        and it is not giving any impact                 */
    if(LucCount < PWM_TWO)
    {
      /* MISRA Rule         : 17.4                                          */
      /* Message            : Increment or decrement operation performed on */
      /*                      pointer.                                      */
      /* Reason             : Increment operator is used to achieve better  */
      /*                      throughput.                                   */
      /* Verification       : However, part of the code is verified manually*/
      /*                      and it is not having any impact.              */

      /* Increment the pointer for the next Synchronous start Unit */
      LpTAUSynchStart++;
    }
    else
    {
     /* For Misra Compliance */
    }
    #else
    /* Set the corresponding channel bit to enable the count operation */
    LpTAUABCUnitUserReg->usTAUABCnTS  = LpTAUABCUnitConfig->usTAUChannelMask;
    #endif /* #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON) */
    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer for the next TAUA/TAUB/TAUC Unit */
    LpTAUABCUnitConfig++;
  }/* End of TAUA/TAUB/TAUC Units 'for' loop */
  #if(PWM_DELAY_MACRO_SUPPORT == STD_ON)
  /*
   * Enable the corresponding bit in DLYAEN register based on the number of
   * units enabled for Delay Macro
   */
  PWM_DELAY_ENABLE_REG = PWM_DELAY_ENABLE_VALUE;
  #endif

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif
  #endif /* End of ((PWM_TAUA_UNIT_USED == STD_ON) ||
                    (PWM_TAUB_UNIT_USED == STD_ON) ||
                    (PWM_TAUC_UNIT_USED == STD_ON)) */

  /* Check for TAUJ Units Used */
  #if(PWM_TAUJ_UNIT_USED == STD_ON)

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
  /* Update the synchronous start pointer */
  LpTAUSynchStart =  Pwm_GpSynchStartConfig;
  /* Check for the TAUJ Unit*/
  if(PWM_TAUJ == LpTAUSynchStart->ucTAUUnitType)
  {
    /* Get the synchronous mask value */
    LusSyncMask = LpTAUSynchStart->usSyncTAUMask;
  }
  else
  {
    LucCount = PWM_ZERO;
    do
    {
      /* MISRA Rule         : 17.4                             */
      /* Message            : Increment or decrement operation */
      /*                      performed on pointer.            */
      /* Reason             : Increment operator is used to    */
      /*                      achieve better throughput.       */
      /* Verification       : However, part of the code is     */
      /*                      verified manually and it is not  */
      /*                      having any impact.               */

      /* Increment the pointer to the next synchronous start unit */
      LpTAUSynchStart++;
      LucCount++;
    }while((LpTAUSynchStart->ucTAUUnitType != PWM_TAUJ) &&
           (LucCount< (uint8_least)PWM_TOTAL_UNITS_FOR_SYNCHSTART));

    /* Get the synchronous mask value */
    LusSyncMask = LpTAUSynchStart->usSyncTAUMask;
  }
  #endif /*  #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON) */

  /* Update the TAUJ Unit config pointer to point to the current TAUJ */
  LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig;

  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUJ_UNITS_CONFIG;
                                                       LucCount++)
  {
    /*
     * Update the pointer for the base address of the TAUJ
     * unit registers
     */
    LpTAUJUnitUserReg = LpTAUJUnitConfig->pTAUJUnitUserCntlRegs;
    LpTAUJUnitOsReg = LpTAUJUnitConfig->pTAUJUnitOsCntlRegs;

    /* Set the corresponding bits as per the configured Idle state */
    LusChannelOutput = (uint8)LpTAUJUnitUserReg->ucTAUJnTO;
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
    LusChannelOutput &= ((uint8)(~LpTAUJUnitConfig->usTAUChannelMask));
    LusChannelOutput |= ((uint8)LpTAUJUnitConfig->usTOMask);
    LpTAUJUnitUserReg->ucTAUJnTO = (uint8)LusChannelOutput;

    /* Set the Mode (Synchronous/Independent channel operation mode)*/
    LpTAUJUnitOsReg->ucTAUJnTOM |= ((uint8)LpTAUJUnitConfig->usTOMMask);

    /*
     * set the corresponding bits to specify the TOm (channel output bit)
     * operation mode.
     */
    LpTAUJUnitOsReg->ucTAUJnTOC &=
                         ((uint8)(~LpTAUJUnitConfig->usTAUChannelMask));
    /* Set the corresponding bits as per the configured Polarity */
    LpTAUJUnitUserReg->ucTAUJnTOL |= ((uint8)LpTAUJUnitConfig->usTOLMask);
    /*
     * Set the corresponding bits to Enable simultaneous rewrite of
     * the data register.
     */
    LpTAUJUnitOsReg->ucTAUJnRDE |= (uint8)LpTAUJUnitConfig->usTAUChannelMask;
    /* Set the corresponding bits to enable/disable TOm operation */
    LpTAUJUnitUserReg->ucTAUJnTOE |= ((uint8)LpTAUJUnitConfig->usTOEMask);

    #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
    /* Check TAUJ channels configured for Synchronous start */
    if(PWM_TAUJ == LpTAUSynchStart->ucTAUUnitType)
    {
      /*
       * Set the channel bits that are not configured for
       * synchronous start, to enable the count operation
       */
      LpTAUJUnitUserReg->ucTAUJnTS =
      ((uint8)(LpTAUJUnitConfig->usTAUChannelMask ^ (LusSyncMask &
                            PWM_SYNCH_TAUJ_MASK)));

      LusSyncMask = LusSyncMask >> PWM_FOUR;
    }
    else
    {
      /*
       * Set the corresponding channel bit to enable the count
       * operation
       */
      LpTAUJUnitUserReg->ucTAUJnTS =
                           ((uint8)LpTAUJUnitConfig->usTAUChannelMask);
    }
    #else
    /*
     * Set the corresponding channel bit to enable the count
     * operation
     */
    LpTAUJUnitUserReg->ucTAUJnTS  =
                           ((uint8)LpTAUJUnitConfig->usTAUChannelMask);
    #endif /* #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON) */

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer for the next TAUJ Unit */
    LpTAUJUnitConfig++;
  }/* End of  TAUJ Units for loop */
  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif
  #endif /* End of (PWM_TAUJ_UNIT_USED == STD_ON) */

  #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  /*
   * load the register PIC0SST with 0x01 to start the timers
   * synchronously
   */
  PWM_SYNCH_START_TRIGGER_REG = PWM_ONE;

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif
  #endif /* End of (PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)*/
}

#define PWM_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Pwm_HW_DeInit
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function de-initialises all the PWM channels by
**                        setting to their configured Idle state, disabling the
**                        notifications, resetting all the registers and
**                        stopping the PWM mode of operation of corresponding
**                        timer.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : NA
**
** Remarks              : Global Variable(s):
**                        Pwm_GpTAUAUnitConfig, Pwm_GpTAUJUnitConfig,
**                        Pwm_GpSynchStartConfig,Pwm_GpChannelConfig,
**                        Pwm_GpNotifStatus, Pwm_GpChannelIdleStatus
**                        Function(s) invoked:
**                        SchM_Enter_Pwm, SchM_Exit_Pwm
*******************************************************************************/
#if (PWM_DE_INIT_API == STD_ON)
#define PWM_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_DeInit(void)
{
  #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON)))
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit configuration */
  P2CONST(Tdd_Pwm_TAUABCUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                      LpTAUABCUnitConfig;
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit user control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                      LpTAUABCUnitUserReg;
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit os control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitOsRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                      LpTAUABCUnitOsReg;
  /* Pointer used for TAUA/TAUB/TAUC channel control registers */
  P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                      LpTAUABCChannelReg;
  #if(PWM_DELAY_MACRO_SUPPORT == STD_ON)
  /* Pointer to the TAUA/TAUB/TAUC Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                      LpTAUABCProperties;
  #endif
  #endif /* #if(((PWM_TAUA_UNIT_USED == STD_ON) || \
                 (PWM_TAUB_UNIT_USED == STD_ON) || \\
                 (PWM_TAUC_UNIT_USED == STD_ON))) */

  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Tdd_Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                      LpTAUJUnitConfig;
  /* Pointer pointing to the TAUJ Unit user control registers */
  P2VAR(Tdd_Pwm_TAUJUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                      LpTAUJUnitUserReg;
  /* Pointer pointing to the TAUJ Unit os control registers */
  P2VAR(Tdd_Pwm_TAUJUnitOsRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                      LpTAUJUnitOsReg;
  /* Pointer used for TAUJ channel control registers */
  P2VAR(Tdd_Pwm_TAUJChannelUserRegs,AUTOMATIC,PWM_CONFIG_DATA)
                                                      LpTAUJChannelReg;
  /* Save count from the TAUA/TAUB/TAUC channel loop */
  uint8_least LucSaveCount = PWM_ZERO;
  #endif

  #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
  /*
   * Pointer pointing to the structure for Synchronous start between
   * TAU Units
   */
  P2CONST(Tdd_PwmTAUSynchStartUseType, AUTOMATIC, PWM_CONFIG_CONST)
                                                        LpTAUSynchStart;
  #endif

  /* Pointer pointing to the channel configuration */
  P2CONST(Tdd_Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                        LpChannelConfig;
  uint16 LusChannelOutput;
  uint8_least LucCount;

  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))
  /* Update the TAUA/TAUB/TAUC config pointer to point to the current TAU */
  LpTAUABCUnitConfig = Pwm_GpTAUABCUnitConfig;
  #endif
  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  /* Update the TAUJ config pointer to point to the current TAUJ */
  LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig;
  #endif
  #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)
  LpTAUSynchStart =  Pwm_GpSynchStartConfig;
  #endif

  LpChannelConfig = Pwm_GpChannelConfig;

  /* Check for TAUA/TAUB/TAUC Units Used*/
  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUABC_UNITS_CONFIG; LucCount++)
  {
    #if(PWM_DELAY_MACRO_SUPPORT == STD_ON)
    if(NULL_PTR != LpTAUABCUnitConfig->pDelayCntlRegs)
    {
      /*
       * Reset the corresponding bits of the Delay control register
       * for the channels configured with Delay value
       */
      *(LpTAUABCUnitConfig->pDelayCntlRegs) &=
                                ~LpTAUABCUnitConfig->ulDelayEnableMask;
    }
    else
    {
     /* For Misra Compliance */
    }
    #endif /* End of (PWM_DELAY_MACRO_SUPPORT == STD_ON) */
    /*
     * Update the pointer for the base address of the TAUA/TAUB/TAUC
     * unit registers
     */
    LpTAUABCUnitUserReg = LpTAUABCUnitConfig->pTAUABCUnitUserCntlRegs;

    /*
     * Update the pointer for the base address of the TAUA/TAUB/TAUC
     * unit registers
     */
    LpTAUABCUnitOsReg = LpTAUABCUnitConfig->pTAUABCUnitOsCntlRegs;

    /* Set the configured channel bits to disable the count operation */
    LpTAUABCUnitUserReg->usTAUABCnTT  = LpTAUABCUnitConfig->usTAUChannelMask;

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

    /* Reset all the configured channels registers */
    LpTAUABCUnitOsReg->usTAUABCnTOM &= ~LpTAUABCUnitConfig->usTAUChannelMask;
    #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
    /* Check if current unit not belongs to TAUC */
    if( PWM_HW_TAUC != LpTAUABCUnitConfig->uiPwmTAUType)
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
      LpTAUABCUnitOsReg->usTAUABnTOC &= ~LpTAUABCUnitConfig->usTAUChannelMask;
    }
    else
    {
     /* For Misra Compliance */
    }
    #endif

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
    LpTAUABCUnitUserReg->usTAUABCnTOL &= ~LpTAUABCUnitConfig->usTAUChannelMask;

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
    LpTAUABCUnitUserReg->usTAUABCnTOE &= ~LpTAUABCUnitConfig->usTAUChannelMask;

    /* Set channel output to its configured Idle state */
    LusChannelOutput = LpTAUABCUnitUserReg->usTAUABCnTO;
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
    LusChannelOutput &= ~LpTAUABCUnitConfig->usTAUChannelMask;
    LusChannelOutput |= LpTAUABCUnitConfig->usTOMask;
    LpTAUABCUnitUserReg->usTAUABCnTO  = LusChannelOutput;

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
    LpTAUABCUnitOsReg->usTAUABCnRDE &= ~LpTAUABCUnitConfig->usTAUChannelMask;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to the next TAUA/TAUB/TAUC unit */
    LpTAUABCUnitConfig++;
  }
  /* Loop to reset the attributes of TAUA/TAUB/TAUC channels */
  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUABC_CHANNELS_CONFIG;
                                                            LucCount++)
  {
    LpTAUABCChannelReg =
    (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_CONST))
                                            LpChannelConfig->pCntlRegs;
    #if(PWM_DELAY_MACRO_SUPPORT == STD_ON)
    LpTAUABCProperties =
    (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_CONST))
                                         LpChannelConfig->pChannelProp;
    /* Load the Delay value in to the Delay Compare register */
    if(NULL_PTR != LpTAUABCProperties->pDlyCompRegs)
    {
      /* Reset the Delay compare register of the Delay Macro */
      *(LpTAUABCProperties->pDlyCompRegs) =  PWM_RESET_WORD;
    }
    else
    {
     /* For Misra Compliance */
    }
    #endif /* End of (PWM_DELAY_MACRO_SUPPORT == STD_ON) */

    /* Reset the CMORm register of the configured channel*/
    *LpChannelConfig->pCMORRegs = PWM_RESET_WORD;

    /* Reset the CDRm register of the configured channel */
    LpTAUABCChannelReg->usTAUABCnCDRm  = PWM_RESET_WORD;

    #if(PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Check the Notification is configured for the current channel */
    if(PWM_NO_CBK_CONFIGURED != LpChannelConfig->ucNotificationConfig)
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
      *(LpChannelConfig->pImrIntrCntlRegs) |= \
                                       ~(LpChannelConfig->ucImrMaskValue);

    }
    else
    {
     /* For Misra Compliance */
    }
    /* CDR Notification status of this channel to PWM_FALSE */
    Pwm_GpNotifStatus[LucCount] = PWM_FALSE;
    #endif

    /* Set the Idle state status of this channel as PWM_TRUE */
    Pwm_GpChannelIdleStatus[LucCount] = PWM_TRUE;

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
  }/* End of TAUA/TAUB/TAUC Channels 'for' loop */

  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  LucSaveCount = LucCount;
  #endif

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  #endif /* End of ((PWM_TAUA_UNIT_USED == STD_ON) ||
                    (PWM_TAUB_UNIT_USED == STD_ON) ||
                    (PWM_TAUC_UNIT_USED == STD_ON))) */

  /* check for TAUJ Units Used*/
  #if(PWM_TAUJ_UNIT_USED == STD_ON)

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUJ_UNITS_CONFIG;
                                                       LucCount++)
  {
    /* Update pointer for the base address of the TAUJ unit registers */
    LpTAUJUnitUserReg = LpTAUJUnitConfig->pTAUJUnitUserCntlRegs;
    LpTAUJUnitOsReg = LpTAUJUnitConfig->pTAUJUnitOsCntlRegs;

    /* Set the configured channel bits to disable the count operation */
    LpTAUJUnitUserReg->ucTAUJnTT  =
                        ((uint8)(LpTAUJUnitConfig->usTAUChannelMask));

    /* Reset all the configured channels registers */

    LpTAUJUnitOsReg->ucTAUJnTOM &=
                       ((uint8)(~LpTAUJUnitConfig->usTAUChannelMask));

    LpTAUJUnitOsReg->ucTAUJnTOC &=
                      ((uint8)(~LpTAUJUnitConfig->usTAUChannelMask));

    LpTAUJUnitUserReg->ucTAUJnTOL &=
                      ((uint8)(~LpTAUJUnitConfig->usTAUChannelMask));

    LpTAUJUnitUserReg->ucTAUJnTOE &=
                      ((uint8)(~LpTAUJUnitConfig->usTAUChannelMask));

    /* Set channel output to its configured Idle state */
    LusChannelOutput = (uint8)LpTAUJUnitUserReg->ucTAUJnTO;
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
    LusChannelOutput &= ((uint8)(~LpTAUJUnitConfig->usTAUChannelMask));
    LusChannelOutput |= ((uint8)LpTAUJUnitConfig->usTOMask);
    LpTAUJUnitUserReg->ucTAUJnTO = (uint8)LusChannelOutput;

    LpTAUJUnitOsReg->ucTAUJnRDE &=
                      ((uint8)(~LpTAUJUnitConfig->usTAUChannelMask));

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    /* Increment the pointer to next TAUJ unit */
    LpTAUJUnitConfig++;
  }/* End of TAUJ units 'for' loop */

  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_TAUJ_CHANNELS_CONFIG;
                                                          LucCount++)
  {
    LpTAUJChannelReg =
    (P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_CONST))
                                          LpChannelConfig->pCntlRegs;
    /* Reset the CMORm register of the configured channel*/
    *LpChannelConfig->pCMORRegs = PWM_RESET_WORD;

    /* Reset the CDRm register of the configured channel */
    LpTAUJChannelReg->ulTAUJnCDRm  = PWM_RESET_LONG_WORD;

    #if(PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Check the Notification is configured for the current channel */
    if (PWM_NO_CBK_CONFIGURED != LpChannelConfig->ucNotificationConfig)
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

      /* Disabling the Interrupt processing */
      *(LpChannelConfig->pImrIntrCntlRegs) |= \
                                  ~(LpChannelConfig->ucImrMaskValue);
    }
    else
    {
     /* For Misra Compliance */
    }
    /* Reset CDR Notification status of this channel */
    Pwm_GpNotifStatus[LucSaveCount] = PWM_FALSE;
    #endif

    /* Set the Idle state status of this channel as PWM_TRUE */
    Pwm_GpChannelIdleStatus[LucSaveCount] = PWM_TRUE;

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
    LucSaveCount++;
  }/* End of TAUJ channels 'for' loop */

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  #endif /* End of (PWM_TAUJ_UNIT_USED == STD_ON) */

  #if(PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON)

  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
  #endif

  for(LucCount = PWM_ZERO; LucCount < PWM_TOTAL_UNITS_FOR_SYNCHSTART;
                                                          LucCount++)
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

    /* Reset synchronous start between TAU Units */
    *(LpTAUSynchStart->pPICCntlRegs) &= ~LpTAUSynchStart->usSyncTAUMask;

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */

    LpTAUSynchStart++;
  }
  #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
  #endif
  #endif /* End of (PWM_SYNCHSTART_BETWEEN_TAU_USED == STD_ON) */
}

#define PWM_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* End of (PWM_DE_INIT_API == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_HW_SetDutyCycle
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function updates the duty cycle counter value in
**                        the hardware registers.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddChannelId, LusDutyCycle
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : NA
**
** Remarks              : Global Variable(s):
**                        Pwm_GpTAUAUnitConfig, Pwm_GpTAUJUnitConfig,
**                        Pwm_GpChannelConfig,Pwm_GpChannelIdleStatus
**                        Function(s) invoked:
**                        Pwm_HW_SetDuty_FixedPeriodShifted,
**                        SchM_Enter_Pwm, SchM_Exit_Pwm
*******************************************************************************/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
#define PWM_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SetDutyCycle
(Pwm_ChannelType LddChannelId, uint16 LusDutyCycle)
{
  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit configuration */
  P2CONST(Tdd_Pwm_TAUABCUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                      LpTAUABCUnitConfig;
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                      LpTAUABCUnitUserReg;
  /* Pointer used for TAUA/TAUB/TAUC channel control registers */
  P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                      LpTAUABCChannelReg;
  /* Pointer to the TAUA/TAUB/TAUC Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCProperties;
  #endif
  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Tdd_Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                      LpTAUJUnitConfig;
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(Tdd_Pwm_TAUJUnitUserRegs, AUTOMATIC, PWM_CONFIG_CONST)
                                                      LpTAUJUnitUserReg;
  /* Pointer used for TAUJ channel control registers */
  P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_CONST)
                                                      LpTAUJChannelReg;
  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJProperties;
  #endif
  /* Pointer pointing to the channel configuration */
  P2CONST(Tdd_Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                      LpChannelConfig;
  Pwm_PeriodType LddMasterPeriod;
  uint8 LucVar;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Initialise a pointer to the channel configuration */
  LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;

  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Check for the channel Class Type */
  if(PWM_FIXED_PERIOD_SHIFTED == LpChannelConfig->enClassType)
  {
    /*
     * Set Duty cycle for the required channel in FixedPeriodShifted
     * Class Type
     */
    Pwm_HW_SetDuty_FixedPeriodShifted(LddChannelId, LusDutyCycle);
  }
  else
  #endif
  {
    /* Check for the channel in Master Mode */
    if(PWM_MASTER_CHANNEL == LpChannelConfig->uiTimerMode)
    {
      #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
          (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* Check whether the channel belongs to TAUA/TAUB/TAUC */
      if((PWM_HW_TAUA == LpChannelConfig->uiPwmTAUType) ||
         (PWM_HW_TAUB == LpChannelConfig->uiPwmTAUType) ||
         (PWM_HW_TAUC == LpChannelConfig->uiPwmTAUType))
      #endif
      {
        #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
         || (PWM_TAUC_UNIT_USED == STD_ON))
        /*
         * Initialise a pointer to the Master's control register
         * configuration of TAUA/TAUB/TAUC
         */
        LpTAUABCChannelReg =
        (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                             (LpChannelConfig->pCntlRegs);

        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */

        /* Fetch the pointer to the current TAUA/TAUB/TAUC Unit config */
        LpTAUABCUnitConfig = Pwm_GpTAUABCUnitConfig +
                                   LpChannelConfig->ucTimerUnitIndex;
        /* MISRA Rule         : 11.5                                      */
        /* Message            : Dangerous pointer cast results in loss of */
        /*                      const qualification.                      */
        /* Reason             : This is to achieve throughput in the      */
        /*                      code.                                     */
        /* Verification       : However, the part of the code is          */
        /*                      verified manually and it is not having    */
        /*                      any impact on code.                       */

        /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
        LpTAUABCProperties =
        (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;
        /* Fetch the pointer to the current TAUA/TAUB/TAUC Unit Registers */
        LpTAUABCUnitUserReg = LpTAUABCUnitConfig->pTAUABCUnitUserCntlRegs;

        /* Get the master's period */
        LddMasterPeriod = LpTAUABCChannelReg->usTAUABCnCDRm;

        /* Get the TAU Type in to the local variable */
        LucVar = LpChannelConfig->uiPwmTAUType;

        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */

        /* Increment the pointer to the slave channel */
        LpChannelConfig++;
        /* Increment the channel Id*/
        LddChannelId++;

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        while(LddChannelId < PWM_TOTAL_TAUABC_CHANNELS_CONFIG)
        {
          if(LpChannelConfig->uiTimerMode != PWM_MASTER_CHANNEL)
          {
            /*
             * Initialise a pointer to the slave's control register
             * configuration of TAUA/TAUB/TAUC
             */
            LpTAUABCChannelReg = (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs,
             AUTOMATIC, PWM_CONFIG_DATA))(LpChannelConfig->pCntlRegs);

            /* Check whether the channel is set to its Idle state */
            if(PWM_TRUE == Pwm_GpChannelIdleStatus[LddChannelId])
            {
              /* Stop the counter operation */
              LpTAUABCUnitUserReg->usTAUABCnTT =
                  LpTAUABCProperties->usChannelMask;

              /* Enable the output of the current channel */
              LpTAUABCUnitUserReg->usTAUABCnTOE |=
                                     LpTAUABCProperties->usChannelMask;

              /* Restart the counter operation */
              LpTAUABCUnitUserReg->usTAUABCnTS =
                  LpTAUABCProperties->usChannelMask;

              /* Set the Idle state of the channel to PWM_FALSE */
              Pwm_GpChannelIdleStatus[LddChannelId] = PWM_FALSE;
            }

            /* Load the Absolute duty value in to the CDR Register */
            LpTAUABCChannelReg->usTAUABCnCDRm =
            (uint16)Pwm_HW_CalculateDuty(LddMasterPeriod, LusDutyCycle, LucVar);

            /*
             * Set the corresponding channel Trigger bit to specifies
             * the channel for which simultaneous rewrite is executed
             */

            LpTAUABCUnitUserReg->usTAUABCnRDT =
                                    LpTAUABCProperties->usChannelMask;

            /* Increment the channel Id */
            LddChannelId++;
            /* MISRA Rule       : 17.4                             */
            /* Message          : Increment or decrement operation */
            /*                    performed on pointer.            */
            /* Reason           : Increment operator is used to    */
            /*                    achieve better throughput.       */
            /* Verification     : However, part of the code is     */
            /*                    verified manually and it is not  */
            /*                    having any impact.               */

            /* Increment the pointer to the next channel */
            LpChannelConfig++;
          }
          else
          {
             break;
          }
        }
        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif
        #endif /* End of (((PWM_TAUA_UNIT_USED == STD_ON) ||
                 (PWM_TAUB_UNIT_USED == STD_ON) || \
                 (PWM_TAUC_UNIT_USED == STD_ON))
                 && (PWM_TAUJ_UNIT_USED == STD_ON)) */

      }/* End of if((LpChannelConfig->uiPwmTAUType == PWM_HW_TAUA) ||
         (LpChannelConfig->uiPwmTAUType == PWM_HW_TAUB) ||
         (LpChannelConfig->uiPwmTAUType == PWM_HW_TAUC)) */

      #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
          (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      else
      #endif
      {
        #if(PWM_TAUJ_UNIT_USED == STD_ON)

        /*
         * Initialise a pointer to the Master's control register
         * configuration of TAUJ
         */
        LpTAUJChannelReg =
        (P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                            (LpChannelConfig->pCntlRegs);

        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */

        /* Fetch the pointer to the current TAUJ Unit config */
        LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig +
                                 LpChannelConfig->ucTimerUnitIndex;
        /* MISRA Rule         : 11.5                                      */
        /* Message            : Dangerous pointer cast results in loss of */
        /*                      const qualification.                      */
        /* Reason             : This is to achieve throughput in the      */
        /*                      code.                                     */
        /* Verification       : However, the part of the code is          */
        /*                      verified manually and it is not having    */
        /*                      any impact on code.                       */
        /* Get the pointer to the TAUJ channel properties */
        LpTAUJProperties =
        (P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

        /* Fetch the pointer to the current TAUJ Unit Registers */
        LpTAUJUnitUserReg = LpTAUJUnitConfig->pTAUJUnitUserCntlRegs;

        /* Get the master's period */
        LddMasterPeriod = LpTAUJChannelReg->ulTAUJnCDRm;

        /* Get the TAU Type in to the local variable */
        LucVar = LpChannelConfig->uiPwmTAUType;

        /* Increment the channel Id */
        LddChannelId++;

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

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        while(LddChannelId < PWM_TOTAL_CHANNELS_CONFIGURED)
        {
          if(LpChannelConfig->uiTimerMode != PWM_MASTER_CHANNEL)
          {
            /* Initialise a pointer to the slave's control register
             * configuration of TAUJ
             */
            LpTAUJChannelReg = (P2VAR(Tdd_Pwm_TAUJChannelUserRegs,
            AUTOMATIC, PWM_CONFIG_DATA)) (LpChannelConfig->pCntlRegs);

            /* Check whether the channel is set to its Idle state */
            if (PWM_TRUE == Pwm_GpChannelIdleStatus[LddChannelId])
            {
              /* Stop the counter operation */
              LpTAUJUnitUserReg->ucTAUJnTT = LpTAUJProperties->ucChannelMask;

              /* Enable the output of the current channel */
              LpTAUJUnitUserReg->ucTAUJnTOE |= LpTAUJProperties->ucChannelMask;

              /* Restart the counter operation */
              LpTAUJUnitUserReg->ucTAUJnTS = LpTAUJProperties->ucChannelMask;

              /* Set the Idle state of the channel to PWM_FALSE */
              Pwm_GpChannelIdleStatus[LddChannelId] = PWM_FALSE;
            }
            else
            {
               /* For Misra Compliance */
            }

            LpTAUJChannelReg->ulTAUJnCDRm = \
            Pwm_HW_CalculateDuty(LddMasterPeriod, LusDutyCycle, LucVar);
            /*
             * Set the corresponding channel Trigger bit to specifies
             * the channel for which simultaneous rewrite is executed
             */
            LpTAUJUnitUserReg->ucTAUJnRDT = LpTAUJProperties->ucChannelMask;

            /* Increment the channel Id */
            LddChannelId++;

            /* MISRA Rule       : 17.4                             */
            /* Message          : Increment or decrement operation */
            /*                    performed on pointer.            */
            /* Reason           : Increment operator is used to    */
            /*                    achieve better throughput.       */
            /* Verification     : However, part of the code is     */
            /*                    verified manually and it is not  */
            /*                    having any impact.               */

            /* Increment the pointer to the next channel */
            LpChannelConfig++;
          }
          else
          {
            break;
          }
        }
        /* End of TAUJ Slave Channels */

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif
        #endif /* End of (PWM_TAUJ_UNIT_USED == STD_ON)*/
      }/* End of TAUJ Unit type*/
    }/* End of if(LpChannelConfig->uiTimerMode == PWM_MASTER_CHANNEL)*/
    /* Channel is slave */
    else
    {
      #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
          (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* Check whether the channel belongs to TAUA/TAUB/TAUC */

      if((PWM_HW_TAUA == LpChannelConfig->uiPwmTAUType) ||
         (PWM_HW_TAUB == LpChannelConfig->uiPwmTAUType) ||
         (PWM_HW_TAUC == LpChannelConfig->uiPwmTAUType))
      #endif
      {
        #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
         || (PWM_TAUC_UNIT_USED == STD_ON))

        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */


        /* Fetch the pointer to the current TAUA/TAUB/TAUC Unit config */
        LpTAUABCUnitConfig = Pwm_GpTAUABCUnitConfig +
                         LpChannelConfig->ucTimerUnitIndex;
        /* MISRA Rule         : 11.5                                      */
        /* Message            : Dangerous pointer cast results in loss of */
        /*                      const qualification.                      */
        /* Reason             : This is to achieve throughput in the      */
        /*                      code.                                     */
        /* Verification       : However, the part of the code is          */
        /*                      verified manually and it is not having    */
        /*                      any impact on code.                       */
        /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
        LpTAUABCProperties =
        (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

        /* Fetch the pointer to the current TAUA/TAUB/TAUC Unit Registers */
        LpTAUABCUnitUserReg = LpTAUABCUnitConfig->pTAUABCUnitUserCntlRegs;

        /* Get the offset of the Master from the slave channel */
        LucVar = LpChannelConfig->ucMasterOffset;

        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */

        /*
         * Initialise a pointer to the Master's control register
         * configuration of TAUA/TAUB/TAUC
         */
        LpTAUABCChannelReg =
        (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                    ((LpChannelConfig-LucVar)->pCntlRegs);

        /* Get the master's period */
        LddMasterPeriod = LpTAUABCChannelReg->usTAUABCnCDRm;

        /* Get the TAU Type in to the local variable */
        LucVar = LpChannelConfig->uiPwmTAUType;

        /*
         * Initialise a pointer to the slave's control register
         * configuration of TAUA/TAUB/TAUC
         */
        LpTAUABCChannelReg =
        (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                             (LpChannelConfig->pCntlRegs);

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        /* Check whether the channel is set to its Idle state */
        if(PWM_TRUE == Pwm_GpChannelIdleStatus[LddChannelId])
        {
          /* Stop the counter operation */
          LpTAUABCUnitUserReg->usTAUABCnTT =
              LpTAUABCProperties->usChannelMask;

          /* Enable the output of the current channel */
          LpTAUABCUnitUserReg->usTAUABCnTOE |=
                                       LpTAUABCProperties->usChannelMask;

          /* Restart the counter operation */
          LpTAUABCUnitUserReg->usTAUABCnTS =
              LpTAUABCProperties->usChannelMask;

          /* Set the Idle state of the channel to PWM_FALSE */
          Pwm_GpChannelIdleStatus[LddChannelId] = PWM_FALSE;
        }
        else
        {
          /* For Misra Compliance */
        }
        /* Load the Absolute duty value in to the CDR Register */
        LpTAUABCChannelReg->usTAUABCnCDRm = (uint16)
        Pwm_HW_CalculateDuty(LddMasterPeriod, LusDutyCycle, LucVar);

        /*
         * Set the corresponding channel Trigger bit to specifies the
         * channel for which simultaneous rewrite is executed
         */
        LpTAUABCUnitUserReg->usTAUABCnRDT = LpTAUABCProperties->usChannelMask;

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif
        #endif /* End of ((PWM_TAUA_UNIT_USED == STD_ON) ||
                 (PWM_TAUB_UNIT_USED == STD_ON) ||
                 (PWM_TAUC_UNIT_USED == STD_ON)) */

      }/* End of ((LpChannelConfig->uiPwmTAUType == PWM_HW_TAUA) ||
         (LpChannelConfig->uiPwmTAUType == PWM_HW_TAUB) ||
         (LpChannelConfig->uiPwmTAUType == PWM_HW_TAUC)) */

      #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
          (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* channel belongs to TAUJ */
      else
      #endif
      {
        #if(PWM_TAUJ_UNIT_USED == STD_ON)

        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */

        /* Fetch the pointer to the current TAUJ Unit config */
        LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig +
                                LpChannelConfig->ucTimerUnitIndex;
        /* MISRA Rule         : 11.5                                      */
        /* Message            : Dangerous pointer cast results in loss of */
        /*                      const qualification.                      */
        /* Reason             : This is to achieve throughput in the      */
        /*                      code.                                     */
        /* Verification       : However, the part of the code is          */
        /*                      verified manually and it is not having    */
        /*                      any impact on code.                       */
        /* Get the pointer to the TAUJ channel properties */
        LpTAUJProperties =
        (P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

        /* Fetch the pointer to the current TAUJ Unit Registers */
        LpTAUJUnitUserReg = LpTAUJUnitConfig->pTAUJUnitUserCntlRegs;

        /* Get the offset of the Master from the slave channel */
        LucVar = LpChannelConfig->ucMasterOffset;

        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */

        /*
         * Initialise a pointer to the Master's control register
         * configuration of TAUJ
         */
        LpTAUJChannelReg =
        (P2VAR(Tdd_Pwm_TAUJChannelUserRegs,AUTOMATIC, PWM_CONFIG_DATA))
                             ((LpChannelConfig-LucVar)->pCntlRegs);

        /* Get the master's period */
        LddMasterPeriod = LpTAUJChannelReg->ulTAUJnCDRm;

        /* Get the TAU Type in to the local variable */
        LucVar = LpChannelConfig->uiPwmTAUType;

        /*
         * Initialise a pointer to the slave's control register
         * configuration of TAUJ
         */
        LpTAUJChannelReg =
        (P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                       (LpChannelConfig->pCntlRegs);

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        /* Check whether the channel is set to its Idle state */
        if(PWM_TRUE == Pwm_GpChannelIdleStatus[LddChannelId])
        {
          /* Stop the counter operation */
          LpTAUJUnitUserReg->ucTAUJnTT = LpTAUJProperties->ucChannelMask;

          /* Enable the output of the current channel */
          LpTAUJUnitUserReg->ucTAUJnTOE |= LpTAUJProperties->ucChannelMask;

          /* Restart the counter operation */
          LpTAUJUnitUserReg->ucTAUJnTS = LpTAUJProperties->ucChannelMask;

          /* Set the Idle state of the channel to PWM_FALSE */
          Pwm_GpChannelIdleStatus[LddChannelId] = PWM_FALSE;
        }
        else
        {
          /* For Misra Compliance */
        }

        /* Load the Absolute Duty in to the CDR register */
        LpTAUJChannelReg->ulTAUJnCDRm =
        Pwm_HW_CalculateDuty(LddMasterPeriod, LusDutyCycle, LucVar);

        /*
         * Set the corresponding channel Trigger bit to specifies the
         * channel for which simultaneous rewrite is executed
         */
        LpTAUJUnitUserReg->ucTAUJnRDT = LpTAUJProperties->ucChannelMask;

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif
        #endif/* End of (PWM_TAUJ_UNIT_USED == STD_ON) */
      }/* End of TAUJ Unit type */
    }/* End of the Slave channel */
  }/* End of Variable and Fixed Period Class Type */
}
#define PWM_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* End of (PWM_SET_DUTY_CYCLE_API == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_HW_SetDuty_FixedPeriodShifted
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function updates the duty cycle for
**                        FixedPeriodShifted ClassType channels of TAUA Units.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddChannelId, LusDutyCycle
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : NA
**
** Remarks              : Global Variable(s):
**                        Pwm_GpTAUAUnitConfig, Pwm_GpChannelConfig,
**                        Pwm_GpChannelIdleStatus
**                        Function(s) invoked:
**                        SchM_Enter_Pwm, SchM_Exit_Pwm
*******************************************************************************/
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) && ((PWM_TAUA_UNIT_USED == STD_ON) || \
     (PWM_TAUB_UNIT_USED == STD_ON)))
#define PWM_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC (void, PWM_PRIVATE_CODE) Pwm_HW_SetDuty_FixedPeriodShifted
(Pwm_ChannelType LddChannelId, uint16 LusDutyCycle)
{
  /* Pointer pointing to the TAUA/TAUB Unit configuration */
  P2CONST(Tdd_Pwm_TAUABCUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpTAUABUnitConfig;
  /* Pointer pointing to the TAUA/TAUB Unit control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABUnitUserReg;
  /* Pointer used for TAUA/TAUB channel control registers */
  P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABChannelReg;

  /* Pointer pointing to the channel configuration */
  P2CONST(Tdd_Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpChannelConfig;

    /* Pointer to the TAUA/TAUB/TAUC Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCProperties;

  Pwm_PeriodType LddMasterPeriod;
  uint16 LusChannelMask;
  uint8_least LucCount;
  uint8 LucVar;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Initialise a pointer to the channel configuration */
  LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;

  /* MISRA Rule         : 11.5                                      */
  /* Message            : Dangerous pointer cast results in loss of */
  /*                      const qualification.                      */
  /* Reason             : This is to achieve throughput in the      */
  /*                      code.                                     */
  /* Verification       : However, the part of the code is          */
  /*                      verified manually and it is not having    */
  /*                      any impact on code.                       */
  /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
  LpTAUABCProperties =
  (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

  /* Check whether the channel in Master mode */
  if(PWM_MASTER_CHANNEL == LpChannelConfig->uiTimerMode)
  {
    /* Get the channel mask for the particular channel */
    LusChannelMask = LpTAUABCProperties->usChannelMask;

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Fetch the pointer to the current TAUA/TAUB Unit config */
    LpTAUABUnitConfig = Pwm_GpTAUABCUnitConfig +
                        LpChannelConfig->ucTimerUnitIndex;
    /* Fetch the pointer to the current TAUA/TAUB Unit Registers */
    LpTAUABUnitUserReg = LpTAUABUnitConfig->pTAUABCUnitUserCntlRegs;

    /*
     * Initialise a pointer to the Master's control register
     * configuration of TAUA/TAUB
     */
    LpTAUABChannelReg =
    (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                         (LpChannelConfig->pCntlRegs);

    /* Get the master's period */
    LddMasterPeriod = LpTAUABChannelReg->usTAUABCnCDRm;

    /* Get the TAU Type in to the local variable */
    LucVar = LpChannelConfig->uiPwmTAUType;

    #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
    #endif

    for(LucCount = PWM_ONE; LucCount <= PWM_THREE; LucCount++)
    {
      /* Increment the channel Id */
      LddChannelId++;
      /* Check whether LddChannelId is valid  */
      if(LddChannelId < PWM_TOTAL_TAUABC_CHANNELS_CONFIG)
      {
        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */

        /* Increment the channel for the next channel */
        LpChannelConfig++;

        /*
         * Initialise a pointer to the slave's control register
         * configuration of TAUA/TAUB
         */
        LpTAUABChannelReg =
        (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                             (LpChannelConfig->pCntlRegs);
        /* MISRA Rule         : 11.5                                      */
        /* Message            : Dangerous pointer cast results in loss of */
        /*                      const qualification.                      */
        /* Reason             : This is to achieve throughput in the      */
        /*                      code.                                     */
        /* Verification       : However, the part of the code is          */
        /*                      verified manually and it is not having    */
        /*                      any impact on code.                       */
        /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
        LpTAUABCProperties =
        (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;
        /* Check for the Slave1 and Slave3 channels */
        if((LucCount == PWM_ONE) || (LucCount == PWM_THREE))
        {
          /* Check whether the channel is set to its Idle state */
          if(Pwm_GpChannelIdleStatus[LddChannelId] == PWM_TRUE)
          {
            /* Stop the counter operation */
            LpTAUABUnitUserReg->usTAUABCnTT = \
                                  LpTAUABCProperties->usChannelMask;

            /* Enable the output of the current channel */
            LpTAUABUnitUserReg->usTAUABCnTOE |= \
                                  LpTAUABCProperties->usChannelMask;

            /* Restart the counter operation */
            LpTAUABUnitUserReg->usTAUABCnTS = \
                                  LpTAUABCProperties->usChannelMask;

            /* Set the Idle state of the channel to PWM_FALSE */
            Pwm_GpChannelIdleStatus[LddChannelId] = PWM_FALSE;
          }
        }
        /* Load the Absolute duty value in to the CDR Register */
        LpTAUABChannelReg->usTAUABCnCDRm = (uint16)
        Pwm_HW_CalculateDuty(LddMasterPeriod, LusDutyCycle, LucVar);
      }
      else
      {
        /* Invalid channel, exit to avoid invalid access*/
        break;
      }
    }
    /*
     * Set the corresponding channel Trigger bit to specifies the
     * channel for which simultaneous rewrite is executed
     */
    LpTAUABUnitUserReg->usTAUABCnRDT = LusChannelMask;

    #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
    #endif
  }/* End of if(LpChannelConfig->uiTimerMode == PWM_MASTER_CHANNEL) */
  else
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /*
     * Initialise a pointer to the Master's control register
     * configuration of TAUA/TAUB
     */
    LpTAUABChannelReg =
    (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
    ((LpChannelConfig-(LpChannelConfig->ucMasterOffset))->pCntlRegs);

    /* Get the master's period */
    LddMasterPeriod = LpTAUABChannelReg->usTAUABCnCDRm;

    /* Get the TAU Type in to the local variable */
    LucVar = LpChannelConfig->uiPwmTAUType;

    /*
     * Initialise a pointer to the slave's control register
     * configuration of TAUA/TAUB
     */
    LpTAUABChannelReg =
    (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                         (LpChannelConfig->pCntlRegs);
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Fetch the pointer to the current TAUA/TAUB Unit config */
    LpTAUABUnitConfig = Pwm_GpTAUABCUnitConfig +
                        LpChannelConfig->ucTimerUnitIndex;

    /* Fetch the pointer to the current TAUA/TAUB Unit Registers */
    LpTAUABUnitUserReg = LpTAUABUnitConfig->pTAUABCUnitUserCntlRegs;

    /* Get the masters channel ID*/
    LddChannelId -= LpChannelConfig->ucMasterOffset;

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* Get the Master channel config pointer*/
    LpChannelConfig = LpChannelConfig-LpChannelConfig->ucMasterOffset;

    /* Get the channel mask from the channel configuration */
    LusChannelMask = LpTAUABCProperties->usChannelMask;

    #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
    #endif

    /*
     * Loop to set salve 1 and salve 2 of the particular Master for the
     * 3 consecutive channels configured in fixed period shifted classtype
     */
    for(LucCount = PWM_ONE; LucCount <= PWM_THREE; LucCount++)
    {
      /* Increment the channel Id */
      LddChannelId++;
      /* Check whether LddChannelId is valid  */
      if(LddChannelId < PWM_TOTAL_TAUABC_CHANNELS_CONFIG)
      {
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

        /* MISRA Rule         : 11.5                                      */
        /* Message            : Dangerous pointer cast results in loss of */
        /*                      const qualification.                      */
        /* Reason             : This is to achieve throughput in the      */
        /*                      code.                                     */
        /* Verification       : However, the part of the code is          */
        /*                      verified manually and it is not having    */
        /*                      any impact on code.                       */
        /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
        LpTAUABCProperties =
        (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                          LpChannelConfig->pChannelProp;

        /* Check for Salve 1 or Slave 3 of the Master */
        if((LucCount == PWM_ONE) || (LucCount == PWM_THREE))
        {
          /* Check whether the channel is set to its Idle state */
          if(Pwm_GpChannelIdleStatus[LddChannelId] == PWM_TRUE)
          {
            /* Stop the counter operation */
            LpTAUABUnitUserReg->usTAUABCnTT = LpTAUABCProperties->usChannelMask;

            /* Enable the output of the current channel */
            LpTAUABUnitUserReg->usTAUABCnTOE |= \
                                              LpTAUABCProperties->usChannelMask;

            /* Restart the counter operation */
            LpTAUABUnitUserReg->usTAUABCnTS = LpTAUABCProperties->usChannelMask;

            /* Set the Idle state of the channel to PWM_FALSE */
            Pwm_GpChannelIdleStatus[LddChannelId] = PWM_FALSE;
          }
        }
      }
      else
      {
        /* Invalid channel, exit to avoid invalid access*/
        break;
      }
    }
    /* Load the Absolute duty value in to the CDR Register */
    LpTAUABChannelReg->usTAUABCnCDRm = (uint16)
         Pwm_HW_CalculateDuty(LddMasterPeriod, LusDutyCycle, LucVar);
    /*
     * Set the corresponding channel Trigger bit to specifies the
     * channel for which simultaneous rewrite is executed
     */
    LpTAUABUnitUserReg->usTAUABCnRDT = LusChannelMask;

    #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
    #endif
  }/* End of the channel in slave Mode */
}
#define PWM_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* End of ((PWM_SET_DUTY_CYCLE_API == STD_ON) &&
                  ((PWM_TAUA_UNIT_USED == STD_ON) || \
                   (PWM_TAUB_UNIT_USED == STD_ON))) */
/*******************************************************************************
** Function Name        : Pwm_HW_SetPeriodAndDuty
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function updates the Period and Duty cycle
**                        counter value in the hardware registers.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddChannelId, LddPeriod, LusDutyCycle
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : NA
**
** Remarks              : Global Variable(s):
**                        Pwm_GpTAUAUnitConfig, Pwm_GpTAUJUnitConfig,
**                        Pwm_GpChannelConfig, Pwm_GpChannelIdleStatus
**                        Function(s) invoked:
**                        Pwm_HW_SetDutyCycle,
**                        SchM_Enter_Pwm, SchM_Exit_Pwm
*******************************************************************************/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
#define PWM_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SetPeriodAndDuty
(Pwm_ChannelType LddChannelId, Pwm_PeriodType LddPeriod, uint16 LusDutyCycle)
{
  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit configuration */
  P2CONST(Tdd_Pwm_TAUABCUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpTAUABCUnitConfig;
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit user control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCUnitUserReg;
  /* Pointer used for TAUA/TAUB/TAUC channel control registers */
  P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCChannelReg;
  /* Pointer to the TAUA/TAUB/TAUC Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCProperties;
  #endif

  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Tdd_Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpTAUJUnitConfig;
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(Tdd_Pwm_TAUJUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJUnitUserReg;

  /* Pointer used for TAUJ channel control registers */
  P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJChannelReg;
  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJProperties;
  #endif

  /* Pointer pointing to the channel configuration */
  P2CONST(Tdd_Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpChannelConfig;
  uint16 LusMasterChannelMask;
  uint8 LucVar;

  /* MISRA Rule         : 17.4                                     */
  /* Message            : Array indexing shall be the only allowed */
  /*                      form of pointer arithmetic.              */
  /* Reason             : To access the channel parameters         */
  /* Verification       : However, part of the code                */
  /*                      is verified manually and                 */
  /*                      it is not having any impact.             */

  LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;

  /*
   * Set the period if the channel is master and
   * set the duty of all the slaves of that master
   */
  if(PWM_MASTER_CHANNEL == LpChannelConfig->uiTimerMode)
  {
    #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
         (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
    /* Check whether the channel belongs to TAUA/TAUB/TAUC */
    if((PWM_HW_TAUA == LpChannelConfig->uiPwmTAUType) ||
       (PWM_HW_TAUB == LpChannelConfig->uiPwmTAUType) ||
       (PWM_HW_TAUC == LpChannelConfig->uiPwmTAUType))
    #endif
    {
      #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
          (PWM_TAUC_UNIT_USED == STD_ON))
      /*
       * Initialise a pointer to the control register
       * configuration of TAUA/TAUB/TAUC
       */
      LpTAUABCChannelReg =
      (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                           (LpChannelConfig->pCntlRegs);
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Fetch the pointer to the current TAUA/TAUB/TAUC Unit config */
      LpTAUABCUnitConfig = Pwm_GpTAUABCUnitConfig +
                                 LpChannelConfig->ucTimerUnitIndex;

      /* Fetch the pointer to the current TAUA/TAUB/TAUC Unit Registers */
      LpTAUABCUnitUserReg = LpTAUABCUnitConfig->pTAUABCUnitUserCntlRegs;

      /* MISRA Rule         : 11.5                                      */
      /* Message            : Dangerous pointer cast results in loss of */
      /*                      const qualification.                      */
      /* Reason             : This is to achieve throughput in the      */
      /*                      code.                                     */
      /* Verification       : However, the part of the code is          */
      /*                      verified manually and it is not having    */
      /*                      any impact on code.                       */
      /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
      LpTAUABCProperties =
      (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

      /* Get the TAU Type in to the local variable */
      LucVar = LpChannelConfig->uiPwmTAUType;

      #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
      #endif

      /* Decrement the period value */
      LddPeriod--;
      /* Load the period value in to the CDR register of the
       * master channel
       */
      LpTAUABCChannelReg->usTAUABCnCDRm = (uint16)LddPeriod;

      /* Get the Channel Mask of the Master channel for RDT register */
      LusMasterChannelMask = LpTAUABCProperties->usChannelMask;

      #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
      #endif


      /* Increment the channel Id */
      LddChannelId++;
      /* MISRA Rule         : 17.4                             */
      /* Message            : Increment or decrement operation */
      /*                      performed on pointer.            */
      /* Reason             : Increment operator is used to    */
      /*                      achieve better throughput.       */
      /* Verification       : However, part of the code is     */
      /*                      verified manually and it is not  */
      /*                      having any impact.               */

      /* Increment the pointer to the next channel*/
      LpChannelConfig++;

      while(LddChannelId < PWM_TOTAL_TAUABC_CHANNELS_CONFIG)
      {
        if(LpChannelConfig->uiTimerMode != PWM_MASTER_CHANNEL)
        {
          /*
           * Initialise a pointer to the slave's control register
           * configuration of TAUA/TAUB/TAUC
           */
          LpTAUABCChannelReg =
          (P2VAR(Tdd_Pwm_TAUABCChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                               (LpChannelConfig->pCntlRegs);
          /* MISRA Rule         : 11.5                                      */
          /* Message            : Dangerous pointer cast results in loss of */
          /*                      const qualification.                      */
          /* Reason             : This is to achieve throughput in the      */
          /*                      code.                                     */
          /* Verification       : However, the part of the code is          */
          /*                      verified manually and it is not having    */
          /*                      any impact on code.                       */
          /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
          LpTAUABCProperties =
          (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                          LpChannelConfig->pChannelProp;

          #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter Protected area */
          SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
          #endif

          /* Check whether the channel is set to its Idle state */
          if(Pwm_GpChannelIdleStatus[LddChannelId] == PWM_TRUE)
          {
            /* Stop the counter operation */
            LpTAUABCUnitUserReg->usTAUABCnTT =
                LpTAUABCProperties->usChannelMask;

            /* Enable the output of the current channel */
            LpTAUABCUnitUserReg->usTAUABCnTOE |=
                LpTAUABCProperties->usChannelMask;

              /* Restart the counter operation */
            LpTAUABCUnitUserReg->usTAUABCnTS =
                LpTAUABCProperties->usChannelMask;
            /* Set the Idle state of the channel to PWM_FALSE */
            Pwm_GpChannelIdleStatus[LddChannelId] = PWM_FALSE;
          }
          /* Load the Absolute duty value in to the CDR Register */
          LpTAUABCChannelReg->usTAUABCnCDRm = (uint16)
                   Pwm_HW_CalculateDuty(LddPeriod, LusDutyCycle, LucVar);

          #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Exit Protected area */
          SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
          #endif

          /* Increment the channel*/
          LddChannelId++;
          /* MISRA Rule         : 17.4                             */
          /* Message            : Increment or decrement operation */
          /*                      performed on pointer.            */
          /* Reason             : Increment operator is used to    */
          /*                      achieve better throughput.       */
          /* Verification       : However, part of the code is     */
          /*                      verified manually and it is not  */
          /*                      having any impact.               */

          /* Increment the pointer to the next channel*/
          LpChannelConfig++;
        }
        else
        {
           break;
        }
      }
      /* End of TAUA/TAUB/TAUC Slave channels */
        /*
         * Set the corresponding channels Trigger bits to specifies the
         * channels for which simultaneous rewrite is executed
         */
      LpTAUABCUnitUserReg->usTAUABCnRDT = LusMasterChannelMask;
      #endif/* End of ((PWM_TAUA_UNIT_USED == STD_ON) ||
             * (PWM_TAUB_UNIT_USED == STD_ON) || (PWM_TAUC_UNIT_USED == STD_ON))
             */
    }/* End of if((LpChannelConfig->uiPwmTAUType == PWM_HW_TAUA) ||
                  (LpChannelConfig->uiPwmTAUType == PWM_HW_TAUB) ||
                  (LpChannelConfig->uiPwmTAUType == PWM_HW_TAUC)) */

    #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
         (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
    /* channel belongs to TAUJ */
    else
    #endif
    {
      #if(PWM_TAUJ_UNIT_USED == STD_ON)
      /*
       * Initialise a pointer to the control register
       * configuration of TAUJ
       */
      LpTAUJChannelReg =
      (P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                          (LpChannelConfig->pCntlRegs);
      /* MISRA Rule         : 11.5                                      */
      /* Message            : Dangerous pointer cast results in loss of */
      /*                      const qualification.                      */
      /* Reason             : This is to achieve throughput in the      */
      /*                      code.                                     */
      /* Verification       : However, the part of the code is          */
      /*                      verified manually and it is not having    */
      /*                      any impact on code.                       */
      /* Get the pointer to the TAUJ channel properties */
      LpTAUJProperties =
      (P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

      /* MISRA Rule         : 17.4                                 */
      /* Message            : Array indexing shall be the only     */
      /*                      allowed form of pointer arithmetic.  */
      /* Reason             : To access the channel parameters     */
      /* Verification       : However, part of the code            */
      /*                      is verified manually and             */
      /*                      it is not having any impact.         */

      /* Fetch the pointer to the current TAUJ Unit config */
      LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig +
                              LpChannelConfig->ucTimerUnitIndex;

      /* Fetch the pointer to the current TAUJ Unit Registers */
      LpTAUJUnitUserReg = LpTAUJUnitConfig->pTAUJUnitUserCntlRegs;

      /* Get the TAU Type in to the local variable */
      LucVar = LpChannelConfig->uiPwmTAUType;

      #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
      #endif

      /* Decrement the period value */
      LddPeriod--;
      /*
       * Load the period value in to the CDR register of the
       * master channel
       */
      LpTAUJChannelReg->ulTAUJnCDRm = LddPeriod;

      /* Get the Channel Mask of the Master channel for RDT register */
      LusMasterChannelMask = (uint16)LpTAUJProperties->ucChannelMask;

      #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
      #endif

      /* Increment the channel Id */
      LddChannelId++;

      /* MISRA Rule         : 17.4                             */
      /* Message            : Increment or decrement operation */
      /*                      performed on pointer.            */
      /* Reason             : Increment operator is used to    */
      /*                      achieve better throughput.       */
      /* Verification       : However, part of the code is     */
      /*                      verified manually and it is not  */
      /*                      having any impact.               */

      /* Increment the pointer to the next channel*/
      LpChannelConfig++;
      while(LddChannelId < PWM_TOTAL_CHANNELS_CONFIGURED)
      {
        if(LpChannelConfig->uiTimerMode != PWM_MASTER_CHANNEL)
        {
          /*
           * Initialise a pointer to the slave's control register
           * configuration of TAUJ
           */
          LpTAUJChannelReg =
          (P2VAR(Tdd_Pwm_TAUJChannelUserRegs, AUTOMATIC, PWM_CONFIG_DATA))
                                              (LpChannelConfig->pCntlRegs);
          /* MISRA Rule         : 11.5                                      */
          /* Message            : Dangerous pointer cast results in loss of */
          /*                      const qualification.                      */
          /* Reason             : This is to achieve throughput in the      */
          /*                      code.                                     */
          /* Verification       : However, the part of the code is          */
          /*                      verified manually and it is not having    */
          /*                      any impact on code.                       */
          /* Get the pointer to the TAUJ channel properties */
          LpTAUJProperties =
          (P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                          LpChannelConfig->pChannelProp;

          #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enter Protected area */
          SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
          #endif

          /* Check whether the channel is set to its Idle state */
          if(PWM_TRUE == Pwm_GpChannelIdleStatus[LddChannelId])
          {
            /* Stop the counter operation */
            LpTAUJUnitUserReg->ucTAUJnTT = LpTAUJProperties->ucChannelMask;

            /* Enable the output of the current channel */
            LpTAUJUnitUserReg->ucTAUJnTOE |= LpTAUJProperties->ucChannelMask;

             /* Restart the counter operation */
            LpTAUJUnitUserReg->ucTAUJnTS = LpTAUJProperties->ucChannelMask;

            /* Set the Idle state of the channel to PWM_FALSE */
            Pwm_GpChannelIdleStatus[LddChannelId] = PWM_FALSE;
          }
          else
          {
            /* For Misra Compliance */
          }
          /* Load the Absolute duty value in to the CDR Register */
          LpTAUJChannelReg->ulTAUJnCDRm =
          Pwm_HW_CalculateDuty(LddPeriod, LusDutyCycle, LucVar);

          #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Exit Protected area */
          SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
          #endif

          /* Increment the channel */
          LddChannelId++;

          /* MISRA Rule         : 17.4                             */
          /* Message            : Increment or decrement operation */
          /*                      performed on pointer.            */
          /* Reason             : Increment operator is used to    */
          /*                      achieve better throughput.       */
          /* Verification       : However, part of the code is     */
          /*                      verified manually and it is not  */
          /*                      having any impact.               */

          /* Increment the pointer to the next channel*/
          LpChannelConfig++;
        }
        else
        {
           break;
        }
      }
      /* End of TAUJ Slave channels */

      /*
       * Set the corresponding channels Trigger bits to specifies the
       * channels for which simultaneous rewrite is executed
       */
      LpTAUJUnitUserReg->ucTAUJnRDT = (uint8)LusMasterChannelMask;
      #endif/* End of (PWM_TAUJ_UNIT_USED == STD_ON) */
    }/* End of TAUJ Unit type */
  }/* End of if(LpChannelConfig->uiTimerMode == PWM_MASTER_CHANNEL) */
  /* Set the Duty cycle of the requested channel if Slave */
  else
  {
    /* Set the Duty cycle for the slave channel */
    Pwm_HW_SetDutyCycle(LddChannelId, LusDutyCycle);
  }
}
#define PWM_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* End of (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_HW_SetOutputToIdle
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function sets the output of a required channel to
**                        its configured Idle state.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddChannelId
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : NA
**
** Remarks              : Global Variable(s):
**                        Pwm_GpTAUAUnitConfig, Pwm_GpTAUJUnitConfig,
**                        Pwm_GpChannelConfig, Pwm_GpChannelIdleStatus
**                        Function(s) invoked:
**                        SchM_Enter_Pwm, SchM_Exit_Pwm
*******************************************************************************/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
#define PWM_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_SetOutputToIdle
(Pwm_ChannelType LddChannelId)
{
  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit configuration */
  P2CONST(Tdd_Pwm_TAUABCUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpTAUABCUnitConfig;
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit user control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCUnitUserReg;
   /* Pointer to the TAUA/TAUB/TAUC Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCProperties;
  #endif

  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Tdd_Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpTAUJUnitConfig;
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(Tdd_Pwm_TAUJUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJUnitUserReg;
  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJProperties;
  #endif

  /* Pointer pointing to the channel configuration */
  P2CONST(Tdd_Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                      LpChannelConfig;
  uint8_least LucCount;
  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))
  uint8 LucVar;
  #endif

  /* MISRA Rule         : 17.4                                     */
  /* Message            : Array indexing shall be the only allowed */
  /*                      form of pointer arithmetic.              */
  /* Reason             : To access the channel parameters         */
  /* Verification       : However, part of the code                */
  /*                      is verified manually and                 */
  /*                      it is not having any impact.             */

  /* Get the pointer to the channel configuration */
  LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;

  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))
  /* Check whether the current channel is TAUA/TAUB/TAUC */
  if((PWM_HW_TAUA == LpChannelConfig->uiPwmTAUType) ||
     (PWM_HW_TAUB == LpChannelConfig->uiPwmTAUType) ||
     (PWM_HW_TAUC == LpChannelConfig->uiPwmTAUType))
  {
    /* MISRA Rule         : 17.4                                     */
    /* Message            : Array indexing shall be the only allowed */
    /*                      form of pointer arithmetic.              */
    /* Reason             : To access the channel parameters         */
    /* Verification       : However, part of the code                */
    /*                      is verified manually and                 */
    /*                      it is not having any impact.             */

    /* Fetch the pointer to the current TAUA/TAUB/TAUC Unit config */
    LpTAUABCUnitConfig = Pwm_GpTAUABCUnitConfig +
                           LpChannelConfig->ucTimerUnitIndex;

    /* Fetch the pointer to the current TAUA/TAUB/TAUC Unit Registers */
    LpTAUABCUnitUserReg = LpTAUABCUnitConfig->pTAUABCUnitUserCntlRegs;

  }
  else
  {
  /* For Misra Compliance */
  }
  #endif

  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  /* Check whether the current channel is TAUJ */
  if(PWM_HW_TAUJ == LpChannelConfig->uiPwmTAUType)
  {
    /* MISRA Rule         : 17.4                                     */
    /* Message            : Array indexing shall be the only allowed */
    /*                      form of pointer arithmetic.              */
    /* Reason             : To access the channel parameters         */
    /* Verification       : However, part of the code                */
    /*                      is verified manually and                 */
    /*                      it is not having any impact.             */

    /* Fetch the pointer to the current TAUJ Unit config */
    LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig +
                           LpChannelConfig->ucTimerUnitIndex;

    /* Fetch the pointer to the current TAUJ Unit Registers */
    LpTAUJUnitUserReg = LpTAUJUnitConfig->pTAUJUnitUserCntlRegs;
  }
   else
  {
  /* For Misra Compliance */
  }
  #endif

  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
  /* Check for the current channel Class Type is in Fixed Period Shifted */
  if(PWM_FIXED_PERIOD_SHIFTED == LpChannelConfig->enClassType)
  {
    /* Check for the channel is in slave mode */
    if(PWM_SLAVE_CHANNEL == LpChannelConfig->uiTimerMode)
    {
      /* Get the Master channel offset from the slave */
      LucVar = LpChannelConfig->ucMasterOffset;

      /* Get the Master channel ID */
      LddChannelId -= LucVar;

      /* MISRA Rule         : 17.4                                     */
      /* Message            : Array indexing shall be the only allowed */
      /*                      form of pointer arithmetic.              */
      /* Reason             : To access the channel parameters         */
      /* Verification       : However, part of the code                */
      /*                      is verified manually and                 */
      /*                      it is not having any impact.             */

      /* Get the pointer to the Master channel config */
      LpChannelConfig = LpChannelConfig-LucVar;
    }
    else
    {
     /* For Misra Compliance */
    }

    for(LucCount = PWM_ONE; LucCount <= PWM_THREE; LucCount++)
    {
      /* Increment the channel Id */
      LddChannelId++;

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

      /* MISRA Rule         : 11.5                                      */
      /* Message            : Dangerous pointer cast results in loss of */
      /*                      const qualification.                      */
      /* Reason             : This is to achieve throughput in the      */
      /*                      code.                                     */
      /* Verification       : However, the part of the code is          */
      /*                      verified manually and it is not having    */
      /*                      any impact on code.                       */
      /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
      LpTAUABCProperties =
      (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

      if((PWM_ONE == LucCount) || (PWM_THREE == LucCount))
      {
        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        /* MISRA Rule         : 9.1                              */
        /* Message            : All automatic variables shall    */
        /*                      have been assigned a value       */
        /*                      before being used.               */
        /* Reason             : This part of the code will be    */
        /*                      visited only when the channel is */
        /*                      of TAUA Unit and is of Fixed     */
        /*                      Period Shifted ClassType.        */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */

        /* Stop the counter operation */
        LpTAUABCUnitUserReg->usTAUABCnTT = LpTAUABCProperties->usChannelMask;

        /* MISRA Rule         : 12.7                              */
        /* Message            : Bitwise operators shall not be    */
        /*                      applied to operands whose         */
        /*                      underlying type is signed.        */
        /* Reason             : Though the bitwise operation is   */
        /*                      performed on unsigned data, this  */
        /*                      warning is generated by the QAC   */
        /*                      tool V6.2.1 as an indirect result */
        /*                      of integral promotion in complex  */
        /*                      bitwise operations                */
        /* Verification       : However, this part of the code is */
        /*                      verified manually and it is not   */
        /*                      having any impact.                */

        /* Set the corresponding channel bit to disable TOm operation */
        LpTAUABCUnitUserReg->usTAUABCnTOE &= ~LpTAUABCProperties->usChannelMask;

         /* Restart the counter operation */
        LpTAUABCUnitUserReg->usTAUABCnTS = LpTAUABCProperties->usChannelMask;

        if((uint8)PWM_LOW == LpChannelConfig->uiIdleLevel)
        {
          /* MISRA Rule         : 12.7                              */
          /* Message            : Bitwise operators shall not be    */
          /*                      applied to operands whose         */
          /*                      underlying type is signed.        */
          /* Reason             : Though the bitwise operation is   */
          /*                      performed on unsigned data, this  */
          /*                      warning is generated by the QAC   */
          /*                      tool V6.2.1 as an indirect result */
          /*                      of integral promotion in complex  */
          /*                      bitwise operations                */
          /* Verification       : However, this part of the code is */
          /*                      verified manually and it is not   */
          /*                      having any impact.                */

          /* Reset the corresponding bit if Idle state is LOW */
          LpTAUABCUnitUserReg->usTAUABCnTO &=
                                   ~LpTAUABCProperties->usChannelMask;
        }
        else
        {
          /* Set the corresponding bit if Idle state is HIGH */
          LpTAUABCUnitUserReg->usTAUABCnTO |= LpTAUABCProperties->usChannelMask;
        }

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        /* Set the Idle state status of this channel as PWM_TRUE */
        Pwm_GpChannelIdleStatus[LddChannelId] = PWM_TRUE;
      }/* End of if((PWM_ONE == LucCount) || (PWM_THREE == LucCount)) */
      else
      {
        /* For Misra Compliance */
      }
    }/* End of for(LucCount = PWM_ONE; PWM_THREE >= LucCount; LucCount++) */
  }/* End of if(PWM_FIXED_PERIOD_SHIFTED == LpChannelConfig->enClassType) */
  /* Is the current channel Class Type is in Fixed / Variable Period */
  else
  #endif /* #if((PWM_TAUA_UNIT_USED == STD_ON) || \
                 (PWM_TAUB_UNIT_USED == STD_ON)) */
  {
    /* Check whether the channel is in Slave Mode */
    if(PWM_SLAVE_CHANNEL == LpChannelConfig->uiTimerMode)
    {
      #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
           (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* Check whether the channel belongs to TAUA/TAUB/TAUC */
      if((PWM_HW_TAUA == LpChannelConfig->uiPwmTAUType) ||
         (PWM_HW_TAUB == LpChannelConfig->uiPwmTAUType) ||
         (PWM_HW_TAUC == LpChannelConfig->uiPwmTAUType))
      #endif
      {
        #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
         || (PWM_TAUC_UNIT_USED == STD_ON))

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        /* MISRA Rule         : 11.5                                      */
        /* Message            : Dangerous pointer cast results in loss of */
        /*                      const qualification.                      */
        /* Reason             : This is to achieve throughput in the      */
        /*                      code.                                     */
        /* Verification       : However, the part of the code is          */
        /*                      verified manually and it is not having    */
        /*                      any impact on code.                       */

        /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
        LpTAUABCProperties =
        (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;
        /* Stop the counter operation */
        LpTAUABCUnitUserReg->usTAUABCnTT = LpTAUABCProperties->usChannelMask;

        /* MISRA Rule         : 12.7                              */
        /* Message            : Bitwise operators shall not be    */
        /*                      applied to operands whose         */
        /*                      underlying type is signed.        */
        /* Reason             : Though the bitwise operation is   */
        /*                      performed on unsigned data, this  */
        /*                      warning is generated by the QAC   */
        /*                      tool V6.2.1 as an indirect result */
        /*                      of integral promotion in complex  */
        /*                      bitwise operations                */
        /* Verification       : However, this part of the code is */
        /*                      verified manually and it is not   */
        /*                      having any impact.                */
        /* Set the corresponding channel bit to disable TOm operation */
        LpTAUABCUnitUserReg->usTAUABCnTOE &= ~LpTAUABCProperties->usChannelMask;

         /* Restart the counter operation */
        LpTAUABCUnitUserReg->usTAUABCnTS = LpTAUABCProperties->usChannelMask;
        if((uint8)PWM_LOW == LpChannelConfig->uiIdleLevel)
        {
          /* MISRA Rule         : 12.7                              */
          /* Message            : Bitwise operators shall not be    */
          /*                      applied to operands whose         */
          /*                      underlying type is signed.        */
          /* Reason             : Though the bitwise operation is   */
          /*                      performed on unsigned data, this  */
          /*                      warning is generated by the QAC   */
          /*                      tool V6.2.1 as an indirect result */
          /*                      of integral promotion in complex  */
          /*                      bitwise operations                */
          /* Verification       : However, this part of the code is */
          /*                      verified manually and it is not   */
          /*                      having any impact.                */

          /* Reset the corresponding bit if Idle state is LOW */
          LpTAUABCUnitUserReg->usTAUABCnTO &=
                                   ~LpTAUABCProperties->usChannelMask;
        }
        else
        {
          /* Set the corresponding bit if Idle state is HIGH */
          LpTAUABCUnitUserReg->usTAUABCnTO |= LpTAUABCProperties->usChannelMask;
        }

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        #endif/* End of #if((PWM_TAUA_UNIT_USED == STD_ON) ||
                            (PWM_TAUB_UNIT_USED == STD_ON) ||
                            (PWM_TAUC_UNIT_USED == STD_ON)) */
      }
      #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
           (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* channel belongs to TAUJ */
      else
      #endif
      {
        #if(PWM_TAUJ_UNIT_USED == STD_ON)

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        /* MISRA Rule         : 11.5                                      */
        /* Message            : Dangerous pointer cast results in loss of */
        /*                      const qualification.                      */
        /* Reason             : This is to achieve throughput in the      */
        /*                      code.                                     */
        /* Verification       : However, the part of the code is          */
        /*                      verified manually and it is not having    */
        /*                      any impact on code.                       */
        /* Get the pointer to the TAUJ channel properties */
        LpTAUJProperties =
        (P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

        /* MISRA Rule         : 9.1                              */
        /* Message            : All automatic variables shall    */
        /*                      have been assigned a value       */
        /*                      before being used.               */
        /* Reason             : This part of the code will be    */
        /*                      visited only when the channel is */
        /*                      of TAUJ Unit.                    */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */

        /* Stop the counter operation */
        LpTAUJUnitUserReg->ucTAUJnTT = LpTAUJProperties->ucChannelMask;

        /* MISRA Rule         : 12.7                              */
        /* Message            : Bitwise operators shall not be    */
        /*                      applied to operands whose         */
        /*                      underlying type is signed.        */
        /* Reason             : Though the bitwise operation is   */
        /*                      performed on unsigned data, this  */
        /*                      warning is generated by the QAC   */
        /*                      tool V6.2.1 as an indirect result */
        /*                      of integral promotion in complex  */
        /*                      bitwise operations                */
        /* Verification       : However, this part of the code is */
        /*                      verified manually and it is not   */
        /*                      having any impact.                */

        /* Set the corresponding channel bit to disable TOm operation */
        LpTAUJUnitUserReg->ucTAUJnTOE &= ~LpTAUJProperties->ucChannelMask;

        /* Restart the counter operation */
        LpTAUJUnitUserReg->ucTAUJnTS = LpTAUJProperties->ucChannelMask;
        if((uint8)PWM_LOW == LpChannelConfig->uiIdleLevel)
        {
          /* MISRA Rule         : 12.7                              */
          /* Message            : Bitwise operators shall not be    */
          /*                      applied to operands whose         */
          /*                      underlying type is signed.        */
          /* Reason             : Though the bitwise operation is   */
          /*                      performed on unsigned data, this  */
          /*                      warning is generated by the QAC   */
          /*                      tool V6.2.1 as an indirect result */
          /*                      of integral promotion in complex  */
          /*                      bitwise operations                */
          /* Verification       : However, this part of the code is */
          /*                      verified manually and it is not   */
          /*                      having any impact.                */

          /* Reset the corresponding bit if Idle state is LOW */
          LpTAUJUnitUserReg->ucTAUJnTO &= ~LpTAUJProperties->ucChannelMask;
        }
        else
        {
          /* Set the corresponding bit if Idle state is HIGH */
          LpTAUJUnitUserReg->ucTAUJnTO |= LpTAUJProperties->ucChannelMask;
        }
        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif
        #endif/* End of (PWM_TAUJ_UNIT_USED == STD_ON) */
      }
      /* Set the Idle state status of this channel as PWM_TRUE */
      Pwm_GpChannelIdleStatus[LddChannelId] = PWM_TRUE;
    }/* End of if(LpChannelConfig->uiTimerMode == PWM_SLAVE_CHANNEL) */
    /* Channel in Master Mode*/
    else
    {
      #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
           (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* Check if channel belongs to TAUA/TAUB/TAUC */
      if((PWM_HW_TAUA == LpChannelConfig->uiPwmTAUType) ||
         (PWM_HW_TAUB == LpChannelConfig->uiPwmTAUType) ||
         (PWM_HW_TAUC == LpChannelConfig->uiPwmTAUType))
      #endif
      {
        #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
         || (PWM_TAUC_UNIT_USED == STD_ON))

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */
        LpChannelConfig++;

        LddChannelId++;

        for(LucCount=PWM_ONE;
        (PWM_MASTER_CHANNEL != LpChannelConfig->uiTimerMode)
        && (LucCount<PWM_TOTAL_TAUABC_CHANNELS_CONFIG); LucCount++)
        {

          /* MISRA Rule         : 11.5                                      */
          /* Message            : Dangerous pointer cast results in loss of */
          /*                      const qualification.                      */
          /* Reason             : This is to achieve throughput in the      */
          /*                      code.                                     */
          /* Verification       : However, the part of the code is          */
          /*                      verified manually and it is not having    */
          /*                      any impact on code.                       */
          /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
          LpTAUABCProperties =
          (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

          /* Stop the counter operation */
          LpTAUABCUnitUserReg->usTAUABCnTT =
            LpTAUABCProperties->usChannelMask;

          /* MISRA Rule         : 12.7                              */
          /* Message            : Bitwise operators shall not be    */
          /*                      applied to operands whose         */
          /*                      underlying type is signed.        */
          /* Reason             : Though the bitwise operation is   */
          /*                      performed on unsigned data, this  */
          /*                      warning is generated by the QAC   */
          /*                      tool V6.2.1 as an indirect result */
          /*                      of integral promotion in complex  */
          /*                      bitwise operations                */
          /* Verification       : However, this part of the code is */
          /*                      verified manually and it is not   */
          /*                      having any impact.                */
          /* Set corresponding channel bit to disable TOm operation */
          LpTAUABCUnitUserReg->usTAUABCnTOE &=
                                         ~LpTAUABCProperties->usChannelMask;

         /* Restart the counter operation */
          LpTAUABCUnitUserReg->usTAUABCnTS =
            LpTAUABCProperties->usChannelMask;

          if((uint8)PWM_LOW == LpChannelConfig->uiIdleLevel)
          {
            /* MISRA Rule         : 12.7                              */
            /* Message            : Bitwise operators shall not be    */
            /*                      applied to operands whose         */
            /*                      underlying type is signed.        */
            /* Reason             : Though the bitwise operation is   */
            /*                      performed on unsigned data, this  */
            /*                      warning is generated by the QAC   */
            /*                      tool V6.2.1 as an indirect result */
            /*                      of integral promotion in complex  */
            /*                      bitwise operations                */
            /* Verification       : However, this part of the code is */
            /*                      verified manually and it is not   */
            /*                      having any impact.                */

            /* Reset the corresponding bit if Idle state is LOW */
            LpTAUABCUnitUserReg->usTAUABCnTO &=
                                        ~LpTAUABCProperties->usChannelMask;
          }
          else
          {
            /* Set the corresponding bit if Idle state is HIGH */
            LpTAUABCUnitUserReg->usTAUABCnTO |=
                                        LpTAUABCProperties->usChannelMask;
          }

          /* Set the Idle state status of this channel as PWM_TRUE */
          Pwm_GpChannelIdleStatus[LddChannelId] = PWM_TRUE;

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

          /* Increment the channel Id */
          LddChannelId++;
        }

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif
        #endif/* End of ((PWM_TAUA_UNIT_USED == STD_ON) ||
                         (PWM_TAUB_UNIT_USED == STD_ON) ||
                         (PWM_TAUC_UNIT_USED == STD_ON)) */
      }/* End of if((LpChannelConfig->uiPwmTAUType == PWM_HW_TAUA) ||
                    (LpChannelConfig->uiPwmTAUType == PWM_HW_TAUB) ||
                    (LpChannelConfig->uiPwmTAUType == PWM_HW_TAUC)) */
      #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
           (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* channel belongs to TAUJ*/
      else
      #endif
      {
        #if(PWM_TAUJ_UNIT_USED == STD_ON)

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */

        /* Increment the channel to the next channel */
        LpChannelConfig++;

        /* Increment the channel Id */
        LddChannelId++;

        for(LucCount=PWM_ONE;
        (PWM_MASTER_CHANNEL != LpChannelConfig->uiTimerMode)
         && (LucCount<PWM_TOTAL_TAUJ_CHANNELS_CONFIG); LucCount++ )
        {
          /* MISRA Rule         : 11.5                                      */
          /* Message            : Dangerous pointer cast results in loss of */
          /*                      const qualification.                      */
          /* Reason             : This is to achieve throughput in the      */
          /*                      code.                                     */
          /* Verification       : However, the part of the code is          */
          /*                      verified manually and it is not having    */
          /*                      any impact on code.                       */
          /* Get the pointer to the TAUJ channel properties */
          LpTAUJProperties =
          (P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

          /* Stop the counter operation */
          LpTAUJUnitUserReg->ucTAUJnTT = LpTAUJProperties->ucChannelMask;

          /* MISRA Rule         : 12.7                              */
          /* Message            : Bitwise operators shall not be    */
          /*                      applied to operands whose         */
          /*                      underlying type is signed.        */
          /* Reason             : Though the bitwise operation is   */
          /*                      performed on unsigned data, this  */
          /*                      warning is generated by the QAC   */
          /*                      tool V6.2.1 as an indirect result */
          /*                      of integral promotion in complex  */
          /*                      bitwise operations                */
          /* Verification       : However, this part of the code is */
          /*                      verified manually and it is not   */
          /*                      having any impact.                */

          /*
           * Set the corresponding channel bit to disable TOm
           * operation
           */
          LpTAUJUnitUserReg->ucTAUJnTOE &= ~LpTAUJProperties->ucChannelMask;

          /* Restart the counter operation */
          LpTAUJUnitUserReg->ucTAUJnTS = LpTAUJProperties->ucChannelMask;
          if((uint8)PWM_LOW == LpChannelConfig->uiIdleLevel)
          {
            /* MISRA Rule         : 12.7                              */
            /* Message            : Bitwise operators shall not be    */
            /*                      applied to operands whose         */
            /*                      underlying type is signed.        */
            /* Reason             : Though the bitwise operation is   */
            /*                      performed on unsigned data, this  */
            /*                      warning is generated by the QAC   */
            /*                      tool V6.2.1 as an indirect result */
            /*                      of integral promotion in complex  */
            /*                      bitwise operations                */
            /* Verification       : However, this part of the code is */
            /*                      verified manually and it is not   */
            /*                      having any impact.                */

            /* Reset the corresponding bit if Idle state is LOW */
            LpTAUJUnitUserReg->ucTAUJnTO &= ~LpTAUJProperties->ucChannelMask;
          }
          else
          {
            /* Set the corresponding bit if Idle state is HIGH */
            LpTAUJUnitUserReg->ucTAUJnTO |= LpTAUJProperties->ucChannelMask;
          }

          /* Set the Idle state status of this channel as PWM_TRUE */
          Pwm_GpChannelIdleStatus[LddChannelId] = PWM_TRUE;

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

          /* Increment the channel Id */
          LddChannelId++;
        }/* End of 'for' LpChannelConfig->uiTimerMode != PWM_MASTER_CHANNEL
            && LucCount<PWM_TOTAL_TAUJ_CHANNELS_CONFIG */

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        #endif/* End of (PWM_TAUJ_UNIT_USED == STD_ON) */
      }/* End of the TAUJ Unit Type */
    }/* End of if channel is in Master Mode */
  }/* End of if(LpChannelConfig->enClassType != PWM_FIXED_PERIOD_SHIFTED) */
}
#define PWM_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* End of (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_HW_GetOutputState
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function gets the outputstate of a PWM channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddChannelId
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Pwm_OutputStateType (PWM_LOW / PWM_HIGH)
**
** Preconditions        : NA
**
** Remarks              : Global Variable(s):
**                        Pwm_GpTAUAUnitConfig, Pwm_GpTAUJUnitConfig,
**                        Pwm_GpChannelConfig, Pwm_GpChannelIdleStatus
**                        Function(s) invoked:
**                        SchM_Enter_Pwm, SchM_Exit_Pwm
*******************************************************************************/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
#define PWM_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Pwm_OutputStateType, PWM_PRIVATE_CODE) Pwm_HW_GetOutputState
(Pwm_ChannelType LddChannelId)
{
  #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
      (PWM_TAUC_UNIT_USED == STD_ON))
  /* Pointer pointing to the TAUA/TAUB/TAUC Unit configuration */
  P2CONST(Tdd_Pwm_TAUABCUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpTAUABCUnitConfig;
  /* Pointer pointing to the TAUA Unit user control registers */
  P2VAR(Tdd_Pwm_TAUABCUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCUnitUserReg;
  /* Pointer to the TAUA/TAUB/TAUC Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUABCProperties;
  #endif

  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  /* Pointer pointing to the TAUJ Unit configuration */
  P2CONST(Tdd_Pwm_TAUJUnitConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpTAUJUnitConfig;
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(Tdd_Pwm_TAUJUnitUserRegs, AUTOMATIC, PWM_CONFIG_DATA) LpTAUJUnitUserReg;
  /* Pointer to the TAUJ Channel Properties structure */
  P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA)
                                                    LpTAUJProperties;
  #endif

  /* Pointer pointing to the channel configuration */
  P2CONST(Tdd_Pwm_ChannelConfigType, AUTOMATIC, PWM_CONFIG_CONST)
                                                    LpChannelConfig;
  Pwm_OutputStateType LenRetOutputState;

  /* MISRA Rule         : 17.4                                     */
  /* Message            : Array indexing shall be the only allowed */
  /*                      form of pointer arithmetic.              */
  /* Reason             : To access the channel parameters         */
  /* Verification       : However, part of the code                */
  /*                      is verified manually and                 */
  /*                      it is not having any impact.             */

  LpChannelConfig = Pwm_GpChannelConfig + LddChannelId;

  /* Default return output state */
  LenRetOutputState = PWM_LOW;

  /* Check whether the channel is in Slave Mode */
  if(PWM_SLAVE_CHANNEL == LpChannelConfig->uiTimerMode)
  {
    /* Check whether this channel output is set to Idle state */
    if(PWM_TRUE == Pwm_GpChannelIdleStatus[LddChannelId])
    {
      LenRetOutputState = (Pwm_OutputStateType)LpChannelConfig->uiIdleLevel;
    }
    /* If the channel output is not in Idle state */
    else
    {
      #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
           (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      /* Check whether the channel belongs to TAUA/TAUB/TAUC */
      if((PWM_HW_TAUA == LpChannelConfig->uiPwmTAUType) ||
         (PWM_HW_TAUB == LpChannelConfig->uiPwmTAUType) ||
         (PWM_HW_TAUC == LpChannelConfig->uiPwmTAUType))
      #endif
      {
        #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
         || (PWM_TAUC_UNIT_USED == STD_ON))

        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */

        /* Fetch the pointer to the current TAUA/TAUB/TAUC Unit config */
        LpTAUABCUnitConfig = Pwm_GpTAUABCUnitConfig +
                             LpChannelConfig->ucTimerUnitIndex;

        /* Fetch the pointer to the current TAUA/TAUB/TAUC Unit Registers */
        LpTAUABCUnitUserReg = LpTAUABCUnitConfig->pTAUABCUnitUserCntlRegs;

        /* MISRA Rule         : 11.5                                      */
        /* Message            : Dangerous pointer cast results in loss of */
        /*                      const qualification.                      */
        /* Reason             : This is to achieve throughput in the      */
        /*                      code.                                     */
        /* Verification       : However, the part of the code is          */
        /*                      verified manually and it is not having    */
        /*                      any impact on code.                       */
        /* Get the pointer to the TAUA/TAUB/TAUC channel properties */
        LpTAUABCProperties =
        (P2VAR(Tdd_Pwm_TAUABCProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        /* Condition to check current output state of the slave channel */
        if(((LpTAUABCUnitUserReg->usTAUABCnTO) &
           (LpTAUABCProperties->usChannelMask)) ==
              LpTAUABCProperties->usChannelMask)
        {
          LenRetOutputState = PWM_HIGH;
        }
        else
        {
        /* For Misra Compliance */
        }

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        #endif/* End of ((PWM_TAUA_UNIT_USED == STD_ON) ||
                         (PWM_TAUB_UNIT_USED == STD_ON) ||
                         (PWM_TAUC_UNIT_USED == STD_ON)) */
      }
      #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
           (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
      else
      #endif
      {
        #if(PWM_TAUJ_UNIT_USED == STD_ON)
        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */

        /* Fetch the pointer to the current TAUJ Unit config */
        LpTAUJUnitConfig = Pwm_GpTAUJUnitConfig +
                            LpChannelConfig->ucTimerUnitIndex;

        /* Fetch the pointer to the current TAUJ Unit Registers */
        LpTAUJUnitUserReg = LpTAUJUnitConfig->pTAUJUnitUserCntlRegs;

        /* MISRA Rule         : 11.5                                      */
        /* Message            : Dangerous pointer cast results in loss of */
        /*                      const qualification.                      */
        /* Reason             : This is to achieve throughput in the      */
        /*                      code.                                     */
        /* Verification       : However, the part of the code is          */
        /*                      verified manually and it is not having    */
        /*                      any impact on code.                       */
        /* Get the pointer to the TAUJ channel properties */
        LpTAUJProperties =
        (P2VAR(Tdd_Pwm_TAUJProperties, AUTOMATIC, PWM_CONFIG_DATA))
                                        LpChannelConfig->pChannelProp;

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        SchM_Enter_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        /*
         * Condition to check the current output state of the
         * slave channel
         */
        if(((LpTAUJUnitUserReg->ucTAUJnTO) &
        (LpTAUJProperties->ucChannelMask)) == LpTAUJProperties->ucChannelMask)
        {
          LenRetOutputState = PWM_HIGH;
        }
        else
        {
        /* For Misra Compliance */
        }

        #if(PWM_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Exit Protected area */
        SchM_Exit_Pwm(PWM_REGISTERS_PROTECTION);
        #endif

        #endif/* End of (PWM_TAUJ_UNIT_USED == STD_ON) */
      }
    }/* End of 'else' part of
        "if (PWM_TRUE == Pwm_GpChannelIdleStatus[LddChannelId])" */
  }/* End of if(PWM_SLAVE_CHANNEL == LpChannelConfig->uiTimerMode) */
  else
  {
  /* For Misra Compliance */
  }
  return LenRetOutputState;
}
#define PWM_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* End of (PWM_GET_OUTPUT_STATE_API == STD_ON) */

/*******************************************************************************
** Function Name        : Pwm_HW_CalculateDuty
**
** Service ID           : NA
**
** Description          : This is PWM Driver Component support function.
**                        This function Calculates Absolute duty for the
**                        PWM channel.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddAbsolutePeriod, LddRelativeDuty, LucTAUType
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Pwm_PeriodType
**
** Preconditions        : NA
**
** Remarks              : Global Variable(s):
**                        None
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#define PWM_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Pwm_PeriodType, PWM_PRIVATE_CODE) Pwm_HW_CalculateDuty
(Pwm_PeriodType LddAbsolutePeriod, Pwm_PeriodType LddRelativeDuty,
                                                  uint8 LucTAUType)
{
  Pwm_PeriodType  LddAbsoluteDuty;
  #if(PWM_TAUJ_UNIT_USED == STD_ON)
  Pwm_PeriodType  LddCorrectionPeriod;
  #endif

  if(MAX_DUTY_CYCLE == LddRelativeDuty)
  {
    #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
         (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
    if((PWM_HW_TAUA == LucTAUType) || (PWM_HW_TAUB == LucTAUType) ||
       (PWM_HW_TAUC == LucTAUType))
    #endif
    {
      #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
         || (PWM_TAUC_UNIT_USED == STD_ON))
      /*
       * If Duty is 100%, Update (CDRm (master channel)
       * setting value + 1) value in the CDRm register
       */
       LddAbsoluteDuty = (uint16)LddAbsolutePeriod + 1;
      #endif
    }
    #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
         (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
    else
    #endif
    {
      #if(PWM_TAUJ_UNIT_USED == STD_ON)
      /*
       * If Duty is 100%, Update (CDRm (master channel)
       * setting value + 1) value in the CDRm register
       */
       LddAbsoluteDuty =  LddAbsolutePeriod + 1;
      #endif
    }
  }
  else if(MIN_DUTY_CYCLE == LddRelativeDuty)
  {
    /* If Duty is 0%, Update 0x0000 value in the CDRm register */
    LddAbsoluteDuty = MIN_DUTY_CYCLE;
  }
  else
  {
    /* Increment the period values since the CDR(master)
       was loaded with 1 less */
    LddAbsolutePeriod++;
    #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
         (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
    if((PWM_HW_TAUA == LucTAUType) || (PWM_HW_TAUB == LucTAUType) ||
       (PWM_HW_TAUC == LucTAUType))
    #endif
    {
      #if((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) \
       || (PWM_TAUC_UNIT_USED == STD_ON))
      /*
       * If Duty is between 0x0000 and 0x8000, AbsoluteDutyCycle =
       * ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15
       */

      /* MISRA Rule         : 12.7                                         */
      /* Message            : A right shift on signed data may be an       */
      /*                      arithmetic or a logical shift.               */
      /* Reason             : Though the shift operation is performed on   */
      /*                      unsigned data, this warning is generated by  */
      /*                      the QAC tool V6.2.1 as an indirect result of */
      /*                      integral promotion, in a special situation   */
      /*                      arises when unsigned char and unsigned short */
      /*                      objects are the operands of a shift operator.*/
      /* Verification       : However, this part of the code is verified   */
      /*                      manually and it is not having any impact.    */

      LddAbsoluteDuty = (uint16)
      ((LddAbsolutePeriod * LddRelativeDuty) >> PWM_DUTY_CALC_DIV);
      #endif
    }
    #if(((PWM_TAUA_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON) || \
         (PWM_TAUC_UNIT_USED == STD_ON)) && (PWM_TAUJ_UNIT_USED == STD_ON))
    else
    #endif
    {
      #if(PWM_TAUJ_UNIT_USED == STD_ON)
      if(LddAbsolutePeriod > PWM_PERIOD_LIMIT)
      {
        /*
         * If Period > 0xFFFF and Duty is between 0x0000 and 0x8000
         */

         LddCorrectionPeriod = LddAbsolutePeriod & PWM_CORRECTION_MASK;

         LddAbsoluteDuty = (uint32)
         (((LddAbsolutePeriod >> PWM_DUTY_CALC_DIV) * LddRelativeDuty) + \
         ((LddCorrectionPeriod * LddRelativeDuty) >> PWM_DUTY_CALC_DIV));
      }
      else
      {
        /*
         * If Duty is between 0x0000 and 0x8000, AbsoluteDutyCycle =
         * ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15
         */
        LddAbsoluteDuty =
        (LddAbsolutePeriod * LddRelativeDuty) >> PWM_DUTY_CALC_DIV;
      }
      #endif
    }
  }
  return LddAbsoluteDuty;
}

#define PWM_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Pwm_HW_Callback
**
** Service ID           : NA
**
** Description          : This routine is used to invoke the callback
**                        notification.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LucChannelIdx
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : NA
**
** Remarks              : Global Variable(s):
**                        Pwm_GpChannelConfig
**                        Function(s) invoked:
**                        None
*******************************************************************************/
#if(PWM_NOTIFICATION_SUPPORTED == STD_ON)

#define PWM_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, PWM_PRIVATE_CODE) Pwm_HW_Callback(Pwm_ChannelType LucChannelIdx)
{
  P2CONST(Tdd_Pwm_NotificationType, AUTOMATIC, PWM_APPL_CODE) LpChannelFunc;
  uint8 LucChIdx;
  /* MISRA Rule         : 17.4                             */
  /* Message            : Increment or decrement operation */
  /*                      performed on pointer.            */
  /* Reason             : Increment operator is used to    */
  /*                      achieve better throughput.       */
  /* Verification       : However, part of the code is     */
  /*                      verified manually and it is not  */
  /*                      having any impact.               */

  LucChIdx = *(Pwm_GpChannelTimerMap + LucChannelIdx);
  /* check if Notification status is enabled for this channel */
  if(PWM_TRUE == Pwm_GpNotifStatus[LucChIdx])
  {
    LucChIdx = Pwm_GpChannelConfig[LucChIdx].ucNotificationConfig;
    LpChannelFunc = &Pwm_GstChannelNotifFunc[LucChIdx];
    LpChannelFunc->pPwmEdgeNotifPtr();
  }
  else
  {
  /* For Misra Compliance */
  }
}

#define PWM_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* End of (PWM_NOTIFICATION_SUPPORTED == STD_ON) */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
