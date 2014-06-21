/**
	\defgroup MODULE_NvM NvM
	Non-volatile Memory Management Module.
*/
/*@{*/
/***************************************************************************//**
	\file		NvM.c
	\brief		the interface of Non-volatile Memory Management Module
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
#include "NvM_Queue.h"
#include "NvM_JobProc.h"
#include "NvM_Cbk.h"
#include "NvM.h"

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
	\var uint8 NvM_RWC_Flags
	Read all/write all/cancel wirte all request flag.
*/
uint8 NvM_RWC_Flags;

/**
	\var RamBlock_t NvM_BlockMngmtArea[BLOCK_TOTAL]
	Block management information buffer.
*/
RamBlock_t NvM_BlockMngmtArea[BLOCK_TOTAL];

/*******************************************************************************
	Function  Definition
*******************************************************************************/
/***************************************************************************//**
	\fn			void NvM_Init( void )
	\author		Lvsf
	\date		2012-3-14
	\brief		Init NvM all internal variables.
*******************************************************************************/
void NvM_Init( void )
{
    uint16 BlockId;
	
	NvM_RWC_Flags = 0;
	NvM_BlockMngmtArea[0].NvRamErrorStatus = NVM_REQ_OK;	
	
	for(BlockId = 1; BlockId < BLOCK_TOTAL; BlockId++)	
    {				
		NvM_BlockMngmtArea[BlockId].DeviceId         = 0;
		NvM_BlockMngmtArea[BlockId].ServiceId        = 0;
        NvM_BlockMngmtArea[BlockId].NvDataIndex      = 0;
		NvM_BlockMngmtArea[BlockId].BlockOffset      = 0;
		NvM_BlockMngmtArea[BlockId].Length           = NvM_Config[BlockId].Length;
		NvM_BlockMngmtArea[BlockId].BlockId          = BlockId;
		NvM_BlockMngmtArea[BlockId].WriteNvRamOnce   = 0;
		NvM_BlockMngmtArea[BlockId].NvRamAttributes  = 0;
		NvM_BlockMngmtArea[BlockId].RamBlockDataAddr = NvM_Config[BlockId].RamAddr1;
		NvM_BlockMngmtArea[BlockId].NvRamErrorStatus = NVM_REQ_OK;
    }
	
	NvM_ClearJob();
    NvM_JobProcInit();
}

/***************************************************************************//**
	\fn	        void NvM_SetDataIndex( uint16 BlockId, uint8 DataIndex)
	\author		Lvsf
	\date		2012-3-14
	\brief		Setting the DataIndex of a dataset NVRAM block.
	\param[in]	BlockId: Block ID
	\param[in]  DataIndex:Data Index
*******************************************************************************/
void NvM_SetDataIndex( uint16 BlockId, uint8 DataIndex )
{
	if(NVM_STATE_UNINIT != NvM_TaskState)
	{
		if ((BLOCK_TOTAL > BlockId) && (0 < BlockId))
		{
			NvM_BlockMngmtArea[BlockId].NvDataIndex = DataIndex;
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
	\fn			void NvM_GetDataIndex( uint16 BlockId, uint8* DataIndexPtr)
	\author		Lvsf
	\date		2012-3-14
	\brief		Getting the currently set DataIndex of a dataset NVRAM block.
	\param[in]	BlockId :Block ID
	\param[out]	DataIndexPtr :DataIndex Pointer
*******************************************************************************/
void NvM_GetDataIndex( uint16 BlockId, uint8* DataIndexPtr )
{
	if ((NVM_STATE_UNINIT != NvM_TaskState)
		&&(BLOCK_TOTAL > BlockId) 
		&&(0 < BlockId)
		&&(NULL != DataIndexPtr)
		&&(NVM_REQ_PENDING != NvM_BlockMngmtArea[BlockId].NvRamErrorStatus))
	{
		*DataIndexPtr = NvM_BlockMngmtArea[BlockId].NvDataIndex ;
	}
	else
	{
	}
}

/***************************************************************************//**
	\fn			void NvM_SetBlockProtection( uint16 BlockId, boolean ProtectionEnabled )
	\author		Lvsf
	\date		2012-3-14
	\brief		Setting/resetting the write protection for a NV block.
	\param[in]	BlockId:Block ID
	\param[in]  ProtectionEnabled: Write Protection should be enable or disable
*******************************************************************************/
void NvM_SetBlockProtection( uint16 BlockId, boolean ProtectionEnabled )
{
	if ((NVM_STATE_UNINIT != NvM_TaskState)
		&&(BLOCK_TOTAL > BlockId) 
		&&(0 < BlockId)
		&&(NVM_REQ_PENDING != NvM_BlockMngmtArea[BlockId].NvRamErrorStatus)
		&&(NVM_BLOCK_WRITE_BLOCK_ONCE_ON != NvM_BlockMngmtArea[BlockId].WriteNvRamOnce))
	{
		if (ProtectionEnabled)
		{
        	NvM_BlockMngmtArea[BlockId].NvRamAttributes |= NVM_WR_PROT_SET;
    	}
    	else
    	{
        	NvM_BlockMngmtArea[BlockId].NvRamAttributes &= NVM_WR_PROT_CL;
    	}
	}
	else
	{
	}
}

/***************************************************************************//**
	\fn			void NvM_GetErrorStatus(uint16 BlockId, uint8* RequestResultPtr)
	\author		Lvsf
	\date		2012-3-14
	\brief		Service to read the block dependent error/status information.
	\param[in]	BlockId:Block ID
	\param[out]	RequestResultPtr:pointer to where to store request result
*******************************************************************************/
void NvM_GetErrorStatus( uint16 BlockId, uint8* RequestResultPtr )
{
	if ((NVM_STATE_UNINIT != NvM_TaskState)
		&&(BLOCK_TOTAL > BlockId) 
		&&(0 < BlockId)
		&&(NULL != RequestResultPtr))
	{
		*RequestResultPtr = NvM_BlockMngmtArea[BlockId].NvRamErrorStatus;
	}
	else
	{
	}
}

/***************************************************************************//**
	\fn			void NvM_SetRamBlockStatus( uint16 BlockId, boolean BlockChanged )
	\author		Lvsf
	\date		2012-3-14
	\brief		Setting the RAM block status of an NVRAM block.
	\param[in]	BlockId:Block ID
	\param[in]  BlockChanged:Ram Block as changed or unchanged
*******************************************************************************/
void NvM_SetRamBlockStatus(uint16 BlockId, boolean BlockChanged)
{
	if ((NVM_STATE_UNINIT != NvM_TaskState)
		&&(BLOCK_TOTAL > BlockId) 
		&&(0 < BlockId)
		&&(NVM_REQ_PENDING != NvM_BlockMngmtArea[BlockId].NvRamErrorStatus )
		&&(NULL != NvM_BlockMngmtArea[BlockId].RamBlockDataAddr ))
	{
		if (BlockChanged)
        {
            /* set block changed and valid */
            NvM_BlockMngmtArea[BlockId].NvRamAttributes 
            	|= (NVM_STATE_CHANGED_SET | NVM_STATE_VALID_SET);
        }
        else
        {
            /* set block unchanged */
            NvM_BlockMngmtArea[BlockId].NvRamAttributes
            	&= (NVM_STATE_CHANGED_CL & NVM_STATE_VALID_CL);
        }
	}
	else
	{
	}
}

/***************************************************************************//**
	\fn			Std_ReturnType NvM_ReadBlock(uint16 BlockId, uint8* NvM_DstPtr)
	\author		Lvsf
	\date		2012-3-14
	\brief		Copy the data of the NV block to its corresponding RAM block.
	\param[in]	BlockId: Block ID
	\param[out]	NvM_DstPtr:Pointer to RAM data block
	\return		Std_RetrunType:E_OK/E_NOT_OK, request has been acceptd or not
*******************************************************************************/
Std_ReturnType NvM_ReadBlock(uint16 BlockId, uint8* NvM_DstPtr)
{
	Std_ReturnType ret = E_NOT_OK;

	if ((NVM_STATE_UNINIT != NvM_TaskState)
		&&(BLOCK_TOTAL > BlockId) 
		&&(0 < BlockId)
		&&(NVM_REQ_PENDING != NvM_BlockMngmtArea[BlockId].NvRamErrorStatus )
		&&(NULL != NvM_DstPtr))
	{
		if (NvM_QueueJob(BlockId, NVM_READ_BLOCK,NvM_DstPtr))
		{
			NvM_BlockMngmtArea[BlockId].NvRamAttributes 
				&= (NVM_STATE_VALID_CL & NVM_STATE_CHANGED_CL);

			ret = E_OK;
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
	\fn			Std_ReturnType NvM_WriteBlock( uint16 BlockId, const uint8* NvM_SrcPtr )
	\author		Lvsf
	\date		2012-3-14
	\brief		Copy the data of the RAM block to its corresponding NV block.
	\param[in]	BlockId: Block ID
	\param[in]  NvM_SrcPtr:Pointer to RAM data block
	\return		Std_RetrunType:E_OK/E_NOT_OK.request has been acceptd or not
*******************************************************************************/
Std_ReturnType NvM_WriteBlock(uint16 BlockId, uint8* NvM_SrcPtr)
{
	Std_ReturnType ret = E_NOT_OK;

	if (  (NVM_STATE_UNINIT != NvM_TaskState)
		&&(BLOCK_TOTAL > BlockId) 
		&&(0 < BlockId)
		&&(NULL != NvM_SrcPtr)
		&&((NvM_BlockMngmtArea[BlockId].NvRamAttributes & NVM_WR_PROT_SET) == 0)
		&&((NvM_BlockMngmtArea[BlockId].NvRamAttributes & NVM_LOCK_STAT_SET) == 0)
		&&(NVM_REQ_PENDING != NvM_BlockMngmtArea[BlockId].NvRamErrorStatus ))
	{
		if (NvM_QueueJob(BlockId, NVM_WRITE_BLOCK, NvM_SrcPtr))
		{
			/* set the ram block status valid and changed */
        	NvM_BlockMngmtArea[BlockId].NvRamAttributes 
        		|= (NVM_STATE_VALID_SET | NVM_STATE_CHANGED_SET);
			
			ret = E_OK;
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
	\fn			Std_ReturnType NvM_RestoreBlockDefaults(uint16 BlockId,uint8* NvM_DestPtr)
	\author		Lvsf
	\date		2012-3-14
	\brief		Restore the default data to its corresponding RAM block.
	\param[in]	BlockId:Block ID
	\param[out]	NvM_DestPtr:Pointer to RAM data block
	\return		Std_ReturnType:E_OK/E_NOT_OK.request has been acceptd or not
*******************************************************************************/
Std_ReturnType NvM_RestoreBlockDefaults( uint16 BlockId, uint8* NvM_DestPtr )
{
	Std_ReturnType ret;

	if (  (NVM_STATE_UNINIT != NvM_TaskState)
		&&(BLOCK_TOTAL > BlockId) 
		&&(0 < BlockId)
		&&(NULL != NvM_DestPtr)
		&&(NVM_REQ_PENDING != NvM_BlockMngmtArea[BlockId].NvRamErrorStatus ))
	{
		if (NvM_QueueJob(BlockId,NVM_READ_BLOCK, NvM_DestPtr))
		{
			NvM_BlockMngmtArea[BlockId].NvRamAttributes &= 
									(NVM_STATE_VALID_CL & NVM_STATE_CHANGED_CL);

			ret = E_OK;
		}
		else
		{	
			ret = E_NOT_OK;
		}
	}
	else
	{
		ret = E_NOT_OK;
	}
	
	return ret;	
}

/***************************************************************************//**
	\fn			Std_ReturnType NvM_EraseNvBlock( uint16 BlockId )
	\author		Lvsf
	\date		2012-3-14
	\brief		Erase a NV block.
	\param[in]	BlockId:Block ID
	\return		Std_ReturnType:E_OK/E_NOT_OK.request has been acceptd or not
*******************************************************************************/
Std_ReturnType NvM_EraseNvBlock( uint16 BlockId )
{
	Std_ReturnType ret;

	if (  (NVM_STATE_UNINIT != NvM_TaskState)
		&&(BLOCK_TOTAL > BlockId) 
		&&(0 < BlockId)
		&&((NvM_BlockMngmtArea[BlockId].NvRamAttributes  & NVM_WR_PROT_SET) == 0)
		&&((NvM_BlockMngmtArea[BlockId].NvRamAttributes & NVM_LOCK_STAT_SET) == 0)
		&&(NVM_REQ_PENDING != NvM_BlockMngmtArea[BlockId].NvRamErrorStatus ))
	{
		if (NvM_QueueJob(BlockId, NVM_ERASE_BLOCK , NULL))
		{
			ret = E_OK;
		}
		else
		{	
			ret = E_NOT_OK;
		}
	}
	else
	{
		ret = E_NOT_OK;
	}

	return ret;
}

/***************************************************************************//**
	\fn		    Std_ReturnType NvM_InvalidateNvBlock( uint16 BlockId )
	\author		Lvsf
	\date		2012-3-14
	\brief		Service to invalidate a NV block.
	\param[in]	BlockId:Block ID
	\return		Std_ReturnType:E_OK/E_NOT_OK.request has been acceptd or not
*******************************************************************************/
Std_ReturnType NvM_InvalidateNvBlock( uint16 BlockId )
{
	Std_ReturnType ret = E_NOT_OK;

	if ((NVM_STATE_UNINIT != NvM_TaskState)
		&&(BLOCK_TOTAL > BlockId) 
		&&(0 < BlockId)
		&&((NvM_BlockMngmtArea[BlockId].NvRamAttributes  & NVM_WR_PROT_SET) == 0)
		&&((NvM_BlockMngmtArea[BlockId].NvRamAttributes & NVM_LOCK_STAT_SET) == 0)
		&&(NVM_REQ_PENDING != NvM_BlockMngmtArea[BlockId].NvRamErrorStatus ))
	{
		if (NvM_QueueJob(BlockId, NVM_INVALIDATE_NV_BLOCK , NULL))
		{
			ret = E_OK;
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
	\fn		    void NvM_ReadAll( void )
	\author		lsf
	\date		2012-3-14
	\brief		Initiates a multi block read request.
*******************************************************************************/
void NvM_ReadAll( void )
{
	if ((NVM_STATE_UNINIT != NvM_TaskState)
		&&(NVM_REQ_PENDING != NvM_BlockMngmtArea[0].NvRamErrorStatus))
	{
		if (NvM_QueueJob(0, NVM_READ_ALL , NULL))
		{
			NvM_RWC_Flags |= NVM_APIFLAG_READ_ALL_SET;
			NvM_BlockMngmtArea[0].NvRamErrorStatus = NVM_REQ_PENDING ;
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
	\fn		    void NvM_WriteAll ( void )
	\author		Lvsf
	\date		2012-3-14
	\brief		Initiates a multi block write request.
*******************************************************************************/
void NvM_WriteAll ( void )
{
	if ((NVM_STATE_UNINIT != NvM_TaskState)
		&&(NVM_REQ_PENDING != NvM_BlockMngmtArea[0].NvRamErrorStatus))
	{
		
		if (NvM_QueueJob(0, NVM_WRITE_ALL , NULL))
		{
			NvM_RWC_Flags &= NVM_APIFLAG_CANCEL_WR_ALL_CL;
			NvM_RWC_Flags |= NVM_APIFLAG_WRITE_ALL_SET;
			NvM_BlockMngmtArea[0].NvRamErrorStatus = NVM_REQ_PENDING;
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
	\fn		    void NvM_CancelWriteAll( void )
	\author		Lvsf
	\date		2012-3-14
	\brief		Cancel running NvM_WriteAll request.
*******************************************************************************/
void NvM_CancelWriteAll( void )
{
	if (NVM_STATE_UNINIT != NvM_TaskState)
    {
		if(NVM_WRITE_ALL == NvM_CurrentBlockInfo.ServiceId)
		{
        	NvM_RWC_Flags |= NVM_APIFLAG_CANCEL_WR_ALL_SET;
			NvM_RWC_Flags &= NVM_APIFLAG_WRITE_ALL_CL;
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
	\fn		    void NvM_JobEndNotification( void )
	\author		Lvsf
	\date		2012-3-14
	\brief		Function to be used by the underlying memory abstraction to 
	            signal end of job without error.
*******************************************************************************/
void NvM_JobEndNotification( void )
{
	if((NvM_RWC_Flags & NVM_APIFLAG_WRITE_ALL_SET)
		||(NvM_RWC_Flags & NVM_APIFLAG_READ_ALL_SET))
	{
		if((BLOCK_TOTAL-1) == NvM_CurrentBlockInfo.BlockId)
		{
			if(NVM_READ_ALL == NvM_CurrentBlockInfo.ServiceId)
			{
				NvM_RWC_Flags &= NVM_APIFLAG_READ_ALL_CL;
			}
			else
			{
				NvM_RWC_Flags &= NVM_APIFLAG_WRITE_ALL_CL;
				NvM_RWC_Flags &= NVM_APIFLAG_CANCEL_WR_ALL_CL;
			}
			
			NvM_CurrentBlockInfo.BlockState = NVM_REQ_OK;
			NvM_BlockMngmtArea[0].NvRamErrorStatus = NVM_REQ_OK;
		}
		else
		{
			NvM_CurrentBlockInfo.BlockState = NVM_REQ_PENDING;	
			NvM_BlockMngmtArea[0].NvRamErrorStatus = NVM_REQ_PENDING;	
		}
	}
	else
	{
		NvM_CurrentBlockInfo.BlockState = NVM_REQ_OK;
		NvM_CurrentBlockInfo.LastResult = NVM_REQ_OK;
		NvM_BlockMngmtArea[NvM_CurrentBlockInfo.BlockId].NvRamErrorStatus =
																	NVM_REQ_OK;
	}
	
	NvM_TaskState = NVM_STATE_IDLE;
}


/***************************************************************************//**
	\fn		    void NvM_JobErrorNotification( void )
	\author		Lvsf
	\date		2012-3-14
	\brief		Function to be used by the underlying memory abstraction to 
	            signal end of job with error.
*******************************************************************************/
void NvM_JobErrorNotification( void )
{
	switch(MemIf_GetJobResult(NvM_CurrentBlockInfo.DeviceId))
    {
        case MEMIF_BLOCK_INCONSISTENT:
            NvM_CurrentBlockInfo.LastResult = NVM_REQ_INTEGRITY_FAILED;
            break;

        case MEMIF_BLOCK_INVALID:
            NvM_CurrentBlockInfo.LastResult = NVM_REQ_NV_INVALIDATED;
            break;

        default:
            NvM_CurrentBlockInfo.LastResult = NVM_REQ_NOT_OK;
    }
	
	if((NvM_RWC_Flags & NVM_APIFLAG_WRITE_ALL_SET)
		||(NvM_RWC_Flags & NVM_APIFLAG_READ_ALL_SET))
	{
		if((BLOCK_TOTAL-1) == NvM_CurrentBlockInfo.BlockId)
		{
			if(NVM_READ_ALL == NvM_CurrentBlockInfo.ServiceId)
			{
				NvM_RWC_Flags &= NVM_APIFLAG_READ_ALL_CL;
			}
			else
			{
				NvM_RWC_Flags &= NVM_APIFLAG_WRITE_ALL_CL;
				NvM_RWC_Flags &= NVM_APIFLAG_CANCEL_WR_ALL_CL;
			}
			
			NvM_CurrentBlockInfo.BlockState = NvM_CurrentBlockInfo.LastResult;
		}
		else
		{
			NvM_CurrentBlockInfo.BlockState = NVM_REQ_PENDING;
		}
	}
	else
	{
		NvM_CurrentBlockInfo.BlockState = NVM_REQ_NOT_OK;
		NvM_CurrentBlockInfo.LastResult = NVM_REQ_NOT_OK;
		NvM_BlockMngmtArea[NvM_CurrentBlockInfo.BlockId].NvRamErrorStatus =
												NvM_CurrentBlockInfo.LastResult;
	}
	
	NvM_TaskState = NVM_STATE_IDLE;
}

/***************************************************************************//**
	\fn		    void NvM_MainFunction(void)
	\author		Lvsf
	\date		2012-3-15
	\brief		Performing the processing of the NvM's job
*******************************************************************************/
void NvM_MainFunction(void)
{
	if (NVM_STATE_UNINIT != NvM_TaskState)
	{
    	NvM_Fsm();
	}
	else
	{
	}
}

/*@}*/

