/**************************************************************
 * *  Filename: divideandconquer.c
 * *  Coded by: Kevin To
 * *  Purpose -
 * *
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filefunctions.h"

// Program entry point
int main()
{
	// Get number of arrays to parse
	char *inputFileName = "MSS_Problems.txt";
	int numberOfLines = numberOfLinesInFile(inputFileName);
	// TODO: Get number of elements

	// Allocate space for the array of inputs
	int **inputArray = (int **)malloc(numberOfLines * sizeof(int *));
	int i;
	for (i = 0; i < numberOfLines; i++)
	{
		inputArray[i] = (int *)malloc(MAX_INT_ELEMENTS * sizeof(int *));
	}

	FillIntArray(inputFileName, inputArray, numberOfLines);

	// Cleanup dynamically allocated strings
	for (i = 0; i < numberOfLines; i++)
	{
		free(inputArray[i]);
	}
	free(inputArray);
}

void executeAlgorithm()
{

}
