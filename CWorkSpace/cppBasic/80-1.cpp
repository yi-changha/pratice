//순수 가상 함수와 추상 클래스

#include <iostream>

using namespace std;

class A {						// 추상적으로만 존재하는 클래스
public:
	//virtual void f() {		// 완벽한 가상은 X, 존재하긴 함.
	//	cout << "A::f()" << endl;
	//}
	
	virtual void f() = 0;		// 0(NULL), 순수 가상함수
};


class B : public A {
public:
	void f() {
		cout << "B::f()" << endl;
	}
};

int main() {
	A *a = new B;
	a->f();
	delete a;
}

// 순수 가상 함수는 인스턴스를 만들 수 없음.
// 추상 클래스는 자체만으로는 아무 것도 할 수 없음.