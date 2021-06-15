#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome(char *message)
{
	// split array will store concatenated version of message parameter
	// token pointer will point to individual tokens in message
	char split[250] = {0};
	char *token = strtok(message, " ");

	// loop will go through each token in message until it returns a null
	// pointer. Each token is concatenated to split
	while(token != NULL)
	{
		strcat(split, token);
		token = strtok(NULL, " ");
	}	

	// length stores the length of split string minus '\0'
	// i is used as a counter for the for loop
	// isPalindrome serves as a boolean
	// ch1 and ch2 are used to compare characters in split string
	int length = strlen(split) - 1;
	int i, isPalindrome = 1;
	char ch1, ch2;

	for(i = 0; i <= length / 2; i++)
	{
		ch1 = split[i];
		ch2 = split[(length - 1) - i];	
		
		// if ch1 and ch2 don't match, string is not a palindrome and loop breaks
		if(ch1 == ch2) {
		}
		else {
			isPalindrome = 0;
			break;
		}	
	}
	// returns value of isPalindrome
	return isPalindrome;
}
int main(void)
{
	// message array stores input message from user
	// //fgets gets line from standard input
	char message[250] = {0};
	printf("Enter a message: ");
	fgets(message, 250, stdin);

	// call palindrome function and pass message string as a parameter
	// function returns boolean value
	int isPalindrome = palindrome(message);

	// prints out a message	
	if(isPalindrome == 0) {
		printf("Is not a palindrome\n");
	}		
	else {
		printf("Is a palindrome\n");
	}

	return 0;
}
