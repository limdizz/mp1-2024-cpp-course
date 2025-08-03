#pragma once
class Complex {
private:
	double re, im;
public:
	void setRe(double _re);
	double getRe();
	void setIm(double _im);
	double getIm();

	void enterReAndIm();
	void printReAndIm();

	Complex sum(Complex b);
	void sumAssignment(Complex b);

	Complex subtract(Complex b);
	void subtractAssign(Complex b);

	Complex multiply(Complex b);
	void multiplyAssign(Complex b);

	Complex divide(Complex b);
	void divideAssign(Complex b);

	double countModulus();
};


