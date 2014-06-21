/*****************************************************************************
|    File Name:  Sys_stackhandler.h
|
|  Description:  System stack handler
|
|-----------------------------------------------------------------------------
|               PATAC Confidential
|-----------------------------------------------------------------------------
|
| This software is copyright is proprietary of
| Pan Asia Technical Automotive Company(PATAC). 
| All rights are reserved by PATAC.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials      Name                   Company
| --------      --------------------   ---------------------------------------
| FRED        Wang Wanrong     PATAC
|
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author     Description
| ----------  --------  ------  ----------------------------------------------
| 2008-12-28  01.00.00  FRED   Creation
| 2009-10-16  01.01.01 FRED   Add Interface for operation system to command to start algorithm calculation.
|****************************************************************************/
#ifndef __SYS_STACK_H
#define __SYS_STACK_H

#include "platform_types.h"

extern UINT16 VaSysSrvc_uwStkUsage[3];

void SysSrvc_StackCheck(void);


#endif
