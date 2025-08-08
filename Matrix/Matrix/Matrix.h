#pragma once
class Matrix {
    double** p;
    int m; 
    int n; 
public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    ~Matrix();

    Matrix& operator=(const Matrix& other);
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
    bool isSymmetric();

    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix operator*(const Matrix& other) const;
    
    void clear();
    void transRewritten();
    Matrix transNewMatrix();
    double* operator[](int index);
    double& operator()(int i, int j);

    friend std::istream& operator>>(std::istream& in, Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
};
