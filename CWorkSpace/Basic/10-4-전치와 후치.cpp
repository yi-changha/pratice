// 전치와 후치

#include <stdio.h>

int main() {
	int a = 10;
	int b;

	printf("=== 전치 증가 연산 ===\n");
	b = ++a;
	// ++a : a에 1을 먼저 증가시키고, b에 대입하라
	printf("a : %d\n", a); // a : 11
	printf("b : %d\n", b); // b : 11

	printf("\n\n=== 후치 증가 연산 ===\n");
	b = a++;
	// b에 a를 대입하고 a를 1 증가시켜라.
	printf("a : %d\n", a); // a : 12
	printf("b : %d\n", b); // b : 11
}