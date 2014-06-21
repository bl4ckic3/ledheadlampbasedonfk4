

#include "Std_Types.h"

const UINT8 KeLED_u_ParkLampDuty=20U;
const UINT8 KeLED_u_DRLDuty=40U;
const UINT8 KeLED_u_HighBeamDuty=40U;
const UINT8 KeLED_u_LowBeamDuty=40U;
const UINT8 KeLED_u_TurnLampDuty=40U;
const UINT8 KeLED_u_CornerLampDuty=40U;
const UINT8 KeLED_u_CityModeLampDuty=40U;
const UINT8 KeLED_u_HighSpeedLampDuty=40U;
const UINT8 KeLED_u_BadWeatherLampDuty=40U;

UINT8 KeLED_u_LightingShowMode=0;

UINT16 VeLED_w_LightingShowCount=0;
UINT8 VeLED_w_PWMDutyCount=0;
UINT8 VeLED_u_TurnLampCount2=0;

extern uint8 GaaByteArrayCanRdData[8];

void LEDPWMOutMainFunction(void)
{
     SetBadWeatherLightOutPWMDuty(40);
     SetParkLampOutPWMDuty(40);
     SetLowBeam1OutPWMDuty(40);
     SetLowBeam2OutPWMDuty(40);
     SetHighBeamOutPWMDuty(40);
     SetTurnLampOutPWMDuty(40);
#if 0
    KeLED_u_LightingShowMode=GetHighSpeedModeSwitchSwitch();
    /*the Code is for Manual Mode*/
    if((0==GaaByteArrayCanRdData[7])&&(1==KeLED_u_LightingShowMode))
    {
        VeLED_w_LightingShowCount=0;
        VeLED_w_PWMDutyCount=0;
        if(true==GetParkLampOut())
        {
            SetParkLampOutPWMDuty(KeLED_u_ParkLampDuty);
        }
        else if(true==GetDRLOut())
        {
            SetParkLampOutPWMDuty(KeLED_u_DRLDuty);
        }
        else
        {
            SetParkLampOutPWMDuty(0);
        }

        if(true==GetLowBeamOut())
        {
            SetLowBeam2OutPWMDuty(KeLED_u_CityModeLampDuty);
        }
        else
        {
            SetLowBeam2OutPWMDuty(0);
        }

        if(true==GetCityModeOut())
        {
            SetLowBeam1OutPWMDuty(KeLED_u_CityModeLampDuty);
        }
        else
        {
            SetLowBeam1OutPWMDuty(0);
        }

        if(true==GetHighBeamOut())
        {
            SetHighBeamOutPWMDuty(KeLED_u_HighBeamDuty);
        }
        else
        {
            SetHighBeamOutPWMDuty(0);
        }

        if(true==GetTurnLampOut())
        {
            SetTurnLampOutPWMDuty(KeLED_u_TurnLampDuty);
        }
        else
        {
            SetTurnLampOutPWMDuty(0);
        }

        if(true==GetCornerLampOut())
        {
            SetCornerLampOutPWMDuty(KeLED_u_CornerLampDuty);
        }
        else
        {
            SetCornerLampOutPWMDuty(0);
        }

        if(true==GetHighSpeedModeOut())
        {
            SetHighSpeedLightOutPWMDuty(KeLED_u_HighSpeedLampDuty);
        }
        else
        {
            SetHighSpeedLightOutPWMDuty(0);
        }

        if(true==GetBadWeatherModeOut())
        {
            SetBadWeatherLightOutPWMDuty(KeLED_u_BadWeatherLampDuty);
        }
        else
        {
            SetBadWeatherLightOutPWMDuty(0);
        }    
    }
    /*the code below is for the AutoMode*/
    else
    {
        VeLED_w_LightingShowCount++;
        
        if(VeLED_w_LightingShowCount>=3100)
        {
            VeLED_w_LightingShowCount=0;
        }

        /*This is for all LED dimming Open*/
        if(VeLED_w_LightingShowCount<40)
        {
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
            SetBadWeatherLightOutPWMDuty(VeLED_w_PWMDutyCount);
            SetTurnLampOutPWMDuty(VeLED_w_PWMDutyCount);
            SetParkLampOutPWMDuty(VeLED_w_PWMDutyCount);
            SetLowBeam1OutPWMDuty(VeLED_w_PWMDutyCount);
            SetLowBeam2OutPWMDuty(VeLED_w_PWMDutyCount);
            SetHighBeamOutPWMDuty(VeLED_w_PWMDutyCount);
        }
        else if((VeLED_w_LightingShowCount>=140)&&(VeLED_w_LightingShowCount<180))
        {
            if(VeLED_w_PWMDutyCount>0)
            {
                VeLED_w_PWMDutyCount--;
            }
            SetBadWeatherLightOutPWMDuty(VeLED_w_PWMDutyCount);
            SetTurnLampOutPWMDuty(VeLED_w_PWMDutyCount);
            SetParkLampOutPWMDuty(VeLED_w_PWMDutyCount);
            SetLowBeam1OutPWMDuty(VeLED_w_PWMDutyCount);
            SetLowBeam2OutPWMDuty(VeLED_w_PWMDutyCount);
            SetHighBeamOutPWMDuty(VeLED_w_PWMDutyCount);
        }
	else if((VeLED_w_LightingShowCount>=230)&&(VeLED_w_LightingShowCount<270))
	{	
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
		SetTurnLampOutPWMDuty(VeLED_w_PWMDutyCount);
	}	
	else if((VeLED_w_LightingShowCount>=320)&&(VeLED_w_LightingShowCount<360))
	{	
            if(VeLED_w_PWMDutyCount>0)
            {
                VeLED_w_PWMDutyCount--;
            }
		SetTurnLampOutPWMDuty(VeLED_w_PWMDutyCount);
	}
	else if((VeLED_w_LightingShowCount>=410)&&(VeLED_w_LightingShowCount<450))
	{	
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
		SetParkLampOutPWMDuty(VeLED_w_PWMDutyCount);
	}	
	else if((VeLED_w_LightingShowCount>=500)&&(VeLED_w_LightingShowCount<540))
	{	
            if(VeLED_w_PWMDutyCount>0)
            {
                VeLED_w_PWMDutyCount--;
            }
		SetParkLampOutPWMDuty(VeLED_w_PWMDutyCount);
	}	
	else if((VeLED_w_LightingShowCount>=590)&&(VeLED_w_LightingShowCount<630))
	{	
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
		SetLowBeam1OutPWMDuty(VeLED_w_PWMDutyCount);
		SetLowBeam2OutPWMDuty(VeLED_w_PWMDutyCount);		
	}	
	else if((VeLED_w_LightingShowCount>=680)&&(VeLED_w_LightingShowCount<720))
	{	
            if(VeLED_w_PWMDutyCount>0)
            {
                VeLED_w_PWMDutyCount--;
            }
		SetLowBeam1OutPWMDuty(VeLED_w_PWMDutyCount);
		SetLowBeam2OutPWMDuty(VeLED_w_PWMDutyCount);	
	}	
	else if((VeLED_w_LightingShowCount>=770)&&(VeLED_w_LightingShowCount<810))
	{	
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
            SetHighBeamOutPWMDuty(VeLED_w_PWMDutyCount);
	}	
	else if((VeLED_w_LightingShowCount>=860)&&(VeLED_w_LightingShowCount<900))
	{	
            if(VeLED_w_PWMDutyCount>0)
            {
                VeLED_w_PWMDutyCount--;
            }
            SetHighBeamOutPWMDuty(VeLED_w_PWMDutyCount);
	}
        else if((VeLED_w_LightingShowCount>=950)&&(VeLED_w_LightingShowCount<1250))
        {
            if(950==VeLED_w_LightingShowCount)
            {
                VeLED_u_TurnLampCount2=0;
            }
            
            VeLED_u_TurnLampCount2++;
            if(VeLED_u_TurnLampCount2<=30)
            {
                SetTurnLampOutPWMDuty(40);
            }
            else if((VeLED_u_TurnLampCount2<=60)&&
            (VeLED_u_TurnLampCount2>30))
            {
                SetTurnLampOutPWMDuty(0);
            }
            else if((VeLED_u_TurnLampCount2<=90)&&
            (VeLED_u_TurnLampCount2>60))
            {
                SetTurnLampOutPWMDuty(40);
            }	
            else if((VeLED_u_TurnLampCount2<=120)&&
            (VeLED_u_TurnLampCount2>90))
            {
                SetTurnLampOutPWMDuty(0);
            }	
            else if((VeLED_u_TurnLampCount2<=150)&&
            (VeLED_u_TurnLampCount2>120))
            {
                SetTurnLampOutPWMDuty(40);
            }	
            else if((VeLED_u_TurnLampCount2<=180)&&
            (VeLED_u_TurnLampCount2>150))
            {
                SetTurnLampOutPWMDuty(0);
            }
            else if((VeLED_u_TurnLampCount2<=210)&&
            (VeLED_u_TurnLampCount2>180))
            {
                SetTurnLampOutPWMDuty(40);
            }	
            else if((VeLED_u_TurnLampCount2<=240)&&
            (VeLED_u_TurnLampCount2>210))
            {
                SetTurnLampOutPWMDuty(0);
            }	
            else if((VeLED_u_TurnLampCount2<=270)&&
            (VeLED_u_TurnLampCount2>240))
            {
                SetTurnLampOutPWMDuty(40);
            }	
            else if((VeLED_u_TurnLampCount2<=300)&&
            (VeLED_u_TurnLampCount2>270))
            {
                SetTurnLampOutPWMDuty(0);
            }						
            else if(VeLED_u_TurnLampCount2>300)
            {
                VeLED_u_TurnLampCount2=0;
                SetTurnLampOutPWMDuty(0);
            }
        }
	else if((VeLED_w_LightingShowCount>=1250)&&(VeLED_w_LightingShowCount<1290))
	{
            if(1250==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=0;
            }	
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
		SetParkLampOutPWMDuty(VeLED_w_PWMDutyCount);
	}	
	else if((VeLED_w_LightingShowCount>=1340)&&(VeLED_w_LightingShowCount<1380))
	{
            if(1340==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=0;
            }	
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
		SetLowBeam1OutPWMDuty(VeLED_w_PWMDutyCount);
	}		
	else if((VeLED_w_LightingShowCount>=1430)&&(VeLED_w_LightingShowCount<1470))
	{
            if(1430==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=0;
            }	
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
		SetLowBeam2OutPWMDuty(VeLED_w_PWMDutyCount);
	}
	else if((VeLED_w_LightingShowCount>=1520)&&(VeLED_w_LightingShowCount<1560))
	{
            if(1520==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=0;
            }	
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
		SetHighBeamOutPWMDuty(VeLED_w_PWMDutyCount);
	}		
	else if((VeLED_w_LightingShowCount>=1610)&&(VeLED_w_LightingShowCount<1650))
	{
            if(1610==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=40;
            }	
            if(VeLED_w_PWMDutyCount>0)
            {
                VeLED_w_PWMDutyCount--;
            }
		SetParkLampOutPWMDuty(VeLED_w_PWMDutyCount);
		SetLowBeam1OutPWMDuty(VeLED_w_PWMDutyCount);			
		SetLowBeam2OutPWMDuty(VeLED_w_PWMDutyCount);			
		SetHighBeamOutPWMDuty(VeLED_w_PWMDutyCount);
	}	
	else if((VeLED_w_LightingShowCount>=1700)&&(VeLED_w_LightingShowCount<1740))
	{
            if(1700==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=0;
            }	
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
		SetParkLampOutPWMDuty(VeLED_w_PWMDutyCount);
	}
	else if((VeLED_w_LightingShowCount>=1790)&&(VeLED_w_LightingShowCount<1830))
	{
            if(1790==VeLED_w_LightingShowCount)	
            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
		SetLowBeam1OutPWMDuty(VeLED_w_PWMDutyCount);
		SetLowBeam2OutPWMDuty(VeLED_w_PWMDutyCount);		
	}
        else if((VeLED_w_LightingShowCount>=1880)&&(VeLED_w_LightingShowCount<2280))
        {
            if(1880==VeLED_w_LightingShowCount)
            {
                VeLED_u_TurnLampCount2=0;
            }
            
            VeLED_u_TurnLampCount2++;
            if(VeLED_u_TurnLampCount2<=40)
            {
               SetHighBeamOutPWMDuty(40);
            }
            else if((VeLED_u_TurnLampCount2<=80)&&
            (VeLED_u_TurnLampCount2>40))
            {
                SetHighBeamOutPWMDuty(0);
            }
            else if((VeLED_u_TurnLampCount2<=120)&&
            (VeLED_u_TurnLampCount2>80))
            {
                SetHighBeamOutPWMDuty(40);
            }	
            else if((VeLED_u_TurnLampCount2<=160)&&
            (VeLED_u_TurnLampCount2>120))
            {
               SetHighBeamOutPWMDuty(0);
            }	
            else if((VeLED_u_TurnLampCount2<=200)&&
            (VeLED_u_TurnLampCount2>160))
            {
                SetHighBeamOutPWMDuty(40);
            }	
            else if((VeLED_u_TurnLampCount2<=240)&&
            (VeLED_u_TurnLampCount2>200))
            {
                SetHighBeamOutPWMDuty(0);
            }
            else if((VeLED_u_TurnLampCount2<=280)&&
            (VeLED_u_TurnLampCount2>240))
            {
               SetHighBeamOutPWMDuty(40);
            }	
            else if((VeLED_u_TurnLampCount2<=320)&&
            (VeLED_u_TurnLampCount2>280))
            {
                SetHighBeamOutPWMDuty(0);
            }	
            else if((VeLED_u_TurnLampCount2<=360)&&
            (VeLED_u_TurnLampCount2>320))
            {
                SetHighBeamOutPWMDuty(40);
            }	
            else if((VeLED_u_TurnLampCount2<=400)&&
            (VeLED_u_TurnLampCount2>360))
            {
                SetHighBeamOutPWMDuty(0);
            }						
            else if(VeLED_u_TurnLampCount2>400)
            {
                VeLED_u_TurnLampCount2=0;
               SetHighBeamOutPWMDuty(0);
            }
        }	
	else if((VeLED_w_LightingShowCount>=2280)&&(VeLED_w_LightingShowCount<2320))
	{
            if(2280==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=40;
            }	
            if(VeLED_w_PWMDutyCount>0)
            {
                VeLED_w_PWMDutyCount--;
            }
		SetParkLampOutPWMDuty(VeLED_w_PWMDutyCount);
		SetLowBeam1OutPWMDuty(VeLED_w_PWMDutyCount);			
		SetLowBeam2OutPWMDuty(VeLED_w_PWMDutyCount);			
		SetHighBeamOutPWMDuty(VeLED_w_PWMDutyCount);
	}			
#if 0		
        else if((VeLED_w_LightingShowCount>=500)&&(VeLED_w_LightingShowCount<1000))
        {
            if(500==VeLED_w_LightingShowCount)
            {
                VeLED_u_TurnLampCount2=0;
            }
            
            VeLED_u_TurnLampCount2++;
            if(VeLED_u_TurnLampCount2<=50)
            {
                SetTurnLampOutPWMDuty(40);
            }
            else if((VeLED_u_TurnLampCount2<=100)&&
            (VeLED_u_TurnLampCount2>50))
            {
                SetTurnLampOutPWMDuty(0);
            }
            else if(VeLED_u_TurnLampCount2>100)
            {
                VeLED_u_TurnLampCount2=0;
                SetTurnLampOutPWMDuty(0);
            }
            
            SetBadWeatherLightOutPWMDuty(40);
 
            SetParkLampOutPWMDuty(0);
            SetLowBeam1OutPWMDuty(0);
            SetLowBeam2OutPWMDuty(0);
            SetHighBeamOutPWMDuty(0);
        }
        else if((VeLED_w_LightingShowCount>=1000)&&(VeLED_w_LightingShowCount<1500))
        {
            if(1000==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=0;
                VeLED_u_TurnLampCount2=0;
            }
            
            VeLED_u_TurnLampCount2++;
            if(VeLED_u_TurnLampCount2<=50)
            {
                SetTurnLampOutPWMDuty(40);
            }
            else if((VeLED_u_TurnLampCount2<=100)&&
            (VeLED_u_TurnLampCount2>50))
            {
                SetTurnLampOutPWMDuty(0);
            }
            else if(VeLED_u_TurnLampCount2>100)
            {
                VeLED_u_TurnLampCount2=0;
                SetTurnLampOutPWMDuty(0);
            }

            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
            SetBadWeatherLightOutPWMDuty(40);

            SetParkLampOutPWMDuty(VeLED_w_PWMDutyCount);
            SetLowBeam1OutPWMDuty(0);
            SetLowBeam2OutPWMDuty(0);
            SetHighBeamOutPWMDuty(0);
        }
        else if((VeLED_w_LightingShowCount>=1500)&&(VeLED_w_LightingShowCount<2000))
        {
            if(1500==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=0;
                VeLED_u_TurnLampCount2=0;
            }
            
            /*Begin of turnlamp Control*/
            VeLED_u_TurnLampCount2++;
            if(VeLED_u_TurnLampCount2<=50)
            {
                SetTurnLampOutPWMDuty(40);
            }
            else if((VeLED_u_TurnLampCount2<=100)&&
            (VeLED_u_TurnLampCount2>50))
            {
                SetTurnLampOutPWMDuty(0);
            }
            else if(VeLED_u_TurnLampCount2>100)
            {
                VeLED_u_TurnLampCount2=0;
                SetTurnLampOutPWMDuty(0);
            }
            /*End of turnlamp Control*/

            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
            SetBadWeatherLightOutPWMDuty(40);
            SetParkLampOutPWMDuty(40);
            SetLowBeam1OutPWMDuty(VeLED_w_PWMDutyCount);
            SetLowBeam2OutPWMDuty(0);
            SetHighBeamOutPWMDuty(0);
        }
        else if((VeLED_w_LightingShowCount>=2000)&&(VeLED_w_LightingShowCount<2500))
        {
            if(2000==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=0;
                VeLED_u_TurnLampCount2=0;
            }

            /*Begin of turnlamp Control*/
            VeLED_u_TurnLampCount2++;
            if(VeLED_u_TurnLampCount2<=50)
            {
                SetTurnLampOutPWMDuty(40);
            }
            else if((VeLED_u_TurnLampCount2<=100)&&
            (VeLED_u_TurnLampCount2>50))
            {
                SetTurnLampOutPWMDuty(0);
            }
            else if(VeLED_u_TurnLampCount2>100)
            {
                VeLED_u_TurnLampCount2=0;
                SetTurnLampOutPWMDuty(0);
            }
            /*End of turnlamp Control*/

            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
            SetBadWeatherLightOutPWMDuty(40);
            SetParkLampOutPWMDuty(40);
            SetLowBeam1OutPWMDuty(40);
            SetLowBeam2OutPWMDuty(VeLED_w_PWMDutyCount);
            SetHighBeamOutPWMDuty(0);
        }
        else if((VeLED_w_LightingShowCount>=2500)&&(VeLED_w_LightingShowCount<3000))
        {
            if(2500==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=0;
                VeLED_u_TurnLampCount2=0;
            }

            /*Begin of turnlamp Control*/
            VeLED_u_TurnLampCount2++;
            if(VeLED_u_TurnLampCount2<=50)
            {
                SetTurnLampOutPWMDuty(40);
            }
            else if((VeLED_u_TurnLampCount2<=100)&&
            (VeLED_u_TurnLampCount2>50))
            {
                SetTurnLampOutPWMDuty(0);
            }
            else if(VeLED_u_TurnLampCount2>100)
            {
                VeLED_u_TurnLampCount2=0;
                SetTurnLampOutPWMDuty(0);
            }
            /*End of turnlamp Control*/

            if(VeLED_w_PWMDutyCount<40)
            {
                VeLED_w_PWMDutyCount++;
            }
            SetBadWeatherLightOutPWMDuty(40);
            SetParkLampOutPWMDuty(40);
            SetLowBeam1OutPWMDuty(40);
            SetLowBeam2OutPWMDuty(40);
            SetHighBeamOutPWMDuty(VeLED_w_PWMDutyCount);
        }
        else if((VeLED_w_LightingShowCount>=3000)&&(VeLED_w_LightingShowCount<3100))
        {
            if(3000==VeLED_w_LightingShowCount)
            {
                VeLED_w_PWMDutyCount=40;
            }

            if(VeLED_w_PWMDutyCount>0)
            {
                VeLED_w_PWMDutyCount--;
            }
            SetBadWeatherLightOutPWMDuty(VeLED_w_PWMDutyCount);
            SetTurnLampOutPWMDuty(0);
            SetParkLampOutPWMDuty(VeLED_w_PWMDutyCount);
            SetLowBeam1OutPWMDuty(VeLED_w_PWMDutyCount);
            SetLowBeam2OutPWMDuty(VeLED_w_PWMDutyCount);
            SetHighBeamOutPWMDuty(VeLED_w_PWMDutyCount);
        }
#endif		
    }
#endif
}


