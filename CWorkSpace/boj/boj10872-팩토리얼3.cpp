/*
팩토리얼 by 이창하(22.04.18)
재귀 함수를 이용한 접근법
문제
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)이 주어진다.

출력
첫째 줄에 N!을 출력한다.
*/


#include <iostream>
using namespace std;

int factorial(int num) {
	if (num == 1 || num == 0) return 1;
	return num * factorial(num - 1);
}

int main() {
	int n;
	cin >> n;
	if (n < 0) exit(-1);
	cout << factorial(n) << endl;
}