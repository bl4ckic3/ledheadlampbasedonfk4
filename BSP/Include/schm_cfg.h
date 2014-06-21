
#ifndef SCHM_CFG_H
#define SCHM_CFG_H
//#  include "Osek.h"

/* set SCHM_NONPREEMPTIVE_ECUM_STARTUPTWO_CALL to STD_ON or STD_OFF to enable or
   disable the protection of EcuM_StartupTwo() against task switches
   This can be used to delay the execution of high priority application tasks
   until the system is fully initialized.
*/
#define SCHM_NONPREEMPTIVE_ECUM_STARTUPTWO_CALL    STD_OFF

/* list of modules that do not have an enable or disable define in v_cfg.h */
#define VGEN_DISABLE_DRVADC
#define VGEN_DISABLE_SYSSERVICE_ASRCRC
#define VGEN_DISBALE_DRVDIO
#define VGEN_DISABLE_IF_ASRIFEA
#define VGEN_DISABLE_IF_ASRIFEABASIC
#define VGEN_DISABLE_IF_ASRIFEA_30_INST2
#define VGEN_ENABLE_SYSSERVICE_ASRECUM
#define VGEN_DISABLE_DRVEED
#define VGEN_DISABLE_DRVEEP
#define VGEN_DISABLE_DRVEEP_30_AT25128
#define VGEN_DISABLE_IF_ASRIFFEE	
#define VGEN_DISABLE_IF_ASRIFFEE30INST2
#define VGEN_DISABLE_DRVFLS
#define VGEN_DISABLE_FLS30ADBUS01
#define VGEN_DISABLE_DRVGPT
#define VGEN_DISABLE_DRVICU
#define VGEN_DISBALE_ECUAB_IOHWAB
#define VGEN_DISABLE_DRVMCU
#define VGEN_DISABLE_IF_ASRIFMEM
#define VGEN_DISABLE_MEMSERVICE_ASRNVM
#define VGEN_DISABLE_DRVPORT
#define VGEN_DISABLE_DRVPWM
#define VGEN_DISABLE_DRVSPI
#define VGEN_DISABLE_DRVWD
#define VGEN_DISABLE_IF_ASRIFWD
#define VGEN_DISABLE_SYSSERVICE_ASRWDM

#endif /* SCHM_CFG_H */

