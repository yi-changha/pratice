// 배열 포인터 : 배열을 가리키는 포인터
// 포인터 배열 : 포인터들이 배열

#include <stdio.h>

int main() {
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	int *ptr[4];

	ptr[0] = &a; // a의 포인터
	ptr[1] = &c; // c의 포인터
	ptr[2] = &d; // d의 포인터
	ptr[3] = &b; // b의 포인터

	printf("%d %d %d %d\n", *ptr[0], *ptr[1], *ptr[2], *ptr[3]); // 10 30 40 20
}