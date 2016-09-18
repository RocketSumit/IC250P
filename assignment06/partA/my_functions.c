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
                if(*(a + count) == '\0' && *(b + count) == '\0')
                        return 0;
                else if(*(a + count) == '\0')
                        return 1;
                else
                        return -1;
                count++;
        }

        if(*(a + count)>*(b + count))
                return 1;
        else
                return -1;
}
