/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Port_PBTypes.h                                              */
/* Version      = 3.1.5a                                                      */
/* Date         = 19-Feb-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2013 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post-build Time Parameters      */
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
 * V3.0.1:  07-Sep-2009  : As per SCR 026, Global Symbols section is updated for
 *                         the  addition of new macros, removal of unused macros
 *                         and alignment of macros.
 *
 * V3.0.3:  07-Nov-2009  : As per SCR 105, the code is updated to support Px4
 *                         variant.
 *
 * V3.0.4:  23-Feb-2010  : As per SCR 189, updated for Port Filter Functionality
 *                         implementation.

 * V3.0.5:  03-Mar-2010  : As per SCR 210, globle symbols section is updated.
 *
 * V3.0.6:  29-Sep-2010  : As per SCR 360, Global Symbols section updated.
 *
 * V3.0.7:  15-Mar-2011  : As per SCR 423, "PORT_WRITE_ERROR_CLEAR_VAL" macro
 *                         value is modified.
 *
 * V3.0.8:  24-Jun-2011  : As per SCR 479, In structure "STagTdd_Port_PMSRRegs"
 *                         parameters "usExistingValAndMask" and
 *                         "usConfigValUnchangeablePins" are removed and
 *                         "ulMaskAndConfigValue" is added.
 * V3.1.0: 26-Jul-2011   : Initial Version DK4-H variant
 * V3.1.1: 15-Sep-2011   : As per the DK-4H requirements
 *                         1. Added DK4-H specific JTAG information.
 *                         2. Added compiler switch for USE_UPD70F3529 device
 *                            name.
 * V3.1.2:  16-Feb-2012  : Merged the fixes done for Fx4L.
 * V3.1.3:  06-Jun-2012  : As per SCR 033, File version is changed.
 * V3.1.4:  10-Jul-2012  : As per SCR 047, "blPortType" is removed from the
 *                         structure "STagTdd_Port_Regs" and file version is
 *                         changed.
 * V3.1.5:  11-Dec-2012  : As per MNT_0005397 and MNT_0005415, added macro
 *                         for to clear I/O reset register.
 * V3.1.5a: 19-Feb-2013  : Merged the fixes done for Sx4-H
 */
/******************************************************************************/

#ifndef PORT_PBTYPES_H
#define PORT_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Port.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_PBTYPES_AR_MAJOR_VERSION  PORT_AR_MAJOR_VERSION_VALUE
#define PORT_PBTYPES_AR_MINOR_VERSION  PORT_AR_MINOR_VERSION_VALUE
#define PORT_PBTYPES_AR_PATCH_VERSION  PORT_AR_PATCH_VERSION_VALUE

/* File version information */
#define PORT_PBTYPES_SW_MAJOR_VERSION  3
#define PORT_PBTYPES_SW_MINOR_VERSION  1
#define PORT_PBTYPES_SW_PATCH_VERSION  4

#if (PORT_SW_MAJOR_VERSION != PORT_PBTYPES_SW_MAJOR_VERSION)
#error "Software major version of Port_PBTypes.h and Port.h did not match!"
#endif
#if (PORT_SW_MINOR_VERSION != PORT_PBTYPES_SW_MINOR_VERSION)
#error "Software minor version of Port_PBTypes.h and Port.h did not match!"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* General defines */
#define PORT_DBTOC_VALUE               ((PORT_VENDOR_ID_VALUE << 22) | \
                                       (PORT_MODULE_ID_VALUE << 14) | \
                                       (PORT_SW_MAJOR_VERSION_VALUE << 8) | \
                                       (PORT_SW_MINOR_VERSION_VALUE << 3))

#define PORT_FALSE                     (boolean)0x00
#define PORT_TRUE                      (boolean)0x01

#define PORT_ZERO                      (uint8)0x00
#define PORT_ONE                       (uint8)0x01
#define PORT_TEN                       (uint8)0x0A

#define PORT_UNINITIALIZED             (boolean)0x00
#define PORT_INITIALIZED               (boolean)0x01

#define PORT_JTAG_SR_REGS              (uint8)0x01
#define PORT_JTAG_FUNC_CTRL_REGS       (uint8)0x02
#define PORT_JTAG_OTHER_16BIT_REGS     (uint8)0x08

#define PORT_MAX_ALLOWED_PIN_MODES     (uint8)0x02
#define PORT_REG_NOTAVAILABLE          (uint8)0xFF

#define PORT_WRITE_ERROR_CLEAR_VAL     (uint8)0xA5

#define PORT_NUM_PODC_REG_ADD_OFFSET   (uint16)0x4500
#define PORT_NUM_PDSC_REG_ADD_OFFSET   (uint16)0x4600
#define PORT_NUM_PUCC_REG_ADD_OFFSET   (uint16)0x4900
#define PORT_NUM_PPROTS_REG_ADD_OFFSET (uint16)0x4B00
#define PORT_NUM_PPCMD_REG_ADD_OFFSET  (uint16)0x4C00
#define PORT_NUM_PSBC_REG_ADD_OFFSET   (uint16)0x4D00

#define PORT_JTAG_PODC_REG_ADD_OFFSET   (uint16)0x0450
#define PORT_JTAG_PDSC_REG_ADD_OFFSET   (uint16)0x0460
#define PORT_JTAG_PUCC_REG_ADD_OFFSET   (uint16)0x0490
#define PORT_JTAG_PPROTS_REG_ADD_OFFSET (uint16)0x04B0
#define PORT_JTAG_PPCMD_REG_ADD_OFFSET  (uint16)0x04C0
#define PORT_JTAG_PSBC_REG_ADD_OFFSET   (uint16)0x04D0

#define PORT_MSB_MASK                  (uint32)0xFFFF0000ul
#define PORT_IORES_CLR                 (uint32)0x00000000ul

#define PORT_IOHOLD_CLR                (uint32)0x00000008ul
#define PORT_IOHOLD_SET                (uint32)0x00000002ul

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Type definition for Port Group types */
typedef enum
{
  PORT_GROUP_NUMERIC = 0,
  PORT_GROUP_ALPHABETIC = 1,
  PORT_GROUP_JTAG = 2
} Port_GroupType;

typedef union STagTun_Port_Pin_Direction
{
  /* Full Word */
  uint32 ulRegContent;
  struct
  {
    /* Lower Word */
    uint16 usLSWord;
    /* Higher Word */
    uint16 usMSWord;
  }Tst_Port_Word;

} Tun_Port_Pin_Direction;

/*******************************************************************************
**   Structure declaration of port group registers, except PMSR, PFCE, PFC    **
**   and PMCSR.                                                               **
**   This structure will be generated in the following sequence of registers: **
**   PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC, PDSC, PUCC and PSBC.    **
*******************************************************************************/

typedef struct STagTdd_Port_Regs
{
  /*
   * Offset value of the register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usRegAddrOffset;
  /* Configured value of the port group registers for initial mode. */
  uint16 usInitModeRegVal;
} Tdd_Port_Regs;

/*******************************************************************************
**  Structure declaration of PFCE, PFC and PMCSR port group registers         **
**  This structure will be generated in the following sequence of registers:  **
**  PFCE, PFC and PMCSR.                                                      **
*******************************************************************************/
typedef struct STagTdd_Port_FuncCtrlRegs
{
  /*
   * Offset value of the register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usRegAddrOffset;
  /* Configured value of the port group registers for initial mode. */
  uint16 usInitModeRegVal;
  #if (PORT_SET_PIN_MODE_API == STD_ON)
  /* Configured value of the port group registers for set pin mode. */
  uint16 usSetModeRegVal;
  #endif

} Tdd_Port_FuncCtrlRegs;

/*******************************************************************************
**      Structure declaration of PMSR registers for all port groups           **
*******************************************************************************/
typedef struct STagTdd_Port_PMSRRegs
{
  /* Bit value of upper 16 bits (31-16) = 0 if for pin
     "PortPinDirectionChangeable" is configured as true
     Bit value of upper 16 bits (31-16) = 1 if for pin
     "PortPinDirectionChangeable" configured as false
     Bit value of lower 16 bits (15-0) = Initial value of the corresponding pin
  */
  uint32 ulMaskAndConfigValue;
  /*
   * Offset value of the PMSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usRegAddrOffset;
  /* Configured PMSR Register value for initial mode */
  uint16 usInitModeRegVal;
} Tdd_Port_PMSRRegs;

/*******************************************************************************
**  Structure containing information on PINs whose direction can be changed   **
**  during run time                                                           **
*******************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
typedef struct STagTdd_Port_PinsDirChangeable
{
  /* The PIN number whose direction is configured as changeable at run time */
  Port_PinType ddPinId;
  /*
   * Offset value of the PMSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usPMSRRegAddrOffset;
  /*
   * Offset value of the PSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usPSRRegAddrOffset;
  /* Mask value to check whether the requested direction and current direction
   * of the PIN are same.
   */
  uint16 usOrMaskVal;
  /* Configured level value for PSR register */
  uint16 usChangeableConfigVal;
  /* Indicates the Port type (Numeric/ Alphabetic/ JTAG) */
  uint8 ucPortType;

} Tdd_Port_PinsDirChangeable;
#endif /* End of PORT_SET_PIN_DIRECTION_API == STD_ON */

/*******************************************************************************
** Structure contains information about the port groups, containing the PINs  **
** whose mode can be changed during run time.                                 **
*******************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
typedef struct STagTdd_Port_PinModeChangeableGroups
{
  /* Index of the PSR register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPSRRegIndex;
  /* Index of the PFCE register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPFCERegIndex;
  /* Index of the PFC register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPFCRegIndex;
  /* Index of the PMCSR register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPMCSRRegIndex;
  /* Index of PMSR register in the structure array of PMSR registers.*/
  uint8 ucPMSRRegIndex;

} Tdd_Port_PinModeChangeableGroups;
#endif /* End of PORT_SET_PIN_MODE_API == STD_ON */

/*******************************************************************************
** Structure contains details of PINs whose mode can be changed during run    **
** time.                                                                      **
*******************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
typedef struct STagTdd_Port_PinModeChangeableDetails
{
  /* The PIN number whose mode is configured as changeable at run time. */
  Port_PinType ddPinId;
  /* Or mask value of the port pin */
  uint16 usOrMask;
  /* Index of the structure array which provide the information of port groups,
   * containing the PINs whose mode can be changed during run time
   */
  uint8 ucSetModeIndex;
  /* Indicates the Port type (Numeric/ Alphabetic/ JTAG)  */
  uint8 ucPortType;

} Tdd_Port_PinModeChangeableDetails;
#endif /* End of PORT_SET_PIN_MODE_API == STD_ON */

/*******************************************************************************
**   Structure contains the declaration for DNFA registers                    **
**   This structure will be generated in the following sequence of registers: **
**   DNFAnCTL, DNFAnEN.                                                       **
*******************************************************************************/
typedef struct STagTdd_Port_DNFARegs
{
  /*
   * Offset value of the DNFACTL register address. This value of any register,
   * if added to the base address, gives the address of that particular register
   */
  uint16 usDNFARegAddrOffset;
  /* Configured value for DNFA noise elimination control register */
  uint8 ucDNFACTL;
  /* Configured value for DNFA noise elimination enable register */
  uint16 usDNFAEN;
} Tdd_Port_DNFARegs;

/*******************************************************************************
**   Structure contains the declaration for FCLA registers                    **
**   This structure will be generated in the following sequence of registers: **
**   FCLAnCTL.                                                                **
*******************************************************************************/
typedef struct STagTdd_Port_FCLARegs
{
  /*
   * Offset value of the FLCACTL register address. This value of any register
   * if added to the base address, gives the address of that particular register
   */
  uint16 usFCLARegAddrOffset;
  /* Configured value for FCLA noise elimination control register */
  uint8 ucFCLACTL;
} Tdd_Port_FCLARegs;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Tdd_Port_Regs, PORT_CONST) Port_Num_Regs[];
extern CONST(Tdd_Port_FuncCtrlRegs, PORT_CONST) Port_Num_FuncCtrlRegs[];
extern CONST(Tdd_Port_PMSRRegs, PORT_CONST) Port_Num_PMSRRegs[];
#endif

#if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Tdd_Port_Regs, PORT_CONST) Port_Alpha_Regs[];
extern CONST(Tdd_Port_FuncCtrlRegs, PORT_CONST) Port_Alpha_FuncCtrlRegs[];
extern CONST(Tdd_Port_PMSRRegs, PORT_CONST) Port_Alpha_PMSRRegs[];
#endif

#if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Tdd_Port_Regs, PORT_CONST) Port_JTAG_Regs[];
extern CONST(Tdd_Port_FuncCtrlRegs, PORT_CONST) Port_JTAG_FuncCtrlRegs[];
extern CONST(Tdd_Port_PMSRRegs, PORT_CONST) Port_JTAG_PMSRRegs[];
#endif

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
extern CONST(Tdd_Port_PinsDirChangeable, PORT_CONST)
                                  Port_GstPinDirChangeableList[];
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
extern CONST(Tdd_Port_PinModeChangeableGroups, PORT_CONST)
                                  Port_GstSetModeGroupsList[];
extern CONST (Tdd_Port_PinModeChangeableDetails, PORT_CONST)
                                  Port_GstSetModePinDetailsList[];
#endif

extern CONST(Tdd_Port_DNFARegs, SPI_NOINIT_DATA) Port_DNFARegs[];
extern CONST(Tdd_Port_FCLARegs, SPI_NOINIT_DATA) Port_FCLARegs[];

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PORT_PBTYPES_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
