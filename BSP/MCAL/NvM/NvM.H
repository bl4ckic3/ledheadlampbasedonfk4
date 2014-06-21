/**
	\addtogroup MODULE_NvM NvM
	Non-volatile Memory Management Module.
*/
/*@{*/
/***************************************************************************//**
	\file		NvM.h
	\brief		Type and API declaration of Non-volatile Memory Management Module.
	\author		lsf
	\version	1.0
	\date		2012-3-29
	\warning	Copyright (C), 2012, PATAC.
*//*----------------------------------------------------------------------------
	\history
	<No.>	<author>	<time>		<version>	<description>
	1		lsf			2012-3-29	 1.0			Create	
*******************************************************************************/
#ifndef _NVM_H
#define _NVM_H

/*******************************************************************************
	Include Files
*******************************************************************************/
#include "Std_Types.h"
#include "NvM_Cfg.h"

/*******************************************************************************
	Macro Definition
*******************************************************************************/
#define NVM_BLOCK_WRITE_BLOCK_ONCE_ON (uint8)1

//todo
#define NvM_Appl_DemBlock 0xF8


/*the result of request*/
#define NVM_REQ_OK                 (uint8)0
#define NVM_REQ_NOT_OK             (uint8)1
#define NVM_REQ_PENDING            (uint8)2
#define NVM_REQ_INTEGRITY_FAILED   (uint8)3
#define NVM_REQ_BLOCK_SKIPPED      (uint8)4
#define NVM_REQ_NV_INVALIDATED     (uint8)5
#define NVM_REQ_CANCELLED          (uint8)6  
#define NVM_VENDOR_ID              (30u)
#define NVM_MODULE_ID              (20u)
#define NVM_INSTANCE_ID            (0u)

/*def Service ID,the service type of function*/
#define NVM_INIT                   (0u) /* Service ID NvM_Init()              */
#define NVM_SET_DATA_INDEX         (1u) /* Service ID NvM_SetDataIndex()      */
#define NVM_GET_DATA_INDEX         (2u) /* Service ID NvM_GetDataIndex()      */
#define NVM_AR_MAJOR_VERSION       (2u)
#define NVM_AR_MINOR_VERSION       (2u)
#define NVM_AR_PATCH_VERSION       (0u)
#define NVM_SET_BLOCK_PROTECTION   (3u) /* Service ID NvM_SetBlockProtection()*/
#define NVM_GET_ERROR_STATUS       (4u) /* Service ID NvM_GetErrorStatus()    */
#define NVM_SET_RAM_BLOCK_STATUS   (5u) /* Service ID NvM_SetRamBlockStatus() */
#define NVM_READ_BLOCK             (6u) /* Service ID NvM_ReadBlock()         */
#define NVM_WRITE_BLOCK            (7u) /* Service ID NvM_WriteBlock()        */
#define NVM_RESTORE_BLOCK_DEFAULTS (8u) /* Service ID NvM_RestoreBlockDefaults()*/
#define NVM_ERASE_BLOCK            (9u) /* Service ID NvM_EraseNvBlock()      */
#define NVM_INVALIDATE_NV_BLOCK   (11u) /* Service ID NvM_InvalidateNvBlock() */
#define NVM_READ_ALL              (12u) /* Service ID NvM_ReadAll()           */
#define NVM_WRITE_ALL             (13u) /* Service ID NvM_WriteAll()          */
#define NVM_MAINFUNCTION          (14u) /* Service ID NvM_MainFunction()      */
#define NVM_GET_VERSION_INFO      (15u) /* Service ID NvM_GetVersionInfo()    */
#define NVM_SET_BLOCK_LOCK_STATUS (16u) /* Service ID NvM_SetBlockProtection()*/   
	
/*def ALL_SET,Set Flag of All Write/ All Read / Cancel All*/
#define NVM_APIFLAG_READ_ALL_SET       0x01
#define NVM_APIFLAG_READ_ALL_CL        0xFE
#define NVM_APIFLAG_WRITE_ALL_SET      0x02
#define NVM_APIFLAG_WRITE_ALL_CL       0xFD
#define NVM_APIFLAG_CANCEL_WR_ALL_SET  0x04
#define NVM_APIFLAG_CANCEL_WR_ALL_CL   0xFB
	
/*def STATE_SET,Set Status of Block	*/
#define NVM_WR_PROT_SET                 0x01
#define NVM_WR_PROT_CL                  0xFE
#define NVM_STATE_CHANGED_SET           0x02
#define NVM_STATE_CHANGED_CL            0xFD
#define NVM_LOCK_STAT_SET               0x04
#define NVM_LOCK_STAT_CL                0xFB
#define NVM_STATE_VALID_SET             0x08
#define NVM_STATE_VALID_CL              0xF7  

/*******************************************************************************
	Type Definition
*******************************************************************************/
/**
	\typedef uint16 NvM_BlockIdType
	Block ID type.
*/
typedef uint16 NvM_BlockIdType;

/**
	\enum NvM_BlockError_Type
	The Block Error or Status
*/
typedef enum
{
	NVM_E_NOT_INITIALIZED		 = 0x14,
	NVM_E_BLOCK_PENDING          = 0x15,
	NVM_E_LIST_OVERFLOW          = 0x16,
	NVM_E_NV_WRITE_PROTECTED     = 0x17,
	NVM_E_BLOCK_CONFIG           = 0x18,
	NVM_E_PARAM_BLOCK_ID		 = 0x0A,
	NVM_E_PARAM_BLOCK_TYPE       = 0x0B,
	NVM_E_PARAM_BLOCK_DATA_IDX   = 0x0C,
	NVM_E_PARAM_BLOCK_ADDRESS    = 0x0D,
	NVM_E_PARAM_DATA             = 0x0E
}NvM_BlockError_Type;

/**
	\struct RamBlock_t
	RamBlock attribute.
*/
typedef struct
{
	uint8      NvRamErrorStatus;
	uint8      NvDataIndex;
	uint8      NvRamAttributes;
	uint8      WriteNvRamOnce;
	uint8*     RamBlockDataAddr;
	uint8      DeviceId;
	uint16	   Length;
	uint16 	   BlockId;
    uint16     ServiceId;
	uint16	   BlockOffset;
} RamBlock_t;

/**
	\struct NvM_Config_t
	Link-time Configuration.
*/
typedef struct{
	uint8*	RamAddr1;	/**<RAM Mapping Address1 */
	uint8*	RamAddr2;	/**<RAM Mapping Address2 */
	uint8*	RomAddr;	/**<ROM Address(Default Value) */
	uint16	Length;		/**<Block Length */
} NvM_Config_t;

typedef uint8 NvM_RequestResultType;
//typedef uint16 NvM_BlockIdType;
#define NvM_Appl_NvmBlock1 (0)
#define NvmBlockDescriptor (1)
#define NVM_PUBLIC_CODE
//#define NVM_REQ_OK               (0u)  /* The last asynchronous request has been finished successfully */
//#define NVM_REQ_NOT_OK           (1u)  /* The last asynchronous request has been finished unsuccessfully */
//#define NVM_REQ_PENDING          (2u)  /* An asynchronous request is currently being processed */
//#define NVM_REQ_INTEGRITY_FAILED (3u)  /* Result of the last NvM_ReadBlock or NvM_ReadAll is an integrity failure */
//#define NVM_REQ_BLOCK_SKIPPED    (4u)  /* The referenced block was skipped during a multi block request */
//#define NVM_REQ_NV_INVALIDATED   (5u)  /* The NV block is invalidated. */
#define NVM_WRITE_ALL             (13u) /* Service ID NvM_WriteAll() */
/*******************************************************************************
	Prototype  Declaration
*******************************************************************************/
extern uint8 NvM_RWC_Flags;
extern RamBlock_t  NvM_BlockMngmtArea[BLOCK_TOTAL];
extern const NvM_Config_t NvM_Config[]; 

extern void NvM_Init(void); 
extern void NvM_SetDataIndex( uint16 BlockId, uint8 DataIndex );
extern void NvM_GetDataIndex( uint16 BlockId, uint8* DataIndexPtr );
extern void NvM_SetBlockProtection( uint16 BlockId, boolean ProtectionEnabled );
extern void NvM_GetErrorStatus( uint16 BlockId, uint8* RequestResultPtr );
extern void NvM_SetRamBlockStatus( uint16 BlockId, boolean BlockChanged );
extern Std_ReturnType NvM_ReadBlock( uint16 BlockId, uint8* NvM_DstPtr );
extern Std_ReturnType NvM_WriteBlock( uint16 BlockId, uint8* NvM_SrcPtr );
extern Std_ReturnType NvM_RestoreBlockDefaults( uint16 BlockId, uint8* NvM_DestPtr );
extern Std_ReturnType NvM_EraseNvBlock( uint16 BlockId );
extern Std_ReturnType NvM_InvalidateNvBlock( uint16 BlockId );
extern void NvM_CancelWriteAll( void );
extern void NvM_ReadAll( void );
extern void NvM_WriteAll ( void );
extern void NvM_MainFunction(void);

#endif /*  #ifndef _NvM_H */
/*@}*/
