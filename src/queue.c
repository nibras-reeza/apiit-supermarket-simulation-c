/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 28/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Abstract definition of data types used internally in queue.
typedef struct queueNode queueNode; 
typedef queueNode *queueNodePtr;

// Concrete definition of each node of queue.
struct queueNode
{
       queueData *data;
       queueNodePtr next;
};

// Concrete definition of queue.
struct Queue
{
       queueNodePtr front;
       queueNodePtr rear;
       int length;
};

// Prototypes for helper functions. Not part of API. 
// Therefore, defined as static. Cannot be called from
// other files.

static queueNode *newNode(void);
// Creates a new node and returns a pointer to it. Returns NULL on failure.

static int initNode(queueNode *, queueData *);
// Encapsulates pointer to data in a previously allocated node variable.
// Returns 0 on success and -1 in case failiure.

static queueData *stripNode(queueNode *);
// Retrieves pointer to data stored in a node and returns it. Also, destroys node.
// Returns NULL in case of failure.

static queueData *readNode(queueNode *);
// Returns pointer to data stored in node. Does not alter queue or node.
// Returns NULL on failure.

static queueNode *frontNode(Queue *);
// Returns a pointer to the node at the front of queue.
// Returns NULL in case of empty queue.

static queueNode *rearNode(Queue *);
// Returns a pointer to the node at the rear of queue.
// Returns NULL in case of empty queue.

static int insertNode(Queue *, queueNode *);
// Inserts a new node into queue.
// Returns 0 on success and -1 in case failiure.

static queueNode *removeNode(Queue *);
// Removes and returns node at front of queue.
// Returns NULL in case of empty queue.

Queue *newQueue(void)
{
      // Use malloc to dynamically allocate memory required to store queue.
     Queue *q = malloc(sizeof(Queue));
     
     // Ensure malloc succeeded and return pointer to newly allocated memory block.
     // Print an error and return NULL otherwise.
     if(q!=NULL)
                return q;
     else
         printf("Error: System out of memory.\n");
     
     return NULL;
}

int queueInit(Queue *q)
{
    // Make sure a NULL pointer is not passed.
    if(q!=NULL)
    {
        // Set queue to represent empty queue.
        q->front = NULL;
        q->rear = NULL; 
        q->length = 0;
        return 0;
    }
    else
    {
        // Print and error and return error code if function fails.
        printf("Error: Invalid queue.");
        return -1;
    }
}

int queueInsert(Queue *q, queueData *data)
{
    int temp;
    
    // Create a new node to insert.
    queueNodePtr  n = newNode();
	
	// Ensure node was created successfully. Return error otherwise.
	if(n==NULL)
	           return -1;
    
    // Encapsulate pointer to data in node.
    initNode(n, data);
    
    // Insert node to queue and retrieve insertion status code.
    temp = insertNode(q, n);
	
	// Check if insertion succeeded.
	if(temp==0)
	           return 0; // Return sucess if insertion succeeded.

    return -1; // Return error by default. Success code would've been returned earlier
               // if function succeeded.
}

queueData *queueRemove(Queue *q)
{
          // Ensure queue isn't empty.
          if(queueIsEmpty(q)==1)
          {
                                // Print error and return NULL if queue is empty.
                                printf("Error: Queue is empty.\n");
								return NULL; 
          }
          else
		  {
              // Remove node from queue, retrieve data and destroy node.
			queueData *data = stripNode(removeNode(q));
            return data; // Return data retrieved.
		  }      
}

queueData *queueFront(Queue *q)
{
          // Ensure queue is not empty.
          if(queueIsEmpty(q)==1)
		  {
                                // Print error and return NULL if queue is empty.
                                printf("Error: Queue is empty.\n");
								return NULL;
		  }
          else
          // Retrieve data from the front node without modifying node/queue.
              return readNode(frontNode(q));      
}

queueData *queueRear(Queue *q)
{
          // Ensure queue is not empty.
          if(queueIsEmpty(q)==1)
		  {
                                // Print error and return NULL if queue is empty.
                                printf("Error: Queue is empty.\n");
								return NULL;
		  }
          else
          // Retrieve data from the front node without modifying node/queue.
              return readNode(rearNode(q));
}

int queueIsEmpty(Queue *q)
{
    if(q->front==NULL)
                      return 1; // Queue is empty if there is no node at front.
    else
        return 0;
}

int getQueueLength(Queue *q)
{
    return q->length; // Return the number of items in queue.
}

int queueFree(Queue *q)
{
    // Remove elements from queue till it becomes empty.
    while(queueIsEmpty(q)==0)
                             queueRemove(q);
                             
    free(q); // Free memory used for queue.
    
    return 0; // Success.
}

static queueNodePtr newNode(void)
{
       // Use malloc to dynamically allocate memory required to store node.
       queueNodePtr n = malloc(sizeof(queueNode));
       
       // Ensure malloc succeeded and return pointer to newly allocated memory block.
       // Print an error otherwise.
       if(n==NULL)
                  printf("Error: System out of memory.\n");
               
       return n; // n=NULL on failure.
}

static int initNode(queueNodePtr n, queueData *data)
{
       // Ensure node passed is valid.
       if(n!=NULL)
       {
           n->data = data; // Encapsulate data in node.
           n->next = NULL; // Ground the node.
           return 0;
       }
       else
       {
           // Print an error code and return error if node is invalid.
           printf("Error: Not a node.\n");
           return -1;
       }
}

static queueData *stripNode(queueNodePtr n)
{
       queueData *d;
       if(n!=NULL)
       {
                  // Extract pointer to data from node and free memory occupied by node.
                  d=n->data;
                  free(n);
       }
       else
           d=NULL; 
           
       return d;
}
       
static queueData *readNode(queueNodePtr n)
{
       queueData *d;
       if(n!=NULL)
                  // Extract pointer to data.
                  d=n->data;
       else
           d=NULL; // Causes program to return NULL if node is invalid.
           
       return d;
}

static queueNodePtr frontNode(Queue *q)
{
       // Ensure queue is not empty.
       if(queueIsEmpty(q)==0)
                                return q->front; // Return pointer to node at front of queue.
       else
           printf("Error: Queue is empty.\n"); // Print error and return NULL if queue is empty.
           
       return NULL;
}

static queueNodePtr rearNode(Queue *q)
{
       // Ensure queue is not empty.
       if(queueIsEmpty(q)==0)
                                return q->rear; // Return pointer to node at front of queue.
       else
           printf("Error: Queue is empty.\n"); // Print error and return NULL if queue is empty.
           
       return NULL;
}

static int insertNode(Queue *q, queueNodePtr n)
{
       // Ensure paramters are valid. Print error and return error code otherwise.
       if(q==NULL||n==NULL)
       {
                           printf("Error: Insertion failed.\n");
                           return -1;
       }
       
       if(q->front!=NULL)
       {
                         // If queue is not empty, do thise.
                         q->rear->next = n; // Insert new node to rear.
                         q->rear =n; // Update new rear of queue.
       }
       else
       {
           // If queue is empty, rear and front are same and refer to the first
           // element to be inserted.
           q->front = n;
           q->rear = n;
       }
       
       q->length++; // Update queue size.
       
       return 0; // Report function success.
}
        
static queueNodePtr removeNode(Queue *q)
{
       // Store current front node temporarily in another variable.
       queueNodePtr temp = q->front; 
       
       // Remove node from front.
       // Update front to point to next node.
       q->front = q->front->next;
       
       q->length--; // Update length.
       return temp; // Return pointer to removed node.
}
