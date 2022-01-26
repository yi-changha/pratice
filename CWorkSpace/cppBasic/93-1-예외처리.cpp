// 예외처리

#include <iostream>
#include <string>
using namespace std;

int fact(int n) {
	if (n < 0) throw to_string(n) + ": 음수입니다.";
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
		cout << "알 수 없는 예외 발생" << endl;
	}
}
							
// 	try{   				    //오류가 발생하면 반복 종료 
//		while (true) {}

//while (true) {			//오류가 발생해도 다시 반복
//	try{