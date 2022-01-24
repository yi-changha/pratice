// »ó¼Ó

#include <iostream>

using namespace std;

class Base {
public:
	void bFun() {
		cout << "Hello" << endl;
	}

	int bNum;
};

class Derived : public Base {
public :
	void dFunc() {
		cout << "Hello?" << endl;
	}

	int dNum;
};

int main() {
	Base b;
	Derived d;

	b.bFun();
	b.bNum = 1;

	d.bFun();
	d.bNum = 2;
	d.dFunc();
	d.dNum = 1;
}