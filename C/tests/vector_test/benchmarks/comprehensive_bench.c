#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.h"
#include "vector.h"


int main(void){

    int trials = 10000;
    int size = 10000;

    BenchResults results = bench_comprehensive(trials,size);

    printf("Average  time for a comprehenmsive usage of functions: %.9f nanoseconds \n", results.average);
    printf("Max time for a comprehenmsive usage of functions: %.8f nanoseconds \n", results.max);
    printf("Min time for a comprehenmsive usage of functions: %.8f nanoseconds \n" , results.min);

    write_csv("benchmark_results.csv","comprehensive_v",size,trials,results);

    return 0;

}