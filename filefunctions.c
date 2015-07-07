
#include <stdio.h>
#include <stdlib.h>
#include "filefunctions.h"

void FillIntArray(char *inputFileName, int **inputArray, int numberOfRows)
{
	initializeIntArray(inputArray, numberOfRows, MAX_INT_ELEMENTS);
	displayIntArray(inputArray, numberOfRows, MAX_INT_ELEMENTS);
}

void initializeIntArray(int **intArray, int numberOfRows, int numberofColumns)
{
	// Cleanup dynamically allocated strings
	int i, j;
	for (i = 0; i < numberOfRows; i++)
	{
		for (j = 0; j < numberofColumns; j++)
		{
			intArray[i][j] = 0;
		}
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

	// This takes care of the case where the last line in the
	// file does not end with a newline character.
	if (ch != '\n' && numberOfLines != 0)
	{
		numberOfLines++;
	}

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
void displayIntArray(int **intArray, int numberOfRows, int numberofColumns)
{
	// Cleanup dynamically allocated strings
	int i, j;
	for (i = 0; i < numberOfRows; i++)
	{
		for (j = 0; j < numberofColumns; j++)
		{
			printf("%d ", intArray[i][j]);
		}
		printf("\n");
	}
}