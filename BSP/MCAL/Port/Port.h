/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Port.h                                                      */
/* Version      = 3.1.5                                                       */
/* Date         = 18-Mar-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, PORT type definitions, structure data types and */
/* API function prototypes of PORT Driver                                     */
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
 * V3.0.1:  07-Sep-2009  : As per SCR 026, Port_ConfigType structure is updated
 *                         for the additon of new elements to implement write
 *                         protection for write protected registers PODC, PDSC
 *                         PUCC and PSBC.
 *
 * V3.0.2:  13-Nov-2009  : As per SCR 120, Port_ConfigType structure is updated
 *                         for the additon of new element to support JTAG
 *                         function control registers.
 *
 * V3.0.3:  23-Feb-2010  : As per SCR 189, updated for Port Filter Functionality
 *                         implementation.
 *
 * V3.0.4:  05-Apr-2010  : As per SCR 245, Port_ConfigType structure is updated
 *                         to add updated ucNoOfNumRestoredRegs and
 *                         ucNoOfAlphaRestoredRegs
 * V3.1.0:  26-Jul-2011  : Initial Version DK4-H variant
 * V3.1.0: 26-Jul-2011   : Initial Version DK4-H variant
 * V3.1.1: 15-Sep-2011   : As per the DK-4H requirements
 *                         1. Added DK4-H specific JTAG information.
 * V3.1.2:  16-Feb-2012  :  Merged the fixes done for Fx4L
 * V3.1.3:  06-Jun-2012  : As per SCR 033, following changes are made:
 *                         1. File version is changed.
 *                         2. Function Port_GetVersionInfo is implemented as
 *                            Macro.
 * V3.1.4:  10-Jul-2012  : As per SCR 047, File version is changed.
 * V3.1.4a: 19-Feb-2013  : Port_ConfigType structure is updated for the addition
 *                         of new element ucNoOfJtagRestoredRegs to support JTAG
 *                         restored registers.
 * V3.1.5:  18-Mar-2013  : As per SCR 80 for the mantis issue #5399,
 *                         PORT_SW_PATCH_VERSION version is updated.
 */
/******************************************************************************/

#ifndef PORT_H
#define PORT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"
#include "Port_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* Version identification */
#define PORT_VENDOR_ID              PORT_VENDOR_ID_VALUE
#define PORT_MODULE_ID              PORT_MODULE_ID_VALUE
#define PORT_INSTANCE_ID            PORT_INSTANCE_ID_VALUE


/* AUTOSAR specification version information */
#define PORT_AR_MAJOR_VERSION       PORT_AR_MAJOR_VERSION_VALUE
#define PORT_AR_MINOR_VERSION       PORT_AR_MINOR_VERSION_VALUE
#define PORT_AR_PATCH_VERSION       PORT_AR_PATCH_VERSION_VALUE

/* File version information */
#define PORT_SW_MAJOR_VERSION       3
#define PORT_SW_MINOR_VERSION       1
#define PORT_SW_PATCH_VERSION       5

#if (PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)
#error "Software major version of Port.h and Port_Cfg.h did not match!"
#endif
#if (PORT_CFG_SW_MINOR_VERSION!= PORT_SW_MINOR_VERSION )
#error "Software minor version of Port.h and Port_Cfg.h did not match!"
#endif



/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                        Service IDs                                         **
*******************************************************************************/

/* Service ID for PORT Initialization */
#define PORT_INIT_SID                            (uint8)0x00
/* Service ID for setting the Direction of PORT Pin */
#define PORT_SET_PIN_DIR_SID                     (uint8)0x01
/* Service ID for refreshing the Direction of PORT Pin */
#define PORT_REFRESH_PORT_DIR_SID                (uint8)0x02
/* Service ID for PORT getting Version Information */
#define PORT_GET_VERSION_INFO_SID                (uint8)0x03
/* Service ID for setting the Mode of PORT Pin */
#define PORT_SET_PIN_MODE_SID                    (uint8)0x04

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                         (uint8)0x0A

/* Port Pin Direction not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE            (uint8)0x0B

/* API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG                      (uint8)0x0C

/* When valid Mode is not available */
#define PORT_E_PARAM_INVALID_MODE                (uint8)0x0D

/* When valid Mode is not configured as changeable  */
#define PORT_E_MODE_UNCHANGEABLE                 (uint8)0x0E

/* When PORT APIs are invoked before PORT Module Initialization */
#define PORT_E_UNINIT                            (uint8)0x0F

/* API Port_GetVersionInfo() API is invoked with wrong parameter */
#define PORT_E_PARAM_POINTER                     (uint8)0xF0

/* When valid Database is not available */
#define PORT_E_INVALID_DATABASE                  (uint8)0xEF

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Type definition for Port_PinType used by the API Port_SetPinDirection() */
typedef uint16 Port_PinType;

/* Type definition for Port_PinDirectionType used by the API
 * Port_SetPinDirection()
 */
typedef enum
{
  PORT_PIN_OUT = 0,
  PORT_PIN_IN = 1
}Port_PinDirectionType;

/* Type definition for Port_PinModeType used by the API
 * Port_SetPinMode()
 */
typedef enum
{
  PORT_INIT_MODE = 0,
  PORT_SETPIN_MODE = 1
}Port_PinModeType;

/* Structure for Port Init Configuration */
/* Overall Module Configuration Data Structure */
typedef struct STagPort_ConfigType
{
  /* Database start value - 0x05DF0300 */
  uint32 ulStartOfDbToc;

  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of Numeric Port Group registers in sequence: PSR,
   * PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC, PDSC, PUCC and PSBC.
   */
  P2CONST(struct STagTdd_Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)
    pPortNumRegs;

  /* Pointer to structure of Numeric Function Control Port Group registers
   * in sequence: PFCE, PFC and PMCSR
   */
  P2CONST(struct STagTdd_Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
    pPortNumFuncCtrlRegs;

  /* Pointer to structure of Numeric PMSR Port Group registers */
  P2CONST(struct STagTdd_Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)
    pPortNumPMSRRegs;
  #endif

  #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of Alphabetic Port Group registers in sequence:
   * PSR,PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC, PDSC, PUCC
   * and PSBC.
   */
  P2CONST(struct STagTdd_Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)
    pPortAlphaRegs;

  /* Pointer to structure of Alphabetic Function Control Port Group
   * registers in sequence: PFCE, PFC and PMCSR
   */
  P2CONST(struct STagTdd_Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
    pPortAlphaFuncCtrlRegs;

  /* Pointer to structure of Alphabetic PMSR Port Group registers */
  P2CONST(struct STagTdd_Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)
    pPortAlphaPMSRRegs;
  #endif

  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of JTAG Port Group registers in sequence:
   * PSR,PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC, PDSC, PUCC
   * and PSBC.
   */
  P2CONST(struct STagTdd_Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)
    pPortJRegs;

  /* Pointer to structure of JATG Function Control Port Group registers in
   * sequence: PFCE, PFC and PMCSR
   */
  P2CONST(struct STagTdd_Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
    pPortJFuncCtrlRegs;

  /* Pointer to structure of JTAG PMSR Port Group registers */
  P2CONST(struct STagTdd_Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)
    pPortJPMSRRegs;
  #endif

  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* Pointer to structure containing details about the pins whose direction
   * can be changed during run time.
   */
  P2CONST(struct STagTdd_Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
    pPinDirChangeable;
  #endif

  #if (PORT_SET_PIN_MODE_API == STD_ON)
  /* Pointer to structure containing details about the port pin mode */
  P2CONST(struct STagTdd_Port_PinModeChangeableGroups, AUTOMATIC,
                                   PORT_CONFIG_CONST)pPinModeChangeableGroups;
  P2CONST(struct STagTdd_Port_PinModeChangeableDetails, AUTOMATIC,
                                  PORT_CONFIG_CONST)pPinModeChangeableDetails;
  #endif

  #if(PORT_DNFA_REG_CONFIG == STD_ON)
  /* Pointer to array of structure containing details about DNFA registers */
  P2CONST(struct STagTdd_Port_DNFARegs, AUTOMATIC, SPI_CONFIG_DATA)
                                                                pPortDNFARegs;
  #endif

  #if(PORT_FCLA_REG_CONFIG == STD_ON)
  /* Pointer to array of structure containing details about FCLA registers */
  P2CONST(struct STagTdd_Port_FCLARegs, AUTOMATIC, SPI_CONFIG_DATA)
                                                                pPortFCLARegs;
  #endif

  #if(PORT_DNFS_AVAILABLE == STD_ON)
  /* The value of digital noise filter sampling clock control register */
  uint16 usPortDNFSRegVal;
  #endif

  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  /* The Total number of PSR/PMSR registers configured */
  uint8 ucNoOfNumPSRRegs;

  /* The Total number of PMCSR registers configured */
  uint8 ucNoOfNumPMCSRRegs;

  /* The Total number of other 16-Bit registers configured */
  uint8 ucNoOfNumOther16BitRegs;

  /* The Total number of Numeric PODC registers configured */
  uint8 ucNoOfNumPODCRegs;
   /* The Total number of Numeric PDSC registers configured */
  uint8 ucNoOfNumPDSCRegs;

  /* The Total number of Numeric PUCC registers configured */
  uint8 ucNoOfNumPUCCRegs;

  /* The Total number of Numeric PSBC registers configured */
  uint8 ucNoOfNumPSBCRegs;
   /* The Total number of Function Control registers configured */
  uint8 ucNoOfNumFuncCtrlRegs;

  #if(PORT_PIN_STATUS_BACKUP == STD_ON)
  /* The Total number of Numeric Restored registers configured */
  uint8 ucNoOfNumRestoredRegs;
  #endif
  #endif

  #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
  /* The Total number of PSR/PMSR registers configured */
  uint8 ucNoOfAlphaPSRRegs;

  /* The Total number of PMCSR registers configured */
  uint8 ucNoOfAlphaPMCSRRegs;

  /* The Total number of other 16-Bit registers configured */
  uint8 ucNoOfAlphaOther16BitRegs;

  /* The Total number of Alphabetic PODC registers configured */
  uint8 ucNoOfAlphaPODCRegs;
   /* The Total number of Alphabetic PDSC registers configured */
  uint8 ucNoOfAlphaPDSCRegs;

  /* The Total number of Alphabetic PUCC registers configured */
  uint8 ucNoOfAlphaPUCCRegs;

  /* The Total number of Alphabetic PSBC registers configured */
  uint8 ucNoOfAlphaPSBCRegs;
   /* The Total number of Function Control registers configured */
  uint8 ucNoOfAlphaFuncCtrlRegs;

  #if(PORT_PIN_STATUS_BACKUP == STD_ON)
  /* The Total number of Alphabetic Restored registers configured */
  uint8 ucNoOfAlphaRestoredRegs;
  #endif
  #endif

  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  /* The Total number of JTAG Function Control registers configured */
  uint8 ucNoOfJFuncCtrlRegs;
  #if (PORT_PIN_STATUS_BACKUP == STD_ON)
  /* The Total number of JTAG Restored registers configured */
  uint8 ucNoOfJtagRestoredRegs;
  #endif
  #endif

  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* The Total number of Pins configured for Direction Change at run time. */
  uint8 ucNoOfPinsDirChangeable;
  #endif

  #if (PORT_SET_PIN_MODE_API == STD_ON)
  /* The Total number of Pins configured for Mode Change at run time. */
  uint8 ucNoOfPinsModeChangeable;
  #endif

  #if(PORT_DNFA_REG_CONFIG == STD_ON)
  /* The total number of DNFA noise elimination registers configured */
  uint8 ucNoOfDNFARegs;
  #endif

  #if(PORT_FCLA_REG_CONFIG == STD_ON)
  /* The total number of FCLA noise elimination regsisters configured */
  uint8 ucNoOfFCLARegs;
  #endif

}Port_ConfigType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

extern FUNC(void, PORT_PUBLIC_CODE) Port_Init
(
   P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST)ConfigPtr
);

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
extern FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDirection
(
   Port_PinType Pin, Port_PinDirectionType Direction
);
#endif

extern FUNC(void, PORT_PUBLIC_CODE) Port_RefreshPortDirection
(
   void
);

#if (PORT_VERSION_INFO_API == STD_ON)

#define Port_GetVersionInfo(versioninfo) \
  { \
    (versioninfo)->vendorID         = (uint16)PORT_VENDOR_ID;    \
    (versioninfo)->moduleID         = (uint16)PORT_MODULE_ID;    \
    (versioninfo)->instanceID       = (uint8)PORT_INSTANCE_ID;  \
    (versioninfo)->sw_major_version = PORT_SW_MAJOR_VERSION;    \
    (versioninfo)->sw_minor_version = PORT_SW_MINOR_VERSION;    \
    (versioninfo)->sw_patch_version = PORT_SW_PATCH_VERSION;    \
  }
#endif /* End of (PORT_VERSION_INFO_API == STD_ON) */

#if (PORT_SET_PIN_MODE_API == STD_ON)
extern FUNC (void, PORT_PUBLIC_CODE) Port_SetPinMode
(
   Port_PinType Pin, Port_PinModeType Mode
);
#endif

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define PORT_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for PORT Init configuration */
extern CONST(Port_ConfigType, PORT_CONST) Port_GstConfiguration[];

#define PORT_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* PORT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
