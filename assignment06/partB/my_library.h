#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>

int **maker(int m,int n);
void writer(int **matrix, int m, int n, char *filename);
void printDelete(int **matrix, int m, int n);

#endif
