
#ifndef SCHM_DEM_H
#define SCHM_DEM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"


#define DEM_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS
#define DEM_EXCLUSIVE_AREA_1   SCHM_EA_SUSPENDALLINTERRUPTS
#define DEM_EXCLUSIVE_AREA_2   SCHM_EA_SUSPENDALLINTERRUPTS

#define SCHM_DEM_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS


#  define SchM_Enter_Dem(ExclusiveArea) \
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea)

#  define SchM_Exit_Dem(ExclusiveArea) \
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea)


#endif /* SCHM_DEM_H */

