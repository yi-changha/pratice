/*
����
���л� ��������� 90%�� �ڽ��� �ݿ��� ����� �Ѵ´ٰ� �����Ѵ�. 
����� �׵鿡�� ���� ������ �˷���� �Ѵ�.

�Է�
ù° �ٿ��� �׽�Ʈ ���̽��� ���� C�� �־�����.
��° �ٺ��� �� �׽�Ʈ ���̽����� �л��� �� N(1 �� N �� 1000, N�� ����)�� ù ���� �־�����, �̾ N���� ������ �־�����. 
������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.

���
�� ���̽����� �� �پ� ����� �Ѵ� �л����� ������ �ݿø��Ͽ� �Ҽ��� ��° �ڸ����� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main() {
	int t;
	double *scoArr;

	cout << "������ ������ �Է��ϼ���." << endl;
	cin >> t;

	for (int j = 1, n, cnt; j < t+1; j++) {
		double avg = 0, ptg = 0, sum = 0;
		cnt = 0;
		cout << j << "�� ���� �л��� ���� �Է����ּ���." << endl;
		cin >> n;
		scoArr = (double *)malloc(sizeof(double)*n);
		if (n > 1000 || n < 1) {
			cout << "ERROR, �л��� ���� 1~1000�Դϴ�." << endl;
			exit(-1);
		}
		cout << j << "�� ���� ���� �л� " << n << "���� ������ �Է��ϼ���." << endl;
		for (int i = 0; i < n; i++) {
			cin >> scoArr[i];
			sum += scoArr[i];
			if (scoArr[i] > 100 || scoArr[i] < 0) {
				cout << "ERROR, ������ 0~100�� �Դϴ�." << endl;
				exit(-2);
			}
		}
		avg = sum / n;

		for (int i = 0; i < n; i++) {
			if (scoArr[i] > avg) cnt++;
		}
		ptg = (double)cnt * 100 / (double)n;

		cout << fixed;
		cout.precision(3);
		cout << j << "�� ���� ����� �Ѵ� �л� ���� : "<< ptg << "%"<< endl << endl;
	}
}