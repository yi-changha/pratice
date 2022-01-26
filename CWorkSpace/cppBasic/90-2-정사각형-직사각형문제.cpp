// ���簢��-���簢�� ����
// �θ� Ŭ������ �Ű������� �� ���� ���

#include <iostream>
using namespace std;

// immutable (�Һ�)
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