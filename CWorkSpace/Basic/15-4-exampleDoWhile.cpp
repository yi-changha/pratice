#include <stdio.h>

int main() {
	int n;
	
	do {
		printf("���� 0�� �Է����ּ���!\n");
		scanf_s("%d", &n);
	} while (n != 0);

	printf("���� 0�� �Է��ϼ̱���!\n");
}

/* while�� �� ��� while ���� scanf_s�� ���� n�� ���ǵ��� �ʾƼ�
 ������� ����.
  ���� 1�� ������ �ʿ��ϱ� ������ do-while ��� */