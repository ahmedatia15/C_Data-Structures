#include "StackArrayDS.h"
#include <stdio.h>

// helper function

static uint8 StackIsImpty(Stack_t *stack_obj);
static uint8 StackISFull(Stack_t *stack_obj);

Stack_t *CreateStack(uint32 maxSize, StackStatus_t *ret_status) {
  Stack_t *my_stack = NULL;
  if ((NULL == ret_status)) {
    *ret_status = STACK_NULL_POINTER;
    my_stack = NULL;
  } else {
    my_stack = (Stack_t *)malloc(sizeof(Stack_t));
    if (!my_stack) {
      *ret_status = STACK_NOK;
      my_stack = NULL;
    } else {
      my_stack->StackTop = -1;
      my_stack->ElementCount = 0;
      my_stack->StackMaxSize = maxSize;
      my_stack->StackArray =
          (void **)calloc(my_stack->StackMaxSize, sizeof(void *));
      if (!my_stack->StackArray) {
        free(my_stack);
        my_stack = NULL;
        *ret_status = STACK_NOK;
      } else {
        *ret_status = STACK_OK;
      }
    }
  }

  return my_stack;
}
Stack_t *DestroyStack(Stack_t *stack_obj, StackStatus_t *ret_status) {
  if ((NULL == ret_status) || (NULL == stack_obj)) {
    *ret_status = STACK_NULL_POINTER;
  } else {
    free(stack_obj->StackArray);
    free(stack_obj);
    *ret_status = STACK_OK;
  }
  return NULL;
}
StackStatus_t PushStack(Stack_t *stack_obj, void *itemPtr) {
  StackStatus_t StackStatus = STACK_NOK;
  if ((NULL == stack_obj) || (NULL == itemPtr)) {
    StackStatus = STACK_NULL_POINTER; /* NULL pointer passed to the function */
  } else {
    if (StackISFull(stack_obj)) {
      StackStatus = STACK_FULL; /* Stack is full, prevent stack overflow */
    } else {
      (stack_obj->StackTop)++; /* Points to the next element in the stack */
      stack_obj->StackArray[stack_obj->StackTop] = itemPtr;
      (stack_obj->ElementCount)++; /* Increment the number of elements in the
                                      stack */
      StackStatus = STACK_OK;
    }
  }
  return StackStatus;
}
void *PopStack(Stack_t *stack_obj, StackStatus_t *ret_status) {
  void *dataptrout = NULL;
  if ((NULL == ret_status) || (NULL == stack_obj)) {
    *ret_status = STACK_NULL_POINTER;
    dataptrout = NULL;

  } else {
    if (StackIsImpty(stack_obj)) {
      *ret_status = STACK_EMPTY;
      dataptrout = NULL;
    } else {
      dataptrout = (stack_obj->StackArray[stack_obj->StackTop]);
      (stack_obj->StackTop)--;
      (stack_obj->ElementCount)--;
      *ret_status = STACK_OK;
    }
  }
  return dataptrout;
}
void *StackTop(Stack_t *stack_obj, StackStatus_t *ret_status) {
  void *dataptrout = NULL;
  if ((NULL == ret_status) || (NULL == stack_obj)) {
    *ret_status = STACK_NULL_POINTER;
    dataptrout = NULL;

  } else {
    if (StackIsImpty(stack_obj)) {
      *ret_status = STACK_EMPTY;
      dataptrout = NULL;
    } else {
      /*copy top element to user*/
      dataptrout = (stack_obj->StackArray[stack_obj->StackTop]);
      *ret_status = STACK_OK;
    }
  }
  return dataptrout;
}
StackStatus_t StackCount(Stack_t *stack_obj, uint32 *stack_count) {
  StackStatus_t stackstatus = STACK_NOK;
  if ((NULL == stack_obj) || (NULL == stack_count)) {
    stackstatus = STACK_NULL_POINTER;
  } else {
    *stack_count = stack_obj->ElementCount;
    stackstatus = STACK_OK;
  }
  return stackstatus;
}

// -------------------------
static uint8 StackIsImpty(Stack_t *stack_obj) {
  return (stack_obj->ElementCount == 0);
}
static uint8 StackISFull(Stack_t *stack_obj) {
  return (stack_obj->ElementCount == stack_obj->StackMaxSize);
}
// -------------------------
/*
static StackStatus_t StackISFull(Stack_t *stack_obj) {
  StackStatus_t stackstatus = STACK_NOK;

  if (stack_obj->ElementCount == stack_obj->StackMaxSize) {
    stackstatus = STACK_FULL;
  } else {
    stackstatus = STACK_NOK;
  }
  return stackstatus;
}
*/