#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct{
    
    int *pmatrix;
    int column;
    int rows;

}cooccurrenceMatrix;

void matrixTest(cooccurrenceMatrix *);
void saveVector(FILE *, cooccurrenceMatrix *);

int main(){

    srand(time(NULL));
    
    cooccurrenceMatrix x;

    FILE *featureFile;

    // char *value = argv[1];
    // char typeFile[18] = "_quantization.txt";

    // char *name = strcat(value, typeFile);

    char name[] = "8_quantization.txt"; //just test

    featureFile = fopen(name, "w"); 
    if(featureFile == NULL){
        puts("File open error: save data to a text file.");
        exit(1);
    }

    matrixTest(&x);

    saveVector(featureFile, &x);

    fclose(featureFile);

    free(x.pmatrix);

    return 0;
}
//just test
void matrixTest(cooccurrenceMatrix *mat){

    mat->column = 5;
    mat->rows = 4;

    if(!(mat->pmatrix = malloc((mat->rows * mat->column) * sizeof(int)) )){
        puts("Not enough memory");
    }

    printf("\n\tnumeros q eram pra ser gravados:\n");

    for(int k=0; k<x->rows*x->column;k++){
        *(x->matrix+k) = 0 + rand() % 5;
        printf("%d-", *(x->matrix+k));
    }
    puts("\n");

}

void saveVector(FILE *featureFile, cooccurrenceMatrix *x){

    int position = 0;

    for(int i = 0; i < x->column * x->rows; i++){
        // if(i != (x->column * x->rows-1)) {
        fprintf(featureFile, "%d, ", *(x->matrix + i)); 
    }

    fseeko(featureFile, -2, SEEK_END); 
    position = ftello(featureFile); 
    ftruncate(fileno(featureFile), position); 

    putc('\n', featureFile);
}

