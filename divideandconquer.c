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
	int i;
	int numberOfElements = 0;
	char *inputFileName = "MSS_Problems.txt";
	int numberOfLines = numberOfLinesInFile(inputFileName);

	// TODO: Get number of elements per line

	for (i = 0; i < numberOfLines; i++)
	{
		numberOfElements = getNumberOfElementsInLine(inputFileName, i);
		int *inputArray = malloc(numberOfElements * sizeof(int));

		// Fill the input array with the numbers from line i in the file
		// fillIntArray(inputFileName, i, inputArray, numberOfElements);

		// Cleanup dynamically allocated strings
		free(inputArray);
		// printf("\n");
	}

	// FillIntArray(inputFileName, inputArray, numberOfLines);

}

void executeAlgorithm()
{

}
