#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "vector.h"

double bench_create( int trials, int size){

    double comprehensive_time = 0;
    for(int i=0;i<trials;i++){

        clock_t start = clock();

        vector *v = create_v(size);
        free_v(&v);

        clock_t end = clock();

        double trial_time = (end-start);
        comprehensive_time += trial_time;
    }

    double avg_time_elapsed = comprehensive_time/ trials;
    
    return avg_time_elapsed;
}

int main(void){
    
    double bench_time = bench_create(1000,10);
    printf("Avergae time for the create_v function with over 1000 trials with size 10 vectors: %d", bench_time);

    return 0;
}
