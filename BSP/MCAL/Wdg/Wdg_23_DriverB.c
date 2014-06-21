/*============================================================================*/
/* Project      = AUTOSAR NEC Xx4 MCAL Components                             */
/* Module       = Wdg_23_DriverB.c                                            */
/* Version      = 3.0.4                                                       */
/* Date         = 06-Mar-2010                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009 by NEC Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* Driver code of the Watchdog Driver B Component                             */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* NEC Electronics Corporation the following shall apply!                     */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by NEC. Any warranty   */
/* is expressly disclaimed and excluded by NEC, either expressed or implied,  */
/* including but not limited to those for non-infringement of intellectual    */
/* property, merchantability and/or fitness for the particular purpose.       */
/*                                                                            */
/* NEC shall not have any obligation to maintain, service or provide bug      */
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
/* In no event shall NEC be liable to the User for any incidental,            */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. NEC shall not be liable for any services or products         */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by NEC in connection with the Product(s) and/or the   */
/* Application.                                                               */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        Xx4                                           */
/*              Compiler:       GHS V5.1.6c                                   */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:  12-Jun-2009  : Initial Version
 *
 * V3.0.1:  14-Jul-2009  : As per SCR 015, compiler version is changed from
 *                         V5.0.5 to V5.1.6c in the header of the file.
 *
 * V3.0.2:  22-Feb-2010  : As per SCR 196, initializing the timer counter
 *                         register is done in Wdg_Init() API.
 *
 * V3.0.3:  25-Feb-2010  : As per SCR 198, watchdog timer is started in
 *                         Wdg_SetMode() API.
 *
 * V3.0.4:  06-Mar-2010  : As per SCR 219, Wdg_SetMode() API is updated
 *                         to start watchdog after setting the requested mode.
 */
/******************************************************************************/


/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

#include "Wdg_23_DriverB.h"
#include "Wdg_23_DriverB_PBTypes.h"

#if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#include "Dem.h"
#include "Wdg_23_DriverB_Ram.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/

/* AUTOSAR specification version information */
#define WDG_23_DRIVERB_C_AR_MAJOR_VERSION  WDG_23_DRIVERB_AR_MAJOR_VERSION_VALUE
#define WDG_23_DRIVERB_C_AR_MINOR_VERSION  WDG_23_DRIVERB_AR_MINOR_VERSION_VALUE
#define WDG_23_DRIVERB_C_AR_PATCH_VERSION  WDG_23_DRIVERB_AR_PATCH_VERSION_VALUE

/* File version information */
#define WDG_23_DRIVERB_C_SW_MAJOR_VERSION  3
#define WDG_23_DRIVERB_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (WDG_23_DRIVERB_AR_MAJOR_VERSION != WDG_23_DRIVERB_C_AR_MAJOR_VERSION)
  #error "Wdg_23_DriverB.c : Mismatch in Specification Major Version"
#endif
#if (WDG_23_DRIVERB_AR_MINOR_VERSION != WDG_23_DRIVERB_C_AR_MINOR_VERSION)
  #error "Wdg_23_DriverB.c : Mismatch in Specification Minor Version"
#endif
#if (WDG_23_DRIVERB_AR_PATCH_VERSION != WDG_23_DRIVERB_C_AR_PATCH_VERSION)
  #error "Wdg_23_DriverB.c : Mismatch in Specification Patch Version"
#endif


#if (WDG_23_DRIVERB_SW_MAJOR_VERSION != WDG_23_DRIVERB_C_SW_MAJOR_VERSION)
  #error "Wdg_23_DriverB.c : Mismatch in Major Version"
#endif
#if (WDG_23_DRIVERB_SW_MINOR_VERSION != WDG_23_DRIVERB_C_SW_MINOR_VERSION)
  #error "Wdg_23_DriverB.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Wdg_23_DriverBInit
**
** Service ID         : 0x00
**
** Description        : This service initialise the Watchdog driver and
**                      hardware.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ConfigPtr Pointer to the configuration
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return Parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable(s):
**                      Wdg_23_DriverB_GpConfigPtr,
**                      Wdg_GddDriverState,
**                      Wdg_GddCurrentMode
**                      Function(s) invoked:
**                      Det_ReportError
**                      Dem_ReportErrorStatus
*******************************************************************************/

#define WDG_23_DRIVERB_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, WDG_23_DRIVERB_PUBLIC_CODE) Wdg_23_DriverBInit
(P2CONST(Wdg_23_DriverB_ConfigType, AUTOMATIC, WDG_23_DRIVERB_APPL_CONST)
  ConfigPtr)
{
  #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)

  /* Report Error to DET, if the config pointer value is NULL */
  if (ConfigPtr == NULL_PTR)
  {
    /* Report Error to DET */
    Det_ReportError(WDG_23_DRIVERB_MODULE_ID,WDG_23_DRIVERB_INSTANCE_ID,
                 WDG_23_DRIVERB_INIT_SID, WDG_23_DRIVERB_E_PARAM_CONFIG);
  }
  else
  #endif /* (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether the existing database is correct */
    if ((ConfigPtr->ulStartOfDbToc) == WDG_23_DRIVERB_DBTOC_VALUE)
    {
      /* Assign the config pointer value to global pointer */
      Wdg_23_DriverB_GpConfigPtr = ConfigPtr;

      /* Check whether Watchdog disable is allowed */
      #if (WDG_23_DRIVERB_DISABLE_ALLOWED == STD_OFF)
      if(Wdg_23_DriverB_GpConfigPtr->ucWdtamdDefaultMode == WDGIF_OFF_MODE)
      {
        /* Report Error to DEM */
        Dem_ReportErrorStatus(WDG_23_DRVB_E_DISABLE_REJECTED,
                                          DEM_EVENT_STATUS_FAILED);
      }
      else
      #endif
      {
        /* To check whether the default mode is OFF mode */
        if (Wdg_23_DriverB_GpConfigPtr->ucWdtamdDefaultMode == WDGIF_OFF_MODE)
        {
          /* Set current mode as OFF mode */
          Wdg_GddCurrentMode = WDGIF_OFF_MODE;
        }
        else
        {
          /* To check whether the default mode is SLOW mode */
        if (Wdg_23_DriverB_GpConfigPtr->ucWdtamdDefaultMode == WDGIF_SLOW_MODE)
          {
            /* MISRA Rule         : 11.3                                      */
            /* Message            : Type casting from any type to or from     */
            /*                      pointers shall not be used.               */
            /* Reason             : To access hardware registers              */
            /* Verification       : However, part of the code is verified     */
            /*                      manually and it is not having any impact. */

            /* Set configured slow mode value to Mode register */
            WDG_23_DRIVERB_WDTAMD_ADDRESS =
                      Wdg_23_DriverB_GpConfigPtr->ucWdtamdSlowValue;
            /* Set current mode as slow mode */
            Wdg_GddCurrentMode = WDGIF_SLOW_MODE;
          }
          else
          {
            /* MISRA Rule         : 11.3                                      */
            /* Message            : Type casting from any type to or from     */
            /*                      pointers shall not be used.               */
            /* Reason             : To access hardware registers              */
            /* Verification       : However, part of the code is verified     */
            /*                      manually and it is not having any impact. */

            /* Set configured slow mode value to Mode register */
            WDG_23_DRIVERB_WDTAMD_ADDRESS =
                      Wdg_23_DriverB_GpConfigPtr->ucWdtamdFastValue;
            /* Set current mode as fast mode */
            Wdg_GddCurrentMode = WDGIF_FAST_MODE;
          }

          /* Check whether Varying Activation Code is enabled or disabled */
          #if (WDG_23_DRIVERB_VAC_ALLOWED == STD_OFF)

          /* MISRA Rule         : 11.3                                        */
          /* Message            : Type casting from any type to or from       */
          /*                      pointers shall not be used.                 */
          /* Reason             : To access hardware registers                */
          /* Verification       : However, part of the code is verified       */
          /*                      manually and it is not having any impact.   */

          /* Initialise the register with preconfigured value */
          WDG_23_DRIVERB_WDTAWDTE_ADDRESS = WDG_23_DRIVERB_RESTART;

          #else
          /* MISRA Rule         : 11.3                                        */
          /* Message            : Type casting from any type to or from       */
          /*                      pointers shall not be used.                 */
          /* Reason             : To access hardware registers                */
          /* Verification       : However, part of the code is verified       */
          /*                      manually and it is not having any impact.   */

          /* Initialise VAC register */
          WDG_23_DRIVERB_WDTAEVAC_ADDRESS = WDG_23_DRIVERB_RESTART -
                                                 WDG_23_DRIVERB_WDTAREF_ADDRESS;
          #endif /* WDG_23_DRIVERB_VAC_ALLOWED == STD_OFF */
        }

        /* Check if WDG_23_DRIVERB_DEV_ERROR_DETECT is enabled */
        #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)
        /* Set the state of Watchdog as idle */
        Wdg_GddDriverState = WDG_IDLE;
        #endif
      }
    }
    #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* Report Error to DET */
      Det_ReportError(WDG_23_DRIVERB_MODULE_ID,WDG_23_DRIVERB_INSTANCE_ID,
        WDG_23_DRIVERB_INIT_SID, WDG_23_DRVB_E_INVALID_DATABASE);
    } /* End of Check to check database */
    #endif
  }
}

#define WDG_23_DRIVERB_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Wdg_23_DriverBSetMode
**
** Service ID         : 0x01
**
** Sync/Async         : Synchronous
**
** Description        : This service change the mode of the Watchdog timer
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : WdgIf_ModeType  Mode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return Parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable(s):Wdg_GddDriverState,
**                      Wdg_GddCurrentMode
**                      Function(s) Invoked:
**                      Dem_ReportErrorStatus
**                      Det_ReportError
*******************************************************************************/

#define WDG_23_DRIVERB_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType,  WDG_23_DRIVERB_PUBLIC_CODE) Wdg_23_DriverBSetMode
  (WdgIf_ModeType Mode)
{
  Std_ReturnType LenReturnValue = E_OK;
  boolean LblRestartFlag = WDG_FALSE;

  /* Report Error to DET, if state of Watchdog is not idle */
  #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)
  if (Wdg_GddDriverState != WDG_IDLE)
  {
    /* Report Error to DET */
    Det_ReportError(WDG_23_DRIVERB_MODULE_ID, WDG_23_DRIVERB_INSTANCE_ID,
                  WDG_23_DRIVERB_SETMODE_SID, WDG_23_DRIVERB_E_DRIVER_STATE);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  /* MISRA Rule           : 13.7                                            */
  /*   Message            : The result of this logical operation is always  */
  /*                        'false'. The value of this control expression   */
  /*                        is always 'false'.                              */
  /*   Reason             : Since e-num type is used it is not possible to  */
  /*                        provide out of range value but as per AUTOSAR   */
  /*                        all the input paramters of an API have to be    */
  /*                        verified.                                       */
  /*   Verification       : However, part of the code is verified manually  */
  /*                        and it is not giving any impact                 */

  /* MISRA Rule           : 14.1                                            */
  /*   Message            : This statement is unreachable.                  */
  /*   Reason             : Since e-num type is used it is not possible to  */
  /*                        provide out of range value but as per AUTOSAR   */
  /*                        all the input paramters of an API have to be    */
  /*                        verified.                                       */
  /*   Verification       : However, part of the code is verified manually  */
  /*                        and it is not giving any impact                 */

  /* Check whether input parameter 'Mode' is within the range */
  if(Mode > WDGIF_FAST_MODE)
  {
    /* Report Error to DET, if the parameter mode is not within the range */
    Det_ReportError(WDG_23_DRIVERB_MODULE_ID, WDG_23_DRIVERB_INSTANCE_ID,
                  WDG_23_DRIVERB_SETMODE_SID, WDG_23_DRIVERB_E_PARAM_MODE);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }

  if(LenReturnValue == E_OK)
  #endif /* #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)
    /* Set the state of Watchdog as busy */
    Wdg_GddDriverState = WDG_BUSY;
    #endif

    /* Switching the Watchdog Mode from OFF to SLOW */
    if ((Wdg_GddCurrentMode == WDGIF_OFF_MODE) && (Mode == WDGIF_SLOW_MODE))
    {
      /* MISRA Rule         : 11.3                                            */
      /* Message            : Type casting from any type to or from           */
      /*                      pointers shall not be used.                     */
      /* Reason             : To access hardware registers                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Set configured slow mode value to Mode register */
      WDG_23_DRIVERB_WDTAMD_ADDRESS =
                                 Wdg_23_DriverB_GpConfigPtr->ucWdtamdSlowValue;
      /* Set current mode value as slow */
      Wdg_GddCurrentMode = WDGIF_SLOW_MODE;
      /* Set Return Value as E_OK */
      LenReturnValue = E_OK;
      /* Set the restart flag */
      LblRestartFlag = WDG_TRUE;
    }
    /* Switching the Watchdog Mode from OFF to FAST */
    else if ((Wdg_GddCurrentMode == WDGIF_OFF_MODE) &&
                                                     (Mode == WDGIF_FAST_MODE))
    {
      /* MISRA Rule         : 11.3                                            */
      /* Message            : Type casting from any type to or from           */
      /*                      pointers shall not be used.                     */
      /* Reason             : To access hardware registers                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Set configured fast mode value to Mode register */
      WDG_23_DRIVERB_WDTAMD_ADDRESS =
                                 Wdg_23_DriverB_GpConfigPtr->ucWdtamdFastValue;
      /* Set current mode value as fast */
      Wdg_GddCurrentMode = WDGIF_FAST_MODE;
      /* Set Return Value as E_OK */
      LenReturnValue = E_OK;
      /* Set the restart flag */
      LblRestartFlag = WDG_TRUE;
    }
    /* Switching the Watchdog Mode from FAST to FAST / SLOW to SLOW */
    else if (Wdg_GddCurrentMode == Mode)
    {
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_OK;
    }
    else
    {
      /* Report Error to DEM */
      Dem_ReportErrorStatus(WDG_23_DRVB_E_MODE_SWITCH_FAILED,
                                                      DEM_EVENT_STATUS_FAILED);
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }

    /* Start the Watchdog Driver if the restart flag is true */
    if(LblRestartFlag == WDG_TRUE)
    {
      /* Check whether Varying Activation Code is enabled or disabled */
      #if (WDG_23_DRIVERB_VAC_ALLOWED == STD_OFF)

      /* MISRA Rule         : 11.3                                       */
      /* Message            : Type casting from any type to or from      */
      /*                      pointers shall not be used.                */
      /* Reason             : To access hardware registers               */
      /* Verification       : However, part of the code is verified      */
      /*                      manually and it is not having any impact.  */

      /* Initialise the register with preconfigured value */
      WDG_23_DRIVERB_WDTAWDTE_ADDRESS = WDG_23_DRIVERB_RESTART;

      #else
      /* MISRA Rule         : 11.3                                       */
      /* Message            : Type casting from any type to or from      */
      /*                      pointers shall not be used.                */
      /* Reason             : To access hardware registers               */
      /* Verification       : However, part of the code is verified      */
      /*                      manually and it is not having any impact.  */

      /* Initialise VAC register */
      WDG_23_DRIVERB_WDTAEVAC_ADDRESS = WDG_23_DRIVERB_RESTART -
                                             WDG_23_DRIVERB_WDTAREF_ADDRESS;
      #endif /* WDG_23_DRIVERB_VAC_ALLOWED == STD_OFF */
    }

    /* Set Watchdog Driver State to IDLE after Mode Switch operation */
    #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)
    /* Set the state of Watchdog as idle */
    Wdg_GddDriverState = WDG_IDLE;
    #endif  /* (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON) */
  }
  return(LenReturnValue);
}

#define WDG_23_DRIVERB_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Wdg_23_DriverBTrigger
**
** Service ID         : 0x02
**
** Sync/Async         : Synchronous
**
** Description        : This service is used to trigger the Watchdog timer
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return Parameter   : None
**
** Preconditions      : Wdg_23_DriverBInit must be called before this function
**
** Remarks            : Global Variable(s):
**                      Wdg_GddDriverState
**                      Function(s) Invoked:
**                      Det_ReportError
**
*******************************************************************************/

#define WDG_23_DRIVERB_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, WDG_23_DRIVERB_PUBLIC_CODE) Wdg_23_DriverBTrigger(void)
{
  /* Check if DET is enabled */
  #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)
  /* Check whether Watchdog is in idle state */
  if (Wdg_GddDriverState != WDG_IDLE)
  {
    /* Report to DET, if Watchdog is not in idle state */
    Det_ReportError(WDG_23_DRIVERB_MODULE_ID, WDG_23_DRIVERB_INSTANCE_ID,
            WDG_23_DRIVERB_TRIGGER_SID, WDG_23_DRIVERB_E_DRIVER_STATE);
  }
  else
  #endif
  {
    #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)
    /* Set the state of Watchdog as busy */
    Wdg_GddDriverState = WDG_BUSY;
    #endif /* WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON */

    /* Check whether Varying Activation Code is enabled */
    #if (WDG_23_DRIVERB_VAC_ALLOWED == STD_OFF)

    /* MISRA Rule         : 11.3                                              */
    /* Message            : Type casting from any type to or from             */
    /*                      pointers shall not be used.                       */
    /* Reason             : To access hardware registers                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */


    /* Initialise the register with preconfigured value */
    WDG_23_DRIVERB_WDTAWDTE_ADDRESS = WDG_23_DRIVERB_RESTART;

    #else
    /* MISRA Rule         : 11.3                                              */
    /* Message            : Type casting from any type to or from             */
    /*                      pointers shall not be used.                       */
    /* Reason             : To access hardware registers                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

    /* Initialise VAC register */
    WDG_23_DRIVERB_WDTAEVAC_ADDRESS = WDG_23_DRIVERB_RESTART -
                                                WDG_23_DRIVERB_WDTAREF_ADDRESS;
    #endif /* WDG_23_DRIVERB_VAC_ALLOWED == STD_OFF */

    #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)
    /* Set the state of Watchdog as idle */
    Wdg_GddDriverState = WDG_IDLE;
    #endif /* WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON */
  }
}
#define WDG_23_DRIVERB_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Wdg_23_DriverBGetVersionInfo
**
** Service ID         : 0x04
**
** Sync/Async         : Synchronous
**
** Description        : This service returns the version information of Watchdog
**                      Driver Component
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : versioninfo
**
** Return Parameter   : None
**
** Preconditions      : None
**
** Remarks            : Global Variable(s):
**                      None
**                      Function(s) Invoked:
**                      Det_ReportError
**
*******************************************************************************/

#if (WDG_23_DRIVERB_VERSION_INFO_API == STD_ON)

#define WDG_23_DRIVERB_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC (void, WDG_23_DRIVERB_PUBLIC_CODE) Wdg_23_DriverBGetVersionInfo
 (P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_23_DRIVERB_APPL_DATA)versioninfo)
{
  #if (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON)
   /* Check whether Version Information is equal to Null Ptr */
  if(versioninfo == NULL_PTR)
  {
    /* Report to DET  */
    Det_ReportError(WDG_23_DRIVERB_MODULE_ID, WDG_23_DRIVERB_INSTANCE_ID,
      WDG_23_DRIVERB_GETVERSIONINFO_SID, WDG_23_DRIVERB_E_PARAM_POINTER);
  }
  else
  #endif  /* (WDG_23_DRIVERB_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = WDG_23_DRIVERB_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = WDG_23_DRIVERB_MODULE_ID;
    /* Copy the instance Id */
    versioninfo->instanceID = WDG_23_DRIVERB_INSTANCE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = WDG_23_DRIVERB_SW_MAJOR_VERSION_VALUE;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = WDG_23_DRIVERB_SW_MINOR_VERSION_VALUE;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = WDG_23_DRIVERB_SW_PATCH_VERSION_VALUE;
  }
}

#define WDG_23_DRIVERB_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (WDG_23_DRIVERB_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
