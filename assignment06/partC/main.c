
/*..............................................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 06, part C
   Date: 21/09/2016
   ..............................................................................*/
#include "my_library.h"

int main(int argc, char const *argv[]) {
        struct randomListNode *head = NULL, *head_copy = NULL;
        int size = 0, count = 0, random_label = 0;

        clear();
        printf("Enter the size of doubly linked list: ");
        scanf("%d", &size);

        /* create the singly linked list */
        for(int i = 0; i<size; i++) {
                count++;
                createOriginalSinglyList(&head, count);
        }

        /* asked for random relations */
        for(int i = 0; i<size; i++) {
                printf("[%d] random -> ", i+1);
                scanf("%d", &random_label);
                insertRandomLinks(head, i + 1, random_label);
                printf("\n");
        }

        count = 0;
        struct randomListNode *iterator = NULL;
        iterator = head;

        printf("Original Linked List:\n");
        /* print the original doubly linked list */
        while(iterator != NULL) {
                count++;
                printf("[%d] random -> %d\n", count, iterator->random->label);
                iterator = iterator->next;
        }

        head_copy = copyRandomList(head);
        count = 0;
        iterator = head_copy;

        printf("\n\nDeep Copied Linked List:\n");
        /* print the copied doubly linked list */
        while(iterator != NULL) {
                count++;
                printf("[%d] random -> %d\n", count, iterator->random->label);
                iterator = iterator->next;
        }
        printf("\n\n");

        return 0;
}
