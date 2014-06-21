/*****************************************************************************
|File Name:  IoHwAb_Do.c
|
|Description:  Abstracted digital output channels.
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
|2012-05-02  01.00.00     WangHui      Create
*****************************************************************************/


/******************************************************************************
**                      Include Section                                      **
******************************************************************************/
#include "Std_Macro.h"
#include "IoHwAb_Do.h"
#include "IoHwAb_DoTypes.h"

/*******************************************************************************
|    Macro Declaration
|******************************************************************************/
#define CeDO_u_BufferSize     ((CeIoHwAb_u_DoNumber+7)/8)

/*******************************************************************************
|    Global Variables Declaration
|******************************************************************************/





/*******************************************************************************
|    Static Local Variables Declaration
|******************************************************************************/

/*When learn K value, disable output overload protect*/
static boolean VeAPI_b_OutPrtctDsbl;

/* Buffer indicates APP control status, bitfield operation*/
static uint8 VaAPI_u_AppOutput[CeDO_u_BufferSize] = {0};
/* Buffer indicates if diagnostic override control request is active or not*/
static uint8 VaAPI_u_AECtrlReqActv[CeDO_u_BufferSize] = {0};
/* Buffer indicates that if output proection is active due to reasons like over current. */
static uint8 VaAPI_u_OutPrtctActv[CeDO_u_BufferSize] = {0};
/* Buffer indicates the current actual output status for each MCU IO or MSDI IO. */
static uint8 VaAPI_u_ActualOutStatus[CeDO_u_BufferSize] = {0};

static uint8 VaDoAb_u_OutOfVolt[CeDO_u_BufferSize] = {0};

#define GetDO_b_DevCtrlReq(EcuDoutId) Read_Buf_Bit(VaAPI_u_AECtrlReqActv, EcuDoutId)
#define SetDO_DevCtrlReq(EcuDoutId) Set_Buf_Bit(VaAPI_u_AECtrlReqActv, EcuDoutId)
#define ClrDO_DevCtrlReq(EcuDoutId) Clr_Buf_Bit(VaAPI_u_AECtrlReqActv, EcuDoutId)

#define GetDO_b_AppCtrlVal(EcuDoutId)   Read_Buf_Bit(VaAPI_u_AppOutput, EcuDoutId)
#define SetDO_AppCtrlVal(EcuDoutId)   Set_Buf_Bit(VaAPI_u_AppOutput, EcuDoutId)
#define ClrDO_AppCtrlVal(EcuDoutId)   Clr_Buf_Bit(VaAPI_u_AppOutput, EcuDoutId)

#define GetHWIO_b_OutPrtctActvByEcuDoutId(EcuDoutId) Read_Buf_Bit(VaAPI_u_OutPrtctActv, EcuDoutId)
#define SetHWIO_OutPrtctActvByEcuDoutId(EcuDoutId) Set_Buf_Bit(VaAPI_u_OutPrtctActv, EcuDoutId)
#define ClrHWIO_OutPrtctActvByEcuDoutId(EcuDoutId) Clr_Buf_Bit(VaAPI_u_OutPrtctActv, EcuDoutId)

#define GetDO_b_BufferVal(EcuDoutId) Read_Buf_Bit(VaAPI_u_ActualOutStatus, EcuDoutId)
#define SetDO_BufferVal(EcuDoutId) Set_Buf_Bit(VaAPI_u_ActualOutStatus, EcuDoutId)
#define ClrDO_BufferVal(EcuDoutId) Clr_Buf_Bit(VaAPI_u_ActualOutStatus, EcuDoutId)

/*Get/Set Dout out of voltage range flag*/
#define GetHWIO_b_DoutOutOfRng(DoId)    Read_Buf_Bit(VaDoAb_u_OutOfVolt, DoId)
#define SetHWIO_DoutOutOfRng(DoId)    Set_Buf_Bit(VaDoAb_u_OutOfVolt, DoId)
#define ClrHWIO_DoutOutOfRng(DoId)    Clr_Buf_Bit(VaDoAb_u_OutOfVolt, DoId)

/*******************************************************************************
|    Extern variables and functions declaration
|******************************************************************************/

/***************************************************************************************************
 | NAME:               DoAb_Init
 | CALLED BY:          
 | PRECONDITIONS:    
 | INPUT PARAMETERS:  
 | RETURN VALUE:       
 | DESCRIPTION:      
 |***************************************************************************************************/
void	DoAb_Init(void)
{
    uint8 i;
    
    VeAPI_b_OutPrtctDsbl=FALSE;
    for(i=0;i<CeDO_u_BufferSize;i++)
    {
        VaAPI_u_AppOutput[i] = 0;
        VaAPI_u_AECtrlReqActv[i]=0;
        VaAPI_u_OutPrtctActv[i]=0;
        VaAPI_u_ActualOutStatus[i]=0;
        VaDoAb_u_OutOfVolt[i]=0;
    }
    
}

/***************************************************************************************************
 | NAME:               UpdateIoHwAb_DoChannel
 | CALLED BY:          
 | PRECONDITIONS:    
 | INPUT PARAMETERS:  
 | RETURN VALUE:       
 | DESCRIPTION:      Update DO channel, if DO is Dio type, update is implemented immediately; if DO is SPI buffer type, 
 |                             output is updated when SPI is implemented.
 |***************************************************************************************************/
void	DoAb_UpdateChannel(void)
{
    TsDO_h_PortConfig *Lp_h_PortConfig;
    uint8 Le_u_DoChannel=CeIoHwAb_u_DoNumber;
    boolean Le_b_DoValue=FALSE;

    for(Le_u_DoChannel=0;Le_u_DoChannel<CeIoHwAb_u_DoNumber;Le_u_DoChannel++)
    {
        Lp_h_PortConfig = (TsDO_h_PortConfig *)&KaDO_h_PortConfig[Le_u_DoChannel];
        
        if(Lp_h_PortConfig->e_bt_En)
        {
            /*use default value if output is protected by voltage or HSD overload*/
            if((FALSE == VeAPI_b_OutPrtctDsbl) &&
                    ((TRUE == GetHWIO_b_OutPrtctActvByEcuDoutId( Le_u_DoChannel))|| 
                    (TRUE == GetHWIO_b_DoutOutOfRng(Le_u_DoChannel))))
            {
                Le_b_DoValue = Lp_h_PortConfig->e_bt_DftVal;
            }
            else
            {
                Le_b_DoValue = GetDO_b_BufferVal( Le_u_DoChannel);
            }
            
            /*convert application logical value to low level value*/
            if(Lp_h_PortConfig->e_b_Inverse)
            {
                Le_b_DoValue = !Le_b_DoValue;
            }

            /*map value to DIO or buffer*/
            if(CeDO_u_DioType == Lp_h_PortConfig->m_u_DoType)
            {
                Dio_WriteChannel(Lp_h_PortConfig->m_u_Offset, Le_b_DoValue);
            }
            else if(CeDO_u_BufferType == Lp_h_PortConfig->m_u_DoType)
            {
                if(Le_b_DoValue)
                {
                    SET_BIT(*(Lp_h_PortConfig->m_p_Buffer), Lp_h_PortConfig->m_u_Offset);
                }
                else
                {
                    CLR_BIT(*(Lp_h_PortConfig->m_p_Buffer), Lp_h_PortConfig->m_u_Offset);
                }
            }
            else
            {}        
        }
    }
}


/***************************************************************************************************
 | NAME:               SetDO_DevCtrl
 | CALLED BY:          
 | PRECONDITIONS:    
 | INPUT PARAMETERS:  Le_b_value - true: active; false:inactive
 |                                  Le_e_DoId - DO id
 | RETURN VALUE:       
 | DESCRIPTION:     Set device control value active/inactive, note the real output logic is determined by configuration.
 |***************************************************************************************************/
void SetDO_DevCtrl(TeIoHwAb_e_DoIds Le_e_DoId, boolean Le_b_value)
{
    SetDO_DevCtrlReq(Le_e_DoId);
    
    if(Le_b_value)
    {
        SetDO_BufferVal(Le_e_DoId);
    }
    else
    {
        ClrDO_BufferVal(Le_e_DoId);
    }
}

 /***************************************************************************************************
 | NAME:               ClrDO_DevCtrl
 | CALLED BY:          
 | PRECONDITIONS:    
 | INPUT PARAMETERS:  Le_b_value - true: active; false:inactive
 |                                  Le_e_DoId - DO id
 | RETURN VALUE:       
 | DESCRIPTION:     clear device control value, note the real output logic is determined by configuration.
 |***************************************************************************************************/
void ClrDO_DevCtrl(TeIoHwAb_e_DoIds Le_e_DoId)
{
    ClrDO_DevCtrlReq(Le_e_DoId);
    
    if(GetDO_b_AppCtrlVal(Le_e_DoId))
    {
        SetDO_BufferVal(Le_e_DoId);
    }
    else
    {
        ClrDO_BufferVal(Le_e_DoId);
    }
}

/***************************************************************************************************
 | NAME:               SetDO_AppCtrl
 | CALLED BY:          
 | PRECONDITIONS:    
 | INPUT PARAMETERS:  Le_b_value - true: active; false:inactive
 |                                  Le_e_DoId - DO id
 | RETURN VALUE:       
 | DESCRIPTION:     Set device control value active/inactive, note the real output logic is determined by configuration.
 |***************************************************************************************************/
void SetDO_AppCtrl(TeIoHwAb_e_DoIds Le_e_DoId, boolean Le_b_value)
{  
    if(Le_b_value)
    {
        SetDO_AppCtrlVal(Le_e_DoId);
        if(FALSE==GetDO_b_DevCtrlReq(Le_e_DoId))
        {
            SetDO_BufferVal(Le_e_DoId);
        }
    }
    else
    {
        ClrDO_AppCtrlVal(Le_e_DoId);
        if(FALSE==GetDO_b_DevCtrlReq(Le_e_DoId))
        {
            ClrDO_BufferVal(Le_e_DoId);
        }        
    }
}

/***************************************************************************************************
 | NAME:               GetDO_OutputVal
 | CALLED BY:          
 | PRECONDITIONS:    
 | INPUT PARAMETERS:  Le_e_DoId - DO id
 | RETURN VALUE:       true: active; false:inactive
 | DESCRIPTION:     Get output value active/inactive.
 |***************************************************************************************************/
boolean GetDO_OutputVal(TeIoHwAb_e_DoIds Le_e_DoId)
{
    return GetDO_b_BufferVal(Le_e_DoId);
}

/*EOF*/

