#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coefficients
{
        double b;
        double d;
        double a;
};

void createSparse(double **sparse_matrix, int N, struct coefficients c1);
void displayMatrix(double *sparse_matrix, int row_n, int column_n);
void create_array(double **main_diagonal, double ** below_diagonal, double **above_diagonal, double **r, int N, struct coefficients c1);
void displayArray(double *main_diagonal, double *below_diagonal, double *above_diagonal, double *r, int N);

#endif
