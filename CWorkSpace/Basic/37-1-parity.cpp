/*
1. parity Ȧ¦��
* ���� �ϳ��� �Ű������� �޾�
* �� ���� ¦���̸� 0, Ȧ���̸� 1�� ��ȯ�ϴ� �Լ��� �ۼ��� ������.
*/

#include <stdio.h>

int parity(int n) {
	if (n % 2 == 0)
		return 0;

	return 1; // else�� ��� ��. if�� �ƴϸ� return�� ���� �ٷ� �Լ� ����
}

/*
int parity(int n) {
	return (n % 2 + 2) % 2;		// 1, -1, 0
}
*/


int main() {
	printf("%d\n", parity(5));
	printf("%d\n", parity(-3));
	printf("%d\n", parity(6));
}