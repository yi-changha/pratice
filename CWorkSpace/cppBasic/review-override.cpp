// override : �켱�ϴ�

#include <iostream>
using namespace std;

class Base {
public :
	int a = 10;
	void Print() {
		cout << "Base" << endl;
	}
};

class Derived : public Base {
public :
	int a = 20;
	void Print() {
		cout << "Derived" << endl;
	}
};

int main() {
	Base b;
	Derived d;

	/*
	cout << b.a << endl;
	cout << d.a << endl;
	cout << d.Base::a << endl;
	cout << d.Derived::a << endl;
	*/

	d.Print();
	d.Base::Print();
	d.Derived::Print();
}