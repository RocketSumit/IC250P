/*........................................
   Name : Sumit Patidar
   Roll no : B15237
   Purpose : IC250 assignment 04, Q4
   Date : 07/09/16
   .........................................*/

#include "my_library.h"

//function to read sparse matrix
int read_matrix(matx matrix1[], int row_cumu_frequency[], int column_cumu_frequency[], int total_elements, int rows, int columns){

        int row_index = 1, column_index = 1, current, nonzero_element_count = 0;

        printf("Enter elements one by one\n");

        for (size_t i = 0; i < total_elements; i++) {
                scanf("%d",&current);

                //store nonzero element in list.
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

//function to do transpose of known matrix
int transpose(matx matrix1[], matx matrix2[], int column_cumu_frequency[], int nonzero_element_count, int transpose_column_elements[])
{

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

//function to get the i,j element of matrix
int getElement(int row_position, int column_position, matx matrix[],int row_cumu_frequency[]){

        if(row_cumu_frequency[row_position] == 0)
                return 0;

        int no_of_elements_in_row = row_cumu_frequency[row_position] - row_cumu_frequency[row_position - 1];

        int current_matrix_position = row_cumu_frequency[row_position - 1];
        for (size_t i = 0; i < no_of_elements_in_row; i++) {
                if(matrix[current_matrix_position ].j == column_position)
                        return matrix[current_matrix_position].value;
                current_matrix_position++;
        }
        return 0;
}
