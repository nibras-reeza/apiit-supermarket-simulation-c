/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#include "customer.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

struct Customer
{
       char id[10];
       Stack *basket;
       int quantity;
       float total;
};

static void printLine(void);

Customer * newCustomer(void)
{
         Customer *c = malloc(sizeof(Customer));
         
         if(c!=NULL)
                    return c;
         else
             printf("Error: System out of memory.\n");
         
         return NULL;
}

int customerInit(Customer *c, char id[])
{
    
    if(c==NULL||id==NULL)
    {
                         printf("Error: Invalid customer or invalid customer id.");
                         return -1;
    }
    
    strcpy(c->id, id);
    c->basket = newStack();
    stackInit(c->basket);
    c->total=0;
    c->quantity = 0;
    
    return 0;
}
    
int addToBasket(Customer *c, basketItem *i)
{
    
    if(c==NULL||i==NULL)
    {
                         printf("Error: No customer to process or invalid item.");
                         return -1;
    }
    
    stackPush(c->basket, i);
    c->quantity+=getItemQuantity(i);
    
    return 0;
}

int remFromBasket(Customer *c)
{
    
    if(c==NULL)
    {
                         printf("Error: No customer to process.");
                         return -1;
    }
    
    basketItem *b = stackPop(c->basket);
    c->quantity-=getItemQuantity(b);
    delBasketItem(b);
    
    return 0;
}
    
int printBill(Customer *c)
{
    
    if(c==NULL)
    {
                         printf("Error: No customer to process.");
                         return -1;
    }
    
    int i;
    time_t invoiceTime;
    basketItem *b;
    Stack *temp=newStack();
    
    stackInit(temp);
    
    clearScreen();
    
    time(&invoiceTime);
    
    printf("\n\tInvoice id: %s\n\n\tDate/Time: %s\n\n", c->id, ctime(&invoiceTime));
    
    printf("\t| Code\t Item\t\t Price\t Qty.\t Subtotal\t\n");
    printLine();
    
    while(stackIsEmpty(c->basket)==0)
    {
             
                                     b=stackPop(c->basket);
                                     if(b!=NULL)
                                     {
                                         printItem(b);
                                         c->total+=subTotal(b);
                                         stackPush(temp, b);
                                     }
    }
    printf("\n\tTotal number of items: %d", c->quantity);
    printf("\n\n\tTotal Payable: %0.2f\n", c->total);
    printLine();
    
    while(stackIsEmpty(temp)==0)
                                stackPush(c->basket, stackPop(temp));
                                
    return 0;
}

int freeCustomer(Customer *c)
{
    if(c!=NULL)
    {
        while(stackIsEmpty(c->basket)==0)
                                         stackPop(c->basket);
                                         
        stackFree(c->basket);
        free(c);
        return 0;
    }
    else
    {
        return -1;
    }
}

static void printLine(void)
{
     int i;
     printf("\t");
     for(i=0; i<49 ;i++)
              printf("-");
     printf("\n");
}
