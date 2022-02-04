/*
문제
나열된 분수들을 1/1 → 1/2 → 2/1 → 3/1 → 2/2 → … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다.

출력
첫째 줄에 분수를 출력한다.
*/

#include <iostream>
using namespace std;

int main() {
	int n, a, b;
	int sum = 0;
	int line = 0;
	cin >> n;

	for (int i = 1; sum < n; i++) {
		sum += i;
		line++;
	}
	
	sum = (sum) - line;
	a = (line +1);
	b = 0;
	for (int i = 0; sum < n; sum++) {
		a--;
		b++;
	}

	if (line % 2 == 0 )
		cout << b << "/" << a << endl;
	else cout << a << "/" << b << endl;
}