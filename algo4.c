//Frank Eslami, CS325-400, Project 1, Algorithm 4
#include <stdio.h>

typedef struct {
    int start_index;
    int end_index;
    int sum;
} max_subarray;

max_subarray get_max_subarray(int main_array[], int main_start_index, int main_end_index);


int main() {
		int main_array[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
		int main_start_index = 0;
		int main_end_index = sizeof(main_array)/sizeof(main_array[0]);
		max_subarray subarray;

		subarray = get_max_subarray(main_array, main_start_index, main_end_index);
		printf("Max sum = %d\n", subarray.sum);
		
		return 0;
}


/******** FUNCTION DEFINTIONS ********/
max_subarray get_max_subarray(int main_array[], int main_start_index, int main_end_index) {
		int i;
		int tmp_sum;
		max_subarray max_data, current_data;

		max_data.sum = 0;
		max_data.start_index = -1;
		max_data.end_index = -1;

		current_data.sum = 0;
		current_data.start_index = -1;

		for (i = main_start_index + 1; i < main_end_index; i++) {
				tmp_sum = current_data.sum	+ main_array[i];
				if (tmp_sum > 0) {
						if (current_data.sum == 0) {
								current_data.start_index = i;
						}
						current_data.sum = tmp_sum;
				}
				else {
						current_data.sum = 0;
				}	

				if (current_data.sum > max_data.sum) {
						max_data.sum = current_data.sum;
						max_data.start_index = current_data.start_index;
						max_data.end_index = i;
				}
		}

		return max_data;
}
