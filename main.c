#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "pgm.h"
#include "utils.h"

#define DIR_NAME "./images/"

int main(int argc, char* argv[]) {
    FILE *featureFile, *readPGMImagesOrder;
    struct pgm pgmImg, meanPgmImg;
    Matrix pgmDataMatrix, *pgmMeanDataMatrix, cooccurrenceMatrix;
    clock_t timestampBegin, timestampEnd;

    int filesCount = 0, i, j;
    int quantizationLevel;
    int *quantizedMatrix, *meanQuantizedMatrix;

    double timePerImage, totalTime = 0;

    char pathName[526];
    char **fileNamesList;
    char *sufixNameTxtFile = "_quantization.txt";
    char *featureFileName = strcat(argv[1], sufixNameTxtFile);
    char fileType;

    // Start quantization level validation region

    if(argc != 2){
        puts("\n\tPut the quantization value.\n");
        exit(1);
    }

    quantizationLevel = atoi(argv[1]);

    if(quantizationLevel < 0){
        puts("Incorret value. The value must be bigger than zero.\n");
        exit(2);
    }

    if(quantizationLevel > 256){
        puts("Incorret value. The value must be smaller than 256.\n");
        exit(3);
    }
    
    // Verify if number is a power of 2
    if((ceil(log2(quantizationLevel)) != floor(log2(quantizationLevel)))){
        puts("Incorret value. The value must be power of 2.\n");
        exit(4);
    }

    // End quantization level validation region

    filesCount = countFilesInDirectory(DIR_NAME);

    // Alloc memory for list
    fileNamesList = (char**) malloc(sizeof(char*) * filesCount);

    // Alloc memory for EACH string in the list
    for(i = 0; i < filesCount; i++) {
        fileNamesList[i] = (char*) malloc(sizeof(char) * 128);
    }
    
    getFilesName(fileNamesList, DIR_NAME);

    // Ordering file names
    strArraySort(fileNamesList, filesCount);

    // Begin of open files region

    featureFile = fopen(featureFileName, "w");

    if(featureFile == NULL){
        puts("File open error: save data to a text file.");
        exit(1);
    }
    
    readPGMImagesOrder = fopen("readPGMImagesOrder.txt","w");

    if (readPGMImagesOrder == NULL){
        puts("File open error: save data to a text file.");
        exit(2);
	}
    
    // End of open files region

    cooccurrenceMatrix.rows = quantizationLevel;
    cooccurrenceMatrix.column = quantizationLevel;

    // Read files and operation
    for(i = 0; i < filesCount; i++) {
        timestampBegin = clock();

        printf("\nName: %s\n", fileNamesList[i]);

        fprintf(readPGMImagesOrder, "%s\n", *(fileNamesList+i));
        
        // Create a relative path to standart image
        sprintf(pathName, "%s%s", DIR_NAME, fileNamesList[i++]);
        readPGMImage(&pgmImg, pathName);

        fprintf(readPGMImagesOrder, "%s\n", *(fileNamesList+i));

        sprintf(pathName, "%s%s", DIR_NAME, fileNamesList[i]);
        readPGMImage(&meanPgmImg, pathName);

        // Alloc memory to quantization
        quantizedMatrix = (int*) malloc(sizeof(int) * pgmImg.c * pgmImg.r);
        meanQuantizedMatrix = (int*) malloc(sizeof(int) * meanPgmImg.c * meanPgmImg.r);

        quantizationMatrix(quantizedMatrix, pgmImg, quantizationLevel);
        quantizationMatrix(meanQuantizedMatrix, meanPgmImg, quantizationLevel);

        cooccurrenceMatrix.matrix = (int*) malloc(sizeof(int) * quantizationLevel * quantizationLevel);

        initializeMatrix(&cooccurrenceMatrix, 0);

        // Create the cooccurrence matrix
        getCooccurrenceMatrix(&cooccurrenceMatrix, quantizedMatrix, meanQuantizedMatrix, pgmImg.r * pgmImg.c);

        // Get label of images
        fileType = fileNamesList[i][0];

        // Save the matrix in list format
        saveVectorInFile(featureFile, &cooccurrenceMatrix);
        
        // Add the label in the file
        fprintf(featureFile, ", %c\n", fileType);
        
        putc('\n', readPGMImagesOrder);

        timestampEnd = clock();

        timePerImage = (double) (timestampEnd - timestampBegin) / CLOCKS_PER_SEC;
        totalTime += timePerImage;

        free(quantizedMatrix);
        free(meanQuantizedMatrix);
        free(cooccurrenceMatrix.matrix);
    }

    puts("\n"); 

	printf("Tempo médio: %lf\n", totalTime / filesCount);
	printf("Tempo Total: %lf\n", totalTime);
    
    free(fileNamesList);

    fclose(featureFile);
    fclose(readPGMImagesOrder);

    return 0;
}


