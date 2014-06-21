
#ifndef SCHM_CANTP_H
#define SCHM_CANTP_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"


#define CANTP_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS
#define CANTP_EXCLUSIVE_AREA_1   SCHM_EA_SUSPENDALLINTERRUPTS
#define CANTP_EXCLUSIVE_AREA_2   SCHM_EA_SUSPENDALLINTERRUPTS

#  define SchM_Enter_CanTp(ExclusiveArea) \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea)

#  define SchM_Exit_CanTp(ExclusiveArea) \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea)


#endif /* SCHM_CANTP_H */

