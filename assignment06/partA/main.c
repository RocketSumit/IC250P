/*..............................................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 06, part C
   Date: 21/09/2016
   ..............................................................................*/
#include "my_library.h"

int main(int argc, char const *argv[]) {
        int choice, a, b;
        char string1[100], string2[100];
        printf("Enter the respectivec choice: \n1 for swapping pointers\n2 for comparing integers\n3 for comparing strings\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:

                printf("Enter two integers to swap: ");
                scanf("%d%d", &a, &b);
                swapPointers(&a, &b);
                printf("After swapping\n");
                printPointerValue(&a);
                printPointerValue(&b);
                break;
        case 2:

                printf("Enter two integers to compare: ");
                scanf("%d%d", &a, &b);
                printf("Comparison result: %d\n", compareInts(&a, &b));
                break;
        case 3:
                printf("Enter two strings to compare\n");
                scanf("%s%s",string1, string2);
                printf("Comparison result: %d\n", compareStrings(string1, string2) );
        }

        return 0;
}
