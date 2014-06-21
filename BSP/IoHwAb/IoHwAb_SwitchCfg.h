/*****************************************************************************
|File Name:  SwitchDef.h
|
|Description:  Switch enumation definition here and interface provide here
|
|-----------------------------------------------------------------------------
|               PATAC Confidential
|-----------------------------------------------------------------------------
|
| This software is copyright is proprietary of Pan Asia Technical Automotive Company(PATAC). 
| All rights are reserved by PATAC.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials      Name                   Company
| ------------------------------------   ---------------------------------------
|
|
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date            Version       Author     Description
|----------  --------  ------  ----------------------------------------------
|2009-09-16  01.00.00     FRED        Creation
*****************************************************************************/
#ifndef __SWITCH_DEF_H
#define __SWITCH_DEF_H


/******************************************************************************
 * Inclusion of Other Header Files
 *****************************************************************************/
//#include "Std_Types.h"


/******************************************************************************
 * Configure Region - optional header file according to config requirements
 *****************************************************************************/
#include "Sys_QueueHandler.h"    /*if use OS event*/
#include "Dio.h"
#include "IoHwAb_Adc.h"
//#include "Api_SchdTbl.h"

/*******************************************************************************
|    Macro Definition
|******************************************************************************/
#define TAPUP_ON_ACTIVE   0x01
#define TAPDN_ON_ACTIVE   0x02
#define TAPONOFF_ACTIVE    0x04



/*******************************************************************************
|    Enum Definition
|******************************************************************************/

/*define an analog switch, first step is to define group name here */
typedef enum
{
    SWGRUP_REARWIP,
    SWGRUP_WIPER,
    SWGRUP_STE1,
    SWGRUP_STE2,
    SWGRUP_HOOD,
    SWGRUP_IA1,
    SWGRUP_NUM

}  TeADSW_GrupId;

/*define at least one digital switch and one analog switch!!
* if no switches needed, you can define a dummy digital switch and a dummy analog switch*/

typedef enum
{
    SWID_IDL0,
    SWID_IDL1,
    SWID_IDL2,
    SWID_IDL3,
    SWID_IDL4,
    SWID_IDL5,
    SWID_IDL6,
    SWID_IDL7,
    SWID_IDL8,
    SWID_IDL9,
    SWID_IDL10,
    SWID_IDL11,
    SWID_IDL12,
    SWID_IDL13,
    SWID_IDL14,
    SWID_IDL15,
    SWID_IDL16,
    SWID_IDL17,
    SWID_IDL18,
    SWID_IDL19,
    SWID_IDL20,
    SWID_IDL21,
    SWID_IDL22,
    SWID_IDL23,
    SWID_IDL24,
    SWID_IDL25,
    SWID_IDL26,
    SWID_IDL27,
    SWID_IDL28,
    SWID_IDL29,
    SWID_IDL30,
    SWID_IDL31,
    SWID_IDL32,
    SWID_IDL33,
    SWID_IDL34,
    SWID_IDL35,
    SWID_IDL36,
    SWID_IDL37,
    SWID_IDL38,
    SWID_IDL39,
    SWID_IDL40,
    SWID_IDL41,
    SWID_IDL42,
    SWID_IDL43,
    SWID_IDL44,
    SWID_IDL45,
    SWID_IDL46,
    SWID_IDL47,
    SWID_IDH0,
    SWID_IDH1,
    SWID_IDH2,
    SWID_IDH3,

    /*Start AD switch define*/
    SWID_TAPON,
    SWID_TAPUP,
    SWID_TAPDN,
    SWID_CRUISEON,
    SWID_CRUISESET,
    SWID_CRUISERES,
    SWID_CRUISECAN,
    SWID_WIPER_1,
    SWID_WIPER_2,
    SWID_WIPER_3,
    SWID_WIPER_4,
    SWID_WIPER_5,
    SWID_WIPER_6,
    SWID_WIPER_7,
    SWID_NUM
}
TeHWIO_e_InputId;

#define SWID_RSRVED SWID_NUM 
#define CeIoHwAb_e_SwIdNull SWID_NUM

/*On board digital in
* Reflect the raw input value. no debounce.
* define board internal digital input here.
*/
typedef enum
{
    OBDI_H_PWM_DIAG_0,
    OBDI_H_PWM_DIAG_1,
    OBDI_H_PWM_DIAG_2,
    OBDI_rsv03,
    OBDI_L_PWM_DIAG_0,
    OBDI_rsv05,
    OBDI_rsv06,
    OBDI_rsv07,
    
    OBDI_L_DO_DIAG_0,
    OBDI_L_DO_DIAG_1,
    OBDI_rsv12,
    OBDI_L_DO_DIAG_11,
    OBDI_rsv14,
    OBDI_HSD_Diag_DO0,
    OBDI_HSD_Diag_DO1,
    OBDI_rsv17,

    OBDI_rsv20,
    OBDI_rsv21,
    OBDI_rsv22,
    OBDI_rsv23,
    OBDI_rsv24,
    OBDI_rsv25,
    OBDI_rsv26,
    OBDI_rsv27,
    
    OBDI_Diag_ACC,
    OBDI_Diag_RUN_RELAY,
    OBDI_Diag_RAP_RELAY,
    OBDI_Diag_Left_Turn_FB,
    OBDI_Diag_Right_Turn_FB,
    OBDI_rsv35,
    OBDI_rsv36,
    OBDI_rsv37,
    
    OBDI_Num,
    /*note OBDI_NULL is not a valid ID*/
    OBDI_NULL = OBDI_Num
}  TeSW_OBDI;


typedef struct
{
    boolean e_b_Enable;
    uint8 * e_p_Port;
    uint8 e_u_Offset;
} TeSW_h_OBDIInfo;

/******************************************************************************
 * Object Declarations and Inline Function Definitions
 *****************************************************************************/
#define SetSW_Event(x)    EVENTQUEUE_PUSH((OS_EVENTID_TYPE)(x));


/******************************************************************************
 * Configure AD swith AD sample buffer source
 *****************************************************************************/
 #define ADSW_SAM_BUF_TUTD    &VeIoHwAb_w_AdcResultBuffer[0]
 #define ADSW_SAM_BUF_REARWIP    &VeIoHwAb_w_AdcResultBuffer[5]
 #define ADSW_SAM_BUF_WIPR    &VeIoHwAb_w_AdcResultBuffer[4]
 #define ADSW_SAM_BUF_IGN    &VeIoHwAb_w_AdcResultBuffer[6]
 #define ADSW_SAM_BUF_STE1    &VeIoHwAb_w_AdcResultBuffer[7]
 #define ADSW_SAM_BUF_STE2    &VeIoHwAb_w_AdcResultBuffer[10]
 #define ADSW_SAM_BUF_HOOD    &VeIoHwAb_w_AdcResultBuffer[3]
 #define ADSW_SAM_BUF_IA1    &VeIoHwAb_w_AdcResultBuffer[1]
  
/******************************************************************************
 * Configure AD swith reference voltage source
 *****************************************************************************/
#define ADSW_REF_ADDR_TUTD    &VeIoHwAb_w_BatteryVoltage
#define ADSW_REF_ADDR_REARWIP    &VeIoHwAb_w_BatteryVoltage
#define ADSW_REF_ADDR_WIPR    &VeIoHwAb_w_BatteryVoltage
#define ADSW_REF_ADDR_IGN      &VeIoHwAb_w_BatteryVoltage
#define ADSW_REF_ADDR_STE1    &VeIoHwAb_w_BatteryVoltage    /*Steering Wheel Control Switch 1*/
#define ADSW_REF_ADDR_STE2    &VeIoHwAb_w_BatteryVoltage    /*Steering Wheel Control Switch 2*/
#define ADSW_REF_ADDR_HOOD    &VeIoHwAb_w_BatteryVoltage
#define ADSW_REF_ADDR_IA1     &VeIoHwAb_w_BatteryVoltage

/******************************************************************************
 * Configure AD swith enum list, note: not all AD switch need enum value, refer to APP-RTE interface requirements.
 *****************************************************************************/

#define ADSW_ENUM_UNDEF 0    /*if AD switch enum value undefined, */

/*Tap Up Tap Down Switch Enum Value, , should be same as model enum*/
typedef enum
{
    CeTRS_e_TutdSwOn,
    CeTRS_e_TutdSwOff,
    CeTRS_e_TutdSwUp,
    CeTRS_e_TutdSwDown,
    CeTRS_e_TutdSwErr

} ADSW_ENUM_TUTD;

/*Cruise Control Switch Enum Value, should be same as model enum*/
typedef enum
{
    CeCRUZ_e_SwIndtrmnt,
    CeCRUZ_e_SwOpenShrtToGnd,
    CeCRUZ_e_SwCancel,
    CeCRUZ_e_SwOff,
    CeCRUZ_e_SwOn,
    CeCRUZ_e_SwResume,
    CeCRUZ_e_SwSet,
    CeCRUZ_e_SpdLimWrnOn,
    CeCRUZ_e_SwErr,
    CeCRUZ_e_SwShrtToPwr
} ADSW_ENUM_CRUS;

/*DIM/FOG Switch Enum Value, should be same as model enum*/
typedef enum
{
    CeILS_e_DimmingDec,
    CeILS_e_DimmingInc,
    CeELS_e_FogFront,
    CeELS_e_FogRear,
    CeLS_e_NULL
} ADSW_ENUM_IA1;

/*Wiper Switch Enum Value, should be same as model enum*/
/*typedef enum
{
    CeWIP_e_FtWipersOff,
    CeWIP_e_FtIntermittent,
    CeWIP_e_FtLowSpeed,
    CeWIP_e_FtHighSpeed,
    CeWIP_e_FtWiperSwFault
} ADSW_ENUM_WIPR;
*/

#if 0 //delete by shiqs
/*Wiper Switch Enum Value, should be same as model enum*/
typedef enum
{
    CeWIP_e_RrWipLow,
    CeWIP_e_RrWipInt,
    CeWIP_e_RrWshOn,
    CeWIP_e_RrWshWipOff
} ADSW_ENUM_REAR_WIPR;

/*Front Wiper Switch Enum Value, should be same as model enum*/
typedef enum
{
    CeWIP_e_FrtWipLow,
    CeWIP_e_FrtWipInt1,
    CeWIP_e_FrtWipInt2,
    CeWIP_e_FrtWipInt3,
    CeWIP_e_FrtWipInt4,
    CeWIP_e_FrtWipInt5,
    CeWIP_e_FrtWipOff,
    CeWIP_e_FrtWipFault
} ADSW_ENUM_FRONT_WIPR;

/*Wiper intermittent Switch Enum Value, should be same as model enum*/
/*typedef enum
{
    CeWIP_e_Intermittent1 = 5,
    CeWIP_e_Intermittent2,
    CeWIP_e_Intermittent3,
    CeWIP_e_Intermittent4,
    CeWIP_e_Intermittent5

} ADSW_ENUM_WIPR_INT;
*/
/*Steering Wheel Control Switch Enum Value, should be same as model enum*/
typedef enum
{
    CeSWC_e_SwtFltIndtrmnt,
    CeSWC_e_SwtFltNoActtn,
    CeSWC_e_SwtFltFct1,
    CeSWC_e_SwtFltFct2,
    CeSWC_e_SwtFltFct3,
    CeSWC_e_SwtFltFct4,
    CeSWC_e_SwtFltFct5,
    CeSWC_e_SwtFltFct6,
    CeSWC_e_SwtFltFct7,
    CeSWC_e_SwtFltFct8,
    CeSWC_e_SwtFltFct9,
    CeSWC_e_SwtFltFct10,
    CeSWC_e_SwtFltFct11,
    CeSWC_e_SwtFltFct12,
    CeSWC_e_SwtFltFct13,
    CeSWC_e_SwtFltFct14,
    CeSWC_e_SwtFltFct15,
    CeSWC_e_SwtFltOpenShrtToGnd,
    CeSWC_e_SwtFltBtwnRng,
    CeSWC_e_SwtFltShrtToPwr

} ADSW_ENUM_STE;
#endif

/******************************************************************************
 * Function:     
 * Description:  
 *****************************************************************************/

/******************************************************************************
 * Function Declarations
 *****************************************************************************/





#endif

/*EOF*/

