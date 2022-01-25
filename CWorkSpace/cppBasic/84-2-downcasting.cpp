#include <iostream>

using namespace std;

class Base {
public:
	virtual void f() {}
	int x = 10;
};

class Derived : public Base {
public:
	void f() {}
	int y = 20;
};

int main() {
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;

	int *a = (int*)new Base;
	cout << a[0] << " " << a[1] << endl;

	int *b = (int*)new Derived;
	cout << b[0] << " " << b[1] << " " << b[2] << endl;

	int *c = (int*)new Derived;
	cout << c[0] << " " << c[1] << " " << c[2] << endl;

	delete a;
	delete b;
	delete c;
}