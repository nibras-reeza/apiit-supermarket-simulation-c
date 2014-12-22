/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#ifndef PRODUCT_LIST_H_
#define PRODUCT_LIST_H_

#include <stdlib.h>

#define MAX_LIST_LENGTH 101

typedef struct Product Product;

typedef struct productList productList;

struct Product
{
       int code;
       char name[16];
       float price;
};

struct productList
{
       Product *list[MAX_LIST_LENGTH];
};


productList * newProductList(void);
int loadProductList(productList *, char []);
int freeProductList(productList *); 

Product * findProductByCode(int, productList *);

int getProductCode(Product *);
char * getProductName(Product *);
float getProductPrice(Product *);

#endif
