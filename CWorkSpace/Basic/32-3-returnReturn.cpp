#include <stdio.h>

void noMeaning() {
	printf("first\n");
	return; //return�� ������ ��� �Լ� ����
	printf("second\n");
	return;
}

int main() {
	noMeaning();
}

// first
// return�� ���� ��� ����Ǿ� second ��µ��� ����