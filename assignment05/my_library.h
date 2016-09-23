#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define clear()  printf("\033[H\033[J")

struct coefficients
{
        double b;
        double d;
        double a;
};

void createSparse(double **sparse_matrix, int N, struct coefficients c1);
void displayMatrix(double *sparse_matrix, int row_n, int column_n);
void create_array(double **main_diagonal, double ** below_diagonal, double **above_diagonal, double **r, int N, struct coefficients c1);
void displayArray(double *main_diagonal, double *below_diagonal, double *above_diagonal, double *r, int N);
double **createAugmentedMatrix(double *sparse_matrix, double *r, int N);
void printAugmentedMatrix(double **augmented_matrix, int N);
double* gaussElimination(double **augmented_matrix, int N);
double* analyticalSolution(double B, int N);
void printToFile(double* x_gauss, double *x_analytical, int N);
void plot1(char *commands[], int no_of_commands);

#endif
