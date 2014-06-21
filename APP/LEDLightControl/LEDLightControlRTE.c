
#include "Std_Types.h"
#include "IoHwAb_Api.h"

BOOL GetParkLampSwitch(void)
{
    BOOL L_Result=false;
    L_Result=IoHwAb_ILParkLampControl();    
    return L_Result;
}

BOOL GetLowBeamSwitch(void)
{
    BOOL L_Result=false;
    L_Result=IoHwAb_ILLowBeamControl();    
    return L_Result;
}

BOOL GetHighBeamSwitch(void)
{
    BOOL L_Result=false;
    L_Result=IoHwAb_ILHighBeamControl();    
    return L_Result;
}

BOOL GetDRLSwitch(void)
{
    BOOL L_Result=false;
    L_Result=IoHwAb_ILDRLControl();    
    return L_Result;
}

BOOL GetTurnLampSwitch(void)
{
    BOOL L_Result=false;
    L_Result=IoHwAb_ILTurnLeftControl();    
    return L_Result;
}

BOOL GetCornerLampSwitch(void)
{
    BOOL L_Result=false;
    L_Result=IoHwAb_ILBendingLeftControl();    
    return L_Result;
}

BOOL GetCityModeSwitchSwitch(void)
{
    BOOL L_Result=false;
    L_Result=IoHwAb_ILVLevelCityModeControl();    
    return L_Result;
}

BOOL GetHighSpeedModeSwitchSwitch(void)
{
    BOOL L_Result=false;
    L_Result=IoHwAb_ILELevelHighSpeedModeControl();    
    return L_Result;
}

BOOL GetBadWeatherModeSwitchSwitch(void)
{
    BOOL L_Result=false;
    L_Result=IoHwAb_ILWLevelBadWeatherControl();    
    return L_Result;
}


BOOL VeLED_b_ParkLampOutFlg=0;
void SetParkLampOut(void)
{
    VeLED_b_ParkLampOutFlg=true;
}
BOOL GetParkLampOut(void)
{
    return VeLED_b_ParkLampOutFlg;
}
void ClrParkLampOut(void)
{
    VeLED_b_ParkLampOutFlg=false;
}


BOOL VeLED_b_DRLOutFlg=0;
void SetDRLOut(void)
{
    VeLED_b_DRLOutFlg=true;
}
BOOL GetDRLOut(void)
{
    return VeLED_b_DRLOutFlg;
}
void ClrDRLOut(void)
{
    VeLED_b_DRLOutFlg=false;
}


BOOL VeLED_b_HighBeamOutFlg=0;
void SetHighBeamOut(void)
{
    VeLED_b_HighBeamOutFlg=true;
}
BOOL GetHighBeamOut(void)
{
    return VeLED_b_HighBeamOutFlg;
}
void ClrHighBeamOut(void)
{
    VeLED_b_HighBeamOutFlg=false;
}


BOOL VeLED_b_LowBeamOutFlg=0;
void SetLowBeamOut(void)
{
    VeLED_b_LowBeamOutFlg=true;
}
BOOL GetLowBeamOut(void)
{
    return VeLED_b_LowBeamOutFlg;
}
void ClrLowBeamOut(void)
{
    VeLED_b_LowBeamOutFlg=false;
}


BOOL VeLED_b_TurnLampOutFlg=0;
void SetTurnLampOut(void)
{
    VeLED_b_TurnLampOutFlg=true;
}
BOOL GetTurnLampOut(void)
{
    return VeLED_b_TurnLampOutFlg;
}
void ClrTurnLampOut(void)
{
    VeLED_b_TurnLampOutFlg=false;
}


BOOL VeLED_b_CornerLampOutFlg=0;
void SetCornerLampOut(void)
{
    VeLED_b_CornerLampOutFlg=true;
}
BOOL GetCornerLampOut(void)
{
    return VeLED_b_CornerLampOutFlg;
}
void ClrCornerLampOut(void)
{
    VeLED_b_CornerLampOutFlg=false;
}


BOOL VeLED_b_CityModeLampOutFlg=0;
void SetCityModeOut(void)
{
    VeLED_b_CityModeLampOutFlg=true;
}
BOOL GetCityModeOut(void)
{
    return VeLED_b_CityModeLampOutFlg;
}
void ClrCityModeOut(void)
{
    VeLED_b_CityModeLampOutFlg=false;
}


BOOL VeLED_b_HighSpeedLampOutFlg=0;
void SetHighSpeedModeOut(void)
{
    VeLED_b_HighSpeedLampOutFlg=true;
}
BOOL GetHighSpeedModeOut(void)
{
    return VeLED_b_HighSpeedLampOutFlg;
}
BOOL ClrHighSpeedModeOut(void)
{
    VeLED_b_HighSpeedLampOutFlg=false;
}


BOOL VeLED_b_BadWeatherLampOutFlg=0;
void SetBadWeatherModeOut(void)
{
    VeLED_b_BadWeatherLampOutFlg=true;
}
BOOL GetBadWeatherModeOut(void)
{
    return VeLED_b_BadWeatherLampOutFlg;
}
BOOL ClrBadWeatherModeOut(void)
{
    VeLED_b_BadWeatherLampOutFlg=false;
}

