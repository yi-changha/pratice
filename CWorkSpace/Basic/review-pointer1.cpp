// ������(pointer) : ������ �ּҸ� �����ϴ� ����

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

	// a, ptr, &, *�� ����
	printf("%a�� �� : %d\n", a);							//20
	printf("%a�� �ּڰ� : %d\n", &a);						//100���� ����
	printf("ptr_a�� ����� �� : %d\n", ptr_a);				//100
	printf("ptr_a�� ����Ű�� ������ �� : %d\n", *ptr_a);	//20
}