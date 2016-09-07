/*.........................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 04, Q1
   Date: 03/09/2016
   .........................................................*/
#include "my_library.h"

//function to insert the data to stack
int stackInsert(GSList **ptr, char *data)
{
        *ptr = g_slist_prepend(*ptr, &data);
        return 0;
}

//functin to pop the data from stack
int stackRemove(GSList **ptr)
{
        if(g_slist_nth(*ptr, 0) == NULL) {
                return 0;
        }
        *ptr = g_slist_delete_link(*ptr, *ptr);
        return 1;
}

//function to check for balanced parenthesis in string
int check(GSList *ptr, char str[]){
        int length = strlen(str);

        for (int i = 0; i < length; i++) {
                if(str[i] == '(') {
                        stackInsert(&ptr, (str + i));
                }
                else if (str[i] == ')') {
                        if(stackRemove(&ptr) == 0)
                                return 0;
                }
        }

        if(stackRemove(&ptr) == 1)
                return 0;

        return 1;
}
