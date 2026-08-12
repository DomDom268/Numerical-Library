#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "vector.h"

void setUp(void)
{

}

void tearDown(void) 
{

}

/* Test to ensure that all creation functions returns NULL with invalid inputs
*
*Expected: create_v(x), zeros(x), ones(x) all return NULL if x<=0
*
*/
void test_create_invalid(void) {
    vector *a = create_v(0);
    vector *b = create_v(-5);
    vector *c = zeros(0);
    vector *d = zeros(-3);
    vector *e = ones(0);
    vector *f = ones(-6);

    TEST_ASSERT_NULL(a);
    TEST_ASSERT_NULL(b);
    TEST_ASSERT_NULL(c);
    TEST_ASSERT_NULL(d);
    TEST_ASSERT_NULL(e);
    TEST_ASSERT_NULL(e);

    free_v(&a);
    free_v(&b);
    free_v(&c);
    free_v(&d);
    free_v(&e);
    free_v(&f);
}

/*Test all creation funtions with singular vectors
*
*Expected create_v(1),zeros(1),ones(1) all return NOT NULL
*/
void test_create_singular(void){
    vector *a = create_v(1);
    vector *b = ones(1);
    vector *c = zeros(1);

    TEST_ASSERT_NOT_NULL(a);
    TEST_ASSERT_NOT_NULL(b);
    TEST_ASSERT_NOT_NULL(c);

    free_v(&a);
    free_v(&b);
    free_v(&c);
}


/*Test to ensure that setVal returns 0 with invalid index
*
*Expected setVal_v(idx) returns 0 if idx >= row || idx < 0
*
*/
void test_setval_invalid(void){
    vector *a = create_v(3);

    int result1 = setVal_v(a,-1,3.0);
    int result2 = setVal_v(a,8,9.0);

    TEST_ASSERT_EQUAL_INT16(0,result1);
    TEST_ASSERT_EQUAL_INT16(0,result2);

    free_v(&a);
}

/*Test to ensure that getVal returns 0 with invalid index
*
*Expected getVal_v(idx) returns 0 if idx >= row || idx < 0
*
*/
void test_getval_invalid(void){
    vector *a = create_v(3);
    double *out1;
    double *out2;

    int result1 = getVal_v(a,-1, out1);
    int result2 = getVal_v(a,5,out2);
    
    TEST_ASSERT_EQUAL_INT16(0,result1);
    TEST_ASSERT_EQUAL_INT16(0,result2);

    free_v(&a);
}

/* Test to ensure that incorret dimension fail with add,subtract,dot,distance functions
*
*Expected: if a->row = 3 and b->row = 4 then add_v(a,b) returns NULL
* subtract_v(a,b) returns NULL 
*dot_v(a,b) returns -1
*distance(a,b) returns -1 
*
*/
void test_incorrect_dimension(void){
    vector *a = create_v(2);
    vector *b = create_v(3);

    vector *check1 = add_v(a,b);
    vector *check2 = subtract_v(a,b);
    double check3 = dot_v(a,b);
    double check4 = euclidean_distance(a,b);
    double check5 = norm_distance(a,b);

    TEST_ASSERT_NULL(check1);
    TEST_ASSERT_NULL(check2);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0,check3);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0,check4);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0,check5);

    free_v(&a);
    free_v(&b);
    free_v(&check1);
    free_v(&check2);
}

/*Infinity handling test for addition, subtraction, dot product
* distances and norms
*
*Expected: all functions should resut in inf due to inf arithmetic
*
*/
void test_infinity(void){
    vector *a = create_v(1);
    vector *b = create_v(1);

    double inf = INFINITY;
    a->data[0] = inf;
    b->data[0] = 1;

    vector *check1 = add_v(a,b);
    vector *check2 = subtract_v(b,a);
    double check3 = dot_v(a,b);
    vector* check4 = scale_v(b,inf);
    double check5 = euclidean_distance(a,b);
    double check6 = manhattan_norm(a);
    double check7 = euclidean_norm(a);
    double check8 = norm_distance(a,b);


    TEST_ASSERT_DOUBLE_IS_INF(check1->data[0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,-inf,check2->data[0]);
    TEST_ASSERT_DOUBLE_IS_INF(check3);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,inf,check4->data[0]);
    TEST_ASSERT_DOUBLE_IS_INF(check5);
    TEST_ASSERT_DOUBLE_IS_INF(check6);
    TEST_ASSERT_DOUBLE_IS_INF(check7);
    TEST_ASSERT_DOUBLE_IS_INF(check8);

    free_v(&a);
    free_v(&b);
    free_v(&check1);
    free_v(&check2);
    free_v(&check4);
}

/*NAN handling test for addition, subtraction,dot product
*distances and norms
*
*Expected: all functions should result in nan due to nan arithmetic
*
*/
void test_nan(void){
    vector *a = create_v(1);
    vector *b = create_v(1);

    double nan = NAN;
    a->data[0] = nan;
    b->data[0] = 1;

    vector *check1 = add_v(a,b);
    vector *check2 = subtract_v(b,a);
    double check3 = dot_v(a,b);
    vector* check4 = scale_v(b,nan);
    double check5 = euclidean_distance(a,b);
    double check6 = manhattan_norm(a);
    double check7 = euclidean_norm(a);
    double check8 = norm_distance(a,b);
    

    TEST_ASSERT_DOUBLE_IS_NAN(check1->data[0]);
    TEST_ASSERT_DOUBLE_IS_NAN(check2->data[0]);
    TEST_ASSERT_DOUBLE_IS_NAN(check3);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,nan,check4->data[0]);
    TEST_ASSERT_DOUBLE_IS_NAN(check5);
    TEST_ASSERT_DOUBLE_IS_NAN(check6);
    TEST_ASSERT_DOUBLE_IS_NAN(check7);
    TEST_ASSERT_DOUBLE_IS_NAN(check8);

    free_v(&a);
    free_v(&b);
    free_v(&check1);
    free_v(&check2);
    free_v(&check4);
}

/*Overflow test for addition,dot product, 
*scalar multiplication and manhattan norm
*
*Expected: results should overflow if vectors contain DBL_MAX
*
*/
void test_overflow(void){
    vector *a = create_v(1);
    vector *b = create_v(1);

    double max = DBL_MAX;
    a->data[0] = max;
    b->data[0] = max;

    vector *check1 = add_v(a,b);
    double check2 = dot_v(a,b);
    vector *check3 = scale_v(a,2.0);

    TEST_ASSERT_DOUBLE_IS_INF(check1->data[0]);
    TEST_ASSERT_DOUBLE_IS_INF(check2);
    TEST_ASSERT_DOUBLE_IS_INF(check3->data[0]);

    free_v(&a);
    free_v(&b);
    free_v(&check1);
    free_v(&check3);
}

/*Underflow test for dot product, scalar multiplication, euclidean norm
*
*Expected results should underflow due to the mulitplication and squares
*
*/
void test_underflow(void){
    vector *a = create_v(1);
    vector *b = create_v(1);

    double min = DBL_TRUE_MIN;
    a->data[0] = min;
    b->data[0] = min;
    double k = 0.5;

    double check1 = dot_v(a,b);
    vector *check2 = scale_v(a,k);
    double check3 = euclidean_norm(a);

    TEST_ASSERT_EQUAL_DOUBLE(0.0,check1);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,check2->data[0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,check3);

    free_v(&a);
    free_v(&b);
    free_v(&check2);
    
}



