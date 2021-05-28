#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Struct called Registration contains a structure for all the information of a 
// registered user for a COVID vaccination.
struct Registration{
	char firstName[50];
	char lastName[50];
	int DOB[3];
	int sex;
	int doseNum;
	int prevDate[3];
	int vaccineType;
	char zip[6];
	char ID[9];
};
// registerPerson Function register a new user into the system.
void registerPerson(struct Registration aList[], int count)
{
	// The following prompts gather information from the user using printf and
	// scanf. The program retrieves first name, last name, DOB, sex, dose number,
	// previous dose date, vaccine type, and residential zip code.
        printf("Thank you registering for your vaccine. Please answer the corresponding questions to the best of your knowledge.\n\n");

        printf("Please enter your first name: ");
        scanf(" %s", &aList[count].firstName);
        printf("Please enter your last name: ");
        scanf(" %s", &aList[count].lastName);

        printf("Please enter your DOB (mm/dd/yyy): ");
        scanf(" %d/%d/%d", &aList[count].DOB[0], &aList[count].DOB[1], &aList[count].DOB[2]);

        printf("Enter your sex (1 Male, 2 Female, 3 No Identification): ");
        scanf(" %d", &aList[count].sex);


        printf("Enter your dose number (1 OR 2): ");
        scanf(" %d", &aList[count].doseNum);

        printf("Enter the date of your previous dose (mm/dd/yyyy): ");
        scanf(" %d/%d/%d", &aList[count].prevDate[0], &aList[count].prevDate[1], &aList[count].prevDate[2]);

        printf("Enter vaccine type (1 Pfizer, 2 Moderna, 3 J&J): ");
        scanf("%d", &aList[count].vaccineType);

        printf("Enter your 5-digit zip code: ");
        scanf("%s", &aList[count].zip);

	aList[count].zip[5] = '\0';

	// After the program gathers all the information, a unique 8 letter code
	// is generated for this particular user. This user can use this
	// code search for their information in the system and display it to the
	// screen.
	//
	// The code itself takes data from the information the user put in:
	aList[count].ID[0] = aList[count].firstName[0];
	aList[count].ID[1] = aList[count].lastName[0];
	aList[count].ID[2] = '0';
	aList[count].ID[3] = '0';

	char vaccineNames[][20] = {"Pfizer", "Moderna", "J&J"};
	aList[count].ID[4] = vaccineNames[aList[count].vaccineType - 1][0];
	
	aList[count].ID[5] = aList[count].zip[2];
	aList[count].ID[6] = aList[count].zip[3];
	aList[count].ID[7] = aList[count].zip[4];

	aList[count].ID[8] = '\0';
	// Prints of the registration code for the user to reference.
	printf("Your registration code: %s\n", aList[count].ID);

}
// The search function searches for a users registration information
// in the system based off of their unique 8 letter code that was
// generated for them during registeration.
void search(struct Registration aList[], char ID[9], int listSize)
{
	int i;
	int found = 1; 
	// Searches for a matching code ID int he system
	for(i = 0; i < listSize; i++)
	{
		found = strcmp(ID, aList[i].ID);
		if(found == 0){
			break;
		}	
	}
	// If a match it found, the corresponding information is diplayed
	// on the screen for the user to see.
	if(found == 0){

		printf("User Information:\n");
		printf("First Name: %s\n", aList[i].firstName);
		printf("Last Name: %s\n", aList[i].lastName);
		printf("DOB: %d/%d/%d", aList[i].DOB[0], aList[i].DOB[1], aList[i].DOB[2]);
		printf("\n");

		char sexID[][50] = {"Male", "Female", "No Identification"};

		printf("Sex: %s\n", sexID[aList[i].sex - 1]);
		printf("Dose number: %d\n", aList[i].doseNum);
		printf("Previous vaccination date: %d/%d/%d", aList[i].prevDate[0], aList[i].prevDate[1], aList[i].prevDate[2]);
		printf("\n");		

		char vaccineNames[][20] = {"Pfizer", "Moderna", "J&J"};
		

		printf("Vaccine type: %s\n", vaccineNames[aList[i].vaccineType - 1]);
		printf("Zip-code: %s\n", aList[i].zip);
	}
	// If no match is found, an error message is printed to screen.
	else{
		printf("User not found.\n");
	}
}
int main(void)
{
	// An array of registration structs is created and initialized to zero. It can
	// hold a maximum of 100 user registrations.
	struct Registration list[100] = {0};
	int count = 0;

	// Registers the first person in the program.
	registerPerson(list, count);

	// Once the first person is registered, they can choose to either 
	// register another person, or view any registration information
	// of someone who has already been registered.
	char input;
	printf("Register another user (R) or view user info (V): ");
	scanf(" %c", &input);

	// Program takes input from scanf, and prompts the user with printf.
	while(input == 'R' || input == 'r' || input == 'V' || input == 'v')
	{
		// Register another user.
		if(input == 'R' || input == 'r')
		{
			count++;
			registerPerson(list, count);
		}
		// View an existing user's information via their unique code.
		else if(input == 'V' || input == 'v')
		{
			char ID[9];
			printf("Enter unique user ID: ");
			scanf("%s", &ID);

			search(list, ID, count + 1);			
		}

		printf("Register another user (R) or view user info (V): ");
		scanf(" %c", &input);

	}

	


return 0;
}
