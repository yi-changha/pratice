/*
����
�־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.

���
�־��� ���� �� �Ҽ��� ������ ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	int total = 0;
	cin >> n;

	for (int i = 0, temp; i < n; i++) {
		int cnt = 0;
		cin >> temp;
		if (temp == 1) total--;
		for (int j = 1; j <= n; j++) {
			if (temp%j == 0) cnt++;
		}
		if (cnt != 0) total++;
	}
	cout << total << endl;
}