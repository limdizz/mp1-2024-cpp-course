#include <iostream>
#include "Rational.h"

int main()
{
    Rational a, b, c, d, e, res;
    
    std::cout << "Enter a numerator and denominator for number A: " << std::endl;
    std::cin >> a;
    std::cout << "A: " << a << std::endl << std::endl;

    std::cout << "Enter a numerator and denominator for number B: " << std::endl;
    std::cin >> b;
    std::cout << "B: " << b << std::endl << std::endl;

    std::cout << "Enter a numerator and denominator for number C: " << std::endl;
    std::cin >> c;
    std::cout << "C: " << c << std::endl << std::endl;

    std::cout << "Enter a numerator and denominator for number D: " << std::endl;
    std::cin >> d;
    std::cout << "D: " << d << std::endl << std::endl;

    std::cout << "Enter a numerator and denominator for number E: " << std::endl;
    std::cin >> e;
    std::cout << "E: " << e << std::endl << std::endl;


    res = a + b;
    std::cout << a << " + " << b << " = " << res << std::endl;

    res = a - b;
    std::cout << a << " - " << b << " = " << res << std::endl;

    res = a * b;
    std::cout << a << " * " << b << " = " << res << std::endl;

    res = a / b;
    std::cout << a << " : " << b << " = " << res << std::endl << std::endl;


    std::cout << b;
    res = b - 6;
    std::cout << " - 6 = " << res << std::endl;

    std::cout << "9 - " << c;
    res = 9 - c;
    std::cout << " = " << res << std::endl;

    std::cout << c;
    res = c + 7;
    std::cout << " + 7 = " << res << std::endl;

    std::cout << "4 + " << d;
    res = 4 + d;
    std::cout << " = " << res << std::endl;
    
    std::cout << d;
    res = d * 5;
    std::cout << " * 5 = " << res << std::endl;

    std::cout << "2 * " << e;
    res = 2 * e;
    std::cout << " = " << res << std::endl;

    std::cout << e;
    res = e / 5;
    std::cout << " : 5 = " << res << std::endl;

    std::cout << "3 : " << a;
    res = 3 / a;
    std::cout << " = " << res << std::endl << std::endl;
  


    Rational f(4, 5), g(1, 6), h(3, 7);
    std::cout << "F: " << f << std::endl << "G: " << g << std::endl << "H: " << h << std::endl << std::endl;

    f += g;
    std::cout << "F = F + G = " << f << std::endl;

    f -= h;
    std::cout << "F = F - H = " << f << std::endl;

    h *= g;
    std::cout << "H = H * G = " << h << std::endl;

    h /= g;
    std::cout << "H = H / G = " << h << std::endl << std::endl;
}