#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "Vector/vector.h"

extern void test_create_invalid(void);
extern void test_create_singular(void);
extern void test_setval_invalid(void);
extern void test_getval_invalid(void);
extern void test_incorrect_dimension(void);
extern void test_infinity(void);
extern void test_nan(void);
extern void test_overflow(void);
extern void test_underflow(void);

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_create_invalid);
    RUN_TEST(test_create_singular);
    RUN_TEST(test_setval_invalid);
    RUN_TEST(test_getval_invalid);
    RUN_TEST(test_incorrect_dimension);
    RUN_TEST(test_infinity);
    RUN_TEST(test_nan);
    RUN_TEST(test_overflow);
    RUN_TEST(test_underflow);

    return UNITY_END();
}