/*
1. parity 홀짝성
* 정수 하나를 매개변수로 받아
* 그 수가 짝수이면 0, 홀수이면 1을 반환하는 함수를 작성해 보세요.
*/

#include <stdio.h>

int parity(int n) {
	if (n % 2 == 0)
		return 0;

	return 1; // else가 없어도 됨. if가 아니면 return을 통해 바로 함수 종료
}

/*
int parity(int n) {
	return (n % 2 + 2) % 2;		// 1, -1, 0
}
*/


int main() {
	printf("%d\n", parity(5));
	printf("%d\n", parity(-3));
	printf("%d\n", parity(6));
}