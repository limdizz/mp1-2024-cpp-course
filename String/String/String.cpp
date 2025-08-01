#include <iostream>
#include "String.h"

String::String(int _size) {
    str = new char[_size + 1];
    size = _size + 1;
    str[0] = '\0';
}

String::String(const char* s) {
    size = strlen(s) + 1;
    str = new char[size];
    for (int i = 0; i < size; i++) {
        str[i] = s[i];
    }
    str[size - 1] = '\0';
}

String::String(const String& s) {
    size = s.size;
    str = new char[size];
    for (int i = 0; i < size; i++) {
        str[i] = s.str[i];
    }
}

String::~String() {
    delete[] str;
}

int String::getLength() const {
    int c = 0;
    while (str[c] != '\0') {
        c++;
    }
    return c;
}

String& String::operator=(const String& s) {
    if (size != s.size) {
        delete[] str;
        size = s.size;
        str = new char[size];
    }

    int i = 0;
    while (s.str[i] != '\0') {
        str[i] = s.str[i];
        i++;
    }
    str[i] = '\0';
    return *this;
}

String String::operator+(const String& s) {
    String res(size + s.size - 1);
    int c = 0;
    for (int i = 0; i < getLength(); i++) {
        res.str[c++] = str[i];
    }
    for (int i = 0; i < s.getLength(); i++) {
        res.str[c++] = s.str[i];
    }
    res.str[c] = '\0';
    return res;
}

String& String::operator+=(const String& s) {
    *this = *this + s;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.str;
    return os;
}

std::istream& operator>>(std::istream& is, String& s) {
    char buffer[1000];
    is.getline(buffer, 1000);
    s = String(buffer);
    return is;
}

int main()
{
    String e;
    std::cout << "Enter any word: " << std::endl;
    std::cin >> e;
    std::cout <<  "e: " << e << std::endl << std::endl;

    String res;
    String a("Spider"), b("Black"), c("Hello"), d("Davey");
    std::cout << "a: " << a << std::endl << "b: " << b << std::endl << "c: " << c << std::endl << "d: " << d << std::endl;

    res = a + b + c;
    std::cout << a << " + " << b << " + " << c << " = " << res << std::endl;

    std::cout << res << " += " << d << " = " << std::endl;
    res += d;

    std::cout << res << std::endl;
    return 0;
}