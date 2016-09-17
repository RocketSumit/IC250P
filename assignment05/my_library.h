#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>

struct sparse
{
        double *tupple;
        int no_of_tupples;
};

void createSparse(double **sparse_matrix, int N, double B);
void displayMatrix(double *sparse_matrix, int row_n, int column_n);
int count(double *sparse_matrix, int row_n, int column_n);
void createTupple(double *sparse_matrix, struct sparse *s1, int row_n, int column_n);
void displayTupple(struct sparse s1);


#endif
