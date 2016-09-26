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

double* gaussElimination(double **augmented_matrix, int N)
{
        int i, j, k;
        double c, sum, *x = NULL;
        x = (double *) malloc (N * sizeof(double));

        for(j=0; j<=N; j++) /* loop for the generation of upper triangular matrix*/
        {
                for(i=0; i<N; i++)
                {
                        if(i>j)
                        {
                                c=augmented_matrix[i][j]/augmented_matrix[j][j];
                                for(k=0; k<=N; k++)
                                {
                                        augmented_matrix[i][k]=augmented_matrix[i][k]-c*augmented_matrix[j][k];
                                }
                        }
                }
        }

        x[N - 1]=augmented_matrix[N - 1][N]/augmented_matrix[N - 1][N - 1];

        /* this loop is for backward substitution*/
        for(i=N-2; i>=0; i--)
        {
                sum=0;
                for(j=i+1; j<N; j++)
                {
                        sum=sum+augmented_matrix[i][j]*x[j];
                }
                x[i]=(augmented_matrix[i][N]-sum)/augmented_matrix[i][i];
        }

        return x;
}

double* analyticalSolution(double B, int N)
{
        double *x = (double *) malloc(N*sizeof(double));
        double argument = sqrt(B);

        for(int i =0; i<N; i++) {
                x[i] = cosh(argument*(double)(1 - ((double)(i)/(double)(N - 1))))/cosh(argument);
        }

        return x;
}

/* determinnes root mean square error for entire temperatures */

double errorEstimation(double *x_gauss, double *x_analytical, int N)
{
        double sum = 0;

        /* adding the squares of differences */
        for (int i = 0; i < N; i++) {
                sum += pow(*(x_gauss + i) - *(x_analytical + i), 2);
        }

        return sqrt(sum/N);

}

void printSolutionToFile(double* x_gauss, double *x_analytical, int N, char *filename)
{
        FILE *fptr = NULL;
        fptr = fopen(filename, "w");
        fprintf(fptr, "%s\t%s\t\t%s\n", "#gauss", "analytical", "x*");

        for (int i = 0; i < N; i++ ) {
                fprintf(fptr, "%lf\t\t%lf\t\t%lf\n", x_gauss[i], x_analytical[i], (double)(i+1)/(double)N);
        }
        fclose(fptr);
}

double **createAugmentedMatrix(double *sparse_matrix, double *r, int N)
{
        double **augmented_matrix = (double **) malloc(N *sizeof(double *));

        for (int i =0; i<N; i++) {
                augmented_matrix[i] = (double *)malloc((N + 1)*sizeof(double));
        }

        // copy sparse matrix to augmented_matrix
        for(int i = 0; i < N; i++) {
                for (int j = 0; j<N; j++) {
                        augmented_matrix[i][j] = *(sparse_matrix + i*N + j);
                }
        }

        //copy right hand side vector to augmented_matrix
        for(int i = 0; i<N; i++) {
                augmented_matrix[i][N] = *(r + i);
        }

        return augmented_matrix;
}

/* prints all elements of augmented matrix */
void printAugmentedMatrix(double **augmented_matrix, int N){

        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N + 1; j++) {
                        printf("%lf\t", augmented_matrix[i][j] );
                }
                printf("\n");
        }
}

/* plots graph between theta, theta_exact vs x* */
void plot1(char *filename, int N)
{
        FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

        char *commandsForGnuplot[4] = { "set terminal png ", "set termopt enhanced ", "set xlabel \"x^* -->\"", "set ylabel \"θ -->\""};

        for(int i = 0; i<4; i++) {
                fprintf(gnuplotPipe, "%s\n", commandsForGnuplot[i]);
        }

        fprintf(gnuplotPipe, "set title \"θ vs x^* for N = %d\"\n", N );
        fprintf(gnuplotPipe, "set output \"graph_%s.png\"\n", filename);
        fprintf(gnuplotPipe, "plot \"results_%s.txt\" using 3:1 with lines title \"θ_{%s}\" ,\"results_%s.txt\" using 3:2 with lines title \"θ_{actual}\"\n ", filename, filename, filename);

        pclose(gnuplotPipe);
}

/* print the rms_error for value of N to file */
void printError(double error, int N, char *filename)
{
        FILE *fptr = NULL;
        fptr = fopen(filename, "a");

        if(ftell(fptr) == 0)
                fprintf(fptr, "%s\t\t%s\n","#RMS_error", "N");

        fprintf(fptr, "%lf\t\t%d\n", error, N);

        fclose(fptr);

}

/* Using three diagonal and right hand side vector, compute x */
double *thomasAlgorithm(double *main_diagonal, double *below_diagonal, double *above_diagonal, double *r, int N)
{
        double *x = (double *)malloc(N*sizeof(double));

        /* Forward elimination */
        for (int i = 1; i< N; i++) {
                *(main_diagonal + i ) -= (*(above_diagonal + i - 1)) * (*(below_diagonal + i - 1))/(*(main_diagonal + i - 1));
                *(r + i) -= (*(r + i - 1))*(*(below_diagonal + i - 1))/(*(main_diagonal + i - 1));
        }

/* backward substitution */
        x[N - 1] = (*(r + N - 1))/(*(main_diagonal + N - 1));

        for (int j = N - 2; j>-1; j--) {
                x[j] = (*(r + j) - (*(above_diagonal + j) * x[j + 1]))/(*(main_diagonal + j));
        }

        return x;
}

void plotErrorGraph(char *filename)
{
        FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

        char *commandsForGnuplot[4] = { "set terminal png ", "set termopt enhanced ", "set xlabel \"N -->\"", "set ylabel \"Error -->\""};

        for(int i = 0; i<4; i++) {
                fprintf(gnuplotPipe, "%s\n", commandsForGnuplot[i]);
        }

        fprintf(gnuplotPipe, "set title \"Error vs N for %sMethod\"\n", filename);
        fprintf(gnuplotPipe, "set output \"error_%s.png\"\n", filename);
        fprintf(gnuplotPipe, "plot \"error_%s.txt\" using 2:1 with lines title \"Error analysis\" ",filename);

        pclose(gnuplotPipe);
}
