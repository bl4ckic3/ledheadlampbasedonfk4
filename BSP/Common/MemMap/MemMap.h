
/*this file must allow be included multi-times*/

#include "Compiler.h"

#if COMPILER_GHS
#include "MemMap_GHS.h"
#elif COMPILER_CX   
#include "MemMap_CX.h"
#endif


