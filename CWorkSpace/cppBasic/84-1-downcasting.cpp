//�ٿ�ĳ���� dynamic_cast
// static_cast : ���� (������)
// dynamic_cast : ���� (��Ÿ��)

// RTTI (Run Time Type Information/Identicfication)

#include <iostream>

using namespace std;

class Base {	
public:
	virtual void f() {}
	int x;
};

class Derived : public Base {
public:
	void f() {}
	int y;
};

int main() {
	cout << sizeof(Base) << endl;	
	cout << sizeof(Derived) << endl;	
}