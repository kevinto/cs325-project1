/**************************************************************
 * *  Filename: divideandconquer.c
 * *  Coded by: Kevin To
 * *  Purpose - To run the divide and conquer algorithm for the 
 * *			max subarray problem.
 * *
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "filefunctions.h"

void executeAlgorithm(int *inputArray, int numberOfElements);
int maxSubArray(int *inputArray, int lowIdx, int highIdx, int *currentLowIdx, int *currentHighIdx, int *highestSum);
void maxCrossingSubArray(int *inputArray, int lowIdx, int midIdx, int highIdx, int *crossLow, int *crossHigh, int *crossSum);

// Program entry point
int main()
{
	int i;
	int numberOfElements = 0;
	char *inputFileName = "MSS_Problems.txt";
	// char *inputFileName = "MSS_TestProblems.txt";
	int numberOfLines = numberOfLinesInFile(inputFileName);

	// Run the algorithm for each line in the input file
	for (i = 0; i < numberOfLines; i++)
	{
		// Find number of elements in parsed line.
		numberOfElements = getNumberOfElementsInLine(inputFileName, i);

		// Create a dynamic array based on the number of elements
		int *inputArray = malloc(numberOfElements * sizeof(int));

		// Fill the input array with the numbers from line i in the file
		fillIntArray(inputFileName, i, inputArray, numberOfElements);

		// Run the algorithm
		executeAlgorithm(inputArray, numberOfElements);

		// Cleanup dynamically allocated strings
		free(inputArray);
	}
}

/**************************************************************
 * * Entry:
 * *  inputArray - The input array to run the algo on.
 * *  numberOfElements - The number of elements in the array
 * *
 * * Exit:
 * *  n/a
 * *
 * * Purpose:
 * *  Executes the divide and conquer algorithm and puts the results
 * *  to the MSS_Results.txt file
 * *
 * ***************************************************************/
void executeAlgorithm(int *inputArray, int numberOfElements)
{
	int i;
	int currentInputArrayIdx = 0;
	int lastLow = 0;
	int lastHigh = 0;
	int finalSum = 0;

	// Run the divide and conquer algo
	maxSubArray(inputArray, 0, numberOfElements - 1, &lastLow, &lastHigh, &finalSum);

	// Check if the number of result elements is within the bounds 
	int numberOfResultElements = lastHigh - lastLow + 1;
	if (numberOfResultElements <= 0)
	{
		printf("Error: invalid amount of result elements\n");
		return;
	}

	// Generate the results array
	int *resultArray = malloc(numberOfResultElements * sizeof(int));
	for (i = 0; i < numberOfResultElements; i++)
	{
		currentInputArrayIdx = lastLow + i;
		if ((currentInputArrayIdx >= numberOfElements) || (currentInputArrayIdx < 0))
		{
			printf("Error: Out of bounds of the input array\n");
		}

		resultArray[i] = inputArray[lastLow + i];
	}

	// Output the result to results file
	outputResultToFile(resultArray, numberOfResultElements, inputArray, numberOfElements);

	// For debugging purposes only
	// displayIntArray(resultArray, numberOfResultElements);
	// printf("\n");

	free(resultArray);
}

/**************************************************************
 * * Entry:
 * *  inputArray - The input array to run the algo on.
 * *  lowIdx - The lower index to start dividing from.
 * *  highIdx - The higher index to end dividing from.
 * *  currentLowIdx - Keeps track of the low index of the max subarray 
 * *  currentHighIdx - Keeps track of the high index of the max subarray 
 * *  highestSum - Keeps track of the highest sum found so far
 * *
 * * Exit:
 * *  n/a
 * *
 * * Purpose:
 * *  Finds the max sub array.
 * *
 * ***************************************************************/
int maxSubArray(int *inputArray, int lowIdx, int highIdx, int *currentLowIdx, int *currentHighIdx, int *highestSum)
{
	if (lowIdx == highIdx)
	{
		// Return if there is only one element
		*currentLowIdx = lowIdx;
		*currentHighIdx = highIdx;
		*highestSum = inputArray[highIdx];
	}
	else
	{
		int midIdx = (lowIdx + highIdx) / 2;

		// Find the max subarray of the left side of the current array
		int leftLow = 0;
		int leftHigh = 0;
		int leftSum = 0;
		maxSubArray(inputArray, lowIdx, midIdx, &leftLow, &leftHigh, &leftSum);

		// Find the max subarray of the right side of the current array
		int rightLow = 0;
		int rightHigh = 0;
		int rightSum = 0;
		maxSubArray(inputArray, midIdx + 1, highIdx, &rightLow, &rightHigh, &rightSum);

		// Find the max subarray that crosses the boundary between the left and right sections of the array
		int crossLow = 0;
		int crossHigh = 0;
		int crossSum = 0;
		maxCrossingSubArray(inputArray, lowIdx, midIdx, highIdx, &crossLow, &crossHigh, &crossSum);

		if ((leftSum >= rightSum) && (leftSum >= crossSum))
		{
			// The left side has the greatest sum
			*currentLowIdx = leftLow;
			*currentHighIdx = leftHigh;
			*highestSum = leftSum;
		}
		else if ((rightSum >= leftSum) && (rightSum >= crossSum))
		{
			// The right side has the greatest sum
			*currentLowIdx = rightLow;
			*currentHighIdx = rightHigh;
			*highestSum = rightSum;
		}
		else
		{
			// The greatest sum is a suffix of the left and
			// a prefix of the right
			*currentLowIdx = crossLow;
			*currentHighIdx = crossHigh;
			*highestSum = crossSum;
		}
	}
}

/**************************************************************
 * * Entry:
 * *  inputArray - The input array to run the algo on.
 * *  lowIdx - The lower index to start calculating the sum from
 * *  midIdx - The mid index to start calculating the sum to and from.
 * *  highIdx - The higher index to end the sum calculation at.
 * *  crossLow - Keeps track of the low index of the max subarray 
 * *  crossHigh - Keeps track of the high index of the max subarray 
 * *  crossSum - The max sub array summation found
 * *
 * * Exit:
 * *  n/a
 * *
 * * Purpose:
 * *  Finds the max sub array that contains a suffix of the left
 * *  and a prefix of the right.
 * *
 * ***************************************************************/
void maxCrossingSubArray(int *inputArray, int lowIdx, int midIdx, int highIdx, int *crossLow, int *crossHigh, int *crossSum)
{
	int i;
	int leftSum = INT_MIN;
	int rightSum = INT_MIN;

	int currentSum = 0;

	// Find the max subarray of the mid to the end of the left side. 
	for (i = midIdx; i >= 0; i--)
	{
		currentSum += inputArray[i];
		if (currentSum > leftSum)
		{
			leftSum = currentSum;
			*crossLow = i;
		}
	}

	// Find the max subarray of the mid to the end of the right side. 
	currentSum = 0;
	for (i = (midIdx + 1); i <= highIdx; i++)
	{
		currentSum += inputArray[i];
		if (currentSum > rightSum)
		{
			rightSum = currentSum;
			*crossHigh = i;
		}
	}

	// Return the max sum found
	*crossSum = leftSum + rightSum;
}
