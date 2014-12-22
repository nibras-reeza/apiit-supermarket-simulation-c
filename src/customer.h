/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "stack.h"

typedef struct Customer Customer; // Abstract definition of Customer structure.

Customer * newCustomer(void);
// Allocates memory dynamically and returns a pointer.
// Returns NULL if allocation fails.

int customerInit(Customer *, char []);
// Initializes customer variable with given id string.
// Returns 0 on success and -1 in case of failure.

int addToBasket(Customer *, basketItem *i);
// Adds given item to customer's basket.
// Returns 0 on success and -1 in case of failure.

int remFromBasket(Customer *);
// Remove last added item from customer's basket.
// Returns 0 on success and -1 in case of failure.

int printBill(Customer *);
// Prints bill for a customer.
// Returns 0 on success and -1 in case of failure.

int freeCustomer(Customer *);
// Destroys a customer variable.
// Returns 0 on success and -1 in case of failure.
 
#endif
