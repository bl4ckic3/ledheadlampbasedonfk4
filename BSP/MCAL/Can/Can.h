/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can.h                                                       */
/* Version      = 3.0.5a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of external declaration of APIs and Service IDs.                 */
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
 * V3.0.0:  12.12.2008  : Initial Version
 * V3.0.1:  10.10.2009  : DET Updated to support INVALID DATABASE error and
 *                        ControllerConfigType structure is updated
 *                        for H/W changes as per SCR ANMCANLINFR3_SCR_031
 * V3.0.2:  21.04.2010  : As per ANMCANLINFR3_SCR_056, provision for Tied Wakeup
 *                        interrupts is added.
 * V3.0.3:  11.05.2010  : 1. "ucMaxNofBasicCanHth" is added in "Can_ConfigType"
 *                        for multiple configuration support as per
 *                        ANMCANLINFR3_SCR_060.
 *                        2. "ddMask<xxx>Reg" are renamed to "ucMask<xxx>Reg" as
 *                        per guidelines. Also their data type is changed from
 *                        uint16 to uint8.
 * V3.0.4:  12.09.2010  : As per ANMCANLINFR3_SCR_083, Can_AFCan_GstConfigType
 *                        is changed as Can_AFCan_GaaConfigType.
 * V3.0.5:  20.06.2011  : As per ANMCANLINFR3_SCR_0107, Type and name of the 
 *                        variables usMaskERRReg, usMaskWUPReg, usMaskRECReg, 
 *                        usMaskTRXReg, pIntCntrlReg and pWupIntCntrlReg is 
 *                        changed as uint16.
 * V3.0.5a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/

#ifndef CAN_H
#define CAN_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "ComStack_Types.h"   /* Type definition header file */
#include "Can_Cfg.h"          /* Configuration header file */
#include "Can_RegStruct.h"    /* Register structure header file */
#if(CAN_WAKEUP_SUPPORT == STD_ON)
#include "EcuM_Cbk.h"         /* ECUM callback and callout header file */
#endif
#include "Can_GenericTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Common Published Information */
#define CAN_AR_MAJOR_VERSION  2
#define CAN_AR_MINOR_VERSION  2
#define CAN_AR_PATCH_VERSION  2

#define CAN_SW_MAJOR_VERSION  3
#define CAN_SW_MINOR_VERSION  0
#define CAN_SW_PATCH_VERSION  0

/* CAN Module Id */
#define CAN_MODULE_ID         (uint16)80
/* CAN Module Vendor Id */
#define CAN_VENDOR_ID         (uint16)23

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* CAN Module Instance Id */
#define CAN_INSTANCE_ID       (uint8)0x00

/* Service ID for Can_Init */
#define CAN_INIT_SID                          (uint8)0x00
/* Service ID for Can_InitController */
#define CAN_INIT_CNTRL_SID                    (uint8)0x02
/* Service ID for Can_GetVersionInfo */
#define CAN_GET_VERSIONINFO_SID               (uint8)0x07
/* Service ID for Can_SetControllerMode */
#define CAN_SET_MODECNTRL_SID                 (uint8)0x03
/* Service ID for Can_DisableControllerInterupts */
#define CAN_DISABLE_CNTRL_INT_SID             (uint8)0x04
/* Service ID for Can_EnableControllerInterupts */
#define CAN_ENABLE_CNTRL_INT_SID              (uint8)0x05
/* Service ID for Can_Write */
#define CAN_WRITE_SID                         (uint8)0x06
/* Service ID for Can_MainFunction_Write */
#define CAN_MAIN_WRITE_SID                    (uint8)0x01
/* Service ID for Can_MainFunction_Read */
#define CAN_MAIN_READ_SID                     (uint8)0x08
/* Service ID for Can_MainFunction_BusOff */
#define CAN_MAIN_BUSOFF_SID                   (uint8)0x09
/* Service ID for Can_MainFunction_Wakeup */
#define CAN_MAIN_WAKEUP_SID                   (uint8)0x0a
/* Service ID for Can_CheckWakeup */
#define CAN_CHK_WAKEUP_SID                    (uint8)0x0b

/* API service called with null Pointer */
#define CAN_E_PARAM_POINTER                   (uint8)0x01
/* API service called with wrong Handle */
#define CAN_E_PARAM_HANDLE                    (uint8)0x02
/* API service called with wrong DLC */
#define CAN_E_PARAM_DLC                       (uint8)0x03
/* API service called with wrong Controller Id */
#define CAN_E_PARAM_CONTROLLER                (uint8)0x04
/* API service called with Uninitialization */
#define CAN_E_UNINIT                          (uint8)0x05
/* API service called with wrong Transition */
#define CAN_E_TRANSITION                      (uint8)0x06
/* API service called with wrong database addresss */
#define CAN_E_INVALID_DATABASE                (uint8)0x07

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*CAN Controller configuration */
typedef struct STagCan_ControllerConfigType
{
  /* Pointer to Hardware Filter Mask */
  P2CONST(Tdd_Can_AFCan_HwFilterMask, AUTOMATIC, CAN_AFCAN_CONFIG_CONST)
                                                                    pFilterMask;

  /* Pointer to Interrupt Control Registers. This is the address of Interrupt
     Control Registers as provided in the configuration for corresponding
     CanController */
  P2VAR(uint16,AUTOMATIC,CAN_AFCAN_CONFIG_DATA)pIntCntrlReg;
  /* Pointer to Wake-up Interrupt Control Registers */
  P2VAR(uint16,AUTOMATIC,CAN_AFCAN_CONFIG_DATA)pWupIntCntrlReg;
  /* Pointer to Wakeup Status Flag */
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2VAR(uint8,AUTOMATIC,CAN_AFCAN_CONFIG_DATA)pWkpStsFlag;
  #endif
  /* Pointer to First HRH */
  P2CONST(void, AUTOMATIC, CAN_AFCAN_CONFIG_CONST)pHrh;
  /* Pointer to First HTH */
  P2CONST(void, AUTOMATIC, CAN_AFCAN_CONFIG_CONST)pHth;
  /* Pointer to 8-bit Control Register Base Address as
     provided in the configuration for corresponding CanController */
  P2VAR(Tdd_Can_AFCan_8bit_CntrlReg, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)
                                                                  pCntrlReg8bit;
  /* Pointer to 16-bit Control Register Base Address as
     provided in the configuration for corresponding CanController */
  P2VAR(Tdd_Can_AFCan_16bit_CntrlReg, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)
                                                                 pCntrlReg16bit;
  /* Pointer to 8-bit Control Register Base Address as
     provided in the configuration for corresponding CanController */
  P2VAR(Tdd_Can_AFCan_32bit_CntrlReg, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)
                                                                 pCntrlReg32bit;
  #if  (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Pointer to Controller Mode */
  P2VAR(uint8, AUTOMATIC, CAN_AFCAN_CONFIG_DATA)pCntrlMode;
  #endif
  /* Wakeup Source Type */
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  EcuM_WakeupSourceType ddWakeupSourceId;
  #endif
  /* Bit   8      : Tx Processing
           9      : Rx Processing
           10     : BusOff Processing
           13     : Wakeup Processing
           14     : Tx Cancel Processing
  */
  /* Interrupt Enable Bit */
  uint16 usIntEnable;
  /* Bit Timing Register */
  uint16 usBTR;
  /* Mask for Bus-off configuration */
  uint16 usMaskERRReg;
  /* Mask for Wake-up configuration */
  uint16 usMaskWUPReg;
  /* Mask for Receive Interrupt configuration */
  uint16 usMaskRECReg;
  /* Mask for Transmit Interrupt configuration */
  uint16 usMaskTRXReg;
  /* Bit Rate Prescaler */
  uint8 ucBRP;
  /* No. Of Filter Mask number */
  uint8 ucNoOfFilterMask;
  /* Number of HRH */
  uint8 ucNoOfHrh;
  /* Number of HTH */
  uint8 ucNoOfHth;
  /* Start of Hth */
  sint16 ssHthOffSetId;
  /* Start of Hrh */
  uint8 ucHrhOffSetId;
  /* Controller Reg Id */
  uint8 ucCntrlRegId;
  /* Maximum number of Message buffers in the controller */
  uint8 ucMaxNoOfMsgBufs;
  #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
  /* Number of BasicCan Hth configured for the controller */
  uint8 ucNoOfBasicCanHth;
  /* Offset for getting the first BasicCan Hth of the controller */
  uint8 ucBasicCanHthOffset;
  #endif
 }Can_ControllerConfigType;

/* CAN Driver Initialization configuration */
typedef struct STagCan_ConfigType
{
  /* StartOfDbToc */
  uint32 ulStartOfDbToc;
  /* Pointer to first Controller structure */
  P2CONST(Can_ControllerConfigType,AUTOMATIC,
                                       CAN_AFCAN_CONFIG_CONST) pFirstController;
  /* Pointer to first Hrh structure */
  P2CONST(void, AUTOMATIC, CAN_AFCAN_CONFIG_CONST) pFirstHth;
  /* Pointer to Controller ID array */
  P2CONST(uint8, AUTOMATIC, CAN_AFCAN_CONFIG_CONST)pCntrlIdArray;
  /* First index of Hth */
  uint8 ucFirstHthId;
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Last index of Hth */
  uint8 ucLastHthId;
  /* Index of last Controller in the configuration */
  uint8 ucLastCntrlId;
  #endif
  #if (CAN_HW_TRANSMIT_CANCELLATION_SUPPORT == STD_ON)
  /* Maximum number of BasicCan Hth configured */
  uint8 ucMaxNofBasicCanHth;
  #endif
}Can_ConfigType;

/*******************************************************************************
**                      Extern declarations for Global Data                   **
*******************************************************************************/
#define CAN_AFCAN_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Global array for Config structure */
extern CONST(Can_ConfigType, CAN_AFCAN_CONST) Can_AFCan_GaaConfigType[];

#define CAN_AFCAN_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#define CAN_AFCAN_START_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Global array for ControllerConfigType structure */
extern CONST(Can_ControllerConfigType, CAN_AFCAN_CONST)
                                       Can_AFCan_GaaControllerConfigType[];

#define CAN_AFCAN_STOP_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAN_AFCAN_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* API for global initialization */
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE) Can_Init
              (P2CONST(Can_ConfigType, AUTOMATIC, CAN_AFCAN_APPL_CONST) Config);
/* API for initialization Controller */
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE) Can_InitController
                 (uint8 Controller, P2CONST(Can_ControllerConfigType, AUTOMATIC,
                                                  CAN_AFCAN_APPL_CONST) Config);
/* API for set Controller mode */
extern FUNC(Can_ReturnType, CAN_AFCAN_PUBLIC_CODE)
    Can_SetControllerMode(uint8 Controller, Can_StateTransitionType Transition);
/* API for disabling Controller interrupt */
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
  Can_DisableControllerInterrupts(uint8 Controller);

/* API for enabling Controller interrupt */
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE)
  Can_EnableControllerInterrupts(uint8 Controller);

/* API for Can Write */
extern FUNC(Can_ReturnType, CAN_AFCAN_PUBLIC_CODE)
  Can_Write(uint8 Hth,
                 P2CONST(Can_PduType, AUTOMATIC, CAN_AFCAN_APPL_CONST) PduInfo);

/* API for schedule processing of write */
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE) Can_MainFunction_Write(void);
/* API for schedule processing of read */
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE) Can_MainFunction_Read(void);
/* API for schedule processing of BusOff */
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE) Can_MainFunction_BusOff(void);
/* API for schedule processing of Wakeup */
extern FUNC(void, CAN_AFCAN_PUBLIC_CODE) Can_MainFunction_Wakeup(void);
/* API to get the version information */
extern FUNC(void,CAN_AFCAN_PUBLIC_CODE) Can_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_AFCAN_APPL_DATA) versioninfo);
/* API for checking wakeup */
extern FUNC(Std_ReturnType, CAN_AFCAN_PUBLIC_CODE)Can_CheckWakeup
                                                             (uint8 Controller);

#define CAN_AFCAN_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* CAN_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

