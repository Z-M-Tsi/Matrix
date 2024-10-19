/*
    * testDetandInv.cpp
    * This file is used to test the determinant and inverse of a matrix.
*/

#include"../include/Matrix.h"

void testDetandInv() {
    
    double eps = 1e-15; 
    int size = 3;

    mymatrix::Matrix<double> A(3, 3);
    A(0, 0) = 2.0; A(0, 1) = 1.0; A(0, 2) = 3.0;
    A(1, 0) = 1.0; A(1, 1) = 0.0; A(1, 2) = 2.0;
    A(2, 0) = 4.0; A(2, 1) = 1.0; A(2, 2) = 8.0;

    std::cout << "Begin to test inverse...\n";
    mymatrix::Matrix<double> B = A.inverse();
    mymatrix::Matrix<double> C = A * B;
    mymatrix::Matrix<double> D = B * A;
    mymatrix::Matrix<double> I = mymatrix::Matrix<double>::eyes(size);

    bool rightInversePassed = true;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (fabs(C(i, j) - I(i, j)) > eps) {
                rightInversePassed = false;
                std::cerr << "Right inverse test failed!\n";
                break;
            }
        }
    }
    if (rightInversePassed) std::cout << "Right inverse test passed!\n";

    bool leftInversePassed = true;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (fabs(D(i, j) - I(i, j)) > eps) {
                leftInversePassed = false;
                std::cerr << "Left inverse test failed!\n";
                break;
            }
        }
    }
    if (leftInversePassed) std::cout << "Left inverse test passed!\n";

    std::cout << "Begin to test determinant...\n";
    double standardDet = -1.0;
    double Adet = A.det();
    if (fabs(Adet - standardDet) > eps) {
        std::cerr << "Determinant test failed!\n";
    } else {
        std::cout << "Determinant test passed!\n";
    }

    std::cout << "Inverse and determinant tests passed!\n";
}