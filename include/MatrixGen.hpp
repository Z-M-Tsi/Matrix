#ifndef MATRIXGEN_HPP
#define MATRIXGEN_HPP
#include "Matrix.h"

namespace mymatrix{
template <typename T>
Matrix<T> Matrix<T>::eyes(int n) {
    Matrix<T> result(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.data[i*n+j] = (i == j) ? 1 : 0;
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::zeros(int rows, int cols) {
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows*cols; ++i) {
        result.data[i] = 0;
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::ones(int rows, int cols) {
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows*cols; ++i) {
        result.data[i] = 1;
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::randi(int rows, int cols, int min, int max) {
    if (!std::is_integral<T>::value) {
        throw std::invalid_argument("randi only supports integral types.");
    }

    Matrix<T> result(rows, cols);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);  

    for (int i = 0; i < rows*cols; ++i) {
            result.data[i] = static_cast<T>(dis(gen));  
    }

    return result;
}

} // namespace mymatrix
#endif // MATRIXGEN_HPP