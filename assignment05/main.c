#include "my_library.h"

int main(int argc, char const *argv[]) {
        double *sparse_matrix = NULL;
        double *main_diagonal = NULL, *below_diagonal = NULL, *above_diagonal = NULL, *r = NULL;
        double **augmented_matrix = NULL, *x_computed = NULL, *x_analytical = NULL;
        double B, error;

        int N, row_n, column_n, choice;
        clock_t start, end;

        clear();
        printf("Enter the value of N: ");
        scanf("%d", &N);
        printf("Enter the value of β(fixed): ");
        scanf("%lf", &B);
        printf("Enter the choice: \n1 for Gauss Elimination Method.\n2 for Thomas Algorithm.\n");

        start = clock_t();

        struct coefficients c1 = {N*N, -1*(2*N*N + B), N*N};

        row_n = column_n = N; //setting value of row and column

        switch(choice) {
        case 1:
                createSparse(&sparse_matrix, N, c1);
                /* does the computation required for gaussElimination */
                augmented_matrix = createAugmentedMatrix(sparse_matrix, r, N);
                x_computed = gaussElimination(augmented_matrix, N);
                x_analytical = analyticalSolution (B, N);
                error = errorEstimation(x_computed, x_analytical, N);

                /* write data to file */
                printf("Writing the output in the result files.\n");
                printToFile(x_computed, x_analytical, N);
                printError(error, N);
                end = clock_t();
                printf("Time taken is %lf ms\n", (end - start)*1000);

                break;

        case 2:
                create_array(&main_diagonal, &below_diagonal, &above_diagonal, &r,  N, c1);

                /* does the computation required for Thomas Algorithm */
                x_computed = thomasAlgorithm(main_diagonal, below_diagonal, above_diagonal, r, N);
                x_analytical = analyticalSolution (B, N);
                error = errorEstimation(x_computed, x_analytical, N);

                /* write data to file */
                printf("Writing the output in the result files.\n");
                printToFile(x_computed, x_analytical, N);
                printError(error, N);
                end = clock_t();
                printf("Time taken is %lf ms\n", (end - start)*1000);
        }


        /* plotting graphs using gnuplot */
        printf("Plotting the required graphs\n");
        char *commandsForGnuplot[] = { "set terminal png ", "set termopt enhanced ", "set xlabel \"x^* -->\"", "set ylabel \"θ -->\"", " set output 'a.png'", " plot \"results.txt\" using 3:1 with lines title \"θ_{gauss}\" ,\"results.txt\" using 3:2 with lines title \"θ_{actual}"};
        plot1(commandsForGnuplot, 6);

        /* free the no longer required memory */
        free(sparse_matrix);
        free(main_diagonal);
        free(above_diagonal);
        free(below_diagonal);
        free(augmented_matrix);
        free(x_computed);
        free(x_analytical);
        free(r);

        return 0;
}
