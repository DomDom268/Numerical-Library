#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"


vector *create_v(int rows){
    if(rows<=0){
        printf("Vector must have more than 0 rows");
        return NULL;
    }

    vector *v = malloc(sizeof(vector));
    v->rows = rows;
    v->data = calloc(rows,sizeof(double));

    return v;
}

void print_v(vector *v){
    if(!v) return;

    for(int i=0;i<v->rows;i++){
        printf("%8.2f\n",v->data[i]);
    }
    printf("\n");
}

void free_v(vector **v){
    if(v == NULL || *v ==NULL){
        return;
    }

    free((*v)->data);
    free(*v);
    *v = NULL;
    
}

int setVal_v(vector *v, int row, double val){
    if(v->rows <= row || row < 0){
        printf("Invalid index");
        return 0;    
    }

    v->data[row] = val;
    return 1;

}

int getVal_v(vector *v, int row, double *out){
    if(v->rows <= row || row < 0 || !out){
        printf("Invalid index or output pointer");
        return 0;    
    }

    *out = v->data[row];
    return 1;
}

vector *add_v(vector *v1, vector *v2){
    if(!v1 || !v2 || v1->rows != v2->rows){
        printf("Vectors must have the same dimensions for addition");
        return NULL;    
    }

    vector *result = create_v(v1->rows);
    if(!result) return NULL;

    for(int i=0;i<v1->rows;i++){
        result->data[i] = v1->data[i] + v2->data[i];
    }
    return result;
}

vector *subtract_v(vector *v1, vector *v2){

    if(!v1 || !v2 || v1->rows != v2->rows){
        printf("Vectors must have the same dimensions for subtraction");
        return NULL;    
    }

    vector *result = create_v(v1->rows);
    if(!result) return NULL;

    for(int i=0;i<v1->rows;i++){
        result->data[i] = v1->data[i] - v2->data[i];
    }
    return result;
}

double dot_v(vector *v1, vector *v2){
    if(!v1 || !v2 || v1->rows != v2->rows){
        printf("Vectors must have the same dimensions for dot product");
        return -1;    
    }

    double result = 0;
    for (int i = 0; i<v1->rows;i++){
        result += v1->data[i] * v2->data[i];
    }
    return result;
}


vector *scale_v(vector *v, double scalar){

    if(!v){
        printf("Vector must not be NULL for scaling");
        return NULL;    
    }

    vector *result = create_v(v->rows);
    if(!result) return NULL;

    for(int i=0; i<v->rows;i++){
        result->data[i] = v->data[i] * scalar;    
    }
    return result;
}

double euclidean_distance(vector *v1, vector *v2){
    if(!v1 || !v2 || v1->rows != v2->rows){
        printf("Vectors must have the same dimensions for euclidean distance");
        return -1;
    }

    double sum = 0;
    for(int i=0; i<v1->rows;i++){
        sum += (v1->data[i] - v2->data[i]) * (v1->data[i] - v2->data[i]);
    }
    return sqrt(sum);
}


double manhattan_norm(vector *v){
    if(!v){
        printf("Vector must not be NULL for manhattan norm");
        return -1;    
    }

    double sum = 0;
    for(int i=0;i<v->rows;i++){
        sum += fabs(v->data[i]);
    }
    return sum;
}

double euclidean_norm(vector *v){
    if(!v){
        printf("Vector must not be NULL for euclidean norm");
        return -1;    
    }

    double sum_squares = 0;
    for(int i=0;i<v->rows;i++){
        sum_squares += v->data[i] * v->data[i];
    }
    return sqrt(sum_squares);
}

double norm_distance(vector *v1, vector *v2){
    if(!v1 || !v2 || v1->rows != v2->rows){
        printf("Vectors must have the same dimensions for norm distance");
        return -1;
    }

   vector *diff = subtract_v(v1,v2);
    if(!diff) return -1;

    double norm_dist = euclidean_norm(diff);
    free_v(&diff);

    return norm_dist;
}

vector *zeros(int size){
    if(size<=0){
        printf("Size must be greater than 0 for zeros vector");
        return NULL;
    }

    vector *result = create_v(size);
    if(!result) return NULL;

    for(int i=0;i<size;i++){
        result->data[i] = 0.0;
    }

    return result;
}

vector *ones(int size){
    if(size<=0){
        printf("Size must be greater than 0 for ones vector");
        return NULL;
    }

    vector *result = create_v(size);
    if(!result) return NULL;

    for(int i=0;i<size;i++){
        result->data[i] = 1.0;
    }

    return result;
}