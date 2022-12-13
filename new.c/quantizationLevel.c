#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// struct
// main

int main(int argc, char* argv[]){

    int quantization;
    
    if(argc != 2){
        puts("\n\tPut the quantization value.\n");
        exit(1);
    }

    quantization = atoi(argv[1]);

    if((ceil(log2(quantization)) == floor(log2(quantization)))){
        puts("Incorret value. The value must be power of 2.\n");
        exit(2);
    }

    if(quantization < 0){
        puts("Incorret value. The value must be bigger than zero.\n");
        exit(3);
    }

    if(quantization > 256){
        puts("Incorret value. The value must be smaller than 256.\n");
        exit(4);
    }

    return 0;
}