#ifndef _QUEUE_ARRAY_H
#define _QUEUE_ARRAY_H
#include <stdio.h>
#include <stdlib.h>

#include "Platform_Types.h"

typedef struct {
  void **QueueArray;   /* Pointer to array of void pointers */
  sint32 QueueMaxSize; /* Maximum elements in the Queue */
  sint32 ElementCount; /* Number of elements in the Queue */
  sint32 QueueFront;   /* Index of the front elements */
  sint32 QueueRear;    /* Index of the rear elements */

} Queue_t;

//----------------

typedef enum {
  QUEUE_NOK = 0,
  QUEUE_OK,
  QUEUE_FULL,
  QUEUE_EMPTY,
  QUEUE_NULL_POINTER,

} QueueStatus_t;
//------------
Queue_t *CreateQueue(uint32 maxSize, QueueStatus_t *ret_status);
QueueStatus_t EnqueueElement(Queue_t *queue_obj, void *item_ptr);
void *DequeueElement(Queue_t *queue_obj, QueueStatus_t *ret_status);
void *QueueFront(Queue_t *queue_obj, QueueStatus_t *ret_status);
void *QueueRear(Queue_t *queue_obj, QueueStatus_t *ret_status);
QueueStatus_t GetQueueCount(Queue_t *queue_obj, uint32 *QueueCount);
QueueStatus_t DestroyQueue(Queue_t *queue_obj);

#endif
