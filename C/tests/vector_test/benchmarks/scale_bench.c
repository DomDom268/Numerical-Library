#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.h"
#include "vector.h"


int main(void){

    int trials = 10000;
    int size = 10000;

    BenchResults results = bench_scale(trials,size);

    printf("Average  time for the scale_v function: %.9f nanoseconds \n", results.average);
    printf("Max scale_v function time: %.8f nanoseconds \n", results.max);
    printf("Min scale_v function time: %.8f nanoseconds \n" , results.min);

    write_csv("benchmark_results.csv","scale_v",size,trials,results);

    return 0;

}