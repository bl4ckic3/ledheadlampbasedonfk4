/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* Module       = App_Icu_Common_Sample.c                                     */
/* Version      = 3.0.5a                                                      */
/* Date         = 18-Oct-2011                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2011 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains sample application for ICU Driver Component             */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
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
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        Xx4                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V3.0.0:  25-Aug-2009  : Initial version
 *
 * V3.0.1:  30-Oct-2009  : Function for Wdg initialization is added.
 *
 * V3.0.2:  03-Nov-2009  : Comments are added for input signal details for
 *                         the corressponding measurement modes.
 *
 * V3.0.3:  04-Nov-2009  : The input signal details are generalized.
 *
 * V3.0.4:  12-Nov-2009  : Breakloop method is changed
 *
 * V3.0.5:  24-Feb-2010  : The file is renamed and unnecessary global 
 *                         variable declaration is removed.
 * V3.0.5a: 18-Oct-2011  : Copyright is updated.
 */
/******************************************************************************/
 
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "App_Icu_Common_Sample.h"
#include "App_Icu_Device_Sample.h"
#include "Icu.h"
#include "Icu_Irq.h"
/*******************************************************************************
**                            Macros                                          **
*******************************************************************************/


/*******************************************************************************
**                        Global variables                                    **
*******************************************************************************/

/* Array used to store the timestamps */
Icu_ValueType GusTimestamp[10];

/* Variable used to store the Module Version Info */
Std_VersionInfoType GddVersionInfo;

/* Global variables to hold version information */
uint16 GucVendorID;
uint16 GucModuleID;
uint8 GucInstanceID;
uint8 GucMajorVersion;
uint8 GucMinorVersion;
uint8 GucPathVersion;

/* Global variable to hold the timestamp capture status */
boolean GblTimestampsCaptured;

boolean BreakLoop;

Icu_InputStateType GblInputStatus[2];

Icu_ValueType GddTimeElapsed1[1];
Icu_ValueType GddTimeElapsed2[1];
Icu_ValueType GddTimeElapsed3[1];
Icu_ValueType GddTimeElapsed4[1];
Icu_ValueType GddTimeElapsed5[1];
Icu_ValueType GddTimeElapsed6[1];
Icu_ValueType GddTimeElapsed7[1];

Icu_DutyCycleType GddDutyCycleValues[7];

uint16 GblTimestampIndex[1];
uint16 GusEdgeNumbers = 0;
Icu_EdgeNumberType GblEdgeNumberCh[1];

/*******************************************************************************
**                        User function prototypes                            **
*******************************************************************************/
void Wdg_Init(void);
void Mcu_Init(void);
void Port_Init(void);
void Big_Delay(void);
void Icu_Edge_Detect_1(void);
void Icu_TimestampNotification_1(void);

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/* 
 * Main Function 
 */
void main(void)
{
  /* Initialise MCU */
  Mcu_Init();

  /* Initialise PORT */
  Port_Init();
  
  /* Initialise WDG */
  Wdg_Init();
   
  /* Read the ICU Driver version information. The pointer is updated with
   * the vendorID, moduleID, instanceID and software version
   */
  Icu_GetVersionInfo(&GddVersionInfo);
  /* Reading of vendorID, moduleID and software version from the pointer */
  GucVendorID = GddVersionInfo.vendorID;
  GucModuleID = GddVersionInfo.moduleID;
  GucInstanceID = GddVersionInfo.instanceID;  
  GucMajorVersion = GddVersionInfo.sw_major_version;
  GucMinorVersion = GddVersionInfo.sw_minor_version;
  GucPathVersion = GddVersionInfo.sw_patch_version;  

  /* Initialise ICU Driver. A valid database address needs to
   * be provided for the proper initialisation of the driver.
   */
  Icu_Init(IcuConfigSet0);
  BreakLoop = ICU_FALSE;

  /* Enable Global Interrupt */
  __asm("ei");

  /*****************************************************************************
  ********************** TIME STAMPING FUNCTIONALITY ***************************
  *****************************************************************************/
  /* A continuous signal of 1 milli-second with 50% duty cycle and Vref
   * should be given at input.
   */
  /* Set Activation condition for IcuChannel2 */
  Icu_SetActivationCondition(IcuChannel2, ICU_RISING_EDGE);
 
  /* Enable notification for IcuChannel2 */
  Icu_EnableNotification(IcuChannel2);  
    
  /* Enable Timestamping for IcuChannel2 */
  Icu_StartTimestamp(IcuChannel2, &GusTimestamp[0], 10, 5);
  do
  { 
    /* Get the index of the  buffer at which next timestamp 
     * value is to be written 
     */
    GblTimestampIndex[0] = Icu_GetTimestampIndex(IcuChannel2);
  }while(!BreakLoop);
  BreakLoop = ICU_FALSE;

  /* Stop Timestamping for for IcuChannel2 */
  Icu_StopTimestamp(IcuChannel2);
  /* Get the index of the  buffer at which next timestamp 
   * value is to be written
   */  
  GblTimestampIndex[0] = Icu_GetTimestampIndex(IcuChannel2); 
  
  /* Disable notification for IcuChannel2 */
  Icu_DisableNotification(IcuChannel2);

  /* Enable Timestamping for IcuChannel2 */
  Icu_StartTimestamp(IcuChannel2, &GusTimestamp[0], 10, 5);
  do
  { 
    /* Get the index of the  buffer at which next timestamp 
     * value is to be written 
     */
    GblTimestampIndex[0] = Icu_GetTimestampIndex(IcuChannel2);
  }while(!BreakLoop);
  BreakLoop = ICU_FALSE;  

  /* Stop Timestamping for IcuChannel2 */
  Icu_StopTimestamp(IcuChannel2);
  /* Get the index of the  buffer at which next timestamp 
   * value is to be written
   */  
  GblTimestampIndex[0] = Icu_GetTimestampIndex(IcuChannel2);  

  /*****************************************************************************
  ********************** EDGE COUNTING FUNCTIONALITY ***************************
  *****************************************************************************/
  /* A discrete signal of 1 milli-second with 50% duty cycle and Vref should be 
   * given at input. User has to trigger the edges at input.
   */
  /* Set Rising Edge Activation condition for IcuChannel1 */
  Icu_SetActivationCondition(IcuChannel1, ICU_RISING_EDGE);
  /* Enable Edge Counting for IcuChannel1 */
  Icu_EnableEdgeCount(IcuChannel1);
  /* Read Edge count for IcuChannel1 */
  do
  {
    /* Get the number of edges counted IcuChannel1 */
    GblEdgeNumberCh[0] = Icu_GetEdgeNumbers(IcuChannel1);
  }while (!BreakLoop);
  BreakLoop = ICU_FALSE;  
  
  /* Reset Edge count for IcuChannel1 */
  Icu_ResetEdgeCount(IcuChannel1);       

  do
  {
    /* Get the number of edges counted */    
    GblEdgeNumberCh[0] = Icu_GetEdgeNumbers(IcuChannel1);
  }while (!BreakLoop);
  BreakLoop = ICU_FALSE;  
    
  /* Disable Edge Counting for IcuChannel1 */
  Icu_DisableEdgeCount(IcuChannel1);  
  
  do
  {
    /* Get the number of edges counted */    
    GblEdgeNumberCh[0] = Icu_GetEdgeNumbers(IcuChannel1);
  }while (!BreakLoop);
  BreakLoop = ICU_FALSE;  
 
  /*****************************************************************************
  ********************* SIGNAL MEASUREMENT FUNCTIONALITY ***********************
  *****************************************************************************/
  /* A continuous signal of 1 milli-second with 60% duty cycle and Vref
   * should be given at input.
   */  
  /* Signal measurement: HIgh Time */
  /* Start Signal Measurement for IcuChannel3 */
  Icu_StartSignalMeasurement (IcuChannel3);        
  /* Read Elapsed High Time for IcuChannel3 */
  GddTimeElapsed1[0] = Icu_GetTimeElapsed(IcuChannel3);
  /* Call Big Delay */
  Big_Delay();
  /* Signal High time has been captured */
  GddTimeElapsed2[0] = Icu_GetTimeElapsed(IcuChannel3);
  GddTimeElapsed3[0] = Icu_GetTimeElapsed(IcuChannel3);
  /* Call Big Delay */
  Big_Delay();
  /* Signal High time has been captured */
  GddTimeElapsed4[0] = Icu_GetTimeElapsed(IcuChannel3);
  /* Call Big Delay */
  Big_Delay();
  /* Signal High time has been captured */
  GddTimeElapsed5[0] = Icu_GetTimeElapsed(IcuChannel3);
  /* Call Big Delay */
  Big_Delay();
  /* Signal High time has been captured */
  GddTimeElapsed6[0] = Icu_GetTimeElapsed(IcuChannel3);
  /* Stop Signal Measurement for IcuChannel3 */
  Icu_StopSignalMeasurement (IcuChannel3);
  /* Call Big Delay */
  Big_Delay();
  /* Signal High time has been captured */
  GddTimeElapsed7[0] = Icu_GetTimeElapsed(IcuChannel3);
  
  /* Signal measurement: Duty cycle */
  
  /* A continuous signal of 1 milli-second with 60% duty cycle and Vref
   * should be given at input channel as well as the channel
   * next to it.
   */
  /* In this case give input signal to IcuChannel4 as well as to its
     next higher channel */  
  
  /* Start Signal Measurement for IcuChannel4 */
  Icu_StartSignalMeasurement (IcuChannel4);        
  /* Read DutyCycle for IcuChannel4 */
  Icu_GetDutyCycleValues(IcuChannel4, &GddDutyCycleValues[0]);
  /* Call Big Delay */
  Big_Delay();
  /* Signal DutyCycle has been captured */
  Icu_GetDutyCycleValues(IcuChannel4, &GddDutyCycleValues[1]);
  Icu_GetDutyCycleValues(IcuChannel4, &GddDutyCycleValues[2]);
  /* Call Big Delay */
  Big_Delay();
  /* Signal DutyCycle has been captured */
  Icu_GetDutyCycleValues(IcuChannel4, &GddDutyCycleValues[3]);
  /* Call Big Delay */
  Big_Delay();
  /* Signal DutyCycle has been captured */
  Icu_GetDutyCycleValues(IcuChannel4, &GddDutyCycleValues[4]);
  /* Call Big Delay */
  Big_Delay();
  /* Signal DutyCycle has been captured */
  Icu_GetDutyCycleValues(IcuChannel4, &GddDutyCycleValues[5]);
  /* Stop Signal Measurement for IcuChannel4 */
  Icu_StopSignalMeasurement (IcuChannel4);
  /* Call Big Delay */
  Big_Delay();
  /* Signal DutyCycle has been captured */
  Icu_GetDutyCycleValues(IcuChannel4, &GddDutyCycleValues[6]);  
  
  /* To check the input state of a channel configured for signal 
   * measurement mode 
   */
  /* Start Signal measurement for IcuChannel3 */
  Icu_StartSignalMeasurement(IcuChannel3);
  
  Big_Delay();
  /* Get the input stae of the channel */
  GblInputStatus[0] = Icu_GetInputState(IcuChannel3);
  GblInputStatus[1] = Icu_GetInputState(IcuChannel3);
 
  /* GblInputStatus[0] should be ICU_ACTIVE and GblInputStatus[1]
   * should be ICU_IDLE 
   */
  /* Stop Signal Measurement for for IcuChannel3 */
  Icu_StopSignalMeasurement(IcuChannel3);
  
  GblInputStatus[0] = ICU_IDLE;
  GblInputStatus[1] = ICU_IDLE;
  
  /*****************************************************************************
  ************************* EDGE DETECTION FUNCTIONALITY ***********************
  *****************************************************************************/
  /* A continuous signal of 1 milli-second with 50% duty cycle and Vref
   * should be given at input.
   */
  /* Enable notification for IcuChannel0 */

  Icu_EnableNotification(IcuChannel0);
   
  do
  {
      ;
  }while (!BreakLoop);
  BreakLoop = ICU_FALSE;  
           
  /* Disable notification for IcuChannel0 */
  Icu_DisableNotification(IcuChannel0);
  GusEdgeNumbers = 0;
  
  do
  {
      ;
  }while (!BreakLoop);
  BreakLoop = ICU_FALSE;  

  /* To check the input state of a channel configured for edge detection mode */
  
  Big_Delay();
  /* Read Input status for IcuChannel0 */
  GblInputStatus[0] = Icu_GetInputState(IcuChannel0);
  GblInputStatus[1] = Icu_GetInputState(IcuChannel0);        
  
  GblInputStatus[0] = ICU_IDLE;
  GblInputStatus[1] = ICU_IDLE; 
  
  /* Set Icu to sleep mode */
  Icu_SetMode(ICU_MODE_SLEEP);
  
  /* Set Icu to normal mode */ 
  Icu_SetMode(ICU_MODE_NORMAL);
 
  /* Disable wakeup for IcuChannel0 */
  Icu_DisableWakeup(IcuChannel0);

  /* Disable wakeup for IcuChannel0 */
  Icu_EnableWakeup(IcuChannel0);  
  
  /* De-Initialisation of ICU Driver. After the driver is de-initialised,
   * no other API calls are valid except Icu_Init(). User should take care
   * of re-initialising the ICU Driver with a valid database before invoking
   * other APIs.
   */
  Icu_DeInit();  

}

/* End of main() function */

void Big_Delay(void)
{
  uint16 LuiCnt1 = 0;
  uint16 LuiCnt2 = 0;

  while(LuiCnt1 < 10)
  {
    LuiCnt1 ++;
    while(LuiCnt2 < 10000)
    {
      LuiCnt2++; 
    }
    LuiCnt2 = 0;
  }
}

/*******************************************************************************
**                         Notification function                              **
*******************************************************************************/

/* Notification function for IcuChannel0 */
void Icu_Edge_Detect_1(void)
{
  /* Increment the counter to indicate that notification is invoked */
  GusEdgeNumbers++;
}

/* Notification function for IcuChannel2 */
void Icu_TimestampNotification_1(void)
{
  /* Set flag to true to inform that the 5 timestamps have been captured */
  GblTimestampsCaptured = TRUE;
}

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/

