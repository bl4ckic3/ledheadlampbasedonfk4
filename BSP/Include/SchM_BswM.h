/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2008-2011 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SchM_BswM.h
 *        Config:  ECUC
 *  Generated at:  2011-05-03
 *
 *        Author:  visntr
 *
 *   Description:  Header of BSW Scheduler for BswM
 *                 Mainfunctions:
 *                 BswM_MainFunction() Cycle Time 20 ms Activation Offset 5 ms
 *********************************************************************************************************************/
#ifndef SCHM_BSWM_H
#define SCHM_BSWM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"

#define BSWM_ACTIVATION_POINT_0   ACT_TIMEOUT_EVENT_20MS
#define SCHM_TIMER_OFFSET_BSWM    ACT_TIMEOUT_EVENT_5MS
#define BSWM_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS

#define SCHM_BSWM_ENTER_CRITICAL_SECTION \

#define SCHM_BSWM_EXIT_CRITICAL_SECTION \

#define SCHM_BSWM_ENTER_MAINFUNCTION \

#define SCHM_BSWM_EXIT_MAINFUNCTION \


#if defined( __SCHM__ )


SCHM_DEFINE_TIMER(BSWM);


#define SCHM_TIMER_INIT_BSWM   SCHM_TIMER_INIT(BSWM, SCHM_TIMER_OFFSET_BSWM)
#define SCHM_MAINFUNCTION_BSWM  SCHM_MAINFUNCTION(BswM_MainFunction(), BSWM, BSWM_ACTIVATION_POINT_0)



#else /* __SCHM__ */


# define SchM_Enter_BswM(ExclusiveArea) \
   SCHM_BSWM_ENTER_CRITICAL_SECTION    \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea)

#  define SchM_Exit_BswM(ExclusiveArea) \
   SCHM_BSWM_EXIT_CRITICAL_SECTION    \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea)

#endif /* __SCHM__ */

#endif /* SCHM_BSWM_H */

