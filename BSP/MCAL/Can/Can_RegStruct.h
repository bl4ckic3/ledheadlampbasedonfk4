/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = Can_RegStruct.h                                             */
/* Version      = 3.0.2a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2008-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
  /* Provision of Controller register structure.                              */
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
 * V3.0.1:  21.10.2009  : Updated compiler version as per
 *                        SCR ANMCANLINFR3_SCR_031.
 * V3.0.2:  20.01.2010  : 8 bit and 32 bit register structure is updated as per
 *                        SCR ANMCANLINFR3_SCR_042.
 * V3.0.2a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/


#ifndef CAN_REGSTRUCT_H
#define CAN_REGSTRUCT_H

/******************************************************************************
**                      Include Section                                      **
******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CAN_REGSTRUCT_AR_MAJOR_VERSION  2
#define CAN_REGSTRUCT_AR_MINOR_VERSION  2
#define CAN_REGSTRUCT_AR_PATCH_VERSION  2

/* File version information */
#define CAN_REGSTRUCT_SW_MAJOR_VERSION  3
#define CAN_REGSTRUCT_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Union for word access */
typedef union STagTun_Can_AFCan_WordAccess
{
  /* Word */
  uint16 usWord;
  struct
  {
    /* Lower Byte */
    uint8 ucLowByte;
    /* Higher Byte */
    uint8 ucHighByte;
  }Tst_ByteAccess;
}Tun_Can_AFCan_WordAccess;


/* CAN Identifier Data Structure */
typedef union STagTun_Can_AFCan_CanId
{
  uint32 ulCanId;
  struct
  {
    /* Lower CAN ID */
    uint16 usCanIdLow;
    /* Higher CAN ID */
    uint16 usCanIdHigh;
  }Tst_CanId;
}Tun_Can_AFCan_CanId;


/* Filter mask values */
typedef struct STagTdd_Can_AFCan_HwFilterMask
{
  /* Filter Mask value for Mask-Low */
  uint16 volatile usMaskLow;
  /* Filter Mask value for Mask-High */
  uint16 volatile usMaskHigh;
}Tdd_Can_AFCan_HwFilterMask;


/* Definitions of 16-Bit Filter mask registers for HW filtering */
typedef struct STagTdd_Can_AFCan_HwFilterMaskReg
{
  /* Filter Mask value for Mask-Low */
  uint16 volatile ucFcnCmmkCtl01h;                           /* 0h */
  /* Reserved */
  uint16 volatile aaReserved1[3];                       /* 2h - 7h */
  /* Filter Mask value for Mask-High */
  uint16 volatile ucFcnCmmkCtl02h;                           /* 8h */
  /* Reserved */
  uint16 volatile aaReserved2[3];                       /* Ah - Fh */
}Tdd_Can_AFCan_HwFilterMaskReg;


/* Definitions of 8-Bit Message Buffer Registers */
typedef struct  STagTdd_Can_AFCan_8bit_MsgBufferReg
{
  /* Data Buffer */
  uint8  aaDataBuffer[32];                            /* 00h - 1Fh */
  /* DLC */
  uint8  volatile ucFcnMmDtlgb;                             /* 20h */
  /* Reserved */
  uint8  volatile aaReserved1[3];                     /* 21h - 23h */
  /* Configuration Register */
  uint8  volatile ucFcnMmStrb;                              /* 24h */
  /* Reserved */
  uint8  volatile aaReserved2[27];                    /* 25h - 3Fh */
} Tdd_Can_AFCan_8bit_MsgBuffer;


/* Definitions of 16-Bit Message Buffer Registers */
typedef struct  STagTdd_Can_AFCan_16bit_MsgBufferReg
{
  /* Data Buffer */
  uint16 aaDataBuffer[16];                            /* 00h - 1Fh */
  /* Reserved */
  uint16 volatile aaReserved1[4];                     /* 20h - 27h */
  /* CAN ID Low */
  uint16 volatile usFcnMmMid0h;                             /* 28h */
  /* Reserved */
  uint16 volatile aaReserved2[3];                     /* 2Ah - 2Fh */
  /* CAN ID High */
  uint16 volatile usFcnMmMid1h;                             /* 30h */
  /* Reserved */
  uint16 volatile aaReserved3[3];                     /* 32h - 37h */
  /* Message Control Register */
  uint16 volatile usFcnMmCtl;                               /* 38h */
  /* Reserved */
  uint16 volatile aaReserved4[3];                     /* 3Ah - 3Fh */
} Tdd_Can_AFCan_16bit_MsgBuffer;


/* Definitions of 32-Bit Message Buffer Registers */
typedef struct  STagTdd_Can_AFCan_32bit_MsgBufferReg
{
  /* Data 0123 */
  uint32 volatile ulFcnMmDat0w;                             /* 00h */
  /* Reserved */
  uint32 volatile aaReserved0[3];                     /* 04h - 0Fh */
  /* Data 4567 */
  uint32 volatile ulFcnMmDat4w;                             /* 10h */
  /* Reserved */
  uint32 volatile aaReserved1[5];                     /* 14h - 27h */
  /* CAN ID */
  uint32 volatile ulFcnMmMid0w;                             /* 28h */
  /* Reserved */
  uint32 volatile aaReserved2[5];                     /* 2Ch - 3Fh */
} Tdd_Can_AFCan_32bit_MsgBuffer;


/* Definitions of 8-Bit Control Registers of CAN controller */
typedef struct STagTdd_Can_AFCan_8bit_CntrlRegs
{
  /* Global Clock Selection Register */
  uint8 volatile ucFcnGmcsPre;                                  /* 0_0008h */
  /* Reserved */
  uint8 volatile aaReserved1[23];                     /* 0_0009h - 0_001Fh */
  /* Automatic Block Transmission delay Register */
  uint8 volatile ucFcnGmadCtl;                                 /* 0_00020h */
  /* Reserved */
  uint8 volatile aaReserved2[551];                    /* 0_0021h - 0_0247h */
  /* Last Error Count Register */
  uint8 volatile ucFcnCmlcStr;                                  /* 0_0248h */
  /* Reserved */
  uint8 volatile aaReserved3[3];                       /* 0_0249h - 0_24Bh */
  /* Status Information Register */
  uint8 volatile ucFcnCminStr;                                  /* 0_024Ch */
  /* Reserved */
  uint8 volatile aaReserved4[27];                     /* 0_024Dh - 0_0267h */
  /* Bit Rate Prescaler */
  uint8 volatile ucFcnCmbrPrs;                                  /* 0_0268h */
  /* Reserved */
  uint8 volatile aaReserved5[15];                     /* 0_0269h - 0_0277h */
  /* Last in Pointer Register */
  uint8 volatile ucFcnCmliStr;                                  /* 0_0278h */
  /* Reserved */
  uint8 volatile aaReserved6[15];                     /* 0_0279h - 0_0287h */
  /* Last out Pointer Register */
  uint8 volatile ucFcnCmloStr;                                  /* 0_0288h */
  /* Reserved */
  uint8 volatile aaReserved7[3447];                   /* 0_0289h - 0_0FFFh */
  /* Message Buffer Register */
  Tdd_Can_AFCan_8bit_MsgBuffer ddMsgBuffer[64];       /* 0_1000h - 0_1FFFh */
  /* Reserved */
  uint8 volatile aaReserved8[4096];                   /* 0_2000h - 0_2FFFh */
}Tdd_Can_AFCan_8bit_CntrlReg;


/* Definitions of 16-Bit Control Registers of CAN controller */
typedef struct STagTdd_Can_AFCan_16bit_CntrlRegs
{
  /* Control Register */
  uint16 volatile usFcnGmclCtl;                                 /* 0_8000h */
  /* Reserved */
  uint16 volatile aaReserved1[7];                     /* 0_8002h - 0_800Fh */
  /* Configuration Register */
  uint16  volatile usFcnGmcfCtl;                                /* 0_8010h */
  /* Reserved */
  uint16 volatile aaReserved2[3];                     /* 0_8012h - 0_8017h */
  /* Automatic Block Transmission Register */
  uint16 volatile usFcnGmabCtl;                                 /* 0_8018h */
  /* Reserved */
  uint16 volatile aaReserved3[275];                   /* 0_801Ah - 0_823Fh */
  /* Global Control Register */
  uint16 volatile usFcnCmclCtl;                                 /* 0_8240h */
  /* Reserved */
  uint16 volatile aaReserved4[7];                     /* 0_8242h - 0_824Fh */
  /* Error Count Register */
  uint16 volatile usFcnCmerCnt;                                 /* 0_8250h */
  /* Reserved */
  uint16 volatile aaReserved5[3];                     /* 0_8252h - 0_8257h */
  /* Interrupt Enable Register */
  uint16 volatile usFcnCmieCtl;                                 /* 0_8258h */
  /* Reserved */
  uint16 volatile aaReserved6[3];                     /* 0_825Ah - 0_825Fh */
  /* Interrupt Status Register */
  uint16 volatile usFcnCmisCtl;                                 /* 0_8260h */
  /* Reserved */
  uint16 volatile aaReserved7[7];                     /* 0_8262h - 0_826Fh */
  /* Bit Timing Register */
  uint16 volatile usFcnCmbtCtl;                                 /* 0_8270h */
  /* Reserved */
  uint16 volatile aaReserved8[7];                     /* 0_8272h - 0_827Fh */
  /* Receive Get Pointer Register */
  uint16 volatile usFcnCmrgRx;                                  /* 0_8280h */
  /* Reserved */
  uint16 volatile aaReserved9[7];                     /* 0_8282h - 0_828Fh */
  /* Transmission Get Pointer Register */
  uint16 volatile usFcnCmtgTx;                                  /* 0_8290h */
  /* Reserved */
  uint16 volatile aaReserved10[3];                    /* 0_8292h - 0_8297h */
  /* Time Stamp Register */
  uint16 volatile usFcnCmtsCtl;                                 /* 0_8298h */
  /* Reserved */
  uint16 volatile aaReserved11[51];                   /* 0_829Ah - 0_82FFh */
  /* Filter Mask */
  Tdd_Can_AFCan_HwFilterMaskReg ddHwFilterMask[8];    /* 0_8300h - 0_837Fh */
  /* Reserved */
  uint16 volatile aaReserved12[1600];                 /* 0_8380h - 0_8FFFh */
  /* Message Buffer Register */
  Tdd_Can_AFCan_16bit_MsgBuffer ddMsgBuffer[64];      /* 0_9000h - 0_9FFFh */
  /* Reserved */
  uint16 volatile aaReserved13[2048];                 /* 0_A000h - 0_AFFFh */
}Tdd_Can_AFCan_16bit_CntrlReg;


/* Definitions of 32-Bit Control Registers of CAN controller */
typedef struct STagTdd_Can_AFCan_32bit_CntrlRegs
{
  /* Data New Bit Monitor Register */
  uint32 aaFcnDnbmRx[8];                              /* 1_00C0h - 1_00DFh */
  /* Reserved */
  uint32 volatile aaReserved1[136];                   /* 1_00E0h - 1_02FFh */
  /* Filter Mask */
  uint32 aaFcnCmmkCtl[32];                            /* 1_0300h - 1_037Fh */
  /* Reserved */
  uint32 volatile aaReserved2[800];                   /* 1_0380h - 1_0FFFh */
  /* Message Buffer Register */
  Tdd_Can_AFCan_32bit_MsgBuffer ddMsgBuffer[64];      /* 1_1000h - 1_1FFFh */
  /* Reserved */
  uint32 volatile aaReserved3[1024];                  /* 1_2000h - 0_2FFFh */
}Tdd_Can_AFCan_32bit_CntrlReg;


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CAN_REGSTRUCT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
