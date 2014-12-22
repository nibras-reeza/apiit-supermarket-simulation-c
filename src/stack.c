/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

Stack * newStack(void)
{
      Stack *s = malloc(sizeof(Stack));
      
      if(s!=NULL)
                 return s;
      else
           printf("Error: System out of memory.\n");
           
      return NULL;
}
           
int stackInit(Stack *s)
{
    s->top = NULL;
    return 0;
}

int stackPush(Stack *s, stackData *data)
{
    stackNodePtr n = malloc(sizeof(stackNode));
    
    if(n==NULL)
    {
               printf("Error: System out of memory.\n");
               return -1;
    }
    
    n->data = data;

    n->next = s->top;

    s->top = n;
    
    s->count++;
    
    return 0;
}

stackData * stackPop(Stack *s)
{
     stackData * data = stackTop(s);
     
     if(data!=NULL)
     {
                   stackNodePtr temp = s->top;
                   s->top = s->top->next;
                   free(temp);
     }
     
     s->count--;
     
     return data;
}

stackData * stackTop(Stack *s)
{
     if(stackIsEmpty(s)==0)
                           return s->top->data;
     else
         printf("Error: Stack is empty.\n");
         
     return NULL;
}
     
int stackIsEmpty(Stack *s)
{
    if(s->top==NULL)
                    return 1;
    else
        return 0;
}

int stackFree(Stack *s)
{
    while(stackIsEmpty(s)==0)
                             stackPop(s);
    free(s);
}

int stackSize(Stack *s)
{
    return s->count;
}
