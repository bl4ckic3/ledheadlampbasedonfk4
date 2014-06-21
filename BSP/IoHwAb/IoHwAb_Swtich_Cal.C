/*****************************************************************************
|    File Name:  Switch_Cal.c
|
|  Description:  cal variables for Swtich
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
| Wanrong                             PATAC
|
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author     Description
| ----------  --------  ------  ----------------------------------------------
| 2009-9-16  01.00.00  Wanrong   Creation
|2011-08-10  02.00.00  wanghui     Revised for Clea+, autosar MCAL
|****************************************************************************/

/******************************************************************************
 * Inclusion of Common Typedef Names and Libraries
 *****************************************************************************/


/******************************************************************************
 * Inclusion of Other Header Files
 *****************************************************************************/
//#include "Std_Types.h"
#include "IoHwAb_Switch.h"
#include "pn_event_queue.h"
#include "wip_rte_types.h"
#include "swc_rte_types.h"

/*******************************************************************************
|    Macro Definition
|******************************************************************************/
#define SetSW_Enable(x)              ((x)<<0)
#define SetSW_PrsIsHigh(x)         ((x)<<1)
#define SetSW_Momentary(x)       ((x)<<2)
#define SetSW_InactvBfrUse(x)   ((x)<<3)
#define SetSW_DeftVal(x)             ((x)<<4)
#define SetSW_UseKam(x)            ((x) <<5)
#define SetSW_WkupTyp(x)          ((x)<<6)

/*Calibrate battery voltage
|x - battery voltage, range 0~25.5f
*/
#define CalSW_BatVolt(x)    ((x)*10)


/******************************************************************************
 * Typedef Name Declarations, Object-Like Macros, and Function Declarations
 *****************************************************************************/

/*get ADC raw value by physical voltage
* INPUT: x - volate, i.e. 5.0 (5.0 V)
*/
#define GetADSW_w_RawByVolt(x)  (uint16)((x) * ADC_CONF_RES/ADC_CONF_VRH)

/*get ADC cooked value by physical voltage
* INPUT: x - volate, i.e. 5.0 (5.0 V)
*/
#define GetADSW_w_CookByVolt(x)  (x * 100)    //cook value is physical value multi 100

/*convert debouce time from ms to time counter for software query
* INPUT: x - time, i.e. 100 (100ms)
*/
#define GetADSW_w_CntByTime(x)   ((x)/ADC_CONF_TASKTIME)

#define GetDGSW_w_CntByTime(x)   ((x)/SWCFG_DIGITAL_TASKSLICE)

#define VaADSW_RawInput    

/******************************************************************************
 *      
 * Global Variables Definition
 *****************************************************************************/



#define CAL_START_CAL1_SECT
#include "MemMap.h"

const  TeSW_CmmnSwInfo  KaSW_h_CmmnSwInfo[SWID_NUM] =
{
    /*SWID_IDL0*/
    {
        SW_CHANNEL_TYPE_SPI,
        7,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_FtpFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL1*/
    {
        SW_CHANNEL_TYPE_SPI,    
        6,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_ManualParklampFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL2*/
    {
        SW_CHANNEL_TYPE_SPI,    
        5,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_HazardFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID      
    },
    /*SWID_IDL3*/
    {
        SW_CHANNEL_TYPE_SPI,
        4,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_DefeatCtrl_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL4*/
    {
        SW_CHANNEL_TYPE_SPI,    
        3,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_CtsyLmpUser_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL5*/
    {
        SW_CHANNEL_TYPE_SPI,    
        2,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_DrvCrtsySwUnlockFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID     
    },
    /*SWID_IDL6*/
    {
        SW_CHANNEL_TYPE_SPI,
        1,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
     Evt_DrvCrtsySwLockFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL7*/
    {
        SW_CHANNEL_TYPE_SPI,    
        0,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       INVALID_EVENT_ID ,    
        Evt_RearClsr_JstOpn,//Evt_Trunk_JstOpn,
Evt_RearClsr_JstClsd//Evt_Trunk_JstClsd
               
    },
      /*SWID_IDL8*/
    {
        SW_CHANNEL_TYPE_SPI,    
        15,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_ExtRcRelSwFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID     
    },
     /*SWID_IDL9*/
    {
        SW_CHANNEL_TYPE_SPI,
        14,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        INVALID_EVENT_ID,    
        Evt_DrvKeyCylLockFlt_Chg,
         Evt_DrvKeyCylUnlockFlt_Chg
               
    },
      /*SWID_IDL10*/
    {
        SW_CHANNEL_TYPE_SPI,    
        13,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_IntRcRelSwFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL11*/
    {
        SW_CHANNEL_TYPE_SPI,    
        12,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE)+ 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_FTHiMdFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID       
    },
    /*SWID_IDL12*/
    {
        SW_CHANNEL_TYPE_SPI,
        11,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_ManualHeadlampFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL13*/
    {
        SW_CHANNEL_TYPE_SPI,    
        10,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
      Evt_HornPadFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL14*/
    {
        SW_CHANNEL_TYPE_SPI,    
        9,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        INVALID_EVENT_ID,//Evt_RfaLock_Req ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID      
    },
    /*SWID_IDL15*/
    {
        SW_CHANNEL_TYPE_SPI,
        8,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
      INVALID_EVENT_ID,
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL16*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel0_0,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_CtdGlassBrkFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
/*SWID_IDL17*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel2_2,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        INVALID_EVENT_ID ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
    /*SWID_IDL18*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel0_15,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_NgtPnlSw_Chg,
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
    /*SWID_IDL19*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel0_2,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       INVALID_EVENT_ID,
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
       /*SWID_IDL20*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel1_6,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        INVALID_EVENT_ID ,    
        INVALID_EVENT_ID ,//Evt_DoorDrv_JstOpn,
         INVALID_EVENT_ID ,//Evt_DoorDrv_JstClsd
              
    },
/*SWID_IDL21*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel10_15,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        INVALID_EVENT_ID ,    
        INVALID_EVENT_ID ,//Evt_DoorPas_JstOpn,
        INVALID_EVENT_ID ,//Evt_DoorPas_JstClsd
              
    },
    /*SWID_IDL22*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel1_5,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       INVALID_EVENT_ID ,    
        INVALID_EVENT_ID ,//Evt_DoorLR_JstOpn,
        INVALID_EVENT_ID ,//Evt_DoorLR_JstClsd
              
    },
    /*SWID_IDL23*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel1_13,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        INVALID_EVENT_ID ,    
        INVALID_EVENT_ID ,//Evt_DoorRR_JstOpn,
        INVALID_EVENT_ID ,//Evt_DoorRR_JstClsd
              
    },
       /*SWID_IDL24*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel4_3,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
      Evt_HornErevPfafRsp_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
 /*SWID_IDL25*/
    {
        SW_CHANNEL_TYPE_SPI,
        23,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_BeamSelectFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL26*/
    {
        SW_CHANNEL_TYPE_SPI,    
        22,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_ManualOffFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL27*/
    {
        SW_CHANNEL_TYPE_SPI,    
        21,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_TurnLeftFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID     
    },
    /*SWID_IDL28*/
    {
        SW_CHANNEL_TYPE_SPI,
        20,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_TurnRightFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL29*/
    {
        SW_CHANNEL_TYPE_SPI,    
        19,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_FoglampFrontFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL30*/
    {
        SW_CHANNEL_TYPE_SPI,    
        18,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
      Evt_FoglampRearFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID      
    },
    /*SWID_IDL31*/
    {
        SW_CHANNEL_TYPE_SPI,
        17,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
      Evt_WndShieldWashFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL32*/
    {
        SW_CHANNEL_TYPE_SPI,    
        16,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_PrkSwData_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
       /*SWID_IDL33*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel0_14,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
     Evt_FtParkedFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
/*SWID_IDL34*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel3_0,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
      Evt_ECSLSwitchFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
    /*SWID_IDL35*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel3_1,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_ValetModeAvail_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
    /*SWID_IDL36*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel3_3,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_EcslLockStatusRRFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
       /*SWID_IDL37*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel3_4,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_EcslLockStatusLRFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
    },
       /*SWID_IDL38*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel11_0,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_CtdScmSignalFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
/*SWID_IDL39*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel11_1,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       INVALID_EVENT_ID ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
         /*SWID_IDL40*/
    {
        SW_CHANNEL_TYPE_SPI,
        31,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
     Evt_TurnLFOutageFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL41*/
    {
        SW_CHANNEL_TYPE_SPI,    
        30,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_TurnRFOutageFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL42*/
    {
        SW_CHANNEL_TYPE_SPI,    
        29,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        Evt_TurnLROutageFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID      
    },
    /*SWID_IDL43*/
    {
        SW_CHANNEL_TYPE_SPI,
        28,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_TurnRROutageFlt_Chg,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL44*/
    {
        SW_CHANNEL_TYPE_SPI,    
        27,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       INVALID_EVENT_ID ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL45*/
    {
        SW_CHANNEL_TYPE_SPI,    
        26,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        INVALID_EVENT_ID ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID   
    },
    /*SWID_IDL46*/
    {
        SW_CHANNEL_TYPE_SPI,
        25,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
        INVALID_EVENT_ID ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
      /*SWID_IDL47*/
    {
        SW_CHANNEL_TYPE_SPI,    
        24,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(FALSE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       INVALID_EVENT_ID ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
               
    },
       /*SWID_IDH0*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel0_4,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(TRUE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       INVALID_EVENT_ID ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
/*SWID_IDH1*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel0_3,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(TRUE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       INVALID_EVENT_ID ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
    /*SWID_IDH2*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel3_8,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(TRUE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       Evt_UserSelLampsLoadFlt_Chg ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },
    /*SWID_IDH3*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel0_12,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(TRUE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
       INVALID_EVENT_ID ,    
        INVALID_EVENT_ID,
         INVALID_EVENT_ID
              
    },

#if 0  
    /*RUN*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel0_12,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(TRUE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
        
        INVALID_EVENT_ID,
        INVALID_EVENT_ID,
        INVALID_EVENT_ID        
    },
    
    /*CRANK*/
    {
        SW_CHANNEL_TYPE_DIO,    
        DioChannel0_13,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/            
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(TRUE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
        
        INVALID_EVENT_ID,
        INVALID_EVENT_ID,
        INVALID_EVENT_ID        
    },

    /*tap up*/
    {
        SW_CHANNEL_TYPE_ADC,    
        DioChannel0_13,
        CalSW_BatVolt(6),  /*battery range lower limit*/
        CalSW_BatVolt(25.5),  /*battery range upper limit*/
        CeSW_FA_UseHstry,  /*battery out of range action*/  
            GetADSW_w_CntByTime(60000),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(TRUE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*5 - tap down*/
    {
        SW_CHANNEL_TYPE_ADC,    
        DioChannel0_13,    
            GetADSW_w_CntByTime(60000),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(TRUE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
            
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*SWID_TAPONOFF*/
    {
        SW_CHANNEL_TYPE_ADC,    
        DioChannel0_13,    
        GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        
            SetSW_Enable(TRUE) + 
            SetSW_PrsIsHigh(TRUE) + 
            SetSW_Momentary(FALSE) + 
            SetSW_InactvBfrUse(FALSE) +
            SetSW_DeftVal(FALSE) + 
            SetSW_UseKam(FALSE) +
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup),
        
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
  
    /*KEYINIGN*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypBiEdge)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    
    /*chime*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +        //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /* AC REQ*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary 
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +         //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*Wiper park*/
    {
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        {
            FALSE * (1<<0) +         //e_b_Momentary
            FALSE * (1<<1) +         //e_b_InactvBfrUse
            FALSE  * (1<<2) +          //e_b_DftVal
            SetSW_UseKam(FALSE)
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
        },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*SWID_WiperLowFB*/
    {
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        {
            FALSE * (1<<0) +         //e_b_Momentary
            FALSE * (1<<1) +         //e_b_InactvBfrUse
            FALSE  * (1<<2) +          //e_b_DftVal
            SetSW_UseKam(FALSE)
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
        },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*SWID_WiperHighFB*/
    {
        GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
        GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
        GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
        {
            FALSE * (1<<0) +         //e_b_Momentary
            FALSE * (1<<1) +         //e_b_InactvBfrUse
            FALSE  * (1<<2) +          //e_b_DftVal
            SetSW_UseKam(FALSE)
            SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
        },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    
    /*Washer*/
    {
            GetDGSW_w_CntByTime(120000),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(20),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    
    /*SWID_RDFG*/
    {
            GetDGSW_w_CntByTime(30000),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                TRUE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*SWID_hazard */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypBiEdge)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
      

    
    /*SWID_LeftTurnLampRtn*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

        /*SWID_RifhtTurnLampRtn*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(20),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

               

    /* front fog lamp sw */
    {
            GetDGSW_w_CntByTime(30000),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {          
                FALSE * (1<<0) +         //e_b_Momentary     
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID          
    },

    /* rear fog lamp sw */
    {
            GetDGSW_w_CntByTime(30000),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                TRUE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2)  +          //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    /* park lamp sw */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypBiEdge)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    /* low beam sw */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypBiEdge)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    
    /* High beam sw */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    /* flash to pass switch*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    
    /*SWID_LFDOOR_AJAR*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },  
    /* ALL door ajar sw */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },    
       /* brake pedal sw */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(15),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2)  +          //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    /* SDM crash signal */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    /*  driver door key unlock  */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                TRUE * (1<<1) +         //e_b_InactvBfrUse, BCM must see unlock action to unlock door
                FALSE  * (1<<2)  +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    /*Driver door key Lock */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(50),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                TRUE * (1<<1) +         //e_b_InactvBfrUse, BCM must see lock action to lock door
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    /*  trunk unlock switch  */
    {
            GetDGSW_w_CntByTime(30000),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(50),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                TRUE * (1<<1) +         //e_b_InactvBfrUse, BCM must see unlock action to unlock trunk
                FALSE  * (1<<2)  +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /* Trunk Ajar  */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(50),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2)  +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

      /*key in drv door cylinder - tamper switch  */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(25),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypBiEdge)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },    
    /*SWID_RearClrKeyCylFilt*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

     /*SWID_ParkBrake*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
             /*Brake Fluid */
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(100),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

             /*SWID_MTReverse*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(15),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*SWID_TurnLampLeft*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(60),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    /*SWID_TurnLampRight*/
    {
            GetDGSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetDGSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(60),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +          //e_b_DftVal
                SetSW_UseKam(TRUE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
/*------------------AD Switches--------------------
|Note!! the task slice may be different between digital switch and analog switch.
|Use GetADSW_w_CntByTime() to config time requirements.
*/


    /*6 - cruise on*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +        //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*7 - cruise set*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                TRUE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +        //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*cruise resume*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                TRUE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +        //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    
    /*cruise cancel*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +        //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*wiper 1*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +        //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*wiper 2*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +        //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*wiper 3*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +        //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*wiper 4*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +        //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*wiper 5*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +         //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },

    /*wiper 6*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +         //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    },
    
    /*wiper 7*/
    {
            GetADSW_w_CntByTime(0),       //e_w_StckTim, ms
            GetADSW_w_CntByTime(0),       //e_w_MaxPrsdTim, ms
            GetDGSW_w_CntByTime(30),      /*e_u_DbcTim, ms*/
            {
                FALSE * (1<<0) +         //e_b_Momentary
                FALSE * (1<<1) +         //e_b_InactvBfrUse
                FALSE  * (1<<2) +         //e_b_DftVal
                SetSW_UseKam(FALSE)
                SetSW_WkupTyp(CeSW_u_WkupTypNoWkup)
            },
            INVALID_EVENT_ID,
            INVALID_EVENT_ID,
            INVALID_EVENT_ID
    }
#endif
};


/**************************************************************
**              Analog Switch IDs Configuration      **
**************************************************************/

#define CRUISE_ON_ACTIVE   0x01      /*---define region---*/
#define CRUISE_SET_ACTIVE   0x02
#define CRUISE_RES_ACTIVE   0x04
#define CRUISE_CANCEL_ACTIVE   0x08




/* Wiper switches*/
const uint8 KaSW_u_WiperAllSwId[] =
{
    SWID_WIPER_1,
    SWID_WIPER_2,
    SWID_WIPER_3,
    SWID_WIPER_4,
    SWID_WIPER_5,
    SWID_WIPER_6,
    SWID_WIPER_7
};
#define SWID_WIPER_OFF            0x00
#define SWID_WIPER_1_ACTIVE   0x01
#define SWID_WIPER_2_ACTIVE   0x02
#define SWID_WIPER_3_ACTIVE   0x04
#define SWID_WIPER_4_ACTIVE   0x08
#define SWID_WIPER_5_ACTIVE   0x10
#define SWID_WIPER_6_ACTIVE   0x20
#define SWID_WIPER_7_ACTIVE   0x40


/**************************************************************
**              Analog Switch voltage mapping Configuration      **
**************************************************************/
/***************************************************************************************/
/*Front Wiper Switch AD range define*/
/***************************************************************************************/
#define WIPER_RNG_SIZE    8
uint16 VaSW_w_WiperRngDiagTimer[WIPER_RNG_SIZE];
TeSW_AdDiagStat VaSW_h_WiperRngDiagStat[WIPER_RNG_SIZE];
//const uint16 KaADSW_u_WIPEvtList[] =  /*---List---*/
//{
//    Evt_FrtWipCtrlDbncISIG_Chg,
//    Evt_FrtWipCtrlDbncISIG_Chg,
//    Evt_FrtWipCtrlDbncISIG_Chg,
//    Evt_FrtWipCtrlDbncISIG_Chg,
//    Evt_FrtWipCtrlDbncISIG_Chg,
//    Evt_FrtWipCtrlDbncISIG_Chg,
//    Evt_FrtWipCtrlDbncISIG_Chg,
//    Evt_FrtWipCtrlDbncISIG_Chg,
//    Evt_FrtWipCtrlDbncISIG_Chg,
//    Evt_FrtWipCtrlDbncISIG_Chg
//};


/*****************************************************************
*Clea+ Front Wiper, input @ 12VDC
*     min         max
*7	2.66 	2.92       low speed
*6	2.02 	2.29 
*5	1.67 	1.92 
*4	1.39 	1.62 
*3	1.20 	1.41 
*2	1.20 	1.41 
*1	1.20 	1.41      high speed
*
******************************************************************/
const TeSW_AdRngCal KaSW_h_WiperRngInfo[WIPER_RNG_SIZE] =
{
    /*Wiper 1 "0.88"*/
    {
        GetADSW_w_RawByVolt(0.60f) ,     /*uint16 wAD_Range_Low  0.17f*/
        GetADSW_w_RawByVolt(1.10f) ,       /*uint16 wAD_Range_High  0.4f*/    
        0,
        CeWIP_e_FrtWipLow,              /* CeWIP_e_FtLowSpeed */
        CeIoHwAb_e_AdRangeNormal  
        
    },
    
    /*Wiper 2 "1.65"*/
    {

        GetADSW_w_RawByVolt(1.11f) ,     /*uint16 wAD_Range_Low  0.45f*/
        GetADSW_w_RawByVolt(1.90f) ,     /*uint16 wAD_Range_High  0.69f*/
        0,
        CeWIP_e_FrtWipInt5,              /* CeWIP_e_Intermittent1 */
        CeIoHwAb_e_AdRangeNormal            
    },

    /*Wiper 3 "2.30"*/
    {
        GetADSW_w_RawByVolt(1.91f) ,     /*uint16 wAD_Range_Low  0.70f*/
        GetADSW_w_RawByVolt(2.60f) ,       /*uint16 wAD_Range_High 0.95f*/  
        0,
        CeWIP_e_FrtWipInt4,               /* Intermittent 2 */ 
        CeIoHwAb_e_AdRangeNormal            
    },

    /*Wiper 4 "2.85"*/
{
        GetADSW_w_RawByVolt(2.61f) ,     /*uint16 wAD_Range_Low 0.96f*/
        GetADSW_w_RawByVolt(3.00f) ,     /*uint16 wAD_Range_High 1.25f*/        
        0,
        CeWIP_e_FrtWipInt3,                /* Intermittent 3 */
        CeIoHwAb_e_AdRangeNormal           
    },
    /*Wiper 5 "3.25"*/
    {
        GetADSW_w_RawByVolt(3.01f) ,     /*uint16 wAD_Range_Low 1.26f*/
        GetADSW_w_RawByVolt(3.50f) ,       /*uint16 wAD_Range_High 1.60f*/     
        0,
        CeWIP_e_FrtWipInt2,                /* Intermittent 4 */
        CeIoHwAb_e_AdRangeNormal            
    },

    /*Wiper 6 "3.68"*/
    {
        GetADSW_w_RawByVolt(3.51f) ,     /*uint16 wAD_Range_Low 1.26f*/
        GetADSW_w_RawByVolt(4.00f) ,       /*uint16 wAD_Range_High 1.60f*/     
        0,
        CeWIP_e_FrtWipInt1,                /* Intermittent 5 */
        CeIoHwAb_e_AdRangeNormal 
    },
    
    /*Wiper 7 "5.0"*/
    {
        GetADSW_w_RawByVolt(4.00f) ,     /*uint16 wAD_Range_Low 1.26f*/
        GetADSW_w_RawByVolt(5.00f) ,       /*uint16 wAD_Range_High 1.60f*/     
        0,
        CeWIP_e_FrtWipOff,                /* CeWIP_e_FtWipersOff */
        CeIoHwAb_e_AdRangeNormal            
    },
    
    /*Wiper 8*/
    {
        GetADSW_w_RawByVolt(5.01f) ,     /*uint16 wAD_Range_Low 1.26f*/
        GetADSW_w_RawByVolt(12.00f) ,       /*uint16 wAD_Range_High 1.60f*/     
        0,
        CeWIP_e_FrtWipFault,             /* CeWIP_e_FtWiperSwFault */
        CeIoHwAb_e_AdRangeNormal            
    }
};

/***************************************************************************************/
/*Rear Wiper Switch AD range define*/
/***************************************************************************************/
#define REAR_WIPER_RNG_SIZE    4
uint16 VaSW_w_RearWiperRngDiagTimer[REAR_WIPER_RNG_SIZE];
TeSW_AdDiagStat VaSW_h_RearWiperRngDiagStat[REAR_WIPER_RNG_SIZE];
//const uint16 KaADSW_u_RearWIPEvtList[] =  /*---List---*/
//{
//    Evt_RrWipCtrlDbncISIG_Chg,
//    Evt_RrWipCtrlDbncISIG_Chg,
//    Evt_RrWipCtrlDbncISIG_Chg,
//    Evt_RrWipCtrlDbncISIG_Chg
//};

/*****************************************************************
*Clea+ Rear Wiper, input @ 12VDC
*     min         max
*4	1.39 	1.62 
*3	1.20 	1.41 
*2	1.20 	1.41 
*1	1.20 	1.41
*
******************************************************************/
const TeSW_AdRngCal KaSW_h_RearWiperRngInfo[REAR_WIPER_RNG_SIZE] =
{
    /*Wiper 1 "2.88"*/
    {
        GetADSW_w_RawByVolt(2.50f) ,     /*uint16 wAD_Range_Low  0.17f*/
        GetADSW_w_RawByVolt(3.30f) ,       /*uint16 wAD_Range_High  0.4f*/    
        0,
        CeWIP_e_RrWipLow,              /* CeWIP_e_RrWipInt */
        CeIoHwAb_e_AdRangeNormal  
        
    },
    
    /*Wiper 2 "3.75"*/
    {

        GetADSW_w_RawByVolt(3.31f) ,     /*uint16 wAD_Range_Low  0.45f*/
        GetADSW_w_RawByVolt(3.90f) ,     /*uint16 wAD_Range_High  0.69f*/
        0,
        CeWIP_e_RrWipInt,              /* CeWIP_e_RrWiplow */
        CeIoHwAb_e_AdRangeNormal            
    },

    /*Wiper 3 "4.18"*/
    {
        GetADSW_w_RawByVolt(3.91f) ,     /*uint16 wAD_Range_Low  0.70f*/
        GetADSW_w_RawByVolt(4.30f) ,       /*uint16 wAD_Range_High 0.95f*/  
        0,
        CeWIP_e_RrWshOn,               /* CeWIP_e_RrWshOn */ 
        CeIoHwAb_e_AdRangeNormal            
    },

    /*Wiper 4 "4.44"*/
{
        GetADSW_w_RawByVolt(4.31f) ,     /*uint16 wAD_Range_Low 0.96f*/
        GetADSW_w_RawByVolt(5.00f) ,     /*uint16 wAD_Range_High 1.25f*/        
        0,
        CeWIP_e_RrWshWipOff,                /* CeWIP_e_RrWshWipOff */
        CeIoHwAb_e_AdRangeNormal           
    }
};

/***************************************************************************************/
/*Steering Wheel Control Switch 1 AD range define*/
/***************************************************************************************/
#define STE1_RNG_SIZE 8    /*Steering range number*/
const TeSW_AdRngCal KaSW_h_Ste1Rng[STE1_RNG_SIZE] =
{
        {    
        GetADSW_w_RawByVolt(0) ,
        GetADSW_w_RawByVolt(0.1f),
        0,
        CeSWC_e_SwtFltNoActtn,
        CeIoHwAb_e_AdRangeNormal
    },
    
    {
        GetADSW_w_RawByVolt(0.1f) ,
        GetADSW_w_RawByVolt(0.5f),
        0,
        CeSWC_e_SwtFltFct1,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(0.1f) ,
        GetADSW_w_RawByVolt(0.5f),
        0,
        CeSWC_e_SwtFltFct2,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(0.5f) ,
        GetADSW_w_RawByVolt(1.8f),
        0,
        CeSWC_e_SwtFltFct3,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(1.8f) ,
        GetADSW_w_RawByVolt(2.2f),
        0,
        CeSWC_e_SwtFltFct4,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(2.2f) ,
        GetADSW_w_RawByVolt(2.8f),
        0,
        CeSWC_e_SwtFltFct5,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(2.8f) ,
        GetADSW_w_RawByVolt(3.8f),
        0,
        CeSWC_e_SwtFltFct6,
        CeIoHwAb_e_AdRangeNormal
        },            

    {
        GetADSW_w_RawByVolt(3.8f) ,
        GetADSW_w_RawByVolt(4.8f),
        0,
        CeSWC_e_SwtFltFct7,
        CeIoHwAb_e_AdRangeNormal
    }
};

/***************************************************************************************/
/*Steering Wheel Control Switch 2 AD range define*/
/***************************************************************************************/
#define STE2_RNG_SIZE 9 //leiyong    /*Steering range number*/
const TeSW_AdRngCal KaSW_h_Ste2Rng[STE2_RNG_SIZE] =
{
    {
        GetADSW_w_RawByVolt(0.400f) ,/*2.002f*/ /*1.972f*///0.668
        GetADSW_w_RawByVolt(0.730f),/*2.18f*/ /*2.172f*/
        0,
         CeSWC_e_SwtFltFct1,
        CeIoHwAb_e_AdRangeNormal
    },
    
    {
        GetADSW_w_RawByVolt(0.75) ,/*2.281f*//*2.251f*///0.811
        GetADSW_w_RawByVolt(0.85),/*2.476f*//*2.451f*/
        0,
        CeSWC_e_SwtFltFct2,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(0.88f) ,/*2.586f*/ /*2.548f*/ /*1.009*/
        GetADSW_w_RawByVolt(1.08f),/*2.797f*/ /*2.748f*/
        0,
        CeSWC_e_SwtFltFct3,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(1.1f) ,/*2.885f*/ /*2.845f*/
        GetADSW_w_RawByVolt(1.34f),/*3.11f*/ /*3.045f*/
        0,
        CeSWC_e_SwtFltFct4,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(1.4f) ,/*3.167f*/ /*3.122f*/
        GetADSW_w_RawByVolt(1.6f),/*3.403f*/ /*3.322f*/
        0,
        CeSWC_e_SwtFltFct5,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(1.74f) ,/*3.45f*/ /*3.401f*/ /*3.573*/
        GetADSW_w_RawByVolt(2.0f),/*3.696f*/ /*3.601f*/
        0,
        CeSWC_e_SwtFltFct6,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(2.32f) ,/*3.81f*/ /*3.75f*/ /*3.938*/
        GetADSW_w_RawByVolt(2.52f),/*4.066f*/ /*3.95f*/
        0,
        CeSWC_e_SwtFltFct7,
        CeIoHwAb_e_AdRangeNormal
    },

    {
        GetADSW_w_RawByVolt(3.32f) ,/*3.8f*/ /*4.14f*//*4.317*/
        GetADSW_w_RawByVolt(3.52f),/*4.8f*/ /*4.34f*/
        0,
        CeSWC_e_SwtFltFct8,
        CeIoHwAb_e_AdRangeNormal
    },
    {
        GetADSW_w_RawByVolt(3.6f) ,
        GetADSW_w_RawByVolt(5.0f),
        0,
        CeSWC_e_SwtFltNoActtn,
        CeIoHwAb_e_AdRangeNormal
    }
};

/***************************************************************************************/
/*HOOD ajar switches AD range define*/
/***************************************************************************************/
#define HOOD_RNG_SIZE    2
//const uint16 KaADSW_u_HOODEvtList[] =  /*---List---*/
//{
//    Evt_CtdHdSwRsp_Chg,
//    Evt_CtdHdSwRsp_Chg
//};

const TeSW_AdRngCal KaSW_h_HoodRngInfo[HOOD_RNG_SIZE] =
{
    /*TRUE*/
    {
        GetADSW_w_RawByVolt(0.05f) ,     /*uint16 wAD_Range_Low  0.17f*/
        GetADSW_w_RawByVolt(0.60f) ,       /*uint16 wAD_Range_High  0.4f*/    
        0,
        TRUE,  
        CeIoHwAb_e_AdRangeNormal  
        
    },

    /*FALSE*/
    {

        GetADSW_w_RawByVolt(0.61f) ,     /*uint16 wAD_Range_Low  0.45f*/
        GetADSW_w_RawByVolt(2.00f) ,     /*uint16 wAD_Range_High  0.69f*/
        0,
        FALSE,  
        CeIoHwAb_e_AdRangeNormal           
    }

};

/***************************************************************************************/
/*IA1(Dimming +/-, FogLamp F/R) ajar switches AD range define*/
/***************************************************************************************/
#define IA1_RNG_SIZE    5
//const uint16 KaADSW_u_IA1EvtList[] =  /*---List---*/
//{
//    Evt_DimCtrlDec_Chg,
//    Evt_DimCtrlInc_Chg,
//    Evt_FoglampFrontFlt_Chg,
//    Evt_FoglampRearFlt_Chg
//};

const TeSW_AdRngCal KaSW_h_IA1RngInfo[IA1_RNG_SIZE] =//123
{
    /*Dimming -*/
    {
        GetADSW_w_RawByVolt(3.61f) ,     /*uint16 wAD_Range_Low  0.17f*/
        GetADSW_w_RawByVolt(3.90f) ,       /*uint16 wAD_Range_High  0.4f*/    
        0,
        CeILS_e_DimmingInc,                /*Dimming -*/
        CeIoHwAb_e_AdRangeNormal,  
      //  Evt_DimCtrlDec_Chg
    },

    /*Dimming +*/
    {
        GetADSW_w_RawByVolt(3.91f) ,     /*uint16 wAD_Range_Low  0.17f*/
        GetADSW_w_RawByVolt(4.30f) ,       /*uint16 wAD_Range_High  0.4f*/    
        0,
        CeILS_e_DimmingDec,                /*Dimming +*/
        CeIoHwAb_e_AdRangeNormal,  
      //  Evt_DimCtrlInc_Chg
    },

    /*FogLamp Front*/
    {
        GetADSW_w_RawByVolt(3.21f) ,     /*uint16 wAD_Range_Low  0.17f*/
        GetADSW_w_RawByVolt(3.60f) ,       /*uint16 wAD_Range_High  0.4f*/    
        0,
        CeELS_e_FogFront,                  /*FogLamp Front*/
        CeIoHwAb_e_AdRangeNormal,  
      //  Evt_FoglampFrontFlt_Chg
    },
    
    /*FogLamp Rear*/
    {

        GetADSW_w_RawByVolt(2.81f) ,     /*uint16 wAD_Range_Low  0.45f*/
        GetADSW_w_RawByVolt(3.20f) ,     /*uint16 wAD_Range_High  0.69f*/
        0,
        CeELS_e_FogRear,                 /*FogLamp Rear*/
        CeIoHwAb_e_AdRangeNormal,
      //  Evt_FoglampRearFlt_Chg
    },

    /* NETUAL */
    {
        GetADSW_w_RawByVolt(4.31f) ,     /*uint16 wAD_Range_Low  0.17f*/
        GetADSW_w_RawByVolt(5.00f) ,       /*uint16 wAD_Range_High  0.4f*/    
        0,
        CeLS_e_NULL,                /*NETUAL*/
        CeIoHwAb_e_AdRangeNormal,  
        
    }

};

/*define an analog switch, 5th step is to define group property here */

const TeADSW_GrupInfo KaADSW_h_GrupInfo[SWGRUP_NUM] =
{
     /* Rear Wiper/Wash */
    {
        ADSW_SAM_BUF_REARWIP,               /*uint16 *e_p_AdRaw; */
        GetADSW_w_CookByVolt(18.55),        /*uint16 e_p_SrcVoltRef*/
        &VeIoHwAb_w_Adc1ResultBuffer[1],       /*uint16 *e_w_SrcVolt; */
        (uint8*)NULL,                  /*uint8* e_p_SwId;*/
        KaSW_h_RearWiperRngInfo,                /*TeSW_AdRngCal* e_p_AdRngCal; */
        LENGTH_OF_ARRAY(KaSW_h_RearWiperRngInfo), /*uint8 e_u_RngArrSize; */
        GetADSW_w_CntByTime(20),         /*uint16 e_w_SwDbcTime;, in ms*/        
        Evt_RrWipCtrlDbncISIG_Chg//KaADSW_u_RearWIPEvtList
    },    

     /*Wiper intermedent*/
    {
        ADSW_SAM_BUF_WIPR,                /*uint16 *e_p_AdRaw, AN03; */
        GetADSW_w_CookByVolt(18.55),        /*uint16 e_p_SrcVoltRef*/
        &VeIoHwAb_w_Adc1ResultBuffer[1],       /*uint16 *e_w_SrcVolt; */
        KaSW_u_WiperAllSwId,                /*uint8* e_p_SwId;*/
        KaSW_h_WiperRngInfo,               /*TeSW_AdRngCal* e_p_AdRngCal; */
        LENGTH_OF_ARRAY(KaSW_h_WiperRngInfo),    /*uint8 e_u_RngArrSize; */
        GetADSW_w_CntByTime(20),        //e_w_SwDbcTime, ms
        Evt_FrtWipCtrlDbncISIG_Chg//KaADSW_u_WIPEvtList
    },

    /*Steering Wheel Control Switch 1 Group*/
    {
        ADSW_SAM_BUF_STE1,                /*uint16 *e_p_AdRaw, AN03; */
        GetADSW_w_CookByVolt(12),       /*uint16 e_p_SrcVoltRef*/
        ADSW_REF_ADDR_STE1,                     /*uint16 *e_w_SrcVolt; */
        (uint8*)NULL,                /*uint8* e_p_SwId;*/
        KaSW_h_Ste1Rng,               /*TeSW_AdRngCal* e_p_AdRngCal; */
        LENGTH_OF_ARRAY(KaSW_h_Ste1Rng),    /*uint8 e_u_RngArrSize; */
        GetADSW_w_CntByTime(20),        //e_w_SwDbcTime, ms
        INVALID_EVENT_ID//Evt_SWCSwt1Flt_Chg
    },

    /*Steering Wheel Control Switch 2 Group*/
    {
        ADSW_SAM_BUF_STE2,                /*uint16 *e_p_AdRaw, AN03; */
        GetADSW_w_CookByVolt(18.70),       /*uint16 e_p_SrcVoltRef*/
        &VeIoHwAb_w_AdcResultBuffer[14],                     /*uint16 *e_w_SrcVolt; */
        (uint8*)NULL,                /*uint8* e_p_SwId;*/
        KaSW_h_Ste2Rng,               /*TeSW_AdRngCal* e_p_AdRngCal; */
        LENGTH_OF_ARRAY(KaSW_h_Ste2Rng),    /*uint8 e_u_RngArrSize; */
        GetADSW_w_CntByTime(20),        //e_w_SwDbcTime, ms
        Evt_SWCSwt2Flt_Chg//INVALID_EVENT_ID//Evt_SWCSwt2Flt_Chg
    },

    /* HOOD AJAR */
    {
        ADSW_SAM_BUF_HOOD,  /*uint16 *e_p_AdRaw; */      
        GetADSW_w_CookByVolt(12),        /*uint16 e_p_SrcVoltRef*/
        ADSW_REF_ADDR_HOOD,       /*uint16 *e_w_SrcVolt; */
        (uint8*)NULL,                      /*uint8* e_p_SwId;*/
        KaSW_h_HoodRngInfo,                     /*TeSW_AdRngCal* e_p_AdRngCal; */
        LENGTH_OF_ARRAY(KaSW_h_HoodRngInfo), /*uint8 e_u_RngArrSize; */
        GetADSW_w_CntByTime(20),                         /*uint16 e_w_SwDbcTime; in ms*/
        Evt_CtdHdSwRsp_Chg//KaADSW_u_HOODEvtList
    },

    /* IA1 AJAR */
    {
        ADSW_SAM_BUF_IA1,  /*uint16 *e_p_AdRaw; */      
        GetADSW_w_CookByVolt(18.55),        /*uint16 e_p_SrcVoltRef*/
        &VeIoHwAb_w_Adc1ResultBuffer[1],       /*uint16 *e_w_SrcVolt; */
        (uint8*)NULL,                      /*uint8* e_p_SwId;*/
        KaSW_h_IA1RngInfo,                     /*TeSW_AdRngCal* e_p_AdRngCal; */
        LENGTH_OF_ARRAY(KaSW_h_IA1RngInfo), /*uint8 e_u_RngArrSize; */
        GetADSW_w_CntByTime(20),                         /*uint16 e_w_SwDbcTime; in ms*/
        INVALID_EVENT_ID//KaADSW_u_IA1EvtList
    },    
    
};

#if 0
/*Output feedback digital in
* Reflect the raw input value. no debounce.
* define board internal digital input here.
*/
const TeSW_h_OBDIInfo KaSW_h_OBDIInfo[OBDI_Num]=
{
    /*Note: PORTA are in address 0, and NULL is also in address 0*/
    {TRUE, &PORTK, 1},
    {TRUE, &PORTK, 2},
    {TRUE, &PTP, 0},
    {FALSE, NULL, 0},
    {TRUE, &PORTK, 0},
    {FALSE, NULL, 0},
    {FALSE, NULL, 0},
    {FALSE, NULL, 0},
    
    {TRUE, &PORTC, 1},
    {TRUE, &PORTC, 2},
    {FALSE, NULL, 0},
    {TRUE, &PORTK, 7},
    {FALSE, NULL, 0},
    {TRUE, &PTJ, 4},
    {TRUE, &PTJ, 5},
    {FALSE, NULL, 0},

    {FALSE, NULL, 0},
    {FALSE, NULL, 0},
    {FALSE, NULL, 0},
    {FALSE, NULL, 0},
    {FALSE, NULL, 0},
    {FALSE, NULL, 0},
    {FALSE, NULL, 0},
    {FALSE, NULL, 0},
    
    {TRUE, &PORTB, 5},
    {TRUE, &PORTC, 7},
    {TRUE, &PORTC, 6},
    {TRUE, &PORTA, 7},
    {TRUE, &PORTA, 6},
    {FALSE, NULL, 0},
    {FALSE, NULL, 0},
    {FALSE, NULL, 0}
};

#endif
#define CAL_STOP_CAL1_SECT
#include "MemMap.h"

