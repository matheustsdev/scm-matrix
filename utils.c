#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pgm.h"
#include "utils.h"

// Bubble sort
void strArraySort(char **strArray, int size) {
    printf("bubble");

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

    printf("%p\n", &fileNamesArray);
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