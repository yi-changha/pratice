// ���� ����
// public		: �ܺ�����o	�ڽ�Ŭ����o
// protected	: �ܺ�����x	�ڽ�Ŭ����o
// private		: �ܺ�����x	�ڽ�Ŭ����x


// �ּ� ó�� ���� �ȵ�.

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