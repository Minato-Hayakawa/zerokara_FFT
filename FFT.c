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
    stack *out = malloc(sizeof(stack));
    out -> head = in -> head / 2;
    int n = in -> head;
    for (int i=0; i < n / 2 ; i++){
        out -> data[i] = in -> data[2 * i];
        out -> data[i + n/2] = in -> data[2 * i + 1];
    }return out;
}

stack *FFT(stack *in){
    stack *even = malloc(sizeof(stack));
    stack *odd = malloc(sizeof(stack));
    stack *out = malloc (sizeof(stack));

    even -> head = in -> head / 2;
    odd -> head = in -> head / 2;

    for (int i=0; i < in -> head / 2; i++){
        even -> data[i] = in -> data[2 * i];
        odd -> data[i] = in -> data[2 * i + 1];
    }

    if (in -> head ==1){
        stack *out = malloc(sizeof(stack));
        out->head = 1;
        out->data[0] = in->data[0];
        return out;
    }
    else if (in -> head != 1){
        stack *even_result = FFT(even);
        stack *odd_result = FFT(odd);
        for (int i=0; i < even_result -> head; i++){
            out -> data[i] = even_result -> data[i];
            out -> data[i + out -> head / 2] = odd_result -> data[i];
        }
    }
    for (int i=0; i < out-> head / 2; i++){
        double weight_real = cos(-2 * M_PI * i / out -> head);
        double weight_image = sin(-2 * M_PI * i / out -> head);
        
        double odd_real = out -> data[i + out -> head / 2].real * weight_real
        - out -> data[i + out -> head / 2].image * weight_image;
        double odd_image = out -> data[i + out -> head / 2].image * weight_real
        + out -> data[i + out -> head / 2].real * weight_image;
        double even_real = out -> data[i].real;
        double even_image = out -> data[i].image;

        out -> data[i].real = even_real + odd_real;
        out -> data[i].image = even_image + odd_image;
        out -> data[i + out -> head / 2].real = even_real - odd_real;
        out -> data[i + out -> head / 2].image = even_image - odd_image;
    }return out;
}