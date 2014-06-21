/*****************************************************************************
|    File Name:  ApiAlarmHandler.h
|
|  Description:  Alarm Handler Header
|
|-----------------------------------------------------------------------------
|               PATAC Confidential
|-----------------------------------------------------------------------------
|
| This software is copyright is proprietary of
| Pan Asia Technical Automotive Company(PATAC). 
| All rights are reserved by PATAC.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials      Name                   Company
| --------      --------------------   ---------------------------------------
| FRED        Wang Wanrong     PATAC
|
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author     Description
| ----------  --------  ------  ----------------------------------------------
| 2009-1-30  01.00.00  FRED   Creation
| 2009-8-10  01.01.00  FRED   Add ContinueKERNEL_Alarm, ReStartKERNEL_Alarm;
|****************************************************************************/
#ifndef __API_ALARM_HANDLER_H__
#define __API_ALARM_HANDLER_H__

#include "platform_types.h"

#define ADOPT_UINT16_FOR_ALARM_ID

#if defined(ADOPT_UINT8_FOR_ALARM_ID) && defined(ADOPT_UINT16_FOR_ALARM_ID)
#error "Can't define both type for Alarm ID"
#elif defined ADOPT_UINT8_FOR_ALARM_ID
#define AlarmIDType UINT8
#elif defined ADOPT_UINT16_FOR_ALARM_ID 
#define AlarmIDType UINT16
#else
#error "A type must be defined for Alarm ID"
#endif

#ifdef  __16_BIT_MCU

#define AlmTickType UINT16 /*for 16bit data, the max value is about 1minute,when 1 tick is 1ms*/

#elif defined __32_BIT_MCU

#define AlmTickType UINT32 /*for 32bit data, the max value is about 49day,when 1 tick is 1ms*/

#else 

#error "can't support this type of MCU"

#endif

#define EN_HASH
#define EN_ELAPSTM
#define EN_DEBUG

/*macro function define*/
#define StartTm(event , duration , cycle)   StartGeneralTm(event , duration , cycle, UNIT_MS)
#define StartTm_L(event , duration , cycle)   StartGeneralTm(event , duration , cycle, UNIT_0P1S)

#define StopTm(event)             StopGeneralTm(event)
#define StopTm_L(event)             StopGeneralTm(event)

#define TmRmnd(event)         TmRmndGeneral(event, UNIT_MS)
#define TmRmnd_L(event)         TmRmndGeneral(event, UNIT_0P1S)
#ifdef EN_ELAPSTM
#define TmElspd(event)        TmElspdGeneral(event, UNIT_MS)
#define TmElspd_L(event)        TmElspdGeneral(event, UNIT_0P1S)
#endif
#define IsTmActv(event)       IsTmActvGeneral(event)
#define IsTmActv_L(event)       IsTmActvGeneral(event)

typedef enum
{
    ONE_SNAPSHOT_ALARM = 0, /**< Indicates the alarm is one snapshot.  */
    CYCLIC_ALARM    /* Indicates the alarm is cyclic.   */
}ALARM_TYPE;

typedef enum
{
    UNIT_MS = 0,/*unit in millisecond*/
    UNIT_0P1S,/*unit in 0.1second*/

    UNIT_NUM
}tALARM_UNIT;


#ifdef EN_DEBUG
enum
{
    ALMERR_OK = 0,
    ALMERR_ALMOVFL,
    ALMERR_NOALLOCATEALM,
};


extern UINT8 AlmErrCode;
extern UINT8 AlmMaxUseNum;
extern UINT8 AlmCurUseNum;
#endif
/**
 * Function declaration.
 */
void SysSrvc_InitFreeAlmQ(void);
 
void StartGeneralTm( const UINT16 event , const UINT16 duration , const BOOL cycle ,const UINT8 unit);
void StopGeneralTm( const UINT16 event ); 

UINT16 TmRmndGeneral( const UINT16 event , const UINT8 unit);
#ifdef EN_ELAPSTM
UINT16 TmElspdGeneral( const UINT16 event ,const UINT8 unit);
#endif
BOOL IsTmActvGeneral( const UINT16 event );

#endif
