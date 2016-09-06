  #include "my_library.h"

int main(int argc, char const *argv[]) {

        FILE *fptr;
        fptr = fopen("/Users/sumitpatidar/Desktop/data.txt", "r");
        int rows, columns, total_elements;
        fscanf(fptr, "%d %d\n", &rows, &columns);

        total_elements = rows*columns;
        matx matrix1[100];
        matx matrix2[100];

        int row_cumu_frequency[100] = {0};
        int column_cumu_frequency[100] = {0};
        int transpose_column_elements[100] = {0};
        int nonzero_elements;

        //read the matrix and store cumulative frequency of row and column elements in arrays
        nonzero_elements = read_matrix(fptr, matrix1, row_cumu_frequency, column_cumu_frequency, total_elements, rows, columns);

        //do transpose
        transpose(matrix1, matrix2, column_cumu_frequency, nonzero_elements, transpose_column_elements);

        FILE *fptr2 = fopen("/Users/sumitpatidar/Desktop/transpose.txt", "w");
        int current_transpose_element;

        fprintf(fptr2, "%d\t%d\n", columns, rows);

        for (size_t i = 1; i <= columns; i++) {
                for (size_t j = 1; j <= rows; j++) {
                        current_transpose_element = getElement(i, j, matrix2, column_cumu_frequency);
                        fprintf(fptr2, "%d\t", current_transpose_element);
                }
                fprintf(fptr2, "\n");
        }

        fclose(fptr);
        fclose(fptr2);

        return 0;
}