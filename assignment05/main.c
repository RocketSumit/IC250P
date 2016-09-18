#include "my_library.h"

int main(int argc, char const *argv[]) {
        double *sparse_matrix = NULL;

        int N, row_n, column_n;
        double B;

        printf("Enter the value of N: ");
        scanf("%d", &N);
        printf("Enter the value of B: ");
        scanf("%lf", &B);

        struct coefficients c1 = {N*N, -1*(2*N*N + B), N*N};

        row_n = column_n = N;

        createSparse(&sparse_matrix, N, c1);
        displayMatrix(sparse_matrix, row_n, column_n);


        double *main_diagonal = NULL, *below_diagonal = NULL, *above_diagonal = NULL, *r = NULL;

        create_array(&main_diagonal, &below_diagonal, &above_diagonal, &r,  N, c1);
        displayArray(main_diagonal, below_diagonal, above_diagonal, r, N);

        return 0;
}
