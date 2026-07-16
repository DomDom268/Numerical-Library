#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include "vector.h"

void setUp(void)
{

}

void tearDown(void)
{

}

/*Associativity Test for vector addition
*
*Property: (a+b)+c = a+(b+c)
*
*Expected 
*/
void test_add_associativity(void){
    vector *a = create_v(3);
    vector *b = create_v(3);
    vector *c = create_v(3);
    
    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
        setVal_v(b,i,i+4.0); // b = [4,5,6]
        setVal_v(c,i,i+7.0); // c = [7,8,9]
    }

    vector *result1 = add_v((add_v(a,b)),c);
    vector *result2 = add_v(a,add_v(b,c));
    
    TEST_ASSERT_NOT_NULL(result1);
    TEST_ASSERT_NOT_NULL(result2);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[0],result2->data[0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[1],result2->data[1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[2],result2->data[2]);

    free_v(&a);
    free_v(&b);
    free_v(&c);
    free_v(&result1);
    free_v(&result2);
}

/*Commutativity Test for addition function
*
*Property: a+b = b+a
*/
void test_add_commutativity(void){
    vector *a = create_v(3);
    vector *b = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
        setVal_v(b,i,i+4.0); // b = [4,5,6]
    }

    vector *result1 = add_v(a,b);
    vector *result2 = add_v(b,a);

    TEST_ASSERT_NOT_NULL(result1);
    TEST_ASSERT_NOT_NULL(result2);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[0],result2->data[0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[1],result2->data[1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[2],result2->data[2]);

    free_v(&a);
    free_v(&b);
    free_v(&result1);
    free_v(&result2);

}


/*Identity Addition test
*
*Property a+0 = a
*
*/
void test_add_identity(void){
    vector *a = create_v(3);
    vector *i = zeros(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a =[1,2,3]
    }

    vector *result = add_v(a,i);

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,a->data[0],result->data[0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,a->data[1],result->data[1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,a->data[2],result->data[2]);
    
    free_v(&a);
    free_v(&i);
    free_v(&result);
}

/*Additive Inverse Test
*
*Property a+(-a) = 0
*
*/
void test_add_inverse(void){
    vector *a = create_v(3);
    vector *i = create_v(3);
    
    for(int j=0;j<3;j++){
        setVal_v(a,j,j+1.0); // a=[1,2,3]
        setVal_v(i,j,-(j+1.0)); //b=[-1,-2,-3]
    }

    vector *result = add_v(a,i);

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[0]);

    free_v(&a);
    free_v(&i);
    free_v(&result);
}

/*Mathematical Property Test for the add function
*
*Comprehensive test for vector addition to ensure the mathematical properties are considered
*
*Includes Associativity, Commutativity, v+0 = v, v+(-v) = 0
*/
void test_add_math(void) {
    test_add_commutativity();
    test_add_associativity();
    test_add_identity();
    test_add_inverse();
}

/*Commutativity Test for Dot Product
*
*Property a.b = b.a
*
*/
void test_dot_commutativity(){
    vector *a = create_v(3);
    vector *b = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
        setVal_v(b,i,i+4.0); // b = [4,5,6]
    }

    double result1 = dot_v(a,b);
    double result2 = dot_v(b,a);

    TEST_ASSERT_NOT_EQUAL(-1,result1);
    TEST_ASSERT_NOT_EQUAL(-1,result2);
    TEST_ASSERT_EQUAL_DOUBLE(result1,result2);
    
    free_v(&a);
    free_v(&b);
    
}

/*Dot product distributive test
*
*Property: a.(b+c) = a.b +b.c
*
*/
void test_dot_distributive(void){
    vector *a = create_v(3);
    vector *b = create_v(3);
    vector *c = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
        setVal_v(b,i,i+4.0); // b = [4,5,6]
        setVal_v(c,i,i+7.0); // c = [7,8,9]
    }

    double result1 = dot_v(a,add_v(b,c));
    double result2 = dot_v(a,b) + dot_v(a,c);

    TEST_ASSERT_NOT_EQUAL(-1,result1);
    TEST_ASSERT_NOT_EQUAL(-1,result2);
    TEST_ASSERT_EQUAL_DOUBLE(result1,result2);

    free_v(&a);
    free_v(&b);
    free_v(&c);
    
}

/*Scalar distributive test
*
*Property: a.kb = k(a.b) 
*
*/
void test_dot_scalar(void){
    vector *a = create_v(3);
    vector *b = create_v(3);
    double k = 5.0;

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
        setVal_v(b,i,i+4.0); // b = [4,5,6]
    }
    
    double result1 = dot_v(a,scale_v(b,k));
    double result2 = k * (dot_v(a,b));

    TEST_ASSERT_NOT_EQUAL(-1,result1);
    TEST_ASSERT_NOT_EQUAL(-1,result2);
    TEST_ASSERT_EQUAL_DOUBLE(result1,result2);

    free_v(&a);
    free_v(&b);
    
}

/*Zero test for dot product
*
*Property: a.0 = O
*
*/
void test_dot_zeros(void){
    vector *a = create_v(3);
    vector *b = zeros(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); //a=[1,2,3]
    }

    double result = dot_v(a,b);

    TEST_ASSERT_NOT_EQUAL(-1,result);
    TEST_ASSERT_EQUAL_DOUBLE(0,result);

    free_v(&a);
    free_v(&b);
    
}

/* Identity test for dot product
*
*Property: a.1 = ∑ai
*
*/
void test_dot_identity(void){
    vector *a = create_v(3);
    vector *b = ones(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); //a=[1,2,3]
    }

    double result = dot_v(a,b);
    double norm = manhattan_norm(a);

    TEST_ASSERT_NOT_EQUAL(-1,result);
    TEST_ASSERT_EQUAL_DOUBLE(norm,result);

    free_v(&a);
    free_v(&b);
    
}

/*Mathematical Property Test for the dot product function
*
*Comprehensive test for dot product
*
*Includes commutativity, distributive, scalar, a.0,a.1
*/
void test_dot_math(){

    test_dot_commutativity();
    test_dot_distributive();
    test_dot_identity();
    test_dot_scalar();
    test_dot_zeros();
}


/* Distributivity test over vector addition for scalar 
*
*Property: k(v+w) = kw +kv
*
*/
void test_scalar_distributivity_vector(void){
    vector *a = create_v(3);
    vector *b = create_v(3);
    double k = 5.0;
    
    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
        setVal_v(b,i,i+4.0); // b = [4,5,6]
    }

    vector *result1 = scale_v(add_v(a,b),k);
    vector *result2 = add_v(scale_v(a,k),scale_v(b,k));

    TEST_ASSERT_NOT_NULL(result1);
    TEST_ASSERT_NOT_NULL(result2);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[0],result2->data[0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[1],result2->data[1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[2],result2->data[2]);

    free_v(&a);
    free_v(&b);
    free_v(&result1);
    free_v(&result2);
}

/* Distributivity test over scalar addition for  
*
*Property: (k+m)v = kv + km
*
*/
void test_scalar_distributivity_scalar(void){
    vector *a = create_v(3);
    double m = 3.0;
    double k = 5.0;
    
    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
    }

    vector *result1 = scale_v(a,(k+m));
    vector *result2 = add_v(scale_v(a,k),scale_v(a,m));

    TEST_ASSERT_NOT_NULL(result1);
    TEST_ASSERT_NOT_NULL(result2);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[0],result2->data[0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[1],result2->data[1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,result1->data[2],result2->data[2]);

    free_v(&a);
    free_v(&result1);
    free_v(&result2);
}

/*Multiplicative identity for scalar multiplication test
*
*Property: 1v = v
*
*/
void test_scalar_identity(void){
    vector *a = create_v(3);
    double k = 1.0;

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
    }

    vector *result = scale_v(a,k);

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,a->data[0],result->data[0]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,a->data[1],result->data[1]);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6,a->data[2],result->data[2]);

    free_v(&a);
    free_v(&result);
}

/*Multiplication by Zero test for scalar multiplication
*
*Property: a0 = 0 
*
*/
void test_scalar_zero(void){
    vector *a = create_v(3);
    double k = 0.0;

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
    }

    vector *result = scale_v(a,k);

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[1]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,result->data[2]);

    free_v(&a);
    free_v(&result);
}

/*Negation test for scalar multiplication
*
*Property: a(-1) = -a
*
*/
void test_scalar_negate(void){
    vector *a = create_v(3);
    double k = -1.0;

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
    }

    vector *result = scale_v(a,k);

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_DOUBLE(-(a->data[0]),result->data[0]);
    TEST_ASSERT_EQUAL_DOUBLE(-(a->data[1]),result->data[1]);
    TEST_ASSERT_EQUAL_DOUBLE(-(a->data[2]),result->data[2]);

    free_v(&a);
    free_v(&result);
}

/*Mathematical Property Test for vector scalar multiplication
*
*Comprehensive test for vector scalar multiplication
*
*Includes distributivity over scalar addition distributivity over vector addition, multiplicative identity, multiplication by zero, negation
*/
void test_scalar_math(){
    test_scalar_distributivity_scalar();
    test_scalar_distributivity_vector();
    test_scalar_identity();
    test_scalar_negate();
    test_scalar_zero();
}

/*Non-negativity test for Manhattan Norm
*
*Property" ||a|| >= 0
*
*/
void test_manhattan_positive(void){
    vector *a = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
    }

    double norm = manhattan_norm(a);

    TEST_ASSERT_NOT_EQUAL(-1.0,norm);
    TEST_ASSERT_GREATER_OR_EQUAL_DOUBLE(0.0,norm);

    free_v(&a);
}

/*Non-negativity test for euclidean norm
*
*Property: ||a|| >= 0
*
*/
void test_euclideannorm_positive(void){
    vector *a = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
    }

    double norm = euclidean_norm(a);

    TEST_ASSERT_NOT_EQUAL(-1.0,norm);
    TEST_ASSERT_GREATER_OR_EQUAL_DOUBLE(0.0,norm);

    free_v(&a);
}

/*Comprehensive test for non-negativity in norms
*
*Includes test for Manhattan and Euclidean norm
*/
void test_norm_positive(void){
    test_manhattan_positive();
    test_euclideannorm_positive();
}

/*Non-negativity test for euclidean distance
*
*Property d(a,b) >= 0
*
*
*/
void test_euclideandistance_positive(void){
    vector *a = create_v(3);
    vector *b = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
        setVal_v(b,i,i+4.0); // b = [4,5,6]
    }

    double distance = euclidean_distance(a,b);

    TEST_ASSERT_NOT_EQUAL(-1.0,distance);
    TEST_ASSERT_GREATER_OR_EQUAL_DOUBLE(0.0,distance);

    free_v(&a);
    free_v(&b);
}

/*Distance from origin test
*
*
*Property: d(a,0) = ||a||
*
*/
void test_euclideandistance_origin(void){
    vector *a = create_v(3);
    vector *o = zeros(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
    }

    double distance = euclidean_distance(a,o); 
    double norm = euclidean_norm(a);
    
    TEST_ASSERT_NOT_EQUAL(-1.0,distance);
    TEST_ASSERT_EQUAL_DOUBLE(norm,distance);

    free_v(&a);
    free_v(&o);
}

/*Distance from oneself test
*
*
*Property: d(a,b) = 0
*
*/
void test_euclideandistance_self(void){
    vector *a = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
    }

    double distance = euclidean_distance(a,a);

    TEST_ASSERT_NOT_EQUAL(-1.0,distance);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,distance);

    free_v(&a);
}   

/*Non-negativity test for norm distance
*
*Property d(a,b) >= 0
*
*
*/
void test_normdistance_positive(void){
    vector *a = create_v(3);
    vector *b = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
        setVal_v(b,i,i+4.0); // b = [4,5,6]
    }

    double distance = norm_distance(a,b);

    TEST_ASSERT_NOT_EQUAL(-1.0,distance);
    TEST_ASSERT_GREATER_OR_EQUAL_DOUBLE(0.0,distance);

    free_v(&a);
    free_v(&b);
}

/*Distance from origin test for norm distance
*
*
*Property: d(a,0) = ||a||
*
*/
void test_normdistance_origin(void){
    vector *a = create_v(3);
    vector *o = zeros(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
    }

    double distance = norm_distance(a,o); 
    double norm = euclidean_norm(a);
    
    TEST_ASSERT_NOT_EQUAL(-1.0,distance);
    TEST_ASSERT_EQUAL_DOUBLE(norm,distance);

    free_v(&a);
    free_v(&o);
}

/*Distance from oneself test for norm distance
*
*
*Property: d(a,b) = 0
*
*/
void test_normdistance_self(void){
    vector *a = create_v(3);

    for(int i=0;i<3;i++){
        setVal_v(a,i,i+1.0); // a = [1,2,3]
    }

    double distance = norm_distance(a,a);

    TEST_ASSERT_NOT_EQUAL(-1.0,distance);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,distance);

    free_v(&a);
}   

/*Comprehensive math test for both distance functions
*
*Includes all the above for both euclidean and norm distance calculations
*
*
*/
void test_distance_math(void){
    test_euclideandistance_origin();
    test_euclideandistance_positive();
    test_euclideandistance_self();
    test_norm_positive();
    test_normdistance_origin();
    test_normdistance_self();
}