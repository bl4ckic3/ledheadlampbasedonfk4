#include "Adc.h"
#include "Port.h"
#include "Mcu.h"
#include "Can.h"
#include "Pwm.h"
#include "Gpt.h"
#include "Dio.h"
#include "DF4010_0.h"
#include <stddef.h>  
#include <stdio.h>

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

/*******************************************************************************
**                                                                            **
*******************************************************************************/

void main(void)
{

	
	/* Enable the global interrupts */    
  __asm("ei");
	/*---------------------------------------------
		Mcu Initialization
	---------------------------------------------*/
  /* Initialise MCU Driver */
  Mcu_Init(McuModuleConfiguration1);
	/* Set the CPU Clock to the PLL0 */
  Mcu_InitClock(MCU_CLK_SETTING_PLL0);
  /* Wait until the PLL is locked */
  while (Mcu_GetPllStatus() != MCU_PLL_LOCKED);
  /* Activate the PLL Clock */
  Mcu_DistributePllClock();
	/* Set the MCU to MCU_RUN_MODE mode */
  Mcu_SetMode(McuModeSettingConf0);
	/* Set the MCU to MCU_RUN_MODE mode */
  //Mcu_SetMode(McuModeSettingConf0);

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
  Gpt_EnableNotification(GptChannelConfiguration0); 
  /* Starting the Timer */ 
  Gpt_StartTimer(GptChannelConfiguration0, 0x0100);
	
	/* Set the MCU to MCU DeepStop mode */
  Mcu_SetMode(McuModeSettingConf1);
	/*---------------------------------------------
		PWM Driver 
	 ---------------------------------------------*/
  /* Initialise the PWM Driver */
  //Pwm_Init(PwmChannelConfigSet0);
	/* Set PWM channel 2  to its idle state */
  //Pwm_SetOutputToIdle(PwmChannel13);

	while(1);


	//Set_LED1();
	Set_LowBeam2();
	//Clr_LowBeam2();


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
void SysSrvc_StartupHook(void)
{
}
void SysSrvc_ShutdownHook (UINT8 Error)
{
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
void osResumeAllInterrupts(void) {
}
void osSuspendAllInterrupts(void){
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
void TAUJ0I0_Notification(void)
{
}
void OSTM0_CH0_ISR(void){
}
