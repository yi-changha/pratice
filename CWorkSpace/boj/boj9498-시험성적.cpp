/*
����
���� ������ �Է¹޾� 90 ~ 100���� A, 80 ~ 89���� B, 70 ~ 79���� C, 60 ~ 69���� D, ������ ������ F�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ������ �־�����. ���� ������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.

���
���� ������ ����Ѵ�
*/

#include <iostream>
using namespace std;

int main() {
	int score;
	cout << "���� ������ �Է��ϼ���" << endl;
	cin >> score;

	if (score > 100)	cout << "ERROR, ������ 100�� �����Դϴ�!" << endl;
	else if (score >= 90) cout << score << "��, A" << endl;
	else if (score >= 80) cout << score << "��, B" << endl;
	else if (score >= 70) cout << score << "��, C" << endl;
	else if (score >= 60) cout << score << "��, D" << endl;
	else if (score >= 0) cout << score << "��, F" << endl;
	else cout << "ERROR, ������ ����(-)�� ���� �����!" << endl;
}