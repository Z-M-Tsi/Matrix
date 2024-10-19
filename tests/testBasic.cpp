/*
    * testBasic.cpp
    * This file is used to test all basic matrix operations in Matrix.h,
    * including addition, subtraction, multiplication, transpose, and submatrix.
*/

#include <iostream>
#include "../include/Matrix.h"


void testBasic() {
    int size = 10;
    mymatrix::Matrix<int> A = mymatrix::Matrix<int>::randi(size, size, 0, 99);
    mymatrix::Matrix<int> B = mymatrix::Matrix<int>::randi(size, size, 0, 99);   
    std::cout << "Testing all basic matrix operations...\n";


    std::cout << "Begin to test addition...\n";
    mymatrix::Matrix<int> C = A + B;

    bool additionPassed = true;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (C(i, j) != A(i, j) + B(i, j)) {
                additionPassed = false;
                std::cerr << "Addition test failed at (" << i << ", " << j << ")!\n";
            }
        }
    }
    if (additionPassed) std::cout << "Addition test passed!\n";

    
    std::cout << "Begin to test subtraction...\n";
    mymatrix::Matrix<int> D = A - B;

    bool subtractionPassed = true;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (D(i, j) != A(i, j) - B(i, j)) {
                subtractionPassed = false;
                std::cerr << "Subtraction test failed at (" << i << ", " << j << ")!\n";
            }
        }
    }
    if (subtractionPassed) std::cout << "Subtraction test passed!\n";


    std::cout << "Begin to test multiplication...\n";
    mymatrix::Matrix<int> E = A * B;

    bool multiplicationPassed = true;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int sum = 0;
            for (int k = 0; k < size; ++k) {
                sum += A(i, k) * B(k, j);
            }
            if (E(i, j) != sum) {
                multiplicationPassed = false;
                std::cerr << "Multiplication test failed at (" << i << ", " << j << ")!\n";
            }
        }
    }
    if (multiplicationPassed) std::cout << "Multiplication test passed!\n";


    std::cout << "Begin to test transpose...\n";
    mymatrix::Matrix<int> F = A.transpose();

    bool transposePassed = true;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (F(i, j) != A(j, i)) {
                transposePassed = false;
                std::cerr << "Transpose test failed at (" << i << ", " << j << ")!\n";
            }
        }
    }
    if (transposePassed) std::cout << "Transpose test passed!\n";
    std::cout << "All functions tested successfully!\n";


    std::cout << "Begin to test index of submatrix...\n";
    mymatrix::Matrix<int> G = A.subMatrix(1, 3, 1, 3);

    bool subMatrixPassed = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (G(i, j) != A(i+1, j+1)) {
                subMatrixPassed = false;
                std::cerr << "Submatrix test failed at (" << i << ", " << j << ")!\n";
            }
        }
    }
    if (subMatrixPassed) std::cout << "Submatrix test passed!\n";

    std::cout << "All Basic functions tested successfully!\n";

}
