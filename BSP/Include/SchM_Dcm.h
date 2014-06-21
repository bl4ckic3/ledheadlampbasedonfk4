
#ifndef SCHM_DCM_H
#define SCHM_DCM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"


#  define SchM_Enter_Dcm(ExclusiveArea) \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea)

#  define SchM_Exit_Dcm(ExclusiveArea) \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea)

#endif /* SCHM_DCM_H */

