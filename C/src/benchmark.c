#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.h"
#include "vector.h"

/*functiont that returns benchmark results for create_v*/
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

/*function that returns benchmark results for setval_v*/
BenchResults bench_setval(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){
        vector *v = create_v(size);

        clock_t start = clock();

        for (int j=0;j<size;j++){
                setVal_v(v,j,random_double());
        }

        clock_t end = clock();
        free_v(&v);

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

/*function that returns benchmark results for add_v*/
BenchResults bench_add(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){
        vector *a = create_v(size);
        vector *b = create_v(size);

        for (int j=0;j<size;j++){
                setVal_v(a,j,random_double());
                setVal_v(b,j,random_double());
        }

        clock_t start = clock();

        add_v(a,b);

        clock_t end = clock();

        free_v(&a);
        free_v(&b);
        
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

/*function that returns benchmark for vector subtraction*/
BenchResults bench_sub(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){
        vector *a = create_v(size);
        vector *b = create_v(size);

        for (int j=0;j<size;j++){
                setVal_v(a,j,random_double());
                setVal_v(b,j,random_double());
        }

        clock_t start = clock();

        subtract_v(a,b);

        clock_t end = clock();

        free_v(&a);
        free_v(&b);
        
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

/*function that returns benchmark for dot product function*/
BenchResults bench_dot(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){
        vector *a = create_v(size);
        vector *b = create_v(size);

        for (int j=0;j<size;j++){
                setVal_v(a,j,random_double());
                setVal_v(b,j,random_double());
        }

        clock_t start = clock();

        dot_v(a,b);

        clock_t end = clock();

        free_v(&a);
        free_v(&b);
        
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

/*function that returns benchmark for vector scaling function*/
BenchResults bench_scale(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;
    double scalar = random_double();

    for(int i=0;i<trials;i++){
        vector *a = create_v(size);

        for (int j=0;j<size;j++){
                setVal_v(a,j,random_double());
        }

        clock_t start = clock();

        vector *result = scale_v(a,random_double());

        clock_t end = clock();

        free_v(&a);
        free_v(&result);
        
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


/*function that returns benchmark for euclidean distance function*/
BenchResults bench_euclidean(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){
        vector *a = create_v(size);
        vector *b = create_v(size);

        for (int j=0;j<size;j++){
                setVal_v(a,j,random_double());
                setVal_v(b,j,random_double());
        }

        clock_t start = clock();

        double result = euclidean_distance(a,b);

        clock_t end = clock();

        free_v(&a);
        free_v(&b);
        
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

/*function that returns benchmark for euclidean norm function*/
BenchResults bench_euclidean_norm(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){
        vector *a = create_v(size);

        for (int j=0;j<size;j++){
                setVal_v(a,j,random_double());
        }

        clock_t start = clock();

        double result = euclidean_norm(a);

        clock_t end = clock();

        free_v(&a);
        
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

/*function that returns benchmark for euclidean norm function*/
BenchResults bench_manhattan_norm(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){
        vector *a = create_v(size);

        for (int j=0;j<size;j++){
                setVal_v(a,j,random_double());
        }

        clock_t start = clock();

        double result = manhattan_norm(a);

        clock_t end = clock();

        free_v(&a);
        
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

/*function that returns the benchmark for print function*/
BenchResults bench_print(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){
        vector *a = create_v(size);

        for (int j=0;j<size;j++){
            setVal_v(a,j,random_double());
        }

        clock_t start = clock();

        print_v(a);

        clock_t end = clock();

        free_v(&a);
        
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

/*function that returns the benchmark for norm_dist function*/
BenchResults bench_norm_dist(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){
        vector *a = create_v(size);
        vector *b = create_v(size);

        for (int j=0;j<size;j++){
            setVal_v(a,j,random_double());
            setVal_v(b,j,random_double());
        }

        clock_t start = clock();

        double result = norm_distance(a,b);

        clock_t end = clock();

        free_v(&a);
        free_v(&b);
        
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

/*function that benchmarks a combination of the functions 
*meant to simulate the usage of the functions* to find the angle between 2 scaled result vectors*/
BenchResults bench_comprehensive(int trials, int size){
    double comprehensive_time_ns = 0;
    double trial_time = 0;
    double min;
    double max;

    for(int i=0;i<trials;i++){
        clock_t start = clock();
        vector *a = create_v(size);
        vector *b = create_v(size);
        vector *c = create_v(size);
        vector *d = create_v(size);

        for (int j=0;j<size;j++){
            setVal_v(a,j,random_double());
            setVal_v(b,j,random_double());
            setVal_v(c,j,random_double());
            setVal_v(d,j,random_double());
        }

        /*Calculate result vectors*/
        vector *e = add_v(a,b);
        vector *f = subtract_v(d,c);

        /*Scale results*/
        e = scale_v(e,random_double());
        f = scale_v(f,random_double());

        /*Calculate dot product and norms*/
        double e_dot_f = dot_v(e,f);
        double e_norm = euclidean_norm(e);
        double f_norm = euclidean_norm(f);   

        /*Calculate angle*/
        double angle = acos(e_dot_f/(e_norm * f_norm));

        clock_t end = clock();

        free_v(&a);
        free_v(&b);
        free_v(&c);
        free_v(&d);
        free_v(&e);
        free_v(&f);
        
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

/*function to generate random doubles for vectors*/
double random_double() { return ((double)rand()/RAND_MAX)*20.0 - 10.0; }