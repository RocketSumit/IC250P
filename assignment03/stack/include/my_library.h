#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <glib.h>

int stackRemove(GSList **ptr);
int stackInsert(GSList **ptr, int data);
int Qremove(GSList **stack1, GSList **stack2);
int Qinsert(GSList **stack1, GSList **stack2, int data);

#endif