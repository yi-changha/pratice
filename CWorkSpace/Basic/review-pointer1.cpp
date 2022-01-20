// 포인터(pointer) : 변수의 주소를 저장하는 변수

#include <stdio.h>

int main() {
	int a = 20;
	char c = 'h';

	int *ptr_a;
	char *ptr_c;

	ptr_a = &a;
	ptr_c = &c;

	printf(" &a = %d\n", ptr_a);
	printf(" &c = %d\n", ptr_c);
	printf("\n");

	// a, ptr, &, *의 관계
	printf("%a의 값 : %d\n", a);							//20
	printf("%a의 주솟값 : %d\n", &a);						//100으로 가정
	printf("ptr_a에 저장된 값 : %d\n", ptr_a);				//100
	printf("ptr_a가 가리키는 변수의 값 : %d\n", *ptr_a);	//20
}