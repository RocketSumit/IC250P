/*..........................................
   Name: Sumit Patidar
   Roll no : B15237
   Purpose : IC250 assignment, Q2
   Date : 07/09/16
   .........................................*/
#include <stdio.h>

typedef struct linkedList {
        int data;
        struct linkedList *next;
}list;

int linked_list_reverse(list **head){
        list *next, *current, *prev = NULL;
        current = *head;

        while(current!= NULL) {
                next = current->next; //point to element next to current
                current->next = prev; // link between current and previous element is reversed
                prev = current;
                current = next;
        }

        *head = prev;
        return 0;
}
