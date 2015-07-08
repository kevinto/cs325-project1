#ifndef _FILEFUNCTIONS_H_
#define _FILEFUNCTIONS_H_

#include <stdio.h>

// Constants
#define MAX_INT_ELEMENTS 50 
#define MAX_INPUT_LINE_SIZE 1000

void displayFile();
int numberOfLinesInFile(char *fileName);
void initializeIntArray(int *intArray, int numberofElements);
void displayIntArray(int *intArray, int numberOfElements);
void fillIntArray(char *inputFileName, int inputLineNumber, int *inputArray, int numberOfElements);
int getNumberOfElementsInLine(char *inputFileName, int inputLineNumber);

#endif