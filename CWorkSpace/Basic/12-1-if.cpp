#include <stdio.h>

int main() {
	int n;
	scanf_s("%d", &n, 1);

	// n%2, n�� 2�� ���� ������ : 0,1

	/*
	if (n % 2 == 0) {
		printf("n�� ¦��\n");
	}
	else {
		printf("n�� Ȧ��\n");
	}
	*/

	if (n % 2) {
		printf("n�� Ȧ��\n");
	}
	else {
		printf("n�� ¦��\n");
	}
}