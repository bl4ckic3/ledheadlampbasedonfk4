
/*******************************************************************************
|    Include Session
|******************************************************************************/
#include "IoHwAb_Can.h"

/*******************************************************************************
|    Static Local Variables Declaration
|******************************************************************************/


/*******************************************************************************
|    Extern variables and functions declaration
|******************************************************************************/
/****************************************************************************** 
*                       Can Global Symbols                                   ** 
******************************************************************************/ 
uint8 GaaByteArrayCan[8] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
uint8 GaaByteArrayCanRdData[8] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
|    Global Function Prototypes 
|******************************************************************************/
void Can_MainFunction_20mS(void){
	
	uint8 LucHthId; 
	Can_PduType LddCanPduType;
	uint32 loopcnt;
	
	Can_MainFunction_Read();
	Can_MainFunction_Write();
	Can_MainFunction_BusOff();
	Can_MainFunction_Wakeup();
	
	/* Debug Useing */
	/* Transmit an L-PDU for Controller 1 */
	LucHthId = 2;
	LddCanPduType.length = 0x08;
	LddCanPduType.swPduHandle = 0x55;
	LddCanPduType.id = 0x120;
	LddCanPduType.sdu = &GaaByteArrayCan[0];
	Can_Write(LucHthId, &LddCanPduType);
	
	/* for wait trasmit over@abs time */
	for(loopcnt=0;loopcnt<100000;loopcnt++){};
	
	Can_MainFunction_Read();
	CanIf_ReadRxData(0x01,0x08,&GaaByteArrayCanRdData);
	
}
