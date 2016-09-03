/*.........................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 04, Q1
   Date: 03/09/2016
   .........................................................*/

#include "my_library.h"

int main(int argc, char const *argv[]) {
        char ch;
        GSList **stack = NULL;

        while (ch!= EOF || ch!= '\n') {
                ch = getc(stdin);
                if(ch == '(') {
                        stackInsert(stack, ch);
                }

                else if (ch == ')') {
                        if (stackRemove(stack) == NULL) {
                                printf("Unbalaced\n");
                                return 0;
                        }
                }
        }
        return 0;
}
