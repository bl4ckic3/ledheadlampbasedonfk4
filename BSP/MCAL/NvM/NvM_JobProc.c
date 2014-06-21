/**
	\addtogroup MODULE_NvM NvM
	Non-volatile Memory Management Module.
*/
/*@{*/
/***************************************************************************//**
	\file		NvM_JobProc.c
	\brief		Query queue and implement job
	\author		Lvsf
	\version	1.0
	\date		2012-3-15
	\warning	Copyright (C), 2012, PATAC.
*//*----------------------------------------------------------------------------
	\history
	<No.>	<author>	<time>		<version>	<description>
	  1			Lvsf		2012-3-15	   1.0		   Create
*******************************************************************************/
/*******************************************************************************
	Include Files
*******************************************************************************/
#include "NvM_JobProc.h"

/*******************************************************************************
	Macro Definition
*******************************************************************************/

/*******************************************************************************
	Type Definition
*******************************************************************************/

/*******************************************************************************
	Prototype  Declaration
*******************************************************************************/

/*******************************************************************************
	Variable  Definition
*******************************************************************************/
/**
	\var NvM_BlockInfo_t NvM_CurrentBlockInfo
	Current block information.
*/
NvM_BlockInfo_t NvM_CurrentBlockInfo;

/**
	\var NvM_State_t NvM_TaskState
	State of job process.
*/
NvM_State_t NvM_TaskState;

/*******************************************************************************
	Function  Definition
*******************************************************************************/
/***************************************************************************//**
	\fn			void NvM_JobProcInit()
	\author		Lvsf
	\date		2012-3-22
	\brief		Init Job process.
*******************************************************************************/
void NvM_JobProcInit(void)
{
    NvM_TaskState = NVM_STATE_IDLE;
}

/***************************************************************************//**
	\fn			void NvM_Fsm(void)
	\author		Lvsf
	\date		2012-3-22
	\brief		Query a Job from Queue and implement the Job.
*******************************************************************************/
void NvM_Fsm(void)
{
	RamBlock_t* RamAddrPtr;
	
	if(NVM_STATE_IDLE == NvM_TaskState)
	{
		if (NVM_REQ_PENDING != NvM_CurrentBlockInfo.BlockState)
		{
			if(NvM_GetJob(&RamAddrPtr))
			{
				uint16 BlockId = RamAddrPtr->BlockId;
				
				NvM_CurrentBlockInfo.BlockId = NvM_BlockMngmtArea[BlockId].BlockId;
				NvM_CurrentBlockInfo.ServiceId = NvM_BlockMngmtArea[BlockId].ServiceId;
				NvM_CurrentBlockInfo.BlockRamPtr = NvM_BlockMngmtArea[BlockId].RamBlockDataAddr;
				NvM_CurrentBlockInfo.BlockOffset = NvM_BlockMngmtArea[BlockId].BlockOffset;
				NvM_CurrentBlockInfo.BlockState = NVM_REQ_PENDING;
				NvM_CurrentBlockInfo.Length = NvM_BlockMngmtArea[BlockId].Length;
				NvM_CurrentBlockInfo.DeviceId = NvM_BlockMngmtArea[BlockId].DeviceId;
				NvM_CurrentBlockInfo.LastResult = NVM_REQ_PENDING;
				
				NvM_FsmAction();
			}
			else
			{
				if((NvM_RWC_Flags & NVM_APIFLAG_READ_ALL_SET)
					||(NvM_RWC_Flags & NVM_APIFLAG_WRITE_ALL_SET))
				{
					NvM_FsmAction();
				}
				else
				{
				}
			}
		
		}
		else
		{
		}
	}
	else
	{
	}
}

/***************************************************************************//**
	\fn			void NvM_FsmAction(void)
	\author		Lvsf
	\date		2012-3-22
	\brief		Implement a job
*******************************************************************************/
void NvM_FsmAction(void)
{
	NvM_BlockInfo_t* CurrBlk = &NvM_CurrentBlockInfo;
	
	switch(CurrBlk->ServiceId)
	{
		case NVM_READ_BLOCK:			
			NvM_TaskState = NVM_STATE_READ;
			NvM_BlockMngmtArea[CurrBlk->BlockId].NvRamErrorStatus 
				= NVM_REQ_PENDING;
			
			MemIf_Read(CurrBlk->DeviceId,
                       CurrBlk->BlockId,
                       CurrBlk->BlockOffset,
                       CurrBlk->BlockRamPtr,
                       CurrBlk->Length);
			break; 
			
		case NVM_WRITE_BLOCK:		
			NvM_TaskState = NVM_STATE_WRITE;
			NvM_BlockMngmtArea[CurrBlk->BlockId].NvRamErrorStatus 
				= NVM_REQ_PENDING;
			
			MemIf_Write(CurrBlk->DeviceId,
						CurrBlk->BlockId,
						CurrBlk->BlockRamPtr);
			break; 
			
		case NVM_ERASE_BLOCK:			
			NvM_TaskState = NVM_STATE_ERASE;
			NvM_BlockMngmtArea[CurrBlk->BlockId].NvRamErrorStatus 
				= NVM_REQ_PENDING;
			
			MemIf_EraseImmediateBlock(CurrBlk->DeviceId,
									CurrBlk->BlockId);
			break; 
			
		case NVM_INVALIDATE_NV_BLOCK:			
			NvM_TaskState = NVM_STATE_ERASE;
			NvM_BlockMngmtArea[CurrBlk->BlockId].NvRamErrorStatus 
				= NVM_REQ_PENDING;
			
			MemIf_InvalidateBlock(CurrBlk->DeviceId,
								CurrBlk->BlockId);
			break;
			
		case NVM_READ_ALL:
			NvM_TaskState = NVM_STATE_READALL;
			CurrBlk->BlockId++;
			NvM_BlockMngmtArea[CurrBlk->BlockId].NvRamErrorStatus
				= NVM_REQ_PENDING;
			
			MemIf_Read(NvM_BlockMngmtArea[CurrBlk->BlockId].DeviceId,
                       NvM_BlockMngmtArea[CurrBlk->BlockId].BlockId,
                       NvM_BlockMngmtArea[CurrBlk->BlockId].BlockOffset,
                       NvM_BlockMngmtArea[CurrBlk->BlockId].RamBlockDataAddr,
                       NvM_BlockMngmtArea[CurrBlk->BlockId].Length);		
			break;

		case NVM_WRITE_ALL:
			NvM_TaskState = NVM_STATE_WRITEALL;
			CurrBlk->BlockId++;
			NvM_BlockMngmtArea[CurrBlk->BlockId].NvRamErrorStatus 
 				= NVM_REQ_PENDING;
			
			if(NvM_RWC_Flags & NVM_APIFLAG_CANCEL_WR_ALL_SET )
			{			
				MemIf_Cancel(CurrBlk->DeviceId);
			}
			else
			{
				MemIf_Write(NvM_BlockMngmtArea[CurrBlk->BlockId].DeviceId,
					NvM_BlockMngmtArea[CurrBlk->BlockId].BlockId,
					NvM_BlockMngmtArea[CurrBlk->BlockId].RamBlockDataAddr);
			}
			break;
			
		default:
			break;
	}
}

/*@}*/

