#include <stdio.h>

int main() {
	int a = 10;

	int *ptr;
	ptr = &a;

	printf("a�� �� : %d\n", a);

	*ptr = 20;
	// ptr�� ����Ű�� ���� 20�� �����ض�. a=20 (*ptr==a)
	// ��, ptr ��ü�� ���� �ٲ��� ����.
	printf("a�� �� : %d\n", a);
}