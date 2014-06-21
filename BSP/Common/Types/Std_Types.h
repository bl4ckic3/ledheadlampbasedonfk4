

#ifndef STD_TYPES_H
#define STD_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Compiler.h"                  /* mapping compiler specific keywords */
#include "Platform_Types.h"            /* platform specific type definitions */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define STD_TYPES_AR_MAJOR_VERSION  1
#define STD_TYPES_AR_MINOR_VERSION  2
#define STD_TYPES_AR_PATCH_VERSION  0

/*
 * File version information
 */
#define STD_TYPES_SW_MAJOR_VERSION  3
#define STD_TYPES_SW_MINOR_VERSION  0
#define STD_TYPES_SW_PATCH_VERSION  0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                    **
*******************************************************************************/

/* for OSEK compliance this typedef has been added */
#ifndef STATUSTYPEDEFINED 
  #define STATUSTYPEDEFINED 
  #define E_OK      0
  typedef unsigned char StatusType;
#endif

/* STD011
  The Std_ReturnType (STD005) may be used with the following values (STD006):
  E_OK:     0
  E_NOT_OK: 1
*/
typedef uint8 Std_ReturnType;
#define E_NOT_OK    1
#define E_PENDING  2u


typedef struct
{
  uint16  vendorID;
  uint16  moduleID;
  uint8  instanceID;
  uint8  sw_major_version;
  uint8  sw_minor_version;
  uint8  sw_patch_version;
} Std_VersionInfoType; /* STD015                                */


#define STD_HIGH    1  /* Physical state 5V or 3.3V             */
#define STD_LOW     0  /* Physical state 0V                     */

#define STD_ACTIVE  1  /* Logical state active                  */
#define STD_IDLE    0  /* Logical state idle                    */

#define STD_ON      1
#define STD_OFF     0



/*****************************************************************************
|    Function Pointer
|****************************************************************************/
/*Note: all pointers in ghs is always far*/
typedef void (* FtnPtr)(void);
typedef void (* FarFtnPtr)(void);
typedef void (* FarEvtFtnPtr)(UINT16);
typedef const FarFtnPtr* FarFtnPtr_Arry;

/***
Constant Function pointer
***/
typedef void (* const CnstFtnPtr)(void);



/*=======================================================================*
 * Fixed width word size data types:                                     *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef int int16_T;
typedef unsigned short uint16_T;
typedef long int32_T;
typedef unsigned long uint32_T;

/*===========================================================================*
 * Generic type definitions: boolean_T, int_T, uint_T, ulong_T, char_T,      *
 *                           and byte_T.                                     *
 *===========================================================================*/
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef char_T byte_T;

#ifndef GMLAN_VALID
    #define GMLAN_VALID 0
#endif

#ifndef GMLAN_INVALID
    #define GMLAN_INVALID 1
#endif
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif  /* STD_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

