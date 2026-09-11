#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matrix/matrix.h"
#include "Matrix/benchmark.h"

/*Function that returns benchmark results for create*/
BenchResults bench_create(int trials, int rows, int cols){

    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<=trials;i++){

        clock_t start = clock();

        matrix *m = create(rows,cols);
        free_matrix(&m);

        clock_t end = clock();

        trial_time = ((double)(end-start)*1e9) / CLOCKS_PER_SEC;
        comprehensive_time_ns += trial_time;

        if(i==0){

            min = trial_time;
            max = trial_time;

        }else if(trial_time<min){

            min = trial_time;

        } else if(trial_time>max){

            max = trial_time;
        }
    }

    BenchResults result;
    result.average = comprehensive_time_ns/trials;
    result.min = min;
    result.max = max;

    return result;
}

/*Function to record becnhamark for setVal*/
BenchResults bench_set(int trials, int rows, int cols){

    double comprehensive_time_ns = 0;
    double trial_time;
    double min;
    double max;
    double size = rows*cols;
    matrix *m = create(rows,cols);

    for(int i =0;i<=trials;i++){

        clock_t start = clock();

        for(int j=0;j<=rows;j++){
            for(int k=0;k<=cols;k++){
                setVal(m,j,k,random_double());
            }
        }
        
        clock_t end = clock();

        trial_time = ((double)(end-start)*1e9) / CLOCKS_PER_SEC;
        comprehensive_time_ns += trial_time;

        if(i==0){
            min = trial_time;
            max = trial_time;
        } else if(trial_time<=min){
            min = trial_time;
        } else if(trial_time>=max){
            max = trial_time;
        }

    }

    free_matrix(&m);

    BenchResults results;
    results.average = comprehensive_time_ns/trials;
    results.max = max;
    results.min = min;

    return results;
}

/*Function to record benchmarks for getVal*/
BenchResults bench_get(int trials, int rows, int cols){
    double comprehensive_time_ns = 0;
    double trial_time;
    double min;
    double max;
    matrix *m = create(rows,cols);

    for(int j=0;j<=rows;j++){
        for(int k=0;k<=cols;k++){
            setVal(m,j,k,random_double());
        }
    }

    double val;
    
    for(int i=0;i<=trials;i++){
        clock_t start = clock();

        getVal(m,0,1,&val);

        clock_t end = clock();

        trial_time = ((double)(end-start)*1e9)/CLOCKS_PER_SEC;
        comprehensive_time_ns+=trial_time;

        if(i==0){
                min = trial_time;
                max = trial_time;
            } else if(trial_time<=min){
                min = trial_time;
            } else if(trial_time>=max){
                max = trial_time;
            }
    }

    free_matrix(&m);

    BenchResults results;
    results.average = comprehensive_time_ns/trials;
    results.max = max;
    results.min = min;

    return results;
}

/*Function to record benchmark for mat_add*/
BenchResults bench_add(int trials, int rows, int cols){
    double comprehensive_time_ns = 0;
    double trial_time;
    double min;
    double max;
    matrix *A = create(rows,cols);
    matrix *B = create(rows,cols);
    matrix *result = create(rows,cols);

    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            setVal(A,i,j,random_double());
            setVal(B,i,j,random_double());
        }
    }

    for(int k=0;k<=trials;k++){

        clock_t start = clock();
        
        result = mat_add(A,B);

        clock_t end = clock();

        trial_time = trialTime(start,end);
        comprehensive_time_ns+=trial_time;

        if(k==0){
                min = trial_time;
                max = trial_time;
            } else if(trial_time<=min){
                min = trial_time;
            } else if(trial_time>=max){
                max = trial_time;
            }
    }

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&result);

    BenchResults results;
    results.average = comprehensive_time_ns/trials;
    results.max = max;
    results.min = min;

    return results;
}

/*Function to record benchmark for mat_subtract*/
BenchResults bench_sub(int trials, int rows, int cols){
    double comprehensive_time_ns = 0;
    double trial_time;
    double min;
    double max;
    matrix *A = create(rows,cols);
    matrix *B = create(rows,cols);
    matrix *result = create(rows,cols);

    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            setVal(A,i,j,random_double());
            setVal(B,i,j,random_double());
        }
    }

    for(int k=0;k<=trials;k++){

        clock_t start = clock();
        
        result = mat_subtract(A,B);

        clock_t end = clock();

        trial_time = trialTime(start,end);
        comprehensive_time_ns+=trial_time;

        if(k==0){
                min = trial_time;
                max = trial_time;
            } else if(trial_time<=min){
                min = trial_time;
            } else if(trial_time>=max){
                max = trial_time;
            }
    }

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&result);

    BenchResults results;
    results.average = comprehensive_time_ns/trials;
    results.max = max;
    results.min = min;

    return results;
}
    
/*Function to record benchmark for scalar_multiply*/
BenchResults bench_scalar_multiply(int trials, int rows, int cols){
    double comprehensive_time_ns = 0;
    double trial_time;
    double min;
    double max;
    matrix *A = create(rows,cols);
    double scalar = random_double();
    matrix *result = create(rows,cols);

    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            setVal(A,i,j,random_double());
        }
    }

    for(int k=0;k<=trials;k++){

        clock_t start = clock();
        
        result = scalar_multiply(A,scalar);

        clock_t end = clock();

        trial_time = trialTime(start,end);
        comprehensive_time_ns+=trial_time;

        if(k==0){
                min = trial_time;
                max = trial_time;
            } else if(trial_time<=min){
                min = trial_time;
            } else if(trial_time>=max){
                max = trial_time;
            }
    }

    free_matrix(&A);
    free_matrix(&result);

    BenchResults results;
    results.average = comprehensive_time_ns/trials;
    results.max = max;
    results.min = min;

    return results;
}
    
/*Function to record benchmark for mat_multiply*/
BenchResults bench_multiply(int trials, int rows, int cols){
    double comprehensive_time_ns = 0;
    double trial_time;
    double min;
    double max;
    matrix *A = create(rows,cols);
    matrix *B = create(rows,cols);
    matrix *result = create(rows,cols);

    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            setVal(A,i,j,random_double());
            setVal(B,i,j,random_double());
        }
    }

    for(int k=0;k<=trials;k++){

        clock_t start = clock();
        
        result = mat_multiply(A,B);

        clock_t end = clock();

        trial_time = trialTime(start,end);
        comprehensive_time_ns+=trial_time;

        if(k==0){
                min = trial_time;
                max = trial_time;
            } else if(trial_time<=min){
                min = trial_time;
            } else if(trial_time>=max){
                max = trial_time;
            }
    }

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&result);

    BenchResults results;
    results.average = comprehensive_time_ns/trials;
    results.max = max;
    results.min = min;

    return results;
}

/*Function to record benchmark for mat_elm_multiply*/
BenchResults bench_elm_mul(int trials, int rows, int cols){
    double comprehensive_time_ns = 0;
    double trial_time;
    double min;
    double max;
    matrix *A = create(rows,cols);
    matrix *B = create(rows,cols);
    matrix *result = create(rows,cols);

    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            setVal(A,i,j,random_double());
            setVal(B,i,j,random_double());
        }
    }

    for(int k=0;k<=trials;k++){

        clock_t start = clock();
        
        result = mat_elm_multiply(A,B);

        clock_t end = clock();

        trial_time = trialTime(start,end);
        comprehensive_time_ns+=trial_time;

        if(k==0){
                min = trial_time;
                max = trial_time;
            } else if(trial_time<=min){
                min = trial_time;
            } else if(trial_time>=max){
                max = trial_time;
            }
    }

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&result);

    BenchResults results;
    results.average = comprehensive_time_ns/trials;
    results.max = max;
    results.min = min;

    return results;
}

/*Function to record benchmark for transpose*/
BenchResults bench_transpose(int trials, int rows, int cols){
    double comprehensive_time_ns = 0;
    double trial_time;
    double min;
    double max;
    matrix *A = create(rows,cols);
    matrix *result = create(rows,cols);

    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            setVal(A,i,j,random_double());
        }
    }

    for(int k=0;k<=trials;k++){

        clock_t start = clock();
        
        result = transpose(A);

        clock_t end = clock();

        trial_time = trialTime(start,end);
        comprehensive_time_ns+=trial_time;

        if(k==0){
                min = trial_time;
                max = trial_time;
            } else if(trial_time<=min){
                min = trial_time;
            } else if(trial_time>=max){
                max = trial_time;
            }
    }

    free_matrix(&A);
    free_matrix(&result);

    BenchResults results;
    results.average = comprehensive_time_ns/trials;
    results.max = max;
    results.min = min;

    return results;
}

/*Function to record benchmark for mat_identity*/
BenchResults bench_id(int trials,int size){
    double comprehensive_time_ns = 0;
    double trial_time;
    double min;
    double max;

    for(int k=0;k<=trials;k++){

        clock_t start = clock();
        
        matrix *I = mat_identity(size);
        free_matrix(&I);

        clock_t end = clock();

        trial_time = trialTime(start,end);
        comprehensive_time_ns+=trial_time;

        if(k==0){
                min = trial_time;
                max = trial_time;
            } else if(trial_time<=min){
                min = trial_time;
            } else if(trial_time>=max){
                max = trial_time;
            }
    }

    BenchResults results;
    results.average = comprehensive_time_ns/trials;
    results.max = max;
    results.min = min;

    return results;
}

/*Function to add bench results to csv*/
void write_csv(const char *fileName, const char *funcName,int trials,int rows,int cols,BenchResults results){

    FILE *file = fopen(fileName,"a");

    if(file==NULL){
        printf("Could not open CSV file\n");
        return;
    }

    double size = rows*cols;
    fprintf(
        file,
        "%s,%d,%d,%.3f,%.3f,%.3f\n",
        funcName,
        trials,
        size,
        results.average,
        results.min,
        results.max
    );

    fclose(file);
}

/*function to generate random doubles for vectors*/
double random_double() { return ((double)rand()/RAND_MAX)*20.0 - 10.0; }

/*Helper function to calculate the trial time*/
double trialTime(clock_t start, clock_t end){

    double time = ((double)(end-start)*1e9)/CLOCKS_PER_SEC;
    return time;

}