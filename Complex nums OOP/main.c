#include <stdio.h>
#include <stdlib.h>


typedef struct Complex Complex;

struct Complex {
    double real;
    double imag;
    void (*conj)(Complex *);
};

void Conjugate(Complex *num) {
    num->imag = (-1) * num->imag;
}

Complex *NewComplex(double real, double imag) {
    Complex *num = malloc(sizeof(*num));
    num->real = real;
    num->imag = imag;
    num->conj = Conjugate;
    return num;
}

void PrintComplex(Complex *num) {
    printf("%.3f + %.3fi\n", num->real, num->imag);
}



int main() {
    Complex num = {.real = 1, .imag = 2};
    Complex *num2 = NewComplex(4, 5);

    PrintComplex(num2);
    Conjugate(num2);
    PrintComplex(num2);

    num2->conj(num2);

    // nvm oop stuff is stupid

    return 0;
}
