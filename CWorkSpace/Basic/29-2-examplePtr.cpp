#include <stdio.h>

int main() {
	int a = 10;
	int b = 20;

	int *ptr;

	ptr = &a; // ptr�� a�� �ּҰ�
	*ptr = 30; // ptr�� �������� 30 , a == 30

	ptr = &b; // ptr�� b�� �ּҰ�
	*ptr = 10; //ptr�� �������� 10, b == 10

	printf("%d\n", a); // 30
	printf("%d\n", b); // 10
	printf("%d\n", *ptr); // 10
}