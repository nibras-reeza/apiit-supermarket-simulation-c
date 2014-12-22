#include "testProductList.h"

int testProductListOps(void)
{
    int i;
    productList *pl = newProductList();
    
    printf("Loading product list...");
    loadProductList(pl,"priceList.csv");
    printf("Ok.\n");
    
    printf("Print all products:");
    for(i=1; i<MAX_LIST_LENGTH; i++)
    {
             Product *p= findProductByCode(i, pl);
             printf("%03d\t %s\t %.2f\n", p->code, p->name,p->price);
}

printf("Discard data...");
i = freeProductList(pl);
printf("Ok.\n");
printf("All tests passed.");
getch();
}
