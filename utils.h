// Matrix with pointer to its beginning and number of rows and columns.
typedef struct Matrix{
    int *matrix;
    int column;
    int rows;
} Matrix;

void strArraySort(char**, int);
void getFilesName(char**, char *);
int countFilesInDirectory(char *);
void getCooccurrenceMatrix(Matrix * , int*, int*, int);
void initializeMatrix(Matrix *, int );
void saveVectorInFile(FILE *, Matrix *);




