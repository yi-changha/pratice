/*
문제
알파벳 소문자, 대문자, 숫자 0-9중 하나가 주어졌을 때, 주어진 글자의 아스키 코드값을 출력하는 프로그램을 작성하시오.

입력
알파벳 소문자, 대문자, 숫자 0-9 중 하나가 첫째 줄에 주어진다.

출력
입력으로 주어진 글자의 아스키 코드 값을 출력한다.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	char n;
	cout << "종료를 원하면 e" << endl;
	while (1) {
		cin >> n;
		cout << int(n) << endl;
		if (int(n) == 101) {
			cout << "종료를 원하면 x";
			cin >> n;
			if (int(n) == 120) {
				cout << "종료를 원하면 i";
				cin >> n;
				if (int(n) == 105) {
					cout << "종료를 원하면 t";
					cin >> n;
					if (int(n) == 116) exit(-1);
				}
			}
		}
	}
}