#include "Dio.h"
#include "IoHwAb_LED.h"
#include "IoHwAb_LEDcfg.h"



/*******************************************************************************
|    Configuration
|******************************************************************************/
/*configure hw-PWM or sim-PWM*/ 
const TePWM_h_Config CaLED_h_PWMCfg[CeLED_e_ChNum] =  
{
	/*m_b_Enable, m_e_PwmType    PWM,  m_w_InitPeriod, m_w_InitDuty*/ 
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_10,  4000, 2000},  /* LED1 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_11,  4000, 2000},  /* LED2 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, EN3PWM,  4000, 2000},  /* LED3 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_4,    4000, 2000},  /* HighSpeed */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_5,    4000, 2000},  /* BadWeather */
	{TRUE, CeIoHwAb_e_PwmTypeHw, EN1PWM,  4000, 2000},  /* TurnLamp */
	{TRUE, CeIoHwAb_e_PwmTypeHw, EN2PWM,  4000, 2000},  /* ParknLamp */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_7,    4000, 2000},  /* LowBeam1 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_6,    4000, 2000},  /* LowBeam2 */
}; 

const TePWM_h_Config CaLED_h_RTCfg[CeLED_e_ChNum] =  
{
	/*m_b_Enable, m_e_PwmType    RT,  m_w_InitPeriod, m_w_InitDuty*/ 
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_12,   4000, 2000},  /* LED1 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_12,   4000, 2000},  /* LED2 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, FREQ3,   4000, 2000},  /* LED3 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_8,    4000, 2000},  /* HighSpeed */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_8,    4000, 2000},  /* BadWeather */
	{TRUE, CeIoHwAb_e_PwmTypeHw, FREQ1,   4000, 2000},  /* TurnLamp */
	{TRUE, CeIoHwAb_e_PwmTypeHw, FREQ2,   4000, 2000},  /* ParknLamp */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_9,    4000, 2000},  /* LowBeam1 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_9,    4000, 2000},  /* LowBeam2 */
}; 

const TePWM_h_Config CaLED_h_ADimCfg[CeLED_e_ChNum] =  
{
	/*m_b_Enable, m_e_PwmType    RT,  m_w_InitPeriod, m_w_InitDuty*/ 
	{TRUE, CeIoHwAb_e_PwmTypeHw, 0,    4000, 2000},  /* LED1 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, 0,    4000, 2000},  /* LED2 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_3,    4000, 2000},  /* LED3 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, 0,    4000, 2000},  /* HighSpeed */
	{TRUE, CeIoHwAb_e_PwmTypeHw, 0,    4000, 2000},  /* BadWeather */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_1,    4000, 2000},  /* TurnLamp */
	{TRUE, CeIoHwAb_e_PwmTypeHw, PWM_2,    4000, 2000},  /* ParknLamp */
	{TRUE, CeIoHwAb_e_PwmTypeHw, 0,    4000, 2000},  /* LowBeam1 */
	{TRUE, CeIoHwAb_e_PwmTypeHw, 0,    4000, 2000},  /* LowBeam2 */
}; 

/*Map Dio to simulate PWM*/ 
const TePWM_h_SimChCfg CaPwmA_h_SimChCfg[CeLED_e_SwLEDChNum] = 
{ 
    /*m_b_PreDutyHigh,    m_t_DioChannelId,   m_e_CrossRefPwm*/
	{TRUE,             DioChannel0_0,   CeIoHwAb_e_PwmTypeHw},
}; 
