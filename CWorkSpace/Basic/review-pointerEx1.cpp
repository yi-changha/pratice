/*
100개 이하의 정수를 입력 받아
첫 줄에 짝수 번쨰 숫자들을 순서대로 출력하고,
다음 줄에 홀수 번째 숫자들을 순서대로 출력하는 프로그램을 만들어 보세요.

입력 예
7
3 1 4 1 5 9 2

출력 예
1 1 9
3 4 5 2
*/

#include <stdio.h>

int main() {
	int n;
	int arr[105];
	scanf_s("%d", &n, 1);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i], 105);
	}

	for (int i = 1; i < n; i+= 2) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i += 2) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}