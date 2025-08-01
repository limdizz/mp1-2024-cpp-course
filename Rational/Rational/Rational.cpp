#include <iostream>
#include "Rational.h"

void Rational::simplify()
{
    int temp;
    int num = numerator, denom = denominator;
    while (temp = num % denom)
    {
        num = denom;
        denom = temp;
    }
    denominator /= denom;
    numerator /= denom;
    if (denominator < 0) {
        denominator = -denominator;
        numerator = -numerator;
    }
}

Rational Rational::operator+(const Rational& other) {
    Rational res(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    res.simplify();
    return res;
}

Rational& Rational::operator+=(const Rational& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
    return *this;
}

Rational Rational::operator-(const Rational& other) {
    Rational res(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    res.simplify();
    return res;
}

Rational& Rational::operator-=(const Rational& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
    return *this;
}

Rational Rational::operator*(const Rational& other) {
    Rational res(numerator * other.numerator, denominator * other.denominator);
    res.simplify();
    return res;
}

Rational& Rational::operator*=(const Rational& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    simplify();
    return *this;
}

Rational Rational::operator/(const Rational& other) {
    if (other.denominator == 0 || other.numerator == 0) {
        std::cout << "Denominator shouldn't equal to zero" << std::endl;
    }
    else {
        Rational res(numerator * other.denominator, other.numerator * denominator);
        res.simplify();
        return res;
    }
    return 0;
}

Rational Rational::operator/=(const Rational& other) {
    numerator *= other.denominator;
    denominator *= other.numerator;
    simplify();
    return *this;
}

Rational Rational::operator+(int number)
{
    numerator = number * denominator + numerator;
    simplify();
    return Rational(numerator, denominator);
}

Rational Rational::operator-(int number)
{
    numerator -= number * denominator;
    simplify();
    return Rational(numerator, denominator);
}

Rational Rational::operator*(int number)
{
    numerator *= number;
    simplify();
    return Rational(numerator, denominator);
}

Rational Rational::operator/(int number)
{
    if (number != 0) {
        denominator *= number;
    }
    else {
        std::cout << "Division by zero is not allowed." << std::endl;
    }
    simplify();
    return Rational(numerator, denominator);
}

Rational operator+(const int a, const Rational& b)
{
    Rational res(a * b.denominator + b.numerator, b.denominator);
    res.simplify();
    return res;
}

Rational operator-(const int a, const Rational& b)
{
    Rational res(a * b.denominator - b.numerator, b.denominator);
    res.simplify();
    return res;
}

Rational operator*(const int a, const Rational& b)
{
    Rational res(a * b.numerator, b.denominator);
    res.simplify();
    return res;
}

Rational operator/(const int a, const Rational& b)
{
    Rational res(a * b.denominator, b.numerator);
    res.simplify();
    return res;
}

std::ostream& operator<<(std::ostream& os, Rational& rational) {
    os << rational.numerator << "/" << rational.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& rational) {
    is >> rational.numerator >> rational.denominator;
    return is;
}
