#include <iostream>

using namespace std;

const double PI = 3.141592653589793;

class Shape {		// 순수 가상함수
public:
	virtual double GetArea() = 0;
	virtual void Resize(double f) = 0;
};

class Circle : public Shape {
public:
	Circle(double r) : r(r) {}

	double GetArea() {
		return PI * r * r;
	}

	void Resize(double f) {
		r *= f;
	}

private:
	float r;
};

class Rectangle : public Shape {
public:
	Rectangle(double a, double b) : a(a), b(b) {}

	double GetArea() {
		return a * b;
	}

	void Resize(double f) {
		a *= f;
		b *= f;
	}

private:
	double a, b;
};

int main() {
	Shape *shapes[] = {
		new Circle(10),
		new Rectangle(20, 30)
		// Shape가 추상클래스여서 객체를 만들 수 없음
		// 부모 클래스가 필요하지만, 부모 클래스가 객체를 만들 수 없게 할 때 사용
		// new Shape(불가)
		// 불필요한 구현을 피해갈 수 있다. 틀만 제공
	};
	

	for (Shape *s : shapes) {
		s->Resize(2);
	}
	for (Shape *s : shapes) {
		cout << s->GetArea() << endl;
	}
	for (Shape *s : shapes) {
		delete s;
	}
} 