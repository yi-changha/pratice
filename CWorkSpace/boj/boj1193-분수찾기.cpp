/*
����
������ �м����� 1/1 �� 1/2 �� 2/1 �� 3/1 �� 2/2 �� �� �� ���� ������� ������ ���ʴ�� 1��, 2��, 3��, 4��, 5��, �� �м���� ����.
X�� �־����� ��, X��° �м��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� X(1 �� X �� 10,000,000)�� �־�����.

���
ù° �ٿ� �м��� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main() {
	int n, a, b;
	int sum = 0;
	int line = 0;
	cin >> n;

	for (int i = 1; sum < n; i++) {
		sum += i;
		line++;
	}
	
	sum = (sum) - line;
	a = (line +1);
	b = 0;
	for (int i = 0; sum < n; sum++) {
		a--;
		b++;
	}

	if (line % 2 == 0 )
		cout << b << "/" << a << endl;
	else cout << a << "/" << b << endl;
}