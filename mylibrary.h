#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#include <complex.h>

#ifdef __cplusplus
extern "C" {
#endif

// Matrix Multiplication
void mat_mult(double* A, double* B, double* C, int n);

// Fourier Transform (DFT)
void dft(double complex* input, double complex* output, int n);

// Gradient Descent for Optimization
void gradient_descent(double (*func)(double), double (*grad)(double), double* x, double lr, int steps);

#ifdef __cplusplus
}
#endif

#endif // MYLIBRARY_H
