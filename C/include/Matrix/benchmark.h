/**
 * @file Matrix/benchmark.c
 * @brief This header file contains function declarations for benchmarking matrix module functions
 */

 #include <time.h>
 #ifndef BENCHMARK_H
 #define BENCHMARK_H

 /** @brief Structure to store benchmark results */
 typedef struct {
    double max;
    double min;
    double average;
 } BenchResults;

/** @brief Function to benchmark matrix creation
 * @param trials Number of trials to run
 * @param rows Number of rows to create in matrix
 * @param cols Number of cols to create in matrix
 * @return BenchResults Structure containing the max,min and average times for the trials 
*/
BenchResults bench_create(int trials, int rows, int cols);

/** @brief Function to benchmark setting matrix values
 * @param trials Number of trials to run
 * @param rows Number of rows to create in matrix
 * @param cols Number of cols to create in matrix
 * @return BenchResults Structure containing the max,min and average times for the trials 
*/
BenchResults bench_set(int trials, int rows, int cols);

/** @brief Function to benchmark getting values from a matrix 
 * @param trials Number of trials to run
 * @param rows Number of rows to create in matrix
 * @param cols Number of cols to create in matrix
 * @return BenchResults Structure containing the max,min and average times for the trials 
*/
BenchResults bench_get(int trials, int rows, int cols);

/** @brief Function to benchmark matrix addition
 * @param trials Number of trials to run
 * @param rows Number of rows to create in matrix
 * @param cols Number of cols to create in matrix
 * @return BenchResults Structure containing the max,min and average times for the trials 
*/
BenchResults bench_add(int trials, int rows, int cols);

/** @brief Function to benchmark matrix subtraction
 * @param trials Number of trials to run
 * @param rows Number of rows to create in matrix
 * @param cols Number of cols to create in matrix
 * @return BenchResults Structure containing the max,min and average times for the trials 
*/
BenchResults bench_sub(int trials, int rows, int cols);

/** @brief Function to benchmark matrix scalar multiplication
 * @param trials Number of trials to run
 * @param rows Number of rows to create in matrix
 * @param cols Number of cols to create in matrix
 * @return BenchResults Structure containing the max,min and average times for the trials 
*/
BenchResults bench_scalar_multiply(int trials, int rows, int cols);

/** @brief Function to benchmark matrix multiplication
 * @param trials Number of trials to run
 * @param rows Number of rows to create in matrix
 * @param cols Number of cols to create in matrix
 * @return BenchResults Structure containing the max,min and average times for the trials 
*/
BenchResults bench_multiply(int trials, int rows, int cols);


/** @brief Function to benchmark matrix element multiplication
 * @param trials Number of trials to run
 * @param rows Number of rows to create in matrix
 * @param cols Number of cols to create in matrix
 * @return BenchResults Structure containing the max,min and average times for the trials 
*/
BenchResults bench_elm_mul(int trials, int rows, int cols);

/** @brief Function to benchmark matrix transposition
 * @param trials Number of trials to run
 * @param rows Number of rows to create in matrix
 * @param cols Number of cols to create in matrix
 * @return BenchResults Structure containing the max,min and average times for the trials 
*/
BenchResults bench_transpose(int trials, int rows, int cols);

/** @brief Function to benchmark identity matrix creation
 * @param trials Number of trials to run
 * @param size Size of the identity matrix to be created
 * @return BenchResults Structure containing the max,min and average times for the trials 
*/
BenchResults bench_id(int trials, int size);

/** @brief Function to save results to a csv file
 * @param fileName Name of the csv file
 * @param funcName Name of the function 
 * @param trials Number of trials
 * @param size Size of the matrix
 * @param results Bench results
*/
void write_csv(const char *fileName,const char *funcName,int trials,int rows,int cols,BenchResults reuslts);


/** @brief Function to generate a random value between 0 and 1
 * @return Random double value
 */
double random_double();

/** @brief Function to record trial time
 * @return trial time
 */
double trialTime(clock_t start,clock_t end);









































































 #endif // BENCHMARK_H