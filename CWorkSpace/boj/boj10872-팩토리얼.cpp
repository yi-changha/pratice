/*
���丮�� by ��â��(22.04.18)
����
0���� ũ�ų� ���� ���� N�� �־�����. �̶�, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N(0 �� N �� 12)�� �־�����.

���
ù° �ٿ� N!�� ����Ѵ�.
*/


#include <iostream>
using namespace std;

int main() {
	int n;
	int val = 1;
	cin >> n;
	if (n < 0) exit(-1);
	else {
		for (int i = n; 0 < i; i--) {
			val *= i;
		}
	}
	cout << val << endl;
}