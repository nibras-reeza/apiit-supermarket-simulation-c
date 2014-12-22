#include "testMenu.h"

int testMenuOps(void)
{
    
  
    setAppTitle("SUPER MARKET COUNTER");
    
    showSplash("splash.txt");
    
    getch();
    
    char mainMenu[][16]={"arrive", "process", "front", "rear", "length", "exit"};
    
    showMenu("test menu", mainMenu, 3);
    
    getch();
}
