// #include <stdlib.h>
// struct
// main

int main(int argc, char* argv[]){

    unsigned int quantization;
    
    if(argc != 2){
        printf("\n\tPut the quantization value.\n");
        exit(1);
    }

    quantization = atoi(argv[1]);

    if(quantization % 2 != 0){
        printf("Incorret value. The value must be pair.");
        exit(2);
    }

    if(quantization < 0){
        printf("Incorret value. The value must be bigger than zero.");
        exit(3);
    }

    if(quantization > 256){
        printf("Incorret value. The value must be smaller than 256.");
        exit(4);
    }

    return 0;
}