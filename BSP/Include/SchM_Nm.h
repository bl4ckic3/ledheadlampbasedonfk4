
#ifndef SCHM_NM_H
#define SCHM_NM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"


#define NM_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS
#define NM_EXCLUSIVE_AREA_1   SCHM_EA_SUSPENDALLINTERRUPTS


#  define SchM_Enter_Nm(ExclusiveArea) \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea)

#  define SchM_Exit_Nm(ExclusiveArea) \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea)


#endif /* SCHM_NM_H */

