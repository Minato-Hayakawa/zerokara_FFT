#include "FFT.h"

stack DFT(stack *in){
    stack out ;
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
        out.data[i] = in -> data[2 * i];
        out.data[i + n/2] = in -> data[2 * i + 1];
    }return &out;
}

stack *FFT(stack *in){
    stack *out = malloc (sizeof(stack));
    stack *saparated;

    if (in -> head ==1);
    else if (in -> head != 1){
        saparated = saparate(in);
        out = FFT(saparated);
    }
    for (int i=0; i < out-> head / 2; i++){
        double weight_real = cos(-2 * M_PI * i / out -> head);
        double weight_image = sin(-2 * M_PI * i / out -> head);
        complex *weight = malloc (sizeof(complex));
        weight -> real = weight_real;
        weight -> image = weight_image;
        double odd_real = out -> data[i + out -> head / 2].real * weight -> real
        - out -> data[i + out -> head / 2].image * weight -> image;
        double odd_image = out -> data[i + out -> head / 2].image * weight -> real
        + out -> data[i + out -> head / 2].real * weight -> image;
        double even_real = out -> data[i].real;
        double even_image = out -> data[i].image;

        out -> data[i].real = even_real + odd_real;
        out -> data[i].image = even_image + odd_image;
        out -> data[i + out -> head / 2].real = even_real - odd_real;
        out -> data[i + out -> head / 2].image = even_image - odd_image;
    }
    return out;
}