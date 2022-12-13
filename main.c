#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "pgm.h"
#include "scm.h"
#include "utils.h"

#define DIR_NAME "./images/"

int main(int argc, char* argv[]) {
    DIR *d;
    FILE *featureFile, *readPGMImagesOrder;
    struct dirent *dir;
    struct pgm pgmImg, meanPgmImg;
    Matrix pgmDataMatrix, *pgmMeanDataMatrix, cooccurrenceMatrix;
    clock_t timestampBegin, timestampEnd;

    int count = 0, i, j, k, tempInt;
    int quantizationLevel;
    int *quantizedMatrix, *meanQuantizedMatrix;

    double timePerImage, totalTime = 0;

    char pathName[526];
    char **fileNamesList;
    char *txtFile = "_quantization.txt";
    char *featureFileName = strcat(argv[1], txtFile);
    char fileType;


    // Start program validation

    if(argc != 2){
        puts("\n\tPut the quantization value.\n");
        exit(1);
    }

    quantizationLevel = atoi(argv[1]);

    if((ceil(log2(quantizationLevel)) != floor(log2(quantizationLevel)))){
        puts("Incorret value. The value must be power of 2.\n");
        exit(2);
    }

    if(quantizationLevel < 0){
        puts("Incorret value. The value must be bigger than zero.\n");
        exit(3);
    }

    if(quantizationLevel > 256){
        puts("Incorret value. The value must be smaller than 256.\n");
        exit(4);
    }

    // End validation

    count = countFilesInDirectory(DIR_NAME);

    fileNamesList = (char**) malloc(sizeof(char*) * count);

    for(i = 0; i < count; i++) {
        fileNamesList[i] = (char*) malloc(sizeof(char) * 128);
    }
    
    getFilesName(fileNamesList, DIR_NAME);

    // Bubble sort
    strArraySort(fileNamesList, count);

    featureFile = fopen(featureFileName, "w");

    if(featureFile == NULL){
        puts("File open error: save data to a text file.");
        exit(1);
    }

    if (!(readPGMImagesOrder = fopen("readPGMImagesOrder.txt","w"))){
        perror("Erro.");
        exit(1);
	}

    cooccurrenceMatrix.rows = quantizationLevel;
    cooccurrenceMatrix.column = quantizationLevel;

    // Read files and operation
    for(i = 0; i < count; i++) {
        timestampBegin = clock();

        printf("\nName: %s\n", fileNamesList[i]);

        fprintf(readPGMImagesOrder, "%s\n", *(fileNamesList+i));

        sprintf(pathName, "%s%s", DIR_NAME, fileNamesList[i++]);
        readPGMImage(&pgmImg, pathName);

        fprintf(readPGMImagesOrder, "%s\n", *(fileNamesList+i));

        sprintf(pathName, "%s%s", DIR_NAME, fileNamesList[i]);
        readPGMImage(&meanPgmImg, pathName);

        quantizedMatrix = (int*) malloc(sizeof(int) * pgmImg.c * pgmImg.r);
        meanQuantizedMatrix = (int*) malloc(sizeof(int) * meanPgmImg.c * meanPgmImg.r);

        quantizationMatrix(quantizedMatrix, pgmImg, quantizationLevel);
        quantizationMatrix(meanQuantizedMatrix, meanPgmImg, quantizationLevel);

        cooccurrenceMatrix.matrix = (int*) malloc(sizeof(int) * quantizationLevel * quantizationLevel);

        initializeMatrix(&cooccurrenceMatrix, 0);

        getCooccurrenceMatrix(&cooccurrenceMatrix, quantizedMatrix, meanQuantizedMatrix, pgmImg.r * pgmImg.c);

        fileType = fileNamesList[i][0];

        saveVectorInFile(featureFile, &cooccurrenceMatrix);
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

	printf("Tempo médio: %lf\n", totalTime / count);
	printf("Tempo Total: %lf\n", totalTime);
    
    free(fileNamesList);

    fclose(featureFile);
    fclose(readPGMImagesOrder);

    return 0;
}


