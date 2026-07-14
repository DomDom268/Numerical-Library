#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int rows;
    double *data;
} vector;

vector *create_v(int rows);
void print_v(vector *v);
void free_v(vector *v);
int setVal_v(vector *v, int row, double val);
int getVal_v(vector *v, int row, double *out);
vector *add_v(vector *a, vector *b);
vector *subtract_v(vector *a, vector *b);
double dot_v(vector *a, vector *b);
vector *scale_v(vector *v, double scalar);
double euclidean_distance(vector *v1, vector *v2);
double manhattan_norm(vector *v);
double euclidean_norm(vector *v);
double norm_distance(vector *v1, vector *v2);
vector *zeros(int size);
vector *ones(int size);


#endif // VECTOR_H