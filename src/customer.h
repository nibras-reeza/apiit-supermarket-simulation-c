/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "stack.h"

typedef struct Customer Customer;

struct Customer
{
       char id[10];
       Stack *basket;
       int quantity;
       float total;
};


Customer * newCustomer(void);
int customerInit(Customer *, char []);
int addToBasket(Customer *, basketItem *i);
int remFromBasket(Customer *);
int calcTotal(Customer *);
int printBill(Customer *);
int freeCustomer(Customer *);
 
#endif
