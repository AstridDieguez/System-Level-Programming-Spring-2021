#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort_numeric(float *numP, int size, int descending)
{
	// Integers i, j, and k are used for the for loops to go through each float.
	// The loop then compares the first item to the other items after it in the array,
	// amd then the second item and all the items after it, and so on.
	int i, j, k = 0;
	if(descending == 0){
	// This for loop sorts ascending
	for(i = 0; i < size; i++)
	{
		for(j = i; j < size - 1; j++)
		{	
			// Takes the value of the pointer numP
			// Takes the value of the pointer numP + 1	
			float num = *(numP + i);
			float num1 = *(numP + j + 1);
			// Compares values. If num is greater, then swap numbers.
			if(num > num1){
				float temp = num;	
				numP[i] = num1;
				numP[j + 1] = temp;
			}
		}
	}
	}
	else{
	// Sort descending. This loop is similar to the loop for sorting by
	// ascending The only difference is that is swaps the numbers
	// by the opposite comparison, so when num is less than num1,
	// the numbers swap.
	for(i = 0; i < size; i++)
	{
		for(j = i; j < size - 1; j++)
		{
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
	char sortChar;
	int sort;
	printf("Sort ascending (A) or descending (D): ");
	scanf("%c", &sortChar);
	// Using printf and scanf here to prompt the user to identify a sort order.
	// If the users input is invalid, the default sort order is ascending.
	if(sortChar == 'a' || sortChar == 'A'){
		sort = 0;
	}
	else if(sortChar == 'd' || sortChar == 'D'){
		sort = 1;
	}
	else{
		//Invalid sort order.
		printf("Invalid sort order. Sorting by ascending.\n");
		sort = 0;	
	}
	// numbers[] array contains an array of floats to be sorted.
	float numbers[] = {10, 0.25, -2342, 12123, 3.145435, 6, 6, 5.999, -2, -5, -109.56};
	int arrSize = sizeof(numbers)/sizeof(float);	
	// The program first displays the array unsorted.
	int i;
	for(i = 0; i < arrSize; i++)
	{
		if(i == arrSize - 1){
			printf("%f\n", numbers[i]);
		}
		else{
			printf("%f, ", numbers[i]);
		}
	}
	// Call sorting function. Function takes three parameters: the memory location 
	// of the first number in the array, the array size, and the sorting method.
	sort_numeric(&numbers[0], arrSize, sort);

	// Displays the sorted array.
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
	
	return 0;
}
