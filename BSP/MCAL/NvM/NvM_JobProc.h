/**
	\addtogroup MODULE_NvM NvM
	Non-volatile Memory Management Module.
*/
/*@{*/
/***************************************************************************//**
	\file		NvM_JobProc.h
	\brief		Type and API declaration of  job Process.
	\author		lsf
	\version	1.0
	\date		2012-3-5
	\warning	Copyright (C), 2012, PATAC.
*//*----------------------------------------------------------------------------
	\history
	<No.>	<author>	<time>		<version>	<description>
	1		lsf			2012-3-14     1.0		   Create
*******************************************************************************/
#ifndef _NvM_JobProc_H
#define _NvM_JobProc_H

/*******************************************************************************
	Include Files
*******************************************************************************/
#include "NvM.h"
#include "NvM_Queue.h"

/*******************************************************************************
	Macro Definition
*******************************************************************************/

/*******************************************************************************
	Type Definition
*******************************************************************************/
typedef uint8 NvM_StateActionType;
typedef uint8 NvM_ServiceIdType;

/** 
	\struct  NvM_BlockInfoType 
	 job processing structure: contains all information related to
     the processing of one certain job
	 
*/
typedef struct
{
    uint8*	BlockRamPtr;
    uint8	DeviceId;
    uint8	BlockState;
	uint8	LastResult;
	uint16	BlockId;
    uint8	ServiceId;
	uint16	Length;
	uint16	BlockOffset;
} NvM_BlockInfo_t;

/**
	\enum NvM_StateType
	the operation status 
*/
typedef enum
{
	NVM_STATE_UNINIT = 0,     /* Block not init */
    NVM_STATE_IDLE,	          /* Block Idle     */
    NVM_STATE_READ,           /* Read Block     */	
    NVM_STATE_WRITE,          /* Write Block    */
	NVM_STATE_ERASE,	      /* Erase Block    */
	NVM_STATE_READALL,        /* Read all       */	
    NVM_STATE_WRITEALL,       /* Write All      */
	NVM_STATE_FSM_DEFAULT     /* Other State    */
}NvM_State_t;

/*******************************************************************************
	Prototype  Declaration
*******************************************************************************/
extern NvM_State_t NvM_TaskState;
extern NvM_BlockInfo_t NvM_CurrentBlockInfo;

extern void NvM_JobProcInit(void);
extern void NvM_Fsm(void);
extern void NvM_FsmAction(void);

#endif /* #ifndef _NvM_H */

/*@}*/
