/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#include "productList.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

static Product * newProduct(int, char [], float);
static int freeProduct(Product *);

static int addToProductList(productList *, Product *);

productList * newProductList(void)
{
            productList *pL = malloc(sizeof(productList));
            
            if(pL==NULL)
            {
                       printf("Error: System out of memory.");
                       return NULL;
            }
            
            return pL;
}

int loadProductList(productList *pL, char path[])
{
    FILE *file = fopen(path, "r");
    
    int code;
    char name[16];
    float price;
    
    if(file==NULL)
    {
                  printf("Error: Price list can not be loaded.");
                  return -1;
    }
    
    while(fscanf(file, "%d %s %f", &code, name, &price)!=EOF)
    {
                       Product *p = newProduct(code, name, price);
                       addToProductList(pL, p);
                       fgetc(file);
    }
    
    fclose(file);
    
    return 0;
}

int freeProductList(productList *pL)
{
    int i;
    
    for(i=1; i<MAX_LIST_LENGTH; i++)
             freeProduct(findProductByCode(1, pL));  
    free(pL);
    
    return 0;
}

Product * findProductByCode(int code, productList *pL)
{
        if(code<MAX_LIST_LENGTH)
                              return pL->list[code];
        else
            return NULL;
}

int getProductCode(Product *p)
{
    if(p==NULL)
    {
               printf("Error: Invalid product");
               return -1;
    }
    
    return p->code;   
}

char * getProductName(Product *p)
{
     if(p==NULL)
     {
                printf("Error: Invalid product");
                return NULL;
     }
     
     return p->name;
}

float getProductPrice(Product *p)
{
      if(p==NULL)
      {
                 printf("Error: Invalid product");
                 return -1.0;
      }
      return p->price;
}

static Product * newProduct(int code, char name[], float price)
{
        Product *p = malloc(sizeof(Product));
        
        if(p==NULL)
        {
                   printf("Error: System out of memory.");
                   return NULL;
        }
        
        p->code =  code;
        strcpy(p->name, name);
        p->price = price;
        
        return p;
}

static int freeProduct(Product *p)
{
    free(p);
    return 0;
}


static int addToProductList(productList *pL, Product *p)
{
    pL->list[p->code] = p;
    return 0;
}
