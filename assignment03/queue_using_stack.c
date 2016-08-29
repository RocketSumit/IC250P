#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
int stackRemove(GSList **ptr);
int stackInsert(GSList **ptr, int data);
int Qremove(GSList **stack1, GSList **stack2);
int Qinsert(GSList **stack1, GSList **stack2, int data);

int main()
{
    GSList *stack1 = NULL, *stack2 = NULL;
    Qinsert(&stack1, &stack2, 1);
    Qinsert(&stack1, &stack2, 2);
    Qinsert(&stack1, &stack2, 3);
    printf("%d\n", Qremove(&stack1, &stack2));
    printf("%d\n", Qremove(&stack1, &stack2));
    printf("%d\n", Qremove(&stack1, &stack2));
    return 0;
}

int stackInsert(GSList **ptr, int data)
{
    *ptr = g_slist_prepend(*ptr, GINT_TO_POINTER(data));
    return 0;
}

int stackRemove(GSList **ptr)
{
    int item;
    item = GPOINTER_TO_INT((*ptr)->data);
    *ptr = g_slist_delete_link(*ptr, *ptr);
    return item;
}

int Qinsert(GSList **stack1, GSList **stack2, int data)
{
    stackInsert(stack1, data);
    return 0;
}
int Qremove(GSList **stack1, GSList **stack2)
{
    int item;
    *stack2 = g_slist_reverse(*stack1);
    item = stackRemove(stack2);
    g_slist_free_full(stack2, )
    *stack1 = g_slist_reverse(*stack2);
    return item; 
}