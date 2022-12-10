#include <stdio.h>

// Matrix with pointer to its beginning and number of rows and columns.
typedef struct {
    int *matrix;
    int column;
    int rows;
} cooccurrenceMatrix;

// Array with pointer to its beginning and its length.
typedef struct {
    int length;
    int *array;
} Array;
