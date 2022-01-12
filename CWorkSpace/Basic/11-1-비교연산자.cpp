// 비교 연산자

#include <stdio.h>

int main() {
	int a, b;
	scanf_s("%d%d", &a, &b, 2);

	printf("\n\n=== int ===\n");
	// bool : 진리값 저장용 변수 (1바이트)
	int p = a > b;
	int q = a < b;
	int r = a == b; // == : 같다
	// 2 > 3 -> 거짓
	// 참 : 1, 거짓 : 0

	printf("a>b %d\n", p);
	printf("a<b %d\n", q);
	printf("a==b %d\n", r);

	printf("\n\n=== bool ===\n");

	bool z = a > b;
	bool x = a < b;
	bool c = a == b;

	printf("a>b %d\n", z);
	printf("a<b %d\n", x);
	printf("a==b %d\n", c);

	// a >= b : a는 b보다 크거나 같다.
	// a <= b : a는 b보다 작거나 같다.
	// a != b : a는 b가 아니다.

}