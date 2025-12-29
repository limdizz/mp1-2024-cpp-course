#pragma once

class Vector
{
	double *v;
	int n;

public:
	Vector(unsigned int _n = 0);
	~Vector() { delete[] v; };
	Vector(const Vector &vec);

	double *operator*();
	Vector &operator=(const Vector &vec);
	Vector operator+(const Vector &vec);
	Vector &operator+=(const Vector &vec);
	Vector operator++();
	Vector operator++(int);
	Vector operator-(const Vector &vec);
	double operator*(const Vector &vec) const;
	Vector operator*(double d);
	friend Vector operator*(double d, const Vector &vec);

	bool operator==(const Vector &vec);
	bool operator!=(const Vector &vec);
	bool operator>(const Vector &vec);
	bool operator<(const Vector &vec);
	bool operator>=(const Vector &vec);
	bool operator<=(const Vector &vec);

	void resize(int n);
	void pushback(double val);

	friend std::ostream &operator<<(std::ostream &os, const Vector &vec);
	friend std::istream &operator>>(std::istream &is, Vector &vec);

	double length();
	int getN() const;
	void setCord(unsigned int pos, double value);
	double getCord(unsigned int pos);
	double &operator[](int pos);
	const double &operator[](int i) const;
};
