//»ó¼Ó

#include <iostream>
using namespace std;

class Base {
public:
	void bFunc() {
		cout << "Hello" << endl;
	}

	int bNum;
};

class Derived : public Base {
public:
	void dFunc() {
		cout << "Hello?" << endl;
	}

	int dNum;
};

int main() {
	Base b;
	Derived d;

	b.bFunc();
	b.bNum = 1;
	
	d.bFunc();
	d.bNum = 2;
	d.dFunc();
	d.dNum = 3;
}