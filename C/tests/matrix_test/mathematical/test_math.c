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

/*Associativity test for Matrix Addition
* Ensures the matrix add functions abides by the associative law
*Expected: A+(B+C) = (A+B)+C
*/
void test_add_associative(void){
    matrix *A = create(3,3);
    matrix *B = create(3,3);
    matrix *C = create(3,3);

    double A_val = 1;
    double B_val = 3;
    double C_val = 5;
    for(int i=0;i<A->rows;i++){
        for(int j=0;j<B->cols;j++){
            setVal(A,i,j,A_val++);
            setVal(B,i,j,B_val++);
            setVal(C,i,j,C_val++);
        }
    }

    matrix *result1 = mat_add(A,mat_add(B,C));
    matrix *result2  = mat_add(mat_add(A,B),C);
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
    free_matrix(&C);
    free_matrix(&result1);
    free_matrix(&result2);

}

/*Additive Inverse test for matrix addition
*Ensures the matrix add function abides by the additive inverse law
*Expected: A + (-A) = 0
*/
void test_additive_inverse(void){
    matrix *A = create(3,3);
    matrix *inv = create(3,3);

    double A_val = 3;
    double inv_val = -3;
    for(int i=0;i<A->rows;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
            setVal(inv,i,j,inv_val--);
        }
    }

    matrix *result = mat_add(A,inv);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[0][1]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[0][2]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[1][0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[1][1]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[2][1]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[2][0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[2][1]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[2][2]);

    free_matrix(&A);
    free_matrix(&inv);
    free_matrix(&result);
    
}

/*Additive Identity test for matrix addition
*Ensures matrix addition function abides by additive identity law
*Expected: A + 0 = A
*/
void test_additive_identity(void){
    matrix *A = create(3,3);
    matrix *Z = create(3,3);

    double A_val = 7;
    for(int i=0;i<A->rows;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
            setVal(Z,i,j,0.0);
        }
    }

    matrix *result = mat_add(A,Z);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_DOUBLE(7.0,result->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(8.0,result->data[0][1]);
    TEST_ASSERT_EQUAL_DOUBLE(8.0,result->data[0][2]);
    TEST_ASSERT_EQUAL_DOUBLE(10.0,result->data[1][0]);
    TEST_ASSERT_EQUAL_DOUBLE(11.0,result->data[1][1]);
    TEST_ASSERT_EQUAL_DOUBLE(12.0,result->data[2][1]);
    TEST_ASSERT_EQUAL_DOUBLE(13.0,result->data[2][0]);
    TEST_ASSERT_EQUAL_DOUBLE(14.0,result->data[2][1]);
    TEST_ASSERT_EQUAL_DOUBLE(15.0,result->data[2][2]);

    free_matrix(&A);
    free_matrix(&Z);
    free_matrix(&result);
}

/*Inverse test for matri addition
*Ensures that matrix addition function abides by the law
*Expected: A + A^-1 = I, where I is the identity matrix
*/
void test_inverse(void){
    matrix *A = create(2,2);
    matrix *A_inv = create(2,2);
    matrix *I = mat_identity(2);

    double A_val = 1;
    for(int i=0;i<A->rows;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
        }
    }

    setVal(A_inv,0,0,-2);
    setVal(A_inv,0,1,1);
    setVal(A_inv,1,0,1.5);
    setVal(A_inv,1,1,-0.5);

    matrix *result = mat_add(A,A_inv);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_DOUBLE(I->data[0][0],result->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(I->data[0][1],result->data[0][1]);
    TEST_ASSERT_EQUAL_DOUBLE(I->data[1][0],result->data[1][0]);
    TEST_ASSERT_EQUAL_DOUBLE(I->data[1][1],result->data[1][1]);

    free_matrix(&A);
    free_matrix(&A_inv);
    free_matrix(&I);
    free_matrix(&result);
}

/*Closure test for matrix addition
*Ensures the addition function abides by closure
*Expected: A+B=C ,where A,B,C are all mxn matrices
*/
void test_add_closure(void){
    matrix *A = create(3,3);
    matrix *B = create(3,3);

    double A_val = 53;
    double B_val = 18;
    for(int i=0;i<A->rows;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
            setVal(B,i,j,B_val++);
        }
    }

    matrix *result = mat_add(A,B);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_DOUBLE(3,result->rows);
    TEST_ASSERT_EQUAL_DOUBLE(3,result->cols);

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&result);
    
}

/*Comprehensive test for matrix addition function*/
void test_add(void){
    test_add_associative();
    test_add_commuitative();
    test_additive_identity();
    test_additive_inverse();
    test_add_closure();
    test_inverse();
}

/*Associativity Law for Matrix Scalar Multiplication
*Ensures matrix scalar multiplication abides by the associativity law
*Expected: r(sA) = (rs)A , where r,s e R
*/
void test_scalar_associative(void){
    matrix *A = create(3,3);
    double r = 3.0;
    double s = 4.0;

    double A_val = 5;
    for(int i=0;i<A->cols;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
        }
    }

    matrix *result1 = scalar_multiply(scalar_multiply(A,s),r);
    matrix *result2 = scalar_multiply(A,(r*s));
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
    free_matrix(&result1);
    free_matrix(&result2);

    
}

/*Scalar Distributive Test:(Over Matrix Multiplication)
*Ensures that scalar matrix mutiplication abides by the distributive law over matrix multiplication
*Expected: r(AB)= rA(B) = A(rB)
*/
void test_distributive_matrix_multiplication(void){
    matrix *A = create(3,3);
    matrix *B = create(3,3);
    double r = 4.0;

    double A_val = 5;
    double B_val = 7;
    for(int i=0;i<A->cols;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
            setVal(B,i,j,B_val++);
        }
    }

    matrix *result1 = scalar_multiply(mat_multiply(A,B),r);
    matrix *result2 = mat_multiply(scalar_multiply(A,r),B);
    matrix *result3 = mat_multiply(A,scalar_multiply(B,r));
    TEST_ASSERT_NOT_NULL(result1);
    TEST_ASSERT_NOT_NULL(result2);
    TEST_ASSERT_NOT_NULL(result3);

    //Asserting test for result 1 and 2
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[0][0],result2->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[0][1],result2->data[0][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[0][2],result2->data[0][2]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[1][0],result2->data[1][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[1][1],result2->data[1][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[1][2],result2->data[1][2]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[2][0],result2->data[2][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[2][1],result2->data[2][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[2][2],result2->data[2][2]);

    //Asserting test for result 2 and 3
    TEST_ASSERT_EQUAL_DOUBLE(result2->data[0][0],result3->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result2->data[0][1],result3->data[0][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result2->data[0][2],result3->data[0][2]);
    TEST_ASSERT_EQUAL_DOUBLE(result2->data[1][0],result3->data[1][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result2->data[1][1],result3->data[1][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result2->data[1][2],result3->data[1][2]);
    TEST_ASSERT_EQUAL_DOUBLE(result2->data[2][0],result3->data[2][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result2->data[2][1],result3->data[2][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result2->data[2][2],result3->data[2][2]);

    //Asserting test for result 1 and 3
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[0][0],result3->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[0][1],result3->data[0][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[0][2],result3->data[0][2]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[1][0],result3->data[1][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[1][1],result3->data[1][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[1][2],result3->data[1][2]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[2][0],result3->data[2][0]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[2][1],result3->data[2][1]);
    TEST_ASSERT_EQUAL_DOUBLE(result1->data[2][2],result3->data[2][2]);

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&result1);
    free_matrix(&result2);
    free_matrix(&result3);
    
}

/* Scalar Distributive Test:(Over Scalar Addition)
*Ensures that scalar matrix  multiplication abides by the distributive law over scalar addition
*Expected: (r+s)A = rA + rS
*/
void test_distributive_scalar_addition(void){
    matrix *A = create(3,3);
    double r  = 3.0;
    double s = 9.0;

    double A_val = 5;
    for(int i=0;i<A->cols;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
        }
    }

    matrix *result1 = scalar_multiply(A,(r+s));
    matrix *result2 = mat_add(scalar_multiply(A,s),scalar_multiply(A,r));
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
    free_matrix(&result1);
    free_matrix(&result2);

}

/*Scalar Distributive Test(Over Matrix Addition)
*Ensures that the scalar matrix multiplication function abides by the distributive law over matrix addition
*Expected: r(A+B) = rA+rB
*/
void test_distributive_matrix_addition(void){
    matrix *A = create(3,3);
    matrix *B = create(3,3);
    double r = 9.0;

    double A_val = 5;
    double B_val = 7;
    for(int i=0;i<A->cols;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
            setVal(B,i,j,B_val++);
        }
    }

    matrix *result1 = scalar_multiply(mat_add(A,B),r);
    matrix *result2 = mat_add(scalar_multiply(A,r),scalar_multiply(B,r));
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


/*Multiplicative Inverse Law test for matrix scalar multiplication
*Ensures matrix scalar multiplication abides by the multiplicative inverse law
*Expected AX0 = 0 
*/
void test_scalar_multiplicative_inverse(void){
    matrix *A = create(3,3);
    double multiplicative_inverse = 0.0;

    double A_val = 5;
    for(int i=0;i<A->cols;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
        }
    }

    matrix *result = scalar_multiply(A,multiplicative_inverse);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[0][1]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[0][2]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[1][0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[1][1]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[1][2]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[2][0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[2][1]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[2][2]);

    free_matrix(&A);
    free_matrix(&result);
}

/*Multiplicative Identity Law test for matrix scalar multiplication
*Ensures matrix scalar multiplication abides by the multiplicative identity law
*Expected: AX1 = A
*/
void test_scalar_multiplicative_identity(void){
    matrix *A = create(3,3);
    double multiplicative_identity = 1.0;

    double A_val = 5;
    for(int i=0;i<A->cols;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
        }
    }

    matrix *result = scalar_multiply(A,multiplicative_identity);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_DOUBLE(A->data[0][0],result->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(A->data[0][1],result->data[0][1]);
    TEST_ASSERT_EQUAL_DOUBLE(A->data[0][2],result->data[0][2]);
    TEST_ASSERT_EQUAL_DOUBLE(A->data[1][0],result->data[1][0]);
    TEST_ASSERT_EQUAL_DOUBLE(A->data[1][1],result->data[1][1]);
    TEST_ASSERT_EQUAL_DOUBLE(A->data[1][2],result->data[1][2]);
    TEST_ASSERT_EQUAL_DOUBLE(A->data[2][0],result->data[2][0]);
    TEST_ASSERT_EQUAL_DOUBLE(A->data[2][1],result->data[2][1]);
    TEST_ASSERT_EQUAL_DOUBLE(A->data[2][2],result->data[2][2]);

    free_matrix(&A);
    free_matrix(&result);
}

/*Closure test for scalar matrix multiplication
*Ensures that scalar matrix multiplication abides by the closure law
*Expected: A = rB , B is mxn if A is mxn
*/
void test_scalar_closure(void){
    matrix *A = create(3,3);
    double r = 3.0;

    double A_val = 5;
    for(int i=0;i<A->cols;i++){
        for(int j=0;j<A->cols;j++){
            setVal(A,i,j,A_val++);
        }
    }

    matrix *result = scalar_multiply(A,r);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_DOUBLE(3,result->rows);
    TEST_ASSERT_EQUAL_DOUBLE(3,result->cols);

    free_matrix(&A);
    free_matrix(&result);
}

/*Comprehensive test for scalar matrix multiplication*/
void test_scalar_comprehensive(void){
    test_scalar_associative();
    test_distributive_matrix_multiplication();
    test_distributive_scalar_addition();
    test_distributive_matrix_addition();
    test_scalar_multiplicative_inverse();
    test_scalar_multiplicative_identity();
    test_scalar_closure();
}

