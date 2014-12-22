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

// Abstract definition of data types used internally in stack.
typedef struct stackNode stackNode;
typedef stackNode *stackNodePtr;

// Concrete definition of nodes that constitute a node.
struct stackNode
{
       stackData *data;
       stackNodePtr next;
};

// Concrete definition of data structure storing the stack.
struct Stack
{
       stackNodePtr top;
       int count;
};

Stack * newStack(void)
{
      // Use malloc to dynamically allocate memory.
      Stack *s = malloc(sizeof(Stack));
      
      // Ensure malloc succeeded and return pointer to newly allocated memory block.
      // Print an error and return NULL otherwise.
      if(s!=NULL)
                 return s;
      else
           printf("Error: System out of memory.\n");
           
      return NULL;
}
           
int stackInit(Stack *s)
{
    // Update new stack variable to represent an empty stack.
    s->top = NULL;
    s->count = 0;
    return 0; // Report success.
}

int stackPush(Stack *s, stackData *data)
{
    // Use malloc to dynamically allocate memory for node.
    stackNodePtr n = malloc(sizeof(stackNode));
    
    // Ensure malloc succeeded and return pointer to newly allocated memory block.
    // Print an error and return NULL otherwise.
    if(n==NULL)
    {
               printf("Error: System out of memory.\n");
               return -1;
    }
    
    n->data = data; // Store pointer to data in node.

    n->next = s->top; // Link new node to top of stack.

    s->top = n; // Update new top.
    
    s->count++;
    
    return 0; // Report success.
}

stackData * stackPop(Stack *s)
{
     // Read pointer to data stored at top of stack.
     stackData * data = stackTop(s);
     
     // If data was present at top node, remove it.
     if(data!=NULL)
     {
                   stackNodePtr temp = s->top; // Temporarily store current top.
                   s->top = s->top->next; // Update top to point to next element in stack.
                   free(temp); // Free memory block used by node.
                   s->count--;
     }

     return data; // NULL if queue is stack.
}

stackData * stackTop(Stack *s)
{
     // Return pointer to data at top of stack if stack is not empty.
     if(stackIsEmpty(s)==0)
                           return s->top->data;
     else
         printf("Error: Stack is empty.\n");
         
     return NULL;
}
     
int stackIsEmpty(Stack *s)
{
    if(s->top==NULL)
                    // Empty stack has no elements. Top is NULL.
                    return TRUE;
    else
        return FALSE;
}

int stackFree(Stack *s)
{
    // Remove all elements from stack till it becomes empty.
    while(stackIsEmpty(s)==0)
                             stackPop(s);
    
    // Free memory used by stack.
    free(s);
}

int stackSize(Stack *s)
{
    return s->count;
}
