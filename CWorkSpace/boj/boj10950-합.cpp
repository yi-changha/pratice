/*
����
�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.

�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)

���
�� �׽�Ʈ ���̽����� A+B�� ����Ѵ�.

*/

#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int A[101] = {};
	int B[101] = {};

	cout << "A B�� �Է� (��, 0 < A, B < 10)" << endl;
	for (int i = 0; i < T; i++) {
		cin >> A[i] >> B[i];
	}

	for (int i = 0; i < T; i++) {
		cout << A[i] + B[i] << endl;
	}
}