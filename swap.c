#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// swap function has three parameters, 2 char pointers and a length variable
void swap(char *s, char *s1, int length)
{	
	// integer i used as a counter with for loop
	int i; 
	// two char variables hold a character for each string
	char ch, ch1; 
	// for loop goes through each string
	for(i = 0; i < length; i++)
	{
		// ch values are extracted from each string
		ch = s[i];
		ch1 = s1[i];

		// If the first character is a letter and the second character is a number
		if(((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90)) && (ch1 >= 48 && ch1 <= 57)) {
			// the values of the charactesr are swapped without using a third variable.
			// These characters are ASCII values and have unique numbers associated with them.
			// here the numbers are manipulated so that the characters end up with the other 
			// characters unique decimal value		
	
			ch = ch + ch1;
			ch1 = ch - ch1;
			ch = ch - ch1;
			
			// after swapping, the values are put into the original strings
			s[i] = ch;
			s1[i] = ch1;
		}
		// If the first character is a number and second character is a letter
		else if(((ch1 >= 97 && ch1 <= 122) || (ch1 >= 65 && ch1 <= 90)) && (ch >= 48 && ch <= 57)){
			// SAME PROCESS AS ABOVE
			ch = ch + ch1;
			ch1 = ch - ch1;
			ch = ch - ch1;
			
			s[i] = ch;
			s1[i] = ch1;
		}
		// If the characters are both letters, both integers, or something else, their values
		// are replaces by a "space", or a terminating character if they are at the end of the string
		else {
			if(i == length - 1) {
				s[i] = '\0';
			 	s1[i] = '\0';
			}
			else {
				s[i] = '_';
				s1[i] = '_';
			}
		}
	}
}
int main(void)
{
	// char arrays with size of 200 to hold two input strings from the user
	char sentence[200] = {0};
	char sentence1[200] = {0};
	// use printf to prompt user, and fgets to get the string and store in char array
	printf("Enter first sentence: ");
	fgets(sentence, 200, stdin);
	printf("Enter second sentence: ");
	fgets(sentence1, 200, stdin);
	
	// length variable gets the length of the first string. This programs assumes that both
	// strings entered of the same length
	int len = strlen(sentence) - 1;

	// call swap function to swap strings
	swap(sentence, sentence1, len);

	// prints out the value of the strings after the swap
	printf("First sentence after swap: %s\n", sentence);
	printf("Second sentence after swap: %s\n", sentence1);
	
	return 0;
}
