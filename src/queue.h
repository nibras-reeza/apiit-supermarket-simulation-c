/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 28/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
  
  Defines the API functions available to the program using queue.h.
  Implementation details are hidden queue.c.
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include "customer.h"

// Define the ADTs.
typedef Customer queueData; // ADT for data stored in queue.
typedef struct Queue Queue; // Abstract definition of Queue.

// Define the prototypes of functions available to developer.

Queue *newQueue(void); 
// Creates a dynamic variable for queue and returns a pointer to it.
// Returns NULL if system is out of memory.

int queueInit(Queue *);
// Allows to initialize a queue created earlier.
// Replaces junk values with values representing an empty queue.
// Returns 0 on success and -1 in case failiure.

int queueInsert(Queue *, queueData *);
// Inserts a pointer to the data to be stored in to the queue.
// Returns 0 on success and -1 in case failiure.

queueData *queueRemove(Queue *);
// Removes data from the queue returns a pointer to it.
// Returns NULL in case of empty queue.

queueData *queueRear(Queue *);
// Returns a pointer to the data at rear. Does not alter queue.
// Returns NULL in case of empty queue.

queueData *queueFront(Queue *);
// Returns a pointer to the data at front. Does not alter queue.
// Returns NULL in case of empty queue.

int queueIsEmpty(Queue *);
// Returns 1 if queue is empty and 0 if it is not.

int getQueueLength(Queue *);
// Returns the number of items in queue.

int queueFree(Queue *);
// Removes all data from queue and frees memory held by queue.
// Returns 0 on success and -1 in case failure.

#endif
