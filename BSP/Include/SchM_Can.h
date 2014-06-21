#ifndef SCHM_CAN_H
#define SCHM_CAN_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"


#define CAN_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS

#  define SchM_Enter_Can(ExclusiveArea) \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea)

#  define SchM_Exit_Can(ExclusiveArea) \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea)


#endif /* SCHM_CAN_H */

