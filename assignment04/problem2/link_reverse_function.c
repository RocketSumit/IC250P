#include <stdio.h>

typedef struct linkedList {
        int data;
        struct linkedList *next;
}list;

int linked_list_reverse(list **ptr){
        list *next, *current, *prev = NULL;
        current = *ptr;

        while(current!= NULL) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
        }
        *ptr = prev;
        return 0;
}
