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

// Concrete definition of a basket item.
struct basketItem
{
       Product *p;
       int quantity;
       float subTotal;
};

basketItem *newBasketItem(Product *p, int q)
{
           // Use malloc to dynamically allocate memory.
           basketItem *b = malloc(sizeof(basketItem));
           
           // Ensure malloc succeeded and return pointer to newly allocated memory block.
           // Print an error and return NULL otherwise.
           if(b==NULL)
           {
               printf("Error: System out of memory.\n");
               return NULL;
           }
           
           // Ensure product passed is valid.
           // Print an error and return NULL otherwise.
           if(p==NULL)
           {
                      printf("Error: Invalid product.\n");
                      return NULL;
           }
           
           // Create basketItem consisting of a pointer to product and quantity.
           b->p = p;
           b->quantity = q;
           
           // Update sub-total.
           subTotal(b);
           
           // Return pointer to initialized variable.
           return b;
}

int *delBasketItem(basketItem *b)
{
           if(b!=NULL)
                      free(b); // If b is a valid pointer, free memory held by it.
           return 0;
}

float subTotal(basketItem *b)
{
      // Assert that b is valid.
      // Print an error and return 0.0 otherwise.
      if(b!=NULL)
      {
          // Calculate sub-total and store it.
          b->subTotal = getProductPrice(b->p) * b->quantity;
          return b->subTotal; // Also return sub-total.
      }
      else
      {
          printf("Error: Invalid item in basket.\n");
          return 0.0;
      }
}

int getItemQuantity(basketItem *b)
{
    // Return quantity of a product bought.
    return b->quantity;
}

void printItem(basketItem *b)
{
     // Assure that b is valid and print a tabular row of product data, quantity and sub-total.
     // Print an error otherwise.
     if(b!=NULL)
     {
                printf("\t| %03d\t %s\t\t %.2f\t  %d\t  %.2f\t\n", getProductCode(b->p), getProductName(b->p), getProductPrice(b->p), b->quantity, b->subTotal);
     }
     else
     {
         printf("Error: Invalid item in basket.\n");
     }
}
