#ifndef _COMPILER_H
#define _COMPILER_H

/*Select memroy mapping file
*if greenhills, use MemMap_GHS.h
*if CX, use MemMap_CX.h
* Note, for sourceinsight parser, comments the unused option with "//"
*/
#define COMPILER_GHS  1
//#define COMPILER_CX   1

#define __32_BIT_MCU

#if COMPILER_GHS
#include "Compiler_GHS.h"
#elif COMPILER_CX  
#include "Compiler_CX.h"
#endif


#endif

