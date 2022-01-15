/*
10 * 10 이하의 정수형 이차원 배열을 입력받아
그 배열의 각 행의 요소의 합을 출력하는 프로그램을 만들어보세요.

입력 예
3 4
4 2 6 3
7 9 3 4
5 1 2 1

출력 예
15
23
9
*/

#include <stdio.h>
int main() {
	int arr[12][12] = {};
	int a;
	int b;
	scanf_s("%d%d\n", &a, &b, 2);

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
	
	for (int i = 0; i < a; i++) {
		int sum = 0;
		for (int j = 0; j < b; j++) {
			sum += arr[i][j];
		}
		printf("%d\n", sum);
	}
}