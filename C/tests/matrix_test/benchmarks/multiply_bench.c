/**
 * @file Matrix/multiply_bench.c
 * @brief File which runs and records the benchmarks for the matrix multiplication function
*/

#include <stdio.h>
#include <stdlib.h>
#include "Matrix/matrix.h"
#include "Matrix/benchmark.h"

int main(void){

    int trials = 1000;
    int rows = 3;
    int cols = 3;

    BenchResults results = bench_multiply(trials,rows,cols);
    write_csv("MatrixBench.csv","multiply",trials,rows,cols,results);

    return 0;
}
