/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 LED Components                         */
/* Module       = Pwm_Irq.h                                                   */
/* Version      = 3.1.3a                                                      */
/* Date         = 23-Apr-2013                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2013-2014 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of API information.                                              */
/*                                                                            */
/*============================================================================*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:  18-Aug-2009  : Initial version
/******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/*******************************************************************************
** Function Name        : IoHwAb_Init
**
** Service ID           : NA
**
** Description          : These are Interrupt routines for the timer TAUAn and
**                        m, where n represents the TAUA Units and m
**                        represents channels associated for each Unit.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Remarks              : Global Variable(s):
**                        Pwm_GpChannelTimerMap, Pwm_GpChannelConfig,
**                        Pwm_GstChannelNotifFunc, Pwm_GpNotifStatus
**
**                        Function(s) invoked:
**                        None
*******************************************************************************/
void IoHwAb_Init(void)
{
	/*---------------------------------------------
		Mcu Initialization
	---------------------------------------------*/
  /* Initialise MCU Driver */
  Mcu_Init(McuModuleConfiguration0);
  /* Set the CPU Clock to the PLL0 */
  Mcu_InitClock(MCU_CLK_SETTING_PLL0);
  /* Wait until the PLL is locked */
  while (Mcu_GetPllStatus() != MCU_PLL_LOCKED);
  /* Activate the PLL Clock */
  Mcu_DistributePllClock();
	/* Set the MCU to MCU_RUN_MODE mode */
  Mcu_SetMode(McuModeSettingConf0);

	/*---------------------------------------------
		Port Driver
	---------------------------------------------*/
	/* Initialize PORT */
	/*  -- VCC5V_CTL,SYNC_CTRL High -- */
  Port_Init(PortConfigSet0);
	FCLA27CTL1 = 0x80;
	FCLA7CTL3  = 0x80;   //CSIG4SI
	
	/*---------------------------------------------
		PWM Driver 
	 ---------------------------------------------*/
  /* Initialise the PWM Driver */
  Pwm_Init(PwmChannelConfigSet0);

	/*---------------------------------------------
		CAN Driver 
	 ---------------------------------------------*/
  /* Global Initialization */
  Can_Init(CanConfigSet_1);
  /* Set Controller Mode to START Mode for Controller 0 */
  Can_SetControllerMode(0, CAN_T_START);
	  /* Set Controller Mode to START Mode for Controller 0 */
  Can_SetControllerMode(1, CAN_T_START);

	  /* Following API can be invoked while exiting a critical area which enables
     all disabled interrupts */
  /* Following API enables Rx, Tx, Wakeup and BusOff Interrupts for
     CAN Controller 0  */
  Can_EnableControllerInterrupts(0);
	Can_EnableControllerInterrupts(1);
 

  return;
}

/****************************************************************************************
| NAME:    IoHwAb_SchM10ms                                                                                               
| CALLED BY:     (10 ms task) SchM
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    
| RETURN VALUE:     NA
| DESCRIPTION:      process IO abstraction task
****************************************************************************************/
void IoHwAb_SchM10ms(void)
{
	#if 0
	IoHwAb_LEDOutput(); /* direct input/output */
	IoHwAb_FANOutput(); /* buffer input/output */
	IoHwAb_DIO();
	IoHwAb_ADInput();   /* buffer input/output */
	#endif
}
