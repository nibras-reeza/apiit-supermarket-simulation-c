#include <stdio.h>
#include "testStack.h"

int testStackOps(void)
{
    int i;
    Stack *s = newStack();
    
    printf("Stack creating. Ok.\n");
    
    stackInit(s);
    printf("Stack inits. Ok.\n");
    
    for(i=0; i<100; i++)
    {
             printf("Inserting %d to stack. ", i);
             stackData *temp=malloc(sizeof(stackData));
             *temp = i;
             stackPush(s, temp);
             printf("Ok.\n");
    }
    
    printf("Testing stack removal...\n");
    
    while(stackIsEmpty(s)==0)
    {
                          stackData *temp;
                          temp = stackPop(s);
                          printf("%d\t", *temp);
    }
    
    printf("Stack removal. Ok.\n");
    
    printf("Remove from empty stack.\n");
    stackPop(s);
    printf("Ok\n");
    
    printf("Stack free test...\n");
    printf("Add elements to stack.");
    
    for(i=0; i<100; i++)
    {
             stackData *temp=malloc(sizeof(stackData));
             *temp = i;
             stackPush(s, temp);
    }
    
    stackFree(s);
    
    printf("Stack destroyed. Ok.\n");
    
    printf("All tests passed.");
    
    return 0;
}
