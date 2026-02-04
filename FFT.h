#define N 100

typedef struct {
    double real;
    double image;
} complex;

typedef struct {
    int head;
    double data[N];
} stack;

void init(stack &data);
stack push(stack &data);
stack pop(stack &data);

stack FFT(stack &data);