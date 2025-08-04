#include <iostream>
#include <vector>

class Figure {
protected:
	int x, y;
public:
	Figure(int _x, int _y) { x = _x, y = _y; }
	virtual double findArea() = 0;
	virtual double findPerim() = 0;
	virtual void print() = 0;
	virtual void move(int deltaX, int deltaY) {
		x += deltaX;
		y += deltaY;
	}
};

class Rectangle : public Figure {
protected:
	int w, h;
public:
	Rectangle(int _x, int _y, int _w, int _h) : Figure(_x, _y) {
		w = _w, h = _h;
	}
	double findArea() { return w * h; }
	double findPerim() { return 2 * (w + h); }
	void print() {
		std::cout << "Rectangle: width = " << w << ", height = " << h << ", area = " << findArea() << ", perimeter = " << findPerim() << " x: " << x << " y: " << y << std::endl;
	}
};

class Square : public Rectangle {
public:
	Square(int _x, int _y, int a) : Rectangle(_x, _y, a, a) {};
	double findArea() { return w * h; } 
	double findPerim() { return 2 * (w + h); }
	void print() {
		std::cout << "Square: width = " << w << ", height = " << h << ", area = " << findArea() << ", perimeter = " << findPerim() << " x: " << x << " y: " << y << std::endl;
	}
};

class Ellipse : public Figure {
protected:
	int a, b;
public:
	double pi = 3.14159265359;
	Ellipse(int _x, int _y, int _a, int _b) : Figure(_x, _y) { a = _a, b = _b; }
	double findArea() { return pi * a * b; }
	double findPerim() { return 2 * pi * sqrt((a * a + b * b) / 2); }
	void print() {
		std::cout << "Ellipse: semi-major axis = " << a << ", semi-minor axis = " << b << ", area = " << findArea() << ", perimeter = " << findPerim() << " x: " << x << " y: " << y << std::endl;
	}
};

class Circle : public Ellipse {
public:
	Circle(int _x, int _y, int _r) : Ellipse(_x, _y, _r, _r) {}
	void print() {
		std::cout << "Circle: radius = " << a << ", area = " << findArea() << ", circumference = " << findPerim() << " x: " << x << " y: " << y << std::endl;
	}
};

class FigureArray : public Figure {
private:
	std::vector<Figure*> figures;
public:
	FigureArray(int _x, int _y) : Figure(_x, _y) {}

	void addFigure(Figure* figure) {
		figures.push_back(figure);
	}

	double findArea()  {
		double totalArea = 0.0;
		for (int i = 0; i < figures.size(); i++) {
			totalArea += figures[i]->findArea();
		}
		return totalArea;
	}

	double findPerim() {
		double totalPerim = 0.0;
		for (int i = 0; i < figures.size(); i++) {
			totalPerim += figures[i]->findPerim();
		}
		return totalPerim;
	}

	void print() {
		std::cout << "Figure array:" << std::endl << std::endl;
		for (int i = 0; i < figures.size(); i++) {
			figures[i]->print();
		}
		std::cout << "Total Area: " << findArea() << ", Total Perimeter: " << findPerim() << std::endl;
	}

	void move(int deltaX, int deltaY) {
		for (int i = 0; i < figures.size(); i++) {
			figures[i]->move(deltaX, deltaY);
		}
	}
};

int main() {
	Rectangle rectangle(-1, 1, 5, 3);
	Ellipse ellipse(5, 5, 4, 2);
	Circle circle(2, 2, 3);
	Square square(3, 9, 6);

	FigureArray array(10, 10);

	array.addFigure(&rectangle);
	array.addFigure(&ellipse);
	array.addFigure(&circle);
	array.addFigure(&square);
	std::cout << "Coordinates before moving:" << std::endl << std::endl;
	array.print();

	array.move(5, -2);
	std::cout << "\nCoordinates after moving (5, -2):" << std::endl << std::endl;
	array.print();

	return 0;
}


	