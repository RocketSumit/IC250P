#ifndef  MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct matrixElements {
        int i;
        int j;
        int value;
}matx;
int row_cumu_frequency[100];
int read_matrix(FILE *fptr, matx matrix1[]);

#endif
