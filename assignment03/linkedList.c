#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
int stackRemove(GSList **ptr);
int stackInsert(GSList **ptr, int data);

int main()
{
    int data[2] = {1, 2};
    GSList *stack1 = NULL;
    stackInsert(&stack1, data[0]);
    stackInsert(&stack1, data[1]);
    printf("%d\n", stackRemove(&stack1));
    stackInsert(&stack1, 4);
    printf("%d\n", stackRemove(&stack1));
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