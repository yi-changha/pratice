#include <stdio.h>

int main() {
	int a = 10;

	int *ptr;
	ptr = &a;
	printf("ptr = %d\n\n", ptr);	// 100���� ����

	*ptr = 20;
	printf("=== *ptr = 20; ���� ���� ===\n");
	printf("ptr = %d\n", ptr);		// 100
	printf("a = %d\n", a);			// 20

	// ptr�� ����Ű�� ������ ���� �ٲ㵵 �ּ�(ptr)���� �ٲ��� ����.
}