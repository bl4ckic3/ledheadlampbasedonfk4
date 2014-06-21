
#ifndef _STD_MACRO_H
#define _STD_MACRO_H

#include "Std_Types.h"

#define READ_BIT(data, bit)     ((0x0 != ((data)& (uint8)(1<<(bit))))?TRUE:FALSE)
#define SET_BIT(data, bit)   ((data) |= (uint8)(1<<(bit)))
#define CLR_BIT(data, bit) ((data) &= (uint8)~(1<<(bit)))
#define RVS_BIT(data, bit) ((data) ^= (uint8)(1<<(bit)))

/*bitID = switch index*/
#define GetByteIndex(bitID)            ((bitID)>>3)
#define GetBitsIndex(bitID)            ((bitID)%8)
/* pBuf = (uint8 *) */
#define Set_Buf_Bit(pBuf,bitID)       SET_BIT(*((uint8 *)(pBuf)+ GetByteIndex(bitID)),GetBitsIndex(bitID))
#define Clr_Buf_Bit(pBuf,bitID)     CLR_BIT(*((uint8 *)(pBuf)+ GetByteIndex(bitID)),GetBitsIndex(bitID))
#define Rvs_Buf_Bit(pBuf,bitID)          RVS_BIT(*((uint8 *)(pBuf) + GetByteIndex(bitID)),GetBitsIndex(bitID))
#define Read_Buf_Bit(pBuf,bitID)         READ_BIT(*((uint8 *)(pBuf)+ GetByteIndex(bitID)),GetBitsIndex(bitID))
#define Ctrl_Buf_Bit(pBuf,bitID,Ctrl_Flag)   { \
                                                                        if (TRUE == (Ctrl_Flag)) \
                                                                        {                         \
                                                                            Set_Buf_Bit(pBuf,bitID);\
                                                                        }                         \
                                                                        else                      \
                                                                        {                         \
                                                                            Clr_Buf_Bit(pBuf,bitID);\
                                                                        }                         \
                                                                    } 
                                                                    
#endif

/*EOF*/

