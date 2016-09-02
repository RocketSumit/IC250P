/*-------------------------------------------------------------------------------
Name: Sumit Patidar
Roll no: B15237
Purpose: IC250 assignment, question 01
Date: 27/08/2016
---------------------------------------------------------------------------------*/

#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <glib.h>

int stackRemove(GSList **ptr);
int stackInsert(GSList **ptr, int data);
int Qremove(GSList **stack1, GSList **stack2);
int Qinsert(GSList **stack1, GSList **stack2, int data);

#endif