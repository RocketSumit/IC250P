#include "my_library.h"
int main(int argc, char const *argv[]) {
        if(argc != 3) {
                printf("Usage requires two commandline parameters:\n1. no of rows\n2. no of columns\n");
                exit(0);
        }
        int m, n;
        m = atoi(argv[1]);
        n = atoi(argv[2]);

        int **matrix = maker(m, n);

        writer(matrix, m, n,"/Users/sumitpatidar/Desktop/matrix.txt");
        printDelete(matrix, m, n);

        return 0;
}
