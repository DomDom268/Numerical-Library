#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "matrix.h"


#pragma message("Compiling test_basic.c for matrices")
void setUp(void)
{

}

void tearDown(void) 
{

}

/*Commutativity test for Matrix Addition
*Ensures that add function abides by commutativity law
*Expected: A+B = B+A
*/
void test_add_commuitative(void){
    matrix *A = create(3,3);
    matrix *B = create(3,3);

    double A_val = 1;
    double B_val = 5;
    for(int i=0;i<A->rows;i++){
        for(int j=0;j<B->rows;j++){
            setVal(A,i,j,A_val++);
            setVal(B,i,j,B_val++);
        }
    }

    matrix *result1 = mat_add(A,B);
    matrix *result2 = mat_add(B,A);
    TEST_ASSERT_NOT_NULL(result1);
    TEST_ASSERT_NOT_NULL(result2);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[0][0],result2->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[0][1],result2->data[0][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[0][2],result2->data[0][2]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[1][0],result2->data[1][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[1][1],result2->data[1][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[1][2],result2->data[1][2]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[2][0],result2->data[2][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[2][1],result2->data[2][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[2][2],result2->data[2][2]);

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&result1);
    free_matrix(&result2);


}