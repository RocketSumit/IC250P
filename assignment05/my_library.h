/*.......................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: IC260 assignment 05
   Date: 28/09/16
   .......................................................*/

#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

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
void printSolutionToFile(double* x_gauss, double *x_analytical, int N, char *filename);
void plotSoultion(char *filename, int N);
void printError(double error, int N, char *filename);
double errorEstimation(double *x_gauss, double *x_analytical, int N);
double *thomasAlgorithm(double *main_diagonal, double *below_diagonal, double *above_diagonal, double *r, int N);
void plotErrorGraph(char *filename);

#endif
