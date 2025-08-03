#include "Complex.h"
#include <iostream>

void main() {
	Complex a, b, c;

	a.enterReAndIm();
	b.enterReAndIm();
	c.enterReAndIm();

	std::cout << "Our values of a: " << std::endl;
	a.printReAndIm();
	std::cout << "Module of a: " << a.countModulus() << std::endl << std::endl;

	std::cout << "Our values of b: " << std::endl;
	b.printReAndIm();
	std::cout << "Our values of c: " << std::endl;
	c.printReAndIm();
	std::cout << std::endl;

	a = a.sum(b);
	std::cout << "Sum a + b:" << std::endl;
	a.printReAndIm();

	a = a.subtract(c);
	std::cout << "Subtraction a - c:" << std::endl;
	a.printReAndIm();

	a = a.multiply(b);
	std::cout << "Multiplication a * b:" << std::endl;
	a.printReAndIm();

	a = a.divide(c);
	std::cout << "Division a / c:" << std::endl;
	a.printReAndIm();
}