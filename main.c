#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pgm.h"
#include "scm.h"
#include "utils.h"

#define DIR_NAME "./images/"

int main(void) {
    DIR *d;
    struct dirent *dir;
    struct pgm pgmImg, meanPgmImg;

    Matrix pgmDataMatrix, *pgmMeanDataMatrix, cooccurrenceMatrix;
    int count = 0, i, j, k, tempInt;
    int quantizationLevel = 8;
    int *quantizedMatrix, *meanQuantizedMatrix;

    char pathName[526];
    char **fileNamesList;

    count = countFilesInDirectory(DIR_NAME);

    fileNamesList = (char**) malloc(sizeof(char*) * count);

    for(i = 0; i < count; i++) {
        fileNamesList[i] = (char*) malloc(sizeof(char) * 128);
    }
    
    getFilesName(fileNamesList, DIR_NAME);

    // Bubble sort
    strArraySort(fileNamesList, count);

    // Read files and operation
    for(i = 0; i < 1; i++) {
        sprintf(pathName, "%s%s", DIR_NAME, fileNamesList[i++]);
        readPGMImage(&pgmImg, pathName);

        printf("%s\n", pathName);

        sprintf(pathName, "%s%s", DIR_NAME, fileNamesList[i++]);
        readPGMImage(&meanPgmImg, pathName);

        printf("%s\n", pathName);

        quantizedMatrix = (int*) malloc(sizeof(int) * pgmImg.c * pgmImg.r);
        meanQuantizedMatrix = (int*) malloc(sizeof(int) * meanPgmImg.c * meanPgmImg.r);

        quantizationMatrix(quantizedMatrix, pgmImg, quantizationLevel);
        quantizationMatrix(meanQuantizedMatrix, meanPgmImg, quantizationLevel);

        cooccurrenceMatrix.matrix = (int*) malloc(sizeof(int) * quantizationLevel * quantizationLevel);
        cooccurrenceMatrix.rows = quantizationLevel;
        cooccurrenceMatrix.column = quantizationLevel;

        initializeMatrix(cooccurrenceMatrix, 0);

        getCooccurrenceMatrix(cooccurrenceMatrix, quantizedMatrix, meanQuantizedMatrix, pgmImg.r);
    }

    // Iniciar medição do tempo. 

    // Leitura da Imagem -PGM

    // Processar
            
    // Saída - Salvar matriz vetorizada no arquivo de características

    // Finalizar medição do tempo.

    // Acumular tempo medido. 

    // Calcular tempo médio por imagem.

    return 0;
}


