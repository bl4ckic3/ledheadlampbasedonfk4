/*****************************************************************************
|    File Name:  ApiQueueHandler.h
|
|  Description:  Event Queue Handler
|
|-----------------------------------------------------------------------------
|               PATAC Confidential
|-----------------------------------------------------------------------------
|
| This software is copyright is proprietary of
| Pan Asia Technical Automotive Company(PATAC). 
| All rights are reserved by PATAC.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials      Name                   Company
| --------      --------------------   ---------------------------------------
| FRED        Wang Wanrong     PATAC
|
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Version   Author     Description
| ----------  --------  ------  ----------------------------------------------
| 2009-1-28  01.00.00  FRED   Creation
|****************************************************************************/
#ifndef __API_QUEUE_HANDLER_H
#define __API_QUEUE_HANDLER_H

#include "platform_types.h"


#define TASK_QUEUE_SIZE  20u
#define EVENT_QUEUE_SIZE 1000u

#define DUMMY_ID_IN_QUEUE  0u

#if DUMMY_ID_IN_QUEUE != 0
#error "I'm sorry"

#endif

#if (TASK_QUEUE_SIZE > 256) || (EVENT_QUEUE_SIZE > 256)
#define QuequeSizeType UINT16
#else
#define QuequeSizeType UINT8
#endif

//#define ADOPT_UINT8_FOR_QUEUE_ITME_ID
#define ADOPT_UINT16_FOR_QUEUE_ITME_ID

#if defined(ADOPT_UINT8_FOR_QUEUE_ITME_ID) && defined(ADOPT_UINT16_FOR_QUEUE_ITME_ID)
#error "Can't define both type for Queue Item ID"
#elif defined ADOPT_UINT8_FOR_QUEUE_ITME_ID
#define QueueItemIDType UINT8
#elif defined ADOPT_UINT16_FOR_QUEUE_ITME_ID 
#define QueueItemIDType UINT16
#else
#error "A type must be defined for Queue Item ID"
#endif


/******************************************************************************
* Macro Definition
*
******************************************************************************/
#define EnterCritical()          __DI()
#define LeaveCritical()         __EI()


#define TASKQUEUE_PUSH(x)      (void)AddKERNEL_b_QueueItem(&VsKERNEL_h_PeriodTaskQueue, x)
#define TASKQUEUE_POP()     GetKERNEL_w_QueueItem(&VsKERNEL_h_PeriodTaskQueue)
#define TASKQUEUE_ISEMPTY() IS_QUEUE_EMPTY(VsKERNEL_h_PeriodTaskQueue)
/*EVENTQUEUE_PUSH is for usage after OS is started*/

#define OSEVENT_PUSH(x)    (void)AddKERNEL_b_QueueItem(&VsKERNEL_h_EventTaskQueue, (x))
#define EVENTQUEUE_PUSH(x) {\
  __DI();\
  OSEVENT_PUSH(x);\
  __EI();}
#define EVENTQUEUE_POP()      GetKERNEL_w_QueueItem(&VsKERNEL_h_EventTaskQueue)
#define EVENTQUEUE_ISEMPTY() IS_QUEUE_EMPTY(VsKERNEL_h_EventTaskQueue)



/*QueueStruct defines the queue object. */
typedef struct QueueStruct
{
    /* structure data members. */
    /** The pre-allocated memory. */
    QueueItemIDType* pArrayMemory;
    /* Points at the front of the queue, where the data will be retrieved
       from. */
    QuequeSizeType   iFrontItem;
    /* Points at the next available position. */
    QuequeSizeType   INextItem;
    /* The size of the queue, max number of items in the queue */
    QuequeSizeType   ArraySize;
    /* The number of items currently stored on the queue. */
    QuequeSizeType   NumInQue;
} QueueStruct_t;

/** 
 * Macros to reduce function call depth. Having adverse effect on stack 
 * size. 
 */
/** Check if the queue is empty. Variable Version*/
 #define IS_QUEUE_EMPTY(MyQueue) \
    ((MyQueue.NumInQue > 0) ? FALSE : TRUE)

/******************************************************************************
* Extern function and variable declaration.
*
******************************************************************************/
extern QueueStruct_t VsKERNEL_h_PeriodTaskQueue;
extern QueueStruct_t VsKERNEL_h_EventTaskQueue;


void SysSrvc_InitAllQueue(void);


/******************************************************************************
* Function Name                   : AddKERNEL_b_QueueItem
* Description                     : Add an item to the back of the queue
* Parameters Passed          : pQueue: The Queue object we're adding to.
                                        EventID  : The item we're adding.
* Parameters Returned        : None
* Return Type                : TRUE if value was inserted.
 *                                   FALSE otherwise.
******************************************************************************/ 
BOOL AddKERNEL_b_QueueItem  (QueueStruct_t* const pQueue, const QueueItemIDType EventID);
/******************************************************************************
* Function Name                   : AddKERNEL_b_QueueInitPhase
* Description                     : Add an item to the back of the queue in OS init phase, which is used in 
                                       startup hook. Never use it after OS is start. 
* Parameters Passed          : pQueue: The Queue object we're adding to.
                                        EventID  : The item we're adding.
* Parameters Returned        : None
* Return Type                : TRUE if value was inserted.
 *                                   FALSE otherwise.
******************************************************************************/ 
BOOL AddKERNEL_b_QueueInitPhase(QueueStruct_t* const pQueue, const QueueItemIDType EventID);
QueueItemIDType GetKERNEL_w_QueueItem    (QueueStruct_t* const pQueue);
BOOL AddKERNEL_b_QueueFrontItem(QueueStruct_t* const pQueue, const QueueItemIDType EventID);
BOOL QueryKERNEL_b_QueueEmpty    (const QueueStruct_t* const pQueue);
BOOL RemoveKERNEL_b_QueueItem(QueueStruct_t* const pQueue, const QueueItemIDType EventID);
BOOL QueryKERNEL_b_ItemInQueue (const QueueStruct_t* const pQueue, 
                             const QueueItemIDType EventID);
QuequeSizeType QueryKERNEL_u_QueueStoredNum(QueueStruct_t* const pQueue);
void ClearKERNEL_Queue       (QueueStruct_t* const pQueue);

#endif
