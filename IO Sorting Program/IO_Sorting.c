/*Erin Dominescy
  10/15/2015*/

#include <stdio.h>
#include <stdlib.h>

/*compare function: Used as a parameter in the quicksort function
	and compares the values of two integers to determine which is greater.

	@param ele1: element 1 will store the first element to be compared.
	@param ele2: element 2 will store the second element to be compared. */

int compare (const void * ele1, const void * ele2){
	int f = *((int*)ele1);
	int s = *((int*)ele2);
	if(f>s) return 1;
	if(f<s) return -1;
	return 0;
}

/*main function: Takes the given input and output files and sets the input to 
	be read and the output to write, then reads the unsorted integers
	from the input file and puts them into an integer array. The unsorted array 
	is then printed to demonstrate that the sorting has not happened yet.

	@param args: The number of arguments given when the program is being executed.
	@param argsv: Stores the values of the arguments given at execution into this array. */

int main (int args, char * argsv[]){

	if (argsv[3]==NULL){
		FILE *input, *output;

		input = fopen(argsv[1], "r");
		output = fopen(argsv[2], "w");

		int read;
		int *array = malloc(sizeof(int));
		int count = 0;

		printf("Getting numbers from input file...\n");
		printf("\n    Unsorted:\n");

				if (input!=NULL){
				
						while (fscanf(input, "%d", &read)!=EOF){
							array[count]=read;
							printf("%d ", array[count]);
							count++;
							int *temp = realloc(array,(count+1)*sizeof(int));
						
									if (temp!=NULL){
										array=temp;
									}
						}
				}
			
				else {
						printf("Input file cannot be opened.\n");
				}


		/*qsort function: used to sort and array of integers from least to greatest.

			@param array: The array to be sorted.
			@param count: The amount of numbers in the array.
			@param sizeof(int): The size of the integer.
			@param compare: Uses the compare function. */

		qsort (array, count, sizeof(int), compare);
				int i=0;	
				printf("\n\n     Sorted:\n");
						for (i; i<count; i++){
								printf("%d ", array[i]);
								fprintf(output, " %d ", array[i]);
						}
				printf("\n\nThe sorted array of numbers has been written to the output file.\n\n");
		}
		
		else {
				printf("Please provide the input and output file names as ./a.out name1 name2\n");
		}

} /*END OF PROGRAM */
