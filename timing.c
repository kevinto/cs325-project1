/**************************************************************
 * *  Filename: timing.c
 * *  Coded by: Matt Walz
 * *  Purpose - This code will generate the timing data for the
 * *      experimental analysis portion of Project 1. The function
 * *      will loop through 10 different input sizes, n, running
 * *      10 times for each input size. Each run will generate an
 * *      array of n random numbers between -99 and 99 and then
 * *      time each of the 4 algorithms as they find the maximum
 * *      sum sub-array of the array of random numbers. Each
 * *      algorithm will output its timing runs to a separate
 * *      output file to avoid mixing up the timing results.
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include "filefunctions.h"

#define MAX_N 100000

// Program entry point
int main()
{
	int range = 99 - (-99) + 1;  //want a range of random numbers from [-99, 99] inclusive
	srand(time(NULL));  //seed the random number generator
	clock_t timer;  //initialize a variable for the timer
	int array_rand[MAX_N];
	// int array_n_vals[] = {2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000, 22500, 25000, 27500, 30000};//{300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500};

	// Values for the divide and conquer
	int array_n_vals[] = {1000, 2000, 3000, 4000, 6000, 8000, 10000, 15000, 20000, 30000};//{300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500};
	// int array_n_vals[] = {35000, 40000, 45000, 50000};//{300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500};

	int i, j, k;
	
//	FILE *outputEnum = fopen("Enum_Timing_Results.txt", "w");  //create output file for timing of algorithm 1
	// FILE *outputBetterEnum = fopen("Better_Enum_Timing_Results.txt", "w");  //create output file for timing of algorithm 2
	FILE *outputDivConquer = fopen("Divide_Conquer_Timing_Results.txt", "w");  //create output file for timing of algorithm 3
//	FILE *outputLinear = fopen("Linear_Timing_Results.txt", "w");  //create output file for timing of algorithm 4
	
	for (i = 0; i < sizeof(array_n_vals)/sizeof(int); i++) {
		for (j = 0; j < 10; j++) {
			//output the current value of n to each file before outputting timing results every time n increments
			if (j == 0) {
				if (i == 0) {
//					fprintf(outputEnum, "n = %d\n\n", array_n_vals[i]);
					// fprintf(outputBetterEnum, "n = %d\n\n", array_n_vals[i]);
					fprintf(outputDivConquer, "n = %d\n\n", array_n_vals[i]);  
//					fprintf(outputLinear, "n = %d\n\n", array_n_vals[i]);
				} else {
//					fprintf(outputEnum, "\n\n\nn = %d\n\n", array_n_vals[i]);
					// fprintf(outputBetterEnum, "\n\n\nn = %d\n\n", array_n_vals[i]);
					fprintf(outputDivConquer, "\n\n\nn = %d\n\n", array_n_vals[i]);  
//					fprintf(outputLinear, "\n\n\nn = %d\n\n", array_n_vals[i]);
				}
			}
			
			
			//generate array of random numbers
			for (k = 0; k < array_n_vals[i]; k++) {
				array_rand[k] = rand() % range + (-99); 
			}
			//time algorithm 1 and record results in algorithm 1 output file
/*			timer = clock();
			alg1_enum(array_rand, array_n_vals[i]);
			timer = clock() - timer;
			if (j == 10 - 1) {
				fprintf(outputEnum, "%f", (float)timer / (float)CLOCKS_PER_SEC);
			} else {
				fprintf(outputEnum, "%f\n", (float)timer / (float)CLOCKS_PER_SEC);
			}
*/			
			//time algorithm 2 and record results in algorithm 2 output file
			// timer = clock();
			// alg2_betterEnum(array_rand, array_n_vals[i]);
			// timer = clock() - timer;
			// if (j == 10 - 1) {
			// 	fprintf(outputBetterEnum, "%f", (float)timer / (float)CLOCKS_PER_SEC);
			// } else {
			// 	fprintf(outputBetterEnum, "%f\n", (float)timer / (float)CLOCKS_PER_SEC);
			// }
			
			//time algorithm 3 and record results in algorithm 3 output file
			timer = clock();
			alg3_divideAndConquer(array_rand, array_n_vals[i]);
			timer = clock() - timer;
			if (j == 10 - 1) {
				fprintf(outputDivConquer, "%f", (float)timer / (float)CLOCKS_PER_SEC);
			} else {
				fprintf(outputDivConquer, "%f\n", (float)timer / (float)CLOCKS_PER_SEC);
			}
			
			//time algorithm 4 and record results in algorithm 4 output file
/*			timer = clock();
			alg4_linear(array_rand, array_n_vals[i]);
			timer = clock() - timer;
			if (j == 10 - 1) {
				fprintf(outputLinear, "%f", (float)timer / (float)CLOCKS_PER_SEC);
			} else {
				fprintf(outputLinear, "%f\n", (float)timer / (float)CLOCKS_PER_SEC);
			}
*/
		}
	}
	
	//close output files
//	fclose(outputEnum);
	// fclose(outputBetterEnum);
	fclose(outputDivConquer);
//	fclose(outputLinear);
}