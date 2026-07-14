#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

//Basic Create test
void test_create_basic(){
    vector *v = create_v(4);
    if(v->data == NULL){
        printf("Vector data not allocated");
        exit(1);
    }

    if(v->rows!= 4){
        printf("Vector created with incorrect dimensions");
        exit(1);
    } else{
        printf("Vector created successfully with %d rows\n", v->rows);
    }
    
    free_v(v);
}

//Edge cases create test
void test_edge_create(){
    vector *v = create_v(0);
    if(v != NULL){
        printf("Vector created with 0 rows, should have failed");
        exit(1);
    } else{
        printf("Vector creation failed as expected with 0 rows\n");
    }

    v = create_v(-5);
    if(v != NULL){
        printf("Vector created with negative rows, should have failed");
        exit(1);
    } else{
        printf("Vector creation failed as expected with negative rows\n");
    }
}

//Complete test for create function
void test_create(){
    test_create_basic();
    test_edge_create();
}

//Free test
void test_free(){
    vector *v = create_v(4);
    free_v(v);

    if(v->data != NULL || v->rows != 0){
        printf("Vector not freed properly");
        exit(1);
    } else{
        printf("Vector freed successfully\n");
    }
}

//Set and get value test
void test_setVal(){
    vector *v = create_v(4);
    int result = setVal_v(v, 2, 5.0);
    if(result != 1){
        printf("Failed to set value in vector");
        exit(1);
    }

    double val;
    getVal_v(v, 2, &val);
    if(val != 5.0){
        printf("Value not set correctly in vector");
        exit(1);
    } else{
        printf("Value set successfully in vector\n");
    }

    free_v(v);
}


//Zeros vector test
void test_zeros(){
    vector *v = zeros(4);
    if(!v){
        printf("Failed to create zero vector");
        exit(1);
    }

    double val = 0;
    for(int i=0;i<v->rows;i++){
        if(v->data[i] != 0.0){
            val ++;
            exit(1);
        }
    }
    if(val == 0){
        printf("Zero vector created successfully\n");
    } else{
        printf("Zero vector not created correctly\n");
        exit(1);
    }
    
    free_v(v);
}


//Ones vector test
void test_ones(){
    vector *v = ones(4);
    if(!v){
        printf("Failed to create ones vector");
        exit(1);
    }

    double val = 0;
    for(int i=0;i<v->rows;i++){
        if(v->data[i] != 1.0){
            val ++;
            exit(1);
        }
    }
    if(val == 0){
        printf("Ones vector created successfully\n");
    } else{
        printf("Ones vector not created correctly\n");
        exit(1);
    }
    
    free_v(v);
}

//Basic Add test
void test_add_basic(){
    vector *v1 = create_v(3);
    vector *v2 = create_v(3);

    setVal_v(v1, 0, 1.0);
    setVal_v(v1, 1, 2.0);
    setVal_v(v1, 2, 3.0);

    setVal_v(v2, 0, 4.0);
    setVal_v(v2, 1, 5.0);
    setVal_v(v2, 2, 6.0);

    vector *result = add_v(v1, v2);
    if(!result){
        printf("Failed to add vectors");
        exit(1);
    }

    double val;
    getVal_v(result, 0, &val);
    if(val != 5.0){
        printf("Addition result incorrect at index 0");
        exit(1);
    }

    getVal_v(result, 1, &val);
    if(val != 7.0){
        printf("Addition result incorrect at index 1");
        exit(1);
    }

    getVal_v(result, 2, &val);
    if(val != 9.0){
        printf("Addition result incorrect at index 2");
        exit(1);
    }

    printf("Vectors added successfully\n");

    free_v(v1);
    free_v(v2);
    free_v(result);
}

//Zero vector addition test
void test_add_zero(){
    vector *v1 = create_v(3);
    vector *v2 = zeros(3);

    setVal_v(v1, 0, 1.0);
    setVal_v(v1, 1, 2.0);
    setVal_v(v1, 2, 3.0);

    vector *result = add_v(v1, v2);
    if(!result){
        printf("Failed to add vectors");
        exit(1);
    }

    double val;
    getVal_v(result, 0, &val);
    if(val != 1.0){
        printf("Addition result incorrect at index 0");
        exit(1);
    }

    getVal_v(result, 1, &val);
    if(val != 2.0){
        printf("Addition result incorrect at index 1");
        exit(1);
    }

    getVal_v(result, 2, &val);
    if(val != 3.0){
        printf("Addition result incorrect at index 2");
        exit(1);
    }

    printf("Vectors added successfully with zero vector\n");

    free_v(v1);
    free_v(v2);
    free_v(result);

}

//Commutativity test for addition
void test_add_commutativity(){
    vector *v1 = create_v(3);
    vector *v2 = create_v(3);

    setVal_v(v1, 0, 1.0);
    setVal_v(v1, 1, 2.0);
    setVal_v(v1, 2, 3.0);

    setVal_v(v2, 0, 4.0);
    setVal_v(v2, 1, 5.0);
    setVal_v(v2, 2, 6.0);

    vector *result1 = add_v(v1, v2);
    vector *result2 = add_v(v2, v1);

    if(!result1 || !result2){
        printf("Failed to add vectors");
        exit(1);
    }

    for(int i=0;i<v1->rows;i++){
        double val1,val2;
        getVal_v(result1,i,&val1);
        getVal_v(result2,i,&val2);
        if(val1 != val2){
            printf("Addition is not commutative at index %d", i);
            exit(1);
        }
    }

    printf("Addition is commutative\n");

    free_v(v1);
    free_v(v2);
    free_v(result1);
    free_v(result2);

}

//Associativity test for addition
void test_add_associativity(){
    vector *v1 = create_v(3);
    vector *v2 = create_v(3);
    vector *v3 = create_v(3);

    setVal_v(v1, 0, 1.0);
    setVal_v(v1, 1, 2.0);
    setVal_v(v1, 2, 3.0);

    setVal_v(v2, 0, 4.0);
    setVal_v(v2, 1, 5.0);
    setVal_v(v2, 2, 6.0);

    setVal_v(v3, 0, 7.0);
    setVal_v(v3, 1, 8.0);
    setVal_v(v3, 2, 9.0);

    vector *result1 = add_v(add_v(v1,v2),v3);
    vector *result2 = add_v(v1,add_v(v2,v3));

    if(!result1 || !result2){
        printf("Failed to add vectors");
        exit(1);
    }

    for(int i=0;i<v1->rows;i++){
        double val1,val2;
        getVal_v(result1,i,&val1);
        getVal_v(result2,i,&val2);
        if(val1 != val2){
            printf("Addition is not associative at index %d", i);
            exit(1);
        }
    }

    printf("Addition is associative\n");

    free_v(v1);
    free_v(v2);
    free_v(v3);
    free_v(result1);
    free_v(result2);

}

//Dimension mismatch test for addition
void test_add_dimension_mismatch(){
    vector *v1 = create_v(3);
    vector *v2 = create_v(4);

    setVal_v(v1, 0, 1.0);
    setVal_v(v1, 1, 2.0);
    setVal_v(v1, 2, 3.0);

    setVal_v(v2, 0, 4.0);
    setVal_v(v2, 1, 5.0);
    setVal_v(v2, 2, 6.0);
    setVal_v(v2, 3, 7.0);

    vector *result = add_v(v1,v2);
    if(result != NULL){
        printf("Addition should have failed due to dimension mismatch");
        exit(1);
    } else{
        printf("Addition failed as expected due to dimension mismatch\n");
    }

    free_v(v1);
    free_v(v2);
}

//Add test
void test_add(){
    test_add_basic();
    test_add_zero();
    test_add_dimension_mismatch();
    test_add_commutativity();
    test_add_associativity();
}


int main(){
    test_create();
    test_free();
    test_setVal();
    test_zeros();
    test_ones();
    test_add();

    printf("All tests passed successfully\n");
    return 0;
}