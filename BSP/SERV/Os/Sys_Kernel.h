/*****************************************************************************
|    File Name:  Sys_kernel.h
|
|  Description:  System task scheduler
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
|****************************************************************************/
#ifndef __SYS_KERNEL_H
#define __SYS_KERNEL_H

#include "std_types.h"

/*
 * File version information
 */
#define SYSSRVC_SW_MAJOR_VERSION       3
#define SYSSRVC_SW_MINOR_VERSION      3
#define SYSSRVC_SW_PATCH_VERSION       3

#define SYSSRVC_VENDOR_ID                       0
#define SYSSRVC_MODULE_ID                       0
#define SYSSRVC_INSTANCE_ID                    0


#define SetCycle() (VeKRN_b_RecycleFlag = TRUE)
#define ClrCycle() (VeKRN_b_RecycleFlag = FALSE)
#define IsCycle() (TRUE == VeKRN_b_RecycleFlag)

#define SendEvt(event ) SysSrvc_SendEvt(event)
#define IsEvt(event)  (event == VeKRN_w_TmpEvtID)
#define ClrEvt() (VeKRN_w_TmpEvtID = 0x0)
#define GetEvt() VeKRN_w_TmpEvtID
#define ClrEvent()  ClrEvt()

/*event backup and restore is done by OS, it's used in models*/
#define BckEvent() 
#define ResEvent() 

#define ChgEvtBool(bvar,bval,upevt,downevt)       if((bvar) != (bval))\
                                                                                {\
                                                                                    if(bval)\
                                                                                    {\
                                                                                        SendEvt(upevt);\
                                                                                    }\
                                                                                    else\
                                                                                    {\
                                                                                        SendEvt(downevt);\
                                                                                    }\
                                                                                }

#define ChgEvt(var,val,evt)                         if((var) != (val))\
                                                                    {\
                                                                            SendEvt(evt);\
                                                                    }

#define ChgEvtB(var,val,evt)                    ChgEvt(var,val,evt)
#define ChgEvt8(var,val,evt)                    ChgEvt(var,val,evt)
#define ChgEvt16(var,val,evt)                    ChgEvt(var,val,evt)
#define ChgEvt32(var,val,evt)                    ChgEvt(var,val,evt)
#define ChgEvtE(Var, Val, Evt)                    ChgEvt8(Var, Val, Evt)


extern UINT16 VeKRN_w_TmpEvtID;
extern BOOL VeKRN_b_RecycleFlag; 

void UserPreISRHook(UINT16 x);
void UserPostISRHook(UINT16 x);
void SysSrvc_GetVersionInfo(Std_VersionInfoType *versioninfo);


void SysSrvc_StartSchduler(void);
void SysSrvc_SendEvt(UINT16 EventID);

void EnterDataShare(void);
void ExitDataShare(void);



#endif
