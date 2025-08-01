#pragma once
class Rational {
private:
    int numerator;
    int denominator;
    void simplify();
public:
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    Rational operator+(const Rational& other);
    Rational operator-(const Rational& other);
    Rational operator*(const Rational& other);
    Rational operator/(const Rational& other);

    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational operator/=(const Rational& other);

    friend Rational operator+(const int a, const Rational& b);
    friend Rational operator-(const int a, const Rational& b);
    friend Rational operator*(const int a, const Rational& b);
    friend Rational operator/(const int a, const Rational& b);

    Rational operator+(int number);
    Rational operator-(int number);
    Rational operator*(int number);
    Rational operator/(int number);

    friend std::ostream& operator<<(std::ostream& os, Rational& rational);
    friend std::istream& operator>>(std::istream& is, Rational& rational);
};
