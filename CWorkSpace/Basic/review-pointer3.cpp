#include <stdio.h>

int main() {
	int a = 10;

	int *ptr;
	ptr = &a;
	printf("ptr = %d\n\n", ptr);	// 100으로 가정

	*ptr = 20;
	printf("=== *ptr = 20; 선언 이후 ===\n");
	printf("ptr = %d\n", ptr);		// 100
	printf("a = %d\n", a);			// 20

	// ptr이 가리키는 변수의 값을 바꿔도 주소(ptr)값은 바뀌지 않음.
}