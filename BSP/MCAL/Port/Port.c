/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Port.c                                                      */
/* Version      = 3.1.9                                                       */
/* Date         = 02-Sep-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* API function implementations of PORT Driver                                */
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
 * V3.0.0:  27-Jul-2009  : Initial Version
 *
 * V3.0.1:  07-Sep-2009  : As per SCR 026 and SCR 036, Port_InitConfig API is
 *                         updated to follow the write protection for 32 bit
 *                         write protected registers PODC, PDSC, PUCC and PSBC.
 *
 * V3.0.2:  31-Oct-2009  : As per SCR 071, check for IOHLDCLR bit is added
 *                         to check the functionality of restoring the
 *                         settings of PORT registers after wake-up from
 *                         deep stop mode in Port_Init().
 *
 * V3.0.3:  13-Nov-2009  : As per SCR 105 and 120, the code is updated to
 *                         support Px4 variant.
 *
 * V3.0.4:  23-Feb-2010  : As per SCR 189, updated for Port Filter Functionality
 *                         implementation.
 *
 * V3.0.5:  03-Mar-2010  : As per SCR 210, following modifications are done:
 *                         1. Port filter configuration is removed from
 *                            Port_InitConfig and separate function
 *                            Port_FilterConfig() is added for that task.
 *                         2. Writing of protected registers is updated to avoid
 *                            the hanging possibility during Port initialization
 *
 * V3.0.6:  05-Apr-2010  : As per SCR 245, following modifications are done:
 *                         1. Port_Init API is updated to remove the check
 *                            whether reset is occurred due to deep stop mode.
 *                         2. Port_InitConfig function is updated to skip the
 *                            re-initialization of the port configuration
 *                            which is restored by Mcu_Init when deepstop reset
 *                            occurs.
 *                         3. Port_SetPinMode API is updated to add the PSR
 *                            register settings.
 * V3.0.7:  15-Apr-2010  : As per SCR 254, Port_InitConfig function is corrected
 *                         to skip re-initialization of PSR register settings
 *                         when deepstop reset occurs.
 * V3.0.8:  15-Mar-2011  : As per SCR 423, in Port_InitConfig API data type of
 *                         PPCMD register is modified to update 8 bit values.
 * V3.0.9:  08-Apr-2011  : As per SCR 428, Port_InitConfig function is updated
 *                         for setting direction register before function
 *                         control register.
 * V3.0.10: 24-Jun-2011  : As per SCR 479, following modifications are done:
 *                         1. Function Port_RefreshPortInternal is updated
 *                            for removing unnecessary Read-Modify-Write
 *                            access of PMSR register.
 *                         2. Function Port_SetPinDirection is updated for
 *                            removing unnecessary SchM protection since
 *                            PMSR register is used and for removing
 *                            unnecessary Read-Modify-Write access of PMSR
 *                            register.
 *                         3. Function Port_SetPinMode is updated for
 *                            adding SchM protection to assure atomic access and
 *                            for removing unnecessary Read-Modify-Write access
 *                            of PMCSR and PSR registers.
 * V3.1.0: 26-Jul-2011   : Initial Version DK4-H variant
 * V3.1.1: 15-Sep-2011   : As per the DK-4H requirements
 *                         1. Added DK4-H specific JTAG information.
 *                         2. Added compiler switch for USE_UPD70F3529 device
 *                            name.
 *                         3. Corrected the address calculation for JPDOC and
 *                            JPDSC registers.
 *                         4. Corrected the address calculation for the JTAG
 *                            protection registers.
 * V3.1.2: 08-Oct-2011  : 1. Added curly brackets for the if condition used for
 *                           address calculation.
 *                        2. Added check for registers PSC1 and PWS1.
 *                        3. Added comments for the violation of MISRA rule.
 * V3.1.3:  16-Feb-2012  :  Merged the fixes done for Fx4L
 * V3.1.4:  06-Jun-2012  : As per SCR 033, following changes are made:
 *                         1. Port_GetVersionInfo API is removed.
 *                         2. Compiler version is removed from Environment
 *                            section.
 *                         3. DET error check conditional branch is corrected.
 * V3.1.5:  10-Jul-2012  : As per SCR 047, in Port_InitConfig, handling of
 *                         JPODC, JPSBC, JPUCC and JPSBC registers are
 *                         corrected.
 * V3.1.6:  27-Nov-2012  : As per MNT_0007541, in Port_InitConfig ,removed
 *                         compiler switch for USE_UPD70F3529 device name .
 * V3.1.7:  11-Dec-2012  : 1.As per MNT_0005397 and MNT_0005415, updated
 *                           Port_Init function to release IO buffer Reset
 *                           during Port initialization.
 *                         2.As per MNT_0005117 , Updated Port_InitConfig
 *                           function.
 * V3.1.7a: 19-Feb-2013  : Merged the fixes done for Sx4-H
 * V3.1.8:  08-Apr-2013  : As per SCR 80 for the mantis issue #5399,Port_Init
 *                         API is updated to correct PORT_IOHOLD_SET and
 *                         PORT_IOHOLD_CLR functionality.
 * V3.1.9:  02-Sep-2013  : Updated Port_Init function.
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Port.h"
#include "Port_Ram.h"
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#include "Dem.h"
#if(PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Port.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_C_AR_MAJOR_VERSION     PORT_AR_MAJOR_VERSION_VALUE
#define PORT_C_AR_MINOR_VERSION     PORT_AR_MINOR_VERSION_VALUE
#define PORT_C_AR_PATCH_VERSION     PORT_AR_PATCH_VERSION_VALUE

/* File version information */
#define PORT_C_SW_MAJOR_VERSION    3
#define PORT_C_SW_MINOR_VERSION    1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (PORT_AR_MAJOR_VERSION != PORT_C_AR_MAJOR_VERSION)
  #error "Port.c : Mismatch in Specification Major Version"
#endif
#if (PORT_AR_MINOR_VERSION != PORT_C_AR_MINOR_VERSION)
  #error "Port.c : Mismatch in Specification Minor Version"
#endif
#if (PORT_AR_PATCH_VERSION != PORT_C_AR_PATCH_VERSION)
  #error "Port.c : Mismatch in Specification Patch Version"
#endif

#if (PORT_SW_MAJOR_VERSION != PORT_C_SW_MAJOR_VERSION)
  #error "Port.c : Mismatch in Major Version"
#endif
#if (PORT_SW_MINOR_VERSION != PORT_C_SW_MINOR_VERSION)
  #error "Port.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                  Function Prototypes                                       **
*******************************************************************************/

#define PORT_START_SEC_PRIVATE_CODE
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

STATIC FUNC(void, PORT_PRIVATE_CODE) Port_InitConfig
                                                 (Port_GroupType LenGroupType);

#if((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
STATIC FUNC(void, PORT_PRIVATE_CODE) Port_FilterConfig(void);
#endif

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
STATIC
FUNC(P2CONST(Tdd_Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
    ,PORT_PRIVATE_CODE) Port_SearchDirChangeablePin(Port_PinType LddPinNumber,
     P2CONST(Tdd_Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
     LpStartPtr, uint8 Lucsize);
#endif

STATIC FUNC(void, PORT_PRIVATE_CODE) Port_RefreshPortInternal
                                                 (Port_GroupType LenGroupType);

#if (PORT_SET_PIN_MODE_API == STD_ON)
STATIC
FUNC(P2CONST(Tdd_Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
    , PORT_PRIVATE_CODE) Port_SearchModeChangeablePin(Port_PinType LddPinNumber,
     P2CONST(Tdd_Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
     LpStartPtr, uint8 Lucsize);
#endif
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
**                  Function Definitions                                      **
*******************************************************************************/

#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
/*******************************************************************************
** Function Name        : Port_Init
**
** Service ID           : 0x00
**
** Description          : This service performs initialization of the PORT
**                        Driver components.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
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
**                        Port_GblDriverStatus,Port_GpConfigPtr
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
FUNC(void, PORT_PUBLIC_CODE) Port_Init
(P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr)
{
  #if (((PORT_PWS0_ENABLE == STD_ON) && (PORT_PSC0_ENABLE == STD_ON)) \
    || ((PORT_PWS1_ENABLE == STD_ON) && (PORT_PSC1_ENABLE == STD_ON)))
  uint32 Luliohold;
  uint8 LucLoopCount;
  #endif /*(((PORT_PWS0_ENABLE == STD_ON) && (PORT_PWS1_ENABLE == STD_ON))
            || ((PORT_PSC0_ENABLE == STD_ON) && (PORT_PSC1_ENABLE == STD_ON)))*/
  
  #if(PORT_IORES0_ENABLE == STD_ON)
   uint8 LucCount;
   #endif

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the config pointer is NULL pointer */
  if (ConfigPtr == NULL_PTR)
  {
    /* Report to DET */
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                                            PORT_E_PARAM_CONFIG);
  }
  else
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    if ((ConfigPtr->ulStartOfDbToc) == PORT_DBTOC_VALUE)
    {
      /* MISRA Rule         : 11.3                                            */
      /* Message            : A cast should not be performed between a        */
      /*                      pointer type and an integral type.              */
      /* Reason             : This is to access the hardware registers.       */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */
      /* Assign the global pointer with the config pointer */
      Port_GpConfigPtr = ConfigPtr;
      /* Check for available Port Group Type(Numeric Port) */
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)

      /* Invoking Port_InitConfig() API with Numeric Port Group data */
      Port_InitConfig(PORT_GROUP_NUMERIC);

      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(Alphabetic Port) */
      #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)

      /* Invoking Port_InitConfig() API with Alphabetic Port Group data */
      Port_InitConfig(PORT_GROUP_ALPHABETIC);

      #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(JTag Port) */
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)

      /* Invoking Port_InitConfig() API with JTag Port Group data */
      Port_InitConfig(PORT_GROUP_JTAG);

      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */

      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* Set the Port status to initialized */
      Port_GblDriverStatus = PORT_INITIALIZED;
      #endif

      #if((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
      /* Invoking Port_FilterConfig() for configuration of filter registers */
      Port_FilterConfig();
      #endif
      #if(PORT_IORES0_ENABLE == STD_ON)

      /* Release IO buffer reset */
      LucCount = PORT_TEN;
      do
      {
        /* Write the write enable register */
        PORT_PROTCMD3 = PORT_WRITE_ERROR_CLEAR_VAL;

        /* MISRA Rule   : 11.3                                       */
        /* Message      : A cast should not be performed between a   */
        /*                pointer type and an integral type.         */
        /* Reason       : This is to access the hardware registers   */
        /*                in the code.                               */
        /* Verification : However, the part of the code is           */
        /*                verified manually and it is not having     */
        /*                any impact on code.                        */

        /* Make IOHLDCLR bit of PSC1 register true */
        PORT_IORES0 = PORT_IORES_CLR;
        PORT_IORES0 = ~PORT_IORES_CLR;
        PORT_IORES0 = PORT_IORES_CLR;
        LucCount--;
      }while((LucCount > PORT_ZERO)&&(PORT_PROTS3 == PORT_ONE));

      if(PORT_PROTS3 == PORT_ONE)
      {
        /* writing to write-protected register failed and
         * report production error
         */
        Dem_ReportErrorStatus(PORT_E_WRITE_FAILURE,
                                             DEM_EVENT_STATUS_FAILED);
      }
      else
      {
         /*For MISRA C compliance */
      }
      #endif /* PORT_IORES0_ENABLE == STD_ON */
      
      #if ((PORT_PWS0_ENABLE == STD_ON) && (PORT_PSC0_ENABLE == STD_ON))
      /* Check for IOHOLD of ISO0 */
      /* MISRA Violation: START Msg(6:0303)-1 */
      if ((PORT_PWS0 & PORT_IOHOLD_SET) == PORT_IOHOLD_SET)
      {
        /* Mask the IOHOLDCLR bit */
        Luliohold = (PORT_PSC0 | PORT_IOHOLD_CLR);
        LucLoopCount = PORT_TEN;
        do
        {
        /* Write the write enable register */
        PORT_PROTCMD2 = PORT_WRITE_ERROR_CLEAR_VAL;

        /* MISRA Rule   : 11.3                                       */
        /* Message      : A cast should not be performed between a   */
        /*                pointer type and an integral type.         */
        /* Reason       : This is to access the hardware registers   */
        /*                in the code.                               */
        /* Verification : However, the part of the code is           */
        /*                verified manually and it is not having     */
        /*                any impact on code.                        */

        /* Make IOHLDCLR bit of PSC1 register true */
        PORT_PSC0 = Luliohold;
        PORT_PSC0 = ~Luliohold;
        PORT_PSC0 = Luliohold;
        LucLoopCount--;
        }while((LucLoopCount > PORT_ZERO)&&(PORT_PROTS2 == PORT_ONE));

        if(PORT_PROTS2 == PORT_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(PORT_E_WRITE_FAILURE,
                                               DEM_EVENT_STATUS_FAILED);
        }
        else
        {
           /*For MISRA C compliance */
        }
      }
      else
      {
        /*For MISRA C compliance */
      }
      #endif /* End of ((PORT_PWS0_ENABLE == STD_ON) &&
                                                (PORT_PSC0_ENABLE == STD_ON)) */
      #if ((PORT_PWS1_ENABLE == STD_ON) && (PORT_PSC1_ENABLE == STD_ON))
      /* Mask the IOHOLDCLR bit */
      if ((PORT_PWS1 & PORT_IOHOLD_SET)==PORT_IOHOLD_SET)
      {
        /* Mask the IOHOLDCLR bit */
        Luliohold = (PORT_PSC1 | PORT_IOHOLD_CLR);
        LucLoopCount = PORT_TEN;
        do
        {
          /* Write the write enable register */
          PORT_PROTCMD2 = PORT_WRITE_ERROR_CLEAR_VAL;
        
          /* MISRA Rule   : 11.3                                       */
          /* Message      : A cast should not be performed between a   */
          /*                pointer type and an integral type.         */
          /* Reason       : This is to access the hardware registers   */
          /*                in the code.                               */
          /* Verification : However, the part of the code is           */
          /*                verified manually and it is not having     */
          /*                any impact on code.                        */
        
          /* Make IOHLDCLR bit of PSC1 register true */
          PORT_PSC1 = Luliohold;
          PORT_PSC1 = ~Luliohold;
          PORT_PSC1 = Luliohold;
          LucLoopCount--;
        }while((LucLoopCount > PORT_ZERO)&&(PORT_PROTS2 == PORT_ONE));

        if(PORT_PROTS2 == PORT_ONE)
        {
          /* writing to write-protected register failed and
           * report production error
           */
          Dem_ReportErrorStatus(PORT_E_WRITE_FAILURE,
                                               DEM_EVENT_STATUS_FAILED);
        }
        else
        {
           /*For MISRA C compliance  */
        }
      }
      else
      {
        /*For MISRA C compliance  */
      }
      #endif /* End of ((PORT_PWS1_ENABLE == STD_ON) &&
                                                (PORT_PSC1_ENABLE == STD_ON)) */
    }
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /*If there is no valid database is present */
    else
    {
      /* Report to DET */
      Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                                           PORT_E_INVALID_DATABASE);
    }
    #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  }
}
#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
/*******************************************************************************
** Function Name        : Port_SetPinDirection
**
** Service ID           : 0x01
**
** Description          : This service sets the port pin direction during
**                        runtime.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Pin - Port Pin ID number
**                        Direction - Port Pin Direction
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : Ports should be initliazed by calling Port_Init().
**
** Remarks              : Global Variable(s):
**                        Port_GblDriverStatus, Port_GpConfigPtr
**                        Function(s) invoked:
**                        Det_ReportError, Port_SearchDirChangeablePin
*******************************************************************************/
FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDirection
(Port_PinType Pin, Port_PinDirectionType Direction)
{
  P2CONST(Tdd_Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
                                                             LpChangeablePinDet;

  /*  MISRA Rule        : 18.4                                                */
  /*  Message           : An object of union type has been defined.           */
  /*  Reason            : Data access of larger data types is used to achieve */
  /*                      better throughput.                                  */
  /*  Verification      : However, part of the code is verified manually and  */
  /*                      it is not having any impact.                        */

  Tun_Port_Pin_Direction LunSRRegContent;

  uint32 LulBaseAddress;

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  boolean LblErrorflag;
  #endif

  LpChangeablePinDet = NULL_PTR;

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  LblErrorflag = PORT_FALSE;

  /* Check whether the PORT module is initialized */
  if(Port_GblDriverStatus == PORT_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIR_SID,
                                                          PORT_E_UNINIT);
    LblErrorflag = PORT_TRUE;
  }

  /* Check whether the requested PIN number is invalid */
  if(Pin >= PORT_TOTAL_NUMBER_OF_PINS)
  {
    /* Report to DET */
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIR_SID,
                                                          PORT_E_PARAM_PIN);
    LblErrorflag = PORT_TRUE;
  }
  if(LblErrorflag == PORT_FALSE)
  {
    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchDirChangeablePin(Pin,
                         Port_GpConfigPtr->pPinDirChangeable,
                         Port_GpConfigPtr->ucNoOfPinsDirChangeable);

    /* Return value LpChangeablePinDet - Changeable, NULL - Unchangeable */
    if(LpChangeablePinDet == NULL_PTR)
    {
      /* Report to DET */
      Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIR_SID,
                                              PORT_E_DIRECTION_UNCHANGEABLE);
      LblErrorflag = PORT_TRUE;
    }
  }

  if(LblErrorflag == PORT_FALSE)
  #endif /*End of (PORT_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (PORT_DEV_ERROR_DETECT == STD_OFF)

    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchDirChangeablePin(Pin,
                         Port_GpConfigPtr->pPinDirChangeable,
                         Port_GpConfigPtr->ucNoOfPinsDirChangeable);
    #endif  /* End of (PORT_DEV_ERROR_DETECT == STD_OFF) */

    /* Get the base address of the corresponding Port Type */
    #if(PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    if(LpChangeablePinDet->ucPortType == PORT_GROUP_NUMERIC)
    {
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    }
    #endif /* End of  (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) */
    #if(PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
    if(LpChangeablePinDet->ucPortType == PORT_GROUP_ALPHABETIC)
    {
      LulBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
    }
    #endif /* End of  (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON) */
    #if(PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
    if(LpChangeablePinDet->ucPortType == PORT_GROUP_JTAG)
    {
      LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
    }
    #endif  /* End of (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)  */

    /* Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
     * variable to 1 of the configured pin whose Direction has to be changed
     */
    LunSRRegContent.Tst_Port_Word.usMSWord = LpChangeablePinDet->usOrMaskVal;

    /* Check if requested direction is OUTPUT */
    if(Direction == PORT_PIN_OUT)
    {
      /* Write the Lower word contents with configured Pin Level Value */
      LunSRRegContent.Tst_Port_Word.usLSWord =\
                                    LpChangeablePinDet->usChangeableConfigVal;

      /* MISRA Rule         : 11.3                                            */
      /* Message            : A cast should not be performed between a        */
      /*                      pointer type and an integral type.              */
      /* Reason             : This is to access the hardware registers.       */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* MISRA Rule         : 9.1                                             */
      /* Message            : The variable '-identifier-' is apparently       */
      /*                      unset at this point.                            */
      /* Reason             : To access hardware registers                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Write the configured value into the register */
      *((uint32 *)(LulBaseAddress + LpChangeablePinDet->usPSRRegAddrOffset)) =
                                           LunSRRegContent.ulRegContent;
      /* Set the requested direction */
      LunSRRegContent.Tst_Port_Word.usLSWord = ~LpChangeablePinDet->usOrMaskVal;
    }
    else
    {
      /* Requested direction is INPUT */
      LunSRRegContent.Tst_Port_Word.usLSWord = LpChangeablePinDet->usOrMaskVal;
    }

    /* MISRA Rule         : 11.3                                            */
    /* Message            : A cast should not be performed between a        */
    /*                      pointer type and an integral type.              */
    /* Reason             : This is to access the hardware registers.       */
    /* Verification       : However, this part of the code is verified      */
    /*                      manually and it is not having any impact.       */

    /* Bit value of Upper 16 bits (31-16) of PMSR register = 1
     * Bit value of Lower 16 bits (15-0) of PMSR register = Configured value
     * for the corresponding pin position
     */
    *((uint32 *)(LulBaseAddress + LpChangeablePinDet->usPMSRRegAddrOffset)) =
                                                LunSRRegContent.ulRegContent;
  }

}
#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
/*******************************************************************************
** Function Name        : Port_RefreshPortDirection
**
** Service ID           : 0x02
**
** Description          : This service shall refresh the direction of all
**                        configured ports to the configured direction.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : Ports should be initliazed by calling Port_init().
**
** Remarks              : Global Variable(s):
**                        Port_GblDriverStatus, Port_GpConfigPtr
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
FUNC(void, PORT_PUBLIC_CODE) Port_RefreshPortDirection (void)
{

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Check whether the PORT module is initialized */
  if(Port_GblDriverStatus == PORT_UNINITIALIZED)
  {
    /* Report to DET  */
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIR_SID,
                                                          PORT_E_UNINIT);
  }
  else
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    /* Invoking Port_RefreshPortInternal API with Numeric Group data */
    Port_RefreshPortInternal(PORT_GROUP_NUMERIC);
    #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
    /* Invoking Port_RefreshPortInternal API with Alphabetic Group data */
    Port_RefreshPortInternal(PORT_GROUP_ALPHABETIC);
    #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
    /* Invoking Port_RefreshPortInternal API with JTag Group data */
    Port_RefreshPortInternal(PORT_GROUP_JTAG);
    #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
  }
}
#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

#if (PORT_SET_PIN_MODE_API == STD_ON)
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
/*******************************************************************************
** Function Name        : Port_SetPinMode
**
** Service ID           : 0x04
**
** Description          : This function used to set the mode of a port pin
**                        during runtime.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : Pin - Port Pin ID number
**                        Mode - New mode to be set on port pin.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : Ports should be initliazed by calling Port_init().
**
** Remarks              : Global Variable(s):
**                        Port_GblDriverStatus, Port_GpConfigPtr
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
FUNC(void, PORT_PUBLIC_CODE) Port_SetPinMode
(Port_PinType Pin, Port_PinModeType Mode)
{

  P2CONST(Tdd_Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpModeChangeablePin = NULL_PTR;
  /* Pointer to Alternate mode data structure */
  P2CONST(Tdd_Port_PinModeChangeableGroups, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinModeGroupStruct = NULL_PTR;
  /* Pointer to Port Registers Data structure */
  P2CONST(Tdd_Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpPortReg = NULL_PTR;
  /* Pointer to Alternate Function Control Registers Data structure */
  P2CONST(Tdd_Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpFuncCtrlReg = NULL_PTR;
  /* Pointer to hold the register address of 32 bit value */
  P2VAR(uint32, AUTOMATIC, PORT_CONFIG_CONST)LpRegAddr = NULL_PTR;

  /* Pointer to hold the register address 16 bit value */
  P2VAR(uint16, AUTOMATIC, PORT_CONFIG_CONST)Lp16BitRegAddr;

  /*  MISRA Rule        : 18.4                                                */
  /*  Message           : An object of union type has been defined.           */
  /*  Reason            : Data access of larger data types is used to achieve */
  /*                      better throughput.                                  */
  /*  Verification      : However, part of the code is verified manually and  */
  /*                      it is not having any impact.                        */

  Tun_Port_Pin_Direction LunSRRegContent;
  uint32 LulBaseAddress;

  uint16 LusPFCERegVal;
  uint16 LusPFCRegVal;



  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  boolean LblErrorflag;
  #endif

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  LblErrorflag = PORT_FALSE;

  /* Check whether the PORT module is initialized */
  if(Port_GblDriverStatus == PORT_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
                                                          PORT_E_UNINIT);
    LblErrorflag = PORT_TRUE;
  }
  /* Check whether the requested PIN number is invalid */
  if (Pin >= PORT_TOTAL_NUMBER_OF_PINS)
  {
    /* Report to DET */
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
                                                          PORT_E_PARAM_PIN);
    LblErrorflag = PORT_TRUE;
  }
   /* Check whether the requested mode is invalid */
  if(Mode >= PORT_MAX_ALLOWED_PIN_MODES)
  {
    /* Report to DET */
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
                                                     PORT_E_PARAM_INVALID_MODE);
    LblErrorflag = PORT_TRUE;
  }

  if(LblErrorflag == PORT_FALSE)
  {
    /* Check whether the Pin mode is changeable at run time */
    LpModeChangeablePin = Port_SearchModeChangeablePin(Pin,
                          Port_GpConfigPtr->pPinModeChangeableDetails,
                          Port_GpConfigPtr->ucNoOfPinsModeChangeable);
    /* Return value LpModeChangeablePin - Changeable, NULL - Unchangeable */
    if(LpModeChangeablePin == NULL_PTR)
    {
      /* Report to DET */
      Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
                                              PORT_E_MODE_UNCHANGEABLE);
      LblErrorflag = PORT_TRUE;
    }
  }
  if(LblErrorflag == PORT_FALSE)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check whether the Pin is mode changeable at run time */
    LpModeChangeablePin = Port_SearchModeChangeablePin(Pin,
                          Port_GpConfigPtr->pPinModeChangeableDetails,
                          Port_GpConfigPtr->ucNoOfPinsModeChangeable);

    /* MISRA Rule         : 17.4                                              */
    /* Message            : Performing Pointer arithmetic.                    */
    /* Reason             : This is to get the ID in the                      */
    /*                      data structure in the code.                       */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

    /* Get the pointer to the Set Mode group list */
    LpSetPinModeGroupStruct = (Port_GpConfigPtr->pPinModeChangeableGroups
                                    + LpModeChangeablePin->ucSetModeIndex);
    /* If the Pin group is of Numeric type */
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    if(LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC)
    {
      LpPortReg = Port_GpConfigPtr->pPortNumRegs;
      LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    }
    else
    #endif /* End of (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) */
    {
      #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
      if(LpModeChangeablePin->ucPortType == PORT_GROUP_ALPHABETIC)
      {
        LpPortReg = Port_GpConfigPtr->pPortAlphaRegs;
        LpFuncCtrlReg = Port_GpConfigPtr->pPortAlphaFuncCtrlRegs;
        LulBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
      }
      else
      #endif  /* End of (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)  */
      {
         #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
         if(LpModeChangeablePin->ucPortType == PORT_GROUP_JTAG)
         {
           LpPortReg = Port_GpConfigPtr->pPortJRegs;
           LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
           LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
         }
         #endif  /* End of (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)   */
      }
    }

    /* Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
     * variable to 1 of the configured pin whose Mode has to be changed
     */
    LunSRRegContent.Tst_Port_Word.usMSWord = LpModeChangeablePin->usOrMask;

    /* Write PSR register.Check for PSR register availability */
    if (LpSetPinModeGroupStruct->ucPSRRegIndex != PORT_REG_NOTAVAILABLE)
    {
      /* MISRA Rule         : 1.2                                             */
      /* Message            : Dereferencing pointer value that is apparently  */
      /*                      NULL.                                           */
      /* Reason             : Pointer is checked and verified when DET is     */
      /*                      switched ON.                                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* MISRA Rule         : 17.4                                            */
      /* Message            : Performing Pointer arithmetic.                  */
      /* Reason             : This is to get the ID in the                    */
      /*                      data structure in the code.                     */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Write Initial mode register value into Lower word of PSR variable */
      LunSRRegContent.Tst_Port_Word.usLSWord = (LpPortReg + \
               LpSetPinModeGroupStruct->ucPSRRegIndex)->usInitModeRegVal;

      /* MISRA Rule         : 11.3                                            */
      /* Message            : A cast should not be performed between a        */
      /*                      pointer type and an integral type.              */
      /* Reason             : This is to access the hardware registers.       */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* MISRA Rule         : 17.4                                            */
      /* Message            : Performing Pointer arithmetic.                  */
      /* Reason             : This is to get the ID in the                    */
      /*                      data structure in the code.                     */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* MISRA Rule         : 9.1                                             */
      /* Message            : The variable '-identifier-' is apparently       */
      /*                      unset at this point.                            */
      /* Reason             : To access hardware registers                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Get the PSR register Address */
      LpRegAddr = (uint32 *)((LpPortReg +
                  LpSetPinModeGroupStruct->ucPSRRegIndex)->usRegAddrOffset
                  + LulBaseAddress);

      /* Bit value of Upper 16 bits (31-16) of PSR register = 1
       * Bit value of Lower 16 bits (15-0) of PSR register = Initial value
       * for the corresponding pin position
       */
      *LpRegAddr = LunSRRegContent.ulRegContent;
    }

    /* Check if requested is Init mode */
    if(Mode == PORT_INIT_MODE)
    {

      /* MISRA Rule         : 1.2                                             */
      /* Message            : Dereferencing pointer value that is apparently  */
      /*                      NULL.                                           */
      /* Reason             : Pointer is checked and verified when DET is     */
      /*                      switched ON.                                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* MISRA Rule         : 17.4                                            */
      /* Message            : Performing Pointer arithmetic.                  */
      /* Reason             : This is to get the ID in the                    */
      /*                      data structure in the code.                     */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Load Initial values to the corresponding PFCE and PFC registers */
      LusPFCERegVal = (LpFuncCtrlReg +
                LpSetPinModeGroupStruct->ucPFCERegIndex)->usInitModeRegVal;
      LusPFCRegVal = (LpFuncCtrlReg +
                LpSetPinModeGroupStruct->ucPFCRegIndex)->usInitModeRegVal;


      /* Bit value of Lower 16 bits (15-0) of PMCSR register = Initial value
       * for the corresponding pin position
       */
      LunSRRegContent.Tst_Port_Word.usLSWord = (LpFuncCtrlReg + \
               LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usInitModeRegVal;
    }
    else
    {
      /* MISRA Rule         : 17.4                                            */
      /* Message            : Performing Pointer arithmetic.                  */
      /* Reason             : This is to get the ID in the                    */
      /*                      data structure in the code.                     */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Load Configured values to the corresponding PFCE and PFC registers */
      LusPFCERegVal = (LpFuncCtrlReg +
                 LpSetPinModeGroupStruct->ucPFCERegIndex)->usSetModeRegVal;
      LusPFCRegVal = (LpFuncCtrlReg +
                 LpSetPinModeGroupStruct->ucPFCRegIndex)->usSetModeRegVal;


      /* Bit value of Lower 16 bits (15-0) of PMCSR register = configured value
       * for the corresponding pin position
       */
      LunSRRegContent.Tst_Port_Word.usLSWord = (LpFuncCtrlReg + \
               LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usSetModeRegVal;
    }

    /* Enter critical section */
    #if(PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    SchM_Enter_Port(PORT_SET_PIN_MODE_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /* Write PFCE register.Check for register availability */
    if (LpSetPinModeGroupStruct->ucPFCERegIndex != PORT_REG_NOTAVAILABLE)
    {

      /* MISRA Rule         : 11.3                                            */
      /* Message            : A cast should not be performed between a        */
      /*                      pointer type and an integral type.              */
      /* Reason             : This is to access the hardware registers.       */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* MISRA Rule         : 17.4                                            */
      /* Message            : Performing Pointer arithmetic.                  */
      /* Reason             : This is to get the ID in the                    */
      /*                      data structure in the code.                     */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      Lp16BitRegAddr = (uint16 *)((LpFuncCtrlReg +
                LpSetPinModeGroupStruct->ucPFCERegIndex)->usRegAddrOffset +
                LulBaseAddress);

      /* Check whether the corresponding bit is to set or reset. */
      if((LusPFCERegVal & LpModeChangeablePin->usOrMask) == PORT_ZERO)
      {
        /* MISRA Rule         : 12.7                                          */
        /* Message            : Bitwise operators shall not be applied to     */
        /*                      operands whose underlying type is signed.     */
        /* Reason             : Though the bitwise operation is performed on  */
        /*                      unsigned data, this warning is generated by   */
        /*                      the QAC tool V6.2.1 as an indirect result of  */
        /*                      integral promotion in complex bitwise         */
        /*                      operations.                                   */
        /* Verification       : However, this part of the code is verified    */
        /*                      manually and it is not having any impact.     */

        /* If bit needs to reset, AND the register contents with InvOrMask */
        *Lp16BitRegAddr &= (~LpModeChangeablePin->usOrMask);
      }
      else
      {
        /* If bit needs to be set, OR the register contents with OrMask */
        *Lp16BitRegAddr |= LpModeChangeablePin->usOrMask;
      }
    } /* End of Write PFCE register */

    /* Write PFC register.Check for register availability */
    if (LpSetPinModeGroupStruct->ucPFCRegIndex != PORT_REG_NOTAVAILABLE)
    {
      /* MISRA Rule         : 11.3                                            */
      /* Message            : A cast should not be performed between a        */
      /*                      pointer type and an integral type.              */
      /* Reason             : This is to access the hardware registers.       */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* MISRA Rule         : 17.4                                            */
      /* Message            : Performing Pointer arithmetic.                  */
      /* Reason             : This is to get the ID in the                    */
      /*                      data structure in the code.                     */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      Lp16BitRegAddr = (uint16 *)((LpFuncCtrlReg +
                  LpSetPinModeGroupStruct->ucPFCRegIndex)->usRegAddrOffset +
                  LulBaseAddress);
      /* Check whether the corresponding bit is to set or reset. */
      if((LusPFCRegVal & LpModeChangeablePin->usOrMask) == PORT_ZERO)
      {
        /* MISRA Rule         : 12.7                                          */
        /* Message            : Bitwise operators shall not be applied to     */
        /*                      operands whose underlying type is signed.     */
        /* Reason             : Though the bitwise operation is performed on  */
        /*                      unsigned data, this warning is generated by   */
        /*                      the QAC tool V6.2.1 as an indirect result of  */
        /*                      integral promotion in complex bitwise         */
        /*                      operations.                                   */
        /* Verification       : However, this part of the code is verified    */
        /*                      manually and it is not having any impact.     */

        /* If bit needs to be reset, AND the register contents with AndMask */
        *Lp16BitRegAddr &= (~LpModeChangeablePin->usOrMask);
      }
      else
      {
        /* If bit needs to be set, OR the register contents with OrMask */
        *Lp16BitRegAddr |= LpModeChangeablePin->usOrMask;
      }
    } /* End of Write PFC register */

    /* Exit critical section */
    #if(PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    SchM_Exit_Port(PORT_SET_PIN_MODE_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /* Write PMCSR register. Check for register availability */
    if (LpSetPinModeGroupStruct->ucPMCSRRegIndex != PORT_REG_NOTAVAILABLE)
    {
      /* MISRA Rule         : 11.3                                            */
      /* Message            : A cast should not be performed between a        */
      /*                      pointer type and an integral type.              */
      /* Reason             : This is to access the hardware registers.       */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* MISRA Rule         : 17.4                                            */
      /* Message            : Performing Pointer arithmetic.                  */
      /* Reason             : This is to get the ID in the                    */
      /*                      data structure in the code.                     */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Get the address of PMCSR register */
      LpRegAddr = (uint32 *)((LpFuncCtrlReg +
                  LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usRegAddrOffset
                  + LulBaseAddress);
      /* Write the corresponding 32 bit value to the PMCSR register */
      *LpRegAddr = LunSRRegContent.ulRegContent;
    }/* End of Write PMCSR register */
  }
}

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* PORT_SET_PIN_MODE_API = = STD_ON */

#if (PORT_SET_PIN_MODE_API == STD_ON)
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
/*******************************************************************************
** Function Name        : Port_SearchModeChangeablePin
**
** Service ID           : Not Applicable
**
** Description          : This function used to verify whether the given pin is
**                        Mode changeable.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddPinNumber - Port Pin number
**                        LpStartPtr - Start pointer to the Changeable pin
**                        structures.
**                        Lucsize - Size of the Changeable pin structures.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Pointer to Mode Changeable Pin structure - if given
**                        pin number matches.
**                        NULL - If Pin number does not match.
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        None
**                        Function(s) invoked:
**                        None
*******************************************************************************/
STATIC
FUNC(P2CONST(Tdd_Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
    , PORT_PRIVATE_CODE) Port_SearchModeChangeablePin(Port_PinType LddPinNumber,
     P2CONST(Tdd_Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
     LpStartPtr, uint8 Lucsize)
{

  P2CONST(Tdd_Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_DATA)
                                                     LpRetPtr = NULL_PTR;
  uint8 LddLow;
  uint8 LddHigh;
  uint8 LddMid;
  uint16 LddListSearchId;

  LddHigh = Lucsize - PORT_ONE;
  LddLow = PORT_ONE;

  /* Get the lower limit of Search ID */
  LddListSearchId = LpStartPtr->ddPinId;

  /* MISRA Rule         : 17.4                                                */
  /* Message            : Performing Pointer arithmetic.                      */
  /* Reason             : This is to get the ID in the                        */
  /*                      data structure in the code.                         */
  /* Verification       : However, part of the code is verified manually      */
  /*                      and it is not having any impact.                    */

  /* Check whether search Search-ID is in range */
  if((LddPinNumber >= LddListSearchId) &&
     (LddPinNumber <= ((LpStartPtr+LddHigh)->ddPinId)))
  {

    /* Check whether requested Search-ID is same as first Search-ID
     *  of the list
     */
    if(LddPinNumber != LddListSearchId)
    {
      do
      {
        /* Get the middle index number */
        LddMid = (LddHigh + LddLow) >> PORT_ONE;

        /* Get the Search-ID of the mid IDs */
          LddListSearchId = ((LpStartPtr+LddMid)->ddPinId);

        /* Compare Search-ID with the requested one */
        if(LddListSearchId == LddPinNumber)
        {
          /* Update the return pointer with the pin number structure */
          LpRetPtr = (LpStartPtr + LddMid);

          /* Set LddHigh to zero to break the loop */
          LddHigh = PORT_ZERO;
        }
        else
        {
          /* Compare the Search-ID with the requested one */
          if(LddPinNumber < LddListSearchId)
          {
            /* MISRA Rule         : 21.1                                      */
            /* Message            : An integer expression with a value that   */
            /*                      apparently negative is being converted    */
            /*                      to an unsigned type.                      */
            /* Reason             : This is to update the local variable.     */
            /* Verification       : However, part of the code is verified     */
            /*                      manually and it is not having any impact. */

            /* If the priority is lower, update LddHigh */
            LddHigh = LddMid - PORT_ONE;
          }
          else
          {
            /* If the priority is higher, update LddLow */
            LddLow = LddMid + PORT_ONE;
          }
        }
      }while(LddLow <= LddHigh);
    }
    else
    {
      /* Update the return pointer with start pointer (Matches with first Id) */
        LpRetPtr = LpStartPtr;
    }
  }
  return LpRetPtr;
}

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* (PORT_SET_PIN_MODE_API == STD_ON) */

#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
/*******************************************************************************
** Function Name        : Port_InitConfig
**
** Service ID           : Not Applicable
**
** Description          : This function used to initialize all the registers of
**                        numeric, alphabetic and JTag ports
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : LenGroupType - Port group type
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
**                        None
**                        Function(s) invoked:
**                        None
*******************************************************************************/

STATIC FUNC(void, PORT_PRIVATE_CODE) Port_InitConfig
                                                 (Port_GroupType LenGroupType)
{
  P2CONST(Tdd_Port_Regs,AUTOMATIC,PORT_CONFIG_CONST)LpPortReg;
  P2CONST(Tdd_Port_FuncCtrlRegs,AUTOMATIC,PORT_CONFIG_CONST)LpFuncCtrlReg;
  P2CONST(Tdd_Port_PMSRRegs,AUTOMATIC,PORT_CONFIG_CONST)LpPMSRReg;

  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) Lp32BitRegAddress;
  P2VAR(uint16, AUTOMATIC, PORT_CONFIG_DATA) Lp16BitRegAddress;
  P2VAR(uint8, AUTOMATIC, PORT_CONFIG_DATA) Lp8BitPPCMDRegAdd;
  P2VAR(uint8, AUTOMATIC, PORT_CONFIG_DATA) Lp8BitPPROTSRegAdd;

  uint32 LulUserBaseAddress;
  uint32 LulOsBaseAddress;

  uint8 LucLoopCount;
  uint8 LucNoOfRegs;
  uint8 LucNoOfPSRRegs;
  uint8 LucNoOfPMCSRRegs;
  uint8 LucNoOfOther16BitRegs;
  uint8 LucNoOfPODCRegs;
  uint8 LucNoOfPDSCRegs;
  uint8 LucNoOfPUCCRegs;
  uint8 LucNoOfPSBCRegs;
  uint8 LucNoOfFuncCtrlRegs;
  #if(PORT_PIN_STATUS_BACKUP == STD_ON)
  uint8 LucNoOfRestoredRegs;
  #endif

  boolean LblDemReported = PORT_FALSE;
  boolean LblNumAlpha = PORT_FALSE;
  boolean LblJtag = PORT_FALSE;

  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  if(LenGroupType == PORT_GROUP_NUMERIC)
  {
    /* Get the pointer to the Numeric Port registers */
    LpPortReg = Port_GpConfigPtr->pPortNumRegs;
    /* Get the pointer to the Numeric Function Control registers */
    LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
    /* Get the pointer to the Numeric PMSR registers */
    LpPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
    /* Get the total number of Numeric SR registers */
    LucNoOfPSRRegs = Port_GpConfigPtr->ucNoOfNumPSRRegs;
    /* Get the total number of Numeric PMCSR registers */
    LucNoOfPMCSRRegs = Port_GpConfigPtr->ucNoOfNumPMCSRRegs;
    /* Get the total number of Numeric Other 16 Bit registers */
    LucNoOfOther16BitRegs = Port_GpConfigPtr->ucNoOfNumOther16BitRegs;
    /* Get the total number of Numeric PODC registers */
    LucNoOfPODCRegs = Port_GpConfigPtr->ucNoOfNumPODCRegs;
    #if(USE_UPD70F3580   == STD_OFF)
    /* Get the total number of Numeric PDSC registers */
    LucNoOfPDSCRegs = Port_GpConfigPtr->ucNoOfNumPDSCRegs;
    /* Get the total number of Numeric PUCC registers */
    LucNoOfPUCCRegs = Port_GpConfigPtr->ucNoOfNumPUCCRegs;
    /* Get the total number of Numeric PSBC registers */
    LucNoOfPSBCRegs = Port_GpConfigPtr->ucNoOfNumPSBCRegs;
    #else
    /* Get the total number of Numeric PDSC registers */
    LucNoOfPDSCRegs = PORT_ZERO;
    /* Get the total number of Numeric PUCC registers */
    LucNoOfPUCCRegs = PORT_ZERO;
    /* Get the total number of Numeric PSBC registers */
    LucNoOfPSBCRegs = PORT_ZERO;
    #endif  /* End of  (USE_UPD70F3580   == STD_OFF)  */
    /* Get the total number of Numeric Function Control registers */
    LucNoOfFuncCtrlRegs = Port_GpConfigPtr->ucNoOfNumFuncCtrlRegs;
    #if(PORT_PIN_STATUS_BACKUP == STD_ON)
    /* Get the total number of Numeric Restored registers */
    LucNoOfRestoredRegs = Port_GpConfigPtr->ucNoOfNumRestoredRegs;
    #endif
    /* Get the Base address of Numeric Port */
    LulUserBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    /* Get the Base address of Numeric Port */
    LulOsBaseAddress = PORT_OS_BASE_ADDRESS_NUMERIC;
    /* Update the local variable as one */
    LblNumAlpha = PORT_TRUE;
  }
  else
  #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
  {
    #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
    if(LenGroupType == PORT_GROUP_ALPHABETIC)
    {
      /* Get the pointer to the Alphabetic Port registers */
      LpPortReg = Port_GpConfigPtr->pPortAlphaRegs;
      /* Get the pointer to the Alphabetic Function Control registers */
      LpFuncCtrlReg = Port_GpConfigPtr->pPortAlphaFuncCtrlRegs;
      /* Get the pointer to the Alphabetic PMSR registers */
      LpPMSRReg = Port_GpConfigPtr->pPortAlphaPMSRRegs;
      /* Get the total number of Alphabetic SR registers */
      LucNoOfPSRRegs = Port_GpConfigPtr->ucNoOfAlphaPSRRegs;
      /* Get the total number of Alphabetic PMCSR registers */
      LucNoOfPMCSRRegs = Port_GpConfigPtr->ucNoOfAlphaPMCSRRegs;
      /* Get the total number of Alphabetic Other 16 Bit registers */
      LucNoOfOther16BitRegs = Port_GpConfigPtr->ucNoOfAlphaOther16BitRegs;
      /* Get the total number of Alphabetic PODC registers */
      LucNoOfPODCRegs = Port_GpConfigPtr->ucNoOfAlphaPODCRegs;
      #if(USE_UPD70F3580   == STD_OFF)
      /* Get the total number of Alphabetic PDSC registers */
      LucNoOfPDSCRegs = Port_GpConfigPtr->ucNoOfAlphaPDSCRegs;
      /* Get the total number of Alphabetic PUCC registers */
      LucNoOfPUCCRegs = Port_GpConfigPtr->ucNoOfAlphaPUCCRegs;
      /* Get the total number of Alphabetic PSBC registers */
      LucNoOfPSBCRegs = Port_GpConfigPtr->ucNoOfAlphaPSBCRegs;
      #else
      /* Get the total number of Alphabetic PDSC registers */
      LucNoOfPDSCRegs = Port_GpConfigPtr->PORT_ZERO;
      /* Get the total number of Alphabetic PUCC registers */
      LucNoOfPUCCRegs = Port_GpConfigPtr->PORT_ZERO;
      /* Get the total number of Alphabetic PSBC registers */
      LucNoOfPSBCRegs = Port_GpConfigPtr->PORT_ZERO;

      #endif  /*End of  (USE_UPD70F3580   == STD_OFF)*/
      /* Get the total number of Alphabetic Function Control registers */
      LucNoOfFuncCtrlRegs = Port_GpConfigPtr->ucNoOfAlphaFuncCtrlRegs;
      #if(PORT_PIN_STATUS_BACKUP == STD_ON)
      /* Get the total number of Alphabetic Restored registers */
      LucNoOfRestoredRegs = Port_GpConfigPtr->ucNoOfAlphaRestoredRegs;
      #endif
      /* Get the Base address of Alphabetic Port */
      LulUserBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
      /* Get the Base address of Alphabetic Port */
      LulOsBaseAddress = PORT_OS_BASE_ADDRESS_ALPHABETIC;
      /* Update the local variable as one */
      LblNumAlpha = PORT_TRUE;
    }
    else
    #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */
    {
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      if(LenGroupType == PORT_GROUP_JTAG)
      {
        /* Get the pointer to the JTag Port registers */
        LpPortReg = Port_GpConfigPtr->pPortJRegs;
        /* Get the pointer to the JTag Function Control registers */
        LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
        /* Get the pointer to the JTag PMSR registers */
        LpPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
        /* Get the total number of JTAG SR registers */
        LucNoOfPSRRegs = PORT_JTAG_PSR_REGS;
        /* Get the total number of JTAG PMCSR registers */
        LucNoOfPMCSRRegs = PORT_JTAG_PMCSR_REGS;
        /* Get the total number of JTag Other 8 Bit registers */
        LucNoOfOther16BitRegs = PORT_JTAG_OTHER_8BIT_REGS;
        /* Get the total number of JTag PODC registers */
        LucNoOfPODCRegs = PORT_JTAG_PODC_REGS;
        /* Get the total number of JTag PDSC registers */
        LucNoOfPDSCRegs = PORT_JTAG_PDSC_REGS;
        /* Get the total number of JTag PUCC registers */
        LucNoOfPUCCRegs = PORT_JTAG_PUCC_REGS;
        /* Get the total number of JTag PSBC registers */
        LucNoOfPSBCRegs = PORT_JTAG_PSBC_REGS;

        /* Get the total number of JTag Function Control registers */
        LucNoOfFuncCtrlRegs = Port_GpConfigPtr->ucNoOfJFuncCtrlRegs;
        #if(PORT_PIN_STATUS_BACKUP == STD_ON)
        /* Get the total number of JTag Restored registers */
        LucNoOfRestoredRegs = Port_GpConfigPtr->ucNoOfJtagRestoredRegs;
        #endif
        /* Get the Base address of JTag Port */
        LulUserBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
        /* Get the Base address of JTag Port */
        LulOsBaseAddress = PORT_OS_BASE_ADDRESS_JTAG;
        /* Update the local variable as one */
        LblJtag = PORT_TRUE;
      }
      #endif /* PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
    }
  }

  /* MISRA Rule         : 9.1                                                 */
  /* Message            : The variable '-identifier-' is apparently           */
  /*                      unset at this point.                                */
  /* Reason             : To access hardware registers                        */
  /* Verification       : However, part of the code is verified manually      */
  /*                      and it is not having any impact.                    */

  /* Get the count of total number of SR registers */
  LucNoOfRegs = LucNoOfPSRRegs;

  #if(PORT_PIN_STATUS_BACKUP == STD_ON)
  /* Check if reset is done by deep stop */
  #if(PORT_PWS0_ENABLE == STD_ON)
  if((PORT_PWS0 & PORT_IOHOLD_SET)==PORT_IOHOLD_SET)
  #endif

  {
    #if(PORT_PWS1_ENABLE == STD_ON)
    if((PORT_PWS1 & PORT_IOHOLD_SET)==PORT_IOHOLD_SET)
    #endif
    {
      LpPortReg = LpPortReg + LucNoOfRestoredRegs;
      LucNoOfRegs = LucNoOfRegs - LucNoOfRestoredRegs;
    }
  }
  #endif  /* End of (PORT_PIN_STATUS_BACKUP == STD_ON) */

  while(LucNoOfRegs > PORT_ZERO)
  {
    /* MISRA Rule         : 11.3                                              */
    /* Message            : A cast should not be performed between a          */
    /*                      pointer type and an integral type.                */
    /* Reason             : This is to access the hardware registers.         */
    /* Verification       : However, this part of the code is verified        */
    /*                      manually and it is not having any impact.         */

    /* Get the register address by adding the offset to the Base address */
    Lp32BitRegAddress =
          (uint32 *)(LpPortReg->usRegAddrOffset + LulUserBaseAddress);
    /* Write the register value to the corresponding register */
    *Lp32BitRegAddress = (LpPortReg->usInitModeRegVal | PORT_MSB_MASK);

    /* MISRA Rule         : 17.4                                              */
    /* Message            : Increment or decrement operation performed        */
    /*                      on pointer.                                       */
    /* Reason             : This is to access the data structure              */
    /*                      pointing to next port group.                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

    LpPortReg++;
    LucNoOfRegs--;
  }

  /* MISRA Rule         : 9.1                                                 */
  /* Message            : The variable '-identifier-' is apparently           */
  /*                      unset at this point.                                */
  /* Reason             : To access hardware registers                        */
  /* Verification       : However, part of the code is verified manually      */
  /*                      and it is not having any impact.                    */

  /* Get the count of total number of Other 16Bit registers */
  LucNoOfRegs = LucNoOfOther16BitRegs;

  while(LucNoOfRegs > PORT_ZERO)
  {
    /* MISRA Rule         : 11.3                                              */
    /* Message            : A cast should not be performed between a          */
    /*                      pointer type and an integral type.                */
    /* Reason             : This is to access the hardware registers.         */
    /* Verification       : However, this part of the code is verified        */
    /*                      manually and it is not having any impact.         */

    /* Get the register address by adding the offset to the Base address */
    Lp16BitRegAddress =
           (uint16 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* Write the register value to the corresponding register */
    *Lp16BitRegAddress = LpPortReg->usInitModeRegVal;

    /* MISRA Rule         : 17.4                                              */
    /* Message            : Increment or decrement operation performed        */
    /*                      on pointer.                                       */
    /* Reason             : This is to access the data structure              */
    /*                      pointing to next port group.                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

/*Compiler Switch to check if the variant is DK4-H*/
#if(USE_UPD70F3529 == STD_ON)
    /*Check for Port Group JTAG*/
    if(LenGroupType == PORT_GROUP_JTAG)
    {
    /*If DK4-H do not increment the structure pointer.
    This provides the correct address for the next loop of registers
    Namely,
    1. JPODC0
    2. JPDSC0
    */
      if(LucNoOfRegs != PORT_ONE)
      {
        LpPortReg++;
      }
      else
      {
        /*For MISRA-C complaint*/
      }
      LucNoOfRegs--;
    }
    else
    /*For all other Port Groups*/
    {
      LpPortReg++;
      LucNoOfRegs--;
    }
/*For all other variants*/
#else
    LpPortReg++;
    LucNoOfRegs--;
#endif /* USE_UPD70F3529 == STD_ON */
  }

  /* MISRA Rule         : 9.1                                                 */
  /* Message            : The variable '-identifier-' is apparently           */
  /*                      unset at this point.                                */
  /* Reason             : To access hardware registers                        */
  /* Verification       : However, part of the code is verified manually      */
  /*                      and it is not having any impact.                    */

  /* Get the count of total number of 32Bit PODC registers */
  LucNoOfRegs = LucNoOfPODCRegs;

  while((LucNoOfRegs > PORT_ZERO) && (LblDemReported == PORT_FALSE))
  {
    /* Initialize the loop count to ten */
    LucLoopCount = PORT_TEN;

    /* MISRA Rule         : 11.3                                              */
    /* Message            : A cast should not be performed between a          */
    /*                      pointer type and an integral type.                */
    /* Reason             : This is to access the hardware registers.         */
    /* Verification       : However, this part of the code is verified        */
    /*                      manually and it is not having any impact.         */

    /* Get the register address by adding the offset to the Base address */
    Lp32BitRegAddress =
                    (uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);

  /*Compiler Switch to check if the variant is DK4-H*/
  #if(USE_UPD70F3529 == STD_ON)
    /*Check for Port Group JTAG*/
    if(LenGroupType == PORT_GROUP_JTAG)
    {
      Lp8BitPPROTSRegAdd = (uint8 *) (LulOsBaseAddress + PORT_JTAG_PPROTS_REG_ADD_OFFSET);
      Lp8BitPPCMDRegAdd = (uint8 *) (LulOsBaseAddress + PORT_JTAG_PPCMD_REG_ADD_OFFSET);
    }
    else
    /*For all other Port Groups*/
    {
      /* Get the address of the corresponding PPROTS register */
      Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PODC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PODC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
      /* Get the address of the corresponding PPCMD register */
      Lp8BitPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PODC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PODC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
    }
  /*For all other variants*/
  #else
  /* Get the address of the corresponding PPROTS register */
    Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PODC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PODC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
    /* Get the address of the corresponding PPCMD register */
    Lp8BitPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PODC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PODC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
  #endif

    do
    {
      *Lp8BitPPCMDRegAdd = PORT_WRITE_ERROR_CLEAR_VAL;
      /* Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

      /* MISRA Rule         : 12.7                                            */
      /* Message            : Bitwise operators shall not be applied to       */
      /*                      operands whose underlying type is signed.       */
      /* Reason             : Though the bitwise operation is performed on    */
      /*                      unsigned data, this warning is generated by     */
      /*                      the QAC tool V6.2.1 as an indirect result of    */
      /*                      integral promotion in complex bitwise           */
      /*                      operations.                                     */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* Write the bit wise inverse value to the corresponding register with
       * upper 16 bit set to one
       */
      *Lp32BitRegAddress = ~LpPortReg->usInitModeRegVal | PORT_MSB_MASK;
      /* Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);
      /* Decrement the loop count for each iteration */
      LucLoopCount--;
      /* Check the state of PPROTS register for successful write operation or
       * perform maximum ten tries, if failure occures report DEM and skip
       * further configuration
       */
    }while((*Lp8BitPPROTSRegAdd == PORT_ONE) && (LucLoopCount > PORT_ZERO));

    /* Check if the loop has exited because of failure of writing to register */
    if(*Lp8BitPPROTSRegAdd == PORT_ONE)
    {
      /* Report write failure production error */
      Dem_ReportErrorStatus(PORT_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      /* Set the Dem error flag */
      LblDemReported = PORT_TRUE;
    }

    /* MISRA Rule         : 17.4                                              */
    /* Message            : Increment or decrement operation performed        */
    /*                      on pointer.                                       */
    /* Reason             : This is to access the data structure              */
    /*                      pointing to next port group.                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

    LpPortReg++;
    LucNoOfRegs--;
  }

  /* MISRA Rule         : 9.1                                                 */
  /* Message            : The variable '-identifier-' is apparently           */
  /*                      unset at this point.                                */
  /* Reason             : To access hardware registers                        */
  /* Verification       : However, part of the code is verified manually      */
  /*                      and it is not having any impact.                    */


  /* Get the count of total number of 32Bit PDSC registers */
  LucNoOfRegs = LucNoOfPDSCRegs;

  while((LucNoOfRegs > PORT_ZERO) && (LblDemReported == PORT_FALSE))
  {
    /* Initialize the loop count to ten */
    LucLoopCount = PORT_TEN;

    /* MISRA Rule         : 11.3                                              */
    /* Message            : A cast should not be performed between a          */
    /*                      pointer type and an integral type.                */
    /* Reason             : This is to access the hardware registers.         */
    /* Verification       : However, this part of the code is verified        */
    /*                      manually and it is not having any impact.         */

    /* Get the register address by adding the offset to the Base address */
    Lp32BitRegAddress =
              (uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);


  /*Compiler Switch to check if the variant is DK4-H*/
  #if(USE_UPD70F3529 == STD_ON)
    /*Check for Port Group JTAG*/
    if(LenGroupType == PORT_GROUP_JTAG)
    {
      Lp8BitPPROTSRegAdd = (uint8 *) (LulOsBaseAddress + PORT_JTAG_PPROTS_REG_ADD_OFFSET);
      Lp8BitPPCMDRegAdd = (uint8 *) (LulOsBaseAddress + PORT_JTAG_PPCMD_REG_ADD_OFFSET);
    }
    else
    /*For all other Port Groups*/
    {
      /* Get the address of the corresponding PPROTS register */
      Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PDSC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PDSC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
      /* Get the address of the corresponding PPCMD register */
      Lp8BitPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PDSC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PDSC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
    }
  /*For all other variants*/
  #else
  /* Get the address of the corresponding PPROTS register */
    Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PDSC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PDSC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));

    /* Get the address of the corresponding PPCMD register */
    Lp8BitPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PDSC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PDSC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
  #endif

    do
    {
      *Lp8BitPPCMDRegAdd = PORT_WRITE_ERROR_CLEAR_VAL;
      /* Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

      /* MISRA Rule         : 12.7                                            */
      /* Message            : Bitwise operators shall not be applied to       */
      /*                      operands whose underlying type is signed.       */
      /* Reason             : Though the bitwise operation is performed on    */
      /*                      unsigned data, this warning is generated by     */
      /*                      the QAC tool V6.2.1 as an indirect result of    */
      /*                      integral promotion in complex bitwise           */
      /*                      operations.                                     */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* Write the bit wise inverse value to the corresponding register with
       * upper 16 bit set to one
       */
      *Lp32BitRegAddress = ~LpPortReg->usInitModeRegVal | PORT_MSB_MASK;
      /* Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);
      /* Decrement the loop count for each iteration */
      LucLoopCount--;
      /* Check the state of PPROTS register for successful write operation or
       * perform maximum ten tries, if failure occures report DEM and skip
       * further configuration
       */
    }while((*Lp8BitPPROTSRegAdd == PORT_ONE) && (LucLoopCount > PORT_ZERO));

    /* Check if the loop has exited because of failure of writing to register */
    if(*Lp8BitPPROTSRegAdd == PORT_ONE)
    {
      /* Report write failure production error */
      Dem_ReportErrorStatus(PORT_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      /* Set the Dem error flag */
      LblDemReported = PORT_TRUE;
    }

    /* MISRA Rule         : 17.4                                              */
    /* Message            : Increment or decrement operation performed        */
    /*                      on pointer.                                       */
    /* Reason             : This is to access the data structure              */
    /*                      pointing to next port group.                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

    LpPortReg++;
    LucNoOfRegs--;
  }

  /* MISRA Rule         : 9.1                                                 */
  /* Message            : The variable '-identifier-' is apparently           */
  /*                      unset at this point.                                */
  /* Reason             : To access hardware registers                        */
  /* Verification       : However, part of the code is verified manually      */
  /*                      and it is not having any impact.                    */

  /* Get the count of total number of 32Bit PUCC registers */
  LucNoOfRegs = LucNoOfPUCCRegs;

  while((LucNoOfRegs > PORT_ZERO) && (LblDemReported == PORT_FALSE))
  {
    /* Initialize the loop count to ten */
    LucLoopCount = PORT_TEN;

    /* MISRA Rule         : 11.3                                              */
    /* Message            : A cast should not be performed between a          */
    /*                      pointer type and an integral type.                */
    /* Reason             : This is to access the hardware registers.         */
    /* Verification       : However, this part of the code is verified        */
    /*                      manually and it is not having any impact.         */

    /* Get the register address by adding the offset to the Base address */
    Lp32BitRegAddress =
                   (uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* Get the address of the corresponding PPROTS register */
    Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PUCC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PUCC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
    /* Get the address of the corresponding PPCMD register */
    Lp8BitPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PUCC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PUCC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));

    do
    {
      *Lp8BitPPCMDRegAdd = PORT_WRITE_ERROR_CLEAR_VAL;
      /* Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

      /* MISRA Rule         : 12.7                                            */
      /* Message            : Bitwise operators shall not be applied to       */
      /*                      operands whose underlying type is signed.       */
      /* Reason             : Though the bitwise operation is performed on    */
      /*                      unsigned data, this warning is generated by     */
      /*                      the QAC tool V6.2.1 as an indirect result of    */
      /*                      integral promotion in complex bitwise           */
      /*                      operations.                                     */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* Write the bit wise inverse value to the corresponding register with
       * upper 16 bit set to one
       */
      *Lp32BitRegAddress = ~LpPortReg->usInitModeRegVal | PORT_MSB_MASK;
      /* Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);
      /* Decrement the loop count for each iteration */
      LucLoopCount--;
      /* Check the state of PPROTS register for successful write operation or
       * perform maximum ten tries, if failure occures report DEM and skip
       * further configuration
       */
    }while((*Lp8BitPPROTSRegAdd == PORT_ONE) && (LucLoopCount > PORT_ZERO));

    /* Check if the loop has exited because of failure of writing to register */
    if(*Lp8BitPPROTSRegAdd == PORT_ONE)
    {
      /* Report write failure production error */
      Dem_ReportErrorStatus(PORT_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      /* Set the Dem error flag */
      LblDemReported = PORT_TRUE;
    }

    /* MISRA Rule         : 17.4                                              */
    /* Message            : Increment or decrement operation performed        */
    /*                      on pointer.                                       */
    /* Reason             : This is to access the data structure              */
    /*                      pointing to next port group.                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

    LpPortReg++;
    LucNoOfRegs--;
  }

  /* MISRA Rule         : 9.1                                                 */
  /* Message            : The variable '-identifier-' is apparently           */
  /*                      unset at this point.                                */
  /* Reason             : To access hardware registers                        */
  /* Verification       : However, part of the code is verified manually      */
  /*                      and it is not having any impact.                    */

  /* Get the count of total number of 32Bit PSBC registers */
  LucNoOfRegs = LucNoOfPSBCRegs;

  while((LucNoOfRegs > PORT_ZERO) && (LblDemReported == PORT_FALSE))
  {
    /* Initialize the loop count to ten */
    LucLoopCount = PORT_TEN;

    /* MISRA Rule         : 11.3                                              */
    /* Message            : A cast should not be performed between a          */
    /*                      pointer type and an integral type.                */
    /* Reason             : This is to access the hardware registers.         */
    /* Verification       : However, this part of the code is verified        */
    /*                      manually and it is not having any impact.         */

    /* Get the register address by adding the offset to the Base address */
    Lp32BitRegAddress =
                    (uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* Get the address of the corresponding PPROTS register */
    Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PSBC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PSBC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
    /* Get the address of the corresponding PPCMD register */
    Lp8BitPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PSBC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PSBC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
    do
    {
      *Lp8BitPPCMDRegAdd = PORT_WRITE_ERROR_CLEAR_VAL;
      /* Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

      /* MISRA Rule         : 12.7                                            */
      /* Message            : Bitwise operators shall not be applied to       */
      /*                      operands whose underlying type is signed.       */
      /* Reason             : Though the bitwise operation is performed on    */
      /*                      unsigned data, this warning is generated by     */
      /*                      the QAC tool V6.2.1 as an indirect result of    */
      /*                      integral promotion in complex bitwise           */
      /*                      operations.                                     */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* Write the bit wise inverse value to the corresponding register with
       * upper 16 bit set to one
       */
      *Lp32BitRegAddress = ~LpPortReg->usInitModeRegVal | PORT_MSB_MASK;
      /* Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);
      /* Decrement the loop count for each iteration */
      LucLoopCount--;
      /* Check the state of PPROTS register for successful write operation or
       * perform maximum ten tries, if failure occures report DEM and skip
       * further configuration
       */
    }while((*Lp8BitPPROTSRegAdd == PORT_ONE) && (LucLoopCount > PORT_ZERO));

    /* Check if the loop has exited because of failure of writing to register */
    if(*Lp8BitPPROTSRegAdd == PORT_ONE)
    {
      /* Report write failure production error */
      Dem_ReportErrorStatus(PORT_E_WRITE_FAILURE, DEM_EVENT_STATUS_FAILED);
      /* Set the Dem error flag */
      LblDemReported = PORT_TRUE;
    }

    /* MISRA Rule         : 17.4                                              */
    /* Message            : Increment or decrement operation performed        */
    /*                      on pointer.                                       */
    /* Reason             : This is to access the data structure              */
    /*                      pointing to next port group.                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

    LpPortReg++;
    LucNoOfRegs--;
  }
   if(LblDemReported == PORT_FALSE)
  {
    /* Get the count of total number of PMSR registers */
    LucNoOfRegs = LucNoOfPSRRegs;

    while(LucNoOfRegs > PORT_ZERO)
    {

      /* MISRA Rule         : 11.3                                            */
      /* Message            : A cast should not be performed between a        */
      /*                      pointer type and an integral type.              */
      /* Reason             : This is to access the hardware registers.       */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* MISRA Rule         : 9.1                                             */
      /* Message            : The variable '-identifier-' is apparently       */
      /*                      unset at this point.                            */
      /* Reason             : To access hardware registers                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Get the pointer to the PMSR registers */
      Lp32BitRegAddress =
         (uint32 *)(LpPMSRReg->usRegAddrOffset + LulUserBaseAddress);
      /* Write the register value to the corresponding register */
      *Lp32BitRegAddress = (LpPMSRReg->usInitModeRegVal | PORT_MSB_MASK);

      /* MISRA Rule         : 17.4                                            */
      /* Message            : Increment or decrement operation performed      */
      /*                      on pointer.                                     */
      /* Reason             : This is to access the data structure            */
      /*                      pointing to next port group.                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      LpPMSRReg++;
      LucNoOfRegs--;
    }


    /* MISRA Rule         : 9.1                                               */
    /* Message            : The variable '-identifier-' is apparently         */
    /*                      unset at this point.                              */
    /* Reason             : To access hardware registers                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

    /* Get the count of total number of Function Control registers */
    LucNoOfRegs = LucNoOfFuncCtrlRegs;

    while(LucNoOfRegs > PORT_ZERO)
    {
      /* MISRA Rule         : 11.3                                            */
      /* Message            : A cast should not be performed between a        */
      /*                      pointer type and an integral type.              */
      /* Reason             : This is to access the hardware registers.       */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* MISRA Rule         : 9.1                                             */
      /* Message            : The variable '-identifier-' is apparently       */
      /*                      unset at this point.                            */
      /* Reason             : To access hardware registers                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Get the pointer to the function control registers */
      Lp16BitRegAddress = (uint16 *)
                          (LpFuncCtrlReg->usRegAddrOffset + LulUserBaseAddress);
      /* Write the register value to the corresponding register */
      *Lp16BitRegAddress = LpFuncCtrlReg->usInitModeRegVal;

      /* MISRA Rule         : 17.4                                            */
      /* Message            : Increment or decrement operation performed      */
      /*                      on pointer.                                     */
      /* Reason             : This is to access the data structure            */
      /*                      pointing to next port group.                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      LpFuncCtrlReg++;
      LucNoOfRegs--;
    }

    /* Get the count of total number of Function Control SR registers */
    LucNoOfRegs = LucNoOfPMCSRRegs;

    while(LucNoOfRegs > PORT_ZERO)
    {

      /* MISRA Rule         : 11.3                                            */
      /* Message            : A cast should not be performed between a        */
      /*                      pointer type and an integral type.              */
      /* Reason             : This is to access the hardware registers.       */
      /* Verification       : However, this part of the code is verified      */
      /*                      manually and it is not having any impact.       */

      /* MISRA Rule         : 9.1                                             */
      /* Message            : The variable '-identifier-' is apparently       */
      /*                      unset at this point.                            */
      /* Reason             : To access hardware registers                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      /* Get the pointer to the function control registers */
      Lp32BitRegAddress = (uint32 *)
                          (LpFuncCtrlReg->usRegAddrOffset + LulUserBaseAddress);
      /* Write the register value to the corresponding register */
      *Lp32BitRegAddress = (LpFuncCtrlReg->usInitModeRegVal | PORT_MSB_MASK);

      /* MISRA Rule         : 17.4                                            */
      /* Message            : Increment or decrement operation performed      */
      /*                      on pointer.                                     */
      /* Reason             : This is to access the data structure            */
      /*                      pointing to next port group.                    */
      /* Verification       : However, part of the code is verified manually  */
      /*                      and it is not having any impact.                */

      LpFuncCtrlReg++;
      LucNoOfRegs--;
    }

  }
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
/*******************************************************************************
** Function Name        : Port_SearchDirChangeablePin
**
** Service ID           : Not Applicable
**
** Description          : This function used to verify whether the given pin is
**                        Direction changeable.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddPinNumber - Port Pin number
**                        LpStartPtr - Start pointer to the Changeable pin
**                        structures.
**                        Lucsize - Size of the Changeable pin structures.
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Pointer to Direction Changeable Pin structure - if
**                        given pin number matches.
**                        NULL - If Pin number does not match.
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        None
**                        Function(s) invoked:
**                        None
*******************************************************************************/
STATIC
FUNC(P2CONST(Tdd_Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
    , PORT_PRIVATE_CODE) Port_SearchDirChangeablePin(Port_PinType LddPinNumber,
     P2CONST(Tdd_Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
     LpStartPtr, uint8 Lucsize)
{

  P2CONST(Tdd_Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_DATA) LpRetPtr
                                                              = NULL_PTR;
  uint8 LddLow;
  uint8 LddHigh;
  uint8 LddMid;
  uint16 LddListSearchId;

  LddHigh = Lucsize - PORT_ONE;
  LddLow = PORT_ONE;

  /* Get the lower limit of Search ID */
  LddListSearchId = LpStartPtr->ddPinId;

  /* MISRA Rule         : 17.4                                                */
  /* Message            : Performing Pointer arithmetic.                      */
  /* Reason             : This is to get the ID in the                        */
  /*                      data structure in the code.                         */
  /* Verification       : However, part of the code is verified manually      */
  /*                      and it is not having any impact.                    */

  /* Check whether search Search-ID is in range */
  if((LddPinNumber >= LddListSearchId) &&
     (LddPinNumber <= ((LpStartPtr+LddHigh)->ddPinId)))
  {

    /* Check whether requested Search-ID is same as first Search-ID
     * of the list
     */
    if(LddPinNumber != LddListSearchId)
    {
      do
      {
        /* Get the middle index number */
        LddMid = (LddHigh + LddLow) >> PORT_ONE;

        /* Get the Search-ID of the mid IDs */
          LddListSearchId = ((LpStartPtr+LddMid)->ddPinId);

        /* Compare Search-ID with the requested one */
        if(LddListSearchId == LddPinNumber)
        {
          /* Update the return pointer with the pin number structure */
          LpRetPtr = (LpStartPtr + LddMid);

          /* Set LddHigh to zero to break the loop */
          LddHigh = PORT_ZERO;
        }
        else
        {
          /* Compare the Search-ID with the requested one */
          if(LddPinNumber < LddListSearchId)
          {
            /* MISRA Rule         : 21.1                                      */
            /* Message            : An integer expression with a value that   */
            /*                      apparently negative is being converted    */
            /*                      to an unsigned type.                      */
            /* Reason             : This is to update the local variable.     */
            /* Verification       : However, part of the code is verified     */
            /*                      manually and it is not having any impact. */

            /* If the priority is lower, update LddHigh */
            LddHigh = LddMid - PORT_ONE;
          }
          else
          {
            /* If the priority is higher, update LddLow */
            LddLow = LddMid + PORT_ONE;
          }
        }
      }while(LddLow <= LddHigh);
    }
    else
    {
      /* Update the return pointer with start pointer (Matches with first Id) */
        LpRetPtr = LpStartPtr;
    }
  }
  return LpRetPtr;
}

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
/*******************************************************************************
** Function Name        : Port_RefreshPortInternal
**
** Service ID           : Not Applicable
**
** Description          : This service shall refresh the direction of all
**                        configured ports to the configured direction.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : LenGroupType - Port Group Type
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : Ports should be initialized by calling Port_init().
**
** Remarks              : Global Variable(s):
**                        Port_GpConfigPtr
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
STATIC FUNC(void, PORT_PRIVATE_CODE) Port_RefreshPortInternal
                                                 (Port_GroupType LenGroupType)
{
  P2CONST(Tdd_Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)LpPMSRReg;
  P2VAR(uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPMSRRegAddress;

  uint32 LulBaseAddress;
  uint8 LucNoOfRegs;

  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  if(LenGroupType == PORT_GROUP_NUMERIC)
  {
    /* Get the pointer to 32Bit Numeric PMSR register structure */
    LpPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
    /* Get the count of 32Bit Numeric PMSR registers */
    LucNoOfRegs = Port_GpConfigPtr->ucNoOfNumPSRRegs;
    /* Get the Numeric base address */
    LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    }
  else
  #endif
  {
    #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
    if(LenGroupType == PORT_GROUP_ALPHABETIC)
    {
      /* Get the pointer to 32Bit Alphabetic PMSR register structure */
      LpPMSRReg = Port_GpConfigPtr->pPortAlphaPMSRRegs;
      /* Get the count of 32Bit Alphabetic PMSR registers */
      LucNoOfRegs = Port_GpConfigPtr->ucNoOfAlphaPSRRegs;
      /* Get the Alphabetic base address */
      LulBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
    }
    else
    #endif
    {
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      if(LenGroupType == PORT_GROUP_JTAG)
      {
        /* Get the pointer to 32Bit JTAG PMSR register structure */
        LpPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
        /* Get the count of 32Bit JTAG PMSR registers */
        LucNoOfRegs = PORT_JTAG_PSR_REGS;
        /* Get the JTAG base address */
        LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
      }
      #endif
    }
  }
  /* MISRA Rule         : 9.1                                               */
  /* Message            : The variable '-identifier-' is apparently         */
  /*                      unset at this point.                              */
  /* Reason             : To access hardware registers                      */
  /* Verification       : However, part of the code is verified manually    */
  /*                      and it is not having any impact.                  */
  while(LucNoOfRegs > PORT_ZERO)
  {
    /* MISRA Rule         : 11.3                                              */
    /* Message            : A cast should not be performed between a          */
    /*                      pointer type and an integral type.                */
    /* Reason             : This is to access the hardware registers.         */
    /* Verification       : However, this part of the code is verified        */
    /*                      manually and it is not having any impact.         */

    /* MISRA Rule         : 9.1                                               */
    /* Message            : The variable '-identifier-' is apparently         */
    /*                      unset at this point.                              */
    /* Reason             : To access hardware registers                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

    /* Get the contents of the register */
    LpPMSRRegAddress = (uint32 *)(LpPMSRReg->usRegAddrOffset +
                                                LulBaseAddress);

    /* Write the initial value to the pins which are Directional unchangeable
       and retain the values of those pins which are Directional changeable */
    *LpPMSRRegAddress = LpPMSRReg->ulMaskAndConfigValue;

    /* MISRA Rule         : 17.4                                              */
    /* Message            : Increment or decrement operation performed        */
    /*                      on pointer.                                       */
    /* Reason             : This is to access the data structure              */
    /*                      pointing to next port group.                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */

    LpPMSRReg++;
    LucNoOfRegs--;
  }
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */


#if((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */
/*******************************************************************************
** Function Name        : Port_FilterConfig
**
** Service ID           : Not Applicable
**
** Description          : This function used to initialize all the registers of
**                        filter configuration
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : None
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
**                        Port_GpConfigPtr
**                        Function(s) invoked:
**                        None
*******************************************************************************/
STATIC FUNC(void, PORT_PRIVATE_CODE) Port_FilterConfig(void)
{
  #if(PORT_DNFA_REG_CONFIG == STD_ON)
  P2CONST(Tdd_Port_DNFARegs, AUTOMATIC, PORT_CONFIG_DATA) LpDNFAReg;
  #endif
  #if(PORT_FCLA_REG_CONFIG == STD_ON)
  P2CONST(Tdd_Port_FCLARegs, AUTOMATIC, PORT_CONFIG_DATA) LpFCLAReg;
  #endif

  uint32 LulBaseAddress;
  uint8 LucNoOfRegs;

  #if(PORT_DNFA_REG_CONFIG == STD_ON)
  /* Get the base address for DNFA Noise Elimination Registers */
  LulBaseAddress = PORT_DNFA_BASE_ADDRESS;
  /* Get the pointer to the details of DNFA Noise Elimination Registers */
  LpDNFAReg = Port_GpConfigPtr->pPortDNFARegs;
  /* Get the count for total number of DNFA Noise Elimination Regsisters */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfDNFARegs;

  while(LucNoOfRegs > PORT_ZERO)
  {
    /* Write the DNFAnCTL register value to the corresponding register */
    /* MISRA Rule         : 11.3                                              */
    /* Message            : A cast should not be performed between a          */
    /*                      pointer type and an integral type.                */
    /* Reason             : This is to access the hardware registers.         */
    /* Verification       : However, this part of the code is verified        */
    /*                      manually and it is not having any impact.         */
    *((uint8 *)(LulBaseAddress + (uint32)LpDNFAReg->usDNFARegAddrOffset)) =
                                                          LpDNFAReg->ucDNFACTL;

    /* Write the DNFAnEN register value to the corresponding register */
    /* MISRA Rule         : 11.3                                              */
    /* Message            : A cast should not be performed between a          */
    /*                      pointer type and an integral type.                */
    /* Reason             : This is to access the hardware registers.         */
    /* Verification       : However, this part of the code is verified        */
    /*                      manually and it is not having any impact.         */
    *((uint16 *)(LulBaseAddress + (uint32)LpDNFAReg->usDNFARegAddrOffset +
                           PORT_DNFAEN_ADDRESS_OFFSET)) = LpDNFAReg->usDNFAEN;

    /* Increment the pointer to get the value of next structure */
    /* MISRA Rule         : 17.4                                              */
    /* Message            : Increment or decrement operation performed        */
    /*                      on pointer.                                       */
    /* Reason             : This is to access the data structure              */
    /*                      pointing to next port group.                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */
    LpDNFAReg++;
    /* Decrement the count for total number of DNFA Regsisters */
    LucNoOfRegs--;
  }

  #if(PORT_DNFS_AVAILABLE == STD_ON)
  /* Get the address of Digital noise filter sampling clock control register */
  LulBaseAddress = PORT_DNFS_BASE_ADDRESS;
  /* Load the value of Digital noise filter sampling clock control register */
  /* MISRA Rule         : 11.3                                                */
  /* Message            : A cast should not be performed between a            */
  /*                      pointer type and an integral type.                  */
  /* Reason             : This is to access the hardware registers.           */
  /* Verification       : However, this part of the code is verified          */
  /*                      manually and it is not having any impact.           */
  *((uint16 *)LulBaseAddress) = Port_GpConfigPtr->usPortDNFSRegVal;
  #endif /* End of PORT_DNFS_AVAILABLE == STD_ON */
  #endif /* End of PORT_DNFA_REG_CONFIG == STD_ON */

  #if(PORT_FCLA_REG_CONFIG == STD_ON)
  /* Get the base address for FCLA Noise Elimination Registers */
  LulBaseAddress = PORT_FCLA_BASE_ADDRESS;
  /* Get the pointer to the details of FCLA Noise Elimination Registers */
  LpFCLAReg = Port_GpConfigPtr->pPortFCLARegs;
  /* Get the count for total number of FCLA Noise Elimination Regsisters */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfFCLARegs;

  while(LucNoOfRegs > PORT_ZERO)
  {
    /* Write the FCLAnCTL register value to the corresponding register */
    /* MISRA Rule         : 11.3                                              */
    /* Message            : A cast should not be performed between a          */
    /*                      pointer type and an integral type.                */
    /* Reason             : This is to access the hardware registers.         */
    /* Verification       : However, this part of the code is verified        */
    /*                      manually and it is not having any impact.         */
    *((uint8 *)(LulBaseAddress + (uint32)LpFCLAReg->usFCLARegAddrOffset)) =
                                                          LpFCLAReg->ucFCLACTL;

    /* Increment the pointer to get the value of next structure */
    /* MISRA Rule         : 17.4                                              */
    /* Message            : Increment or decrement operation performed        */
    /*                      on pointer.                                       */
    /* Reason             : This is to access the data structure              */
    /*                      pointing to next port group.                      */
    /* Verification       : However, part of the code is verified manually    */
    /*                      and it is not having any impact.                  */
    LpFCLAReg++;
    /* Decrement the count for total number of FCLA Regsisters */
    LucNoOfRegs--;
  }
  #endif /* End of PORT_FCLA_REG_CONFIG == STD_ON */
}

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"/* PRQA S 5087 */

#endif /* End of (PORT_DNFA_REG_CONFIG == STD_ON) ||
                       (PORT_FCLA_REG_CONFIG == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
