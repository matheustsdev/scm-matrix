#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matriz(int *p, int l, int c);
void quantizationMatriz(int *matrix, int quantization, int rows, int columns);

int main(){

    int *m = NULL;
    unsigned int quantization = 8;
    int l = 4;
    int c = 4;

    m = (int*)malloc(l * c * sizeof(int));

    matriz(m, l, c);

    quantizationMatriz(m, quantization, l, c);

    return 0;
}

void matriz(int *p, int l, int c){
    srand(time(NULL));
    for(int i = 0; i < l * c; i++){
        *(p+i) = 0 + rand() % 256;
        printf("%d ", *(p+i));
    }
    printf("\n");
}


void quantizationMatriz(int *matrix, int quantization, int rows, int column){
    for(int i = 0; i < rows * column; i++){
        *(matrix+i) = *(matrix+i) / (256/quantization);
        printf("%d ", *(matrix+i));
    }
}