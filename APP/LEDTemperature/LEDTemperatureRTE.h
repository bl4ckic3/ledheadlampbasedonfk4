
#ifndef _LEDTemperatureRTE_H
#define _LEDTemperatureRTE_H

#include "Std_Types.h"

void SetLEDTemperature_ADCValue1(UINT16 Value);
UINT16 GetLEDTemperature_ADCValue1(void);

void SetLEDTemperature_ADCValue2(UINT16 Value);
UINT16 GetLEDTemperature_ADCValue2(void);

UINT16 GetLEDTemperature_Value1(void);
UINT16 GetLEDTemperature_Value2(void);

UINT8 GetLEDTempPWMDutyOut1(void);
UINT8 GetLEDTempPWMDutyOut2(void);

#endif

