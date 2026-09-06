/**
 * @file test_basic.c
 * @brief Basic unit test for vector operations using the Unity framework. Ensures basic correctness of vector creation, manipulation, and mathematical operations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "Vector/vector.h"


#pragma message("Compiling test_basic.c")
void setUp(void)
{

}

void tearDown(void) 
{

}

/*Basic Create Test
*Ensuring that the create function initializes the vector correctly 
*and allocates memory for the data array.
*/
void test_create_basic(void){
    vector *v = create_v(4);
    TEST_ASSERT_NOT_NULL(v);
    TEST_ASSERT_EQUAL_INT(4, v->rows);
    free_v(&v);
}

/*Free Test
*Ensuring that the free function properly deallocates the vector's memory.
*/
void test_free_basic(void){
    vector *v = create_v(4);
    // TEST_ASSERT_NOT_NULL(v);
    
    free_v(&v);
    TEST_ASSERT_NULL(v);
}

/*Set Value and Get Value Test
*Ensuring that the set_v and get_v functions work correctly.
*
*Creates v = [0,0,0,0], sets v[2] = 5.0, and checks if v[2] is indeed 5.0.
*/
void test_setVal_basic(void){
    vector *v = create_v(4);
    int result = setVal_v(v, 2, 5.0);
    TEST_ASSERT_EQUAL_INT(1, result);

    double val;
    getVal_v(v, 2, &val);
    TEST_ASSERT_EQUAL_DOUBLE(5.0, val);

    free_v(&v);
}


/*Zeros Test
*Ensuring that the zeros function initializes the vector with all zero values.
*/
void test_zeros_basic(void){
    vector *v = zeros(4);
    for(int i=0;i<v->rows;i++){
        TEST_ASSERT_EQUAL_DOUBLE(0.0, v->data[i]);
    }
    free_v(&v);
}

/*Ones Test
*Ensuring that the ones function initializes the vector with all one values.
*/
void test_ones_basic(void){
    vector *v = ones(4);
   for(int i=0;i<v->rows;i++){
    TEST_ASSERT_EQUAL_DOUBLE(1.0,v->data[i]);
   }
    free_v(&v);
}

/*Addition Test
*Ensuring that the add_v function correctly adds two vectors.
*
*Property: a+b=c
*
*Expected: [1,2,3] + [4,5,6] = [5,7,9]
*/

void test_add_basic(void){
    vector *v1 = create_v(3);
    vector *v2 = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(v1,i,i+1.0); // v1 = [1,2,3]
        setVal_v(v2,i,i+4.0); // v2 = [4,5,6]
    }

    vector *v3 = add_v(v1, v2);

    TEST_ASSERT_NOT_NULL(v3);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, 5.0, v3->data[0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,7.0,v3->data[1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,9.0,v3->data[2]);

    free_v(&v1);
    free_v(&v2);
    free_v(&v3);
    
}

/*Subtraction Test
*Ensuring that the subtract_v function correctly subtracts two vectors.
*
*Property: a-b=c
*
*Expected: [4,5,6] + [1,2,3] = [3,3,3]
*/
void test_subtract_basic(void){
    vector *v1 = create_v(3);
    vector *v2 = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(v1,i,i+4.0); // v1 = [4,5,6]
        setVal_v(v2,i,i+1.0); // v2 = [1,2,3]
    }

    vector *v3 = subtract_v(v1, v2);

    TEST_ASSERT_NOT_NULL(v3);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, 3.0, v3->data[0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,3.0,v3->data[1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,3.0,v3->data[2]);

    free_v(&v1);
    free_v(&v2);
    free_v(&v3);
    
}

/*Dot product Test
*Ensuring that the dot product returns the expected value
*
*Property: a.b = ∑aibi
*
*Expected: [1,2,3].[4,5,6] = 32
*/
void test_dot_basic(void) {
    vector *v1 = create_v(3);
    vector *v2 = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(v1,i,i+1.0); // v1 = [1,2,3]
        setVal_v(v2,i,i+4.0); // v2 = [4,5,6]
    }

    double result = dot_v(v1, v2);

    TEST_ASSERT_NOT_EQUAL(-1,result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,32.0,result);

    free_v(&v1);
    free_v(&v2);
}

/*Vector Scaling Test
*Ensuring that the vector is scaled as expected
*
*Property: xv = [xv1 xv2 xv3]
*
*Expected: 2[1,2,3] = [2,4,6]
*/
void test_scale_basic(void){
    vector *v1 = create_v(3);
    double scalar = 2;

    for(int i=0;i<3;i++){
    setVal_v(v1,i,i+1.0); // v1 = [1,2,3]
    }

    vector *v3 = scale_v(v1,scalar);

    TEST_ASSERT_NOT_NULL(v3);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,2,v3->data[0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,4,v3->data[1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,6,v3->data[2]);

    free_v(&v1);
    free_v(&v3);

}

/*Basic Euclidean Distance Test
*Ensures that the distance function returns the expected value
*
*Property: d(a,b) = sqrt(∑(ai-bi)^2)
*
*Expected: d([1,2,3],[4,5,6]) = sqrt(27)
*/
void test_euclidean_distance_basic(void){
    vector *v1 = create_v(3);
    vector *v2 = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(v1,i,i+1.0); // v1 = [1,2,3]
        setVal_v(v2,i,i+4.0); // v2 = [4,5,6]
    }

    double result = euclidean_distance(v1,v2);

    TEST_ASSERT_NOT_EQUAL(-1,result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,sqrt(27),result);

    free_v(&v1);
    free_v(&v2);

}

/*Basic Euclidean Norm Test
*Ensures that the euclidean norm function returns the expected value
*
*Property: ||a|| = sqrt(∑(ai)^2)
*
*Expected: a=[1,2,3] ||a|| = sqrt(14)
*/
void test_euclidean_norm_basic(void){
    vector *v1 = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(v1,i,i+1.0); // v1 = [1,2,3]
    }

    double result = euclidean_norm(v1);

    TEST_ASSERT_NOT_EQUAL(-1,result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,sqrt(14.0),result);

    free_v(&v1);
}

/*Basic Manhattan Norm Test
*
*Property: ||a|| = ∑|ai|
*
*Expected: a = [1,2,3] ||a|| = 6.0
*/
void test_manhattan_norm_basic(void){
    vector *v1 = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(v1,i,i+1.0); // v1 = [1,2,3]
    }

    double result = manhattan_norm(v1);

    TEST_ASSERT_NOT_EQUAL(-1,result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,6.0,result);

    free_v(&v1);
}

/*Basic Distance/Norm Test
*
*Property: d(a,b) = ||a-b||
*/
void test_normm_distance_basic(void){
    vector *v1 = create_v(3);
    vector *v2 = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(v1,i,i+1.0); // v1 = [1,2,3]
        setVal_v(v2,i,i+4.0); // v2 = [4,5,6]
    }

    double result = norm_distance(v1,v2);

    TEST_ASSERT_NOT_EQUAL(-1,result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,sqrt(27),result);

    free_v(&v1);
    free_v(&v2);

}


