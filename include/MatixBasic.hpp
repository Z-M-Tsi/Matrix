#ifndef MATRIXBASIC_HPP
#define MATRIXBASIC_HPP
#include "Matrix.h"

namespace mymatrix {
template <typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data = new T[rows * cols];
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& M) : rows(M.rows), cols(M.cols) {
    data = new T[rows * cols];
    for (int i = 0; i < rows * cols; ++i)
        data[i] = M.data[i];
}

template <typename T>
Matrix<T>::~Matrix() {
    delete[] data;
}

template <typename T>
inline int Matrix<T>::get_rows() const {
    return rows;
}

template <typename T>
inline int Matrix<T>::get_cols() const {
    return cols;
}

template <typename T>
inline std::pair<int, int> Matrix<T>::size() const {
    return std::make_pair(rows, cols);
}

template <typename T>
Matrix<T> Matrix<T>::subMatrix(int init_row, int final_row, int init_col, int final_col) const {
    if (init_row < 0 || init_row >= rows || final_row < 0 || final_row >= rows || init_col < 0 || init_col >= cols || final_col < 0 || final_col >= cols)
        throw std::out_of_range("Index out of range");

    if (init_row > final_row || init_col > final_col)
        throw std::invalid_argument("Invalid submatrix range");

    int sub_rows = final_row - init_row + 1;
    int sub_cols = final_col - init_col + 1;
    Matrix<T> result(sub_rows, sub_cols);
    for (int i = init_row; i <= final_row; ++i)
        for (int j = init_col; j <= final_col; ++j)
            result.data[(i - init_row) * sub_cols + (j - init_col)] = data[i * cols + j];
    return result;
}

template <typename T>
void Matrix<T>::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            if (fabs(data[i * cols + j]) < 1e-6)
                std::cout << std::setw(6) << 0 << " ";
            else
                {std::cout << std::setw(6) << data[i * cols + j] << " ";}
        std::cout << std::endl;
    }
}
} // namespace mymatrix
#endif // MATRIXBASIC_HPP