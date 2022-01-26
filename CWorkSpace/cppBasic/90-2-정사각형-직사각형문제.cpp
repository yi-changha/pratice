// 정사각형-직사각형 문제
// 부모 클래스의 매개변수가 더 많은 경우

#include <iostream>
using namespace std;

// immutable (불변)
class Rectangle{
public:
	Rectangle(double a, double b) : a(a), b(b) {}
	Rectangle ResizeX(double k) const { return Rectangle(a * k, b); }
	Rectangle ResizeY(double k) const { return Rectangle(a, b * k); }
	double GetA() const { return a; }
	double GetB() const { return b; }
private:
	const double a, b;
};

class Square : public Rectangle {
public:
	Square(double a) : Rectangle(a, a) {}
};

int main() {
	Square s(10);
	Rectangle r = s.ResizeX(2);
	cout << s.GetA() << endl;
	cout << s.GetB() << endl;
	cout << r.GetA() << endl;
	cout << r.GetB() << endl;
}