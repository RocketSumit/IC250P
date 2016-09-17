#include "my_library.h"

/* Dynamically creates matrix of sizeof row_n*column_n */
void createSparse(int **sparse_matrix, int row_n, int column_n)
{
        int n;

        *sparse_matrix = (int *) malloc (row_n * column_n * sizeof(int));

        for (int i = 0; i < (row_n*column_n); i++) {
                printf("\nEnter sparse matrix %dth element: ", i);
                scanf("%d", &n );
                *(*sparse_matrix + i) = n;
        }
}

/* Display all elements of sparse matrix */
void displayMatrix(int *sparse_matrix, int row_n, int column_n)
{

        for (int i = 0; i < row_n*column_n; i++) {

                //position the cursor to new line for each new row
                if (i%column_n == 0) {
                        printf("\n");
                }
                printf("%d\t", *(sparse_matrix + i));
        }
        printf("\n\n");
}

/* Counts number of non-zero elements */
int count(int *sparse_matrix, int row_n, int column_n)
{
        int count = 0;

        for (size_t i = 0; i < row_n * column_n; i++) {
                if (*(sparse_matrix + i) != 0 ) {
                        count++;
                }
        }

        return count;
}

/* Creates an array that stores information about non-zero elements */
void createTupple(int *sparse_matrix, struct sparse *s1, int row_n, int column_n)
{
        s1->no_of_tupples = count(sparse_matrix, row_n, column_n) + 1;
        s1->tupple = (int *) malloc (3 * s1->no_of_tupples * sizeof(int));

        *(s1->tupple + 0) = row_n;
        *(s1->tupple + 1) = column_n;
        *(s1->tupple + 2) = s1->no_of_tupples - 1;

        int r = 0, c = 0, l = 2;

        // increments the row and reset column values
        for (int i = 0; i < row_n * column_n; i++) {
                if(i%column_n == 0 &&  i != 0) {
                        r++;
                        c = 0;
                }

                /* checks for non-zero values and
                   then assign row, column index
                   and value to tupple */
                if(*(sparse_matrix + i) != 0) {
                        l++;
                        *(s1->tupple + l) = r;
                        l++;
                        *(s1->tupple + l) = c;
                        l++;
                        *(s1->tupple + l) = *(sparse_matrix + i);
                }
                c++;
        }
}

/* Displays the content of tupple */
void displayTupple(struct sparse s1)
{
        for (int i = 3; i < (s1.no_of_tupples * 3); i++) {
                if(i%3 == 0)
                        printf("\n");
                printf("%d\t", *(s1.tupple + i));
        }

        printf("\n\n");
}
