/*============================================================================*/
/* Project      = AUTOSAR NEC Xx4 MCAL Components                             */
/* Module       = App_Gpt_Common_Sample.c                                     */
/* Version      = 3.0.2                                                       */
/* Date         = 25-Feb-2010                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009 by NEC Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains sample application for GPT Driver Component             */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* NEC Electronics Corporation the following shall apply!                     */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by NEC. Any warranty   */
/* is expressly disclaimed and excluded by NEC, either expressed or implied,  */
/* including but not limited to those for non-infringement of intellectual    */
/* property, merchantability and/or fitness for the particular purpose.       */
/*                                                                            */
/* NEC shall not have any obligation to maintain, service or provide bug      */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall NEC be liable to the User for any incidental,            */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. NEC shall not be liable for any services or products         */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by NEC in connection with the Product(s) and/or the   */
/* Application.                                                               */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        Xx4                                           */
/*              Compiler:       GHS V5.1.6c                                   */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:  23-Oct-2009  : Initial version
 * V3.0.1:  02-Nov-2009  : Timer Interrupt Vector Addresses
 *                       : are removed.
 * V3.0.2:  25-Feb-2010  : 
 */
/******************************************************************************/
 
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "App_Gpt_Common_Sample.h"
#include "Gpt.h"
#include "App_Gpt_Device_Sample.h"
/*******************************************************************************
**                            Macros                                          **
*******************************************************************************/

/*******************************************************************************
**                        Global variables                                    **
*******************************************************************************/

/* Variable used to store the Module Version Info */
Std_VersionInfoType Test_versioninfo;

/* Global variables to hold version information */
uint16 VendorID;
uint16 ModuleID;
uint8  InstanceID;
uint8 SW_Major_Version;
uint8 SW_Minor_Version;
uint8 SW_Patch_Version;

/* Global variable to hold the values */ 

Gpt_ValueType Test_Value1;
Gpt_ValueType Test_Value2;

/*******************************************************************************
**                        User function prototypes                            **
*******************************************************************************/

void Port_Init(void);
void Mcu_Init(void);
void Wdg_Init(void);
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

void main(void)
{
  /* Initialise MCU */
  Mcu_Init();
  /* Initialize the Port pins */
  Port_Init();
  /* Initialize the Watchdog timer */
  Wdg_Init();

  __asm("ei");  
  
  /* Getting the version Info of the GPT Driver */
  Gpt_GetVersionInfo(&Test_versioninfo);
  VendorID = Test_versioninfo.vendorID;
  ModuleID = Test_versioninfo.moduleID;
  InstanceID = Test_versioninfo.instanceID;
  SW_Major_Version = Test_versioninfo.sw_major_version;
  SW_Minor_Version = Test_versioninfo.sw_minor_version;
  SW_Patch_Version = Test_versioninfo.sw_patch_version;
  

  /* Initialisation of the GPT Driver */
  Gpt_Init(GptChannelConfigSet0);
 
  /* Enabling the Notification */
  Gpt_EnableNotification(GptChannelConfiguration0);

  /* Starting the Timer */
  Gpt_StartTimer(GptChannelConfiguration0, 0x5000);
  
  /* Reading the time elapsed */
  Test_Value1 = Gpt_GetTimeElapsed(GptChannelConfiguration0);

  /* Reading the time remaining */  
  Test_Value2 = Gpt_GetTimeRemaining(GptChannelConfiguration0);
   
  /* Set mode to Sleep */
  Gpt_SetMode(GPT_MODE_SLEEP);

  /* Disabling the Wakeup Notification */  
  Gpt_DisableWakeup(GptChannelConfiguration0);
  
  /* Set mode to Normal */
  Gpt_SetMode(GPT_MODE_NORMAL);
      
 /* Disabling the Notification */  
  Gpt_DisableNotification(GptChannelConfiguration0);

  /* Set mode to Sleep */
  Gpt_SetMode(GPT_MODE_SLEEP);

  /* Enabling the Wakeup Notification */
  Gpt_EnableWakeup(GptChannelConfiguration0);
  
  /*Checking the wake up notification*/
  Gpt_Cbk_CheckWakeup(GPT_WKP_SRC_1);

  /* Set mode to Normal */
  Gpt_SetMode(GPT_MODE_NORMAL);

  /* Stopping the Timer */
  Gpt_StopTimer(GptChannelConfiguration0);  
    
  /* De-initialize GPT Driver */
  Gpt_DeInit();
  
  
  while(1)
  {
    
  }  
    

}/* End of main() function */

void Gpt_Notification_0(void)
{
  /* Notification for channel */
}

void Gpt_Notification_1(void)
{
  /* Notification for channel */
}

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
