/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#ifndef BASKET_ITEM_H_
#define BASKET_ITEM_H_

#include "productList.h"

typedef struct basketItem basketItem;

struct basketItem
{
       Product *p;
       int quantity;
       float subTotal;
};


basketItem *newBasketItem(Product *, int);
basketItem *delBasketItem(basketItem *);
float subTotal(basketItem *);

void printItem(basketItem *);

#endif
