// 접근 제어 지시자
// public		: 외부접근o	자식클래스o
// protected	: 외부접근x	자식클래스o
// private		: 외부접근x	자식클래스x

#include <iostream>
using namespace std;

class Base {
public:
	int bPublic;

protected:
	int bProtected;

private:
	int bPrivate;
};

class Derived : public Base {
public:
	int dPublic;

	void DFunc() {
		bPublic = 1;
		bProtected = 2;
		//bPrivate = 3;		//private이어서 안됨.
		dPublic = 4;
		dPrivate = 5;
	}

private:
	int dPrivate;
};

int main() {
	Base b;
	Derived d;
	
	b.bPublic = 1;
	//b.bProtected = 2;		//외부접근 x
	//b.bPrivate = 3;		//외부접근 x

	d.bPublic = 1;
	//d.bProtected = 2;		//외부접근 x
	//d.bPrivate = 3;		//외부접근 x
	d.dPublic = 4;
	//d.dPrivate = 4;		//외부접근 x
}