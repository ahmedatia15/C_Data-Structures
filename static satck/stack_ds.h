#ifndef _STACK_DS_H
#define _STACK_DS_H

#include "std_types.h"

#define STACK_MAX_SIZE 5

#define STACK_DEBUG

typedef struct stack_ds {
  sint32_t stack_pointer;
  uint32_t data[STACK_MAX_SIZE];
} stack_ds_t;

typedef enum stack_status {
  STACK_EMPTY,
  STACK_FULL,
  STACK_NOT_FULL
} stack_status_t;
/**
 * @brief initilaze the stack pointer
 *
 * @param my_stack pointer to stack
 * @return return_status_t
 */
return_status_t stack_init(stack_ds_t *my_stack);
return_status_t stack_push(stack_ds_t *my_stack, uint32_t value);
return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *value);
return_status_t stack_top(stack_ds_t *my_stack, uint32_t *value);
return_status_t stack_size(stack_ds_t *my_stack, uint32_t *stack_size);
return_status_t stack_display(stack_ds_t *my_stack);
#endif //_STACK_DS_H