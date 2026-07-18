#ifndef BENCHMARK_H
#define BENCHMARK_H

typedef struct {
    double max;
    double min;
    double average;
} BenchResults;

BenchResults bench_create(int trials, int size);
BenchResults bench_setval(int trials, int size);
BenchResults bench_add(int trials, int size);
BenchResults bench_sub(int trials, int size);
BenchResults bench_dot(int trials, int size);
BenchResults bench_scale(int trials, int size);
BenchResults bench_euclidean(int trials, int size);
BenchResults bench_euclidean_norm(int trials, int size);
BenchResults bench_manhattan_norm(int trials, int size);
void write_csv (const char *filename, const char *function, int size, int trials, BenchResults results);
double random_double();





















#endif // BENCHMARK_H