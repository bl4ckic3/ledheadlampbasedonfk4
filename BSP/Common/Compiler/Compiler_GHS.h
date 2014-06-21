
#ifndef COMPILER_H 
#define COMPILER_H  

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Compiler_Cfg.h"    /* Module specific memory and pointer */


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/


#define INLINE  inline
#define STATIC  static
#define _INTERRUPT_  __interrupt
#ifndef INTERRUPTFUC
   #define INTERRUPTFUC interrupt
#endif
#define OsAppMode			0
#ifndef _GREENHILLS_C_V850_
  #define _GREENHILLS_C_V850_
#endif

#ifndef NULL_PTR
  #define NULL_PTR  ((void *)0)                       
#endif

#ifndef NULL
   #define NULL ((void *)0)
#endif

/*far: data pointer in FK4 is always 32bit*/
#define    DATA_FAR
#define    CONST_FAR
#define    FUNC_FAR
#define    far

/* AUTOMATIC used for the declaration of local pointers */
#define AUTOMATIC

/* TYPEDEF used for defining pointer types within type definitions */
#define TYPEDEF

/* Type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
   fctname     function name respectively name of the defined type
 */
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

/* The compiler abstraction shall define the FUNC macro for the declaration and
   definition of functions, that ensures correct syntax of function 
   declarations as required by a specific compiler. - used for API functions
   rettype     return type of the function
   memclass    classification of the function itself
 */
#define FUNC(type, memclass)  type

/* Pointer to constant data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define P2CONST(ptrtype, memclass, ptrclass)  const ptrtype *

/* Pointer to variable data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/* Const pointer to variable data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

/* Const pointer to constant data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

/* ROM constant
   type        type of the constant
   memclass    classification of the constant
 */
#define CONST(type, memclass) const type

/* RAM variables
   type        type of the variable
   memclass    classification of the variable
 */
#define VAR(type, memclass) type


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* COMPILER_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
