/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Mcu.c                                                       */
/* Version      = 3.0.17                                                      */
/* Date         = 10-Sep-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2010-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API function implementations of MCU Driver              */
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
 * V3.0.1: 28-Jul-2010 : As per SCR 320 following changes are made:
 *                       1 Mcu_Init Api updated with Voltage comparator
 *                         channels initialization functionality.
 *                       2 Mcu_InitClock Api updated to support FOUT
 *                         functionality.
 *                       3 Deepstop mode is supported with the WAKE pin
 *                         functionality as a precompile option.
 *                       4 In Mcu_GetPllStatus Api conditional checks modified
 *                         to avoid reloading of the same value.
 *                       5 Misra warning added in Mcu_PerformReset Api.
 *
 * V3.0.2: 02-Sep-2010 : As per SCR 341, Misra warning's are added.
 *
 * V3.0.3: 06-Jan-2011 : As per SCR 392, following changes are done:
 *                       1 Clearing of Wake up factors in Mcu_Init Api are
 *                         removed.
 *                       2 Mcu_InitClock Api is updated to add a functionality
 *                         for High speed Internal ring ocillator.
 *                       3 Functionality related to High speed Internal ring
 *                         oscillator is removed in Mcu_SetMode Api.
 *                       4 Mcu_DeepStopPrepare Internal API added.
 *                       5 Sequence of verification of the status of clock
 *                         domains is modified.
 *                       6 Mcu_InitClock and Mcu_DistributePllClock Api's are
 *                         updated for CLMAn control register 1.
 *
 * V3.0.4: 27-Jan-2011 : As per SCR 407, functionality of IO reset register 1
 *                       is added in Mcu_SetMode Api.
 *
 * V3.0.5: 25-Feb-2011 : As per SCR 420, PROTCMDn and PROTSn registers are
 *                       modified to update and check the status with value of
 *                       8 bit.
 *
 * V3.0.6: 17-Jun-2011 : As per SCR 468, following changes are done:
 *                       1 Data types of the following data structure
 *                         elements are corrected:ulLVIindicatingReg,
 *                         ulSubOscStabTime, ulPLL0StabTime, ulPLL1StabTime,
 *                         ulPLL2StabTime, ulOscWufMsk and ulMainOscStabTime.
 *                       2 The functionality for clearing of Wake up factors is
 *                         updated for writing with "0" for Wake up factors
 *                         which are not assigned to a valid wake-up factor.
 *                       3 Functionality of Voltage comparators is updated with
 *                         precompile options and also to update the enable and
 *                         the edge selection bits seperately.
 *                       4 Trailing spaces are removed at the end of lines.
 *
 * V3.0.7: 29-Jun-2011 : As per SCR 481, Clock monitor disabling
 *                       functionality is removed and added a check for status
 *                       of clock monitor before updating respective clock
 *                       monitor registers in Mcu_InitClock and
 *                       Mcu_DistributePllClock Api's.
 *
 * V3.0.7a: 18-Oct-2011  : Copyright is updated.
 *
 * V3.0.8 : 17-May-2012  : As per SCR 014, Following changes are made:
 *                         1. Precompile options are added to
 *                            LulSubClockStabCount and LulMainClockStabCount
 *                            variables in Mcu_InitClock API.
 *                         2. Mcu_SetMode API is updated for changes in
 *                            MCU_STOP_MODE, MCU_RUN_MODE_ISO1_DEEPSTOP and
 *                            MCU_DEEPSTOP_MODE power down modes.
 *                         3. Mcu_DeepStopPrepare function is updated for
 *                            removal of disabling the PLL's functionality.
 *                         4. Invocation of Mcu_DeepStopPrepare is modified in
 *                            Mcu_SetMode API for change in order of preparing
 *                            AWO and ISO0 clock domains.
 *                         5. Stop mask is unmasked for PLL's in
 *                            Mcu_DeepStopPrepare function.
 *
 * V3.0.9 : 06-Jun-2012  : As per SCR 031, Mcu_GetVersionInfo API is removed
 *                         and implemented as macro.
 *
 * V3.0.9a: 19-Feb-2013  : Merged Sx4-H V3.00 as below.
 *                         1. As per MANTIS 5337, Mcu_InitRamSection is updated
 *                            for changing type from 16bit to 32bit of
 *                            ulRamSectionSize and related variables.
 *                         2. As per MANTIS 4690, Mcu_GetPllStatus is modified
 *                            to modify checking algorithm of PLL0-2.
 *                         3. As per MANTIS 7125, Mcu_SetMode is modified.
 *                         4. Added # define MCU_STOP_SEC_PRIVATE_CODE at last
 *                            of code.
 *
 * V3.0.10 : 06-Dec-2012 : As per SCR 078, Automatic change to I/O buffer hold
 *                         state upon entering DEEPSTOP mode is avoided in case
 *                         "McuPortGroupStatusBackup"=false, in the
 *                         API Mcu_SetMode().
 *
 * V3.0.11 : 31-Jan-2013 : IOHOLD masking functionality is updated as
 *                         independent of Port Group Status Backup
 *                         functionality
 *
 * V3.0.12: 25-Mar-2013  : As per SCR 091, The following changes have been made,
 *                         1. Alignment is changed as per code guidelines.
 *                         2. Registers Used section is updated in API Headers
 *                         3. As per mantis #6151, IOHOLD masking functionality
 *                            is updated as independent of Port Group Status
 *                            Backup functionality.
 *                         4. As per mantis #5455, a vendor specific API
 *                            Mcu_MaskClear_WakeUpFactor is added to Mask and
 *                            Clear the wakeup factor register.
 *                         5. As per mantis #5465, The API Mcu_RestartClocks,
 *                            is added for restart of PLL after early wakeup
 *                         6. As per OPCN requirement "Resume of Clock
 *                            Generators after STOP / DEEPSTOP" a vendor
 *                            specific API Mcu_ConfigureAWO7 is added.
 *                         7. As per OPCN requirement workaround for "CPU start
 *                            after DEEPSTOP" disabling of PLL before Deep Stop
 *                            mode is removed from Mcu_DeepStopPrepare
 *                            API.
 *                         8. As per Mantis #5465, Mcu_Iso1SoftWakeUp API is
 *                            added.
 *
 * V3.0.13: 12-04-2013   : As per SCR 100, for mantis #7125 The initialization
 *                         of wakeup mask registers is loaded with configuration
 *                         values and masking of register.
 *
 * V3.0.14: 22-04-2013   : As per SCR 104, Following changes are made:
 *                         1.For mantis #5465 and #8472 The Mcu_RestartClocks
 *                           API is updated for the restart of the Sub
 *                           Oscillator.
 *                         2.For mantis #9015 The Mcu_ConfigureAWO7 API is
 *                           Invoked between MCU_STOP_MODE_ISO1_ON and
 *                           MCU_STOP_MODE_ISO1_DEEPSTOP.
 *                         3.For Mantis #5465 and #8472 Mcu_SetMode API is
 *                           updated for the return value of the
 *                           Mcu_RestartClocks API.
 *                         4.For mantis #5465 and #8472 Mcu_Iso1SoftWakeUp API
 *                           is updated for the passing of argument.
 *
 * V3.0.14a: 14-06-2013  : As per the MANTIS #12207, API Mcu_RestartClocks()
 *                         is updated for patch release.
 *
 * V3.0.15: 12-Jul-2013  : As per mantis 11731 and SCR xxx,following changes are
 *                         made:
 *                         Mcu_SetMode API is updated for the clock switch
 *                         in the STOP Mode.
 * V3.0.16: 18-Jul-2013  : As per Mantis 11731 and SCR xxx Mcu_CpuClockRestore
 *                         API is added and Mcu_SetMode API is updated.
 *
 * V3.0.17: 10-Sep-2013  : The declaration of variable LblDemReported is 
 *                         modified in Mcu_SetMode API.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Mcu.h"
#include "Mcu_Ram.h"
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#include "Dem.h"
#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Mcu.h"
#endif
#include "Mcu_LTTypes.h"
#include "Mcu_Reg.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/

/* AUTOSAR Specification version information */
#define MCU_C_AR_MAJOR_VERSION     MCU_AR_MAJOR_VERSION_VALUE
#define MCU_C_AR_MINOR_VERSION     MCU_AR_MINOR_VERSION_VALUE
#define MCU_C_AR_PATCH_VERSION     MCU_AR_PATCH_VERSION_VALUE

/* File version information */
#define MCU_C_SW_MAJOR_VERSION     3
#define MCU_C_SW_MINOR_VERSION     0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (MCU_AR_MAJOR_VERSION != MCU_C_AR_MAJOR_VERSION)
  #error "Mcu.c : Mismatch in Specification Major Version"
#endif

#if (MCU_AR_MINOR_VERSION != MCU_C_AR_MINOR_VERSION)
  #error "Mcu.c : Mismatch in Specification Minor Version"
#endif

#if (MCU_AR_PATCH_VERSION != MCU_C_AR_PATCH_VERSION)
  #error "Mcu.c : Mismatch in Specification Patch Version"
#endif

#if (MCU_SW_MAJOR_VERSION != MCU_C_SW_MAJOR_VERSION)
  #error "Mcu.c : Mismatch in Major Version"
#endif

#if (MCU_SW_MINOR_VERSION != MCU_C_SW_MINOR_VERSION)
  #error "Mcu.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
#define MCU_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"

/* Global for storing AW07 CKSC register value */
STATIC VAR(uint32, MCU_CONFIG_DATA) Mcu_GulCkscA07Val;

/* Global for storing AW07 CKSC register value */
STATIC VAR(uint32, MCU_CONFIG_DATA) Mcu_Gblckscstatus;

#define MCU_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"
/*******************************************************************************
**             Internal Function Prototypes                                   **
*******************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(void, MCU_PRIVATE_CODE)Mcu_DeepStopPrepare(void);

#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(void, MCU_PRIVATE_CODE)Mcu_ConfigureAWO7(void);

#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_RestartClocks(void);

#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_CpuClockPrepare(void);

#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_CpuClockRestore(void);

#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_Iso1SoftWakeUp(void);
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************

**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Mcu_Init
**
** Service ID         : 0x00
**
** Description        : This service performs initialization of the MCU Driver
**                      component.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : ConfigPtr - Pointer to MCU Driver Configuration set
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable:
**                      Mcu_GblDriverStatus, Mcu_GpConfigPtr
**                      Mcu_GpCkscRegOffset, Mcu_GpCkscRegValue
**
** Function Invoked   : Det_ReportError, Dem_ReportErrorStatus,
**                      Mcu_Iso1SoftWakeUp
**
** Registers Used     : PROTCMD2, LVICNT, PROTS2, VCPC0CTL0, VCPC0CTL1, PWS0,
**                      PWS1
**
*******************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, MCU_PUBLIC_CODE) Mcu_Init
      (P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr)
{
  #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  /* Pointer pointing to the Port registers */
  P2CONST(Tdd_Mcu_PortGroupAddress, AUTOMATIC, MCU_CONFIG_DATA) LpPortRegisters;
  /* pointer to CKSC register offset */
  P2VAR(uint32, AUTOMATIC, MCU_CONFIG_CONST) LpPortRamArea;
  uint8 LucIndex;
  #endif

  #if ((MCU_VCPC0CTL0_ENABLE == STD_ON) || (MCU_VCPC0CTL1_ENABLE == STD_ON))
  uint8 LucVoltageCmp;
  #endif
  uint8 LenReturnValue;
  boolean LblDemReported;
  uint8 LucCount = MCU_FIVE;
  LblDemReported = MCU_FALSE;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the config pointer is NULL pointer */
  if (ConfigPtr == NULL_PTR)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_SID,
                                                            MCU_E_PARAM_CONFIG);
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check if the database is present */
    if ((ConfigPtr->ulStartOfDbToc) == MCU_DBTOC_VALUE)
    {
      /* Assign the global pointer with the config pointer */
      Mcu_GpConfigPtr = ConfigPtr;
      /* Assign global pointers to CKSC register offset and value */
      Mcu_GpCkscRegOffset = Mcu_GpConfigPtr->pCkscRegOffset;
      Mcu_GpCkscRegValue = Mcu_GpConfigPtr->pCkscRegValue;

      /* MISRA Rule        : 11.3                                             */
      /* Message           : A cast should not be performed between a         */
      /*                     pointer type and an integral type.               */
      /* Reason            : This is to access the hardware registers in the  */
      /*                     code.                                            */
      /* Verification      : However, the part of the code is                 */
      /*                     verified manually and it is not having           */
      /*                     any impact on code.                              */

      do
      {
        /* Write the write enable register */
        MCU_PROTCMD2 = MCU_WRITE_DATA;

        /* MISRA Rule   : 11.3                                             */
        /* Message      : A cast should not be performed between a         */
        /*                pointer type and an integral type.               */
        /* Reason       : This is to access the hardware registers in the  */
        /*                code.                                            */
        /* Verification : However, the part of the code is                 */
        /*                verified manually and it is not having           */
        /*                any impact on code.                              */

        /* Set LVI indication voltage detection level */
        MCU_LVICNT = Mcu_GpConfigPtr->ulLVIindicationReg;
        MCU_LVICNT = ~(Mcu_GpConfigPtr->ulLVIindicationReg);
        MCU_LVICNT = Mcu_GpConfigPtr->ulLVIindicationReg;

        LucCount--;

        /* MISRA Rule   : 11.3                                             */
        /* Message      : A cast should not be performed between a         */
        /*                pointer type and an integral type.               */
        /* Reason       : This is to access the hardware registers in the  */
        /*                code.                                            */
        /* Verification : However, the part of the code is                 */
        /*                verified manually and it is not having           */
        /*                any impact on code.                              */
      }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

      if (MCU_PROTS2 == MCU_ONE)
      {
        /* writing to write-protected register failed and
         * report production error
         */
        Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      }

      #if (MCU_VCPC0CTL0_ENABLE == STD_ON)
      /* Get Voltage comparator configured channel 0 */
      LucVoltageCmp = Mcu_GpConfigPtr->ucVCPC0CTLreg0;

      /* MISRA Rule   : 11.3                                             */
      /* Message      : A cast should not be performed between a         */
      /*                pointer type and an integral type.               */
      /* Reason       : This is to access the hardware registers in the  */
      /*                code.                                            */
      /* Verification : However, the part of the code is                 */
      /*                verified manually and it is not having           */
      /*                any impact on code.                              */
      /* check if the Voltage comparator configured channel 0 needs to be
       * enabled */
      if ((LucVoltageCmp & MCU_VCPC_ENABLE_VALUE) == MCU_VCPC_ENABLE_VALUE)
      {
        /* Update the voltage comparator for Enable bit seperately for Reset*/
        MCU_VCPC0CTL0 &= MCU_VCPC_ENABLE_VALUE;
        /* configure the Voltage transition direction edge selection of
         * interrupt for Voltage comparator channel 0 */
        MCU_VCPC0CTL0 |= (LucVoltageCmp  & MCU_VCPC_ENABLE_MASK);
        /* Update the voltage comparator for Enable bit seperately */
        MCU_VCPC0CTL0 |= MCU_VCPC_ENABLE_VALUE;
      }
      #endif

      #if (MCU_VCPC0CTL1_ENABLE == STD_ON)
      /* Get Voltage comparator configured channel 1 */
      LucVoltageCmp = Mcu_GpConfigPtr->ucVCPC0CTLreg1;

      /* MISRA Rule   : 11.3                                             */
      /* Message      : A cast should not be performed between a         */
      /*                pointer type and an integral type.               */
      /* Reason       : This is to access the hardware registers in the  */
      /*                code.                                            */
      /* Verification : However, the part of the code is                 */
      /*                verified manually and it is not having           */
      /*                any impact on code.                              */
      /* check if the Voltage comparator configured channel 1 needs to be
       * enabled */
      if ((LucVoltageCmp & MCU_VCPC_ENABLE_VALUE) == MCU_VCPC_ENABLE_VALUE)
      {
        /* Update the voltage comparator for Enable bit seperately for Reset */
        MCU_VCPC0CTL1 &= MCU_VCPC_ENABLE_VALUE;
        /* configure the Voltage transition direction edge selection of
         * interrupt for Voltage comparator channel 1 */
        MCU_VCPC0CTL1 |= (LucVoltageCmp & MCU_VCPC_ENABLE_MASK);
        /* Update the voltage comparator for Enable bit seperately  */
        MCU_VCPC0CTL1 |= MCU_VCPC_ENABLE_VALUE;
      }
      #endif

      /* MISRA Rule   : 11.3                                             */
      /* Message      : A cast should not be performed between a         */
      /*                pointer type and an integral type.               */
      /* Reason       : This is to access the hardware registers in the  */
      /*                code.                                            */
      /* Verification : However, the part of the code is                 */
      /*                verified manually and it is not having           */
      /*                any impact on code.                              */
      /* Check if reset because of ISO0 wakeup */
      if (((MCU_WUFH0 != MCU_LONG_WORD_ZERO) ||
            (MCU_WUFL0 != MCU_LONG_WORD_ZERO) ||
               (MCU_WUFM0 != MCU_LONG_WORD_ZERO)))
      {
        LenReturnValue = Mcu_Iso1SoftWakeUp();
        if (LenReturnValue != E_NOT_OK)
        {
          do
          {
            /* Infinite loop to wait for PWSS1PSS bit of PWS1 to 0 and
             * Iso bit to 1 */

          }while(((MCU_PWS1 & MCU_PWS_REG_MASK) != MCU_LONG_WORD_ONE));
        }
      }

      /* MISRA Rule   : 11.3                                             */
      /* Message      : A cast should not be performed between a         */
      /*                pointer type and an integral type.               */
      /* Reason       : This is to access the hardware registers in the  */
      /*                code.                                            */
      /* Verification : However, the part of the code is                 */
      /*                verified manually and it is not having           */
      /*                any impact on code.                              */

      do
       {
         #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
         SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
         #endif

         /* MISRA Rule  : 11.3                                    */
         /* Message     : A cast should not be performed between a*/
         /*               pointer type and an integral type.      */
         /* Reason      : This is to access the hardware registers*/
         /*               in the code.                            */
         /* Verification: However, the part of the code is        */
         /*               verified manually and it is not having  */
         /*               any impact on code.                     */


         /* Write the write enable register */
         MCU_PROTCMD2 = MCU_WRITE_DATA;

         /* Make the ISO1 region enter into DEEPSTOP mode */
         MCU_PSC0 = MCU_LONG_WORD_ZERO;
         MCU_PSC0 = ~MCU_LONG_WORD_ZERO;
         MCU_PSC0 = MCU_LONG_WORD_ZERO;
         LucCount--;
         #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
         SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
         #endif
       }while((LucCount > MCU_ZERO) &&
                   (MCU_PROTS2 == MCU_ONE));

       if (MCU_PROTS2 == MCU_ONE)
       {
         /* writing to write-protected register failed and
          * report production error
          */
         Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                          DEM_EVENT_STATUS_FAILED);
         LblDemReported = MCU_TRUE;
       }

      do
       {
         #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
         SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
         #endif

         /* MISRA Rule  : 11.3                                    */
         /* Message     : A cast should not be performed between a*/
         /*               pointer type and an integral type.      */
         /* Reason      : This is to access the hardware registers*/
         /*               in the code.                            */
         /* Verification: However, the part of the code is        */
         /*               verified manually and it is not having  */
         /*               any impact on code.                     */


         /* Write the write enable register */
         MCU_PROTCMD2 = MCU_WRITE_DATA;

         /* Make the ISO1 region enter into DEEPSTOP mode */
         MCU_PSC1 = MCU_LONG_WORD_ZERO;
         MCU_PSC1 = ~MCU_LONG_WORD_ZERO;
         MCU_PSC1 = MCU_LONG_WORD_ZERO;
         LucCount--;
         #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
         SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
         #endif
       }while((LucCount > MCU_ZERO) &&
                   (MCU_PROTS2 == MCU_ONE));

       if (MCU_PROTS2 == MCU_ONE)
       {
         /* writing to write-protected register failed and
          * report production error
          */
         Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                          DEM_EVENT_STATUS_FAILED);
         LblDemReported = MCU_TRUE;
       }

      if (LblDemReported == MCU_FALSE)
      {
        /* Check if the wake-up is from deep-stop mode */
        if (((MCU_PWS0 & MCU_IOHOLD_MASK) == MCU_IOHOLD_MASK)
                      && ((MCU_PWS1 & MCU_IOHOLD_MASK) == MCU_IOHOLD_MASK))
        {
          /* MISRA Rule   : 11.3                                          */
          /* Message      : A cast should not be performed between a      */
          /*                pointer type and an integral type.            */
          /* Reason       : This is to access the hardware registers      */
          /*                 in the code.                                 */
          /* Verification : However, the part of the code is              */
          /*                verified manually and it is not having        */
          /*                any impact on code.                           */

          #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
          /* Restore PORT registers */
          /* Count for the size of array in which the values at Port
           * registers are to be stored for back-up before entering into
           * deep-stop mode
           */
          LucIndex = Mcu_GpConfigPtr->ucNumOfPortGroup;
          /* Get pointer to RAM area */
          LpPortRamArea = Mcu_GpConfigPtr->pPortRamArea;
          /* Get pointer to port registers structure */
          LpPortRegisters =
               (P2CONST(Tdd_Mcu_PortGroupAddress, AUTOMATIC, MCU_CONFIG_DATA))
                                            Mcu_GpConfigPtr->pPortGroupSetting;
          do
          {
            /* Restore the value of PSR register of the configured
             * Port group
             */
            LpPortRegisters->pPortGroupAddress->ulPSRn
                  = (*LpPortRamArea) | MCU_MSB_MASK;

            /* MISRA Rule         : 17.4                             */
            /* Message            : Increment or decrement operation */
            /*                      performed on pointer.            */
            /* Reason             : Increment operator is used to    */
            /*                      achieve better throughput.       */
            /* Verification       : However, part of the code is     */
            /*                      verified manually and it is not  */
            /*                      having any impact.               */
            LpPortRamArea++;
            LpPortRegisters++;
            LucIndex--;
          }while (LucIndex > MCU_ZERO);
          #endif /* #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */
        }
      }

      #if (MCU_DEV_ERROR_DETECT == STD_ON)
      /* Set the Global Status */
      Mcu_GblDriverStatus = MCU_INITIALIZED;
      #endif
    }
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* No database flashed. Hence, report to DET */
      Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_SID,
                                                        MCU_E_INVALID_DATABASE);
    }
    #endif
  }
}
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_InitRamSection
**
** Service ID         : 0x01
**
** Description        : This function initializes the RAM section as provided
**                      from the configuration structure.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : RamSection - Id for RAM section
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Remarks            : Global Variable:
**                      Mcu_GblDriverStatus, Mcu_GpConfigPtr
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None
**
*******************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitRamSection
(Mcu_RamSectionType RamSection)
{
  P2CONST(Tdd_Mcu_RamSetting, AUTOMATIC, MCU_CONFIG_CONST) LpRamSetting;
  P2VAR(uint8, AUTOMATIC, MCU_CONFIG_DATA) LpRamStartAddress;
  Std_ReturnType LenReturnValue;
  uint32 LulNoOfByte;
  uint8 LucDataByte;

  /* Initialize return value with E_OK */
  LenReturnValue = E_OK;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (Mcu_GblDriverStatus == MCU_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_SID,
                                                               MCU_E_UNINIT);
    /* Set the return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }

  /* Report to DET, if RamSetting Id is out of range */
  if (RamSection >= MCU_MAX_RAMSETTING)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_SID,
                                                     MCU_E_PARAM_RAMSECTION);
    /* Set the return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* Do nothing */
  }

  /* Check if any development error occurred */
  if (LenReturnValue == E_OK)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* Get the pointer to the RAM structure */
    LpRamSetting = &Mcu_GstRamSetting[RamSection];

    /* Get the start address of the RAM section */
    LpRamStartAddress = LpRamSetting->pRamStartAddress;
    /* Get the size of RAM section */
    LulNoOfByte = LpRamSetting->ulRamSectionSize;
    /* Get initial value */
    LucDataByte = LpRamSetting->ucRamInitValue;

    while (LulNoOfByte != ((uint32)MCU_ZERO))
    {
      /* Initialize RAM area with the value */
      *LpRamStartAddress = LucDataByte;

      /* MISRA Rule         : 17.4                             */
      /* Message            : Increment or decrement operation */
      /*                      performed on pointer.            */
      /* Reason             : Increment operator is used to    */
      /*                      achieve better throughput.       */
      /* Verification       : However, part of the code is     */
      /*                      verified manually and it is not  */
      /*                      having any impact.               */

      LpRamStartAddress++;
      LulNoOfByte--;
    }
  }
  return (LenReturnValue);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_InitClock
**
** Service ID         : 0x02
**
** Description        : This service initializes the PLL and other MCU specific
**                      clock options.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : ClockSetting - Id for Clock setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Remarks            : Global Variable:
**                      Mcu_GblDriverStatus, Mcu_GpConfigPtr
**                      Mcu_GpClockSetting, Mcu_GpCkscRegOffset,
**                      Mcu_GpCkscRegValue
**
** Function Invoked   : Det_ReportError
**                      Dem_ReportErrorStatus
**
** Registers Used     : MOSCC, MOSCST, MOSCE, MOSCS, SOSCST, SOSCE, SOSCS,
**                      ROSCS, ROSCE, PLLS0, PLLC0, PLLST0, PLLE0, PLLS1, PLLC1,
**                      PLLST1, PLLE1, PLLS2, PLLC2, PLLST2, PLLE2, PROTCMD0,
**                      PROTS0, PROTCMD1, PROTS1, PROTCMD2, PROTS2, FOUTDIV,
**                      CLMA0CTL1, CLMA0CMPH, CLMA0CMPL, CLMA0PCMD, CLMA0CTL0,
**                      CLMA0PS, CLMA2CTL1, CLMA2CMPH, CLMA2CMPL, CLMA2PCMD,
**                      CLMA2CTL0, CLMA2PS, CKSC
**
*******************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitClock
(Mcu_ClockType ClockSetting)
{
  #if (MCU_MAINOSC_ENABLE == STD_ON)
  uint32 LulMainClockStabCount;
  #endif

  #if (MCU_SUBOSC_ENABLE == STD_ON)
  uint32 LulSubClockStabCount;
  #endif
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) Lpval;

  /* Global pointer to CKSC register offset */
  P2CONST(uint16, AUTOMATIC, MCU_CONFIG_CONST) LpCkscRegOffset;

  /* Global pointer to CKSC register value */
  P2CONST(uint32, AUTOMATIC, MCU_CONFIG_CONST) LpCkscRegValue;


  Std_ReturnType LenReturnValue = E_OK;
  uint8 LucClockSettingIndex = MCU_ZERO;
  uint8 LucNoOfCkscReg;
  uint8 LucSelectedSrcClk;
  uint8 LucCount = MCU_FIVE;
  boolean LblDemReported = MCU_FALSE;
  #if (MCU_SUBOSC_ENABLE == STD_ON)
  LulSubClockStabCount = MCU_CLK_SETTING_RINGOSC;
  #endif

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (Mcu_GblDriverStatus == MCU_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITCLOCK_SID,
                                                                MCU_E_UNINIT);
    /* Set the return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  /* Report to DET, if clock setting Id is invalid */
  else
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    /* Get the pointer to the Clock setting structure  */
    LucClockSettingIndex = *((Mcu_GpConfigPtr->pClkSettingIndexMap)
                                                              + ClockSetting);
    if ((ClockSetting >= MCU_MAX_CLK_SET) ||
                                (LucClockSettingIndex == MCU_INVALID_SETTING))
    {
      /* Report to DET */
      Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITCLOCK_SID,
                                                          MCU_E_PARAM_CLOCK);
      /* Set the return value to E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }
  }

  /* Check if any development error occurred */
  if (LenReturnValue == E_OK)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* Get the pointer to the Clock setting structure */
    #if (MCU_DEV_ERROR_DETECT == STD_OFF)
    LucClockSettingIndex = *((Mcu_GpConfigPtr->pClkSettingIndexMap)
                                                              + ClockSetting);
    #endif
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    /* Store the pointer to the configured clock structure  */
    Mcu_GpClockSetting =
    (P2CONST(Tdd_Mcu_ClockSetting, MCU_CONST, MCU_CONFIG_CONST))
                      (Mcu_GpConfigPtr->pClockSetting) + LucClockSettingIndex;

    /* Get the value of the selected source clock */
    LucSelectedSrcClk = Mcu_GpClockSetting->ucSelectedSrcClock;

    /* MISRA Rule   : 11.3                                          */
    /* Message      : A cast should not be performed between a      */
    /*                pointer type and an integral type.            */
    /* Reason       : This is to access the hardware registers      */
    /*                in the code.                                  */
    /* Verification : However, the part of the code is              */
    /*                verified manually and it is not having        */
    /*                any impact on code.                           */
    /*Disbale the FOUT divider register */
    MCU_FOUTDIV = MCU_FOUT_DISABLE_MASK;

    #if (MCU_MAINOSC_ENABLE == STD_ON)
    /* Check whether the selected clock source is main oscillator */
    if ((LucSelectedSrcClk & MCU_MAIN_OSC_SELECTED) == MCU_MAIN_OSC_SELECTED)
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */

      /* Check whether MOSC is OFF */
      if ((MCU_MOSCS & MCU_MAIN_OSC_ON) != MCU_MAIN_OSC_ON)
      {
        /* Load the value of MOSCC register */
        MCU_MOSCC = Mcu_GpClockSetting->ucMosccRegValue;

        /* Set Main Oscillator stabilization time */
        MCU_MOSCST = Mcu_GpClockSetting->ulMainOscStabTime;

        /* Enable the Main Oscillator */
        do
        {
          /* check for Main Oscilator Stop mask */
          if ((Mcu_GpClockSetting->ucSelectedSTPMK & MCU_MAIN_OSC_MASKED)
                                                      == MCU_MAIN_OSC_MASKED)
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                in the code.                                  */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            /* Writing to write enable register */
            MCU_PROTCMD2 = MCU_WRITE_DATA;
            MCU_MOSCE = MCU_LONG_WORD_FIVE;
            MCU_MOSCE = ~MCU_LONG_WORD_FIVE;
            MCU_MOSCE = MCU_LONG_WORD_FIVE;
          }
          else
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */

            /* Writing to write enable register */
            MCU_PROTCMD2 = MCU_WRITE_DATA;
            MCU_MOSCE = MCU_LONG_WORD_ONE;
            MCU_MOSCE = ~MCU_LONG_WORD_ONE;
            MCU_MOSCE = MCU_LONG_WORD_ONE;
          }
          LucCount--;
        } while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

        if (MCU_PROTS2 == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }

        /* Load the stabilization count value */
        LulMainClockStabCount = Mcu_GpConfigPtr->ulMainClockStabCount;

        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer type and an integral type.            */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
        while (((MCU_MOSCS & MCU_LONG_WORD_ONE) == MCU_LONG_WORD_ZERO) &&
                                        (LulMainClockStabCount > MCU_ZERO))
        {
          LulMainClockStabCount--;
        }

        if ((MCU_MOSCS & MCU_LONG_WORD_SEVEN) != MCU_LONG_WORD_SEVEN)
        {
          /* MainOsc failed and report production error */
          Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }
      }
    }
    #endif /* (MCU_MAINOSC_ENABLE == STD_ON) */

    /* Check whether the selected clock source is Sub oscillator and
     * the DEM error has not occurred
     */
    #if (MCU_SUBOSC_ENABLE == STD_ON)
    if ((LenReturnValue == E_OK) &&
    ((LucSelectedSrcClk & MCU_SUB_OSC_SELECTED) == MCU_SUB_OSC_SELECTED))
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Check whether SOSC is OFF */
      if ((MCU_SOSCS & MCU_SUB_OSC_ON) != MCU_SUB_OSC_ON)
      {
        /* Set Sub Oscillator stabilization time */
        MCU_SOSCST = Mcu_GpClockSetting->ulSubOscStabTime;

        LucCount = MCU_FIVE;
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer type and an integral type.            */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
        /* Enable the Sub Oscillator */
        do
        {
          /* writing to write enable register */
          MCU_PROTCMD2 = MCU_WRITE_DATA;
          /* check for Sub Oscilator Stop mask */
          if ((Mcu_GpClockSetting->ucSelectedSTPMK & MCU_SUB_OSC_MASKED)
                                                    == MCU_SUB_OSC_MASKED)
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            MCU_SOSCE = MCU_LONG_WORD_FIVE;
            MCU_SOSCE = ~MCU_LONG_WORD_FIVE;
            MCU_SOSCE = MCU_LONG_WORD_FIVE;
          }
          else
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            MCU_SOSCE = MCU_LONG_WORD_ONE;
            MCU_SOSCE = ~MCU_LONG_WORD_ONE;
            MCU_SOSCE = MCU_LONG_WORD_ONE;
          }
          LucCount--;
        }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

        if (MCU_PROTS2 == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }

        /* If CPU clock is High Ring Oscillator */
        if (ClockSetting == MCU_CLK_SETTING_RINGOSC)
        {
          /* Load the High Ring stabilization count value */
          LulSubClockStabCount = MCU_HIGH_RING_STAB_CNT;
        }
        /* If CPU clock is Main Oscillator */
        else if (ClockSetting == MCU_CLK_SETTING_MAINOSC)
        {
          /* Load the Main clock stabilization count value */
          LulSubClockStabCount = MCU_MAIN_CLK_STAB_CNT;
        }
        else
        {
          /* Load the PLL clock stabilization count value */
          LulSubClockStabCount = MCU_PLL_CLK_STAB_CNT;
        }

        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer type and an integral type.            */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
        while (((MCU_SOSCS & MCU_LONG_WORD_SEVEN) != MCU_LONG_WORD_SEVEN) &&
                    (LulSubClockStabCount > MCU_ZERO))
        {
          LulSubClockStabCount--;
        }

        if ((MCU_SOSCS & MCU_LONG_WORD_SEVEN) != MCU_LONG_WORD_SEVEN)
        {
          /* SubOsc failed and report production error */
          Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }
      }
    }
    #endif /* (MCU_SUBOSC_ENABLE == STD_ON) */

    /* Check whether the selected clock source is High speed Internal Ring
     *  Oscillator and the DEM error has not occurred
     */
    #if (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON)
    if ((LenReturnValue == E_OK) &&
      ((LucSelectedSrcClk & MCU_8MHZ_OSC_SELECTED) == MCU_8MHZ_OSC_SELECTED))
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Check whether High speed Internal Ring Oscillator is OFF */
      if ((MCU_ROSCS & MCU_RING_OSC_ON) != MCU_RING_OSC_ON)
      {
        LucCount = MCU_FIVE;
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer type and an integral type.            */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
        /* Enable the High speed Internal Ring Oscillator */
        do
        {
          /* writing to write enable register */
          MCU_PROTCMD2 = MCU_WRITE_DATA;
          /* check for High speed Internal Ring Oscillator's Stop mask */
          if ((Mcu_GpClockSetting->ucSelectedSTPMK & MCU_RING_OSC_MASKED)
                                                    == MCU_RING_OSC_MASKED)
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            MCU_ROSCE = MCU_LONG_WORD_FIVE;
            MCU_ROSCE = ~MCU_LONG_WORD_FIVE;
            MCU_ROSCE = MCU_LONG_WORD_FIVE;
          }
          else
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            MCU_ROSCE = MCU_LONG_WORD_ONE;
            MCU_ROSCE = ~MCU_LONG_WORD_ONE;
            MCU_ROSCE = MCU_LONG_WORD_ONE;
          }
          LucCount--;
        }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

        if (MCU_PROTS2 == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }
      }
      /* High speed Internal Ring Oscillator is already ON */
      else
      {
        LucCount = MCU_FIVE;
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer type and an integral type.            */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
        do
        {
          /* writing to write enable register */
          MCU_PROTCMD2 = MCU_WRITE_DATA;
          /* check for High speed Internal Ring Oscillator's Stop mask */
          if ((Mcu_GpClockSetting->ucSelectedSTPMK & MCU_RING_OSC_MASKED)
                                                    == MCU_RING_OSC_MASKED)
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            /* Enable the High speed Internal Ring Oscillator's STPMK bit  */
            MCU_ROSCE = MCU_LONG_WORD_FOUR;
            MCU_ROSCE = ~MCU_LONG_WORD_FOUR;
            MCU_ROSCE = MCU_LONG_WORD_FOUR;
          }
          else
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            /* Disable the High speed Internal Ring Oscillator's STPMK bit  */
            MCU_ROSCE = MCU_LONG_WORD_ZERO;
            MCU_ROSCE = ~MCU_LONG_WORD_ZERO;
            MCU_ROSCE = MCU_LONG_WORD_ZERO;
          }
          LucCount--;
        }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

        if (MCU_PROTS2 == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }
      }
    }
    #endif /* (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON) */
    /* Check whether the selected clock source is PLL0 and
     * the DEM error has not occurred
     */
    #if (MCU_PLL0_ENABLE == STD_ON)
    if ((LenReturnValue == E_OK) &&
    ((LucSelectedSrcClk & MCU_PLL0_CLOCK_SELECTED) == MCU_PLL0_CLOCK_SELECTED))
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Check whether PLL0 is OFF */
      if ((MCU_PLLS0 & MCU_PLL0_ON) != MCU_PLL0_ON)
      {
        /* Load the value of PLL control register PLLC0 */
        MCU_PLLC0 = Mcu_GpClockSetting->ulPLL0ControlValue;

        /* Set PLL0 stabilization time */
        MCU_PLLST0 = Mcu_GpClockSetting->ulPLL0StabTime;

        LucCount = MCU_FIVE;
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer type and an integral type.            */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
        /* Enable the PLL0 clock */
        do
        {
          /* writing to write enable register */
          MCU_PROTCMD2 = MCU_WRITE_DATA;
          /* check for PLL0 Stop mask */
          if ((Mcu_GpClockSetting->ucSelectedSTPMK & MCU_PLL0_MASKED)
                                                          == MCU_PLL0_MASKED)
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            MCU_PLLE0 = MCU_LONG_WORD_FIVE;
            MCU_PLLE0 = ~MCU_LONG_WORD_FIVE;
            MCU_PLLE0 = MCU_LONG_WORD_FIVE;
          }
          else
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            MCU_PLLE0 = MCU_LONG_WORD_ONE;
            MCU_PLLE0 = ~MCU_LONG_WORD_ONE;
            MCU_PLLE0 = MCU_LONG_WORD_ONE;
          }
          LucCount--;
        }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

        if (MCU_PROTS2 == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }
      }
    }
    #endif /* (MCU_PLL0_ENABLE == STD_ON) */

    /* Check whether the selected clock source is PLL1 and
     * the DEM error has not occurred
     */
    #if (MCU_PLL1_ENABLE == STD_ON)
    if ((LenReturnValue == E_OK) &&
    ((LucSelectedSrcClk & MCU_PLL1_CLOCK_SELECTED) == MCU_PLL1_CLOCK_SELECTED))
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Check whether PLL1 is OFF */
      if ((MCU_PLLS1 & MCU_PLL1_ON) != MCU_PLL1_ON)
      {
        /* Load the value of PLL control register PLLC1 */
        MCU_PLLC1 = Mcu_GpClockSetting->ulPLL1ControlValue;

        /* Set PLL1 stabilization time */
        MCU_PLLST1 = Mcu_GpClockSetting->ulPLL1StabTime;

        LucCount = MCU_FIVE;
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer type and an integral type.            */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */

        /* Enable the PLL1 clock */
        do
        {
          /* writing to write enable register */
          MCU_PROTCMD2 = MCU_WRITE_DATA;
          /* check for PLL1 Stop mask */
          if ((Mcu_GpClockSetting->ucSelectedSTPMK & MCU_PLL1_MASKED)
                                                          == MCU_PLL1_MASKED)
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            MCU_PLLE1 = MCU_LONG_WORD_FIVE;
            MCU_PLLE1 = ~MCU_LONG_WORD_FIVE;
            MCU_PLLE1 = MCU_LONG_WORD_FIVE;
          }
          else
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            MCU_PLLE1 = MCU_LONG_WORD_ONE;
            MCU_PLLE1 = ~MCU_LONG_WORD_ONE;
            MCU_PLLE1 = MCU_LONG_WORD_ONE;
          }
          LucCount--;
        }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

        if (MCU_PROTS2 == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }
      }
    }
    #endif /* (MCU_PLL1_ENABLE == STD_ON) */

    /* Check whether the selected clock source is PLL2 and
     * the DEM error has not occurred
     */
    #if (MCU_PLL2_ENABLE == STD_ON)
    if ((LenReturnValue == E_OK) &&
    ((LucSelectedSrcClk & MCU_PLL2_CLOCK_SELECTED) == MCU_PLL2_CLOCK_SELECTED))
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Check whether PLL2 is OFF */
      if ((MCU_PLLS2 & MCU_PLL2_ON) != MCU_PLL2_ON)
      {
        /* Load the value of PLL control register PLLC2 */
        MCU_PLLC2 = Mcu_GpClockSetting->ulPLL2ControlValue;

        /* Set PLL2 stabilization time */
        MCU_PLLST2 = Mcu_GpClockSetting->ulPLL2StabTime;

        LucCount = MCU_FIVE;
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer type and an integral type.            */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
        /* Enable the PLL2 clock */
        do
        {
          /* writing to write enable register */
          MCU_PROTCMD2 = MCU_WRITE_DATA;
          /* check for PLL2 Stop mask */
          if ((Mcu_GpClockSetting->ucSelectedSTPMK & MCU_PLL2_MASKED)
                                                            == MCU_PLL2_MASKED)
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            MCU_PLLE2 = MCU_LONG_WORD_FIVE;
            MCU_PLLE2 = ~MCU_LONG_WORD_FIVE;
            MCU_PLLE2 = MCU_LONG_WORD_FIVE;
          }
          else
          {
            /* MISRA Rule   : 11.3                                          */
            /* Message      : A cast should not be performed between a      */
            /*                pointer type and an integral type.            */
            /* Reason       : This is to access the hardware registers      */
            /*                 in the code.                                 */
            /* Verification : However, the part of the code is              */
            /*                verified manually and it is not having        */
            /*                any impact on code.                           */
            MCU_PLLE2 = MCU_LONG_WORD_ONE;
            MCU_PLLE2 = ~MCU_LONG_WORD_ONE;
            MCU_PLLE2 = MCU_LONG_WORD_ONE;
          }
          LucCount--;
        }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

        if (MCU_PROTS2 == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }
      }
    }
    #endif /* (MCU_PLL2_ENABLE == STD_ON) */

    /* Load CKSC registers if DEM error has not occurred */
    if (LenReturnValue == E_OK)
    {
      /* Get the number of CKSC registers configured for Iso0*/
      LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfIso0CkscReg;

      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Get pointer to the array of CKSC registers offset */
      LpCkscRegOffset = Mcu_GpCkscRegOffset +
                              (Mcu_GpClockSetting->ucCkscIndexOffset);

      /* Get pointer to the array of CKSC registers values */
      LpCkscRegValue = Mcu_GpCkscRegValue +
                              (Mcu_GpClockSetting->ucCkscIndexOffset);

      while (LucNoOfCkscReg > MCU_ZERO)
      {
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                type.                                         */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */

        /* Get the pointer to the configured Iso0 domain CKSC register address*/
        Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                            (MCU_CKSC000_BASE_ADDRESS + (*LpCkscRegOffset));

        LucCount = MCU_FIVE;
        do
        {
          /* MISRA Rule   : 11.3                                          */
          /* Message      : A cast should not be performed between a      */
          /*                pointer type and an integral type.            */
          /* Reason       : This is to access the hardware registers      */
          /*                 in the code.                                 */
          /* Verification : However, the part of the code is              */
          /*                verified manually and it is not having        */
          /*                any impact on code.                           */
          MCU_PROTCMD0 = MCU_WRITE_DATA;

          *Lpval = (*LpCkscRegValue);
          *Lpval = ~(*LpCkscRegValue);
          *Lpval = (*LpCkscRegValue);
          LucCount--;
        }while ((LucCount > MCU_ZERO) && (MCU_PROTS0 == MCU_ONE));

        if (MCU_PROTS0 == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }
        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */
        LpCkscRegOffset++;
        LpCkscRegValue++;

        /* Decrement number of CKSC registers */
        LucNoOfCkscReg--;
      }

      /* Get the number of CKSC registers configured for Iso1 */
      LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfIso1CkscReg;

      while (LucNoOfCkscReg > MCU_ZERO)
      {
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                  type.                                       */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */

        /* Get the pointer to the configured Iso1 domain CKSC register
        address */
        Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                              (MCU_CKSC000_BASE_ADDRESS + (*LpCkscRegOffset));

        LucCount = MCU_FIVE;
        do
        {
          MCU_PROTCMD1 = MCU_WRITE_DATA;

          *Lpval = (*LpCkscRegValue);
          *Lpval = ~(*LpCkscRegValue);
          *Lpval = (*LpCkscRegValue);
          LucCount--;
        }while ((LucCount > MCU_ZERO) && (MCU_PROTS1 == MCU_ONE));

        if (MCU_PROTS1 == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }
        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */
        LpCkscRegOffset++;
        LpCkscRegValue++;

        /* Decrement number of CKSC registers */
        LucNoOfCkscReg--;
      }

      /* Get the number of CKSC registers configured in Awo */
      LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfAwoCkscReg;

      while (LucNoOfCkscReg > MCU_ZERO)
      {
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                  type.                                       */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */

        /* Get the pointer to the configured Awo domain CKSC register
         * address
         */
        Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                               (MCU_CKSC000_BASE_ADDRESS + (*LpCkscRegOffset));
        LucCount = MCU_FIVE;
        do
        {
          MCU_PROTCMD2 = MCU_WRITE_DATA;

          *Lpval = (*LpCkscRegValue);
          *Lpval = ~(*LpCkscRegValue);
          *Lpval = (*LpCkscRegValue);
          LucCount--;
        }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

        if (MCU_PROTS2 == MCU_ONE)
        {
          /* Writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LenReturnValue = E_NOT_OK;
        }

        /* Increment pointers to CKSC registers offset and values */
        LpCkscRegOffset++;
        LpCkscRegValue++;

        /* Decrement number of CKSC registers */
        LucNoOfCkscReg--;
      }
    }

    /* Load CKSC registers if DEM error has not occurred */
    if (LenReturnValue == E_OK)
    {
      /* Get the number of CKSC registers configured for Iso0*/
      LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfIso0CkscReg;

      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */

      /* Get pointer to the array of CKSC registers offset */
      LpCkscRegOffset = Mcu_GpCkscRegOffset +
                              (Mcu_GpClockSetting->ucCkscIndexOffset);

      /* Get pointer to the array of CKSC registers values */
      LpCkscRegValue = Mcu_GpCkscRegValue +
                              (Mcu_GpClockSetting->ucCkscIndexOffset);

      while ((LucNoOfCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
      {
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                type.                                         */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */

        /* Get the pointer to the configured Iso0 domain CKSC register address*/
        Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                            (MCU_CKSC000_BASE_ADDRESS + (*LpCkscRegOffset));

        LucCount = MCU_FIVE;

        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */
        /*check for activation of clock domain in CKCSTAT_mn register*/
        while (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
                    != MCU_LONG_WORD_ONE) && (LucCount > MCU_ZERO))
        {
          LucCount--;
        }
        /* Generate DEM error for Illegal clock ID*/
        if (((*(Lpval + MCU_LONG_WORD_ONE)  & MCU_LONG_WORD_ONE ) !=
              MCU_LONG_WORD_ONE) &&
            ((*(Lpval + MCU_LONG_WORD_ONE)  & MCU_CKSC_MASK_VALUE ) !=
              (*LpCkscRegValue & MCU_CKSC_MASK_VALUE)))
        {
          Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                DEM_EVENT_STATUS_FAILED);
          LblDemReported = MCU_TRUE;
        }
        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */
        /* Increment pointers to CKSC registers offset and values */
        else
        {
          LpCkscRegOffset++;
          LpCkscRegValue++;

          /* Decrement number of CKSC registers */
          LucNoOfCkscReg--;
        }
      }

      /* Get the number of CKSC registers configured for Iso1 */
      LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfIso1CkscReg;

      while ((LucNoOfCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
      {
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                  type.                                       */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */

        /* Get the pointer to the configured Iso1 domain CKSC register
        address */
        Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                              (MCU_CKSC000_BASE_ADDRESS + (*LpCkscRegOffset));

        LucCount = MCU_FIVE;
        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */
        /*check for activation of clock domain in CKCSTAT_mn register*/
        while (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
                  != MCU_LONG_WORD_ONE) && (LucCount > MCU_ZERO))
        {
          LucCount--;
        }
        /* Generate DEM error for Illegal clock ID*/
       if (((*(Lpval + MCU_LONG_WORD_ONE)  & MCU_LONG_WORD_ONE ) !=
            MCU_LONG_WORD_ONE) &&
            ((*(Lpval + MCU_LONG_WORD_ONE)  & MCU_CKSC_MASK_VALUE ) !=
              (*LpCkscRegValue & MCU_CKSC_MASK_VALUE)))
        {
          Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                DEM_EVENT_STATUS_FAILED);
          LblDemReported = MCU_TRUE;
        }
        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */

        /* Increment pointers to CKSC registers offset and values */
        else
        {
          LpCkscRegOffset++;
          LpCkscRegValue++;

          /* Decrement number of CKSC registers */
          LucNoOfCkscReg--;
        }
      }

      /* Get the number of CKSC registers configured in Awo */
      LucNoOfCkscReg = Mcu_GpClockSetting->ucNoOfAwoCkscReg;

      while ((LucNoOfCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
      {
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                  type.                                       */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */

        /* Get the pointer to the configured Awo domain CKSC register
         * address
         */
        Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                               (MCU_CKSC000_BASE_ADDRESS + (*LpCkscRegOffset));

        LucCount = MCU_FIVE;

        /* MISRA Rule         : 17.4                            */
        /* Message            : Performing pointer arithmetic.  */
        /* Reason             : For code optimization.          */
        /* Verification       : However, part of the code is    */
        /*                      verified manually and it is not */
        /*                      having any impact.              */
        /*check for activation of clock domain in CKCSTAT_mn register*/
        while (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
                    != MCU_LONG_WORD_ONE) && (LucCount > MCU_ZERO))
        {
          LucCount--;
        }
        /* Generate DEM error for Illegal clock ID*/
        if (((*(Lpval + MCU_LONG_WORD_ONE)  & MCU_LONG_WORD_ONE ) !=
            MCU_LONG_WORD_ONE) &&
            ((*(Lpval + MCU_LONG_WORD_ONE)  & MCU_CKSC_MASK_VALUE ) !=
            (*LpCkscRegValue & MCU_CKSC_MASK_VALUE)))
        {
          Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                DEM_EVENT_STATUS_FAILED);
          LblDemReported = MCU_TRUE;
        }

        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */
        else
        {
          /* Increment pointers to CKSC registers offset and values */
          LpCkscRegOffset++;
          LpCkscRegValue++;

          /* Decrement number of CKSC registers */
          LucNoOfCkscReg--;
        }
      }
    }
    /* MISRA Rule   : 11.3                                             */
    /* Message      : A cast should not be performed between a         */
    /*                pointer type and an integral type.               */
    /* Reason       : This is to access the hardware registers in the  */
    /*                code.                                            */
    /* Verification : However, the part of the code is                 */
    /*                verified manually and it is not having           */
    /*                any impact on code.                              */
    /* Get the dividing factor value for FOUT */
    MCU_FOUTDIV = Mcu_GpClockSetting->usFoutDivReg;

    /* Initializing static variables */
    Mcu_GulCkscA07Val = MCU_CKSCAO7_REGISTER;

    /* Check if CLMA0 is enabled */
    if ((LblDemReported == MCU_FALSE) && (((Mcu_GpConfigPtr->ucCLMEnable) &
              MCU_CLMA0_ENABLE) == MCU_CLMA0_ENABLE))
    {
      /* Check if Clock monitor is disabled */
      if ((MCU_CLMA0CTL0 & MCU_ONE) == MCU_ZERO)
      {
        if (((Mcu_GpConfigPtr->ucCLMOutputSignal) & MCU_CLMA0_ENABLE)
                      == MCU_CLMA0_ENABLE)
        {
          /* Load clock CLMA0 control register 1 with Interrupt request value */
          MCU_CLMA0CTL1 = MCU_ONE;
        }
        else
        {
          /* Load clock CLMA0 control register 1 with Reset request value */
          MCU_CLMA0CTL1 = MCU_ZERO;
        }

        /* MISRA Rule   : 11.3                                             */
        /* Message      : A cast should not be performed between a         */
        /*                pointer type and an integral type.               */
        /* Reason       : This is to access the hardware registers in the  */
        /*                code.                                            */
        /* Verification : However, the part of the code is                 */
        /*                verified manually and it is not having           */
        /*                any impact on code.                              */
        /* Initialize compare registers */
        /* Compare High */
        MCU_CLMA0CMPH = Mcu_GpConfigPtr->usCLMA0CMPH;
        /* Compare Low */
        MCU_CLMA0CMPL = Mcu_GpConfigPtr->usCLMA0CMPL;

        LucCount = MCU_FIVE;
        do
        {
          /* Write the write enable register */
          MCU_CLMA0PCMD = MCU_WRITE_DATA;

          /* MISRA Rule   : 11.3                                             */
          /* Message      : A cast should not be performed between a         */
          /*                pointer type and an integral type.               */
          /* Reason       : This is to access the hardware registers in the  */
          /*                code.                                            */
          /* Verification : However, the part of the code is                 */
          /*                verified manually and it is not having           */
          /*                any impact on code.                              */

          /* Load clock CLMA0 control register 0 with value one in special
          sequence */
          MCU_CLMA0CTL0 = MCU_ONE;
          MCU_CLMA0CTL0 = MCU_INVERTED_ONE;
          MCU_CLMA0CTL0 = MCU_ONE;

          LucCount--;
        }while ((LucCount > MCU_ZERO) && (MCU_CLMA0PS == MCU_ONE));

        if (MCU_CLMA0PS == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LblDemReported = MCU_TRUE;
        }
      }
    }

    /* MISRA Rule   : 11.3                                          */
    /* Message      : A cast should not be performed between a      */
    /*                pointer type and an integral type.            */
    /* Reason       : This is to access the hardware registers      */
    /*                 in the code.                                 */
    /* Verification : However, the part of the code is              */
    /*                verified manually and it is not having        */
    /*                any impact on code.                           */
    /* Check if CLMA2 is enabled */
    if ((LblDemReported == MCU_FALSE) &&
    (((Mcu_GpConfigPtr->ucCLMEnable) & MCU_CLMA2_ENABLE) == MCU_CLMA2_ENABLE))
    {
      /* Check if Clock monitor is disabled */
      if ((MCU_CLMA2CTL0 & MCU_ONE) == MCU_ZERO)
      {
        if (((Mcu_GpConfigPtr->ucCLMOutputSignal) & MCU_CLMA2_ENABLE)
                      == MCU_CLMA2_ENABLE)
        {
          /* Load clock CLMA2 control register 1 with Interrupt request value */
          MCU_CLMA2CTL1 = MCU_ONE;
        }
        else
        {
          /* Load clock CLMA2 control register 1 with Reset request value */
          MCU_CLMA2CTL1 = MCU_ZERO;
        }
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                  type.                                       */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
        /* Initialize compare registers */
        /* Compare High */
        MCU_CLMA2CMPH = MCU_CLMA2_CMPH;
        /* Compare Low */
        MCU_CLMA2CMPL = MCU_CLMA2_CMPL;

        LucCount = MCU_FIVE;
        do
        {
          /* Write the write enable register */
          MCU_CLMA2PCMD = MCU_WRITE_DATA;

          /* MISRA Rule   : 11.3                                             */
          /* Message      : A cast should not be performed between a         */
          /*                pointer type and an integral type.               */
          /* Reason       : This is to access the hardware registers in the  */
          /*                code.                                            */
          /* Verification : However, the part of the code is                 */
          /*                verified manually and it is not having           */
          /*                any impact on code.                              */

          /* Load clock CLMA2 control register 0 with value one in special
           * sequence
           */
          MCU_CLMA2CTL0 = MCU_ONE;
          MCU_CLMA2CTL0 = MCU_INVERTED_ONE;
          MCU_CLMA2CTL0 = MCU_ONE;
          LucCount--;
          /* MISRA Rule   : 11.3                                          */
          /* Message      : A cast should not be performed between a      */
          /*                pointer to a volatile object and an integral  */
          /*                  type.                                       */
          /* Reason       : This is to access the hardware registers      */
          /*                 in the code.                                 */
          /* Verification : However, the part of the code is              */
          /*                verified manually and it is not having        */
          /*                any impact on code.                           */
        }while ((LucCount > MCU_ZERO) && (MCU_CLMA2PS == MCU_ONE));

        if (MCU_CLMA2PS == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
          LblDemReported = MCU_TRUE;
        }
      }
    }
  }
  return LenReturnValue;
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_DistributePllClock
**
** Service ID         : 0x03
**
** Description        : This service activates the PLL clock to the MCU clock
**                      distribution.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : MCU Driver component must be initialized
**
** Remarks            : Global Variable:
**                      Mcu_GblDriverStatus, Mcu_GpConfigPtr
**                      Mcu_GpClockSetting, Mcu_GpCkscRegOffset,
**                      Mcu_GpCkscRegValue
**
** Function Invoked   : Mcu_GetPllStatus, Det_ReportError
**                      Dem_ReportErrorStatus
**
** Registers Used     : PROTCMD0, PROTS0, PROTCMD1, PROTS1, PROTCMD2, PROTS2,
**                      CLMA3CTL1, CLMA3CMPH, CLMA3CMPL, CLMA3PCMD, CLMA3CTL0,
**                      CLMA3PS, CKSC
**
*******************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, MCU_PUBLIC_CODE) Mcu_DistributePllClock (void)
{
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  Mcu_PllStatusType LddPllLockStatus;
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */

  /* pointer to CKSC register offset */
  P2CONST(uint16, AUTOMATIC, MCU_CONFIG_CONST) LpPllCkscRegOffset;
  /* pointer to CKSC register value */
  P2CONST(uint32, AUTOMATIC, MCU_CONFIG_CONST) LpPllCkscRegValue;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) Lpval;
  uint8 LucNoOfPllCkscReg;
  uint8 LucCount = MCU_FIVE;
  boolean LblDemReported = MCU_FALSE;


  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  LddPllLockStatus = Mcu_GetPllStatus();

  /* Report to DET, if module is not initialized */
  if (Mcu_GblDriverStatus == MCU_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_DISTRIBUTEPLLCLOCK_SID,
                                                                MCU_E_UNINIT);
  }
  else
  {
    /* Do nothing */
  }

  /* Get the PLL status and if PLL status is 'UNLOCKED', report to DET */
  if (LddPllLockStatus == MCU_PLL_UNLOCKED)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                        MCU_DISTRIBUTEPLLCLOCK_SID, MCU_E_PLL_NOT_LOCKED);
  }
  /* If no DET error, continue */
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* Get the number of PLL CKSC registers configured for Iso0 */
    LucNoOfPllCkscReg = Mcu_GpClockSetting->ucNoOfPllIso0CkscReg;

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    /* Get pointer to the array of CKSC registers offset */
    LpPllCkscRegOffset = Mcu_GpCkscRegOffset +
                           (Mcu_GpClockSetting->ucCkscPllIndexOffset);

    /* Get pointer to the array of CKSC registers values */
    LpPllCkscRegValue = Mcu_GpCkscRegValue +
                           (Mcu_GpClockSetting->ucCkscPllIndexOffset);

    while ((LucNoOfPllCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer to a volatile object and an integral  */
      /*                  type.                                       */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Get the pointer to the configured Iso0 domain pll
      CKSC register address */
      Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                       (MCU_CKSC000_BASE_ADDRESS + (*LpPllCkscRegOffset));
      do
      {
        MCU_PROTCMD0 = MCU_WRITE_DATA;

        *Lpval = (*LpPllCkscRegValue);
        *Lpval = ~(*LpPllCkscRegValue);
        *Lpval = (*LpPllCkscRegValue);
        LucCount--;
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                  type.                                       */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
      }while ((LucCount > MCU_ZERO) && (MCU_PROTS0 == MCU_ONE));

      if (MCU_PROTS0 == MCU_ONE)
      {
        /* writing to write-protected register failed and
         * report production error
         */
        Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }

      LucCount = MCU_FIVE;
      /* MISRA Rule         : 17.4                             */
      /* Message            : Increment or decrement operation */
      /*                      performed on pointer.            */
      /* Reason             : Increment operator is used to    */
      /*                      achieve better throughput.       */
      /* Verification       : However, part of the code is     */
      /*                      verified manually and it is not  */
      /*                      having any impact.               */
      /* Increment pointers to CKSC registers offset and values */
      LpPllCkscRegOffset++;
      LpPllCkscRegValue++;

      /* Decrement number of CKSC registers */
      LucNoOfPllCkscReg--;
    }

    /* Get the number of Pll CKSC registers configured for Iso1 */
    LucNoOfPllCkscReg = Mcu_GpClockSetting->ucNoOfPllIso1CkscReg;

    while ((LucNoOfPllCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
    {
      /* MISRA Rule   : 11.3                                         */
      /* Message      : A cast should not be performed between a      */
      /*                pointer to a volatile object and an integral  */
      /*                  type.                                       */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Get the pointer to the configured Iso1 domain pll
       * CKSC register address
       */
      Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                          (MCU_CKSC000_BASE_ADDRESS + (*LpPllCkscRegOffset));

      do
      {
        MCU_PROTCMD1 = MCU_WRITE_DATA;

        *Lpval = (*LpPllCkscRegValue);
        *Lpval = ~(*LpPllCkscRegValue);
        *Lpval = (*LpPllCkscRegValue);
        LucCount--;
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                  type.                                       */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
      }while ((LucCount > MCU_ZERO) && (MCU_PROTS1 == MCU_ONE));

      if (MCU_PROTS1 == MCU_ONE)
      {
        /* writing to write-protected register failed and
         * report production error
         */
        Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }

      LucCount = MCU_FIVE;
      /* MISRA Rule         : 17.4                              */
      /* Message            : Increment or decrement operation  */
      /*                      performed on pointer.             */
      /* Reason             : Increment operator is used to     */
      /*                      achieve better throughput.        */
      /* Verification       : However, part of the code is      */
      /*                      verified manually and it is not   */
      /*                      having any impact.                */
      /* Increment pointers to CKSC registers offset and values */
      LpPllCkscRegOffset++;
      LpPllCkscRegValue++;

      /* Decrement number of CKSC registers */
      LucNoOfPllCkscReg--;
    }

    /* Get the number of Pll CKSC registers configured for Awo */
    LucNoOfPllCkscReg = Mcu_GpClockSetting->ucNoOfPllAwoCkscReg;

    while ((LucNoOfPllCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer to a volatile object and an integral  */
      /*                  type.                                       */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */

      /* Get the pointer to the configured Awo domain pll
       * CKSC register address
       */
      Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                          (MCU_CKSC000_BASE_ADDRESS + (*LpPllCkscRegOffset));

      do
      {
        MCU_PROTCMD2 = MCU_WRITE_DATA;

        *Lpval = (*LpPllCkscRegValue);
        *Lpval = ~(*LpPllCkscRegValue);
        *Lpval = (*LpPllCkscRegValue);
        LucCount--;
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                  type.                                       */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
      }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

      if (MCU_PROTS2 == MCU_ONE)
      {
        /* writing to write-protected register failed and
         * report production error
         */
        Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }

      LucCount = MCU_FIVE;
      /* MISRA Rule         : 17.4                             */
      /* Message            : Increment or decrement operation */
      /*                      performed on pointer.            */
      /* Reason             : Increment operator is used to    */
      /*                      achieve better throughput.       */
      /* Verification       : However, part of the code is     */
      /*                      verified manually and it is not  */
      /*                      having any impact.               */
      /* Increment pointers to CKSC registers offset and values */
      LpPllCkscRegOffset++;
      LpPllCkscRegValue++;

      /* Decrement number of CKSC registers */
      LucNoOfPllCkscReg--;
    }

    /* Get the number of PLL CKSC registers configured for Iso0 */
    LucNoOfPllCkscReg = Mcu_GpClockSetting->ucNoOfPllIso0CkscReg;

    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    /* Get pointer to the array of CKSC registers offset */
    LpPllCkscRegOffset = Mcu_GpCkscRegOffset +
                           (Mcu_GpClockSetting->ucCkscPllIndexOffset);

    /* Get pointer to the array of CKSC registers values */
    LpPllCkscRegValue = Mcu_GpCkscRegValue +
                           (Mcu_GpClockSetting->ucCkscPllIndexOffset);

    while ((LucNoOfPllCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer to a volatile object and an integral  */
      /*                  type.                                       */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Get the pointer to the configured Iso0 domain pll
      CKSC register address */
      Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                       (MCU_CKSC000_BASE_ADDRESS + (*LpPllCkscRegOffset));

      LucCount = MCU_FIVE;
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */
      /*check for activation of clock domain in CKCSTAT_mn register*/
      while (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
                   != MCU_LONG_WORD_ONE) && (LucCount > MCU_ZERO))
      {
        LucCount--;
      }

      /* Generate DEM error for Illegal clock ID*/
      if (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
                   != MCU_LONG_WORD_ONE) &&
         ((*(Lpval + MCU_LONG_WORD_ONE) & MCU_CKSC_MASK_VALUE) !=
                   (*LpPllCkscRegValue & MCU_CKSC_MASK_VALUE)))
      {
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }
      else
      {
        LucCount = MCU_FIVE;
        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */
        /* Increment pointers to CKSC registers offset and values */
        LpPllCkscRegOffset++;
        LpPllCkscRegValue++;

        /* Decrement number of CKSC registers */
        LucNoOfPllCkscReg--;
      }
    }

    /* Get the number of Pll CKSC registers configured for Iso1 */
    LucNoOfPllCkscReg = Mcu_GpClockSetting->ucNoOfPllIso1CkscReg;

    while ((LucNoOfPllCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
    {
      /* MISRA Rule   : 11.3                                         */
      /* Message      : A cast should not be performed between a      */
      /*                pointer to a volatile object and an integral  */
      /*                  type.                                       */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Get the pointer to the configured Iso1 domain pll
       * CKSC register address
       */
      Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                          (MCU_CKSC000_BASE_ADDRESS + (*LpPllCkscRegOffset));

      LucCount = MCU_FIVE;
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */
      /*check for activation of clock domain in CKCSTAT_mn register*/
      while (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
                  != MCU_LONG_WORD_ONE) && (LucCount > MCU_ZERO))
      {
        LucCount--;
      }
      /* Generate DEM error for Illegal clock ID*/
      if (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
                 != MCU_LONG_WORD_ONE) &&
          ((*(Lpval + MCU_LONG_WORD_ONE) & MCU_CKSC_MASK_VALUE) !=
                 (*LpPllCkscRegValue & MCU_CKSC_MASK_VALUE)))
      {
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }
      else
      {
        LucCount = MCU_FIVE;
        /* MISRA Rule         : 17.4                              */
        /* Message            : Increment or decrement operation  */
        /*                      performed on pointer.             */
        /* Reason             : Increment operator is used to     */
        /*                      achieve better throughput.        */
        /* Verification       : However, part of the code is      */
        /*                      verified manually and it is not   */
        /*                      having any impact.                */
        /* Increment pointers to CKSC registers offset and values */
        LpPllCkscRegOffset++;
        LpPllCkscRegValue++;

        /* Decrement number of CKSC registers */
        LucNoOfPllCkscReg--;
      }
    }

    /* Get the number of Pll CKSC registers configured for Awo */
    LucNoOfPllCkscReg = Mcu_GpClockSetting->ucNoOfPllAwoCkscReg;

    while ((LucNoOfPllCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
    {
      LucCount = MCU_FIVE;

      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer to a volatile object and an integral  */
      /*                  type.                                       */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Get the pointer to the configured AWo domain pll
       * CKSC register address
       */
      Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
                          (MCU_CKSC000_BASE_ADDRESS + (*LpPllCkscRegOffset));
      /* MISRA Rule         : 17.4                            */
      /* Message            : Performing pointer arithmetic.  */
      /* Reason             : For code optimization.          */
      /* Verification       : However, part of the code is    */
      /*                      verified manually and it is not */
      /*                      having any impact.              */
      /*check for activation of clock domain in CKCSTAT_mn register*/
      while (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
                != MCU_LONG_WORD_ONE) && (LucCount > MCU_ZERO))
      {
        LucCount--;
      }
      /* Generate DEM error for Illegal clock ID*/
      if (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
                 != MCU_LONG_WORD_ONE) &&
            ((*(Lpval+MCU_LONG_WORD_ONE) & MCU_CKSC_MASK_VALUE) !=
                 (*LpPllCkscRegValue & MCU_CKSC_MASK_VALUE)))
      {
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }
      else
      {
        LucCount = MCU_FIVE;
        /* MISRA Rule         : 17.4                             */
        /* Message            : Increment or decrement operation */
        /*                      performed on pointer.            */
        /* Reason             : Increment operator is used to    */
        /*                      achieve better throughput.       */
        /* Verification       : However, part of the code is     */
        /*                      verified manually and it is not  */
        /*                      having any impact.               */
        /* Increment pointers to CKSC registers offset and values */
        LpPllCkscRegOffset++;
        LpPllCkscRegValue++;

        /* Decrement number of CKSC registers */
        LucNoOfPllCkscReg--;
      }
    }
    /* MISRA Rule   : 11.3                                          */
    /* Message      : A cast should not be performed between a      */
    /*                pointer type and an integral type.            */
    /* Reason       : This is to access the hardware registers      */
    /*                 in the code.                                 */
    /* Verification : However, the part of the code is              */
    /*                verified manually and it is not having        */
    /*                any impact on code.                           */
    /* Check if CLMA3 is enabled */
    if (((Mcu_GpConfigPtr->ucCLMEnable) & MCU_CLMA3_ENABLE) == MCU_CLMA3_ENABLE)
    {
      /* Check if Clock monitor is disabled */
      if ((MCU_CLMA3CTL0 & MCU_ONE) == MCU_ZERO)
      {
        if (((Mcu_GpConfigPtr->ucCLMOutputSignal) & MCU_CLMA3_ENABLE)
                      == MCU_CLMA3_ENABLE)
        {
          /* Load clock CLMA3 control register 1 with Interrupt request value */
          MCU_CLMA3CTL1 = MCU_ONE;
        }
        else
        {
          /* Load clock CLMA3 control register 1 with Reset request value */
          MCU_CLMA3CTL1 = MCU_ZERO;
        }

        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer to a volatile object and an integral  */
        /*                  type.                                       */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */

        /* Initialize compare registers */
        /* Compare High */
        MCU_CLMA3CMPH = Mcu_GpConfigPtr->usCLMA3CMPH;
        /* Compare Low */
        MCU_CLMA3CMPL = Mcu_GpConfigPtr->usCLMA3CMPL;

        LucCount = MCU_FIVE;

        do
        {
          /* Write the write enable register */
          MCU_CLMA3PCMD = MCU_WRITE_DATA;

          /* MISRA Rule   : 11.3                                             */
          /* Message      : A cast should not be performed between a         */
          /*                pointer type and an integral type.               */
          /* Reason       : This is to access the hardware registers in the  */
          /*                code.                                            */
          /* Verification : However, the part of the code is                 */
          /*                verified manually and it is not having           */
          /*                any impact on code.                              */

          /* Load clock CLMA3 control register 0 with value one in special
             sequence */
          MCU_CLMA3CTL0 = MCU_ONE;
          MCU_CLMA3CTL0 = MCU_INVERTED_ONE;
          MCU_CLMA3CTL0 = MCU_ONE;

          LucCount--;
          /* MISRA Rule   : 11.3                                          */
          /* Message      : A cast should not be performed between a      */
          /*                pointer to a volatile object and an integral  */
          /*                  type.                                       */
          /* Reason       : This is to access the hardware registers      */
          /*                 in the code.                                 */
          /* Verification : However, the part of the code is              */
          /*                verified manually and it is not having        */
          /*                any impact on code.                           */
        }while ((LucCount > MCU_ZERO) && (MCU_CLMA3PS == MCU_ONE));

        if (MCU_CLMA3PS == MCU_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
        }
      }
    }
  }
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_GetPllStatus
**
** Service ID         : 0x04
**
** Description        : This service provides the lock status of the PLL.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_PllStatusType
**
** Preconditions      : MCU Driver component must be initialized
**
** Remarks            : Global Variable:
**                      Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : PLLS0, PLLS1, PLLS2
**
*******************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Mcu_PllStatusType, MCU_PUBLIC_CODE) Mcu_GetPllStatus (void)
{
  Mcu_PllStatusType LddPllLockStatus = MCU_PLL_UNLOCKED;
  uint8 LucSelectedSrcClk;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (Mcu_GblDriverStatus == MCU_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETPLLSTATUS_SID,
                                                               MCU_E_UNINIT);
    /* Set PLL status to undefined */
    LddPllLockStatus = MCU_PLL_STATUS_UNDEFINED;
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* Read the value of selected source clock registers */
    LucSelectedSrcClk = Mcu_GpClockSetting->ucSelectedSrcClock;

    #if (MCU_PLL0_ENABLE == STD_ON)
    /* Check the lock status of PLL0 */
    if ((LucSelectedSrcClk & MCU_PLL0_CLOCK_SELECTED)
                                                   == MCU_PLL0_CLOCK_SELECTED)
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */

      /* Check CLKSTAB bit */
      if ((MCU_PLLS0 & MCU_PLL_CLKSTAB_MASK) == MCU_PLL_CLKSTAB_MASK)
      {
        /* PLL is locked */
        LddPllLockStatus = MCU_PLL_LOCKED;
      }
      else
      {
        /* PLL is not locked */
        LddPllLockStatus = MCU_PLL_UNLOCKED;
      }
    }
    if (LddPllLockStatus == MCU_PLL_UNLOCKED)
    {
      /* Further check of status are skipped. */
    }
    else
    #endif  /* (MCU_PLL0_ENABLE == STD_ON) */
    {
      #if (MCU_PLL1_ENABLE == STD_ON)
      /* Check the lock status of PLL1 */
      if ((LucSelectedSrcClk & MCU_PLL1_CLOCK_SELECTED)
                                              == MCU_PLL1_CLOCK_SELECTED)
      {
        /* MISRA Rule   : 11.3                                          */
        /* Message      : A cast should not be performed between a      */
        /*                pointer type and an integral type.            */
        /* Reason       : This is to access the hardware registers      */
        /*                 in the code.                                 */
        /* Verification : However, the part of the code is              */
        /*                verified manually and it is not having        */
        /*                any impact on code.                           */
        /* Check CLKSTAB bit */
          if ((MCU_PLLS1 & MCU_PLL_CLKSTAB_MASK) == MCU_PLL_CLKSTAB_MASK)
        {
          /* PLL is not locked */
          LddPllLockStatus = MCU_PLL_LOCKED;
        }
        else
        {
          /* PLL is not locked */
          LddPllLockStatus = MCU_PLL_UNLOCKED;
        }
      }
      if (LddPllLockStatus == MCU_PLL_UNLOCKED)
      {
        /* Further check of status are skipped. */
      }
      else
      #endif  /* (MCU_PLL1_ENABLE == STD_ON) */
      {
        #if (MCU_PLL2_ENABLE == STD_ON)
        /* Check the lock status of PLL2 */
        if ((LucSelectedSrcClk & MCU_PLL2_CLOCK_SELECTED)
                                                  == MCU_PLL2_CLOCK_SELECTED)
        {
          /* MISRA Rule   : 11.3                                          */
          /* Message      : A cast should not be performed between a      */
          /*                pointer type and an integral type.            */
          /* Reason       : This is to access the hardware registers      */
          /*                 in the code.                                 */
          /* Verification : However, the part of the code is              */
          /*                verified manually and it is not having        */
          /*                any impact on code.                           */
          /* Check CLKSTAB bit */
          if ((MCU_PLLS2 & MCU_PLL_CLKSTAB_MASK) == MCU_PLL_CLKSTAB_MASK)
          {
            /* PLL is not locked */
            LddPllLockStatus = MCU_PLL_LOCKED;
          }
          else
          {
            /* To avoid misra warning */
            /* At this timing, PLL is always not locked */
          }
        }
        #endif  /* (MCU_PLL2_ENABLE == STD_ON) */
      } /* (LddPllLockStatus == MCU_PLL_UNLOCKED) for PLL1 */
    } /* (LddPllLockStatus == MCU_PLL_UNLOCKED) for PLL0 */
  } /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  return(LddPllLockStatus);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_GetResetReason
**
** Service ID         : 0x05
**
** Description        : The function reads the reset type from the hardware.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_ResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Remarks            : Global Variable:
**                      Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError,
**                      Dem_ReportErrorStatus.
**
** Registers Used     : RESF, WUFCL0, WUFL0, WUFCM0, WUFM0, WUFCH0, WUFH0, PWS1,
**                      WUFCL1, WUFL1, WUFCM1, WUFM1, WUFCH1, WUFH1, RESFC
**
*******************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Mcu_ResetType, MCU_PUBLIC_CODE)Mcu_GetResetReason (void)
{
  Mcu_ResetType LddResetSource;

  uint32 LulLoopCount;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)

  /* Report to DET, if module is not initialized */
  if (Mcu_GblDriverStatus == MCU_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETRESETREASON_SID,
                                                                  MCU_E_UNINIT);
    /* Set Reset status to undefined */
    LddResetSource = MCU_RESET_UNDEFINED;
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* MISRA Rule         : 11.3                                        */
    /* Message            : A cast should not be performed between a    */
    /*                      pointer type and an integral type.          */
    /* Reason             : This is to access the hardware registers in */
    /*                      the code.                                   */
    /* Verification       : However, the part of the code is            */
    /*                      verified manually and it is not having      */
    /*                      any impact on code.                         */
    switch (MCU_RESF)
    {
      case MCU_POR  : if (((MCU_WUFH0 != MCU_LONG_WORD_ZERO) ||
                          (MCU_WUFL0 != MCU_LONG_WORD_ZERO) ||
                          (MCU_WUFM0 != MCU_LONG_WORD_ZERO)) &&
                          ((MCU_WUFH1 != MCU_LONG_WORD_ZERO) ||
                          (MCU_WUFL1 != MCU_LONG_WORD_ZERO) ||
                          (MCU_WUFM1 != MCU_LONG_WORD_ZERO)))
                      {
                        LddResetSource = MCU_AWO_ISO0_ISO1_WAKEUP;
                        LulLoopCount = MCU_LOOPCOUNT_MAX_VAL;

                        while (((MCU_PWS1 & MCU_PSS_ONE) == MCU_PSS_ONE) &&
                                (LulLoopCount != MCU_LONG_WORD_ZERO))
                        {
                          LulLoopCount--;
                        }

                        if (LulLoopCount == MCU_LONG_WORD_ZERO)
                        {
                          /* Power down mode entry failed and
                           * report production error
                           */
                          Dem_ReportErrorStatus(MCU_E_POWER_DOWN_MODE_FAILURE,
                                                    DEM_EVENT_STATUS_FAILED);
                        }

                        /* MISRA Rule: 11.3                                 */
                        /* Message :A cast should not be performed between a*/
                        /*        pointer type and an integral type.        */
                        /* Reason      :         This is to access the      */
                        /*                 hardware registers in the code.  */
                        /* Verification: However, the part of the code is   */
                        /*               verified manually and it           */
                        /*               is not having any impact on code.  */
                        /* Clear wakeup factor registers */
                        MCU_WUFCL0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL0);
                        MCU_WUFCM0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM0);
                        MCU_WUFCH0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH0);
                        MCU_WUFCL1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL1);
                        MCU_WUFCM1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM1);
                        MCU_WUFCH1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH1);
                      }
                      /* MISRA Rule: 11.3                                     */
                      /* Message   : A cast should not be performed between a */
                      /*             pointer type and an integral type.       */
                      /* Reason    : This is to access the hardware registers */
                      /*             in the code.                             */
                      /* Verification: However, the part of the code is       */
                      /*               verified manually and it is not having */
                      /*                      any impact on code.             */
                      else if (
                              (MCU_WUFH0 != MCU_LONG_WORD_ZERO) ||
                              (MCU_WUFL0 != MCU_LONG_WORD_ZERO) ||
                              (MCU_WUFM0 != MCU_LONG_WORD_ZERO))
                      {
                        LddResetSource = MCU_AWO_ISO0_WAKEUP;
                        /* Clear wakeup factor registers */
                        MCU_WUFCL0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL0);
                        MCU_WUFCM0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM0);
                        MCU_WUFCH0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH0);
                      }
                      /* MISRA Rule   : 11.3                                  */
                      /* Message      : A cast should not be performed between*/
                      /*                a pointer type and an integral type.  */
                      /* Reason       : This is to access the hardware        */
                      /*                registers in the code.                */
                      /* Verification : However, the part of the code is      */
                      /*                verified manually and it is not having*/
                      /*                any impact on code.                   */
                      else if (
                              (MCU_WUFH1 != MCU_LONG_WORD_ZERO) ||
                              (MCU_WUFL1 != MCU_LONG_WORD_ZERO) ||
                              (MCU_WUFM1 != MCU_LONG_WORD_ZERO))
                      {
                        LddResetSource = MCU_ISO1_WAKEUP;

                        LulLoopCount = MCU_LOOPCOUNT_MAX_VAL;

                        while (((MCU_PWS1 & MCU_PSS_ONE) == MCU_PSS_ONE) &&
                                  (LulLoopCount != MCU_LONG_WORD_ZERO))
                        {
                          LulLoopCount--;
                        }
                        if (LulLoopCount == MCU_LONG_WORD_ZERO)
                        {
                          /* Power down mode entry failed and
                           * report production error
                           */
                          Dem_ReportErrorStatus(MCU_E_POWER_DOWN_MODE_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
                        }

                        /* MISRA Rule   : 11.3                                */
                        /* Message      : A cast should not be performed      */
                        /*                between a pointer type and an       */
                        /*                integral type.                      */
                        /* Reason       : This is to access the hardware      */
                        /*                registers in the code.              */
                        /* Verification : However, the part of the code is    */
                        /*                verified manually and it            */
                        /*                is not having any impact on code.   */
                        /* Clear wakeup factor registers */
                        MCU_WUFCL1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL1);
                        MCU_WUFCM1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM1);
                        MCU_WUFCH1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH1);
                      }
                      else
                      {
                        /* Reset is due to Power ON */
                        LddResetSource = MCU_POWER_ON_RESET;
                      }
                      break;

      /* Software reset */
      case MCU_SWR  : LddResetSource = MCU_SW_RESET;
                      break;

      /* Reset is due to overflow of watchdog timer 0 */
      case MCU_WDR0 : LddResetSource = MCU_WATCHDOG0_RESET;
                      break;

      /* Reset is due to overflow of watchdog timer 1 */
      case MCU_WDR1 : LddResetSource = MCU_WATCHDOG1_RESET;
                      break;

      /* Clock Monitor 0 reset */
      case MCU_CLM0 : LddResetSource = MCU_CLM0_RESET;
                      break;

      /* Clock Monitor 2 reset */
      case MCU_CLM2 : LddResetSource = MCU_CLM2_RESET;
                      break;

      /* Clock Monitor 3 reset */
      case MCU_CLM3 : LddResetSource = MCU_CLM3_RESET;
                      break;

      /* Low voltage indication reset */
      case MCU_LVI  : LddResetSource = MCU_LVI_RESET;
                      break;

      /* Terminal reset */
      case MCU_TER  : LddResetSource = MCU_TERMINAL_RESET;
                      break;

      /* Reset is due to unknown source */
      default       : LddResetSource = MCU_RESET_UNKNOWN;
                      break;
    }
    /* MISRA Rule: 11.3                                       */
    /* Message   : A cast should not be performed between a   */
    /*             pointer type and an integral type.         */
    /* Reason    : This is to access the hardware registers in*/
    /*                the code.                               */
    /* Verification: However, the part of the code is         */
    /*               verified manually and it is not having   */
    /*                      any impact on code.               */
    /* Clear Reset factor register */
    MCU_RESFC = MCU_RESF_CLEAR;
  }
  return (LddResetSource);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_GetResetRawValue
**
** Service ID         : 0x06
**
** Description        : The service return reset type value from the hardware
**                      register
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_RawResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Remarks            : Global Variable:
**                      Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : RESF, RESFC
**
*******************************************************************************/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Mcu_RawResetType, MCU_PUBLIC_CODE) Mcu_GetResetRawValue (void)
{
  Mcu_RawResetType LddResetValue;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (Mcu_GblDriverStatus == MCU_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETRESETRAWVAULE_SID,
                                                                MCU_E_UNINIT);
    /* Set RESET status to uninitialized */
    LddResetValue = MCU_RESET_UNINIT;
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* MISRA Rule         : 11.3                                        */
    /* Message            : A cast should not be performed between a    */
    /*                      pointer type and an integral type.          */
    /* Reason             : This is to access the hardware registers in */
    /*                      the code.                                   */
    /* Verification       : However, the part of the code is            */
    /*                      verified manually and it is not having      */
    /*                      any impact on code.                         */

    /* Get the reset factor register value */
    LddResetValue = (Mcu_RawResetType)MCU_RESF;

    /* Clear Reset factor register */
    MCU_RESFC = MCU_RESF_CLEAR;
  }
  return(LddResetValue);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_PerformReset
**
** Service ID         : 0x07
**
** Description        : This service provides microcontroller reset by accessing
**                      the Software reset register.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Remarks            : Global Variable:
**                      Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError
**                      Dem_ReportErrorStatus
**
** Registers Used     : PROTCMD2, SWRESA, PROTS2
**
*******************************************************************************/
#if (MCU_PERFORM_RESET_API == STD_ON)

#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC (void, MCU_PUBLIC_CODE) Mcu_PerformReset (void)
{
  uint8 LucSWRESCount = MCU_FIVE;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (Mcu_GblDriverStatus == MCU_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_PERFORMRESET_SID,
                                                                MCU_E_UNINIT);
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    do
    {
      /* MISRA Rule         : 11.3                                        */
      /* Message            : A cast should not be performed between a    */
      /*                      pointer type and an integral type.          */
      /* Reason             : This is to access the hardware registers in */
      /*                      the code.                                   */
      /* Verification       : However, the part of the code is            */
      /*                      verified manually and it is not having      */
      /*                      any impact on code.                         */
      /* Write data to protection command register */
      MCU_PROTCMD2 = MCU_WRITE_DATA;
      /* Write the correct value to the software reset register */
      MCU_SWRESA = MCU_RES_CORRECT_VAL;
      /* Write the inverted value to the software reset register */
      MCU_SWRESA = MCU_RES_INVERTED_VAL;
      /* Write the correct value to the software reset register */
      MCU_SWRESA = MCU_RES_CORRECT_VAL;

      LucSWRESCount--;
    }while ((LucSWRESCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

    if (MCU_PROTS2 == MCU_ONE)
    {
      /* Writing to write-protected register failed and
       * report production error
       */
      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
  }
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* MCU_PERFORMRESET_API == STD_ON */

/*******************************************************************************
** Function Name      : Mcu_SetMode
**
** Service ID         : 0x08
**
** Description        : This service activates the MCU power modes.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : McuMode - Id for power mode setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Remarks            : Global Variable:
**                      Mcu_GblDriverStatus, Mcu_GpConfigPtr
**
** Function Invoked   : Mcu_DeepStopPrepare
**                      Det_ReportError
**                      Dem_ReportErrorStatus
**                      Mcu_CpuClockPrepare
**                      Mcu_ConfigureAWO7
**                      Mcu_RestartClocks
**
** Registers Used     : OSCWUFMSK, PROTCMD3, PROTS3, WUFMSKL0, WUFMSKM0,
**                      WUFMSKH0, WUFMSKL1, WUFMSKM1, WUFMSKH1, WUFCL1, WUFCM1,
**                      WUFCH1, BURC, BURAE, PSC1, WUFL1, WUFM1, WUFH1, PWS0,
**                      PWS1, PROTCMD2, PSC0, PROTS2, WUFCL0, WUFL0, WUFCM0,
**                      WUFM0, WUFCH0, WUFH0
**
*******************************************************************************/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, MCU_PUBLIC_CODE) Mcu_SetMode (Mcu_ModeType McuMode)
{
  P2CONST(Tdd_Mcu_ModeSetting, MCU_CONST, MCU_CONFIG_CONST) LpModeSetting;

  #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  /* Pointer pointing to the Port control registers */
  P2CONST(Tdd_Mcu_PortGroupAddress, AUTOMATIC, MCU_CONFIG_DATA) LpPortRegisters;
  /* Pointer to array of RAM area */
  P2VAR(uint32, AUTOMATIC, MCU_CONFIG_CONST) LpPortRamArea;
  #endif
  uint32 Luldeepstop;
  uint32 Luliohold;
  uint32 LulLoopCount;
  #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
  uint8 LucIndex;
  #endif

  Std_ReturnType LenReturnValue;
  uint8 LucMode;
  uint8 LucCount = MCU_FIVE;
  uint8 LblFlag = MCU_FALSE;
  boolean LblDemReported = MCU_FALSE;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  boolean LblDetErrFlag;
  #endif

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status value with MCU_FALSE */
  LblDetErrFlag = MCU_FALSE;
  /* Report to DET, if the component is not initialized */
  if (Mcu_GblDriverStatus == MCU_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID,
                                                                  MCU_E_UNINIT);

    /* Set the error status value to MCU_TRUE */
    LblDetErrFlag = MCU_TRUE;
  }
  else
  {
    /* Do nothing */
  }

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */

  /* Report to DET, if Mode Setting Id is out of range */
  if (McuMode >= MCU_MAX_MODE_SET)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID,
                                                          MCU_E_PARAM_MODE);
    /* Set the error status value to MCU_TRUE */
    LblDetErrFlag = MCU_TRUE;
  }
  else
  {
    /* Do nothing */
  }

  /* Check if any development error occurred */
  if (LblDetErrFlag == MCU_FALSE)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    LpModeSetting = ((P2CONST(Tdd_Mcu_ModeSetting, MCU_CONST, MCU_CONFIG_CONST))
                                  (Mcu_GpConfigPtr->pModeSetting) + McuMode);

    LucMode = LpModeSetting->ucModeType;

    /* MISRA Rule   : 11.3                                          */
    /* Message      : A cast should not be performed between a      */
    /*                pointer type and an integral type.            */
    /* Reason       : This is to access the hardware registers      */
    /*                in the code.                                  */
    /* Verification : However, the part of the code is              */
    /*                verified manually and it is not having        */
    /*                any impact on code.                           */

    /* Clear oscillator wake-up factor mask register */
    MCU_OSCWUFMSK = MCU_LONG_WORD_ZERO;

    /* Write value to Enable/Disable oscillator wakeup for ISO0 and ISO1 area */
    MCU_OSCWUFMSK = LpModeSetting->ulOscWufMsk;

    /* Load value to IO reset register 1 to reset different ports
     * before power down
     */
    #if (MCU_IORES1_ENABLE == STD_ON)
    do
    {
      /* Write the write enable register */
      MCU_PROTCMD3 = MCU_WRITE_DATA;
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                in the code.                                  */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */

      /* Write protected sequence */
      MCU_IORES1 = LpModeSetting->ucIOResetReg1;
      MCU_IORES1 = ~(LpModeSetting->ucIOResetReg1);
      MCU_IORES1 = LpModeSetting->ucIOResetReg1;
      LucCount--;
    }while ((LucCount > MCU_ZERO) && (MCU_PROTS3 == MCU_ONE));

    if (MCU_PROTS3 == MCU_ONE)
    {
      /* writing to write-protected register failed and
       * report production error
       */
      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    #endif /* MCU_IORES1_ENABLE == STD_ON */


    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* Check if the requested power mode is RUN_MODE */
    if (LucMode == MCU_RUN_MODE)
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                in the code.                                  */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */

      /* if ISO1 is already in STOP mode i.e. previous mode is
       * RUN_MODE_ISO1_STOP or RUN_MODE_ISO1_DEEPSTOP
       */
      if ((MCU_PWS0 == MCU_ISO0_RUN_MODE) &&
              ((MCU_PWS1 == MCU_MODE_ISO1_STOP)||
              (MCU_PWS1 == MCU_MODE_ISO1_DEEPSTOP)))
      {
        /* Report to DET */
        Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID,
                                                         MCU_E_INVALID_MODE);

        /* Set the error status value to MCU_TRUE */
        LblDetErrFlag = MCU_TRUE;
      }
    }

    /* Check if any development error occurred */
    if (LblDetErrFlag == MCU_FALSE)
    #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */
      /* Clear wakeup factor registers */
      MCU_WUFCL0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL0);
      MCU_WUFCM0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM0);
      MCU_WUFCH0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH0);
      MCU_WUFCL1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL1);
      MCU_WUFCM1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM1);
      MCU_WUFCH1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH1);

      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                in the code.                                  */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */

      if ( LucMode != MCU_HALT_MODE )
      {
        MCU_WUFMSKL0 = LpModeSetting->ulPowerDownWakeupTypeL0;
        MCU_WUFMSKM0 = LpModeSetting->ulPowerDownWakeupTypeM0;
        MCU_WUFMSKH0 = LpModeSetting->ulPowerDownWakeupTypeH0;
        MCU_WUFMSKL1 = LpModeSetting->ulPowerDownWakeupTypeL1;
        MCU_WUFMSKM1 = LpModeSetting->ulPowerDownWakeupTypeM1;
        MCU_WUFMSKH1 = LpModeSetting->ulPowerDownWakeupTypeH1;
      }
      else
      {
        /* No action Required */
      }

      switch (LucMode)
      {
        case MCU_HALT_MODE:
              /* Assembly instruction for HALT */
              __asm("halt");

              __asm("nop");
              __asm("nop");
              __asm("nop");
              __asm("nop");
              __asm("nop");
            break;

        case MCU_RUN_MODE_ISO1_STOP:
              #if (MCU_DEV_ERROR_DETECT == STD_ON)

              /* if ISO1 is already in STOP mode i.e. previous mode is
               * RUN_MODE_ISO1_DEEPSTOP
               */
              /* MISRA Rule   : 11.3                                        */
              /* Message      : A cast should not be performed between a    */
              /*                pointer type and an integral type.          */
              /* Reason       : This is to access the hardware registers    */
              /*                in the code.                                */
              /* Verification : However, the part of the code is            */
              /*                verified manually and it is not having      */
              /*                any impact on code.                         */
              if (MCU_PWS1 == MCU_MODE_ISO1_DEEPSTOP)
              {
                /* Report to DET */
                Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID,
                                                            MCU_E_INVALID_MODE);

                /* Set the error status value to MCU_TRUE */
                LblDetErrFlag = MCU_TRUE;
              }
              else
              #endif /* #if (MCU_DEV_ERROR_DETECT == STD_ON) */
              {
                LucCount = MCU_FIVE;
                /* MISRA Rule   : 11.3                                      */
                /* Message      : A cast should not be performed between a  */
                /*                pointer type and an integral type.        */
                /* Reason       : This is to access the hardware registers  */
                /*                 in the code.                             */
                /* Verification : However, the part of the code is          */
                /*                verified manually and it is not having    */
                /*                any impact on code.                       */
                /* STOP ISO1 area */
                do
                {
                  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                  SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                  #endif
                  /* Write the write enable register */
                  MCU_PROTCMD2 = MCU_WRITE_DATA;
                  /* MISRA Rule   : 11.3                                     */
                  /* Message      : A cast should not be performed between a */
                  /*                pointer type and an integral type.       */
                  /* Reason       : This is to access the hardware registers */
                  /*                in the code.                             */
                  /* Verification : However, the part of the code is         */
                  /*                verified manually and it is not having   */
                  /*                any impact on code.                      */
                  /* Make STP bit of PSC1 register true */
                  MCU_PSC1 = MCU_ISO1_STOP_MODE;
                  MCU_PSC1 = ~MCU_ISO1_STOP_MODE;
                  MCU_PSC1 = MCU_ISO1_STOP_MODE;
                  LucCount--;
                  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                  SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                  #endif
                }while ((LucCount > MCU_ZERO) &&
                                           (MCU_PROTS2 == MCU_ONE));

                if (MCU_PROTS2 == MCU_ONE)
                {
                  /* writing to write-protected register failed and
                     report production error */
                  Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                     DEM_EVENT_STATUS_FAILED);
                }

                LulLoopCount = MCU_LOOPCOUNT_MAX_VAL;
                /* MISRA Rule   : 11.3                                       */
                /* Message      : A cast should not be performed between a   */
                /*                pointer type and an integral type.         */
                /* Reason       : This is to access the hardware registers   */
                /*                in the code.                               */
                /* Verification : However, the part of the code is           */
                /*                verified manually and it is not having     */
                /*                any impact on code.                        */
                do
                {
                  if ((MCU_WUFL1 != MCU_LONG_WORD_ZERO)
                   ||(MCU_WUFM1 != MCU_LONG_WORD_ZERO)
                   ||((MCU_WUFH1 & MCU_WUFH0_MASK) != MCU_LONG_WORD_ZERO))
                  {
                    LblFlag = MCU_TRUE;
                  }
                  LulLoopCount--;
                  /* Read PSS bit till it becomes 1 */
                }while ((((MCU_PWS1 & MCU_PSS_ONE) != MCU_PSS_ONE) &&
                      (LulLoopCount > MCU_LONG_WORD_ZERO))  &&
                                                      (LblFlag == MCU_FALSE));

                if (LulLoopCount == MCU_LONG_WORD_ZERO)
                {
                  /* Power down mode entry failed and
                   * report production error
                   */
                  Dem_ReportErrorStatus(MCU_E_POWER_DOWN_MODE_FAILURE,
                                           DEM_EVENT_STATUS_FAILED);
                }
                /* MISRA Rule   : 11.3                                     */
                /* Message      : A cast should not be performed between a */
                /*                pointer type and an integral type.       */
                /* Reason       : This is to access the hardware registers */
                /*                 in the code.                            */
                /* Verification : However, the part of the code is         */
                /*                verified manually and it is not having   */
                /*                any impact on code.                      */
                if (LblFlag == MCU_TRUE)
                {
                  /* Clear Iso1 wakeup factor registers */
                  MCU_WUFCL1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL1);
                  MCU_WUFCM1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM1);
                  MCU_WUFCH1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH1);
                }
              }
            break;

        case MCU_STOP_MODE:
              #if (MCU_DEV_ERROR_DETECT == STD_ON)
              /* if ISO1 is already in DEEPSTOP mode i.e. previous mode is
               * RUN_MODE_ISO1_DEEPSTOP
               */
              if (MCU_PWS1 == MCU_MODE_ISO1_DEEPSTOP)
              {
                /* Report to DET */
                Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID,
                                                           MCU_E_INVALID_MODE);

                /* Set the error status value to MCU_TRUE */
                LblDetErrFlag = MCU_TRUE;
              }
              else
              #endif /* #if (MCU_DEV_ERROR_DETECT == STD_ON) */
              {
                /* Prepare AWO7 clock for STOP mode */
                Mcu_ConfigureAWO7();

                /* set CPU Clock to default setting */
                LenReturnValue = Mcu_CpuClockPrepare();

                if (LenReturnValue == E_OK)
                {
                  /* MISRA Rule   : 11.3                                     */
                  /* Message      : A cast should not be performed between a */
                  /*                pointer type and an integral type.       */
                  /* Reason       : This is to access the hardware registers */
                  /*                 in the code.                            */
                  /* Verification : However, the part of the code is         */
                  /*                verified manually and it is not having   */
                  /*                any impact on code.                      */
                  /* Check if the Iso1 is already in STOP mode  */
                  if (MCU_PWS1 == MCU_MODE_ISO1_STOP)
                  {
                    /* MISRA Rule   : 11.3                                    */
                    /* Message      : A cast should not be performed between a*/
                    /*                pointer type and an integral type.      */
                    /* Reason       : This is to access the hardware registers*/
                    /*                 in the code.                           */
                    /* Verification : However, the part of the code is        */
                    /*                verified manually and it is not having  */
                    /*                any impact on code.                     */

                    /* STOP ISO0 area */
                    LucCount = MCU_FIVE;
                    do
                    {
                      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                      SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                      #endif
                      /* Write the write enable register */
                      MCU_PROTCMD2 = MCU_WRITE_DATA;

                      /* MISRA Rule  : 11.3                                   */
                      /* Message     : A cast should not be performed between */
                      /*               a pointer type and an integral type.   */
                      /* Reason      : This is to access the hardware         */
                      /*               registers in the code.                 */
                      /* Verification: However, the part of the code is       */
                      /*               verified manually and it is not having */
                      /*               any impact on code.                    */

                      /* Make STP bit of PSC0 register true */
                      MCU_PSC0 = MCU_ISO0_STOP_MODE;
                      MCU_PSC0 = ~MCU_ISO0_STOP_MODE;
                      MCU_PSC0 = MCU_ISO0_STOP_MODE;
                      LucCount--;

                      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                      SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                      #endif
                    }while ((LucCount > MCU_ZERO) &&
                            (MCU_PROTS2 == MCU_ONE));

                    if (MCU_PROTS2 == MCU_ONE)
                    {
                      /* writing to write-protected register failed and
                       * report production error
                       */
                      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
                    }
                  }
                  else
                  {
                    LucCount = MCU_FIVE;
                    /* MISRA Rule   : 11.3                                    */
                    /* Message      : A cast should not be performed between a*/
                    /*                pointer type and an integral type.      */
                    /* Reason       : This is to access the hardware registers*/
                    /*                 in the code.                           */
                    /* Verification : However, the part of the code is        */
                    /*                verified manually and it is not having  */
                    /*                any impact on code.                     */
                    /* STOP ISO1 area */
                    do
                    {
                      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                      SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                      #endif
                      /* Write the write enable register */
                      MCU_PROTCMD2 = MCU_WRITE_DATA;
                      /* MISRA Rule  : 11.3                                   */
                      /* Message     : A cast should not be performed between */
                      /*               a pointer type and an integral type.   */
                      /* Reason      : This is to access the hardware         */
                      /*               registers in the code.                 */
                      /* Verification: However, the part of the code is       */
                      /*               verified manually and it is not having */
                      /*               any impact on code.                    */
                      /* Make STP bit of PSC1 register true */
                      MCU_PSC1 = MCU_ISO1_STOP_MODE;
                      MCU_PSC1 = ~MCU_ISO1_STOP_MODE;
                      MCU_PSC1 = MCU_ISO1_STOP_MODE;
                      LucCount--;
                      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                      SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                      #endif
                    }while ((LucCount > MCU_ZERO) &&
                                             (MCU_PROTS2 == MCU_ONE));

                    if (MCU_PROTS2 == MCU_ONE)
                    {
                      /* writing to write-protected register failed and
                       * report production error
                       */
                      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
                    }

                    /* MISRA Rule   : 11.3                                    */
                    /* Message      : A cast should not be performed between a*/
                    /*                pointer type and an integral type.      */
                    /* Reason       : This is to access the hardware registers*/
                    /*                 in the code.                           */
                    /* Verification : However, the part of the code is        */
                    /*                verified manually and it is not having  */
                    /*                any impact on code.                     */

                    /* STOP ISO0 area */
                    LucCount = MCU_FIVE;
                    do
                    {
                      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                      SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                      #endif
                      /* Write the write enable register */
                      MCU_PROTCMD2 = MCU_WRITE_DATA;

                      /* MISRA Rule  : 11.3                                   */
                      /* Message     : A cast should not be performed between */
                      /*               a pointer type and an integral type.   */
                      /* Reason      : This is to access the hardware         */
                      /*               registers in the code.                 */
                      /* Verification: However, the part of the code is       */
                      /*               verified manually and it is not having */
                      /*               any impact on code.                    */

                      /* Make STP bit of PSC0 register true */
                      MCU_PSC0 = MCU_ISO0_STOP_MODE;
                      MCU_PSC0 = ~MCU_ISO0_STOP_MODE;
                      MCU_PSC0 = MCU_ISO0_STOP_MODE;
                      LucCount--;

                      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                      SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                      #endif
                    }while ((LucCount > MCU_ZERO) &&
                              (MCU_PROTS2 == MCU_ONE));

                    if (MCU_PROTS2 == MCU_ONE)
                    {
                      /* writing to write-protected register failed and
                       * report production error
                       */
                      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                    DEM_EVENT_STATUS_FAILED);
                    }
                  }

                  /* CPU remains in Infinite loop while transition to STOP of
                   * ISO0 starts
                   */
                  do
                  {
                    /* Infinite loop to wait for PWSS0PSS bit of PWS0 to 0 */
                  } while (((MCU_PWS0 & MCU_PWS_PSS_MSK) == MCU_PWS_PSS_MSK));

                  /* STOP mode wakeup processing, Wait until ISO1 is woken up */
                  do
                  {
                    /* Infinite loop to wait for PWSS1PSS bit of PWS1 to 0 */
                  }while (((MCU_PWS1 & MCU_PWS_PSS_MSK) == MCU_PWS_PSS_MSK));


                  /* MISRA Rule : 11.3                                     */
                  /* Message    : A cast should not be performed between a */
                  /*              pointer type and an integral type.       */
                  /* Reason     : This is to access the hardware registers */
                  /*               in the code.                            */
                  /* Verification : However, the part of the code is       */
                  /*                verified manually and it is not having */
                  /*                any impact on code.                    */
                  /* Check for Awo, Iso0 and Iso1 wakeup factor registers  */

                  if (((MCU_WUFH0 != MCU_LONG_WORD_ZERO) ||
                        (MCU_WUFL0 != MCU_LONG_WORD_ZERO) ||
                        (MCU_WUFM0 != MCU_LONG_WORD_ZERO)) &&
                        ((MCU_WUFH1 != MCU_LONG_WORD_ZERO) ||
                        (MCU_WUFL1 != MCU_LONG_WORD_ZERO) ||
                        (MCU_WUFM1 != MCU_LONG_WORD_ZERO)))
                  {
                    /* Clear wakeup factor registers */
                    MCU_WUFCL0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL0);
                    MCU_WUFCM0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM0);
                    MCU_WUFCH0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH0);
                    MCU_WUFCL1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL1);
                    MCU_WUFCM1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM1);
                    MCU_WUFCH1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH1);
                  }
                  /* Check for Awo, Iso0 wakeup factor registers */
                  else if ((MCU_WUFH0 != MCU_LONG_WORD_ZERO) ||
                            (MCU_WUFL0 != MCU_LONG_WORD_ZERO) ||
                            (MCU_WUFM0 != MCU_LONG_WORD_ZERO))
                  {
                    /* MISRA Rule   : 11.3                                    */
                    /* Message      : A cast should not be performed between a*/
                    /*                pointer type and an integral type.      */
                    /* Reason       : This is to access the hardware registers*/
                    /*                 in the code.                           */
                    /* Verification : However, the part of the code is        */
                    /*                verified manually and it is not having  */
                    /*                any impact on code.                     */
                    /* Clear Iso0 wakeup factor registers */
                    MCU_WUFCL0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL0);
                    MCU_WUFCM0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM0);
                    MCU_WUFCH0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH0);
                  }
                  else
                  {
                    /* To avoid MISRA warning */
                  }

                  /* Restore the AWO7 domain clock */
                  Mcu_ConfigureAWO7();
                  LenReturnValue = Mcu_CpuClockRestore();

                  if (LenReturnValue == E_NOT_OK)
                  {
                    /* writing to write-protected register failed and
                     * report production error
                     */
                     Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                              DEM_EVENT_STATUS_FAILED);

                    /* Set the error status value to MCU_TRUE */
                    LblDemReported = MCU_TRUE;
                  }
                }
              }
            break;

        case MCU_RUN_MODE_ISO1_DEEPSTOP:

              #if (MCU_DEV_ERROR_DETECT == STD_ON)
              /* MISRA Rule   : 11.3                                         */
              /* Message      : A cast should not be performed between a     */
              /*                pointer type and an integral type.           */
              /* Reason       : This is to access the hardware registers     */
              /*                in the code.                                 */
              /* Verification : However, the part of the code is             */
              /*                verified manually and it is not having       */
              /*                any impact on code.                          */
              /* if ISO1 is in stop mode i.e. previous mode is
               * RUN_MODE_ISO1_STOP
               */
              if (MCU_PWS1 == MCU_MODE_ISO1_STOP)
              {
                /* Report to DET */
                Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID,
                                                        MCU_E_INVALID_MODE);

                /* Set the error status value to MCU_TRUE */
                LblDetErrFlag = MCU_TRUE;
              }
              else
              #endif /* #if (MCU_DEV_ERROR_DETECT == STD_ON) */
              {
                LucCount = MCU_FIVE;

                #if (MCU_DEEPSTOP_WAKE_PIN == STD_ON)
                /* Set the REGSTP bit along with STP and POF bits */
                Luldeepstop = MCU_ISO1_DEEPSTOP_MODE_REGSTP;
                #else
                /* Set only the STP and POF bits */
                Luldeepstop = MCU_ISO1_DEEPSTOP_MODE;
                #endif/*MCU_DEEPSTOP_WAKE_PIN == STD_ON*/

                do
                {
                  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                  SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                  #endif

                  /* MISRA Rule   : 11.3                                     */
                  /* Message      : A cast should not be performed between a */
                  /*                pointer type and an integral type.       */
                  /* Reason       : This is to access the hardware registers */
                  /*                in the code.                             */
                  /* Verification : However, the part of the code is         */
                  /*                verified manually and it is not having   */
                  /*                any impact on code.                      */

                  /* Write the write enable register */
                  MCU_PROTCMD2 = MCU_WRITE_DATA;

                  /* Make the ISO1 region enter into DEEPSTOP mode */
                  MCU_PSC1 = Luldeepstop;
                  MCU_PSC1 = ~Luldeepstop;
                  MCU_PSC1 = Luldeepstop;
                  LucCount--;
                  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                  SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                  #endif
                }while ((LucCount > MCU_ZERO) &&
                             (MCU_PROTS2 == MCU_ONE));

                if (MCU_PROTS2 == MCU_ONE)
                {
                  /* writing to write-protected register failed and
                   * report production error
                   */
                  Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                     DEM_EVENT_STATUS_FAILED);
                }

                /* wait till Iso1 enters deepstop mode by verifying
                 * PSS=0 and ISO=1
                 */
                do
                {
                  /*no action required*/
                }while (((MCU_PWS1 & MCU_PWS_REG_MASK)  \
                                  != MCU_PWS_DEEPSTOP_STS));
              }
            break;

        case MCU_STOP_MODE_ISO1_DEEPSTOP:

              #if (MCU_DEV_ERROR_DETECT == STD_ON)
              /* if ISO1 is not in deepstop mode i.e. previous mode is
               * RUN_MODE_ISO1_STOP
               */
              /* MISRA Rule   : 11.3                                     */
              /* Message      : A cast should not be performed between a */
              /*                pointer type and an integral type.       */
              /* Reason       : This is to access the hardware registers */
              /*                 in the code.                            */
              /* Verification : However, the part of the code is         */
              /*                verified manually and it is not having   */
              /*                any impact on code.                      */
              if (MCU_PWS1 == MCU_MODE_ISO1_STOP)
              {
                /* Report to DET */
                Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID,
                                                         MCU_E_INVALID_MODE);


                /* Set the error status value to MCU_TRUE */
                LblDetErrFlag = MCU_TRUE;
              }
              else
              #endif /* #if (MCU_DEV_ERROR_DETECT == STD_ON) */
              {
                /* MISRA Rule   : 11.3                                     */
                /* Message      : A cast should not be performed between a */
                /*                pointer type and an integral type.       */
                /* Reason       : This is to access the hardware registers */
                /*                 in the code.                            */
                /* Verification : However, the part of the code is         */
                /*                verified manually and it is not having   */
                /*                any impact on code.                      */

                /* Preapare clock for AWO7 clock domain */
                Mcu_ConfigureAWO7();

                /* Check if the Iso1 is already in DEEPSTOP mode  */
                if (MCU_PWS1 == MCU_MODE_ISO1_DEEPSTOP)
                {
                  LucCount = MCU_FIVE;

                  /* MISRA Rule   : 11.3                                     */
                  /* Message      : A cast should not be performed between a */
                  /*                pointer type and an integral type.       */
                  /* Reason       : This is to access the hardware registers */
                  /*                 in the code.                            */
                  /* Verification : However, the part of the code is         */
                  /*                verified manually and it is not having   */
                  /*                any impact on code.                      */
                  /* Change ISO0 from RUN to DEEPSTOP mode */

                  do
                  {
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                    /* Write the write enable register */
                    MCU_PROTCMD2 = MCU_WRITE_DATA;
                    /* MISRA Rule  : 11.3                                     */

                    /* Message     : A cast should not be performed between a */
                    /*               pointer type and an integral type.       */
                    /* Reason      : This is to access the hardware registers */
                    /*               in the code.                             */
                    /* Verification : However, the part of the code is        */
                    /*                verified manually and it is not having  */
                    /*                any impact on code.                     */

                    /* Make STP bit of PSC0 register true */
                    MCU_PSC0 = MCU_ISO0_STOP_MODE;
                    MCU_PSC0 = ~MCU_ISO0_STOP_MODE;
                    MCU_PSC0 = MCU_ISO0_STOP_MODE;
                    LucCount--;
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                  }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

                  if (MCU_PROTS2 == MCU_ONE)
                  {
                    /* writing to write-protected register failed and
                     * report production error
                     */
                    Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                            DEM_EVENT_STATUS_FAILED);
                  }
                }
                else
                {
                  LucCount = MCU_FIVE;

                  do
                  {
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif

                    /* MISRA Rule  : 11.3                                    */
                    /* Message     : A cast should not be performed between a*/
                    /*               pointer type and an integral type.      */
                    /* Reason      : This is to access the hardware registers*/
                    /*               in the code.                            */
                    /* Verification: However, the part of the code is        */
                    /*               verified manually and it is not having  */
                    /*               any impact on code.                     */

                    /* Write the write enable register */
                    MCU_PROTCMD2 = MCU_WRITE_DATA;

                    /* Make STP and POF bits of PSC1 register true */
                    MCU_PSC1 = MCU_ISO1_DEEPSTOP_MODE;
                    MCU_PSC1 = ~MCU_ISO1_DEEPSTOP_MODE;
                    MCU_PSC1 = MCU_ISO1_DEEPSTOP_MODE;
                    LucCount--;
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                  }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

                  if (MCU_PROTS2 == MCU_ONE)
                  {
                    /* writing to write-protected register failed and
                     * report production error
                     */
                    Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                    DEM_EVENT_STATUS_FAILED);
                  }
                  LucCount = MCU_FIVE;

                  /* MISRA Rule  : 11.3                                      */
                  /* Message     : A cast should not be performed between a  */
                  /*               pointer type and an integral type.        */
                  /* Reason      : This is to access the hardware registers  */
                  /*                in the code.                             */
                  /* Verification: However, the part of the code is          */
                  /*               verified manually and it is not having    */
                  /*               any impact on code.                       */
                  /* Change ISO0 from RUN to STOP mode */
                  do
                  {
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                    /* Write the write enable register */
                    MCU_PROTCMD2 = MCU_WRITE_DATA;
                    /* MISRA Rule  : 11.3                                     */
                    /* Message     : A cast should not be performed between a */
                    /*               pointer type and an integral type.       */
                    /* Reason      : This is to access the hardware registers */
                    /*               in the code.                             */
                    /* Verification: However, the part of the code is         */
                    /*               verified manually and it is not having   */
                    /*               any impact on code.                      */

                    /* Make STP bit of PSC0 register true */
                    MCU_PSC0 = MCU_ISO0_STOP_MODE;
                    MCU_PSC0 = ~MCU_ISO0_STOP_MODE;
                    MCU_PSC0 = MCU_ISO0_STOP_MODE;
                    LucCount--;
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                  }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

                  if (MCU_PROTS2 == MCU_ONE)
                  {
                    /* writing to write-protected register failed and
                     * report production error
                     */
                    Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
                  }
                }

                /* MISRA Rule  : 11.3                                      */
                /* Message     : A cast should not be performed between a  */
                /*               pointer type and an integral type.        */
                /* Reason      : This is to access the hardware registers  */
                /*                in the code.                             */
                /* Verification: However, the part of the code is          */
                /*               verified manually and it is not having    */
                /*               any impact on code.                       */

                /* Clear wakeup factor registers */

                if (((MCU_WUFH0 != MCU_LONG_WORD_ZERO) ||
                    (MCU_WUFL0 != MCU_LONG_WORD_ZERO) ||
                    (MCU_WUFM0 != MCU_LONG_WORD_ZERO)) &&
                   ((MCU_WUFH1 != MCU_LONG_WORD_ZERO) ||
                    (MCU_WUFL1 != MCU_LONG_WORD_ZERO) ||
                    (MCU_WUFM1 != MCU_LONG_WORD_ZERO)))
                {
                  /* Mask the IOHOLDCLR bit */
                  Luliohold = (MCU_PSC1 | MCU_IOHOLD_CLR);

                  LucCount = MCU_FIVE;
                  do
                  {
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                    /* Write the write enable register */
                    MCU_PROTCMD2 = MCU_WRITE_DATA;

                    /* MISRA Rule  : 11.3                                    */
                    /* Message     : A cast should not be performed between a*/
                    /*               pointer type and an integral type.      */
                    /* Reason      : This is to access the hardware registers*/
                    /*               in the code.                            */
                    /* Verification: However, the part of the code is        */
                    /*               verified manually and it is not having  */
                    /*               any impact on code.                     */

                    /* Make IOHLDCLR bit of PSC1 register true */
                    MCU_PSC1 = Luliohold;
                    MCU_PSC1 = ~Luliohold;
                    MCU_PSC1 = Luliohold;
                    LucCount--;
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                  }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

                  if (MCU_PROTS2 == MCU_ONE)
                  {
                    /* writing to write-protected register failed and
                     * report production error
                     */
                    Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
                  }

                  /* MISRA Rule   : 11.3                                      */
                  /* Message      : A cast should not be performed between a  */
                  /*                pointer type and an integral type.        */
                  /* Reason       : This is to access the hardware registers  */
                  /*                 in the code.                             */
                  /* Verification : However, the part of the code is          */
                  /*                verified manually and it is not having    */
                  /*                any impact on code.                       */

                  /* Clear Awo, Iso0 and Iso1 wakeup factor registers */
                  MCU_WUFCL0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL0);
                  MCU_WUFCM0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM0);
                  MCU_WUFCH0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH0);
                  MCU_WUFCL1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL1);
                  MCU_WUFCM1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM1);
                  MCU_WUFCH1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH1);
                }
                else if ((MCU_WUFH0 != MCU_LONG_WORD_ZERO) ||
                      (MCU_WUFL0 != MCU_LONG_WORD_ZERO) ||
                      (MCU_WUFM0 != MCU_LONG_WORD_ZERO))
                {
                  /* MISRA Rule   : 11.3                                     */
                  /* Message      : A cast should not be performed between a */
                  /*                pointer type and an integral type.       */
                  /* Reason       : This is to access the hardware registers */
                  /*                 in the code.                            */
                  /* Verification : However, the part of the code is         */
                  /*                verified manually and it is not having   */
                  /*                any impact on code.                      */
                  /* Clear Iso0 wakeup factor registers */
                  MCU_WUFCL0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL0);
                  MCU_WUFCM0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM0);
                  MCU_WUFCH0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH0);
                }
                /* To avoid MISRA warning */
                else
                {
                  /* To avoid MISRA warning */
                }

                /* Restore the AWO7 domain clock */
                Mcu_ConfigureAWO7();
              }
            break;

        case MCU_DEEPSTOP_MODE:

              #if (MCU_DEV_ERROR_DETECT == STD_ON)
              /* MISRA Rule   : 11.3                                        */
              /* Message      : A cast should not be performed between a    */
              /*                pointer type and an integral type.          */
              /* Reason       : This is to access the hardware registers    */
              /*                 in the code.                               */
              /* Verification : However, the part of the code is            */
              /*                verified manually and it is not having      */
              /*                any impact on code.                         */


              /* If ISO1 is in stop mode i.e. previous mode is
               * RUN_MODE_ISO1_STOP
               */
              if (MCU_PWS1 == MCU_MODE_ISO1_STOP)
              {
                /* Report to DET */
                Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID,
                                                            MCU_E_INVALID_MODE);

                /* Set the error status value to MCU_TRUE */
                LblDetErrFlag = MCU_TRUE;
              }
              else
              #endif /* #if (MCU_DEV_ERROR_DETECT == STD_ON) */
              {
                #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON)
                /* Store PORT registers */
                /* Count for the size of array in which the values at Port
                 * registers are to be stored for back-up before entering into
                 * deep-stop mode
                 */
                /* Get the number of Port groups configured */
                LucIndex = Mcu_GpConfigPtr->ucNumOfPortGroup;
                /* Get pointer to the RAM area */
                LpPortRamArea = Mcu_GpConfigPtr->pPortRamArea;
                /* Get pointer to the Port registers structure */
                LpPortRegisters =
                (P2CONST(Tdd_Mcu_PortGroupAddress, AUTOMATIC, MCU_CONFIG_DATA))
                                            Mcu_GpConfigPtr->pPortGroupSetting;

                /* MISRA Rule  : 11.3                                     */
                /* Message     : A cast should not be performed between a */
                /*               pointer type and an integral type.       */
                /* Reason      : This is to access the hardware registers */
                /*               in the code.                             */
                /* Verification: However, the part of the code is         */
                /*               verified manually and it is not having   */
                /*               any impact on code.                      */

                /*Permit write access to BURAM by setting BURWE bit*/
                MCU_BURC = MCU_BURWE_SET_VALUE;

                do
                {
                  /* Store the value of PSR register of the configured
                   * Port group in BURAM area
                   */
                  *LpPortRamArea = LpPortRegisters->pPortGroupAddress->ulPSRn;
                  /* MISRA Rule         : 17.4                             */
                  /* Message            : Increment or decrement operation */
                  /*                      performed on pointer.            */
                  /* Reason             : Increment operator is used to    */
                  /*                      achieve better throughput.       */
                  /* Verification       : However, part of the code is     */
                  /*                      verified manually and it is not  */
                  /*                      having any impact.               */
                  LpPortRamArea++;
                  LpPortRegisters++;
                  LucIndex--;
                }while ((LucIndex > MCU_ZERO) && (MCU_BURAE == MCU_ZERO));

                if (MCU_BURAE == MCU_ONE)
                {
                  /* writing to BURAM Area failed and
                   * report production error
                   */
                  Dem_ReportErrorStatus(MCU_E_BURAM_WRITE_FAILURE,
                                                    DEM_EVENT_STATUS_FAILED);

                  LblDemReported = MCU_TRUE;
                }
                #endif /* #if (MCU_PORTGROUP_STATUS_BACKUP == STD_ON) */

                #if (MCU_IOHOLDMASK_REQ == STD_ON)
                /* To avoid automatic change to I/O buffer hold state upon
                 * entering DEEPSTOP */

                LucCount = MCU_FIVE;
                do
                {
                  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                  SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                  #endif
                  /* Write the write enable register */
                  MCU_PROTCMD2 = MCU_WRITE_DATA;

                  /* Make IOHOLDMASK bit of PSC0 register true */
                  MCU_PSC0 |= MCU_IOHOLD_MASK_CLEAR;
                  MCU_PSC0 |= ~MCU_IOHOLD_MASK_CLEAR;
                  MCU_PSC0 |= MCU_IOHOLD_MASK_CLEAR;
                  LucCount--;

                  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                  SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                  #endif
                }while ((LucCount > MCU_ZERO) &&
                      (MCU_PROTS2 == MCU_ONE));

                if (MCU_PROTS2 == MCU_ONE)
                {
                  /* writing to write-protected register failed and
                   * report production error
                   */
                  Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                   DEM_EVENT_STATUS_FAILED);
                  /* Set the error status value to MCU_TRUE */
                  LblDemReported = MCU_TRUE;
                }

                /* To avoid automatic change to I/O buffer hold state upon
                 * entering DEEPSTOP */
                LucCount = MCU_FIVE;
                do
                {
                  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                  SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                  #endif
                  /* Write the write enable register */
                  MCU_PROTCMD2 = MCU_WRITE_DATA;
                  /* Make IOHOLDMASK bit of PSC1 register true */
                  MCU_PSC1 |= MCU_IOHOLD_MASK_CLEAR;
                  MCU_PSC1 |= ~MCU_IOHOLD_MASK_CLEAR;
                  MCU_PSC1 |= MCU_IOHOLD_MASK_CLEAR;
                  LucCount--;

                  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                  SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                  #endif
                }while((LucCount > MCU_ZERO) &&
                         (MCU_PROTS2 == MCU_ONE));

                if (MCU_PROTS2 == MCU_ONE)
                {
                  /* writing to write-protected register failed and
                   * report production error
                   */
                  Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                DEM_EVENT_STATUS_FAILED);
                  /* Set the error status value to MCU_TRUE */
                  LblDemReported = MCU_TRUE;
                }
                #endif /* #if (MCU_IOHOLDMASK_REQ == STD_ON) */

                LenReturnValue = E_OK;


                /* Check if the Iso1 is already not in DEEPSTOP mode  */
                if ((MCU_PWS1 != MCU_MODE_ISO1_DEEPSTOP)
                    && (LblDemReported != MCU_TRUE) && (LenReturnValue == E_OK))
                {
                  LucCount = MCU_FIVE;

                  #if (MCU_DEEPSTOP_WAKE_PIN == STD_ON)
                  /* Set the REGSTP bit along with STP and POF bits */
                 Luldeepstop = (MCU_ISO1_DEEPSTOP_MODE_REGSTP | MCU_PSC1);
                  #else
                  /* Set only the STP and POF bits */
                 Luldeepstop = (MCU_ISO1_DEEPSTOP_MODE | MCU_PSC1);
                  #endif/*MCU_DEEPSTOP_WAKE_PIN == STD_ON*/

                  do
                  {
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif

                    /* MISRA Rule  : 11.3                                    */
                    /* Message     : A cast should not be performed between a*/
                    /*               pointer type and an integral type.      */
                    /* Reason      : This is to access the hardware registers*/
                    /*               in the code.                            */
                    /* Verification: However, the part of the code is        */
                    /*               verified manually and it is not having  */
                    /*               any impact on code.                     */


                    /* Write the write enable register */
                    MCU_PROTCMD2 = MCU_WRITE_DATA;

                    /* Make the ISO1 region enter into DEEPSTOP mode */
                    MCU_PSC1 = Luldeepstop;
                    MCU_PSC1 = ~Luldeepstop;
                    MCU_PSC1 = Luldeepstop;
                    LucCount--;
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                  }while ((LucCount > MCU_ZERO) &&
                              (MCU_PROTS2 == MCU_ONE));

                  if (MCU_PROTS2 == MCU_ONE)
                  {
                    /* writing to write-protected register failed and
                     * report production error
                     */
                    Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                     DEM_EVENT_STATUS_FAILED);
                    LblDemReported = MCU_TRUE;
                  }
                }
                else
                {
                  /* no action required */
                }

                LblFlag = MCU_FALSE;
                LulLoopCount = MCU_LOOPCOUNT_MAX_VAL;

                /* MISRA Rule   : 11.3                                     */
                /* Message      : A cast should not be performed between a */
                /*                pointer type and an integral type.       */
                /* Reason       : This is to access the hardware registers */
                /*                 in the code.                            */
                /* Verification : However, the part of the code is         */
                /*                verified manually and it is not having   */
                /*                any impact on code.                      */

                /* If wakeup is due to a wakeup factor, then just wait till
                 * PSS=0 and ISO=1
                 */
                do
                {
                  if ((MCU_WUFL1 != MCU_LONG_WORD_ZERO)
                  ||(MCU_WUFM1 != MCU_LONG_WORD_ZERO)
                  ||((MCU_WUFH1 & MCU_WUFH0_MASK) != MCU_LONG_WORD_ZERO))
                  {
                    LblFlag = MCU_TRUE;
                  }
                  LulLoopCount--;
                }while ((((MCU_PWS1 & MCU_PWS_REG_MASK) != MCU_PWS_DEEPSTOP_STS)
                  && (LulLoopCount > MCU_LONG_WORD_ZERO))
                                                && (LblFlag == MCU_FALSE));

                if (LulLoopCount == MCU_LONG_WORD_ZERO)
                {
                  /*
                   * Power down mode entry failed and
                   * report production error
                   */
                  Dem_ReportErrorStatus(MCU_E_POWER_DOWN_MODE_FAILURE, \
                                                    DEM_EVENT_STATUS_FAILED);
                  LblDemReported = MCU_TRUE;
                }
                else
                {
                  /* No action required */
                }
                if ((LblFlag == MCU_TRUE) && (LblDemReported == MCU_FALSE))
                {
                  /* early wakeup of Iso1 region */
                  /* Restart Main Osc, High Speed IntOsc and Sub oscillator */
                  LenReturnValue = Mcu_RestartClocks();
                  if (LenReturnValue == E_OK)
                  {
                    /* MISRA Rule   : 11.3                                    */
                    /* Message      : A cast should not be performed between a*/
                    /*                pointer type and an integral type.      */
                    /* Reason       : This is to access the hardware registers*/
                    /*                 in the code.                           */
                    /* Verification : However, the part of the code is        */
                    /*                verified manually and it is not having  */
                    /*                any impact on code.                     */

                    /* Clear wakeup factor registers */
                    MCU_WUFCL1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL1);
                    MCU_WUFCM1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM1);
                    MCU_WUFCH1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH1);
                  }
                }
                else
                {
                  /* No action required */
                }
                /* Check if the Iso1 is already in DEEPSTOP mode  */
               if (((MCU_PWS1 & MCU_PWS_REG_MASK) == MCU_PWS_DEEPSTOP_STS) &&
                    (LblDemReported != MCU_TRUE)&& (LenReturnValue == E_OK))
                {

          /* set CPU Clock to default setting */
                  LenReturnValue = Mcu_CpuClockPrepare();

                  /* prepare the clock domains of ISO0/AWO For Deepstop mode */
                  Mcu_DeepStopPrepare();
                  /* Prepare AWO7 clock for DEEPSTOP mode */
                  Mcu_ConfigureAWO7();
                  LucCount = MCU_FIVE;

                  #if (MCU_DEEPSTOP_WAKE_PIN == STD_ON)
                  /* Set the REGSTP bit along with STP and POF bits */
                 Luldeepstop = (MCU_ISO0_DEEPSTOP_MODE_REGSTP | MCU_PSC0);
                  #else
                  /* Set only the STP and POF bits */
                 Luldeepstop = (MCU_ISO0_DEEPSTOP_MODE | MCU_PSC0);
                  #endif/*MCU_DEEPSTOP_WAKE_PIN == STD_ON*/
                  /* MISRA Rule   : 11.3                                     */
                  /* Message      : A cast should not be performed between a */
                  /*                pointer type and an integral type.       */
                  /* Reason       : This is to access the hardware registers */
                  /*                 in the code.                            */
                  /* Verification : However, the part of the code is         */
                  /*                verified manually and it is not having   */
                  /*                any impact on code.                      */
                  /* Change ISO0 from RUN to DEEPSTOP mode */
                  do
                  {
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                    /* Write the write enable register */
                    MCU_PROTCMD2 = MCU_WRITE_DATA;
                    /* MISRA Rule  : 11.3                                    */
                    /* Message     : A cast should not be performed between a*/
                    /*               pointer type and an integral type.      */
                    /* Reason      : This is to access the hardware registers*/
                    /*               in the code.                            */
                    /* Verification: However, the part of the code is        */
                    /*               verified manually and it is not having  */
                    /*               any impact on code.                     */

                    /* Make the ISO0 region enter into DEEPSTOP mode */
                    MCU_PSC0 = Luldeepstop;
                    MCU_PSC0 = ~Luldeepstop;
                    MCU_PSC0 = Luldeepstop;
                    LucCount--;
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                  }while ((LucCount > MCU_ZERO)
                                       && (MCU_PROTS2 == MCU_ONE));

                  if (MCU_PROTS2 == MCU_ONE)
                  {
                    /* writing to write-protected register failed and
                     * report production error
                     */
                    Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                   DEM_EVENT_STATUS_FAILED);
                    LblDemReported = MCU_TRUE;
                  }

                  do
                  {
                    /* Infinite loop to wait for PWSS0PSS bit of PWS0 to 0 */
                  }while (((MCU_PWS0 & MCU_PWS_DEEPSTOP_STS)
                                          == MCU_PWS_DEEPSTOP_STS));
                  /* Restore the AWO7 domain clock if deepstop entry fails */
                  Mcu_ConfigureAWO7();
                }
                else
                {
                  /* Failure in entering to Deepstop mode due to early wakeup
                   * report production error
                   */
                   Dem_ReportErrorStatus(MCU_E_POWER_DOWN_MODE_FAILURE,
                                              DEM_EVENT_STATUS_FAILED);
                }
              }
            break;

        case MCU_STOP_MODE_ISO1_ON:

              #if (MCU_DEV_ERROR_DETECT == STD_ON)
              /* if ISO1 is already in STOP mode i.e. previous mode is
               * RUN_MODE_ISO1_STOP or RUN_MODE_ISO1_DEEPSTOP
               */
              /* MISRA Rule   : 11.3                                     */
              /* Message      : A cast should not be performed between a */
              /*                pointer type and an integral type.       */
              /* Reason       : This is to access the hardware registers */
              /*                 in the code.                            */
              /* Verification : However, the part of the code is         */
              /*                verified manually and it is not having   */
              /*                any impact on code.                      */
              if ((MCU_PWS1 == MCU_MODE_ISO1_STOP)
                                       || (MCU_PWS1 == MCU_MODE_ISO1_DEEPSTOP))
              {
                /* Report to DET */
                Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID,
                                                          MCU_E_INVALID_MODE);

                /* Set the error status value to MCU_TRUE */
                LblDetErrFlag = MCU_TRUE;
              }
              else
              #endif /* #if (MCU_DEV_ERROR_DETECT == STD_ON) */
              {
                /* MISRA Rule   : 11.3                                      */
                /* Message      : A cast should not be performed between a  */
                /*                pointer type and an integral type.        */
                /* Reason       : This is to access the hardware registers  */
                /*                 in the code.                             */
                /* Verification : However, the part of the code is          */
                /*                verified manually and it is not having    */
                /*                any impact on code.                       */

                /* Prepare AWO7 clock for STOP mode */
                Mcu_ConfigureAWO7();
                /* Check if Iso1 is in RUN mode */
                if (MCU_PWS1 == MCU_ISO1_RUN_MODE)
                {
                  LucCount = MCU_FIVE;

                  /* Change ISO0 to STOP mode */
                  do
                  {
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                    /* Write the write enable register */
                    MCU_PROTCMD2 = MCU_WRITE_DATA;
                    /* MISRA Rule  : 11.3                                    */
                    /* Message     : A cast should not be performed between a*/
                    /*               pointer type and an integral type.      */
                    /* Reason      : This is to access the hardware registers*/
                    /*               in the code.                            */
                    /* Verification: However, the part of the code is        */
                    /*               verified manually and it is not having  */
                    /*               any impact on code.                     */

                    /* Make STP bit of PSC0 register true */
                    MCU_PSC0 = MCU_ISO0_STOP_MODE;
                    MCU_PSC0 = ~MCU_ISO0_STOP_MODE;
                    MCU_PSC0 = MCU_ISO0_STOP_MODE;
                    LucCount--;
                    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
                    SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
                    #endif
                  } while ((LucCount > MCU_ZERO)
                                        && (MCU_PROTS2 == MCU_ONE));

                  if (MCU_PROTS2 == MCU_ONE)
                  {
                    /* writing to write-protected register failed and
                     * report production error
                     */
                    Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                                      DEM_EVENT_STATUS_FAILED);
                  }
                }

                /* MISRA Rule   : 11.3                                      */
                /* Message      : A cast should not be performed between a  */
                /*                pointer type and an integral type.        */
                /* Reason       : This is to access the hardware registers  */
                /*                 in the code.                             */
                /* Verification : However, the part of the code is          */
                /*                verified manually and it is not having    */
                /*                any impact on code.                       */

                if ((MCU_WUFH0 != MCU_LONG_WORD_ZERO) ||
                  (MCU_WUFL0 != MCU_LONG_WORD_ZERO) ||
                  (MCU_WUFM0 != MCU_LONG_WORD_ZERO))
                {
                  /* Clear Iso0 wakeup factor registers */
                  MCU_WUFCL0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL0);
                  MCU_WUFCM0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM0);
                  MCU_WUFCH0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH0);
                }

                /* Restore the AWO7 domain clock */
                Mcu_ConfigureAWO7();
              }
            break;

        default:
            break;
      }
    }
  }
}
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_DeepStopPrepare
**
** Service ID         : None
**
** Description        : This service prepares the clocks for DeepStop mode.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : void
**
** Preconditions      : None
**
** Remarks            : Global Variable:
**                      Mcu_GpClockSetting, Mcu_GpCkscRegOffset
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : PROTCMD0, PROTS0, PLLS2, PROTCMD2, PLLE2, PROTS2, CKSC
**
*******************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(void, MCU_PRIVATE_CODE)Mcu_DeepStopPrepare(void)
{
  /* pointer to CKSC register offset */
  P2CONST(uint16, AUTOMATIC, MCU_CONFIG_CONST) LpPllCkscRegOffset;

  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) Lpval;

  uint32 LulSTPMKmask;

  uint8 LucCount = MCU_FIVE;
  uint8 LucNoOfPllCkscReg;
  boolean LblDemReported = MCU_FALSE;

  /* Get the number of PLL CKSC registers configured for Iso0*/
  LucNoOfPllCkscReg = Mcu_GpClockSetting->ucNoOfPllIso0CkscReg;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */
  /* Get pointer to the array of CKSC registers offset    */
  LpPllCkscRegOffset = Mcu_GpCkscRegOffset +
              (Mcu_GpClockSetting->ucCkscPllIndexOffset);

  LucCount = MCU_FIVE;

  while ((LucNoOfPllCkscReg > MCU_ZERO) &&
                          (LblDemReported == MCU_FALSE))
  {
    /* MISRA Rule   : 11.3                                   */
    /*Message      : A cast should not be performed between a*/
    /*               pointer to a volatile object and an     */
    /*               integral type.                          */
    /*Reason       : This is to access the hardware registers*/
    /*                in the code.                           */
    /*Verification : However, the part of the code is        */
    /*               verified manually and it is not having  */
    /*               any impact on code.                     */
    /*Get the pointer to the configured Iso0 domain pll
    CKSC register address */
    Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
            (MCU_CKSC000_BASE_ADDRESS + (*LpPllCkscRegOffset));

    /* MISRA Rule  : 11.3                                    */
    /* Message     : A cast should not be performed between a*/
    /*               pointer type and an integral type.      */
    /* Reason      : This is to access the hardware registers*/
    /*                in the code.                           */
    /* Verification: However, the part of the code is        */
    /*               verified manually and it is not having  */
    /*               any impact on code.                     */
    if (Lpval != ((uint32 *)MCU_CKSC000_ADDRESS))
    {
      /* Mask the configured STPMK Bit */
      LulSTPMKmask = ((*Lpval) & MCU_LONG_WORD_ONE);

      do
      {
        MCU_PROTCMD0 = MCU_WRITE_DATA;

        *Lpval = (LulSTPMKmask | MCU_CKSC_8MHZ_INITIAL_VAL);
        *Lpval = ~(LulSTPMKmask | MCU_CKSC_8MHZ_INITIAL_VAL);
        *Lpval = (LulSTPMKmask | MCU_CKSC_8MHZ_INITIAL_VAL);
        LucCount--;

      }while ((LucCount > MCU_ZERO) &&
                        (MCU_PROTS0 == MCU_ONE));

      if (MCU_PROTS0 == MCU_ONE)
      {
        /* writing to write-protected register failed and
         * report production error
         */
        Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                            DEM_EVENT_STATUS_FAILED);

        LblDemReported = MCU_TRUE;
      }
    }

    LucCount = MCU_FIVE;
    /* MISRA Rule         : 17.4                            */
    /* Message            : Increment or decrement operation*/
    /*                      performed on pointer.           */
    /* Reason             : Increment operator is used to   */
    /*                      achieve better throughput.      */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    /*Increment pointers to CKSC registers offset and values*/
    LpPllCkscRegOffset++;
    /* Decrement number of CKSC registers */
    LucNoOfPllCkscReg--;
  }

  /* Increment the LpPllCkscRegOffset beyond Iso1 registers */
  LpPllCkscRegOffset = (LpPllCkscRegOffset +
                        (Mcu_GpClockSetting->ucNoOfPllIso1CkscReg));

  /* Get the number of PLL CKSC registers configured for AWO */
  LucNoOfPllCkscReg = Mcu_GpClockSetting->ucNoOfPllAwoCkscReg;

  LucCount = MCU_FIVE;

  while ((LucNoOfPllCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
  {
    /* MISRA Rule   : 11.3                                     */
    /* Message      : A cast should not be performed between a */
    /*             pointer to a volatile object and an integral*/
    /*                  type.                                  */
    /* Reason       : This is to access the hardware registers */
    /*                 in the code.                            */
    /* Verification : However, the part of the code is         */
    /*                verified manually and it is not having   */
    /*                any impact on code.                      */
    /* Get the pointer to the configured Iso0 domain pll
       CKSC register address */
    Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
              (MCU_CKSC000_BASE_ADDRESS + (*LpPllCkscRegOffset));

    /* MISRA Rule  : 11.3                                    */
    /* Message     : A cast should not be performed between a*/
    /*               pointer type and an integral type.      */
    /* Reason      : This is to access the hardware registers*/
    /*                in the code.                           */
    /* Verification: However, the part of the code is        */
    /*               verified manually and it is not having  */
    /*               any impact on code.                     */

    if (Lpval == (MCU_CKSC_AW06_ADDRESS))
    {
      do
      {
        MCU_PROTCMD2 = MCU_WRITE_DATA;

        *Lpval = MCU_LONG_WORD_ZERO;
        *Lpval = ~MCU_LONG_WORD_ZERO;
        *Lpval = MCU_LONG_WORD_ZERO;
        LucCount--;
      }while ((LucCount > MCU_ZERO) &&
                         (MCU_PROTS2 == MCU_ONE));

      if (MCU_PROTS2 == MCU_ONE)
      {
        /* writing to write-protected register failed and
         * report production error
         */
        Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                              DEM_EVENT_STATUS_FAILED);

        LblDemReported = MCU_TRUE;
      }
    }
    else
    {
      /* Mask the configured STPMK Bit */
      LulSTPMKmask = ((*Lpval) & MCU_LONG_WORD_ONE);

      do
      {
        MCU_PROTCMD2 = MCU_WRITE_DATA;

        *Lpval = (LulSTPMKmask | MCU_CKSC_8MHZ_INITIAL_VAL);
        *Lpval = ~(LulSTPMKmask | MCU_CKSC_8MHZ_INITIAL_VAL);
        *Lpval = (LulSTPMKmask | MCU_CKSC_8MHZ_INITIAL_VAL);
        LucCount--;
        /*MISRA Rule   : 11.3                                    */
        /*Message      : A cast should not be performed between a*/
        /*           pointer to a volatile object and an integral*/
        /*                 type.                                 */
        /*Reason       : This is to access the hardware registers*/
        /*                in the code.                           */
        /*Verification : However, the part of the code is        */
        /*               verified manually and it is not having  */
        /*               any impact on code.                     */
      }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

      if (MCU_PROTS2 == MCU_ONE)
      {
        /* writing to write-protected register failed and
         * report production error
         */
        Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                            DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }
    }
    LucCount = MCU_FIVE;
    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */
    /* Increment pointers to CKSC registers
     * offset and values */
    LpPllCkscRegOffset++;
    /* Decrement number of CKSC registers */
    LucNoOfPllCkscReg--;
  }

  /* Get the number of PLL CKSC registers configured for Iso0*/
  LucNoOfPllCkscReg = Mcu_GpClockSetting->ucNoOfPllIso0CkscReg;

  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */
  /* Get pointer to the array of CKSC registers offset */
  LpPllCkscRegOffset = Mcu_GpCkscRegOffset +
                (Mcu_GpClockSetting->ucCkscPllIndexOffset);

  LucCount = MCU_FIVE;

  while ((LucNoOfPllCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
  {
    /* MISRA Rule   : 11.3                                   */
    /*Message      : A cast should not be performed between a*/
    /*               pointer to a volatile object and an     */
    /*               integral type.                          */
    /*Reason       : This is to access the hardware registers*/
    /*                in the code.                           */
    /*Verification : However, the part of the code is        */
    /*               verified manually and it is not having  */
    /*               any impact on code.                     */
    /*Get the pointer to the configured Iso0 domain pll
    CKSC register address */
    Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
            (MCU_CKSC000_BASE_ADDRESS + (*LpPllCkscRegOffset));

    /* MISRA Rule  : 11.3                                    */
    /* Message     : A cast should not be performed between a*/
    /*               pointer type and an integral type.      */
    /* Reason      : This is to access the hardware registers*/
    /*                in the code.                           */
    /* Verification: However, the part of the code is        */
    /*               verified manually and it is not having  */
    /*               any impact on code.                     */
    if (Lpval != ((uint32 *)MCU_CKSC000_ADDRESS))
    {
      LucCount = MCU_FIVE;
      /* MISRA Rule         : 17.4                          */
      /* Message            : Performing pointer arithmetic.*/
      /* Reason             : For code optimization.        */
      /* Verification       : However, part of the code is  */
      /*                    verified manually and it is not */
      /*                      having any impact.            */
      /*check for activation of clock domain in
           CKCSTAT_mn register*/
      while (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
              != MCU_LONG_WORD_ONE) && (LucCount > MCU_ZERO))
      {
        LucCount--;
      }

      /* Generate DEM error for Illegal clock ID*/
      if (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
             != MCU_LONG_WORD_ONE) &&
         ((*(Lpval+MCU_LONG_WORD_ONE) & MCU_CKSC_MASK_VALUE)
             != (MCU_CKSC_8MHZ_INITIAL_VAL & MCU_CKSC_MASK_VALUE)))

      {
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                  DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }
    }

    /* MISRA Rule         : 17.4                            */
    /* Message            : Increment or decrement operation*/
    /*                      performed on pointer.           */
    /* Reason             : Increment operator is used to   */
    /*                      achieve better throughput.      */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    /*Increment pointer to CKSC registers offset            */
    LpPllCkscRegOffset++;
    /* Decrement number of CKSC registers */
    LucNoOfPllCkscReg--;
  }

  /* Increment the LpPllCkscRegOffset beyond Iso1 registers */
  LpPllCkscRegOffset = (LpPllCkscRegOffset +
                        (Mcu_GpClockSetting->ucNoOfPllIso1CkscReg));

  /* Get the number of PLL CKSC registers configured for AWO */
  LucNoOfPllCkscReg = Mcu_GpClockSetting->ucNoOfPllAwoCkscReg;

  while ((LucNoOfPllCkscReg > MCU_ZERO) && (LblDemReported == MCU_FALSE))
  {
    /* MISRA Rule   : 11.3                                     */
    /* Message      : A cast should not be performed between a */
    /*             pointer to a volatile object and an integral*/
    /*                  type.                                  */
    /* Reason       : This is to access the hardware registers */
    /*                 in the code.                            */
    /* Verification : However, the part of the code is         */
    /*                verified manually and it is not having   */
    /*                any impact on code.                      */
    /* Get the pointer to the configured Iso0 domain pll
       CKSC register address */
    Lpval = (P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST))
              (MCU_CKSC000_BASE_ADDRESS + (*LpPllCkscRegOffset));

    LucCount = MCU_FIVE;
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */
    /*check for activation of clock domain in CKCSTAT_mn register*/
    if (Lpval != (MCU_CKSC_AW06_ADDRESS))
    {
      while (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
              != MCU_LONG_WORD_ONE) && (LucCount > MCU_ZERO))
      {
        LucCount--;
      }

      /* Generate DEM error for Illegal clock ID*/
      if (((*(Lpval + MCU_LONG_WORD_ONE) & MCU_LONG_WORD_ONE)
             != MCU_LONG_WORD_ONE) &&
         ((*(Lpval + MCU_LONG_WORD_ONE) & MCU_CKSC_MASK_VALUE)
             != (MCU_CKSC_8MHZ_INITIAL_VAL & MCU_CKSC_MASK_VALUE)))
      {
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                 DEM_EVENT_STATUS_FAILED);
        LblDemReported = MCU_TRUE;
      }
    }

    /* MISRA Rule         : 17.4                             */
    /* Message            : Increment or decrement operation */
    /*                      performed on pointer.            */
    /* Reason             : Increment operator is used to    */
    /*                      achieve better throughput.       */
    /* Verification       : However, part of the code is     */
    /*                      verified manually and it is not  */
    /*                      having any impact.               */
    /* Increment pointer to CKSC registers offset            */
    LpPllCkscRegOffset++;
    /* Decrement number of CKSC registers */
    LucNoOfPllCkscReg--;
  }
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_CpuClockPrepare
**
** Service ID         : None
**
** Description        : This service prepares the CPU clock for DEEPSTOP and
**                      STOP mode.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : void
**
** Preconditions      : None
**
** Remarks            : Global Variable:
**                      none
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : PROTCMD0, PROTS0, CKSC
**
*******************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_CpuClockPrepare(void)
{
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpCkscVal;

  boolean LblDemReported;

  Std_ReturnType LenReturnValue;

  uint8 LucCount;

  LblDemReported = MCU_FALSE;

  /* Initialize return value with E_OK */
  LenReturnValue = E_OK;

  /* Set the CPU clock to default setting */
  /* Get the base address of CKSC_000 clock Domain */
  LpCkscVal = (P2VAR(volatile uint32, AUTOMATIC,
                  MCU_CONFIG_CONST))(MCU_CKSC000_ADDRESS);

  Mcu_Gblckscstatus = *(LpCkscVal);

  LucCount = MCU_FIVE;

  do
  {
    MCU_PROTCMD0 = MCU_WRITE_DATA;
    /*MISRA Rule  :11.3                                     */
    /*Message     :A cast should not be performed between a */
    /*             pointer type and an integral type.       */
    /*Reason      :This is to access the hardware registers */
    /*              in the code.                            */
    /*Verification:However, the part of the code is         */
    /*             verified manually and it is not having   */
    /*             any impact on code.                      */
    /* Switch the CKSC_000 clock from PLL0 to
     * High speed Internal Oscillator */
    *LpCkscVal = MCU_CKSC000_INITIAL_VAL;
    *LpCkscVal = ~MCU_CKSC000_INITIAL_VAL;
    *LpCkscVal = MCU_CKSC000_INITIAL_VAL;
    LucCount--;
  }while ((LucCount > MCU_ZERO) &&
                    (MCU_PROTS0 == MCU_ONE));

  if (MCU_PROTS0 == MCU_ONE)
  {
    /* writing to write-protected register failed and
     * report production error
     */
     Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                        DEM_EVENT_STATUS_FAILED);

    /* Set the error status value to MCU_TRUE */
    LblDemReported = MCU_TRUE;
  }

  LucCount = MCU_FIVE;
  /* MISRA Rule         : 17.4                            */
  /* Message            : Performing pointer arithmetic.  */
  /* Reason             : For code optimization.          */
  /* Verification       : However, part of the code is    */
  /*                      verified manually and it is not */
  /*                      having any impact.              */
  /* check for activation of clock domain in CKCSTAT_mn
   * register */
  while (((*(LpCkscVal + MCU_LONG_WORD_ONE) &
          MCU_LONG_WORD_ONE) != MCU_LONG_WORD_ONE)
                    && (LucCount > MCU_ZERO))
  {
    LucCount--;
  }

  /* Generate DEM error for Illegal clock ID*/
  if ((*(LpCkscVal + MCU_LONG_WORD_ONE) & MCU_CKSC_MASK_VALUE)
      != (*LpCkscVal & MCU_CKSC_MASK_VALUE))
  {
    Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                            DEM_EVENT_STATUS_FAILED);
    /* Set the error status value to MCU_TRUE */
    LblDemReported = MCU_TRUE;
  }
  if (LblDemReported == MCU_TRUE)
  {
    LenReturnValue = E_NOT_OK;
  }

  return (LenReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_MaskClear_WakeUpFactor
**
** Service ID         : 0x0A
**
** Description        : This service Clears and Masks the wakeup registers
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : McuMode - Id for power mode setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Remarks            : Global Variable:
**                      Mcu_GblDriverStatus, Mcu_GpConfigPtr
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : WUFMSKL0, WUFMSKM0, WUFMSKH0, WUFMSKL1, WUFMSKM1
**                      WUFMSKH1, WUFCL0, WUFL0, WUFCM0, WUFM0, WUFCH0, WUFH0
**                      WUFCL1, WUFL1, WUFCM1, WUFM1, WUFCH1, WUFH1
**
******************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, MCU_PUBLIC_CODE) Mcu_MaskClear_WakeUpFactor (Mcu_ModeType McuMode)
{
  P2CONST(Tdd_Mcu_ModeSetting, MCU_CONST, MCU_CONFIG_CONST) LpModeSetting;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  Mcu_ModeType LucMode;
  Std_ReturnType LenDetErrFlag;
  #endif

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error status value with MCU_FALSE */
  LenDetErrFlag = E_NOT_OK;
  /* Report to DET, if the component is not initialized */
  if (Mcu_GblDriverStatus == MCU_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, \
                    MCU_MASKCLEAR_WAKEUPFACTOR_SID, MCU_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    LpModeSetting = \
    ((P2CONST(Tdd_Mcu_ModeSetting, MCU_CONST, MCU_CONFIG_CONST)) \
                        (Mcu_GpConfigPtr->pModeSetting) + (McuMode));

    LucMode = LpModeSetting->ucModeType;

    /* MISRA Rule   : 11.3                                          */
    /* Message      : A cast should not be performed between a      */
    /*                pointer type and an integral type.            */
    /* Reason       : This is to access the hardware registers      */
    /*                in the code.                                  */
    /* Verification : However, the part of the code is              */
    /*                verified manually and it is not having        */
    /*                any impact on code.                           */

    if (LucMode != MCU_DEEPSTOP_MODE)
    {
      /* Report to DET */
      Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, \
                    MCU_MASKCLEAR_WAKEUPFACTOR_SID, MCU_E_PARAM_MODE);
      LenDetErrFlag = E_OK;
    }
  }
  /* Check if any development error occurred */
  if (LenDetErrFlag == E_NOT_OK)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (MCU_DEV_ERROR_DETECT == STD_OFF)
    LpModeSetting = ((P2CONST(Tdd_Mcu_ModeSetting, MCU_CONST, MCU_CONFIG_CONST))
                                  (Mcu_GpConfigPtr->pModeSetting) + McuMode);
    #endif

    /* MISRA Rule   : 11.3                                          */
    /* Message      : A cast should not be performed between a      */
    /*                pointer type and an integral type.            */
    /* Reason       : This is to access the hardware registers      */
    /*                in the code.                                  */
    /* Verification : However, the part of the code is              */
    /*                verified manually and it is not having        */
    /*                any impact on code.                           */

    /* Load wake-up factor register value */
    MCU_WUFMSKL0 = LpModeSetting->ulPowerDownWakeupTypeL0;
    MCU_WUFMSKM0 = LpModeSetting->ulPowerDownWakeupTypeM0;
    MCU_WUFMSKH0 = LpModeSetting->ulPowerDownWakeupTypeH0;
    MCU_WUFMSKL1 = LpModeSetting->ulPowerDownWakeupTypeL1;
    MCU_WUFMSKM1 = LpModeSetting->ulPowerDownWakeupTypeM1;
    MCU_WUFMSKH1 = LpModeSetting->ulPowerDownWakeupTypeH1;

    /* Clear wakeup factor registers */
    MCU_WUFCL0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL0);
    MCU_WUFCM0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM0);
    MCU_WUFCH0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH0);
    MCU_WUFCL1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL1);
    MCU_WUFCM1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM1);
    MCU_WUFCH1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH1);
  }
}
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_RestartClocks
**
** Service ID         : None
**
** Description        : This service restarts the clocks for wakeup processing
**                      of Deepstop mode .
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : void
**
** Preconditions      : None
**
** Remarks            : Global Variable:
**                      none
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : MOSCST, MOSCE, MOSCS, ROSCE, PLLS0, PLLE0, PLLS1, PLLE1,
**                      SOSCE, SOSCS, PLLS2, PROTCMD2, PLLE2, PROTS2
**
******************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_RestartClocks(void)
{
  Std_ReturnType LenReturnValue;

#if (MCU_MAINOSC_ENABLE == STD_ON)
  uint32 LulMainClockStabCount;
#endif /* (MCU_MAINOSC_ENABLE == STD_ON) */
#if (MCU_SUBOSC_ENABLE == STD_ON)
  uint32 LulSubClockStabCount;
#endif /* (MCU_SUBOSC_ENABLE == STD_ON) */

  uint8 LucCount;

  LenReturnValue = E_OK;

  LucCount = MCU_FIVE;

  #if (MCU_MAINOSC_ENABLE == STD_ON)
  /* MISRA Rule  :11.3                                     */
  /* Message     :A cast should not be performed between a */
  /*              pointer type and an integral type.       */
  /* Reason      :This is to access the hardware registers */
  /*               in the code.                            */
  /* Verification:However, the part of the code is         */
  /*              verified manually and it is not having   */
  /*              any impact on code.                      */
  /* Check if main oscilltor is stopped before entering Deepstop */
  if ((MCU_MOSCE  & MCU_MAIN_OSC_MASKED) != MCU_MAIN_OSC_MASKED)
  {
    /* Set Main Oscillator stabilization time */
    MCU_MOSCST = MCU_MAINOSC_STAB;

    /* Enable the Main Oscillator */
    do
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */

      /* Writing to write enable register */
      MCU_PROTCMD2 = MCU_WRITE_DATA;
      MCU_MOSCE = MCU_LONG_WORD_ONE;
      MCU_MOSCE = ~MCU_LONG_WORD_ONE;
      MCU_MOSCE = MCU_LONG_WORD_ONE;

      LucCount--;
    } while((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

    if (MCU_PROTS2 == MCU_ONE)
    {
      /* writing to write-protected register failed and
       * report production error
       */
      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }

    /* Load the stabilization count value */
    LulMainClockStabCount = MCU_CKSC_STAB_COUNT;

    /* MISRA Rule   : 11.3                                          */
    /* Message      : A cast should not be performed between a      */
    /*                pointer type and an integral type.            */
    /* Reason       : This is to access the hardware registers      */
    /*                 in the code.                                 */
    /* Verification : However, the part of the code is              */
    /*                verified manually and it is not having        */
    /*                any impact on code.                           */
    while (((MCU_MOSCS & MCU_LONG_WORD_ONE) == MCU_LONG_WORD_ZERO) &&
                                    (LulMainClockStabCount > MCU_ZERO))
    {
      LulMainClockStabCount--;
    }

    if ((MCU_MOSCS & MCU_LONG_WORD_SEVEN) != MCU_LONG_WORD_SEVEN)

    {
      /* MainOsc failed and report production error */
      Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;

    }
  }
  #endif /* (MCU_MAINOSC_ENABLE == STD_ON) */
  #if (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON)
  /* MISRA Rule  :11.3                                     */
  /* Message     :A cast should not be performed between a */
  /*              pointer type and an integral type.       */
  /* Reason      :This is to access the hardware registers */
  /*               in the code.                            */
  /* Verification:However, the part of the code is         */
  /*              verified manually and it is not having   */
  /*              any impact on code.                      */
  /* Check if Internal Ring oscilltor is stopped before entering Deepstop */
  if (((MCU_ROSCE  & MCU_RING_OSC_MASKED) != MCU_RING_OSC_MASKED) && \
                      (LenReturnValue == E_OK))
  {
    LucCount = MCU_FIVE;
    /* MISRA Rule   : 11.3                                          */
    /* Message      : A cast should not be performed between a      */
    /*                pointer type and an integral type.            */
    /* Reason       : This is to access the hardware registers      */
    /*                 in the code.                                 */
    /* Verification : However, the part of the code is              */
    /*                verified manually and it is not having        */
    /*                any impact on code.                           */
    /* Enable the High speed Internal Ring Oscillator */
    do
    {
      /* writing to write enable register */
      MCU_PROTCMD2 = MCU_WRITE_DATA;

      MCU_ROSCE = MCU_LONG_WORD_ONE;
      MCU_ROSCE = ~MCU_LONG_WORD_ONE;
      MCU_ROSCE = MCU_LONG_WORD_ONE;

      LucCount--;
    }while((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

    if (MCU_PROTS2 == MCU_ONE)
    {
      /* writing to write-protected register failed and
       * report production error
       */
      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
  }
  #endif /* (MCU_HIGHSPEED_RINGOSC_ENABLE == STD_ON) */
  #if (MCU_SUBOSC_ENABLE == STD_ON)
  /* MISRA Rule  :11.3                                     */
  /* Message     :A cast should not be performed between a */
  /*              pointer type and an integral type.       */
  /* Reason      :This is to access the hardware registers */
  /*               in the code.                            */
  /* Verification:However, the part of the code is         */
  /*              verified manually and it is not having   */
  /*              any impact on code.                      */
  /* Check if Sub oscilltor is stopped before entering Deepstop */
  if (((MCU_SOSCE  & MCU_SUB_OSC_MASKED ) != MCU_SUB_OSC_MASKED ) && \
                      (LenReturnValue == E_OK))

  {
    LucCount = MCU_FIVE;
    /* MISRA Rule   : 11.3                                          */
    /* Message      : A cast should not be performed between a      */
    /*                pointer type and an integral type.            */
    /* Reason       : This is to access the hardware registers      */
    /*                 in the code.                                 */
    /* Verification : However, the part of the code is              */
    /*                verified manually and it is not having        */
    /*                any impact on code.                           */
    /* Enable the Sub Oscillator */
    do
    {
      /* writing to write enable register */
      MCU_PROTCMD2 = MCU_WRITE_DATA;

      MCU_SOSCE = MCU_LONG_WORD_ONE;
      MCU_SOSCE = ~MCU_LONG_WORD_ONE;
      MCU_SOSCE = MCU_LONG_WORD_ONE;

      LucCount--;

    }while ((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));


    if (MCU_PROTS2 == MCU_ONE)
    {
      /*
       * writing to write-protected register failed and
       * report production error
       */
      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
    /* Load the High Ring stabilization count value */
    LulSubClockStabCount = MCU_HIGH_RING_STAB_CNT;

    /* MISRA Rule   : 11.3                                          */
    /* Message      : A cast should not be performed between a      */
    /*                pointer type and an integral type.            */
    /* Reason       : This is to access the hardware registers      */
    /*                 in the code.                                 */
    /* Verification : However, the part of the code is              */
    /*                verified manually and it is not having        */
    /*                any impact on code.                           */
    while (((MCU_SOSCS & MCU_LONG_WORD_SEVEN) != MCU_LONG_WORD_SEVEN) && \
                (LulSubClockStabCount > MCU_ZERO))
    {
      LulSubClockStabCount--;
    }

    if ((MCU_SOSCS & MCU_LONG_WORD_SEVEN) != MCU_LONG_WORD_SEVEN)
    {
      /* SubOsc failed and report production error */
      Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  #endif /* (MCU_SUBOSC_ENABLE == STD_ON) */
  #if (MCU_PLL0_ENABLE == STD_ON)

  LucCount = MCU_FIVE;

  /* Check if PLL is inactive */
  if (((MCU_PLLS0  & MCU_PLL0_ON) != MCU_PLL0_ON) && \
                      (LenReturnValue == E_OK))
  {
    /* Enable the PLL Clock */
    do
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */

      /* Writing to write enable register */
      MCU_PROTCMD2 = MCU_WRITE_DATA;
      MCU_PLLE0 = MCU_LONG_WORD_ONE;
      MCU_PLLE0 = ~MCU_LONG_WORD_ONE;
      MCU_PLLE0 = MCU_LONG_WORD_ONE;

      LucCount--;
    } while((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

    if (MCU_PROTS2 == MCU_ONE)
    {
      /* writing to write-protected register failed and
       * report production error
       */
      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
  }
  #endif /* (MCU_PLL0_ENABLE == STD_ON) */

  #if (MCU_PLL1_ENABLE == STD_ON)

  LucCount = MCU_FIVE;

  /* Check if PLL1 is inactive */
  if (((MCU_PLLS1  & MCU_PLL1_ON) != MCU_PLL1_ON) && \
                      (LenReturnValue == E_OK))
  {
    /* Enable the PLL Clock */
    do
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */

      /* Writing to write enable register */
      MCU_PROTCMD2 = MCU_WRITE_DATA;
      MCU_PLLE1 = MCU_LONG_WORD_ONE;
      MCU_PLLE1 = ~MCU_LONG_WORD_ONE;
      MCU_PLLE1 = MCU_LONG_WORD_ONE;

      LucCount--;
    } while((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

    if (MCU_PROTS2 == MCU_ONE)
    {
      /* writing to write-protected register failed and
       * report production error
       */
      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
  }
  #endif /* (MCU_PLL1_ENABLE == STD_ON) */

  #if (MCU_PLL2_ENABLE == STD_ON)

  LucCount = MCU_FIVE;

  /* Check if PLL2 is inactive */
  if (((MCU_PLLS2  & MCU_PLL2_ON) != MCU_PLL2_ON) && \
                      (LenReturnValue == E_OK))
  {
    /* Enable the PLL Clock */
    do
    {
      /* MISRA Rule   : 11.3                                          */
      /* Message      : A cast should not be performed between a      */
      /*                pointer type and an integral type.            */
      /* Reason       : This is to access the hardware registers      */
      /*                 in the code.                                 */
      /* Verification : However, the part of the code is              */
      /*                verified manually and it is not having        */
      /*                any impact on code.                           */

      /* Writing to write enable register */
      MCU_PROTCMD2 = MCU_WRITE_DATA;
      MCU_PLLE2 = MCU_LONG_WORD_ONE;
      MCU_PLLE2 = ~MCU_LONG_WORD_ONE;
      MCU_PLLE2 = MCU_LONG_WORD_ONE;

      LucCount--;
    } while((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

    if (MCU_PROTS2 == MCU_ONE)
    {
      /* writing to write-protected register failed and
       * report production error
       */
      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
  }
  #endif /* (MCU_PLL2_ENABLE == STD_ON) */
  return (LenReturnValue);
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/******************************************************************************
** Function Name      : Mcu_Iso1SoftWakeUp
**
** Service ID         : None
**
** Description        : This service is to wake up of Iso1 by software.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Remarks            : Global Variable:
**                      none
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Register Used      : PROTCMD2, PSC1, PROTS2, WUFCL0, WUFL0, WUFCM0, WUFM0,
**                      WUFCH0, WUFH0, WUFCL1, WUFL1, WUFCM1, WUFM1, WUFCH1,
**                      WUFH1
******************************************************************************/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_Iso1SoftWakeUp(void)
{
  uint32 Luliohold;

  Std_ReturnType LenReturnValue = E_OK;

  uint8 LucCount = MCU_FIVE;

  do
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
    #endif
    /* MISRA Rule  :11.3                                     */
    /* Message     :A cast should not be performed between a */
    /*              pointer type and an integral type.       */
    /* Reason      :This is to access the hardware registers */
    /*               in the code.                            */
    /* Verification:However, the part of the code is         */
    /*              verified manually and it is not having   */
    /*              any impact on code.                      */
    /* Write the write enable register */
    MCU_PROTCMD2 = MCU_WRITE_DATA;

    /* Make ISOWU bit of PSC1 register true */
    MCU_PSC1 = MCU_PSC1_ISOWU_MSK;
    MCU_PSC1 = ~MCU_PSC1_ISOWU_MSK;
    MCU_PSC1 = MCU_PSC1_ISOWU_MSK;
    LucCount--;
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
    #endif
  }while ((LucCount > MCU_ZERO) &&
                         (MCU_PROTS2 == MCU_ONE));

  if (MCU_PROTS2 == MCU_ONE)
  {
    /* writing to write-protected register failed and
     * report production error
     */
    Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                            DEM_EVENT_STATUS_FAILED);
    LenReturnValue = E_NOT_OK;
  }

  /* Check if no Dem is reported and the function was invoked for early
   * wake-up process
   */
  if (LenReturnValue == E_OK)
  {
    /* Mask the IOHOLDCLR bit */
    Luliohold = (MCU_PSC1 | MCU_IOHOLD_CLR);

    LucCount = MCU_FIVE;

    do
    {
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      SchM_Enter_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
      #endif
      /* MISRA Rule  :11.3                                     */
      /* Message     :A cast should not be performed between a */
      /*              pointer type and an integral type.       */
      /* Reason      :This is to access the hardware registers */
      /*               in the code.                            */
      /* Verification:However, the part of the code is         */
      /*              verified manually and it is not having   */
      /*              any impact on code.                      */
      /* Write the write enable register */
      MCU_PROTCMD2 = MCU_WRITE_DATA;

      /* Make IOHLDCLR bit of PSC1 register true */
      MCU_PSC1 = Luliohold;
      MCU_PSC1 = ~Luliohold;
      MCU_PSC1 = Luliohold;
      LucCount--;
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      SchM_Exit_Mcu(MCU_PWR_MODE_PSC_PROTECTION);
      #endif
    }while ((LucCount > MCU_ZERO) &&
                           (MCU_PROTS2 == MCU_ONE));

    if (MCU_PROTS2 == MCU_ONE)
    {
      /* writing to write-protected register failed and
       * report production error
       */
      Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                                      DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }

    /* MISRA Rule  :11.3                                     */
    /* Message     :A cast should not be performed between a */
    /*              pointer type and an integral type.       */
    /* Reason      :This is to access the hardware registers */
    /*               in the code.                            */
    /* Verification:However, the part of the code is         */
    /*              verified manually and it is not having   */
    /*              any impact on code.                      */
    /* Clear wakeup factor registers for Iso0 and Iso1 */
    MCU_WUFCL0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL0);
    MCU_WUFCM0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM0);
    MCU_WUFCH0 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH0);
    MCU_WUFCL1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFL1);
    MCU_WUFCM1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFM1);
    MCU_WUFCH1 = (MCU_WAKEUP_FACTOR_CLR & MCU_WUFH1);
  }
  return (LenReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/******************************************************************************
** Function Name      : Mcu_ConfigureAWO7
**
** Service ID         : None
**
** Description        : This service modifies the AWO_7 clock for STOP/DEEPSTOP.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : void
**
** Preconditions      : None
**
** Remarks            : Global Variable:
**                      Mcu_GulCkscA07Val
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : PROTCMD2, PROTS2, CKSC
**
******************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(void, MCU_PRIVATE_CODE)Mcu_ConfigureAWO7(void)
{
  /* CKSC register value to be written */
  uint32 CkscRegVal;
  /* Count for register access */
  uint8 LucCount;

  LucCount = MCU_FIVE;
  /* Check current AWO7 settings */
  if (MCU_CKSCAO7_SLOW_VAL != MCU_CKSCAO7_REGISTER)
  {
    /* Store the CKSCA07 register value for restoring after wakeup */
    Mcu_GulCkscA07Val = MCU_CKSCAO7_REGISTER;
    /* Prepare for stop: select slow clock and STPMK = 0 */
    CkscRegVal = MCU_CKSCAO7_SLOW_VAL;
  }
  else /* Wakeup from stop: restore AWO7 clock */
  {
    /* Checking whether the stored clock is valid */
    if ((MCU_LONG_WORD_TWO == (Mcu_GulCkscA07Val & MCU_LONG_WORD_TWO)) &&
              ((Mcu_GulCkscA07Val & MCU_CKSCAO7_MASK) != MCU_CKSCAO7_MASK))
    {
      /* Stored Clock is valid */
      CkscRegVal = (Mcu_GulCkscA07Val & \
                        (MCU_CKSCAO7_MASK | MCU_LONG_WORD_ONE) );
    }
    else
    {
      /* Stored clock is invalid use default clock */
      CkscRegVal = MCU_CKSCAO7_DEFAULT_VAL;
    }
  }

  do
  {
    /* MISRA Rule   : 11.3                                   */
    /* Message      : A cast should not be performed between */
    /*                pointer type and an integral type.     */
    /* Reason       : This is to access hardware registers   */
    /*                in the code.                           */
    /* Verification : However, the part of the code is       */
    /*                verified manually and it is not having */
    /*                any impact on code.                    */
    MCU_PROTCMD2 = MCU_WRITE_DATA;

    MCU_CKSCAO7_REGISTER = CkscRegVal;
    MCU_CKSCAO7_REGISTER = ~(CkscRegVal);
    MCU_CKSCAO7_REGISTER = CkscRegVal;
    LucCount--;
  }while((LucCount > MCU_ZERO) && (MCU_PROTS2 == MCU_ONE));

  if (MCU_ONE == MCU_PROTS2)
  {
    /* writing to write-protected register failed and
     * report production error
     */
    Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    LucCount = MCU_FIVE;
    /* MISRA Rule         : 17.4                            */
    /* Message            : Performing pointer arithmetic.  */
    /* Reason             : For code optimization.          */
    /* Verification       : However, part of the code is    */
    /*                      verified manually and it is not */
    /*                      having any impact.              */

    /* check for activation of clock domain
    in CKCSTAT_mn register */
    while (((MCU_CSCSTATAO7_REGISTER & MCU_LONG_WORD_ONE)
                          != MCU_LONG_WORD_ONE) && (LucCount > MCU_ZERO))
    {
      LucCount--;
    }
    /* Generate DEM error for clock setting failure */
    if (((MCU_CSCSTATAO7_REGISTER & MCU_LONG_WORD_ONE ) != MCU_LONG_WORD_ONE) &&
        ((MCU_CSCSTATAO7_REGISTER & MCU_CKSC_MASK_VALUE ) !=
                                (CkscRegVal & MCU_CKSC_MASK_VALUE )))
    {
      Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                            DEM_EVENT_STATUS_FAILED);
    }
  }
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/******************************************************************************
** Function Name      : Mcu_CpuClockRestore
**
** Service ID         : None
**
** Description        : This service Restore the CPU clock for STOP Mode.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : void
**
** Preconditions      : None
**
** Remarks            : Global Variable:
**                      Mcu_Gblckscstatus
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : PROTCMD0, PROTS0.
**
******************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)Mcu_CpuClockRestore(void)
{
 P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpCkscVal;

 uint8 LucCount;
 Std_ReturnType LenReturnValue;
 boolean LblCkscEnable = MCU_FALSE;
 LenReturnValue = E_OK;

 /* Check the status of CPU clock its in range or not before restore Clock */
 if ((Mcu_Gblckscstatus >= MCU_LONG_WORD_TEN)&& \
                        (Mcu_Gblckscstatus <= MCU_LONG_WORD_SEVENTYFOUR))
  {
    /* Check whether CPU clock selected is Main oscillator Clock */
    if ((Mcu_Gblckscstatus == MCU_LONG_WORD_EIGHTEEN)&& \
    ((MCU_MOSCS & MCU_LONG_WORD_SEVEN) == MCU_LONG_WORD_SEVEN))
    {
     /* Set the flag to MCU_TRUE */
     LblCkscEnable = MCU_TRUE;
    }
    else
    {
     /* Set the flag to MCU_FALSE */
     LblCkscEnable = MCU_FALSE;
    }
    /* Check whether CPU clock selected is Pll0 Clock */
    if(((Mcu_Gblckscstatus > MCU_LONG_WORD_EIGHTEEN) && \
        (Mcu_Gblckscstatus < MCU_LONG_WORD_SEVENTYFOUR))&&
        (MCU_PLLS0 & MCU_LONG_WORD_SEVEN) == MCU_LONG_WORD_SEVEN)
    {
     /* Set the flag to MCU_TRUE */
     LblCkscEnable = MCU_TRUE;
    }
    else
    {
     /* Set the flag to MCU_FALSE */
     LblCkscEnable = MCU_FALSE;
    }

    /* Check whether CPU clock selected is High speed internal Clock */
    if (((Mcu_Gblckscstatus >= MCU_LONG_WORD_TEN)&& \
       (Mcu_Gblckscstatus <= MCU_LONG_WORD_TWENTYTWO))&&
    ((MCU_ROSCS & MCU_LONG_WORD_SEVEN) == MCU_LONG_WORD_SEVEN))
    {
     /* Set the flag to MCU_TRUE */
     LblCkscEnable = MCU_TRUE;
    }
    else
    {
     /* Set the flag to MCU_FALSE */
     LblCkscEnable = MCU_FALSE;
    }

    if (LblCkscEnable == MCU_TRUE)
    {
      /* Set the CPU clock to configured setting */
      /* Get the base address of CKSC_000 clock Domain */
      LpCkscVal = (P2VAR(volatile uint32, AUTOMATIC,
                        MCU_CONFIG_CONST))(MCU_CKSC000_ADDRESS);

      LucCount = MCU_FIVE;
      do
      {
        MCU_PROTCMD0 = MCU_WRITE_DATA;

        /*MISRA Rule  :11.3                                    */
        /*Message     :A cast should not be performed between a*/
        /*             pointer type and an integral type.      */
        /*Reason      :This is to access the hardware registers*/
        /*              in the code.                           */
        /*Verification:However, the part of the code is        */
        /*             verified manually and it is not having  */
        /*             any impact on code.                     */
        /* Switch the CKSC_000 clock from PLL0 to
         * High speed Internal Oscillator */
        *LpCkscVal = Mcu_Gblckscstatus;
        *LpCkscVal = ~Mcu_Gblckscstatus;
        *LpCkscVal = Mcu_Gblckscstatus;
        LucCount--;
       }while ((LucCount > MCU_ZERO) &&
          (MCU_PROTS0 == MCU_ONE));


     if (MCU_PROTS0 == MCU_ONE)
     {
       /* writing to write-protected register failed and
        * report production error
        */
        Dem_ReportErrorStatus(MCU_E_WRITE_FAILURE,
                 DEM_EVENT_STATUS_FAILED);

       /* Set the error status value to E_NOT_OK */
       LenReturnValue = E_NOT_OK;
     }

   }
   else
   {
     /* Set the error status value to E_NOT_OK */
     LenReturnValue = E_NOT_OK;
   }
 }
 return (LenReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
