#include <stdio.h>

int main() {
	int a = 10;

	int *ptr;
	ptr = &a;

	int **ptr_ptr;
	ptr_ptr = &ptr;
	
	printf("a = %d\n", a); // a의 값
	printf("&a = &d\n", &a); // a의 주소값

	printf("ptr = %d\n", ptr); // ptr에 저장된 값
	printf("&ptr = %d\n", &ptr); // ptr의 주소값

	printf("ptr_ptr = %d\n", ptr_ptr); //ptr_ptr의 값
	printf("*ptr_ptr = %d\n", *ptr_ptr); //ptr_ptr이 가리키는 값
	printf("**ptr_ptr = %d\n", **ptr_ptr); // a
}