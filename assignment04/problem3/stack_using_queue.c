/*..........................................
   Name: Sumit Patidar
   Roll no : B15237
   Purpose : IC250 assignment, Q3
   Date : 07/09/16
   .........................................*/

#include "my_library.h"

int main(int argc, char const *argv[]) {
        GSList *stack;

        int n[3];
        printf("Enter three integer elements to be stacked: ");
        scanf("%d%d%d",&n[0], &n[1], &n[2]);

        for (size_t i = 0; i < 3; i++) {
                push_stack(&stack, n[i]);
        }

        //print the pop values
        printf("\nPopped values are: ");
        for (size_t i = 0; i < 3; i++) {
                printf("%d\t", pop(&stack));
        }
        printf("\n");

        return 0;
}
