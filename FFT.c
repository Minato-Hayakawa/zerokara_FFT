#include "FFT.h"

stack saparate(stack &in){
    stack out;
    int n = in -> head;
    if (in -> head == 1);
    else {
        for (int i=0; i < n / 2 ; i++)
        out -> data[i] = in -> data[in -> head*2];
        out -> data[i + n/2] = in -> data[in -> head*2 + 1];
    }return out;
}
stack FFT(stack &in){
}