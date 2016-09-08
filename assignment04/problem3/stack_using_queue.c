/*..........................................
   Name: Sumit Patidar
   Roll no : B15237
   Purpose : IC250 assignment, Q3
   Date : 07/09/16
   .........................................*/

#include "my_library.h"

int main(int argc, char const *argv[]) {
        GSList *stack;


        int total_elements;
        printf("Enter how many elements to be entered:\n");
        scanf("%d", &total_elements);

        int n[total_elements];

        for (size_t i = 0; i < total_elements; i++) {
                printf("Enter the element: ");
                scanf("%d", &n[i]);
                printf("\n");
        }

        for (size_t i = 0; i < total_elements; i++) {
                push_stack(&stack, n[i]);
        }

        //print the pop values
        printf("\nPopped values are: ");
        for (size_t i = 0; i < total_elements; i++) {
                printf("%d\t", pop(&stack));
        }

        printf("\n");

        return 0;
}
