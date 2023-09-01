#ifndef _STACK_ARRAY_DS_H_
#define _STACK_ARRAY_DS_H_

#include "Platform_Types.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  void **StackArray;   /* Points to the array that allocated in the heap */
  sint32 ElementCount; /* Has the actual number of elements in the stack */
  uint32 StackMaxSize; /* Has the maximum number of elements in the stack */
  sint32 StackTop;     /* Has the index of the top element in the stack */
} Stack_t;

typedef enum {
  STACK_NOK = 0,     /* Stack operation not performed successfully */
  STACK_OK,          /* Stack operation performed successfully  */
  STACK_FULL,        /* Stack is full */
  STACK_EMPTY,       /* Stack is empty */
  STACK_NULL_POINTER /* NULL pointer passed to the Stack operations */
} StackStatus_t;
/**
 * @brief Create a Stack object
 *
 * @param maxSize
 * @param ret_status
 * @return Stack_t*
 */
Stack_t *CreateStack(uint32 maxSize, StackStatus_t *ret_status);
// ___________________________________________
/**
 * @brief his function releases all memory to the heap.
 *
 * @param stack_obj
 * @param ret_status
 * @return Stack_t*
 */
Stack_t *DestroyStack(Stack_t *stack_obj, StackStatus_t *ret_status);
// ___________________________________________
/**
 * @brief This function pushes an item onto the stack.
 *
 * @param stack_obj
 * @param itemPtr
 * @return StackStatus_t
 */
StackStatus_t PushStack(Stack_t *stack_obj, void *itemPtr);
// ___________________________________________
/**
 * @brief This function pops the item on the top of the stack.
 *
 * @param stack_obj
 * @param ret_status
 * @return void*
 */
void *PopStack(Stack_t *stack_obj, StackStatus_t *ret_status);
// ___________________________________________
/**
 * @brief  This function retrieves the data from the top of the
           stack without changing the stack.
 * @param stack_obj
 * @param ret_status
 * @return void*
 */
void *StackTop(Stack_t *stack_obj, StackStatus_t *ret_status);
// ___________________________________________
/**
 * @brief Returns number of elements in stack.
 *
 * @param stack_obj
 * @param stack_count
 * @return StackStatus_t
 */
StackStatus_t StackCount(Stack_t *stack_obj, uint32 *stack_count);

// ___________________________________________

#endif // _STACK_ARRAY_DS_H_
