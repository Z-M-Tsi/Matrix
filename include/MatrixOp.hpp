#ifndef MATRIXOP_HPP
#define MATRIXOP_HPP
#include "Matrix.h"

namespace mymatrix {
template <typename T>
inline T& Matrix<T>:: operator()(int i, int j)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw std::out_of_range("Index out of range");
    return data[i * cols + j];
}

template <typename T>
inline const T& Matrix<T>:: operator()(int i, int j) const
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw std::out_of_range("Index out of range");
    return data[i * cols + j];
}

template <typename T>
Matrix<T>& Matrix<T>:: operator=(const Matrix<T>& M)
{
    if (this == &M)
        return *this;
    rows = M.rows;
    cols = M.cols;
    data = M.data;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& M) const {
    if (rows != M.rows || cols != M.cols) 
        throw std::invalid_argument("Matrices must have the same dimensions for addition");

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows * cols; ++i) {
        result.data[i] = data[i] + M.data[i];
    }
    return result; 
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& M) const {
    if (rows != M.rows || cols != M.cols) 
        throw std::invalid_argument("Matrices must have the same dimensions for subtraction");

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows * cols; ++i) {
        result.data[i] = data[i] - M.data[i];
    }
    return result; 
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& M) const {
    if (cols != M.rows) 
        throw std::invalid_argument("Invalid dimensions for matrix multiplication");

    // Matrix<T> result(rows, M.cols);
    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < M.cols; ++j) {
    //         T sum = 0;
    //         for (int k = 0; k < cols; ++k) {
    //             sum += data[i*cols+k] * M.data[k*M.cols+j];
    //         }
    //         result.data[i*M.cols+j] = sum;
    //     }
    // }
    Matrix<T> result = zeros(rows, M.cols);
    for (int m = 0; m < rows; ++m) { // (m x k) * (k x n) = (m x n), mkn method
        for (int k = 0; k < cols; ++k) {
            for (int n = 0; n < M.cols; ++n) {
                result.data[m*M.cols+n] += data[m*cols+k] * M.data[k*M.cols+n];
            }
        }
    }
    return result;  
}

template <typename U>
Matrix<U> operator*(const U& scalar, const Matrix<U>& M) {
    Matrix<U> result(M.rows, M.cols);
    for (int i = 0; i < M.rows * M.cols; ++i) {
        result.data[i] = scalar * M.data[i];
    }
    return result;
}

template <typename U>
Matrix<U> operator*(const Matrix<U>& M, const U& scalar) {
    return scalar * M;
}

} // namespace mymatrix
#endif // MATRIXOP_HPP
