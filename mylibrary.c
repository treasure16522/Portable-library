// mylibrary.c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

// Matrix multiplication
void mat_mult(double* A, double* B, double* C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i * n + j] = 0;
            for (int k = 0; k < n; k++) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}

// Fourier Transform (simple DFT)
void dft(double complex* input, double complex* output, int n) {
    for (int k = 0; k < n; k++) {
        output[k] = 0;
        for (int t = 0; t < n; t++) {
            double angle = -2.0 * M_PI * t * k / n;
            output[k] += input[t] * cexp(angle * I);
        }
    }
}

// Gradient Descent for optimization
void gradient_descent(double (*func)(double), double (*grad)(double), double* x, double lr, int steps) {
    for (int i = 0; i < steps; i++) {
        *x -= lr * grad(*x);
    }
}

// Example wrapper for portability
#ifdef __cplusplus
extern "C" {
#endif
    void mat_mult_c(double* A, double* B, double* C, int n) { mat_mult(A, B, C, n); }
    void dft_c(double complex* input, double complex* output, int n) { dft(input, output, n); }
    void gradient_descent_c(double (*func)(double), double (*grad)(double), double* x, double lr, int steps) {
        gradient_descent(func, grad, x, lr, steps);
    }
#ifdef __cplusplus
}
#endif
