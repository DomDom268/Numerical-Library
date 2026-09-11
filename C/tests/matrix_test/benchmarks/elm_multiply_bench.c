/**
 * @file Matrix/elm_mul_bench.c
 * @brief File which runs and records the benchmarks for the matrix element multiplication function
*/

#include <stdio.h>
#include <stdlib.h>
#include "Matrix/matrix.h"
#include "Matrix/benchmark.h"

int main(void){

    int trials = 1000;
    int rows = 3;
    int cols = 3;

    BenchResults results = bench_elm_mul(trials,rows,cols);
    write_csv("MatrixBench.csv","elmMul",trials,rows,cols,results);

    return 0;
}
