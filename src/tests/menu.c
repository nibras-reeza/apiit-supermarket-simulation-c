#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

static char appName[SCREEN_WIDTH - 2] = "TEST MESSAGE. REPLACE TEXT";

char * showMenu(char title[], char items[][16], int total)
{
    int i;
    char *input = malloc(sizeof(char)*16);
    clearScreen();
    printMenuHeader(title);
    
    for(i=0; i<total; i++)
             printf("\t%d) %s\n", i+1, items[i]);
             
    printf("\n\n");
    
    printf("Please pick a menu option:\t");
    scanf("%s", input);
    
    return input;
}

int showSplash(char path[])
{
    FILE *file = fopen(path, "r");
    char letter;
    
    clearScreen();
    
    while ((letter = fgetc(file)) != EOF)
    if(letter!='\n')
        printf("%c", letter);
    fclose(file);

}

int setAppTitle(char title[])
{
    strcpy(appName, title);
} 

void clearScreen(void)
{
     system("cls"); // Windows only. Replace with system("clear"); for Unix.
     printAppHeader();
}

static void printAppHeader(void)
{
     printChar('*', SCREEN_WIDTH);
     
     printf("*");
     printChar(' ', SCREEN_WIDTH-2);
     printf("*");
     
     printf("*");
     printCenter(appName, 2);
     printf("*");
     
     printf("*");
     printChar(' ', SCREEN_WIDTH-2);
     printf("*");
     
     printChar('*', SCREEN_WIDTH);
     
}

static int printMenuHeader(char title[])
{
    int l = strlen(title);
    
    printf("\n");
    printCenter(title, 0);
    
    printChar(' ', (SCREEN_WIDTH-l)/2);
    printChar('-', l);
    printf("\n");
}

static void printChar(char c, int i)
{
     while(i>0)
     {
                printf("%c",c);
                i--;
     }
}

static void printCenter(char text[], int margin)
{
     int length, spaceTotal, spaceBefore, spaceAfter;
     
     length = strlen(text);
     //for(length=0; text[length]!='\0'; length++);
     
     spaceTotal = SCREEN_WIDTH - (length+margin);
     
     if(spaceTotal%2==0)
                        spaceBefore = spaceAfter = spaceTotal/2;
     else
     {
         spaceBefore = spaceTotal / 2;
         spaceAfter = (spaceTotal / 2)+1;
     }
     
     printChar(' ', spaceBefore);
     printf("%s", text);
     printChar(' ', spaceAfter);
}
