#ifndef STACK_H_
#define STACK_H_



typedef int stackData;

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
