/*
  Author: Nibras Ahamed Reeza (CB004641)
  Last Modified: 06/09/2012
  EMail: nibras.reeza@gmail.com
  
  This file is part of the assignment for Algorithms and Data Structures in C.
*/

#ifndef MENU_H_
#define MENU_H_

#define SCREEN_WIDTH 80

int showMenu(char[], char [][16], int);
// Displays menu options passed in a 2D array and prompts user to choose an options.
// Returns number corresponding to picked option.
// Returns -1 for errors.

int showSplash(char []);
// Displays file found in path passed as string as a splash screen.
// Returns 0 on success and -1 in case of failure.

int setAppTitle(char []);
// Modifies the app title displayed when clearScreen is invoked.
// Returns 0 on success and -1 in case of failure.

void clearScreen(void);
// Clears screen and displays a title bar.

#endif
