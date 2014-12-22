/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
  
  This file defines the interface the program uses to retrieve product data.
  Uses an array as data store. Should ideally be replace with a hash table or
  database interface.
*/

#ifndef PRODUCT_LIST_H_
#define PRODUCT_LIST_H_

#include <stdlib.h>

#define MAX_LIST_LENGTH 101

// Define ADTs.
typedef struct Product Product;

typedef struct productList productList;

productList * newProductList(void);
// Allows allocating memory to store the products list data store.
// Returns NULL if system is out of memory.

int loadProductList(productList *, char []);
// Loads products in file found in path provided as string.
// Returns 0 on success and -1 in case of failure.

int freeProductList(productList *); 
// Destroy the product list data store.
// Returns 0 on success and -1 in case of failure.

Product * findProductByCode(int, productList *);
// Returns a pointer to a product with product code passed found in data store passed.
// Returns NULL if product was not found.

// Following functions allow reading the attributes of a product.
int getProductCode(Product *);
char * getProductName(Product *);
float getProductPrice(Product *);

#endif
