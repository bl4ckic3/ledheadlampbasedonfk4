/*****************************************************************************
|    File Name:  Sys_Runtimehandler.h
|
|  Description:  head file of Sys_Runtimehandler.C
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
| 2012-04-15  01.00.00  zephan   Creation
|****************************************************************************/
#ifndef __SYS_RUNTIME_H
#define __SYS_RUNTIME_H

#include "platform_types.h"
#include "tcb.h"

#define EN_RUNTM_STAT  
#define EN_STKCHK
#define PRD_RUNTM   
#define ISR_RUNTM
#ifndef PRD_TSKQUEUE
#define PRD_TSKQUEUE
#endif
typedef struct TagRunTm
{
/*    UINT32 begin_stamp;
    UINT32 end_stamp;*/
    UINT32 current_runtime;    
#ifdef EN_RUNTM_STAT
    UINT32 max_runtime;
    UINT32 avg_runtime;
    UINT32 tot_runtime;
    UINT8 sample_num;
#endif
} TagRunTm_Info;

typedef struct PrdRunTm
{
    UINT32 allowed_deviation;
    UINT32 bucket;
    UINT32 NextEp;
    UINT32 min_runtime;
}PrdRunTm_Info;

#ifdef PRD_TSKQUEUE
enum RunTmTarget
{
    CeTag_PrdTskdummy = 0,/*idle task*/
    CeTag_PrdTsk2p5,
    CeTag_PrdTsk5A,
    CeTag_PrdTsk5B,
    CeTag_PrdTsk10A,
    CeTag_PrdTsk10B,
    CeTag_PrdTsk20,
    CeTag_UserTst0,
    CeTag_UserTst1,
    CeTag_UserTst2,
    CeTag_UserTst3,
    CeTag_UserTst4,
    CeTag_UserTst5,
    CeTag_AllTag

};
#define PRDTSK_OFFSET  CeTag_PrdTskdummy

#endif

#define ISR_OFFSET  CeTag_UserTst0
extern UINT32 GetCurHwTimer(void);
extern void Sys_EnterIdleClbk(void);
extern void Sys_ExitIdleCblk(void);
#define SysSrvc_GetCurStamp() GetCurHwTimer()
#define SysSrvc_CalcRunTm(lststamp,curstamp)  ((curstamp) - (lststamp))

extern TagRunTm_Info VaSysSrvc_TagRuntmCheck[];

void SysSrvc_GetRunTmStat(TagRunTm_Info * pruntmtag,UINT32 curtm);

#endif
