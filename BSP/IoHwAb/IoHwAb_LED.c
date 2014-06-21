
/*******************************************************************************
|    Include Session
|******************************************************************************/
#include "IoHwAb_LEDcfg.h"
#include "IoHwAb_LED.h"


/*******************************************************************************
|    Static Local Variables Declaration
|******************************************************************************/
/* Buffer indicates if diagnostic override control request is active or not*/ 
static boolean SaLED_b_HwLEDDevCtrlActv[CeLED_e_ChNum]; 
static boolean SaLED_b_SwLEDDevCtrlActv[CeLED_e_SwLEDChNum]; 

static TeLED_h_ChPeriodDuty SaLED_h_HwLEDPeriodDuty[CeLED_e_ChNum]; 
static TeLED_h_ChPeriodDuty SaLED_h_SwLEDPeriodDuty[CeLED_e_SwLEDChNum]; 

/*******************************************************************************
|    Extern variables and functions declaration
|******************************************************************************/
static void iLED_RefreshPeriodDuty_TPS(TeLED_ChName Le_e_LEDName);
static void iLED_RefreshPeriodDuty_TLD(TeLED_ChName Le_e_LEDName);

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
void LED_Init(void){
	uint16 Le_w_LEDName;
	TeLED_h_ChPeriodDuty *Lp_h_LEDPeriodDuty;
	uint16 Period; 
	
	//Period = KeBSP_w_CourtesyLampPwmPeriod;
	
	/*-------------------------------------------
	  Configuration Initialization
	---------------------------------------------*/
	/*Init the data buffer of fixed-period PWM, not the physical outputs*/
	/*the physical hardware PWM output is determined by PwmInit() */
	/*the physical simulate PWM output is determined by DioInit()*/
	Lp_h_LEDPeriodDuty = SaLED_h_HwLEDPeriodDuty;
	
	for(Le_w_LEDName=0; Le_w_LEDName<(uint16)CeLED_e_ChNum;Le_w_LEDName++){
		
		Lp_h_LEDPeriodDuty->m_w_Period = CaLED_h_PWMCfg[Le_w_LEDName].m_w_InitPeriod;
		Lp_h_LEDPeriodDuty->m_w_AEPeriod = Lp_h_LEDPeriodDuty->m_w_Period;
		Lp_h_LEDPeriodDuty->m_w_AppPeriod = Lp_h_LEDPeriodDuty->m_w_Period;
		
		Lp_h_LEDPeriodDuty->m_w_Duty = CaLED_h_PWMCfg[Le_w_LEDName].m_w_InitDuty;
		Lp_h_LEDPeriodDuty->m_w_AEDuty = Lp_h_LEDPeriodDuty->m_w_Duty;
		Lp_h_LEDPeriodDuty->m_w_AppDuty = Lp_h_LEDPeriodDuty->m_w_Duty;
		
		Lp_h_LEDPeriodDuty++;
	
	}
	
  /*-------------------------------------------
	  RT Frequence Setting
	---------------------------------------------*/
	Pwm_SetPeriodAndDuty(PwmChannel8,4000,2000);
	Pwm_SetPeriodAndDuty(PwmChannel9,4000,2000);
	Pwm_SetPeriodAndDuty(PwmChannel10,4000,2000);
	Pwm_SetPeriodAndDuty(PwmChannel11,4000,2000);
	
}



void LED_SetHwLED_TPS(TeLED_ChName Channel, uint16 Period, uint16 Duty, TeLED_Mode Mode){
	/* pointer to pwm period&duty configuraion*/
	TeLED_h_ChPeriodDuty *Lp_h_LEDPeriodDuty;
	
	Lp_h_LEDPeriodDuty = &SaLED_h_HwLEDPeriodDuty[Channel];
	
	if(LED_MODE_DEVCTRL == Mode){
		SaLED_b_HwLEDDevCtrlActv[Channel] = TRUE;
		
		/*save history period and duty if previous mode is normal mode(device control inactive mode)*/
		Lp_h_LEDPeriodDuty->m_w_AEPeriod = Period;
		Lp_h_LEDPeriodDuty->m_w_AEDuty   = Duty;
		Lp_h_LEDPeriodDuty->m_w_Period   = Period;
		Lp_h_LEDPeriodDuty->m_w_Duty     = Duty; 
	}else if((LED_MODE_NORMAL == Mode)&&(FALSE==SaLED_b_HwLEDDevCtrlActv[Channel])){
		/*save history period and duty if previous mode is normal mode(device control inactive mode)*/
		Lp_h_LEDPeriodDuty->m_w_AppPeriod = Period;
		Lp_h_LEDPeriodDuty->m_w_AppDuty   = Duty;
		Lp_h_LEDPeriodDuty->m_w_Period    = Period;
		Lp_h_LEDPeriodDuty->m_w_Duty      = Duty; 
	}else{
		Lp_h_LEDPeriodDuty->m_w_AppPeriod = Period;
		Lp_h_LEDPeriodDuty->m_w_AppDuty = Duty;
	}
	
	iLED_RefreshPeriodDuty_TPS(Channel); /* reflect your setting into hardware directly */
	
}
void LED_SetHwLED_TLD(TeLED_ChName Channel, uint16 Period, uint16 Duty, TeLED_Mode Mode){
	
	/* pointer to pwm period&duty configuraion*/
	TeLED_h_ChPeriodDuty *Lp_h_LEDPeriodDuty;
	
	Lp_h_LEDPeriodDuty = &SaLED_h_HwLEDPeriodDuty[Channel];
	
	if(LED_MODE_DEVCTRL == Mode){
		SaLED_b_HwLEDDevCtrlActv[Channel] = TRUE;
		
		/*save history period and duty if previous mode is normal mode(device control inactive mode)*/
		Lp_h_LEDPeriodDuty->m_w_AEPeriod = Period;
		Lp_h_LEDPeriodDuty->m_w_AEDuty   = Duty;
		Lp_h_LEDPeriodDuty->m_w_Period   = Period;
		Lp_h_LEDPeriodDuty->m_w_Duty     = Duty; 
	}else if((LED_MODE_NORMAL == Mode)&&(FALSE==SaLED_b_HwLEDDevCtrlActv[Channel])){
		/*save history period and duty if previous mode is normal mode(device control inactive mode)*/
		Lp_h_LEDPeriodDuty->m_w_AppPeriod = Period;
		Lp_h_LEDPeriodDuty->m_w_AppDuty   = Duty;
		Lp_h_LEDPeriodDuty->m_w_Period    = Period;
		Lp_h_LEDPeriodDuty->m_w_Duty      = Duty; 
	}else{
		Lp_h_LEDPeriodDuty->m_w_AppPeriod = Period;
		Lp_h_LEDPeriodDuty->m_w_AppDuty = Duty;
	}
	
	iLED_RefreshPeriodDuty_TLD(Channel); /* reflect your setting into hardware directly */
	
}

void iLED_RefreshPeriodDuty_TPS(Channel){
	
	const TePWM_h_Config *Lp_h_PwmConfig;
	TeLED_h_ChPeriodDuty *Lp_h_LEDPeriodDuty;
	
	Lp_h_PwmConfig = &CaLED_h_PWMCfg[Channel]; /* find your led's pwm channel for dimming */
	Lp_h_LEDPeriodDuty = &SaLED_h_HwLEDPeriodDuty[Channel]; /* The period and duty you want to set */
	
	/* Resetting LED's PWM and Period to Dimming */
	if(CeIoHwAb_e_PwmTypeHw == Lp_h_PwmConfig->m_e_PwmType){
		/*update PWM output immediately*/
		Pwm_SetPeriodAndDuty(
			Lp_h_PwmConfig->m_w_ChannelId,
			Lp_h_LEDPeriodDuty->m_w_Period,
			Lp_h_LEDPeriodDuty->m_w_Duty);
	}else if(CeIoHwAb_e_PwmTypeSim == Lp_h_PwmConfig->m_e_PwmType){
		/*let simulate PWM handler to update output*/
	}else{
        /*incorrect condition*/
	}	
	
}
void iLED_RefreshPeriodDuty_TLD(Channel){
	const TePWM_h_Config *Lp_h_PwmConfig;
	TeLED_h_ChPeriodDuty *Lp_h_LEDPeriodDuty;
	
	Lp_h_PwmConfig = &CaLED_h_PWMCfg[Channel]; /* find your led's pwm channel for dimming */
	Lp_h_LEDPeriodDuty = &SaLED_h_HwLEDPeriodDuty[Channel]; /* The period and duty you want to set */
	
		/* Resetting LED's PWM and Period to Dimming */
	if(CeIoHwAb_e_PwmTypeHw == Lp_h_PwmConfig->m_e_PwmType){
		/*update PWM output immediately*/
		Pwm_SetPeriodAndDuty(
			Lp_h_PwmConfig->m_w_ChannelId,
			Lp_h_LEDPeriodDuty->m_w_Period,
			Lp_h_LEDPeriodDuty->m_w_Duty);
    }
    else if(CeIoHwAb_e_PwmTypeSim == Lp_h_PwmConfig->m_e_PwmType)
    {
        /*let simulate PWM handler to update output*/
    }
    else
    {
        /*incorrect condition*/
    }	
	
}
/*******************************************************************************
**                      LED1 Open                                             **
*******************************************************************************/
void Set_LED1(void){
	/* enable RT clock output */
  Pwm_SetDutyCycle(PWM_12,0x4000);
	
  /* enable PWMIN1 output */
  Pwm_SetDutyCycle(PWM_10,0x0000);
}

void Clr_LED1(void){
	/* enable PWMIN1 output */
  Pwm_SetDutyCycle(PWM_10,0x0000);
	
	/* enable RT clock output */
  Pwm_SetDutyCycle(PWM_12,0x0000);
}

void Set_LowBeam2(void){
	/* enable RT clock output */
  Pwm_SetDutyCycle(PWM_9,0x4000);
	
  /* enable PWMIN1 output */
  Pwm_SetDutyCycle(PWM_6,0x0000);
}
void Clr_LowBeam2(void){
	/* enable RT clock output */
  Pwm_SetDutyCycle(PWM_9,0x0000);
	
  /* enable PWMIN1 output */
  Pwm_SetDutyCycle(PWM_6,0x0000);
}

void Set_LED3(void){
	
	/* enable SET PIN */
  Pwm_SetDutyCycle(PWM_3,0x4000);
	
	/* enable ENPWMI PIN */
  Pwm_SetDutyCycle(EN3PWM,0x4000);
	
  /* enable EN_PWMI output */
  Pwm_SetDutyCycle(FREQ3,0x4000);
	
}

void Clr_TurnLamp(void){
	
	/* Disable SET PIN */
  Pwm_SetDutyCycle(PWM_1,0x0000);
	
	/* Disable ENPWMI PIN */
  Pwm_SetDutyCycle(EN1PWM,0x0000);
	
  /* Disable EN_PWMI output */
  Pwm_SetDutyCycle(FREQ1,0x0000);

}

void Set_TurnLamp(void){
	
	/* enable SET PIN */
  Pwm_SetDutyCycle(PWM_1,0x0000);
	
	/* enable ENPWMI PIN */
  Pwm_SetDutyCycle(EN1PWM,0x0000);
	
  /* enable EN_PWMI output */
  Pwm_SetDutyCycle(FREQ1,0x4000);
	
}

