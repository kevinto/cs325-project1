#ifndef _FILEFUNCTIONS_H_
#define _FILEFUNCTIONS_H_

#include <stdio.h>

// Constants
#define MAX_INT_ELEMENTS 50 

void displayFile();
int numberOfLinesInFile(char *fileName);
void initializeIntArray(int **intArray, int numberOfRows, int numberofColumns);
void displayIntArray(int **intArray, int numberOfRows, int numberofColumns);
void FillIntArray(char *inputFileName, int **inputArray, int numberOfRows);

#endif