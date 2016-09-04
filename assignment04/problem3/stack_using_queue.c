#include <stdio.h>
#include <glib.h>

int enqueue(GSList **ptr, int data){
        *ptr = g_slist_prepend(*ptr, GIN_TO_POINTER(data)); //adding the element at first position
        return 0;
}

int dequeue(GSList **ptr){
        *ptr = g_slist_reverse(*ptr);//reversing the list

        int item;
        item = g_slist_nth(*ptr, 0); //get the value of first element
        *ptr = g_slist_delete_link(*ptr, *ptr); //delete the first node
        *ptr = g_slist_reverse(*ptr);// again reverse the list
        return item;
}

int main(int argc, char const *argv[]) {
        GSList *stack;
        return 0;
}

int push_stack(GSList **stack, int data){
        GSList *temporary = NULL;
        enqueue(&temporary, data);
        int item;
        while(g_slist_nth(*stack, 0) != NULL) {
                item  = dequeue(*ptr1);
                enqueue(&temporary, item);
        }
        *stack = temporary;
}

int pop(GSList **stack){
        return dequeue(*stack);
}
