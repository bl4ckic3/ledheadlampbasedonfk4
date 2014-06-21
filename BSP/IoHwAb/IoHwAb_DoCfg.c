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
#include "Dio.h"
#include "IoHwAb_DoCfg.h"

uint8 dummybuffer[2];

//KaHWIO_h_PortAttri
const TsDO_h_PortConfig KaDO_h_PortConfig[CeIoHwAb_u_DoNumber] =
{
/*********************************************************************************************************************
* configure this table according to hardware design only!!!
    |p_bt_Port|                           |e_bt_Offset|       |e_b_Inverse|        |e_bt_DftVal|         |e_bt_En|        | m_u_DoType|
**********************************************************************************************************************/
/*ODH0 ~ ODH1*/
    {NULL, DioChannel10_11, FALSE, TRUE, TRUE, CeDO_u_DioType},
    {NULL, DioChannel10_10, FALSE, TRUE, TRUE, CeDO_u_DioType},
/*OUT1 ~ OUT4)*/
    {NULL, DioChannel1_11,  FALSE, TRUE, TRUE, CeDO_u_DioType},
    {NULL, DioChannel1_10,  FALSE, TRUE, TRUE, CeDO_u_DioType},
    {NULL, DioChannel1_9,   FALSE, TRUE, TRUE, CeDO_u_DioType},
    {NULL, DioChannel1_8,   FALSE, TRUE, TRUE, CeDO_u_DioType},
};

/*EOF*/

