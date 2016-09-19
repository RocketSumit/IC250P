#include "my_library.h"

int **maker(int m,int n)
{
        int **x;
        x = (int **)malloc(m * sizeof(int*));

        //allocates memory for each row
        for(int i =0; i<m; i++) {
                x[i] = (int *)malloc(n*sizeof(int));
        }

        //intilize matrix with random integers
        for(int i =0; i<m; i++) {
                for(int j = 0; j<n; j++) {
                        x[i][j] = rand();
                }
        }
        return x;
}
void writer(int **matrix, int m, int n, char *filename)
{
        FILE *fptr;
        fptr = fopen(filename, "w");
        fprintf(fptr,"%d\t%d\n",m,n);

        for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                        fprintf(fptr, "%d\t", matrix[i][j]);
                }
                fprintf(fptr,"\n");
        }

        fclose(fptr);
}

void printDelete(int **matrix, int m, int n)
{
        printf("%d\t%d\n",m,n);

        for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                        printf("%d\t", matrix[i][j]);
                }
                printf("\n");
        }

        free(matrix);
}
