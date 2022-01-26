// 정사각형-직사각형 문제

#include <iostream>
using namespace std;

// 부모 클래스의 매개변수가 더 많은 경우

class Rectangle {	// 직사각형
public:
	Rectangle(double a, double b) : a(a), b(b) {}
	virtual ~Rectangle() {}	
	void ResizeX(double k) { a *= k; }
	void ResizeY(double k) { a *= k; }
private:
	double a, b;
};

class Square : public Rectangle {	// 정사각형
public :
	Square(double a) : Rectangle(a, a) {}
	void ResizeX(double k) = delete;
	void ResizeY(double k) = delete;
	void ResizeXY(double k) {
		Rectangle::ResizeX(k);
		Rectangle::ResizeY(k);
	}
};

int main() {
	Rectangle *r = new Square(10);
	r->ResizeX(2);		// 정사각형이어야하나 한 변의 길이만 변화해 직사각형이 되버림.
}