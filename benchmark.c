#include "FFT.h"
#include <time.h>
int main() {

    int n = 1024;
    int repeat = 1000;
    double max_error = 0.0;
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

    for(int i=0; i<n; i++){
        double cabs_DFT = sqrt(DFT(in)-> data[i].real * DFT(in)->data[i].real + DFT(in)->data[i].image * DFT(in)->data[i].image);
        double cabs_FFT = sqrt(FFT(in)-> data[i].real * FFT(in)->data[i].real + FFT(in)->data[i].image * FFT(in)->data[i].image);
        double error = cabs_DFT - cabs_FFT;
        if(error > max_error){
            max_error = error;
        }
    }
        printf("N = %d\n", n);
    printf("DFT time: %f sec (total for %d runs)\n", DFT_time, repeat);
    printf("FFT time: %f sec (total for %d runs)\n", FFT_time, repeat);
    printf("Maximam error between DFT and FFT: %20e\n", max_error);
    return 0;
}