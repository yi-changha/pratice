// 배열 포인터 : 배열을 가리키는 포인터
// 포인터 배열 : 포인터들이 배열

#include <stdio.h>

int main() {
	int a = 10, b = 20, c = 30, d = 40;
	int *ptr[4]; 

	ptr[0] = &a;
	ptr[1] = &c;
	ptr[2] = &d;
	ptr[3] = &b;

	printf("%d %d %d %d\n", *ptr[0], *ptr[1], *ptr[2], *ptr[3]);
}