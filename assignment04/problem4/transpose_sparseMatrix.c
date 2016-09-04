#include "my_library.h"

int main(int argc, char const *argv[]) {

        FILE *fptr;
        fptr = fopen("/Users/sumitpatidar/Desktop/data.txt", "r");
        matx matrix1[100];

        int row_cumu_frequency[100] = {0};
        int column_cumu_frequency[100] = {0};

        read_matrix(fptr, matrix1, row_cumu_frequency, column_cumu_frequency);
        fclose(fptr);
        for(int i = 0; i<5; i++)
                printf("%d\n", column_cumu_frequency[i]);
        return 0;
}
