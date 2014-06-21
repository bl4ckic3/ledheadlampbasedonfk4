
#ifndef _LEDLightControlRTE_H
#define _LEDLightControlRTE_H


#include "Std_Types.h"


void GetParkLampSwitch(void);
BOOL GetLowBeamSwitch(void);
BOOL GetHighBeamSwitch(void);
BOOL GetDRLSwitch(void);
BOOL GetTurnLampSwitch(void);
BOOL GetCornerLampSwitch(void);
BOOL GetCornerLampSwitch(void);
BOOL GetCityModeSwitchSwitch(void);
BOOL GetHighSpeedModeSwitchSwitch(void);
BOOL GetBadWeatherModeSwitchSwitch(void);

void SetParkLampOut(void);
BOOL GetParkLampOut(void);
void ClrParkLampOut(void);

void SetDRLOut(void);
BOOL GetDRLOut(void);
void ClrDRLOut(void);

void SetHighBeamOut(void);
BOOL GetHighBeamOut(void);
void ClrHighBeamOut(void);

void SetLowBeamOut(void);
BOOL GetLowBeamOut(void);
void ClrLowBeamOut(void);

void SetTurnLampOut(void);
BOOL GetTurnLampOut(void);
void ClrTurnLampOut(void);

void SetCornerLampOut(void);
BOOL GetCornerLampOut(void);
void ClrCornerLampOut(void);

void SetCityModeOut(void);
BOOL GetCityModeOut(void);
void ClrCityModeOut(void);

void SetHighSpeedModeOut(void);
BOOL GetHighSpeedModeOut(void);
void ClrHighSpeedModeOut(void);

void SetBadWeatherModeOut(void);
BOOL GetBadWeatherModeOut(void);
void ClrBadWeatherModeOut(void);


#endif

