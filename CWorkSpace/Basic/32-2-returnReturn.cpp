#include <stdio.h>

int noMeaning() {
	printf("first\n");
	return 1; //return�� ������ ��� �Լ� ����
	printf("second\n");
	return 2;
}

int main() {
	int a;
	a = noMeaning();

	printf("��ȯ�� �� : %d\n", a); // 1
}