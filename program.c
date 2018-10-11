#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program.h"

void calculateRowsAndCols(const char *paramInput){

	int numberOfFiles = 0, rows, cols;
    FILE *countFile, *listFile;
    char fileName[30], cmd[30], input[30];

    // ADD ARGV CHECKS!

    sprintf(cmd, "ls %s | wc -l > fileInfo.txt", paramInput);
	printf("2\n");
    system("touch fileInfo.txt");
	printf("3\n");
    system(cmd);
	printf("4\n");

    //open the created file and read content
    countFile = fopen("fileInfo.txt", "r");
	printf("5\n");
    fscanf(countFile, "%d", &numberOfFiles);
	printf("6\n");
    printf("Number of files in folder: %d\n", numberOfFiles);

    sprintf(cmd, "ls %s > fileInfo.txt", paramInput);
    system(cmd);

    for(int i = 0; i < numberOfFiles; i++) {
        //overwriting the the filenames until the last name is left
        fscanf(countFile, "%s", fileName);
    }

    // converting char to int by subtracting the ASCII-value of 0 (48).
    cols = (fileName[5] - '0') + 1;
    rows = numberOfFiles / cols;


    printf("The last file in the folder: %s\n", fileName);
    printf("Cols in grid: %d\n", cols);
    printf("Rows in grid: %d\n", rows);

    fclose(countFile);
    //system("rm fileInfo.txt");

	printAsciiArt(rows, 30, paramInput);
}

/**
 * @brief 
 * 
 * @param numRows 
 * @param paramInput 
 */
void printAsciiArt(int numRows, int numCharsPerRow, char* paramInput){

	char filename1[35], filename2[35], filename3[35], fileLine1[30], 
			fileLine2[30], fileLine3[30], resultFilePath[50];

	FILE *file1, *file2, *file3, *resultFile;
	
	//concatinating resultFilePath with given param as input and opens the file
	sprintf(resultFilePath, "./mergedResults/%s_result.txt", paramInput);
	resultFile = fopen(resultFilePath, "w+");
	
	//printing content char by char
	for(int y = 0; y < numRows; y++) {
	
		int x = 0;
		
		//concatinating file paths
		sprintf(filename1, "./%s/part_%d_%d_%s.txt", paramInput, x, y, paramInput);
		sprintf(filename2, "./%s/part_%d_%d_%s.txt", paramInput, x + 1, y, paramInput);
		sprintf(filename3, "./%s/part_%d_%d_%s.txt", paramInput, x + 2, y, paramInput);
		
		//opening files	
		file1 = fopen(filename1, "r");
		file2 = fopen(filename2, "r");
		file3 = fopen(filename3, "r");
			
		if(!file1 || !file2 || !file3) {
		
			printf("ERROR! Cannot open file");
			return;
		}
		
		for (int row = 0; row < 30; row++){
		
			for (int i = 0; i < numCharsPerRow; i++) {
			
				fscanf(file1, "%c", &fileLine1[i]);
				fscanf(file2, "%c", &fileLine2[i]);
				fscanf(file3, "%c", &fileLine3[i]);
				
			}
			
			fprintf(resultFile, "%s%s%s\n", fileLine1, fileLine2, fileLine3);
		}
		
		//closing files
		fclose(file1);
		fclose(file2);
		fclose(file3);
	}
	
	//closing result files
	fclose(resultFile);

	printf("Merging complete, please open '%s' to see the result!\n", resultFilePath);

}
