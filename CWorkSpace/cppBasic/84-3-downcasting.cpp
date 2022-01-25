#include <iostream>
#include <math.h>

using namespace std;

class Shape {
public:
	virtual double GetArea() const = 0;
	virtual void Resize(double k) = 0;
};

class Circle : public Shape {
public:
	Circle(double r) : r(r) {}
	double GetArea() const {
		return r * r * 3.14;
	}
	void Resize(double k) {
		r *= k;
	}
private:
	double r;
};

class Rectangle : public Shape {
public:
	Rectangle(double a, double b) : a(a), b(b) {}
	double GetArea() const {
		return a * b;
	}
	void Resize(double k) {
		a *= k;
		b *= k;
	}
	double GetDiag() const {
		return sqrt(a * a + b * b);
	}
private:
	double a, b;
};

int main() {
	Shape *shapes[] = { new Circle(1), new Rectangle(1, 2) };

	for (int i = 0; i < 2; i++) {
		// ������ ����
		// ���࿡ ���簢���� ���, �밢�� ���� ���
		cout << "������ ���� : " << shapes[i]->GetArea() << endl;
		Rectangle *r = dynamic_cast<Rectangle*>(shapes[i]);
		if (r != NULL) {
			cout << "�밢���� ���� : " << r->GetDiag() << endl;
		}
	}

	for (int i = 0; i < 2; i++) {
		delete shapes[i];
	}
}