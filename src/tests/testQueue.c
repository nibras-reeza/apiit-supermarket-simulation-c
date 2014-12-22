#include <stdio.h>
#include "testQueue.h"

int testQueueOps(void)
{
    int i;
    Queue *q = newQueue();
    
    printf("Queue creating. Ok.\n");
    
    queueInit(q);
    printf("Queue inits. Ok.\n");
    
    for(i=0; i<100; i++)
    {
             printf("Inserting %d to queue. ", i);
             queueData *temp=malloc(sizeof(queueData));
             *temp = i;
             queueInsert(q, temp);
             printf("Ok. L=%d\n",getQueueLength(q));
    }
    
    printf("Testing queue removal...\n");
    
    while(queueIsEmpty(q)==0)
    {
                          queueData *temp;
                          temp = queueRemove(q);
                          printf("%d L=%d\t", *temp,getQueueLength(q));
    }

    printf("Queue removal. Ok.\n");
    
        for(i=0; i<100; i++)
    {
             printf("Inserting %d to queue. ", i);
             queueData *temp=malloc(sizeof(queueData));
             *temp = i;
             queueInsert(q, temp);
             printf("Ok. L=%d\n",getQueueLength(q));
    }
    
    printf("Testing queue removal...\n");
    
    while(queueIsEmpty(q)==0)
    {
                          queueData *temp;
                          temp = queueRemove(q);
                          printf("%d L=%d\t", *temp,getQueueLength(q));
    }

    printf("Queue removal. Ok.\n");
    
    printf("Remove from empty queue.\n");
    queueRemove(q);
    printf("Ok\n");
    
    printf("Queue free test...\n");
    printf("Add elements to queue.");
    
    for(i=0; i<100; i++)
    {
             queueData *temp=malloc(sizeof(queueData));
             *temp = i;
             queueInsert(q, temp);
    }
    
    queueFree(q);
    
    printf("Queue destroyed. Ok.\n");
    
    printf("All tests passed.");
    
    return 0;
}
