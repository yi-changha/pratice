/*
	n=4
	1
	13
	135
	1357
*/

#include <stdio.h>

int main() {
	int n;
	scanf_s("%d\n", &n, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d ", 2 * j -1);
		}
		printf("\n");
	}
	printf("\n");
}