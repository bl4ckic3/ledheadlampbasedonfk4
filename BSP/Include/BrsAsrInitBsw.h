/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2009 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  BrsAsrInitBsw.h
 *    Component:  BrsAsr
 *       Module:  BrsAsrInitBsw
 *    Generator:  -
 *
 *  Description:  BrsAsrInitBsw contains the functions BrsAsrInitBswDriverInitZero,One,Two,Three which are
 *                meant to be called in the related initialization stages from the Ecu State Manager
 *                The functions BrsAsrInitBswDriverInitZero to Three execute the basic initialisation of 
 *                the hardware and calls to the InitMemory and Init routines of the BSW modules.
 *              
 *                The initialisation sequence is derived from the Specification of Ecu Statemanager (AUTOSAR 3.1)
 *  
 *********************************************************************************************************************/

#if !defined (BRSASRINITBSW_H)
# define BRSASRINITBSW_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Component Version Information */
# define BRSASRINITBSW_MAJOR_VERSION       (0x01)
# define BRSASRINITBSW_MINOR_VERSION       (0x00)
# define BRSASRINITBSW_PATCH_VERSION       (0x07)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void BrsAsrInitBswDriverInitZero(void);
void BrsAsrInitBswDriverInitOne(void);
void BrsAsrInitBswDriverInitTwo(void);
void BrsAsrInitBswDriverInitThree(void);

#endif

