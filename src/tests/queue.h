/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#define MAX 100

typedef int queueData;

typedef struct Queue Queue;

struct Queue
{
       queueData *list[MAX];
       int front;
       int rear;
       int length;
};


Queue *newQueue(void);
int queueInit(Queue *);

int queueInsert(Queue *, queueData *);
queueData *queueRemove(Queue *);

queueData *queueRear(Queue *);
queueData *queueFront(Queue *);

int queueIsEmpty(Queue *);
int queueIsFull(Queue *);

int getQueueLength(Queue *);

int queueFree(Queue *);

#endif
