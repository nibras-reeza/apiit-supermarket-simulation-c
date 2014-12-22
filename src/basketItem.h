/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
  
  Quantity or rather number of items purchased is not a characteristic of products.
  Therefore, an intermediate structure consisting of a product, quantity and sub-total
  called basketItem is introduced.
*/

#ifndef BASKET_ITEM_H_
#define BASKET_ITEM_H_

#include "productList.h"

typedef struct basketItem basketItem; // Abstract definition of basket item.

basketItem *newBasketItem(Product *, int);
// Creates a dynamic variable for basketItem and returns a pointer to it.
// Returns NULL if system is out of memory.

int *delBasketItem(basketItem *);
// Frees memory held by a basketItem.
// Returns 0 on success and -1 in case failure.

float subTotal(basketItem *);
// Caculates subtotal for basketItem.

int getItemQuantity(basketItem *);
// Returns the quantity of products in a basketItem.

void printItem(basketItem *);
// Prints a basketItem.

#endif
