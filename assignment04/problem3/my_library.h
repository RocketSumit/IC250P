#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <glib.h>

int enqueue(GSList **ptr, int data);
int dequeue(GSList **ptr);
int push_stack(GSList **stack, int data);
int pop(GSList **stack);

#endif
