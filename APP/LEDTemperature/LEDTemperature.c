

#include "Std_Types.h"


UINT16 VeLED_sw_TempFlt1=0;
UINT16 VeLED_sw_TempFlt2=0;

UINT8 VeLED_sw_TempPWMDutyOut1=100U;
UINT8 VeLED_sw_TempPWMDutyOut2=100U;

/****************************************************************************************
| NAME:             ConvertLED_VoltToTempTask                                                                                  
| CALLED BY:        task handler                                                         
| PRECONDITIONS:    task is to be scheduled                                          
| INPUT PARAMETERS: void                                                               
| RETURN VALUE:     void                                                             
| DESCRIPTION:      This function is filter the volt and convert volt to temp                       
|***************************************************************************************/

void ConvertLED_VoltToTempTask(void)
{
        UINT16  LeLED_w_VoltIsigADValue1;
        UINT16  LeLED_w_VoltIsigADValue2;
        
        /* get the original value from ADC processing module */
        LeLED_w_VoltIsigADValue1 = GetLEDTemperature_ADCValue1();
          
        /*through lookup,get the filterd value of temprature*/
        //VeLED_sw_TempFlt1 = GetLIB_sw_DataByDimTwoTab(KaLED_sw_LEDTempVoltLookupTbl, 
        //    KeLED_u_TempLookupArraySize, LeLED_w_VoltIsigADValue1);

        /* get the original value from ADC processing module */
        LeLED_w_VoltIsigADValue2 = GetLEDTemperature_ADCValue2();
          
        /*through lookup,get the filterd value of temprature*/
        VeLED_sw_TempFlt2 = GetLIB_sw_DataByDimTwoTab(KaLED_sw_LEDTempVoltLookupTbl, 
            KeLED_u_TempLookupArraySize, LeLED_w_VoltIsigADValue2);
            
}

void ConvertLED_TempToPWMTask(void)
{
        SINT16  LeLED_sw_TempFlt1;
        SINT16  LeLED_sw_TempFlt2;

        LeLED_sw_TempFlt1=VeLED_sw_TempFlt1;
        LeLED_sw_TempFlt2=VeLED_sw_TempFlt2;      
          
        /*through lookup,get the filterd value of temprature*/
        VeLED_sw_TempPWMDutyOut1 = GetLIB_sw_DataByDimTwoTab(KaLED_sw_LEDTempPWMLookupTbl, 
            KeLED_u_PWMLookupArraySize, LeLED_sw_TempFlt1);
          
        /*through lookup,get the filterd value of temprature*/
        VeLED_sw_TempPWMDutyOut2 = GetLIB_sw_DataByDimTwoTab(KaLED_sw_LEDTempPWMLookupTbl, 
            KeLED_u_PWMLookupArraySize, LeLED_sw_TempFlt2);
            
}

 /*******************************************************************************
| FUNCTION NAME   :      GetLIB_sw_DataByDimTwoTab     
| CALLED BY        :                                                      
| PRECONDITIONS   :                                           
| INPUT PARAMETERS:                                                            
| RETURN VALUE    :
| DESCRIPTION      :                  
|******************************************************************************/
SINT16 GetLIB_sw_DataByDimTwoTab(TwoDimCstArryPtr_S16 const pTab, 
                                                        const UINT8 Length, const SINT16 SerchValue)
{
    UINT8 Idx;
    UINT8 Head = 0;
    UINT8 Rear = Length - 1;
    SINT32 tmp32;
    SINT16 tmp16;


    /*In most case, the engine speed or vehicle speed is 0x0, and it is at head of arrary, return it directly 
    to accelareate the search speed, by Wanrong*/
    if(SerchValue <= pTab[0][0])
    {
        return pTab[0][1];
    }
    /*> upper edge case: use upper*/
    else if(SerchValue >= pTab[Rear][0])
    {
        return pTab[Rear][1];
    }
    /*else continue*/
    else
    {}
    
    while((Rear-Head)>1)
    {
        Idx = (UINT8)((UINT16)(Head + Rear) >> 1);
        tmp16 = pTab[Idx][0];
        if(SerchValue < tmp16)
            Rear = Idx;
        else if(SerchValue > tmp16)
            Head = Idx;
        else
            return pTab[Idx][1];
    }

    /* Linear Scale */
    tmp16 = pTab[Rear][0] - pTab[Head][0];
    if(tmp16> 0) 
    { 
        /* increasement */
        if(pTab[Rear][1] >= pTab[Head][1])
        {
            tmp32 = ((SINT32)SerchValue - (SINT32)pTab[Head ][0]) * ((SINT32)pTab[Rear][1] - (SINT32)pTab[Head][1]);
            tmp32 = tmp32/tmp16;     /* additional diff */
            tmp32 += pTab[Head][1];
        }
        /* decreasement */
        else
        {
            tmp32 = ((SINT32)pTab[Rear][0] - (SINT32)SerchValue) * ((SINT32)pTab[Head][1] - (SINT32)pTab[Rear][1]);
            tmp32 = tmp32/tmp16;     /* additional diff */
            tmp32 += pTab[Rear][1];
        }
    } 
    else 
    {
       tmp32 = pTab[Head][1];
    }
    return (SINT16)tmp32;   
}


