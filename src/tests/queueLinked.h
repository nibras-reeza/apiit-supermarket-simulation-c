/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#ifndef QUEUE_H_
#define QUEUE_H_

typedef int queueData;

typedef struct queueNode queueNode;
typedef queueNode *queueNodePtr;

typedef struct Queue Queue;

struct queueNode
{
       queueData *data;
       queueNodePtr next;
};

struct Queue
{
       queueNodePtr front;
       queueNodePtr rear;
       int length;
};


Queue *newQueue(void);
int queueInit(Queue *);

int queueInsert(Queue *, queueData *);
queueData *queueRemove(Queue *);

queueData *queueRear(Queue *);
queueData *queueFront(Queue *);

int queueIsEmpty(Queue *);

int getQueueLength(Queue *);

int queueFree(Queue *);

#endif
