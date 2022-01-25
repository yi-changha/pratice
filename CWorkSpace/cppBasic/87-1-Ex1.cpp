#include <iostream>

using namespace std;

class A {
public:
	virtual int f() { return x; }
	virtual ~A() {}
private:
	int x = 10;
};

class B : public A {
public:
	int f() { return x; }	//virtual �� ������ ���� A�� �������̵� �߱� ����
	virtual int g() { return A::f(); }
private :
	int x = 20;
};

class C : public B {
public:
	int f() { return x; }
	int g() { return B::f(); }
	virtual int h() { return B::g(); }
private:
	int x = 30;
};

int main() {
	A *a = new B;
	A *b = new C;
	B *c = new C;
	C *d = new C;
	
	cout << a->f() << endl; //20
	cout << static_cast<B*>(a)->g() << endl; //10
	cout << b->f() << endl; //30
	if (C *t = dynamic_cast<C*>(b)) {
		cout << t->g() << endl;
	}	//20
	cout << c->f() << endl; //30
	cout << c->g() << endl; //20
	cout << d->g() << endl; //20
	cout << d->h() << endl; //10
	
	delete a;
	delete b;
	delete c;
	delete d;
}