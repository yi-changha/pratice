// ��ø if��
// �߰�ȣ �ڵ� ��Ÿ��

#include <stdio.h>

int main() {
	int a, b, c;

	scanf_s("%d%d%d", &a, &b, &c, 3);

// if, else �ȿ� ������ �� �ٸ� ������ {} ��������
	if (a > b) {
		if (a > c) printf("���� ū ���� %d\n", a);
		else printf("���� ū ���� %d\n", c);
	} else if (b > c) printf("���� ū ���� %d\n", b);
	else printf("���� ū ���� %d\n", c); // c > b
}