
#ifndef SCHM_CANIF_H
#define SCHM_CANIF_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"



#define CANTRCV_30_TJA1145_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS

#define SCHM_CANTRCV_30_TJA1145_EXCLUSIVE_INSTANCE_0   (0u)

#  define SchM_Enter_CanTrcv_30_Tja1145(ExclusiveArea) \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea)

#  define SchM_Exit_CanTrcv_30_Tja1145(ExclusiveArea) \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea)


#endif /* SCHM_CANIF_H */

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
