#include <stdio.h>

int main() {
	char a;

	printf("�����Է� : ");
	scanf_s("%c", &a, 1);
	// scanf_s()�� ����� �Է¹��� ���� ("%c", %a, 1)�� ����
	// �Է¹��� ���� ���� �߰������� ���������

	printf("%c�� ASCII �� : %d\n", a, a);

	int b;

	printf("�����Է� : ");
	scanf_s("%d", &b, 1);
	printf("%d�� ASCII �� : %c\n", b, b);
}