#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkPass(char* pass_ptr, int length)
{
	// lowerCount will count for lowercase letters
	// upperCount will count for uppercase letters
	// numCount will count numbers
	// i will be the counter for the for loop
	int lowerCount = 0, upperCount = 0, numCount = 0;
	int i;
       	// ch holds the char for each loop iteration, consChar is used to compare
       	// the previous char to the current char, charCount counts the number of
       	// consecutive chars, and consecutive serves as a true/false value.
	char ch, consChar = pass_ptr[0], charCount = 1;
	int consecutive = 0;
	//  for loop goes through each character of the password given
	//  by the user and checks for lowercase letters, uppercase letters, and
	//  numbers, as well as consecutive characers	
	for(i = 0; i < length; i++) {
		ch = pass_ptr[i];
		if(ch >= 97 && ch <= 122) {
			// lower case counter
			lowerCount++;
		}
		else if(ch >= 65 && ch <= 90) {
			// upper case counter
			upperCount++;
		}
		else if(ch >= 48 && ch <= 57) {
			// number counter
			numCount++;	
		}	
		// if statement will check for consecutive characters each iteration.
		// Will begin checking after the second char, and compare the current
		// char to the char before it to see if its consecutive.
		// After 3 consecutive chars this block will not be executed
		if(i > 0 && consecutive == 0) {
			if(ch == (consChar + 1)) {
				charCount++;
			}
			else {
				// Reset charCount, no match
				charCount = 1;
			}
			consChar = ch;
			// consecutive is used as a boolean here, 0 for not
			// consecutive and 1 for consecutive
			if(charCount >= 3) {
				consecutive = 1;
			}
		}
	}
	// Points variable holds the points for the password
	// 20 points will be added if there is lack of either
	// lowercase letters, uppercase letters or numbers, and if
	// there are more than 2 consecutive characters
	int points = 0;
        if(lowerCount == 0) {
                points = points + 20;
        }
        if(upperCount == 0) {
                points = points + 20;
        }
        if(numCount == 0) {
                points = points + 20;
        }
        if(consecutive == 1) {
                points = points + 20;
        }
	// This function returns points as an integer
	return points;
}
int main(void)
{
	// char array to hold the password, no larger than 100 characters
	char password[100] = {0};
	// printf and scanf to get password input from user
	printf("Enter password: ");
	scanf("%s", &password);
	int len = strlen(password);
	// Criteria:
	// Missing lower case
	// Lack of capital letters
	// Missing numbers
	// More than 2 consecutive characters (123 or abc)

	int points = checkPass(password, len);
	// Print the password status and final score.	
	if(points < 30) {
		printf("The password is safe.\n");
	}
	else {
		printf("The password is unsafe! Please reset.\n");	
	}
	printf("Final score %d\n", points);
	
	return 0;
}
