#include <stdio.h>
#include <complex.h>
#include "mylibrary.h"

int main() {
    double complex input[4] = {1, 2, 3, 4};
    double complex output[4];

    dft(input, output, 4);

    printf("DFT Result: \n");
    for (int i = 0; i < 4; i++) {
        printf("%f + %fi\n", creal(output[i]), cimag(output[i]));
    }

    return 0;
}