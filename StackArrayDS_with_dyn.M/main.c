#include "Platform_Types.h"
#include "StackArrayDS.h"
#include <stdio.h>
#include <stdlib.h>
uint32 stack1_size;
Stack_t *stack1 = NULL;
uint32 var1 = 0x11;
float32 var2 = 2.14;
char var3 = 'a';
uint32 stack_count;

void *stacktopelement = NULL;

int main() {
  printf("-------------------------------\n");
  StackStatus_t stack1_status = STACK_NOK;

  printf("enter number of stack onre element\n");
  scanf_s("%i", &stack1_size);
  stack1 = CreateStack(stack1_size, &stack1_status);
  if (stack1) {
    printf("stack one created normally \n");
  }
  printf("-------------------------------\n");
  stack1_status = PushStack(stack1, &var1);
  printf("stack one status = %i \n", stack1_status);
  stack1_status = PushStack(stack1, &var2);
  printf("stack one status = %i \n", stack1_status);
  stack1_status = PushStack(stack1, &var3);
  printf("stack one status = %i \n", stack1_status);
  stack1_status = PushStack(stack1, &var3);
  printf("stack one status = %i \n", stack1_status);
  printf("-------------------------------\n");
  stack1_status = StackCount(stack1, &stack_count);
  printf("stack one status = %i \n", stack_count);

  printf("-------------------------------\n");

  stacktopelement = StackTop(stack1, &stack1_status);
  printf("stack one status = %i \n", stack1_status);
  printf("value of stack to = %c\n", *(char *)stacktopelement);
  printf("-------------------------------\n");
  stacktopelement = PopStack(stack1, &stack1_status);
  printf("stack one status = %i \n", stack1_status);
  printf("value of stack to = %c\n", *(char *)stacktopelement);
  stacktopelement = PopStack(stack1, &stack1_status);
  printf("stack one status = %i \n", stack1_status);
  printf("value of stack to = %f\n", *(float32 *)stacktopelement);
  stacktopelement = PopStack(stack1, &stack1_status);
  printf("stack one status = %i \n", stack1_status);
  printf("value of stack to = 0x%x\n", *(uint32 *)stacktopelement);
  stacktopelement = PopStack(stack1, &stack1_status);
  printf("stack one status = %i \n", stack1_status);
  printf("value of stack to = 0x%x\n", *(uint32 *)stacktopelement);

  printf("-------------------------------\n");

  stack1 = DestroyStack(stack1, &stack1_status);
  if (!stack1) {
    printf("stack one destroy done \n");
  }

  return 0;
}
