## Introduction

Welcome to the Matrix project for the **MATH6207H Scientific Computing** course at **Shanghai Jiao Tong University** (SJTU). 
This repository contains a C++ library named **Matrix**.
Its goal is to provide a simple, efficient, and flexible toolkit for performing linear algebra operations. 
This library offers fundamental matrix manipulation utilities and numerical methods essential for scientific computing.


We warmly welcome contributions to the project!
If you have any questions or suggestions, feel free to contact the author at: sjtucai2003@sjtu.edu.cn



## Table of Contents

- [Introduction](#introduction)
- [Table of Contents](#table-of-contents)
- [Features](#features)
- [Structure](#structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Quickstart](#quickstart)
- [To-do](#to-do)
- [License](#license)


## Features
* Matrix Creation: Supports creating matrices of different types(currenly includes `float` and `double`).
* Matrix Operations: Addition, subtraction, multiplication, and transposition.
* Determinants and Inverses: Efficient algorithms to compute determinants and matrix inverses.
* Decompositions: LU decomposition and other factorizations (currently includes modified Cholesky and QR).


## Structure
* `include/`: Header files defining the Matrix class, vector utilities, and key functions. 
* `tests/`: Unit tests to validate correctness of the operations.


## Requirements
* C++11 or later for modern syntax and memory management.
* CMake for building the project.


## Installation

To get started, clone the repository and install the necessary dependencies:

```bash
git clone https://github.com/Z-M-Tsi/Matrix.git
cd Matrix
```

After installation, you can check if the build was successful by running the tests:

```bash
cd tests
make all
make clean
```


## Quickstart

Here is a simple example of how to use the Matrix library:

```cpp
#include"Matrix.h"

int main(){
    // Create matrices
    mymatrix::Matrix<float> A(2, 2);
    std::cout << "A = " << std::endl;
    A.print()
    mymatrix::Matrix<float> B(2, 2);
    std::cout << "B = " << std::endl;
    B.print()

    // Perform operations
    mymatrix::Matrix<float> C = A + B;
    std::cout << "A + B = " << std::endl;
    C.print()

    return 0;
}
```


## To-do
These are the planned features to be implemented:
* Add support for complex-valued matrices.
* Implement solvers for linear system $Ax=b$.
* Implement Matrix norms.
* Implement eigenvalue and eigenvector computations.
* Add more matrix decomposition methods (e.g., SVD)
* Add compatibility with parallel computing (e.g., OpenMP, CUDA).
* Expand the test suite for robustness and reliability.
* Enhance documentation with detailed examples and use cases.

We welcome your contributions and ideas! Feel free to join us in building and refining the project.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.