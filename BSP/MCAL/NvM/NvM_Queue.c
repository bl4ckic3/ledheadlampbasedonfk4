/**
	\addtogroup MODULE_NvM NvM
	Non-volatile Memory Management Module.
*/
/*@{*/
/***************************************************************************//**
	\file		NvM_Queue.h
	\brief		Implementation of queue.
	\author		Lvsf
	\version	1.0
	\date		2012-3-28
	\warning	Copyright (C), 2012, PATAC.
*//*----------------------------------------------------------------------------
	\history
	<No.>	<author>	<time>		<version>	<description>
	1		Lvsf		2012-3-28	1.0			Create
*******************************************************************************/
/*******************************************************************************
	Include Files
*******************************************************************************/
#include "NvM_JobProc.h"
#include "NvM_Queue.h"

/*******************************************************************************
	Macro Definition
*******************************************************************************/

/*******************************************************************************
	Type Definition
*******************************************************************************/

/*******************************************************************************
	Prototype  Declaration
*******************************************************************************/
static void InitQueue(Queue_t*	  Queue);
static uint8 PushQueue(Queue_t* Queue, RamBlock_t* Job);
static uint8 PopQueue(Queue_t*	   Queue, RamBlock_t** Job);

/*******************************************************************************
	Variable  Definition
*******************************************************************************/
/**
	\var static Queue_t JobQueue
	Job Queue.
*/
static Queue_t JobQueue;

/*******************************************************************************
	Function  Definition
*******************************************************************************/
/***************************************************************************//**
	\fn			void NvM_ClearJob(void)
	\author		Lvsf
	\date		2012-3-28
	\brief		Clear all job from queue.
*******************************************************************************/
void NvM_ClearJob(void)
{
	InitQueue(&JobQueue);
}

/***************************************************************************//**
	\fn			uint8 NvM_QueueJob(uint16 BlockId, uint16 ServiceId, 
					uint8* BufferPtr)
	\author		Lvsf
	\date		2012-3-28
	\param[in]	BlockId :Block ID.
	\param[in]	ServiceId :Service ID.
	\param[in]	BufferPtr :RAM data pointer.
	\return		FALSE: Failure/TRUE: Success.
	\brief		Add job to queue.
*******************************************************************************/
uint8 NvM_QueueJob(uint16 BlockId, uint16 ServiceId, uint8* BufferPtr)
{
	uint8  Status;
	uint8  ret = FALSE;
	
	Status = NvM_BlockMngmtArea[BlockId].NvRamErrorStatus;
	
	if (NVM_REQ_PENDING != Status)
	{
		if(PushQueue(&JobQueue, &NvM_BlockMngmtArea[BlockId]))
		{
			NvM_BlockMngmtArea[BlockId].BlockId = BlockId;
			NvM_BlockMngmtArea[BlockId].ServiceId = ServiceId;
			NvM_BlockMngmtArea[BlockId].RamBlockDataAddr = BufferPtr;
			NvM_BlockMngmtArea[BlockId].NvRamErrorStatus = NVM_REQ_PENDING;
			
			ret = TRUE;
		}
		else 
		{
		}
	}
	else
	{
	}

	return ret;
}

/***************************************************************************//**
	\fn			uint8 NvM_GetJob(RamBlock_t** Job)
	\author		Lvsf
	\date		2012-3-28
	\param[out]	Job :The pointer to element.
	\return		FALSE: Failure/TRUE: Success.
	\brief		Get job from queue.
*******************************************************************************/
uint8 NvM_GetJob(RamBlock_t** Job)
{
	uint8 ret = FALSE;
	
	if(PopQueue(&JobQueue, Job))
	{
		ret = TRUE;
	}
	else
	{
	}
	
	return ret;
}

/***************************************************************************//**
	\fn			static void InitQueue(Queue_t* Queue)
	\author		Lvsf
	\date		2012-3-28
	\param[in]	Queue :The pointer to queue.
	\brief		Init queue.
*******************************************************************************/
static void InitQueue(Queue_t*    Queue)
{
	if(NULL != Queue)
	{
		Queue->Front = 0;
		Queue->Rear = 0;
	}
	else
	{
	}
}

/***************************************************************************//**
	\fn			static uint8 PushQueue(Queue_t* Queue, RamBlock_t* Job)
	\author		Lvsf
	\date		2012-3-28
	\param[in]	Queue :The pointer to queue.
	\param[in]	Job :The pointer to element.
	\return		FALSE: Failure/TRUE: Success.
	\brief		Push element into queue.
*******************************************************************************/
static uint8 PushQueue(Queue_t* Queue, RamBlock_t* Job)
{
	uint8 ret = FALSE;
	
	if(NULL != Queue)
	{
		if((Queue->Rear+1)%NVM_QUEUE_SIZE != Queue->Front)
		{
			Queue->Data[Queue->Rear] = Job;
        	Queue->Rear = (Queue->Rear+1)%NVM_QUEUE_SIZE;
      	  	
			ret = TRUE;
		}
		else
		{
		}
	}
	else
	{
	}
	
	return ret;
}

/***************************************************************************//**
	\fn			static uint8 PopQueue(Queue_t* Queue, RamBlock_t** Job)
	\author		Lvsf
	\date		2012-3-28
	\param[in]	Queue :The pointer to queue.
	\param[out]	Job :The pointer to element.
	\return		FALSE: Failure/TRUE: Success.
	\brief		Pop element from queue.
*******************************************************************************/
static uint8 PopQueue(Queue_t*     Queue, RamBlock_t** Job)
{
	uint8 ret = FALSE;
	
	if(NULL != Queue)
	{
		if(Queue->Front != Queue->Rear)
		{
			*Job = Queue->Data[Queue->Front];
			Queue->Front = (Queue->Front+1)%NVM_QUEUE_SIZE;

			ret = TRUE;
		}
		else
		{
		}
	}
	else
	{
	}
	
	return ret;
}

