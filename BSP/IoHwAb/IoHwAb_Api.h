/*****************************************************************************
|File Name:  IoHwAb_Api.h
|
|Description:  
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
| Date       Version    Author  Description
|----------  --------   ------  ----------------------------------------------
|2014-04-01  01.00.00   ZhanYi  Create
*****************************************************************************/

#ifndef _IOHWAB_API_H
#define _IOHWAB_API_H

#include "Std_Types.h"
#include "Dio.h"
#include "IoHwAb_Do.h"

/*----------------------------------------------------------------------------------
- Digital Outputs
-----------------------------------------------------------------------------------*/
#define IoHwAb_SetODH1(x)         SetDO_AppCtrl(CeDO_e_ODH1, (boolean)(x)) /*Corner lamp*/
#define IoHwAb_SetODH2(x)         SetDO_AppCtrl(CeDO_e_ODH2, (boolean)(x)) /*FAN Control*/
#define IoHwAb_SetDRLFAIL(x)      SetDO_AppCtrl(CeDO_e_OUT1, (boolean)(x))
#define IoHwAb_SetLowBeam1Fail(x) SetDO_AppCtrl(CeDO_e_OUT2, (boolean)(x))
#define IoHwAb_SetLowBeam2Fail(x) SetDO_AppCtrl(CeDO_e_OUT3, (boolean)(x))
#define IoHwAb_SetTurnLampFail(x) SetDO_AppCtrl(CeDO_e_OUT4, (boolean)(x))

#define IoHwAb_GetODH1(x)         GetDO_AppCtrl(CeDO_e_ODH1, (boolean)(x))
#define IoHwAb_GetODH2(x)         GetDO_AppCtrl(CeDO_e_ODH2, (boolean)(x))
#define IoHwAb_GetDRLFAIL(x)      GetDO_AppCtrl(CeDO_e_OUT1, (boolean)(x))
#define IoHwAb_GetLowBeam1Fail(x) GetDO_AppCtrl(CeDO_e_OUT2, (boolean)(x))
#define IoHwAb_GetLowBeam2Fail(x) GetDO_AppCtrl(CeDO_e_OUT3, (boolean)(x))
#define IoHwAb_GetTurnLampFail(x) GetDO_AppCtrl(CeDO_e_OUT4, (boolean)(x))

/*----------------------------------------------------------------------------------
- Digital Inputs
-----------------------------------------------------------------------------------*/
boolean IoHwAb_GetSW_ParkLamp(void);
boolean IoHwAb_GetSW_LowBeam(void);
boolean IoHwAb_GetSW_HighBeam(void);
boolean IoHwAb_GetSW_TurnLamp(void);
boolean IoHwAb_GetSW_CornerLamp(void);
boolean IoHwAb_GetSW_DRL(void);
boolean IoHwAb_GetSW_CityMode(void);
boolean IoHwAb_GetSW_HighSpeed(void);
boolean IoHwAb_GetSW_BadWeatherMode(void);
boolean IoHwAb_GetSW_ControlEnable(void);

/*----------------------------------------------------------------------------------
- LED Outputs
-----------------------------------------------------------------------------------*/
void IoHwAb_SetLED1(uint16 percent);
void IoHwAb_SetLED2(uint16 percent);
void IoHwAb_SetHighSpeed(uint16 percent);
void IoHwAb_BadWeather(uint16 percent);
void IoHwAb_SetLED3(uint16 percent);
void IoHwAb_SetTurnLamp(uint16 percent);
void IoHwAb_SetParkLamp(uint16 percent);
void IoHwAb_SetLowBeam1(uint16 percent);
void IoHwAb_SetLowBeam2(uint16 percent);

/*----------------------------------------------------------------------------------
- Can Outputs
-----------------------------------------------------------------------------------*/
boolean IoHwAb_ILCLevelLowBeam(void);
boolean IoHwAb_ILBendingRightControl(void);
boolean IoHwAb_ILBendingLeftControl(void);
boolean IoHwAb_ILTurnRightControl(void);
boolean IoHwAb_ILTurnLeftControl(void);
boolean IoHwAb_ILParkLampControl(void);
boolean IoHwAb_ILLowBeamControl(void);
boolean IoHwAb_ILHighBeamControl(void);
boolean IoHwAb_ILDRLControl(void);
boolean IoHwAb_ILELevelHighSpeedModeControl(void);
boolean IoHwAb_ILVLevelCityModeControl(void);
boolean IoHwAb_ILWLevelBadWeatherControl(void);

#endif
/*EOF*/

