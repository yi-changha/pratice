//return : �����ִ�, ��ȯ

#include <stdio.h>

// 2���� �Ű�����(����)�� ���� ��ȯ
int plus(int a, int b) {
	return a + b;
}

int main() {
	int sum = plus(3, 5);
	printf("%d\n", sum);
}