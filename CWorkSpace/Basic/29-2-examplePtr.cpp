#include <stdio.h>

int main() {
	int a = 10;
	int b = 20;

	int *ptr;

	ptr = &a; // ptr은 a의 주소값
	*ptr = 30; // ptr의 참조값이 30 , a == 30

	ptr = &b; // ptr은 b의 주소값
	*ptr = 10; //ptr의 참조값이 10, b == 10

	printf("%d\n", a); // 30
	printf("%d\n", b); // 10
	printf("%d\n", *ptr); // 10
}