#include "FFT.h"
#include <time.h>
int main() {

    int n = 8;
    int repeat = 100;
    stack *in = malloc(sizeof(stack));
    in->head = n;

    clock_t start = clock();
    for (int i=0; i < repeat; i++){
        DFT(in);
    }
    clock_t end = clock();

    double DFT_time = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    for (int i=0; i < repeat; i++){
        FFT(in);
    }
    end = clock();
    double FFT_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("N = %d\n", N);
    printf("DFT time: %f sec (total for %d runs)\n", DFT_time, repeat);
    printf("FFT time: %f sec (total for %d runs)\n", FFT_time, repeat);
    return 0;
}