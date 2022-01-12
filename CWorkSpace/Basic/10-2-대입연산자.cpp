// += -= *= /= %=
// 프로그래머들이 귀찮아서 만든 연산자

#include <stdio.h>

int main() {
	int a = 5;
	printf("a=5  %d\n", a);
	a += 6; // a = a + 6;
	printf("a+=6  %d\n", a);
	a *= 7; // a = a * 7;
	printf("a*=7  %d\n", a);
	a -= 6; // a = a - 6;
	printf("a-=6  %d\n", a);
	a %= 2; // a = a % 2; a를 2로 나눈 나머지
	printf("a%%=2  %d\n", a);
}