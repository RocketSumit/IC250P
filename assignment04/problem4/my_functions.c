
#include "my_library.h"

int read_matrix(FILE *fptr, matx matrix1[]){

        int rows, columns, total_elements;
        fscanf(fptr, "%d %d\n", &rows, &columns);
        total_elements = rows*columns;

        int row_index = 1, column_index = 1, current, element_count = 0;
        int row_cumu_frequency[rows];

        for (size_t i = 0; i < total_elements; i++) {
                fscanf(fptr, "%d",&current);

                if (current != 0) {
                        matrix1[element_count].i = row_index;
                        matrix1[element_count].j = column_index;
                        matrix1[element_count].value = current;
                        element_count++;
                }
                column_index++;
                if (column_index == (columns + 1)) {
                        row_cumu_frequency[row_index - 1] = element_count;
                        row_index++;
                        column_index = 1;
                }
        }
        return 0;
}
