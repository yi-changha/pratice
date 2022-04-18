/*
별찍기 by 이창하(22.04.18)
재귀 함수를 이용한 접근법

문제
재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.
크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.
N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다.

입력
N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3k이며, 이때 1 ≤ k < 8이다.

출력
첫째 줄부터 N번째 줄까지 별을 출력한다.
*/

#include <iostream>
using namespace std;

int three(int num) {
	if (num == 0) return 1;
	return three(num - 1) * 3;
}

void star(int i, int j, int num) {
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1) cout << " ";
	else if (num / 3 == 0) cout << '*';
	else star(i, j, num / 3);
}

int main() {
	int k;
	cin >> k;
	int n = three(k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		cout << endl;
	}
}