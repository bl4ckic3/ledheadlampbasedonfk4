
#ifndef SCHM_ECUM_H
#define SCHM_ECUM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"

#define SCHM_ECUM_WAKEUPINTERRUPTS 0xF0

#define ECUM_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS
#define ECUM_EXCLUSIVE_AREA_1   SCHM_ECUM_WAKEUPINTERRUPTS


#  define SchM_Enter_EcuM(ExclusiveArea) \
   if (ExclusiveArea == SCHM_ECUM_WAKEUPINTERRUPTS) \
   {  \
   } \
   else \
   { \
        SCHM_ENTER_EXCLUSIVE(ExclusiveArea);    \
   }

#  define SchM_Exit_EcuM(ExclusiveArea) \
   if (ExclusiveArea == SCHM_ECUM_WAKEUPINTERRUPTS) \
   {  \
   } \
   else \
   { \
        SCHM_EXIT_EXCLUSIVE(ExclusiveArea);    \
   }

   
   

#endif /* SCHM_ECUM_H */

