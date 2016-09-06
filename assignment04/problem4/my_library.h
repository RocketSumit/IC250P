#ifndef  MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct matrixElements {
        int i;
        int j;
        int value;
}matx;

int read_matrix(FILE *fptr, matx matrix1[], int row_cumu_frequency[], int column_cumu_frequency[]);
int transpose(matx matrix1[], matx matrix2[], int column_cumu_frequency[], int nonzero_element_count);


#endif
