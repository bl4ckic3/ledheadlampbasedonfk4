/*----------------------------------------------------------------------------
|
|  File Name: NodeConfig.h
|
|  Comment: Configuration of the emulated OSEK node
|                                         
|           Change the text entries below to describe the node, which you
|           want to emulate.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Lm           Marc    Lobmeyer          Vector Informatik GmbH   
| As           Stefan  Albus             Vector Informatik GmbH  
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date         Ver  Author  Description
| ----------   ---  ------  --------------------------------------------------
| 29.01.2000   1.0  As      Creation of the skeleton file
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 1994 - 2000 by Vector Informatik GmbH.  All rights reserved.
-----------------------------------------------------------------------------*/

// The name of the node, which you want to emulate.
// This should be the same name, which is used in the database (CANdb) to
// describe this node.
#define NODE_NAME               "DEMO"

// The version of the library, which you generate for CANoe
// Due to limitations of the ressource compiler, you must specify it twice.(As 
// a coma seperated list of numbers and as a text string.)
#define NODE_VERSION_NUMBER     1,0,0
#define NODE_VERSION_STRING     "1.0.0"

// A little description about the things, which will happen here.
#define NODE_DESCRIPTION        "General Example of OSEK Emulation"

/************   Organi, Version 3.9.1 Vector-Informatik GmbH  ************/
