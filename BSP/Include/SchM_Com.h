
#ifndef SCHM_COM_H
#define SCHM_COM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"

/* Com can either use a single interrupt lock for all PDUs at once or for every PDU individually.
To enable individual locks for the tx mainfunction
set COM_EXCLUSIVE_AREA_1 to SCHM_COM_EA_INTERRUPTSLOCKEDBYDIFFERENTEA and COM_EXCLUSIVE_AREA_2 to SCHM_EA_SUSPENDALLINTERRUPTS.
To enable individual locks for the rx mainfunctions
set COM_EXCLUSIVE_AREA_3 to SCHM_COM_EA_INTERRUPTSLOCKEDBYDIFFERENTEA and COM_EXCLUSIVE_AREA_4 to SCHM_EA_SUSPENDALLINTERRUPTS.
Refer to the Com Technical Reference for a detailed description */

#define SCHM_COM_EA_INTERRUPTSLOCKEDBYDIFFERENTEA 1

#define COM_EXCLUSIVE_AREA_0   SCHM_EA_SUSPENDALLINTERRUPTS
#define COM_EXCLUSIVE_AREA_1   SCHM_EA_SUSPENDALLINTERRUPTS
#define COM_EXCLUSIVE_AREA_2   SCHM_EA_SUSPENDALLINTERRUPTS
#define COM_EXCLUSIVE_AREA_3   SCHM_EA_SUSPENDALLINTERRUPTS
#define COM_EXCLUSIVE_AREA_4   SCHM_EA_SUSPENDALLINTERRUPTS

/*
extern const uint8 COM_EXCLUSIVE_AREA_0;
extern const uint8 COM_EXCLUSIVE_AREA_1;
extern const uint8 COM_EXCLUSIVE_AREA_2;
extern const uint8 COM_EXCLUSIVE_AREA_3;
extern const uint8 COM_EXCLUSIVE_AREA_4;
*/

#  define SchM_Enter_Com(ExclusiveArea) SCHM_ENTER_EXCLUSIVE(ExclusiveArea)
//((ExclusiveArea == SCHM_COM_EA_INTERRUPTSLOCKEDBYDIFFERENTEA)?   ,SCHM_ENTER_EXCLUSIVE(ExclusiveArea))
#if 0
\
   if (ExclusiveArea == SCHM_COM_EA_INTERRUPTSLOCKEDBYDIFFERENTEA)\
   {\
   }\
   else\
   {\
       SCHM_ENTER_EXCLUSIVE(ExclusiveArea);\
   }
#endif
#  define SchM_Exit_Com(ExclusiveArea) SCHM_EXIT_EXCLUSIVE(ExclusiveArea)
//((ExclusiveArea == SCHM_COM_EA_INTERRUPTSLOCKEDBYDIFFERENTEA)?   ,SCHM_EXIT_EXCLUSIVE(ExclusiveArea))
#if 0
   {\
   }\
   else\
   {\
       SCHM_EXIT_EXCLUSIVE(ExclusiveArea);\
   }
#endif
/*

void SchM_Enter_Com(uint8 ExclusiveArea)
{
   if (ExclusiveArea == SCHM_COM_EA_INTERRUPTSLOCKEDBYDIFFERENTEA)
   {

   }
   else
   {
       SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
   }
}

void SchM_Exit_Com(uint8 ExclusiveArea)
{
   if (ExclusiveArea == SCHM_COM_EA_INTERRUPTSLOCKEDBYDIFFERENTEA)
   {

   }
   else
   {
       SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
   }
}
//void SchM_Enter_Com(uint8 ExclusiveArea);
//void SchM_Exit_Com(uint8 ExclusiveArea);
*/


#endif /* SCHM_COM_H */

