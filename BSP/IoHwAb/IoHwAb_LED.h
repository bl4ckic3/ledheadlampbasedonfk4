/*============================================================================*/
/* Project      = Led know how                                               */
/* Module       = CommEn.c                                                    */
/* Version      = 0.0.0a                                                      */
/* Date         = 18-Dec-2013                                                 */
/*============================================================================*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V0.0.0:  14-Jan-2014 : Initial Version. By ZhanYi@Renesas
*******************************************************************************/
#ifndef IOHWAB_LED_H
#define IOHWAB_LED_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Pwm.h"
#include "Dio.h"
#include "IoHwAb_LEDcfg.h"


/*******************************************************************************
|    Macro Definition
|******************************************************************************/
#define EN3PWM PwmChannel1
#define EN2PWM PwmChannel2
#define EN1PWM PwmChannel3
#define PWM_1   PwmChannel5
#define PWM_2   PwmChannel6
#define PWM_3   PwmChannel7
#define PWM_9   PwmChannel9
#define PWM_8   PwmChannel11
#define PWM_12  PwmChannel13
#define FREQ1   PwmChannel16
#define FREQ2   PwmChannel15
#define FREQ3   PwmChannel17
#define FREQ1   PwmChannel19
#define PWM_4   PwmChannel21
#define PWM_5   PwmChannel23
#define PWM_11  PwmChannel25
#define PWM_10  PwmChannel27
//#define PWM_12  PwmChannel29
#define PWM_7   PwmChannel31
#define PWM_6   PwmChannel33

/*PWM mode control - normal control or device control*/
#define TeLED_Mode    uint8     
#define LED_MODE_NORMAL     0
#define LED_MODE_DEVCTRL    1   /*Diagnostic mode -device control*/



typedef enum
{
    CeIoHwAb_e_PwmTypeHw,
    CeIoHwAb_e_PwmTypeSim
} TeIoHwAb_PwmType;

typedef struct
{
    boolean m_b_Enable;
    TeIoHwAb_PwmType m_e_PwmType;  /* determine hw type or simulate type*/
    uint16 m_w_ChannelId;       /* if hardwire PWM, this is pwm channel id; if simulate PWM, this is simulate PWM channel Id*/
    uint16 m_w_InitPeriod;      /* Initial PWM peirod*/
    uint16 m_w_InitDuty;        /* Initial PWM Duty*/
} TePWM_h_Config;


/*Simulate PWM channel configurations*/
typedef struct
{
    boolean m_b_PreDutyHigh;  /*set the MCU output high/low before acheve duty point*/
    Dio_ChannelType m_t_DioChannelId;  
    TeLED_ChName m_e_CrossRefLED; /*cross reference PWM name*/
} TePWM_h_SimChCfg;

typedef struct
{
    uint16 m_w_Period;  /*actual command period*/
    uint16 m_w_Duty;  /*actual command duty*/
    uint16 m_w_AEPeriod;  /*device control*/
    uint16 m_w_AEDuty;  /*device control*/
    uint16 m_w_AppPeriod;  /*App control*/
    uint16 m_w_AppDuty;  /*App control*/
    
} TeLED_h_ChPeriodDuty;


extern const TePWM_h_Config CaLED_h_PWMCfg[CeLED_e_ChNum];
extern const TePWM_h_Config CaLED_h_RTCfg[CeLED_e_ChNum];
extern const TePWM_h_Config CaLED_h_AdimCfg[CeLED_e_ChNum];

extern const TePWM_h_SimChCfg CaLED_h_SimChCfg[CeLED_e_SwLEDChNum];



/*******************************************************************************
|    Global Function Prototypes 
|******************************************************************************/
void Set_LED1(void);
void Clr_LED1(void);
void Set_LED3(void);
void Clr_LED3(void);
void Set_LowBeam2(void);
void Clr_LowBeam2(void);

#endif
