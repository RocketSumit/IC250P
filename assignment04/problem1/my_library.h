/*.........................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 04, Q1
   Date: 03/09/2016
   .........................................................*/

#ifndef  MY_LIBRARY_H
#define MY_LIBRARY_H

  #include <stdio.h>
  #include <glib.h>
  #include <stdlib.h>
  #include <string.h>

int stackInsert(GSList **ptr, char *data);
int stackRemove(GSList **ptr);
int check(GSList *ptr, char str[]);

#endif
