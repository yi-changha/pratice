// ��ø for��

#include <stdio.h>

int main() {
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++) {
		//for (int j = 1; j <= n; j++) {  //��
			printf("*");
		}
		printf("\n");
	}
}