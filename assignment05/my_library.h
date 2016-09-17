#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>

struct sparse
{
        int *tupple;
        int no_of_tupples;
};

void createSparse(int **sparse_matrix, int row_n, int column_n);
void displayMatrix(int *sparse_matrix, int row_n, int column_n);
int count(int *sparse_matrix, int row_n, int column_n);
void createTupple(int *sparse_matrix, struct sparse *s1, int row_n, int column_n);
void displayTupple(struct sparse s1);


#endif
