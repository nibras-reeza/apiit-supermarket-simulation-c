/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

Queue *newQueue(void)
{
     Queue *q = malloc(sizeof(Queue));
     
     if(q!=NULL)
                return q;
     else
         printf("Error: System out of memory.\n");
     
     return NULL;
}

int queueInit(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->length = 0;
}

int queueInsert(Queue *q, queueData *data)
{
    if(queueIsFull(q)==0)
    {
                         q->rear=(q->rear+1)%MAX;
                         q->list[q->rear]=data;
                         q->length++;
                         return 0;
    }
    else
    {
        printf("Error: Queue is full.");
        return -1;
    }
}

queueData *queueRemove(Queue *q)
{
          queueData *data = queueFront(q);
          if(data!=NULL)
          {
                        q->front=(q->front+1)%MAX;
                        q->length--;
          }
          return data; 
}

queueData *queueFront(Queue *q)
{
          if(queueIsEmpty(q)==0)
                                return q->list[q->front];
          else
              printf("Error: Queue is empty.\n");
              
          return NULL;
}

queueData *queueRear(Queue *q)
{
          if(queueIsEmpty(q)==0)
                                return q->list[q->rear];
          else
              printf("Error: Queue is empty.\n");
              
          return NULL;
}


int queueIsEmpty(Queue *q)
{
    if(q->length==0)
                      return 1;
    else
        return 0;
}

int queueIsFull(Queue *q)
{
    if(q->length<MAX)
                      return 0;
    else
        return 1;
}

int getQueueLength(Queue *q)
{

    return q->length;
}

int queueFree(Queue *q)
{
    while(queueIsEmpty(q)==0)
                             queueRemove(q);
                             
    free(q);
    
    return 0;
}
