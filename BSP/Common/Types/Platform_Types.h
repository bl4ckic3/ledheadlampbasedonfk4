/*******************************************************************************
|  File Name:  Platform_Types.h
|  Description:  the head file to define the hardware platform types
|-------------------------------------------------------------------------------
| (copy right) This software is the proprietary of  (PATAC). 
|              All rights are reserved by PATAC.
|-------------------------------------------------------------------------------
| Initials      Name                   Company
| --------      --------------------   -----------------------------------------
| Zephan         XXXX                   PATAC
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date         Version    Author     Description
| ----------   --------   ------     -------------------------------------------
| 2012-03-06   01.00.00   zephan     Creation
|
*******************************************************************************/

#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_
/*******************************************************************************
|    Other Header File Inclusion (if needed)
*******************************************************************************/


/*******************************************************************************
|    Macro,Enum,Type...defines
*******************************************************************************/
#define __32_BIT_MCU

/*****************************************************************************
|    8 bit Data Types
|****************************************************************************/
typedef unsigned char           UINT8;
typedef signed char             SINT8;

typedef unsigned char           BOOL;


/*****************************************************************************
|    16 bit Data Types
|****************************************************************************/
typedef unsigned short           UINT16;
typedef signed short             SINT16;


/*****************************************************************************
|    32 bit Data Types
|****************************************************************************/
#if defined( __32_BIT_MCU )

    typedef unsigned int    UINT32;
    typedef signed int      SINT32;

            
#elif defined(__16_BIT_MCU)
    typedef unsigned long    UINT32;
    typedef signed long      SINT32;

#endif

/*****************************************************************************
|    PATAC Data Types
|****************************************************************************/
	typedef unsigned char   BYTE;
	typedef unsigned short int PCT_UW_15;
	typedef unsigned long T_PCT_UW_15;
	typedef signed short int INTEGER;
/*****************************************************************************
|    Bits Data Types
|****************************************************************************/

typedef  struct 
{
    unsigned Bit0 :1;
    unsigned Bit1 :1;
    unsigned Bit2 :1;
    unsigned Bit3 :1;
    unsigned Bit4 :1;
    unsigned Bit5 :1;
    unsigned Bit6 :1;
    unsigned Bit7 :1;
} BITS8;

typedef struct 
{
    unsigned Bit0  :1;
    unsigned Bit1  :1;
    unsigned Bit2  :1;
    unsigned Bit3  :1;
    unsigned Bit4  :1;
    unsigned Bit5  :1;
    unsigned Bit6  :1;
    unsigned Bit7  :1;
    unsigned Bit8  :1;
    unsigned Bit9  :1;
    unsigned Bit10 :1;
    unsigned Bit11 :1;
    unsigned Bit12 :1;
    unsigned Bit13 :1;
    unsigned Bit14 :1;
    unsigned Bit15 :1;
} BITS16;


typedef union 
{
  UINT8 byte;
  BITS8 bits;
} BIT_UN8;

typedef union 
{
    UINT8 byte[2];
    UINT16 word;
    BITS16 bits;
} BIT_UN16;


typedef enum boolean_T
{
    False = 0,
    True = !False,
}BOOLEAN;

/*****************************************************************************
|  String Data Types
|****************************************************************************/
typedef const char *            STRING;
/*****************************************************************************
|    Function Pointer
|****************************************************************************/
typedef void (* FUNCTPTR)(void);

typedef const FUNCTPTR * FarFtnPtr_Arry;

typedef void (* const CONSTFUNCTPTR)(void);

typedef CONSTFUNCTPTR       CFPTR;
/*****************************************************************************
|    Basic data defines
|****************************************************************************/
#define boolean BOOL

#define uint8 UINT8
#define sint8 SINT8

#define uint16 UINT16
#define sint16  SINT16

#define uint32 UINT32
#define sint32  SINT32


#ifndef NULL
   #define NULL ((void *)0x0000)
#endif

#ifndef TRUE
   #define TRUE (!0)
#endif

#ifndef FALSE
   #define FALSE 0
#endif

#ifndef false
   #define false False
#endif

#ifndef true
   #define true True
#endif
/*******************************************************************************
|    Global Variable with extern linkage 
*******************************************************************************/
typedef unsigned long       uint8_least;    /* At least 8 bit                */
typedef unsigned long       uint16_least;   /* At least 16 bit               */
typedef unsigned long       uint32_least;   /* At least 32 bit               */
typedef signed long         sint8_least;    /* At least 7 bit + 1 bit sign   */
typedef signed long         sint16_least;   /* At least 15 bit + 1 bit sign  */
typedef signed long         sint32_least;   /* At least 31 bit + 1 bit sign  */
typedef unsigned char       boolean;        /* for use with TRUE/FALSE       */
/*******************************************************************************
|    Global Function Prototypes 
*******************************************************************************/

#endif/*End of File*/





