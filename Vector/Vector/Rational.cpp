#include "Rational.h"

Rational::Rational(int num, int den) {
    numerator = num;
    denominator = den;
    simplify();
}

Rational Rational::operator+(const Rational& other) const {
    return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(numerator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator/(const Rational& other) const {
    return Rational(numerator * other.denominator, denominator * other.numerator);
}

std::ostream& operator<<(std::ostream& os, const Rational& rational) {
    os << rational.numerator << "/" << rational.denominator;
    return os;
}

void Rational::simplify() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int gcd = findGCD(abs(numerator), denominator);
    numerator /= gcd;
    denominator /= gcd;
}

int Rational::findGCD(int a, int b) {
    if (b == 0) return a;
    return findGCD(b, a % b);
}