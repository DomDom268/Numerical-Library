#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "vector.h"

extern void test_create_basic(void);
extern void test_free_basic(void);
extern void test_setVal_basic(void);
extern void test_zeros_basic(void);
extern void test_ones_basic(void);
extern void test_add_basic(void);
extern void test_subtract_basic(void);
extern void test_dot_basic(void);
extern void test_scale_basic(void);
extern void test_euclidean_distance_basic(void);
extern void test_euclidean_norm_basic(void);
extern void test_manhattan_norm_basic(void);
extern void test_normm_distance_basic(void);

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_create_basic);
    RUN_TEST(test_free_basic);
    RUN_TEST(test_setVal_basic);
    RUN_TEST(test_zeros_basic);
    RUN_TEST(test_ones_basic);
    RUN_TEST(test_add_basic);
    RUN_TEST(test_subtract_basic);
    RUN_TEST(test_dot_basic);
    RUN_TEST(test_scale_basic);
    RUN_TEST(test_euclidean_distance_basic);
    RUN_TEST(test_euclidean_norm_basic);
    RUN_TEST(test_manhattan_norm_basic);
    RUN_TEST(test_normm_distance_basic);

    return UNITY_END();
}

