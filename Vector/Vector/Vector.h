#pragma once
template <typename T>
class Vector {
private:
    T* v;
    int n;

public:
    Vector(unsigned int _n = 0)  {
        v = new T[_n];
        n = _n;
    }

    ~Vector() {
        delete[] v;
    }

    Vector(const Vector& vec) {
        v = new T[vec.n];
        n = vec.n;
        for (int i = 0; i < n; ++i) {
            v[i] = vec.v[i];
        }
    }

    Vector& operator=(const Vector& vec) {
        if (this != &vec) {
            delete[] v;
            v = new T[vec.n];
            n = vec.n;
            for (int i = 0; i < n; ++i) {
                v[i] = vec.v[i];
            }
        }
        return *this;
    }

    Vector operator+(const Vector& vec) {
        Vector result(n);
        for (int i = 0; i < n; ++i) {
            result.v[i] = v[i] + vec.v[i];
        }
        return result;
    }

    Vector& operator+=(const Vector& vec) {
        for (int i = 0; i < n; ++i) {
            v[i] += vec.v[i];
        }
        return *this;
    }

    Vector operator-(const Vector& vec) {
        Vector result(n);
        for (int i = 0; i < n; ++i) {
            result.v[i] = v[i] - vec.v[i];
        }
        return result;
    }

    Vector operator*(double d) {
        Vector result(n);
        for (int i = 0; i < n; ++i) {
            result.v[i] = v[i] * d;
        }
        return result;
    }

    Vector operator/(double d) {
        Vector result(n);
        for (int i = 0; i < n; ++i) {
            result.v[i] = v[i] / d;
        }
        return result;
    }

    friend Vector operator*(double d, const Vector& vec) {
        return vec * d;
    }

    bool operator==(const Vector& vec) {
        if (n != vec.n) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (v[i] != vec.v[i]) {
                return false;
            }
        }
        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "(";
        for (int i = 0; i < vec.n; i++) {
            os << vec.v[i];
            if (i < vec.n - 1) {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector& vec) {
        for (int i = 0; i < vec.n; i++) {
            is >> vec.v[i];
        }
        return is;
    }

    T& operator[](unsigned int pos) {
        return v[pos];
    }
};

