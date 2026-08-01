#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "matrix.h"

extern void test_add_commuitative(void);
extern void test_add_associative(void);
extern void test_additive_inverse(void);
extern void test_additive_identity(void);
extern void test_add_closure(void);
extern void test_add(void);
extern void test_scalar_associative(void);
extern void test_distributive_matrix_multiplication(void);
extern void test_distributive_scalar_addition(void);
extern void test_distributive_matrix_addition(void);
extern void test_scalar_multiplicative_inverse(void);
extern void test_scalar_multiplicative_identity(void);
extern void test_scalar_closure(void);
extern void test_scalar_comprehensive(void);
extern void test_hadamard_commutative(void);
extern void test_hadamard_associative(void);
extern void test_hadamard_distributive(void);
extern void test_hadamard_identity(void);
extern void test_hadamard_inverse(void);
extern void test_hadamard_zero(void);
extern void test_hadamard_closure(void);
extern void test_hadamard_comprehensive(void);
extern void test_non_commutative(void);
extern void test_multiply_associative(void);
extern void test_multiply_distributive(void);
extern void test_multiply_zero(void);
extern void test_multiply_identity(void);
extern void test_multiply_inverse(void);
extern void test_multiply_comprehensive(void);
extern void test_transpose_double(void);
extern void test_transpose_sum(void);
extern void test_transpose_product(void);
extern void test_scalar_transpose(void);
extern void test_transpose_comprehensive(void);

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_add);
    RUN_TEST(test_scalar_comprehensive);
    RUN_TEST(test_hadamard_comprehensive);
    RUN_TEST(test_multiply_comprehensive);
    RUN_TEST(test_transpose_comprehensive);
    
    return UNITY_END();
}