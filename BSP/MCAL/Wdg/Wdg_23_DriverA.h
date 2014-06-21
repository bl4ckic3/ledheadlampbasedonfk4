/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Wdg_23_DriverA.h                                            */
/* Version      = 3.0.2a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Pre-Compile Macros and API information                        */
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
 * V3.0.0:   12-Jun-2009 : Initial version 
 * V3.0.1:   14-Jul-2009 : As per SCR 015, compiler version is changed from 
 *                         V5.0.5 to V5.1.6c in the header of the file.
 * V3.0.2:   20-Jun-2011 : As per SCR 476 following changes are made
 *                         1. New variable ucWdtamdDefaultValue is added in the
 *                            structure STagTdd_Wdg_23_DriverA_ConfigType for
 *                            code optimization.
 *                         2. Data type of variable ddWdtamdDefaultMode changed
 *                            to WdgIf_ModeType.
 * V3.0.2a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef WDG_23_DRIVERA_H
#define WDG_23_DRIVERA_H
  
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"            
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

#define WDG_23_DRIVERA_VENDOR_ID  WDG_23_DRIVERA_VENDOR_ID_VALUE
#define WDG_23_DRIVERA_MODULE_ID  WDG_23_DRIVERA_MODULE_ID_VALUE
#define WDG_23_DRIVERA_INSTANCE_ID  WDG_23_DRIVERA_INSTANCE_ID_VALUE

/* Autosar specification version information */
#define WDG_23_DRIVERA_AR_MAJOR_VERSION  WDG_23_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_23_DRIVERA_AR_MINOR_VERSION  WDG_23_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_23_DRIVERA_AR_PATCH_VERSION  WDG_23_DRIVERA_AR_PATCH_VERSION_VALUE

/* Software version Information */
#define WDG_23_DRIVERA_SW_MAJOR_VERSION  WDG_23_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_23_DRIVERA_SW_MINOR_VERSION  WDG_23_DRIVERA_SW_MINOR_VERSION_VALUE
#define WDG_23_DRIVERA_SW_PATCH_VERSION  WDG_23_DRIVERA_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      DET ERROR CODES                                       **
*******************************************************************************/

/* Following error will be reported when API service is used in wrong context 
   (For eg. When Trigger / SetMode function is invoked without initialization)*/
#define WDG_23_DRIVERA_E_DRIVER_STATE      (uint8) 0x10

/* Following error will be reported when API service is called with wrong / 
   incosistent parameter(s) */
#define WDG_23_DRIVERA_E_PARAM_MODE        (uint8) 0x11

/* Following error will be reported when API service is called with wrong / 
   incosistent parameter(s) */
#define WDG_23_DRIVERA_E_PARAM_CONFIG      (uint8) 0x12

/* Following error will be reported when Wdg_GetVersionInfo API is invoked with 
   a null pointer */
#define WDG_23_DRIVERA_E_PARAM_POINTER     (uint8) 0xF0

/* Following error will be reported when Watchdog driver database does not 
   exist or exist in invalid location */
#define WDG_23_DRVA_E_INVALID_DATABASE     (uint8) 0xF1

typedef struct STagTdd_Wdg_23_DriverA_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc; 
  /* Value of WDTAMD register for SLOW mode*/
  uint8 ucWdtamdSlowValue;
  /* Value of WDTAMD register for FAST mode*/
  uint8 ucWdtamdFastValue;      
  /* Value of WDTAMD register for Default mode */
  uint8 ucWdtamdDefaultValue;
  /* Configured Default mode */
  WdgIf_ModeType ddWdtamdDefaultMode; 
    
}Wdg_23_DriverA_ConfigType;

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Service ID of Watchdog Driver Initialization API  */
#define WDG_23_DRIVERA_INIT_SID            0x00

/* Service ID of SetMode API which switches current watchdog mode to the 
   Watchdog mode defined by the parameter ModeSet */

#define WDG_23_DRIVERA_SETMODE_SID         0x01

/* Service ID of Trigger API which triggers the Watchdog Hardware*/
#define WDG_23_DRIVERA_TRIGGER_SID         0x02

/* Service ID of Version Information API */
#define WDG_23_DRIVERA_GETVERSIONINFO_SID  0x04

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define WDG_23_DRIVERA_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(Wdg_23_DriverA_ConfigType, 
              WDG_23_DRIVERA_CONFIG_CONST) Wdg_23_DriverA_GstConfiguration[];

#define WDG_23_DRIVERA_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#define WDG_23_DRIVERA_START_SEC_PUBLIC_CODE
#include "MemMap.h"
  
/* External Declaration for Watchdog Initialization API */
extern FUNC(void, WDG_23_DRIVERA_PUBLIC_CODE) Wdg_23_DriverAInit
  (P2CONST(Wdg_23_DriverA_ConfigType, AUTOMATIC, WDG_23_DRIVERA_APPL_CONST)
                                                                    ConfigPtr);
  
/* External Declaration for Watchdog SetMode API */
extern FUNC(Std_ReturnType, WDG_23_DRIVERA_PUBLIC_CODE) Wdg_23_DriverASetMode 
  (WdgIf_ModeType Mode);
  
/* External Declaration for Watchdog Trigger API */
extern FUNC(void, WDG_23_DRIVERA_PUBLIC_CODE) Wdg_23_DriverATrigger(void);
  

#if (WDG_23_DRIVERA_VERSION_INFO_API == STD_ON)

/* External Declaration for Watchdog Version Information API */
extern FUNC(void, WDG_23_DRIVERA_PUBLIC_CODE)Wdg_23_DriverAGetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_23_DRIVERA_APPL_DATA)versioninfo);

#endif
  
#define WDG_23_DRIVERA_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* WDG_23_DRIVERA_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
