#include <stdio.h>

int main(void){
    FILE *file = fopen("MatrixBench.csv","w");

    fprintf(file, "function,trials,size,average,min,max\n");

    fclose(file);

    return 0;
}