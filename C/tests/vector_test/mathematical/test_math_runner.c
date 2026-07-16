#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "vector.h"

extern void test_add_associativity(void);
extern void test_add_commutativity(void);
extern void test_add_identity(void);
extern void test_add_inverse(void);
extern void test_add_math(void);
extern void test_dot_commutativity(void);
extern void test_dot_distributive(void);
extern void test_dot_scalar(void);
extern void test_dot_zeros(void);
extern void test_dot_identity(void);
extern void test_dot_math(void);
extern void test_scalar_distributivity_vector(void);
extern void test_scalar_distributivity_scalar(void);
extern void test_scalar_identity(void);
extern void test_scalar_zero(void);
extern void test_scalar_zero(void);
extern void test_scalar_negate(void);
extern void test_scalar_math(void);
extern void test_manhattan_positive(void);
extern void test_euclideannorm_positive(void);
extern void test_norm_positive(void);
extern void test_euclideandistance_positive(void);
extern void test_euclideandistance_origin(void);
extern void test_euclideandistance_self(void);
extern void test_normdistance_positive(void);
extern void test_normdistance_origin(void);
extern void test_normdistance_self(void);
extern void test_distance_math(void);

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_add_math);
    RUN_TEST(test_dot_math);
    RUN_TEST(test_scalar_math);
    RUN_TEST(test_norm_positive);
    RUN_TEST(test_distance_math);

    return UNITY_END();
}
