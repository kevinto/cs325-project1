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
int maxSubArray(int *inputArray, int lowIdx, int highIdx, int *currentLowIdx, int *currentHighIdx, int *highestSum);
void maxCrossingSubArray(int *inputArray, int lowIdx, int midIdx, int highIdx, int *crossLow, int *crossHigh, int *crossSum);

// Program entry point
int main()
{
	int i;
	int numberOfElements = 0;
	// char *inputFileName = "MSS_TestProblems.txt";
	char *inputFileName = "MSS_Problems.txt";
	int numberOfLines = numberOfLinesInFile(inputFileName);

	// Run the algorithm for each line in the input file
	for (i = 0; i < numberOfLines; i++)
	{
		numberOfElements = getNumberOfElementsInLine(inputFileName, i);
		int *inputArray = malloc(numberOfElements * sizeof(int));

		// Fill the input array with the numbers from line i in the file
		fillIntArray(inputFileName, i, inputArray, numberOfElements);
		// displayIntArray(inputArray, numberOfElements);
		executeAlgorithm(inputArray, numberOfElements);

		// Cleanup dynamically allocated strings
		free(inputArray);
	}

	// Test code
	// int testArray[4] = { -1, 2, 3, 5 };
	// executeAlgorithm(testArray, 4);
}

void executeAlgorithm(int *inputArray, int numberOfElements)
{
	// Write code here.
	int i;
	int currentInputArrayIdx = 0;
	int lastLow = 0;
	int lastHigh = 0;
	int finalSum = 0;
	maxSubArray(inputArray, 0, numberOfElements - 1, &lastLow, &lastHigh, &finalSum);
	// printf("lastLow: %d\n", lastLow);
	// printf("lastHigh: %d\n", lastHigh);
	// printf("finalSum: %d\n", finalSum);

	// Output results to console for testing
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
	// int resultArray[3]; // This is a sample array
	// resultArray[0] = 1;
	// resultArray[1] = 2;
	// resultArray[2] = 3;
	outputResultToFile(resultArray, numberOfResultElements, inputArray, numberOfElements);

	// This code is just to debug. Remove if ready
	// displayIntArray(resultArray, numberOfResultElements);
	// printf("\n");

	free(resultArray);
}

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

		int leftLow = 0;
		int leftHigh = 0;
		int leftSum = 0;
		maxSubArray(inputArray, lowIdx, midIdx, &leftLow, &leftHigh, &leftSum);
		// printf("leftLow: %d\n", leftLow);
		// printf("leftHigh: %d\n", leftHigh);
		// printf("leftSum: %d\n", leftSum);

		int rightLow = 0;
		int rightHigh = 0;
		int rightSum = 0;
		maxSubArray(inputArray, midIdx + 1, highIdx, &rightLow, &rightHigh, &rightSum);
		// printf("rightLow: %d\n", rightLow);
		// printf("rightHigh: %d\n", rightHigh);
		// printf("rightSum: %d\n", rightSum);

		int crossLow = 0;
		int crossHigh = 0;
		int crossSum = 0;
		maxCrossingSubArray(inputArray, lowIdx, midIdx, highIdx, &crossLow, &crossHigh, &crossSum);
		// printf("crossLow: %d\n", crossLow);
		// printf("crossHigh: %d\n", crossHigh);
		// printf("crossSum: %d\n", crossSum);

		if ((leftSum >= rightSum) && (leftSum >= crossSum))
		{
			*currentLowIdx = leftLow;
			*currentHighIdx = leftHigh;
			*highestSum = leftSum;
		}
		else if ((rightSum >= leftSum) && (rightSum >= crossSum))
		{
			*currentLowIdx = rightLow;
			*currentHighIdx = rightHigh;
			*highestSum = rightSum;
		}
		else
		{
			*currentLowIdx = crossLow;
			*currentHighIdx = crossHigh;
			*highestSum = crossSum;
		}
	}
}

void maxCrossingSubArray(int *inputArray, int lowIdx, int midIdx, int highIdx, int *crossLow, int *crossHigh, int *crossSum)
{
	int i;
	int leftSum = 0;
	int maxLeftIdx = 0;

	int rightSum = 0;
	int maxRightIdx = 0;

	int currentSum = 0;

	for (i = midIdx; i >= 0; i--)
	{
		currentSum += inputArray[i];
		if (currentSum > leftSum)
		{
			leftSum = currentSum;
			// maxLeftIdx = i;
			*crossLow = i;
		}
	}

	currentSum = 0;
	for (i = midIdx + 1; i <= highIdx; i++)
	{
		currentSum += inputArray[i];
		if (currentSum > rightSum)
		{
			rightSum = currentSum;
			// maxRightIdx = i;
			*crossHigh = i;
		}
	}

	*crossSum = leftSum + rightSum;
	// printf("maxLeftIdx: %d\n", maxLeftIdx);
	// printf("maxRightIdx: %d\n", maxRightIdx);
	// printf("leftSum + rightSum: %d\n", leftSum + rightSum);
}
