#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "vector.h"

double bench_create( int trials, int size){

    double comprehensive_time_ns = 0;
    for(int i=0;i<trials;i++){

        clock_t start = clock();

        vector *v = create_v(size);
        free_v(&v);

        clock_t end = clock();

        comprehensive_time_ns += ((double)(end - start) * 1e9) / CLOCKS_PER_SEC;
    }

    return comprehensive_time_ns / trials;
    
    
}

int main(void){
    
    double bench_time = bench_create(1000,10);
    printf("Avergae time for the create_v function with over 1000 trials with size 10 vectors: %.9f nanoseconds", bench_time);

    return 0;
}
