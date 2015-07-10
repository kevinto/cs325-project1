/**************************************************************
 * *  Filename: random_array.c 
 * *  Coded by: Frank Eslami
 * *  Purpose - Generate & write to file 10 random arrays of integers of size n
 * *
 * * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "filefunctions.h"

void create_random_array(int n);

int main(int argc, char *argv[]) {
    //Obtain n input from terminal
    int n;
    printf("Enter array size. Ten arrays of this size will be written to file 'MSS_Problems.txt': ");
    scanf("%d", &n);

    create_random_array(n);
    return 0;
}

//Create 10 arrays of random integers of size n between -99 to 99 & write to file
void create_random_array(int n) {
    srand(time(NULL));
    int i, j, rand_num;

    FILE *outputFile = fopen("MSS_Problems.txt", "w");

    //Create 10 arrays of size n   
    for (i = 0; i < 10; i++) { 
        fprintf(outputFile, "%c", '[');

        for (j = 0; j < n; j++) {
            if(j == 0) {
                rand_num = rand() % (100 - 1) + 1;
                fprintf(outputFile, "%d", rand_num);
            }
            else {
                rand_num = rand() % (100 + 99) - 99;
                fprintf(outputFile, ", %d", rand_num);
            }
        } 
		if (i != 9)
		    fprintf(outputFile, "%c\n", ']');
		else
		    fprintf(outputFile, "%c", ']');
    }
}
