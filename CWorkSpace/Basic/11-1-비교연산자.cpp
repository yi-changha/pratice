// �� ������

#include <stdio.h>

int main() {
	int a, b;
	scanf_s("%d%d", &a, &b, 2);

	printf("\n\n=== int ===\n");
	// bool : ������ ����� ���� (1����Ʈ)
	int p = a > b;
	int q = a < b;
	int r = a == b; // == : ����
	// 2 > 3 -> ����
	// �� : 1, ���� : 0

	printf("a>b %d\n", p);
	printf("a<b %d\n", q);
	printf("a==b %d\n", r);

	printf("\n\n=== bool ===\n");

	bool z = a > b;
	bool x = a < b;
	bool c = a == b;

	printf("a>b %d\n", z);
	printf("a<b %d\n", x);
	printf("a==b %d\n", c);

	// a >= b : a�� b���� ũ�ų� ����.
	// a <= b : a�� b���� �۰ų� ����.
	// a != b : a�� b�� �ƴϴ�.

}