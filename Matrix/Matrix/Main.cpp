#include <iostream>
#include "Matrix.h"

int main()
{
    std::cout << "CONSTRUCTORS: " << std::endl << std::endl;

    Matrix m1(2, 3);
    m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
    m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
    std::cout << "Matrix m1:\n" << m1;

    Matrix m2 = m1; 
    std::cout << "\nMatrix m2 (copy of m1):\n" << m2 << std::endl;

    std::cout << "OPERATORS: " << std::endl;

    Matrix m3;
    m3 = m1;
    std::cout << "\nMatrix m3 (assigned from m1):\n" << m3;

    std::cout << "\nm1 == m2: " << (m1 == m2) << std::endl;
    std::cout << "m1 != m2: " << (m1 != m2) << std::endl;

    Matrix m4(2, 3);
    m4[0][0] = 6; m4[0][1] = 5; m4[0][2] = 4;
    m4[1][0] = 3; m4[1][1] = 2; m4[1][2] = 1;

    std::cout << "\nMatrix m4:\n" << m4;
    std::cout << "\nm1 + m4:\n" << (m1 + m4);
    std::cout << "\nm1 - m4:\n" << (m1 - m4);

    m1 += m4;
    std::cout << "\nm1 after += m4:\n" << m1;

    m1 -= m4;
    std::cout << "\nm1 after -= m4:\n" << m1;

    Matrix m5(3, 2);
    m5[0][0] = 1; m5[0][1] = 2;
    m5[1][0] = 3; m5[1][1] = 4;
    m5[2][0] = 5; m5[2][1] = 6;

    std::cout << "\nMatrix m5:\n" << m5;
    std::cout << "\nm1 * m5:\n" << (m1 * m5) << std::endl;

    std::cout << "TRANSPOSITION: " << std::endl;

    Matrix m6(2, 2);
    m6[0][0] = 1; m6[0][1] = 2;
    m6[1][0] = 3; m6[1][1] = 4;

    std::cout << "\nMatrix m6:\n" << m6;
    m6.transRewritten();
    std::cout << "\nm6 after in-place transposition:\n" << m6;

    Matrix m7 = m6.transNewMatrix();
    std::cout << "\nm7 (transposed m6):\n" << m7 << std::endl;

    std::cout << "SYMMETRY: " << std::endl;

    Matrix m8(3, 3);
    m8[0][0] = 1; m8[0][1] = 2; m8[0][2] = 3;
    m8[1][0] = 2; m8[1][1] = 5; m8[1][2] = 6;
    m8[2][0] = 3; m8[2][1] = 6; m8[2][2] = 9;

    std::cout << "\nMatrix m8:\n" << m8;
    std::cout << "m8 is symmetric: " << m8.isSymmetric() << std::endl;

    std::cout << "\nm8(1, 1) = " << m8(1, 1) << std::endl;
    m8(1, 1) = 10;
    std::cout << "After m8(1, 1) = 10:\n" << m8;

    try {
        Matrix m9(2, 2);
        Matrix m10(3, 3);
        m9 + m10;
    }
    catch (const std::exception& e) {
        std::cout << "\nCaught exception: " << e.what() << std::endl;
    }
    return 0;
}
