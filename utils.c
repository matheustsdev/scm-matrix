#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pgm.h"
#include "utils.h"
#include "scm.h"

// Bubble sort
void strArraySort(char **strArray, int size) {
    char temp[256];

    for(int i = 0; i < size; i++)

      for(int j = 0; j < size - 1; j++){

         if(strcmp(strArray[i],strArray[j]) < 0){
            strcpy(temp,strArray[i]);
            strcpy(strArray[i],strArray[j]);
            strcpy(strArray[j],temp);
         }
      }
}

void getFilesName(char **fileNamesArray, char *relativePath) {
    DIR *d;
    int count = 0, i = 0, j = 0;
    struct dirent *dir;
    char temp[128];

    d = opendir(relativePath);
     
    if (d) {
       while ((dir = readdir(d)) != NULL ) {
            if(strlen(dir->d_name) > 2) {
                strcpy(fileNamesArray[i], dir->d_name);

                i++;
            }
        }

    closedir(d);

    }
}

int countFilesInDirectory(char *relativePath) {
    DIR *d;
    int count = 0;
    struct dirent *dir;

    d = opendir(relativePath);
     
    if (d) {
        while ((dir = readdir(d)) != NULL ) {
            if(strlen(dir->d_name) > 2) {
                count++;
            }
        }
    }
    closedir(d);

    return count;
}

void matrixAtoiQuantization(Matrix *convertedMatrix, struct pgm pgmImg, int quantizationLevel) {
    char *splittedString;
    int tempInt, j, k;
    struct pgm copyImg = pgmImg;

    printf("Atoi");

    // Get row to split
    for(j = 0; j < pgmImg.r; j++) {
        k = 0;

        // Split string add in int matrix
        while(splittedString != NULL) {
            // splittedString = strtok(copyImg.pData[j], " ");
            printf("%d\n", copyImg.pData[1]);

            tempInt = atoi(splittedString);

            *(convertedMatrix->matrix + k) = quantizationValue(tempInt, quantizationLevel);
        }
    }
}

void getCooccurrenceMatrix(Matrix cooccurrenceBuffer , int *firstMatrix, int *secondMatrix, int pgmSquareSize) {
    int i, j, sum = 0;
    int convertedIValue, convertedJValue, matrixIndex;

        for(i = 0; i < pgmSquareSize * pgmSquareSize; i++) {
            convertedIValue = *(firstMatrix + i);
            convertedJValue = *(secondMatrix + i);

            matrixIndex = convertedIValue * cooccurrenceBuffer.column + convertedJValue;

            cooccurrenceBuffer.matrix[matrixIndex] += 1;  
        }

        puts("\n");

        for(i = 0; i < cooccurrenceBuffer.rows; i++) {
        for( j = 0; j < cooccurrenceBuffer.column; j++) {
            matrixIndex = i * cooccurrenceBuffer.column + j;

            sum += *(cooccurrenceBuffer.matrix + matrixIndex);

            printf("%d ", *(cooccurrenceBuffer.matrix + matrixIndex));
        }
        puts("\n");
      }
}

void initializeMatrix(Matrix matrix, int initializedValue) {
    int i;

    for(i = 0; i < matrix.column * matrix.rows; i++) {
        *(matrix.matrix + i) = initializedValue;
    }
}