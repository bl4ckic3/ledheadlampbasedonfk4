/*****************************************************************************
|File Name:  Switch.c
|
|Description:  Switch input handle subsystem.
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
|2009-05-18  01.00.00     WH          Creation
|2009-07-02  01.00.01     WH          Add comments
|2009-07-24  01.00.02     WH          Add switch input edge event trigger
|2009-08-25  01.00.03     WH          Devide edge event trigger into two parts: rising edge and falling edge
|2009-08-28  01.00.04     FRED        Delete CaSW_u_AvlbldPwrMod, because system power mode now has the mask
|2009-09-13  01.00.05     FRED        Change event ID assigned in the switch definition
|2009-09-21  01.00.06     WH          Add e_b_SwPrsdFltValid to indicate if switch status is after debounce.
|                                                   Add ProcSW_PreSleep()
|2009-11-18  01.00.07     WH         Merge digital switch passtime to common switch passtime
|2010-01-17  01.00.08     WH          Change SetSW_AdDiagRng() feature: when DTC is invalid, still do stuck monitor
|                                                  Add ResetSW_DiagStat() for $04 service.
|2010-04-22  01.01.00     WH     Add e_b_DisableCtrl flag, so other task can use this control bit to disable a switch handle.
|2010-04-28  01.01.01     WH     Add battery range calibration.
|                                              Delete Short to battery/ground, open load diagnose because 
|                                                   this diagnostic is not available.
|                                              Delete VaSW_u_DgtlWireFltRaw for the above reason.
|                                              Delete stuck DTC set/clear interface because these DTCs are handled together in another task.
|2010-05-14  01.01.02     WH    Fix Analog switch no stuck feature bug.
|2011-08-10  02.00.00     WH    Revised for FK4
|2012-08-09  02.01.00     WH    Add AD switch enum value feature.
|2013-10-28  03.00.00     WY    Modify Function DtrmSW_sendsignal.
*****************************************************************************/


/******************************************************************************
**                      Include Section                                      **
******************************************************************************/

#include "IoHwAb_Switch.h"
#include "string.h"
#include "Std_Macro.h"
#include "Com.h"
#include "PnNm_Manager.h"
//#include "Kam.h"

/*******************************************************************************
|    Macro Definition
|******************************************************************************/

#define CeIoHwAb_u_NullAdRangeId 0xFF

#define IoHwAb_GetBatVoltRaw()       1200u
#define IoHwAb_GetBatVoltFlt()       1200u
#define IoHwAb_GetBatVoltStat()    TRUE

/*******************************************************************************
|    Enum Definition
|******************************************************************************/

/*******************************************************************************
|    Typedef Definition
|******************************************************************************/

/*******************************************************************************
|    Global variables Declaration
|******************************************************************************/
TeADSW_GrupStat VaADSW_h_GrupStat[SWGRUP_NUM];
uint16 VaSW_w_AdGrupTimer[SWGRUP_NUM];

TeSW_CmmnStat VaSW_h_CmmnStat[SWID_NUM];
TeSW_CmmnFailFlags VaSW_h_CmmnFFlg[SWID_NUM];
uint8 VaSW_u_OBDIStat[(OBDI_Num+7)/8];


/*AD switch enum value raw, init to zero*/
UINT8 VaSW_e_GrupSwEnumRaw[SWGRUP_NUM];
   
/*AD switch enum value filted, init to zero*/
UINT8 VaSW_e_GrupSwEnumFlt[SWGRUP_NUM];

/*******************************************************************************
|    Static local variables Declaration
|******************************************************************************/

//#pragma DATA_SEG RUN_KAM
TeSW_CmmnStat RaSW_h_CmmnStat[SWID_NUM];
//#pragma DATA_SEG DEFAULT

/*Switch timer for debounce(digital) and stuck check(digital/analog)*/
static uint16 VaSW_w_CmmnTimer[SWID_NUM];

/*******************************************************************************
|    Static Local Functions Declaration
|******************************************************************************/
#if 0
void SetSW_GrupDtc(uint8 GrupId, uint8 RngId);
void ClrSW_GrupDtc(uint8 GrupId);
void SetSW_AdDiagGrup(uint8 GrupId, uint8 RngId);
void SetSW_AdDiagRng(uint8 GrupId, uint8 RngId);
#endif

#if 0
static void UpdtSW_OBDIStatus(void);
static uint8 GetSW_u_StuckStat(uint8 SwId);
static void TrigSW_EvtOnChng(uint8 SwId);
#endif
static void DtrmSW_NonAdTypeRaw(void);
static void UpdtSW_FltStat(uint8 LeSW_u_SwId);
static void DtrmSW_Status(void);
static void DtrmSW_sendsignal(void);

static void DtrmSW_AdTypeRaw(void);
static uint8 GetSW_u_AdRangeRaw(uint8 GrupId);
static void UpdtSW_AdRangeFlt(uint8 GrupId, uint8 Le_u_AdRangeIdRaw);
static void UpdtSW_AdDscrtStat(uint8 GrupId);

extern uint32 App_READ_Buffer_JOB1[1];
/*******************************************************************************
|    Extern variables and functions declaration
|******************************************************************************/
/*******************************************************************************
|    Function Source Code
|******************************************************************************/

/****************************************************************************************
| NAME:    SwtAb_Handler                                                                                               
| CALLED BY:    IoHwAb_SchM10ms
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    
| RETURN VALUE:     NA
| DESCRIPTION:      process switch task
****************************************************************************************/
void SwtAb_Handler(void) 
{
     DtrmSW_NonAdTypeRaw();

     DtrmSW_AdTypeRaw();
     
     DtrmSW_Status();

     DtrmSW_sendsignal();
	 
     //UpdtSW_OBDIStatus();
}

/****************************************************************************************
| NAME:    DtrmSW_NonAdTypeRaw                                                                                               
| CALLED BY:    SwtAb_Handler(10 ms task schedule)
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    NA
| RETURN VALUE:     NA
| DESCRIPTION:      Determine digital switch status (non-AD type switches).                          
****************************************************************************************/
static void DtrmSW_NonAdTypeRaw(void)
{
    uint8 Le_u_SwId;   

    for(Le_u_SwId = 0; Le_u_SwId < SWID_NUM; Le_u_SwId++)
    {  
        /*determine switch raw input*/
        if(FALSE == SWCFG_ENABLED(Le_u_SwId))
        {
            SW_RAW(Le_u_SwId) = 0;
        }
        /*determine switch raw input by switch type and config*/
        else if(SW_CHANNEL_TYPE_DIO == SWCFG_CHANNEL_TYPE(Le_u_SwId))
        {
            if((SWCFG_PRS_IS_HIGH(Le_u_SwId) && (STD_HIGH==Dio_ReadChannel(SWCFG_CHANNEL_ID(Le_u_SwId)))) ||
                ((FALSE == SWCFG_PRS_IS_HIGH(Le_u_SwId)) && (STD_LOW==Dio_ReadChannel(SWCFG_CHANNEL_ID(Le_u_SwId)))))
            {
                SW_RAW(Le_u_SwId) = 1;
            }
            else
            {
                SW_RAW(Le_u_SwId) = 0;
            }
        }
        else if(SW_CHANNEL_TYPE_SPI == SWCFG_CHANNEL_TYPE(Le_u_SwId))
        {
            if((SWCFG_PRS_IS_HIGH(Le_u_SwId) && (STD_HIGH==Read_Buf_Bit((uint8 *)App_READ_Buffer_JOB1,SWCFG_CHANNEL_ID(Le_u_SwId)))) ||
                ((FALSE == SWCFG_PRS_IS_HIGH(Le_u_SwId)) && (STD_LOW==Read_Buf_Bit((uint8 *)App_READ_Buffer_JOB1,SWCFG_CHANNEL_ID(Le_u_SwId)))))
            {
                SW_RAW(Le_u_SwId) = 1;
            }
            else
            {
                SW_RAW(Le_u_SwId) = 0;
            }        
        }
        else
        {
            /*TODO: other type switches like SPI or I2C*/
        }
    }/*parsing next digital switch*/ 

}


/****************************************************************************************
| NAME:    UpdtSW_FltStat                                                                                               
| CALLED BY:                               
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    LeSW_u_SwId - Switch ID #
| RETURN VALUE:     NA
| DESCRIPTION:      determine switch status after diagnostic.
|                             call this rountine after switch is debouced.
****************************************************************************************/
static void UpdtSW_FltStat(uint8 LeSW_u_SwId)
{
    /*Set once inactive flag when debounced and not pressed
    * Set learned flag when debouce pass and once inactive requirement pass
    * If switch is no need once-inactive, also set learn flag.
    */
    if(FALSE == SW_RAW(LeSW_u_SwId)) 
    {
        SET_SW_ONCEINACTV(LeSW_u_SwId);
        SET_SW_LEARNED(LeSW_u_SwId);
    }

    if(FALSE == SWCFG_INACTV_BFRUSE(LeSW_u_SwId)) 
    {
        SET_SW_LEARNED(LeSW_u_SwId); 
    }

    /*update switch filtered status after learned and stuck checked
    * if switch error, or not learned, use default value instead
    */
    if(IS_SW_LEARNED(LeSW_u_SwId))
    {
        SW_FLT(LeSW_u_SwId) = SW_RAW(LeSW_u_SwId);
    }
    else
    {
        SW_FLT(LeSW_u_SwId) = SWCFG_DEFAULT_VAL(LeSW_u_SwId);
    }

    /*set valid flag after debounce*/
    VeSW_b_PrsdStatValid(LeSW_u_SwId) = TRUE;
    
    /*change toggle flag when filtered switch changed from unpressed to pressed.
    *  it is set without consider switch type, however, toggle state is mainly used with momentary switch.
    */
    if(SW_FLT(LeSW_u_SwId) &&
        (FALSE == SW_FLT_LAST(LeSW_u_SwId)))
    {
        TOGGLE_SW(LeSW_u_SwId);
    }
    
}

/****************************************************************************************
| NAME:    TrigSW_EvtOnChng                                                                                               
| CALLED BY:                        
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    
| RETURN VALUE:     NA
| DESCRIPTION:      Detect switch change event and update last switch filtered state
****************************************************************************************/
static void TrigSW_EvtOnChng(uint8 SwId)
{
     if(SW_FLT_LAST(SwId) != SW_FLT(SwId))
     {
        if(TRUE == SW_FLT(SwId))
        {
            SetSW_Event(SWCFG_EVENTID_PRESS(SwId));
        }
        else
        {
            SetSW_Event(SWCFG_EVENTID_RELEASE(SwId));
        }
        SetSW_Event(SWCFG_EVENTID_CHANGE(SwId));
        
         SW_FLT_LAST(SwId) = SW_FLT(SwId);    //save history filterd switch status
     }
     
}

/****************************************************************************************
| NAME:    DtrmSW_AdTypeRaw                                                                                               
| CALLED BY:    SwtAb_Handler(10 ms task)
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    NA
| RETURN VALUE:     NA
| DESCRIPTION:      Determine ADSW group status and switch status                       
****************************************************************************************/
static void DtrmSW_AdTypeRaw(void)
{
    uint8 GrupId; 
    uint8 Le_u_AdRangeIdRaw;
    
    for(GrupId = 0; GrupId < SWGRUP_NUM; GrupId++)
    {
        Le_u_AdRangeIdRaw = GetSW_u_AdRangeRaw(GrupId);

        /*undefined range (illegal range), note short to battery/ground and open circuit should be defiined*/
        if(CeIoHwAb_u_NullAdRangeId == Le_u_AdRangeIdRaw)
        {
            /*keep the previous value*/
        }
        else
        {
            VaSW_e_GrupSwEnumRaw[GrupId] = KaADSW_h_GrupInfo[GrupId].e_p_AdRngCal[Le_u_AdRangeIdRaw].m_e_SwEnum;
        }
        
        UpdtSW_AdRangeFlt(GrupId, Le_u_AdRangeIdRaw);
        UpdtSW_AdDscrtStat(GrupId);
    }

}

/****************************************************************************************
| NAME:    GetSW_u_AdRangeRaw                                                                                               
| CALLED BY:      DtrmSW_AdType                 
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    GrupId - AD group ID #
| RETURN VALUE:   
| DESCRIPTION: 
****************************************************************************************/
static uint8 GetSW_u_AdRangeRaw(uint8 GrupId)
{
    uint8 Le_u_AdRangeIdTemp;
    uint8 Le_u_AdRangeIdRaw;
    uint16 Le_w_ConvertedAdRaw;
    uint32 dwTmp;
    
    /*convert the AD raw Value to reference value*/
    dwTmp = *KaADSW_h_GrupInfo[GrupId].mp_w_AdRaw;

    dwTmp = dwTmp * KaADSW_h_GrupInfo[GrupId].e_w_SrcVoltRef /
                    *KaADSW_h_GrupInfo[GrupId].e_p_SrcVolt;
    if(dwTmp > ADC_CONF_RES)
    {
        Le_w_ConvertedAdRaw = ADC_CONF_RES;
    }
    else
    {
        Le_w_ConvertedAdRaw = (uint16)dwTmp;
    }
        
    /*find current AD value in range list to match one of the AD range of this switch
    *if match, save the ID and exit searching
    *matched range index means related switches are pressed.
    */
    Le_u_AdRangeIdRaw = CeIoHwAb_u_NullAdRangeId;   

    /*range is allowed crossing over each other, in this case, history range take higher priority.*/
    /*note, AD switch has possibly in previous voltage range in real world, so we always check the previous region first*/
    Le_u_AdRangeIdTemp = VaADSW_h_GrupStat[GrupId].m_u_PrevAdRangeId;
    if((Le_u_AdRangeIdTemp < SWCFG_ADRNG_SIZE(GrupId)) &&
        (Le_w_ConvertedAdRaw >= KaADSW_h_GrupInfo[GrupId].e_p_AdRngCal[Le_u_AdRangeIdTemp].wAD_Range_Low) &&
        (Le_w_ConvertedAdRaw <= KaADSW_h_GrupInfo[GrupId].e_p_AdRngCal[Le_u_AdRangeIdTemp].wAD_Range_High))
    {
        Le_u_AdRangeIdRaw = Le_u_AdRangeIdTemp;
    }
    /*If not in history range, low index range take higher priority*/
    /*Note AD range region may overlapped with each other, in this case, lower range has higher priority*/
    else
    {
        for(Le_u_AdRangeIdTemp = 0; Le_u_AdRangeIdTemp < SWCFG_ADRNG_SIZE(GrupId); Le_u_AdRangeIdTemp++)
        {
            if((Le_w_ConvertedAdRaw >= KaADSW_h_GrupInfo[GrupId].e_p_AdRngCal[Le_u_AdRangeIdTemp].wAD_Range_Low) &&
                (Le_w_ConvertedAdRaw <= KaADSW_h_GrupInfo[GrupId].e_p_AdRngCal[Le_u_AdRangeIdTemp].wAD_Range_High))
            {
                Le_u_AdRangeIdRaw = Le_u_AdRangeIdTemp;
                break;
            }        
        }
    }

    return Le_u_AdRangeIdRaw;
    
}

/****************************************************************************************
| NAME:    UpdtSW_AdRangeFlt                                                                                               
| CALLED BY:      DtrmSW_AdType        
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    GrupId - AD group ID #
|                                   Le_u_AdRangeIdRaw - current AD input Range Id, Note: RngId maybe a illegal ID!
| RETURN VALUE: 
| DESCRIPTION:      determine discrete switch due to group id and range id when debounce time pass.
****************************************************************************************/
static void UpdtSW_AdRangeFlt(uint8 GrupId, uint8 Le_u_AdRangeIdRaw)
{
    uint8 Le_u_CurrAdRangeId_Flt;
    uint8 Le_u_PrevAdRangeId_Flt;

    Le_u_PrevAdRangeId_Flt = VaADSW_h_GrupStat[GrupId].m_u_AdRangeId_Flt;
    
     /*update group timer and last group id*/
    if(Le_u_AdRangeIdRaw != VaADSW_h_GrupStat[GrupId].m_u_PrevAdRangeId)
    {
        VaSW_w_AdGrupTimer[GrupId] = 0; 
        VaADSW_h_GrupStat[GrupId].m_u_PrevAdRangeId = Le_u_AdRangeIdRaw;
    }
    else
    {
        if(VaSW_w_AdGrupTimer[GrupId] < 0xFFFF)
        {
            VaSW_w_AdGrupTimer[GrupId] ++; 
        }
    }  

    /*update filtered range ID and set a flag if group range is debounced*/
    /*note AD switch stuck diagnostic is also detected in common switch module*/
    if(VaSW_w_AdGrupTimer[GrupId] >= KaADSW_h_GrupInfo[GrupId].e_w_SwDbcTime)
    {
        Le_u_CurrAdRangeId_Flt = Le_u_AdRangeIdRaw;
        VaADSW_h_GrupStat[GrupId].m_u_AdRangeId_Flt = Le_u_CurrAdRangeId_Flt;
        VaSW_e_GrupSwEnumFlt[GrupId] = VaSW_e_GrupSwEnumRaw[GrupId];
    }

    /*EVENT- range changed event occur, set event ID and update last filtered range ID*/
    if(Le_u_CurrAdRangeId_Flt  !=  Le_u_PrevAdRangeId_Flt)
    {
        SetSW_Event(SWCFG_ADGRUP_EVENTID_RNGCHNG(GrupId));
        //SetSW_Event(SWCFG_ADGRUP_EVENTID_RNGCHNG_ARR(GrupId,Le_u_CurrAdRangeId_Flt));
    }
    
}

/****************************************************************************************
| NAME:    UpdtSW_AdDscrtStat                                                                                               
| CALLED BY:      DtrmSW_AdType                         
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    GrupId - AD group ID #
| RETURN VALUE:  
| DESCRIPTION:      determine discrete switch due to group id and range id when debounce time pass.
****************************************************************************************/
static void UpdtSW_AdDscrtStat(uint8 GrupId)
{
    //uint8 Le_u_AdRangeIdFlt;
    //TeSW_CmmnFailFlags Le_h_CmmnFFlg;
   // uint8 Le_u_SwIdBitMask;
    //const uint8 * DATA_FAR Lp_u_AdSwId;
    //TeSW_AdRangeType Le_e_AdRangeType;
    //uint8 SwId;
#if 0
    Le_u_AdRangeIdFlt = VaADSW_h_GrupStat[GrupId].m_u_AdRangeId_Flt;
    Le_e_AdRangeType = KaADSW_h_GrupInfo[GrupId].e_p_AdRngCal[Le_u_AdRangeIdFlt].m_e_AdRangeType;
    Lp_u_AdSwId = &KaADSW_h_GrupInfo[GrupId].e_p_SwId[0];
    Le_u_SwIdBitMask = KaADSW_h_GrupInfo[GrupId].e_p_AdRngCal[Le_u_AdRangeIdFlt].e_u_BitMask;

    /*Update some failure flags of all related discrete switches when AD range is debounced*/
    if(Lp_u_AdSwId != NULL)
    {
    SwId = *Lp_u_AdSwId;
    }
    else
    {
        SwId = CeIoHwAb_e_SwIdNull;
    }
    while(CeIoHwAb_e_SwIdNull != SwId)
    {
        SET_SW_DBCPASS(SwId);
        /*get descrete input when range id is defined(although it may be defined as illeage range)*/
        if(Le_u_AdRangeIdFlt != CeIoHwAb_u_NullAdRangeId)
        {  
            /*Update discrete switch raw value*/
            SW_RAW(SwId) = ((Le_u_SwIdBitMask & 0x01) > 0);
            Le_u_SwIdBitMask >>= 1;
            
            /*Update releated switches' failure flag by this range property*/
            Le_h_CmmnFFlg.Byte = VaSW_h_CmmnFFlg[SwId].Byte;
            Le_h_CmmnFFlg.Bits.e_b_ShrtBat = (CeIoHwAb_e_AdRangeIllegal == Le_e_AdRangeType);  /*defined illegal range*/
            Le_h_CmmnFFlg.Bits.e_b_ShrtBat = (CeIoHwAb_e_AdRangeShortBat == Le_e_AdRangeType);
            Le_h_CmmnFFlg.Bits.e_b_ShrtGnd = (CeIoHwAb_e_AdRangeShortGnd == Le_e_AdRangeType);
            Le_h_CmmnFFlg.Bits.e_b_OpenC = (CeIoHwAb_e_AdRangeOpenLoad== Le_e_AdRangeType);
        }

        /*clear switch Raw value if in undefined-range*/
        else
        {
            SW_RAW(SwId) = FALSE;
            Le_h_CmmnFFlg.Bits.e_b_IllglRng = 1;    /*un-defined illegal range*/
        }
        /*Update Failure flags of each related switch*/
        VaSW_h_CmmnFFlg[SwId].Byte = Le_h_CmmnFFlg.Byte;

        /*next switch ID*/
        Lp_u_AdSwId++;
        SwId = *Lp_u_AdSwId;
        
    }
#endif
}

/****************************************************************************************
| NAME:    DtrmSW_Status                                                                                               
| CALLED BY:    10 ms task schedule                                        
| PRECONDITIONS: Raw input is determined                                     
| INPUT PARAMETERS:    NA
| RETURN VALUE:     NA
| DESCRIPTION:      Determine filtered switch status by raw input.
****************************************************************************************/
static void DtrmSW_Status(void)
{
    uint8 Le_u_SwId;
    uint16 LeSW_w_StatusTimer;
    boolean LeSW_b_Stucked;  /*this local var is for speed optimizing*/
    boolean LeSW_b_MaxPrsTimeout;  /*this local var is for speed optimizing*/
    boolean LeSW_b_VoltOutRange;  /*this local var is for speed optimizing*/
    
    /*x10 scaled battery voltage*/
    uint8 Le_u_BatVolt;   
    
    for(Le_u_SwId=0; Le_u_SwId<SWID_NUM; Le_u_SwId++)
    {
        LeSW_w_StatusTimer = VaSW_w_CmmnTimer[Le_u_SwId];  /*save for later use, this local var is for speed optimizing*/
        
        /*reset timer if raw input changed; if no change, increase counter*/
        if(SW_RAW_LAST(Le_u_SwId) !=  SW_RAW(Le_u_SwId))
        {
            LeSW_w_StatusTimer = 0;
            CLR_SW_DBCPASS(Le_u_SwId);
        }
        else if(LeSW_w_StatusTimer < 0xFFFF)
        {
            LeSW_w_StatusTimer++;
        }
        else
        {}
        VaSW_w_CmmnTimer[Le_u_SwId] = LeSW_w_StatusTimer;

        /*Diagnostic if momentary switches is stucked or timeout the max pressed time*/
        /*if momentary switch is pressed, check the counter and determine the failure status*/
        LeSW_b_MaxPrsTimeout = 0;
        LeSW_b_Stucked = 0;
        if(SWCFG_MOMENTARY(Le_u_SwId) && SW_RAW(Le_u_SwId))
        {
            if((SWCFG_MAXPRSTIME(Le_u_SwId) > 0) &&
                (LeSW_w_StatusTimer >= SWCFG_MAXPRSTIME(Le_u_SwId)))
            {
                LeSW_b_MaxPrsTimeout = 1;
            }
            else
            {
                LeSW_b_MaxPrsTimeout = 0;
            }
            
            if((SWCFG_STUCKTIME(Le_u_SwId) > 0) &&
                (LeSW_w_StatusTimer >= SWCFG_STUCKTIME(Le_u_SwId)))
            {
                LeSW_b_Stucked = 1;
            }
            else
            {
                LeSW_b_Stucked = 0;
            }
            VaSW_h_CmmnFFlg[Le_u_SwId].Bits.e_b_MaxPrsTim = LeSW_b_MaxPrsTimeout;
            VaSW_h_CmmnFFlg[Le_u_SwId].Bits.e_b_Stck = LeSW_b_Stucked;
        }        

        /*determine if switch voltage range is OK*/
        if(IoHwAb_GetBatVoltStat())
        {
            Le_u_BatVolt = IoHwAb_GetBatVoltFlt() /10u;        
            if((Le_u_BatVolt < SWCFG_BAT_VOLT_LOW(Le_u_SwId)) ||
                (Le_u_BatVolt > SWCFG_BAT_VOLT_HIGH(Le_u_SwId)))
            {
                LeSW_b_VoltOutRange = TRUE;
            }
            else
            {
                LeSW_b_VoltOutRange = FALSE;
            }
            VaSW_h_CmmnFFlg[Le_u_SwId].Bits.e_b_BVOR = LeSW_b_VoltOutRange;
        }
        
        /*if diagnostic info show error, use default value as filtered value
        * else, use debouced value as filtered value
        * Note battery voltage has affectted the raw value, not directly affect debounced value here.
        */
        if(LeSW_b_MaxPrsTimeout || LeSW_b_Stucked)
        {
            SW_FLT(Le_u_SwId) = FALSE;
        }
        else if(LeSW_b_VoltOutRange)
        {
            if(CeSW_FA_UseTrue == SWCFG_BAT_VOLT_ERRACT(Le_u_SwId))
            {
                SW_FLT(Le_u_SwId) = TRUE;
            }
            else if(CeSW_FA_UseFalse == SWCFG_BAT_VOLT_ERRACT(Le_u_SwId))
            {
                SW_FLT(Le_u_SwId) = FALSE;
            }
            else
            {/*use history value*/}        
        }
        else if((FALSE == GET_SW_DBCPASS(Le_u_SwId)) &&
                  (LeSW_w_StatusTimer >= SWCFG_DBCTIME(Le_u_SwId)))
        {   
            SET_SW_DBCPASS(Le_u_SwId);
            UpdtSW_FltStat(Le_u_SwId);  
        }
        else
        {}

        /*save last switch status*/
        SW_RAW_LAST(Le_u_SwId) = SW_RAW(Le_u_SwId);
        
        /* Detect switch change event and update last switch filtered state */
        TrigSW_EvtOnChng(Le_u_SwId); 
    }


}

static void DtrmSW_sendsignal(void)
{
	boolean_T FlToPsSwAtv = (boolean_T)0 ;
	static boolean_T FlToPsSwAtv_last = (boolean_T)0;

	boolean_T WSWshSwAtv = (boolean_T)0 ;
	static boolean_T WSWshSwAtv_last = (boolean_T)0 ;

	boolean_T RrClosAjarSwAct = (boolean_T)0 ;
	static boolean_T RrClosAjarSwAct_last = (boolean_T)0 ;

/*
	boolean_T PDAjrSwAtv = (boolean_T)0;
	static boolean_T PDAjrSwAtv_last = (boolean_T)0;

	boolean_T DDAjrSwAtv = (boolean_T)0;
	static boolean_T DDAjrSwAtv_last = (boolean_T)0;
*/
	boolean_T HdStV = (boolean_T)0;
	static boolean_T HdStV_last = (boolean_T)0;
	
	FlToPsSwAtv = PnRte_Read_ElsFtpFlt();
	if(FlToPsSwAtv != FlToPsSwAtv_last)
	{
		//Com_SendSignal(Com_Com_FlToPsSwAtv__Lighting_Status_BB__BB, &FlToPsSwAtv);
		PN_SendSingleSignal(Com_Com_FlToPsSwAtv__Lighting_Status_BB__BB, &FlToPsSwAtv, TRUE, ComM_UserPN03);
		FlToPsSwAtv_last = FlToPsSwAtv;	
	}

	WSWshSwAtv = PnRte_Read_WipWndShieldWashFlt();
	if(WSWshSwAtv != WSWshSwAtv_last)
	{
		Com_SendSignal(Com_Com_WSWshSwAtv__Wipe_Wash_Status_BB__BB, &WSWshSwAtv);
		WSWshSwAtv_last = WSWshSwAtv;
	}

	RrClosAjarSwAct = PnRte_Read_EcRearClsrOpnFlt() ;
	if(RrClosAjarSwAct != RrClosAjarSwAct_last)
	{
		Com_SendSignal(Com_Com_RrClosAjarSwAct__Rear_Closure_Ajar_Switch_Status__BB, &RrClosAjarSwAct);
		RrClosAjarSwAct_last =  RrClosAjarSwAct;
	}

/*
	PDAjrSwAtv = IoHwAb_GetIDL21();
       if(PDAjrSwAtv != PDAjrSwAtv_last )
       {
		Com_SendSignal(Com_Com_PDAjrSwAtv__Passenger_Door_Status_BB__BB, &PDAjrSwAtv);
		PDAjrSwAtv_last = PDAjrSwAtv;
       }

       DDAjrSwAtv = IoHwAb_GetIDL20();
	if(DDAjrSwAtv != DDAjrSwAtv_last)  
	{
		Com_SendSignal(Com_Com_DDAjrSwAtv__Driver_Door_Status__BB, &DDAjrSwAtv);
	}
*/

	HdStV = IoHwAb_GetIA3Isg();
	if(HdStV != HdStV_last)
	{
		Com_SendSignal(Com_Com_HdStV__Hood_Status_BB__BB, &HdStV);
		HdStV_last = HdStV;
	}
	
}

#if 0
/****************************************************************************************
| NAME:  InitSW_OnSysRst                                                                                     
| CALLED BY:   System reset initialization, after KAM initialized.                           
| PRECONDITIONS:                                             
| INPUT PARAMETERS:   
| RETURN VALUE:     
| DESCRIPTION:                       
****************************************************************************************/
void InitSW_OnSysRst(void)
{
    uint8 i;
    boolean bTemp;

    /*Copy KAM value if KAM integration is OK*/
    if(FALSE == GetKAM_b_RunKamRstFlg())
    {
        (void)memcpy((uint8 *)VaSW_h_CmmnStat, 
                        (uint8 *)RaSW_h_CmmnStat, SWID_NUM * sizeof(TeSW_CmmnStat));
    }

    for(i=0;i<SWID_NUM;i++)
    {
        /*when KAM reset, or switch is not KAM Enable, init switch with default value*/
        if((FALSE == SWCFG_KAM_ENABLE(i)) ||
            (TRUE == GetKAM_b_RunKamRstFlg()))
        {
            bTemp = SWCFG_DEFAULT_VAL(i);
            SW_STATUS(i) = 0x0000;
            SW_FLT(i) = bTemp;
            SW_FLT_LAST(i) = bTemp;
        }
    }  
    
}


/****************************************************************************************
| NAME:  SavSW_PreSysSleep                                                                                     
| CALLED BY:   Before enter sleep.                           
| PRECONDITIONS:                                             
| INPUT PARAMETERS:   
| RETURN VALUE:     
| DESCRIPTION:                       
****************************************************************************************/
void SavSW_PreSysSleep(void)
{

    PutKAM_ArrayData((uint8 *)RaSW_h_CmmnStat,
                (uint8 *)VaSW_h_CmmnStat, SWID_NUM * sizeof(TeSW_CmmnStat));

}







/****************************************************************************************
| NAME:    ProcSW_PreSleep                                                                                               
| CALLED BY:                        
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    
| RETURN VALUE:     NA
| DESCRIPTION:      process switch before goto sleep.
****************************************************************************************/
void ProcSW_PreSleep(void)
{
    /*add KAM variables*/
    
}

/****************************************************************************************
| NAME:    UpdtSW_OBDIStatus                                                                                               
| CALLED BY: SwtAb_Handler (10ms)
| PRECONDITIONS:                                             
| INPUT PARAMETERS:    
| RETURN VALUE:     NA
| DESCRIPTION:      on board digital input switch status
****************************************************************************************/
static void UpdtSW_OBDIStatus(void)
{
    uint8 uOBDIid;
    uint8 uDinReg;
    uint8 uOffset;
    TeSW_h_OBDIInfo *LpSW_h_OBDIInfo;

    LpSW_h_OBDIInfo = KaSW_h_OBDIInfo;
    for(uOBDIid=0;uOBDIid<OBDI_Num;uOBDIid++)
    {
        if(LpSW_h_OBDIInfo->e_b_Enable)
        {
            uDinReg = *(LpSW_h_OBDIInfo->e_p_Port);
            uOffset = LpSW_h_OBDIInfo->e_u_Offset;
            
            if((uDinReg & (1<< uOffset)) > 0)
            {
                SetOBDI_Stat(uOBDIid, TRUE);
            }
            else
            {
                SetOBDI_Stat(uOBDIid, FALSE);
            }
        }
	 LpSW_h_OBDIInfo++;
	
    }
}

/****************************************************************************************
| NAME:    ScanSW_WkupPort                                                                                               
| CALLED BY: ProcPWR_SleepWake() : API wakeup or EPM sleep-awake task
| PRECONDITIONS:                                             
| INPUT PARAMETERS:     
| RETURN VALUE:   Switch ID whick wake up system
|                           255 - no wakeup port active
| DESCRIPTION:      
****************************************************************************************/
uint8 ScanSW_WkupPort(void)
{
    uint8 uSwId;
    uint8 uDgtlSwId;
    uint8 uWkupTyp;
    TeSW_CmmnSwInfo * Lp_h_CmmSwInfo; /*near pointer*/
    uint8 Le_u_BatVolt;
    boolean bLastSwRawStat;
    boolean bCurSwRawStat;
    boolean bWkupActive=FALSE;
    uint8 Ret;

    Le_u_BatVolt = VePWR_h_BatVolt.e_w_ScaledBatVolt /10;
    
    for(uSwId=0;uSwId<SWID_NUM;uSwId++)
    {
        Lp_h_CmmSwInfo = &KaSW_h_CmmnSwInfo[uSwId];
        uWkupTyp = Lp_h_CmmSwInfo->e_h_CmmnMisc.Bits.e_u2_WkupTyp;
        
        /*Get switch handle id from list, only digital wake up port are supported*/
        if((CeSW_u_WkupTypNoWkup != uWkupTyp) &&
            (uSwId <= SWID_DIGITAL_LAST))
        {
            uDgtlSwId = uSwId;
   
            /*determine switch raw input by powermode*/
            if((TRUE == SWCFG_ENABLED(uDgtlSwId)) &&
                (Le_u_BatVolt >= KaSW_h_DgtlSwInfo[uDgtlSwId].e_u_BatVoltLo) &&
                (Le_u_BatVolt <= KaSW_h_DgtlSwInfo[uDgtlSwId].e_u_BatVoltHi))
            {
                /*check if switch is pressed this time (not consider debouce here)*/
                if((SWCFG_PRS_IS_HIGH(uDgtlSwId) && 
                        Read_Buf_Bit(DGTLSW_DATASRC(uDgtlSwId), DGTLSW_BITIDX(uDgtlSwId)) )||
                    ((FALSE == SWCFG_PRS_IS_HIGH(uDgtlSwId)) && 
                        (FALSE == Read_Buf_Bit(DGTLSW_DATASRC(uDgtlSwId), DGTLSW_BITIDX(uDgtlSwId)))) )
                {
                    bCurSwRawStat = TRUE;
                }
                else
                {
                    bCurSwRawStat = FALSE;
                }

                /*Compare Raw State and determine if wakeup*/
                bLastSwRawStat = SW_RAW(uSwId);
                SW_RAW(uSwId) = bCurSwRawStat;
                if((bLastSwRawStat != bCurSwRawStat) &&
                  (((CeSW_u_WkupTypPosEdge == uWkupTyp) && (TRUE==bCurSwRawStat)) ||
                        ((CeSW_u_WkupTypNegEdge == uWkupTyp) && (FALSE==bCurSwRawStat)) ||
                        (CeSW_u_WkupTypBiEdge == uWkupTyp)) )
                {
                    bWkupActive = TRUE;
                    break; /*exit for*/
                }
            }
        }
    }

    if(bWkupActive)
    {
        Ret = uSwId;
    }
    else
    {
        Ret = 255;
    }

    return Ret;
    
}

#endif

