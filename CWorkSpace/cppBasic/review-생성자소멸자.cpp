// ������ : ��ü�� ������ �� �ڵ����� ȣ��Ǵ� �Լ�
// �Ҹ��� : ��ü�� �Ҹ�� �� �ڵ����� ȣ��Ǵ� �Լ�

#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass() {		// ������
		cout << "������ ȣ��" << endl;
	}
	
	~MyClass() {	// �Ҹ���
		cout << "�Ҹ��� ȣ��" << endl;
	}
};

// MyClass global1Obj;

void testLocal1Obj() {
	cout << "testLocalObj �Լ� ����" << endl;
	MyClass local10bj;
	cout << "testLocalObj �Լ� ��" << endl;
}

int main() {
	cout << "main�Լ� ����" << endl;
	testLocal1Obj();
	cout << "main�Լ� ��" << endl;
}