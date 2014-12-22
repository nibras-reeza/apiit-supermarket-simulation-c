/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#include "basketItem.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

basketItem *newBasketItem(Product *p, int q)
{
           basketItem *b = malloc(sizeof(basketItem));
           
           if(b==NULL)
           {
               printf("Error: System out of memory.\n");
               return NULL;
           }
           
           if(p==NULL)
           {
                      printf("Error: Invalid product.\n");
                      return NULL;
           }
    
           b->p = p;
           b->quantity = q;
           subTotal(b);
           return b;
}

basketItem *delBasketItem(basketItem *b)
{
           if(b!=NULL)
                      free(b);
}

float subTotal(basketItem *b)
{
      if(b!=NULL)
      {
          b->subTotal = b->p->price * b->quantity;
          return b->subTotal;
      }
      else
      {
          printf("Error: Invalid item in basket.\n");
          return 0.0;
      }
}

void printItem(basketItem *b)
{
     if(b!=NULL)
     {
                printf("\t| %03d\t %s\t\t %.2f\t  %d\t  %.2f\t\n", getProductCode(b->p), getProductName(b->p), getProductPrice(b->p), b->quantity, b->subTotal);
     }
     else
     {
         printf("Error: Invalid item in basket.\n");
     }
}
