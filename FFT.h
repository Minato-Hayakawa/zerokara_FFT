#define N 100

typedef struct {
    double real;
    double image;
} complex;

typedef struct{
    int head;
    complex data[N];
} stack;

void saparate(stack &in);
stack FFT(stack &in);
stack inverse_FFT(stack &in);