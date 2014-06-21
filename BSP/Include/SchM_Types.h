
#ifndef SCHM_TYPES_H
#define SCHM_TYPES_H

typedef uint8 SchM_ReturnType;

#define SCHM_E_OK       ((SchM_ReturnType)0x00)
#define SCHM_E_LIMIT    ((SchM_ReturnType)0x04)
#define SCHM_E_NOFUNC   ((SchM_ReturnType)0x05)
#define SCHM_E_STATE    ((SchM_ReturnType)0x07)

#define SCHM_EA_SUSPENDALLINTERRUPTS 0


#      define SCHM_ENTER_EXCLUSIVE(ExclusiveArea)          \
         SuspendAllInterrupts()

#      define SCHM_EXIT_EXCLUSIVE(ExclusiveArea)          \
         ResumeAllInterrupts()


#endif /* SCHM_TYPES_H */

