//���� ����, ���� ����

#include <iostream>
using namespace std;


int main() {
	int *a = new int(5);
	int *b = new int(3);

	a = b;		// ���� ���� (������ ����)	, �ּҰ� ����
	*a = *b;	// ���� ���� (���� ����)	, �޸𸮿� �ִ� �� ����
	
	delete a;
	delete b;
}