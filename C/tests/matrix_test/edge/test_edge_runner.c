#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "Matrix/matrix.h"

extern void test_create_invalid(void);
extern void test_create_singular(void);
extern void test_invalid_dimensions(void);
extern void test_unequal_dimension(void);
extern void test_infinity(void);
extern void test_nan(void);
extern void test_overflow(void);


int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_create_invalid);
    RUN_TEST(test_create_singular);
    RUN_TEST(test_invalid_dimensions);
    RUN_TEST(test_unequal_dimension);
    RUN_TEST(test_infinity);
    RUN_TEST(test_nan);
    RUN_TEST(test_overflow);

    return UNITY_END();
}