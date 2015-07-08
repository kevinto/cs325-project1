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

void executeAlgorithm(int *inputArray, int numberOfElements);

// Program entry point
int main()
{
	int i;
	int numberOfElements = 0;
	char *inputFileName = "MSS_Problems.txt";
	int numberOfLines = numberOfLinesInFile(inputFileName);

	// Run the algorithm for each line in the input file
	for (i = 0; i < numberOfLines; i++)
	{
		numberOfElements = getNumberOfElementsInLine(inputFileName, i);
		int *inputArray = malloc(numberOfElements * sizeof(int));

		// Fill the input array with the numbers from line i in the file
		fillIntArray(inputFileName, i, inputArray, numberOfElements);
		executeAlgorithm(inputArray, numberOfElements);

		// Cleanup dynamically allocated strings
		free(inputArray);
	}

	// FillIntArray(inputFileName, inputArray, numberOfLines);

}

void executeAlgorithm(int *inputArray, int numberOfElements)
{
	// Write code here.

	// This code is just to debug. Remove if ready
	displayIntArray(inputArray, numberOfElements);
	printf("\n");
}
