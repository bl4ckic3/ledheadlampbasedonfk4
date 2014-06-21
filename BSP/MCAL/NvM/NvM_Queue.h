/**
	\addtogroup MODULE_NvM NvM
	Non-volatile Memory Management Module.
*/
/*@{*/
/***************************************************************************//**
	\file		NvM_Queue.h
	\brief		Type and API declaration of job queue.
	\author		Lvsf
	\version	1.0
	\date		2012-3-28
	\warning	Copyright (C), 2012, PATAC.
*//*----------------------------------------------------------------------------
	\history
	<No.>	<author>	<time>		<version>	<description>
	1		Lvsf		2012-3-28	1.0			Create
*******************************************************************************/
#ifndef _NVM_QUEUE_H
#define _NVM_QUEUE_H

/*******************************************************************************
	Include Files
*******************************************************************************/
#include "NvM.h"

/*******************************************************************************
	Macro Definition
*******************************************************************************/
/**
	\def NVM_QUEUE_SIZE
	Queue size.
*/
#define NVM_QUEUE_SIZE    10

/*******************************************************************************
	Type Definition
*******************************************************************************/
/**
	\struct Queue_t
	Queue type definition.
*/
typedef struct
{
    RamBlock_t* Data[NVM_QUEUE_SIZE];	/**<Elements of Queue*/
    uint8 Front;						/**<Header of Queue*/
	uint8 Rear;							/**<Tail of Queue*/
} Queue_t;

/*******************************************************************************
	Prototype  Declaration
*******************************************************************************/
/* Clear all jobs */
extern void NvM_ClearJob(void);

/* Add job to queue */
extern uint8 NvM_QueueJob(uint16 BlockId,
                            uint16 ServiceId,
                            uint8* BlockOperatePtr);

/* Get job from queue */
extern uint8 NvM_GetJob(RamBlock_t** Job);

#endif /* #ifndef _NVM_QUEUE_H */
/*@}*/

