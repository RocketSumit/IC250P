#include "my_library.h"

int main(int argc, char const *argv[]) {
        int *sparse_matrix = NULL;
        int row_n = atoi(argv[1]);
        int column_n = atoi(argv[2]);

        createSparse(&sparse_matrix, row_n, column_n);
        display(sparse_matrix, row_n, column_n);

        return 0;
}
