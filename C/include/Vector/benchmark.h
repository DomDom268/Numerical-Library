/**
 * @file benchmark.h
 * @brief This header file contains function declarations for benchmarking various vector operations. It provides a structure to store benchmark results and functions to perform benchmarks on vector creation, addition, subtraction, dot product, scaling, and distance calculations.
 */


#ifndef BENCHMARK_H
#define BENCHMARK_H

/** @brief Structure to store benchmark results */
typedef struct {
    double max;
    double min;
    double average;
} BenchResults;


/** @brief Function to benchmark vector creation
 * @param trials Number of trials to run
 * @param size Size of the vector to create
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_create(int trials, int size);

/** @brief Function to benchmark setting vector values
 * @param trials Number of trials to run
 * @param size Size of the vector to set values for
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_setval(int trials, int size);

/** @brief Function to benchmark vector addition
 * @param trials Number of trials to run
 * @param size Size of the vectors to add
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_add(int trials, int size);

/** @brief Function to benchmark vector subtraction
 * @param trials Number of trials to run
 * @param size Size of the vectors to subtract
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_sub(int trials, int size);

/** @brief Function to benchmark dot product
 * @param trials Number of trials to run
 * @param size Size of the vectors to compute dot product for
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_dot(int trials, int size);

/** @brief Function to benchmark vector scaling
 * @param trials Number of trials to run
 * @param size Size of the vector to scale
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_scale(int trials, int size);

/** @brief Function to benchmark Euclidean distance calculation
 * @param trials Number of trials to run
 * @param size Size of the vectors to compute Euclidean distance for
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_euclidean(int trials, int size);

/** @brief Function to benchmark Euclidean norm calculation
 * @param trials Number of trials to run
 * @param size Size of the vector to compute Euclidean norm for
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_euclidean_norm(int trials, int size);

/** @brief Function to benchmark Manhattan norm calculation
 * @param trials Number of trials to run
 * @param size Size of the vector to compute Manhattan norm for
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_manhattan_norm(int trials, int size);

/** @brief Function to benchmark printing vector values
 * @param trials Number of trials to run
 * @param size Size of the vector to print
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_print(int trials, int size);

/** @brief Function to benchmark norm-based distance calculation
 * @param trials Number of trials to run
 * @param size Size of the vectors to compute norm-based distance for
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_norm_dist(int trials, int size);

/** @brief Function to benchmark comprehensive vector operations
 * @param trials Number of trials to run
 * @param size Size of the vectors to use in comprehensive benchmarking
 * @return BenchResults Structure containing max, min, and average times for the trials
 */
BenchResults bench_comprehensive(int trials, int size);

/** @brief Function to write benchmark results to a CSV file
 * @param filename Name of the CSV file to write results to
 * @param function Name of the function being benchmarked
 * @param size Size of the vectors used in the benchmark
 * @param trials Number of trials run
 * @param results Benchmark results to write
 */
void write_csv (const char *filename, const char *function, int size, int trials, BenchResults results);

/** @brief Function to generate a random double value between 0 and 1
 * @return Random double value
 */
double random_double();





















#endif // BENCHMARK_H