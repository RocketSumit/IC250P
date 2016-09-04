#include <stdio.h>
#include <glib.h>
int enqueue(GSList **ptr, int data);
int dequeue(GSList **ptr);
int push_stack(GSList **stack, int data);
int pop(GSList **stack);

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

int push_stack(GSList **stack, int data){
        GSList *temporary = NULL;
        enqueue(&temporary, data);
        int item;
        while(g_slist_nth(*stack, 0) != NULL) {
                item  = dequeue(stack);
                enqueue(&temporary, item);
        }
        *stack = temporary;
        return 0;
}

int pop(GSList **stack){
        return dequeue(stack);
}
