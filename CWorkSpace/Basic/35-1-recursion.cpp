// ��� �Լ�
// recursion

#include <stdio.h>

void rec(int n) {
	if (n > 5) return; 
	// ������ �ݺ��Ǵµ� n>5. ��, n =6 �� �� �Լ� ����
	// rec(6) �߰��� ����, rec(5) ����, rec(4) ����, ...

	printf("n = %d\n", n);
	rec(n+1);
}

int main() {
	rec(1);
}