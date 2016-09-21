/*..............................................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 06, part C
   Date: 21/09/2016
   ..............................................................................*/
#include "my_library.h"

void swapPointers(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

void printPointerValue(int *a)
{
        printf("%d\n", *a);
}

int compareInts(int *a, int *b)
{
        if(*a > *b)
                return 1;
        else return 0;
}

int compareStrings(char *a, char *b)
{
        int count = 0;

        while(*(a + count) == *(b + count)) {
                count++;
                if(*(a + count) == '\0' && *(b + count) == '\0')
                        return 0;
                else if(*(a + count) == '\0')
                        return 1;
                else if(*(b + count) == '\0')
                        return -1;

        }

        if(*(a + count)<*(b + count))
                return 1;
        else
                return -1;
}

void countTillNum(int n)
{
        int *ptr = &n;
        if(*ptr == 0)
                return;
        countTillNum(*ptr -1);
        printf("%d\n", *ptr);
}
