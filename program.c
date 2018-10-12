#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program.h"

void printAsciiArt(int numRows, char* paramInput){

	char *filename1, *filename2, *filename3, *fileLine1, 
			*fileLine2, *fileLine3, *resultFilePath;

	int resultFilePathLength = strlen(paramInput) + 26;
	int filenameLength = (2 * strlen(paramInput)) + 17;

	filename1 = malloc(filenameLength * sizeof(char));
	filename2 = malloc(filenameLength * sizeof(char));
	filename3 = malloc(filenameLength * sizeof(char));
	fileLine1 = malloc(31 * sizeof(char));
	fileLine2 = malloc(31 * sizeof(char));
	fileLine3 = malloc(31 * sizeof(char));

	resultFilePath = malloc(resultFilePathLength * sizeof(char));

	if(!filename1 || !filename2 || !filename3 || !fileLine1 || !fileLine2 || !fileLine3 || !resultFilePath) {
		printf("ERROR! cannot allocate memory..");
		return;
	}

	FILE *file1, *file2, *file3, *resultFile;
	
	//concatinating resultFilePath with given param as input and opens the file
	snprintf(resultFilePath, resultFilePathLength, "./mergedFiles/%s_result.txt", paramInput);
	
	resultFile = fopen(resultFilePath, "w+");
	
	//printing content char by char
	for(int y = 0; y < numRows; y++) {
	
		int x = 0;
		
		//concatinating file paths
		snprintf(filename1, filenameLength, "./%s/part_%d_%d_%s.txt", paramInput, x, y, paramInput);
		snprintf(filename2, filenameLength, "./%s/part_%d_%d_%s.txt", paramInput, x + 1, y, paramInput);
		snprintf(filename3, filenameLength, "./%s/part_%d_%d_%s.txt", paramInput, x + 2, y, paramInput);
		
		//opening files	
		file1 = fopen(filename1, "r");
		file2 = fopen(filename2, "r");
		file3 = fopen(filename3, "r");
			
		if(!file1 || !file2 || !file3) {
		
			printf("ERROR! Cannot open file");
			return;
		}
		
		for (int row = 0; row < 30; row++){
		
			for (int i = 0; i < 30; i++) {
			
				fscanf(file1, "%c", &fileLine1[i]);
				fscanf(file2, "%c", &fileLine2[i]);
				fscanf(file3, "%c", &fileLine3[i]);
				
			}

			fileLine1[30] = '\0';
			fileLine2[30] = '\0';
			fileLine3[30] = '\0';

			fprintf(resultFile, "%s%s%s\n", fileLine1, fileLine2, fileLine3);
		}
		
		//closing files
		fclose(file1);
		fclose(file2);
		fclose(file3);
	}

	free(filename1);
	free(filename2);
	free(filename3);

	free(fileLine1);
	free(fileLine2);
	free(fileLine3);
	
	//closing result files
	
	fclose(resultFile);
	
	printf("Merging complete, please open '%s' to see the result!\n", resultFilePath);
	free(resultFilePath);

}
