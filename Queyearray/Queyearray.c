#include "Queyearray.h"

static uint8 QueueIsFull(Queue_t *queue_obj) {
  return (queue_obj->ElementCount == queue_obj->QueueMaxSize);
}

static uint8 QueueIsEmpty(Queue_t *queue_obj) {
  return (queue_obj->ElementCount == 0);
}
Queue_t *CreateQueue(uint32 maxSize, QueueStatus_t *ret_status) {

  Queue_t *MyQueue;
  MyQueue = (Queue_t *)malloc(sizeof(Queue_t));
  if ((NULL == MyQueue) || (NULL == ret_status)) {
    *ret_status = QUEUE_NULL_POINTER;
    MyQueue = NULL;
  } else {
    MyQueue->QueueArray = (void **)calloc(maxSize, sizeof(void *));
    if ((NULL == MyQueue->QueueArray)) {
      *ret_status = QUEUE_NOK;
      MyQueue = NULL;
    } else {
      MyQueue->ElementCount = 0;
      MyQueue->QueueFront = -1;
      MyQueue->QueueRear = -1;
      MyQueue->QueueMaxSize = maxSize;

      *ret_status = QUEUE_OK;
    }
  }

  return MyQueue;
}

/**
 * @brief
 *
 * @param queue_obj
 * @param item_ptr
 * @return QueueStatus_t
 */
QueueStatus_t EnqueueElement(Queue_t *queue_obj, void *item_ptr) {
  QueueStatus_t status = QUEUE_NOK;
  if ((NULL == queue_obj) || (NULL == item_ptr)) {
    status = QUEUE_NULL_POINTER;
  } else {
    if (QueueIsFull(queue_obj)) {
      status = QUEUE_FULL;
    } else {
      (queue_obj->QueueRear)++;
      if (queue_obj->QueueRear == queue_obj->QueueMaxSize) {
        queue_obj->QueueRear = 0;
      }
      queue_obj->QueueArray[queue_obj->QueueRear] = item_ptr;
      if (queue_obj->ElementCount == 0) {
        queue_obj->QueueFront = 0;
        queue_obj->ElementCount = 1;
      } else {

        (queue_obj->ElementCount)++;
      }

      status = QUEUE_OK;
    }
  }
  return status;
}

/**
 * @brief
 *
 * @param queue_obj
 * @param ret_status
 * @return void*
 */
void *DequeueElement(Queue_t *queue_obj, QueueStatus_t *ret_status) {

  void *DequeueEle = NULL;
  if ((NULL == queue_obj) || (NULL == ret_status)) {
    *ret_status = QUEUE_NULL_POINTER;
  } else {
    /*check if queue is empty*/
    if (!queue_obj->ElementCount) /* = (queue_obj->ElementCount == 0)*/
    {
      *ret_status = QUEUE_EMPTY;
      DequeueEle = NULL;
    } else {
      DequeueEle = queue_obj->QueueArray[queue_obj->QueueFront];
      (queue_obj->QueueFront)++;
      if (queue_obj->QueueFront == queue_obj->QueueMaxSize) {
        queue_obj->QueueFront = 0;
      }
      if ((1 == queue_obj->ElementCount)) {
        queue_obj->QueueFront = -1;
        queue_obj->QueueRear = -1;
      }
      (queue_obj->ElementCount)--;

      *ret_status = QUEUE_OK;
    }
  }
  return DequeueEle;
}

/**
 * @brief
 *
 * @param queue_obj
 * @param ret_status
 * @return void*
 */
void *QueueFront(Queue_t *queue_obj, QueueStatus_t *ret_status) {
  void *elementreturn = NULL;
  if ((NULL == queue_obj) || (NULL == ret_status)) {
    *ret_status = QUEUE_NULL_POINTER;
  } else {
    if (QueueIsEmpty(queue_obj)) /* = (queue_obj->ElementCount == 0)*/
    {
      *ret_status = QUEUE_EMPTY;
      elementreturn = NULL;
    } else {
      elementreturn = queue_obj->QueueArray[queue_obj->QueueFront];
      *ret_status = QUEUE_OK;
    }
  }
  return elementreturn;
}

/**
 * @brief
 *
 * @param queue_obj
 * @param ret_status
 * @return void*
 */
void *QueueRear(Queue_t *queue_obj, QueueStatus_t *ret_status) {
  void *elementreturn = NULL;
  if ((NULL == queue_obj) || (NULL == ret_status)) {
    *ret_status = QUEUE_NULL_POINTER;
  } else {
    if (!QueueIsEmpty(queue_obj)) {
      *ret_status = QUEUE_EMPTY;
      elementreturn = NULL;
    } else {
      elementreturn = queue_obj->QueueArray[queue_obj->QueueRear];
      *ret_status = QUEUE_OK;
    }
  }
  return elementreturn;
}

/**
 * @brief Get the Queue Count object
 *
 * @param queue_obj
 * @param QueueCount
 * @return QueueStatus_t
 */
QueueStatus_t GetQueueCount(Queue_t *queue_obj, uint32 *QueueCount) {
  QueueStatus_t status = QUEUE_NOK;
  if ((NULL == queue_obj) || (NULL == QueueCount)) {
    status = QUEUE_NULL_POINTER;
  } else {
    if (QueueIsEmpty(queue_obj)) {
      *QueueCount = 0;
      status = QUEUE_EMPTY;

    } else {
      *QueueCount = queue_obj->ElementCount;

      status = QUEUE_OK;
    }
  }
  return status;
}

/**
 * @brief
 *
 * @param queue_obj
 * @return QueueStatus_t
 */
QueueStatus_t DestroyQueue(Queue_t *queue_obj) {
  QueueStatus_t status = QUEUE_NOK;
  if ((NULL == queue_obj)) {
    status = QUEUE_NOK;
  } else {
    free(queue_obj->QueueArray);
    free(queue_obj);
    status = QUEUE_OK;
  }
  return status;
}