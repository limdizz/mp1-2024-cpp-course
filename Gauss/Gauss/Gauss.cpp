#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

void fillMatrix(double** matrix, int n) {
    if (n > 3) {
        double range = 0;
        cout << "Enter the range of numbers in the matrix: ";
        cin >> range;
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = (double)rand() / RAND_MAX * (range - 0.01) + 0.01;
            }
        }
    }
    else {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
    }
}

void printMatrix(double** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

void fillVector(double* vector, int n) {
    if (n <= 3) {
        cout << "Enter the vector elements:" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> vector[i];
        }
    }
    else {
        double range = 0.0;
        cout << "Enter the range of numbers in the vector: ";
        cin >> range;
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            vector[i] = (double)rand() / RAND_MAX * (range - 0.01) + 0.01;
        }
    }
}

void printVector(double* vector, int n) {
    for (int i = 0; i < n; ++i) {
        cout << vector[i] << "  ";
    }
    cout << endl;
}

void matrixVectorProduct(double** matrix, double* vector, double* result, int n) {
    for (int i = 0; i < n; ++i) {
        result[i] = 0;
        for (int j = 0; j < n; ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

double check(double** A, double* x, double* B, int n) {
    double maxDiff = 0.0;
    double* Ax = new double[n];
    matrixVectorProduct(A, x, Ax, n);
    for (int i = 0; i < n; ++i) {
        double diff = abs(Ax[i] - B[i]);
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }
    delete[] Ax;
    return maxDiff;
}

void solveGauss(double** a, double* x, double* b, int n) {
    for (int j = 0; j < n - 1; j++) {
        for (int i = j + 1; i < n; i++) {
            double alpha = a[i][j] / a[j][j];
            for (int k = j; k < n; k++) {
                a[i][k] -= alpha * a[j][k];
            }
            b[i] -= alpha * b[j];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }
}

void solveGaussModified(double** a, double* x, double* b, int n) {
    for (int j = 0; j < n - 1; j++) {
        int maxRow = j;
        double maxVal = a[j][j];
        for (int i = j + 1; i < n; i++) {
            if (abs(a[i][j]) > abs(maxVal)) {
                maxVal = a[i][j];
                maxRow = i;
            }
        }

        if (maxRow != j) {
            swap(a[j], a[maxRow]);
            swap(b[j], b[maxRow]);
        }

        for (int i = j + 1; i < n; i++) {
            double alpha = a[i][j] / a[j][j];
            for (int k = j; k < n; k++) {
                a[i][k] -= alpha * a[j][k];
            }
            b[i] -= alpha * b[j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }
}

void saveProblemToFile(double** A, double* B, int n, string filename, int prec) {
    ofstream file(filename);
    if (file.is_open()) {
        file << n << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                file << setprecision(prec) << fixed << A[i][j] << " ";
            }
            file << endl;
        }
        file << endl;
        for (int i = 0; i < n; ++i) {
            file << B[i] << " ";
        }
        file << endl << endl;
        file.close();
        cout << "The task statement has been successfully saved to a file " << filename << endl;
    }
    else {
        cerr << "Error opening the file for writing" << endl;
    }
}

void readProblemFromFile(double**& A, double*& B, int& n, string filename, int prec) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> n;
        A = new double* [n];
        for (int i = 0; i < n; ++i) {
            A[i] = new double[n];
            for (int j = 0; j < n; ++j) {
                cout << setprecision(prec) << fixed;
                file >> A[i][j];
            }
        }
        B = new double[n];
        for (int i = 0; i < n; ++i) {
            file >> B[i];
        }
        file.close();
        cout << "The task statement has been successfully uploaded from the file " << filename << endl << endl;
    }
    else {
        cerr << "Error opening the file for reading" << endl;
    }
}

void main() {
    while (true) {
        int n, prec;
        cout << "Enter the size of the matrix and precision: ";
        cin >> n >> prec;
        cout << setprecision(prec) << fixed;

        double** matrix = new double* [n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new double[n];
        }

        double* x = new double[n];
        double* B = new double[n];

        cout << "Matrix:" << endl;
        fillMatrix(matrix, n);
        printMatrix(matrix, n);

        cout << "Vector B: " << endl;
        fillVector(B, n);
        printVector(B, n);

        char answer;
        cout << "Do you want to save data to the file? (y/n): " << endl;
        cin >> answer;
        if (answer == 'y') {
            saveProblemToFile(matrix, B, n, "problem.txt", prec);
        }

        solveGaussModified(matrix, x, B, n);
        cout << "Gauss modified solution:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "x[" << i << "] = " << x[i] << endl;
        }

        double maxDifference = check(matrix, x, B, n);
        cout << scientific << "Max difference between A*x and B: " << maxDifference << endl << endl << fixed;

        solveGauss(matrix, x, B, n);
        cout << "Gauss solution:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "x[" << i << "] = " << x[i] << endl;
        }

        cout << scientific << "Max difference between A*x and B: " << maxDifference << endl << endl;

        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] x;
        delete[] B;

        double** A_loaded = nullptr;
        double* B_loaded = nullptr;
        int n_loaded = 0;
        double* x1 = nullptr;;

        cout << "Do you want to read data from file? (y/n) \n";
        cin >> answer;
        if (answer == 'y') {
            readProblemFromFile(A_loaded, B_loaded, n_loaded, "problem.txt", prec);
            if (A_loaded && B_loaded && n_loaded > 0) { 
                x1 = new double[n_loaded]; 

                cout << "Read matrix: " << endl;
                printMatrix(A_loaded, n_loaded);
                cout << "Read B: " << endl;
                printVector(B_loaded, n_loaded);

                solveGaussModified(A_loaded, x1, B_loaded, n_loaded);
                cout << "Gauss solution for read matrix and B column:" << endl;
                for (int i = 0; i < n_loaded; i++) {
                    cout << "x[" << i << "] = " << x1[i] << endl;
                }

                double maxDiff = check(A_loaded, x1, B_loaded, n_loaded);
                cout << scientific << "Max difference between A*x and B: " << maxDiff << endl;

                for (int i = 0; i < n_loaded; ++i) {
                    delete[] A_loaded[i];
                }
                delete[] A_loaded;
                delete[] B_loaded;
                delete[] x1;
            }
        }
        cout << endl;
    }
}
