/*-------------------------------------------------------------------------------
Name: Sumit Patidar
Roll no: B15237
Purpose: IC250 assignment, question 01
Date: 27/08/2016
---------------------------------------------------------------------------------*/
#include "my_library.h"

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
    *stack1 = g_slist_reverse(*stack2);
    return item; 
}