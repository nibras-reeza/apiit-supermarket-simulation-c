#include <stdio.h>
#include <stdlib.h>
#include "testStack.h"
#include "testQueue.h"
#include "testMenu.h"
#include "testProductList.h"

int main(int argc, char *argv[])
{
        testMenuOps();
    
    getch();
    
    testStackOps();
    
    getch();
    
    testQueueOps();
    
    getch();
    
    testProductListOps();
    
    getch();
    

  
  system("PAUSE");	
  return 0;
}
