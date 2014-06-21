/*****************************************************************************
|File Name:  IoHwAb_Api.c
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
| Date            Version       Author     Description
|----------  --------  ------  ----------------------------------------------
|2014-04-01 01.00.00     ZhanYi      Create
*****************************************************************************/
#include "IoHwAb_Api.h"
#include "IoHwAb_LED.h"

extern uint8 GaaByteArrayCanRdData[8];
uint16 KeBSP_w_CourtesyLampPwmPeriod;

#define TSTBIT(target,bit) target&(0x01<<bit)
#define BIT0 0x00
#define BIT1 0x01
#define BIT2 0x02
#define BIT3 0x03
#define BIT4 0x04
#define BIT5 0x05
#define BIT6 0x06
#define BIT7 0x07
/*-----------------------------------------------------------------------------
- Can Inputs
-----------------------------------------------------------------------------*/
boolean IoHwAb_ILCLevelLowBeam(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[0],BIT0)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}

boolean IoHwAb_ILBendingRightControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[0],BIT1)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}


boolean IoHwAb_ILBendingLeftControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[0],BIT2)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}

boolean IoHwAb_ILTurnRightControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[0],BIT3)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}

boolean IoHwAb_ILTurnLeftControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[0],BIT4)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}

boolean IoHwAb_ILParkLampControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[0],BIT5)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}

boolean IoHwAb_ILLowBeamControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[0],BIT6)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}

boolean IoHwAb_ILHighBeamControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[0],BIT7)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}

boolean IoHwAb_ILDRLControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[1],BIT7)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}

boolean IoHwAb_ILELevelHighSpeedModeControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[1],BIT6)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}

boolean IoHwAb_ILVLevelCityModeControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[1],BIT5)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}

boolean IoHwAb_ILWLevelBadWeatherControl(void){
	
	boolean swStatus;

	if(TSTBIT(GaaByteArrayCanRdData[1],BIT4)){
		swStatus = TRUE;
	}else{
		swStatus = FALSE;
	}
	
	return swStatus;
}


/*-----------------------------------------------------------------------------
- Digital Inputs
-----------------------------------------------------------------------------*/
boolean IoHwAb_GetSW_ParkLamp(void){
	
	boolean swStatus;
	
	swStatus = Dio_ReadChannel(DioChannel25_13);
	
	return swStatus;
}

boolean IoHwAb_GetSW_LowBeam(void){
	
	boolean swStatus;
	
	swStatus = Dio_ReadChannel(DioChannel25_12);
	
	return swStatus;
}

boolean IoHwAb_GetSW_HighBeam(void){
	
	boolean swStatus;

	swStatus = Dio_ReadChannel(DioChannel25_11);
	
	return swStatus;
}

boolean IoHwAb_GetSW_TurnLamp(void){
	
	boolean swStatus;

	swStatus = Dio_ReadChannel(DioChannel25_10);
	
	return swStatus;
}

boolean IoHwAb_GetSW_CornerLamp(void){
	
	boolean swStatus;
	
	swStatus = Dio_ReadChannel(DioChannel25_9);
	
	return swStatus;
	
}
boolean IoHwAb_GetSW_DRL(void){
	
	boolean swStatus;
	
	swStatus = Dio_ReadChannel(DioChannel25_8);
	
	return swStatus;
}


boolean IoHwAb_GetSW_CityMode(void){
	
	boolean swStatus;
	
	swStatus = Dio_ReadChannel(DioChannel25_7);
	
	return swStatus;
}

boolean IoHwAb_GetSW_HighSpeed(void){
	
	boolean swStatus;
	
	swStatus = Dio_ReadChannel(DioChannel25_6);
	
	return swStatus;
}


boolean IoHwAb_GetSW_BadWeatherMode(void){
	
	boolean swStatus;
	
	swStatus = Dio_ReadChannel(DioChannel25_5);
	
	return swStatus;
}

boolean IoHwAb_GetSW_ControlEnable(void){
	
	boolean swStatus;
	
	swStatus = Dio_ReadChannel(DioChannel0_0);
	
	return swStatus;
}

uint32 IoHwAb_GetVolPTC1(void){
}

uint32 IoHwAb_GetVolPTC2(void){
}

/*-----------------------------------------------------------------------------
- LED Outputs
-----------------------------------------------------------------------------*/
void IoHwAb_SetLED1(uint16 percent){
	uint16 Period; 
	LED_SetHwLED_TPS(CeIoHwAb_e_LED_1,Period, percent, LED_MODE_NORMAL);
}

void IoHwAb_SetLED2(uint16 percent){
	uint16 Period; 
	LED_SetHwLED_TPS(CeIoHwAb_e_LED_2,Period, percent, LED_MODE_NORMAL);
}

void IoHwAb_SetLowBeam1(uint16 percent){
  uint16 Period;
	LED_SetHwLED_TLD(CeIoHwAb_e_LowBeam_1,Period, percent, LED_MODE_NORMAL);
}

void IoHwAb_SetLowBeam2(uint16 percent){
	uint16 Period; 
	LED_SetHwLED_TPS(CeIoHwAb_e_LowBeam_2,Period, percent, LED_MODE_NORMAL);
	
}

void IoHwAb_SetHighSpeed(uint16 percent){
	uint16 Period; 
	LED_SetHwLED_TPS(CeIoHwAb_e_HighSpeed,Period, percent, LED_MODE_NORMAL);
	
}

void IoHwAb_SetBadWeather(uint16 percent){
	uint16 Period; 
	LED_SetHwLED_TPS(CeIoHwAb_e_BadWeather,Period, percent, LED_MODE_NORMAL);
	
}

void IoHwAb_SetLED3(uint16 percent){
	uint16 Period;
	LED_SetHwLED_TLD(CeIoHwAb_e_LED_3,Period, percent, LED_MODE_NORMAL);
	
}

void IoHwAb_SetTurnLamp(uint16 percent){
  uint16 Period;
	LED_SetHwLED_TLD(CeIoHwAb_e_TurnLamp,Period, percent, LED_MODE_NORMAL);
}

void IoHwAb_SetParkLamp(uint16 percent){
  uint16 Period;
	LED_SetHwLED_TLD(CeIoHwAb_e_ParkLamp,Period, percent, LED_MODE_NORMAL);
}



/*EOF*/

