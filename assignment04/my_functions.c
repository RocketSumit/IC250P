/*.........................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 04, Q1
   Date: 03/09/2016
   .........................................................*/
#include "my_library.h"

int stackInsert(GSList **ptr, char data)
{
        *ptr = g_slist_prepend(*ptr, data);
        return 0;
}

char stackRemove(GSList **ptr)
{
        char item;
        item = (*ptr)->data;
        *ptr = g_slist_delete_link(*ptr, *ptr);
        return item;
}
