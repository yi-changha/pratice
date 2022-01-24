// 접근 제어
// public		: 외부접근o	자식클래스o
// protected	: 외부접근x	자식클래스o
// private		: 외부접근x	자식클래스x


// 주석 처리 실행 안됨.

#include <iostream>

using namespace std;

class Base {
public:
	int bPublic;

protected:
	int bProtected;

private:
	int bPribate;
};

class Derived : public Base {
public:
	int dPublic;

	void DFunc() {
		bPublic = 1;
		bProtected = 2;
		//bPrivate = 3;
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
	//b.bProtected = 2;
	//b.bPrivate = 3;

	d.bPublic = 1;
	//d.bProtectd = 2;
	//d.bPrivate = 3;
	d.dPublic = 4;
	//d.dPrivate = 5;
}