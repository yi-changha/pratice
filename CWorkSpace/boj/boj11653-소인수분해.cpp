/*
����
���� N�� �־����� ��, ���μ������ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N (1 �� N �� 10,000,000)�� �־�����.

���
N�� ���μ����� ����� �� �ٿ� �ϳ��� ������������ ����Ѵ�. N�� 1�� ��� �ƹ��͵� ������� �ʴ´�.
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 2 || n > 10000000) exit(-1);

	for (int i = 2, temp = n; i <= n; i++) {
		while ((temp%i) == 0) {
			cout << i << endl;
			temp /= i;
		}
	}
}