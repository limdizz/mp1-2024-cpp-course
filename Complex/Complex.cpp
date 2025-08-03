#include <iostream>
#include "Complex.h"
#include <cmath>

const int inf = INT_MAX;

void Complex::setRe(double _re) {
	re = _re;
}

double Complex::getRe() {
	return re;
}

void Complex::setIm(double _im) {
	im = _im;
}

double Complex::getIm() {
	return im;
}

void Complex::enterReAndIm() {
	std::cout << "Enter values: ";
	std::cin >> re >> im;
	std::cout << std::endl;
}

void Complex::printReAndIm() {
	std::cout << "(" << getRe() << ", " << getIm() << ")" << std::endl << std::endl;
}

Complex Complex::sum(Complex b) {
	Complex t;
	t.re = re + b.re;
	t.im = im + b.im;

	return t;
}

void Complex::sumAssignment(Complex b) {
	re += b.re;
	im += b.im;
}

Complex Complex::subtract(Complex b) {
	Complex t;
	t.re = re - b.re;
	t.im = im - b.im;

	return t;
}

void Complex::subtractAssign(Complex b) {
	re -= b.re;
	im -= b.im;
}

Complex Complex::multiply(Complex b) {
	Complex t;
	t.re = re * b.re - im * b.im;
	t.im = re * b.im + im * b.re;

	return t;
}

void Complex::multiplyAssign(Complex b) {
	double new_re = re * b.re - im * b.im;
	im = re * b.im + im * b.re;
	re = new_re;
}

Complex Complex::divide(Complex b) {
	Complex t;
	if (fabs(b.re) < 1e-6 && fabs(b.im) < 1e-6) {
		t.re = inf;
		t.im = inf;
	}
	t.re = (re * b.re + im * b.im) / (b.re * b.re + b.im * b.im);
	t.im = (im * b.re - re * b.im) / (b.re * b.re + b.im * b.im);
	return t;
}

void Complex::divideAssign(Complex b) {
	if (fabs(b.re) < 1e-6 && fabs(b.im) < 1e-6) {
		re = inf;
		im = inf;
	}
	re = (re * b.re + im * b.im) / (b.re * b.re + b.im * b.im);
	im = (im * b.re - re * b.im) / (b.re * b.re + b.im * b.im);
}

double Complex::countModulus() {
	return std::sqrt(re * re + im * im);
}
