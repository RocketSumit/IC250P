#include "my_library.h"

/* Dynamically creates matrix of sizeof row_n*column_n */
void createSparse(double **sparse_matrix, int N, struct coefficients c1)
{
        int i;
        *sparse_matrix = (double *) malloc (N * N * sizeof(double));

        for ( i = 0; i < N; i++) {
                if (i == 0)
                        *(*sparse_matrix + 0) = 1;
                else
                        *(*sparse_matrix + i) = 0;
        }

        for ( int j = 1; j < N - 1; j++) {
                for (int k = 0; k <N; k++) {

                        if(i == (j*N + j - 1))
                                *(*sparse_matrix + i) = c1.b;
                        else if (i == (j*N + j))
                                *(*sparse_matrix + i) = c1.d;
                        else if (i == (j*N + j + 1))
                                *(*sparse_matrix + i) = c1.a;
                        else
                                *(*sparse_matrix + i) = 0;
                        i++;
                }
        }

        for ( int j = 0; j < N; j++) {
                if (i == ((N - 1)*N + N - 2 ))
                        *(*sparse_matrix + i) = -1;
                else if(i == ((N - 1)*N + N - 1 ))
                        *(*sparse_matrix + i) = 1;
                else
                        *(*sparse_matrix + i) = 0;
                i++;
        }
}

/* Display all elements of sparse matrix */
void displayMatrix(double *sparse_matrix, int row_n, int column_n)
{

        for (int i = 0; i < row_n*column_n; i++) {

                //position the cursor to new line for each new row
                if (i%column_n == 0) {
                        printf("\n");
                }
                printf("%lf\t", *(sparse_matrix + i));
        }
        printf("\n\n");
}

/* creates four 1D arrays of main, below and above diagonal elements */
void create_array(double **main_diagonal, double ** below_diagonal, double **above_diagonal, double **r, int N, struct coefficients c1)
{
        *main_diagonal = (double *)malloc(N*sizeof(double));
        *below_diagonal = (double *)malloc((N -1)*sizeof(double));
        *above_diagonal = (double *)malloc((N- 1)*sizeof(double));
        *r = (double *)malloc(N * sizeof(double));

        for(int i = 0; i<N; i++ ) {
                if(i == 0) {
                        *(*main_diagonal + i) = 1;
                        *(*below_diagonal + i) = c1.b;
                        *(*above_diagonal + 0) = 0;
                        *(*r + i) = 1;
                }
                else if(i < N - 2) {
                        *(*main_diagonal + i) = c1.d;
                        *(*below_diagonal + i) = c1.b;
                        *(*above_diagonal + i) = c1.a;
                        *(*r + i) = 0;
                }
                else if(i == N - 2) {
                        *(*main_diagonal + i) = c1.d;
                        *(*below_diagonal + i) = -1;
                        *(*above_diagonal + i) = c1.a;
                        *(*r + i) = 0;
                }
                else if(i == N - 1) {
                        *(*main_diagonal + i) = 1;
                        *(*r + i) = 0;
                }
        }
}

void displayArray(double *main_diagonal, double *below_diagonal, double *above_diagonal, double *r, int N)
{
        printf("[b]\t\t[d]\t\t[a]\t\t[r]\n");

        for (int i = 0; i < N - 1; i++) {
                printf("%lf\t%lf\t%lf\t%lf\n", *(below_diagonal + i), *(main_diagonal + i), *(above_diagonal + i), *(r + i));
        }
        printf("\t\t%lf\t\t\t%lf\n",*(main_diagonal + N - 1), *(r + N - 1));
}

double* gaussElimination(int **sparse_matrix, int N)
{
        double c, sum, *x = NULL;
        x = (double *) malloc (N * sizeof(double));

        for(int j=0; j<N; j++) /* loop for the generation of upper triangular matrix*/
        {
                for(int i= 0; i<N; i++)
                {
                        if(i>j)
                        {
                                c=sparse_matrix[i][j]/sparse_matrix[j][j];
                                for(int k=0; k<=N; k++)
                                {
                                        sparse_matrix[i][k]=sparse_matrix[i][k]-c*sparse_matrix[j][k];
                                }
                        }
                }
        }
        x[N]=sparse_matrix[N][N+1]/sparse_matrix[N][N];
        /* this loop is for backward substitution*/
        for(int i=N-2; i>=0; i--)
        {
                sum=0;
                for(int j=i; j<N; j++)
                {
                        sum=sum+sparse_matrix[i][j]*x[j];
                }
                x[i]=(sparse_matrix[i][N+1]-sum)/sparse_matrix[i][i];
        }

        return x;
}

double* analyticalSolution(double B, int N)
{
        double *x = NULL;
        for(int i =0; i<N; i++) {
                x[i] = cosh(sqrt(B)*(1 - (i + 1)/N))/cosh(sqrt(B));
        }
        return x;
}
