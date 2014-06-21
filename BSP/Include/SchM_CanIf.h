
#ifndef SCHM_CANIF_H
#define SCHM_CANIF_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"



#define CANIF_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS
#define CANIF_EXCLUSIVE_AREA_1   SCHM_EA_SUSPENDALLINTERRUPTS
#define CANIF_EXCLUSIVE_AREA_2   SCHM_EA_SUSPENDALLINTERRUPTS
#define CANIF_EXCLUSIVE_AREA_3   SCHM_EA_SUSPENDALLINTERRUPTS
#define CANIF_EXCLUSIVE_AREA_4   SCHM_EA_SUSPENDALLINTERRUPTS

#  define SchM_Enter_CanIf(ExclusiveArea) \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea)

#  define SchM_Exit_CanIf(ExclusiveArea) \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea)


#endif /* SCHM_CANIF_H */

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
