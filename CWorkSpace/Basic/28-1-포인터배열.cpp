// �迭 ������ : �迭�� ����Ű�� ������
// ������ �迭 : �����͵��� �迭

#include <stdio.h>

int main() {
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	int *ptr[4];

	ptr[0] = &a; // a�� ������
	ptr[1] = &c; // c�� ������
	ptr[2] = &d; // d�� ������
	ptr[3] = &b; // b�� ������

	printf("%d %d %d %d\n", *ptr[0], *ptr[1], *ptr[2], *ptr[3]); // 10 30 40 20
}