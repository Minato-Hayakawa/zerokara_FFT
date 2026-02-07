#include "FFT.h"
int main() {

    int n = 8;
    stack *in = malloc(sizeof(stack));
    in->head = n;

    printf("--- Input Data ---\n");
    for (int i = 0; i < n; i++) {

        in->data[i].real = 100 * sin(2 * M_PI * 50 * i / n);
        in->data[i].image = 0.0;
        printf("data[%d]: %f + %fi\n", i, in->data[i].real, in->data[i].image);
    }
    printf("\n");

    stack *result = FFT(in);

    printf("--- FFT Result ---\n");
    for (int i = 0; i < n; i++) {
        printf("result[%d]: %f + %fi\n", i, result->data[i].real, result->data[i].image);
    }

    free(in);
    free(result);

    return 0;
}