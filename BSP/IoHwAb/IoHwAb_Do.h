/*****************************************************************************
|File Name:  IoHwAb_Do.h
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
|2011-08-19  01.00.00     ZhanYi      Create
*****************************************************************************/
#ifndef _IOHWAB_DO_H
#define _IOHWAB_DO_H

/******************************************************************************
**                      Include Section                                      **
******************************************************************************/
#include "Dio.h"
#include "IoHwAb_DoCfg.h"




void	DoAb_Init(void);
void	DoAb_UpdateChannel(void);
void SetDO_DevCtrl(TeIoHwAb_e_DoIds Le_e_DoId, boolean Le_b_value);
void ClrDO_DevCtrl(TeIoHwAb_e_DoIds Le_e_DoId);
void SetDO_AppCtrl(TeIoHwAb_e_DoIds Le_e_DoId, boolean Le_b_value);
boolean GetDO_OutputVal(TeIoHwAb_e_DoIds Le_e_DoId);
#endif

/*EOF*/

