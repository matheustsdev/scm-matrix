#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>

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

void getCooccurrenceMatrix(Matrix *cooccurrenceBuffer , int *firstMatrix, int *secondMatrix, int totalElementsInImg) {
    int i = 0, j = 0, sum = 0;
    int convertedIValue, convertedJValue, matrixIndex;

        for(i = 0; i < totalElementsInImg; i++) {
            convertedIValue = *(firstMatrix + i);
            convertedJValue = *(secondMatrix + i);

            matrixIndex = convertedIValue * cooccurrenceBuffer->column + convertedJValue;

            cooccurrenceBuffer->matrix[matrixIndex] += 1;  
        }
}

void initializeMatrix(Matrix *matrix, int initializedValue) {
    int i;

    for(i = 0; i < matrix->column * matrix->rows; i++) {
        *(matrix->matrix + i) = initializedValue;
    }
}

void saveVectorInFile(FILE *featureFile, Matrix *matrix){

    int position = 0;

    for(int i = 0; i < matrix->column * matrix->rows; i++){
        fprintf(featureFile, "%d, ", *(matrix->matrix + i)); 
    }

    fseeko(featureFile, -2, SEEK_END); 
    position = ftello(featureFile); 
    ftruncate(fileno(featureFile), position); 

}

double log2Function(double value) {
    return log(value)/log(2);
}