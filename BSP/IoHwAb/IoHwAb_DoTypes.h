/*****************************************************************************
|File Name:  IoHwAb_DoPrivate.h
|
|Description:  Abstracted digital output channels.
|
|-----------------------------------------------------------------------------
|               PATAC Confidential
|-----------------------------------------------------------------------------
|
| This software is copyright is proprietary of Pan Asia Technical Automotive Company(PATAC). 
| All rights are reserved by PATAC.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials      Name                   Company
| ------------------------------------   ---------------------------------------
|
|
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date            Version       Author     Description
|----------  --------  ------  ----------------------------------------------
|2011-08-19  01.00.00     WH      Create
*****************************************************************************/
#ifndef _IOHWAB_DOPRIAVATE_H
#define _IOHWAB_DOPRIAVATE_H

/******************************************************************************
**                      Include Section                                      **
******************************************************************************/
#include "std_types.h"

/*******************************************************************************
**                      Precompile Options                                    **
*******************************************************************************/
/*DO source type*/
#define CeDO_u_NullType    0
#define CeDO_u_DioType    1
#define CeDO_u_BufferType    2

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef struct
{
    uint8 * 	m_p_Buffer;                     /*pointer to the MCU IO port address or buffer*/
    uint8	m_u_Offset;	                    /*buffer offset or Dio index*/
    boolean	e_b_Inverse;                   /*if output inverse or not*/
    boolean	e_bt_DftVal;	                    /*Default value when normal operation */
    boolean	e_bt_En;                          /*enabled or not*/
    uint8       m_u_DoType;                     /*DO source type*/
}TsDO_h_PortConfig;

/*local configurations*/
extern const TsDO_h_PortConfig KaDO_h_PortConfig[];

#endif

/*EOF*/
