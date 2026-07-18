#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.h"
#include "vector.h"


int main(void){

    int trials = 10000;
    int size = 10000;

    BenchResults results = bench_euclidean_norm(trials,size);

    printf("Average  time for the euclidean_norm function: %.9f nanoseconds \n", results.average);
    printf("Max euclidean_norm function time: %.8f nanoseconds \n", results.max);
    printf("Min euclidean_norm function time: %.8f nanoseconds \n" , results.min);

    write_csv("benchmark_results.csv","euclidean_norm",size,trials,results);

    return 0;

}