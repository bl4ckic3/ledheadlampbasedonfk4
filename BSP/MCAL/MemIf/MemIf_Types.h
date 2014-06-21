/**
	\addtogroup MODULE_MemIf MemIf
	Memory Abstration Interface Module.
*/
/*@{*/
/***************************************************************************//**
	\file		MemIf_Types.h
	\brief		Types Definition of Memory Abstration Interface Module.
	\author		zhaoyg
	\version	1.0
	\date		2012-3-27
	\warning	Copyright (C), 2012, PATAC.
*//*----------------------------------------------------------------------------
	\history
	<No.>	<author>	<time>		<version>	<description>
	1		zhaoyg		2012-3-27	1.0			Create
*******************************************************************************/
#ifndef _MEMIF_TYPES_H
#define _MEMIF_TYPES_H

/*******************************************************************************
	Include Files
*******************************************************************************/

/*******************************************************************************
	Macro Definition
*******************************************************************************/

/*******************************************************************************
	Type Definition
*******************************************************************************/
/**
	\enum MemIf_StatusType
	Type definition for MEMIF status types.
*/
typedef enum
{
	MEMIF_UNINIT = 0,
	MEMIF_IDLE,
	MEMIF_BUSY,
	MEMIF_BUSY_INTERNAL
} MemIf_StatusType;

/**
	\enum MemIf_StatusType
	Type definition for MEMIF job result types.
*/
typedef enum
{
	MEMIF_JOB_OK = 0,
	MEMIF_JOB_FAILED,
	MEMIF_JOB_PENDING,
	MEMIF_JOB_CANCELLED,
	MEMIF_BLOCK_INCONSISTENT,
	MEMIF_BLOCK_INVALID
} MemIf_JobResultType;

/**
	\enum MemIf_StatusType
	Type definition for MEMIF mode types.
*/
typedef enum
{
	MEMIF_MODE_SLOW = 0,
	MEMIF_MODE_FAST
} MemIf_ModeType;

/*******************************************************************************
	Prototype  Declaration
*******************************************************************************/

#endif /* #ifndef _MEMIF_TYPES_H */
/*@}*/

