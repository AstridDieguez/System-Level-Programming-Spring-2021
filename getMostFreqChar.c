#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
if(argc > 2){
	printf("Too many arguments\n");
}
else if(argc == 1){
	printf("Not enough arguments\n");
}
else{
	printf("Argument supplied is %s\n", argv[1]);
	FILE *fp;
	fp = fopen(argv[1], "r");

	char buff[255];
	char input[255];
	while(fgets(buff, 255, (FILE*)fp) != NULL)
	{
		strcat(input, buff);	
	}

	printf("%s\n", input);

	int i;
	char c;
	int count[26] = {0};

	for(i = 0; i < 255 + 1; i++)
	{
		c = input[i];
		if(c <= 'z' && c >= 'a')
		{
			count[c - 'a']++;
		}	
		else if(c <= 'Z' && c >= 'A')
		{
			count[c - 'A']++;
		}	
	}

	i = 0;
	int freq = count[i];
	char ch = i + 'a';
	
	for(i = 1; i < 26; i++)
	{
		if(freq < count[i])
		{
			freq = count[i];
			ch = i + 'a';
		}
	}	
	printf("The most frequent letter is '%c'. It appeared %d times.\n", ch, freq);
}	
return 0;
}

