#ifndef MATRIX_H
#define MATRIX_H
#pragma once
#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    double **data; //pointer to a 2D array
} matrix;

matrix *create(int rows, int cols);
void free_matrix(matrix *m);
int setVal(matrix *m, int rows, int cols, double val);
int getVal(matrix *m, int rows,int cols, double *out);
void print_matrix(matrix *m);
matrix *mat_add(matrix *a, matrix *b);
matrix *mat_subtract(matrix *a, matrix *b);
matrix *scalar_multiply(matrix *m, double scalar);
matrix *mat_multiply(matrix *a, matrix *b);
matrix *mat_elm_multiply(matrix *a, matrix *b);
matrix *transpose(matrix *m);
matrix *mat_identity(int size);


























#endif // MATRIX_H