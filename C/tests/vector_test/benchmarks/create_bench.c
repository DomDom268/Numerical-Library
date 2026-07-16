#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "vector.h"


typedef struct {
    double max;
    double min;
    double average;
} BenchResults;

BenchResults bench_create( int trials, int size){

    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){

        clock_t start = clock();

        vector *v = create_v(size);
        free_v(&v);

        clock_t end = clock();

        trial_time = ((double)(end - start) * 1e9) / CLOCKS_PER_SEC;
        
        if(i==0){ 

            min = trial_time;
            max = trial_time;

        } else if(trial_time < min){

            min = trial_time;

        } else if(trial_time > max){

            max = trial_time;
        }
        
        comprehensive_time_ns += trial_time;
    }

    BenchResults result;
    result.average = comprehensive_time_ns / trials; 
    result.max = max;
    result.min = min;

    return result;
    
    
}

int main(void){
    
    BenchResults results = bench_create(100000,100000);
    printf("Average  time for the create_v function: %.9f nanoseconds \n", results.average);
    printf("Max create_v function time: %.8f nanoseconds \n", results.max);
    printf("Min create_v function time: %.8f nanoseconds \n" , results.min);

    return 0;

}
