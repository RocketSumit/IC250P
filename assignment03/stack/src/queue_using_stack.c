/*-------------------------------------------------------------------------------
Name: Sumit Patidar
Roll no: B15237
Purpose: IC250 assignment, question 01
Date: 27/08/2016
---------------------------------------------------------------------------------*/
#include "my_library.h"
#include <stdio.h>
#include <stdlib.h>


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
