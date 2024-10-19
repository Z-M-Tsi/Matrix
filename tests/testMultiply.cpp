/*
    * testMultiply.cpp
    * This file is used to benchmark the performance of matrix multiplication
    * between Matrix.h and native array.
*/

#include<iostream>
#include<chrono>
#include<random>
#include"../include/Matrix.h"

void benchmark(int n) {
    std::cout << "Benchmarking with size: " << n << "x" << n << "\n";

    mymatrix::Matrix<int> MA = mymatrix::Matrix<int>::randi(n, n, 0, 99);
    mymatrix::Matrix<int> MB = mymatrix::Matrix<int>::randi(n, n, 0, 99);

    double** A = new double*[n];
    double** B = new double*[n];
    
    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
        B[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            A[i][j] = MA(i, j);
            B[i][j] = MB(i, j);
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    double** C = new double*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Native Array Time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    mymatrix::Matrix<int> MC = MA * MB;
    end = std::chrono::high_resolution_clock::now();
    std::cout << "mymatrix Time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    std::cout << "Benchmarking finished!\n\n";


    for (int i = 0; i < n; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
}

int main(int argc, char* argv[]) {
    benchmark(64);
    benchmark(128);
    benchmark(256);
    benchmark(512);
    benchmark(1024);
    // benchmark(2048);
    return 0;
}