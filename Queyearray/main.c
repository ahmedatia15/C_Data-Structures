#include "Platform_Types.h"
#include "Queyearray.h"
#include <stdio.h>
#include <stdlib.h>

QueueStatus_t return_status = QUEUE_NOK;
uint32 MaxQueueOneEle;
Queue_t *queue1;

uint32 numberone = 0x11;
uint32 numbertwo = 0x22;
uint32 numberthree = 0x33;
uint32 numberfour = 0x44;
uint32 numberfive = 0x55;

uint32 numberQueueEle;

void *DequeueEle;
int main() {
  printf("-----------------------\n");
  printf("plz enter max element of queue you want \n");
  scanf_s("%i", &MaxQueueOneEle);
  queue1 = CreateQueue(MaxQueueOneEle, &return_status);
  printf("[0]if function faild [1]if function done -->[%i]\n", return_status);

  return_status = EnqueueElement(queue1, &numberone);
  printf("-->[%i]\n", return_status);
  return_status = EnqueueElement(queue1, &numbertwo);
  printf("-->[%i]\n", return_status);
  return_status = EnqueueElement(queue1, &numberthree);
  printf("-->[%i]\n", return_status);
  //-----------------------------------------
  DequeueEle = QueueRear(queue1, &return_status);
  printf("-->[%i]\n", return_status);
  printf("queue_rear_Element = [%x]\n", *(uint32 *)DequeueEle);
  //-----------------------------------------
  return_status = EnqueueElement(queue1, &numberfour);
  printf("-->[%i]\n", return_status);
  return_status = EnqueueElement(queue1, &numberfive);
  printf("-->[%i]\n", return_status);
  return_status = EnqueueElement(queue1, &numberfive);
  printf("-->[%i]\n", return_status);
  printf("\n\n\n");
  //-----------------------------------------
  return_status = GetQueueCount(queue1, &numberQueueEle);
  printf("queue status-> [%i]\n", return_status);
  printf("queue element count = %i\n", numberQueueEle);
  //-----------------------------------------

  printf("-----------------------\n");

  DequeueEle = DequeueElement(queue1, &return_status);
  printf("-->[%i]\n", return_status);
  printf("queueElement = [%x]\n", *(uint32 *)DequeueEle);

  printf("-----------------------\n");
  DequeueEle = QueueFront(queue1, &return_status);
  printf("-->[%i]\n", return_status);
  printf("queuefront = [%x]\n", *(uint32 *)DequeueEle);
  printf("-----------------------\n");

  DequeueEle = DequeueElement(queue1, &return_status);
  printf("-->[%i]\n", return_status);
  printf("queueElement = [%x]\n", *(uint32 *)DequeueEle);
  DequeueEle = DequeueElement(queue1, &return_status);
  printf("-->[%i]\n", return_status);
  printf("queueElement = [%x]\n", *(uint32 *)DequeueEle);
  DequeueEle = DequeueElement(queue1, &return_status);
  printf("-->[%i]\n", return_status);
  printf("queueElement = [%x]\n", *(uint32 *)DequeueEle);
  DequeueEle = DequeueElement(queue1, &return_status);
  printf("-->[%i]\n", return_status);
  printf("queueElement = [%x]\n", *(uint32 *)DequeueEle);

  return_status = DestroyQueue(queue1);
  printf("-->[%i]\n", return_status);

  return 0;
}
