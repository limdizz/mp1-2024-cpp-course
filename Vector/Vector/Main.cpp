#include <iostream>
#include "Vector.h"
#include "Rational.h"

int main() {
    Vector<Rational> vec1(3);
    int userInput1, userInput2, userInput3, userInput4, userInput5, userInput6;
    std::cout << "Enter numerator and denominator: ";
    std::cin >> userInput1 >> userInput2;
    vec1[0] = Rational(userInput1, userInput2);
    std::cout << "Vec1[0] = " << vec1[0] << std::endl;
    std::cout << "Enter numerator and denominator: ";
    std::cin >> userInput3 >> userInput4;
    vec1[1] = Rational(userInput3, userInput4);
    std::cout << "Vec1[1] = " << vec1[1] << std::endl;
    std::cout << "Enter numerator and denominator: ";
    std::cin >> userInput5 >> userInput6;
    vec1[2] = Rational(userInput5, userInput6);
    std::cout << "Vec1[2] = " << vec1[2] << std::endl << std::endl;


    Vector<Rational> vec2(3);
    vec2[0] = Rational(2, 3);
    std::cout << "Vec2[0] = " << vec2[0] << std::endl;
    vec2[1] = Rational(1, 5);
    std::cout << "Vec2[1] = " << vec2[1] << std::endl;
    vec2[2] = Rational(7, 9);
    std::cout << "Vec2[2] = " << vec2[2] << std::endl << std::endl;

    Vector<Rational> vec3 = vec1 + vec2;
    std::cout << "Vec3 = Vec1 + Vec2 = " << vec3 << std::endl;

    Vector<Rational> vec4 = vec1 - vec2;
    std::cout << "Vec4 = Vec1 - Vec2 = " << vec4 << std::endl << std::endl;

    Vector<Rational> vec5 = vec1 * 4;
    std::cout << "Vec5 = Vec1 * 4 = " << vec5 << std::endl;
    std::cout << "Vec5[1] = " << vec5[1] << std::endl;
    std::cout << "Vec5 / 2 = " << vec5 / 2 << std::endl << std::endl;
}