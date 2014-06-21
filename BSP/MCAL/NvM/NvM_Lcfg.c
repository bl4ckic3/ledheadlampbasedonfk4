/**
	\addtogroup MODULE_NvM NvM
	Non-volatile Memory Management Module.
*/
/*@{*/
/***************************************************************************//**
	\file		NvM_Lcfg.c
	\brief		Link-time Configuration of NVRAM Management Module.
	\author		zhaoyg
	\version	1.0
	\date		2012-3-27
	\warning	Copyright (C), 2012, PATAC.
*//*----------------------------------------------------------------------------
	\history
	<No.>	<author>	<time>		<version>	<description>
	1		zhaoyg		2012-3-27	1.0			Create
*******************************************************************************/
/*******************************************************************************
	Include Files
*******************************************************************************/
#include "NvM.h"

/*******************************************************************************
	Macro Definition
*******************************************************************************/
/**
	\def NVM_BLK_CFG
	\param	RamAddr :RAM address of block.
	\param	RomAddr :ROM address of block(Default Value).
	\param	Length :Length of block.
	Block configuration.
*/
#define NVM_BLK_CFG(RamAddr1, RamAddr2, RomAddr, Length)\
	{(uint8*)(RamAddr1),(uint8*)(RamAddr2),(uint8*)(RomAddr),(Length)}

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
	\var NvM_Config_t NvM_Config[BLOCK_TOTAL]
	Block Configuration.
*/

#if 1		//test Map A
const NvM_Config_t NvM_Config[BLOCK_TOTAL] =
	{
	NVM_BLK_CFG(0x00000000, 0x00000000, 0x00000000, 0		),
	NVM_BLK_CFG(0xFEDFF000, 0xFEDFF400, 0x000FE000, 1024	),
	NVM_BLK_CFG(0xFEDFF800, 0xFEDFFA00, 0x000FE400, 512 	),
	NVM_BLK_CFG(0xFEDFFC00, 0xFEDFFD00, 0x000FE600, 256 	),
	NVM_BLK_CFG(0xFEDFFE00, 0xFEDFFF00, 0x000FE700, 256 	)
};

#else		//test Map B
const NvM_Config_t NvM_Config[BLOCK_TOTAL] =
{
NVM_BLK_CFG(0x00000000, 0x00000000, 0x00000000, 0		),
NVM_BLK_CFG(0xFEDFE000,	0xFEDFE400, 0x000BF000,	1024	),
NVM_BLK_CFG(0xFEDFE800,	0xFEDFEC00, 0x000BF400,	1024	),
NVM_BLK_CFG(0xFEDFF000, 0xFEDFF200, 0x000BF800, 512		),
NVM_BLK_CFG(0xFEDFF400, 0xFEDFF600, 0x000BFA00, 512 	),
NVM_BLK_CFG(0xFEDFF800, 0xFEDFF900, 0x000BFC00, 256 	),
NVM_BLK_CFG(0xFEDFFA00, 0xFEDFFA80, 0x000BFD00, 128 	),
NVM_BLK_CFG(0xFEDFFB00, 0xFEDFFB80, 0x000BFD80, 128 	),
NVM_BLK_CFG(0xFEDFFC00, 0xFEDFFC80, 0x000BFE00, 128 	),
NVM_BLK_CFG(0xFEDFFD00, 0xFEDFFD80, 0x000BFE80, 128 	),
NVM_BLK_CFG(0xFEDFFE00, 0xFEDFFE80, 0x000BFF00, 128 	),
NVM_BLK_CFG(0xFEDFFF00, 0xFEDFFF40, 0x000BFF80, 64		),
NVM_BLK_CFG(0xFEDFFF80, 0xFEDFFFA0, 0x000BFFC0, 32		),
NVM_BLK_CFG(0xFEDFFFC0, 0xFEDFFFD0, 0x000BFFE0, 16		),
NVM_BLK_CFG(0xFEDFFFE0, 0xFEDFFFE8, 0x000BFFF0, 8		),
NVM_BLK_CFG(0xFEDFFFF0, 0xFEDFFFF4, 0x000BFFF8, 4		),
NVM_BLK_CFG(0xFEDFFFF8, 0xFEDFFFFC, 0x000BFFFC, 4		)
};

#endif


/*******************************************************************************
	Function  Definition
*******************************************************************************/

/*@}*/

