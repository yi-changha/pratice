#include <stdio.h>

int main() {
	int a = 10;

	int *ptr;
	ptr = &a;

	int **ptr_ptr;
	ptr_ptr = &ptr;
	
	printf("a = %d\n", a); // a�� ��
	printf("&a = &d\n", &a); // a�� �ּҰ�

	printf("ptr = %d\n", ptr); // ptr�� ����� ��
	printf("&ptr = %d\n", &ptr); // ptr�� �ּҰ�

	printf("ptr_ptr = %d\n", ptr_ptr); //ptr_ptr�� ��
	printf("*ptr_ptr = %d\n", *ptr_ptr); //ptr_ptr�� ����Ű�� ��
	printf("**ptr_ptr = %d\n", **ptr_ptr); // a
}