#include <stdio.h>

int noMeaning() {
	printf("first\n");
	return 1; //return을 만나면 즉시 함수 종료
	printf("second\n");
	return 2;
}

int main() {
	int a;
	a = noMeaning();

	printf("반환돈 값 : %d\n", a); // 1
}