#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.h"
#include "vector.h"


int main(void){

    // FILE *file = fopen("benchmark_results.csv","w");

    // fprintf(file, "function,size,trials,average,max,min\n");

    // fclose(file);
    
    int trials = 10000;
    int size = 10000;

    BenchResults results = bench_setval(10000,10000);

    printf("Average  time for the create_v function: %.9f nanoseconds \n", results.average);
    printf("Max create_v function time: %.8f nanoseconds \n", results.max);
    printf("Min create_v function time: %.8f nanoseconds \n" , results.min);

    write_csv("benchmark_results.csv","setVal_v",size,trials,results);

    return 0;

}