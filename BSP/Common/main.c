//#include <stddef.h>  
//#include <stdio.h>
#include "DF4010_0.h"
#include "IoHwAb.h"
#include "IoHwAb_Api.h"


#define SKIP_MAGIC_NUMBER

/*******************************************************************************
**                        Global variables                                    **
*******************************************************************************/
Std_ReturnType GddSetupBuffer0;

/* Declaration for the result buffers */
Adc_ValueGroupType GddDataBufferPtr0[3];
Adc_ValueGroupType ADValueBuffer[3];

/* Variable used to store the Module Version Info */
Std_VersionInfoType GddVersionInfo;

uint8 taskerr;

uint32 programinit_flag = 1;

void Appl_10mS_Task(void);

/****************************************************************************** 
*                       OS Global Symbols                                   ** 
******************************************************************************/ 
BOOL bitValue = 0;
uint8   TaskAlreadyDo = 1; /* permit task run or not */
uint32	Gdd1mSFlag = 0;
uint32	Gdd10mSFlag = 0;
uint32	Gdd100mSFlag = 0;
uint32 lpcnt_spi = 1;
uint32 spicnt=0;  /* spi loop variable */
/****************************************************************************** 
*                       Can Global Symbols                                   ** 
******************************************************************************/ 


extern void IoHwAb_Init(void);

/*******************************************************************************
**                                                                            **
*******************************************************************************/

void main(void)
{

	int i;

#if 0
	/*---------------------------------------------
		Port Driver
	---------------------------------------------*/
	/* Initialize PORT */
	/*  -- VCC5V_CTL,SYNC_CTRL High -- */
  Port_Init(PortConfigSet0);
	FCLA27CTL1 = 0x80;
	FCLA7CTL3  = 0x80;   //CSIG4SI
	
	/*---------------------------------------------
		GPT Driver 
	 ---------------------------------------------*/
  /* Initialisation of the GPT Driver */ 
  Gpt_Init(GptChannelConfigSet0); 
  /* Enabling the Notification */ 
  Gpt_EnableNotification(GptChannelConfiguration1); 
  /* Starting the Timer */ 
  Gpt_StartTimer(GptChannelConfiguration1, 0x1F40);
	

	/*---------------------------------------------
		PWM Driver 
	 ---------------------------------------------*/
  /* Initialise the PWM Driver */
  Pwm_Init(PwmChannelConfigSet0);
	/* Set PWM channel 2  to its idle state */
  //Pwm_SetOutputToIdle(PwmChannel13);



#endif
	
    /*EcuM_StartUp() will call the following code*/
    SysSrvc_StartSchduler();/*here RTOS is started*/
    /*code will never reach here */
    for(;;);

  while(1){
		bitValue =~ bitValue;
		for(i=0;i<10000;i++) {
			Dio_WriteChannel(DioChannel25_12, bitValue);
		}
	}
	//while(1);
	
  /*---------------------------------------------
		Cyclic Task
		---------------------------------------------*/
	while(1){
		//if(Gdd1mSFlag == 10) {
			if(TaskAlreadyDo == 0){
				Appl_10mS_Task();
				TaskAlreadyDo = 1; /* finish task doing job,unpermit task run */
			}else{
				taskerr = 1; // overrun happen!check your task time
			}
		//}
	} /* infinite loop */
} /* end of mainfunction */

/*******************************************************************************
                              Task(Dummy)
*******************************************************************************/
void PWMInit(void)
{   
	IoHwAb_SetLED1(0x8000);
	IoHwAb_SetLED2(0x8000);
	IoHwAb_SetLED3(0x8000);
	IoHwAb_SetLowBeam1(0x8000);
	IoHwAb_SetLowBeam2(0x8000);
	IoHwAb_SetHighSpeed(0x8000);
	IoHwAb_SetBadWeather(0x8000);
	IoHwAb_SetTurnLamp(0x8000);
	IoHwAb_SetParkLamp(0x8000);
}

void SysSrvc_StartupHook(void)
{
  IoHwAb_Init();
  PWMInit();
}
void SysSrvc_ShutdownHook (UINT8 Error)
{
}


void Test_Task(void)
{

#if 0
	IoHwAb_SetODH1(1);
	IoHwAb_SetODH2(1);
	IoHwAb_SetDRLFAIL(1);
	IoHwAb_SetLowBeam1Fail(1);
	IoHwAb_SetLowBeam2Fail(1);
	IoHwAb_SetTurnLampFail(1);

	IoHwAb_GetSW_ParkLamp();
	IoHwAb_GetSW_LowBeam();
	IoHwAb_GetSW_HighBeam();
	IoHwAb_GetSW_TurnLamp();
	IoHwAb_GetSW_CornerLamp();
	IoHwAb_GetSW_CornerLamp();
	IoHwAb_GetSW_CornerLamp();
	IoHwAb_GetSW_CornerLamp();
	IoHwAb_GetSW_BadWeatherMode();
	IoHwAb_GetSW_ControlEnable();

	IoHwAb_ILCLevelLowBeam();
	IoHwAb_ILBendingLeftControl();
	IoHwAb_ILTurnRightControl();
	IoHwAb_ILTurnLeftControl();
	IoHwAb_ILParkLampControl();
	IoHwAb_ILLowBeamControl();
	IoHwAb_ILHighBeamControl();
	IoHwAb_ILDRLControl();
	IoHwAb_ILELevelHighSpeedModeControl();
	IoHwAb_ILVLevelCityModeControl();
	IoHwAb_ILWLevelBadWeatherControl();
#endif

}
void IoHwAb_Adc_Notification_Group0(void)
{	
}
void Pwm_Notification_0(void){
}
void Pwm_Notification_1(void){
}
void Pwm_Notification_2(void){
}
/*****************************************************************************
                        CALL BACK                
*****************************************************************************/
void OSTM_Notification (void){

  Gdd1mSFlag++;
	
	if(Gdd1mSFlag == 1) {
		TaskAlreadyDo = 0; /* permit task to run */
	}
	
	if(Gdd1mSFlag == 10){
		Gdd1mSFlag = 0;
	};

}

/*****************************************************************************
                      10mS Period Task                
*****************************************************************************/
void Appl_10mS_Task(void) {
#if 0	
	bitValue = ~bitValue;
	
	Dio_WriteChannel(DioChannel0_0, bitValue);
	Dio_WriteChannel(DioChannel0_7, bitValue);
	Dio_WriteChannel(DioChannel0_10, bitValue);
	
	Dio_WriteChannel(DioChannel1_7, bitValue);
	Dio_WriteChannel(DioChannel1_8, bitValue);
	Dio_WriteChannel(DioChannel1_9, bitValue);
	Dio_WriteChannel(DioChannel1_10, bitValue);
	Dio_WriteChannel(DioChannel1_11, bitValue);
	Dio_WriteChannel(DioChannel1_12, bitValue);

	Dio_WriteChannel(DioChannel25_1, bitValue);
	Dio_WriteChannel(DioChannel25_5, bitValue);
	Dio_WriteChannel(DioChannel25_6, bitValue);
	Dio_WriteChannel(DioChannel25_7, bitValue);
	Dio_WriteChannel(DioChannel25_8, bitValue);
	Dio_WriteChannel(DioChannel25_9, bitValue);
	Dio_WriteChannel(DioChannel25_10, bitValue);
	Dio_WriteChannel(DioChannel25_11, bitValue);
	Dio_WriteChannel(DioChannel25_12, bitValue);
	Dio_WriteChannel(DioChannel25_13, bitValue);
	Dio_WriteChannel(DioChannel25_14, bitValue);

	Dio_WriteChannel(DioChannel27_0, bitValue);
	Dio_WriteChannel(DioChannel27_1, bitValue);
	
#endif	
}

/*****************************************************************************
                        Dummy Func                
*****************************************************************************/
void SPI_Sequence0_Notification(void)
{
}
void SPI_Sequence1_Notification(void)
{
}
void SPI_Sequence2_Notification(void)
{
}
void SPI_Sequence3_Notification(void)
{
}
void CanTrcv_30_Tja1145_SpiIndicationN_BB(void)
{
}
void CanTrcv_30_Tja1145_SpiIndicationM_BB(void)
{
}
void CanTrcv_30_Tja1145_SpiIndicationL_BB(void)
{
}
void SuspendAllInterrupts(void){
}
void ResumeAllInterrupts(void){
}
