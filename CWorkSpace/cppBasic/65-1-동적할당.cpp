// ���� �Ҵ� : int a;
// ���� �Ҵ� : ���α׷� ���� �߿� ������ �޸𸮿� �Ҵ��ϴ� ��

#include <iostream>

using namespace std;

int main() {
	int *a = new int(5);

	cout << a << endl;			//�ּҰ�
	cout << *a << endl;			//����Ű�� ��

	*a = 10;

	cout << a << endl;		
	cout << *a << endl;

	delete a;					//�޸� ����
}
