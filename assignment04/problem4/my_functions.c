
#include "my_library.h"

int read_matrix(FILE *fptr, matx matrix1[], int row_cumu_frequency[], int column_cumu_frequency[]){

        int rows, columns, total_elements;
        fscanf(fptr, "%d %d\n", &rows, &columns);
        total_elements = rows*columns;

        int row_index = 1, column_index = 1, current, nonzero_element_count = 0;

        for (size_t i = 0; i < total_elements; i++) {
                fscanf(fptr, "%d",&current);

                if (current != 0) {
                        matrix1[nonzero_element_count].i = row_index;
                        matrix1[nonzero_element_count].j = column_index;
                        matrix1[nonzero_element_count].value = current;
                        nonzero_element_count++;
                }
                column_index++;
                if (column_index == (columns + 1)) {
                        row_cumu_frequency[row_index] = nonzero_element_count;
                        row_index++;
                        column_index = 1;
                }
        }

        int col_nonzero_element_count = 0; // counting the numbers of element in columns
        for (size_t i = 0; i < total_elements; i++) {
                for (size_t j = 0; j < total_elements; j++) {
                        if(matrix1[j].j == (i + 1)) {
                                col_nonzero_element_count++;
                        }
                }
                column_cumu_frequency[i + 1] = col_nonzero_element_count;
        }
        return nonzero_element_count;
}

int transpose(matx matrix1[], matx matrix2[], int column_cumu_frequency[], int nonzero_element_count)
{
        //copy the array of column frequency to other
        int transpose_column_elements[100] = {0};

        int column_index;
        for (size_t k = 0; k < nonzero_element_count; k++) {
                //find column index
                column_index =  column_cumu_frequency[matrix1[k].j - 1] + transpose_column_elements[matrix1[k].j];
                matrix2[column_index].i = matrix1[k].j;
                matrix2[column_index].j = matrix1[k].i;
                matrix2[column_index].value = matrix1[k].value;
                transpose_column_elements[matrix1[k].j]++;
        }
        return 0;
}
