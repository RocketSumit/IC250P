
#include "my_library.h"

int enqueue(GSList **ptr, int data){
        *ptr = g_slist_prepend(*ptr, GINT_TO_POINTER(data)); //adding the element at first position
        return 0;
}

int dequeue(GSList **ptr){
        *ptr = g_slist_reverse(*ptr);//reversing the list

        int item;
        item = GPOINTER_TO_INT((*ptr)->data); //get the value of first element
        *ptr = g_slist_delete_link(*ptr, *ptr); //delete the first node
        *ptr = g_slist_reverse(*ptr);// again reverse the list
        return item;
}

//function to push element to stack
int push_stack(GSList **stack, int data){
        GSList *temporary = NULL;
        enqueue(&temporary, data); //enqueue the new element to new queue

        int item;

        while(g_slist_nth(*stack, 0) != NULL) {
                item  = dequeue(stack);
                enqueue(&temporary, item);
        }
        //new stack created
        *stack = temporary;
        return 0;
}

//function to pop element from stack
int pop(GSList **stack){
        return dequeue(stack);
}
