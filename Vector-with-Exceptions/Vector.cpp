#include <iostream>
#include "Vector.h"
#include "Exception.h"

Vector::Vector(unsigned int _n)
{
    n = _n;
    v = new double[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
}

Vector::Vector(const Vector &vec)
{
    n = vec.n;
    v = new double[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = vec.v[i];
    }
}

Vector &Vector::operator=(const Vector &vec)
{
    if (this != &vec)
    {
        if (n != vec.n)
        {
            delete[] v;
            n = vec.n;
            v = new double[n];
        }
        for (int i = 0; i < n; i++)
        {
            v[i] = vec.v[i];
        }
    }
    return *this;
}

Vector Vector::operator+(const Vector &vec)
{
    if (n == vec.n)
    {
        Vector res(n);
        for (int i = 0; i < n; i++)
        {
            res.v[i] = v[i] + vec.v[i];
        }
        return res;
    }
    throw Exception(__FILE__, __func__, __LINE__, "The sizes are not equal");
}

Vector &Vector::operator+=(const Vector &vec)
{
    for (int i = 0; i < n; i++)
    {
        v[i] += vec.v[i];
    }
    return *this;
}

Vector Vector::operator-(const Vector &vec)
{
    if (n == vec.n)
    {
        Vector res(n);
        for (int i = 0; i < n; i++)
        {
            res.v[i] = v[i] - vec.v[i];
        }
        return res;
    }
    throw Exception(__FILE__, __func__, __LINE__, "The sizes are not equal");
}

double Vector::operator*(const Vector &vec) const
{
    if (n == vec.n)
    {
        double res = 0.0;
        for (int i = 0; i < n; i++)
        {
            res += v[i] * vec.v[i];
        }
        return res;
    }
    throw Exception(__FILE__, __func__, __LINE__, "The sizes are not equal");
}

Vector Vector::operator*(double d)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
    {
        res.v[i] = v[i] * d;
    }
    return res;
}

Vector operator*(double d, const Vector &vec)
{
    Vector res(vec.n);
    for (int i = 0; i < vec.n; i++)
    {
        res.v[i] = d * vec.v[i];
    }
    return res;
}

double Vector::length()
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i] * v[i];
    }
    return sqrt(sum);
}

double &Vector::operator[](int pos)
{
    if (pos < 0 || pos >= n)
        throw Exception(__FILE__, __func__, __LINE__, "Equal less than zero or more than size");
    else
        return v[pos];
}

int Vector::getN() const { return n; }
void Vector::setCord(unsigned int pos, double value) { v[pos] = value; }
double Vector::getCord(unsigned int pos) { return v[pos]; }

double *Vector::operator*()
{
    return v;
}

const double &Vector::operator[](int i) const
{
    if (i < 0 || i >= n)
        throw Exception(__FILE__, __func__, __LINE__, "Equal less than zero or more than size");
    else
        return v[i];
}

std::ostream &operator<<(std::ostream &os, const Vector &vec)
{
    os << "(";
    for (int i = 0; i < vec.n; i++)
    {
        os << vec.v[i];
        if (i < vec.n - 1)
        {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Vector &vec)
{
    for (int i = 0; i < vec.n; i++)
    {
        is >> vec.v[i];
    }
    return is;
}

bool Vector::operator==(const Vector &vec)
{
    if (n != vec.n)
    {
        throw Exception(__FILE__, __func__, __LINE__, "The sizes are not equal");
    }
    bool b = true;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != vec.v[i])
        {
            b = false;
        }
    }
    return b;
}

bool Vector::operator!=(const Vector &vec)
{
    return !(*this == vec);
}

Vector Vector::operator++()
{ // prefix
    for (int i = 0; i < n; i++)
    {
        v[i]++;
    }
    return *this;
}

Vector Vector::operator++(int)
{ // postfix
    Vector d = *this;
    for (int i = 0; i < n; i++)
    {
        v[i]++;
    }
    return d;
}

bool Vector::operator>(const Vector &vec)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= vec.v[i])
        {
            return false;
        }
    }
    return true;
}

bool Vector::operator<(const Vector &vec)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= vec.v[i])
        {
            return false;
        }
    }
    return true;
}

bool Vector::operator>=(const Vector &vec)
{
    return (*this > vec) || (*this == vec);
}

bool Vector::operator<=(const Vector &vec)
{
    return (*this < vec) || (*this == vec);
}

void Vector::resize(int _n)
{
    if (_n < 0)
    {
        throw Exception(__FILE__, __func__, __LINE__, "Invalid size specified for resizing");
    }
    if (n == _n)
        return;
    Vector tm(*this);
    delete[] v;
    v = new double[_n], n = _n;
    int mn = std::min(tm.n, n);
    for (int i = 0; i < mn; i++)
    {
        v[i] = tm.v[i];
    }
}

void Vector::pushback(double val)
{
    double *new_v = new double[n + 1];
    for (int i = 0; i < n; i++)
    {
        new_v[i] = v[i];
    }
    new_v[n] = val;
    delete[] v;
    v = new_v;
    n++;
}
