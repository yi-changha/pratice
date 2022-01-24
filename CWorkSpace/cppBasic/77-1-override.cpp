// override : �켱�ϴ�. ������ ����� �θ� Ŭ������ ������� �켱
// overwrite : ����� 
// overload : �Լ� ���� ����.

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