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

// Concrete definition of a product/type of item that maybe purchased.
struct Product
{
       int code;
       char name[16];
       float price;
};

// Concrete definition of structure storing products.
// Acts as a data store.
struct productList
{
       Product *list[MAX_LIST_LENGTH];
};

// Other programs using product list may not manually add products.
// They can only load a product list front file and access product
// data on a read only basis.

static Product * newProduct(int, char [], float);
// Create a new product variable with given charecteristics. 

static int freeProduct(Product *);
// Destroy a product.

static int addToProductList(productList *, Product *);
// Add pointer to a product to the data store.


productList * newProductList(void)
{
            // Use malloc to dynamically allocate memory.
            productList *pL = malloc(sizeof(productList));
            
            // Ensure malloc succeeded and return pointer to newly allocated memory block.
            // Print an error and return NULL otherwise.
            if(pL==NULL)
            {
                       printf("Error: System out of memory.");
                       return NULL;
            }
            
            return pL;
}

int loadProductList(productList *pL, char path[])
{
    // Open file at string path.
    FILE *file = fopen(path, "r");
    
    // Temporary variables.
    int code;
    char name[16];
    float price;
    
    // Return error and print error if file couldn't be opened.
    if(file==NULL)
    {
                  printf("Error: Price list can not be loaded.");
                  return -1;
    }
    
    // Read data from file line-by-line until end is released.
    while(fscanf(file, "%d %s %f", &code, name, &price)!=EOF)
    {
                       // Create a new product using data read from file.
                       Product *p = newProduct(code, name, price);
                       
                       // Add pointer to newly created product to product list.
                       addToProductList(pL, p);
                       
                       // Move to next line.
                       fgetc(file);
    }
    
    // File isn't required anymore. Close it.
    fclose(file);
    
    return 0;
}

int freeProductList(productList *pL)
{
    int i;
    
    // Remove each product from product list till all items are removed.
    for(i=1; i<MAX_LIST_LENGTH; i++)
             freeProduct(findProductByCode(1, pL));  
    
    // Free memory used for product list.
    free(pL);
    
    return 0; // Report success.
}

Product * findProductByCode(int code, productList *pL)
{
        // Searches for given product code in the product list and returns
        // pointer for relavant product. Uses identity function.
        if(code<MAX_LIST_LENGTH)
                              return pL->list[code];
        else
            return NULL; // Return NULL if product code is invalid.
}

int getProductCode(Product *p)
{
    // Ensure pointer passed is valid, otherwise, report an error.
    if(p==NULL)
    {
               printf("Error: Invalid product");
               return -1;
    }

    return p->code;   
}

char * getProductName(Product *p)
{
     // Ensure pointer passed is valid, otherwise, report an error.
     if(p==NULL)
     {
                printf("Error: Invalid product");
                return NULL;
     }
     
     return p->name;
}

float getProductPrice(Product *p)
{
      // Ensure pointer passed is valid, otherwise, report an error.
      if(p==NULL)
      {
                 printf("Error: Invalid product");
                 return -1.0;
      }
      return p->price;
}

static Product * newProduct(int code, char name[], float price)
{
        // Use malloc to dynamically allocate memory.
        Product *p = malloc(sizeof(Product));
        
        // Ensure malloc succeeded and return pointer to newly allocated memory block.
        // Print an error and return NULL otherwise.
        if(p==NULL)
        {
                   printf("Error: System out of memory.");
                   return NULL;
        }
        
        // Store attributes of product in allocated variable.
        p->code =  code;
        strcpy(p->name, name);
        p->price = price;
        
        return p; // Return pointer to new variable.
}

static int freeProduct(Product *p)
{
    // Free memory used by variable.
    free(p);
    return 0; // Report success.
}


static int addToProductList(productList *pL, Product *p)
{
    // Add pointer to new product to product table based on identity hash.
    pL->list[p->code] = p;
    return 0; // Report success.
}
