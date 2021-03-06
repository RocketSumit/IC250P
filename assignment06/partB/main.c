/*..............................................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 06, part C
   Date: 21/09/2016
   ..............................................................................*/

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

        writer(matrix, m, n,"matrix.txt");
        printDelete(matrix, m, n);

        return 0;
}
