#include "my_library.h"

/*Dynamically creates matrix of sizeof row_n*column_n*/
void createSparse(int **sparse_matrix, int row_n, int column_n)
{
        int n;

        *sparse_matrix = (int *) malloc (row_n*column_n*sizeof(int));

        for (int i = 0; i < (row_n*column_n); i++) {
                printf("\nEnter sparse matrix %dth element: ", i);
                scanf("%d", &n );
                **(sparse_matrix + i) = n;
        }
}

/*Display all elements of sparse matrix*/
void display(int *sparse_matrix, int row_n, int column_n)
{

        for (int i = 0; i < row_n*column_n; i++) {

                //position the cursor to new line for each new row
                if (i%column_n == 0) {
                        printf("\n");
                }
                printf("%d\t", *(sparse_matrix + i));
        }
        printf("\n");
}
