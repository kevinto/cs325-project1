/**************************************************************
 * *  Filename: enumeration.c
 * *  Coded by: Matt Walz
 * *  Purpose - This code will read a file line by line (where each
 * *      line contains an array in the form "[1, 2, 19, -6, ... , 3]")
 * *      and calculate the maximum sub-array sum of each array in the
 * *      input file using a brute force enumeration method which loops
 * *      through all possible starting and ending indices, i and j,
 * *      and calculates the summation of all elements between i and j.
 * *      It then outputs the formatted results to another file. This
 * *      is Algorithm 1 of Project 1 for CS 325 Summer 2015.
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
}

void executeAlgorithm(int *inputArray, int numberOfElements)
{
	//Calculate the maximum sum sub-array and keep track of the indices between which that sub-array is contained
	int i, j, k, sum; //initialize index integers and sum integer for for loops
	int max = INT_MIN; //smallest possible int value
	int max_i = -1; //initialize i index for max sum sub-array
	int max_j = -1; //initialize j index for max sum sub-array
	for (i = 0; i < numberOfElements; i++) {
		for (j = i; j < numberOfElements; j++) {
			sum = 0; //reset sum to 0 before calculating next summation between new i and j values
			for (k = i; k <= j; k++) { //Calculate the summation of all elements in array between i and j
				sum = sum + inputArray[k];
			}
			if (sum > max) { //current summation is greater than previous max
				max = sum;
				max_i = i;
				max_j = j;
			}
		}
	}	

	// Output the results to file
	int *results = &inputArray[max_i];
	int resultsLength = (max_j - max_i) + 1;
	outputResultToFile(results, resultsLength, inputArray, numberOfElements);
}