//boj1330
/*
����
�� ���� A�� B�� �־����� ��, A�� B�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
ù° �ٿ� ���� �� ���� �� �ϳ��� ����Ѵ�.

�Է�
ù° �ٿ� A�� B�� �־�����. A�� B�� ���� �� ĭ���� ���еǾ��� �ִ�.

���
A�� B���� ū ��쿡�� '>'�� ����Ѵ�.
A�� B���� ���� ��쿡�� '<'�� ����Ѵ�.
A�� B�� ���� ��쿡�� '=='�� ����Ѵ�.

����
-10,000 �� A, B �� 10,000
*/

#include <iostream>
#include <exception>
using namespace std;

int main() {
	int A, B;

	repeat:
	cout << "-10, 000 �� A, B �� 10, 000" << endl;
	cin >> A >> B;
	if ((A <= 10000 && A >= -10000) && (B <= 10000 && B >= -10000)) {
		if (A < B)
			cout << "A < B" << endl;
		else if (A == B)
			cout << "A == B" << endl;
		else
			cout << "A > B" << endl;
	}
	else
		cout << "ERROR" << endl;
}