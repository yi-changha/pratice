/*
����
���ĺ� �ҹ���, �빮��, ���� 0-9�� �ϳ��� �־����� ��, �־��� ������ �ƽ�Ű �ڵ尪�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
���ĺ� �ҹ���, �빮��, ���� 0-9 �� �ϳ��� ù° �ٿ� �־�����.

���
�Է����� �־��� ������ �ƽ�Ű �ڵ� ���� ����Ѵ�.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	char n;
	cout << "���Ḧ ���ϸ� e" << endl;
	while (1) {
		cin >> n;
		cout << int(n) << endl;
		if (int(n) == 101) {
			cout << "���Ḧ ���ϸ� x";
			cin >> n;
			if (int(n) == 120) {
				cout << "���Ḧ ���ϸ� i";
				cin >> n;
				if (int(n) == 105) {
					cout << "���Ḧ ���ϸ� t";
					cin >> n;
					if (int(n) == 116) exit(-1);
				}
			}
		}
	}
}