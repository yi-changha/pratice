//순수 가상 함수

#include <iostream>

using namespace std;

class A {
public:
	virtual void f() = 0;
};

class B : public A {
public:
	void f() {
		cout << "B::f()" << endl;
	}

};


int main() {
	A *a = new B;
	a->f();
	delete a;
}