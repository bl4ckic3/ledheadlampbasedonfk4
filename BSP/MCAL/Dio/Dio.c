/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Dio.c                                                       */
/* Version      = 3.1.3                                                       */
/* Date         = 05-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API implementations of Dio Driver Component.            */
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
/* or implied,including but not limited to those for non-infringement of      */
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
 * V3.0.0:  04-Sep-2009  : Initial Version
 *
 * V3.0.1:  13-Nov-2009  : As per SCR 124, Updated to overcome the difference
 *                         of offset for PPR register address for JTAG Ports
 *                         as compared to Numeric and Alphabetic Ports.
 *
 * V3.0.2:  31-Mar-2010  : As per SCR 238, Dio_WriteChannel is updated for
 *                         change in used macro name from DIO_ZERO to STD_LOW.
 *
 * V3.0.3:  30-Aug-2010  : As per SCR 342, Dio_WriteChannelGroup(),
 *                         Dio_WriteChannel(), Dio_WritePort(),
 *                         Dio_readChannel(), Dio_readPort(),
 *                         Dio_readChannelGroup() are updated for SchM
 *                         Protection.
 *
 * V3.0.4:  14-Sep-2010  : As per SCR 352, Dio_WriteChannelGroup(),
 *                         Dio_WriteChannel(), Dio_WritePort(),
 *                         Dio_readChannel(), Dio_readPort(),
 *                         Dio_readChannelGroup() are updated for the removal
 *                         of SchM Protection.
 * V3.1.0:  27-Jul-2011  : Updated software version 3.1.0 .
 * V3.1.1:  04-Oct-2011  : Added comments for the violation of MISRA rule 19.1.
 * V3.1.2:  10-Feb-2012  : Merged the fixes done to Fx4L Dio driver.
 * V3.1.3:  05-Jun-2012  : As per SCR 027, following changes are made:
 *                         1. Dio_GetVersionInfo API is removed.
 *                         2. File version is changed.
 *                         3. Compiler version is removed from Environment
 *                            section.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dio.h"
#include "Dio_LTTypes.h"
#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define DIO_C_AR_MAJOR_VERSION    DIO_AR_MAJOR_VERSION_VALUE
#define DIO_C_AR_MINOR_VERSION    DIO_AR_MINOR_VERSION_VALUE
#define DIO_C_AR_PATCH_VERSION    DIO_AR_PATCH_VERSION_VALUE

/* File version information */
#define DIO_C_SW_MAJOR_VERSION    3
#define DIO_C_SW_MINOR_VERSION    1
#define DIO_C_SW_PATCH_VERSION    3

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (DIO_AR_MAJOR_VERSION != DIO_C_AR_MAJOR_VERSION)
  #error "Dio.c : Mismatch in Specification Major Version"
#endif
#if (DIO_AR_MINOR_VERSION != DIO_C_AR_MINOR_VERSION)
  #error "Dio.c : Mismatch in Specification Minor Version"
#endif
#if (DIO_AR_PATCH_VERSION != DIO_C_AR_PATCH_VERSION)
  #error "Dio.c : Mismatch in Specification Patch Version"
#endif

#if (DIO_SW_MAJOR_VERSION != DIO_C_SW_MAJOR_VERSION)
  #error "Dio.c : Mismatch in Major Version"
#endif
#if (DIO_SW_MINOR_VERSION != DIO_C_SW_MINOR_VERSION)
  #error "Dio.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Dio_ReadPort
**
** Service ID           : 0x02
**
** Description          : This service returns the level of all channels of
**                        given Port.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : PortlId
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Returns the value of physical level of the channels
**                        that form the Port
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Dio_GaaPortGroup
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
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
FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadPort(Dio_PortType PortId)
{
  P2CONST(Tdd_Dio_PortGroup, AUTOMATIC, DIO_PRIVATE_CONST) LpPortGroup;
  P2VAR(uint32, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  Dio_PortLevelType LddPortLevel;

  /* Initialize the return value to 0 */
  LddPortLevel = DIO_ZERO;

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)

  /* Check whether the Port Id is out of range */
  if (PortId >= DIO_MAXNOOFPORT)
  {
    /* Report Error to DET */
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_READ_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
  }
  else
  #endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get the pointer to the required Port */

    /* MISRA Rule        : 17.4                                           */
    /* Message           : Performing pointer arithmetic.                 */
    /* Reason            : To get access of port parameters.              */
    /* Verification      : However, part of the code is verified manually */
    /*                     and it is not having any impact.               */
    LpPortGroup = Dio_GstPortGroup + PortId;

    /* Get the Port Address for the required port */
    LpPortAddress = LpPortGroup->pPortAddress;

    /* Check if the required port is JTAG port */
    if(DIO_TRUE == LpPortGroup->blJtagPort)
    {
      /*
       * Read the port value from PPR register by adding offset to
       * PSR register address for JTAG Port
       */

      /* MISRA Rule        : 17.4                                           */
      /* Message           : Performing pointer arithmetic.                 */
      /* Reason            : To get PPR register address.                   */
      /* Verification      : However, part of the code is verified manually */
      /*                     and it is not having any impact.               */
      LddPortLevel = (Dio_PortLevelType)(*(LpPortAddress
                                                     + DIO_PPR_OFFSET_JTAG));
    }
    else
    {
      /*
       * Read the port value from PPR register by adding offset to
       * PSR register address for Numeric/Alphabetic Port
       */

      /* MISRA Rule        : 17.4                                           */
      /* Message           : Performing pointer arithmetic.                 */
      /* Reason            : To get PPR register address.                   */
      /* Verification      : However, part of the code is verified manually */
      /*                     and it is not having any impact.               */
      LddPortLevel = (Dio_PortLevelType)(*(LpPortAddress
                                                     + DIO_PPR_OFFSET_NONJTAG));
    }
  }

  /* Return the Port Level */
  return(LddPortLevel);
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Dio_WritePort
**
** Service ID           : 0x03
**
** Description          : This service writes the specified level to all the
**                        channels in given Port.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : PortId
**                        Level
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
**                        Dio_GaaPortGroup
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
FUNC(void, DIO_PUBLIC_CODE) Dio_WritePort
(Dio_PortType PortId, Dio_PortLevelType Level)
{
  P2CONST(Tdd_Dio_PortGroup, AUTOMATIC, DIO_PRIVATE_CONST) LpPortGroup;

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)

  /* Check whether the Port Id is out of range */
  if (PortId >= DIO_MAXNOOFPORT)
  {
    /* Report Error to DET */
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                             DIO_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
  }
  else
  #endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get the pointer to the required Port */

    /* MISRA Rule        : 17.4                                           */
    /* Message           : Performing pointer arithmetic.                 */
    /* Reason            : To get access of port parameters.              */
    /* Verification      : However, part of the code is verified manually */
    /*                     and it is not having any impact.               */
    LpPortGroup = Dio_GstPortGroup + PortId;

    /*
     * Write the Port value using 32-bit PSR register
     * Enable upper 16-bits using mask to effectively write to lower 16-bits
     */
    *(LpPortGroup->pPortAddress) = (Level | DIO_MSB_MASK);
  }
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Dio_ReadChannel
**
** Service ID           : 0x00
**
** Description          : This service returns the value of the specified
**                        DIO Channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : ChannelId
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Dio_LevelType - STD_HIGH/STD_LOW depending on the
**                        physical level of the Pin
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Dio_GstPortChannel
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_ReadChannel(Dio_ChannelType ChannelId)
{

  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  P2CONST(Tdd_Dio_PortChannel, AUTOMATIC, DIO_PRIVATE_CONST) LpPortChannel;
  P2VAR(uint32, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  Dio_PortLevelType LddPortLevel;
  #endif

  Dio_LevelType LddLevel;

  /* Initialize the return value to STD_LOW */
  LddLevel = STD_LOW;

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)

  /* Check whether the Channel Id is out of range */
  if (ChannelId >= DIO_MAXNOOFCHANNEL)
  {
    /* Report Error to DET */
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
  }
  else
  #endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if atleast one Channel is configured */
    #if (DIO_CHANNEL_CONFIGURED == STD_ON)

    /* Get the pointer to the required Channel */

    /* MISRA Rule        : 17.4                                           */
    /* Message           : Performing pointer arithmetic.                 */
    /* Reason            : To get access of the channel parameters.       */
    /* Verification      : However, part of the code is verified manually */
    /*                     and it is not having any impact.               */
    LpPortChannel = Dio_GstPortChannel + ChannelId;

    /* Get the Port Address in which the Channel is configured */
    LpPortAddress = LpPortChannel->pPortAddress;

    /* Check if the required port is JTAG port */
    if(DIO_TRUE == LpPortChannel->blJtagPort)
    {
      /*
       * Read the port value from PPR register by adding offset to
       * PSR register address for JTAG Port
       */

      /* MISRA Rule        : 17.4                                           */
      /* Message           : Performing pointer arithmetic.                 */
      /* Reason            : To get PPR register address.                   */
      /* Verification      : However, part of the code is verified manually */
      /*                     and it is not having any impact.               */
      LddPortLevel = (Dio_PortLevelType)(*(LpPortAddress
                                                     + DIO_PPR_OFFSET_JTAG));
    }
    else
    {
      /*
       * Read the port value from PPR register by adding offset to
       * PSR register address for Numeric/Alphabetic Port
       */

      /* MISRA Rule        : 17.4                                           */
      /* Message           : Performing pointer arithmetic.                 */
      /* Reason            : To get PPR register address.                   */
      /* Verification      : However, part of the code is verified manually */
      /*                     and it is not having any impact.               */
      LddPortLevel = (Dio_PortLevelType)(*(LpPortAddress
                                                     + DIO_PPR_OFFSET_NONJTAG));
    }

    /*
     * Mask the port value for required Channel bit position and
     * clear other bit positions
     */
    LddPortLevel &= (LpPortChannel->usMask);

    /* Check whether value is not equal to zero */
    if (LddPortLevel != DIO_ZERO )
    {
      /* Set the return value to STD_HIGH */
      LddLevel = STD_HIGH;
    }
    else
    {
    /* To Avoid Misra Warning */
    }
    #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */
  }

  /* Return the Channel Level */
  return LddLevel;
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Dio_WriteChannel
**
** Service ID           : 0x01
**
** Description          : This service writes the given value into the specified
**                        DIO Channel.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : ChannelId
**                        Level
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
**                        Dio_GstPortChannel
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannel
(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  P2CONST(Tdd_Dio_PortChannel, AUTOMATIC, DIO_PRIVATE_CONST) LpPortChannel;

  /* MISRA Rule        : 18.4                                                */
  /* Message           : An object of union type has been defined.           */
  /* Reason            : For accessing 32-bit PSR register separately for    */
  /*                     lower 16-bit data and upper 16-bit mask.            */
  /* Verification      : However, part of the code is verified manually and  */
  /*                     it is not having any impact.                        */
  Tun_Dio_PortData LunPSRContent;

  uint16 LusMask;
  #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)

  /* Check whether the Channel Id is out of range */
  if (ChannelId >= DIO_MAXNOOFCHANNEL)
  {
    /* Report Error to DET */
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
  }
  else
  #endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if atleast one Channel is configured */
    #if (DIO_CHANNEL_CONFIGURED == STD_ON)

    /* Get the pointer to the Port Channel */

    /* MISRA Rule        : 17.4                                           */
    /* Message           : Performing pointer arithmetic.                 */
    /* Reason            : To get access of the channel parameters.       */
    /* Verification      : However, part of the code is verified manually */
    /*                     and it is not having any impact.               */
    LpPortChannel = Dio_GstPortChannel + ChannelId;

    /* Get the mask value for the Channel */
    LusMask = LpPortChannel->usMask;

    /*
     * Enable appropriate Channel position by writing
     * upper 16bits of PSR register
     */
    LunPSRContent.Tst_WordValue.usMSWord = LusMask;

    /* Check if the input level value is ZERO */
    if (STD_LOW == Level)
    {
      /*
       * Make the Channel value as ZERO by writing
       * lower 16-bits of PSR register
       */
      LunPSRContent.Tst_WordValue.usLSWord = DIO_ZERO;
    }
    else
    {
      /*
       * Make the Channel value as ONE by writing
       * lower 16-bits of PSR register
       */
      LunPSRContent.Tst_WordValue.usLSWord = LusMask;
    }

    /* Load 32 bit value to PSR register */
    *(LpPortChannel->pPortAddress) = LunPSRContent.ulLongWord;

    #endif /* (DIO_CHANNEL_CONFIGURED == STD_ON) */
  }
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Dio_ReadChannelGroup
**
** Service ID           : 0x04
**
** Description          : This service returns the value of the ChannelGroup
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : ChannelGroupIdPtr
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Returns the value of physical level of the Channels
**                        that form the ChannelGroup
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        None
**                        Function(s) invoked:
**                        Det_ReportError
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroup
(CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr)
{
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  P2VAR(uint32, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  #endif

  Dio_PortLevelType LddPortLevel;

  /* Set the return value to 0 */
  LddPortLevel = DIO_ZERO;

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)

  /* Check whether ChannelGroupIdPtr is NULL_PTR */
  if (NULL_PTR == ChannelGroupIdPtr)
  {
    /* Report Error to DET */
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_CHANNEL_GROUP_SID,
                                                  DIO_E_PARAM_INVALID_GROUP_ID);
  }
  else
  #endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if atleast one ChannelGroup is configured */
    #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)

    /* Get the Port Address in which the Channel is configured */

    /* MISRA Rule        : 17.4                                           */
    /* Message           : Performing pointer arithmetic.                 */
    /* Reason            : To access the PPR register.                    */
    /* Verification      : However, part of the code is verified manually */
    /*                     and it is not having any impact.               */
    LpPortAddress = ChannelGroupIdPtr->pPortAddress;

    /* Check if the required port is JTAG port */
    if(DIO_TRUE == ChannelGroupIdPtr->blJtagPort)
    {
      /* Read the port value from PPR register by adding offset to */
      /* PSR register address for JTAG Port                        */

      /* MISRA Rule        : 17.4                                           */
      /* Message           : Performing pointer arithmetic.                 */
      /* Reason            : To get PPR register address.                   */
      /* Verification      : However, part of the code is verified manually */
      /*                     and it is not having any impact.               */
      LddPortLevel = (Dio_PortLevelType)(*(LpPortAddress
                                                     + DIO_PPR_OFFSET_JTAG));
    }
    else
    {
      /* Read the port value from PPR register by adding offset to */
      /* PSR register address for Numeric/Alphabetic Port          */

      /* MISRA Rule        : 17.4                                           */
      /* Message           : Performing pointer arithmetic.                 */
      /* Reason            : To get PPR register address.                   */
      /* Verification      : However, part of the code is verified manually */
      /*                     and it is not having any impact.               */
      LddPortLevel = (Dio_PortLevelType)(*(LpPortAddress
                                                     + DIO_PPR_OFFSET_NONJTAG));
    }

    /*
     * Mask the port value for required ChannelGroup related bit positions
     * and clear other bit positions
     */
    LddPortLevel &= (ChannelGroupIdPtr->usMask);

    /* Rotate right to get the corresponding ChannelGroup value */
    LddPortLevel >>= (ChannelGroupIdPtr->ucOffset);
    #endif /* (DIO_CHANNELGROUP_CONFIGURED == STD_ON) */
  }

  /* Return the ChannelGroup Level */
  return(LddPortLevel);
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

/*******************************************************************************
** Function Name        : Dio_WriteChannelGroup
**
** Service ID           : 0x05
**
** Description          : This service writes specified level to the
**                        ChannelGroup
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : ChannelGroupIdPtr
**                        Level
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
**                        Det_ReportError
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */

FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannelGroup
(CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr,
 Dio_PortLevelType Level)
{
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)

  /* MISRA Rule        : 18.4                                                */
  /* Message           : An object of union type has been defined.           */
  /* Reason            : For accessing 32-bit PSR register separately for    */
  /*                     lower 16-bit data and upper 16-bit mask.            */
  /* Verification      : However, part of the code is verified manually and  */
  /*                     it is not having any impact.                        */
  Tun_Dio_PortData LunPSRContent;

  uint16 LusMask;
  #endif

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)

  /* Check whether ChannelGroupIdPtr is NULL_PTR */
  if (NULL_PTR == ChannelGroupIdPtr)
  {
    /* Report Error to DET */
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_GROUP_SID,
                    DIO_E_PARAM_INVALID_GROUP_ID);
  }
  else
  #endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if atleast one ChannelGroup is configured */
    #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)

    /* Get the mask for the ChannelGroup */
    LusMask = ChannelGroupIdPtr->usMask;

    /* Rotate left the input level to get the value to be written to port */
    Level <<= (ChannelGroupIdPtr->ucOffset);

    /*
     * Enable appropriate ChannelGroup related positions
     * by writing upper 16-bits of PSR register
     */
    LunPSRContent.Tst_WordValue.usMSWord = LusMask;

    /* Write the Level value to lower 16-bits of PSR register*/
    LunPSRContent.Tst_WordValue.usLSWord = Level;

    /*Load 32 bit value to PSR register*/
    *(ChannelGroupIdPtr->pPortAddress) = LunPSRContent.ulLongWord;

    #endif /* (DIO_CHANNELGROUP_CONFIGURED == STD_ON) */
  }
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"/* PRQA S 5087 */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
