;*****************************************************************************
;file name: Vector.asm
;Description:  CX compiler and ASM file for interrupt vector define.
;-----------------------------------------------------------------------------
;               PATAC Confidential
;-----------------------------------------------------------------------------
;
; This software is copyright is proprietary of Pan Asia Technical Automotive 
; Company(PATAC). 
; All rights are reserved by PATAC.
;
;-----------------------------------------------------------------------------
;               A U T H O R   I D E N T I T Y
;-----------------------------------------------------------------------------
; Initials      Name                   Company
; ------------------------------------   -------------------------------------
;
;
;-----------------------------------------------------------------------------
;               R E V I S I O N   H I S T O R Y
;-----------------------------------------------------------------------------
; Date       Version   Author     Description
;----------  --------  ------  -----------------------------------------------
;2011-08-04  01.00.00   WH        Create for BSP
;*****************************************************************************


	.public _APP_VECT_TAB_START

;--------------------------------------------------------------------
;hardware interrupt entry point table
;--------------------------------------------------------------------
INTP0 .cseg text
	jr	_APP_VECT_TAB_START+(4*9)
INTP1 .cseg text
	jr	_APP_VECT_TAB_START+(4*10)
INTP2 .cseg text
	jr	_APP_VECT_TAB_START+(4*11)
INTP3 .cseg text
	jr	_APP_VECT_TAB_START+(4*12)
INTP4 .cseg text
	jr	_APP_VECT_TAB_START+(4*13)
INTP5 .cseg text
	jr	_APP_VECT_TAB_START+(4*14)
INTP6 .cseg text
	jr	_APP_VECT_TAB_START+(4*15)
INTP7 .cseg text
	jr	_APP_VECT_TAB_START+(4*16)
INTP8 .cseg text
	jr	_APP_VECT_TAB_START+(4*17)
INTP9 .cseg text
	jr	_APP_VECT_TAB_START+(4*18)
INTP10 .cseg text
	jr	_APP_VECT_TAB_START+(4*19)

INTADCA0I0      .cseg text
	jr     _APP_VECT_TAB_START+(4*101)
INTADCA0I1      .cseg text
	jr     _APP_VECT_TAB_START+(4*102)
INTADCA0I2      .cseg text
	jr     _APP_VECT_TAB_START+(4*103)

INTCSIG0IRE      .cseg text
	jr	_APP_VECT_TAB_START+(4*109)
INTCSIG0IR      .cseg text
	jr	_APP_VECT_TAB_START+(4*110)
INTCSIG0IC      .cseg text
	jr	_APP_VECT_TAB_START+(4*111)

INTADCA1I0      .cseg text
	jr     _APP_VECT_TAB_START+(4*143)
INTADCA1I1      .cseg text
	jr     _APP_VECT_TAB_START+(4*144)
INTADCA1I2      .cseg text
	jr     _APP_VECT_TAB_START+(4*145)

INTOSTM0 .cseg text
	jr	_APP_VECT_TAB_START+(4*147)



;--------------------------------------------------------------------
; application vector table (jump table)
;--------------------------------------------------------------------
APP_VECT_TAB.text .cseg  text 

_APP_VECT_TAB_START:

	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _ISR_INTP0
	;10
	jr _ISR_INTP1
	jr _ISR_INTP2
	jr _ISR_INTP3
	jr _ISR_INTP4
	jr _ISR_INTP5
	jr _ISR_INTP6
	jr _ISR_INTP7
	jr _ISR_INTP8
	jr _ISR_INTP9
	jr _ISR_INTP10
	;20
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;30
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;40
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;50
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;60
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;70
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;80
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;90
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;100
	jr _unused_isr
	jr _ISR_ADCA0I0
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _ISR_SPI0RXERR
	;110
	jr _ISR_SPI0RX
	jr _ISR_SPI0TX
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;120
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;130
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;140
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _ISR_OSTM
	jr _unused_isr
	jr _unused_isr
	;150
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;160
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;170
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;180
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;190
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _ISR_LMA2IS
	jr _ISR_LMA2IR
	jr _ISR_LMA2IT
	jr _ISR_LMA3IS
	jr _ISR_LMA3IR
	jr _ISR_LMA3IT
	jr _unused_isr
	;200
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;210
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;220
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;230
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;240
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	;250
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr
	jr _unused_isr

	


