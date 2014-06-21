/*
*******************************************************************************
**
**  Copyright(C) Renesas Electronics Corporation 2010
**  All rights reserved by Renesas Electronics Corporation.
**
**  Abstract :
**
**  Last update:	2011/06/23
**  
*******************************************************************************
*/

/*
*******************************************************************************
**  Include files
*******************************************************************************
*/
#include "df4010_0.h"
#include "Std_Types.h"
#include "InterruptType.h"
/*
*******************************************************************************
**  Global define
*******************************************************************************
*/
uint16 VeOS_w_UnitCount=0;

/*-----------------------------------------------------------------------------
**
**	Abstract:
**		This function implements initializes of interrupt.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------*/
void InterruptSetup(void)
{
	/* Flag Clear */
	ICP0 &= 0xEFFF;
	/* Mask Clear */
	ICP0 &= 0xFF7F;
}

/*****************************************************************************/
/*---Application Vector ISR functions---*/
/*****************************************************************************/

#define CODE_START_ISR_SECT
#include "MemMap.h"


#if COMPILER_GHS
PRAGMA_INTERRUPT();
#elif COMPILER_CX
#pragma interrupt NO_VECT unused_isr
#endif
void unused_isr(void)
{
	while(1){};
}

/*****************************************************************************/
/*--ICU ISR functions---*/
/*****************************************************************************/
 __interrupt void  Icu_Edge_Detect_1(void)
{
}

 

