#include "my_library.h"

int main(int argc, char const *argv[]) {
        struct sparse s1 = {0};
        int *sparse_matrix = NULL;
        if(argc != 3) {
                printf("Usage requires two command line parameters:\n\t[a] No of rows\n\t[b] No of columns\n");
                exit(0);
        }
        int row_n = atoi(argv[1]);
        int column_n = atoi(argv[2]);

        createSparse(&sparse_matrix, row_n, column_n);
        displayMatrix(sparse_matrix, row_n, column_n);
        createTupple(sparse_matrix, &s1, row_n, column_n);
        displayTupple(s1);

        return 0;
}
