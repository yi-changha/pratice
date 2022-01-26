// ���簢��-���簢�� ����

#include <iostream>
using namespace std;

// �θ� Ŭ������ �Ű������� �� ���� ���

class Rectangle {	// ���簢��
public:
	Rectangle(double a, double b) : a(a), b(b) {}
	virtual ~Rectangle() {}	
	void ResizeX(double k) { a *= k; }
	void ResizeY(double k) { a *= k; }
private:
	double a, b;
};

class Square : public Rectangle {	// ���簢��
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
	r->ResizeX(2);		// ���簢���̾���ϳ� �� ���� ���̸� ��ȭ�� ���簢���� �ǹ���.
}