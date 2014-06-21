
/******************************************************************************/

#ifndef COMPILER_H 
#define COMPILER_H  

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Compiler_Cfg.h"    /* Module specific memory and pointer */
                             

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define COMPILER_AR_MAJOR_VERSION  2
#define COMPILER_AR_MINOR_VERSION  0
#define COMPILER_AR_PATCH_VERSION  0

/*
 * File version information
 */
#define COMPILER_SW_MAJOR_VERSION  3
#define COMPILER_SW_MINOR_VERSION  0
#define COMPILER_SW_PATCH_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*
 * Compiler abstraction symbols
 */

#define INLINE  inline
#define STATIC  static
#define _INTERRUPT_  

#ifndef _GREENHILLS_C_V850_
  #define _GREENHILLS_C_V850_
#endif

#ifndef NULL_PTR
  #define NULL_PTR  ((void *)0)                       
#endif

/*pointer in FK4 is always 32bit*/
#ifndef FAR_PTR
 #define FAR_PTR
#endif

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
#define FUNC(type, memclass) memclass type

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
