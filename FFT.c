#include "FFT.h"

stack DFT(stack *in){
    stack out;
    for (int i=0; i< in -> head; i++){
        out.data[i].real = 0;
        out.data[i].image = 0;
        for (int j=0; j< in -> head; j++){
            out.data[i].real += in->data[j].real * cos(2 * M_PI * i * j / in -> head);
            out.data[i].image += in->data[j].image * (-sin(2 * M_PI * i * j / in -> head));
        }
    }
    return out;
}

stack iDFT(stack *in){
    stack out;
    for (int i=0; i< in -> head; i++){
        out.data[i].real = 0;
        out.data[i].image = 0;
        for (int j=0; j< in -> head; j++){
            out.data[i].real += in->data[j].real * cos(2 * M_PI * i * j / in -> head) / in -> head;
            out.data[i].image += in->data[j].image * sin(2 * M_PI * i * j / in -> head) / in -> head;
        }
    } return out;
}

stack *saparate(stack *in){
    stack out;
    int n = in -> head;
    for (int i=0; i < n / 2 ; i++){
    out.data[i] = in -> data[in -> head * 2 * i];
    out.data[i + n/2] = in -> data[in -> head * 2 * i + 1];
    }return &out;
}

stack FFT(stack *in){
    stack *out;
    stack *weight;
    if (in -> head ==1);
    else if (in -> head != 1){
        out = saparate(in);
        FFT(out);
    }

    for (int i = 1; i < N-1; i++){
        weight[i].real = in[i] * cos(2 * M_PI * t / i);
        weight[i].image = in[i] * (-sin(2 * M_PI * t / i));
    }
}