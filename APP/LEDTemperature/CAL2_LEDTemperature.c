#include "std_types.h"

#define CAL_ConvertVolToADVal(vol) (UINT16)(((float)(vol)*4095)/5.0f) 
#define CAL_SCALEUP_2TIMES_SINT16(x) (SINT16)((x)*32)


const  SINT16 KaLED_sw_LEDTempVoltLookupTbl[][2]=
{
    /*the application adopt following first data pair as default value,
    because 20 degree is normal temperature. Please don't change temperature here*/
    {CAL_ConvertVolToADVal(1.27f),125}, /*temperature 120*/
    {CAL_ConvertVolToADVal(1.53f),115}, /*temperature 115*/
    {CAL_ConvertVolToADVal(1.84f),105}, /*temperature 105*/
    {CAL_ConvertVolToADVal(2.19f),95}, /*temperature 95*/
    {CAL_ConvertVolToADVal(2.57f),85}, /*temperature 85*/
    {CAL_ConvertVolToADVal(2.98f),75}, /*temperature 75*/
    {CAL_ConvertVolToADVal(3.37f),65}, /*temperature 65*/
    {CAL_ConvertVolToADVal(3.74f),55}, /*temperature 55*/
    {CAL_ConvertVolToADVal(4.07f),45}, /*temperature 45*/
    {CAL_ConvertVolToADVal(4.34f),35}, /*temperature 35*/
    {CAL_ConvertVolToADVal(4.55f),25}, /*temperature 25*/
    {CAL_ConvertVolToADVal(4.70f),15}, /*temperature 15*/
    {CAL_ConvertVolToADVal(4.81f),5}, /*temperature 5*/
    {CAL_ConvertVolToADVal(4.89f),-5}, /*temperature -5*/
    {CAL_ConvertVolToADVal(4.93f),-15}, /*temperature -15*/
    {CAL_ConvertVolToADVal(4.96f),-25}, /*temperature -25*/
    {CAL_ConvertVolToADVal(4.98f),-35}, /*temperature -35*/
    {CAL_ConvertVolToADVal(4.99f),-45}, /*temperature -45*/
};

/* temperature look up array size */
const UINT8 KeLED_u_TempLookupArraySize =  
    sizeof(KaLED_sw_LEDTempVoltLookupTbl)/(sizeof(SINT16) * 2);

const  SINT16 KaLED_sw_LEDTempPWMLookupTbl[][2]=
{
    /*the application adopt following first data pair as default value,
    because 20 degree is normal temperature. Please don't change temperature here*/
    {50,125}, /*temperature 120*/
    {60,115}, /*temperature 115*/
    {70,105}, /*temperature 105*/
    {80,95}, /*temperature 95*/
    {90,85}, /*temperature 85*/
    {100,75}, /*temperature 75*/
    {100,65}, /*temperature 65*/
    {100,55}, /*temperature 55*/
    {100,45}, /*temperature 45*/
    {100,35}, /*temperature 35*/
    {100,25}, /*temperature 25*/
    {100,15}, /*temperature 15*/
    {100,5}, /*temperature 5*/
};

/* PWM look up array size */
const UINT8 KeLED_u_PWMLookupArraySize =  
    sizeof(KaLED_sw_LEDTempPWMLookupTbl)/(sizeof(SINT16) * 2);

