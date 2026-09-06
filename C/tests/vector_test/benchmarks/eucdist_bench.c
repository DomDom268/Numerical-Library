/**
 * @file eucdist_bench.c
 * @brief This file contains the main function to benchmark the vector Euclidean distance operation. It runs a specified number of trials for computing Euclidean distances between vectors of a given size and records the maximum, minimum, and average execution times. The results are printed to the console and written to a CSV file for further analysis.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.h"
#include "Vector/vector.h"


int main(void){

    int trials = 10000;
    int size = 10000;

    BenchResults results = bench_euclidean(trials,size);

    printf("Average  time for the euclidean_dist function: %.9f nanoseconds \n", results.average);
    printf("Max euclidean_distance function time: %.8f nanoseconds \n", results.max);
    printf("Min euclidean_distance function time: %.8f nanoseconds \n" , results.min);

    write_csv("benchmark_results.csv","euclidean_distance",size,trials,results);

    return 0;

}