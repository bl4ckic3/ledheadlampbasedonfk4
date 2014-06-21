/**
	\addtogroup MODULE_NvM NvM
	Non-volatile Memory Management Module.
*/
/*@{*/
/***************************************************************************//**
	\file		NvM_Types.h
	\brief		Types Definition of NVRAM Management Module.
	\author		zhaoyg
	\version	1.0
	\date		2012-3-27
	\warning	Copyright (C), 2012, PATAC.
*//*----------------------------------------------------------------------------
	\history
	<No.>	<author>	<time>		<version>	<description>
	1		zhaoyg		2012-3-27	1.0			Create
*******************************************************************************/
#ifndef _NVM_TYPES_H
#define _NVM_TYPES_H

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
	\enum NvM_BlockManagementType
	Block Management Type.
*/
typedef enum BlockManagementType
{
	NVM_BLOCK_NATIVE = 0,
	NVM_BLOCK_REDUNDANT,
	NVM_BLOCK_DATASET
} NvM_BlockManagementType;    

/**
	\enum NvM_ApiConfigClassType
	API Config Class Type.
*/
typedef enum ApiConfigClassType
{
	NVM_API_CONFIG_CLASS_1 = 0,
	NVM_API_CONFIG_CLASS_2,
	NVM_API_CONFIG_CLASS_3
} NvM_ApiConfigClassType;

/*******************************************************************************
	Prototype  Declaration
*******************************************************************************/

#endif /* #ifndef _NVM_TYPES_H */
/*@}*/

