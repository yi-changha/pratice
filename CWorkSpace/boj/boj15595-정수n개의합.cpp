/*
����
���� n���� �־����� ��, n���� ���� ���ϴ� �Լ��� �ۼ��Ͻÿ�.
�ۼ��ؾ� �ϴ� �Լ��� ������ ����.

long long sum(std::vector<int> &a);
a: ���� ���ؾ� �ϴ� ���� n���� ����Ǿ� �ִ� �迭 (0 �� a[i] �� 1,000,000, 1 �� n �� 3,000,000)
���ϰ�: a�� ���ԵǾ� �ִ� ���� n���� ��
*/

#include <iostream>
using namespace std;

int inspect(const int n, const int min, const int max) {
	if (n < min || n > max) {
		cout << "ERROR, " << min << "���� ũ�� " << max << "���� ���� ������ �Է��ؾ��մϴ�." << endl;
		exit(-1);
	}
}

int longSum(const int n) {
	int sum = 0;
	int *a;
	a = (int *)malloc(sizeof(int)*n);

	cout << n << "���� ������ �Է����ּ���. (��, 1,000,000������ ���� �ƴ� ����)" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		inspect(a[i], 0, 1000000);
		sum += a[i];
	}
	return sum;
}

int main() {
	int n;
	cout << "�Է��� ������ ������ �Է����ּ���." << endl;
	cin >> n;
	inspect(n, 1, 3000000);

	cout << longSum(n) << endl;
}