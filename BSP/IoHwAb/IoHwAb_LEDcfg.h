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
*******************************************************************************/
#ifndef IOHWAB_LED_CFG_H
#define IOHWAB_LED_CFG_H

#define CeIoHwAb_e_InvalidPwmName  CeLED_e_ChNum

/*PWM clock config:
|Although PWM clock is config in MCAL, this parameter is set in this file and used in RTE
|Unit: us
*/
#define CeLED_w_ClockSourceUs    32u

/*simulate PWM channel Id*/
typedef enum
{
    CeLED_e_SimCh0,
    CeLED_e_SwLEDChNum
} TeLED_SimChEnum;

typedef enum
{
    //CeIoHwAb_e_PWMCLK,
    CeIoHwAb_e_LED_1, /*Reserved1*/
    CeIoHwAb_e_LED_2, /*Reserved2*/
    CeIoHwAb_e_LED_3, /*Highbeam*/
    CeIoHwAb_e_HighSpeed, /*HighSpeed*/
    CeIoHwAb_e_BadWeather, /*BadWeather*/
    CeIoHwAb_e_TurnLamp, /*TurnLamp*/
    CeIoHwAb_e_ParkLamp, /*ParkLamp*/
    CeIoHwAb_e_LowBeam_1, /*LowBeam1*/
    CeIoHwAb_e_LowBeam_2, /*LowBeam2*/
	  CeLED_e_ChNum
} TeLED_ChName;



#endif /* IOHWAB_LED_CFG_H */


