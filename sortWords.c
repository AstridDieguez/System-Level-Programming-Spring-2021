#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort_alphabetic(char words[][30], int size, int sortOrder)
{
	// i, j, and k are used to loop through the strings in the string array and 
	// compare them. i is the value of the first string, and j is the value of the
	// next string. k is used to loop through the string(s) swap them from
	// location to location.
	int i, j, k;
	// Index, min and swap are used in the case that the strings match on the
	// first character. In that case, the next characters of the string(s)
	// are compared, and the next, until it is clear with string is bigger
	// or smaller.
	int index = 0, min;
	int swap = 0;
	// Ascending order 0 
	// Descending order 1
	if(sortOrder == 0 || sortOrder == 1){
	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++){
			// Strings are made to be case insensitive for simplicity.	
			char chP = words[i][index];
			char chP1 = words[j][index];
			if(chP >= 65 && chP <= 90){
				chP = chP + 32;
			}
			if(chP1 >= 65 && chP1 <= 90){
				chP1 = chP1 + 32;
			}
			//printf("chP: %c, chP1: %c\n", chP, chP1);
			
			// if equal, change chP and chP1 to next char in word(s)
			if(chP > chP1 && sortOrder == 0 || chP < chP1 && sortOrder == 1 || swap == 1){
				k = 0;
				// Temp char arrays hold the string values to be swapped.
				char temp[30] = {0};
				char temp1[30] = {0};
				
				// point 1 and point 2 point to the first characters
				// in the string(s).
				char *point1 = &(words[i][k]);
				char *point2 = &(words[j][k]);

				// ch an ch1 extract the value from the pointers.
				char ch = *point1;
				char ch1 = *point2;

				// store first string in temp
				while(ch != '\0')
				{
					temp[k] = ch;
					k++;
					words[i][k - 1] = 0;
					ch = words[i][k];
				}
				temp[k] = '\0';
				// store second string in temp1
				k = 0;			
				while(ch1 != '\0')
				{
					temp1[k] = ch1;
					k++;
					words[j][k - 1] = 0;
					ch1 = words[j][k];
				}	
				temp1[k] = '\0';

				//printf("temp: %s\n", temp);
				//printf("temp1: %s\n", temp1);
				
				// swap strings
				k = 0;
				ch = temp1[k];
				while(ch != '\0')
				{
					words[i][k] = ch;
					k++;
					ch = temp1[k];
				}
				words[i][k] = '\0';
				
				k = 0;
				ch1 = temp[k];
				while(ch1 != '\0')
				{
					words[j][k] = ch1;
					k++;
					ch1 = temp[k];			
				}
				words[j][k] = '\0';
			
				swap = 0;	
			}
			// If the charactesr are equal, and the sort order is
			// ascending, move on to the next characters up until the 
			// length of the shorter string.
			else if(chP == chP1 && sortOrder == 0){
			if(index == 0){
				int len = strlen(words[i]);
				int len1 = strlen(words[j]);
				if(len <= len1){
					min = len;
				}
				else{
					min = len1;
				}
				j--;
				index++;
			}
			else if(index == min - 1){
				index = 0;
				min = 0;	
			}
			else{
				j--;
				index++;
			}
			}
			// If the characters are equal and the sort order is
			// descending, move on to the next characters up until 
			// the length of the shorter string. At the length of the
			// shorter string, swap strings.
			else if(chP == chP1 && sortOrder == 1){
			if(index == 0){
				int len = strlen(words[i]);
				int len1 = strlen(words[j]);
				if(len <= len1){
					min = len;
				}
				else{
					min = len1;
				}
				j--;
				index++;
			}
			else if(index == min - 1){
				swap = 1;

				index = 0;
				min = 0;
				j--;
			}
			else{
				j--;
				index++;
			}
			}			
		}
	}
	}
	else{
		
	}		
}
// This function displays a string array passed as a parameter.
void print_words(char words[][30], int size)
{
	// A for loop and while loop is used here to display strings in the array.
	int i, j = 0;
	for(i = 0; i < size; i++)
	{	
		// Ch extracts individual chars from each string and displays them.
		// Once the entire string is displayed, i is incremented and
		// it begins to display the next string.
		char ch = words[i][j];
		while(ch != '\0')
		{
			printf("%c", ch);
			j++;
			ch = words[i][j];
		}
		j = 0;
		printf("\n");
	}
}
int main(void){

// Printf and scanf are used here to prompt the user for a specified sorting order. If 
// The users input is invalid, the default sorting order is ascending.
char sortChar;
int sort = 0;
printf("Ascending order (A) or descending order (D): ");
scanf("%c", &sortChar);
if(sortChar == 'a' || sortChar == 'A'){
	sort = 0;
}
else if(sortChar == 'd' || sortChar == 'D'){
	sort = 1;
}
else{
	printf("Invalid sort order. Sorting by ascending.\n");
}
// 2-D char array contains an array of strings to be sorted.
char words[][30] = {"Systems", "Programming", "Deep", "Learning", "Internet", "Things", "Robotics", "Course"};

// Size gets the length of the array of the strings.
int size = sizeof(words)/30;

int i, j;

// The array is first displayed unsorted.
print_words(words, size);

// Array is sorted.
sort_alphabetic(words, size, sort);

// The array is displayed sorted.
printf("\nSorted:\n");
print_words(words, size);
return 0;
}
