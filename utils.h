//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
//∗ Aluno : Matheus Teixeira, Livia Leite, Yaslly Guimarães
//∗ M a t r i c u l a : 20221045050303, 20221045050257, 20221045050591
//∗ A v a l i a c a o 0 4 : Trabalho F i n a l
//∗ 0 4 . 5 0 5 . 2 3 − 2 0 2 2 . 2 − P r o f . D a n i e l F e r r e i r a 
//∗ Compilador : gcc | v e r s a o:  11.3.0
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗

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




