/*
����
ù° �ٿ��� �� 1��, ��° �ٿ��� �� 2��, N��° �ٿ��� �� N���� ��� ����

�Է�
ù° �ٿ� N(1 �� N �� 100)�� �־�����.

���
ù° �ٺ��� N��° �ٱ��� ���ʴ�� ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "100������ �ڿ����� �Է����ּ���." << endl;
	cin >> n;
	if (n < 1 || n > 100) exit(-1);

	for (int i = 0; i < n; i++) {
		for (int j = n; j-i > 0; j--)
			cout << " ";

		for (int k = 0; k < i; k++)
			cout << "*";
		cout << endl;
	}
}