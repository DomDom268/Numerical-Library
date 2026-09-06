#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "Matrix/matrix.h"


#pragma message("Compiling test_basic.c for matrices")
void setUp(void)
{

}

void tearDown(void) 
{

}

/*Creation Edge Tests
*Ensures that all creation functions return NULL with invalid inputs
*m,n < 0 
*/
void test_create_invalid(void){
    matrix *A = create(-1,1);
    matrix *B = create(1,-1);
    matrix *C = create(-1,-1);
    matrix *D = mat_identity(0);
    matrix *E = mat_identity(-1);

    TEST_ASSERT_NULL(A);
    TEST_ASSERT_NULL(B);
    TEST_ASSERT_NULL(C);
    TEST_ASSERT_NULL(D);
    TEST_ASSERT_NULL(E);

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);
    free_matrix(&D);
    free_matrix(&E);
}

/*Singular Matrix Test
*Ensures that create functions do not return Null for singular creation
*m,n = 1
*/
void test_create_singular(void){
    matrix *A = create(1,1);
    matrix *B = mat_identity(1);

    TEST_ASSERT_NOT_NULL(A);
    TEST_ASSERT_NOT_NULL(B);

    free_matrix(&A);
    free_matrix(&B);
}

/*Invalid dimension tests for setVal and getVal functions
*Ensures NULL is returned when invalid indeces are passed 
* m,n < 0 || m,m >= rows,cols
*/
void test_invalid_dimensions(void){
    matrix *A = create(3,3);

    double A_val = 5.0;
    for(int i=0;i<A->rows;i++){
        for(int j=0;j<A->cols;j++){
                setVal(A,i,j,A_val++);
        }
    }

    double val;
    double A_status = setVal(A,4,4,4);
    double B_status = getVal(A,4,4,&val);

    TEST_ASSERT_EQUAL_INT16(0,A_status);
    TEST_ASSERT_EQUAL_INT16(0,B_status);

    free_matrix(&A);
}

/* Unequal Size Test
*Ensures that functions that require euqal size between matrics return 0
*Am != Bm || An != Bn
*/
void test_unequal_dimension(void){
    matrix *A = create(2,3);
    matrix *B = create(2,4);
    matrix *C = create(4,5);
    matrix *D = create(5,4);

    matrix *result1 = mat_add(A,B);
    matrix *result2 = mat_add(C,D);
    matrix *result3 = mat_subtract(A,B);
    matrix *result4 = mat_elm_multiply(C,D);
    TEST_ASSERT_NULL(result1);
    TEST_ASSERT_NULL(result2);
    TEST_ASSERT_NULL(result3);
    TEST_ASSERT_NULL(result4);

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);
    free_matrix(&D);
    free_matrix(&result1);
    free_matrix(&result2);
    free_matrix(&result3);
    free_matrix(&result4);
}

/*Infinity handling test for matrix addition, subtraction, scalar multiplication
*multiplication and element multiplication
*Expected: All functions to result in infinity due to infinity arithmetic invoved
*/
void test_infinity(void){
    matrix *A = create(2,2);
    matrix *B = create(2,2);

    double inf = INFINITY;
    double A_val = 3.0;
    double B_val = 8.0;
    

    for(int i=0;i<A->rows;i++){
        for(int j=0;j<A->cols;j++){
            if(i==0 && j==0){
                setVal(A,i,j,inf);
                setVal(B,i,j,1.0);
            }else{
                setVal(A,i,j,A_val++);
                setVal(B,i,j,B_val++);
            }
        }
    }

    matrix *check1 = mat_add(A,B);
    matrix *check2 = mat_subtract(B,A);
    matrix *check3 = scalar_multiply(A,3.0);
    matrix *check4 = mat_multiply(A,B);
    matrix *check5 = mat_elm_multiply(A,B);

    TEST_ASSERT_DOUBLE_IS_INF(check1->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_NEG_INF(check2->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_INF(check3->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_INF(check4->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_INF(check4->data[0][1]);
    TEST_ASSERT_DOUBLE_IS_INF(check5->data[0][0]);

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&check1);
    free_matrix(&check2);
    free_matrix(&check3);
    free_matrix(&check4);
    free_matrix(&check5);

}

/*NAN handling test for matrix addition, subtraction, scalar multiplication
*multiplication and element multiplication
*Expected: All functions to result in nan due to nan arithmetic involved
*/
void test_nan(void){
    matrix *A = create(2,2);
    matrix *B = create(2,2);

    double nan = NAN;
    double A_val = 3.0;
    double B_val = 8.0;
    

    for(int i=0;i<A->rows;i++){
        for(int j=0;j<A->cols;j++){
            if(i==0 && j==0){
                setVal(A,i,j,nan);
                setVal(B,i,j,1.0);
            }else{
                setVal(A,i,j,A_val++);
                setVal(B,i,j,B_val++);
            }
        }
    }

    matrix *check1 = mat_add(A,B);
    matrix *check2 = mat_subtract(B,A);
    matrix *check3 = scalar_multiply(A,3.0);
    matrix *check4 = mat_multiply(A,B);
    matrix *check5 = mat_elm_multiply(A,B);

    TEST_ASSERT_DOUBLE_IS_NAN(check1->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_NAN(check2->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_NAN(check3->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_NAN(check4->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_NAN(check4->data[0][1]);
    TEST_ASSERT_DOUBLE_IS_NAN(check5->data[0][0]);

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&check1);
    free_matrix(&check2);
    free_matrix(&check3);
    free_matrix(&check4);
    free_matrix(&check5);

}

/*Overflow test for matrix addition, subtraction, scalar multiplication
*multiplication and element multiplication
*Expected: All functions to overflow with DBL_MAX as one of the entries
*/
void test_overflow(void){
    matrix *A = create(2,2);

    double max = DBL_MAX;
    double A_val = 3.0;
    

    for(int i=0;i<A->rows;i++){
        for(int j=0;j<A->cols;j++){
            if(i==0 && j==0){
                setVal(A,i,j,max);
            }else{
                setVal(A,i,j,A_val++);
            }
        }
    }

    matrix *check1 = mat_add(A,A);
    matrix *check2 = scalar_multiply(A,3.0);
    matrix *check3 = mat_multiply(A,A);
    matrix *check4 = mat_elm_multiply(A,A);

    TEST_ASSERT_DOUBLE_IS_INF(check1->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_INF(check2->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_INF(check3->data[0][0]);
    TEST_ASSERT_DOUBLE_IS_INF(check3->data[0][1]);
    TEST_ASSERT_DOUBLE_IS_INF(check4->data[0][0]);

    free_matrix(&A);
    free_matrix(&check1);
    free_matrix(&check2);
    free_matrix(&check3);
    free_matrix(&check4);

}