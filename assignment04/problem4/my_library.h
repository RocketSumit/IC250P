/*........................................
   Name : Sumit Patidar
   Roll no : B15237
   Purpose : IC250 assignment 04, Q4
   Date : 07/09/16
   .........................................*/
#ifndef  MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct matrixElements {
        int i;
        int j;
        int value;
}matx;

int read_matrix(matx matrix1[], int row_cumu_frequency[], int column_cumu_frequency[], int total_elements, int rows, int columns);
int transpose(matx matrix1[], matx matrix2[], int column_cumu_frequency[], int nonzero_element_count, int transpose_column_elements[]);
int getElement(int row_position, int column_position, matx matrix[],int row_cumu_frequency[]);

#endif
