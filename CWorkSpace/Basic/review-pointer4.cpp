// �����͸� ����Ű�� ������

#include <stdio.h>

int main() {
	int a = 10;
	
	int *ptr;
	ptr = &a;

	int **ptr_ptr;
	ptr_ptr = &ptr;

	printf("a = %d\n", a);					//10
	printf("&a = %d\n", &a);				//100���� ����
	//printf("&&a = %d\n", &&a);			//����
	//printf("*a = %d\n", *a);				//����; �������� ����.
	printf("\n");

	printf("ptr = %d\n", ptr);				//100
	printf("&ptr = %d\n", &ptr);			//200���� ����
	printf("*ptr = %d\n", *ptr);			//10
	printf("\n");

	printf("ptr_ptr = %d\n", ptr_ptr);		//200
	printf("*ptr_ptr = %d\n", *ptr_ptr);	//100
	printf("**ptr_ptr = %d\n", **ptr_ptr);	//10
}