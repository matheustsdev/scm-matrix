#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pgm.h"
#include "utils.h"

#define DIR_NAME "./images/"

int main(void) {
    DIR *d;
    char *dirName = "./images", pathName[526];
    int count = 0, i = 0;
    char **fileNamesList;
    struct dirent *dir;
    struct pgm img;

    count = countFilesInDirectory(DIR_NAME);

    fileNamesList = (char**) malloc(sizeof(char*) * count);

    for(i = 0; i < count; i++) {
        fileNamesList[i] = (char*) malloc(sizeof(char) * 128);
    }
    
    getFilesName(fileNamesList, DIR_NAME);

    // Bubble sort
    strArraySort(fileNamesList, count);

    for(i = 0; i < count; i++) {
        printf("%s\n", fileNamesList[i]);
        sprintf(pathName, "%s%s", DIR_NAME, fileNamesList[i]);
        readPGMImage(&img, pathName);
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
