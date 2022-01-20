// 포인터를 가리키는 포인터

#include <stdio.h>

int main() {
	int a = 10;
	
	int *ptr;
	ptr = &a;

	int **ptr_ptr;
	ptr_ptr = &ptr;

	printf("a = %d\n", a);					//10
	printf("&a = %d\n", &a);				//100으로 가정
	//printf("&&a = %d\n", &&a);			//오류
	//printf("*a = %d\n", *a);				//오류; 존재하지 않음.
	printf("\n");

	printf("ptr = %d\n", ptr);				//100
	printf("&ptr = %d\n", &ptr);			//200으로 가정
	printf("*ptr = %d\n", *ptr);			//10
	printf("\n");

	printf("ptr_ptr = %d\n", ptr_ptr);		//200
	printf("*ptr_ptr = %d\n", *ptr_ptr);	//100
	printf("**ptr_ptr = %d\n", **ptr_ptr);	//10
}