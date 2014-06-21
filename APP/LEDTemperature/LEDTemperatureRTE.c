

#include "Std_Types.h"


UINT16 LEDTemperature_w_ADC1=0;
void SetLEDTemperature_ADCValue1(UINT16 Value)
{
    LEDTemperature_w_ADC1=Value;
}
UINT16 GetLEDTemperature_ADCValue1(void)
{
    return LEDTemperature_w_ADC1;
}


UINT16 LEDTemperature_w_ADC2=0;
void SetLEDTemperature_ADCValue2(UINT16 Value)
{
    LEDTemperature_w_ADC2=Value;
}
UINT16 GetLEDTemperature_ADCValue2(void)
{
    return LEDTemperature_w_ADC2;
}


UINT16 GetLEDTemperature_Value1(void)
{
    //return VeLED_sw_TempFlt1;
}

UINT16 GetLEDTemperature_Value2(void)
{
    //return VeLED_sw_TempFlt2;
}


UINT8 GetLEDTempPWMDutyOut1(void)
{
    //return VeLED_sw_TempPWMDutyOut1;
}

UINT8 GetLEDTempPWMDutyOut2(void)
{
    //return VeLED_sw_TempPWMDutyOut2;
}



