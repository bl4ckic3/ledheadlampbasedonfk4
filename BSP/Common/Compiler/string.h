
#ifndef _STRING_H
#define _STRING_H

#include "CompilerSelect.h"

#if COMPILER_GHS
/*lib file libstartup.a include all the functions in string.h, so you need only to include the libstartup.a to your project.*/
#elif COMPILER_CX
#include <string.h>
#else
#error "Compiler is not selected!"
#endif




#endif
/*EOF*/

