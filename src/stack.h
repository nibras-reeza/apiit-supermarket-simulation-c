/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#ifndef STACK_H_
#define STACK_H_

#include "basketItem.h"

typedef basketItem stackData;

typedef struct stackNode stackNode;
typedef stackNode *stackNodePtr;


typedef struct Stack Stack;

struct stackNode
{
       stackData *data;
       stackNodePtr next;
};

struct Stack
{
       stackNodePtr top;
       int count;
};


Stack * newStack(void);
int stackInit(Stack *);
int stackPush(Stack *, stackData *);
stackData * stackPop(Stack *);
stackData * stackTop(Stack *);
int stackIsEmpty(Stack *);
int stackFree(Stack *);

int stackSize(Stack *);

#endif
