#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function as a pointer as a parameter than
// points to the len variable
int getPoints(int *len_ptr)
{
	// new len variable retrieves the actual value of len_ptr
	int len = *len_ptr;
	int points = (10 - len) * 5;
	return points;
}
int main(void)
{
	// char array to store user input
	char password[100] = {0};
	// printf and scanf to retrieve password from user
	printf("Enter password: ");
	scanf("%s", &password);
	// len variable gets the length of the password string.
	// points variable stores the total points
	int len = strlen(password);
	int points = 0;
	// if loop determines if the password is safe or not depending on its
	// length. And the prints out the final score of the password based
	// on how many characters it is missign out of 10
	if(len < 10) {
		// points variable calls getPoints functions to get the points
		// for this password. Passes the address of the len variable
		points = getPoints(&len); 
		if(points < 30) {
			printf("Final score %d\n", points);	
		}
		else {
			printf("Password unsafe! Please reset.\n");
			printf("Final score %d\n", points);
		}
	}
	else {
		printf("The password is safe.\n");
		printf("Final score %d\n", points);
	}
	return 0;
}
