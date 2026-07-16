#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.h"
#include "vector.h"

/*functiont hat returns benchmark results*/
BenchResults bench_create( int trials, int size){

    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){

        clock_t start = clock();

        vector *v = create_v(size);
        free_v(&v);

        clock_t end = clock();

        trial_time = ((double)(end - start) * 1e9) / CLOCKS_PER_SEC;
        
        if(i==0){ 

            min = trial_time;
            max = trial_time;

        } else if(trial_time < min){

            min = trial_time;

        } else if(trial_time > max){

            max = trial_time;
        }
        
        comprehensive_time_ns += trial_time;
    }

    BenchResults result;
    result.average = comprehensive_time_ns / trials; 
    result.max = max;
    result.min = min;

    return result;
    
}

/*function that writes to the csv to save the benchmark results*/
void write_csv (const char *filename, const char *function, int size, int trials, BenchResults results){

    FILE *file = fopen(filename, "a");


    if(file == NULL)
    {
        printf("Could not open CSV file\n");
        return;
    }


    fprintf(
        file,
        "%s,%d,%d,%.3f,%.3f,%.3f\n",
        function,
        size,
        trials,
        results.average,
        results.min,
        results.max
    );


    fclose(file);
}
