/*
    * Matrix.h
    * This is the header file for the Matrix class for dense matrices.
    * The class is templated to allow for different data types.
    * The class is designed to be used in numerical linear algebra.
    * The class supports basic matrix operations, 
    * such as addition, subtraction, multiplication, transpose, submatrix, etc.
    * The class also supports frequently used matrix generations,
    * such as identity matrix, zero matrix, one matrix, and random integer matrix.
*/


#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

namespace mymatrix{
template <typename T>
class Matrix {
private:
    int rows, cols;
    T* data;

    int selectPivot(int r) const;

    bool isSymmetric() const;
    Matrix<T> symPosiInverse() const;
    T symPosiDet() const;

public:
    // Constructors and Destructor
    Matrix(int rows, int cols);
    Matrix(const Matrix<T>& M);
    ~Matrix();
    
    // Getters
    int get_rows() const;
    int get_cols() const;
    std::pair<int, int> size() const;
    Matrix<T> subMatrix(int init_row, int final_row, int init_col, int final_col) const;
    void print() const;

    // Frequently used generations
    static Matrix<T> eyes(int n);
    static Matrix<T> zeros(int rows, int cols);
    static Matrix<T> ones(int rows, int cols);
    static Matrix<T> randi(int rows, int cols, int min, int max);

    // Overloaded operators 
    T& operator()(int i, int j);
    const T& operator()(int i, int j) const;
    Matrix<T>& operator=(const Matrix<T>& M);
    Matrix<T> operator+(const Matrix<T>& M) const;
    Matrix<T> operator-(const Matrix<T>& M) const;
    Matrix<T> operator*(const Matrix<T>& M) const;
    
    template <typename U>
    friend Matrix<U> operator*(const U& scalar, const Matrix<U>& M);
    template <typename U>
    friend Matrix<U> operator*(const Matrix<U>& M, const U& scalar);
    
    // Frequently used matrix self operations
    Matrix<T> transpose() const;
    Matrix<T> inverse(const std::string& flag = "") const;
    T det(const std::string& flag = "") const;

    // Matrix decompositions
    std::pair<Matrix<T>, std::pair<int, int>*> LU(const std::string& flag = "") const;
    Matrix<T> Cholesky() const;
    std::pair<Matrix<T>, Matrix<T>> QR() const;
    
};

} // namespace mymatrix

#include "MatrixPrivate.hpp"
#include "MatixBasic.hpp"
#include "MatrixOp.hpp"
#include "MatrixSelf.hpp"
#include "MatrixGen.hpp"
#include "MatrixDecomp.hpp"

#endif // MATRIX_H