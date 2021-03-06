/*.......................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: IC260 assignment 05
   Date: 28/09/16
   .......................................................*/

#include "my_library.h"

int main(int argc, char const *argv[]) {
        double *sparse_matrix = NULL;
        double *main_diagonal = NULL, *below_diagonal = NULL, *above_diagonal = NULL, *r = NULL;
        double **augmented_matrix = NULL, *x_computed = NULL, *x_analytical = NULL;
        double B, error, time_taken, memory_used;

        int N, row_n, column_n, choice;
        clock_t start, end;

        clear();
        printf("Enter the value of N: ");
        scanf("%d", &N);
        printf("Enter the value of β(fixed): ");
        scanf("%lf", &B);
        printf("\nEnter the choice: \n1 for Gauss Elimination Method.\n2 for Thomas Algorithm.\n");
        scanf("%d", &choice);

        start = clock();

        struct coefficients c1 = {(N - 1) * (N - 1), -1*(2*(N - 1) * (N - 1) + B), (N - 1) * (N - 1)};

        row_n = column_n = N; //setting value of row and column

        createSparse(&sparse_matrix, N, c1);
        create_array(&main_diagonal, &below_diagonal, &above_diagonal, &r,  N, c1);

        switch(choice) {
        case 1:

                /* does the computation required for gaussElimination */
                augmented_matrix = createAugmentedMatrix(sparse_matrix, r, N);
                x_computed = gaussElimination(augmented_matrix, N);
                x_analytical = analyticalSolution (B, N);
                error = errorEstimation(x_computed, x_analytical, N);

                /* write data to file */
                printf("Writing the output in the result files.\n\n");
                printSolutionToFile(x_computed, x_analytical, N, "results_gauss.txt");
                printError(error, N, "error_gauss.txt");
                end = clock();
                time_taken = (double)(end - start)/CLOCKS_PER_SEC;
                printf("Time taken is %lf ms\n\n", time_taken*1000);

                /* plotting graphs using gnuplot */
                printf("Plotting the required graphs.\n\n");
                plotSoultion( "gauss", N );
                plotErrorGraph("gauss");

                /* calculate the memory used */
                memory_used = sizeof(sparse_matrix)* (N*N) + sizeof(augmented_matrix)*(N*(N + 1)) + sizeof(x_analytical)*N + sizeof(x_computed)*N + sizeof(r)*N;
                printf("Space used is %lf MB\n\n", memory_used/(1024.0*1024.0));

                break;

        case 2:

                /* does the computation required for Thomas Algorithm */
                x_computed = thomasAlgorithm(main_diagonal, below_diagonal, above_diagonal, r, N);
                x_analytical = analyticalSolution (B, N);
                error = errorEstimation(x_computed, x_analytical, N);

                /* write data to file */
                printf("Writing the output in the result files.\n\n");
                printSolutionToFile(x_computed, x_analytical, N, "results_thomas.txt");
                printError(error, N, "error_thomas.txt");
                end = clock();
                time_taken = (double)(end - start)/CLOCKS_PER_SEC;
                printf("Time taken is %lf ms\n\n", time_taken*1000);

                /* plotting graphs using gnuplot */
                printf("Plotting the required graphs.\n\n");
                plotSoultion( "thomas", N );
                plotErrorGraph("thomas");

                /* calculate the memory used */
                memory_used = sizeof(sparse_matrix)* (N*N) + sizeof(x_analytical)*N + sizeof(x_computed)*N + sizeof(main_diagonal)*N + sizeof(above_diagonal)*(N - 1) + sizeof(below_diagonal)*(N - 1) + sizeof(r)*N;
                printf("Space used is %lf MB\n\n", memory_used/(1024.0*1024.0));

        }

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
