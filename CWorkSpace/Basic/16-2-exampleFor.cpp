#include <stdio.h>

int main() {
	// 1, 2, 4, 8, 16, 32, ...

	int n;
	scanf_s("%d", &n, 1);

	for (int i = 1; i <= n; i *= 2) {
		printf("%d\n", i);
	}
}