#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program.h"

int main(int argc, char* argv[]){

	char *paramInput;
	int numRows = 0;

	paramInput = malloc(25 * sizeof(char));
	
	//setting max iterations based on the users input
	if (argv[1] == NULL || argc != 2 ) {
	
		printf("ERROR! Missing param!\n");
		printf("Allowed params are: 'wolf' or 'mickey'\n");
		return -1;
	} 
    
	strcpy(paramInput, argv[1]);
	
    if(!strcmp(paramInput, "wolf")) {
		
		numRows = 5;
			
	} else if (!strcmp(paramInput, "mickey")) {
			
		numRows = 2;
			
	} else {
		
		printf("ERROR!! wrong param!\n");
		printf("Allowed params are: 'wolf' or 'mickey'\n");
		return -1;
		
	}

	printAsciiArt(numRows, paramInput);

	free(paramInput);
	return 0;
}