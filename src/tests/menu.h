#ifndef MENU_H_
#define MENU_H_

#define SCREEN_WIDTH 80

char * showMenu(char[], char [][16], int);
int showSplash(char []);

int setAppTitle(char []);

void clearScreen(void);

static void printAppHeader(void);
static int printMenuHeader(char []);
static void printChar(char, int);
static void printCenter(char [], int);

#endif
