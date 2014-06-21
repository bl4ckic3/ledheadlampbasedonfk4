/*============================================================================*/
/* Project      = AUTOSAR Renesas Xx4 MCAL Components                         */
/* File name    = Dio_Cfg.h                                                   */
/* Version      = 3.1.2                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2009-2012 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  3.1.4
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    FK4_4010_DIO_V308_140401_HEADLAMP.arxml
 * GENERATED ON:   1 Apr 2014 - 10:46:38
 */


#ifndef DIO_CFG_H 
#define DIO_CFG_H  
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define DIO_CFG_AR_MAJOR_VERSION  2
#define DIO_CFG_AR_MINOR_VERSION  2
#define DIO_CFG_AR_PATCH_VERSION  0

/* File version information */
#define DIO_CFG_SW_MAJOR_VERSION  3
#define DIO_CFG_SW_MINOR_VERSION  1

/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define DIO_AR_MAJOR_VERSION_VALUE  2
#define DIO_AR_MINOR_VERSION_VALUE  2
#define DIO_AR_PATCH_VERSION_VALUE  0

#define DIO_SW_MAJOR_VERSION_VALUE  3
#define DIO_SW_MINOR_VERSION_VALUE  1
#define DIO_SW_PATCH_VERSION_VALUE  2

#define DIO_VENDOR_ID_VALUE  23
#define DIO_MODULE_ID_VALUE  120

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the DIO Driver */
#define DIO_INSTANCE_ID_VALUE               0

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                STD_OFF

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                STD_OFF

/* Pre-compile option for presence of Channel */
#define DIO_CHANNEL_CONFIGURED              STD_ON

/* Pre-compile option for presence of Channel Group */
#define DIO_CHANNELGROUP_CONFIGURED         STD_ON


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Total number of configured ports */
#define DIO_MAXNOOFPORT                     (Dio_PortType)5

/* Total number of configured channels */
#define DIO_MAXNOOFCHANNEL                  (Dio_ChannelType)25

/* DIO Port Configuration Handles */
#define DioPort0                            (Dio_PortType)0
#define DioPort1                            (Dio_PortType)1
#define DioPort10                           (Dio_PortType)2
#define DioPort25                           (Dio_PortType)3
#define DioPort27                           (Dio_PortType)4

/* DIO Channel Configuration Handles */
#define DioChannel0_0                       (Dio_ChannelType)0
#define DioChannel0_10                      (Dio_ChannelType)1
#define DioChannel0_7                       (Dio_ChannelType)2
#define DioChannel10_10                     (Dio_ChannelType)3
#define DioChannel10_11                     (Dio_ChannelType)4
#define DioChannel1_10                      (Dio_ChannelType)5
#define DioChannel1_11                      (Dio_ChannelType)6
#define DioChannel1_12                      (Dio_ChannelType)7
#define DioChannel1_7                       (Dio_ChannelType)8
#define DioChannel1_8                       (Dio_ChannelType)9
#define DioChannel1_9                       (Dio_ChannelType)10
#define DioChannel25_1                      (Dio_ChannelType)11
#define DioChannel25_10                     (Dio_ChannelType)12
#define DioChannel25_11                     (Dio_ChannelType)13
#define DioChannel25_12                     (Dio_ChannelType)14
#define DioChannel25_13                     (Dio_ChannelType)15
#define DioChannel25_14                     (Dio_ChannelType)16
#define DioChannel25_5                      (Dio_ChannelType)17
#define DioChannel25_6                      (Dio_ChannelType)18
#define DioChannel25_7                      (Dio_ChannelType)19
#define DioChannel25_8                      (Dio_ChannelType)20
#define DioChannel25_9                      (Dio_ChannelType)21
#define DioChannel27_0                      (Dio_ChannelType)22
#define DioChannel27_1                      (Dio_ChannelType)23
#define DioChannel27_2                      (Dio_ChannelType)24

/* DIO Channel Group Configuration Handles */
#define DioChannelGroup0 (&Dio_GstChannelGroupData[0])
#define DioChannelGroup1 (&Dio_GstChannelGroupData[1])
#define DioChannelGroup10 (&Dio_GstChannelGroupData[2])
#define DioChannelGroup25 (&Dio_GstChannelGroupData[3])
#define DioChannelGroup27 (&Dio_GstChannelGroupData[4])
           
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* DIO_CFG_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

