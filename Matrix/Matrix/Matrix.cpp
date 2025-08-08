#include <iostream>
#include "Matrix.h"

Matrix::Matrix() {
    m = 0; 
    n = 0;
    p = nullptr;
}

Matrix::Matrix(const Matrix& other) {
    m = other.m;
    n = other.n;
    p = new double* [m];
    for (int i = 0; i < m; i++) {
        p[i] = new double[n];
        for (int j = 0; j < n; j++) {
            p[i][j] = other.p[i][j];
        }
    }
}

Matrix::Matrix(int rows, int cols) {
    m = rows;
    n = cols;
    p = new double* [m];
    for (int i = 0; i < m; i++) {
        p[i] = new double[n];
    }
}

Matrix::~Matrix() {
    clear();
}

void Matrix::clear() {
    if (p != nullptr) {
        for (int i = 0; i < m; i++) {
            delete[] p[i];
        }
        delete[] p;
        p = nullptr;
    }
    m = n = 0;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        clear();
        m = other.m;
        n = other.n;
        p = new double* [m];
        for (int i = 0; i < m; i++) {
            p[i] = new double[n];
            for (int j = 0; j < n; j++) {
                p[i][j] = other.p[i][j];
            }
        }
    }
    return *this;
}

bool Matrix::operator==(const Matrix& other) const {
    if (m != other.m || n != other.n) {
        return false;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (p[i][j] != other.p[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    if (m != other.m || n != other.n) {
        return true;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (p[i][j] != other.p[i][j]) {
                return false;
            }
        }
    }
    return false;
}

Matrix Matrix::operator+(const Matrix& other) {
    if (m != other.m || n != other.n) {
        throw std::invalid_argument("Matrix dimensions must agree");
    }
    Matrix result(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = p[i][j] + other.p[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) {
    if (m != other.m || n != other.n) {
        throw std::invalid_argument("Matrix dimensions must agree");
    }
    Matrix result(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = p[i][j] - other.p[i][j];
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    if (m != other.m || n != other.n) {
        throw std::invalid_argument("Matrix dimensions must agree");
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] += other.p[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (m != other.m || n != other.n) {
        throw std::invalid_argument("Matrix dimensions must agree");
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] -= other.p[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (n != other.m) {
        throw std::invalid_argument("Matrix dimensions must agree for multiplication");
    }
    Matrix res(m, other.n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < other.n; j++) {
            res.p[i][j] = 0;
            for (int k = 0; k < other.m; k++) {
                res.p[i][j] += p[i][k] * other.p[k][j];
            }
        }
    }
    return res;
}

void Matrix::transRewritten() {
    if (m != n) {
        throw std::runtime_error("Matrix must be square for in-place transposition");
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = p[i][j];
            p[i][j] = p[j][i];
            p[j][i] = temp;
        }
    }
}

Matrix Matrix::transNewMatrix() {
    Matrix res = Matrix(n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[j][i] = p[i][j];
        }
    }
    return res;
}

bool Matrix::isSymmetric() {
    if (m != n) {
        return false;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            if (p[i][j] != p[j][i]) {
                return false;
            }
        }
    }
    return true;
}

std::istream& operator>>(std::istream& in, Matrix& matrix) {
    for (int i = 0; i < matrix.m; ++i) {
        for (int j = 0; j < matrix.n; ++j) {
            in >> matrix.p[i][j];
        }
    }
    return in;
}

 std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (int i = 0; i < matrix.m; ++i) {
        for (int j = 0; j < matrix.n; ++j) {
            out << matrix.p[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

double* Matrix::operator[](int index) {
     if (index < 0 || index >= m) {
         throw std::out_of_range("Matrix row index out of range");
     }
     return p[index];
 }


double& Matrix::operator()(int i, int j) {
    if(i < 0 || i >= m || j < 0 || j >= n) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return p[i][j];
}
