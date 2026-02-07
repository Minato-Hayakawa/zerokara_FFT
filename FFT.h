#define N 100
#include <math.h>
typedef struct {
    double real;
    double image;
} complex;

typedef struct{
    int head;
    complex data[N];
} stack;

stack DFT(stack *in);
stack *saparate(stack *in);
stack FFT(stack *in);
stack inverse_FFT(stack *in);