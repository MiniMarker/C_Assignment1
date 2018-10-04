#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program.h"

int main(int argc, char* argv[]){
	
	char paramInput[10];
	int numRows = 0, numCharsPerRow = 0;
	
	//setting max iterations based on the users input
	if (argv[1] == NULL || argc != 2 ) {
	
		printf("ERROR! Missing param!\n");
		printf("Allowed params are: 'wolf' or 'mickey'\n");
		return -1;
	
	} else {

		strcpy(paramInput, argv[1]);
	
		if(!strcmp(paramInput, "wolf")) {
			
			numRows = 5;
			numCharsPerRow = 30;
			
		} else if (!strcmp(paramInput, "mickey")) {
			
			numRows = 2;
            numCharsPerRow = 30;
			
		} else {
		
			printf("ERROR!! wrong param!\n");
			printf("Allowed params are: 'wolf' or 'mickey'\n");
			return -1;
			
		}
	}

	printAsciiArt(numRows, numCharsPerRow, paramInput);
	return 0;
}