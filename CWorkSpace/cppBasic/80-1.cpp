//���� ���� �Լ��� �߻� Ŭ����

#include <iostream>

using namespace std;

class A {						// �߻������θ� �����ϴ� Ŭ����
public:
	//virtual void f() {		// �Ϻ��� ������ X, �����ϱ� ��.
	//	cout << "A::f()" << endl;
	//}
	
	virtual void f() = 0;		// 0(NULL), ���� �����Լ�
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

// ���� ���� �Լ��� �ν��Ͻ��� ���� �� ����.
// �߻� Ŭ������ ��ü�����δ� �ƹ� �͵� �� �� ����.