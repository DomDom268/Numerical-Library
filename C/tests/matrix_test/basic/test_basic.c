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

/*Basic create test for matrix
*Ensures that the create function works as intended
*and allocates memory correctly
*/

void test_create_basic(void){
    matrix *a = create(3,3);
    TEST_ASSERT_NOT_NULL(a);
    TEST_ASSERT_EQUAL_INT(3,a->rows);
    TEST_ASSERT_EQUAL_INT(3,a->cols);
    free_matrix(&a);

}

/*Basic test for the freee_matrix function
*Ensures that the free_matrix function deallocates memory correctly
*/

void test_free_matrix_basic(void){
    matrix *a = create(3,3);

    free_matrix(&a);
    TEST_ASSERT_NULL(a);
}

/*Basic test for the setVal and getVal functions
*Creates m=[[0,0] [0,0]], sets m[1][2] = 6 and checks getVal(m[1][2]) == 6
*/
void test_set_get_basic(void){
    matrix *m = create(2,2);
    int set_status = setVal(m,0,1,6.0);
    TEST_ASSERT_NOT_EQUAL_INT(0,set_status);

    double val;
    int get_status = getVal(m,0,1,&val);
    TEST_ASSERT_NOT_EQUAL_INT(0,get_status);
    TEST_ASSERT_EQUAL_DOUBLE(6.0,val);

    free_matrix(&m);

}

/*Basic test for matrix addition
*Ensures mat_add function works as expected
*Expected a = [[1,2] [3,4]] b =[[5,6] [7,8]] and expects c = [[6,8] [10,12]]
*/
void test_mat_add_basic(void){
    matrix *a = create(2,2);
    matrix *b = create(2,2);

    double a_val = 1;
    double b_val = 5;

    for(int i=0;i<a->rows;i++){
        for(int j=0; j<b->cols;j++){
            setVal(a,i,j,a_val++);
            setVal(b,i,j,b_val++);
        }
    }

    matrix *result = mat_add(a,b);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,6.0,result->data[0][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,8.0,result->data[0][1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,10.0,result->data[1][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,12.0,result->data[1][1]);

    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&result);

}

/*Basic test for matrix subtraction
*Ensures mat_subtract works as intended
*Expected a = [[5,6] [7,8]] b =[[1,2] [3,4]] and expects c = [[4,4] [4,4]]
*/
void test_mat_subtract_basic(void){
    matrix *a = create(2,2);
    matrix *b = create(2,2);

    double a_val = 5;
    double b_val = 1;

    for(int i=0;i<a->rows;i++){
        for(int j=0; j<b->cols;j++){
            setVal(a,i,j,a_val++);
            setVal(b,i,j,b_val++);
        }
    }

    matrix *result = mat_subtract(a,b);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,4.0,result->data[0][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,4.0,result->data[0][1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,4.0,result->data[1][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,4.0,result->data[1][1]);

    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&result);
}

/*Basic test for scalar mulytiplication function
*Ensures scalar_multiply functions as intended
*Expected a=[[1,2] [3,4]] b = 5.0 c = [[5,10] [15,20]]
*/
void test_scalar_basic(void){
    matrix *m = create(2,2);
    double k = 5.0;
    double m_val = 1;

    for(int i=0;i<m->rows;i++){
        for(int j=0; j<m->cols;j++){
            setVal(m,i,j,m_val++);
        }
    }

    matrix *result = scalar_multiply(m,k);
    
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,5.0,result->data[0][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,10.0,result->data[0][1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,15.0,result->data[1][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,20.0,result->data[1][1]);

    free_matrix(&m);
    free_matrix(&result);


}

/*Basic test for element wise matrix multiplication
*Ensures that mat_elm_multiply functions as intended
*Expected a = [[5,6] [7,8]] b =[[1,2] [3,4]] and expects c = [[5,12] [21,32]]
*/
void test_mat_elm_multiply(void){
    matrix *a = create(2,2);
    matrix *b = create(2,2);

    double a_val = 5;
    double b_val = 1;

    for(int i=0;i<a->rows;i++){
        for(int j=0; j<b->cols;j++){
            setVal(a,i,j,a_val++);
            setVal(b,i,j,b_val++);
        }
    }

    matrix *result = mat_elm_multiply(a,b);

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,5.0,result->data[0][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,12.0,result->data[0][1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,21.0,result->data[1][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,32.0,result->data[1][1]);

    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&result);
}

/*Basic test for matrix multiplication
*Ensure the mat_multiply functions as intended
*Expected a = [[5,6] [7,8]] b =[[1,2] [3,4]] and expects c = [[23,34] [31,46]]
*/
void test_mat_multiply(void){
    matrix *a = create(2,2);
    matrix *b = create(2,2);

    double a_val = 5;
    double b_val = 1;

    for(int i=0;i<a->rows;i++){
        for(int j=0; j<b->cols;j++){
            setVal(a,i,j,a_val++);
            setVal(b,i,j,b_val++);
        }
    }

    matrix *result = mat_multiply(a,b);

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,23.0,result->data[0][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,34.0,result->data[0][1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,31.0,result->data[1][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,46.0,result->data[1][1]);

    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&result);
}

/*Basic test for matrix transposition
*Ensures that transpose functions as intended
*Expected a = [[5,6] [7,8]] aT = [[5,7] [6,8]]
*/
void test_transpose_basic(void){
    matrix *m = create(2,2);
    double m_val = 5;

    for(int i=0;i<m->rows;i++){
        for(int j=0; j<m->cols;j++){
            setVal(m,i,j,m_val++);
        }
    }

    matrix *result = transpose(m);
    
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,5.0,result->data[0][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,7.0,result->data[0][1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,6.0,result->data[1][0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,8.0,result->data[1][1]);

    free_matrix(&m);
    free_matrix(&result);

}

/*Basic test for the identity function
*Ensures that mat_identity functions as intended
*Expects to return a matrix with only 1s in the diagonal
*/
void test_mat_identity(void){
    
    matrix *identity = mat_identity(3);

    TEST_ASSERT_NOT_NULL(identity);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,identity->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,identity->data[1][1]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,identity->data[2][2]);

    free_matrix(&identity);


}