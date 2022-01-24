// override : 우선하다. 고유의 멤버가 부모 클래스의 멤버보다 우선
// overwrite : 덮어쓰다 
// overload : 함수 여러 정의.

#include <iostream>

using namespace std;

class Base {
public :
	int a = 10;		//Base() : a(10) {}
	void Print() {
		cout << "From Base" << endl;
	}
};


class Derived : public Base {
public:
	int a = 20;
	void Print() {
		cout << "From Derived" << endl;
	}
};

int main() {
	Base b;
	Derived d;

	cout << b.a << endl;			//10
	cout << d.a << endl;			//20
	cout << d.Base::a << endl;		//10
	cout << d.Derived::a << endl;	//20
	cout << endl;

	d.Print();						//derived
	d.Base::Print();				//base
	d.Derived::Print();				//derived
}