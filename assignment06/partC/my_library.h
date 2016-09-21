/*..............................................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 06, part C
   Date: 21/09/2016
   ..............................................................................*/
#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>

struct randomListNode {
        int label;
        struct randomListNode *next;
        struct randomListNode *random;
};

struct randomListNode* copyRandomList (struct randomListNode *head);

#endif
