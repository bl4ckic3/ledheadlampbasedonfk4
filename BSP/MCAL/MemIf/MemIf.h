/**
	\addtogroup MODULE_MemIf MemIf
	Memory Abstration Interface Module.
*/
/*@{*/
/***************************************************************************//**
	\file		MemIf.h
	\brief		API Declaration of Memory Abstration Interface Module.
	\author		zhaoyg
	\version	1.0
	\date		2012-3-27
	\warning	Copyright (C), 2012, PATAC.
*//*----------------------------------------------------------------------------
	\history
	<No.>	<author>	<time>		<version>	<description>
	1		zhaoyg		2012-3-27	1.0			Create
*******************************************************************************/
#ifndef _MEMIF_H
#define _MEMIF_H

/*******************************************************************************
	Include Files
*******************************************************************************/
#include "MemIf_Types.h"

/*******************************************************************************
	Macro Definition
*******************************************************************************/
/**
	\def MEMIF_BROADCAST_ID
	Broadcast ID.
*/
#define MEMIF_BROADCAST_ID	(0xFF)

/*******************************************************************************
	Type Definition
*******************************************************************************/

/*******************************************************************************
	Prototype  Declaration
*******************************************************************************/
/**
	\def MemIf_SetMode
	Set Work Mode.
*/
#define MemIf_SetMode(Mode)\
	Fee_SetMode((Mode))

/**
	\def MemIf_Read
	Read Data.
*/
#define MemIf_Read(DeviceIndex,BlockNumber,BlockOffset,DataBufferPtr,Length)\
	Fee_Read((BlockNumber),(BlockOffset),(DataBufferPtr),(Length))

/**
	\def MemIf_Write
	Write Data.
*/
#define MemIf_Write(DeviceIndex,BlockNumber,DataBufferPtr)\
	Fee_Write((BlockNumber),(DataBufferPtr))

/**
	\def MemIf_EraseImmediateBlock
	Erase Immediate Block.
*/
#define MemIf_EraseImmediateBlock(DeviceIndex,BlockNumber)\
	Fee_EraseImmediateBlock((BlockNumber))

/**
	\def MemIf_InvalidateBlock
	Invalidate Block.
*/
#define MemIf_InvalidateBlock(DeviceIndex,BlockNumber)\
	Fee_InvalidateBlock((BlockNumber))

/**
	\def MemIf_Cancel
	Cancel Job.
*/
#define MemIf_Cancel(DeviceIndex)\
	Fee_Cancel()

/**
	\def MemIf_GetStatus
	Get Status.
*/
#define MemIf_GetStatus(DeviceIndex)\
	Fee_GetStatus()

/**
	\def MemIf_GetJobResult
	Get Job Result.
*/
#define MemIf_GetJobResult(DeviceIndex)\
	Fee_GetJobResult()

#endif /* #ifndef _MEMIF_H */
/*@}*/

