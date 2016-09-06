  #include "my_library.h"

int main(int argc, char const *argv[]) {

        FILE *fptr;
        fptr = fopen("/Users/sumitpatidar/Desktop/data.txt", "r");
        matx matrix1[100];
        matx matrix2[100];

        int row_cumu_frequency[100] = {0};
        int column_cumu_frequency[100] = {0};
        int nonzero_elements;

        //read the matrix and store cumulative frequency of row and column elements in arrays
        nonzero_elements = read_matrix(fptr, matrix1, row_cumu_frequency, column_cumu_frequency);

        //do transpose
        transpose(matrix1, matrix2, column_cumu_frequency, nonzero_elements);

        fclose(fptr);
        return 0;
}
