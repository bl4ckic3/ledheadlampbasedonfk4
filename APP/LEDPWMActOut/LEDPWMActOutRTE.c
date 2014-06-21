

#include "Std_Types.h"
#include "IoHwAb_Api.h"

#if 0
void IoHwAb_SetLED1(uint16 percent);
void IoHwAb_SetLED2(uint16 percent);
void IoHwAb_SetHighSpeed(uint16 percent);
void IoHwAb_BadWeather(uint16 percent);
void IoHwAb_SetLED3(uint16 percent);
void IoHwAb_SetTurnLamp(uint16 percent);
void IoHwAb_SetParkLamp(uint16 percent);
void IoHwAb_SetLowBeam1(uint16 percent);
void IoHwAb_SetLowBeam2(uint16 percent);

#endif

void SetParkLampOutPWMDuty(UINT8 value)
{
    UINT16 L_DutyCycle;
    L_DutyCycle=(0x8000-((0x8000U/100U)*((UINT16)value)));
    IoHwAb_SetLowBeam1(L_DutyCycle);
    IoHwAb_SetLowBeam2(L_DutyCycle);
}

void SetHighBeamOutPWMDuty(UINT8 value)
{
    UINT16 L_DutyCycle;
    L_DutyCycle=(0x8000-((0x8000U/100U)*((UINT16)value)));
    IoHwAb_SetParkLamp(L_DutyCycle);
}

void SetLowBeam1OutPWMDuty(UINT8 value)
{
    UINT16 L_DutyCycle;
    L_DutyCycle=(0x8000-((0x8000U/100U)*((UINT16)value)));
    IoHwAb_SetLED2(L_DutyCycle);
}

void SetLowBeam2OutPWMDuty(UINT8 value)
{
    UINT16 L_DutyCycle;
    L_DutyCycle=(0x8000-((0x8000U/100U)*((UINT16)value)));
    IoHwAb_SetTurnLamp(L_DutyCycle);
}

void SetTurnLampOutPWMDuty(UINT8 value)
{
    UINT16 L_DutyCycle;
    L_DutyCycle=(0x8000-((0x8000U/100U)*((UINT16)value)));
    IoHwAb_SetHighSpeed(L_DutyCycle);
}

void SetCornerLampOutPWMDuty(UINT8 value)
{
    if(value>0)
    {
        IoHwAb_SetODH1(true);
    }
    else
    {
        IoHwAb_SetODH1(false);
    }
}

void SetHighSpeedLightOutPWMDuty(UINT8 value)
{
    UINT16 L_DutyCycle;
    L_DutyCycle=(0x8000-((0x8000U/100U)*((UINT16)value)));
    //IoHwAb_SetTurnLamp(L_DutyCycle);
}

void SetBadWeatherLightOutPWMDuty(UINT8 value)
{
    UINT16 L_DutyCycle;
    L_DutyCycle=(0x8000-((0x8000U/100U)*((UINT16)value)));
    IoHwAb_SetLED1(L_DutyCycle);
}



