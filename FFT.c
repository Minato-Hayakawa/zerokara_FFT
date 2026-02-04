#include "FFT.h"

stack saparate(stack *in){
    stack *out;
    int n = in -> head;
    for (int i=0; i < n / 2 ; i++){
    out -> data[i] = in -> data[in -> head*2];
    out -> data[i + n/2] = in -> data[in -> head*2 + 1];
    }return *out;
}
stack FFT(stack *in){
    stack out;
    stack weight;
    if (in -> head ==1);
    while (in -> head != 1){
        out = saparate(in);
    }

    for (int i = 1; i < N-1; i++){
        weight[i].real = in[i] * cos(2 * M_PI * t / i);
        weight[i].image = in[i] * (-sin(2 * M_PI * t / i));
    }
}