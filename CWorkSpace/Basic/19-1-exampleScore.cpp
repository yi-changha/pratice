// ������ : + - / * % += -= ++ -- && || !
// ���ǹ� : if() switch()
// �ݺ��� : while() for()

// 1. ���� ���� �Է�
// 90 ~ 100 A
// 80 ~ 89 B
// 70 ~ 79 C
// 60 ~ 69 D
// 50 ~ 59 E

#include <stdio.h>

int main() {
	int i;
	printf("���� ������ �Է��ϼ���.\n");
	scanf_s("%d\n", &i, 1);

	if (100 < i) {
		printf("������ 100���� �����Դϴ�.", i);
	}
	else if (90 <= i) {
		printf("%d, A", i);
	}
	else if (80 <= i) {
		printf("%d, B", i);
	}
	else if (70 <= i) {
		printf("%d,C", i);
	}
	else if (60 <= i) {
		printf("%d,D", i);
	}
	else if (50 <= i) {
		printf("%d, E", i);
	}
	else if (0 <= i) {
		printf("%d, ���� ��ȸ�� ���������", i);
	}
	else {
		printf("�Է� �����Դϴ�.");
	}
}