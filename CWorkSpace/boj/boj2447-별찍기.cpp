/*
����� by ��â��(22.04.18)
��� �Լ��� �̿��� ���ٹ�

����
������� �������� ���� ��� ����. N�� 3�� �ŵ�����(3, 9, 27, ...)�̶�� �� ��, ũ�� N�� ������ N��N ���簢�� ����̴�.
ũ�� 3�� ������ ����� ������ �ְ�, ����� ������ ��� ĭ�� ���� �ϳ��� �ִ� �����̴�.
N�� 3���� Ŭ ���, ũ�� N�� ������ �������� ä���� ����� (N/3)��(N/3) ���簢���� ũ�� N/3�� �������� �ѷ��� �����̴�.

�Է�
N�� 3�� �ŵ������̴�. �� � ���� k�� ���� N=3k�̸�, �̶� 1 �� k < 8�̴�.

���
ù° �ٺ��� N��° �ٱ��� ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int three(int num) {
	if (num == 0) return 1;
	return three(num - 1) * 3;
}

void star(int i, int j, int num) {
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1) cout << " ";
	else if (num / 3 == 0) cout << '*';
	else star(i, j, num / 3);
}

int main() {
	int k;
	cin >> k;
	int n = three(k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		cout << endl;
	}
}