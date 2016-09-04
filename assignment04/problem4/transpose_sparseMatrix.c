#include "my_library.h"

int main(int argc, char const *argv[]) {

        FILE *fptr;
        fptr = fopen("/Users/sumitpatidar/Desktop/data.txt", "r");
        matx matrix1[100];
        read_matrix(fptr, matrix1);
        fclose(fptr);
        return 0;
}
