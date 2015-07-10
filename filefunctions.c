
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "filefunctions.h"

/**************************************************************
 * * Entry:
 * *  resultArray - the int array of the algorithm result
 * *  resultArraySize - the result array size
 * *  originalArray - the original int array containing all the values
 * *  originalArraySize - the original array size
 * *
 * * Exit:
 * *  n/a
 * *
 * * Purpose:
 * *  Outputs the original array, the result array, and the sum of
 * *  result array into MSS_Results.txt
 * *
 * ***************************************************************/
void outputResultToFile(int *resultArray, int resultArraySize, int *originalArray, int originalArraySize)
{
	FILE *outputFile = fopen("MSS_Results.txt", "a");

	// Output the original input array
	fprintf(outputFile, "%c", '[');
	int i;
	for (i = 0; i < originalArraySize; ++i)
	{
		// Do not write comma if first element
		if (i != 0)
		{
			fprintf(outputFile, "%s", ", ");
		}
		fprintf(outputFile, "%d", originalArray[i]);
	}

	fprintf(outputFile, "%c", ']');
	fprintf(outputFile, "%c", '\n');

	// Output the max sequence
	fprintf(outputFile, "%c", '[');
	int resultArraySum = 0;
	for (i = 0; i < resultArraySize; ++i)
	{
		// Do not write comma if first element
		if (i != 0)
		{
			fprintf(outputFile, "%s", ", ");
		}
		fprintf(outputFile, "%d", resultArray[i]);
		resultArraySum += resultArray[i];
	}

	fprintf(outputFile, "%c", ']');
	fprintf(outputFile, "%c", '\n');

	// Output the sum of the result array
	fprintf(outputFile, "%d", resultArraySum);
	fprintf(outputFile, "%s", "\n\n");

	fclose(outputFile);
}

void fillIntArray(char *inputFileName, int inputLineNumber, int *inputArray, int numberOfElements)
{
	// printf("you are on line: %d\n", inputLineNumber);
	initializeIntArray(inputArray, numberOfElements);

	char stringValue[MAX_INPUT_LINE_SIZE];
	getLineFromFile(inputFileName, inputLineNumber, stringValue);

	// Establish string and get the first token 
	int currentNumber;
	int currentInputArrayIdx = 0;
	char *token = strtok(stringValue, ",[]");
	while ( token != 0 )
	{
		sscanf(token, "%d", &currentNumber);

		if (currentInputArrayIdx >= numberOfElements)
		{
			// printf("inputLineNumber: %d\n", inputLineNumber);
			// printf("Error (fillIntArray): Accessing out of bounds index in array\n");
			break;
		}

		inputArray[currentInputArrayIdx++] = currentNumber;

		/* Get next token: */
		token = strtok(0, ",[]");
	}
}

int getNumberOfElementsInLine(char *inputFileName, int inputLineNumber)
{
	int numberOfElements = 0;
	FILE *fp;
	fp = fopen(inputFileName, "r");

	if (fp == 0)
	{
		perror("Failed to open file: MSS_Problems.txt");
	}
	else
	{
		int lineNumber = 0;
		char line[MAX_INPUT_LINE_SIZE]; /* or other suitable maximum line size */

		while (fgets(line, sizeof(line), fp) != 0) /* read a line */
		{
			// fputs(line, stdout); /* write the line */
			// printf("%s\n", line);

			// Break the loop if we are at the line we want
			if (lineNumber == inputLineNumber)
			{
				break;
			}
			lineNumber++;
		}

		RemoveNewLineAndAddNullTerm(line);
		// printf("%s\n", line);

		numberOfElements = countElementsInString(line);
		fclose(fp);
	}

	return numberOfElements;
}

void getLineFromFile(char *inputFileName, int inputLineNumber, char *stringValue)
{
	int numberOfElements = 0;
	FILE *fp;
	fp = fopen(inputFileName, "r");

	if (fp == 0)
	{
		perror("Failed to open file: MSS_Problems.txt");
	}
	else
	{
		int lineNumber = 0;
		char line[MAX_INPUT_LINE_SIZE]; /* or other suitable maximum line size */

		while (fgets(line, sizeof(line), fp) != 0) /* read a line */
		{
			// fputs(line, stdout); /* write the line */
			// printf("%s\n", line);

			// Break the loop if we are at the line we want
			if (lineNumber == inputLineNumber)
			{
				break;
			}
			lineNumber++;
		}

		RemoveNewLineAndAddNullTerm(line);
		strncpy(stringValue, line, MAX_INPUT_LINE_SIZE);
		// printf("%s\n", line);

		fclose(fp);
	}
}

int countElementsInString(char *stringValue)
{
	int numberOfCommas = 0;
	int i;

	int stringLen = strlen(stringValue);
	for (i = 0; i < stringLen; i++)
	{
		if (stringValue[i] == 0)
		{
			break;
		}

		if (stringValue[i] == ',')
		{
			numberOfCommas++;
		}
	}

	if (numberOfCommas == 0)
	{
		return 1;
	}
	else
	{
		return numberOfCommas + 1;
	}
}

// Sets all elements in the array to zero
void initializeIntArray(int *intArray, int numberofElements)
{
	int i, j;
	for (i = 0; i < numberofElements; i++)
	{
		intArray[i] = 0;
	}
}

int numberOfLinesInFile(char *fileName)
{
	int ch = 0;
	int numberOfLines = 0;

	FILE *fp;
	fp = fopen(fileName, "r");

	// Count each newline character as a line
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '\n')
		{
			numberOfLines++;
		}
	}

	// This takes care of two cases:
	//	1. The last line of the file doesnt end with a new character
	//	2. There is only one line in the file and this lines does not
	//	   contain a newline character
	// if ((ch != '\n' && numberOfLines != 0) || (ch != 0 && numberOfLines == 0 ))
	// if ((ch != '\n' && numberOfLines != 0))
	// {
	// 	numberOfLines++;
	// }

	fclose(fp);
	return numberOfLines;
}

void displayFile()
{
	FILE *fp;
	char *fileName = "MSS_Problems.txt";
	fp = fopen(fileName, "r");

	if (fp == 0)
	{
		perror("Failed to open file: MSS_Problems.txt");
	}
	else
	{
		char line[5000]; /* or other suitable maximum line size */

		while (fgets(line, sizeof(line), fp) != 0) /* read a line */
		{
			fputs(line, stdout); /* write the line */
			printf("end line\n");
		}

		fclose(fp);
	}

	numberOfLinesInFile(fileName);
}

// For debug purposes
void displayIntArray(int *intArray, int numberOfElements)
{
	int i;
	int arrayTracker = 0;
	for (i = 0; i < numberOfElements; i++)
	{
		printf("%d ", intArray[i]);
		arrayTracker++;
	}

	printf("\n");
	printf("displayIntArray total elements: %d\n", arrayTracker);
}

/**************************************************************
 * * Entry:
 * *  stringValue - the string you want to transform
 * *
 * * Exit:
 * *  n/a
 * *
 * * Purpose:
 * *  Removes the new line character from the string and adds a null
 * *  terminator in its place.
 * *
 * ***************************************************************/
void RemoveNewLineAndAddNullTerm(char *stringValue)
{
	size_t ln = strlen(stringValue) - 1;
	if (stringValue[ln] == '\n')
	{
		stringValue[ln] = '\0';
	}
}

void alg1_enum(int *inputArray, int numberOfElements)
{
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
}

void alg2_betterEnum(int *inputArray, int numberOfElements)
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
 * *  Executes the divide and conquer algorithm for timing
 * *
 * ***************************************************************/
void alg3_divideAndConquer(int *inputArray, int numberOfElements)
{
	int i;
	int currentInputArrayIdx = 0;
	int lastLow = 0;
	int lastHigh = 0;
	int finalSum = 0;

	// Run the divide and conquer algo
	algo3_maxSubArray(inputArray, 0, numberOfElements - 1, &lastLow, &lastHigh, &finalSum);
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
int algo3_maxSubArray(int *inputArray, int lowIdx, int highIdx, int *currentLowIdx, int *currentHighIdx, int *highestSum)
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
		algo3_maxSubArray(inputArray, lowIdx, midIdx, &leftLow, &leftHigh, &leftSum);

		// Find the max subarray of the right side of the current array
		int rightLow = 0;
		int rightHigh = 0;
		int rightSum = 0;
		algo3_maxSubArray(inputArray, midIdx + 1, highIdx, &rightLow, &rightHigh, &rightSum);

		// Find the max subarray that crosses the boundary between the left and right sections of the array
		int crossLow = 0;
		int crossHigh = 0;
		int crossSum = 0;
		algo3_maxCrossingSubArray(inputArray, lowIdx, midIdx, highIdx, &crossLow, &crossHigh, &crossSum);

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
void algo3_maxCrossingSubArray(int *inputArray, int lowIdx, int midIdx, int highIdx, int *crossLow, int *crossHigh, int *crossSum)
{
	int i;
	int leftSum = INT_MIN;
	int maxLeftIdx = 0;

	int rightSum = INT_MIN;
	int maxRightIdx = 0;

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