/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Dio.h                                                       */
/* Version      = 3.1.2                                                       */
/* Date         = 05-Jun-2012                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, DIO type definitions, structure data types and  */
/* API function prototypes of DIO Driver                                      */
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
 * V3.0.0:  10-Nov-2009  : Initial version
 *
 * V3.0.1:  13-Nov-2009  : As per SCR 124, updated to include boolean parameter
 *                         for JTAG Ports.
 *
 * V3.0.2:  31-Mar-2010  : As per SCR 238, new line added at the end of file.
 * V3.1.0:  27-Jul-2011  : Modified for Dk4.
 * V3.1.1:  10-Feb-2012  : Merged the fixes done to Fx4L Dio driver.
 * V3.1.2:  05-Jun-2012  : As per SCR 027, following changes are made:
 *                         1. File version is changed.
 *                         2. Compiler version is removed from Environment
 *                            section.
 *                         3. Function Dio_GetVersionInfo is implemented as 
 *                            Macro.
 */
/******************************************************************************/

#ifndef DIO_H
#define DIO_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"      /* Standard AUTOSAR types */
#include "Dio_Cfg.h"        /* DIO Configuration header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define DIO_AR_MAJOR_VERSION       DIO_AR_MAJOR_VERSION_VALUE
#define DIO_AR_MINOR_VERSION       DIO_AR_MINOR_VERSION_VALUE
#define DIO_AR_PATCH_VERSION       DIO_AR_PATCH_VERSION_VALUE

/* File version information */
#define DIO_SW_MAJOR_VERSION       3
#define DIO_SW_MINOR_VERSION       1
#define DIO_SW_PATCH_VERSION       2

#if (DIO_CFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)
#error "Software major version of Dio.h and Dio_Cfg.h did not match!"
#endif
#if (DIO_CFG_SW_MINOR_VERSION!= DIO_SW_MINOR_VERSION )
#error "Software minor version of Dio.h and Dio_Cfg.h did not match!"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Vendor and Module IDs */
#define DIO_VENDOR_ID              DIO_VENDOR_ID_VALUE
#define DIO_MODULE_ID              DIO_MODULE_ID_VALUE
#define DIO_INSTANCE_ID            DIO_INSTANCE_ID_VALUE

/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)0x05

/* Service ID for DIO getting Version Information */
#define DIO_GETVERSIONINFO_SID         (uint8)0x12

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)0x0A

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP_ID   (uint8)0x1F

/* DET code to report Invalid pointer passed to the Dio_GetVersionInfo */
#define DIO_E_PARAM_INVALID_POINTER    (uint8)0xF0

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint16 Dio_PortLevelType;

/* Structure for Dio_ChannelGroup*/
typedef struct STagDio_ChannelGroupType
{
  /* Address of the port */
  P2VAR(uint32, AUTOMATIC, DIO_CONFIG_DATA) pPortAddress;
  /* Positions of the Channel Group */
  uint16 usMask;
  /* Position from LSB */
  uint8 ucOffset;
  /* Boolean paramter: 1 = JTAG port, 0 = Numeric/Alphabatic port */
  boolean blJtagPort;
} Dio_ChannelGroupType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Function for DIO read Channel API */
extern FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadPort
(Dio_PortType PortId);

/* Function for DIO write Channel API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_WritePort
(Dio_PortType PortId, Dio_PortLevelType Level);

/* Function for DIO read Port API */
extern FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_ReadChannel
(Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannel
(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Function for DIO read Channel Group API */
extern FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroup
(CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr);

/* Function for DIO write Channel Group API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannelGroup
(CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr,
 Dio_PortLevelType Level);

 /* Function for DIO getting Version Information API */
#if (DIO_VERSION_INFO_API == STD_ON)

  #define Dio_GetVersionInfo(versioninfo) \
  { \
    (versioninfo)->vendorID = (uint16)DIO_VENDOR_ID; \
    (versioninfo)->moduleID = (uint16)DIO_MODULE_ID; \
    (versioninfo)->instanceID = (uint8)DIO_INSTANCE_ID; \
    (versioninfo)->sw_major_version = DIO_SW_MAJOR_VERSION; \
    (versioninfo)->sw_minor_version = DIO_SW_MINOR_VERSION; \
    (versioninfo)->sw_patch_version = DIO_SW_PATCH_VERSION; \
  }

#endif  /* STD_ON == DIO_VERSION_INFO_API */

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define DIO_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(Dio_ChannelGroupType, DIO_CONST) Dio_GstChannelGroupData[];

#define DIO_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


#endif /* DIO_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
