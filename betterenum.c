/**************************************************************
 * *  Filename: betterenum.c
* *  Coded by: Matt Walz
 * *  Purpose - This code will read a file line by line (where each
 * *      line contains an array in the form "[1, 2, 19, -6, ... , 3]")
 * *      and calculate the maximum sub-array sum of each array in the
 * *      input file using a modified enumeration method which loops
 * *      through all possible starting and ending indices, i and j.
 * *      Then, rather than calculating the summation of every possible
 * *      starting and end point combination and duplicating calculations
 * *      we use the fact that the summation from i to j+1 is equal to
 * *      summation from i to j plus the element at location j to minimize
 * *      the amount of calculations required by the algorithm. As we
 * *      iterate through j, we are calculating the summation from i to j
 * *      by adding element j to the existing sum. Then, once we have 
 * *      iterated through the whole range of j and increment i, we set
 * *      the summation to zero and begin again with the same pattern.
 * *      Then, the formatted results are output to another file. This
 * *      is Algorithm 2 of Project 1 for CS 325 Summer 2015.
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "filefunctions.h"

void executeAlgorithm(int *inputArray, int numberOfElements);

// Program entry point
int main()
{
	int i;
	int numberOfElements = 0;
	char *inputFileName = "MSS_TestProblems.txt";
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
	int i, j, sum; //initialize index integers and sum integer for for loops
	int max = INT_MIN; //smallest possible int value
	int max_i = -1; //initialize i index for max sum sub-array
	int max_j = -1; //initialize j index for max sum sub-array
	for (i = 0; i < numberOfElements; i++) {
		sum = 0; //reset sum to zero when we iterate to the next starting point (i index)
		for (j = i; j < numberOfElements; j++) {
			sum = sum + inputArray[j];
			if (sum > max) { //current summation is greater than previous max
				max = sum;
				max_i = i;
				max_j = j;
			}
		}
	}
	
	// This code is just to debug. Remove if ready
	displayIntArray(inputArray, numberOfElements);
	printf("\ni = %d; j = %d; Sum = %d \n\n", max_i, max_j, max);
}