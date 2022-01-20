// ���۷��� ����
#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a(5);
	int &p = a;
	p = 20;
	int b = 10;

	cout << "a = " << a << endl;
	cout << "p = " << p << endl;

	swap(a, b);
	cout << endl << "swap(a, b)" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int abc() {
	int a(5);
	int &r1 = a;
	//int &r2 = 3;		//��� ��ü�� �޸𸮿� ���������� �ʾ� ����ų �� ����.
	//int &r3 = a * 3;	//�� ��ü�� �޸𸮿� ���������� �ʾ� ����ų �� ����.

	// r-value : ������ �� ���� ��; l-value ������ �� �ִ� ��.
	int a(5);
	//int &&r1 = a;		// ���۷��� ������ ���� r-value ���� �ȳ��� ����.
	int &&r2 = 3;
	int &&r3 = a * 3;
}