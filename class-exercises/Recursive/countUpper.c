//Count the number of uppercase characters in a paragraph

//1. Fix the program so it executes correctly
//2. Add a structure containing the variables (char * and int)
//3. Add a count and display the total number of spaces
//4. Add a count and display the total number of digits


#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(void) {

	//variables
	char* s;		//holds the input string from the user
	int countU = 0;		//counter for the number of uppercase chars

	//allocate space and test if successful
	if((s = malloc(100)) == NULL) {
		printf("malloc failed\n\n");
		exit(1);	//exit the program
	}

	//prompt the user
	printf("Enter a paragraph: ");
	scanf("%s", &s);

	//read character by character
	for (int i = 0; s[i] != '\n'; i++) {
		if (isupper(s[i])
			countU++;
	}

	//free allocated space
	free(s);

	printf("The number of uppercase chars is: %d\n", countU);

	return 0;
}