/**
 * @file Matrix/id_bench.c
 * @brief File which runs and records the benchmarks for the matrix identity function
*/

#include <stdio.h>
#include <stdlib.h>
#include "Matrix/matrix.h"
#include "Matrix/benchmark.h"

int main(void){

    int trials = 1000;
    int rows = 3;
    int cols = 3;
    int size = rows*cols;

    BenchResults results = bench_id(trials,size);
    write_csv("MatrixBench.csv","id",trials,rows,cols,results);

    return 0;
}
