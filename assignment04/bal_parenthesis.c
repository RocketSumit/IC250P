/*.........................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 04, Q1
   Date: 03/09/2016
   .........................................................*/

#include "my_library.h"

int main(int argc, char const *argv[]) {
        char str[50];
        GSList *stack = NULL;
        printf("Enter the expression (or type 0 to exit):");
        scanf("%[^\n]s", str);
        int boolian;

        if (strlen(str) == 1 && atof(str) == 0.0) {
                return 0;
        }
        boolian = check(stack, str);

        if(boolian == 1) {
                printf("Expression \"%s\" is having balanced parenthesis.\n", str);
        }
        else{
                printf("Expression \"%s\" is having unbalaced parenthesis.\n", str);
        }

        return 0;
}
