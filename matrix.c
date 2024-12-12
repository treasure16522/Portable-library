#include <stdio.h>
#include "mylibrary.h"

int main() {
    double A[4] = {1, 2, 3, 4};
    double B[4] = {5, 6, 7, 8};
    double C[4];

    mat_mult(A, B, C, 2);

    printf("Result: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", C[i * 2 + j]);
        }
        printf("\n");
    }

    return 0;
}