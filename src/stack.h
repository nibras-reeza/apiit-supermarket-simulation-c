/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
  
  This file defines the API for the Stack used in the program. This file does
  not depend on any of the other files in the program. 
*/

#ifndef STACK_H_
#define STACK_H_

#include "basketItem.h"
// The stack is used to store items purchased and their quantity. Therefore,
// basketItem.h is being included to import the concrete definition for
// stackData which is the abstract type which defines data stored in stack.

#define TRUE 1
#define FALSE 0
// Define TRUE and FALSE for convenience.

typedef basketItem stackData; // Abstract definition for data stored in stack.

typedef struct Stack Stack; // ADT of Stack data structure.

Stack * newStack(void);
// Creates a dynamic variable for stack and returns a pointer to it.
// Returns NULL if system is out of memory.

int stackInit(Stack *);
// Allows to initialize a stack declared earlier.
// Replaces junk values with values representing an empty stack.
// Returns 0 on success and -1 in case of failure.

int stackPush(Stack *, stackData *);
// Pushes a pointer to data into the stack.
// Returns 0 on success and -1 in case failiure.

stackData * stackPop(Stack *);
// Removes and returns pointer to data at top of stack.
// Returns NULL in case of empty stack.

stackData * stackTop(Stack *);
// Returns pointer to data at top of stack without modifying it.
// Returns NULL in case of empty stack.

int stackIsEmpty(Stack *);
// Returns 1 if stack is empty and 0 if it is not.

int stackFree(Stack *);
// Removes all data from stack and frees memory held by stack.
// Returns 0 on success and -1 in case failure.

int stackSize(Stack *);
// Returns the number of items in stack.

#endif
