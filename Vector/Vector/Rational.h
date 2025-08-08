#include <iostream>
#pragma once
class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational(int num = 0, int den = 1);
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Rational& rational);

    void simplify();
    int findGCD(int a, int b);
};

