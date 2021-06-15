#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struct defines information for a countryCode with two members
// each countryCode struct has a code and a respective name
struct countryCode {
	int code;
	char name[50];
};
// searchList takes a countryCode array, size and code number as parameters
// and searches the list for the struct that's code matches with the given code
void searchList(struct countryCode aList[], int size, int num)
{
	// i i sused as a counter for the for loop
	// found is used as a boolean  to signify when a matching struct
	// has been found	
	int i, found = 0;
	for(i = 0; i < size; i++)
	{
		// if struct's code member's value matches num, set found to true
		// and break out of the loop
		if(aList[i].code == num) {
			found = 1;
			break;
		}
	}	
	
	// if a struct was found, print the struct's corresponding name
	// if not found, print error message
	if(found)
	{
		printf("Country name: %s\n", aList[i].name);
	}
	else {
		printf("Error: Code does not match\n");
	}
	
	
}
int main(void)
{
	// code variable stores input from user
	int code = 0;
	//printf prompts user for dialing code and scanf retreives and stores in
	//code variable
	printf("Please enter an international dialing code: ");
	scanf("%d", &code);
	// integer array codes[] stores all the dialing codes in a list
	int codes[] = {506, 33, 505, 51, 46, 1, 964, 81, 54, 86, 45, 353, 63, 381, 44, 261, 49, 55, 20, 52, 40, 966};
	// *names[] pointer array stores an array pointers to different string locations with names that are repsective of each dialing code in codes[]
	char *names[] = {"Costa Rica", "France", "Nicaragua", "Peru", "Sweden", "United States", "Iraq", "Japan", "Argentina", "China", "Denmark", "Ireland", "Philippines", "Serbia", "United Kingdom", "Madagascar", "Germany", "Brazil", "Egypt", "Mexico", "Romania", "Saudi Arabia"};
	// size integer stores the size of list of codes
	int size = sizeof(codes)/sizeof(int);
	
	// int i is used as sa counter for the for loop
	// int j is used to extract chars from eeach string in *names 
	int i, j = 0;
	char ch = 0;
	// list is an array of countryCode structs
	struct countryCode list[size];
	// For loop initializes all the members of all the structs in list.
	// Takes values form codes[] and *names[]
	for(i = 0; i < size; i++){
		list[i].code = codes[i];
		ch = names[i][j];
		while(ch != '\0')
		{
			list[i].name[j] = ch;
			j++;
			ch = names[i][j];
		}
		list[i].name[j] = '\0';
		j = 0;	
	}
	
	searchList(list, size, code);	

	return 0;
}
