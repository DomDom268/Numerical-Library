/**
 * @file vector.h
 * @author Dominic Christopher
 * @brief A header file for vector operations. Including functions for creating, manipulating, and performing operations on vectors.
 * 
 */

#ifndef VECTOR_H
#define VECTOR_H
#pragma once
#include <stddef.h>

/** 
 * @brief A structure representing a vector. Includes the number of rows and a pointer to the data array.
 */
typedef struct {
    int rows;
    double *data;
} vector;

/**
 * @brief Allocates memory for a new vector with the specified number of rows.
 * @param rows The number of rows in the vector.
 * @return A pointer to the newly created vector.
 */
vector *create_v(int rows);
/**
 * @brief Prints the contents of the vector to the standard output.
 * @param v A pointer to the vector to be printed.
 */
void print_v(vector *v);
/**
 * @brief Frees the memory allocated for the vector.
 * @param v A pointer to the vector to be freed.
 */
void free_v(vector **v);
/**
 * @brief Sets the value of a specific row in the vector.
 * @param v A pointer to the vector.
 * @param row The row index.
 * @param val The value to set.
 * @return 0 on success, -1 on failure.
 */
int setVal_v(vector *v, int row, double val);
/**
 * @brief Gets the value of a specific row in the vector.
 * @param v A pointer to the vector.
 * @param row The row index.
 * @param out A pointer to store the retrieved value.
 * @return 0 on success, -1 on failure.
 */
int getVal_v(vector *v, int row, double *out);
/**
 * @brief Adds two vectors.
 * @param a A pointer to the first vector.
 * @param b A pointer to the second vector.
 * @return A pointer to the resulting vector.
 */
vector *add_v(vector *a, vector *b);
/**
 * @brief Subtracts the second vector from the first.
 * @param a A pointer to the first vector.
 * @param b A pointer to the second vector.
 * @return A pointer to the resulting vector.
 */
vector *subtract_v(vector *a, vector *b);
/**
 * @brief Computes the dot product of two vectors.
 * @param a A pointer to the first vector.
 * @param b A pointer to the second vector.
 * @return The dot product of the two vectors.
 */
double dot_v(vector *a, vector *b);
/**
 * @brief Scales a vector by a scalar value.
 * @param v A pointer to the vector.
 * @param scalar The scalar value.
 * @return A pointer to the resulting vector.
 */
vector *scale_v(vector *v, double scalar);
/**
 * @brief Computes the Euclidean distance between two vectors.
 * @param v1 A pointer to the first vector.
 * @param v2 A pointer to the second vector.
 * @return The Euclidean distance between the two vectors.
 */
double euclidean_distance(vector *v1, vector *v2);
/**
 * @brief Computes the distance between two vectors using the Manhattan norm.
 * @param v1 A pointer to the first vector.
 * @param v2 A pointer to the second vector.
 * @return The Manhattan distance between the two vectors.
 */
double norm_distance(vector *v1, vector *v2);

/**
 * @brief Computes the euclidean norm (L2 norm) of a vector.
 * @param v A pointer to the vector.
 * @return The euclidean norm of the vector.
 */
double euclidean_norm(vector *v);

/**
 * @brief Computes the Manhattan norm of a vector.
 * @param v A pointer to the vector.
 * @return The Manhattan norm of the vector.
 */
double manhattan_norm(vector *v);

/**
 * @brief Creates a vector filled with zeros.
 * @param size The number of rows in the vector.
 * @return A pointer to the newly created vector.
 */
vector *zeros(int size);
/**
 * @brief Creates a vector filled with ones.
 * @param size The number of rows in the vector.
 * @return A pointer to the newly created vector.
 */
vector *ones(int size);


#endif // VECTOR_H