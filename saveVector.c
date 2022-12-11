#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct{
    
    int *matrix;
    int column;
    int rows;

}cooccurrenceMatrix;

void matrixTest(int *, int , int);
void saveVector(FILE *, int *, int , int);

int main(){

    srand(time(NULL));
    
    int numFiles = 5; // number of files

    cooccurrenceMatrix x[numFiles];

    //creat file 

    FILE *featureFile;

    char *value = argv[1];
    char txtFile[] = "_quantization.txt";

    char *name = strcat(value, txtFile);

    featureFile = fopen(name, "w"); 
    if(featureFile == NULL){
        puts("File open error: save data to a text file.");
        exit(1);
    }

    for(int h=0; h<numFiles; h++){
        x[h].column = 5;
        x[h].rows = 4;
    }

    for(int g = 0; g<numFiles; g++){

        x[g].matrix = NULL;
        if(!(x[g].matrix = malloc(x[g].rows * x[g].column * sizeof(int)) )){
            puts("Not enough memory");
            exit(2);
        }

        matrixTest(x[g].matrix, (x[g].column), (x[g].rows)); 
    }

    for(int j = 0; j<numFiles; j++){
        saveVector(featureFile, x[j].matrix, x[j].rows, x[j].column);
    }

    fclose(featureFile);

    for(int m = 0; m<numFiles; m++){
        free(x[m].matrix);
    }

    return 0;
}
//just-test
void matrixTest(int *matriz, int rows, int column){

    printf("\n\tnumeros q eram pra ser gravados:\n");

    for(int k=0; k<rows*column;k++){
        *(matriz+k) = 0 + rand() % 5;
        printf("%d-", *(matriz+k));
    }
    puts("\n");
}

void saveVector(FILE *featureFile, int *matrix, int rows, int column){

    int pos = 0;

    for(int i = 0; i < column*rows; i++){
        fprintf(featureFile, "%d, ", *(matrix + i)); // convert integer to string
    }

    fseeko(featureFile, -2, SEEK_END); // change file position 
    pos = ftello(featureFile); //get position value
    ftruncate(fileno(featureFile), pos); //delete 

    putc('\n', featureFile);
}

