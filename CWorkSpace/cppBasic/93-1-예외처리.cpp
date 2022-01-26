// ����ó��

#include <iostream>
#include <string>
using namespace std;

int fact(int n) {
	if (n < 0) throw to_string(n) + ": �����Դϴ�.";
	if (n == 0) return 1;		// 0! == 1
	return n * fact(n - 1);
}

int comb(int n, int r) {
	int a = fact(n);
	int b = fact(r);
	int c = fact(n - r);
	return a / b / c;
}

int main() {
	int n, r;
	try {
		while (true) {
			cin >> n >> r;
			cout << comb(n, r) << endl;
		}
	}
	catch (const string &e) {
			cout << e << endl;
	}
	catch (int e) {
		cout << e << endl;
	}
	catch (...) {
		cout << "�� �� ���� ���� �߻�" << endl;
	}
}
							
// 	try{   				    //������ �߻��ϸ� �ݺ� ���� 
//		while (true) {}

//while (true) {			//������ �߻��ص� �ٽ� �ݺ�
//	try{