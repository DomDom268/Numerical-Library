/**
 * @file comprehensive_bench.c
 * @brief This file contains the main function to benchmark comprehensive vector operations. It runs a specified number of trials for various vector operations of a given size and records the maximum, minimum, and average execution times. The results are printed to the console and written to a CSV file for further analysis.
 */

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