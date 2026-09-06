/**
 * @file create_bench.c
 * @brief This file contains the main function to benchmark the vector creation operation. It runs a specified number of trials for creating vectors of a given size and records the maximum, minimum, and average execution times. The results are printed to the console and written to a CSV file for further analysis.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.h"
#include "Vector/vector.h"


int main(void){

    // FILE *file = fopen("benchmark_results.csv","w");

    // fprintf(file, "function,size,trials,average,max,min\n");

    // fclose(file);
    
    int trials = 10000;
    int size = 10000;

    BenchResults results = bench_create(trials,size);

    printf("Average  time for the create_v function: %.9f nanoseconds \n", results.average);
    printf("Max create_v function time: %.8f nanoseconds \n", results.max);
    printf("Min create_v function time: %.8f nanoseconds \n" , results.min);

    write_csv("benchmark_results.csv","create_v",size,trials,results);

    return 0;

}
