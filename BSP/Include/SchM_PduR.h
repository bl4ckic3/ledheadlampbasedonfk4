
#ifndef SCHM_PDUR_H
#define SCHM_PDUR_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"


#define PDUR_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS

#  define SchM_Enter_PduR(ExclusiveArea) \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea)

#  define SchM_Exit_PduR(ExclusiveArea) \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea)


#endif /* SCHM_PDUR_H */

