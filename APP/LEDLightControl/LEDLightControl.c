

#include "Std_Types.h"
#include "IoHwAb_Api.h"

void EH_LightShapeOut(void)
{

    if(true==GetCityModeSwitchSwitch())
    {
        SetCityModeOut();
    }
    else
    {
        ClrCityModeOut();
    }
    
    if(true==GetHighSpeedModeSwitchSwitch())
    {
        SetHighSpeedModeOut();
    }
    else
    {
        ClrHighSpeedModeOut();
    }

    if(true==GetBadWeatherModeSwitchSwitch())
    {
        SetBadWeatherModeOut();
    }
    else
    {
        ClrBadWeatherModeOut();
    }    

#if 0
    if((true==GetLowBeamSwitch())&&(false==GetCityModeSwitchSwitch())&&
    (false==GetHighSpeedModeSwitchSwitch())&&(false==GetBadWeatherModeSwitchSwitch()))
    {
        ClrCityModeOut();
        ClrHighSpeedModeOut();
        ClrBadWeatherModeOut();
    }
    else if((true==GetLowBeamSwitch())&&(true==GetCityModeSwitchSwitch()))
    {
        SetCityModeOut();
        ClrHighSpeedModeOut();
        ClrBadWeatherModeOut();
    }
    else if((true==GetLowBeamSwitch())&&(false==GetCityModeSwitchSwitch())&&
    (true==GetHighSpeedModeSwitchSwitch()))
    {
        ClrCityModeOut();
        SetHighSpeedModeOut();
        ClrBadWeatherModeOut();
    }
    else if((true==GetLowBeamSwitch())&&(false==GetCityModeSwitchSwitch())&&
    (false==GetHighSpeedModeSwitchSwitch())&&(true==GetBadWeatherModeSwitchSwitch()))
    {
        ClrCityModeOut();
        ClrHighSpeedModeOut();
        SetBadWeatherModeOut();
    }
    else if(false==GetLowBeamSwitch())
    {
        ClrCityModeOut();
        ClrHighSpeedModeOut();
        ClrBadWeatherModeOut();
    }
#endif

}


void EH_CornerLampOut()
{
    if(true==GetCornerLampSwitch())
    {
        SetCornerLampOut();
    }
    else
    {
        ClrCornerLampOut();
    }
}

UINT8 VeLED_u_TurnLampCount=0;
const CeLED_u_TurnLampDuty=40;
void EH_TurnLampOut()
{
    if(true==GetTurnLampSwitch())
    {
        VeLED_u_TurnLampCount++;
        if(VeLED_u_TurnLampCount<=CeLED_u_TurnLampDuty)
        {
            SetTurnLampOut();
        }
        else if((VeLED_u_TurnLampCount<=(CeLED_u_TurnLampDuty*2))&&
        (VeLED_u_TurnLampCount>CeLED_u_TurnLampDuty))
        {
            ClrTurnLampOut();
        }
        else if(VeLED_u_TurnLampCount>(CeLED_u_TurnLampDuty*2))
        {
            VeLED_u_TurnLampCount=0;
            ClrTurnLampOut();
        }
    }
    else
    {
        VeLED_u_TurnLampCount=0;
        ClrTurnLampOut();
    }
}

void EH_HighBeamOut()
{
    if(true==GetHighBeamSwitch())
    {
        SetHighBeamOut();
    }
    else
    {
        ClrHighBeamOut();
    }
}

void EH_LowBeamOut(void)
{
    if(true==GetLowBeamSwitch())
    {
        SetLowBeamOut();
    }
    else
    {
        ClrLowBeamOut();
    }
}


void EH_ParkDRLOut(void)
{
    if(true==GetParkLampSwitch())
    {
        SetParkLampOut();
        ClrDRLOut();
    }
    else if((false==GetParkLampSwitch())&&(true==GetDRLSwitch()))
    {
        ClrParkLampOut();
        SetDRLOut();
    }
    else if((false==GetParkLampSwitch())&&(false==GetDRLSwitch()))
    {
        ClrParkLampOut();
        ClrDRLOut();
    }
}

void EH_FANControl(void)
{
    IoHwAb_SetODH2(true);
}

void LEDSwitchMainFunction(void)
{
    EH_ParkDRLOut();
    EH_LowBeamOut();
    EH_HighBeamOut();
    EH_TurnLampOut();
    EH_CornerLampOut();
    EH_LightShapeOut();
    EH_FANControl();
}
