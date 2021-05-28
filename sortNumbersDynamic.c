#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort_numeric(float *numP, int size, int descending)
{
	// Sorts the float array by ascending order.
	int i, j, k = 0;
	if(descending == 0){
	// Sort ascending
	for(i = 0; i < size; i++)
	{
		for(j = i; j < size - 1; j++)
		{
			// Pointers used here to extract values from the array.
			// Values are then compared, and then swapped if necessary.	
			float num = *(numP + i);
			float num1 = *(numP + j + 1);
			if(num > num1){
				float temp = num;	
				numP[i] = num1;
				numP[j + 1] = temp;
			}
		}
	}
	}
	else{
	// Sort descending
	for(i = 0; i < size; i++)
	{
		//First Item is i
		for(j = i; j < size - 1; j++)
		{
			//Second item is j
			//Pointers used here to extract values from teh array.
			//Values are then compared and then swapped if necessary.
			float num = *(numP + i);
			float num1 = *(numP + j + 1);
			if(num < num1){
				float temp = num;
				numP[i] = num1;
				numP[j + 1] = temp;
			}
		}
	}
	}
}
int main(void)
{
	// printf and scanf are used here to prompt the user to identify a sorting order
	// If the users input is invalid, the default sorting method is ascending
	char sortChar;
	int sort;
	printf("Sort ascending (A) or descending (D): ");
	scanf(" %c", &sortChar);

	if(sortChar == 'a' || sortChar == 'A'){
		sort = 0;
	}
	else if(sortChar == 'd' || sortChar == 'D'){
		sort = 1;
	}
	else{
		printf("Invalid sort order. Sorting by ascending.\n");
		sort = 0;	
	}
	
	// This program prompts the user to manually input numbers into a 
	// dynamically allocated array. THe user inputs one number every prompt.
	float fl;
	char input;
	int floatSize = sizeof(float);
	int count = 0;	

	printf("Enter a number: ");
	scanf("%f", &fl);

	// Allocate memory
	float *numbers = (float*)malloc(floatSize);
	numbers[count] = fl;
	
	count++;
	int arrSize = count;
	// Sort here
	sort_numeric(&numbers[0], arrSize, sort);

	// Print sorted array
        printf("Sorted:\n");
        int k;
        for(k = 0; k < arrSize; k++){
                if(k == arrSize - 1){
                        printf("%f\n", numbers[k]);
                }
                else{
                        printf("%f, ", numbers[k]);
                }
        }
	// Program prompts user if they would like to add another number to array.
	// If the input y or Y, they are prompted to enter another number.
	// Otherwise the program terminates
	printf("Add to array? (Y): ");
	scanf(" %c", &input);

	while(input == 'y' || input == 'Y')
	{
		printf("Enter a number: ");
		scanf("%f", &fl);
	
		// The program uses realloc to increase the size of the
		// dynamically allocated array to make space
		// for the next float	
		printf("You entered: %f\n", fl);
		count++;
		numbers = realloc(numbers, count * floatSize);
		numbers[count - 1] = fl;

		arrSize = count;
		// Program sorts the newly allocated array 
		sort_numeric(&numbers[0], arrSize, sort);
		// THe new array is then displayed to the user
		printf("Sorted:\n");

		for(k = 0; k < arrSize; k++){
			if(k == arrSize - 1){
				printf("%f\n", numbers[k]);
			}
			else{
				printf("%f, ", numbers[k]);
			}
		}
		// Prompt again to add another float
		printf("Add to array? (Y): ");
		scanf(" %c", &input);
	}
	
	return 0;
}
