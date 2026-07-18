#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.h"
#include "vector.h"


int main(void){

    int trials = 10000;
    int size = 10000;

    BenchResults results = bench_print(trials,size);

    printf("Average  time for the print_v function: %.9f nanoseconds \n", results.average);
    printf("Max print function time: %.8f nanoseconds \n", results.max);
    printf("Min print_v function time: %.8f nanoseconds \n" , results.min);

    write_csv("benchmark_results.csv","print_v",size,trials,results);

    return 0;

}