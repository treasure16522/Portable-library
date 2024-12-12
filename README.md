# Portable-library
Mini project idea for a portable library
Certainly! Below is a complete example of a README.md file incorporating all the information you provided. This format is compatible with GitHub Markdown (MD) syntax and is structured for clarity and usability.

```markdown
# Portable Matrix Library

This repository contains a portable library for matrix multiplication, Fourier transforms, and gradient descent optimization. The library is designed to be efficient and can be integrated into various programming languages.

## Table of Contents
- [Installation Guide](#installation-guide)
  - [Building the Library](#building-the-library)
- [Usage in Different Languages](#usage-in-different-languages)
  - [Python](#python)
  - [Rust](#rust)
  - [C++](#c)
  - [Java](#java)
- [Running Test Cases](#running-test-cases)
- [Key Points](#key-points)

## Installation Guide

### Building the Library
1. Clone the repository:
   ```bash
   git clone https://github.com/treasure16522/Portable-library.git
   cd Portable-library
   ```
2. Compile the library:
   - For Linux/macOS:
     ```bash
     gcc -shared -o libmatrix.so -fPIC mylibrary.c
     ```
   - For Windows:
     ```bash
     gcc -shared -o matrix.dll mylibrary.c
     ```

## Usage in Different Languages

### Python
1. Install `ctypes` if not already available.
2. Use the following example:
   ```python
   import ctypes

   lib = ctypes.CDLL('./libmatrix.so')
   lib.mat_mult.restype = None
   ```
  
### Rust
1. Add to `Cargo.toml`:
   ```toml
   [dependencies]
   libc = "0.2"
   ```
2. Use `libc` to call functions.

### C++
1. Include the header file:
   ```cpp
   extern "C" {
       void mat_mult(double* A, double* B, double* C, int n);
   }
   ```
2. Link with the shared library during compilation.

### Java
1. Create the Native Library:
   - Compile your C library into a shared object or dynamic link library:
     - On Linux/macOS:
       ```bash
       gcc -shared -o libmatrix.so -fPIC mylibrary.c
       ```
     - On Windows:
       ```cmd
       gcc -shared -o matrix.dll mylibrary.c
       ```
2. Write a Java Wrapper Class:
   - Use `System.loadLibrary()` to load your shared library at runtime.
   - Declare the native methods in your Java class using the `native` keyword.
3. Generate JNI Headers:
   - Compile your Java wrapper class and generate a .class file.
   - Use the `javah` tool (or `javac -h`) to generate a JNI header file:
     ```bash
     javac -h . WrapperClass.java
     ```
4. Implement the JNI Functions:
   - Implement the JNI functions in C that bridge Java and your library functions.
   - For example, `mat_mult` in Java will map to `Java_PackageName_WrapperClass_matMult` in C.
5. Compile and Link the JNI Implementation:
   - Compile the JNI implementation along with your library for seamless integration.
6. Run the Java Program:
   - Set the `java.library.path` system property to include the directory where your shared library is located:
     - On Linux/macOS:
       ```bash
       java -Djava.library.path=. YourJavaProgram
       ```
     - On Windows:
       ```cmd
       java -Djava.library.path=. YourJavaProgram
       ```

## Running Test Cases

To run the provided test cases in C (`fourier.c` and `matrix.c`) using the library (`mylibrary.dll` on Windows or `mylibrary.so` on Linux/macOS), follow these steps:

1. **Share the Compiled Library Only**: 
   - Provide the shared object file (`mylibrary.so` for Linux/macOS or `mylibrary.dll` for Windows) without sharing the source code (`mylibrary.c`).
   - Share the `mylibrary.h` header file to define the function prototypes required for test cases.

2. **Setup Environment**:
   - **Linux/macOS**:
     1. Place the `mylibrary.so` file in a known directory, e.g., `/usr/local/lib` or the current directory.
     2. Ensure the directory containing `mylibrary.so` is in the library path:
        ```bash
        export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
        ```
   - **Windows**:
     1. Place the `mylibrary.dll` file in the same directory as the test executable or in a directory listed in the system's PATH variable.

3. **Compile Test Cases**:
   - Use the `gcc` compiler to compile the test cases (`fourier.c` and `matrix.c`) into executables, linking against the shared library:
   - **Linux/macOS**:
     ```bash
     gcc -o fourier_test fourier.c -L. -lmylibrary -lm
     gcc -o matrix_test matrix.c -L. -lmylibrary -lm
     ```
   - **Windows**:
     ```cmd
     gcc -o fourier_test.exe fourier.c mylibrary.dll
     gcc -o matrix_test.exe matrix.c mylibrary.dll
     ```

4. **Run the Test Cases**:
   - After compiling, run the test cases, ensuring the shared library is accessible:
   - **Linux/macOS**:
     ```bash
     ./fourier_test
     ./matrix_test
     ```
   - **Windows**:
     ```cmd
     fourier_test.exe
     matrix_test.exe
     ```

5. **Verify Results**:
   - The outputs of the test cases (e.g., matrices for `matrix.c`, transformed data for `fourier.c`) will verify the functionality of `mylibrary.dll` or `mylibrary.so`.
   - Since the test executables link to the compiled library, the library's internal source code (`mylibrary.c`) remains hidden from the user.

## Key Points
- **Binary Distribution**: By providing only the compiled `.so` or `.dll` files, you retain ownership of your source code.
- **Interface Sharing**: Only share the `mylibrary.h` file to allow test cases to interact with the library.
- **Cross-Platform Use**: Provide both `.so` and `.dll` versions for compatibility across Linux/macOS and Windows.
## Functions

1. **`mat_mult(double* A, double* B, double* C, int n)`**:
   - Performs matrix multiplication for two n x n matrices. The result is stored in the matrix C.

2. **`dft(double complex* input, double complex* output, int n)`**:
   - Computes the Discrete Fourier Transform (DFT) of the input array, producing the transformed output in the specified output array.

3. **`gradient_descent(double (*func)(double), double (*grad)(double), double* x, double lr, int steps)`**:
   - Optimizes a given mathematical function using the gradient descent algorithm. It iteratively updates the value of x based on the learning rate (lr) and the gradient of the function for a specified number of steps.

4. **`mat_mult_c(double* A, double* B, double* C, int n)`** (Wrapper function for C interoperability):
   - A wrapper function to call `mat_mult` for compatibility with C/C++ interfaces.

5. **`dft_c(double complex* input, double complex* output, int n)`** (Wrapper function for C interoperability):
   - A wrapper function to call `dft` for compatibility with C/C++ interfaces.

6. **`gradient_descent_c(double (*func)(double), double (*grad)(double), double* x, double lr, int steps)`** (Wrapper function for C interoperability):
   - A wrapper function to enable calling `gradient_descent` easily from C/C++.
  
     
## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

```

### Notes on the Structure:
- Each section is clearly labeled for easy navigation.
- Code snippets are set off in code blocks for better readability.
- Items like the "Getting Started" and "Key Points" sections provide useful context for users.
- Make sure to replace or adjust any names (like `YourJavaProgram` or `WrapperClass.java`) and paths to match your actual project structure and naming conventions.

You can adjust and refine the content as needed to fit the specifics of your project and any additional information you want to add!
