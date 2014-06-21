
/*define interrupt type*/

#ifndef _INTERRUPT_TYPE_H
#define _INTERRUPT_TYPE_H

#include "CompilerSelect.h"


#if COMPILER_GHS
#define PRAGMA_INTERRUPT()          _Pragma("ghs interrupt")
#elif COMPILER_CX
#define PRAGMA_INTERRUPT(x)          _Pragma("interrupt NO_VECT "##x)
#else
#error "compiler is not specified, select the compiler in \"CompilerSelect.h\" "
#endif

#endif

