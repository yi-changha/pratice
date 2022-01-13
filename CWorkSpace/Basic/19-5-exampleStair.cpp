/*
	n=4

	1
	1 2 3
	1 2 3 4 5
	1 2 3 4 5 6 7
*/

#include <stdio.h>

int main() {
	int n;
	scanf_s("%d\n", &n, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 2 * i; j++) 
			printf("%d ", j);
		printf("\n");
	}
}