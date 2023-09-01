#include "stack_ds.h"
#include <stdint.h>
#include <stdio.h>

stack_ds_t my_stack1;
stack_ds_t my_stack2;

uint32_t satck_pop_value = ZERO;
uint32_t satck_top_value = ZERO;
uint32_t satck_size_value = ZERO;

int main() {
  return_status_t ret = R_NOk;
  printf("Hello \n");
  ret = stack_init(&my_stack1);
  if (R_NOk == ret) {
    printf("stack1 faild to be intialized !! \n");
  } else {
    ret = stack_push(&my_stack1, 11);
    ret = stack_push(&my_stack1, 22);
    ret = stack_push(&my_stack1, 33);
    ret = stack_push(&my_stack1, 44);
    ret = stack_push(&my_stack1, 55);

    /*
      ret = stack_push(&my_stack1, 66); // faild
      ret = stack_push(&my_stack1, 77); // faild

      ret = stack_pop(&my_stack1, &satck_pop_value);
      printf("stack pop value =%i \n", satck_pop_value);
      ret = stack_pop(&my_stack1, &satck_pop_value);
      printf("stack pop value =%i \n", satck_pop_value);
      ret = stack_pop(&my_stack1, &satck_pop_value);
      printf("stack pop value =%i \n", satck_pop_value);
      ret = stack_pop(&my_stack1, &satck_pop_value);
      printf("stack pop value =%i \n", satck_pop_value);
      ret = stack_pop(&my_stack1, &satck_pop_value);
      if (R_NOk == ret) {
        printf("stack pop value =%i \n", satck_pop_value);
      }
      ret = stack_pop(&my_stack1, &satck_pop_value);

      printf("stack pop value =%i \n", satck_pop_value);

      ret = stack_pop(&my_stack1, &satck_pop_value);

      printf("stack pop value =%i \n", satck_pop_value);

      ret = stack_pop(&my_stack1, &satck_pop_value);

      printf("stack pop value =%i \n", satck_pop_value);
    */
    ret = stack_top(&my_stack1, &satck_top_value);
    if (R_NOk == ret) {
      printf("stack top value =%i \n", satck_top_value);
    }
    ret = stack_size(&my_stack1, &satck_size_value);
    if (R_NOk == ret) {
      printf("stack size value =%i \n", satck_size_value);
    }
    ret = stack_display(&my_stack1);
    if (R_NOk == ret) {
      printf("stack\n");
    }
  }
  ret = stack_init(&my_stack2);
  if (R_NOk == ret) {
    printf("stack1 faild to be intialized !! \n");
  } else {
  }

  return 0;
}
