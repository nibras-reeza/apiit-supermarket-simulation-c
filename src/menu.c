/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
  
  Provides the print/output functions for the applications. Non of the functions
  except showMenu are elaborated since these are simple printf statements without
  complex logic.
*/

#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Static functions used only within this module/file.
// All are print functions. 
static void printAppHeader(void);
static int printMenuHeader(char []);
static void printChar(char, int);
static void printCenter(char [], int);

static char appName[SCREEN_WIDTH - 2] = "TEST MESSAGE. REPLACE TEXT";

int showMenu(char title[], char items[][16], int total)
{
    int i, j, option = -1;
    char input[16];
    
    // Function works with only up to 9 options.
    // If user enters number, we can process only first digit.
    // Processing two digit number from a string is complicated.
    
    if(total>9)
    {
                 printf("Error: Too many menu options.");
                 return -1;
    }
    
    clearScreen();
    
    printMenuHeader(title);
    
    for(i=0; i<total; i++)
             printf("\t%d) %s\n", i+1, items[i]);
             
    printf("\n\n");
    
    printf("Please pick a menu option:\t");
    scanf("%s", input);
    
    // See if user has entered a number
    for(i=0; i<total; i++)
             if(input[0]-'0'==(i+1))
             {
                                    // If number entered mataches a menu option,
                                    // return the option number.
                                    option  = i+1;
                                    return option;
             }
             
    // If no valid menu numbers were matched, perform string comparisions.
    for(i=0; i<total; i++) // Pick a menu option's string.
    {
             // Check length first. If menu option string's length does not match
             // length of string user entered, no need to compare further.
             int l = strlen(items[i]);
             if(l!=strlen(input))
                                 continue; 
             
             // If lengths match, compare corresponding letter/charecters.                    
             for(j=0; j<l; j++)
             {
                      if(tolower(input[j])!=tolower(items[i][j])) // Convert letters to lowercase and compare. Ensures commands are case insensitive.
                                               break;
             }
             
             // If all charecters in input and items[i] match, return menu number for items[i].
             if(j==l)
             {
                     option = i+1;
                     return option;
             }
    }
    
    return option; // Return -1 because the input didn't match any expected inputs.
    /*switch(input[0])
        {
                        case '1':case'A':case'a':
                             option =1;
                             break;
                             
                        case '2':
                             option = 2;
                             break;
                             
                        case '3':
                             option = 3;
                             break;
                             
                        case 'p': case 'P':
                             if(input[2]=='o'||input[2]=='O') 
                             option =2;
                             else
                                 option =3;
                             break;
                             
                        case '4': case 'F': case 'f':
                                  option =4;
                                  break;
                                  
                        case '5': case 'R': case 'r':
                                 option = 5;
                                  break;
                                  
                        case '6': case 'L': case 'l':
                                  option =6;
                                  break;
                                  
                        case '7': case 'E': case 'e':
                                  option =7;
                                  break;
                                  
                        default: 
                                 option = -1;
        };*/
}

int showSplash(char path[])
{
    FILE *file = fopen(path, "r");
    char letter;
    
    if(file==NULL)
    {
                  printf("Error: Splash missing.");
                  return -1;
    }
    
    clearScreen();
    
    while ((letter = fgetc(file)) != EOF)
        if(letter!='\n')
            printf("%c", letter);
        
    fclose(file);
    
    return 0;
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
    
    return 0;
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
