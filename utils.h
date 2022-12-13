// Matrix with pointer to its beginning and number of rows and columns.
typedef struct Matrix{
    int *matrix;
    int column;
    int rows;
} Matrix;

// Array with pointer to its beginning and its length.
typedef struct {
    int length;
    int *array;
} Array;


void strArraySort(char**, int);
void getFilesName(char**, char *);
int countFilesInDirectory(char *);
//void matrixAtoiQuantization(Matrix *, struct pgm,int );
void getCooccurrenceMatrix(Matrix * , int*, int*, int);
void initializeMatrix(Matrix *, int );
void saveVectorInFile(FILE *, Matrix *);
double log2Function(double);




