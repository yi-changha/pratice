// ��ġ�� ��ġ

#include <stdio.h>

int main() {
	int a = 10;
	int b;

	printf("=== ��ġ ���� ���� ===\n");
	b = ++a;
	// ++a : a�� 1�� ���� ������Ű��, b�� �����϶�
	printf("a : %d\n", a); // a : 11
	printf("b : %d\n", b); // b : 11

	printf("\n\n=== ��ġ ���� ���� ===\n");
	b = a++;
	// b�� a�� �����ϰ� a�� 1 �������Ѷ�.
	printf("a : %d\n", a); // a : 12
	printf("b : %d\n", b); // b : 11
}