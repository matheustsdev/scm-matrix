
#include <unistd.h>
#include <sys/types.h>


typedef struct{
    
    int *pmatrix;
    int c;
    int r;

}cooccurrenceMatrix;

void saveVector(FILE *featureFile, cooccurrenceMatrix *mat){

    int pos = 0;

    for(int i = 0; i < mat->c * mat->r; i++){
        fprintf(featureFile, "%d, ", *(mat->pmatrix + i)); 
    }

    fseeko(featureFile, -2, SEEK_END); 
    pos = ftello(featureFile); 
    ftruncate(fileno(featureFile), pos); 

    putc('\n', featureFile);
}
