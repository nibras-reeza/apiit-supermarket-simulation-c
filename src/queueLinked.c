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
    q->front = NULL;
    q->rear = NULL;
    q->length = 0;
}

int queueInsert(Queue *q, queueData *data)
{
    queueNodePtr n = malloc(sizeof(queueNode));
    
    if(n==NULL)
    {
               printf("Error: System out of memory.\n");
               return -1;
    }
    
    n->data = data;
    n->next = NULL;
    
    if(q->front!=NULL)
    {
                      q->rear->next = n;
                      q->rear =n;
    }
    else
    {
        q->front = n;
        q->rear = n;
    }
    
    q->length++;
        
    return 0;
}

queueData *queueRemove(Queue *q)
{
          queueData *data = queueFront(q);
          if(data!=NULL)
          {
                        queueNodePtr temp = q->front; 
                        q->front = q->front->next;
                        free(temp);
                        q->length--;
          }
          return data; 
}

queueData *queueFront(Queue *q)
{
          if(queueIsEmpty(q)==0)
                                return q->front->data;
          else
              printf("Error: Queue is empty.\n");
              
          return NULL;
}

queueData *queueRear(Queue *q)
{
          if(queueIsEmpty(q)==0)
                                return q->rear->data;
          else
              printf("Error: Queue is empty.\n");
              
          return NULL;
}


int queueIsEmpty(Queue *q)
{
    if(q->front==NULL)
                      return 1;
    else
        return 0;
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
