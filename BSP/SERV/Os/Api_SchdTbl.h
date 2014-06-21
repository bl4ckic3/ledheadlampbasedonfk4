/*****************************************************************************
|    File Name:  SysQueueInfo.h
|
|  Description:  Mange periodically called system tasks
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
| 2012-02-16  01.00.00  zephan   Creation
|****************************************************************************/

#ifndef __API_SCHDTBL_H_
#define __API_SCHDTBL_H_

#define Reset_Event_OnceUse(EvtId)  ((EvtId) = 0)

/******************************************************************************
* Add new event here and add its corresponding handle function list in QueueFuncsList.h, then put the 
* function  list's pointer in CaKERNEL_fp_TaskFuncs at correct position. 
*
*Call EVENTQUEUE_PUSH when a change happen and corresponding event need to posted to notify to 
* handle related sub-system function.
******************************************************************************/
enum EVENT_LIST
{
    CeEVT_e_Dummy = 0,
    CeEVT_e_Test,
  
       
    CeEVT_e_TotalNum
};



#endif
