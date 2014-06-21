
#ifndef SCHM_COMM_H
#define SCHM_COMM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"


#define COMM_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS
#define COMM_EXCLUSIVE_AREA_1   SCHM_EA_SUSPENDALLINTERRUPTS

#  define SchM_Enter_ComM(ExclusiveArea) \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea)

#  define SchM_Exit_ComM(ExclusiveArea) \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea)

#endif /* SCHM_COMM_H */

