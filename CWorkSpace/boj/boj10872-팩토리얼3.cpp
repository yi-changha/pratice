/*
���丮�� by ��â��(22.04.18)
��� �Լ��� �̿��� ���ٹ�
����
0���� ũ�ų� ���� ���� N�� �־�����. �̶�, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N(0 �� N �� 12)�� �־�����.

���
ù° �ٿ� N!�� ����Ѵ�.
*/


#include <iostream>
using namespace std;

int factorial(int num) {
	if (num == 1 || num == 0) return 1;
	return num * factorial(num - 1);
}

int main() {
	int n;
	cin >> n;
	if (n < 0) exit(-1);
	cout << factorial(n) << endl;
}