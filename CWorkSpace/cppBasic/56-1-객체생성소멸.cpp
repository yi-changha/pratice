// ������ : ��ü�� ������ �� �ڵ����� ȣ��Ǵ� �Լ�
// �Ҹ��� : ��ü�� �Ҹ�� �� �ڵ����� ȣ��Ǵ� �Լ�

#include <iostream>

using namespace std;

class MyClass {
public :
	MyClass() {		//������
		cout << "������ ȣ��" << endl;
	}
	~MyClass() {	//�Ҹ���
		cout << "�Ҹ��� ȣ��" << endl;
	}
};

//MyClass globalObj;	//���� ��ü(global object)

void testLocalObj() {
	cout << "testLocalObj �Լ� ����" << endl;
	MyClass localObj;
	cout << "testLocalObj �Լ� ��" << endl;
}

int main() {
	cout << "main�Լ� ����" << endl;
	testLocalObj();
	cout << "main�Լ� ��" << endl;
}