
/*..............................................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 06, part C
   Date: 21/09/2016
   ..............................................................................*/
#include "my_library.h"

int main(int argc, char const *argv[]) {
        struct randomListNode *head = NULL, *head_copy = NULL;
        struct randomListNode r1, r2, r3;
        r1.label = 1;
        r2.label = 2;
        r3.label = 3;
        head = &r1;
        r1.next = &r2;
        r2.next = &r3;
        r3.next = NULL;
        r1.random = &r3;
        r2.random = &r1;
        r3.random = &r2;

        head_copy = copyRandomList(head);
        while(head_copy != NULL) {
                printf("%d\n", head_copy->random->label);
                head_copy = head_copy->next;
        }
        return 0;
}
