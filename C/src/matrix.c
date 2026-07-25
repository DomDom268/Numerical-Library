// this C file implements a matrix struct and fundamental matrix operations
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    double **data; //pointer to a 2D array
} matrix;


// function to create matrix with given dimensions by allocating memory for the row pointers and for each row
matrix *create(int rows, int cols) {
    if (rows==0 || cols==0){
        printf("Error: Matrix must have dimension greater than 0x0");
        return NULL;
    }

    int size = rows * cols;
    matrix *m = malloc(sizeof(matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(double*));

    if(!m->data) {
        printf("Failed to allocate row pointers");
        return NULL;
    }

    for (int i = 0;i < rows; i++) {
        m->data[i] = calloc(cols, sizeof(double)); // Allocates memory for each row
        if(!m->data[i]) {
            printf("Failed to allocate row");
            //free previously allocated row
            for(int j = 0; j<i; j++) free(m->data[j]);
            free(m->data);
            free(m);
            return NULL;
        }
    }

    return m;
}

// function to free matrix memory
void free_matrix(matrix **m) {
    if(m == NULL || *m == NULL) return;
    for(int i = 0;i < (*m)->rows; i++){
        free((*m)->data[i]);
    }
    free((*m)->data);
    free(*m);
    *m = NULL;
}

//function to add value to matrix; returns 1 if successfull and 0 otherwise
int setVal(matrix *m, int rows, int cols, double val) {
    if(!m || rows >= m->rows || cols >=m->cols){
        printf("Invalid index");
        return 0;
    }

    m->data[rows][cols] = val;
    return 1;
}

//function to get value from the matrix; retrusn 1 if successful and 0 otherwise
int getVal(matrix *m, int rows, int cols, double *out) {
    if(!m || rows >= m->rows || cols >=m->cols || !out){
        printf("Invalid index or output pointer");
        return 0;
    }

    *out = m->data[rows][cols];
    return 1;
}

//function to print matrix; returns nothing
void print_matrix(matrix *m) {
    if (!m) return;

    for (int i=0; i < m->rows; i++){
        for(int j=0; j < m->cols; j++){
            printf("%8.2f", m->data[i][j]);
        }
        printf("\n");
    }
}

//function to add two matrices; returns a new matrix if successful and NULL otherwise
matrix *mat_add(matrix *a, matrix *b) {

    if(!a || !b || a->rows != b->rows || a->cols != b->cols){
        printf("Matrices must have the same dimensions for addition");
        return NULL;
    }

    matrix *result = create(a->rows,b->cols);
    if(!result) return NULL;

    for(int i=0; i <a->rows;i++){
        for(int j=0; j<a->cols;j++){
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    
    return result;
}

//function to subtract two matrices; returns a new matrix if successful and NULL otherwise
matrix *mat_subtract(matrix *a, matrix *b) {

    if(!a || !b || a->rows != b->rows || a->cols != b->cols){
        printf("Matrices must have the same dimensions for subtraction");
        return NULL;
    }

    matrix *result = create(a->rows,b->cols);
    if(!result) return NULL;

    for(int i=0; i <a->rows;i++){
        for(int j=0; j<a->cols;j++){
            result->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    
    return result;
}

//function to multiply a matrix by a scalar; returns a new matrix if successful and NULL otherwise
matrix *scalar_multiply(matrix *m, double scalar) {
    if(!m) return NULL;

    matrix *result = create(m->rows,m->cols);
    if(!result) return NULL;

    for(int i=0;i<m->rows;i++){
        for(int j=0;j<m->cols;j++){
            result->data[i][j] = m->data[i][j] * scalar;
        }
    }
    return result;
}

//function to multiply two matrices; returns a new matrix if successful and NULL otherwise
matrix *mat_multiply(matrix *a, matrix *b) {
    if(!a || !b || a->cols != b->rows){
        printf("Imcompatible dimensions for multiplication");
        return NULL;
    }

    matrix *result=create(a->rows,b->cols);
    if(!result) return NULL;

    for(int i =0; i<a->rows;i++){
        for(int j=0;j<b->cols;j++){
            result->data[i][j] = 0;
            for(int k=0; k<a->cols;k++){
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return result;
}

//function to calculate element wise multipllication of two matrices
matrix *mat_elm_multiply(matrix *a, matrix *b){
    if(!a || !b || a->cols != b->cols || a->rows != b->rows){
        printf("Incompatible matrices");
        return NULL;
    }

    matrix *result = create(a->rows,a->cols);
    if(!result) return NULL;

    for(int i=0;i<a->rows;i++){
        for(int j=0;j<b->cols;j++){
            result->data[i][j] = a->data[i][j] * b->data[i][j];
        }
    }

    return result;
}
//function to transpose a matrix; returns a new matrix if successful and NULL otherwise
matrix *transpose(matrix *m) {
    if(!m) return NULL;

    matrix *result = create(m->cols,m->rows);
    if(!result) return NULL;

    for(int i=0;i<m->rows;i++){
        for(int j=0; j<m->cols; j++){
            result->data[i][j] = m->data[j][i];
        }
    }
    return result;
}

matrix *mat_identity(int size){
    if(size <=0){
        printf("Size must be greater than 0 for identity matrix");
        return NULL;
    }

    matrix *result = create(size,size);
    if(!result) return NULL;

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j){
                result->data[i][j] = 1;
            } else{
                result->data[i][j] = 0;
            }
        }
    }
    return result;
}

