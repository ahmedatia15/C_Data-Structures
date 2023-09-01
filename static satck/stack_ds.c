#include "stack_ds.h"
/**
 * @brief check stack if full
 *
 * @param my_stack
 * @return stack_status_t
 */
static stack_status_t stack_full(stack_ds_t *my_stack) {
  if (my_stack->stack_pointer == (STACK_MAX_SIZE - 1)) {
    return STACK_FULL;

  } else {
    return STACK_NOT_FULL;
  }
}

/*_____________________________________________________________________*/

/**
 * @brief check stack if empty
 *
 * @param my_stack
 * @return stack_status_t
 */
static stack_status_t stack_empty(stack_ds_t *my_stack) {
  if ((stack_ds_t *)-1 == my_stack) {
    return STACK_EMPTY;
  } else {
    return STACK_NOT_FULL;
  }
}

/*_____________________________________________________________________*/

/**
 * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
 *
 * @param my_stack pointer to stack
 * @return return_status_t
 */

return_status_t stack_init(stack_ds_t *my_stack) {
  return_status_t ret = R_NOk;
  if (NULL == my_stack) {
    ret = R_NOk;
  } else {
    my_stack->stack_pointer = -1;
    ret = R_ok;
  }

  return ret;
}

/*_____________________________________________________________________*/

/**
 * @brief This function pushes an item onto the stack.
 *
 * @param my_stack
 * @param value
 * @return return_status_t
 */
return_status_t stack_push(stack_ds_t *my_stack, uint32_t value) {
  return_status_t ret = R_NOk;
  if ((NULL == my_stack) || (stack_full(my_stack) == STACK_FULL)) {
    /* code */
    ret = R_NOk;
#if defined(STACK_DEBUG)
    printf("Error Stack is full can't push [%i] \n", value);
#endif // stack_pointer
  } else {
    my_stack->stack_pointer++;
    my_stack->data[my_stack->stack_pointer] = value;
#if defined(STACK_DEBUG)
    printf("value of [%i] pushed to stack \n", value);
#endif // stack_pointer

    ret = R_ok;
  }
  return ret;
}

/*_____________________________________________________________________*/

/**
 * @brief This function pops the item on the top of the stack.
 *
 * @param my_stack
 * @param value
 * @return return_status_t
 */
return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *value) {
  return_status_t ret = R_NOk;
  if ((NULL == my_stack) || (NULL == value) ||
      (stack_empty(my_stack) == STACK_EMPTY)) {
    ret = R_NOk;
#if defined(STACK_DEBUG)
    printf("Error Stack is empty i can't read data \n");
#endif // stack_pointer
  } else {
    *value = my_stack->data[my_stack->stack_pointer];
    my_stack->stack_pointer--;
#if defined(STACK_DEBUG)
    printf("value of [%i] popped to stack \n", *value);
#endif // stack_pointer
    ret = R_ok;
  }

  return ret;
}

/*_____________________________________________________________________*/

/**
 * @brief This function retrieves the data from the top of the
            stack without changing the stack.
 *
 * @param my_stack
 * @param value
 * @return return_status_t
 */
return_status_t stack_top(stack_ds_t *my_stack, uint32_t *value) {
  return_status_t ret = R_NOk;
  if ((NULL == my_stack) || (NULL == value) ||
      (stack_empty(my_stack) == STACK_EMPTY)) {
    ret = R_NOk;
#if defined(STACK_DEBUG)
    printf("Error Stack is empty i can't read data \n");
#endif // stack_pointer
  } else {
    *value = my_stack->data[my_stack->stack_pointer];
#if defined(STACK_DEBUG)
    printf("stack top value = [%i] \n", *value);
#endif // stack_pointer
    ret = R_ok;
  }

  return ret;
}
/**
 * @brief Returns size of stack.
 *
 * @param my_stack
 * @param stack_size
 * @return return_status_t
 */
return_status_t stack_size(stack_ds_t *my_stack, uint32_t *stack_size) {
  return_status_t ret = R_NOk;

  if ((NULL == my_stack) || (NULL == stack_size)) {
    ret = R_NOk;
#if defined(STACK_DEBUG)
    printf("Error Stack is NULL i can't read data\n");
#endif // stack_pointer
  } else {
    *stack_size = my_stack->stack_pointer + 1;
    printf("Stack size is [%i]\n", *stack_size);

    ret = R_ok;
  }
  return ret;
}

/*_____________________________________________________________________*/

/**
 * @brief Returns number of elements in stack.
 *
 * @param my_stack
 * @return return_status_t
 */
return_status_t stack_display(stack_ds_t *my_stack) {
  return_status_t ret = R_NOk;
  sint32_t counter = ZERO_INT;
  if ((NULL == my_stack) || (stack_empty(my_stack) == STACK_EMPTY)) {
    ret = R_NOk;
#if defined(STACK_DEBUG)
    printf("Error Stack is NULL i can't read data ,or stack is empty \n");
#endif // stack_pointer
  } else {
    printf("stack data : \n");
    for (counter = my_stack->stack_pointer; counter >= 0; counter--) {
      printf("%i\t", my_stack->data[counter]);
    }

    ret = R_ok;
  }
  return ret;
}
