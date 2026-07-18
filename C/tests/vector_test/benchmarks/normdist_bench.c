#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.h"
#include "vector.h"


int main(void){

    int trials = 10000;
    int size = 10000;

    BenchResults results = bench_norm_dist(trials,size);

    printf("Average  time for the norm_dist function: %.9f nanoseconds \n", results.average);
    printf("Max norm_dist function time: %.8f nanoseconds \n", results.max);
    printf("Min norm_dist function time: %.8f nanoseconds \n" , results.min);

    write_csv("benchmark_results.csv","norm_dist",size,trials,results);

    return 0;

}