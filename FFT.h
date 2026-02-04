#define N 100

typedef struct {
    double real;
    double image;
} complex;

complex FFT(complex &in);
complex inverse_FFT(complex &in);