--
--	V850 Language Independent Runtime Library
--
--	Copyright 1996-2000 by Green Hills Software, Inc.
--
--    This program is the property of Green Hills Software, Inc,
--    its contents are proprietary information and no part of it
--    is to be disclosed to anyone except employees of Green Hills
--    Software, Inc., or as agreed in writing signed by the President
--    of Green Hills Software, Inc.
--

#ifdef __V850
#define CALL(x)	jarl	x, lp
#else
#define CALL(x)	jal	x
#endif

#ifdef __V810
#define HI	hi1
#else
#define HI	hi
#endif

#ifdef __V850_LOAD_STORE_SYNC
#define SYNC mov r31, r0
#else
#define SYNC
#endif

#if defined(EVA_LOAD_HAZARD) \
    || defined(__V850_LOAD_STORE_SYNC) \
    || defined(__V850_BITOP_SYNC)
#define RETI	mov r31, r0 ; reti
#else
#define RETI	reti
#endif

#ifdef __V850E
#define MOV32(x, y) mov x, y
#else
#define MOV32(x, y) movhi HI(x),zero,y ; movea	lo(x),y,y
#endif
