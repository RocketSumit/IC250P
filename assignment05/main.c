#include "my_library.h"

int main(int argc, char const *argv[]) {
        //struct sparse s1 = {0};
        double *sparse_matrix = NULL;

        int N, row_n, column_n;
        double B;

        printf("Enter the values of B and N: ");
        scanf("%lf%d",&B, &N);

        row_n = column_n = N;

        createSparse(&sparse_matrix, N, B);
        displayMatrix(sparse_matrix, row_n, column_n);
        //createTupple(sparse_matrix, &s1, row_n, column_n);
        //displayTupple(s1);

        return 0;
}
