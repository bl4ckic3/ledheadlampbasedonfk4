/*******************************************************************************
|  File Name:  kam.h
|  Description:  Keep Alive Memory define and handler
|-------------------------------------------------------------------------------
| (c) This software is the proprietary of Pan Asia Technical Automotive Company (PATAC). 
|     All rights are reserved by PATAC.
|-------------------------------------------------------------------------------
| Initials      Name                   Company
| --------      --------------------   -----------------------------------------
| XXX           XXXX                   PATAC
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date         Version    Author     Description
| ----------   --------   ------     -------------------------------------------
|2009-05-18  01.00.00     WH          Creation
|2009-07-02  01.00.01     WH          Add comments
|2009-07-24  01.00.02     WH          Add switch input edge event trigger
|2009-08-25  01.00.03     WH          Devide edge event trigger into two parts: rising edge and falling edge
|2009-11-16  01.00.04     WH          Add e_b_KamEnable in TeSW_CmmnSwMisc, that means try 
|                                                   to use KAM value when system reset occour.
|                                                   Delete SWCFG_DGTL_PASSTIM and e_w_PassTim in TeSW_DgtlSwInfo
|2010-04-22  01.01.00     WH     Add e_b_DisableCtrl flag, so other task can use this control bit to disable a switch handle.
|2011-08-10  02.00.00     WH     Revised for Clea+, autosar MCAL
|******************************************************************************/
#ifndef SWITCH_H
#define SWITCH_H

/*******************************************************************************
|    Other Header File Inclusion
|******************************************************************************/
//#include "Std_Types.h"
#include "Platform_Types.h"
#include "IoHwAb_SwitchCfg.h"
#include "IoHwAb_Private.h"
#include "Sys_QueueHandler.h"    /*use OS event*/
#include "Dio.h"
#include "Adc.h"
#include "Api_SchdTbl.h"

/*******************************************************************************
|    Compile Option or configuration Section (for test/debug)
|******************************************************************************/

/*Event ID is used by OS, it can be set to 16bit or 8bit due to OS config*/
#define OS_EVENTID_TYPE    uint16


/*API Configuration*/

#define ADC_CONF_VRH         5.0f    //ADC reference voltage high
#define ADC_CONF_VRL         0.0f    //ADC reference voltage low
#define ADC_CONF_RES         4095   //ADC resolution:  10bit = 1023, 12bit = 4095

#define ADC_CONF_TASKTIME    5    //ms, ADSW task time slice
#define SWCFG_DIGITAL_TASKSLICE  5   //ms, digital switch task time slice


#define INVALID_DTC_ID      0

#define SW_CHANNEL_TYPE_DIO       0
#define SW_CHANNEL_TYPE_SPI       1
#define SW_CHANNEL_TYPE_ADC       2

#define INVALID_EVENT_ID    0    /*invalid Event ID is zero because OS dummy event value is zero*/

/*A macro for calculate number of array members*/
#define LENGTH_OF_ARRAY(x)        ((sizeof (x)) / (sizeof ((x)[0])))

/*******************************************************************************
|    Macro Definition
|******************************************************************************/

#define IS_SW_PRSD(x)       VaSW_h_CmmnStat[x].Bits.e_b_SwPrsdFlt
#define IS_SW_SIG(x)       VaSW_h_CmmnStat[x].Bits.e_b_SwPrsdRaw   //ADD BY shiqs

#define VeSW_b_PrsdStatValid(x)   VaSW_h_CmmnStat[x].Bits.e_b_SwPrsdFltValid
#define IS_SW_LEARNED(x)       VaSW_h_CmmnStat[x].Bits.e_b_Learned

/*get the switch current pressed status, if not momentary switch, just filtered pressed signal, if momentary,
read toggle status*/
#define READ_SW_COMPOUND_SATUS(x) (KaSW_h_CmmnSwInfo[x].e_h_CmmnMisc.Bits.e_b_Momentary ?\
                                     VaSW_h_CmmnStat[x].Bits.e_b_TgglStat:\
                                     VaSW_h_CmmnStat[x].Bits.e_b_SwPrsdFlt)
                                     
/*******************************************************************************
|    Typedef Definition
|******************************************************************************/

/*switch fault failsoft actions:
| >: use history value as switch value
| >: use TRUE as switch value
| >: use FALSE as switch value
*/
typedef enum
{
    CeSW_FA_UseHstry,
    CeSW_FA_UseTrue,
    CeSW_FA_UseFalse
} TeSW_FaultActn;

typedef union
{
    uint8 Byte;
    struct
    {
        unsigned b1_Enabled      :1;   /*enabled/disabled this switch*/
        unsigned b1_PrsIsHigh     :1;  /*when switch pressed, port is high or low, this is for DIO type switches only */
        unsigned e_b_Momentary     :1;  /*momentary switch need no stuck diagnose*/
        unsigned e_b_InactvBfrUse  :1; /*for some switch, it will possibly always be stuck, 
                                   then we require to detect inactive signal first before thinking it is active*/
        unsigned e_b_DftVal            :1; /*default value when failsoft like stuck, short to ground/battery, etc.*/
        unsigned e_b_KamEnable    :1;  /*if enable, attempt to use KAM value first when system reset*/
        
        /*CeSW_u_WkupTyp...
        *0 - no wakeup port
        *1 - posedge wakeup (inactive->active)
        *2 - negedge wakeup (active->inactive)
        *3 - biedge wakeup (both edge)*/
        unsigned e_u2_WkupTyp     :2;  
    } Bits;
}  TeSW_CmmnSwMisc;

#define CeSW_u_WkupTypNoWkup    0 /*no wakeup or wakeup by interrupt */
#define CeSW_u_WkupTypPosEdge    1
#define CeSW_u_WkupTypNegEdge    2
#define CeSW_u_WkupTypBiEdge       3

/*switch common information -note: not support Failure type byte here!
|2010-5-14 comments: all DTC diagnostic is moved to DTC handler!here also do
|stuck diagnose
*/
typedef struct
{
    uint8 m_u_ChannelType; /*0-DIO channel, 1-SPI channel */
    uint8 m_u_ChannelId;  /*DIO channel ID, or spi channel ID offset*/

    /*Switches shall work in the range of battery voltage, if the switch is not feeded by
    |battery power, find the relation with battery voltage and convert it.
    |e_u_BatVoltLo - low limit, x10 scaled voltage, i.e. 10.2V -> 102
    |e_u_BatVoltHi - high limit, x10 scaled voltage, i.e. 10.2V -> 102
    |e_u_BatVoltErrAct - If switches leave the legal range, keep the value specified here.
    */
    uint8 e_u_BatVoltLo;
    uint8 e_u_BatVoltHi;
    uint8 e_u_BatVoltErrAct;  /*Use the value in TeSW_FaultActn, but declared as u8 */
    
    uint16 e_w_StckTim;         //ms, stuck time, if latched switch, this parameter is not used
    uint16 e_w_MaxPrsdTim;  //ms, max pressed time, stuck pending if time exceed. if latched switch, this parameter is not used
    uint8  e_u_DbcTim;       /*ms, debouce time*/
    TeSW_CmmnSwMisc e_h_CmmnMisc;   //mometary, inactive before use, default value 
    OS_EVENTID_TYPE m_t_EvtId_Chng;
    OS_EVENTID_TYPE m_t_EvtId_Press;   //event ID on switch rising edge, used by OS
    OS_EVENTID_TYPE m_t_EvtId_Release;  //event ID on switch falling edge, used by OS

    
}  TeSW_CmmnSwInfo;


#define SWCFG_CHANNEL_TYPE(x)   KaSW_h_CmmnSwInfo[x].m_u_ChannelType
#define SWCFG_CHANNEL_ID(x)       KaSW_h_CmmnSwInfo[x].m_u_ChannelId
#define SWCFG_BAT_VOLT_HIGH(x)  KaSW_h_CmmnSwInfo[x].e_u_BatVoltHi
#define SWCFG_BAT_VOLT_LOW(x)  KaSW_h_CmmnSwInfo[x].e_u_BatVoltLo
#define SWCFG_BAT_VOLT_ERRACT(x)  KaSW_h_CmmnSwInfo[x].e_u_BatVoltErrAct

#define SWCFG_ENABLED(x)             KaSW_h_CmmnSwInfo[x].e_h_CmmnMisc.Bits.b1_Enabled
#define SWCFG_PRS_IS_HIGH(x)      KaSW_h_CmmnSwInfo[x].e_h_CmmnMisc.Bits.b1_PrsIsHigh
#define SWCFG_INACTV_BFRUSE(x)    KaSW_h_CmmnSwInfo[x].e_h_CmmnMisc.Bits.e_b_InactvBfrUse
#define SWCFG_MOMENTARY(x)           KaSW_h_CmmnSwInfo[x].e_h_CmmnMisc.Bits.e_b_Momentary
#define SWCFG_DIAG_STUCK_EN(x)    KaSW_h_CmmnSwInfo[x].e_h_DiagEn.Bits.e_b_StckDiagEn

#define SWCFG_DBCTIME(x)               KaSW_h_CmmnSwInfo[x].e_u_DbcTim
#define SWCFG_STUCKTIME(x)             KaSW_h_CmmnSwInfo[x].e_w_StckTim
#define SWCFG_MAXPRSTIME(x)           KaSW_h_CmmnSwInfo[x].e_w_MaxPrsdTim
#define SWCFG_DEFAULT_VAL(x)         KaSW_h_CmmnSwInfo[x].e_h_CmmnMisc.Bits.e_b_DftVal
#define SWCFG_KAM_ENABLE(x)         KaSW_h_CmmnSwInfo[x].e_h_CmmnMisc.Bits.e_b_KamEnable
#define SWCFG_STCKDTC(x)                 KaSW_h_CmmnSwInfo[x].e_w_StckDtcId
#define SWCFG_EVENTID_CHANGE(x)   KaSW_h_CmmnSwInfo[x].m_t_EvtId_Chng
#define SWCFG_EVENTID_PRESS(x)   KaSW_h_CmmnSwInfo[x].m_t_EvtId_Press
#define SWCFG_EVENTID_RELEASE(x)   KaSW_h_CmmnSwInfo[x].m_t_EvtId_Release


typedef union
{
    uint8 Byte;
    struct
    {
        unsigned e_b_ShrtBat    :1;
        unsigned e_b_ShrtGnd   :1;
        unsigned e_b_OpenC     :1;    //open circuit
        unsigned e_b_Stck       :1;     /*stuck, over stuck time*/
        unsigned e_b_MaxPrsTim:1;  /*Over max press time*/
        unsigned e_b_IllglRng  :1;    //illegal range
        unsigned e_b_BVOR:1;   /*battery voltage out of range*/
    }  Bits;
}  TeSW_CmmnFailFlags;
#define SW_FAILTYPE_SHRTBAT    0x01
#define SW_FAILTYPE_SHRTGND    0x02
#define SW_FAILTYPE_OC    0x04
#define SW_FAILTYPE_STUCK    0x08
#define SW_FAILTYPE_ILLGRNG    0x10

/*digital switch diagnostic states*/
typedef enum
{
    SW_DIAG_NOT_READY,
    
    SW_DIAG_PASS_PENDING,
    SW_DIAG_PASS,
    
    SW_DIAG_STUCK_PENDING, 
    SW_DIAG_STUCK

} TeSW_DgtlDiagStat;


typedef union
{
    uint16 Word;
    struct
    {
        unsigned e_b_SwPrsdFlt       : 1; /*the SW is pressed after filtering*/
        unsigned e_b_SwPrsdFltValid :1; /*indicate if filtered value is valid*/
        unsigned e_b_SwPrsdFltLast   : 1; /*save last filtered status for judging toggle purpose*/
        unsigned e_b_SwPrsdRaw : 1;
        unsigned e_b_SwPrsdRawLast   : 1;  //last raw value

        unsigned e_b_DbcPass         :1;  //flag indicate switch level is debouced
        
        unsigned e_b_OnceInactv      :1; /* If the switch must wait for inactive first before
                                           thinking active is valid.  Save once inactive or not here */
        unsigned e_b_TgglStat        :1;   //toggle status, for momentary switch, press once, TRUE, press again, FALSE
        unsigned bSWJustPressed      :1; //this is for momentary switch, which acts after it is fully released, it should be reset by requster
        unsigned e_b_Learned         :1;  //set learned flag when input is determined first time when power up/wake up.

    } Bits;

}  TeSW_CmmnStat;

#define IS_SW_ONCEINACTV(x)       VaSW_h_CmmnStat[x].Bits.e_b_OnceInactv
#define IS_SW_DBCPASS(x)              VaSW_h_CmmnStat[x].Bits.e_b_DbcPass

#define CLR_SW_STAT(x)  { VaSW_h_CmmnStat[x].Word = 0x0000;}
#define SET_SW_LEARNED(x)  {VaSW_h_CmmnStat[x].Bits.e_b_Learned = 1;}
#define SET_SW_DBCPRSD(x)  {VaSW_h_CmmnStat[x].Bits.e_b_SwPrsdDbc = 1;}

#define GET_SW_DBCPASS(x)   VaSW_h_CmmnStat[x].Bits.e_b_DbcPass
#define SET_SW_DBCPASS(x)   {VaSW_h_CmmnStat[x].Bits.e_b_DbcPass = 1;}
#define CLR_SW_DBCPASS(x)   {VaSW_h_CmmnStat[x].Bits.e_b_DbcPass = 0;}

#define SET_SW_TOGGLE(x)    {VaSW_h_CmmnStat[x].Bits.e_b_TgglStat = 1;}
#define CLR_SW_TOGGLE(x)    {VaSW_h_CmmnStat[x].Bits.e_b_TgglStat = 0;}
#define TOGGLE_SW(x)    {VaSW_h_CmmnStat[x].Bits.e_b_TgglStat = !VaSW_h_CmmnStat[x].Bits.e_b_TgglStat;}

#define SET_SW_ONCEINACTV(x)    {VaSW_h_CmmnStat[x].Bits.e_b_OnceInactv = 1;}

#define SW_RAW(x)              VaSW_h_CmmnStat[x].Bits.e_b_SwPrsdRaw
#define SW_RAW_LAST(x)    VaSW_h_CmmnStat[x].Bits.e_b_SwPrsdRawLast

#define SW_FLT(x)              VaSW_h_CmmnStat[x].Bits.e_b_SwPrsdFlt
#define SW_FLT_LAST(x)    VaSW_h_CmmnStat[x].Bits.e_b_SwPrsdFltLast
#define SW_STATUS(x)    VaSW_h_CmmnStat[x].Word

/**************************************************************************
**          Can't Configurable Region     **
***************************************************************************/

typedef enum
{
    SW_ADDIAG_NOT_READY, 
    SW_ADDIAG_PASS,
    SW_ADDIAG_PASS_DELAY,
    SW_ADDIAG_FAIL,
    SW_ADDIAG_FAIL_DELAY
   
}  TeSW_AdDiagStat;

/*AD range failure flag is used for calibration.
|For indicating the purpose of define the range.
|Flag a debounced AD range with "illegal" if it is in a illegal range.
|x - TRUE(1) or FALSE(0)
*/
typedef union
{
    uint8 AllBits;
    struct
    {
        unsigned e_b_Illegal:1;    /*is it an illegal range?*/
        unsigned e_b_ShrtGnd:1;  /*is it a short to ground range?*/
        unsigned e_b_ShrtBat:1;   /*is it a short to battery range?*/
        unsigned e_b_OpenC:1;    /*is it a open circuit range?*/
    } Bits;
} TeSW_AdRngFFlg;
#define AdRng_Illegal(x)        (x)
#define AdRng_ShrtGnd(x)      ((x)<<1)
#define AdRng_ShrtBat(x)       ((x)<<2)
#define AdRng_OpenC(x)  ((x)<<3)


/*Create Log 20110822 wanghui: 
* this is a CAL attribution, indicating if it is a illegal range or normal range. 
*/
typedef enum
{
    CeIoHwAb_e_AdRangeNormal,    /*AD value is in normal range*/
    CeIoHwAb_e_AdRangeIllegal,      /*AD value is in illegal range*/
    CeIoHwAb_e_AdRangeShortGnd, /*AD value is in short to ground range*/
    CeIoHwAb_e_AdRangeShortBat,
    CeIoHwAb_e_AdRangeOpenLoad,
    CeIoHwAb_e_AdRangeOverLoad,
    CeIoHwAb_e_AdRangeNum
} TeSW_AdRangeType;

/*Change Log 20110822 wanghui: 
*(1) remove e_w_DtcCode, e_w_PassDelay and e_w_FailDelay because all DTCs is handlered by DTC module, 
*    in switch module, only error flags should be determined.
*(2) rename e_h_FFlg as m_h_AdRangeType, because this CAL is to indicate if it is a illegal range or normal range. 
*/
typedef struct
{
    uint16 wAD_Range_Low;   //the lower value of spefic AD Range, i.e. value within 0 ~ 1023
    uint16 wAD_Range_High;  //the upper value of spefic AD Range, i.e. value within 0 ~ 1023
    uint8 e_u_BitMask;           //List the switch combination to show which switch is active
    uint8 m_e_SwEnum;    /*convert AD range to enum switch value*/
    TeSW_AdRangeType m_e_AdRangeType;
}  TeSW_AdRngCal;


/*Change Log 20110822 wanghui: 
*(1) remove member e_u_SwNum because switches in one AD channel is enumed and end with a null switch, so 
*    size is no longer nessesary.
*(2) remove member e_w_DtcCode because all DTCs is handlered by DTC module, in switch module, only error
*    flags should be determined.
*(3) e_w_FailDelay and e_w_PassDelay are removed because change (2).
*(4) e_p_RngDiagStat and e_p_RngDiagTimer are removed because change (2).
*/
typedef struct
{
    /*The AD value ready status is not considered here, because its ready latency after startup is very short.
    And the Ad sample should be run conitnuously at background*/
    uint16 *mp_w_AdRaw;             /*point to RAM where store the sampled AD sw input value */
    uint16 e_w_SrcVoltRef;        /*this is the standard AD value assumed as the pull up source, for example, 
    5V or 12V, please up scaled by 100 times*/
    uint16 *e_p_SrcVolt; /*point to RAM where store the sampled ref pull up voltage value,  up scaled by 
    100 */
    const uint8 *e_p_SwId;        /*first switch in the list of Input_Switches_t, others must be just next to this one*/
    TeSW_AdRngCal const * e_p_AdRngCal; /*point to mapping info array*/
    uint8 e_u_RngArrSize;           /*total number of AD switch mapping information, dimension of the array*/
    uint16 e_w_SwDbcTime;        /*the debouce time to take input as stable status, in ms*/
    
    const OS_EVENTID_TYPE e_t_EvntId_RngChng;    //range change event ID
    //const OS_EVENTID_TYPE *e_t_EvntId_RngChng;    //range change event ID
    
}  TeADSW_GrupInfo;


#define SWCFG_ADGRUP_PASSPNDNG_TIME(x)   KaADSW_h_GrupInfo[x].e_w_PassPendingTime
#define SWCFG_ADGRUP_DBC_TIME(x)                KaADSW_h_GrupInfo[x].e_w_SwDbcTime

#define SWCFG_ADRNG_SIZE(groupId)         KaADSW_h_GrupInfo[groupId].e_u_RngArrSize


#define SWCFG_ADGRUP_EVENTID_RNGCHNG(groupId)    KaADSW_h_GrupInfo[groupId].e_t_EvntId_RngChng
#define SWCFG_ADGRUP_EVENTID_RNGCHNG_ARR(groupId, EvtId)    KaADSW_h_GrupInfo[groupId].e_t_EvntId_RngChng[EvtId]



/*AD range ID data structure*/
typedef struct
{
    uint8 m_u_PrevAdRangeId;   /*AD range id raw value in previous task cycle*/
    uint8 m_u_AdRangeId_Flt;    /*AD range id filtered value in current task cycle*/
}  TeADSW_GrupStat;


/*******************************************************************************
|    Global Variables with extern linkage 
|******************************************************************************/
extern TeADSW_GrupStat VaADSW_h_GrupStat[SWGRUP_NUM];
extern TeSW_CmmnStat VaSW_h_CmmnStat[SWID_NUM];
extern TeSW_CmmnFailFlags VaSW_h_CmmnFFlg[SWID_NUM];
extern uint8 VaSW_u_OBDIStat[(OBDI_Num+7)/8];
extern uint16 VeSW_w_BatVoltRef;

#if 0
/*uOBDI_ID*/
#define GetOBDI_Stat(uOBDI_ID)  Read_Buf_Bit(VaSW_u_OBDIStat,uOBDI_ID)
/*uOBDI_ID- 
*bVal - TRUE/FALSE
*/
#define SetOBDI_Stat(uOBDI_ID, bVal)  Ctrl_Buf_Bit(VaSW_u_OBDIStat,uOBDI_ID,bVal)

#endif

#define CAL_START_CAL1_SECT
#include "MemMap.h"

extern const TeADSW_GrupInfo KaADSW_h_GrupInfo[SWGRUP_NUM];
extern const  TeSW_CmmnSwInfo  KaSW_h_CmmnSwInfo[SWID_NUM];
extern const TeSW_h_OBDIInfo KaSW_h_OBDIInfo[OBDI_Num];

#define CAL_STOP_CAL1_SECT
#include "MemMap.h"

//#pragma DATA_SEG RUN_KAM
extern TeSW_CmmnStat RaSW_h_CmmnStat[SWID_NUM];
//#pragma DATA_SEG DEFAULT



/*******************************************************************************
|    Global Function Prototypes 
|******************************************************************************/

void InitSW_OnSysRst(void);
void ResetSW_DiagStat(void);
void SavSW_PreSysSleep(void);
void SwtAb_Handler(void);
uint8 ScanSW_WkupPort(void);

#endif

