/*
����
"OOXXOXXOOO"�� ���� OX������ ����� �ִ�. O�� ������ ���� ���̰�, X�� ������ Ʋ�� ���̴�. 
������ ���� ��� �� ������ ������ �� �������� ���ӵ� O�� ������ �ȴ�. 
���� ���, 10�� ������ ������ 3�� �ȴ�.
"OOXXOXXOOO"�� ������ 1+2+0+0+1+0+0+1+2+3 = 10���̴�.
OX������ ����� �־����� ��, ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. 
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���̰� 0���� ũ�� 80���� ���� ���ڿ��� �־�����. 
���ڿ��� O�� X������ �̷���� �ִ�.

���
�� �׽�Ʈ ���̽����� ������ ����Ѵ�.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;

	string ox;
	int scoreArr[100];
	int score = 0;
	int add = 1;
	for (int i = 0; i < t; i++, score = 0, add = 1) {
		cin >> ox;
		for (int j = 0; j < ox.length(); j++) {
			if (ox.at(j) == 'O') {
				score += add;
				add++;
			}
			else add = 1;
		}
		scoreArr[i] = score;
	}

	for (int i = 0; i < t; i++) {
		cout << scoreArr[i] << endl;
	}
}