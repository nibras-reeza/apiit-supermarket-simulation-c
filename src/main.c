#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "queue.h"
#include "productList.h"
#include "basketItem.h"
#include "customer.h"

int qArrive(Queue *, productList *);
int qProcess(Queue *);
int qFront(Queue *);
int qRear(Queue *);
int qLength(Queue *);
int qAll(Queue *);
int qExit(Queue *, productList *);

void wait(void);

int main(int argc, char *argv[])
{
    // Define basic variables.
    int input;
    productList *products;
    Queue *q;
    
    // Allocate memory for pointers.
    products = newProductList();
    q = newQueue();
    
    // Load product-price data store and assert that it succeeded.
    if(loadProductList(products, "priceList.csv")!=0)
    {
                                wait();
                                exit(-1);
    }
    
    queueInit(q); // Initialize queue.

    setAppTitle("SUPER MARKET COUNTER");
    
    showSplash("splash.txt");
    
    getch();
    
    // Loops the menu till user chooses to exit.
    do
    {
        // Declare menu options.
        char mainMenu[][16]={"Arrive", "Process", "Print", "Front", "Rear", "Length", "Exit"};
        
        // Display menu and receive user input.
        input = showMenu("Main Menu", mainMenu, 7);
        
        // Choose a function based on user input.
        switch(input)
        {
                        case 1:
                             qArrive(q, products);
                             break;
                             
                        case 2:
                             qProcess(q);
                             break;
                             
                        case 3:
                             qPrint(q);
                             break;
                             
                        case 4:
                             qFront(q);
                             break;
                                  
                        case 5:
                             qRear(q);
                             break;
                                  
                        case 6:
                             qLength(q);
                             break;
                                  
                        case 7:
                                  qExit(q, products);
                                  break;
                                  
                        default: 
                                 printf("Invalid Menu Option. Try again!");
                                 wait();
                                 continue;
        };    
    }while(1);
    
    return 0;
}

int qArrive(Queue *q, productList *products)
{
    int code, quantity;
    char id[10];
    char input;
    Customer *c = newCustomer();
    Product *p;
    basketItem *item;
    
    printf("\n\tEnter customer id:\n\t");
    scanf("%s", id);   
    customerInit(c, id);
    
    clearScreen();

    do
    {
                    clearScreen();
                    
                    printf("\n\tAdd items to bill of '%s'\n", id);
                    
                    printf("\n\t\tEnter product code: \t(0: quit)\n\t\t");
                    scanf("%d", &code);
                    
                    if(code==0)
                               break;
                    
                    p=findProductByCode(code, products);
                    
                    if(p==NULL)
                    {
                               printf("Error: Cannot add item to basket.");
                               wait();
                               continue;
                    }
                    
                    printf("\n\t\tEnter quantity:\n\t\t");
                    scanf("%d", &quantity);
                    
                    
                    
                    addToBasket(c, newBasketItem(p, quantity));
                    
                    printf("\n\t\t%d of %s were added to the basket.", quantity, getProductName(p));
                    printf("\n\n\t\t[backspace: undo  0: done  1: continue]\n\t\t");
                    input = getch();
                    
                    if(input=='\b')
                    {
                                remFromBasket(c);
                                printf("\n\t\tLast item was removed successfully!");
                                wait();
                                continue;
                    }
                    
                    
                    
    }while(input!='0');
    
    queueInsert(q, c);
}

int qProcess(Queue *q)
{
    Customer *c;
    
    clearScreen();
    c = queueRemove(q);
    printBill(c);
    freeCustomer(c);
    wait();
}

int qPrint(Queue *q)
{
    int i=getQueueLength(q);
    Customer *c;
    
    clearScreen();
    
    do
    { 
        c = queueRemove(q);
        printBill(c);
        wait();
        
        if(c!=NULL)
                   queueInsert(q, c);
        i--;
    }while(i>0);
}

int qFront(Queue *q)
{
    clearScreen();
    printBill(queueFront(q));
    wait();
}

int qRear(Queue *q)
{
    clearScreen();
    printBill(queueRear(q));
    wait();
}

int qLength(Queue *q)
{
    printf("\n\n\tThere are %d customers in the queue.", getQueueLength(q));
    wait();
}

int qExit(Queue *q, productList *products)
{
    int code;
    clearScreen();
    printf("\n\n\n\tThank you for using SUPER MARKET COUNTER!\n");
    printf("\n\tPress any key to exit!");
    
    while(queueIsEmpty(q)==0)
                             freeCustomer(queueRemove(q));
    
    queueFree(q);
    
    code = freeProductList(products);
    if(code==0)
    {
                                    getch();
                                    exit(code);
    }
    else
    {
        printf("Error: Freeing memory failed!");
        wait();
        exit(code);
    }
}

void wait(void)
{
     printf("\n\n\t\t\t[ press any key to continue ]\n");
     getch();
}
