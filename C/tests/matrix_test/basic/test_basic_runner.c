#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "matrix.h"

extern void test_create_basic(void);
extern void test_free_matrix_basic(void);
extern void test_set_get_basic(void);
extern void test_mat_add_basic(void);
extern void test_mat_subtract_basic(void);
extern void test_scalar_basic(void);
extern void test_mat_elm_multiply(void);
extern void test_mat_multiply(void);
extern void test_transpose_basic(void);

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_create_basic);
    RUN_TEST(test_free_matrix_basic);
    RUN_TEST(test_set_get_basic);
    RUN_TEST(test_mat_add_basic);
    RUN_TEST(test_mat_subtract_basic);
    RUN_TEST(test_scalar_basic);
    RUN_TEST(test_mat_elm_multiply);
    RUN_TEST(test_mat_multiply);
    RUN_TEST(test_transpose_basic);
    
    return UNITY_END();
}