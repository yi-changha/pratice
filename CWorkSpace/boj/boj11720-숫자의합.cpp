/*
����
N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٿ� ���� N���� ������� �־�����.

���
�Է����� �־��� ���� N���� ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;
#define MAX 101

int main() {
	int n, sum = 0;
	cin >> n;
	char arr[MAX];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += ((int)arr[i] - 48);
	};
	cout << sum << endl;
}