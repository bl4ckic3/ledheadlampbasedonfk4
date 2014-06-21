/*****************************************************************************
|    File Name:  QueueFuncsList.h
|
|  Description:  File to put related functions list
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
#include "Platform_Types.h"
#include "Sys_QueueHandler.h"
#include "Api_SchdTbl.h"
#include "Can.h"
#include "IoHwAb_Can.h"
#include "IoHwAb_Api.h"
#include "LEDLightControl.h"
#include "LEDPWMActOut.h"

#define EVENT_FUNCS_ID(EventID) CaKERNEL_fp_##EventID

void Test_Task(void);


/******************************************************************************
* FUNCTION POINTER for each Event,  You can add related functions in the array. For example, driver door
* open event is possible related to power mode, content theft, chime, entry display etc subsystem handler
* fucntions.
*
*IMPORTANT NOTE: NULL must be last element of each array. No other elements except NULL is OK.
******************************************************************************/
const  FUNCTPTR CaKERNEL_1KmsTaskList[] = 
{
    NULL/*last ID must be DUMMY*/
};

const  FUNCTPTR CaKERNEL_500msTaskList[] = 
{

    NULL/*last ID must be DUMMY*/
};

const  FUNCTPTR CaKERNEL_200msTaskList[] = 
{

    NULL/*last ID must be DUMMY*/
};

const  FUNCTPTR CaKERNEL_100msTaskList[] = 
{
    NULL/*last ID must be DUMMY*/
};

const  FUNCTPTR CaKERNEL_50msTaskList[] = 
{
    NULL/*last ID must be DUMMY*/
};

const  FUNCTPTR CaKERNEL_20msTaskList[] = 
{
	Can_MainFunction_20mS,

	NULL/*last ID must be DUMMY*/
};

const  FUNCTPTR CaKERNEL_10msATaskList[] = 
{

	NULL/*last ID must be DUMMY*/
};

const  FUNCTPTR CaKERNEL_10msBTaskList[] = 
{
    LEDSwitchMainFunction,
    LEDPWMOutMainFunction,
    NULL/*last ID must be DUMMY*/
};

const  FUNCTPTR CaKERNEL_5msATaskList[] = 
{
	Test_Task,
	DoAb_UpdateChannel,
	NULL/*last ID must be DUMMY*/
};

const  FUNCTPTR CaKERNEL_5msBTaskList[] = 
{
  NULL/*last ID must be DUMMY*/
};

const  FUNCTPTR CaKERNEL_2p5msTaskList[] = 
{
    
    NULL/*last ID must be DUMMY*/
};


/*event function list*/
const FarFtnPtr_Arry EVENT_FUNCS_ID(CeEVT_e_Test)[] =
{
    Test_Task,
    NULL/* NULL must be the last position*/
};

/******************************************************************************
* FUNCTION LIST POINTER for each Event, it is correponding to the EVENT enumate array, the number must be
*exactly same
*
*IMPORTANT NOTE: First elemement is dummy event, its functions list is NULL
******************************************************************************/
const FarFtnPtr_Arry CaKERNEL_a_EventFuncs[] =
{
    NULL,/*first item must be NULL*/
    EVENT_FUNCS_ID(CeEVT_e_Test),
/*fill you Event list  here*/
};

void Task_BackGround(void)
{

}
void Task_InitAfterOsOn(void)
{

}

void SysSrvc_OsTickHook(void)
{

}

void Sys_EnterIdleClbk(void)
{

}

void Sys_ExitIdleCblk(void)
{

}

void GetCurHwTimer(void)
{

}
